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
/* render.c
 $Log$
 Revision 1.12  2008/03/22 18:42:54  yaya
 Post release cleanup and credit to Ikonen in file headers. -- HJB

 Revision 1.11  2008/03/17 03:01:31  yaya
 Update to agree with 2.7.4.2 release and T. Ikonen GTK mods -- HJB

 Revision 1.5  2008/03/17 01:32:41  yaya
 Add gtk mods by tpikonen, and intergate with 2.7.4.2 mods -- HJB

 Revision 1.10  2008/03/16 22:25:22  yaya
 Align comments with production version; Update rasmol_install and
 rasmol_run shell scripts for Japanese and Chinese; Align logic for
 positioning and sizing initial window with windows version -- HJB

 Revision 1.4  2008/01/30 03:15:55  yaya
 More post 2.7.4.1 release cleanup -- HJB

 Revision 1.9  2008/01/29 04:12:11  yaya
 Post release cleanup of problems discovered. -- HJB

 Revision 1.3  2008/01/28 03:29:38  yaya
 Update CVS to RasMol_2.7.4.1 -- HJB

 Revision 1.8  2008/01/05 20:56:29  yaya
 Update handling of stereo interaction with slab
 Enable save of CBF-style maps. -- HJB

 Revision 1.7  2007/12/14 02:04:50  yaya
 Correct Chinese data for missing line in langsel_utf.c
 Rewrite code for handling of slab mode in stereo -- HJB

 Revision 1.6  2007/11/19 03:28:39  yaya
 Update to credits for 2.7.4 in manual and headers
 Mask code added -- HJB

 Revision 1.5  2007/10/23 02:27:55  yaya
 Preliminary mods for revised PDB format derived from Rutgers mods.
 Partial changes for map tangles -- HJB

 Revision 1.4  2007/07/14 14:09:03  yaya
 Update to command.c to add load option for maps
 Introduce display to map bonds

 Revision 1.3  2007/07/07 21:54:31  yaya
 Next round of preliminary updates for maps, allowing multiple maps,
 code to set the contour level and some fixes to the languages files -- HJB

 Revision 1.2  2007/07/02 12:44:39  yaya
 Partial preliminary map code -- HJB

 Revision 1.1.1.1  2007/03/01 01:16:32  todorovg
 Chinese working versio from rasmol_ru initial import

 Revision 1.3  2006/11/01 03:23:51  yaya
 Update NSIS windows installer for more script types and to fix
 misplaced script instructions for data files; add document and
 script icons directly in raswin.exe; add credit line to
 G. A. Pozhvanov in comments for Russian translations. -- HJB

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

 Revision 1.4  2004/02/15 00:24:00  yaya
 *** empty log message ***

 Revision 1.3  2003/12/13 19:26:11  yaya
 *** empty log message ***

 Revision 1.2  2003/12/12 21:10:38  yaya
 *** empty log message ***

 * Revision 1.1  2002/04/14  14:15:17  14:15:17  yaya (Herbert J. Bernstein(Non-HP))
 * Initial revision
 * 
 Revision 1.1  2001/01/31 02:13:45  yaya
 Initial revision

 Revision 1.8  2000/08/27 16:09:25  yaya
 monitor dynamics extensions

 Revision 1.7  2000/08/26 18:12:42  yaya
 Updates to header comments in all files

 Revision 1.6  2000/08/26 03:14:09  yaya
 Mods for mac compilations

 Revision 1.5  2000/08/18 16:40:39  yaya
 *** empty log message ***

 Revision 1.4  2000/08/13 20:56:27  yaya
 Conversion from toolbar to menus

 Revision 1.3  2000/08/09 01:18:14  yaya
 Rough cut with ucb

 */
#include "rasmol.h"

#ifdef IBMPC
#include <malloc.h>
#endif
#ifdef MSWIN
#include <windows.h>
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

#define RENDER
#include "molecule.h"
#include "graphics.h"
#include "render.h"
#include "repres.h"
#include "abstree.h"
#include "transfor.h"
#include "command.h"
#include "cmndline.h"
#include "pixutils.h"
#include "cif_fract.h"
#include "multiple.h" /* [GSG 11/9/95] */
#include "vector.h"
#include "wbrotate.h"
#include "maps.h"

/* Avoid PowerPC Errors! */
#ifdef INFINITY
#undef INFINITY
#endif

#define PoolSize       16
#define ApproxZero     1.0E-3
#define INFINITY       200000
#define FUDGEFACTOR    1000



/* Macros for commonly used loops */
#define ForEachAtom  for(chain=Database->clist;chain;chain=chain->cnext) \
                     for(group=chain->glist;group;group=group->gnext)    \
                     for(aptr=group->alist;aptr;aptr=aptr->anext)
#define ForEachBond  for(bptr=Database->blist;bptr;bptr=bptr->bnext)
#define ForEachSurfBond  for(sbptr=Database->sblist;sbptr;sbptr=sbptr->sbnext)
#define ForEachBack  for(chain=Database->clist;chain;chain=chain->cnext) \
                     for(bptr=chain->blist;bptr;bptr=bptr->bnext)


typedef struct { Real h,l; } Interval;

  
#if !defined(IBMPC) && !defined(APPLEMAC)
Card ColConstTable[MAXRAD];
#endif

static RAtom __far * __far *YBucket;
static RAtom __far * __far *IBuffer;
static int BuckY,ItemX;
static int FBufX,FBufY;
static int DBClear;

static RAtom __far *SBuffer;
static RAtom __far *Exclude;
static Real ShadowI, ShadowJ, ShadowK;
static int  ShadowX, ShadowY, ShadowZ;
static int deltax, deltay, deltaz;
static int xcord, ycord, zcord;
static int xflag, yflag, zflag;
static int xhash, yhash, zhash;
static int RayCount;

static Item __far *FreeItem;
static Real VoxRatio;
static int VoxelCount,InVoxCount;
static int VoxelsDone;

/* Identified Atom Info */
static AtomRef PickHist[4];
static Long IdentDist;
static int IdentFound;
static int IdentDepth;



/*=======================*/
/*  Function Prototypes  */
/*=======================*/

static void SqrInterval( Interval __far* );
static void VoxelInsert( RAtom __far*, int );
static int AtomInter( RAtom __far* );
static void TestAtomProximity( RAtom __far *, int, int );
static void DisplayHBonds( HBond __far *, int );



static void FatalRenderError( char *ptr )
{
    char buffer[80];

    sprintf(buffer,"Renderer Error: Unable to allocate %s!",ptr);
    RasMolFatalExit(buffer);
}


unsigned int isqrt( Card val )
{
#ifndef sun386
    register int i,result;
    register Card temp;
    register Card rem;

    i = 16;
    while( !(val&((Card)3<<30)) && i )
    {   val <<= 2;
        i--;
    }

    if( i )
    {   rem = (val>>30)-1;
        val <<= 2;
        result = 1;
        i--;

        while( i )
        {   rem = (rem<<2) | (val>>30);
            result <<= 1;
            val <<= 2;

            temp = result<<1;
            if( rem > temp )
            {   rem -= temp|1;
                result |= 1;
            }
            i--;
        }
        return( result );
    } else return( 0 );
#else
    return( (int)sqrt((double)val) );
#endif
}



/*=============================*/
/*  ClearBuffers Subroutines!  */
/*=============================*/
 
#ifdef MSWIN
/* Windows NT vs Microsoft C vs Borland Turbo C */

static void ClearMemory(  char __huge *ptr, long count )
{
#ifndef _WIN32
#ifdef __TURBOC__
    register long left;
    register int off;

    off = OFFSETOF(ptr);
    if( off )
    {   left = 65536 - off;
        if( count < left )
        {   _fmemset(ptr,0,(size_t)count);
            return;
        } else
        {   _fmemset(ptr,0,(size_t)left);
            count -= left;
            ptr += left;
        }
    }

    while( count > 65535 )
    {   _fmemset(ptr,0,(size_t)65535);
        count -= 65536;
        ptr += 65535;
        *ptr++ = '\0';
    }

    if( count )
        _fmemset(ptr,0,(size_t)count);
#else /* Microsoft C/C++ */
    while( count > 65534 )
    {   _fmemset(ptr,0,(size_t)65534);
        count -= 65534;
	ptr += 65534;
    }
    if( count )
        _fmemset(ptr,0,(size_t)count);
#endif /* TURBOC */
#else  /* Windows NT  */
    memset(ptr,0,(size_t)count);
#endif /* Windows NT */
}


void ClearBuffers( void )
{
    register Pixel __huge *ptr;
#if !defined EIGHTBIT
    register Pixel __huge *end;
    register Pixel fill;
#endif

    if( !FBClear )
    {   FBClear = True;
        ptr = (Pixel __huge*)GlobalLock(FBufHandle);
#ifdef EIGHTBIT
        ClearMemory((char __huge*)ptr,(Long)XRange*YRange*sizeof(Pixel));
#else /*THIRTYTWOBIT*/
        fill = Lut[BackCol];
        end = ptr + (Long)XRange*YRange;
        do {
            *ptr++ = fill;
        } while( ptr<end );
#endif
        GlobalUnlock(FBufHandle);
    }

    if( !DBClear )
    {   DBClear = True;
	    ptr = (Pixel __huge*)GlobalLock(DBufHandle);
        ClearMemory((char __huge*)ptr,(Long)XRange*YRange*sizeof(short));
	    GlobalUnlock(DBufHandle);
    }
}
#else /* ! MSWIN */
void ClearBuffers( void )
{
#ifndef EIGHTBIT
    register Pixel *ptr;
    register Pixel *end;
    register Pixel fill;

    if( !FBClear )
    {   FBClear = True;
	fill = Lut[BackCol];
	ptr = FBuffer;
	end = FBuffer+(Long)XRange*YRange;
	do {
            *ptr++ = fill;
	} while( ptr<end );
    }
#else

    if( !FBClear )
    {   FBClear = True;
        memset(FBuffer,Lut[BackCol],(Long)XRange*YRange*sizeof(Pixel));
    }
#endif

    if( !DBClear )
    {   DBClear = True;
        memset(DBuffer,0,(Long)XRange*YRange*sizeof(short));
    }
}
#endif /* UNIX & VMS */


