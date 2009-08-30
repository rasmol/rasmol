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
/* pixutils.c
 $Log$
 Revision 1.10  2008/03/22 18:42:54  yaya
 Post release cleanup and credit to Ikonen in file headers. -- HJB

 Revision 1.9  2008/03/17 03:01:31  yaya
 Update to agree with 2.7.4.2 release and T. Ikonen GTK mods -- HJB

 Revision 1.4  2008/03/17 01:32:41  yaya
 Add gtk mods by tpikonen, and intergate with 2.7.4.2 mods -- HJB

 Revision 1.3  2008/03/16 22:38:09  yaya
 Update stable release to 2.7.4.2; Update rasmol_install and rasmol_run
 scripts to handle Japanese and Chiness (using cxterm), changing
 Japanese for unix back to EUCJP; and align command line options
 to set initial window size and position to agree between unix and
 windows -- HJB

 Revision 1.8  2008/03/16 22:25:22  yaya
 Align comments with production version; Update rasmol_install and
 rasmol_run shell scripts for Japanese and Chinese; Align logic for
 positioning and sizing initial window with windows version -- HJB

 Revision 1.2  2008/01/28 03:29:38  yaya
 Update CVS to RasMol_2.7.4.1 -- HJB

 Revision 1.7  2008/01/22 19:31:40  yaya
 Fixup typos in messages and align versions of langsel.
 Correct boundary calculations for map generate.
 Update CW project for windows.  -- HJB

 Revision 1.6  2008/01/14 15:49:16  yaya
 More of code for CBF style map save
 More use of stdlib as per Ladislav Michnovic
 --HJB

 Revision 1.5  2008/01/05 20:56:29  yaya
 Update handling of stereo interaction with slab
 Enable save of CBF-style maps. -- HJB

 Revision 1.4  2007/12/14 02:04:50  yaya
 Correct Chinese data for missing line in langsel_utf.c
 Rewrite code for handling of slab mode in stereo -- HJB

 Revision 1.3  2007/11/19 03:28:39  yaya
 Update to credits for 2.7.4 in manual and headers
 Mask code added -- HJB

 Revision 1.2  2007/10/29 02:29:36  yaya
 Fix stereo offset for map surfaces and other uses of ClipPoly
 Decouple mesh from surface for maps
 Experiment with alternatives for normals calculation -- to
 be continued -- HJB

 Revision 1.1.1.1  2007/03/01 01:16:33  todorovg
 Chinese working versio from rasmol_ru initial import

 Revision 1.3  2006/11/01 03:23:51  yaya
 Update NSIS windows installer for more script types and to fix
 misplaced script instructions for data files; add document and
 script icons directly in raswin.exe; add credit line to
 G. A. Pozhvanov in comments for Russian translations. -- HJB

 Revision 1.2  2006/09/17 10:53:56  yaya
 Clean up headers and start on code for X11 -- HJB

 Revision 1.1.1.1  2006/09/16 18:45:54  yaya
 Start of RasMol Russian Translation Project based on translations
 by Gregory A. Pozhvanov of Saint Petersburg State University -- HJB

 Revision 1.1.1.1  2006/06/19 22:05:14  todorovg
 Initial Rasmol 2.7.3 Import

 Revision 1.1  2004/05/07 19:46:16  yaya
 Initial revision

 Revision 1.4  2004/02/15 00:24:00  yaya
 *** empty log message ***

 Revision 1.3  2004/01/26 23:53:12  yaya
 *** empty log message ***

 Revision 1.2  2003/12/13 19:26:11  yaya
 *** empty log message ***

 Revision 1.1  2003/12/12 21:10:38  yaya
 Initial revision

 Revision 1.1  2001/01/31 02:13:45  yaya
 Initial revision

 Revision 1.5  2000/08/26 18:12:37  yaya
 Updates to header comments in all files

 Revision 1.4  2000/08/13 20:56:21  yaya
 Conversion from toolbar to menus

 Revision 1.3  2000/08/03 18:32:41  yaya
 Parametrization for alt conformer bond radius

 Revision 1.2  2000/02/23 00:00:00  yaya
 Prelininary 2.7.2 build

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
/* #ifdef sun386 */ /* Ladislav Michnovic, 10 Jan 08 */
#include <stdlib.h>
/* #endif        */ /* Ladislav Michnovic, 10 Jan 08 */

#include <stdio.h>
#include <math.h>

#define PIXUTILS
#include "pixutils.h"
#include "graphics.h"
#include "molecule.h"
#include "abstree.h"
#include "transfor.h"
#include "repres.h"
#include "render.h"
#include "font.h"
#include "langsel.h"

/* Sutherland-Cohen Line Clipping Macros */
#define BitAbove    0x01
#define BitBelow    0x02
#define BitRight    0x04
#define BitLeft     0x08
#define BitFront    0x10
#define BitBack     0x20

#define Reject(x,y)   ((x)&(y))
#define Accept(x,y)   (!((x)|(y)))


typedef struct {
                Long dx,dz,di;
                Long x,z,i;
               } Edge;

typedef struct {
                short dx,dy,dz;
                short inten;
                Long offset;
               } ArcEntry;


/* Note: DrawCylinderCaps currently employs an
*      extremely crude hack to avoid stripes
*      appearing along cylinders.
 */
#define ARCSIZE  4096

static ArcEntry __far *ArcAcPtr;
static ArcEntry __far *ArcDnPtr;
#if defined(IBMPC) || defined(APPLEMAC)
static ArcEntry __far *ArcAc;
static ArcEntry __far *ArcDn;
#else
static ArcEntry ArcAc[ARCSIZE];
static ArcEntry ArcDn[ARCSIZE];
#endif
static Long C[3], A[3];
static Long Cprev[3], Cnext[3];

static int radprev, radnext, rad, rada, c;


static int ClipStatus;

/*
    The following two macros add a pixel to the z-buffer

    dptr-- a pointer to an array of depths
    fptr-- a pointer to an array of pixels
    View.shift a- on offset into the arrays
    d   -- the depth of the new pixel
    c   -- the color of the new pixel
    ca  -- an alternate color to use if p is true

    note that increasing z values are closer to the viewer

 */



#define SETPIXEL(dptr,fptr,d,c)    if( (d) > *((dptr)+View.shift) )  \
                                   {   *((dptr)+View.shift) = (d);  \
                                       *((fptr)+View.shift) = (c);   \
                                   }
#define SETPIXELP(dptr,fptr,d,c,ca,p) if( (d) > *((dptr)+View.shift))   \
                                   {   *(dptr+View.shift) = (d);               \
                                       if(!p) {*((fptr)+View.shift) = (c); }   \
                                       else  {*((fptr)+View.shift) = (ca);}   \
                                   }

#define OutCode(res,x,y,z)            \
    {   if( (y)<0 )                   \
        {   (res) = BitAbove;         \
        } else if( (y) >= View.ymax ) \
        {   (res) = BitBelow;         \
        } else (res) = 0;             \
                                      \
        if( (x) < 0 )                 \
        {   (res) |= BitLeft;         \
        } else if( (x) >= View.xmax ) \
            (res) |= BitRight;        \
                                      \
        if( !ZValid((x),(z)) )        \
            (res) |= BitFront;        \
                                      \
        if( !ZBack((x),(z))  )        \
            (res) |= BitBack;         \
    }



/*=======================*/
/*  Function Prototypes  */
/*=======================*/

#ifdef FUNCPROTO
static void DrawArcDn( short __huge*, Pixel __huge*, int, int );
static void DrawArcAc( short __huge*, Pixel __huge*, int, int );
static void ClipArcDn( short __huge*, Pixel __huge*, int, int, int, int );
static void ClipArcAc( short __huge*, Pixel __huge*, int, int, int, int );
#else
static void DrawArcDn();
static void DrawArcAc();
static void ClipArcDn();
static void ClipArcAc();
#endif

#ifdef UNUSED
static int OutCode( int x, int y, int z )
{
    register int result;

    if( y < 0 )
    {   result = BitAbove;
    } else if( y >= View.ymax )
    {   result = BitBelow;
    } else result = 0;

    if( x < 0 )
    {   result |= BitLeft;
    } else if( x >= View.xmax )
        result |= BitRight;

    if( !ZValid(x,z) )
        result |= BitFront;
    
    if( !ZBack(x,z) )
        result |= Bitback;
    return result;
}
#endif


void PlotPoint( int x, int y, int z, int col )
{
    register Pixel __huge *fptr;
    register short __huge *dptr;
    register Long offset;

    /* SETPIXEL(dptr,fptr,z,Lut[col]); */

    offset = (Long)y*View.yskip+x;
    dptr = View.dbuf+offset+View.shift;
    if( OValid(offset) && z > *dptr )
    {   fptr = View.fbuf+offset+View.shift;
        *fptr = Lut[col];
        *dptr = z;
    }
}


void ClipPoint( int x, int y, int z, int col )
{
    register Pixel __huge *fptr;
    register short __huge *dptr;
    register Long offset;

    if( XValid(x) && YValid(y) && ZBValid(x,z) )
    {   /* PlotPoint(x,y,z,col); */
        offset = (Long)y*View.yskip+x;
        dptr = View.dbuf+offset+View.shift;
        if( OValid(offset) && z > *dptr )
        {   fptr = View.fbuf+offset+View.shift;
            *fptr = Lut[col];
            *dptr = z;
        }
    }
}


void PlotDeepPoint( int x, int y, int z, int col )
{
    register Long offset;
    register Pixel __huge *fptr;
    register short __huge *dptr;
    register int inten;

    offset = (Long)y*View.yskip+x;
    dptr = View.dbuf+offset+View.shift;

    if( OValid(offset) && z > *dptr )
    {  fptr = View.fbuf+offset+View.shift;
       inten = (ColourDepth*(z+ImageRadius-ZOffset))/ImageSize;
       if( inten > 0 )
       {   *fptr = Lut[col+(inten&ColourMask)];
       } else *fptr = Lut[col];
       *dptr = z;
    }
}


void ClipDeepPoint( int x, int y, int z, int col )
{
    register Long offset;
    register Pixel __huge *fptr;
    register short __huge *dptr;
    register int inten;

    if( XValid(x) && YValid(y) && ZBValid(x,z) )
    {   /* PlotDeepPoint(x,y,z,col); */
        offset = (Long)y*View.yskip+x;
        dptr = View.dbuf+offset+View.shift;

        if( OValid(offset) && z > *dptr )
        {  fptr = View.fbuf+offset+View.shift;
           inten = (ColourDepth*(z+ImageRadius-ZOffset))/ImageSize;
           *fptr = Lut[col+inten];
           *dptr = z;
        }
    }
}



/*================================================*/
/*  Macros for Bresenhams Line Drawing Algorithm  */
/*================================================*/

#define CommonStep(s)  z1 += zrate; SETPIXELP(dptr,fptr,z1,c,ca,p);     \
                       if( (zerr+=dz)>0 ) { zerr-=(s); z1+=iz; }

#define XStep  { if((err+=dy)>0) { fptr+=ystep; dptr+=ystep; err-=dx; } \
                 fptr+=ix; dptr+=ix; x1+=ix;                            \
                 p =  altc && (x1-mid<(dx/4)) && (mid-x1<(dx/4));       \
                 CommonStep(dx); }

#define YStep  { if((err+=dx)>0) { fptr+=ix; dptr+=ix; err-=dy; } \
                 fptr+=ystep; dptr+=ystep; y1+=iy;                \
                 p =  altc && (y1-mid<(dy/4)) && (mid-y1<(dy/4)); \
                 CommonStep(dy); }
                     

void DrawTwinLine( int x1, int y1, int z1,
                   int x2, int y2, int z2,
                   int col1, int col2, char altl )
{
    register Long offset;
    register Pixel __huge *fptr;
    register short __huge *dptr;
    register int zrate, zerr;
    register int ystep,err;
    register int ix,iy,iz;
    register int dx,dy,dz;
    register int mid=0;
    register Pixel c, ca;
    register int p, altc;

    c = Lut[col1];
    altc = 0;
    ca = c;
    if ( altl != '\0' && altl != ' ') {
      altc = AltlColours[((int)altl)&(AltlDepth-1)];
      ca = Lut[altc];
    }
    

    offset = (Long)y1*View.yskip + x1;
    fptr = View.fbuf+offset;
    dptr = View.dbuf+offset;

    if ( OValid(offset) ) {
      SETPIXEL(dptr,fptr,z1,c);
    }

    dx = x2-x1;  dy = y2-y1; 
    if( !dx && !dy ) return;
    dz = z2-z1;

    if( dy<0 ) 
    {   ystep = -View.yskip;
        dy = -dy; 
        iy = -1;
    } else
    {   ystep = View.yskip;
        iy = 1;
    }

    if( dx<0 ) 
    {   dx = -dx;
        ix = -1;
    } else ix = 1;

    if( dz<0 ) 
    {   dz = -dz;
        iz = -1;
    } else iz = 1;

    if( dx>dy )
    {   if( dz >= dx )
        {   zrate = dz/dx;
            dz -= dx*zrate;
            if( iz < 0 )
                zrate = -zrate;
        } else zrate = 0;
        err = zerr = -(dx>>1);

        if( col1 != col2 )
        {   mid = (x1+x2)>>1;
            while( x1!=mid ) XStep;
            c = Lut[col2];
        }
        while( x1!=x2 ) XStep;

    } else
    {   if( dz >= dy )
        {   zrate = dz/dy;
            dz -= dy*zrate;
            if( iz < 0 )
                zrate = -zrate;
        } else zrate = 0;
        err = zerr = -(dy>>1);

        if( col1 != col2 )
        {   mid = (y1+y2)>>1;
            while( y1!=mid ) YStep;
            c = Lut[col2];
        }
        while( y1!=y2 ) YStep;
    }
}


void ClipLine( int x1, int y1, int z1,
               int x2, int y2, int z2,
               int col,  char altl )
{
    register int code1,code2;
    register int delta,rest;
    register int temp;

    OutCode(code1,x1,y1,z1);
    OutCode(code2,x2,y2,z2);
    if( Reject(code1,code2) )
        return;
  
    while( !Accept(code1,code2) )
    {  if( !code1 )
        {   temp=x1; x1=x2; x2=temp;
            temp=y1; y1=y2; y2=temp;
            temp=z1; z1=z2; z2=temp;
            code1 = code2;
            code2 = 0;
        }

        if( code1 & BitAbove )
        {   delta = y2-y1;
            x1 += (int)(((Long)y1*(x1-x2))/delta);  
            z1 += (int)(((Long)y1*(z1-z2))/delta);
            y1 = 0;
        } else if( code1 & BitLeft )
        {   delta = x2-x1;
            y1 += (int)(((Long)x1*(y1-y2))/delta);
            z1 += (int)(((Long)x1*(z1-z2))/delta);
            x1 = 0;
        } else if( code1 & BitRight )
        {   delta = x2-x1;
            temp=View.xmax-1; rest=temp-x1;
            y1 += (int)(((Long)rest*(y2-y1))/delta);
            z1 += (int)(((Long)rest*(z2-z1))/delta);
            x1 = temp;
        } else if( code1 & BitBelow )
        {   delta = y2-y1;
            temp=View.ymax-1; rest=temp-y1;
            x1 += (int)(((Long)rest*(x2-x1))/delta);
            z1 += (int)(((Long)rest*(z2-z1))/delta);
            y1 = temp;
        } else if( code1 & BitFront ) /* SLAB */
        {   delta = z2-z1;
            rest = (SlabValue-1)-z1;
            x1 += (int)(((Long)rest*(x2-x1))/delta);
            y1 += (int)(((Long)rest*(y2-y1))/delta);
            z1 = SlabValue-1;
        } else /* DEPTH */
        {   delta = z2-z1;
            rest = (DepthValue+1)-z1;
            x1 += (int)(((Long)rest*(x2-x1))/delta);
            y1 += (int)(((Long)rest*(y2-y1))/delta);       
            z1 = DepthValue+1;
        }

        OutCode(code1,x1,y1,z1);
        if( Reject(code1,code2) )
            return;

    }
    DrawTwinLine(x1,y1,z1,x2,y2,z2,col,col,altl);
}


