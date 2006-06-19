
/***************************************************************************
 *                               RasMol 2.7.3                              *
 *                                                                         *
 *                                 RasMol                                  *
 *                 Molecular Graphics Visualisation Tool                   *
 *                             6 February 2005                             *
 *                                                                         *
 *                   Based on RasMol 2.6 by Roger Sayle                    *
 * Biomolecular Structures Group, Glaxo Wellcome Research & Development,   *
 *                      Stevenage, Hertfordshire, UK                       *
 *         Version 2.6, August 1995, Version 2.6.4, December 1998          *
 *                   Copyright (C) Roger Sayle 1992-1999                   *
 *                                                                         *
 *                          and Based on Mods by                           *
 *Author             Version, Date             Copyright                   *
 *Arne Mueller       RasMol 2.6x1   May 98     (C) Arne Mueller 1998       *
 *Gary Grossman and  RasMol 2.5-ucb Nov 95     (C) UC Regents/ModularCHEM  *
 *Marco Molinaro     RasMol 2.6-ucb Nov 96         Consortium 1995, 1996   *
 *                                                                         *
 *Philippe Valadon   RasTop 1.3     Aug 00     (C) Philippe Valadon 2000   *
 *                                                                         *
 *Herbert J.         RasMol 2.7.0   Mar 99     (C) Herbert J. Bernstein    * 
 *Bernstein          RasMol 2.7.1   Jun 99         1998-2001               *
 *                   RasMol 2.7.1.1 Jan 01                                 *
 *                   RasMol 2.7.2   Aug 00                                 *
 *                   RasMol 2.7.2.1 Apr 01                                 *
 *                   RasMol 2.7.2.1.1 Jan 04                               *
 *                   RasMol 2.7.3   Feb 05                                 *
 *                                                                         *
 *with RasMol 2.7.3 incorporating changes by Clarice Chigbo, Ricky Chachra,*
 *and Mamoru Yamanishi.  Work on RasMol 2.7.3 supported in part by         *
 *grants DBI-0203064, DBI-0315281 and EF-0312612 from the U.S. National    *
 *Science Foundation and grant DE-FG02-03ER63601 from the U.S. Department  *
 *of Energy.                                                               *
 *                                                                         *
 *                    and Incorporating Translations by                    *
 *  Author                               Item                      Language*
 *  Isabel Servan Martinez,                                                *
 *  Jose Miguel Fernandez Fernandez      2.6   Manual              Spanish *
 *  Jose Miguel Fernandez Fernandez      2.7.1 Manual              Spanish *
 *  Fernando Gabriel Ranea               2.7.1 menus and messages  Spanish *
 *  Jean-Pierre Demailly                 2.7.1 menus and messages  French  *
 *  Giuseppe Martini, Giovanni Paolella, 2.7.1 menus and messages          *
 *  A. Davassi, M. Masullo, C. Liotto    2.7.1 help file           Italian *
 *                                                                         *
 *                             This Release by                             *
 * Herbert J. Bernstein, Bernstein + Sons, P.O. Box 177, Bellport, NY, USA *
 *                       yaya@bernstein-plus-sons.com                      *
 *               Copyright(C) Herbert J. Bernstein 1998-2005               *
 *                                                                         *
 *                READ THE FILE NOTICE FOR RASMOL LICENSES                 *
 *Please read the file NOTICE for important notices which apply to this    *
 *package and for license terms (GPL or RASLIC).                           *
 ***************************************************************************/
/* repres.c
 $Log: not supported by cvs2svn $
 Revision 1.1  2004/05/07 19:46:16  yaya
 Initial revision

 Revision 1.3  2004/02/15 00:24:00  yaya
 *** empty log message ***

 Revision 1.2  2003/12/13 19:26:11  yaya
 *** empty log message ***

 Revision 1.1  2003/12/12 21:10:38  yaya
 Initial revision

 Revision 1.1  2001/01/31 02:13:45  yaya
 Initial revision

 Revision 1.7  2000/08/27 16:09:27  yaya
 monitor dynamics extensions

 Revision 1.6  2000/08/26 18:12:43  yaya
 Updates to header comments in all files

 Revision 1.5  2000/08/18 16:40:42  yaya
 *** empty log message ***

 Revision 1.4  2000/08/13 20:56:28  yaya
 Conversion from toolbar to menus

 Revision 1.3  2000/08/09 01:18:15  yaya
 Rough cut with ucb

 Revision 1.2  2000/08/03 18:32:42  yaya
 Parametrization for alt conformer bond radius

 */
#include "rasmol.h"

#ifdef IBMPC
#include <windows.h>
#include <malloc.h>
#endif
#ifdef APPLEMAC
#include <Types.h>
#include <Errors.h>
#ifdef __CONDITIONALMACROS__
#include <Printing.h>
#else
#include <PrintTraps.h>
#endif
#endif
#ifndef sun386
#include <stdlib.h>
#endif

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>

#define REPRES
#include "molecule.h"
#include "graphics.h"
#include "repres.h"
#include "render.h"
#include "command.h"
#include "cmndline.h"
#include "abstree.h"
#include "transfor.h"
#include "pixutils.h"
#include "infile.h"
#include "vector.h"
#include "wbrotate.h"


#define RootSix          2.44948974278

#ifdef INVERT
#define InvertY(y) (y)
#else
#define InvertY(y) (-(y))
#endif

/* These define light source position */
#define LightLength      RootSix


#define ForEachAtom  for(chain=Database->clist;chain;chain=chain->cnext) \
                     for(group=chain->glist;group;group=group->gnext)    \
                     for(aptr=group->alist;aptr;aptr=aptr->anext)
#define ForEachBond  for(bptr=Database->blist;bptr;bptr=bptr->bnext)
#define ForEachBack  for(chain=Database->clist;chain;chain=chain->cnext) \
                     for(bptr=chain->blist;bptr;bptr=bptr->bnext)


typedef struct { int dx, dy, dz; } DotVector;
typedef struct {
        DotVector __far *probe;
        DotVector __far *dots;
        int count;
    } ElemDotStruct;
 

static ElemDotStruct __far *ElemDots;
static RAtom __far *Exclude;
static Monitor *FreeMonit;
static Label *FreeLabel;


/*=======================*/
/*  Function Prototypes  */
/*=======================*/
  
#ifdef FUNCPROTO
void AddMonitors( RAtom __far*, RAtom __far* );
static void AddDot( Long, Long, Long, int );
static void CheckVDWDot( Long, Long, Long, int );
static int TestSolventDot( Long, Long, Long );
#else
void AddMonitors();
static void AddDot();
static void CheckVDWDot();
static int TestSolventDot();
#endif



static void FatalRepresError( char *ptr )
{
    char buffer[80];
 
    sprintf(buffer,"Renderer Error: Unable to allocate %s!",ptr);
    RasMolFatalExit(buffer);
}
 

/*============================*/
/*  Label Handling Functions  */
/*============================*/

static void ResetLabels( void )
{
    register Label *ptr;
 
    while( LabelList )
    {   ptr = LabelList;
        LabelList = ptr->next;
        ptr->next = FreeLabel;
        free(ptr->label);
        FreeLabel = ptr;
    }
}
 