void ReAllocBuffers( void )
{
    register RAtom __far * __far *iptr;
    register int index;
    register long len, temp;

#ifdef MSWIN
    temp = (long)XRange*sizeof(short)+32;
    if( SLineHandle ) GlobalFree(SLineHandle);
    SLineHandle = GlobalAlloc(GMEM_MOVEABLE,temp);
    if( !SLineHandle ) FatalRenderError("slab line buffer");
    if( DLineHandle ) GlobalFree(DLineHandle);
    DLineHandle = GlobalAlloc(GMEM_MOVEABLE,temp);
    if( !DLineHandle ) FatalRenderError("depth line buffer");
    temp = (long)XRange*YRange*sizeof(short)+32;
    if( DBufHandle ) GlobalFree(DBufHandle);
    DBufHandle = GlobalAlloc(GMEM_MOVEABLE,temp);
    if( !DBufHandle ) FatalRenderError("depth buffer");
#else
    temp = (long)XRange*sizeof(short)+32;
    if( SLineBuffer ) _ffree( SLineBuffer );
    SLineBuffer = (short*)_fmalloc( temp );
    if( !SLineBuffer ) FatalRenderError("slab line buffer");
    if( DLineBuffer ) _ffree( DLineBuffer );
    DLineBuffer = (short*)_fmalloc( temp );
    if( !DLineBuffer ) FatalRenderError("depth line buffer");
    temp = (long)XRange*YRange*sizeof(short)+32;
    if( DBuffer ) _ffree( DBuffer );
    DBuffer = (short*)_fmalloc( temp );
    if( !DBuffer ) FatalRenderError("depth buffer");
#endif
    DBClear=False;

    if( YBucket && (BuckY<YRange) )
    {   _ffree(YBucket); 
	YBucket=(void __far*)0; 
    }

    if( !YBucket )
    {   len = YRange*sizeof(RAtom __far*);
	YBucket = (RAtom __far* __far*)_fmalloc( len );
	if( !YBucket ) FatalRenderError("Y buckets");
	BuckY = YRange;
    }

    if( IBuffer && (ItemX<XRange) )
    {   _ffree(IBuffer); 
	IBuffer=(void __far*)0; 
    }

    if( !IBuffer )
    {   len = (XRange+4)*sizeof(RAtom __far*);
	IBuffer = (RAtom __far* __far*)_fmalloc(len);
	if( !IBuffer ) FatalRenderError("item buffer");
	len = XRange>>2;  iptr = IBuffer;
	for( index=0; index<=len; index++ )
	{   *iptr++ = (void __far*)0;  *iptr++ = (void __far*)0;
	    *iptr++ = (void __far*)0;  *iptr++ = (void __far*)0;
	}
	ItemX = XRange;
    }
}


void ReSizeScreen( void )
{
    register Real orig;

    ReRadius();
    if( Range != ZoomRange )
    {   orig = MaxZoom;
        /* Code should match InitialTransform() */
        /* MaxZoom*DScale*Range*750 == 252      */
	    MaxZoom = 0.336*WorldSize/Range;
	    ZoomRange = Range;  MaxZoom -= 1.0;

	    /* Handle Change in MaxZoom */
	    if( DialValue[DialZoom]>0.0 )
	    {   DialValue[DialZoom] *= orig/MaxZoom;
	        if( DialValue[DialZoom]>1.0 )
		    DialValue[DialZoom] = 1.0;
	    }
    }

#ifdef MSWIN
    if( !FBufHandle || (FBufX!=XRange) || (FBufY!=YRange) )
#else /* UNIX */
    if( !FBuffer || (FBufX!=XRange) || (FBufY!=YRange) )
#endif
    {   if( !CreateImage() )
	    FatalRenderError("frame buffer");

	BucketFlag = False;
	FBufX=XRange;  FBufY=YRange;  FBClear = False;
	ReAllocBuffers();
	ClearBuffers();
#ifdef THIRTYTWOBIT
      if( BackR||BackG||BackB )
              FBClear = False;
#endif
    }
}


static void PrepareYBucket( void )
{
    register RAtom __far * __far *temp;
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *aptr;
    register int scan;
    register int rad;

    temp = YBucket;
    for( scan=0; scan<BuckY; scan++ )
	*temp++ = (void __far*)0;

    iProbeRad = (int)rint(Scale*ProbeRadius);

    if( UseClipping )
    {   ForEachAtom
	    if( aptr->flag&(SphereFlag|TouchFlag) )
	    {   rad = aptr->irad;
                if (aptr->flag&ExpandFlag) rad += iProbeRad;
		if( (aptr->x-rad>=XRange) || 
		    (aptr->x+rad<0) || (aptr->y+rad<0) )
		    continue;
		if( (scan=aptr->y-rad) > BuckY ) continue;

		if( scan>0 )
		{   aptr->bucket = YBucket[scan];
		    YBucket[scan] = aptr;
		} else
		{   aptr->bucket = *YBucket;
		    *YBucket = aptr;
		}
	    }
    } else
	ForEachAtom
	    if( aptr->flag&(SphereFlag|TouchFlag) )
	    {   scan = aptr->y-aptr->irad;
                if (aptr->flag&ExpandFlag) scan -= iProbeRad;
		aptr->bucket = YBucket[scan];
		YBucket[scan] = aptr;
	    }
    BucketFlag = True;
}


static void SqrInterval( Interval __far *ival )
{
    register Real l,h;

    l = ival->l;
    h = ival->h;

    if( l>=0.0 )
    {   ival->l = l*l;
	ival->h = h*h;
    } else if( h<0.0 )
    {   ival->l = h*h;
	ival->h = l*l;
    } else
    {   ival->h = (-l>h)? l*l : h*h;
	ival->l = 0.0;
    }
}


static void VoxelInsert( RAtom __far *ptr,  int ref )
{
    register Item __far *datum;
    register int i;

    if( !FreeItem )
    {   datum = (Item __far*)_fmalloc( PoolSize*sizeof(Item) );
	if( !datum ) FatalRenderError("voxel item");
	RegisterAlloc( datum );
    for( i=1; i<PoolSize; i++ )
	{   datum->list = FreeItem;
	    FreeItem = datum++;
	}
    } else
    {   datum = FreeItem;
	FreeItem = datum->list;
    }
    datum->data = ptr;
    InVoxCount++;

    if( !HashTable[ref] ) VoxelCount++;
    datum->list = (Item __far*)HashTable[ref];
    HashTable[ref] = (void __far*)datum;
}


void ResetVoxelData( void )
{
    register Item __far *datum;
    register int i;

    if( VoxelsDone )
    {   for( i=0; i<VOXSIZE; i++ )
	    if( HashTable[i] )
	    {   datum = (Item __far*)HashTable[i];
                while( datum->list ) datum = datum->list;
		datum->list = FreeItem;
		FreeItem = (Item __far*)HashTable[i];
		HashTable[i] = (void __far*)0;
	    }
	VoxelsDone = False;
    } else for( i=0; i<VOXSIZE; i++ )
	HashTable[i] = (void __far*)0;
    VoxelsClean = True;
}


void CreateVoxelData( int flag )   
{
    static Interval ix, iy, iz;
    register int lvx, lvy, lvz;
    register int hvx, hvy, hvz;
    register Long mx, my, mz;
    register int px, py, pz;
    register int i, rad;
    register Real radius2;

    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *aptr;

    ResetVoxelData();
    InVoxCount = VoxelCount = 0;
    VoxRatio = (Real)SideLen/VOXORDER;
    IVoxRatio = 1.0/VoxRatio;
    VoxelsDone = True;

    ForEachAtom
    if( aptr->flag & flag )
    {   mx = aptr->xorg + aptr->fxorg + Offset;
	my = aptr->yorg + aptr->fyorg + Offset;
	mz = aptr->zorg + aptr->fzorg + Offset;
	if( flag != SphereFlag )
	{   if( SolventDots || !ProbeRadius )
	    {   rad = ElemVDWRadius(aptr->elemno);
	    } else rad = ElemVDWRadius(aptr->elemno)+ProbeRadius;
	} else rad = aptr->radius +
            (aptr->flag&ExpandFlag)?ProbeRadius:0;  
	radius2 = (Long)rad*rad;

	lvx = (int)((mx-rad)*IVoxRatio);  hvx = (int)((mx+rad)*IVoxRatio);
	lvy = (int)((my-rad)*IVoxRatio);  hvy = (int)((my+rad)*IVoxRatio);
	lvz = (int)((mz-rad)*IVoxRatio);  hvz = (int)((mz+rad)*IVoxRatio);

	for( px=lvx; px<=hvx; px++ )
	{   ix.l=px*VoxRatio-mx;
	    ix.h=ix.l+VoxRatio;  
	    SqrInterval(&ix);
	    i = VOXORDER2*px + VOXORDER*lvy;
       
	    for( py=lvy; py<=hvy; py++ )
	    {   iy.l=py*VoxRatio-my;
		iy.h=iy.l+VoxRatio;
		SqrInterval(&iy);
		
		for( pz=lvz; pz<=hvz; pz++ )
		{   iz.l=pz*VoxRatio-mz; 
		    iz.h=iz.l+VoxRatio;
		    SqrInterval(&iz);

#ifdef ORIG
                    /* Test for surface voxels */
		    if( ((ix.l+iy.l+iz.l)<radius2) && 
			((ix.h+iy.h+iz.h)>radius2) )
			VoxelInsert( aptr, i+pz );
#else
                    /* Test for contained voxels */
                    if( ix.l+iy.l+iz.l < radius2 )
			VoxelInsert( aptr, i+pz );
#endif
		} /*pz*/
		i += VOXORDER;
	    } /*py*/
	} /*px*/
    }
}


void ShadowTransform( void )
{
    ShadowI = (LightXComp*LightDot(RotX[0],-RotY[0],RotZ[0]))/LightLength;
    ShadowJ = (LightYComp*LightDot(RotX[0],-RotY[0],RotZ[0]))/LightLength;
    ShadowK = (LightZComp*LightDot(RotX[0],-RotY[0],RotZ[0]))/LightLength;

    if( ShadowI>ApproxZero )
    {   deltax =  (int)(FUDGEFACTOR/ShadowI); xhash =  VOXORDER2; xflag =  1;
    } else if( ShadowI<-ApproxZero )
    {   deltax = -(int)(FUDGEFACTOR/ShadowI); xhash = -VOXORDER2; xflag = -1;
    } else xflag = 0;

    if( ShadowJ>ApproxZero )
    {   deltay =  (int)(FUDGEFACTOR/ShadowJ); yhash =  VOXORDER; yflag =  1;
    } else if( ShadowJ<-ApproxZero )
    {   deltay = -(int)(FUDGEFACTOR/ShadowJ); yhash = -VOXORDER; yflag = -1;
    } else yflag = 0;

    if( ShadowK>ApproxZero )
    {   deltaz =  (int)(FUDGEFACTOR/ShadowK); zhash = zflag =  1;
    } else if( ShadowK<-ApproxZero )
    {   deltaz = -(int)(FUDGEFACTOR/ShadowK); zhash = zflag = -1;
    } else zflag = 0;
}