void ClipTwinLine( int x1, int y1, int z1,
                   int x2, int y2, int z2,
                   int col1, int col2, char altl )
{
    register int xmid,ymid,zmid;
    register int code1,code2;


    if( col1!=col2 )
    {   OutCode(code1,x1,y1,z1);
        OutCode(code2,x2,y2,z2);
        if( !Reject(code1,code2) )
        {   if( !Accept(code1,code2) )
            {  xmid = (x1+x2)/2;
               ymid = (y1+y2)/2;
               zmid = (z1+z2)/2;
               ClipLine(x1,y1,z1,xmid,ymid,zmid,col1,altl);
               ClipLine(xmid,ymid,zmid,x2,y2,z2,col2,altl);
            } else
               DrawTwinLine(x1,y1,z1,x2,y2,z2,col1,col2,altl);
        }
    } else ClipLine(x1,y1,z1,x2,y2,z2,col1,altl);
}


void ClipDashLine( int x1, int y1, int z1,
                     int x2, int y2, int z2,
                     int col1, int col2, char altl )
{
    register Long offset;
    register Pixel __huge *fptr;
    register short __huge *dptr;
    register int ix,iy,iz;
    register int dx,dy,dz;
    register int zrate, zerr;
    register int ystep,err;
	register int co;
    register Pixel c, ca, mid;
    register int count;
    register int altc;

    if( (x1==x2) && (y1==y2) )
         return;

    /* Reject(OutCode(x1,y1,z1),OutCode(x2,y2,z2)) */
    if( (x1<0) && (x2<0) ) return;
    if( (y1<0) && (y2<0) ) return;
    if( (x1>=View.xmax) && (x2>=View.xmax) ) return;
    if( (y1>=View.ymax) && (y2>=View.ymax) ) return;

    c = Lut[col1];
    altc = 0;
    ca = c;
    if ( altl != '\0' && altl != ' ') {
      altc = AltlColours[((int)altl)&(AltlDepth-1)];
      ca = Lut[altc];
    }

    dx = x2 - x1;  
	dy = y2 - y1;
    dz = z2 - z1;  

    offset = (Long)y1*View.yskip + x1;
    fptr = View.fbuf+offset;
    dptr = View.dbuf+offset;
    count = 0;

    ystep = View.yskip;
    ix = iy = iz = 1;
    if( dy<0 ) { dy = -dy; iy = -1; ystep = -ystep; }
    if( dx<0 ) { dx = -dx; ix = -1; }
    if( dz<0 ) { dz = -dz; iz = -1; }

    if( dx>dy )
    {   if( x2<x1 )
        {   mid = col1;
            col1 = col2;
            col2 = mid;
        }
        if( dz >= dx )
        {   zrate = dz/dx;
            dz -= dx*zrate;
            if( iz < 0 )
                zrate = -zrate;
        } else zrate = 0;

        err = zerr = -(dx>>1);
        mid = (x1+x2)/2;

        while( x1!=x2 )
        {   if( XValid(x1) && YValid(y1) && ZBValid(x1,z1) )
            {   if( count<2 )
                {   co = (x1<mid)? col1 : col2;
					c = Lut[co];
                    SETPIXEL(dptr,fptr,z1,c);
                    count++;
                } else if( count==3 )
                {   count = 0;
                } else count++;
            }

            if( (err+=dy)>0 )
            {   err -= dx;
                fptr+=ystep;
                dptr+=ystep;
                y1+=iy;
            }

            if( (zerr+=dz)>0 )
            {   zerr -= dx;
                z1 += iz;
            }

            fptr+=ix; dptr+=ix; x1+=ix;
            z1 += zrate;
        }
    } else
    {   if( y1>y2 )
        {   mid = col1;
            col1 = col2;
            col2 = mid;
        }

        if( dz >= dy )
        {   zrate = dz/dy;
            dz -= dy*zrate;
            if( iz < 0 )
                zrate = -zrate;
        } else zrate = 0;

        err = zerr = -(dy>>1);
        mid = (y1+y2)/2;

        
        while( y1!=y2 )
        {   if( XValid(x1) && YValid(y1) && ZBValid(x1,z1) )
            {   if( count<2 )
                {   co = (y1<mid)? col1 : col2;
					c = Lut[co];
                    SETPIXEL(dptr,fptr,z1,c);
                    count++;
                } else if( count==3 )
                {   count = 0;
                } else count++;
            }

            if( (err+=dx)>0 )
            {   err-=dy;
                fptr+=ix;
                dptr+=ix;
                x1+=ix;
            }

            if( (zerr+=dz)>0 )
            {   zerr -= dy;
                z1 += iz;
            }

            fptr+=ystep; dptr+=ystep; y1+=iy;
            z1 += zrate; 
        }
    }
}





/*=============================================*/
/*  Macros for 3D Bresenhams Vector Algorithm  */
/*=============================================*/

#define CommonVectStep(s)  z1 += zrate;   c1 += crate; c2 -= crate;       \
                   SETPIXELP(dptr,fptr,z1,Lut[col+c1],Lut[cola],p);       \
                           if( (zerr+=dz)>0 ) { zerr -= (s); z1 += iz; }  \
                           if( (cerr+=dc)>0 ) { cerr -= (s); c1 += iz; }

#define XVectStep  { if((err+=dy)>0) { fptr+=ystep; dptr+=ystep; err-=dx; } \
                     fptr+=ix; dptr+=ix; x1+=ix;                            \
                     p =  altc && (x1-mid<(dx/4)) && (mid-x1<(dx/4));      \
                     CommonVectStep(dx); }

#define YVectStep  { if((err+=dx)>0) { fptr+=ix; dptr+=ix; err-=dy; } \
                     fptr+=ystep; dptr+=ystep; y1+=iy;                \
                     p =  altc && (y1-mid<(dy/4)) && (mid-y1<(dy/4));\
                     CommonVectStep(dy); }


void DrawTwinVector( int x1, int y1, int z1,
                     int x2, int y2, int z2,
                     int col1, int col2, char altl )
{
    register Long offset;
    register Pixel __huge *fptr;
    register short __huge *dptr;
    register int dx,dy,dz,dc;
    register int crate, cerr;
    register int zrate, zerr;
    register int ystep,err;
    register int ix,iy,iz;
    register int col, cola,  mid=0;
    register int c1, c2;
    register int p, altc;

    c1 = (ColourDepth*(z1+ImageRadius-ZOffset))/ImageSize;
    c2 = (ColourDepth*(z2+ImageRadius-ZOffset))/ImageSize;
    altc = 0;
    if ( altl != '\0' && altl != ' ')
      altc = AltlColours[((int)altl)&(AltlDepth-1)];
    cola = altc;

    offset = (Long)y1*View.yskip + x1;
    fptr = View.fbuf+offset;
    dptr = View.dbuf+offset;

    if ( OValid(offset) ){
      /* SETPIXEL(dptr,fptr,z1,Lut[col1+c1]); */
      if ( z1 > *(dptr+View.shift) ) {
        *(fptr+View.shift) = Lut[col1+c1];
        *(dptr+View.shift) = z1;
      }
    }

    dx = x2 - x1;  dy = y2 - y1;
    dz = z2 - z1;  dc = c2 - c1;
    if( !dx && !dy ) return;

    if( dy<0 ) 
    {   ystep = -View.yskip;
        dy = -dy; 
        iy = -1; 
    } else
    {   ystep = View.yskip;
        iy = 1;
    }

    if( dx<0 ) 
    {   dx = -dx; 
        ix = -1; 
    } else ix = 1;

    iz = (dz<0)? -1 : 1;

    if( dx>dy )
    {   if( dz >= dx )
        {   zrate = dz/dx;
            dz -= dx*zrate;
            if( iz < 0 )
                zrate = -zrate;
        } else zrate = 0;

        if( dc >= dx )
        {   crate = dc/dx;
            dc -= dx*crate;
            if( iz < 0 )
                crate = -crate;
        } else crate = 0;

        err = zerr = cerr = -(dx>>1);
        col = col1;

        if( dz<0 )
        {   dz = -dz;
            dc = -dc;
        }
        
        if( col1 != col2 )
        {   mid = (x1+x2)>>1;
            while( x1!=mid ) XVectStep;
            col = col2;
        }
        while( x1!=x2 ) XVectStep;
    } else
    {   if( dz >= dy )
        {   zrate = dz/dy;
            dz -= dy*zrate;
            if( iz < 0 )
                zrate = -zrate;
        } else zrate = 0;

        if( dc >= dy )
        {   crate = dc/dy;
            dc -= dy*crate;
            if( iz < 0 )
                crate = -crate;
        } else crate = 0;

        err = zerr = cerr = -(dy>>1);
        col = col1;

        if( dz<0 )
        {   dz = -dz;
            dc = -dc;
        }

        if( col1 != col2 )
        {   mid = (y1+y2)>>1;
            while( y1!=mid ) YVectStep;
            col = col2;
        }
        while( y1!=y2 ) YVectStep;
    }
}


void ClipVector( int x1, int y1, int z1,
                        int x2, int y2, int z2,
                        int col, char altl )
{
    register int code1,code2;
    register int delta,rest;
    register int temp;

    OutCode(code1,x1,y1,z1);
    OutCode(code2,x2,y2,z2);
    if( Reject(code1,code2) )
        return;

    while( !Accept(code1,code2) )
    {   if( !code1 )
        {   temp=x1; x1=x2; x2=temp;
            temp=y1; y1=y2; y2=temp;
            temp=z1; z1=z2; z2=temp;
            code1 = code2;
            code2 = 0;
        }

        if( code1 & BitAbove )
        {   delta = y2-y1;
            x1 += (int)(((Long)y1*(x1-x2))/delta);  
            z1 += (int)(((Long)y1*(z1-z2))/delta);
            y1 = 0;
        } else if( code1 & BitLeft )
        {   delta = x2-x1;
            y1 += (int)(((Long)x1*(y1-y2))/delta);
            z1 += (int)(((Long)x1*(z1-z2))/delta);
            x1 = 0;
        } else if( code1 & BitRight )
        {   delta = x2-x1;
            temp=View.xmax-1; rest=temp-x1;
            y1 += (int)(((Long)rest*(y2-y1))/delta);
            z1 += (int)(((Long)rest*(z2-z1))/delta);
            x1 = temp;
        } else if( code1 & BitBelow )
        {   delta = y2-y1;
            temp=View.ymax-1; rest=temp-y1;
            x1 += (int)(((Long)rest*(x2-x1))/delta);
            z1 += (int)(((Long)rest*(z2-z1))/delta);
            y1 = temp;
        } else if( code1 & BitFront )/* SLAB */
        {   delta = z2-z1;
            rest = (SlabValue-1)-z1;
            x1 += (int)(((Long)rest*(x2-x1))/delta);
            y1 += (int)(((Long)rest*(y2-y1))/delta);
            z1 = SlabValue-1;
        } else 
        {   delta = z2-z1;
            rest = (DepthValue+1)-z1;
            x1 += (int)(((Long)rest*(x2-x1))/delta);
            y1 += (int)(((Long)rest*(y2-y1))/delta);
            z1 = DepthValue+1;
        }
        OutCode(code1,x1,y1,z1);
        if( Reject(code1,code2) )
            return;
    }
    DrawTwinVector(x1,y1,z1,x2,y2,z2,col,col,altl);
}


void ClipTwinVector( int x1, int y1, int z1,
                     int x2, int y2, int z2,
                     int col1, int col2, char altl )
{
    register int xmid,ymid,zmid;
    register int code1,code2;

    if( col1!=col2 )
    {   OutCode(code1,x1,y1,z1);
        OutCode(code2,x2,y2,z2);
        if( !Reject(code1,code2) )
        {   if( !Accept(code1,code2) )
            {  xmid = (x1+x2)/2;
               ymid = (y1+y2)/2;
               zmid = (z1+z2)/2;
               ClipVector(x1,y1,z1,xmid,ymid,zmid,col1,altl);
               ClipVector(xmid,ymid,zmid,x2,y2,z2,col2,altl);
            } else
               DrawTwinVector(x1,y1,z1,x2,y2,z2,col1,col2,altl);
        }
    } else
        ClipVector(x1,y1,z1,x2,y2,z2,col1,altl);
}


/*==================================*/
/*  Monochrome Depth-Cued Vectors!  */
/*==================================*/

void DrawTwinVector2( int x1, int y1, int z1,
                      int x2, int y2, int z2,
                      int col1, int col2 )
{
    register int inten;
    register int midz;

    midz = ((z1+z2)/2)+ImageRadius-ZOffset;
    if( midz >= ImageSize )
    {   inten = ColourMask;
    } else if( midz > 0 )
    {   inten = (ColourDepth*midz)/ImageSize;
    } else inten = 0;
    DrawTwinLine(x1,y1,z1,x2,y2,z2,col1+inten,col2+inten,' ');
}


void ClipTwinVector2( int x1, int y1, int z1,
                      int x2, int y2, int z2,
                      int col1, int col2 )
{
    register int inten;
    register int midz;

    midz = ((z1+z2)/2)+ImageRadius-ZOffset;
    if( midz >= ImageSize )
    {   inten = ColourMask;
    } else if( midz > 0 )
    {   inten = (ColourDepth*midz)/ImageSize;
    } else inten = 0;
    ClipTwinLine(x1,y1,z1,x2,y2,z2,col1+inten,col2+inten,' ');
}