void DeleteLabel( Label *label )
{
    register Label **ptr;
 
    if( label->refcount == 1 )
    {   ptr = &LabelList;
        while( *ptr != label )
        ptr = &(*ptr)->next;
 
        *ptr = label->next;
        label->next = FreeLabel;
        free(label->label);
        FreeLabel = label;
    } else label->refcount--;
}
 

int DeleteLabels( void )
{
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *aptr;
    register int result;
 
    if( !Database )
        return( True );
 
    result = True;
 
    ForEachAtom
        if( aptr->flag & SelectFlag )
        {   if( aptr->label )
            {   DeleteLabel( (Label*)aptr->label );
                aptr->label = (void*)0;
            }
            result = False;
        }
    return( result );
}


Label *CreateLabel( char *text, int len )
{
    register Label *ptr;
 
    /* Test for existing label */
    for( ptr=LabelList; ptr; ptr=ptr->next )
        if( !strcmp(ptr->label,text) )
            return( ptr );
 
    if( FreeLabel )
    {   ptr = FreeLabel;  FreeLabel = ptr->next;
    } else if( !(ptr=(Label*)malloc(sizeof(Label))) )
        FatalRepresError("label");
 
    ptr->label = (char*)malloc(len+1);
    if( !ptr->label ) FatalRepresError("label");
    strcpy(ptr->label,text);
 
    ptr->next = LabelList;
    ptr->refcount = 0;
    LabelList = ptr;
    return( ptr );
}
 
 
void DefineLabels( char *label )
{
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *aptr;
    register Label *ptr;
    register char *cptr;
    register int len;
 
 
    if( !Database ) return;
    if( DeleteLabels() )
        return;
 
    len = 0;
    for( cptr=label; *cptr; cptr++ )
        len++;
 
    /* Strip trailing spaces */
    while( len && cptr[-1]==' ' )
    {   cptr--;  len--;
        *cptr = '\0';
    }
 
    if( !len )
        return;
 
    ptr = CreateLabel(label,len);

    ForEachAtom
        if( aptr->flag & SelectFlag )
        {   aptr->label = ptr;
            ptr->refcount++;
        }
}
 
 
void DefaultLabels( int enable )
{
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *aptr;
    register Label *label1;
    register Label *label2;
 
    if( !Database )
        return;
 
    label1 = (Label*)0;
    label2 = (Label*)0;
 
    if( MainGroupCount > 1 )
    {   ForEachAtom
            if( IsAlphaCarbon(aptr->refno) || IsSugarPhosphate(aptr->refno) )
            {   if( aptr->flag & SelectFlag )
                {   if( aptr->label )
                    {   DeleteLabel( (Label*)aptr->label );
                        aptr->label = (Label*)0;
                    }

                    if( enable )
                    {   if( Info.chaincount > 1 )
                        {   if( isdigit(chain->ident) )
                            {   if( !label1 )
                                    label1 = CreateLabel("%n%r:%c",7);
                                aptr->label = label1;
                                label1->refcount++;
                            } else
                            {   if( !label2 )
                                    label2 = CreateLabel("%n%r%c",6);
                                aptr->label = label2;
                                label2->refcount++;
                            }
                        } else
                        {   if( !label1 )
                                label1 = CreateLabel("%n%r",4);
                            aptr->label = label1;
                            label1->refcount++;
                        }
                    }
                    ReDrawFlag |= RFRefresh;
                }
                break;
            }
 
    } else /* Small Molecule! */
        ForEachAtom
            if( (aptr->flag&SelectFlag) && (aptr->elemno!=6)
                                        && (aptr->elemno!=1) )
            {   if( aptr->label )
                {   DeleteLabel( (Label*)aptr->label );
                    aptr->label = (Label*)0;
                }

                if( enable )
                {   if( !label1 )
                        label1 = CreateLabel("%e",2);
                    aptr->label = label1;
                    label1->refcount++;
                }
                ReDrawFlag |= RFRefresh;
            }
}


void LabelTerminii( int enable )
{
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *aptr;
    register Label *label;
 
    if( !Database )
        return;

    for( chain=Database->clist; chain; chain=chain->cnext )
        if( chain->glist && chain->glist->gnext )
        {   group = chain->glist;
            if( IsProtein(group->refno) )
            {   /* N terminus */
                aptr = FindGroupAtom(group,1);
                if( aptr && (aptr->flag&SelectFlag) )
                {   if( aptr->label )
                    {   DeleteLabel( (Label*)aptr->label );
                        aptr->label = (Label*)0;
                    }
                    if( enable )
                    {   label = CreateLabel("N",1);
                        aptr->label = label;
                        label->refcount++;
                    }
                }

                while( group->gnext )
                    group = group->gnext;

                /* C terminus */
                aptr = FindGroupAtom(group,1);
                if( aptr && (aptr->flag&SelectFlag) )
                {   if( aptr->label )
                    {   DeleteLabel( (Label*)aptr->label );
                        aptr->label = (Label*)0;
                    }
                    if( enable )
                    {   label = CreateLabel("C",1);
                        aptr->label = label;
                        label->refcount++;
                    }
                }

            } else if( IsDNA(group->refno) )
            {   /* 5' terminus */
                aptr = FindGroupAtom(group,7);
                if( aptr && (aptr->flag&SelectFlag) )
                {   if( aptr->label )
                    {   DeleteLabel( (Label*)aptr->label );
                        aptr->label = (Label*)0;
                    }
                    if( enable )
                    {   label = CreateLabel("5'",2);
                        aptr->label = label;
                        label->refcount++;
                    }
                }

                while( group->gnext )
                    group = group->gnext;

                /* 3' terminus */
                aptr = FindGroupAtom(group,7);
                if( aptr && (aptr->flag&SelectFlag) )
                {   if( aptr->label )
                    {   DeleteLabel( (Label*)aptr->label );
                        aptr->label = (Label*)0;
                    }
                    if( enable )
                    {   label = CreateLabel("3'",2);
                        aptr->label = label;
                        label->refcount++;
                    }
                }
            }
        }
}


void DisplayLabels( void )
{
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *aptr;
    register Label *label;
    register int col,z;
 
    auto unsigned char buffer[256];
 
 
    if( !Database )
        return;
 
    if( !UseSlabPlane )
    {   z = ImageRadius + ZOffset;
    } else z = SlabValue - 1;
 
    ForEachAtom
        if( aptr->label )
        {   /* Peform Label Slabbing! */
            if( !ZValid(aptr->z) || !ZBack(aptr->z) )
                continue;
 
            label = (Label*)aptr->label;
            FormatLabel(chain,group,aptr,label->label,buffer);
 
            if( !UseLabelCol )
            {   /* Depth-cue atom labels */
                /* col = aptr->col + (ColorDepth*                  */
                /*       (aptr->z+ImageRadius-ZOffset))/ImageSize; */
                col = aptr->col + (FontStroke?0:(ColourMask>>1));
            } else col = LabelCol;
 
            /* (aptr->z+2) + ((aptr->flag & SphereFlag)?aptr->irad:0); */
            DisplayRasString(aptr->x+4,aptr->y,z,buffer,col);
        }
}