static int AtomInter( RAtom __far *ptr )
{
    register Long modv,radius2;
    register int vx, vy, vz;
    register Real tca;

    if( ptr->mbox == RayCount )
	return False;
    ptr->mbox = RayCount;

    vx = (int)(ptr->xorg + ptr->fxorg) - ShadowX;
    vy = (int)(ptr->yorg + ptr->fyorg) - ShadowY;
    vz = (int)(ptr->zorg + ptr->fzorg) - ShadowZ;

    tca = vx*ShadowI + vy*ShadowJ + vz*ShadowK;
    if( tca<0.0 ) return False;
    
    radius2 = ptr->radius+10;  radius2 = radius2*radius2;
    modv = (Long)vx*vx + (Long)vy*vy + (Long)vz*vz - radius2;
    return( modv<tca*tca );
}


static int VoxelInter( Item __far *ptr )
{
    while( ptr )
    {   if( (ptr->data!=Exclude) && AtomInter(ptr->data) )
        {   SBuffer = ptr->data;
            return True;
        }
        ptr = ptr->list;
    }
    return False;
}


static int ShadowRay( void )
{
    register Item __far * __far *ident;
    register Real ex, ey, ez;
    register Long dx, dy, dz;
    register int ref;
   
    RayCount++;
    if( SBuffer )
    {   if( (SBuffer!=Exclude) && AtomInter(SBuffer) )
	    return True;
	SBuffer = (void __far*)0;
    }

    ex = IVoxRatio*(ShadowX+Offset);  xcord = (int)ex;
    ey = IVoxRatio*(ShadowY+Offset);  ycord = (int)ey;
    ez = IVoxRatio*(ShadowZ+Offset);  zcord = (int)ez;

    ref = VOXORDER2*xcord+VOXORDER*ycord+zcord;
    ident = (Item __far* __far*)(HashTable+ref);

    if( xflag == 1 ) 
    {   dx = (Long)(((xcord+1)-ex)*deltax);
    } else if( xflag == -1 )
    {   dx = (Long)((ex-xcord)*deltax); 
    } else dx = INFINITY;

    if( yflag == 1 ) 
    {   dy = (Long)(((ycord+1)-ey)*deltay);
    } else if( yflag == -1 )
    {   dy = (Long)((ey-ycord)*deltay); 
    } else dy = INFINITY;

    if( zflag == 1 ) 
    {   dz = (Long)(((zcord+1)-ez)*deltaz);
    } else if( zflag == -1 )
    {   dz = (Long)((ez-zcord)*deltaz); 
    } else dz = INFINITY;
    
    while( !VoxelInter(*ident) )
    {   if( (dx<=dy) && (dx<=dz) )
        {   xcord += xflag;
            if( (xcord<0) || (xcord>=VOXORDER) )
                return False;
            ident += xhash; 
            dx += deltax;
        } else if( dy <= dz  ) /*(dy<=dx)*/
        {   ycord += yflag;
            if( (ycord<0) || (ycord>=VOXORDER) )
                return False;
            ident += yhash;
            dy += deltay;
        } else /* (dz<=dx) && (dz<=dy) */
        {   zcord += zflag;
            if( (zcord<0) || (zcord>=VOXORDER) )
                return False;
            ident += zhash; 
            dz += deltaz;
        }
    }
    return True;
}


#define UpdateScanAcross \
	if( depth>*dptr )   \
	{   *dptr = depth;  \
	    iptr[dx] = ptr; \
	} dptr++; dx++;


/* ScanLine for Shadows! */
static void ScanLine( void )
{
    static RAtom __far *list;
    register RAtom __far *ptr;
    register RAtom __far * __far *iptr;
    register RAtom __far * __far *prev;
    register short __huge *dbase;
    register short __huge *dptr;
    register Pixel __huge *fptr;

    register int pos,depth,inten;
    register int lastx,wide,scan;
    register int dx,dy,dz;

    fptr = FBuffer;
    dbase = DBuffer;
    list = (void __far*)0;  

    wide = XRange>>2;  iptr = IBuffer;
    for( pos=0; pos<=wide; pos++ )
    {   *iptr++ = (void __far*)0;  *iptr++ = (void __far*)0;
	*iptr++ = (void __far*)0;  *iptr++ = (void __far*)0;
    }

    for( scan=0; scan<YRange; scan++ )
    {   for( ptr = YBucket[scan]; ptr; ptr = ptr->bucket )
	{    ptr->next = list; list = ptr; }

	prev = &list;
	for( ptr=list; ptr; ptr=ptr->next )
	{   dy = scan - ptr->y;
	    wide = pythag(ptr->irad,AbsFun(dy));
	    lastx = (XRange-1)-ptr->x;
	    if( wide<lastx ) lastx=wide;
	    dx = - MinFun(wide,ptr->x);

	    iptr = IBuffer+ptr->x;

	    dptr = dbase+ptr->x+dx;
	    while( dx<=lastx )
	    {   depth = pythag(wide,AbsFun(dx))+ptr->z;
		UpdateScanAcross;
	    }

	    /* Remove completed atoms */
	    if( dy == ptr->irad )
	    {   *prev = ptr->next;
	    } else prev = &ptr->next;
	} /*ptr*/


	/* Process visible scanline */
	prev = (RAtom __far* __far*)IBuffer;
	SBuffer = (void __far*)0;
	dptr = dbase; 

	for( pos=0; pos<XRange; pos++ )
	{   if( *prev )
	    {   ptr = *prev;
                dz = *dptr-ptr->z;
                inten = LightDot(pos-ptr->x,InvertY(scan-ptr->y),dz);
		if( inten>0 )
		{   inten = (int)( (inten*ColConst[ptr->irad])>>ColBits);
		    dz = *dptr-ZOffset;
		    dx = pos-XOffset;
		    dy =   scan-YOffset;

		    ShadowX = (int)(dx*InvX[0]+dy*InvX[1]+dz*InvX[2]);
		    ShadowY = (int)(dx*InvY[0]+dy*InvY[1]+dz*InvY[2]);
		    ShadowZ = (int)(dx*InvZ[0]+dy*InvZ[1]+dz*InvZ[2]);

		    Exclude = ptr;
		    if( ShadowRay() )
		    {   *fptr = Lut[ptr->col+(inten>>2)];
		    } else *fptr = Lut[ptr->col+inten];
		} else *fptr = Lut[ptr->col];
		*prev = (void __far*)0;
	    }
	    dptr++; fptr++; prev++;
	}
	dbase = dptr;
    } /*scan*/
}



static void DisplaySpaceFill( void )
{
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *aptr;

    iProbeRad = (int)rint(Scale*(Real)ProbeRadius);
    if( UseShadow )
    {   if( !BucketFlag )
	    PrepareYBucket();
	ScanLine();
    } else if( UseClipping )
    {   ForEachAtom
	    if( aptr->flag&(SphereFlag|TouchFlag) )
		ClipSphere(aptr->x,aptr->y,aptr->z,
                    aptr->irad+((aptr->flag&ExpandFlag)?iProbeRad:0),
                    aptr->col);
    } else 
	ForEachAtom
	    if( aptr->flag&(SphereFlag|TouchFlag) )
		DrawSphere(aptr->x,aptr->y,aptr->z,
                    aptr->irad+((aptr->flag&ExpandFlag)?iProbeRad:0),
                    aptr->col);
}


static void DisplayStars( void )
{
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *aptr;

    iProbeRad = (int)rint(Scale*ProbeRadius);

    if( UseClipping )
    {   ForEachAtom
	    if( aptr->flag&StarFlag )
		ClipStar(aptr->x,aptr->y,aptr->z,
                  aptr->radius+(aptr->flag&ExpandFlag?ProbeRadius:0),
                  aptr->col);
    } else 
	ForEachAtom
	    if( aptr->flag&StarFlag )
		DrawStar(aptr->x,aptr->y,aptr->z,
                  aptr->radius+(aptr->flag&ExpandFlag?ProbeRadius:0),
                  aptr->col);
}


static void DisplayWireframe( void )
{
    register Bond __far *bptr;
    register SurfBond __far *sbptr;
    register RAtom __far *s;
    register RAtom __far *d;
    register int sc,dc,stmp;
	
    iProbeRad = (int)rint(Scale*(Real)ProbeRadius);

    if( UseClipping )
    {   ForEachBond
	   if( bptr->flag & DrawBondFlag )
           {   s = bptr->srcatom; d = bptr->dstatom;



	       if( !bptr->col ) {
	         sc = s->col;  dc = d->col;
	       } else {
                 sc = dc = bptr->col;


               }

	       if( bptr->flag&WireFlag )
	       {   ClipTwinVector(s->x,s->y,s->z,d->x,d->y,d->z,sc,dc,bptr->altl);
	       } else if( bptr->flag&CylinderFlag )
	       {   if( bptr->irad>0 )
	           {  ClipCylinder(s->x,s->y,s->z,d->x,d->y,d->z,
                                   sc,dc,bptr->irad, bptr->altl, bptr->iarad);
	           } else ClipTwinLine(s->x,s->y,s->z,d->x,d->y,d->z,
				   sc+ColourMask,dc+ColourMask,bptr->altl);
               } else /* bptr->flag & DashFlag */
                   ClipDashVector(s->x,s->y,s->z,d->x,d->y,d->z,sc,dc,bptr->altl);
	   }
    } else {
	ForEachBond
	   if( bptr->flag & DrawBondFlag )
           {   s = bptr->srcatom; d = bptr->dstatom;



               if( !bptr->col )
               {   sc = s->col;  dc = d->col;
               } else {
                 sc = dc = bptr->col;


               }

               if( bptr->flag&WireFlag )
               {      DrawTwinVector(s->x,s->y,s->z,d->x,d->y,d->z,sc,dc,
                        bptr->altl);
	       } else if( bptr->flag&CylinderFlag )
	       {   if( bptr->irad>0 )
	           {  DrawCylinder(s->x,s->y,s->z,d->x,d->y,d->z,
                                   sc,dc,bptr->irad,bptr->altl,bptr->iarad);
	           } else DrawTwinLine(s->x,s->y,s->z,d->x,d->y,d->z,
				   sc+ColourMask,dc+ColourMask,bptr->altl);
	       } else ClipDashVector(s->x,s->y,s->z,d->x,d->y,d->z,sc,dc,
                        bptr->altl);
           }
     } 
     if (DrawSurf && DrawAtoms)
     ForEachSurfBond
     {   s = sbptr->srcatom; d = sbptr->dstatom;
	     if (s->flag&SelectFlag && d->flag&SelectFlag
	         && !(s->flag&ExpandFlag || d->flag&ExpandFlag )) {



         if( !sbptr->col ) {
           sc = s->col;  dc = d->col;
         } else {
           sc = dc = sbptr->col;


         }
         SBD.rad = s->irad;
         if (d->irad > SBD.rad) SBD.rad = d->irad;
         if (iProbeRad > SBD.rad) SBD.rad = iProbeRad;
         SBD.x1 = s->x;
         SBD.y1 = s->y;
         SBD.z1 = s->z;
         SBD.x2 = d->x;
         SBD.y2 = d->y;
         SBD.z2 = d->z;
         SBD.U[0] = SBD.x2-SBD.x1;
         SBD.U[1] = SBD.y2-SBD.y1;
         SBD.U[2] = SBD.z2-SBD.z1;
         SBD.sxyz = (LScale*sbptr->sxyz)>>4;
         SBD.c1 = sc;
         SBD.c2 = dc;
         SBD.u1 = (LScale*sbptr->u1)>>4;
         SBD.u2 = (LScale*sbptr->u2)>>4;
         SBD.wp = (LScale*sbptr->wp)>>4;
         SBD.t1 = (LScale*sbptr->t1)>>4;
         SBD.t2 = (LScale*sbptr->t2)>>4;
         SBD.w1 = (LScale*sbptr->w1)>>4;
         SBD.w2 = (LScale*sbptr->w2)>>4;

         SBD.s0=0;
         SBD.s1=1;
         SBD.s2=2;

         if (AbsFun(SBD.U[0]) > AbsFun(SBD.U[1])) {
             SBD.s0 = 1;
             SBD.s1 = 0;
         }
         if (AbsFun(SBD.U[SBD.s1]) > AbsFun(SBD.U[2])) {
             stmp = SBD.s1;
             SBD.s1 = SBD.s2;
             SBD.s2 = stmp;
         }
         if (AbsFun(SBD.U[SBD.s0]) > AbsFun(SBD.U[SBD.s1])) {
             stmp = SBD.s0;
             SBD.s0 = SBD.s1;
             SBD.s1 = stmp;
         }

         SBD.Us0Us1 = SBD.U[SBD.s0]*SBD.U[SBD.s1];
         SBD.Us0Us0_Us2Us2 = SBD.U[SBD.s0]*SBD.U[SBD.s0]+SBD.U[SBD.s2]*SBD.U[SBD.s2];
         SBD.Us1Us1_Us2Us2 = SBD.U[SBD.s1]*SBD.U[SBD.s1]+SBD.U[SBD.s2]*SBD.U[SBD.s2];
         SBD.Us0Us0_Us1Us1_Us2Us2 = SBD.U[SBD.s0]*SBD.U[SBD.s0]+
             SBD.U[SBD.s1]*SBD.U[SBD.s1]+SBD.U[SBD.s2]*SBD.U[SBD.s2];
	     ClipSurfaceBond(s->x,s->y,s->z,d->x,d->y,d->z,
                 sc,dc, s->irad,d->irad, iProbeRad, sbptr->altl);
	   }
     }

}