void ClipDashVector( int x1, int y1, int z1,
                     int x2, int y2, int z2,
                     int col1, int col2, char altl )
{
    register Long offset;
    register Pixel __huge *fptr;
    register short __huge *dptr;
    register int ix,iy,iz,ic;
    register int dx,dy,dz,dc;
    register int crate, cerr;
    register int zrate, zerr;
    register int ystep,err;
    register int col, cola, mid;
    register int c1, c2;
    register int count;
    register int p, altc;

    if( (x1==x2) && (y1==y2) )
         return;

    /* Reject(OutCode(x1,y1,z1),OutCode(x2,y2,z2)) */
    if( (x1<0) && (x2<0) ) return;
    if( (y1<0) && (y2<0) ) return;
    if( (x1>=View.xmax) && (x2>=View.xmax) ) return;
    if( (y1>=View.ymax) && (y2>=View.ymax) ) return;
    if( UseSlabPlane && (z1>=SlabValue) && (z2>=SlabValue) )
        return;
    if( UseDepthPlane && (z1<=DepthValue) && (z2<=DepthValue) )
        return;

    c1 = (ColourDepth*(z1+ImageRadius-ZOffset))/ImageSize;
    c2 = (ColourDepth*(z2+ImageRadius-ZOffset))/ImageSize;
    altc = 0;
    if ( altl != '\0' && altl != ' ')
      altc = AltlColours[((int)altl)&(AltlDepth-1)];
    cola = altc;

    dx = x2 - x1;  dy = y2 - y1;
    dz = z2 - z1;  dc = c2 - c1;

    offset = (Long)y1*View.yskip + x1;
    fptr = View.fbuf+offset;
    dptr = View.dbuf+offset;
    count = 0;

    ystep = View.yskip;
    ix = iy = iz = ic = 1;
    if( dy<0 ) { dy = -dy; iy = -1; ystep = -ystep; }
    if( dx<0 ) { dx = -dx; ix = -1; }
    if( dz<0 ) { dz = -dz; iz = -1; }
    if( dc<0 ) { dc = -dc; ic = -1; }

    if( dx>dy )
    {   if( x2<x1 )
        {   mid = col1;
            col1 = col2;
            col2 = mid;
        }
        if( dz >= dx )
        {   zrate = dz/dx;
            dz -= dx*zrate;
            if( iz < 0 )
                zrate = -zrate;
        } else zrate = 0;

        if( dc >= dx )
        {   crate = dc/dx;
            dc -= dx*crate;
        } else crate = 0;

        err = zerr = cerr = -(dx>>1);
        mid = (x1+x2)/2;

        while( x1!=x2 )
        {   if( XValid(x1) && YValid(y1) && ZBValid(x1,z1)  )
            {   if( count<2 )
                {   col = (x1<mid)? col1 : col2;
	   	    cola = (x1<mid)? col2 : col1;
                    p =  altc&&(abs(x1-mid)<abs(dx)/4);
                    SETPIXELP(dptr,fptr,z1,Lut[col+c1], Lut[cola],p);
                    count++;
                } else if( count==3 )
                {   count = 0;
                } else count++;
            }

            if( (err+=dy)>0 )
            {   err -= dx;
                fptr+=ystep;
                dptr+=ystep;
                y1+=iy;
            }

            if( (zerr+=dz)>0 )
            {   zerr -= dx;
                z1 += iz;
            }

            if( (cerr+=dc)>0 )
            {   cerr -= dx;
                c1 += ic;
            }

            fptr+=ix; dptr+=ix; x1+=ix;
            z1 += zrate;   c1 += crate;
        }
    } else
    {   if( y1>y2 )
        {   mid = col1;
            col1 = col2;
            col2 = mid;
        }

        if( dz >= dy )
        {   zrate = dz/dy;
            dz -= dy*zrate;
            if( iz < 0 )
                zrate = -zrate;
        } else zrate = 0;

        if( dc >= dy )
        {   crate = dc/dy;
            dc -= dy*crate;
        } else crate = 0;

        err = zerr = cerr = -(dy>>1);
        mid = (y1+y2)/2;

        
        while( y1!=y2 )
        {   if( XValid(x1) && YValid(y1) && ZBValid(x1,z1) )
            {   if( count<2 )
                {   col = (y1<mid)? col1 : col2;
                    p =  altc&&(abs(y1-mid)<abs(dy)/4);
                    SETPIXELP(dptr,fptr,z1,Lut[col+c1],Lut[cola],p);
                    count++;
                } else if( count==3 )
                {   count = 0;
                } else count++;
            }

            if( (err+=dx)>0 )
            {   err-=dy;
                fptr+=ix;
                dptr+=ix;
                x1+=ix;
            }

            if( (zerr+=dz)>0 )
            {   zerr -= dy;
                z1 += iz;
            }

            if( (cerr+=dc)>0 )
            {   cerr -= dy;
                c1 += ic;
            }

            fptr+=ystep; dptr+=ystep; y1+=iy;
            z1 += zrate;   c1 += crate; c2 -=crate;
        }
    }
}


/* SplineCount is either 1, 2, 3, 4, 5 or 9! */
void StrandRibbon( Knot __far *src, Knot __far *dst, int col1, int col2 )
{
    register int hsx, hsy, hsz;
    register int hdx, hdy, hdz;
    register int qsx, qsy, qsz;
    register int qdx, qdy, qdz;
    register int col;

    if( SplineCount != 4 )
    {   if( SplineCount == 1 ) 
        {   ClipVector( src->px, src->py, src->pz,
                        dst->px, dst->py, dst->pz, col2, ' ' );
            return;
        } else if( SplineCount != 2 )
            ClipVector( src->px, src->py, src->pz,
                        dst->px, dst->py, dst->pz, col1, ' ' );

        ClipVector( src->px+src->wx, src->py+src->wy, src->pz+src->wz,
                    dst->px+dst->wx, dst->py+dst->wy, dst->pz+dst->wz, 
                    col2, ' ' );
        ClipVector( src->px-src->wx, src->py-src->wy, src->pz-src->wz,
                    dst->px-dst->wx, dst->py-dst->wy, dst->pz-dst->wz, 
                    col2, ' ' );
        if( SplineCount<=3 ) return;

        hsx = src->wx/2;  hsy = src->wy/2;  hsz = src->wz/2;
        hdx = dst->wx/2;  hdy = dst->wy/2;  hdz = dst->wz/2;

        ClipVector( src->px+hsx, src->py+hsy, src->pz+hsz,
                    dst->px+hdx, dst->py+hdy, dst->pz+hdz, col1, ' ' );
        ClipVector( src->px-hsx, src->py-hsy, src->pz-hsz,
                    dst->px-hdx, dst->py-hdy, dst->pz-hdz, col1, ' ' );
        if( SplineCount==5 ) 
            return;
        col = col1;
    } else /* SplineCount == 4 */
    {   hsx = src->wx/2;  hsy = src->wy/2;  hsz = src->wz/2;
        hdx = dst->wx/2;  hdy = dst->wy/2;  hdz = dst->wz/2;
        col = col2;
    }

    qsx = hsx/2;  qsy = hsy/2;  qsz = hsz/2;
    qdx = hdx/2;  qdy = hdy/2;  qdz = hdz/2;

    ClipVector( src->px+hsx+qsx, src->py+hsy+qsy, src->pz+hsz+qsz,
                dst->px+hdx+qdx, dst->py+hdy+qdy, dst->pz+hdz+qdz, 
                col, ' ' );
    ClipVector( src->px+hsx-qsx, src->py+hsy-qsy, src->pz+hsz-qsz,
                dst->px+hdx-qdx, dst->py+hdy-qdy, dst->pz+hdz-qdz, 
                col1, ' ' );
    ClipVector( src->px-hsx+qsx, src->py-hsy+qsy, src->pz-hsz+qsz,
                dst->px-hdx+qdx, dst->py-hdy+qdy, dst->pz-hdz+qdz, 
                col1, ' ' );
    ClipVector( src->px-hsx-qsx, src->py-hsy-qsy, src->pz-hsz-qsz,
                dst->px-hdx-qdx, dst->py-hdy-qdy, dst->pz-hdz-qdz, 
                col, ' ' );
}


void DashRibbon( Knot __far *src, Knot __far *dst, int col1, int col2 )
{
    register int hsx, hsy, hsz;
    register int hdx, hdy, hdz;
    register int qsx, qsy, qsz;
    register int qdx, qdy, qdz;
    register int col;

    if( SplineCount != 4 )
    {   if( SplineCount == 1 ) 
        {   ClipDashVector( src->px, src->py, src->pz,
                            dst->px, dst->py, dst->pz, col2, col2, ' ' );
            return;
        } else if( SplineCount != 2 )
            ClipDashVector( src->px, src->py, src->pz,
                            dst->px, dst->py, dst->pz, col1, col1, ' ' );

        ClipDashVector(src->px+src->wx,src->py+src->wy,src->pz+src->wz,
                       dst->px+dst->wx,dst->py+dst->wy,dst->pz+dst->wz,
                       col2,col2, ' ');
        ClipDashVector(src->px-src->wx,src->py-src->wy,src->pz-src->wz,
                       dst->px-dst->wx,dst->py-dst->wy,dst->pz-dst->wz,
                       col2,col2, ' ');
        if( SplineCount<=3 ) return;

        hsx = src->wx/2;  hsy = src->wy/2;  hsz = src->wz/2;
        hdx = dst->wx/2;  hdy = dst->wy/2;  hdz = dst->wz/2;

        ClipDashVector( src->px+hsx, src->py+hsy, src->pz+hsz,
                        dst->px+hdx, dst->py+hdy, dst->pz+hdz, 
                        col1, col1, ' ' );
        ClipDashVector( src->px-hsx, src->py-hsy, src->pz-hsz,
                        dst->px-hdx, dst->py-hdy, dst->pz-hdz, 
                        col1, col1, ' ' );
        if( SplineCount==5 ) 
            return;
        col = col1;
    } else /* SplineCount == 4 */
    {   hsx = src->wx/2;  hsy = src->wy/2;  hsz = src->wz/2;
        hdx = dst->wx/2;  hdy = dst->wy/2;  hdz = dst->wz/2;
        col = col2;
    }

    qsx = hsx/2;  qsy = hsy/2;  qsz = hsz/2;
    qdx = hdx/2;  qdy = hdy/2;  qdz = hdz/2;

    ClipDashVector(src->px+hsx+qsx,src->py+hsy+qsy,src->pz+hsz+qsz,
                   dst->px+hdx+qdx,dst->py+hdy+qdy,dst->pz+hdz+qdz,
                   col,col, ' ');
    ClipDashVector(src->px+hsx-qsx,src->py+hsy-qsy,src->pz+hsz-qsz,
                   dst->px+hdx-qdx,dst->py+hdy-qdy,dst->pz+hdz-qdz,
                   col1,col1, ' ');
    ClipDashVector(src->px-hsx+qsx,src->py-hsy+qsy,src->pz-hsz+qsz,
                   dst->px-hdx+qdx,dst->py-hdy+qdy,dst->pz-hdz+qdz,
                   col1,col1, ' ');
    ClipDashVector(src->px-hsx-qsx,src->py-hsy-qsy,src->pz-hsz-qsz,
                   dst->px-hdx-qdx,dst->py-hdy-qdy,dst->pz-hdz-qdz,
                   col,col, ' ');
}


#ifdef UNUSED /* Unused Function */
static void OutLinePolygon( Poly *p )
{
    register int i;

    for( i=0; i<p->count-1; i++ )
         ClipLine( p->v[i].x, p->v[i].y, p->v[i].z, 
                   p->v[i+1].x, p->v[i+1].y, p->v[i+1].z,
                   p->v[i].inten);
    ClipLine( p->v[i].x, p->v[i].y, p->v[i].z,
              p->v[0].x, p->v[0].y, p->v[0].z,
              p->v[i].inten);
}
#endif


#ifdef UNUSED
static void DrawPolygon(  Poly *p )
{
    static Edge lft, rgt;
    register Edge *pmin, *pmax;
    register Pixel __huge *fbase;
    register short __huge *dbase;
    register short __huge *dptr;
    register Long offset;

    register Long dz,di;
    register Long z,inten;
    register int ri,li,ry,ly;
    register int xmin,xmax;
    register int dy,ymin;
    register int top,rem;
    register int x,y,i;

    /* Find top vertex */
    top = 0;  
    ymin = p->v[0].y;
    for( i=1; i<p->count; i++ )
       if( p->v[i].y < ymin )
       {   ymin = p->v[i].y;
           top = i;
       }

    rem = p->count;
    ly = ry = y = ymin;
    li = ri = top;

    offset = (Long)y*View.yskip;
    fbase = View.fbuf+offset;
    dbase = View.dbuf+offset;

    while( rem )
    {   while( ly<=y && rem )
        {   i = li-1; if( i<0 ) i=p->count-1;
            if( p->v[i].y > y )
            {   dy = p->v[i].y - ly;
                lft.di = (((Long)(p->v[i].inten - p->v[li].inten))<<16)/dy;
                lft.dx = (((Long)(p->v[i].x - p->v[li].x))<<16)/dy;
                lft.dz = (((Long)(p->v[i].z - p->v[li].z))<<16)/dy;

                lft.i = ((Long)p->v[li].inten)<<16;
                lft.x = ((Long)p->v[li].x)<<16;
                lft.z = ((Long)p->v[li].z)<<16;
            }
            ly = p->v[i].y;
            rem--;  li = i;
        }

        while( ry<=y && rem )
        {   i = ri+1; if( i>=p->count ) i = 0;
            if( p->v[i].y > y )
            {   dy = p->v[i].y - ry;
                rgt.di = (((Long)(p->v[i].inten - p->v[ri].inten))<<16)/dy;
                rgt.dx = (((Long)(p->v[i].x - p->v[ri].x))<<16)/dy;
                rgt.dz = (((Long)(p->v[i].z - p->v[ri].z))<<16)/dy;

                rgt.i = ((Long)p->v[ri].inten)<<16;
                rgt.x = ((Long)p->v[ri].x)<<16;
                rgt.z = ((Long)p->v[ri].z)<<16;
            }
            ry = p->v[i].y;
            rem--; ri = i;
        }

        ymin = MinFun(ly,ry);
        
        while( y<ymin )
        {   if( lft.x < rgt.x )
            {   pmin = &lft;
                pmax = &rgt;
            } else
            {   pmin = &rgt;
                pmax = &lft;
            }

            xmax = (int)(pmax->x>>16)+1;
            xmin = (int)(pmin->x>>16);

            di = (Long)((pmax->i-pmin->i)/(xmax-xmin));
            dz = (Long)((pmax->z-pmin->z)/(xmax-xmin));
            inten = pmin->i;  
            z = pmin->z;

            dptr = dbase+xmin;
            for( x=xmin; x<xmax; x++ )
            {   if( (int)(z>>16) > *(dptr+View.shift) )
                {   fbase[x+View.shift] = Lut[(int)(inten>>16)];
                    *(dptr+View.shift) = (int)(z>>16);
                }
                inten += di;
                z += dz;
                dptr++;
            }

            lft.x += lft.dx;  rgt.x += rgt.dx;
            lft.z += lft.dz;  rgt.z += rgt.dz;
            lft.i += lft.di;  rgt.i += rgt.di;
            dbase += View.yskip;
            fbase += View.yskip;
            y++;
        }
    }
}
#endif


#ifdef UNUSED
static void DrawFlatPolygon( Poly *p )
{
    static Edge lft, rgt;
    register Edge *pmin, *pmax;
    register Pixel __huge *fbase;
    register short __huge *dbase;
    register short __huge *dptr;
    register Long offset;

    register Long z,dz;
    register int ri,li,ry,ly;
    register int xmin,xmax;
    register int dy,ymin;
    register int top,rem;
    register int x,y,i;

    /* Find top vertex */
    top = 0;  
    ymin = p->v[0].y;
    for( i=1; i<p->count; i++ )
       if( p->v[i].y < ymin )
       {   ymin = p->v[i].y;
           top = i;
       }

    rem = p->count;
    ly = ry = y = ymin;
    li = ri = top;

    offset = (Long)y*View.yskip;
    fbase = View.fbuf+offset;
    dbase = View.dbuf+offset;

    while( rem )
    {   while( ly<=y && rem )
        {   i = li-1; if( i<0 ) i=p->count-1;
            if( p->v[i].y > y )
            {   dy = p->v[i].y - ly;
                lft.dx = (((Long)(p->v[i].x - p->v[li].x))<<16)/dy;
                lft.dz = (((Long)(p->v[i].z - p->v[li].z))<<16)/dy;

                lft.x = ((Long)p->v[li].x)<<16;
                lft.z = ((Long)p->v[li].z)<<16;
            }
            ly = p->v[i].y;
            rem--;  li = i;
        }

        while( ry<=y && rem )
        {   i = ri+1; if( i>=p->count ) i = 0;
            if( p->v[i].y > y )
            {   dy = p->v[i].y - ry;
                rgt.dx = (((Long)(p->v[i].x - p->v[ri].x))<<16)/dy;
                rgt.dz = (((Long)(p->v[i].z - p->v[ri].z))<<16)/dy;

                rgt.x = ((Long)p->v[ri].x)<<16;
                rgt.z = ((Long)p->v[ri].z)<<16;
            }
            ry = p->v[i].y;
            rem--; ri = i;
        }


        ymin = MinFun(ly,ry);
        
        while( y<ymin )
        {   if( lft.x < rgt.x )
            {   pmin = &lft;
                pmax = &rgt;
            } else
            {   pmin = &rgt;
                pmax = &lft;
            }

            xmax = (int)(pmax->x>>16)+1;
            xmin = (int)(pmin->x>>16);

            dz = (Long)((pmax->z-pmin->z)/(xmax-xmin));
            z = pmin->z;

            dptr = dbase+xmin;
            for( x=xmin; x<xmax; x++ )
            {   if( (int)(z>>16) > *(dptr+View.shift) )
                {   fbase[x+View.shift] = Lut[p->v[0].inten];
                    *(dptr+View.shift) = (int)(z>>16);
                }
                z += dz;
                dptr++;
            }

            lft.x += lft.dx;  rgt.x += rgt.dx;
            lft.z += lft.dz;  rgt.z += rgt.dz;
            dbase += View.yskip;
            fbase += View.yskip;
            y++;
        }
    }
}
#endif