/*==============================*/
/*  Monitor Handling Functions  */
/*==============================*/
 
void DeleteMonitors( void )
{
    register Monitor *ptr;
 
    while( MonitList )
    {   ptr = MonitList;
        if( ptr->col )
            Shade[Colour2Shade(ptr->col)].refcount--;
 
        MonitList = ptr->next;
        ptr->next = FreeMonit;
        FreeMonit = ptr;
    }
}
 

/* [GSG 11/21/95] AddMonitors2 can add a monitor w/a given number */
void AddMonitors2( RAtom __far *src, RAtom __far *dst,
      RAtom __far *mid1, RAtom __far *mid2,
      short dist, unsigned char units, int monmode )
{
    register Monitor **prev;
    register Monitor *ptr;
 
    /* Delete an already existing monitor! */
    for( prev = &MonitList;  *prev; prev = &ptr->next )
    {   ptr = *prev;
        if( ((ptr->src==src) && (ptr->dst==dst)
             &&(ptr->mid1==mid1) && (ptr->mid2==mid2)) ||
            ((ptr->src==dst) && (ptr->dst==src)
             &&(ptr->mid1==mid2) && (ptr->mid2==mid1)) )
        {   if( ptr->col )
                Shade[Colour2Shade(ptr->col)].refcount--;
 
             *prev = ptr->next;
             ptr->next = FreeMonit;
             FreeMonit = ptr;
             return;
         }
    }
 
    /* Create a new monitor! */
    if( FreeMonit )
    {   ptr = FreeMonit;  FreeMonit = ptr->next;
    } else if( !(ptr=(Monitor*)malloc(sizeof(Monitor))) )
        FatalRepresError("monitor");
 
    ptr->dist = dist;
 
    ptr->src = src;
    ptr->dst = dst;
    ptr->mid1 = mid1;
    ptr->mid2 = mid2;
    ptr->monmode = monmode;
    ptr->col = 0;
    ptr->units = units;
 
    ptr->next = MonitList;
    MonitList = ptr;
}

void AddMonitors( RAtom __far *src, RAtom __far *dst )
{
    register Long dx, dy, dz;
    register Long dist;
    short temp;
 
    dx = src->xorg - dst->xorg + src->fxorg - dst->fxorg;
    dy = src->yorg - dst->yorg + src->fyorg - dst->fyorg;
    dz = src->zorg - dst->zorg + src->fzorg - dst->fzorg;

    /* ptr->dist = 100.0*CalcDistance(src,dst) */
    dist = isqrt( dx*dx + dy*dy + dz*dz );
    temp = rint(100.0*CalcDistance(src,dst));

    AddMonitors2(src, dst, 
      (RAtom __far *)NULL, (RAtom __far *)NULL, temp, 127, PickDist);

}


void CreateMonitor( Long src, Long dst )
{
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *aptr;
    register RAtom __far *sptr;
    register RAtom __far *dptr;
    register int done;
    char buffer[20];
 
    if( src == dst )
    {   InvalidateCmndLine();
        WriteString("Error: Duplicate atom serial numbers!\n");
        return;
    }
 
    done = False;
    sptr = (RAtom __far*)0;
    dptr = (RAtom __far*)0;
 
    for( chain=Database->clist; chain && !done; chain=chain->cnext )
        for( group=chain->glist; group && !done; group=group->gnext )
            for( aptr=group->alist; aptr; aptr=aptr->anext )
            {   if( aptr->serno == src )
                {   sptr = aptr;
                    if( dptr )
                    {   done = True;
                        break;
                    }
                } else if( aptr->serno == dst )
                {   dptr = aptr;
                    if( sptr )
                    {   done = True;
                        break;
                    }
                }
            }
 
    if( !done )
    {   InvalidateCmndLine();
        WriteString("Error: Atom serial number");
        if( sptr )
        {   sprintf(buffer," %ld",dst);
        } else if( dptr )
        {   sprintf(buffer," %ld",src);
        } else sprintf(buffer,"s %ld and %ld",src,dst);
        WriteString(buffer); WriteString(" not found!\n");
 
    } else AddMonitors( sptr, dptr );
}
 
 
void DisplayMonitors( void )
{
    register RAtom __far *s;
    register RAtom __far *d;
    register RAtom __far *m1;
    register RAtom __far *m2;
    register Monitor *ptr;
    register int x,y,z;
    register int sc,dc;
    register int col;
    register Long dx, dy, dz;
    register Long ldist;
 
    register unsigned char *cptr;
    register int dist;
    unsigned char buffer[11];
 
    if( !Database )
        return;
 
    if( !UseSlabPlane )
    {   z = ImageRadius + ZOffset;
    } else z = SlabValue-1;
    buffer[10] = '\0';
    buffer[6] = '.';
 
    for( ptr=MonitList; ptr; ptr=ptr->next )
    {   s = ptr->src;
        d = ptr->dst;
        m1 = ptr->mid1;
        m2 = ptr->mid2;

        buffer[9] = ptr->units;
 
        if( !ptr->col )
        {   sc = s->col;
            dc = d->col;
        } else sc = dc = ptr->col;
 
        ClipDashVector(s->x,s->y,s->z,d->x,d->y,d->z,sc,dc,' ');
 
        if( DrawMonitDistance )
            if( ZValid( (s->z+d->z)/2 ) && ZBack( (s->z+d->z)/2 ))
            {   x = (s->x+d->x)/2;
                y = (s->y+d->y)/2;
 
                if( !UseLabelCol )
                {   /* Use Source atom colour! */
                    col = sc + (FontStroke?0:(ColourMask>>1));
                } else col = LabelCol;
 
                if ( BondSelected ) {
                  if ((ptr->monmode == PickDist)
                    && ( s->visited ^ d->visited ) ) {
                    dx = s->xorg - d->xorg + s->fxorg - d->fxorg;
                    dy = s->yorg - d->yorg + s->fyorg - d->fyorg;
                    dz = s->zorg - d->zorg + s->fzorg - d->fzorg;
                    ldist = (int)isqrt( dx*dx + dy*dy + dz*dz );
                    ptr->dist = (int)((ldist<<1)/5);
                  }
                  if ((ptr->monmode == PickAngle)
                    && (( s->visited ^ d->visited ) ||
                        ( s->visited ^ m1->visited ) ||
                        ( m1->visited ^ d->visited )) ){
                    ptr->dist = 
                      (int)(100*CalcAngle(s,m1,d));
                  }
                  if ((ptr->monmode == PickTorsn)
                    && (( s->visited ^ d->visited ) ||
                        ( s->visited ^ m1->visited ) ||
                        ( m1->visited ^ m2->visited ) ||
                        ( m2->visited ^ d->visited )) ) {
                    ptr->dist = 
                      (int)(100*CalcTorsion(s,m1,m2,d));
                  }
                }
                dist = ptr->dist;
                if ( dist < 0 ) dist = -dist;
                buffer[8] = (dist%10)+'0';  dist /= 10;
                buffer[7] = (dist%10)+'0';
                cptr = &buffer[5];

                if( dist > 9 )
                {   do {
                       dist /= 10;
                       *cptr-- = (dist%10)+'0';
                    } while( dist > 9 );
                    cptr++;
                } else *cptr = '0';
                if ( ptr->dist < 0 ) *(--cptr)='-';
 
                DisplayRasString(x+4,y,z,cptr,col);
            }
    }
}
 
 
/*=========================*/
/*  Dot Surface Functions  */
/*=========================*/