/* Used by DisplayDoubleBonds! */
static void DisplayCylinder( int x1, int y1, int z1, 
                             int x2, int y2, int z2, 
                             int c1, int c2, int rad,
                             char altl, int arad)
{
    if( UseClipping )
    {   if( rad == 0 )
        {   ClipTwinLine(x1,y1,z1,x2,y2,z2,c1+ColourMask,c2+ColourMask,altl);
        } else ClipCylinder(x1,y1,z1,x2,y2,z2,c1,c2,rad,altl,arad);
    } else
    {   if( rad == 0 )
        {   DrawTwinLine(x1,y1,z1,x2,y2,z2,c1+ColourMask,c2+ColourMask,altl);
        } else DrawCylinder(x1,y1,z1,x2,y2,z2,c1,c2,rad,altl,arad);
    }
}


static void DisplayDoubleBonds( void )
{
    register RAtom __far *s;
    register RAtom __far *d;
    register Bond __far *bptr;
    register int dx,dy,ix,iy;
    register int ax,ay,sc,dc;
    register int k,flag;

    ForEachBond
        if( bptr->flag & DrawBondFlag )
        {   s = bptr->srcatom; d = bptr->dstatom;
            if( !bptr->col ) 
            {   sc = s->col;  dc = d->col;
            } else sc = dc = bptr->col;

            flag = (bptr->flag&CylinderFlag) && (bptr->irad>4);
            if( !(bptr->flag & DoubBondFlag) || flag )
            {   if( bptr->flag&WireFlag )
                {   ClipTwinVector(s->x,s->y,s->z,d->x,d->y,d->z,sc,dc, 
                     bptr->altl);
                } else if( bptr->flag&CylinderFlag )
                {   DisplayCylinder(s->x,s->y,s->z,d->x,d->y,d->z,
                                    sc,dc,bptr->irad,bptr->altl,bptr->iarad);
                } else /* bptr->flag & DashFlag */
                    ClipDashVector(s->x,s->y,s->z,d->x,d->y,d->z,sc,dc,
                      bptr->altl);
            } 

            if( (bptr->flag & (DoubBondFlag|TripBondFlag)) && !flag )
            {   if( s->x > d->x )
                {   ax = s->x - d->x;  dx = 1;
                } else
                {   ax = d->x - s->x;  dx = 0;
                }

                if( s->y > d->y )
                {   ay = s->y - d->y;  dy = 1;
                } else 
                {   ay = d->y - s->y;  dy = 0;
                }

                /* Determine Bond Separation */
                if( (bptr->flag&CylinderFlag) && bptr->irad )
                {   if( bptr->flag & DoubBondFlag )
                    {   k = (3*bptr->irad+1)>>1;
                    } else k = 3*bptr->irad;
                } else k = (bptr->flag&TripBondFlag)?3:2;

                if( ax > (ay<<1) )
                {   ix = 0;  iy = k;
                } else if( ay > (ax<<1) )
                {   iy = 0;  ix = k;
                } else /* diagonal */
                {   k = (3*k)>>2;
                    if( dx == dy )
                    {   ix = k;  iy = -k;
                    } else
                    {   ix = k;  iy = k;
                    }
                }

                if( bptr->flag&WireFlag )
                {   ClipTwinVector(s->x+ix,s->y+iy,s->z,
                                   d->x+ix,d->y+iy,d->z,sc,dc,bptr->altl);
                    ClipTwinVector(s->x-ix,s->y-iy,s->z,
                                   d->x-ix,d->y-iy,d->z,sc,dc,bptr->altl);
                } else if( bptr->flag&CylinderFlag )
                {   DisplayCylinder(s->x+ix,s->y+iy,s->z,
                                    d->x+ix,d->y+iy,d->z,
                                    sc,dc,bptr->irad,bptr->altl,bptr->iarad);
                    DisplayCylinder(s->x-ix,s->y-iy,s->z,
                                    d->x-ix,d->y-iy,d->z,
                                    sc,dc,bptr->irad,bptr->altl,bptr->iarad);
                } else /* bptr->flag & DashFlag */
                {  ClipDashVector(s->x+ix,s->y+iy,s->z,
                                  d->x+ix,d->y+iy,d->z,sc,dc,bptr->altl);
                   ClipDashVector(s->x+ix,s->y+iy,s->z,
                                  d->x+ix,d->y+iy,d->z,sc,dc,bptr->altl);
                }
            }
        }
}


static void DisplayBackbone( void )
{
    register Chain __far *chain;
    register Bond __far *bptr;
    register RAtom __far *s;
    register RAtom __far *d;
    register int sc,dc;

    ForEachBack
       if( bptr->flag&DrawBondFlag )
       {   s = bptr->srcatom; d = bptr->dstatom;
           if( !bptr->col ) 
           {   sc = s->col;  dc = d->col;
           } else sc = dc = bptr->col;

           if( bptr->flag&CylinderFlag )
           {   if( bptr->irad>0 )
               { ClipCylinder(s->x,s->y,s->z,d->x,d->y,d->z,
                              sc,dc,bptr->irad,bptr->altl,bptr->iarad);
               } else ClipTwinLine(s->x,s->y,s->z,d->x,d->y,d->z,
                                   sc+ColourMask,dc+ColourMask,bptr->altl);
           } else if( bptr->flag & WireFlag )
           {      ClipTwinVector(s->x,s->y,s->z,d->x,d->y,d->z,sc,dc,
                                 bptr->altl);
           } else ClipDashVector(s->x,s->y,s->z,d->x,d->y,d->z,sc,dc,
                                 bptr->altl);
       }
}


static void DisplayHBonds( HBond __far *list, int mode )
{
    register HBond __far *ptr;
    register RAtom __far *s;
    register RAtom __far *d;
    register int sc,dc;

    for( ptr=list; ptr; ptr=ptr->hnext )
        if( ptr->flag & DrawBondFlag )
	{   if( mode )
	    {   s = ptr->srcCA; d = ptr->dstCA;
		if( !s || !d ) continue;
	    } else
	    {   d = ptr->src;
		s = ptr->dst;
	    }

	    if( !ptr->col )
	    {   sc = s->col;  dc = d->col;
	    } else sc = dc = ptr->col;
	    if( ptr->flag & CylinderFlag )
	    {   if( ptr->irad>0 )
		{   ClipCylinder(s->x,s->y,s->z,d->x,d->y,d->z,
                                 sc,dc,ptr->irad,ptr->altl,ptr->iarad);
		} else ClipTwinLine(s->x,s->y,s->z,d->x,d->y,d->z,
				    sc+ColourMask,dc+ColourMask,ptr->altl);
	    } else ClipDashVector(s->x,s->y,s->z,d->x,d->y,d->z,sc,dc,ptr->altl);
	}
}