void ClipPolygon( Poly *p )
{
    static Edge lft, rgt;
    register Edge *pmin, *pmax;
    register Pixel __huge *fbase;
    register short __huge *dbase;
    register short __huge *dptr;
    register Long offset;

    register Long dz,di;
    register Long z,inten;
    register int ri,li,ry,ly;
    register int xmin,xmax;
    register int dy,ymin;
    register int top,rem;
    register int x,y,i;
    register int anyin, anyout;
    register int xp;

    anyout = False;
    for (i = 0; i < p->count; i++) {
      if (p->v[i].y < 0 || p->v[i].y >= View.ymax ) anyout = True;
    }

    /* Reject Clip Polygon */
    if( UseSlabPlane )  {
        anyin = False;
        for( i=0; i<p->count; i++ ) {
          
          xp = p->v[i].x;
          if ( xp < 0 ) { anyout = True; continue; }
          if ( xp >= View.xmax) { anyout = True; continue; }
          if( p->v[i].z < View.slbuf[xp] )
                anyin = True;
          else anyout = True;
        }
        if (!anyin) return;
    }
    if( UseDepthPlane ) {
        anyin = False;
        for( i=0; i<p->count; i++ ) {
          xp = p->v[i].x;
          if ( xp < 0 ) { anyout = True; continue; }
          if ( xp >= View.xmax) { anyout = True; continue; }
          if( p->v[i].z > View.dlbuf[xp] )
                anyin = True;
          else anyout = True;
        }
        if (!anyin) return;
    }
    /* Find top vertex */
    top = 0;  
    ymin = p->v[0].y;
    for( i=1; i<p->count; i++ )
       if( p->v[i].y < ymin )
       {   ymin = p->v[i].y;
           top = i;
       }

    rem = p->count;
    ly = ry = y = ymin;
    li = ri = top;

    if( y<0 )
    {   rem--;

        while( ly<=0 && rem )
        {   i = li-1; if( i<0 ) i=p->count-1;
            if( p->v[i].y > 0 )
            {   dy = p->v[i].y - ly;
                lft.di = (((Long)(p->v[i].inten - p->v[li].inten))<<16)/dy;
                lft.dx = (((Long)(p->v[i].x - p->v[li].x))<<16)/dy;
                lft.dz = (((Long)(p->v[i].z - p->v[li].z))<<16)/dy;

                lft.i = (((Long)p->v[li].inten)<<16) - (Long)ly*lft.di;
                lft.x = (((Long)p->v[li].x)<<16) - (Long)ly*lft.dx;
                lft.z = (((Long)p->v[li].z)<<16) - (Long)ly*lft.dz;
            } else rem--;
            ly = p->v[i].y;
            li = i;
        }

        while( ry<=0 && rem )
        {   i = ri+1; if( i>=p->count ) i = 0;
            if( p->v[i].y > 0 )
            {   dy = p->v[i].y - ry;
                rgt.di = (((Long)(p->v[i].inten - p->v[ri].inten))<<16)/dy;
                rgt.dx = (((Long)(p->v[i].x - p->v[ri].x))<<16)/dy;
                rgt.dz = (((Long)(p->v[i].z - p->v[ri].z))<<16)/dy;

                rgt.i = (((Long)p->v[ri].inten)<<16) - (Long)ry*rgt.di;
                rgt.x = (((Long)p->v[ri].x)<<16) - (Long)ry*rgt.dx;
                rgt.z = (((Long)p->v[ri].z)<<16) - (Long)ry*rgt.dz;
            } else rem--;
            ry = p->v[i].y;
            ri = i;
        }

        fbase = View.fbuf;
        dbase = View.dbuf;
        y = 0;
    } else /* y >= 0 */
    {   offset = (Long)y*View.yskip;
        fbase = View.fbuf+offset;
        dbase = View.dbuf+offset;
    }

    while( rem )
    {   while( ly<=y && rem )
        {   i = li-1; if( i<0 ) i=p->count-1;
            if( p->v[i].y > y )
            {   dy = p->v[i].y - ly;
                lft.di = (((Long)(p->v[i].inten - p->v[li].inten))<<16)/dy;
                lft.dx = (((Long)(p->v[i].x - p->v[li].x))<<16)/dy;
                lft.dz = (((Long)(p->v[i].z - p->v[li].z))<<16)/dy;

                lft.i = ((Long)p->v[li].inten)<<16;
                lft.x = ((Long)p->v[li].x)<<16;
                lft.z = ((Long)p->v[li].z)<<16;
            }
            ly = p->v[i].y;
            rem--;  li = i;
        }

        while( ry<=y && rem )
        {   i = ri+1; if( i>=p->count ) i = 0;
            if( p->v[i].y > y )
            {   dy = p->v[i].y - ry;
                rgt.di = (((Long)(p->v[i].inten - p->v[ri].inten))<<16)/dy;
                rgt.dx = (((Long)(p->v[i].x - p->v[ri].x))<<16)/dy;
                rgt.dz = (((Long)(p->v[i].z - p->v[ri].z))<<16)/dy;

                rgt.i = ((Long)p->v[ri].inten)<<16;
                rgt.x = ((Long)p->v[ri].x)<<16;
                rgt.z = ((Long)p->v[ri].z)<<16;
            }
            ry = p->v[i].y;
            rem--; ri = i;
        }


        ymin = MinFun(ly,ry);
        if( ymin>View.ymax )
        {   ymin = View.ymax;
            rem = 0;
        }
        
        while( y<ymin )
        {   if( lft.x < rgt.x )
            {   pmin = &lft;
                pmax = &rgt;
            } else
            {   pmin = &rgt;
                pmax = &lft;
            }

            xmax = (int)(pmax->x>>16)+1;
            xmin = (int)(pmin->x>>16);

            if( (xmin<View.xmax) && (xmax>=0) )
            {   di = (Long)((pmax->i-pmin->i)/(xmax-xmin));
                dz = (Long)((pmax->z-pmin->z)/(xmax-xmin));
                if( xmin<0 )
                {   inten = pmin->i - xmin*di;
                    z = pmin->z - xmin*dz;
                    xmin = 0;
                } else /* xmin >= 0 */
                {   inten = pmin->i;  
                    z = pmin->z;
                }

                if( xmax>=View.xmax )
                    xmax = View.xmax;

                dptr = dbase+xmin;
                for( x=xmin; x<xmax; x++ )
                {   if( (!anyout ||((XValid(x))&&(YValid(y))&&(ZBValid(x,(int)(z>>16)))))
                      && (int)(z>>16) > *(dptr+View.shift ) )
                    {   fbase[x+View.shift] = Lut[(int)(inten>>16)];
                        *(dptr+View.shift) = (int)(z>>16);
                    }
                    inten += di;
                    z += dz;
                    dptr++;
                }
            }

            lft.x += lft.dx;  rgt.x += rgt.dx;
            lft.z += lft.dz;  rgt.z += rgt.dz;
            lft.i += lft.di;  rgt.i += rgt.di;
            dbase += View.yskip;
            fbase += View.yskip;
            y++;
        }
    }
}

  
#ifdef UNUSED
static void ClipFlatPolygon( Poly *p )
{
    static Edge lft, rgt;
    register Edge *pmin, *pmax;
    register Pixel __huge *fbase;
    register short __huge *dbase;
    register short __huge *dptr;
    register Long offset;

    register Long z,dz;
    register int ri,li,ry,ly;
    register int xmin,xmax;
    register int dy,ymin;
    register int top,rem;
    register int x,y,i;

    /* Reject Clip Polygon */
    if( UseSlabPlane )
        for( i=0; i<p->count; i++ )
            if( p->v[i].z >= SlabValue )
                return;

     if( UseDepthPlane )
        for( i=0; i<p->count; i++ )
            if( p->v[i].z <= DepthValue )
                return;
   /* Find top vertex */
    top = 0;  
    ymin = p->v[0].y;
    for( i=1; i<p->count; i++ )
       if( p->v[i].y < ymin )
       {   ymin = p->v[i].y;
           top = i;
       }

    rem = p->count;
    ly = ry = y = ymin;
    li = ri = top;

    if( y<0 )
    {   rem--;

        while( ly<=0 && rem )
        {   i = li-1; if( i<0 ) i=p->count-1;
            if( p->v[i].y > 0 )
            {   dy = p->v[i].y - ly;
                lft.dx = (((Long)(p->v[i].x - p->v[li].x))<<16)/dy;
                lft.dz = (((Long)(p->v[i].z - p->v[li].z))<<16)/dy;

                lft.x = ((Long)p->v[li].x)<<16;
                lft.z = ((Long)p->v[li].z)<<16;
            } else rem--;
            ly = p->v[i].y;
            li = i;
        }

        while( ry<=0 && rem )
        {   i = ri+1; if( i>=p->count ) i = 0;
            if( p->v[i].y > 0 )
            {   dy = p->v[i].y - ry;
                rgt.dx = (((Long)(p->v[i].x - p->v[ri].x))<<16)/dy;
                rgt.dz = (((Long)(p->v[i].z - p->v[ri].z))<<16)/dy;

                rgt.x = ((Long)p->v[ri].x)<<16;
                rgt.z = ((Long)p->v[ri].z)<<16;
            } else rem--;
            ry = p->v[i].y;
            ri = i;
        }

        fbase = View.fbuf;
        dbase = View.dbuf;
        y = 0;
    } else /* y >= 0 */
    {   offset = (Long)y*View.yskip;
        fbase = View.fbuf+offset;
        dbase = View.dbuf+offset;
    }

    while( rem )
    {   while( ly<=y && rem )
        {   i = li-1; if( i<0 ) i=p->count-1;
            if( p->v[i].y > y )
            {   dy = p->v[i].y - ly;
                lft.dx = (((Long)(p->v[i].x - p->v[li].x))<<16)/dy;
                lft.dz = (((Long)(p->v[i].z - p->v[li].z))<<16)/dy;

                lft.x = ((Long)p->v[li].x)<<16;
                lft.z = ((Long)p->v[li].z)<<16;
            }
            ly = p->v[i].y;
            rem--;  li = i;
        }

        while( ry<=y && rem )
        {   i = ri+1; if( i>=p->count ) i = 0;
            if( p->v[i].y > y )
            {   dy = p->v[i].y - ry;
                rgt.dx = (((Long)(p->v[i].x - p->v[ri].x))<<16)/dy;
                rgt.dz = (((Long)(p->v[i].z - p->v[ri].z))<<16)/dy;

                rgt.x = ((Long)p->v[ri].x)<<16;
                rgt.z = ((Long)p->v[ri].z)<<16;
            }
            ry = p->v[i].y;
            rem--; ri = i;
        }

        ymin = MinFun(ly,ry);
        if( ymin>View.ymax )
        {   ymin = View.ymax;
            rem = 0;
        }
        
        while( y<ymin )
        {   if( lft.x < rgt.x )
            {   pmin = &lft;
                pmax = &rgt;
            } else
            {   pmin = &rgt;
                pmax = &lft;
            }

            xmax = (int)(pmax->x>>16)+1;
            xmin = (int)(pmin->x>>16);

            if( (xmin<View.xmax) && (xmax>=0) )
            {   dz = (Long)((pmax->z-pmin->z)/(xmax-xmin));
                if( xmin<0 )
                {   z = pmin->z - xmin*dz;
                    xmin = 0;
                } else /* xmin >= 0 */
                    z = pmin->z;

                if( xmax>=View.xmax )
                    xmax = View.xmax;

                dptr = dbase+xmin;
                for( x=xmin; x<xmax; x++ )
                {   if( (int)(z>>16) > *(dptr+View.shift ) )
                    {   fbase[x+View.shift] = Lut[p->v[0].inten];
                        *(dptr+View.shift) = (int)(z>>16);
                    }
                    z += dz;
                    dptr++;
                }
            }

            lft.x += lft.dx;  rgt.x += rgt.dx;
            lft.z += lft.dz;  rgt.z += rgt.dz;
            dbase += View.yskip;
            fbase += View.yskip;
            y++;
        }
    }
}
#endif


void SolidRibbon( Knot __far *src, Knot __far *dst, int col )
{
    static Poly p;

    p.v[0].x = src->px+src->wx;  
    p.v[0].y = src->py+src->wy;  
    p.v[0].z = src->pz+src->wz;
    p.v[0].inten = src->vinten+col;

    p.v[1].x = dst->px+dst->wx;  
    p.v[1].y = dst->py+dst->wy;  
    p.v[1].z = dst->pz+dst->wz;
    p.v[1].inten = dst->vinten+col;

    p.v[2].x = dst->px-dst->wx;
    p.v[2].y = dst->py-dst->wy;  
    p.v[2].z = dst->pz-dst->wz;
    p.v[2].inten = dst->vinten+col;

    p.v[3].x = src->px-src->wx;  
    p.v[3].y = src->py-src->wy;  
    p.v[3].z = src->pz-src->wz;
    p.v[3].inten = src->vinten+col;

    p.count = 4;
    /* OutLinePolygon( &p ); */
    ClipPolygon( &p );
}


void SolidRibbon2( Knot __far *src, Knot __far *dst, int col1, int col2 )
{
    register int dx,dy;
    register int col;
    static Poly p;

    p.count = 3;
    p.v[0].x = src->px+src->wx;  
    p.v[0].y = src->py+src->wy;  
    p.v[0].z = src->pz+src->wz;
    p.v[1].x = dst->px-dst->wx;  
    p.v[1].y = dst->py-dst->wy;  
    p.v[1].z = dst->pz-dst->wz;

    dx = p.v[1].x - p.v[0].x;
    dy = p.v[1].y - p.v[0].y;

    p.v[2].x = dst->px+dst->wx;
    p.v[2].y = dst->py+dst->wy;  
    p.v[2].z = dst->pz+dst->wz;

#ifdef INVERT
    col = ( dst->wx*dy > dst->wy*dx )? col2 : col1;
#else
    col = ( dst->wx*dy < dst->wy*dx )? col2 : col1;
#endif
    p.v[0].inten = src->vinten+col;
    p.v[1].inten = dst->vinten+col;
    p.v[2].inten = dst->vinten+col;

    /* OutLinePolygon( &p ); */
    ClipPolygon( &p );

    p.v[2].x = src->px-src->wx;  
    p.v[2].y = src->py-src->wy;  
    p.v[2].z = src->pz-src->wz;

#ifdef INVERT
    col = ( src->wx*dy > src->wy*dx )? col2 : col1;
#else
    col = ( src->wx*dy < src->wy*dx )? col2 : col1;
#endif

    p.v[0].inten = src->vinten+col;
    p.v[1].inten = dst->vinten+col;
    p.v[2].inten = src->vinten+col;
    /* OutLinePolygon( &p ); */
    ClipPolygon( &p );
}


