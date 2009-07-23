/***************************************************************************
 *                              RasMol 2.7.5                               *
 *                                                                         *
 *                                 RasMol                                  *
 *                 Molecular Graphics Visualisation Tool                   *
 *                              13 June 2009                               *
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
 *Bernstein          RasMol 2.7.1   Jun 99         1998-2008               *
 *                   RasMol 2.7.1.1 Jan 01                                 *
 *                   RasMol 2.7.2   Aug 00                                 *
 *                   RasMol 2.7.2.1 Apr 01                                 *
 *                   RasMol 2.7.2.1.1 Jan 04                               *
 *                   RasMol 2.7.3   Feb 05                                 *
 *                   RasMol 2.7.3.1 Apr 06                                 *
 *                   RasMol 2.7.4   Nov 07                                 *
 *                   RasMol 2.7.4.1 Jan 08                                 *
 *                   RasMol 2.7.4.2 Mar 08                                 *
 *                   RasMol 2.7.5   May 09                                 *
 *                                                                         *
 * RasMol 2.7.5 incorporates changes by T. Ikonen, G. McQuillan, N. Darakev*
 * and L. Andrews (via the neartree package).  Work on RasMol 2.7.5        *
 * supported in part by grant 1R15GM078077-01 from the National Institute  *
 * of General Medical Sciences (NIGMS), U.S. National Institutes of Health *
 * and by grant ER63601-1021466-0009501 from the Office of Biological &    *
 * Environmental Research (BER), Office of Science, U. S. Department of    *
 * Energy.  RasMol 2.7.4 incorporated  changes by G. Todorov, Nan Jia,     *
 * N. Darakev, P. Kamburov, G. McQuillan, and J. Jemilawon. Work on RasMol *
 * 2.7.4 supported in part by grant 1R15GM078077-01 from the NIGMS/NIH and *
 * grant ER63601-1021466-0009501 from BER/DOE.  RasMol 2.7.3 incorporates  *
 * changes by Clarice Chigbo, Ricky Chachra, and Mamoru Yamanishi.  Work   *
 * on RasMol 2.7.3 supported in part by grants DBI-0203064, DBI-0315281    *
 * and EF-0312612 from the U.S. National Science Foundation and grant      *
 * DE-FG02-03ER63601 from BER/DOE. The content is solely the responsibility*
 * of the authors and does not necessarily represent the official views of *
 * the funding organizations.                                              *
 *                                                                         *
 * The code for use of RasMol under GTK in RasMol 2.7.4.2 and 2.7.5 was    *
 * written by Teemu Ikonen.                                                *
 *                                                                         *
 *                    and Incorporating Translations by                    *
 *  Author                               Item                     Language *
 *  Isabel Servan Martinez,                                                *
 *  Jose Miguel Fernandez Fernandez      2.6   Manual             Spanish  *
 *  Jose Miguel Fernandez Fernandez      2.7.1 Manual             Spanish  *
 *  Fernando Gabriel Ranea               2.7.1 menus and messages Spanish  *
 *  Jean-Pierre Demailly                 2.7.1 menus and messages French   *
 *  Giuseppe Martini, Giovanni Paolella, 2.7.1 menus and messages          *
 *  A. Davassi, M. Masullo, C. Liotto    2.7.1 help file          Italian  *
 *  G. Pozhvanov                         2.7.3 menus and messages Russian  *
 *  G. Todorov                           2.7.3 menus and messages Bulgarian*
 *  Nan Jia, G. Todorov                  2.7.3 menus and messages Chinese  *
 *  Mamoru Yamanishi, Katajima Hajime    2.7.3 menus and messages Japanese *
 *                                                                         *
 *                             This Release by                             *
 * Herbert J. Bernstein, Bernstein + Sons, 5 Brewster Ln, Bellport, NY, USA*
 *                       yaya@bernstein-plus-sons.com                      *
 *               Copyright(C) Herbert J. Bernstein 1998-2008               *
 *                                                                         *
 *                READ THE FILE NOTICE FOR RASMOL LICENSES                 *
 *Please read the file NOTICE for important notices which apply to this    *
 *package and for license terms (GPL or RASLIC).                           *
 ***************************************************************************/