static void DisplayBoxes( void )
{
    register Real lena, lenb, lenc;
    register Real tmpx, tmpy, tmpz;
    register Real cosa, cosb, cosg;
    register Real temp, sing;

    register int xorg, yorg, zorg;
    register int Cenx, Ceny, Cenz;
    register int dxx,dxy,dxz;
    register int dyx,dyy,dyz;
    register int dzx,dzy,dzz;
    register int x, y, z;

    Cenx=(int)(CenX*MatX[0]+CenY*MatX[1]+CenZ*MatX[2]);
	Ceny=(int)(CenX*MatY[0]+CenY*MatY[1]+CenZ*MatY[2]);
	Cenz=(int)(CenX*MatZ[0]+CenY*MatZ[1]+CenZ*MatZ[2]);

    if( DrawAxes  || DrawBoundBox )
    {   dxx = (int)(MaxX*MatX[0]);
	dxy = (int)(MaxX*MatY[0]);
	dxz = (int)(MaxX*MatZ[0]);

	dyx = (int)(MaxY*MatX[1]);
	dyy = (int)(MaxY*MatY[1]);
	dyz = (int)(MaxY*MatZ[1]);

	dzx = (int)(MaxZ*MatX[2]);
	dzy = (int)(MaxZ*MatY[2]);
	dzz = (int)(MaxZ*MatZ[2]);

	if( DrawAxes )
	{   /* Line (MinX,0,0) to (MaxX,0,0) */
            x = XOffset+dxx;  y = YOffset+dxy;  z = ZOffset+dxz;
            if( ZBValid(x,z) ) DisplayRasString(x+2,y,z,
              (unsigned char *)"X",BoxCol);
	    ClipTwinLine(XOffset-dxx,YOffset-dxy,ZOffset-dxz,
                         x,y,z,BoxCol,BoxCol,' ');

	    /* Line (0,MinY,0) to (0,MaxY,0) */
            x = XOffset+dyx;  y = YOffset+dyy;  z = ZOffset+dyz;
            if( ZBValid(x,z) ) DisplayRasString(x+2,y,z,
              (unsigned char *)"Y",BoxCol);
	    ClipTwinLine(XOffset-dyx,YOffset-dyy,ZOffset-dyz, 
			 x,y,z,BoxCol,BoxCol,' ');


	    /* Line (0,0,MinZ) to (0,0,MaxZ) */
            x = XOffset-dzx;  y = YOffset-dzy;  z = ZOffset-dzz;
            if( ZBValid(x,z) ) DisplayRasString(x+2,y,z,
              (unsigned char *)"Z",BoxCol);
	    ClipTwinLine(XOffset+dzx,YOffset+dzy,ZOffset+dzz, 
			 x,y,z,BoxCol,BoxCol,' ');

	}

	if( DrawBoundBox )
	{   /* Line (MinX,MinY,MinZ) to (MaxX,MinY,MinZ) */
	    x=XOffset-Cenx-dyx-dzx;  y=YOffset-Ceny-dyy-dzy;  z=ZOffset-Cenz-dyz-dzz;
	    ClipTwinLine(x-dxx,y-dxy,z-dxz,x+dxx,y+dxy,z+dxz,BoxCol,BoxCol,' ');

	    /* Line (MaxX,MinY,MinZ) to (MaxX,MaxY,MinZ) */
	    x=XOffset-Cenx+dxx-dzx;  y=YOffset-Ceny+dxy-dzy;  z=ZOffset-Cenz+dxz-dzz;
	    ClipTwinLine(x-dyx,y-dyy,z-dyz,x+dyx,y+dyy,z+dyz,BoxCol,BoxCol,' ');

	    /* Line (MaxX,MaxY,MinZ) to (MinX,MaxY,MinZ) */
	    x=XOffset-Cenx+dyx-dzx;  y=YOffset-Ceny+dyy-dzy;  z=ZOffset-Cenz+dyz-dzz;
	    ClipTwinLine(x+dxx,y+dxy,z+dxz,x-dxx,y-dxy,z-dxz,BoxCol,BoxCol,' ');

	    /* Line (MinX,MaxY,MinZ) to (MinX,MinY,MinZ) */
	    x=XOffset-Cenx-dxx-dzx;  y=YOffset-Ceny-dxy-dzy;  z=ZOffset-Cenz-dxz-dzz;
	    ClipTwinLine(x+dyx,y+dyy,z+dyz,x-dyx,y-dyy,z-dyz,BoxCol,BoxCol,' ');


	    /* Line (MinX,MinY,MinZ) to (MinX,MinY,MaxZ) */
	    x=XOffset-Cenx-dxx-dyx;  y=YOffset-Ceny-dxy-dyy;  z=ZOffset-Cenz-dxz-dyz;
	    ClipTwinLine(x-dzx,y-dzy,z-dzz,x+dzx,y+dzy,z+dzz,BoxCol,BoxCol,' ');

	    /* Line (MaxX,MinY,MinZ) to (MaxX,MinY,MaxZ) */
	    x=XOffset-Cenx+dxx-dyx;  y=YOffset-Ceny+dxy-dyy;  z=ZOffset-Cenz+dxz-dyz;
	    ClipTwinLine(x-dzx,y-dzy,z-dzz,x+dzx,y+dzy,z+dzz,BoxCol,BoxCol,' ');

	    /* Line (MaxX,MaxY,MinZ) to (MaxX,MaxY,MaxZ) */
	    x=XOffset-Cenx+dxx+dyx;  y=YOffset-Ceny+dxy+dyy;  z=ZOffset-Cenz+dxz+dyz;
	    ClipTwinLine(x-dzx,y-dzy,z-dzz,x+dzx,y+dzy,z+dzz,BoxCol,BoxCol,' ');

	    /* Line (MinX,MaxY,MinZ) to (MinX,MaxY,MaxZ) */
	    x=XOffset-Cenx-dxx+dyx;  y=YOffset-Ceny-dxy+dyy;  z=ZOffset-Cenz-dxz+dyz;
	    ClipTwinLine(x-dzx,y-dzy,z-dzz,x+dzx,y+dzy,z+dzz,BoxCol,BoxCol,' ');


	    /* Line (MinX,MinY,MaxZ) to (MaxX,MinY,MaxZ) */
	    x=XOffset-Cenx-dyx+dzx;  y=YOffset-Ceny-dyy+dzy;  z=ZOffset-Cenz-dyz+dzz;
	    ClipTwinLine(x-dxx,y-dxy,z-dxz,x+dxx,y+dxy,z+dxz,BoxCol,BoxCol,' ');

	    /* Line (MaxX,MinY,MaxZ) to (MaxX,MaxY,MaxZ) */
	    x=XOffset-Cenx+dxx+dzx;  y=YOffset-Ceny+dxy+dzy;  z=ZOffset-Cenz+dxz+dzz;
	    ClipTwinLine(x-dyx,y-dyy,z-dyz,x+dyx,y+dyy,z+dyz,BoxCol,BoxCol,' ');

	    /* Line (MaxX,MaxY,MaxZ) to (MinX,MaxY,MaxZ) */
	    x=XOffset-Cenx+dyx+dzx;  y=YOffset-Ceny+dyy+dzy;  z=ZOffset-Cenz+dyz+dzz;
	    ClipTwinLine(x+dxx,y+dxy,z+dxz,x-dxx,y-dxy,z-dxz,BoxCol,BoxCol,' ');

	    /* Line (MinX,MaxY,MaxZ) to (MinX,MinY,MaxZ) */
	    x=XOffset-Cenx-dxx+dzx;  y=YOffset-Ceny-dxy+dzy;  z=ZOffset-Cenz-dxz+dzz;
	    ClipTwinLine(x+dyx,y+dyy,z+dyz,x-dyx,y-dyy,z-dyz,BoxCol,BoxCol,' ');
	}
    }

    if( DrawUnitCell && *Info.spacegroup )
    {   /* Calculate Unit Cell! */
      if (det(Info.matf2o) < 1.1 )
      {
	lena = 250.0*Info.cella;
	lenb = 250.0*Info.cellb;
	lenc = 250.0*Info.cellc;

	cosa = cos(Info.cellalpha);
	cosb = cos(Info.cellbeta);
	cosg = cos(Info.cellgamma);  
        sing = sin(Info.cellgamma);

	temp = cosa*cosa + cosb*cosb + cosg*cosg - 2.0*cosa*cosb*cosg;
	tmpx = cosb; 
	tmpy = (cosa - cosb*cosg)/sing;
	tmpz = -sqrt(1.0-temp)/sing;

	dxx = (int)(lena*MatX[0]);
	dxy = (int)(lena*MatY[0]);
	dxz = (int)(lena*MatZ[0]);

	dyx = (int)(lenb*(cosg*MatX[0] + ProperY(sing*MatX[1])));
	dyy = (int)(lenb*(cosg*MatY[0] + ProperY(sing*MatY[1])));
	dyz = (int)(lenb*(cosg*MatZ[0] + ProperY(sing*MatZ[1])));

	dzx = (int)(lenc*(tmpx*MatX[0] + ProperY(tmpy*MatX[1]) + tmpz*MatX[2]));
	dzy = (int)(lenc*(tmpx*MatY[0] + ProperY(tmpy*MatY[1]) + tmpz*MatY[2]));
	dzz = (int)(lenc*(tmpx*MatZ[0] + ProperY(tmpy*MatZ[1]) + tmpz*MatZ[2]));

	xorg = XOffset - (int)(OrigCX*MatX[0]+OrigCY*MatX[1]+OrigCZ*MatX[2]);
	yorg = YOffset - (int)(OrigCX*MatY[0]+OrigCY*MatY[1]+OrigCZ*MatY[2]);
	zorg = ZOffset - (int)(OrigCX*MatZ[0]+OrigCY*MatZ[1]+OrigCZ*MatZ[2]);

      } else {

        double cellmat[3][3];
        int ii;

        for (ii = 0; ii < 3; ii++) {
          cellmat[0][ii] = MatX[0]*Info.matf2o[0][ii] + 
            ProperY(MatX[1]*Info.matf2o[1][ii]) - MatX[2]*Info.matf2o[2][ii];
          cellmat[1][ii] = MatY[0]*Info.matf2o[0][ii] + 
            ProperY(MatY[1]*Info.matf2o[1][ii]) - MatY[2]*Info.matf2o[2][ii];
          cellmat[2][ii] = MatZ[0]*Info.matf2o[0][ii] + 
            ProperY(MatZ[1]*Info.matf2o[1][ii]) - MatZ[2]*Info.matf2o[2][ii];
        }


	xorg = XOffset - (int)(OrigCX*MatX[0]+OrigCY*MatX[1]+OrigCZ*MatX[2])
          + (int)((250.*Info.vecf2o[0])*MatX[0]+
            ProperY(250.*Info.vecf2o[1])*MatX[1]-
            (250.*Info.vecf2o[2])*MatX[2]);
	yorg = YOffset - (int)(OrigCX*MatY[0]+OrigCY*MatY[1]+OrigCZ*MatY[2])
          + (int)((250.*Info.vecf2o[0])*MatY[0]+
            ProperY(250.*Info.vecf2o[1])*MatY[1]-
            (250.*Info.vecf2o[2])*MatY[2]);
	zorg = ZOffset - (int)(OrigCX*MatZ[0]+OrigCY*MatZ[1]+OrigCZ*MatZ[2])
          + (int)((250.*Info.vecf2o[0])*MatZ[0]+
            ProperY(250.*Info.vecf2o[1])*MatZ[1]-
            (250.*Info.vecf2o[2])*MatZ[2]);

        dxx = (int)(250.*cellmat[0][0]);
        dxy = (int)(250.*cellmat[1][0]);
        dxz = (int)(250.*cellmat[2][0]);

        dyx = (int)(250.*cellmat[0][1]);
        dyy = (int)(250.*cellmat[1][1]);
        dyz = (int)(250.*cellmat[2][1]);

        dzx = (int)(250.*cellmat[0][2]);
        dzy = (int)(250.*cellmat[1][2]);
        dzz = (int)(250.*cellmat[2][2]);

        
      }

		/* Draw Unit Cell! */
		x = xorg - Cenx;
		y = yorg - Ceny;
		z = zorg - Cenz;
		ClipTwinLine(x,y,z,x+dxx,y+dxy,z+dxz,BoxCol,BoxCol,' ');
		ClipTwinLine(x,y,z,x+dyx,y+dyy,z+dyz,BoxCol,BoxCol,' ');
		ClipTwinLine(x,y,z,x+dzx,y+dzy,z+dzz,BoxCol,BoxCol,' ');

		x = xorg - Cenx + dxx + dyx;
		y = yorg - Ceny + dxy + dyy;
		z = zorg - Cenz + dxz + dyz;
		ClipTwinLine(x,y,z,x-dxx,y-dxy,z-dxz,BoxCol,BoxCol,' ');
		ClipTwinLine(x,y,z,x-dyx,y-dyy,z-dyz,BoxCol,BoxCol,' ');
		ClipTwinLine(x,y,z,x+dzx,y+dzy,z+dzz,BoxCol,BoxCol,' ');

		x = xorg - Cenx + dxx + dzx;
		y = yorg - Ceny + dxy + dzy;
		z = zorg - Cenz + dxz + dyz;
		ClipTwinLine(x,y,z,x-dxx,y-dxy,z-dxz,BoxCol,BoxCol,' ');
		ClipTwinLine(x,y,z,x+dyx,y+dyy,z+dyz,BoxCol,BoxCol,' ');
		ClipTwinLine(x,y,z,x-dzx,y-dzy,z-dzz,BoxCol,BoxCol,' ');

		x = xorg - Cenx + dyx + dzx;
		y = yorg - Ceny + dyy + dzy;
		z = zorg - Cenz + dyz + dzz;
		ClipTwinLine(x,y,z,x+dxx,y+dxy,z+dxz,BoxCol,BoxCol,' ');
		ClipTwinLine(x,y,z,x-dyx,y-dyy,z-dyz,BoxCol,BoxCol,' ');
		ClipTwinLine(x,y,z,x-dzx,y-dzy,z-dzz,BoxCol,BoxCol,' ');
    }
}