void RectRibbon( Knot __far *src, Knot __far *dst, int col )
{
    static Poly p;

    p.count = 4;

    p.v[0].inten = src->vinten+col;
    p.v[1].inten = dst->vinten+col;
    p.v[2].inten = dst->vinten+col;
    p.v[3].inten = src->vinten+col;

    /* Top Surface */
    p.v[0].x = src->px+src->wx+src->dx;  
    p.v[0].y = src->py+src->wy+src->dy;  
    p.v[0].z = src->pz+src->wz+src->dz;

    p.v[1].x = dst->px+dst->wx+dst->dx;  
    p.v[1].y = dst->py+dst->wy+dst->dy;  
    p.v[1].z = dst->pz+dst->wz+dst->dz;

    p.v[2].x = dst->px-dst->wx+dst->dx;
    p.v[2].y = dst->py-dst->wy+dst->dy;  
    p.v[2].z = dst->pz-dst->wz+dst->dz;

    p.v[3].x = src->px-src->wx+src->dx;  
    p.v[3].y = src->py-src->wy+src->dy;  
    p.v[3].z = src->pz-src->wz+src->dz;
    ClipPolygon( &p );

    /* Bottom Surface */
    p.v[0].x = src->px+src->wx-src->dx;  
    p.v[0].y = src->py+src->wy-src->dy;  
    p.v[0].z = src->pz+src->wz-src->dz;

    p.v[1].x = dst->px+dst->wx-dst->dx;  
    p.v[1].y = dst->py+dst->wy-dst->dy;  
    p.v[1].z = dst->pz+dst->wz-dst->dz;

    p.v[2].x = dst->px-dst->wx-dst->dx;
    p.v[2].y = dst->py-dst->wy-dst->dy;  
    p.v[2].z = dst->pz-dst->wz-dst->dz;

    p.v[3].x = src->px-src->wx-src->dx;  
    p.v[3].y = src->py-src->wy-src->dy;  
    p.v[3].z = src->pz-src->wz-src->dz;
    ClipPolygon( &p );

    p.v[0].inten = src->hinten+col;
    p.v[1].inten = dst->hinten+col;
    p.v[2].inten = dst->hinten+col;
    p.v[3].inten = src->hinten+col;

    /* Left Surface */
    p.v[0].x = src->px+src->wx+src->dx;  
    p.v[0].y = src->py+src->wy+src->dy;  
    p.v[0].z = src->pz+src->wz+src->dz;

    p.v[1].x = dst->px+dst->wx+dst->dx;  
    p.v[1].y = dst->py+dst->wy+dst->dy;  
    p.v[1].z = dst->pz+dst->wz+dst->dz;

    p.v[2].x = dst->px+dst->wx-dst->dx;
    p.v[2].y = dst->py+dst->wy-dst->dy;  
    p.v[2].z = dst->pz+dst->wz-dst->dz;

    p.v[3].x = src->px+src->wx-src->dx;  
    p.v[3].y = src->py+src->wy-src->dy;  
    p.v[3].z = src->pz+src->wz-src->dz;
    ClipPolygon( &p );

    /* Right Surface */
    p.v[0].x = src->px-src->wx+src->dx;  
    p.v[0].y = src->py-src->wy+src->dy;  
    p.v[0].z = src->pz-src->wz+src->dz;

    p.v[1].x = dst->px-dst->wx+dst->dx;  
    p.v[1].y = dst->py-dst->wy+dst->dy;  
    p.v[1].z = dst->pz-dst->wz+dst->dz;

    p.v[2].x = dst->px-dst->wx-dst->dx;
    p.v[2].y = dst->py-dst->wy-dst->dy;  
    p.v[2].z = dst->pz-dst->wz-dst->dz;

    p.v[3].x = src->px-src->wx-src->dx;  
    p.v[3].y = src->py-src->wy-src->dy;  
    p.v[3].z = src->pz-src->wz-src->dz;
    ClipPolygon( &p );
}


static int TestSphere( int x, int y, int z, int rad )
{
    register int temp;
    register int zrad;
    register int xp;
    double theta;

    ClipStatus = 0;
    
    xp = x;
    if (xp < 0) xp =0;
    if (xp >= View.xmax) xp = View.xmax-1;
    zrad = rad;
    if (UseStereo) {
      theta = -PI*StereoAngle/360.;
      zrad = rint(((double)rad)/cos(theta));
    }

    if( UseSlabPlane )
    {   if( z-zrad>=View.slbuf[xp] )
            return( False );

        if( z+zrad>=View.slbuf[xp] )
        {   if( SlabMode != SlabReject )
            {   ClipStatus |= BitFront;
            } else return( False );
        } else if( SlabMode==SlabSection )
            return( False );
    }

    if( UseDepthPlane )
    {   if( z+zrad<=View.dlbuf[xp])
            return( False );

        if( z-zrad<=View.dlbuf[xp])
        {   if( SlabMode != SlabReject )
            {   ClipStatus |= BitBack;
            } else return( False );
        } else if( SlabMode==SlabSection )
            return( False );
    }

    temp = x+rad;
    if( temp<0 ) return( False );
    if( temp>=View.xmax ) ClipStatus |= BitRight;

    temp = x-rad;
    if( temp>=View.xmax ) return( False );
    if( temp<0 ) ClipStatus |= BitLeft;

    temp = y+rad;
    if( temp<0 ) return( False );
    if( temp>=View.ymax ) ClipStatus |= BitBelow;

    temp = y-rad;
    if( temp>=View.ymax ) return( False );
    if( temp<0 ) ClipStatus |= BitAbove;

    return True;
}



/*===========================*/
/*  Sphere Rendering Macros  */
/*===========================*/

#define UpdateAcross(dz)                                \
        depth = (dz)+z;                                 \
        if( depth > *(dptr+View.shift) )                \
        {   *(dptr+View.shift) = depth;                 \
            fptr = fold+dx;                             \
            inten = LightDot(dx,dy,dz);                 \
            if( inten>0 )                               \
            {      inten = (int)((inten*colconst(rad))>>ColBits); \
                   *(fptr+View.shift) = Lut[col+inten]; \
            } else *(fptr+View.shift) = Lut[col];       \
        }                                  \
        dptr++;  dx++;


#define oUpdateLine  \
        dx = -wide;                   \
        dptr = dold-wide;             \
        tptr = LookUp[wide]+wide;     \
        while( dx<0 ) { UpdateAcross(*tptr); tptr--; }       \
        do { UpdateAcross(*tptr); tptr++; } while(dx<=wide); \
        dold += View.yskip;  fold += View.yskip;             \
        dy++;

#define UpdateLine  \
        dx = -wide;                   \
        dptr = dold-wide;             \
        while( dx<0 ) { UpdateAcross(pythag(wide,-dx));} \
        do { UpdateAcross(pythag(wide,dx)); } while(dx<=wide); \
        dold += View.yskip;  fold += View.yskip;             \
        dy++;


void DrawSphere( int x, int y, int z, int rad, int col )
{
    register Pixel __huge *fptr, __huge *fold;
    register short __huge *dptr, __huge *dold;

    register Long offset;
    register int depth,wide,inten;
    register int dx,dy;

    /* Avoid Lookup Table Overflow! */
    /* if( rad > MAXRAD ) rad = MAXRAD; */

    offset = (Long)(y-rad)*View.yskip + x;
    fold=View.fbuf+offset;  
    dold=View.dbuf+offset;

    dy = -rad;
    while( dy<0 ) 
    {   wide = pythag(rad,-dy); 
        UpdateLine; 
    }

    do { 
        wide = pythag(rad,dy);  
        UpdateLine; 
    } while( dy<=rad );
}


#ifndef max
#define max(a, b) ((a) < (b) ? (b) : (a))
#endif


void ClipSphere( int x, int y, int z, int rad, int col )
{
    register Pixel __huge *fptr, __huge *fold;
    register short __huge *dptr, __huge *dold;

    register int lastx,lasty,dx,dy,dz;
    register int depth,wide,inten,side;
    register int crad,cwide,temp;
    register Long offset;


    /* If this sphere is not visible, do not draw it */
    if( !TestSphere(x,y,z,rad) )
        return;

    /* If this sphere is completely visible, draw it */
    if( !ClipStatus )
    {   DrawSphere(x,y,z,rad,col);
        return;
    }


    /* If we hit y=0, start there */
    if( ClipStatus&BitAbove )
    {   dy = -y;
        fold = View.fbuf + x;
        dold = View.dbuf + x;
    } else
    /* else start at the top of the sphere */
    {   dy = -rad;
        offset = (Long)(y+dy)*View.yskip+x;
        fold = View.fbuf + offset;
        dold = View.dbuf + offset;
    }

    /* If we hit the bottom of the screen, end there */
    if( ClipStatus&BitBelow )
    {   lasty = (View.ymax-1)-y;
    } else lasty = rad;

    /* side is as far as dx can go */
    side = (View.xmax-1)-x;
    dx = 0;
    /* No Slab Plane Clipping */
    if( !(ClipStatus&BitFront) && !(ClipStatus&BitBack) )
    {   while( dy<=lasty )
        {   wide = pythag(rad,AbsFun(dy));
            lastx = MinFun(wide,side);
            dx = - MinFun(wide,x);
            dptr = dold + dx;

            while( dx<=lastx )
            {   dz = pythag(wide,AbsFun(dx));
                UpdateAcross(dz);
            }
            dold += View.yskip;
            fold += View.yskip;
            dy++;
        }
        return;
    }


    /* we have slab plane clipping  or depth clipping */
    
    if (SlabMode == SlabReject) return;
    
    if (!UseStereo) {
    dz = SlabValue-z;
    crad = pythag(rad,AbsFun(dz));
 
    if( (z>SlabValue) || (SlabMode==SlabSection) )
    {   if( crad<lasty ) lasty = crad;
        if( -crad>dy ) 
        {   dy = -crad;
            offset = (Long)(y+dy)*View.yskip+x;
            fold = View.fbuf + offset;
            dold = View.dbuf + offset;
        }
    }

    while( dy<=lasty )
    {   temp = AbsFun(dy);
        wide = pythag(rad,temp);
        lastx = MinFun(wide,side);
        dx = - MinFun(x,wide);
        dptr = dold + dx;

        if( temp<=crad )
        {   cwide = pythag(crad,temp);
            while( dx<=lastx )
            {   temp = AbsFun(dx);
                if( temp<=cwide )
                {    /* Slab Plane Clipping Modes */
                    switch( SlabMode )
                    {   case( SlabHollow ):
                                dz = pythag(wide,temp);
                                depth = z - dz;
                                if( depth>*(dptr+View.shift) )
                                {   *(dptr+View.shift) = depth;
                                    inten = LightDot(-dx,-dy,dz);

                                    if( inten>0 )
                                    {   inten=(int)( (inten*colconst(rad))
                                                     >>(ColBits+1));
                                        fold[dx+View.shift] =
                                          Lut[col+inten];
                                    } else fold[dx+View.shift] = Lut[col];
                                }
                                break;

                        case( SlabSection ):
                        case( SlabClose ):
                                dz = SlabValue-z;
                                depth = dx*dx+dy*dy+dz*dz+SlabValue+SliceValue;
                                if( (*(dptr+View.shift)
                                  < SlabValue+SliceValue) ||
                                  (depth<*(dptr+View.shift)) )
                                {   fold[dx+View.shift] = 
                                      Lut[col+SlabInten];
                                    *(dptr+View.shift) = depth;
                                }
                                break;
                    }
                    dptr++;  dx++;
                } else if( (z<SlabValue) && (SlabMode!=SlabSection) )
                {    dz = pythag(wide,temp);
                     UpdateAcross(dz);
                } else
                {   dptr++;  dx++;
                }
            }
        } else /* Slabless ScanLine */
            while( dx<=lastx )
            {   dz =pythag(wide,AbsFun(dx));
                UpdateAcross(dz);
            }

        dold += View.yskip;
        fold += View.yskip;
        dy++;
    }
    } else {
      /* We have the worst case, slab plane clipping in stereo */
      int clipt, ddz;
      dy = -rad;
      offset = (Long)(y+dy)*View.yskip+x;
      fold = View.fbuf + offset;
      dold = View.dbuf + offset;      
      while( dy<=lasty )
        {   wide = pythag(rad,AbsFun(dy));
            lastx = MinFun(wide,side);
            dx = - MinFun(wide,x);
            dptr = dold + dx;

            while( dx<=lastx )
            {   clipt = False;
                dz = pythag(wide,AbsFun(dx));
                depth = dz+z;
                ddz=View.slbuf[x+dx]-z;
                ddz=dx*dx+dy*dy+ddz*ddz+View.slbuf[x+dx]+SliceValue;
                if (UseSlabPlane && SlabMode == SlabClose && depth >= View.slbuf[x+dx]
                  && z <= View.slbuf[x+dx]) {
                  depth =  View.slbuf[x+dx]-1;
                  clipt = True;
                }
                if (UseDepthPlane && SlabMode == SlabClose && depth <= View.dlbuf[x+dx]
                  && z >= View.dlbuf[x+dx]) {
                  depth =  View.dlbuf[x+dx]+1;
                  clipt = True;
                }
                if ((clipt&&(ddz<*(dptr+View.shift)||
                  View.slbuf[x+dx]+SliceValue>*(dptr+View.shift)))||
                  (depth > *(dptr+View.shift))) {
                  if( ZBValid(x+dx,depth) ) {   
                    *(dptr+View.shift) = clipt?ddz:depth;
                    fptr = fold+dx;
                    if (clipt){
                      *(fptr+View.shift) = Lut[col+SlabInten];
                    } else {
                      inten = LightDot(dx,dy,dz);
                      if( inten>0 ) {  
                        inten = (int)((inten*colconst(rad))>>ColBits);
                        *(fptr+View.shift) = Lut[col+inten];
                      } else *(fptr+View.shift) = Lut[col];
                    }
                  } else {
                    depth = z-dz;
                    clipt = False;
                    if (UseSlabPlane && SlabMode == SlabClose && depth < View.slbuf[x+dx]
                      && z >= View.slbuf[x+dx]) {
                      depth =  View.slbuf[x+dx]-1;
                      clipt = True;
                    }
                    if (UseDepthPlane && SlabMode == SlabClose && depth > View.dlbuf[x+dx]
                      && z <= View.dlbuf[x+dx]) {
                      depth =  View.dlbuf[x+dx]+1;
                      clipt = True;
                    }
                    if ((ZBValid(x+dx,depth))
                      && ((clipt&&(ddz<*(dptr+View.shift)||
                      View.slbuf[x+dx]+SliceValue>*(dptr+View.shift)))||
                      (depth > *(dptr+View.shift))) ) {
                      *(dptr+View.shift) = clipt?ddz:depth;
                      fptr = fold+dx;
                      if (clipt){
                        *(fptr+View.shift) = Lut[col+SlabInten];
                      } else {
                        inten = LightDot(-dx,-dy,dz);
                        if( inten>0 ) {  
                          inten = (int)((inten*colconst(rad))>>ColBits);
                          *(fptr+View.shift) = Lut[col+inten];
                        } else *(fptr+View.shift) = Lut[col];
                      }
                    }
                  }
                }
                dptr++;  dx++;
            }
            dold += View.yskip;
            fold += View.yskip;
            dy++;
        }
        return;
    }
    	
}