void DeleteSurface( void )
{
    register DotStruct __far *ptr;
    register int shade;
    register int i;
 
    while( DotPtr )
    {   for( i=0; i<DotPtr->count; i++ )
        {   shade = Colour2Shade(DotPtr->col[i]);
            Shade[shade].refcount--;
        }
 
        ptr = DotPtr->next;
        _ffree( DotPtr );
        DotPtr = ptr;
    }
}
 
 
static void AddDot( Long x, Long y, Long z, int col )
{
    register DotStruct __far *ptr;
    register int i, shade;
 
    if( !DotPtr || (DotPtr->count==DotMax) )
    {   ptr = (DotStruct __far*)_fmalloc(sizeof(DotStruct));
        if( !ptr ) FatalRepresError("dot surface");
 
        ptr->next = DotPtr;
        ptr->count = 0;
        DotPtr = ptr;
    } else ptr = DotPtr;
 
    shade = Colour2Shade(col);
    Shade[shade].refcount++;
 
    i = ptr->count++;
    ptr->col[i] = col;
    ptr->xpos[i] = x;
    ptr->ypos[i] = y;
    ptr->zpos[i] = z;
}
 
 
static void CheckVDWDot(  Long x,  Long y,  Long z, int col )
{
    register Item __far *item;
    register RAtom __far *aptr;
    register int ix,iy,iz;
    register int dx,dy,dz;
    register Long dist;
    register Long rad;
    register int i;
 
    ix = (int)((x+Offset)*IVoxRatio);
    iy = (int)((y+Offset)*IVoxRatio);
    iz = (int)((z+Offset)*IVoxRatio);
 
    i = VOXORDER2*ix + VOXORDER*iy + iz;
    for( item=HashTable[i]; item; item=item->list )
        if( item->data != Exclude )
        {   aptr = item->data;
            if( !ProbeRadius )
            {   rad = ElemVDWRadius(aptr->elemno);
            } else rad = ElemVDWRadius(aptr->elemno)+ProbeRadius;
            rad = rad*rad;
 
            /* Optimized Test! */
            dx = (int)(aptr->xorg + aptr->fxorg  - x);
            if( (dist=(Long)dx*dx) < rad )
            {   dy = (int)(aptr->yorg + aptr->fyorg - y);
                if( (dist+=(Long)dy*dy) < rad )
                {   dz = (int)(aptr->zorg + aptr->fzorg - z);
                    if( (dist+=(Long)dz*dz) < rad )
                        return;
                }
            }
        }
    AddDot( x, y, z, col );
}
 
 
static int TestSolventDot( Long x, Long y, Long z )
{
    register Item __far *item;
    register RAtom __far *aptr;
    register int lx,ly,lz;
    register int ux,uy,uz;
    register int dx,dy,dz;
    register int ix,iy,iz;
    register Long dist;
    register Long rad;
    register int i;
 
    dist = Offset-ProbeRadius;
    lx = (int)((x+dist)*IVoxRatio);
    if( lx >= VOXORDER ) return( True );
    ly = (int)((y+dist)*IVoxRatio);
    if( ly >= VOXORDER ) return( True );
    lz = (int)((z+dist)*IVoxRatio);
    if( lz >= VOXORDER ) return( True );
 
    dist = Offset+ProbeRadius;
    ux = (int)((x+dist)*IVoxRatio);
    if( ux < 0 ) return( True );
    uy = (int)((y+dist)*IVoxRatio);
    if( uy < 0 ) return( True );
    uz = (int)((z+dist)*IVoxRatio);
    if( uz < 0 ) return( True );
 
    if( lx < 0 ) lx = 0;  if( ux >= VOXORDER ) ux = VOXORDER-1;
    if( ly < 0 ) ly = 0;  if( uy >= VOXORDER ) uy = VOXORDER-1;
    if( lz < 0 ) lz = 0;  if( uz >= VOXORDER ) uz = VOXORDER-1;
 
    for( ix=lx; ix<=ux; ix++ )
       for( iy=ly; iy<=uy; iy++ )
          for( iz=lz; iz<=uz; iz++ )
          {   i = VOXORDER2*ix + VOXORDER*iy + iz;
              for( item=HashTable[i]; item; item=item->list )
                  if( item->data != Exclude )
                  {   aptr = item->data;
                      rad = ElemVDWRadius(aptr->elemno);
                      rad = (rad+ProbeRadius)*(rad+ProbeRadius);
 
                      /* Optimized Test! */
                      dx = (int)(aptr->xorg + aptr->fxorg - x);
                      if( (dist=(Long)dx*dx) < rad )
                      {   dy = (int)(aptr->yorg + aptr->fyorg - y);
                          if( (dist+=(Long)dy*dy) < rad )
                          {   dz = (int)(aptr->zorg + aptr->fzorg - z);
                              if( (dist+=(Long)dz*dz) < rad )
                                  return False;
                          }
                      }
                  }
          }
    return True;
}
 
 
static void InitElemDots( void )
{
    register int i,size;
 
    size = MAXELEMNO*sizeof(ElemDotStruct);
    ElemDots = (ElemDotStruct __far*)_fmalloc(size);
    if( !ElemDots ) FatalRepresError("dot vector table");
 
    for( i=0; i<MAXELEMNO; i++ )
        ElemDots[i].count = 0;
}
 
 
static void AddElemDots( int elem, int density )
{
    register DotVector __far *ptr;
    register DotVector __far *probe;
    register Real x, y, z, p, q, xy;
    register int equat,vert,horz;
    register int rad,count;
    register int i,j,k;
    register int temp=0;
 
 
    if( SolventDots || !ProbeRadius )
    {   rad = ElemVDWRadius(elem);
    } else rad = ElemVDWRadius(elem)+ProbeRadius;
 
    count = (int)(((Long)density*rad*rad)/((Long)250*250));
    ptr = (DotVector __far*)_fmalloc(count*sizeof(DotVector));
    if( !ptr ) FatalRepresError("dot vectors");
 
    if( SolventDots )
    {   probe = (DotVector __far*)_fmalloc(count*sizeof(DotVector));
        if( !probe ) FatalRepresError("probe vectors");
        temp = rad + ProbeRadius;
    } else probe = NULL;
 
    equat = (int)rint(sqrt(PI*count));
    if( !(vert=equat>>1) )
        vert = 1;
 
    i = 0;
    for( j=0; (i<count) && (j<vert); j++ )
    {   p = (PI*j)/(Real)vert;
        z = cos(p);  xy = sin(p);
        horz = (int)rint(equat*xy);
        if( !horz ) horz = 1;
 
        for( k=0; (i<count) && (k<horz); k++ )
        {   q = (2.0*PI*k)/(Real)horz;
            x = xy*sin(q);
            y = xy*cos(q);
 
            ptr[i].dx = (int)rint(rad*x);
            ptr[i].dy = (int)rint(rad*y);
            ptr[i].dz = (int)rint(rad*z);
            if( probe )
            {   probe[i].dx = (int)rint(temp*x);
                probe[i].dy = (int)rint(temp*y);
                probe[i].dz = (int)rint(temp*z);
            }
            i++;
        }
    }
    ElemDots[elem].probe = probe;
    ElemDots[elem].dots = ptr;
    ElemDots[elem].count = i;
}
 
 
static void FreeElemDots( void )
{
    register int i;
 
    for( i=0; i<MAXELEMNO; i++ )
        if( ElemDots[i].count ) {
            _ffree( ElemDots[i].dots );
            if ( ElemDots[i].probe ) {
              _ffree( ElemDots[i].probe );
            }
        }
    _ffree( ElemDots );
}
 
 
void CalculateSurface( int density )
{
    register DotVector __far *probe;
    register DotVector __far *ptr;
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *aptr;
    register int i,count;
    register int elem;
 
    if( !Database )
        return;
 
    DeleteSurface();
    ResetVoxelData();
 
    InitElemDots();
    CreateVoxelData( AllAtomFlag );
    VoxelsClean = False;
 
    ForEachAtom
        if( aptr->flag & SelectFlag )
        {   elem = aptr->elemno;
            if( !ElemDots[elem].count )
                AddElemDots(elem,density);
 
            Exclude = aptr;
            ptr = ElemDots[elem].dots;
            probe = ElemDots[elem].probe;
            count = ElemDots[elem].count;
            if( SolventDots )
            {   for( i=0; i<count; i++ )
                    if( TestSolventDot( aptr->xorg + aptr->fxorg + probe[i].dx,
                                      aptr->yorg + aptr->fyorg + probe[i].dy,
                                      aptr->zorg + aptr->fzorg + probe[i].dz ) )
                        AddDot( aptr->xorg + aptr->fxorg + ptr[i].dx,
                              aptr->yorg + aptr->fyorg + ptr[i].dy,
                              aptr->zorg + aptr->fzorg + ptr[i].dz,
                              aptr->col );
            } else
                for( i=0; i<count; i++ )
                    CheckVDWDot( aptr->xorg +  aptr->fxorg + ptr[i].dx,
                               aptr->yorg + aptr->fyorg + ptr[i].dy,
                               aptr->zorg + aptr->fzorg + ptr[i].dz,
                               aptr->col);
        }
 
    FreeElemDots();
}
 