/* repres.c
 $Log$
 Revision 1.22  2008/06/11 01:42:41  yaya
 Finish map surface update. -- HJB

 Revision 1.21  2008/04/01 17:31:19  hk0i
 updated new color mode feature for dots

 Revision 1.20  2008/03/22 18:42:55  yaya
 Post release cleanup and credit to Ikonen in file headers. -- HJB

 Revision 1.19  2008/03/17 03:01:31  yaya
 Update to agree with 2.7.4.2 release and T. Ikonen GTK mods -- HJB

 Revision 1.6  2008/03/17 01:32:41  yaya
 Add gtk mods by tpikonen, and intergate with 2.7.4.2 mods -- HJB

 Revision 1.18  2008/03/16 22:25:22  yaya
 Align comments with production version; Update rasmol_install and
 rasmol_run shell scripts for Japanese and Chinese; Align logic for
 positioning and sizing initial window with windows version -- HJB

 Revision 1.5  2008/01/30 03:15:55  yaya
 More post 2.7.4.1 release cleanup -- HJB

 Revision 1.17  2008/01/29 04:12:11  yaya
 Post release cleanup of problems discovered. -- HJB

 Revision 1.4  2008/01/29 04:35:26  yaya
 Postrelease update to fix problems discovered -- HJB

 Revision 1.3  2008/01/28 03:29:38  yaya
 Update CVS to RasMol_2.7.4.1 -- HJB

 Revision 1.16  2008/01/16 21:35:11  yaya
 Change default resolution from .5 Angstrom to 1 Angstrom
 Correct map xlow, xhigh calculations
 Correct map axis output -- HJB

 Revision 1.15  2007/12/14 02:04:50  yaya
 Correct Chinese data for missing line in langsel_utf.c
 Rewrite code for handling of slab mode in stereo -- HJB

 Revision 1.14  2007/11/19 03:28:40  yaya
 Update to credits for 2.7.4 in manual and headers
 Mask code added -- HJB

 Revision 1.13  2007/11/16 22:48:30  yaya
 Remove use of MapNumber if favor of size of vector
 Clean up selection logic; start on script writing code -- HJB

 Revision 1.12  2007/11/13 03:22:17  yaya
 Changes to support map selectors.  Needs more work. -- HJB

 Revision 1.11  2007/10/31 03:02:55  yaya
 Fix for gaps in map surface and removal of debug normals and points
 Add strcasestr for systems that don't support it
 Set up installer for windows -- HJB

 Revision 1.10  2007/10/29 02:29:36  yaya
 Fix stereo offset for map surfaces and other uses of ClipPoly
 Decouple mesh from surface for maps
 Experiment with alternatives for normals calculation -- to
 be continued -- HJB

 Revision 1.9  2007/10/23 02:27:55  yaya
 Preliminary mods for revised PDB format derived from Rutgers mods.
 Partial changes for map tangles -- HJB

 Revision 1.8  2007/10/22 00:46:54  yaya
 Add start of code for normal to map needed for solid surface.
 Make new title revisions contingent on Interactive flag.
 --HJB

 Revision 1.7  2007/09/03 14:25:10  yaya
 Upload of more of the map load and map generate commands -- HJB

 Revision 1.6  2007/08/03 02:02:34  yaya
 Add MEAN to map level command, and move the various map settings
 under the map command, and set the defaults to make a nice map
 on a default generate (spread .1667, level mean, spacing .5) -- HJB

 Revision 1.5  2007/07/14 14:09:03  yaya
 Update to command.c to add load option for maps
 Introduce display to map bonds

 Revision 1.4  2007/07/09 13:57:06  yaya
 Add spacing and spread commands -- HJB

 Revision 1.3  2007/07/07 21:54:31  yaya
 Next round of preliminary updates for maps, allowing multiple maps,
 code to set the contour level and some fixes to the languages files -- HJB

 Revision 1.2  2007/07/02 12:44:39  yaya
 Partial preliminary map code -- HJB

 Revision 1.1.1.1  2007/03/01 01:16:32  todorovg
 Chinese working versio from rasmol_ru initial import

 Revision 1.4  2006/11/01 03:23:51  yaya
 Update NSIS windows installer for more script types and to fix
 misplaced script instructions for data files; add document and
 script icons directly in raswin.exe; add credit line to
 G. A. Pozhvanov in comments for Russian translations. -- HJB

 Revision 1.3  2006/10/20 13:53:02  yaya
 Move about dialog flag file RASWIN.FLG to APPDATA style directories
 Translate three "not founds" that had been missed before -- HJB

 Revision 1.2  2006/09/17 10:53:56  yaya
 Clean up headers and start on code for X11 -- HJB

 Revision 1.1.1.1  2006/09/16 18:45:59  yaya
 Start of RasMol Russian Translation Project based on translations
 by Gregory A. Pozhvanov of Saint Petersburg State University -- HJB

 Revision 1.2  2006/06/19 22:06:41  todorovg
 Rasmol 2.7.3.1

 Revision 1.1.1.1  2006/06/19 22:05:14  todorovg
 Initial Rasmol 2.7.3 Import

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
#include "langsel.h"
#include "maps.h"


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
        _ffree(ptr->label);
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
        _ffree(label->label);
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
    } else if( !(ptr=(Label*)_fmalloc(sizeof(Label))) )
        FatalRepresError("label");
 
    ptr->label = (char*)_fmalloc(len+1);
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
            if( !ZBValid(aptr->x,aptr->z) )
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
      Long dist, unsigned char units, int monmode )
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
    } else if( !(ptr=(Monitor*)_fmalloc(sizeof(Monitor))) )
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
    Long temp;
 
    temp = (Long)rint(100.0*CalcDistance(src,dst));

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
        WriteString(buffer); WriteString(MsgStrs[StrNotFnd]);
 
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
            if( ZBValid( (s->x+d->x)/2, (s->z+d->z)/2 ) )
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

	DotCount = density;
 
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
                    if( ZBValid(xi,zi))
                        PlotDeepPoint(xi,yi,zi,ptr->col[i]);
                }
            }
        }
     ReDrawFlag |= RFRefresh;

}
 
void DisplayMapPoints( void )
{
    register int xi,yi,zi;
    register Real x,y,z;
    register int i, j, irad;
    register int Cenx,Ceny,Cenz;
    MapPointVec __far *MapPointsPtr;
    MapInfo mapinfo;
    
    Cenx=(int)rint(CenX*MatX[0]+CenY*MatX[1]+CenZ*MatX[2]);
    Ceny=(int)rint(CenX*MatY[0]+CenY*MatY[1]+CenZ*MatY[2]);
    Cenz=(int)rint(CenX*MatZ[0]+CenY*MatZ[1]+CenZ*MatZ[2]);

    if (MapInfoPtr)
      for (j=0; j<MapInfoPtr->size; j++) {
      	vector_get_element((GenericVec __far *)MapInfoPtr,(void __far *)&mapinfo,j );
      	MapPointsPtr = mapinfo.MapPointsPtr;
      	irad = (int)rint(Scale*(Real)(mapinfo.MapMeshRad));

        if (MapPointsPtr && (mapinfo.flag&MapPointFlag) )
        for (i=0; i<MapPointsPtr->size; i++) {
        	x = (MapPointsPtr->array[i]).xpos;
        	y = (MapPointsPtr->array[i]).ypos;
        	z = (MapPointsPtr->array[i]).zpos;
 
            xi = (int)rint(x*MatX[0]+y*MatX[1]+z*MatX[2])+XOffset-Cenx;
            if( XValid(xi) ) { 
              yi = (int)rint(x*MatY[0]+y*MatY[1]+z*MatY[2])+YOffset-Ceny;
              if( YValid(yi) ) { 
                zi = (int)rint(x*MatZ[0]+y*MatZ[1]+z*MatZ[2])+ZOffset-Cenz;
                if( ZBValid(xi,zi)  ) {
                  if (irad <= 0 && ZBValid(xi,zi) ) {
                    PlotDeepPoint(xi,yi,zi,(MapPointsPtr->array[i]).col);
                  } else  {
                    ClipSphere(xi,yi,zi,irad,(MapPointsPtr->array[i]).col);
                  }
                  }
                }
              }
            }
        }
    ReDrawFlag |= RFRefresh;

}

void DisplayMapBonds( void )
{
    register int xsrc,ysrc,zsrc,xdst,ydst,zdst;
    register Real x1,y1,z1,x2,y2,z2;
    register int i, j, irad;
    register int src, dst;
    register int Cenx,Ceny,Cenz;
    MapPointVec __far *MapPointsPtr;
    MapBondVec __far *MapBondsPtr;
    MapInfo mapinfo;
    
    Cenx=(int)rint(CenX*MatX[0]+CenY*MatX[1]+CenZ*MatX[2]);
    Ceny=(int)rint(CenX*MatY[0]+CenY*MatY[1]+CenZ*MatY[2]);
    Cenz=(int)rint(CenX*MatZ[0]+CenY*MatZ[1]+CenZ*MatZ[2]);

    if (MapInfoPtr)
      for (j=0; j<MapInfoPtr->size; j++) {
      	vector_get_element((GenericVec __far *)MapInfoPtr,(void __far *)&mapinfo,j );
      	MapPointsPtr = mapinfo.MapPointsPtr;
      	MapBondsPtr = mapinfo.MapBondsPtr;
      	irad = (int)rint(Scale*(Real)(mapinfo.MapMeshRad));
      	
      	if (MapBondsPtr && (mapinfo.flag&MapMeshFlag))
      	for (i=0; i<MapBondsPtr->size; i++) {
      	  src = (MapBondsPtr->array[i]).src;
      	  dst = (MapBondsPtr->array[i]).dst;
          x1 = (MapPointsPtr->array[src]).xpos;
          y1 = (MapPointsPtr->array[src]).ypos;
          z1 = (MapPointsPtr->array[src]).zpos;
          x2 = (MapPointsPtr->array[dst]).xpos;
          y2 = (MapPointsPtr->array[dst]).ypos;
          z2 = (MapPointsPtr->array[dst]).zpos;
          xsrc = (int)rint(x1*MatX[0]+y1*MatX[1]+z1*MatX[2])+XOffset-Cenx;
          ysrc = (int)rint(x1*MatY[0]+y1*MatY[1]+z1*MatY[2])+YOffset-Ceny;
          zsrc = (int)rint(x1*MatZ[0]+y1*MatZ[1]+z1*MatZ[2])+ZOffset-Cenz;
          xdst = (int)rint(x2*MatX[0]+y2*MatX[1]+z2*MatX[2])+XOffset-Cenx;
          ydst = (int)rint(x2*MatY[0]+y2*MatY[1]+z2*MatY[2])+YOffset-Ceny;
          zdst = (int)rint(x2*MatZ[0]+y2*MatZ[1]+z2*MatZ[2])+ZOffset-Cenz;
          if (irad>0) {
          	ClipCylinder(xsrc,ysrc,zsrc,xdst,ydst,zdst,
          	  (MapPointsPtr->array[src]).col,
              (MapPointsPtr->array[dst]).col,
              irad, ' ', ' ');
          } else {
            if ((mapinfo.flag&MapMeshDashFlag) == MapMeshDashFlag ) {
              ClipDashVector(xsrc,ysrc,zsrc,xdst,ydst,zdst,
                (MapPointsPtr->array[src]).col,
                (MapPointsPtr->array[dst]).col,' ');
            } else {
              ClipTwinVector(xsrc,ysrc,zsrc,xdst,ydst,zdst,
                (MapPointsPtr->array[src]).col,
                (MapPointsPtr->array[dst]).col,' ');
            }  
          }
      	}
      	
    }
}

void DisplayMapTangles( void ) {

    register Real x1,y1,z1,x2,y2,z2,x3,y3,z3;
    register int i, j, ii;
    register int src, dst, oth;
    register int Cenx,Ceny,Cenz;
    Long normals[3][3];
    Long* worldnormals[3];
    MapPointVec __far *MapPointsPtr;
    MapTangleVec __far *MapTanglePtr;
    MapInfo mapinfo;
    Poly tangle, tangletemp;
    int inten[4];
    
    Cenx=(int)rint(CenX*MatX[0]+CenY*MatX[1]+CenZ*MatX[2]);
    Ceny=(int)rint(CenX*MatY[0]+CenY*MatY[1]+CenZ*MatY[2]);
    Cenz=(int)rint(CenX*MatZ[0]+CenY*MatZ[1]+CenZ*MatZ[2]);

    if (MapInfoPtr)
      for (j=0; j<MapInfoPtr->size; j++) {
      	vector_get_element((GenericVec __far *)MapInfoPtr,(void __far *)&mapinfo,j );
      	MapPointsPtr = mapinfo.MapPointsPtr;
      	MapTanglePtr = mapinfo.MapTanglePtr;
      	
      	if (MapTanglePtr && (mapinfo.flag&MapSurfFlag))
      	for (i=0; i<MapTanglePtr->size; i++) {
      	  src = (MapTanglePtr->array[i]).points[0];
      	  dst = (MapTanglePtr->array[i]).points[1];
      	  oth = (MapTanglePtr->array[i]).points[2];
      	  x1 = (MapPointsPtr->array[src]).xpos;
          y1 = (MapPointsPtr->array[src]).ypos;
          z1 = (MapPointsPtr->array[src]).zpos;
          x2 = (MapPointsPtr->array[dst]).xpos;
          y2 = (MapPointsPtr->array[dst]).ypos;
          z2 = (MapPointsPtr->array[dst]).zpos;
          x3 = (MapPointsPtr->array[oth]).xpos;
          y3 = (MapPointsPtr->array[oth]).ypos;
          z3 = (MapPointsPtr->array[oth]).zpos;
          tangle.v[0].x = (int)rint(x1*MatX[0]+y1*MatX[1]+z1*MatX[2])+XOffset-Cenx;
          tangle.v[0].y = (int)rint(x1*MatY[0]+y1*MatY[1]+z1*MatY[2])+YOffset-Ceny;
          tangle.v[0].z = (int)rint(x1*MatZ[0]+y1*MatZ[1]+z1*MatZ[2])+ZOffset-Cenz;
          tangle.v[1].x = (int)rint(x2*MatX[0]+y2*MatX[1]+z2*MatX[2])+XOffset-Cenx;
          tangle.v[1].y = (int)rint(x2*MatY[0]+y2*MatY[1]+z2*MatY[2])+YOffset-Ceny;
          tangle.v[1].z = (int)rint(x2*MatZ[0]+y2*MatZ[1]+z2*MatZ[2])+ZOffset-Cenz;
          tangle.v[2].x = (int)rint(x3*MatX[0]+y3*MatX[1]+z3*MatX[2])+XOffset-Cenx;
          tangle.v[2].y = (int)rint(x3*MatY[0]+y3*MatY[1]+z3*MatY[2])+YOffset-Ceny;
          tangle.v[2].z = (int)rint(x3*MatZ[0]+y3*MatZ[1]+z3*MatZ[2])+ZOffset-Cenz;
          worldnormals[0]=(MapPointsPtr->array[src]).Un;
          worldnormals[1]=(MapPointsPtr->array[dst]).Un;
          worldnormals[2]=(MapPointsPtr->array[oth]).Un;
          for (ii=0; ii<3; ii++ ) {
            normals[ii][0] = ((Long)rint((worldnormals[ii][0]*RotX[0]+worldnormals[ii][1]*RotX[1]+worldnormals[ii][2]*RotX[2]))/32.);
            normals[ii][1] = ((Long)rint((worldnormals[ii][0]*RotY[0]+worldnormals[ii][1]*RotY[1]+worldnormals[ii][2]*RotY[2]))/32.);
            normals[ii][2] = ((Long)rint((worldnormals[ii][0]*RotZ[0]+worldnormals[ii][1]*RotZ[1]+worldnormals[ii][2]*RotZ[2]))/32.);
          }
          inten[0] = LightDot(normals[0][0],normals[0][1],normals[0][2]);
          if (inten[0] > 0) {
             inten[0] = ((inten[0]*colconst(128))>>ColBits);
             if (inten[0] > ColourMask) inten[0] = ColourMask;
          } else {
          	 inten[0] = 0;
          }
          tangle.v[0].inten =  (MapPointsPtr->array[src]).col+inten[0];
          inten[1] = LightDot(normals[1][0],normals[1][1],normals[1][2]);
          if (inten[1] > 0) {
             inten[1] = ((inten[1]*colconst(128))>>ColBits);
             if (inten[1] > ColourMask) inten[1] = ColourMask;
          } else {
          	 inten[1] = 0;
          }
          tangle.v[1].inten = (MapPointsPtr->array[dst]).col+inten[1];
          inten[2] = LightDot(normals[2][0],normals[2][1],normals[2][2]);
          if (inten[2] > 0) {
             inten[2] = ((inten[2]*colconst(128))>>ColBits);
             if (inten[2] > ColourMask) inten[2] = ColourMask;
          } else {
          	 inten[2] = 0;
          }
          tangle.v[2].inten = (MapPointsPtr->array[oth]).col+inten[2];
          tangle.count = 3;
            
          /* If all three corners are the same color and vary only in
             intensity, render as a single triangle
           */
          if (((MapPointsPtr->array[oth]).col ==  (MapPointsPtr->array[dst]).col)
              &&  ((MapPointsPtr->array[dst]).col == (MapPointsPtr->array[src]).col)) {
            ClipPolygon(&tangle);
          } else {
              /* The three corners vary in color.  Introduce the midpoint of
                 the original triangle, and render as up to 6 monchrome triangles
                 using edge midpoints when the edge is not of one color
               */
              tangletemp.count = 3;
              tangletemp.v[2].x = (tangle.v[0].x+tangle.v[1].x+tangle.v[2].x)/3;
              tangletemp.v[2].y = (tangle.v[0].y+tangle.v[1].y+tangle.v[2].y)/3;
              tangletemp.v[2].z = (tangle.v[0].z+tangle.v[1].z+tangle.v[2].z)/3;
              tangletemp.v[0].x = tangle.v[0].x;
              tangletemp.v[0].y = tangle.v[0].y;
              tangletemp.v[0].z = tangle.v[0].z;
              inten[3] = (inten[0]+inten[1]+inten[2]+2)/3;
              if ((MapPointsPtr->array[dst]).col == (MapPointsPtr->array[src]).col){
                  tangletemp.v[1].x = tangle.v[1].x;
                  tangletemp.v[1].y = tangle.v[1].y;
                  tangletemp.v[1].z = tangle.v[1].z;
                  tangletemp.v[0].inten = tangle.v[0].inten;
                  tangletemp.v[1].inten = tangle.v[1].inten;
                  tangletemp.v[2].inten = (MapPointsPtr->array[src]).col+inten[3];
                  ClipPolygon(&tangletemp);
              } else {
                  tangletemp.v[1].x = (tangle.v[0].x+tangle.v[1].x)/2;
                  tangletemp.v[1].y = (tangle.v[0].y+tangle.v[1].y)/2;
                  tangletemp.v[1].z = (tangle.v[0].z+tangle.v[1].z)/2;
                  tangletemp.v[0].inten = tangle.v[0].inten;
                  tangletemp.v[1].inten = (MapPointsPtr->array[src]).col+(inten[0]+inten[1]+1)/2;
                  tangletemp.v[2].inten = (MapPointsPtr->array[src]).col+inten[3];
                  ClipPolygon(&tangletemp);
                  tangletemp.v[0].x = tangle.v[1].x;
                  tangletemp.v[0].y = tangle.v[1].y;
                  tangletemp.v[0].z = tangle.v[1].z;
                  tangletemp.v[0].inten = tangle.v[1].inten;
                  tangletemp.v[1].inten = (MapPointsPtr->array[dst]).col+(inten[0]+inten[1]+1)/2;
                  tangletemp.v[2].inten = (MapPointsPtr->array[dst]).col+inten[3];
                  ClipPolygon(&tangletemp);
             }
              tangletemp.v[0].x = tangle.v[1].x;
              tangletemp.v[0].y = tangle.v[1].y;
              tangletemp.v[0].z = tangle.v[1].z;
              if ((MapPointsPtr->array[dst]).col == (MapPointsPtr->array[oth]).col){
                  tangletemp.v[1].x = tangle.v[2].x;
                  tangletemp.v[1].y = tangle.v[2].y;
                  tangletemp.v[1].z = tangle.v[2].z;
                  tangletemp.v[0].inten = tangle.v[1].inten;
                  tangletemp.v[1].inten = tangle.v[2].inten;
                  tangletemp.v[2].inten = (MapPointsPtr->array[dst]).col+inten[3];
                  ClipPolygon(&tangletemp);
              } else {
                  tangletemp.v[1].x = (tangle.v[1].x+tangle.v[2].x)/2;
                  tangletemp.v[1].y = (tangle.v[1].y+tangle.v[2].y)/2;
                  tangletemp.v[1].z = (tangle.v[1].z+tangle.v[2].z)/2;
                  tangletemp.v[0].inten = tangle.v[1].inten;
                  tangletemp.v[1].inten = (MapPointsPtr->array[dst]).col+(inten[1]+inten[2]+1)/2;
                  tangletemp.v[2].inten = (MapPointsPtr->array[dst]).col+inten[3];
                  ClipPolygon(&tangletemp);
                  tangletemp.v[0].x = tangle.v[2].x;
                  tangletemp.v[0].y = tangle.v[2].y;
                  tangletemp.v[0].z = tangle.v[2].z;
                  tangletemp.v[0].inten = tangle.v[2].inten;
                  tangletemp.v[1].inten = (MapPointsPtr->array[oth]).col+(inten[1]+inten[2]+1)/2;
                  tangletemp.v[2].inten = (MapPointsPtr->array[oth]).col+inten[3];
                  ClipPolygon(&tangletemp);
              }
              tangletemp.v[0].x = tangle.v[2].x;
              tangletemp.v[0].y = tangle.v[2].y;
              tangletemp.v[0].z = tangle.v[2].z;
              if ((MapPointsPtr->array[oth]).col == (MapPointsPtr->array[src]).col){
                  tangletemp.v[1].x = tangle.v[0].x;
                  tangletemp.v[1].y = tangle.v[0].y;
                  tangletemp.v[1].z = tangle.v[0].z;
                  tangletemp.v[0].inten = tangle.v[2].inten;
                  tangletemp.v[1].inten = tangle.v[0].inten;
                  tangletemp.v[2].inten = (MapPointsPtr->array[oth]).col+inten[3];
                  ClipPolygon(&tangletemp);
              } else {
                  tangletemp.v[1].x = (tangle.v[2].x+tangle.v[0].x)/2;
                  tangletemp.v[1].y = (tangle.v[2].y+tangle.v[0].y)/2;
                  tangletemp.v[1].z = (tangle.v[2].z+tangle.v[0].z)/2;
                  tangletemp.v[0].inten = tangle.v[2].inten;
                  tangletemp.v[1].inten = (MapPointsPtr->array[oth]).col+(inten[2]+inten[0]+1)/2;
                  tangletemp.v[2].inten = (MapPointsPtr->array[oth]).col+inten[3];
                  ClipPolygon(&tangletemp);
                  tangletemp.v[0].x = tangle.v[0].x;
                  tangletemp.v[0].y = tangle.v[0].y;
                  tangletemp.v[0].z = tangle.v[0].z;
                  tangletemp.v[0].inten = tangle.v[0].inten;
                  tangletemp.v[1].inten = (MapPointsPtr->array[src]).col+(inten[2]+inten[0]+1)/2;
                  tangletemp.v[2].inten = (MapPointsPtr->array[src]).col+inten[3];
                  ClipPolygon(&tangletemp);
              }
          }
          /* Debug code for surface normals */ 
          /* for(ii=0;ii<3;ii++) {
            ClipTwinVector(tangle.v[ii].x,tangle.v[ii].y,tangle.v[ii].z,
              tangle.v[ii].x+normals[ii][0]/10,tangle.v[ii].y+normals[ii][1]/10,tangle.v[ii].z+normals[ii][2]/10,
               (MapPointsPtr->array[dst]).col,(MapPointsPtr->array[dst]).col,' ');          	
          } */
      		
      	}
      }
    


      }

/*==============================*/
/*  Ribbon & Cartoon Functions  */
/*==============================*/
 
void CalculateVInten( Knot *ptr )
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
 

void CalculateHInten( Knot *ptr )
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
    MapInfoPtr = (MapInfoVec __far *)0;
    MapLevel = 0.0;
    MapFlag = MapMeanFlag|MapScaleFlag;
    MapSpacing = 250L;
    MapSpread = .6667;
    MapRGBCol[0] = 0xFA;
    MapRGBCol[1] = 0xFF;
    MapRGBCol[2] = 0xFA;
    MapPointRad=0;
    MapMeshRad=0;
    MapLabel=NULL;
    MonitList = (Monitor __far*)0;
    LabelList = (void*)0;

    FreeMonit = (Monitor __far*)0;
    FreeLabel = (void*)0;

    ResetRepres();
}