void DrawStar( int x, int y, int z, int rad, int col )
{
    DrawTwinVector(x-rad*MatX[0],y-rad*MatY[0],z-rad*MatZ[0],
      x+rad*MatX[0],y+rad*MatY[0],z+rad*MatZ[0],col,col,' ');
    DrawTwinVector(x-rad*MatX[1],y-rad*MatY[1],z-rad*MatZ[1],
      x+rad*MatX[1],y+rad*MatY[1],z+rad*MatZ[1],col,col,' ');
    DrawTwinVector(x-rad*MatX[2],y-rad*MatY[2],z-rad*MatZ[2],
      x+rad*MatX[2],y+rad*MatY[2],z+rad*MatZ[2],col,col,' ');
}

void ClipStar( int x, int y, int z, int rad, int col )
{
    ClipTwinVector(x-rad*MatX[0],y-rad*MatY[0],z-rad*MatZ[0],
      x+rad*MatX[0],y+rad*MatY[0],z+rad*MatZ[0],col,col,' ');
    ClipTwinVector(x-rad*MatX[1],y-rad*MatY[1],z-rad*MatZ[1],
      x+rad*MatX[1],y+rad*MatY[1],z+rad*MatZ[1],col,col,' ');
    ClipTwinVector(x-rad*MatX[2],y-rad*MatY[2],z-rad*MatZ[2],
      x+rad*MatX[2],y+rad*MatY[2],z+rad*MatZ[2],col,col,' ');
}

static void DrawArcAc( short __huge *dbase,
                       Pixel __huge *fbase,
                       int z, int c )
{
    register ArcEntry __far *ptr;
    register short __huge *dptr;
    register short depth;

    for( ptr=ArcAc; ptr<ArcAcPtr; ptr++ )
    {   dptr = dbase+ptr->offset;  depth = ptr->dz+z;
        SETPIXEL(dptr,fbase+ptr->offset,depth,Lut[ptr->inten+c]);
    }
}

static void DrawArcDn( short __huge *dbase,
                       Pixel __huge *fbase,
                       int z, int c )
{
    register ArcEntry __far *ptr;
    register short __huge *dptr;
    register short depth;

    for( ptr=ArcDn; ptr<ArcDnPtr; ptr++ )
    {   dptr = dbase+ptr->offset;  depth = ptr->dz+z;
        SETPIXEL(dptr,fbase+ptr->offset,depth,Lut[ptr->inten+c]);
    }
}





#define xderiv 0
#define yderiv 1
#define xxderiv 2
#define xyderiv 3
#define yyderiv 4

#define xsub 0
#define ysub 1
#define zsub 2

#define sstep 15


#define YCIRCPIXEL                                             \
offset1 = (Long)((C[ysub]+dy)*View.yskip+(C[xsub]+dx));        \
offset2 = (Long)((C[ysub]-dy)*View.yskip+(C[xsub]-dx));        \
inten = LightDot(dx+C[xsub]-A[xsub],                           \
                 dy+C[ysub]-A[ysub],                           \
                 dz+C[zsub]-A[zsub]);                          \
if ( inten > 0 ) {                                             \
    inten = (int)((inten*colconst(rada))>>ColBits);            \
} else {                                                       \
    inten = 0;                                                 \
}                                                              \
if (inten > ColourMask) inten = ColourMask;                    \
if( OValid(offset1) && XValid(C[xsub]+dx) &&                   \
    YValid(C[ysub]+dy) &&                                      \
    ZBValid(C[xsub]+dx,C[zsub]+dz)  ){                         \
    SETPIXEL(View.dbuf+offset1,                                \
             View.fbuf+offset1,C[zsub]+dz,Lut[c+inten]);       \
}                                                              \
inten = LightDot(-dx+C[xsub]-A[xsub],                          \
                 -dy+C[ysub]-A[ysub],                          \
                 -dz+C[zsub]-A[zsub]);                         \
if ( inten > 0 ) {                                             \
    inten = (int)((inten*colconst(rada))>>ColBits);            \
} else {                                                       \
    inten = 0;                                                 \
}                                                              \
if (inten > ColourMask) inten = ColourMask;                    \
if( OValid(offset2) && XValid(C[xsub]-dx) &&                   \
    YValid(C[ysub]-dy) &&                                      \
    ZBValid(C[xsub]-dx,C[zsub]-dz) ){                          \
    SETPIXEL(View.dbuf+offset2,                                \
             View.fbuf+offset2,C[zsub]-dz,Lut[c+inten]);       \
}

#ifdef __MC68K__
#define SMALLER 1
#endif

#ifdef SMALLER
#define CIRCPIXEL CircPixel(dx,dy,dz);
void CircPixel( Long dx, Long dy, Long dz) {
    register int inten;
    register Long offset1, offset2;
    YCIRCPIXEL
}
#else
#define CIRCPIXEL YCIRCPIXEL
#endif


#define CIRCDOZ                                                \
if (AbsFun(F+SBD.U[SBD.s2]) < AbsFun(F) ) {                    \
  {CIRCPIXEL}; (*ds2)++; F+=SBD.U[SBD.s2];                     \
 } else {                                                      \
  if (AbsFun(F-SBD.U[SBD.s2]) < AbsFun(F) ) {                  \
    {CIRCPIXEL}; (*ds2)--; F-=SBD.U[SBD.s2];                   \
  }                                                            \
}


#define CIRCUP                                                 \
G += Gyup; Gxup += 2*(SBD.Us0Us1); Gxdown -= 2*(SBD.Us0Us1);   \
Gyup += 2*(SBD.Us1Us1_Us2Us2);                                 \
Gydown -= 2*(SBD.Us1Us1_Us2Us2);                               \
F += SBD.U[SBD.s1]; (*ds1)++;                                  \
CIRCDOZ


#define CIRCDOWN                                               \
G += Gydown; Gxup -= 2*(SBD.Us0Us1); Gxdown += 2*(SBD.Us0Us1); \
Gyup -= 2*(SBD.Us1Us1_Us2Us2);                                 \
Gydown += 2*(SBD.Us1Us1_Us2Us2);                               \
F -= SBD.U[SBD.s1]; (*ds1)--;                                  \
CIRCDOZ


#define CIRCRIGHT                                              \
G += Gxup; Gxup += 2*( SBD.Us0Us0_Us2Us2 );                    \
Gxdown -= 2*(SBD.Us0Us0_Us2Us2);                               \
Gyup += 2*((SBD.Us0Us1)); Gydown -= 2*((SBD.Us0Us1));          \
F += SBD.U[SBD.s0]; (*ds0)++;                                  \
CIRCDOZ




void DrawCircle( void ) {
	Long dx, dy, dz;
	register Long offset1, offset2;
	register Long F, G, FS, s2S, Gxup, Gxdown, Gyup, Gydown;
	register int inten;
	int spandex, s, w;
	int rdir, cdir;
	Long * ds[3];
	register Long *ds0, *ds1, *ds2;
	long Xmin, Ymin, Xmax, Ymax, Xpeak;
	int updown, ifirst;
	register int brush, brushdir;
		
	rdir = (radnext-radprev)==0?0:((radnext-radprev<0)?-1:1);
	cdir = (Cnext[SBD.s2]-Cprev[SBD.s2])==0?0:((Cnext[SBD.s2]-Cprev[SBD.s2]<0)?-1:1);
	
	
	ds[0] = &dx;
	ds[1] = &dy;
	ds[2] = &dz;
	
	C[0] = Cnext[0]; C[1] = Cnext[1]; C[2] = Cnext[2];
	spandex = 1+AbsFun(rdir)+AbsFun(Cnext[SBD.s2]-Cprev[SBD.s2]);
	w = 0;
	ifirst = 0;
	
	ds0 = ds[SBD.s0]; ds1 = ds[SBD.s1]; ds2 = ds[SBD.s2];
	
	do {
	  if (w == 0) {
	    brush = 2*AbsFun(radnext-radprev) + 2 + max(AbsFun(Cnext[SBD.s0]-Cprev[SBD.s0]), AbsFun(Cnext[SBD.s1]-Cprev[SBD.s1])); 
	    rad = radnext>radprev?radnext:radprev;
		w+=AbsFun (rdir);
		if (w == 0) {w++; spandex++;}
	  } else {
	    Long rat;
		
		if (cdir == 0) break;
		brush = 2;
		switch (ifirst) {
		  case 0:  C[SBD.s2] -= cdir;
				if (Cnext[SBD.s0]-Cprev[SBD.s0] == 0) ifirst++;
				break;
		  case 1:  rat = (4096*(Cnext[SBD.s2]-C[SBD.s2]))/(Cnext[SBD.s2]-Cprev[SBD.s2]);
		        C[SBD.s0] = (rat*Cprev[SBD.s0]+(4096-rat)*Cnext[SBD.s0])/4096;
				if (Cnext[SBD.s1]-Cprev[SBD.s1] == 0) ifirst++;
				break;
		  case 2:  rat = (4096*(Cnext[SBD.s2]-C[SBD.s2]))/(Cnext[SBD.s2]-Cprev[SBD.s2]);
		        C[SBD.s1] = (rat*Cprev[SBD.s1]+(4096-rat)*Cnext[SBD.s1])/4096;
		        break;
		}
		
		ifirst++; if (ifirst==3) {w++; ifirst=0;}
	  }
	  if (brush > rad) brush = rad;
	
	
	/* now |U[SBD.s0]| <= |U[SBD.s1]| <= |U[SBD.s2]|, draw an s0-s1 curve */
		
		rada = (int)(.5+sqrt(
							  (double)(rad*rad+(C[0]-A[0])*(C[0]-A[0])
									   +(C[1]-A[1])*(C[1]-A[1])
									   +(C[2]-A[2])*(C[2]-A[2]))));
		Xmin = - (Xmax =
				  (Long)(rint((double)(rad))*(sqrt((double)(SBD.Us1Us1_Us2Us2)))/
						 sqrt((double)(SBD.Us0Us0_Us1Us1_Us2Us2))));
		
		if ( Xmax > rad) {
			Xmin = -(Xmax=rad);
		}
		Ymax = -(Long)(rint((double)(rad*(SBD.Us0Us1)))/
					   ( sqrt((double)(SBD.Us1Us1_Us2Us2))*
						 sqrt((double)(SBD.Us0Us0_Us1Us1_Us2Us2)) ));
		Ymin = -Ymax;
		if ( Ymax > rad ) {
			Ymin = -(Ymax=rad);
		}
		Xpeak = -(Long)(rint((double)(rad*(SBD.Us0Us1)))/
					   ( sqrt((double)(SBD.Us0Us0_Us2Us2))*
						 sqrt((double)(SBD.Us0Us0_Us1Us1_Us2Us2)) ));
		*ds0 = Xmin;
		*ds1 = Ymin;
		
		
		G = Xmin*Xmin*(SBD.Us0Us0_Us2Us2)+Ymin*Ymin*(SBD.Us1Us1_Us2Us2)  +
			2*Xmin*Ymin*(SBD.Us0Us1) - rad*rad*SBD.U[SBD.s2]*SBD.U[SBD.s2];
		Gxup = (2*Xmin+1)*(SBD.Us0Us0_Us2Us2) + 2*Ymin*(SBD.Us0Us1);
		Gyup = (2*Ymin+1)*(SBD.Us1Us1_Us2Us2) + 2*Xmin*(SBD.Us0Us1);
		Gxdown = (-2*Xmin+1)*(SBD.Us0Us0_Us2Us2) - 2*Ymin*(SBD.Us0Us1);
		Gydown = (-2*Ymin+1)*(SBD.Us1Us1_Us2Us2) - 2*Xmin*(SBD.Us0Us1);
		*ds2= (int)(rint(-(double)((*ds0)*SBD.U[SBD.s0]+(*ds1)*SBD.U[SBD.s1]))/((double)SBD.U[SBD.s2]));
		F = dx*SBD.U[0] + dy*SBD.U[1] + dz*SBD.U[2];
		FS = F;
		s2S = *ds2;
		brushdir = 0;
		for (s=0; s< brush; s++) {
		    CIRCPIXEL
			(*ds0)++;
			F += SBD.U[SBD.s0];
            CIRCDOZ
		}
		(*ds0)-=brush;
		updown = 1;
		F = FS;
		*ds2 = s2S;
		
		/*
		                      Gxup small
		                      Gyup > 0
						     ----------
						   /\  | | | | /\
						  /\1     2    3/\
			Gxup < 0     | ----       ----|  Gxup > 0
		   Gyup small	 | -0-        --4-|  Gydown small
		 
		 
		 */
		
		
		while ((*ds0 < Xmax )|| (*ds0 == Xmax && *ds1 > Ymax)) {  /* Start by going up and right */
			if ( (3*(*ds0) < 2*Xmin + Xpeak) ) { 
				brushdir = 0;
			} else {
			    if ( (3*(*ds0) < Xmin +2*Xpeak) ) {
				brushdir = 1;
				} else {
				  if ( (3*(*ds0) < 2*Xpeak+ Xmax)  ) { 
				  brushdir = 2;
				  } else {
				    if ( (3*(*ds0) < Xpeak + 2*Xmax) ) {
				      brushdir = 3;
					} else {
				      brushdir = 4;
					}
				  }
				} 
		    }
			if (*ds0 < Xpeak) {
			  if ( (AbsFun(G+Gyup) < AbsFun(G+Gxup)) ||
				             (AbsFun(G+Gyup+Gxup+2*(SBD.Us0Us1)) < AbsFun(G+Gxup))) {
				      {CIRCUP}
				      if (AbsFun(G+Gxup) < AbsFun(G) ) {CIRCRIGHT}
				} else {
				{CIRCRIGHT}
				}
			} else {
				if (((AbsFun(G+Gydown) < AbsFun(G+Gxup))  ||
					 (AbsFun(G+Gydown+Gxup-2*(SBD.Us0Us1)) < AbsFun(G+Gxup))     ) || 
					(*ds0 == Xmax && *ds1 > Ymax)){
				{CIRCDOWN}
					if ((AbsFun(G+Gxup) < AbsFun(G)) && *ds0 < Xmax) {CIRCRIGHT}
				} else {
				{CIRCRIGHT}
				}
			}
			FS = F;
			s2S = *ds2;
            switch(brushdir) {
				/* Starting on the left side of the ellipse */
				case 0: 
					for (s = 0; s < brush; s++) {
					  {CIRCPIXEL}
					  (*ds0)++; F += SBD.U[SBD.s0]; /* go right */
					  {CIRCDOZ}
					}
					(*ds0)-=brush;
					break;
					/* Continue on the upslope of the left side of the ellipse */
				case 1:  
					for (s = 0; s < brush; s++) {
					  {CIRCPIXEL}
					  (*ds0)++; F+= SBD.U[SBD.s0];
					  {CIRCDOZ}
					  if ( s > 0 ){CIRCPIXEL}; 
					  (*ds1)--; F=-SBD.U[SBD.s1]; /* go down right */
					  {CIRCDOZ}
					}
					(*ds0)-=brush; (*ds1)+=brush;
					break;
					/* Continue on the top of the ellipse */
				case 2:  
					for (s = 0; s < brush; s++) {
					  {CIRCPIXEL}
					  (*ds1)--; F-= SBD.U[SBD.s1]; /* go down */
					  {CIRCDOZ}
					}
					(*ds1)+=brush;
					break;
					/* Continue on the down slope of the right of the ellipse */
				case 3:   
					for (s = 0; s < brush; s++) {
					  {CIRCPIXEL}
					  (*ds0)--; F-=SBD.U[SBD.s0];
					  {CIRCDOZ}
					  if ( s > 0 ) {CIRCPIXEL};
					  (*ds1)--; F-=SBD.U[SBD.s1]; /* go down left */
					  {CIRCDOZ}
					}
					(*ds0)+=brush; (*ds1)+=brush;
					break;
					/* Finish on the right side of the ellipse */
				case 4:  
					for (s = 0; s < brush; s++) {
					  {CIRCPIXEL}
					  (*ds0)--; F -= SBD.U[SBD.s0]; /* go right */
					  {CIRCDOZ}
					}
					(*ds0)+=brush;
					break;
			}
			F = FS;
			*ds2 = s2S;
			
		}
        continue;
		} while (w < spandex);
}