static Long ReadValue( char *ptr, int len )
{
    register Long result;
    register char ch;
    register int neg;

    result = 0;
    neg = False;
    while( len-- )
    {   ch = *ptr++;
        if( isdigit(ch) )
        {   result = (10*result)+(ch-'0');
        } else if( ch=='-' )
           neg = True;
    }
    return( neg? -result : result );
}


void LoadDotsFile( FILE *fp, int info )
{
    register Long x,y,z;
    register Long count;
    register int shade;
    register int col;
    char buffer[256];

    DeleteSurface();
    shade = DefineShade(255,255,255);
    col = Shade2Colour(shade);

    count = 0;
    while( FetchRecord(fp,buffer) )
    {   x = ReadValue(buffer+13,8);
        y = ReadValue(buffer+22,8);
        z = ReadValue(buffer+31,8);

        x =  x/4 - OrigCX;
        y =  y/4 - OrigCY;
        z = -z/4 - OrigCZ;
        AddDot(x,y,z,col);
        count++;
    }
    fclose(fp);

    if( count )
        ReDrawFlag |= RFRefresh;

    if( info )
    {   InvalidateCmndLine();

        if( count > 1 )
        {   sprintf(buffer,"%ld dots read from file\n",count);
            WriteString(buffer);
        } else if( count == 1 )
        {      WriteString("1 dot read from file\n");
        } else WriteString("No dots read from file!\n");
    }
}


void DisplaySurface( void )
{
    register DotStruct __far *ptr;
    register int xi,yi,zi;
    register Real x,y,z;
    register int i;
    register int Cenx,Ceny,Cenz;
    
    Cenx=(int)rint(CenX*MatX[0]+CenY*MatX[1]+CenZ*MatX[2]);
    Ceny=(int)rint(CenX*MatY[0]+CenY*MatY[1]+CenZ*MatY[2]);
    Cenz=(int)rint(CenX*MatZ[0]+CenY*MatZ[1]+CenZ*MatZ[2]);

 
    for( ptr=DotPtr; ptr; ptr=ptr->next )
        for( i=0; i<ptr->count; i++ )
        {   x = ptr->xpos[i];
            y = ptr->ypos[i];
            z = ptr->zpos[i];
 
            xi = (int)rint(x*MatX[0]+y*MatX[1]+z*MatX[2])+XOffset-Cenx;
            if( XValid(xi) )
            {   yi = (int)rint(x*MatY[0]+y*MatY[1]+z*MatY[2])+YOffset-Ceny;
                if( YValid(yi) )
                {   zi = (int)rint(x*MatZ[0]+y*MatZ[1]+z*MatZ[2])+ZOffset-Cenz;
                    if( ZValid(zi) && ZBack(zi) )
                        PlotDeepPoint(xi,yi,zi,ptr->col[i]);
                }
            }
        }
}
 


/*==============================*/
/*  Ribbon & Cartoon Functions  */
/*==============================*/
 
static void CalculateVInten( Knot *ptr )
{
    register Real inten;
 
    if( !ptr->vsize )
        ptr->vsize = isqrt( (Long)ptr->vnx*ptr->vnx +
                            (Long)ptr->vny*ptr->vny +
                            (Long)ptr->vnz*ptr->vnz ) + 1;
 
#ifdef ORIGINAL
    inten = LightDot(ptr->vnx,-InvertY(ptr->vny),ptr->vnz);
    inten /= ptr->vsize*LightLength;
#else
    inten = (Real)ptr->vnz/ptr->vsize;
#endif
 
    if( ptr->vnz < 0 ) inten = -inten;
 
    if( inten > 0.0 )
    {   ptr->vinten = (char)(ColourMask*inten);
    } else ptr->vinten = 0;
}
 