static void DisplayArea( void )
{	register int z;

    if( !UseSlabPlane )
    {   z = ImageRadius + ZOffset;
    } else z = SlabValue - 1;

	ClipDashLine(AreaX1,AreaY1,z,AreaX1,AreaY2,z,BoxCol,BoxCol,' ');
	ClipDashLine(AreaX1,AreaY2,z,AreaX2,AreaY2,z,BoxCol,BoxCol,' ');
	ClipDashLine(AreaX1,AreaY1,z,AreaX2,AreaY1,z,BoxCol,BoxCol,' ');
	ClipDashLine(AreaX2,AreaY1,z,AreaX2,AreaY2,z,BoxCol,BoxCol,' ');

}


static void DisplaySelected( void )
{
    register RAtom __far *s, __far *d;
    register Chain __far *chain;
    register Group __far *group;
    register Bond __far *bptr;
    register RAtom __far *aptr;
    register int irad,sc,dc;
    register int col;

    irad = (int)rint(Scale*20);

    if( irad>0 )
    {   ForEachBond
	{   s = bptr->srcatom;  
	    col = (s->flag&SelectFlag)? 1 : 0;
	    sc = Shade2Colour(col);

	    d = bptr->dstatom;  
	    col = (d->flag&SelectFlag)? 1 : 0;
	    dc = Shade2Colour(col);
	    ClipCylinder(s->x,s->y,s->z,d->x,d->y,d->z,sc,dc,irad,bptr->altl,
            4*irad/5);
	}
    } else ForEachBond
	{   s = bptr->srcatom;  
	    col = (s->flag&SelectFlag)? 1 : 0;
	    sc = Shade2Colour(col);

	    d = bptr->dstatom;  
	    col = (d->flag&SelectFlag)? 1 : 0;
	    dc = Shade2Colour(col);
	    ClipTwinLine(s->x,s->y,s->z,d->x,d->y,d->z,
			 sc+ColourMask,dc+ColourMask,bptr->altl);
	}


    irad = (int)rint(Scale*50);
    ForEachAtom
	if( aptr->flag&NonBondFlag )
	{   col = Shade2Colour( (aptr->flag&SelectFlag)? 1 : 0 );
	    ClipSphere(aptr->x,aptr->y,aptr->z,irad,col);
	}
}


static void RenderFrame( void )
{
    register Chain __far *chain;
    int dwf;

    dwf = 0;

    if( !DisplayMode )
    {   if( DrawAtoms ) 
        DisplaySpaceFill();
        if( DrawSurf ) {
          DisplayWireframe();
          dwf++;
        }
        if( DrawStars )
            DisplayStars();

	if( !UseSlabPlane || (SlabMode != SlabSection) )
	{   if( DrawBonds ) 
            {   if( DrawDoubleBonds )
                {   DisplayDoubleBonds();
                } else {
                  if (!dwf) DisplayWireframe();
                  dwf++;
                }
            }

	    if( DrawRibbon )
		for( chain=Database->clist; chain; chain=chain->cnext )
		    if( chain->glist )
                        DisplayRibbon( chain );

	    if( DotPtr ) DisplaySurface();
	    if( MapInfoPtr ) {
	      DisplayMapPoints();
	      DisplayMapBonds();
	      DisplayMapTangles();
	    }
	    if( LabelList ) DisplayLabels();
            if( MonitList ) DisplayMonitors();
	    DisplayHBonds( Database->slist, SSBondMode );
	    DisplayHBonds( Database->hlist, HBondMode );
	    DisplayBackbone();
	}

    } else DisplaySelected();

	if( DrawArea )
		DisplayArea();
    DisplayBoxes();
}


static void DrawFrameOne( void )
{
    register double temp, kemp;
    register int wide;
    register int ii;
    double theta,costheta,tantheta;

    if( !Database ) 
	return;

    /* ClearBuffers(); [GSG/11/9/95] */
    if( !DisplayMode )
    {   if( UseShadow && DrawAtoms )
	    if( !VoxelsClean )
		CreateVoxelData( SphereFlag );
    }

#ifdef MSWIN
    /* Lock Buffers into Memory */
    FBuffer = (Pixel __huge*)GlobalLock(FBufHandle);
    DBuffer = (short __huge*)GlobalLock(DBufHandle);
    SLineBuffer = (short __huge*)GlobalLock(SLineHandle);
    DLineBuffer = (short __huge*)GlobalLock(DLineHandle);
#endif

    if( UseDepthPlane )
    {   DepthValue = (int)(DialValue[DialBClip]*ImageRadius)+ZOffset;
        UseClipping = True;
        for (ii=0; ii < XRange; ii++) DLineBuffer[ii] = DepthValue;
    }   else UseClipping = UseScreenClip;

    if( UseSlabPlane )
    {   SlabValue = (int)(DialValue[DialSlab]*ImageRadius)+ZOffset;
	    SlabInten = (int)(ColourMask*LightZComp/LightLength);
	    SliceValue = 16;
        for (ii=0; ii < XRange; ii++) SLineBuffer[ii] = SlabValue;
	    UseClipping = True;
    } else UseClipping = UseScreenClip;

    if( UseSlabPlane )
	{	if( UseAutoDepthCue )
		{	ShiftS = (int)((1-DialValue[DialSlab])*ImageRadius)/2;
		} else
			ShiftS = 0;
    } else
		ShiftS = 0;


    /* Common View Elements */
    View.yskip = XRange;
    View.ymax = YRange;
    View.fbuf = FBuffer;
    View.dbuf = DBuffer;
    View.slbuf = SLineBuffer;
    View.dlbuf = DLineBuffer;

    if( UseStereo )
    {
        temp = StereoAngle/180.0;
        theta = -PI*temp/2.;
        costheta = cos(theta);
        tantheta = tan(theta);
        wide = XRange>>1;

        /* Create 'Left' View structure */
        View.shift = 0;
        View.xmax = wide;
        View.offmax = 2*wide*YRange;
        
        if( UseSlabPlane ){
          for (ii=0; ii<wide; ii++) {
            kemp = (double)SlabValue+rint(((double)(wide/2-ii))*tantheta);
            if (kemp > (double)ZRange-1) kemp = ZRange-1;
            if (kemp < 0.) kemp=0.;
            View.slbuf[ii] = (short)kemp;
          }
        }
        if( UseDepthPlane ) { 
          for (ii=0; ii<wide; ii++) {
            kemp = (double)DepthValue+rint(((double)(wide/2-ii))*tantheta);
            if (kemp > (double)ZRange-1) kemp = ZRange-1;
            if (kemp < 0.) kemp=0.;
            View.dlbuf[ii] = (short)kemp;
          }
        }
        SliceValue = rint(16./costheta);

        /*  DialValue[DialRY] -= temp; */
        WRotStereo = -temp/2.;
        ReDrawFlag |= RFRotateY;
        ApplyTransform();
        RenderFrame();

        /* Create 'Right' View structure */
        View.shift = wide;
        View.xmax = wide;
        View.offmax = 2*wide*YRange;
        View.slbuf += wide;
        View.dlbuf += wide;

        if( UseSlabPlane ){
          for (ii=0; ii<wide; ii++) {
            kemp = (double)SlabValue-rint(((double)(wide/2-ii))*tantheta);
            if (kemp > (double)ZRange-1) kemp = ZRange-1;
            if (kemp < 0.) kemp=0.;
            View.slbuf[ii] = (short)kemp;
          }
        }
        if( UseDepthPlane ) { 
          for (ii=0; ii<wide; ii++) {
            kemp = (double)DepthValue-rint(((double)(wide/2-ii))*tantheta);
            if (kemp > (double)ZRange-1) kemp = ZRange-1;
            if (kemp < 0.) kemp=0.;
            View.dlbuf[ii] = (short)kemp;
          }
        }

        /* DialValue[DialRY] += temp; */
        WRotStereo = temp/2.;
        ReDrawFlag |= RFRotateY;
        ApplyTransform();
        RenderFrame();

    } else /* Mono */
    {   /* Create 'Mono' View structure */
        View.shift = 0;
        View.xmax = XRange;
        View.offmax = XRange*YRange;
        WRotStereo = 0.;
        if (WLastRS != 0.) ApplyTransform();
        RenderFrame();
    }

#ifdef MSWIN
    /* Unlock Buffers */
    GlobalUnlock(FBufHandle);
    GlobalUnlock(DBufHandle);
    GlobalUnlock(SLineHandle);
    GlobalUnlock(DLineHandle);
#endif
    DBClear = False;
    FBClear = False;
}