void DrawTorus( int x1, int y1, int z1,
                              int x2, int y2, int z2,
                              int c1, int c2,
                              int xrad1, int xrad2, int radp, char altl )
{

    double ccen;
    int oClipStatus;
    
    register int altc;
    Long s, smax, t, u;
    int rad;


    altc=0;
    if (altl != '\0' && altl != ' ')
      altc = AltlColours[((int)altl)&(AltlDepth-1)];


    c = c1;

    rad = -1;
	smax = SBD.t1;
    
    if (SBD.sxyz < 1) return;
    
    for (u = SBD.t1; u <= SBD.sxyz-SBD.t2+2*sstep; u+=sstep ) {
	  if ( u < SBD.u1+sstep ) {
	    smax = s = u;
	  } else {
	    s = SBD.sxyz - SBD.t2 + smax+sstep-u;
        if (s >= SBD.sxyz-SBD.t2 ) {
            rad = -1;
            c = c2;
        }
	  }

      if (rad != -1 ) {
          Cprev[xsub] = Cnext[xsub]; Cprev[ysub] = Cnext[ysub]; Cprev[zsub] = Cnext[zsub];
      }
      Cnext[xsub] = ((SBD.sxyz-s)*((Long)SBD.x1)+s*((Long)SBD.x2))/((Long)SBD.sxyz);
      Cnext[ysub] = ((SBD.sxyz-s)*((Long)SBD.y1)+s*((Long)SBD.y2))/((Long)SBD.sxyz);
      Cnext[zsub] = ((SBD.sxyz-s)*((Long)SBD.z1)+s*((Long)SBD.z2))/((Long)SBD.sxyz);
      radnext = (int)(SBD.wp>>4) - pythag(radp,AbsFun((int)((s-SBD.u1)>>4)));
      if (radnext <0 ) {
          rad = -1;
          continue;
      }
      if (rad == -1 ) {
          Cprev[xsub] = Cnext[xsub]; Cprev[ysub] = Cnext[ysub]; Cprev[zsub] = Cnext[zsub];
      } else {
          if (Cprev[xsub] == Cnext[xsub] && Cprev[ysub] == Cnext[ysub] && Cprev[zsub] == Cnext[zsub]) continue;
      }
      radnext = AbsFun(radnext);
      if (rad == -1) rad = radnext;
      radprev = rad;
      rad = radnext;
      
      if (u <= SBD.u1) {
        ccen = ((double)(SBD.u1-s))/16.;
        t = SBD.u1 - (Long)rint(((double)(SBD.wp))*ccen/sqrt((double)(radp*radp)-ccen*ccen));
      } else {
        ccen = ((double)(SBD.u2-(SBD.sxyz-s)))/16.;
        t = SBD.u2 - (Long)rint(((double)(SBD.wp))*ccen/sqrt((double)(radp*radp)-ccen*ccen));
        t = SBD.sxyz - t;
      }
      A[xsub] = ((SBD.sxyz-t)*((Long)SBD.x1)+t*((Long)SBD.x2))/((Long)SBD.sxyz);
      A[ysub] = ((SBD.sxyz-t)*((Long)SBD.y1)+t*((Long)SBD.y2))/((Long)SBD.sxyz);
      A[zsub] = ((SBD.sxyz-t)*((Long)SBD.z1)+t*((Long)SBD.z2))/((Long)SBD.sxyz);

      if (ClipStatus) {
          oClipStatus = ClipStatus;
          rada = (int)(.99+sqrt(
                (double)(rad*rad+
                (Cnext[0]-A[0])*(Cnext[0]-A[0])+
                (Cnext[1]-A[1])*(Cnext[1]-A[1])+
                (Cnext[2]-A[2])*(Cnext[2]-A[2]))));
          if (TestSphere(A[0],A[1],A[2],rada)) {
              if ( (ClipStatus&BitFront) && SlabMode == SlabClose) {
                  ClipSphere(A[0],A[1],A[2],rada,c);
                  rad = -1;
              } else {
                  DrawCircle();
              }
          }
          ClipStatus = oClipStatus;
      } else {
      DrawCircle();
      }

      if ( altc && s-SBD.u1 < (SBD.sxyz-SBD.t2-SBD.t1)/2 
                && SBD.u1-s < (SBD.sxyz-SBD.t2-SBD.t1)/2 ) {
       c = altc;
      } else {
         if (s >= SBD.u1) c = c2;
      }
    }

}



static int TestSurfaceBond( int x1, int y1, int z1,
                              int x2, int y2, int z2,
                              int xrad1, int xrad2, int radp )
{
    int x1p, x2p;
    ClipStatus = False;
    
    x1p = x1;
    if (x1 < 0) x1p = 0;
    if (x1 >= View.xmax) x1p = View.xmax-1;

    x2p = x2;
    if (x1 < 0) x2p = 0;
    if (x1 >= View.xmax) x2p = View.xmax-1;


    if ( x1+xrad1 < 0 && x2+xrad2 < 0 ) return False;
    if ( x1-xrad1 >= View.xmax && x2-xrad2 >= View.xmax ) return False;

    if ( y1+xrad1 < 0 && y2+xrad2 < 0 ) return False;
    if ( y1-xrad1 >= View.ymax && y2-xrad2 >= View.ymax ) return False;

    if ( UseSlabPlane ) {
        if ( z1-xrad1 >= View.slbuf[x1p]  && z2-xrad1 >= View.slbuf[x2p] ) return False;
    }

    if ( UseDepthPlane ) {
        if ( z1+xrad1 <= View.dlbuf[x1p] && z2+xrad2 <= View.dlbuf[x2p] ) return False;
    }

    if ( x1-xrad1 < 0 || x2-xrad2 < 0 ||
         x1+xrad1 >= View.xmax || x2+xrad2 >= View.xmax ||
         y1-xrad1 < 0 || y2-xrad2 < 0 ||
         y1+xrad1 >= View.ymax || y2+xrad2 >= View.ymax ) ClipStatus = True;
    if ( UseSlabPlane ) {
        if ( z1+xrad1 > View.slbuf[x1p] || z2+xrad2 > View.slbuf[x2p]) ClipStatus = True;
    }
    if ( UseDepthPlane ) {
        if ( z1-xrad1 < View.dlbuf[x1p] || z2-xrad2 < View.dlbuf[x2p]) ClipStatus = True;
    }
    return True;
}

void ClipSurfaceBond( int x1, int y1, int z1,
                              int x2, int y2, int z2,
                              int c1, int c2,
                              int xrad1, int xrad2, int radp, char altl )
{
    if (!TestSurfaceBond(x1,y1,z1,x2,y2,z2,xrad1,xrad2,radp) ) return;
    DrawTorus( x1,y1,z1, x2,y2,z2,  c1,c2, xrad1,xrad2,radp, altl );

}


static void DrawCylinderCaps( int x1, int y1, int z1,
                              int x2, int y2, int z2,
                              int c1, int c2, int rad, char altl )
{
    register short __huge *dold, __huge *dptr;
    register Pixel __huge *fold;
#ifdef UNUSED
    register int ax,ay,ix,iy;
    register int zrate,lz;
#endif
    register Long offset,temp,end;
    register int inten,absx;
    register int wide,depth;
    register int dx,dy,dz;
    register int lx,ly;
    register int p, alts, altc;

    altc=0;
    if (altl != '\0' && altl != ' ')
      altc = AltlColours[((int)altl)&(AltlDepth-1)];

    lx = x2-x1;
    ly = y2-y1;

#ifdef UNUSED
    lz = z2-z1;
    if( ly>0 ) { ay = ly; iy = 1; }
    else { ay = -ly; iy = -1; }
    if( lx>0 ) { ax = lx; ix = 1; }
    else { ax = -lx; ix = -1; }
    zrate = lz/MaxFun(ax,ay);
#endif

    end = (Long)ly*View.yskip+lx;
    temp = (Long)y1*View.yskip+x1;
    fold = View.fbuf+temp;
    dold = View.dbuf+temp;

    if ( rad < 0 ) rad = 0;
    if ( rad >= MAXRAD ) rad = MAXRAD-1; 

    ArcAcPtr = ArcAc;
    ArcDnPtr = ArcDn;

    temp = (Long)-(rad*View.yskip);
    for( dy= -rad; dy<=rad; dy++ )
    {   wide =pythag(rad,AbsFun(dy));
        alts = 0;

        for( dx= -wide; dx<=wide; dx++ )
        {   absx = AbsFun(dx);
            dz = pythag(wide,absx);
            inten = LightDot(dx,dy,dz);
            if( inten>0 )
            {   inten = (int)((inten*colconst(rad))>>ColBits);
            } else inten = 0;
            offset = temp+dx;

            if( XValid(x1+dx) && YValid(y1+dy) )
            {   dptr = dold+offset; depth = z1+dz;
                p = altc&&
                  (5*dx*dx*rad*rad + 5*dy*dy*wide*wide < rad*rad*wide*wide );
                SETPIXELP(dptr,fold+offset,depth,Lut[c1+inten], \
                   Lut[altc+inten],p);
            }

            if( XValid(x2+dx) && YValid(y2+dy) )
            {   dptr = dold+(offset+end); depth = z2+dz;
                p = altc&&
                  (5*dx*dx*rad*rad + 5*dy*dy*wide*wide < rad*rad*wide*wide );
                SETPIXELP(dptr,fold+(offset+end),depth,Lut[c2+inten], \
                  Lut[altc+inten],p);
            }

#ifdef UNUSED
            k1 = AbsFun(dx+ix); 
            k2 = AbsFun(dx-ix);

            if( ((k1>wide)||(dz>=pythag(wide,k1)-zrate)) &&
                ((k2>wide)||(dz>pythag(wide,k2)+zrate)) )
#endif
            if ( (ArcAcPtr-ArcAc)<ARCSIZE ) {
            {   ArcAcPtr->offset = offset; ArcAcPtr->inten = inten;
                ArcAcPtr->dx=dx; ArcAcPtr->dy=dy; ArcAcPtr->dz=dz;
                ArcAcPtr++;
            } }

#ifdef UNUSED
            k1 = AbsFun(dy+iy);
            k2 = AbsFun(dy-iy);

            high = pythag(rad,absx);
            if( ((k1>high)||(dz>=pythag(pythag(rad,k1),absx)-zrate)) &&
                ((k2>high)||(dz>pythag(pythag(rad,k2),absx)+zrate)) )
#endif
            if ( (ArcDnPtr-ArcDn)<ARCSIZE ) {
            {   ArcDnPtr->offset = offset; ArcDnPtr->inten = inten;
                ArcDnPtr->dx=dx; ArcDnPtr->dy=dy; ArcDnPtr->dz=dz;
                ArcDnPtr++;
            } }
        }
        temp += View.yskip;
    }
}


static void DrawCappedCyl( int x1, int y1, int z1,
                   int x2, int y2, int z2,
                   int c1, int c2, int rad )
{
    register short __huge *dbase;
    register Pixel __huge *fbase;

    register int zrate,zerr,ystep,err;
    register int ix,iy,ax,ay;
    register int lx,ly,lz;
    register int mid,tmp;
    register Long temp;

    /* Trivial Case */
    if( (x1==x2) && (y1==y2) )
    {   if( z1>z2 )
        {      DrawSphere(x1,y1,z1,rad,c1);
        } else DrawSphere(x2,y2,z2,rad,c2);
        return;
    }

    if( z1<z2 )
    {   tmp=x1; x1=x2; x2=tmp;
        tmp=y1; y1=y2; y2=tmp;
        tmp=z1; z1=z2; z2=tmp;
        tmp=c1; c1=c2; c2=tmp;
    }

    DrawCylinderCaps(x1,y1,z1,x2,y2,z2,c1,c2,rad,' ');

    lx = x2-x1;
    ly = y2-y1;
    lz = z2-z1;

    if( ly>0 ) { ystep = View.yskip; ay = ly; iy = 1; }
    else {   ystep = -View.yskip; ay = -ly; iy = -1; }
    if( lx>0 ) { ax = lx; ix = 1; }
    else { ax = -lx; ix = -1; }
    zrate = lz/MaxFun(ax,ay);

    temp = (Long)y1*View.yskip+x1;
    fbase = View.fbuf+temp;
    dbase = View.dbuf+temp;
    if( ax>ay )
    {   lz -= ax*zrate;
        zerr = err = -(ax>>1);
        mid = (x1+x2)/2;

        while( x1!=mid )
        {   z1 += zrate;  if( (zerr-=lz)>0 ) { zerr-=ax; z1--; }
            fbase+=ix; dbase+=ix; x1+=ix;
            if( (err+=ay)>0)
            {   fbase+=ystep; dbase+=ystep; err-=ax;
                   DrawArcDn(dbase,fbase,z1,c1);
            } else DrawArcAc(dbase,fbase,z1,c1);
        }
        

        while( x1!=x2 )
        {   z1 += zrate;  if( (zerr-=lz)>0 ) { zerr-=ax; z1--; }
            fbase+=ix; dbase+=ix; x1+=ix;
            if( (err+=ay)>0)
            {   fbase+=ystep; dbase+=ystep; err-=ax;
                   DrawArcDn(dbase,fbase,z1,c2);
            } else DrawArcAc(dbase,fbase,z1,c2);
        }
    } else /*ay>=ax*/
    {   lz -= ay*zrate;
        zerr = err = -(ay>>1);
        mid = (y1+y2)/2;
        while( y1!=mid )
        {   z1 += zrate;  if( (zerr-=lz)>0 ) { zerr-=ay; z1--; }
            fbase+=ystep; dbase+=ystep; y1+=iy;
            if( (err+=ax)>0 )
            {   fbase+=ix; dbase+=ix; err-=ay; 
                   DrawArcAc(dbase,fbase,z1,c1);
            } else DrawArcDn(dbase,fbase,z1,c1);
	}
   
        while( y1!=y2 )
        {   z1 += zrate;  if( (zerr-=lz)>0 ) { zerr-=ay; z1--; }
            fbase+=ystep; dbase+=ystep; y1+=iy;
            if( (err+=ax)>0 )
            {   fbase+=ix; dbase+=ix; err-=ay; 
                   DrawArcAc(dbase,fbase,z1,c2);
            } else DrawArcDn(dbase,fbase,z1,c2);
        }
    }

}

void DrawCylinder( int x1, int y1, int z1,
                   int x2, int y2, int z2,
                   int c1, int c2, int rad,
                   char altl, int arad )