static void CalculateHInten( Knot *ptr )
{
    register Real inten;
 
    /* The intensity of the sides of a protein cartoon
     * may be calculated using ptr->cx,cy,cz and this
     * should save interpolating ptr->hnx,hny,hnz!
     */
 
    if( !ptr->hsize )
        ptr->hsize = isqrt( (Long)ptr->hnx*ptr->hnx +
                            (Long)ptr->hny*ptr->hny +
                            (Long)ptr->hnz*ptr->hnz ) + 1;
 
#ifdef ORIGINAL
    inten = LightDot(ptr->hnx,-InvertY(ptr->hny),ptr->hnz);
    inten /= ptr->hsize*LightLength;
#else
    inten = (Real)ptr->hnz / ptr->hsize;
#endif

    if( ptr->hnz < 0 ) inten = -inten;
 
    if( inten > 0.0 )
    {   ptr->hinten = (char)(ColourMask*inten);
    } else ptr->hinten = 0;
}
 
 
void DisplayRibbon( Chain  __far *chain )
{
    register Group __far *group;
    register RAtom __far *captr;
    register RAtom __far *o1ptr;
    register RAtom __far *o2ptr;
    register RAtom __far *next;
 
    register int prev,wide;
    register int col1,col2;
    register int bx,by,bz;
    register int dx,dy,dz;
    register int arrow;
    register int size;
 
    static Knot mid1, mid2, mid3;
    static Knot knot1, knot2;
 
    prev = False;
    group = chain->glist;
    if( IsProtein(group->refno) )
    {   captr = FindGroupAtom(group,1);
    } else captr = FindGroupAtom(group,7);
 
    while( group->gnext )
    {   if( IsProtein(group->gnext->refno) )
        {   next = FindGroupAtom(group->gnext,1);
            o1ptr = FindGroupAtom(group,3);
        } else /* Nucleic Acid */
        {   next = FindGroupAtom(group->gnext,7);
            o1ptr = FindGroupAtom(group->gnext,10);
        }
 
        /* When not to have a control point! */
        if( !next || !captr || !o1ptr || (next->flag&BreakFlag) ||
            !((group->flag|group->gnext->flag)&DrawKnotFlag) )
        {   group = group->gnext;
            captr = next;
            prev = False;
            continue;
        }
 
        knot2.tx = next->x - captr->x;
        knot2.ty = next->y - captr->y;
        knot2.tz = next->z - captr->z;
 
        if( IsProtein(group->refno) )
        {   bx = o1ptr->x - captr->x;
            by = o1ptr->y - captr->y;
            bz = o1ptr->z - captr->z;
 
        } else /* Nucleic Acid */
        {   o2ptr = FindGroupAtom(group,8);
            if( o2ptr && !FindGroupAtom(group,17) )
            {   /* Deoxyribonucleic Acid */
                bx = (o1ptr->x + o2ptr->x)/2 - captr->x;
                by = (o1ptr->y + o2ptr->y)/2 - captr->y;
                bz = (o1ptr->z + o2ptr->z)/2 - captr->z;
            } else /* Ribonucleic Acid */
            {   bx = o1ptr->x - captr->x;
                by = o1ptr->y - captr->y;
                bz = o1ptr->z - captr->z;
            }
        }
 
        knot2.px = (captr->x + next->x)/2;
        knot2.py = (captr->y + next->y)/2;
        knot2.pz = (captr->z + next->z)/2;
 
        /* c := a x b */
        knot2.vnx = knot2.ty*bz - knot2.tz*by;
        knot2.vny = knot2.tz*bx - knot2.tx*bz;
        knot2.vnz = knot2.tx*by - knot2.ty*bx;
 
        if( (group->struc&group->gnext->struc) & HelixFlag )
        {   /* Compensate for narrowing of helices! */
            size = isqrt((Long)knot2.vnx*knot2.vnx +
                         (Long)knot2.vny*knot2.vny +
                         (Long)knot2.vnz*knot2.vnz);
            knot2.vsize = size;
 
            if( size )
            {   /* 1.00 Angstrom Displacement */
                wide = (int)(250*Scale);
#ifdef INVERT
                knot2.px += (int)(((Long)wide*knot2.vnx)/size);
                knot2.py += (int)(((Long)wide*knot2.vny)/size);
                knot2.pz += (int)(((Long)wide*knot2.vnz)/size);
#else
                knot2.px -= (int)(((Long)wide*knot2.vnx)/size);
                knot2.py -= (int)(((Long)wide*knot2.vny)/size);
                knot2.pz -= (int)(((Long)wide*knot2.vnz)/size);
#endif
            }
        } else knot2.vsize = 0;
 
        if( !(group->flag&group->gnext->flag&TraceFlag) )
        {   /* d := c x a */
            dx = (int)(((Long)knot2.vny*knot2.tz -
                        (Long)knot2.vnz*knot2.ty)/96);
            dy = (int)(((Long)knot2.vnz*knot2.tx -
                        (Long)knot2.vnx*knot2.tz)/96);
            dz = (int)(((Long)knot2.vnx*knot2.ty -
                        (Long)knot2.vny*knot2.tx)/96);
 
            knot2.hsize = isqrt((Long)dx*dx + (Long)dy*dy + (Long)dz*dz);
 
            /* Handle Carbonyl Oxygen Flip */
            if( prev && (((Long)knot1.hnx*dx +
                          (Long)knot1.hny*dy +
                          (Long)knot1.hnz*dz)<0) )
            {   knot2.hnx = -dx;   knot2.vnx = -knot2.vnx;
                knot2.hny = -dy;   knot2.vny = -knot2.vny;
                knot2.hnz = -dz;   knot2.vnz = -knot2.vnz;
            } else
            {   knot2.hnx = dx;
                knot2.hny = dy;
                knot2.hnz = dz;
            }
 
            arrow = False;
            if( group->flag&CartoonFlag )
            {   if( DrawBetaArrows && (group->struc&SheetFlag) &&
                    !(group->gnext->struc&SheetFlag) )
                {   wide = (3*group->width)>>1;
                    arrow = True;
                } else wide = group->width;
            } else if( group->flag & WideKnotFlag )
            {   /* Average Ribbon Width */
                if( group->gnext->flag & WideKnotFlag )
                {   wide = (group->width+group->gnext->width)>>1;
                } else if( group->gnext->flag & CartoonFlag )
                {   wide = group->gnext->width;
                } else wide = group->width;
            } else wide = group->gnext->width;
 
            /* Set Ribbon Width */
            wide = (int)(wide*Scale);
 
            if( knot2.hsize && !arrow )
            {   size = knot2.hsize;
                knot2.wx = (int)(((Long)wide*knot2.hnx)/size);
                knot2.wy = (int)(((Long)wide*knot2.hny)/size);
                knot2.wz = (int)(((Long)wide*knot2.hnz)/size);
                knot2.wide = (short)wide;
            } else
            {   knot2.wide = 0;
                knot2.wx = 0;
                knot2.wy = 0;
                knot2.wz = 0;
            }
 
            if( group->flag & CartoonFlag )
                if( prev && (knot1.wide!=wide) && knot1.hsize )
                {   size = knot1.hsize;
                    knot1.wx = (int)(((Long)wide*knot1.hnx)/size);
                    knot1.wy = (int)(((Long)wide*knot1.hny)/size);
                    knot1.wz = (int)(((Long)wide*knot1.hnz)/size);
                }
 
            if( (group->flag|group->gnext->flag)&CartoonFlag )
            {   CalculateVInten( &knot2 );
                CalculateHInten( &knot2 );
 
                size = knot2.vsize;
                wide = (int)(CartoonHeight*Scale);
                knot2.dx = (int)(((Long)wide*knot2.vnx)/size);
                knot2.dy = (int)(((Long)wide*knot2.vny)/size);
                knot2.dz = (int)(((Long)wide*knot2.vnz)/size);
            } else if( (group->flag|group->gnext->flag)&RibbonFlag )
                CalculateVInten( &knot2 );
        }
 
        if( !(col1 = group->col1) )
            col1 = captr->col;
 
        if( prev )
        {   /* Approximate spline segment with plane! */
            /* SolidRibbon( &knot1, &knot2, col1 );   */
 
            /* Calculate Hermite Spline Points */
            mid1.px = (int)(((Long)54*knot1.px + (Long)9*knot1.tx +
                             (Long)10*knot2.px - (Long)3*knot2.tx)/64);
            mid1.py = (int)(((Long)54*knot1.py + (Long)9*knot1.ty +
                             (Long)10*knot2.py - (Long)3*knot2.ty)/64);
            mid1.pz = (int)(((Long)54*knot1.pz + (Long)9*knot1.tz +
                             (Long)10*knot2.pz - (Long)3*knot2.tz)/64);
 
            mid2.px = (int)(((Long)4*knot1.px + knot1.tx +
                             (Long)4*knot2.px - knot2.tx)/8);
            mid2.py = (int)(((Long)4*knot1.py + knot1.ty +
                             (Long)4*knot2.py - knot2.ty)/8);
            mid2.pz = (int)(((Long)4*knot1.pz + knot1.tz +
                             (Long)4*knot2.pz - knot2.tz)/8);
 
            mid3.px = (int)(((Long)10*knot1.px + (Long)3*knot1.tx +
                             (Long)54*knot2.px - (Long)9*knot2.tx)/64);
            mid3.py = (int)(((Long)10*knot1.py + (Long)3*knot1.ty +
                             (Long)54*knot2.py - (Long)9*knot2.ty)/64);
            mid3.pz = (int)(((Long)10*knot1.pz + (Long)3*knot1.tz +
                             (Long)54*knot2.pz - (Long)9*knot2.tz)/64);
 
            if( group->flag & TraceFlag )
            {   wide = (int)(group->width*Scale);
                ClipCylinder( knot1.px, knot1.py, knot1.pz,
                              mid1.px, mid1.py, mid1.pz,
                              col1, col1, wide, ' ', wide );
                ClipCylinder( mid1.px, mid1.py, mid1.pz,
                              mid2.px, mid2.py, mid2.pz,
                              col1, col1, wide, ' ', wide );
                ClipCylinder( mid2.px, mid2.py, mid2.pz,
                              mid3.px, mid3.py, mid3.pz,
                              col1, col1, wide, ' ', wide );
                ClipCylinder( mid3.px, mid3.py, mid3.pz,
                              knot2.px, knot2.py, knot2.pz,
                              col1, col1, wide, ' ', wide );
            } else if( group->flag & DotsFlag )
            {   wide = (int)(group->width*Scale);
                ClipSphere(knot1.px,knot1.py,knot1.pz,wide,col1);
                ClipSphere(mid2.px, mid2.py, mid2.pz, wide,col1);
            } else
            {   /* Calculate Hermite Spline Widths */
                mid1.wx = (27*knot1.wx + 5*knot2.wx)/32;
                mid1.wy = (27*knot1.wy + 5*knot2.wy)/32;
                mid1.wz = (27*knot1.wz + 5*knot2.wz)/32;
 
                mid2.wx = (knot1.wx + knot2.wx)/2;
                mid2.wy = (knot1.wy + knot2.wy)/2;
                mid2.wz = (knot1.wz + knot2.wz)/2;
 
                mid3.wx = (5*knot1.wx + 27*knot2.wx)/32;
                mid3.wy = (5*knot1.wy + 27*knot2.wy)/32;
                mid3.wz = (5*knot1.wz + 27*knot2.wz)/32;
 
                /* Draw the Spline Segments */
                if( group->flag & (StrandFlag|DashStrandFlag) )
                {   if( !(col2 = group->col2) )
                        col2 = captr->col;
                    if( group->flag & StrandFlag )
                    {   StrandRibbon( &knot1, &mid1,  col1, col2 );
                        StrandRibbon( &mid1,  &mid2,  col1, col2 );
                        StrandRibbon( &mid2,  &mid3,  col1, col2 );
                        StrandRibbon( &mid3,  &knot2, col1, col2 );
                    } else /* group->flag & DashStrandFlag */
                    {   DashRibbon( &knot1, &mid1,  col1, col2 );
                        DashRibbon( &mid1,  &mid2,  col1, col2 );
                        DashRibbon( &mid2,  &mid3,  col1, col2 );
                        DashRibbon( &mid3,  &knot2, col1, col2 );
                    }
                } else /* Ribbon or Cartoon! */
                {   mid1.vsize = 0;
                    mid1.vnx = (int)(((Long)27*knot1.vnx +
                                      (Long) 5*knot2.vnx)/32);
                    mid1.vny = (int)(((Long)27*knot1.vny +
                                      (Long) 5*knot2.vny)/32);
                    mid1.vnz = (int)(((Long)27*knot1.vnz +
                                      (Long) 5*knot2.vnz)/32);
                    CalculateVInten( &mid1 );
 
                    mid2.vsize = 0;
                    mid2.vnx = (knot1.vnx + knot2.vnx)/2;
                    mid2.vny = (knot1.vny + knot2.vny)/2;
                    mid2.vnz = (knot1.vnz + knot2.vnz)/2;
                    CalculateVInten( &mid2 );
 
                    mid3.vsize = 0;
                    mid3.vnx = (int)(((Long) 5*knot1.vnx +
                                      (Long)27*knot2.vnx)/32);
                    mid3.vny = (int)(((Long) 5*knot1.vny +
                                      (Long)27*knot2.vny)/32);
                    mid3.vnz = (int)(((Long) 5*knot1.vnz +
                                      (Long)27*knot2.vnz)/32);
                    CalculateVInten( &mid3 );
 
                    if( group->flag & RibbonFlag )
                    {   if( group->struc & HelixFlag )
                        {   if( !(col2 = group->col2) )
                                col2 = captr->col;                          
                        } else col2 = col1;
                        
                        if( col1 != col2 )
                        {   SolidRibbon2( &knot1, &mid1,  col1, col2 );
                            SolidRibbon2( &mid1,  &mid2,  col1, col2 );
                            SolidRibbon2( &mid2,  &mid3,  col1, col2 );
                            SolidRibbon2( &mid3,  &knot2, col1, col2 );
                        } else
                        {   SolidRibbon( &knot1, &mid1,  col1 );
                            SolidRibbon( &mid1,  &mid2,  col1 );
                            SolidRibbon( &mid2,  &mid3,  col1 );
                            SolidRibbon( &mid3,  &knot2, col1 );
                        }
                    } else /* Cartoon! */
                    {   /* Calculate Spline Heights */
                        wide = (int)(CartoonHeight*Scale);
 
                        size = mid1.vsize;
                        mid1.dx = (int)(((Long)wide*mid1.vnx)/size);
                        mid1.dy = (int)(((Long)wide*mid1.vny)/size);
                        mid1.dz = (int)(((Long)wide*mid1.vnz)/size);
 
                        size = mid2.vsize;
                        mid2.dx = (int)(((Long)wide*mid2.vnx)/size);
                        mid2.dy = (int)(((Long)wide*mid2.vny)/size);
                        mid2.dz = (int)(((Long)wide*mid2.vnz)/size);
 
                        size = mid3.vsize;
                        mid3.dx = (int)(((Long)wide*mid3.vnx)/size);
                        mid3.dy = (int)(((Long)wide*mid3.vny)/size);
                        mid3.dz = (int)(((Long)wide*mid3.vnz)/size);
 
                        /* Calculate Surface Intensity */
                        mid1.hsize = 0;
                        mid1.hnx = (int)(((Long)27*knot1.hnx +
                                          (Long) 5*knot2.hnx)/32);
                        mid1.hny = (int)(((Long)27*knot1.hny +
                                          (Long) 5*knot2.hny)/32);
                        mid1.hnz = (int)(((Long)27*knot1.hnz +
                                          (Long) 5*knot2.hnz)/32);
                        CalculateHInten( &mid1 );
 
                        mid2.hsize = 0;
                        mid2.hnx = (knot1.hnx + knot2.hnx)/2;
                        mid2.hny = (knot1.hny + knot2.hny)/2;
                        mid2.hnz = (knot1.hnz + knot2.hnz)/2;
                        CalculateHInten( &mid2 );
 
                        mid3.hsize = 0;
                        mid3.hnx = (int)(((Long) 5*knot1.hnx +
                                          (Long)27*knot2.hnx)/32);
                        mid3.hny = (int)(((Long) 5*knot1.hny +
                                          (Long)27*knot2.hny)/32);
                        mid3.hnz = (int)(((Long) 5*knot1.hnz +
                                          (Long)27*knot2.hnz)/32);
                        CalculateHInten( &mid3 );
 
                        RectRibbon( &knot1, &mid1,  col1 );
                        RectRibbon( &mid1,  &mid2,  col1 );
                        RectRibbon( &mid2,  &mid3,  col1 );
                        RectRibbon( &mid3,  &knot2, col1 );
                    }
                }
            }
        } else if( group == chain->glist )
        {   knot1 = knot2;
            knot1.px = captr->x;
            knot1.py = captr->y;
            knot1.pz = captr->z;
 
            if( group->flag & RibbonFlag )
            {   SolidRibbon( &knot1, &knot2, col1 );    
            } else if( group->flag & RibbonFlag )
            {   RectRibbon( &knot1, &knot2, col1 );
            } else if( group->flag & StrandFlag )
            {   if( !(col2 = group->col2) )
                    col2 = captr->col;
                StrandRibbon( &knot1,  &knot2, col1, col2 );
            } else if( group->flag & DashStrandFlag )
            {   if( !(col2 = group->col2) )
                    col2 = captr->col;
                DashRibbon( &knot1,  &knot2, col1, col2 );
            } else if( group->flag & TraceFlag )
            {   ClipCylinder( knot1.px, knot1.py, knot1.pz,
                              knot2.px, knot2.py, knot2.pz,
                              col1, col1, (int)(group->width*Scale),
                              ' ',  (int)(group->width*Scale) );
            } else if( group->flag & DotsFlag )
            {   wide = (int)(group->width*Scale);
                ClipSphere(knot1.px,knot1.py,knot1.pz,wide,col1);
            }
            prev = True;
        } else prev = True;
        group = group->gnext;
        captr = next;
 
        knot1 = knot2;
    }
 
    if( prev )
    {   if( !(col1 = group->col1) )
            col1 = captr->col;
 
        if( group->flag & CartoonFlag )
        {   /* Test for arrow head! */
            if( DrawBetaArrows && (group->struc&SheetFlag) )
            {   wide = (3*group->width)>>1;
                knot2.px = captr->x + (knot2.tx/2);
                knot2.py = captr->y + (knot2.ty/2);
                knot2.pz = captr->z + (knot2.tz/2);
 
                arrow = True;
            } else
            {   wide = group->width;
                knot2.px = captr->x;
                knot2.py = captr->y;
                knot2.pz = captr->z;
                arrow = False;
            }
 
            wide = (int)(Scale*wide);
            if( (knot1.wide!=wide) && knot1.hsize )
            {   size = knot1.hsize;
                knot1.wx = (int)(((Long)wide*knot1.hnx)/size);
                knot1.wy = (int)(((Long)wide*knot1.hny)/size);
                knot1.wz = (int)(((Long)wide*knot1.hnz)/size);
 
                if( !arrow )
                {   knot2.wx = knot1.wx;
                    knot2.wy = knot1.wy;
                    knot2.wz = knot1.wz;
                } else
                {   knot2.wx = 0;
                    knot2.wy = 0;
                    knot2.wz = 0;
                }
            } else if( arrow )
            {   knot2.wx = 0;
                knot2.wy = 0;
                knot2.wz = 0;
            }
 
            RectRibbon( &knot1, &knot2, col1 );
        } else /* !Cartoon */
        {   knot2.px = captr->x;
            knot2.py = captr->y;
            knot2.pz = captr->z;
 
            if( group->flag & RibbonFlag )
            {   SolidRibbon( &knot1, &knot2, col1 );    
            } else if( group->flag & StrandFlag )
            {   if( !(col2 = group->col2) )
                    col2 = captr->col;
                StrandRibbon( &knot1,  &knot2, col1, col2 );
            } else if( group->flag & DashStrandFlag )
            {   if( !(col2 = group->col2) )
                    col2 = captr->col;
                DashRibbon( &knot1,  &knot2, col1, col2 );
            } else if( group->flag & TraceFlag )
            {   ClipCylinder( knot1.px, knot1.py, knot1.pz,
                              knot2.px, knot2.py, knot2.pz,
                              col1, col1, (int)(group->width*Scale),
                              ' ',  (int)(group->width*Scale) );
            } else if( group->flag & DotsFlag )
            {   wide = (int)(group->width*Scale);
                ClipSphere(knot1.px,knot1.py,knot1.pz,wide,col1);
                ClipSphere(knot2.px,knot2.py,knot2.pz,wide,col1);
            }   
        }
    }
}
 
 
void ResetRepres( void )
{
    DeleteSurface();
    DeleteMonitors();
    SolventDots = False;
    ProbeRadius = 0;

    ResetLabels();

    SurfaceChainsFlag = False;
    DrawMonitDistance = True;
    DrawBetaArrows = True;
    CartoonHeight = 100;
}


void InitialiseRepres( void )
{
    DotPtr = (DotStruct __far*)0;
    MonitList = (Monitor __far*)0;
    LabelList = (void*)0;

    FreeMonit = (Monitor __far*)0;
    FreeLabel = (void*)0;

    ResetRepres();
}