/* [GSG 11/9/95] added new DrawFrame */
void DrawFrame( void )
{
    int i, SaveMolecule = MoleculeIndex;
    ClearBuffers();
    for (i=0; i<NumMolecules; i++) {
      SwitchMolecule(i);
      DrawFrameOne();
    }
    SwitchMolecule(SaveMolecule);
}


static void TestAtomProximity(  RAtom __far *ptr, int xpos, int ypos )
{
    register Long dist;
    register int dx,dy;

    if( UseSlabPlane && (ptr->z>SlabValue) )
	return;

    if( UseDepthPlane && (ptr->z<DepthValue) )
		return;

    dx = ptr->x - xpos;
    dy = ptr->y - ypos;

    dist = (Long)dx*dx + (Long)dy*dy;

    if( IdentFound )
    {   if( dist==IdentDist )
	{   if( ptr->z<IdentDepth )
		return;
	} else if( dist>IdentDist ) 
	    return;
    }

    IdentDepth = ptr->z;
    IdentFound = True;
    IdentDist = dist;
    QAtom = ptr;
}


static void IdentifyAtom( int xpos, int ypos )
{
    register int rad, wide, dpth;
    register int new, dx, dy, dz;
    register Chain __far *chain;
    register Group __far *group;
    register HBond __far *hptr;
    register RAtom  __far *aptr;
    register Bond __far *bptr;
  
    /* [GSG 11/10/95] Switch to molecule that is clicked on */
    int SaveMolecule = MoleculeIndex, i;

    for (i = 0; i < NumMolecules; i++) {
      SwitchMolecule(i);


    /* Reset Search */
    QChain = (void __far*)0;
    QGroup = (void __far*)0;
    QAtom = (void __far*)0;
    IdentFound = False;

    if( !DisplayMode )
    {   if( !UseSlabPlane || (SlabMode != SlabSection) )
        {   for( chain=Database->clist; chain; chain=chain->cnext )
                for( group=chain->glist; group; group=group->gnext )
                {   if( group->flag & DrawKnotFlag )
                    {   if( IsProtein(group->refno) )
                        {   aptr = FindGroupAtom(group,1);
                        } else aptr = FindGroupAtom(group,7);
                        if( aptr ) TestAtomProximity(aptr,xpos,ypos);
                    }
                }

            /* Double tolerance for spline knots! */
            if( IdentFound ) IdentDist >>= 1;

            if( DrawBonds )
		ForEachBond
		    if( bptr->flag&DrawBondFlag )
		    {   TestAtomProximity(bptr->srcatom,xpos,ypos);
			TestAtomProximity(bptr->dstatom,xpos,ypos);
		    }

	    ForEachBack
		if( bptr->flag&DrawBondFlag )
		{   TestAtomProximity(bptr->srcatom,xpos,ypos);
		    TestAtomProximity(bptr->dstatom,xpos,ypos);
		}

	    for( hptr=Database->hlist; hptr; hptr=hptr->hnext )
		if( hptr->flag )
		{   if( HBondMode )
		    {   TestAtomProximity(hptr->srcCA,xpos,ypos);
			TestAtomProximity(hptr->dstCA,xpos,ypos);
		    } else
		    {   TestAtomProximity(hptr->src,xpos,ypos);
			TestAtomProximity(hptr->dst,xpos,ypos);
		    }
		}

	    for( hptr=Database->slist; hptr; hptr=hptr->hnext )
		if( hptr->flag )
		{   if( HBondMode )
		    {   TestAtomProximity(hptr->srcCA,xpos,ypos);
			TestAtomProximity(hptr->dstCA,xpos,ypos);
		    } else
		    {   TestAtomProximity(hptr->src,xpos,ypos);
			TestAtomProximity(hptr->dst,xpos,ypos);
		    }
		}

	}

	ForEachAtom
	{   /* Identify bond! */
	    if( aptr == QAtom )
	    {   QChain = chain;
		QGroup = group;
	    }

	    if( aptr->flag & (SphereFlag | StarFlag) )
	    {   int xrad;

                xrad = aptr->irad;
                if (aptr->flag&ExpandFlag) xrad+=iProbeRad;
                dy = AbsFun(aptr->y-ypos);
		if( dy > xrad ) continue;
		rad = pythag(xrad,dy);
		dx = AbsFun(aptr->x-xpos);
		if( dx>rad ) continue;

		new = False;
		dpth = aptr->z+pythag(rad,dx);
		if( UseSlabPlane && (aptr->z+rad>=SlabValue) )
		{   dz = SlabValue-aptr->z;
		    if( SlabMode && (dz >= -rad) )
		    {   wide = pythag(aptr->irad,AbsFun(dz));
			if( (dy<=wide) && (dx<=pythag(wide,dy)) )
			{   if( SlabMode == SlabHollow )
			    {   dpth = aptr->z-pythag(rad,dx);
				new = !IdentFound || (dpth>IdentDepth);
			    } else if( SlabMode != SlabHalf )
			    {   /* SlabClose, SlabSection */
				dpth = dx*dx+dy*dy+dz*dz+SlabValue+SliceValue;
				if( IdentFound )
				{   new = (IdentDepth<SlabValue+SliceValue) 
					  || (dpth<IdentDepth);
				} else new=True;
			    }
			} else if( (dz>0) && (SlabMode!=SlabSection) )
			    new = !IdentFound || (dpth>IdentDepth);
		    }
		} else if( !UseSlabPlane || (SlabMode != SlabSection) )
		    new = !IdentFound || IdentDist || (dpth>IdentDepth);

		if( new )
		{   IdentFound = True;
		    IdentDepth = dpth;
		    IdentDist = 0;

		    QChain = chain;
		    QGroup = group;
		    QAtom = aptr;
		}
	    } 
	}
    } else /* Display Mode */
    {   ForEachAtom
	{   TestAtomProximity(aptr,xpos,ypos);
	    /* Identify bond! */
	    if( aptr == QAtom )
	    {   QChain = chain;
		QGroup = group;
	    }
	}
    }


    if( !IdentFound || (IdentDist>=50) )
    {   /* Reset Pick Atom! */
        QChain = (void __far*)0;
        QGroup = (void __far*)0;
        QAtom = (void __far*)0;
    } else break; /* [GSG 11/10/95] */
    } /* [GSG 11/10/95] */

    /* [GSG 11/10/95] Switch to molecule if it's not current */
    if (IdentFound && (IdentDist<50) && i != SaveMolecule)
      SelectMolecule(i);
    else
      SwitchMolecule(SaveMolecule);
}


void SetPickMode( int mode )
{
    if( PickMode != mode )
    {   if( (PickMode==PickOrign) || (mode==PickOrign) )
            ReDrawFlag |= RFTrans | RFRotate;
        PickMode = mode;
        if ( PickMode == PickDist || PickMode == PickAngle || 
          PickMode == PickTorsn ) {
          ReDrawFlag |= RFRefresh;
          DeleteMonitors();
        }
    }
    if ( mode == PickDist || mode == PickAngle 
      || mode == PickTorsn || mode == PickMonit ) {
      DrawMonitDistance = True;
      ReDrawFlag |= RFRefresh;
    }
    PickCount = 0;
}


static void DescribeAtom( AtomRef *ptr, int flag )
{
    register char *str;
    register int i,ch;
    char buffer[40];

    str = Residue[ptr->grp->refno];
    for( i=0; i<3; i++ )
        if( str[i]!=' ' )
            WriteChar(str[i]);

    sprintf(buffer,"%d",ptr->grp->serno);
    WriteString(buffer);

    ch = ptr->chn->ident;
    if( ch != ' ' ) {
        if( isdigit(ch) )
            WriteChar(':');
        WriteChar(ch);
    }

    WriteChar('.');
    str = ElemDesc[ptr->atm->refno];
    for( i=0; str[i] && i<12; i++ )
        if( str[i]!=' ' )
            WriteChar(str[i]);

    if (ptr->atm->model) {
        sprintf(buffer,"/%d",ptr->atm->model);
        WriteString(buffer);
    }

    if( flag ) {
        sprintf(buffer," (%ld)",ptr->atm->serno);
        WriteString(buffer);
    }
}