{   int altc;
    int x1a, y1a, z1a, x2a, y2a, z2a, rada;
    double flen, xd, yd, zd;

    altc = 0;
    if ( altl != '\0' && altl != ' ')
      altc = AltlColours[((int)altl)&(AltlDepth-1)];

    if (!altc) {
      DrawCappedCyl(x1, y1, z1, x2, y2, z2, c1, c2, rad);
    } else {


      xd = x1-x2;
      yd = y1-y2;
      zd = z1-z2;

      flen = .001+sqrt(xd*xd+yd*yd+zd*zd);

      rada = arad;
      if ( rada > rad ) {
        rada = rad;
      }

      x1a = (int)((double)x1+(rad-rada+2.)*xd/flen);
      y1a = (int)((double)y1+(rad-rada+2.)*yd/flen);
      z1a = (int)((double)z1+(rad-rada+2.)*zd/flen);

      x2a = (int)((double)x2-(rad-rada+2.)*xd/flen);
      y2a = (int)((double)y2-(rad-rada+2.)*yd/flen);
      z2a = (int)((double)z2-(rad-rada+2.)*zd/flen);


      DrawCappedCyl(x1a, y1a, z1a, x2a, y2a, z2a, altc, altc, rada);

      if (9*((int)flen) >  20*rad) {
        x1a = x1-(int)((.45-((double)rad)/flen)*xd);
        y1a = y1-(int)((.45-((double)rad)/flen)*yd);
        z1a = z1-(int)((.45-((double)rad)/flen)*zd);

        x2a = x2+(int)((.45-((double)rad)/flen)*xd);
        y2a = y2+(int)((.45-((double)rad)/flen)*yd);
        z2a = z2+(int)((.45-((double)rad)/flen)*zd);

        DrawCappedCyl(x1, y1, z1, x1a, y1a, z1a, c1, c1, rad);
        DrawCappedCyl(x2a, y2a, z2a, x2, y2, z2, c2, c2, rad);
        
      } else {

        DrawSphere(x1,y1,z1,rad,c1);
        DrawSphere(x2,y2,z2,rad,c2);

      }

      

    }

}


static int TestCylinder( int x1, int y1, int z1,
                         int x2, int y2, int z2,
                         int rad )
{
    register int tmp1, tmp2;

    int x1p, x2p;
    double theta, zrat;
    
    zrat = 1.;
    if (UseStereo) {
    	theta = -PI*StereoAngle/360.;
        zrat = 1./cos(theta);
    }
    x1p = x1;
    if (x1 < 0) x1p = 0;
    if (x1 >= View.xmax) x1p = View.xmax-1;

    x2p = x2;
    if (x1 < 0) x2p = 0;
    if (x1 >= View.xmax) x2p = View.xmax-1;

    if( UseSlabPlane )
        if( (z1+(int)rint(zrat*(double)rad)>=View.slbuf[x1p]) || (z2+(int)rint(zrat*(double)rad)>+View.slbuf[x2p]) )
            return(False);

    ClipStatus = False;

    tmp1 = x1+rad;  tmp2 = x2+rad;
    if( (tmp1<0) && (tmp2<0) )
        return( False );
    if( (tmp1>=View.xmax) || (tmp2>=View.xmax) )
        ClipStatus = True;

    tmp1 = x1-rad;  tmp2 = x2-rad;
    if( (tmp1>=View.xmax) && (tmp2>=View.xmax) )
        return( False );
    if( (tmp1<0) || (tmp2<0) )
        ClipStatus = True;

    tmp1 = y1+rad;  tmp2 = y2+rad;
    if( (tmp1<0) && (tmp2<0) )
        return( False );
    if( (tmp1>=View.ymax) || (tmp2>=View.ymax) )
        ClipStatus = True;

    tmp1 = y1-rad;  tmp2 = y2-rad;
    if( (tmp1>=View.ymax) && (tmp2>=View.ymax) )
        return( False );
    if( (tmp1<0) || (tmp2<0) )
        ClipStatus = True;

    return True;
}


static void ClipArcAc( short __huge *dbase, 
                       Pixel __huge *fbase,
                       int x, int y, int z, int c )
{
    register ArcEntry __far *ptr;
    register short __huge *dptr;
    register short depth;
    register int temp;

    ptr = ArcAc;
    while( (temp=y+ptr->dy) < 0 )
        if(++ptr == ArcAcPtr )
            return;

    while( (temp<View.ymax) && (ptr<ArcAcPtr) )
    {   temp = x+ptr->dx;
        if( XValid(temp) && OValid(ptr->offset) )
        {   dptr = dbase+ptr->offset;  depth = ptr->dz+z;
            SETPIXEL(dptr,fbase+ptr->offset,depth,Lut[ptr->inten+c]);
        }
        ptr++;
        temp = y+ptr->dy;
    }
}

static void ClipArcDn( short __huge *dbase,
                       Pixel __huge *fbase,
                       int x, int y, int z, int c )
{
    register ArcEntry __far *ptr;
    register short __huge *dptr;
    register short depth;
    register int temp;

    ptr = ArcDn;
    if (ptr == ArcDnPtr) return;
    while( (temp=y+ptr->dy) < 0 )
        if(++ptr == ArcDnPtr )
            return;

    while( (temp<View.ymax) && (ptr!=ArcDnPtr) )
    {   temp = x+ptr->dx;
        if( XValid(temp) && OValid(ptr->offset) )
        {   dptr = dbase+ptr->offset;  depth = ptr->dz+z;
            SETPIXEL(dptr,fbase+ptr->offset,depth,Lut[ptr->inten+c]);
        }
        ptr++;
        temp = y+ptr->dy;
    }
}


static void ClipCappedCyl( int x1, int y1, int z1,
                   int x2, int y2, int z2,
                   int c1, int c2, int rad )
{
    register short __huge *dbase;
    register Pixel __huge *fbase;

    register int zrate,zerr,ystep,err;
    register int ix,iy,ax,ay;
    register int lx,ly,lz;
    register int mid,tmp;
    register Long temp;

    /* Visibility Tests */
    if( !TestCylinder(x1,y1,z1,x2,y2,z2,rad) )
        return;

    if( !ClipStatus )
    {   DrawCappedCyl(x1,y1,z1,x2,y2,z2,c1,c2,rad);
        return;
    }

    /* Trivial Case */
    if( (x1==x2) && (y1==y2) )
    {   if( z1>z2 )
        {      ClipSphere(x1,y1,z1,rad,c1);
        } else {
          ClipSphere(x2,y2,z2,rad,c2);
        }
        return;
    }

    if( z1<z2 )
    {   tmp=x1; x1=x2; x2=tmp;
        tmp=y1; y1=y2; y2=tmp;
        tmp=z1; z1=z2; z2=tmp;
        tmp=c1; c1=c2; c2=tmp;
    }

    DrawCylinderCaps(x1,y1,z1,x2,y2,z2,c1,c2,rad,' ');

    lx = x2-x1;
    ly = y2-y1;
    lz = z2-z1;

    if( ly>0 ) { ystep = View.yskip; ay = ly; iy = 1; }
    else {   ystep = -View.yskip; ay = -ly; iy = -1; }
    if( lx>0 ) { ax = lx; ix = 1; }
    else { ax = -lx; ix = -1; }
    zrate = lz/MaxFun(ax,ay);

    temp = (Long)y1*View.yskip+x1;
    fbase = View.fbuf+temp;
    dbase = View.dbuf+temp;

    if( ax>ay )
    {   if( x2<x1 )
        {   tmp = c1;
            c1 = c2;
            c2 = tmp;
        }
        lz -= ax*zrate;
        zerr = err = -(ax>>1);
        mid = (x1+x2)/2;

        while( x1!=x2 )
        {   z1 += zrate;  if( (zerr-=lz)>0 ) { zerr-=ax; z1--; }
            fbase+=ix; dbase+=ix; x1+=ix;
            if( (err+=ay)>0 )
            {   fbase += ystep;  err -= ax;
                dbase += ystep;  y1 += iy;
                   ClipArcDn(dbase,fbase,x1,y1,z1,(x1<mid?c1:c2));
            } else {
              ClipArcAc(dbase,fbase,x1,y1,z1,(x1<mid?c1:c2));
            }
        }
    } else /*ay>=ax*/
    {   if( y2<y1 )
        {   tmp = c1;
            c1 = c2;
            c2 = tmp;
        }
        lz -= ay*zrate;
        zerr = err = -(ay>>1);
        mid = (y1+y2)/2;
        while( y1!=y2 )
        {   z1 += zrate;  if( (zerr-=lz)>0 ) { zerr-=ay; z1--; }
            fbase+=ystep; dbase+=ystep; y1+=iy;
            if( (err+=ax)>0 )
            {   fbase += ix;  err -= ay;
                dbase += ix;  x1 += ix; 
                   ClipArcAc(dbase,fbase,x1,y1,z1,(y1<mid?c1:c2));
            } else ClipArcDn(dbase,fbase,x1,y1,z1,(y1<mid?c1:c2));
        }
    }
}


void ClipCylinder( int x1, int y1, int z1,
                   int x2, int y2, int z2,
                   int c1, int c2, int rad,
                   char altl, int arad)
{   int  altc;
    int x1a, y1a, z1a, x2a, y2a, z2a, rada;
    double flen, xd, yd, zd;

    altc = 0;
    if ( altl != '\0' && altl != ' ')
      altc = AltlColours[((int)altl)&(AltlDepth-1)];

    if (!altc) {
      ClipCappedCyl(x1, y1, z1, x2, y2, z2, c1, c2, rad);
    } else {

      xd = x1-x2;
      yd = y1-y2;
      zd = z1-z2;

      flen = .001+sqrt(xd*xd+yd*yd+zd*zd);

      rada = arad;
      if ( rada > rad ) {
        rada = rad;
      }

      x1a = (int)((double)x1+(rad-rada+2.)*xd/flen);
      y1a = (int)((double)y1+(rad-rada+2.)*yd/flen);
      z1a = (int)((double)z1+(rad-rada+2.)*zd/flen);
  
      x2a = (int)((double)x2-(rad-rada+2.)*xd/flen);
      y2a = (int)((double)y2-(rad-rada+2.)*yd/flen);
      z2a = (int)((double)z2-(rad-rada+2.)*zd/flen);

      ClipCappedCyl(x1a, y1a, z1a, x2a, y2a, z2a, altc, altc, rada);

      if (9*((int)flen) >  20*rad) {
        x1a = x1-(int)((.45-((double)rad)/flen)*xd);
        y1a = y1-(int)((.45-((double)rad)/flen)*yd);
        z1a = z1-(int)((.45-((double)rad)/flen)*zd);

        x2a = x2+(int)((.45-((double)rad)/flen)*xd);
        y2a = y2+(int)((.45-((double)rad)/flen)*yd);
        z2a = z2+(int)((.45-((double)rad)/flen)*zd);

        ClipCappedCyl(x1, y1, z1, x1a, y1a, z1a, c1, c1, rad);
        ClipCappedCyl(x2a, y2a, z2a, x2, y2, z2, c2, c2, rad);

      } else {

        ClipSphere(x1,y1,z1,rad,c1);
        ClipSphere(x2,y2,z2,rad,c2);

      }
    }

}


/*================================*/
/*  Character Rendering Routines  */
/*================================*/

void SetFontSize( int size )
{
    register int count;
    register char *ptr;
    register int i;

    if( LabelList || (MonitList && DrawMonitDistance) )
      ReDrawFlag |= RFRefresh;

    FontSize = abs(size);
    FontPS = False;
    if ( size < 0 ) FontPS = True;
    count = 0;
    for( i=0; i<23; i++ )
    {   FontDimen[i] = count>>4;
        count += FontSize;
    }

    for ( i=0; i<97; i++ )
    { if ( FontPS )
      { ptr = VectFont[i];
        FontWid[i] = 0;
        while( *ptr )
        { if( ptr[0] < 'a' )
  	  { if( FontDimen[ptr[0]-'A'] > FontWid[i] ) 
              FontWid[i] = FontDimen[ptr[0]-'A'];
	  } else {
            if( FontDimen[ptr[0]-'a'] > FontWid[i] ) 
              FontWid[i] = FontDimen[ptr[0]-'a'];
          }
          ptr += 2;
        }
        FontWid[i] += FontSize/4 + 1;
      } else {
        FontWid[i] = FontSize;
      }
    } 
}

void SetFontStroke( int width )
{
    FontStroke = width;
}

static void ClipCharacter( int x, int y,int z, int glyph, int col )
{
    register char *ptr;
    register int sx,sy;
    register int ex=0,ey=0;

    ptr = VectFont[glyph];
    while( *ptr )
    {   /* Uppercase test */
        if( ptr[0] < 'a' )
        {   sx = x + FontDimen[ptr[0]-'A'];
            sy = y + InvertY(FontDimen[ptr[1]-'a']);
            ptr += 2;
        } else
        {   sx = ex;
            sy = ey;
        }

        ex = x + FontDimen[ptr[0]-'a'];
        ey = y + InvertY(FontDimen[ptr[1]-'a']);
        if (FontStroke < 1 ) {
          if( (ex!=sx) || (ey!=sy) )
          {   ClipLine(sx,sy,z,ex,ey,z,col,' ');
          } else ClipPoint(ex,ey,z,col);
        } else {
          if( (ex!=sx) || (ey!=sy) )
          {   ClipCylinder(sx,sy,z,ex,ey,z,col,col,FontStroke,' ',FontStroke);
          } /* else ClipSphere(ex,ey,z,FontStroke,col); */
        }
        ptr += 2;
    }
}


void DisplayRasString( int x, int y, int z, unsigned char *label,  int col )
{
    register int clip,high,max;
    register char *ptr;
    register int sx,sy;
    register int ex=0,ey=0;

    high = (FontSize*3)>>1;
#ifdef INVERT
    if( ((y+high)<0) || (y>=View.ymax) ) return;
    clip = (y<0) || (y+high>=View.ymax);
#else
    if( (y<0) || ((y-high)>=View.ymax) ) return;
    clip = (y-high<0) || (y>=View.ymax);
#endif

    if( x < 0 )
    {   while( *label && (x<=-FontSize) )
        {   x +=  FontWid[(*label-32)]+FontStroke;
            label++;
        }

        if( *label )
        {   ClipCharacter(x,y,z,(*label-32),col);
            x += FontWid[(*label-32)]+FontStroke;
            label++;
        } else return;
    }

    if( !clip )
    {   max = View.xmax-FontSize;
        while( *label && (x<max) )
        {  ptr = VectFont[*label-32];
           while( *ptr )
           {   /* Uppercase test */
               if( ptr[0] < 'a' )
               {   sx = x + FontDimen[ptr[0]-'A'];
                   sy = y + InvertY(FontDimen[ptr[1]-'a']);
                   ptr += 2;
               } else
               {   sx = ex;
                   sy = ey;
               }

               ex = x + FontDimen[ptr[0]-'a'];
               ey = y + InvertY(FontDimen[ptr[1]-'a']);
               if (FontStroke < 1 ) {
                 if( (ex!=sx) || (ey!=sy) )
                 {   DrawTwinLine(sx,sy,z,ex,ey,z,col,col,' ');
                 } else PlotPoint(ex,ey,z,col);
               } else {
                 if( (ex!=sx) || (ey!=sy) )
                 {   DrawCylinder(sx,sy,z,ex,ey,z,col,col,
                                  FontStroke,' ',FontStroke);
                 } /* else DrawSphere(ex,ey,z,FontStroke,col); */
               }
               ptr += 2;
           }

           x += FontWid[(*label-32)]+FontStroke;
           label++;
        }

        if( *label )
            ClipCharacter(x,y,z,(*label-32),col);
    } else /* Always Clip! */
        while( *label && (x<View.xmax) )
        {   ClipCharacter(x,y,z,(*label-32),col);
            x += FontWid[(*label-32)]+FontStroke;
            label++;
        }
}



void InitialisePixUtils( void )
{
#if defined(IBMPC) || defined(APPLEMAC)
    ArcAc = (ArcEntry __far*)_fmalloc(ARCSIZE*sizeof(ArcEntry));
    ArcDn = (ArcEntry __far*)_fmalloc(ARCSIZE*sizeof(ArcEntry));
#endif
    SplineCount = 5;
    SetFontSize(8);
    SetFontStroke(0);
}