int PickAtoms( int shift, int xpos, int ypos )
{
    register AtomRef *ptr;
    register Label *label;
    register double temp;
    register char *str;
    register size_t len;

    char buffer[80];
    AtomRef ref;

    if( PickMode == PickNone )
        return False;

    IdentifyAtom(xpos,ypos);

    if( !QAtom )
        return False;

    if( PickMode==PickCentr && shift )
        SetPickMode(PickOrign);

    if( PickMode==PickAtom ) {
        SelectAtom( shift, QAtom, QGroup );
        return True;
    } else if( PickMode == PickGroup ) {
        SelectGroup( shift, QGroup );
        return True;
    } else if( PickMode == PickChain ) {
        SelectChain( shift, QChain );
        return True;
    } else if( PickMode == PickIdent || PickMode == PickCoord ) {
        InvalidateCmndLine();
        WriteString("Atom: ");
        str = ElemDesc[QAtom->refno];
        if( str[0]!=' ' )
            WriteChar(str[0]);
        WriteChar(str[1]);
        WriteChar(str[2]);
        { int iii;
            for (iii = 3; str[iii] && iii < 12; iii++) {
                if( str[iii]!=' ' )
                    WriteChar(str[iii]);
            }
        }

        if( !(QAtom->altl == ' ')) {
            WriteChar(';');
            WriteChar(QAtom->altl);
        }

        sprintf(buffer," %ld  ",QAtom->serno);
        WriteString(buffer);

        if (!(QGroup->serno == -9999)) {
            str = Residue[QGroup->refno];
            if( QAtom->flag&HeteroFlag ) {
                WriteString("Hetero: ");
            } else
                WriteString("Group: ");

            if( str[0]!=' ' )
                WriteChar(str[0]);
            WriteChar(str[1]);
            WriteChar(str[2]);

            sprintf(buffer," %d",QGroup->serno);
            WriteString(buffer);
            if (!(QGroup->insert == ' ') && !(QGroup->insert=='\0'))
                WriteChar(QGroup->insert);
        }

        if( QChain->ident!=' ' ) {
            WriteString("  Chain: ");
            WriteChar(QChain->ident);
        }

        if( QAtom->model) {
            sprintf(buffer,"  Model: %d",QAtom->model);
            WriteString(buffer);
        }
        WriteChar('\n');
        if (PickMode == PickCoord || shift != 0 ) {
            register double x, y, z;

            x = (double)(QAtom->xorg + QAtom->fxorg + OrigCX)/250.0
                +(double)(QAtom->xtrl)/10000.0;
            y = (double)(QAtom->yorg + QAtom->fyorg + OrigCY)/250.0
                +(double)(QAtom->ytrl)/10000.0;
            z = (double)(QAtom->zorg + QAtom->fzorg + OrigCZ)/250.0
                +(double)(QAtom->ztrl)/10000.0;
#ifdef INVERT
            sprintf(buffer, "  Coordinates: %9.3f %9.3f %9.3f\n",x,-y,-z);
#else
            sprintf(buffer, "  Coordinates: %9.3f %9.3f %9.3f\n",x,y,-z);
#endif
            WriteString(buffer);
        }

    } else if( PickMode == PickLabel ) {
        if( !QAtom->label ) {
            if( *LabelFormat!='\0' ) {
                len = strlen(LabelFormat);
                label = CreateLabel(LabelFormat,len);
            } else if( MainGroupCount > 1 ) {
                strcpy(buffer,"%n%r");
                str = buffer+4;
                if( Info.chaincount > 1 ) {
                    if( isdigit(QChain->ident) )
                        *str++ = ':';
                    *str++ = '%';
                    *str++ = 'c';
                }
                strcpy(str,".%a");

                len = (str-buffer) + 3;
                label = CreateLabel(buffer,(int)len);
            } else
                label = CreateLabel("%e%i%A",6);
            QAtom->label = label;
            label->refcount++;
        } else {
            DeleteLabel( (Label*)QAtom->label );
            QAtom->label = (void*)0;
        }
        ReDrawFlag |= RFRefresh;

    } else if( PickMode == PickCentr ) {
        CentreTransform(QAtom->xorg + QAtom->fxorg,
                QAtom->yorg + QAtom->fyorg,
                QAtom->zorg + QAtom->fzorg, XlateCen);

        ref.chn = QChain;
        ref.grp = QGroup;
        ref.atm = QAtom;

        InvalidateCmndLine();
        WriteString("Rotating about ");
        DescribeAtom(&ref,True);
        WriteChar('\n');

    } else if( PickMode == PickOrign ) {
        CentreTransform(QAtom->xorg + QAtom->fxorg,
                QAtom->yorg + QAtom->fyorg,
                QAtom->zorg + QAtom->fzorg, False);

        ref.chn = QChain;
        ref.grp = QGroup;
        ref.atm = QAtom;

        InvalidateCmndLine();
        WriteString("Rotating about ");
        DescribeAtom(&ref,True);
        WriteChar('\n');

    } else if( PickMode == PickMonit ) {
        /* State Machine Implementation */

        if( PickCount == 0 ) {
            PickHist[0].atm = QAtom;
            PickCount = 1;
        } else if( PickCount == 1 ) {
            if( !shift ) {
                if( PickHist[0].atm != QAtom ) {
                    AddMonitors(PickHist[0].atm,QAtom);
                    ReDrawFlag |= RFRefresh;
                }
                PickCount = 2;
            } else
                PickHist[0].atm = QAtom;
        } else /* PickCount == 2 */
            if( !shift ) {
                PickHist[0].atm = QAtom;
                PickCount = 1;
            } else if( PickHist[0].atm != QAtom ) {
                AddMonitors(PickHist[0].atm,QAtom);
                ReDrawFlag |= RFRefresh;
            }
    } else if (PickMode == PickBond) { /* [GSG 11/16/95] */
        if( PickCount ) {
            if( shift ) {
                PickCount--;
            } else if( PickCount == 2 )
                PickCount = 0;
        }

        ptr = PickHist+PickCount;
        ptr->chn = QChain;
        ptr->grp = QGroup;
        ptr->atm = QAtom;
        PickCount++;

        if( CommandActive )
            WriteChar('\n');
        CommandActive = False;

        WriteString("Atom #");
        WriteChar(PickCount+'0');
        WriteString(": ");
        DescribeAtom(ptr,True);
        WriteChar('\n');

        if( PickCount == 2 )
            SetBondAxis(PickHist[0].atm, PickHist[1].atm);
    } else { /* Distance, Angle or Torsion! */
        if( PickCount ) {
            if( shift ) {
                PickCount--;
            } else if( PickCount == PickMode )
                PickCount = 0;
        }

        ptr = PickHist+PickCount;
        ptr->chn = QChain;
        ptr->grp = QGroup;
        ptr->atm = QAtom;
        PickCount++;

        InvalidateCmndLine();
        WriteString("Atom #");
        WriteChar(PickCount+'0');
        WriteString(": ");
        DescribeAtom(ptr,True);
        WriteChar('\n');

        if( PickCount == PickMode ) {
            /* [GSG 11/29/95] */
            if ( PickMode != PickMonit )
                DeleteMonitors();
            if( PickMode == PickDist ) {
                temp = (double)CalcDistance(PickHist[0].atm, PickHist[1].atm);

                WriteString("Distance ");
                DescribeAtom(PickHist,False);
                WriteChar('-');
                DescribeAtom(PickHist+1,False);
                sprintf(buffer,": %.2f\n\n",temp);
                WriteString(buffer);
                /* [GSG 11/21/95] */
                AddMonitors(PickHist[0].atm, QAtom);
                ReDrawFlag |= RFRefresh;

            } else if( PickMode == PickAngle ) {
                temp = (double)CalcAngle(PickHist[0].atm,
                                         PickHist[1].atm,
                                         PickHist[2].atm);

                WriteString("Angle ");
                DescribeAtom(PickHist,False);
                WriteChar('-');
                DescribeAtom(PickHist+1,False);
                WriteChar('-');
                DescribeAtom(PickHist+2,False);
                sprintf(buffer,": %.2f\n\n",temp);
                WriteString(buffer);

                /* [GSG 11/21/95] */
                AddMonitors2(PickHist[0].atm, PickHist[2].atm,
                             PickHist[1].atm, (RAtom __far *)NULL,
                             (Long) (rint(temp*100)), 128, PickAngle);
                ReDrawFlag |= RFRefresh;
            } else { /* PickMode == PickTorsn */
                temp = (double)CalcTorsion(PickHist[0].atm,
                                           PickHist[1].atm,
                                           PickHist[2].atm,
                                           PickHist[3].atm);

                WriteString("Torsion ");
                DescribeAtom(PickHist,False);
                WriteChar('-');
                DescribeAtom(PickHist+1,False);
                WriteChar('-');
                DescribeAtom(PickHist+2,False);
                WriteChar('-');
                DescribeAtom(PickHist+3,False);
                sprintf(buffer,": %.2f\n\n",temp);
                WriteString(buffer);
                WriteString(buffer);

                /* [GSG 11/21/95] */
                AddMonitors2(PickHist[0].atm, PickHist[3].atm,
                             PickHist[1].atm, PickHist[2].atm,
                             (Long) (rint(temp*100)), 128, PickTorsn);
                ReDrawFlag |= RFRefresh;
            }
        }
    }
    return True;
}


void SetStereoMode( int enable )
{
    ReDrawFlag |= (RFRefresh | RFTrans | RFRotate | RFMagnify);
    StereoView = ViewLeft;
    UseStereo = enable;
    DetermineClipping();
}


void ResetRenderer( void )
{
	if( !VoxelsClean )
		ResetVoxelData();

    DrawAtoms = False;  MaxAtomRadius = 0;
    DrawBonds = False;  MaxBondRadius = 0;
    DrawStars = False;
    DrawRibbon = False;
    DrawSurf = False;

    SlabMode = SlabClose;
    UseSlabPlane = False;
    UseDepthPlane = False;
    UseLabelCol = False;
    UseShadow = False;

    UseDepthCue = False;

    SSBondMode = False;
    HBondMode = False;
    DisplayMode = 0;

    DrawDoubleBonds = False;
    DrawBoundBox = False;
    DrawUnitCell = False;
    DrawAxes = False;

    SetStereoMode(False);
    StereoAngle = 6.0;

	/*RasTop*/
	PickCount = 0;
}


static void InitialiseTables( void )
{
    register Byte __far *ptr;
    register unsigned int root,root2;
    register unsigned int i,rad,arg;

    ptr = Array;
    LookUp[0] = ptr;  *ptr++ = 0;
    LookUp[1] = ptr;  *ptr++ = 1;  *ptr++ = 0;
    
    for( rad=2; rad<MAXRAD; rad++ )
    {   LookUp[rad] = ptr;

        /* i == 0 */
        *ptr++ = (Byte)rad;  

        root = rad-1;
        root2 = root*root;

        arg = rad*rad;
	for( i=1; i<rad; i++ )
        {   /* arg = rad*rad - i*i */
            arg -= (i<<1)-1;

            /* root = isqrt(arg)   */
            while( arg < root2 )
            {   root2 -= (root<<1)-1;
                root--;
            }
            /* Thanks to James Crook */
            *ptr++ = ((arg-root2)<i)? root : root+1;
        }

        /* i == rad */
        *ptr++ = 0;    
    }
}


void InitialiseRenderer( void )
{
    register int rad,maxval;

    FBuffer = (void __huge*)0;  
    DBuffer = (void __huge*)0;
    IBuffer = (void __far*)0;   
    YBucket = (void __far*)0;

#if defined(MSWIN) || defined(APPLEMAC)
    FBufHandle = NULL;
    DBufHandle = NULL;
    SLineHandle = NULL;
    DLineHandle = NULL;
#endif

#if defined(IBMPC) || defined(APPLEMAC)
    /* Allocate tables on FAR heaps */ 
    Array = (Byte __far*)_fmalloc(MAXTABLE*sizeof(Byte));
    LookUp = (Byte __far* __far*)_fmalloc(MAXRAD*sizeof(Byte __far*));
    HashTable = (void __far* __far*)_fmalloc(VOXSIZE*sizeof(void __far*));
    ColConst = (Card __far*)_fmalloc(MAXRAD*sizeof(Card));
    
    if( !Array || !LookUp || !HashTable || !ColConst )
	FatalRenderError("tables");
#else
    ColConst = ColConstTable;
#endif

    InitialiseTables();

    /* Initialise ColConst! */
    for( rad=0; rad<MAXRAD; rad++ )
    {   maxval = (int)(LightLength*rad)+4;
	ColConst[rad] = ((Card)ColourDepth<<ColBits)/maxval;
    }

    FreeItem = (Item __far*)0;
    PickMode = PickIdent;
	DrawArea = False;
	AreaX1 = AreaX2 = AreaY1 = AreaY2 = 0;
    RotMode = RotMol;

    VoxelsClean = False;
    VoxelsDone = False;
    BucketFlag = False;
    RayCount = 0;

	UseAutoDepthCue = False;

    ResetRenderer();
    ReSizeScreen();
}

#if defined RASTOPWIN
void UpdateRender(int Level)
{	if( Level==1 )
	{	if(YBucket) _ffree(YBucket);
		if(IBuffer) _ffree(IBuffer);
		return;
	} else if( Level==2 )
	{	FreeItem = (Item __far*)0;
	} 
}
#endif

