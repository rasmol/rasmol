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
/* outfile.c
 $Log$
 Revision 1.9  2008/03/22 18:42:53  yaya
 Post release cleanup and credit to Ikonen in file headers. -- HJB

 Revision 1.8  2008/03/17 03:01:31  yaya
 Update to agree with 2.7.4.2 release and T. Ikonen GTK mods -- HJB

 Revision 1.3  2008/03/17 01:32:41  yaya
 Add gtk mods by tpikonen, and intergate with 2.7.4.2 mods -- HJB

 Revision 1.7  2008/03/16 22:25:22  yaya
 Align comments with production version; Update rasmol_install and
 rasmol_run shell scripts for Japanese and Chinese; Align logic for
 positioning and sizing initial window with windows version -- HJB

 Revision 1.2  2008/01/28 03:29:37  yaya
 Update CVS to RasMol_2.7.4.1 -- HJB

 Revision 1.6  2008/01/05 20:56:29  yaya
 Update handling of stereo interaction with slab
 Enable save of CBF-style maps. -- HJB

 Revision 1.5  2007/12/14 02:04:50  yaya
 Correct Chinese data for missing line in langsel_utf.c
 Rewrite code for handling of slab mode in stereo -- HJB

 Revision 1.4  2007/11/19 03:28:39  yaya
 Update to credits for 2.7.4 in manual and headers
 Mask code added -- HJB

 Revision 1.3  2007/07/07 21:54:31  yaya
 Next round of preliminary updates for maps, allowing multiple maps,
 code to set the contour level and some fixes to the languages files -- HJB

 Revision 1.2  2007/07/02 12:44:39  yaya
 Partial preliminary map code -- HJB

 Revision 1.1.1.1  2007/03/01 01:16:33  todorovg
 Chinese working versio from rasmol_ru initial import

 Revision 1.5  2007/02/02 21:08:59  yaya
 Remove // comments for AIX build
 Fix signed length conflict
 Fix array bounds violation for molecule names in multiple.c -- HJB

 Revision 1.4  2006/12/03 02:53:10  yaya
 Clean up compilation warnings in outfile.c
 Mods for about screen under Linux -- HJB

 Revision 1.3  2006/11/01 03:23:50  yaya
 Update NSIS windows installer for more script types and to fix
 misplaced script instructions for data files; add document and
 script icons directly in raswin.exe; add credit line to
 G. A. Pozhvanov in comments for Russian translations. -- HJB

 Revision 1.2  2006/09/17 10:53:55  yaya
 Clean up headers and start on code for X11 -- HJB

 Revision 1.1.1.1  2006/09/16 18:45:53  yaya
 Start of RasMol Russian Translation Project based on translations
 by Gregory A. Pozhvanov of Saint Petersburg State University -- HJB

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

 Revision 1.4  2000/08/26 18:12:36  yaya
 Updates to header comments in all files

 Revision 1.3  2000/08/26 03:14:01  yaya
 Mods for mac compilations

 Revision 1.2  2000/08/09 01:18:08  yaya
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

#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define OUTFILE
#include "outfile.h"
#include "molecule.h"
#include "command.h"
#include "cmndline.h"
#include "abstree.h"
#include "transfor.h"
#include "render.h"
#include "repres.h"
#include "graphics.h"
#include "pixutils.h"
#include "script.h"
#include "font.h"
#include "maps.h"
/* #define BIGGIF */


#define Round(x)       ((int)(x))

#ifdef INVERT
#define InvertY(y) (y)
#else
#define InvertY(y) (-(y))
#endif

#ifdef EIGHTBIT
#define RComp(x)   (RLut[LutInv[x]])
#define GComp(x)   (GLut[LutInv[x]])
#define BComp(x)   (BLut[LutInv[x]])
#else
#define RComp(x)   (((x)>>16)&0xff)
#define GComp(x)   (((x)>>8)&0xff)
#define BComp(x)   ((x)&0xff)
#endif

/* Macros for commonly used loops */
#define ForEachAtom  for(chain=Database->clist;chain;chain=chain->cnext) \
                     for(group=chain->glist;group;group=group->gnext)    \
                     for(aptr=group->alist;aptr;aptr=aptr->anext)
#define ForEachBond  for(bptr=Database->blist;bptr;bptr=bptr->bnext)
#define ForEachBack  for(chain=Database->clist;chain;chain=chain->cnext) \
                     for(bptr=chain->blist;bptr;bptr=bptr->bnext)


/* Sun rasterfile.h macro defns */
#define RAS_MAGIC       0x59a66a95
#define RAS_RLE         0x80
#define RT_STANDARD     1
#define RT_BYTE_ENCODED 2
#define RMT_NONE        0
#define RMT_EQUAL_RGB   1

/* Standard A4 size page: 8.267x11.811 inches */
/* U.S. Normal size page: 8.500x11.000 inches */
#define PAGEHIGH  (11.811*72.0)
#define PAGEWIDE  (8.267*72.0)
#define BORDER    0.90

/* Compression Ratio   0<x<127 */
#define EPSFCompRatio  32

#define PSBond      0x00
#define PSHBond     0x01
#define PSSSBond    0x02
#define PSAtom      0x03
#define PSRibbon    0x04
#define PSMonit     0x05

/* Apple PICT macros */
#define PICTcliprgn         0x0001
#define PICTpicversion      0x0011
#define PICTpackbitsrect    0x0098
#define PICTdirectbitsrect  0x009a
#define PICTendofpict       0x00ff
#define PICTheaderop        0x0c00

/* Raster3D defines */
#define NTX 45		/* number of tiles in x direction*/
#define NTY 32		/* number of tiles in y direction*/
#define NPX 16		/* number of pixels per tile in x direction*/
#define NPY 16		/* number of pixels per tile in y direction*/
typedef void __far* PSItemPtr;


#ifdef EIGHTBIT
#if defined(IBMPC) || defined(APPLEMAC)
static short __far *ABranch;
static short __far *DBranch;
static short __far *Hash;
static Byte __far *Node;
#else
static short ABranch[4096];
static short DBranch[4096];
static short Hash[256];
static Byte Node[4096];
#endif
#endif


#ifdef EIGHTBIT
typedef struct {
        Byte len;
        Byte ch;
        } BMPPacket;
        
static BMPPacket BMPBuffer[10];
static int BMPCount,BMPTotal;        
static int BMPPad;
#endif


#ifdef EIGHTBIT
static int GIFClrCode; 
static int GIFEOFCode;
#endif

static short RLELineSize;
static Card RLEFileSize;
static int RLEEncode;
static int RLEOutput;
static int RLELength;
static int RLEPixel;
static int RLEChar;


static Byte Buffer[256];
static int LineLength;
static FILE *OutFile;
static int PacketLen;
#ifdef EIGHTBIT
static Byte LutInv[256];
static Card BitBuffer;
static int BitBufLen;
static int CodeSize;
#endif

static Real LineWidth;
static int VectSolid;
static int VectCol;


/*=======================*/
/*  Function Prototypes  */
/*=======================*/

static int FindDepth( PSItemPtr, int );
static void DepthSort( PSItemPtr __far*, char __far*, int );
static int ClipVectSphere( RAtom __far* );
static int ClipVectBond( RAtom __far*, RAtom __far* );
static void WriteVectSphere( PSItemPtr __far*, char __far*, int );
static void WriteVectStick( RAtom __far*, RAtom __far*, int, int );
static void WriteVectWire( RAtom __far*, RAtom __far*, int, int );
static void FetchPSItems( PSItemPtr __far*, char __far* );
static void WritePSItems( PSItemPtr __far*, char __far*, int );
static void WriteR3DSphere( PSItemPtr __far*, char __far*, int, int );
static void WriteR3DItems( PSItemPtr __far*, char __far*, int, int );
static void WriteR3DStick( RAtom __far*, RAtom __far*, int, int, int );
static void WriteR3DMonitor( Monitor __far*, int, int );
static void OutputR3DCharacter( Real, Real, Real, int, int, Real,Real );
static void WriteR3DLabels( int );
void OutputR3DFontString( Real, Real, Real, unsigned char*, int, Real );
R3DRib __far *Add_ribdata( Real, Real, Real, Real, Real, Real, Real, Real, Real, R3DRib __far*,int, Real);

static void DetermineIRISSizes( Long __far*, short __far*, int*, int* );
static void WriteIRISHeader( Long __far*, short __far*, int, int );

#ifdef APPLEMAC
/* External RasMac Function Declaration! */
void SetFileInfo( char*, OSType, OSType, short );
#endif



void FatalOutputError( char *ptr )
{
    InvalidateCmndLine();
    WriteString("Output Error: Unable to create file `");
    WriteString( ptr );  WriteString("'!\n");
}



/*===========================*/
/*  Integer Output Routines  */
/*===========================*/

static void WriteByte( int val )
{
    putc( val, OutFile );
}


#ifdef EIGHTBIT
static void WriteLSBShort( int val )
{
    putc( val&0xff, OutFile );
    putc( (val>>8)&0xff, OutFile );
}
#endif


static void WriteMSBShort( int val )
{
    putc( (val>>8)&0xff, OutFile );
    putc( val&0xff, OutFile );
}


#ifdef EIGHTBIT
static void WriteLSBLong( Card val )
{
    putc((int)(val&0xff),OutFile);
    putc((int)((val>>8) &0xff),OutFile);
    putc((int)((val>>16)&0xff),OutFile);
    putc((int)((val>>24)&0xff),OutFile);
}

#endif


static void WriteMSBLong( Card val )
{
    putc((int)((val>>24)&0xff),OutFile);
    putc((int)((val>>16)&0xff),OutFile);
    putc((int)((val>>8) &0xff),OutFile);
    putc((int)(val&0xff),OutFile);
}


static void CalcInvColourMap( void )
{
#ifdef EIGHTBIT
    register int i;

    for( i=0; i<256; i++ )
        if( ULut[i] )
            LutInv[Lut[i]] = i;
#endif
}


#ifdef EIGHTBIT
static int CompactColourMap( void )
{
    register Pixel __huge *ptr;
    register Long pos, count;
    register int i, cols;

    CalcInvColourMap();
    for( i=0; i<256; i++ )
    {   Buffer[i] = 0;
        Node[i] = 5;
    }

#ifdef MSWIN
    ptr = (Pixel __huge*)GlobalLock(FBufHandle);    
#else
    ptr = FBuffer;
#endif

    cols = 0;
    count = (Long)XRange*YRange;
    for( pos=0; pos<count; pos++ )
    {   i = LutInv[*ptr++];
        if( !Buffer[i] ) 
        {   Node[cols++] = i;
            Buffer[i] = cols;
        }
    }

    for( i=0; i<256; i++ )
        LutInv[i] = Buffer[LutInv[i]]-1;
#ifdef MSWIN
    GlobalUnlock(FBufHandle);
#endif
    return cols;
}
#endif



/*==============================*/
/*  Portable Pixmap Generation  */
/*==============================*/

static void WritePPMWord( int i )
{
    if( i>99 )
    {   putc((i/100)+'0',OutFile); i %= 100;
        putc((i/10) +'0',OutFile); i %= 10;
    } else if( i>9 )
    {   putc((i/10)+'0',OutFile);  i %= 10;
    }
    putc(i+'0',OutFile);
}


int WritePPMFile( char *name, int raw )
{
    register Pixel __huge *ptr;
    register int i,col;
    register int x,y;

#if defined(IBMPC) || defined(APPLEMAC)
    OutFile = fopen(name, (raw?"wb":"w") );
#else
    OutFile = fopen(name,"w");
#endif

    if( !OutFile ) 
    {   FatalOutputError(name);
        return( False );
    }

    CalcInvColourMap();
    fprintf(OutFile,"P%c %d %d 255\n",(raw?'6':'3'),XRange,YRange);

#ifdef MSWIN
    FBuffer = (Pixel __huge*)GlobalLock(FBufHandle);
#endif

#ifndef INVERT
    ptr = FBuffer;
#endif

    if( !raw )
    {   col = 0;
        for( y=YRange-1; y>=0; y-- )
        {
#ifdef INVERT
            ptr = FBuffer + (Long)y*XRange;
#endif
            for( x=0; x<XRange; x++ )
            {   i = *ptr++;
                WritePPMWord((int)RComp(i));  WriteByte(' ');
                WritePPMWord((int)GComp(i));  WriteByte(' ');
                WritePPMWord((int)BComp(i));  
                if( ++col == 5 )
                {   WriteByte('\n');
                    col = 0;
                } else WriteByte(' ');
            }
        }
    } else
        for( y=YRange-1; y>=0; y-- )
        {
#ifdef INVERT
            ptr = FBuffer + (Long)y*XRange;
#endif
            for( x=0; x<XRange; x++ )
            {   i = *ptr++;
                putc((int)RComp(i),OutFile);
                putc((int)GComp(i),OutFile);
                putc((int)BComp(i),OutFile);
            }
        }

    fclose(OutFile);
#ifdef APPLEMAC
    /* Avoid ANSI trigraph problems! */
    SetFileInfo(name,'\?\?\?\?','\?\?\?\?',134);
#endif
#ifdef MSWIN
    GlobalUnlock(FBufHandle); 
#endif
    return( True );
}



/*=============================*/
/*  Compuserve GIF Generation  */
/*=============================*/

#ifdef EIGHTBIT
static void WriteGIFCode( int code )
{
    register int max;

    max = (code==GIFEOFCode)? 0 : 7;
    BitBuffer |= ((Card)code<<BitBufLen);
    BitBufLen += CodeSize;

    while( BitBufLen > max )
    {    
#ifdef IBMPC
         Buffer[PacketLen++]=(Byte)(BitBuffer&0xff);
#else
         Buffer[PacketLen++]=BitBuffer;
#endif
         BitBuffer >>= 8;
         BitBufLen -= 8;

        if( PacketLen==255 )
        {   WriteByte(0xff);
            fwrite((char*)Buffer,1,255,OutFile);
            PacketLen = 0;
        }
    }
}


int WriteGIFFile( char *name )
{
    register int i,j,cols;
    register int pref,next,last;
    register int isize, ilast;
    register Pixel __huge *ptr;
    register short __far *prev;
    register int x,y,init;

    cols = CompactColourMap();
    if( cols<2 ) return( False );

    for( isize=2; isize<8; isize++ )
        if( (1<<isize) >= cols ) break;
    cols = 1<<isize;

#if defined(IBMPC) || defined(APPLEMAC)
    OutFile = fopen(name,"wb");
#else
    OutFile = fopen(name,"w");
#endif
    if( !OutFile ) 
    {    FatalOutputError(name);
         return( False );
    }
    fputs("GIF87a",OutFile);
    WriteLSBShort(XRange);
    WriteLSBShort(YRange);
    WriteByte(0xf0|(isize-1)); 
    WriteByte(0x00); 
    WriteByte(0x00);

    for( j=0; j<cols; j++ )
    {   i = Node[j];
        WriteByte(RLut[i]);
        WriteByte(GLut[i]);
        WriteByte(BLut[i]);
    }

    WriteByte(',');
    WriteByte(0x00);  WriteByte(0x00);
    WriteByte(0x00);  WriteByte(0x00);
    WriteLSBShort(XRange);
    WriteLSBShort(YRange);
    WriteByte(0x00);  WriteByte(isize);

    PacketLen=0;
    BitBuffer=0;
    BitBufLen=0;

    GIFClrCode = (1<<isize);
    GIFEOFCode = GIFClrCode+1;
    ilast = (GIFClrCode<<1)-GIFEOFCode;
    isize++;

    CodeSize = isize;
    last = ilast;
    next = 1;  
   
    WriteGIFCode(GIFClrCode);
    for( i=0; i<cols; i++ )
        Hash[i]=0;

#ifdef MSWIN
    FBuffer = (Pixel __huge*)GlobalLock(FBufHandle);    
#endif

#ifndef INVERT
    ptr = FBuffer;
#endif

    /* Avoid Warnings! */
    prev = (short __far*)0; 
    pref = 0;

    init = False;
    for( y=YRange-1; y>=0; y-- )
    {   
#ifdef INVERT
        ptr = FBuffer + (Long)y*XRange;
#endif
        for( x=0; x<XRange; x++ )
        {   
#ifdef BIGGIF
            i = LutInv[*ptr++];
            WriteGIFCode(i);
            if( next == ilast-1 )
            {   WriteGIFCode(GIFClrCode);
                next = 1;
            } else next++;
#else
            if( !init )
            {   pref = LutInv[*ptr++];
                prev = Hash+pref;
                init = True;
                continue;
            }

            i = LutInv[*ptr++];

            while( *prev && (Node[*prev] != (Byte)i) )
                prev = ABranch+*prev;

            if( *prev )
            {   pref = *prev+GIFEOFCode;
                prev = DBranch+*prev;
            } else
            {   WriteGIFCode(pref);
                if( next == last )
                {   if( CodeSize == 12 )
                    {   WriteGIFCode(GIFClrCode);
                        pref = i;  prev = Hash+i;
                        for( i=0; i<cols; i++ )
                            Hash[i] = 0;
                        CodeSize = isize;
                        last = ilast;
                        next = 1; 
                        continue;
                    }
                    last = (last<<1)+GIFEOFCode;
                    CodeSize++;
                }
                *prev = next;
                ABranch[next] = 0;
                DBranch[next] = 0;
                Node[next] = i;
                prev = Hash+i;
                pref = i;
                next++;
            }
#endif
        }
    }

#ifndef BIGGIF
    WriteGIFCode(pref);
#endif

    WriteGIFCode(GIFEOFCode);
    if( PacketLen )
    {   WriteByte(PacketLen);
        fwrite((char*)Buffer,1,PacketLen,OutFile);
    }

    WriteByte(0x00);
    WriteByte(';');
    fclose(OutFile);

#ifdef APPLEMAC
    /* Avoid ANSI trigraph problems! */
    SetFileInfo(name,'\?\?\?\?','GIFf',134);
#endif
#ifdef MSWIN
    GlobalUnlock(FBufHandle);
#endif
    return True;
}
#else /* EIGHTBIT */

int WriteGIFFile( char *name )
{
    UnusedArgument(name);

    InvalidateCmndLine();
    WriteString("Output Error: Only 8-bit GIF files supported!\n");
    return False;
}
#endif



/*================================*/
/*  SUN Raster Format Generation  */
/*================================*/

static void FlushRastRLE( void )
{
    if( RLEChar==RAS_RLE )
    {   if( RLEOutput )
        {   WriteByte(RAS_RLE);
            WriteByte(RLELength-1);
            if( RLELength!=1 )
                WriteByte(RAS_RLE);
        } else RLEFileSize += (RLELength>1)? 3 : 2;
    } else
        if( RLEOutput )
        {   if( RLELength>2 )
            {   WriteByte(RAS_RLE);
                WriteByte(RLELength-1);
            } else if( RLELength==2 )
                WriteByte(RLEChar);
            WriteByte(RLEChar);
        } else RLEFileSize += MinFun(RLELength,3);
}


static void WriteRastRLECode( int val )
{
    if( RLEEncode )
    {   if( !RLELength )
        {   RLELength = 1;
            RLEChar = val;
        } else if( (RLEChar!=val) || (RLELength==256) )
        {   FlushRastRLE();
            RLELength = 1;
            RLEChar = val;
        } else RLELength++;
    } else WriteByte(val);
}


static void WriteRastRLEPad( void )
{
    if( RLEEncode )
    {   if( !RLELength || (RLELength==256) )
        {   WriteRastRLECode(0x00);
        } else RLELength++;
    } else WriteByte(0x00);
}


static void WriteRastData( int output )
{
    register Pixel __huge *ptr;
    register int x,y,pad;
#ifndef EIGHTBIT
    register int i;
#endif

#ifdef MSWIN
    FBuffer = (Pixel __huge*)GlobalLock(FBufHandle);
#endif

#ifndef INVERT
    ptr = FBuffer;
#endif

    pad = XRange%2;

    RLEOutput = output;
    RLEFileSize = 0;
    RLELength = 0;

    for( y=YRange-1; y>=0; y-- )
    {   
#ifdef INVERT
        ptr = FBuffer + (Long)y*XRange;
#endif
        for( x=0; x<XRange; x++ )
#ifndef EIGHTBIT
        {   i = *ptr++;
            WriteRastRLECode((int)BComp(i));
            WriteRastRLECode((int)GComp(i));
            WriteRastRLECode((int)RComp(i));
        }
#else
            WriteRastRLECode((int)LutInv[*ptr++]);
#endif
        if( pad ) WriteRastRLEPad();
    }

    if( RLEEncode && RLELength )
        FlushRastRLE();
#ifdef MSWIN
    GlobalUnlock(FBufHandle);
#endif
}


int WriteRastFile( char *name, int encode )
{
#ifdef EIGHTBIT
    register int i,cols;
#endif
    register int size;

#if defined(IBMPC) || defined(APPLEMAC)
    OutFile = fopen(name,"wb");
#else
    OutFile = fopen(name,"w");
#endif

    if( !OutFile )
    {   FatalOutputError(name);
        return(False);
    }
    WriteMSBLong( RAS_MAGIC );
    WriteMSBLong(XRange);  
    WriteMSBLong(YRange);
    RLEEncode = encode;

#ifdef EIGHTBIT
    WriteMSBLong(8);

    if( encode )
    {   WriteRastData(False);
        WriteMSBLong(RLEFileSize);
        WriteMSBLong(RT_BYTE_ENCODED);
    } else
    {   size = (XRange%2)? XRange+1 : XRange;
        WriteMSBLong(size*YRange);
        WriteMSBLong(RT_STANDARD);
    }

    cols = CompactColourMap();
    WriteMSBLong(RMT_EQUAL_RGB);
    WriteMSBLong(cols*3);

    for( i=0; i<cols; i++ ) WriteByte(RLut[Node[i]]);
    for( i=0; i<cols; i++ ) WriteByte(GLut[Node[i]]);
    for( i=0; i<cols; i++ ) WriteByte(BLut[Node[i]]);
#else
    WriteMSBLong(24);

    if( encode )
    {   WriteRastData(False);
        WriteMSBLong(RLEFileSize);
        WriteMSBLong(RT_BYTE_ENCODED);
    } else
    {   size = XRange*3;
        if( size&1 ) size++;
        WriteMSBLong((Long)size*YRange);
        WriteMSBLong(RT_STANDARD);
    }
    WriteMSBLong(RMT_NONE);
    WriteMSBLong(0);
#endif

    WriteRastData(True);
    fclose( OutFile );
#ifdef APPLEMAC
    /* Avoid ANSI trigraph problems! */
    SetFileInfo(name,'\?\?\?\?','\?\?\?\?',134);
#endif
    return True;
}



/*===============================*/
/*  PostScript Image Generation  */
/*===============================*/

static void OutputEPSFByte( int val )
{
    static char *hex = "0123456789ABCDEF";

    WriteByte( hex[val>>4] );
    WriteByte( hex[val&0x0f] );
    if( (LineLength+=2) > 72 )
    {   WriteByte('\n');
        LineLength = 0;
    }
}


static void EncodeEPSFPixel( int val, int col )
{
    register int r, g, b;
    register int i;

    r = RComp(val);
    g = GComp(val);
    b = BComp(val);

    if( col )
    {   OutputEPSFByte( r );
        OutputEPSFByte( g );
        OutputEPSFByte( b );
    } else
    {   i = (20*r + 32*g + 12*b)>>6;
        OutputEPSFByte( i );
    }
}


int WriteEPSFFile( char *name, int col, int compr )
{
    register int x, y, i, j;
    register int xsize, ysize;
    register int xpos, ypos;
    register int rotpage;

    register Pixel __huge *ptr;
    int RLEBuffer[128];

    OutFile = fopen(name,"w");
    if( !OutFile )
    {   FatalOutputError(name);
        return(False);
    }

    CalcInvColourMap();
    if( XRange <= YRange )
    {   rotpage = False; 
        xsize = XRange; 
        ysize = YRange;
    } else
    {   rotpage = True;  
        xsize = YRange; 
        ysize = XRange;
    }

    if( xsize > (int)(BORDER*PAGEWIDE) )
    {   ysize = (int)(ysize*(BORDER*PAGEWIDE)/xsize);
        xsize = (int)(BORDER*PAGEWIDE);
    }
    if( ysize > (int)(BORDER*PAGEHIGH) )
    {   xsize = (int)(xsize*(BORDER*PAGEHIGH)/ysize);
        ysize = (int)(BORDER*PAGEHIGH);
    }

    xpos = (int)(PAGEWIDE-xsize)/2;
    ypos = (int)(PAGEHIGH-ysize)/2;

    fputs("%!PS-Adobe-2.0 EPSF-2.0\n",OutFile);
    fprintf(OutFile,"%%Creator: RasMol Version %s\n",VERSION);
    fprintf(OutFile,"%%%%Title: %s\n",name);
    fprintf(OutFile,"%%%%BoundingBox: %d %d ",xpos,ypos);
    fprintf(OutFile,"%d %d\n",xpos+xsize,ypos+ysize);

    fputs("%%Pages: 1\n",OutFile);
    fputs("%%EndComments\n",OutFile);
    fputs("%%EndProlog\n",OutFile);
    fputs("%%Page: 1 1\n",OutFile);

    fputs("gsave\n",OutFile);
    fputs("10 dict begin\n",OutFile);
    fprintf(OutFile,"%d %d translate\n",xpos,ypos);
    fprintf(OutFile,"%d %d scale\n",xsize,ysize);
    if( rotpage )
    {   fputs("0.5 0.5 translate\n",OutFile);
        fputs("90 rotate\n",OutFile);
        fputs("-0.5 -0.5 translate\n",OutFile);
    }
    fputc('\n',OutFile);

    if( compr )
    {   fputs("/rlecount 0 def\n",OutFile);
        fputs("/rlebyte 1 string def\n",OutFile);
        fprintf(OutFile,"/pixbuf %d string def\n", col?3:1 );
        fputs("/reppixel { pixbuf } def\n",OutFile);
        fputs("/getpixel { \n",OutFile);
        fputs("  currentfile pixbuf readhexstring pop\n",OutFile);
        fputs("} def\n\n",OutFile);

        if( col )
        {   fputs("/colorimage where {\n",OutFile);
            fputs("  pop\n",OutFile);
            fputs("} {\n",OutFile);
            fputs("  /bytebuf 1 string def\n",OutFile);
            fputs("  /colorimage { pop pop image } def\n",OutFile);
            fputs("  /reppixel { bytebuf } def\n",OutFile);
            fputs("  /getpixel {\n",OutFile);
            fputs("    currentfile pixbuf readhexstring pop pop\n",OutFile);
            fputs("    bytebuf 0\n",OutFile);
            fputs("    pixbuf 0 get 20 mul\n",OutFile);
            fputs("    pixbuf 1 get 32 mul\n",OutFile);
            fputs("    pixbuf 2 get 12 mul\n",OutFile);
            fputs("    add add -6 bitshift put bytebuf\n",OutFile);
            fputs("  } def\n",OutFile);
            fputs("} ifelse\n\n",OutFile);
        }

        fputs("/rledecode {\n",OutFile);
        fputs("  rlecount 0 eq {\n",OutFile);
        fputs("    currentfile rlebyte readhexstring pop\n",OutFile);
        fprintf(OutFile,"    0 get dup %d gt {\n",EPSFCompRatio);
        fprintf(OutFile,"      /rlecount exch %d sub def\n",EPSFCompRatio);
        fputs("      /rleflag true def\n",OutFile);
        fputs("    } {\n",OutFile);
        fputs("      /rlecount exch def\n",OutFile);
        fputs("      /rleflag false def\n",OutFile);
        fputs("    } ifelse getpixel\n",OutFile);
        fputs("  } {\n",OutFile);
        fputs("    /rlecount rlecount 1 sub def\n",OutFile);
        fputs("    rleflag { reppixel } { getpixel } ifelse\n",OutFile);
        fputs("  } ifelse\n",OutFile);
        fputs("} def\n",OutFile);
    } else if( col )
    {   fprintf(OutFile,"/scanbuf %d string def\n",XRange*3);
        fputs("/colorimage where {\n",OutFile);
        fputs("  pop\n",OutFile);
        fputs("} {\n",OutFile);
        fputs("  /pixbuf 3 string def\n",OutFile);
        fputs("  /bytebuf 1 string def\n",OutFile);
        fputs("  /colorimage {\n",OutFile);
        fputs("    pop pop pop {\n",OutFile);
        fputs("      currentfile pixbuf readhexstring pop pop\n",OutFile);
        fputs("      bytebuf 0\n",OutFile);
        fputs("      pixbuf 0 get 20 mul\n",OutFile);
        fputs("      pixbuf 1 get 32 mul\n",OutFile);
        fputs("      pixbuf 2 get 12 mul\n",OutFile);
        fputs("      add add -6 bitshift put bytebuf\n",OutFile);
        fputs("    } image\n",OutFile);
        fputs("  } def\n",OutFile);
        fputs("} ifelse\n\n",OutFile);
    } else fprintf(OutFile,"/scanbuf %d string def\n\n",XRange);

    fprintf(OutFile,"%d %d %d\n",XRange,YRange,8);
    fprintf(OutFile,"[%d 0 0 -%d 0 %d]\n",XRange,YRange,YRange);

    if( !compr )
    {   fputs("{ currentfile scanbuf readhexstring pop }\n",OutFile);
    } else fputs("{ rledecode }\n",OutFile);
    if( col ) fputs("false 3 color",OutFile);
    fputs("image\n",OutFile);

#ifdef MSWIN
    FBuffer = (Pixel __huge*)GlobalLock(FBufHandle);
#endif

#ifndef INVERT
    ptr = FBuffer; 
#endif

    RLELength = 0;
    LineLength = 0;
    for( y=YRange-1; y>=0; y-- )
    {
#ifdef INVERT
        ptr = FBuffer + (Long)y*XRange;
#endif
        for( x=0; x<XRange; x++ )
        {   i = *ptr++;
            if( compr )
            {   if( RLELength )
                {   if( RLEEncode )
                    {   if( (RLEPixel!=i) || (RLELength==256-EPSFCompRatio) )
                        {   OutputEPSFByte(RLELength+EPSFCompRatio-1);
                            EncodeEPSFPixel(RLEPixel,col);
                            RLEEncode = False;
                            RLEBuffer[0] = i;
                            RLELength = 1;
                        } else RLELength++;
                    } else if( RLEBuffer[RLELength-1] == i )
                    {   if( RLELength>1 )
                        {   OutputEPSFByte(RLELength-2);
                            for( j=0; j<RLELength-1; j++ )
                                EncodeEPSFPixel(RLEBuffer[j],col);
                        }
                        RLEEncode = True;
                        RLELength = 2;
                        RLEPixel = i;
                    } else if( RLELength == EPSFCompRatio+1 )
                    {   OutputEPSFByte(EPSFCompRatio);
                        for( j=0; j<RLELength; j++ )
                             EncodeEPSFPixel(RLEBuffer[j],col);
                        RLEEncode = False;
                        RLEBuffer[0] = i;
                        RLELength = 1;
                    } else RLEBuffer[RLELength++] = i;
                } else
                {   RLEEncode = False;
                    RLEBuffer[0] = i;
                    RLELength = 1;
                }
            } else EncodeEPSFPixel( i, col );
        }
    }

    if( compr && RLELength )
    {   if( RLEEncode )
        {   OutputEPSFByte(RLELength+EPSFCompRatio-1);
            EncodeEPSFPixel(RLEPixel,col);
        } else
        {   OutputEPSFByte(RLELength-1);
            for( j=0; j<RLELength; j++ )
                EncodeEPSFPixel(RLEBuffer[j],col);
        }
    }

    if( LineLength ) 
        fputc('\n',OutFile);
    fputs("end\n",OutFile);
    fputs("grestore\n",OutFile);
    fputs("showpage\n",OutFile);
    fputs("%%Trailer\n",OutFile);
    fputs("%%EOF\n",OutFile);
    fclose( OutFile );
#ifdef APPLEMAC
    /* Avoid ANSI trigraph problems! */
    SetFileInfo(name,'vgrd','TEXT',134);
#endif
#ifdef MSWIN
    GlobalUnlock(FBufHandle);
#endif
    return True;
}


/*============================*/
/*  Microsoft BMP Generation  */
/*============================*/
  
#ifdef EIGHTBIT
/* Flush AbsMode buffer */
static void FlushBMPBuffer( void )
{
    if( RLEOutput )
    {   WriteByte(0x00);
        WriteByte(PacketLen);
        fwrite((char*)Buffer,1,PacketLen,OutFile);
        if( PacketLen%2 ) WriteByte(0x00);    
    } else
        RLEFileSize += (PacketLen%2)+PacketLen+2;
    PacketLen = 0;
}


/* Flush RLEMode buffer */
static void FlushBMPPackets( void )
{
    register int i;
    
    if( PacketLen )
        FlushBMPBuffer();

    if( RLEOutput )
    {   for( i=0; i<BMPCount; i++ )
        {   WriteByte(BMPBuffer[i].len);
            WriteByte(BMPBuffer[i].ch);
        }
    } else RLEFileSize += (BMPCount<<1);
    BMPCount = BMPTotal = 0;
}


static void ProcessBMPPacket( void )
{
    register int cost;
    register int i,j;
    
    BMPBuffer[BMPCount].len = RLELength;
    BMPBuffer[BMPCount].ch = RLEChar;
    BMPTotal += RLELength;
    RLELength = 0;
    BMPCount++; 

    /* RLEMode is more efficient */
    if( BMPTotal > BMPCount+5 )
    {   FlushBMPPackets();
        return;
    }
    
    /* Flush AbsMode buffer */
    if( PacketLen+BMPTotal>255 )
        FlushBMPBuffer();
    
    /* Cannot leave RLEMode */
    if( PacketLen+BMPTotal<3 )
        return;
        
    /* Determine AbsMode cost */
    if( PacketLen )
    {   cost = BMPTotal - (PacketLen%2);
        cost += (cost%2);
    } else cost = (BMPTotal%2)+BMPTotal+2;    

    /* Put RLE Packets into AbsMode buffer */
    if( cost <= (int)(BMPCount<<1) )
    {   for( i=0; i<BMPCount; i++ )
            for( j=0; j<(int)BMPBuffer[i].len; j++ )
                Buffer[PacketLen++] = BMPBuffer[i].ch;
        BMPCount = BMPTotal = 0;
    }
}
 

/* Collect pixels into RLE Packets */
static void WriteBMPCode( int val )
{
    if( !RLELength )
    {   RLELength = 1;
        RLEChar = val;
    } else
        if( (RLEChar!=val) || (RLELength==255) )
        {   ProcessBMPPacket();
            RLELength = 1;
            RLEChar = val;
        } else
            RLELength++;
}


static void WriteBMPData( int output )
{
    register Pixel __huge *ptr;
    register int x,y;
    
    RLEOutput = output;
    RLEFileSize = 0;   BMPCount = 0;
    RLELength = 0;     BMPTotal = 0;
    PacketLen = 0; 

#ifdef INVERT
    ptr = FBuffer;
#endif

    for( y=YRange-1; y>=0; y-- )
    {
#ifndef INVERT
        ptr = FBuffer + (Long)y*XRange;
#endif
        for( x=0; x<XRange; x++ )
            WriteBMPCode(LutInv[*ptr++]);

        for( x=0; x<BMPPad; x++ )
            WriteBMPCode(0x00);

        /* Flush RLE codes */
        ProcessBMPPacket();
        FlushBMPPackets();
        
        if( RLEOutput )
        {   /* End of line code */
            WriteByte(0x00);
            WriteByte(y?0x00:0x01);
        } else RLEFileSize += 2;
    }
}

  
int WriteBMPFile( char *name )
{
    register Pixel __huge *ptr;
    register int x,y,i,raw;
    register Card size;

#if defined(IBMPC) || defined(APPLEMAC)
    OutFile = fopen(name,"wb");
#else
    OutFile = fopen(name,"w");
#endif
    if( !OutFile )
    {    FatalOutputError(name);
         return( False );
    }

#ifdef MSWIN
    FBuffer = (Pixel __huge*)GlobalLock(FBufHandle);
#endif

    CalcInvColourMap();
    /* zero-pad scanlines to long */
    BMPPad = XRange%4;
    if( BMPPad ) 
         BMPPad = 4-BMPPad; 

    WriteBMPData(False);
    size = (Long)(XRange+BMPPad)*YRange;
    if( RLEFileSize<size )
    {   size = RLEFileSize;
        raw = False;
    } else raw = True;

    WriteByte('B'); 
    WriteByte('M');
    WriteLSBLong(size+1078);
    WriteLSBLong((Card)0);
    WriteLSBLong((Card)1078);

    WriteLSBLong((Card)40);
    WriteLSBLong((Card)XRange);
    WriteLSBLong((Card)YRange);
    WriteByte(0x01);  WriteByte(0x00);
    WriteByte(0x08);  WriteByte(0x00);
    WriteLSBLong(raw? (Card)0 : (Card)1);
    WriteLSBLong(size);
    
    WriteLSBLong((Card)0);
    WriteLSBLong((Card)0);
    WriteLSBLong((Card)256);
    WriteLSBLong((Card)256);

    for( i=0; i<256; i++ )
    {   WriteByte(BLut[i]);
        WriteByte(GLut[i]);
        WriteByte(RLut[i]);
        WriteByte(0x00);
    }

    if( raw )
    {   
#ifdef INVERT
        ptr = FBuffer;
#endif
        for( y=YRange-1; y>=0; y-- )
        {
#ifndef INVERT
            ptr = FBuffer + (Long)y*XRange;
#endif
            for( x=0; x<XRange; x++ )
                WriteByte(LutInv[*ptr++]);
            for( x=0; x<BMPPad; x++ )
                WriteByte(0x00);
        }
    } else
        WriteBMPData(True);
    fclose(OutFile);

#ifdef APPLEMAC
    /* Avoid ANSI trigraph problems! */
    SetFileInfo(name,'\?\?\?\?','\?\?\?\?',134);
#endif
#ifdef MSWIN
    GlobalUnlock(FBufHandle);
#endif
    return True;
}
#else /* EIGHTBIT */
int WriteBMPFile( char *name )
{
    UnusedArgument(name);
 
    InvalidateCmndLine();
    WriteString("Output Error: Only 8-bit BMP files supported!\n");
    return False;
}
#endif



/*================================*/
/*  Vector PostScript Generation  */
/*================================*/

static int FindDepth( PSItemPtr item,  int type )
{
    register Monitor __far *monit;
    register HBond __far *hbond;
    register RAtom __far *atom;
    register Bond __far *bond;
    register int result;

    switch( type )
    {   case(PSAtom):    atom = (RAtom __far*)item;
                         return atom->z;

        case(PSBond):    bond = (Bond __far*)item;
                         result = bond->srcatom->z;
                         if( result < bond->dstatom->z )
                             result = bond->dstatom->z;
                         return result;

        case(PSSSBond):  
        case(PSHBond):   hbond = (HBond __far*)item;
                         if( (type==PSHBond)? HBondMode : SSBondMode )
                         {   result = hbond->srcCA->z;
                             if( result < hbond->dstCA->z )
                                 result = hbond->dstCA->z;
                         } else
                         {   result = hbond->src->z;
                             if( result < hbond->dst->z )
                                 result = hbond->dst->z;
                         }
                         return result;

        case(PSMonit):   monit = (Monitor __far*)item;
                         result = monit->src->z;
                         if( result < monit->dst->z )
                             result = monit->dst->z;
                         return result;
    }
    return 0;
}


static void DepthSort( PSItemPtr __far *data, char __far *type, int count )
{
    register char ttmp;
    register void __far *dtmp;
    register int i, j, k;
    register int depth;
    register int temp;

    for( i=1; i<count; i++ )
    {   dtmp = data[i];  
        ttmp = type[i];

        j = i-1;
        depth = FindDepth(dtmp,ttmp);
        temp = FindDepth(data[j],type[j]);
        while( (depth<temp) || ((depth==temp)&&(ttmp<type[j])) )
            if( j-- ) 
            {   temp = FindDepth(data[j],type[j]);
            } else break;
        j++;

        if( j != i )
        {   for( k=i; k>j; k-- )
            {    data[k] = data[k-1];
                 type[k] = type[k-1];
            }
            data[j] = dtmp;
            type[j] = ttmp;
        }
    }
}


static int ClipVectSphere( RAtom __far *ptr )
{
    register int rad;

    rad = ptr->irad;

    if( ptr->x + rad < 0 )  return True;
    if( ptr->y + rad < 0 )  return True;
    if( ptr->x - rad >= XRange )  return True;
    if( ptr->y - rad >= YRange )  return True;
    return False;
}


static int ClipVectBond( RAtom __far *src, RAtom __far *dst )
{
    if( !src || !dst )  return True;
    if( (src->x<0) && (dst->x<0) )  return True;
    if( (src->y<0) && (dst->y<0) )  return True;
    if( (src->x>=XRange) && (dst->x>=XRange) )  return True;
    if( (src->y>=YRange) && (dst->y>=YRange) )  return True;
    return False;
}


static void WriteVectColour( int col )
{
    if( col != VectCol )
    {   fprintf(OutFile,"%g ",(Real)RLut[col]/255.0);
        fprintf(OutFile,"%g ",(Real)GLut[col]/255.0);
        fprintf(OutFile,"%g ",(Real)BLut[col]/255.0);
        fputs("setrgbcolor\n",OutFile);
        VectCol = col;
    }
}


#define MAXSECT 5
typedef struct {
        /* Ellipse */
        Real ephi,epsi;
        Real etheta;
        Real ex,ey;
        Real erad;

        /* Sphere */
        Real sphi,spsi;
        int sx,sy;
        Real srad;
    } SphereSect;


static int VectClipContain( SphereSect *x, SphereSect *y )
{
    if( x->erad != 0.0 )
    {   if( y->erad != 0.0 )
            /* Simple segment containment test! */
            return( ((x->sphi+x->spsi)>=(y->sphi+y->spsi)) &&
                    ((x->sphi-x->spsi)<=(y->sphi-y->spsi)) );
    } else if( y->erad == 0.0 )
        return( x->srad >= y->srad );
    return False;
}

static void WriteVectSphere( PSItemPtr __far *data, char __far *type, 
                             int index )
{
    register int ecount, count;
    register RAtom __far *atm;
    register RAtom __far *ptr;
    register Long dist2,dist3;
    register int dx, dy, dz;
    register int i,j,k;

    register Real b,d,f,g=0.0,x;
    register Real radf,radb;
    register Real phi1,phi2;
    register Real temp,psi;
    register Real theta;

    register SphereSect *sptr;
    SphereSect sect[MAXSECT];

    ptr = (RAtom __far*)data[index];
    radf = ((Real)ptr->radius)*Scale;

    count = 0;
    ecount = 0;
    sptr = sect;
    for( i=index-1; i>=0; i-- )
    {   if( type[i] != PSAtom )
            continue;

        atm = (RAtom __far*)data[i];
        /* Atom can't intersect visibly! */
        if( atm->z + atm->irad < ptr->z )
            continue;

        dx = atm->x - ptr->x; 
        dy = atm->y - ptr->y; 
        dz = atm->z - ptr->z;

        dist2 = (Long)dx*dx + (Long)dy*dy;
        dist3 = dist2 + dz*dz;

        radb = ((Real)atm->radius)*Scale;  
        temp = radf + radb;

        /* Atoms don't intersect! */
        if( dist3 > temp*temp ) continue;

        d = sqrt( (double)dist3 );
        f = (temp*(radf-radb)+dist3)/(2.0*d);
        theta = -dz/d;

        if( f>0 )
        {   temp = radf*radf;
            /* Intersection not visible! */
            if( theta*temp > temp-f*f )
                continue;
        } else if( f < -radf )
            return;

        x = sqrt( (radf-f)*(radf+f) );

        if( dx || dy )
        {   g = sqrt( (double)dist2 );
            psi = Rad2Deg*atan2(dy,dx);
            b = (f*(dz*dz))/(d*g);

            if( AbsFun(b)>x )
                continue;

            phi1 = b + (f*g)/d;
            phi1 = Rad2Deg*acos(phi1/radf);
            if( phi1!=phi1 ) continue;

            phi2 = (d*b)/g;
            if( AbsFun(phi2) < x )
            {   phi2 = Rad2Deg*acos(phi2/x);
                if( phi2!=phi2 ) continue;
                if( phi2 > 90.0 ) 
                    phi2 = 180.0-phi1;
            } else phi2 = 90.0;

            sptr->erad = x;
            sptr->etheta = -theta;
            sptr->ephi = psi;
            sptr->epsi = phi2;

            temp = f/d;
            sptr->ex = ptr->x+temp*dx;
            sptr->ey = ptr->y+temp*dy;

            sptr->srad = radf;
            sptr->sphi = psi;
            sptr->spsi = phi1;
            sptr->sx = ptr->x;
            sptr->sy = ptr->y;

        } else
        {   x = sqrt( (radf-g)*(radf+g) );

            sptr->srad = x;
            sptr->erad = 0.0;
            sptr->sx = ptr->x;
            sptr->sy = ptr->y;
            sptr->sphi = 180;
            sptr->spsi = -180;
        }

        /* Optimize Segments */
        j = 0;
        while( j<count )
            if( VectClipContain(sptr,sect+j) )
            {   /* Delete Segment sect[j] */
                for( k=j; k<count; k++ )
                    sect[k] = sect[k+1];
                count--;  sptr--;
            } else if( VectClipContain(sect+j,sptr) )
            {   break;  /* Exclude Segment */
            } else j++;
           

        if( j==count )
        {   count++;  sptr++;
            if( sptr->erad != 0.0 )
                ecount++;
            if( count==MAXSECT )
                break;
        }
    }

    if( UseOutLine )
    {   temp = (ptr->z-ZOffset)/ImageSize + 1.0;
        if( temp != LineWidth )
        {   fprintf(OutFile,"%g setlinewidth\n",temp);
            LineWidth = temp;
        }
    }

    if( !VectSolid )
    {   fputs("[] 0 setdash\n",OutFile);
        VectSolid = True;
    }

    if( count )
    {   fputs("gsave\n",OutFile);
        fprintf(OutFile,"%%%% %d %d\n",count,ecount);

        sptr = sect;
        for( i=0; i<count; i++ )
        {   if( sptr->erad != 0.0 )
            {   fprintf(OutFile,"%g %g %g %g %g %g ClipEllips\n",
                            sptr->erad,sptr->epsi,sptr->etheta,
                            sptr->ephi,sptr->ex,sptr->ey);
            }

            if( (i==count-1) || (sptr->erad==0.0) )
            {   fprintf(OutFile,"%g %g %g %d %d ClipSphere\n",sptr->srad,
                                sptr->sphi+sptr->spsi,sptr->sphi-sptr->spsi,
                                sptr->sx, sptr->sy );
            } else fprintf(OutFile,"%g %g %g %d %d ClipBox\n",
                                    sptr->srad+sptr->srad+2,
                                    sptr->srad+1, sptr->ephi,
                                    sptr->sx, sptr->sy );
            sptr++;
        }

        i = ptr->col + ColourMask;
        fprintf(OutFile,"%g ",(Real)RLut[i]/255.0);
        fprintf(OutFile,"%g ",(Real)GLut[i]/255.0);
        fprintf(OutFile,"%g ",(Real)BLut[i]/255.0);
        fprintf(OutFile,"%g Shade\n",radf);
        fputs("grestore\n\n",OutFile);
    } else
    {   i = ptr->col + ColourMask;
        fprintf(OutFile,"%g ",(Real)RLut[i]/255.0);
        fprintf(OutFile,"%g ",(Real)GLut[i]/255.0);
        fprintf(OutFile,"%g ",(Real)BLut[i]/255.0);
        fprintf(OutFile,"%g %ld %ld ",radf,ptr->x,ptr->y);
        fputs("Sphere\n\n",OutFile);
    }
}


static void WriteVectWire( RAtom __far *src, RAtom __far *dst,
                           int col, int dash )
{
    register RAtom __far *tmp;
    register Real radius=0.0;
    register Real temp;
    register Real dist;

    register Real midx, midy;
    register Real endx, endy;
    register int col1, col2;
    register int dx, dy, dz;
    register Long dist2;
    register int inten;

    if( src->z > dst->z )
    {   tmp = src;
        src = dst;
        dst = tmp;
    }

    if( !col )
    {   col1 = src->col;
        col2 = dst->col;
    } else col1 = col2 = col;

    if( UseBackFade )
    {   dz = (src->z+dst->z)>>1;
        inten = (ColourDepth*(dz+ImageRadius-ZOffset))/ImageSize;
    } else inten = ColourMask;

    dx = dst->x - src->x;  
    dy = dst->y - src->y;
    dist2 = dx*dx + dy*dy;
    dist = sqrt( (double)dist2 );

    if( dst->flag & SphereFlag )
    {   radius = ((Real)dst->radius)*Scale;
        if( dist <= radius ) return;

        /* Test for second half obscured! */
        if( (col1!=col2) && (0.5*dist < radius) )
            col2 = col1;
    }

    if( src->flag & SphereFlag )
    {   radius = ((Real)src->radius)*Scale;
        if( dist <= radius ) return;

        /* Test for first half obscured! */
        if( (col1!=col2) && (0.5*dist < radius) )
            col1 = col2;
    }

    WriteVectColour( col1+inten );

    dz = (src->z+dst->z)>>1;
    temp = (double)(dz-ZOffset)/ImageSize + 1.0;
    if( temp != LineWidth )
    {   fprintf(OutFile,"%g setlinewidth\n",temp);
        LineWidth = temp;
    }

    if( dash )
    {   if( VectSolid )
        {   fputs("[3 3] 0 setdash\n",OutFile);
            VectSolid = False;
        }
    } else
        if( !VectSolid )
        {   fputs("[] 0 setdash\n",OutFile);
            VectSolid = True;
        }

    if( src->flag & SphereFlag )
    {   dz = dst->z - src->z;
        dist = sqrt( (double)(dist2 + dz*dz) );
        endx = src->x + (radius*dx)/dist;
        endy = src->y + (radius*dy)/dist;
        fprintf(OutFile,"%g %g ",endx,endy);
    } else
        fprintf(OutFile,"%ld %ld ",src->x,src->y);

    if( col1 != col2 )
    {   midx = 0.5*(src->x + dst->x);
        midy = 0.5*(src->y + dst->y);
        fprintf(OutFile,"%g %g Wire\n",midx,midy);

        WriteVectColour( col2+inten );
        fprintf(OutFile,"%g %g ",midx,midy);
    } 
    fprintf(OutFile,"%ld %ld Wire\n",dst->x,dst->y);
}


static void WriteVectStick( RAtom __far *src, RAtom __far *dst, 
                            int col, int rad )
{
    register RAtom __far *tmp;
    register Real midx, midy;
    register Real relx, rely;
    register Real endx=0.0, endy=0.0;
    register Real radius, angle;
    register Real dist, dist3;
    register Real temp, ratio;

    register Long dist2;
    register int dx, dy, dz;
    register int col1, col2;
    register int i, inten;

    if( !rad )
    {   WriteVectWire(src,dst,col,False);
        return;
    }

    if( src->z > dst->z )
    {   tmp = src;
        src = dst;
        dst = tmp;
    }

    if( !col )
    {   col1 = src->col;
        col2 = dst->col;
    } else col1 = col2 = col;

    dx = dst->x - src->x;  
    dy = dst->y - src->y;
    dz = dst->z - src->z;
    dist2 = dx*dx + dy*dy;
    dist3 = sqrt( (double)(dist2 + dz*dz) );
    dist = sqrt( (double)dist2 );

    if( dst->flag & SphereFlag )
    {   radius = ((Real)dst->radius)*Scale;
        if( dist <= radius ) return;

        /* Test for nearest half obscured! */
        if( (col1!=col2) && (0.5*dist < radius) )
            col2 = col1;
    }

    if( src->flag & SphereFlag )
    {   radius = ((Real)src->radius)*Scale;
        if( dist <= radius ) return;

        /* Test for furthest half obscured! */
        if( (col1!=col2) && (0.5*dist < radius) )
            col1 = col2;
    }

    if( !VectSolid )
    {   fputs("[] 0 setdash\n",OutFile);
        VectSolid = True;
    }

    temp = ((src->z-ZOffset)+(dst->z-ZOffset))/ImageSize + 1.0;
    if( temp != LineWidth )
    {   fprintf(OutFile,"%g setlinewidth\n",temp);
        LineWidth = temp;
    }

    radius = ((Real)rad)*Scale;
    angle = Rad2Deg*atan2((double)dy,(double)dx);
    inten = (int)((dist/dist3)*ColourMask);

    if( col1 != col2 )
    {   midx = 0.5*(src->x + dst->x);
        midy = 0.5*(src->y + dst->y);
        relx = (radius*dx)/dist;
        rely = (radius*dy)/dist;

        fprintf(OutFile,"%g %g moveto\n",midx+rely,midy-relx);
        fprintf(OutFile,"%g %g lineto\n",midx-rely,midy+relx);

        ratio = dz/dist3;

        if( (src->flag&SphereFlag) && (src->radius>rad) )
        {   temp = (Scale*(Real)(src->radius))/dist3;
            endx = src->x + temp*dx;
            endy = src->y + temp*dy;

            fprintf(OutFile,"%g %g %g ",radius,ratio,angle);
            fprintf(OutFile,"%g %g StickEnd\n",endx,endy);
        } else
        {   fprintf(OutFile,"%ld %ld %g ",src->x,src->y,radius);
            fprintf(OutFile,"%g %g arc\n",angle+90,angle-90);
        }
        fputs("closepath ",OutFile);

        i = col1 + inten;
        fprintf(OutFile,"%g ",(Real)RLut[i]/255.0);
        fprintf(OutFile,"%g ",(Real)GLut[i]/255.0);
        fprintf(OutFile,"%g ",(Real)BLut[i]/255.0);
        fputs("setrgbcolor fill\n",OutFile);

        fprintf(OutFile,"%ld %ld %g ",dst->x,dst->y,radius);
        fprintf(OutFile,"%g %g arc\n",angle-90,angle+90);
        fprintf(OutFile,"%g %g %g ",radius,ratio,angle);
        fprintf(OutFile,"%g %g StickEnd\n",midx,midy);
        fputs("closepath ",OutFile);

        i = col2 + inten;
        fprintf(OutFile,"%g ",(Real)RLut[i]/255.0);
        fprintf(OutFile,"%g ",(Real)GLut[i]/255.0);
        fprintf(OutFile,"%g ",(Real)BLut[i]/255.0);
        fputs("setrgbcolor fill\n",OutFile);

        if( UseOutLine )
        {   fprintf(OutFile,"%ld %ld %g ",dst->x,dst->y,radius);
            fprintf(OutFile,"%g %g arc\n",angle-90,angle+90);
            if( (src->flag&SphereFlag) && (src->radius>rad) )
            {   fprintf(OutFile,"%g %g %g ",radius,ratio,angle);
                fprintf(OutFile,"%g %g StickEnd\n",endx,endy);
            } else
            {   fprintf(OutFile,"%ld %ld %g ",src->x,src->y,radius);
                fprintf(OutFile,"%g %g arc\n",angle+90,angle-90);
            }
            fputs("closepath 0 setgray stroke\n",OutFile);
        }
    } else /* col1 == col2! */
    {   fprintf(OutFile,"%ld %ld %g ",dst->x,dst->y,radius);
        fprintf(OutFile,"%g %g arc\n",angle-90,angle+90);

        if( (src->flag&SphereFlag) && (src->radius>rad) )
        {   temp = (Scale*(Real)(src->radius))/dist3;
            endx = src->x + temp*dx;
            endy = src->y + temp*dy;
            ratio = dz/dist3;

            fprintf(OutFile,"%g %g %g ",radius,ratio,angle);
            fprintf(OutFile,"%g %g StickEnd\n",endx,endy);
        } else
        {   fprintf(OutFile,"%ld %ld %g ",src->x,src->y,radius);
            fprintf(OutFile,"%g %g arc\n",angle+90,angle-90);
        }

        i = col1 + inten;
        fprintf(OutFile,"%g ",(Real)RLut[i]/255.0);
        fprintf(OutFile,"%g ",(Real)GLut[i]/255.0);
        fprintf(OutFile,"%g ",(Real)BLut[i]/255.0);
        fputs("Stick\n",OutFile);
    }
    VectCol = 0;
}


static void WriteVectDots( void )
{
    register DotStruct __far *ptr;
    register Real x,y,z;
    register Real xi,yi;
    register int inten;
    register int temp, tump;
    register int zi;
    register int i;
    register int xp;

    if( LineWidth != 1.0 )
    {   fputs("1 setlinewidth\n",OutFile);
        LineWidth = 1.0;
    }

    temp = SlabValue - ZOffset;
    tump = DepthValue - ZOffset;
    for( ptr=DotPtr; ptr; ptr=ptr->next )
        for( i=0; i<ptr->count; i++ )
        {   x = ptr->xpos[i];  
            y = ptr->ypos[i];  
            z = ptr->zpos[i];


            xi = (x*MatX[0]+y*MatX[1]+z*MatX[2]) + XOffset;
            if( (xi<0.0) || ((int)rint(xi)>=View.xmax) ) continue;
            yi = (x*MatY[0]+y*MatY[1]+z*MatY[2]) + YOffset;
            if( (yi<0.0) || ((int)rint(yi)>=View.ymax) ) continue;

            zi = (int)(x*MatZ[0]+y*MatZ[1]+z*MatZ[2]);
            xp = rint(xi);
            if( UseSlabPlane && (zi>=View.slbuf[xp]) ) continue;
            if( UseDepthPlane && (zi<=View.dlbuf[xp]) ) continue;

            inten = (ColourDepth*(zi+ImageRadius))/ImageSize;
            WriteVectColour( ptr->col[i]+inten );
            fprintf(OutFile,"%g %g Dot\n",xi,yi);
        }
}

static void WriteVectMapPoints( void )
{
    register Real x,y,z;
    register Real xi,yi;
    register int inten;
    register int temp, tump;
    register int zi;
    register int i;
    register int xp;

    if( LineWidth != 1.0 )
    {   fputs("1 setlinewidth\n",OutFile);
        LineWidth = 1.0;
    }

    temp = SlabValue - ZOffset;
    tump = DepthValue - ZOffset;
    if (MapInfoPtr) {
      int imap;
      MapPointVec __far* MapPointsPtr;
      for (imap = 0; imap < MapInfoPtr->size; imap++) {
        MapInfo mapinfo;
        vector_get_element((GenericVec __far *)MapInfoPtr,(void __far *)&mapinfo,imap);
        MapPointsPtr = mapinfo.MapPointsPtr;
        if (MapPointsPtr) {
          for (i= 0; i < MapPointsPtr->size; i++) {
            x = (MapPointsPtr->array[i]).xpos;
            y = (MapPointsPtr->array[i]).xpos;
            z = (MapPointsPtr->array[i]).xpos;
        
            xi = (x*MatX[0]+y*MatX[1]+z*MatX[2]) + XOffset;
            if( (xi<0.0) || ((int)rint(xi)>=View.xmax) ) continue;
            yi = (x*MatY[0]+y*MatY[1]+z*MatY[2]) + YOffset;
            if( (yi<0.0) || ((int)rint(yi)>=View.ymax) ) continue;

            zi = (int)(x*MatZ[0]+y*MatZ[1]+z*MatZ[2]);
            xp = rint(xi);
            if( UseSlabPlane && (zi>=View.slbuf[xp]) ) continue;
            if( UseDepthPlane && (zi<=View.dlbuf[xp]) ) continue;

            inten = (ColourDepth*(zi+ImageRadius))/ImageSize;
            WriteVectColour( (MapPointsPtr->array[i]).col+inten );
            fprintf(OutFile,"%g %g Dot\n",xi,yi);
          }
        }
      }
    }
}

static void WriteVectMapBonds( void) {
	
}

static void WriteVectLabels( void )
{
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *aptr;
    register Label *label;
    auto unsigned char buffer[80];

    fputs("/Times-Roman",OutFile); /* Courier or Courier-Bold? */
    fprintf(OutFile," findfont %d scalefont setfont\n",FontSize<<1);

    if( UseLabelCol )
    {   if( BackR || BackG || BackB )
        {   fprintf(OutFile,"%g %g %g setrgbcolor\n",
                    LabR/250.0, LabG/250.0, LabB/250.0);
        } else fputs("0 setgray\n",OutFile);
    } else VectCol = 0;

    ForEachAtom
        if( aptr->label )
        {   if( !UseLabelCol && (aptr->col!=VectCol) )
                 WriteVectColour( aptr->col );

            label = (Label*)aptr->label;
            FormatLabel(chain,group,aptr,label->label,buffer);
            fprintf(OutFile,"(%s) %ld %ld Label\n",buffer,aptr->x,aptr->y);
        }
}


static void WriteVectMonitors( void )
{
    register RAtom __far *s;
    register RAtom __far *d;
    register Monitor *ptr;
    register int x,y,col;

    register char *cptr;
    register int dist;
    char buffer[10];
 
    buffer[9] = '\0';
    buffer[6] = '.';

    fputs("/Times-Roman",OutFile); /* Courier or Courier-Bold? */
    fprintf(OutFile," findfont %d scalefont setfont\n",FontSize<<1);

    for( ptr=MonitList; ptr; ptr=ptr->next )
    {   s = ptr->src;
        d = ptr->dst;

        if( ZBValid( (s->x+d->x)/2,(s->z+d->z)/2 ) )
        {   x = (s->x+d->x)/2;
            y = (s->y+d->y)/2;
 
            if( !UseLabelCol )
            {   /* Use Source atom colour! */
                if( ptr->col )
                {   col = ptr->col + (ColourMask>>1);
                } else col = s->col + (ColourMask>>1);
            } else col = LabelCol;
            WriteVectColour(col);
 
            dist = ptr->dist;
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
 
            fprintf(OutFile,"(%s) %d %d Label\n",cptr,x+4,y);
        }
    }
}


static Long CountPSItems( void )
{
    register Chain __far *chain;
    register Group __far *group;
    register HBond __far *hptr;
    register Bond __far *bptr;
    register RAtom __far *aptr;
    register Monitor *mptr;
    register Long result;

    result = 0;
    if( DrawAtoms || DrawStars)
        ForEachAtom 
            if( aptr->flag&(SphereFlag|StarFlag) ) 
                if( !UseClipping || !ClipVectSphere(aptr) )
                    result++;

    if( DrawBonds )
        ForEachBond 
            if( bptr->flag&DrawBondFlag && (!UseClipping ||
                !ClipVectBond(bptr->srcatom,bptr->dstatom)) )
                    result++;
    if( DrawRibbon)
	for(chain=Database->clist;chain;chain=chain->cnext)
		if(chain->glist)
			result++;	

    ForEachBack 
        if( bptr->flag&DrawBondFlag && (!UseClipping ||
            !ClipVectBond(bptr->srcatom,bptr->dstatom)) )
                result++;

    for( hptr=Database->hlist; hptr; hptr=hptr->hnext )
        if( hptr->flag&DrawBondFlag )
        {   if( HBondMode )
            {   if( !ClipVectBond(hptr->srcCA,hptr->dstCA) )
                    result++;
            } else if( !ClipVectBond(hptr->src,hptr->dst) )
                result++;
        }

    for( hptr=Database->slist; hptr; hptr=hptr->hnext )
        if( hptr->flag&DrawBondFlag )
        {   if( SSBondMode )
            {   if( !ClipVectBond(hptr->srcCA,hptr->dstCA) )
                    result++;
            } else if( !ClipVectBond(hptr->src,hptr->dst) )
                result++;
        }

    for( mptr=MonitList; mptr; mptr=mptr->next )
        if( !UseClipping || !ClipVectBond(mptr->src,mptr->dst) )
            result++;

    return result;
}


static void FetchPSItems( PSItemPtr __far *data, char __far *type )
{
    register Chain __far *chain;
    register Group __far *group;
    register HBond __far *hptr;
    register Bond __far *bptr;
    register RAtom __far *aptr;
    register Monitor *mptr;
    register int i,flag;


    i = 0;
    if( DrawAtoms || DrawStars )
        ForEachAtom
            if( aptr->flag&(SphereFlag | StarFlag) )
                if( !UseClipping || !ClipVectSphere(aptr) )
                {   type[i] = PSAtom; 
                    data[i++] = aptr;
                }

    if( DrawBonds )
        ForEachBond
            if( bptr->flag&DrawBondFlag && (!UseClipping ||
                !ClipVectBond(bptr->srcatom,bptr->dstatom)) )
            {   type[i] = PSBond;
                data[i++] = bptr;
            } 
	
    if( DrawRibbon )
    {
	for( chain = Database->clist; chain; chain=chain->cnext)
		if( chain->glist )
		{
			type[i]= PSRibbon;
			data[i++]= chain;
		}
    }
		

    ForEachBack
       if( bptr->flag&DrawBondFlag && (!UseClipping ||
           !ClipVectBond(bptr->srcatom,bptr->dstatom)) )
       {   type[i] = PSBond;
           data[i++] = bptr; 
       } 

    for( hptr=Database->hlist; hptr; hptr=hptr->hnext )
        if( hptr->flag&DrawBondFlag )
        {   if( HBondMode )
            {   flag = !ClipVectBond(hptr->srcCA,hptr->dstCA);
            } else flag = !ClipVectBond(hptr->src,hptr->dst);

            if( flag )
            {   type[i] = PSHBond;
                data[i++] = hptr;
            }
        }

    for( hptr=Database->slist; hptr; hptr=hptr->hnext )
        if( hptr->flag&DrawBondFlag )
        {   if( SSBondMode )
            {   flag = !ClipVectBond(hptr->srcCA,hptr->dstCA);
            } else flag = !ClipVectBond(hptr->src,hptr->dst);

            if( flag )
            {   type[i] = PSSSBond;
                data[i++] = hptr;
            }
        }

    for( mptr=MonitList; mptr; mptr=mptr->next )
        if( !UseClipping || !ClipVectBond(mptr->src,mptr->dst) )
        {   type[i] = PSMonit;
            data[i++] = mptr;
        } 
}




int WriteVectPSFile( char *name )
{
    register Real ambi;
    register Real temp, inten;
    register int xsize, ysize;
    register int xpos, ypos;
    register Long count;
    register int i;

    PSItemPtr __far *data;
    char __far *type;

    count = CountPSItems();
    if( !count ) return( True );

#ifdef IBMPC
    if( count > 16383 )
    {   InvalidateCmndLine();
        WriteString("Output Error: Too many PostScript objects!\n");
        return( False );
    }
#endif

    /* Allocate arrays for objects! */
    data = (PSItemPtr __far*)_fmalloc((size_t)count*sizeof(PSItemPtr));
    type = (char __far*)_fmalloc((size_t)count*sizeof(char));
    if( !data || !type )
    {   InvalidateCmndLine();
        WriteString("Output Error: Not enough memory to create PostScript!\n");

        if( data ) _ffree( data );
        if( type ) _ffree( type );
        return( False );
    }

    OutFile = fopen(name,"w");
    if( !OutFile )
    {   FatalOutputError(name);
        return(False);
    }

    /* Determine the size of the image */
    ysize = (int)(YRange*(BORDER*PAGEWIDE)/XRange);
    if( ysize > (int)(BORDER*PAGEHIGH) )
    {   xsize = (int)(XRange*(BORDER*PAGEHIGH)/YRange);
        ysize = (int)(BORDER*PAGEHIGH);
    } else xsize = (int)(BORDER*PAGEWIDE);

    xpos = (int)(PAGEWIDE-xsize)/2;
    ypos = (int)(PAGEHIGH-ysize)/2;

    fputs("%!PS-Adobe-2.0 EPSF-2.0\n",OutFile);
    fprintf(OutFile,"%%Creator: RasMol Version %s\n",VERSION);
    fprintf(OutFile,"%%%%Title: %s\n",name);
    fprintf(OutFile,"%%%%BoundingBox: %d %d ",xpos,ypos);
    fprintf(OutFile,"%d %d\n",xpos+xsize,ypos+ysize);

    fputs("%%Pages: 1\n",OutFile);
    fputs("%%EndComments\n",OutFile);
    fputs("%%EndProlog\n",OutFile);
    fputs("%%BeginSetup\n",OutFile);

    fputs("1 setlinecap 1 setlinejoin [] 0 setdash\n",OutFile);
    fputs("1 setlinewidth 0 setgray\n",OutFile);
    fputs("%%EndSetup\n",OutFile);
    fputs("%%Page: 1 1\n",OutFile);

    fputs("gsave\n",OutFile);
    fputs("14 dict begin\n\n",OutFile);
    fputs("/handleerror { showpage } def\n\n",OutFile);
    fputs("/Inten {\n  dup 4 index mul exch\n",OutFile);
    fputs("  dup 4 index mul exch\n",OutFile);
    fputs("  3 index mul setrgbcolor\n} def\n\n",OutFile);

    fputs("/Dot {\n  moveto 0 0 rlineto stroke\n} def\n\n",OutFile);
    fputs("/Wire {\n  moveto lineto stroke\n} def\n\n",OutFile);
#ifdef INVERT
    fputs("/Label {\n  moveto show\n} def\n\n",OutFile);
#else
    fputs("/Label {\n  moveto 1 -1 scale\n",OutFile);
    fputs("  show mtrx setmatrix\n} def\n\n",OutFile);
#endif

    if( UseOutLine )
    {   fputs("/Stick {\n  closepath gsave setrgbcolor fill\n",OutFile);
        fputs("  grestore 0 setgray stroke\n} def\n\n",OutFile);
    } else
        fputs("/Stick {\n  closepath setrgbcolor fill\n} def\n\n",OutFile);

    fputs("/StickEnd {\n  matrix currentmatrix 6 1 roll\n",OutFile);
    fputs("  translate rotate 1 scale\n",OutFile);
    fputs("  0 0 3 2 roll 90 -90 arc\n  setmatrix\n} def\n\n",OutFile);

    if( UseOutLine )
    {   fputs("/Shade {\n  closepath gsave clip\n",OutFile);
    } else fputs("/Shade {\n  closepath clip\n",OutFile);

    if( Ambient < 0.99 )
    {   ambi = 0.5*Ambient;
        fputs("  45 rotate dup -0.81649658092 mul scale\n",OutFile);
        fprintf(OutFile,"  %g Inten fill\n",ambi);
        inten = (1.0-ambi)/31;
        for( i=0; i<31; i++ )
        {   temp = (Real)(i+1)/32;
            fprintf(OutFile,"  0 %g ",(Real)i/32);
            fprintf(OutFile,"%g 0 360 arc ",sqrt(1.0-temp*temp));
            fprintf(OutFile,"%g Inten fill\n",i*inten+ambi);
        }
        if( UseOutLine )
        {   fputs("  grestore 0 setgray stroke",OutFile);
        } else fputc(' ',OutFile);
        fputs(" pop pop pop\n} def\n\n",OutFile);

    } else /* Saturated Colours! */
    {   fputs("  pop setrgbcolor fill\n",OutFile);
        if( UseOutLine )
            fputs("  grestore 0 setgray stroke\n",OutFile);
        fputs("} def\n\n",OutFile);
    }


    fputs("/ClipSphere {\n  translate 0 0 5 2 roll arc\n} def\n\n",OutFile);
    fputs("/ClipBox {\n  translate rotate\n  dup lineto dup neg ",OutFile);
    fputs("dup\n  0 rlineto 0 exch rlineto 0 rlineto closepath\n",OutFile);
    fputs("  clip newpath mtrx setmatrix\n} def\n\n",OutFile);
    fputs("/ClipEllips {\n  translate rotate 1 scale\n",OutFile);
    fputs("  0 0 4 2 roll dup neg arc\n",OutFile);
    fputs("  reversepath mtrx setmatrix\n} def\n\n",OutFile);

    fputs("/Sphere {\n  gsave\n",OutFile);
    fputs("  translate 0 0 2 index 0 360 arc\n",OutFile);
    if( UseOutLine )
    {   fputs("  gsave Shade grestore\n",OutFile);
        fputs("  0 setgray stroke\n",OutFile);
        fputs("  grestore\n} def\n\n",OutFile);
    } else
        fputs("  Shade grestore\n} def\n\n",OutFile);

#ifdef INVERT
    fprintf(OutFile,"%d %d translate\n",xpos,ypos);
    fprintf(OutFile,"%g ",(Real)xsize/XRange);
    fprintf(OutFile,"%g ",(Real)ysize/YRange);
#else
    fprintf(OutFile,"%d %d translate\n",xpos,ypos+ysize);
    fprintf(OutFile,"%g ",(Real)xsize/XRange);
    fprintf(OutFile,"%g ",(Real)-ysize/YRange);
#endif
    fputs("scale\n/mtrx matrix currentmatrix def\n\n",OutFile);

    fputs("newpath 0 0 moveto 0 ",OutFile);
    fprintf(OutFile,"%d rlineto %d 0 rlineto 0 %d",YRange,XRange,-YRange);
    fputs(" rlineto\nclosepath clip ",OutFile);
    if( BackR || BackG || BackB )
    {   fprintf(OutFile,"%g %g %g",BackR/255.0,BackG/255.0,BackB/255.0);
        fputs(" setrgbcolor fill\n\n",OutFile);
    } else fputs("newpath\n\n",OutFile);

    LineWidth = 1.0;
    VectSolid = True;
    VectCol = 0;

    FetchPSItems(data,type);
    if( count>1 )
        DepthSort(data,type,(int)count);

    WritePSItems(data,type,(int)count);
 
    if( !VectSolid )
    {   fputs("[] 0 setdash\n",OutFile);
        VectSolid = True;
    }

    if( DotPtr )
        WriteVectDots();
    if( MapInfoPtr)
        WriteVectMapPoints();
    if( DrawMonitDistance && MonitList )
        WriteVectMonitors();
    if( LabelList )
        WriteVectLabels();

    fputs("newpath 0 0 moveto 0 ",OutFile);
    fprintf(OutFile,"%d rlineto %d 0 rlineto 0 %d",YRange,XRange,-YRange);
    fputs(" rlineto\nclosepath 0 setgray 1 setlinewidth stroke\n",OutFile);
    fputs("end grestore\nshowpage\n",OutFile);
    fputs("%%Trailer\n",OutFile);
    fputs("%%EOF\n",OutFile);

    fclose( OutFile );
#ifdef APPLEMAC
    /* Avoid ANSI trigraph problems! */
    SetFileInfo(name,'vgrd','TEXT',134);
#endif
    _ffree( data );
    _ffree( type );
    return(True);
}

static void WritePSItems( PSItemPtr __far *data, char __far *type, int count )
{
    register Monitor __far *monit;
    register HBond __far *hbond;
    register Bond __far *bond;
    register RAtom __far *src;
    register RAtom __far *dst;
    register int i;

    for( i=0; i<count; i++ )
        switch( type[i] )
        {   case(PSAtom):   WriteVectSphere(data,type,i);
                            break;

            case(PSBond):   bond = (Bond __far*)data[i];
                            src = bond->srcatom;
                            dst = bond->dstatom;

                            if( bond->flag & WireFlag )
                            {   WriteVectWire(src,dst,bond->col,False);
                            } else if( bond->flag & CylinderFlag )
                            {   WriteVectStick(src,dst,bond->col,bond->radius);
                            } else /* bond->flag & DashFlag */
                                WriteVectWire(src,dst,bond->col,True);
                            break;

            case(PSSSBond): 
            case(PSHBond):  hbond = (HBond __far*)data[i];
                            if( (type[i]==PSHBond)? HBondMode : SSBondMode )
                            {   src = hbond->srcCA;
                                dst = hbond->dstCA;
                            } else
                            {   src = hbond->src;
                                dst = hbond->dst;
                            }

                            if( hbond->flag & WireFlag )
                            {   WriteVectWire(src,dst,hbond->col,True);
                            } else /* bond->flag & CylinderFlag */
                                WriteVectStick(src,dst,hbond->col,
                                                       hbond->radius);
                            break;

            case(PSMonit):  monit = (Monitor __far*)data[i];
                            WriteVectWire(monit->src,monit->dst,
                                          monit->col,True);
                            break;
        }
}



/****************************************************************************/
/*                           Writing a Raster3D file                        */
/****************************************************************************/

#define R3Dcoord(xorg,yorg,zorg,xtemp,ytemp,ztemp,xnew,ynew,znew) {\
		xtemp= (Real)((xorg) - CenX) ; \
		ytemp= (Real)((yorg) - CenY) ; \
		ztemp= (Real)((zorg) - CenZ) ; \
		xnew =        ((xtemp)*MatX[0] + (ytemp)*MatX[1] + (ztemp)*MatX[2] + ((Real)(XOffset-XRange/2)))/(Real)(scale); \
		ynew = InvertY((xtemp)*MatY[0] + (ytemp)*MatY[1] + (ztemp)*MatY[2] + ((Real)(YOffset-YRange/2)))/(Real)(scale); \
		znew =        ((xtemp)*MatZ[0] + (ytemp)*MatZ[1] + (ztemp)*MatZ[2] + ((Real)(ZOffset-ZRange/2)))/(Real)(scale); }

#define R3DcoordC(xorgC,yorgC,zorgC,xnew,ynew,znew) {\
		xnew =        ((xorgC)*MatX[0] + (yorgC)*MatX[1] + (zorgC)*MatX[2] + ((Real)(XOffset-XRange/2)))/(Real)(scale); \
		ynew = InvertY((xorgC)*MatY[0] + (yorgC)*MatY[1] + (zorgC)*MatY[2] + ((Real)(YOffset-YRange/2)))/(Real)(scale); \
		znew =        ((xorgC)*MatZ[0] + (yorgC)*MatZ[1] + (zorgC)*MatZ[2] + ((Real)(ZOffset-ZRange/2)))/(Real)(scale); }
 	

static void WriteR3DSphere( PSItemPtr __far *data, char __far *type, 
                             int index, int scale)
{
	register RAtom __far *ptr;
	register Real x, y, z;			/* coordinates after rotation and translation */
	register Real x_sc, y_sc, z_sc;		/* coordinates scaled from Rasmol to Raster3d */
	register Real rad;
	register ShadeDesc *shade;


	ptr = (RAtom __far*)data[index];
	
	R3Dcoord(ptr->xorg+ptr->fxorg,ptr->yorg+ptr->fyorg,ptr->zorg+ptr->fzorg,x_sc,y_sc,z_sc,x,y,z);

	rad =  Scale*(Real)(ptr->radius)/scale;

	/*i = ptr->col + ColourMask;*/
	shade = Shade + Colour2Shade(ptr->col);

	fprintf(OutFile,"2 \n");
	fprintf(OutFile,"%.5f %.5f %.5f %.5f ", x, y, z, rad);
	fprintf(OutFile,"%g %g %g\n",(Real)(shade->r)/255.0,
			   (Real)(shade->g)/255.0 ,(Real)(shade->b)/255.0);
}

static void R3DSphere( int x, int y, int z, int radius, int col, int scale)
{
	register Real x1, y1, z1;			/* coordinates after rotation and translation*/
	register Real x_sc, y_sc, z_sc;		/* coordinates scaled from Rasmol to Raster3d*/
	register Real rad;
	register ShadeDesc *shade;


	R3Dcoord(x,y,z,x_sc,y_sc,z_sc,x1,y1,z1);

	rad =  Scale*(Real)(radius)/scale;

	/*i = col + ColourMask;*/
	shade = Shade + Colour2Shade(col);

	fprintf(OutFile,"2 \n");
	fprintf(OutFile,"%.5f %.5f %.5f %.5f ", (double)x, (double)y, (double)z, rad);
	fprintf(OutFile,"%g %g %g\n", 
	    (double) (shade->r)/255.0,
	    (double) (shade->g)/255.0, 
	    (double) (shade->b)/255.0);
}

static void R3DCylinder( int x1, int y1, int z1, int x2, int y2, int z2, int col, int scale )
{

	register Real src_x_sc, src_y_sc, src_z_sc;
	register Real dst_x_sc, dst_y_sc, dst_z_sc;
	register Real src_x, src_y, src_z;
	register Real dst_x, dst_y, dst_z, bond_rad;
	register ShadeDesc *shade;
	
	R3Dcoord(x1,y1,z1,src_x_sc,src_y_sc,src_z_sc,src_x,src_y,src_z);
	R3Dcoord(x2,y2,z2,dst_x_sc,dst_y_sc,dst_z_sc,dst_x,dst_y,dst_z);

	bond_rad = 0.01;

	/*i = col + ColourMask;*/
	shade = Shade + Colour2Shade(col);

	fprintf(OutFile,"3 \n");
        fprintf(OutFile,"%.5f %.5f %.5f %.5f %.5f %.5f %.5f 0.00 "
					,src_x, src_y, src_z, bond_rad, dst_x, dst_y, dst_z);
	fprintf(OutFile,"%g %g %g\n",(Real)(shade->r)/255.0, (Real)(shade->g)/255.0, (Real)(shade->b)/255.0);
}

static void WriteR3DStick( RAtom __far *src, RAtom __far *dst, 
                            int col, int rad, int scale )
{

	register int col1, col2;

	register Real src_x_sc, src_y_sc, src_z_sc;
	register Real dst_x_sc, dst_y_sc, dst_z_sc;
	register Real src_x, src_y, src_z;
	register Real dst_x, dst_y, dst_z, bond_rad;
	register Real mid_x, mid_y, mid_z;
	register ShadeDesc *shade;
 
	
	R3Dcoord(src->xorg + src->fxorg,src->yorg + src->fyorg,src->zorg + src->fzorg,src_x_sc,src_y_sc,src_z_sc,src_x,src_y,src_z);
	R3Dcoord(dst->xorg + dst->fxorg,dst->yorg + dst->fyorg,dst->zorg + dst->fzorg,dst_x_sc,dst_y_sc,dst_z_sc,dst_x,dst_y,dst_z);


	bond_rad = Scale*(Real)(rad)/scale;



	if( !rad )
	{
		WriteR3DStick(src,dst,col,10,scale);
	        return;
	}

	if( !col )
    	{
		mid_x=(src_x+dst_x)/2;
		mid_y=(src_y+dst_y)/2;
		mid_z=(src_z+dst_z)/2;

		col1 = src->col;
	        col2 = dst->col;

	        /*i = col1 + ColourMask;*/
			shade = Shade + Colour2Shade(col1);

		fprintf(OutFile,"3 \n");
	  	fprintf(OutFile,"%.5f %.5f %.5f %.5f %.5f %.5f %.5f 0.00 "
							,src_x,src_y,src_z,bond_rad,mid_x,mid_y,mid_z);
	        fprintf(OutFile,"%g ",(Real)(shade->r)/255.0);
	        fprintf(OutFile,"%g ",(Real)(shade->g)/255.0);
	        fprintf(OutFile,"%g \n",(Real)(shade->b)/255.0);

        	/* i = col2 + ColourMask; */
			shade = Shade + Colour2Shade(col2);

		fprintf(OutFile,"3 \n");
        	fprintf(OutFile,"%.5f %.5f %.5f %.5f %.5f %.5f %.5f 0.00 "
							,mid_x,mid_y,mid_z,bond_rad,dst_x,dst_y,dst_z);
	        fprintf(OutFile,"%g ",(Real)(shade->r)/255.0);
        	fprintf(OutFile,"%g ",(Real)(shade->g)/255.0);
	        fprintf(OutFile,"%g \n",(Real)(shade->b)/255.0);
	}
	else
	{
	 	/* i = col + ColourMask; */
	    shade = Shade + Colour2Shade(col);

		fprintf(OutFile,"3 \n");
        	fprintf(OutFile,"%.5f %.5f %.5f %.5f %.5f %.5f %.5f 0.00 "
							,src_x,src_y,src_z,bond_rad,dst_x,dst_y,dst_z);
	        fprintf(OutFile,"%g ",(Real)(shade->r)/255.0);
        	fprintf(OutFile,"%g ",(Real)(shade->g)/255.0);
	        fprintf(OutFile,"%g \n",(Real)(shade->b)/255.0);
	}
}

static void WriteR3DMonitor( Monitor __far* monit, int rad, int scale )
{

	RAtom __far *src;
	RAtom __far *dst;

	register int col,col1, col2;
	register int num_of_dots,j;
	register Real length, dot_length;

	register Real src_x_sc, src_y_sc, src_z_sc;
	register Real dst_x_sc, dst_y_sc, dst_z_sc;
	register Real x_incr, y_incr, z_incr;
	register Real src_x, src_y, src_z;
	register Real dst_x, dst_y, dst_z, bond_rad;
	register Real mid_x, mid_y, mid_z;
	register Real tmp_x, tmp_y, tmp_z;
	register Real mid_xdist, mid_ydist, mid_zdist;
	register Real mid_x_sc, mid_y_sc, mid_z_sc;
	register Real distance;
	static unsigned char name[22];
	int units=128;
	register ShadeDesc *shade;
	

	src = monit->src;
	dst = monit->dst;
        col = monit->col;	
 	distance =(Real)monit->dist/100;

	R3Dcoord(src->xorg + src->fxorg,src->yorg + src->fyorg,src->zorg + src->fzorg,src_x_sc,src_y_sc,src_z_sc,src_x,src_y,src_z);
	R3Dcoord(dst->xorg + dst->fxorg,dst->yorg + dst->fyorg,dst->zorg + dst->fzorg,dst_x_sc,dst_y_sc,dst_z_sc,dst_x,dst_y,dst_z);
	
	bond_rad = Scale*(Real)(rad)/scale;
	dot_length = 0.01;

	
	if(!rad )
	{
		WriteR3DMonitor(monit,10,scale);
	        return;
	}

	if(!col)
	{
		col1 = src->col;
		col2 = dst->col;
	}
	else
		col1=col2=col;


	length=sqrt((src_x-dst_x)*(src_x-dst_x) + (src_y-dst_y)*(src_y-dst_y)+
						 (src_z-dst_z)*(src_z-dst_z));
	
	x_incr=dot_length*(dst_x-src_x)/length;
	y_incr=dot_length*(dst_y-src_y)/length;
	z_incr=dot_length*(dst_z-src_z)/length;

	mid_x=(src_x+dst_x)/2;
	mid_y=(src_y+dst_y)/2;
	mid_z=(src_z+dst_z)/2;

	tmp_x=mid_x+x_incr/2;
	tmp_y=mid_y+y_incr/2;
	tmp_z=mid_z+z_incr/2;
	num_of_dots=length/dot_length;

	for(j=0;j<num_of_dots/4;j++)
	{
	 	/* i = col2 + ColourMask; */
		shade = Shade + Colour2Shade(col2);


		fprintf(OutFile,"3 \n");
        	fprintf(OutFile,"%.5f %.5f %.5f %.5f %.5f %.5f %.5f 0.00 "
			,tmp_x,tmp_y,tmp_z,bond_rad,(tmp_x+x_incr),(tmp_y+y_incr),(tmp_z+z_incr));
	        fprintf(OutFile,"%g ",(Real)(shade->r)/255.0);
        	fprintf(OutFile,"%g ",(Real)(shade->g)/255.0);
	        fprintf(OutFile,"%g \n",(Real)(shade->b)/255.0);

		tmp_x=tmp_x+ 2*x_incr;	
		tmp_y=tmp_y+ 2*y_incr;
		tmp_z=tmp_z+ 2*z_incr;
		
	}

	tmp_x=mid_x-x_incr/2;
	tmp_y=mid_y-y_incr/2;
	tmp_z=mid_z-z_incr/2;

	for(j=0;j<num_of_dots/4;j++)
	{
	 	/* i = col1 + ColourMask;*/
		shade = Shade + Colour2Shade(col1);

		fprintf(OutFile,"3 \n");
        	fprintf(OutFile,"%.5f %.5f %.5f %.5f %.5f %.5f %.5f 0.00 "
			,tmp_x,tmp_y,tmp_z,bond_rad,(tmp_x-x_incr),(tmp_y-y_incr),(tmp_z-z_incr));
	        fprintf(OutFile,"%g ",(Real)(shade->r)/255.0);
        	fprintf(OutFile,"%g ",(Real)(shade->g)/255.0);
	        fprintf(OutFile,"%g \n",(Real)(shade->b)/255.0);

		tmp_x=tmp_x-2*x_incr;	
		tmp_y=tmp_y-2*y_incr;
		tmp_z=tmp_z-2*z_incr;
		
	}

	if(DrawMonitDistance)
	{
		if(monit-> monmode == PickDist)
			units=127;
		else if(monit-> monmode == PickAngle)
			units=128;
		if(monit-> monmode == PickTorsn)
			units=128;

		sprintf((char *)name,"%.2f%c",distance,units);
		
		R3Dcoord((src->xorg + src->fxorg + dst->xorg + dst->fxorg)/2,(src->yorg + src->fyorg + dst->yorg + dst->fyorg)/2,(src->zorg + src->fzorg + dst->zorg + dst->fzorg)/2,mid_x_sc,mid_y_sc,mid_z_sc,mid_xdist,mid_ydist,mid_zdist);


		OutputR3DFontString(mid_xdist,mid_ydist,mid_zdist,name,col1,scale);
	}

}

static void WriteR3DLabels(int scale)
{
	register Chain __far *chain;
	register Group __far *group;
	register RAtom __far *aptr;
	register Label *label;
	register Real lab_x, lab_y, lab_z;
	register Real x_sc, y_sc, z_sc;
	auto unsigned char buffer[80];
	static unsigned char name[22];


/*    if( UseLabelCol )
    {   if( BackR || BackG || BackB )
        {   fprintf(OutFile,"%g %g %g setrgbcolor\n",
                    LabR/250.0, LabG/250.0, LabB/250.0);
        } else fputs("0 setgray\n",OutFile);
    } else VectCol = 0;
*/
	ForEachAtom
		if( aptr->label )
		{
/*			if( !UseLabelCol && (aptr->col!=VectCol) )*/
/*				WriteVectColour( aptr->col );*/

			label = (Label*)aptr->label;
			FormatLabel(chain,group,aptr,label->label,buffer);
			sprintf((char *)name,"%s",buffer);

	        R3Dcoord(aptr->xorg + aptr->fxorg,aptr->yorg + aptr->fyorg,aptr->zorg + aptr->fzorg,x_sc,y_sc,z_sc,lab_x,lab_y,lab_z);
	
			OutputR3DFontString(lab_x, lab_y, lab_z,name,aptr->col,scale);
		}
}

static void OutputR3DCharacter( Real x, Real y, Real z, int glyph, int col,Real scale, Real r3d_font_scale)
{
	register char *ptr;
	register Real sx,sy;
	register Real ex,ey;
	register Real out_x1, out_y1, out_z, out_x2, out_y2;
	register ShadeDesc *shade;
	
	ex = x; ey = y;

	/*i = col + ColourMask;*/
	shade = Shade + Colour2Shade(col);
	ptr = VectFont[glyph];

	while( *ptr )
	{
		/* Uppercase test */
	        if( ptr[0] < 'a' )
        	{ 
			sx = x + r3d_font_scale*FontDimen[ptr[0]-'A'];
			sy = y + InvertY(r3d_font_scale*FontDimen[ptr[1]-'a']);
	        	ptr += 2;
		}
		else
        	{	
			sx = ex;
	  		sy = ey;
	        }
		
	        ex = x + r3d_font_scale*FontDimen[ptr[0]-'a'];
	        ey = y + InvertY(r3d_font_scale*FontDimen[ptr[1]-'a']);

		out_x1 =  sx;	
		out_x2 =  ex;	
		out_y1 = InvertY(sy);
		out_y2 = InvertY(ey);
		out_z  = 1.36;

		fprintf(OutFile,"3 \n");

	        if (FontStroke < 1 )
	        	fprintf(OutFile,"%.5f %.5f %.5f 0.001 %.5f %.5f %.5f 0.00 "
						,out_x1,out_y1,out_z,out_x2,out_y2,out_z);
		else
	        	fprintf(OutFile,"%.5f %.5f %.5f %.5f %.5f %.5f %.5f 0.00 "
						,out_x1,out_y1,out_z,FontStroke*0.002,out_x2,out_y2,out_z);
	
	        fprintf(OutFile,"%g ",(Real)(shade->r)/255.0);
        	fprintf(OutFile,"%g ",(Real)(shade->g)/255.0);
	        fprintf(OutFile,"%g \n",(Real)(shade->b)/255.0);

        	ptr += 2;
	}
}

void OutputR3DFontString( Real x, Real y, Real z, unsigned char *label, int col, Real scale )
{
	register Real r3d_font_scale =0.0015;

	while( *label )
        {
		OutputR3DCharacter(x,y,z,(*label-32),col,scale,r3d_font_scale);
        	x += r3d_font_scale * FontWid[(*label-32)]+ r3d_font_scale * FontStroke;
	       	label++;
        }
}

/*==============================*/
/*  Ribbon & Cartoon Functions  */
/*==============================*/
 
/* SplineCount is either 1, 2, 3, 4, 5 or 9! */

void R3DStrandRibbon( Knot __far *src, Knot __far *dst, int col1, int col2, Real scale )
{
    register int hsx, hsy, hsz;
    register int hdx, hdy, hdz;
    register int qsx, qsy, qsz;
    register int qdx, qdy, qdz;
    register int col;

    register Real x1, y1, z1;
    register Real x2, y2, z2;
    register Real src_x, src_y, src_z;
    register Real dst_x, dst_y, dst_z;
    register Real bond_rad;
	register ShadeDesc *shade;
	
    bond_rad=0.003; 

    if( SplineCount != 4 )
    {   if( SplineCount == 1 ) 
        {	
		R3Dcoord(src->px,src->py,src->pz,x1,y1,z1,src_x,src_y,src_z);
		R3Dcoord(dst->px,dst->py,dst->pz,x2,y2,z2,dst_x,dst_y,dst_z);
 	
		/* i = col2 + ColourMask; */
		shade = Shade + Colour2Shade(col2);

		fprintf(OutFile,"3 \n");
        	fprintf(OutFile,"%.5f %.5f %.5f %.5f %.5f %.5f %.5f 0.00 "
					, src_x, src_y, src_z, bond_rad, dst_x, dst_y, dst_z);
	        fprintf(OutFile,"%g %g %g\n", (Real)(shade->r)/255.0, (Real)(shade->g)/255.0, (Real)(shade->b)/255.0);

            	return;

        }
	else if( SplineCount != 2 )
	{

		R3Dcoord(src->px,src->py,src->pz,x1,y1,z1,src_x,src_y,src_z);
		R3Dcoord(dst->px,dst->py,dst->pz,x2,y2,z2,dst_x,dst_y,dst_z);

	 	/* i = col1 + ColourMask; */
		shade = Shade + Colour2Shade(col1);

		fprintf(OutFile,"3 \n");
        	fprintf(OutFile,"%.5f %.5f %.5f %.5f %.5f %.5f %.5f 0.00 "
						, src_x, src_y, src_z, bond_rad, dst_x, dst_y, dst_z);
	        fprintf(OutFile,"%g %g %g\n", (Real)(shade->r)/255.0, (Real)(shade->g)/255.0, (Real)(shade->b)/255.0);
	}

		R3Dcoord(src->px + src->wx,src->py  + src->wy,src->pz + src->wz,x1,y1,z1,src_x,src_y,src_z);
		R3Dcoord(dst->px + dst->wx,dst->py  + dst->wy,dst->pz + dst->wz,x2,y2,z2,dst_x,dst_y,dst_z);


	 	/* i = col2 + ColourMask; */
		shade = Shade + Colour2Shade(col2);

		fprintf(OutFile,"3 \n");
        	fprintf(OutFile,"%.5f %.5f %.5f %.5f %.5f %.5f %.5f 0.00 "
						, src_x, src_y, src_z, bond_rad, dst_x, dst_y, dst_z);
	        fprintf(OutFile,"%g %g %g\n", (Real)(shade->r)/255.0, (Real)(shade->g)/255.0, (Real)(shade->b)/255.0);


		R3Dcoord(src->px  - src->wx,src->py - src->wy,src->pz - src->wz,x1,y1,z1,src_x,src_y,src_z);
		R3Dcoord(dst->px  - dst->wx,dst->py - dst->wy,dst->pz - dst->wz,x2,y2,z2,dst_x,dst_y,dst_z);

	 	/* i = col2 + ColourMask; */
		shade = Shade + Colour2Shade(col2);

		fprintf(OutFile,"3 \n");
        	fprintf(OutFile,"%.5f %.5f %.5f %.5f %.5f %.5f %.5f 0.00 "
						, src_x, src_y, src_z, bond_rad, dst_x, dst_y, dst_z);
	        fprintf(OutFile,"%g %g %g\n", (Real)(shade->r)/255.0, (Real)(shade->g)/255.0, (Real)(shade->b)/255.0);


        if( SplineCount<=3 ) return;

        hsx = src->wx/2;  hsy = src->wy/2;  hsz = src->wz/2;
        hdx = dst->wx/2;  hdy = dst->wy/2;  hdz = dst->wz/2;
	
		R3Dcoord(src->px  + hsx,src->py + hsy,src->pz + hsz,x1,y1,z1,src_x,src_y,src_z);
		R3Dcoord(dst->px  + hdx,dst->py + hdy,dst->pz + hdz,x2,y2,z2,dst_x,dst_y,dst_z);


	 	/* i = col1 + ColourMask; */
		shade = Shade + Colour2Shade(col1);

		fprintf(OutFile,"3 \n");
        	fprintf(OutFile,"%.5f %.5f %.5f %.5f %.5f %.5f %.5f 0.00 "
						, src_x, src_y, src_z, bond_rad, dst_x, dst_y, dst_z);
	        fprintf(OutFile,"%g %g %g\n", (Real)(shade->r)/255.0, (Real)(shade->g)/255.0, (Real)(shade->b)/255.0);
	
		R3Dcoord(src->px  - hsx,src->py - hsy,src->pz - hsz,x1,y1,z1,src_x,src_y,src_z);
		R3Dcoord(dst->px  - hdx,dst->py - hdy,dst->pz - hdz,x2,y2,z2,dst_x,dst_y,dst_z);

	 	/* i = col1 + ColourMask; */
		shade = Shade + Colour2Shade(col1);

		fprintf(OutFile,"3 \n");
        	fprintf(OutFile,"%.5f %.5f %.5f %.5f %.5f %.5f %.5f 0.00 "
						, src_x, src_y, src_z, bond_rad, dst_x, dst_y, dst_z);
	        fprintf(OutFile,"%g %g %g\n", (Real)(shade->r)/255.0, (Real)(shade->g)/255.0, (Real)(shade->b)/255.0);


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

	R3Dcoord(src->px  + hsx + qsx,src->py + hsy + qsy,src->pz + hsz + qsy,x1,y1,z1,src_x,src_y,src_z);
	R3Dcoord(dst->px  + hdx + qdx,dst->py + hdy + qdy,dst->pz + hdz + qdz,x2,y2,z2,dst_x,dst_y,dst_z);


    /* i = col + ColourMask; */
	shade = Shade + Colour2Shade(col);

    fprintf(OutFile,"3 \n");
    fprintf(OutFile,"%.5f %.5f %.5f %.5f %.5f %.5f %.5f 0.00 "
    			, src_x, src_y, src_z, bond_rad, dst_x, dst_y, dst_z);
    fprintf(OutFile,"%g %g %g\n", (Real)(shade->r)/255.0, (Real)(shade->g)/255.0, (Real)(shade->b)/255.0);

	R3Dcoord(src->px  + hsx - qsx,src->py + hsy - qsy,src->pz + hsz - qsy,x1,y1,z1,src_x,src_y,src_z);
	R3Dcoord(dst->px  + hdx - qdx,dst->py + hdy - qdy,dst->pz + hdz - qdz,x2,y2,z2,dst_x,dst_y,dst_z);

    /* i = col1 + ColourMask; */
	shade = Shade + Colour2Shade(col1);

    fprintf(OutFile,"3 \n");
    fprintf(OutFile,"%.5f %.5f %.5f %.5f %.5f %.5f %.5f 0.00 "
			, src_x, src_y, src_z, bond_rad, dst_x, dst_y, dst_z);
    fprintf(OutFile,"%g %g %g\n", (Real)(shade->r)/255.0, (Real)(shade->g)/255.0, (Real)(shade->b)/255.0);	
	
	R3Dcoord(src->px  - hsx + qsx,src->py - hsy + qsy,src->pz - hsz + qsy,x1,y1,z1,src_x,src_y,src_z);
	R3Dcoord(dst->px  - hdx + qdx,dst->py - hdy + qdy,dst->pz - hdz + qdz,x2,y2,z2,dst_x,dst_y,dst_z);


    /* i = col1 + ColourMask; */
	shade = Shade + Colour2Shade(col1);

    fprintf(OutFile,"3 \n");
    fprintf(OutFile,"%.5f %.5f %.5f %.5f %.5f %.5f %.5f 0.00 "
			, src_x, src_y, src_z, bond_rad, dst_x, dst_y, dst_z);
    fprintf(OutFile,"%g %g %g\n", (Real)(shade->r)/255.0, (Real)(shade->g)/255.0, (Real)(shade->b)/255.0);

	R3Dcoord(src->px  - hsx - qsx,src->py - hsy - qsy,src->pz - hsz - qsy,x1,y1,z1,src_x,src_y,src_z);
	R3Dcoord(dst->px  - hdx - qdx,dst->py - hdy - qdy,dst->pz - hdz - qdz,x2,y2,z2,dst_x,dst_y,dst_z);


    /* i = col + ColourMask; */
	shade = Shade + Colour2Shade(col);

    fprintf(OutFile,"3 \n");
    fprintf(OutFile,"%.5f %.5f %.5f %.5f %.5f %.5f %.5f 0.00 "
			, src_x, src_y, src_z, bond_rad, dst_x, dst_y, dst_z);
    fprintf(OutFile,"%g %g %g\n", (Real)(shade->r)/255.0, (Real)(shade->g)/255.0, (Real)(shade->b)/255.0);
}


/*
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
    ClipPolygon( &p );
}
*/

/*void normals(Real p1_x, Real p1_y, Real p1_z, Real p2_x, Real p2_y, Real p2_z,
	     Real p3_x, Real p3_y, Real p3_z, Real $res_x, Real $res_y, Real $res_z)

{

    vect1_x = p1_x - p2_x;
    vect1_y = p1_y - p2_y;
    vect1_z = p1_z - p2_z;

    vect2_x = p1_x - p3_x;
    vect2_y = p1_y - p3_y;
    vect2_z = p1_z - p3_z;

    nor1_x= vect1_y*vect2_z - vect1_z*vect2_y;
    nor1_y= vect1_z*vect2_x - vect1_x*vect2_z;
    nor1_z= vect1_x*vect2_y - vect1_y*vect2_x;

    if( (vect1_x*vect2_x + vect1_y*vect2_y + vect1_z*vect2_z) < 0 )
    {
	nor1_x = - nor1_x;
	nor1_y = - nor1_y;
	nor1_z = - nor1_z;

    }
}*/


#ifdef UNUSED
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

#endif

void Cartoon_ribdata( Knot __far *src, Knot __far *dst, R3DRib __far** front, R3DRib __far** back, 
				R3DRib __far** side1, R3DRib __far** side2, int col, Real scale)
{
    Real x1, x2, x3, x4;
    Real y1, y2, y3, y4;
    Real z1, z2, z3, z4;

/* top surface*/
    x1= src->px + src->wx + src->dx;
    y1= src->py + src->wy + src->dy;	
    z1= src->pz + src->wz + src->dz;

    x2= dst->px + dst->wx + dst->dx;	
    y2= dst->py + dst->wy + dst->dy;	
    z2= dst->pz + dst->wz + dst->dz;

    x3= dst->px - dst->wx + dst->dx;	
    y3= dst->py - dst->wy + dst->dy;	
    z3= dst->pz - dst->wz + dst->dz;

    x4= src->px - src->wx + src->dx;
    y4= src->py - src->wy + src->dy;	
    z4= src->pz - src->wz + src->dz;

    *front = Add_ribdata(x1, y1, z1, x4, y4, z4, x2, y2, z2,*front, col, scale); 
    *front = Add_ribdata(x4, y4, z4, x2, y2, z2, x3, y3, z3,*front, col, scale); 

/* bottom surface*/
    x1= src->px + src->wx - src->dx;
    y1= src->py + src->wy - src->dy;	
    z1= src->pz + src->wz - src->dz;

    x2= dst->px + dst->wx - dst->dx;	
    y2= dst->py + dst->wy - dst->dy;	
    z2= dst->pz + dst->wz - dst->dz;

    x3= dst->px - dst->wx - dst->dx;	
    y3= dst->py - dst->wy - dst->dy;	
    z3= dst->pz - dst->wz - dst->dz;

    x4= src->px - src->wx - src->dx;
    y4= src->py - src->wy - src->dy;	
    z4= src->pz - src->wz - src->dz;

    *back = Add_ribdata(x1, y1, z1, x4, y4, z4, x2, y2, z2,*back, col, scale); 
    *back = Add_ribdata(x4, y4, z4, x2, y2, z2, x3, y3, z3,*back, col, scale); 

/*side1*/
    x1 = src->px + src->wx + src->dx;  
    y1 = src->py + src->wy + src->dy;  
    z1 = src->pz + src->wz + src->dz;

    x2 = dst->px + dst->wx + dst->dx;  
    y2 = dst->py + dst->wy + dst->dy;  
    z2 = dst->pz + dst->wz + dst->dz;

    x3 = dst->px + dst->wx - dst->dx;
    y3 = dst->py + dst->wy - dst->dy;  
    z3 = dst->pz + dst->wz - dst->dz;

    x4 = src->px + src->wx - src->dx;  
    y4 = src->py + src->wy - src->dy;  
    z4 = src->pz + src->wz - src->dz;

    *side1 = Add_ribdata(x1, y1, z1, x4, y4, z4, x2, y2, z2,*side1, col, scale); 
    *side1 = Add_ribdata(x4, y4, z4, x2, y2, z2, x3, y3, z3,*side1, col, scale); 

/*side2*/

    x1 = src->px - src->wx + src->dx;  
    y1 = src->py - src->wy + src->dy;  
    z1 = src->pz - src->wz + src->dz;

    x2 = dst->px - dst->wx + dst->dx;  
    y2 = dst->py - dst->wy + dst->dy;  
    z2 = dst->pz - dst->wz + dst->dz;

    x3 = dst->px - dst->wx - dst->dx;
    y3 = dst->py - dst->wy - dst->dy;  
    z3 = dst->pz - dst->wz - dst->dz;

    x4 = src->px - src->wx - src->dx;  
    y4 = src->py - src->wy - src->dy;  
    z4 = src->pz - src->wz - src->dz;

    *side2 = Add_ribdata(x1, y1, z1, x4, y4, z4, x2, y2, z2,*side2, col, scale); 
    *side2 = Add_ribdata(x4, y4, z4, x2, y2, z2, x3, y3, z3,*side2, col, scale); 
}

R3DRib __far * Poly_ribdata( Knot __far *src, Knot __far *dst, R3DRib __far* curdata, int col, Real scale)
{
    Real x1, x2, x3, x4;
    Real y1, y2, y3, y4;
    Real z1, z2, z3, z4;

    x1= src->px + src->wx;
    y1= src->py + src->wy;	
    z1= src->pz + src->wz;

    x2= dst->px + dst->wx;	
    y2= dst->py + dst->wy;	
    z2= dst->pz + dst->wz;

    x3= dst->px - dst->wx;	
    y3= dst->py - dst->wy;	
    z3= dst->pz - dst->wz;

    x4= src->px - src->wx;
    y4= src->py - src->wy;	
    z4= src->pz - src->wz;

    curdata = Add_ribdata(x1, y1, z1, x4, y4, z4, x2, y2, z2, curdata, col, scale); 
    curdata = Add_ribdata(x4, y4, z4, x2, y2, z2, x3, y3, z3, curdata, col, scale); 
    return curdata;
}

R3DRib __far *Add_ribdata( Real in_x1, Real in_y1, Real in_z1, Real in_x2, Real in_y2, Real in_z2,
			    Real in_x3, Real in_y3, Real in_z3, R3DRib __far* curdata,int col, Real scale)
{
    Real n1_x, n1_y, n1_z;
    Real vect1_x, vect1_y, vect1_z; 
    Real vect2_x, vect2_y, vect2_z; 

    R3DRib __far *xtemp;
    xtemp = (R3DRib __far *)_fmalloc(sizeof(R3DRib));

    R3DcoordC((Real)(in_x1),(Real)(in_y1),(Real)(in_z1),xtemp->x1,xtemp->y1,xtemp->z1);
    R3DcoordC((Real)(in_x2),(Real)(in_y2),(Real)(in_z2),xtemp->x2,xtemp->y2,xtemp->z2);
    R3DcoordC((Real)(in_x3),(Real)(in_y3),(Real)(in_z3),xtemp->x3,xtemp->y3,xtemp->z3);
	
    /* xtemp->x1= Scale*(Real)(in_x1)/scale;
    xtemp->y1= InvertY(Scale*(Real)(in_y1)/scale);	
    xtemp->z1= Scale*(Real)(in_z1)/scale;

    xtemp->x2= Scale*(Real)(in_x2)/scale;	
    xtemp->y2= InvertY(Scale*(Real)(in_y2)/scale);	
    xtemp->z2= Scale*(Real)(in_z2)/scale;

    xtemp->x3= Scale*(Real)(in_x3)/scale;	
    xtemp->y3= InvertY(Scale*(Real)(in_y3)/scale);	
    xtemp->z3= Scale*(Real)(in_z3)/scale; */


    vect1_x= xtemp->x3 - xtemp->x1;
    vect1_y= xtemp->y3 - xtemp->y1;
    vect1_z= xtemp->z3 - xtemp->z1;

    vect2_x= xtemp->x2 - xtemp->x1;
    vect2_y= xtemp->y2 - xtemp->y1;
    vect2_z= xtemp->z2 - xtemp->z1;

    n1_x= vect1_y*vect2_z - vect1_z*vect2_y;
    n1_y= vect1_z*vect2_x - vect1_x*vect2_z;
    n1_z= vect1_x*vect2_y - vect1_y*vect2_x;

    xtemp->norm1_x = xtemp->norm2_x = xtemp->norm3_x = n1_x;	
    xtemp->norm1_y = xtemp->norm2_y = xtemp->norm3_y = n1_y;	
    xtemp->norm1_z = xtemp->norm2_z = xtemp->norm3_z = n1_z;	
    xtemp->col = col;

    xtemp->next = curdata; 
    return xtemp;
}

void R3DSolidRib(R3DRib __far *ribdata)
{

	Real	x_av, y_av, z_av;
	R3DRib __far *beg_ribdata;
	register ShadeDesc *shade;

	beg_ribdata = ribdata; 
	if (!ribdata) return;

	for(;ribdata->next;ribdata=ribdata->next)
	{
		if((ribdata->norm1_x*ribdata->next->norm1_x + ribdata->norm1_y*ribdata->next->norm1_y
				+ ribdata->norm1_z*ribdata->next->norm1_z) < 0 )
	  	{
		     ribdata->next->norm1_x = ribdata->next->norm2_x = ribdata->next->norm3_x =
								- ribdata->next->norm1_x;
		     ribdata->next->norm1_y = ribdata->next->norm2_y = ribdata->next->norm3_y =
							 	- ribdata->next->norm1_y;
		     ribdata->next->norm1_z = ribdata->next->norm2_z = ribdata->next->norm3_z =
							 	- ribdata->next->norm1_z;
		}
        }

	ribdata= beg_ribdata;

	for(;ribdata->next->next;ribdata=ribdata->next)
	{
	  x_av= (ribdata->norm1_x + ribdata->next->norm2_x + ribdata->next->next->norm3_x)/3;
 	  y_av= (ribdata->norm1_y + ribdata->next->norm2_y + ribdata->next->next->norm3_y)/3;
	  z_av= (ribdata->norm1_z + ribdata->next->norm2_z + ribdata->next->next->norm3_z)/3;

	  ribdata->norm1_x = ribdata->next->norm2_x = ribdata->next->next->norm3_x = x_av;
 	  ribdata->norm1_y = ribdata->next->norm2_y = ribdata->next->next->norm3_y = y_av;
	  ribdata->norm1_z = ribdata->next->norm2_z = ribdata->next->next->norm3_z = z_av;
	}

	for( ;beg_ribdata; beg_ribdata = beg_ribdata->next)
	{
		fprintf(OutFile,"1\n");
		fprintf(OutFile,"%.5f %.5f %.5f %.5f %.5f %.5f %.5f %.5f %.5f "
			,beg_ribdata->x1, beg_ribdata->y1, beg_ribdata->z1
			,beg_ribdata->x2, beg_ribdata->y2, beg_ribdata->z2
			,beg_ribdata->x3, beg_ribdata->y3, beg_ribdata->z3);

	    /* i = beg_ribdata->col + ColourMask; */
		shade = Shade + Colour2Shade(beg_ribdata->col);
	    fprintf(OutFile,"%g %g %g\n", (Real)(shade->r)/255.0, (Real)(shade->g)/255.0, (Real)(shade->b)/255.0);

		fprintf(OutFile,"7\n");
		fprintf(OutFile,"%.5f %.5f %.5f %.5f %.5f %.5f %.5f %.5f %.5f\n "
			,beg_ribdata->norm1_x, beg_ribdata->norm1_y, beg_ribdata->norm1_z
			,beg_ribdata->norm2_x, beg_ribdata->norm2_y, beg_ribdata->norm2_z
			,beg_ribdata->norm3_x, beg_ribdata->norm3_y, beg_ribdata->norm3_z);
	}

}


void WriteR3DRibbon( Chain  __far *chain, Real scale )
{
    register Group __far *group;
    register RAtom __far *captr;
    register RAtom __far *o1ptr;
    register RAtom __far *o2ptr;
    register RAtom __far *next;
 
    register int prev, wide;
    register int col1,col2;
    register int bx,by,bz;
    register int dx,dy,dz;
    register int arrow;
    register int size;
    R3DRib __far *ribdata;
    R3DRib __far *front, *back, *side1, *side2;
    int  cartoon_flag;

    static Knot mid1, mid2, mid3;
    static Knot knot1, knot2;
 

    cartoon_flag = 0;
    ribdata = front = back = side1 = side2 =NULL;
    prev = False;
    group = chain->glist;

    if( IsProtein(group->refno) )
    	captr = FindGroupAtom(group,1);
    else 
	captr = FindGroupAtom(group,7);
 

    while( group->gnext )
    { 
	if( IsProtein(group->gnext->refno) )
        { 
		next = FindGroupAtom(group->gnext,1);
        	o1ptr = FindGroupAtom(group,3);
        } else /* Nucleic Acid */
        {
		next = FindGroupAtom(group->gnext,7);
	        o1ptr = FindGroupAtom(group->gnext,10);
        }
 
        /* When not to have a control point! */
        if( !next || !captr || !o1ptr || (next->flag&BreakFlag) ||
            !((group->flag|group->gnext->flag)&DrawKnotFlag) )
        {
		group = group->gnext;
	        captr = next;
        	prev = False;
	        continue;
        }
 
        knot2.tx = next->xorg - captr->xorg + next->fxorg - captr->fxorg ;
        knot2.ty = next->yorg - captr->yorg + next->fyorg - captr->fyorg;
        knot2.tz = next->zorg - captr->zorg + next->fzorg - captr->fzorg;
 
        if( IsProtein(group->refno) )
        {   bx = o1ptr->xorg - captr->xorg + o1ptr->fxorg - captr->fxorg;
            by = o1ptr->yorg - captr->yorg + o1ptr->fyorg - captr->fyorg;
            bz = o1ptr->zorg - captr->zorg + o1ptr->fzorg - captr->fzorg;
 
        } else /* Nucleic Acid */
        {   o2ptr = FindGroupAtom(group,8);
            if( o2ptr && !FindGroupAtom(group,17) )
            {   /* Deoxyribonucleic Acid */
                bx = (o1ptr->xorg + o2ptr->xorg)/2 - captr->xorg + (o1ptr->fxorg + o2ptr->fxorg)/2 - captr->fxorg;
                by = (o1ptr->yorg + o2ptr->yorg)/2 - captr->yorg + (o1ptr->fyorg + o2ptr->fyorg)/2 - captr->fyorg;
                bz = (o1ptr->zorg + o2ptr->zorg)/2 - captr->zorg + (o1ptr->fzorg + o2ptr->fzorg)/2 - captr->fzorg;
            } else
	    {   /* Ribonucleic Acid */
                bx = o1ptr->xorg - captr->xorg + o1ptr->fxorg - captr->fxorg;
                by = o1ptr->yorg - captr->yorg + o1ptr->fyorg - captr->fyorg;
                bz = o1ptr->zorg - captr->zorg + o1ptr->fzorg - captr->fzorg;
            }
        }

        knot2.px = (captr->xorg + next->xorg)/2 + (captr->fxorg + next->fxorg)/2;
        knot2.py = (captr->yorg + next->yorg)/2 + (captr->fyorg + next->fyorg)/2;
        knot2.pz = (captr->zorg + next->zorg)/2 + (captr->fzorg + next->fzorg)/2;
 
        /* c := a x b */
        knot2.vnx = knot2.ty*bz*Scale*Scale - knot2.tz*by*Scale*Scale;
        knot2.vny = knot2.tz*bx*Scale*Scale - knot2.tx*bz*Scale*Scale;
        knot2.vnz = knot2.tx*by*Scale*Scale - knot2.ty*bx*Scale*Scale;

        if( (group->struc&group->gnext->struc) & HelixFlag )
        {   /* Compensate for narrowing of helices! */
            size = isqrt((Long)knot2.vnx*knot2.vnx +
                         (Long)knot2.vny*knot2.vny +
                         (Long)knot2.vnz*knot2.vnz);
            knot2.vsize = size;
 
            if( size )
            {   /* 1.00 Angstrom Displacement */
                wide = 250; 
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
            {
		if( DrawBetaArrows && (group->struc&SheetFlag) &&
                    !(group->gnext->struc&SheetFlag) )
                { 
			wide = (3*group->width)>>1;
                	arrow = True;
                } else
			wide = group->width;

            } else if( group->flag & WideKnotFlag )
            {
		/* Average Ribbon Width */
                if( group->gnext->flag & WideKnotFlag )
                	wide = (group->width+group->gnext->width)>>1;
                else if( group->gnext->flag & CartoonFlag )
                	wide = group->gnext->width;
                else
			wide = group->width;

            } else wide = group->gnext->width;
 

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
                wide = (int)(CartoonHeight);

                knot2.dx = (int)(((Long)wide*knot2.vnx)/size);
                knot2.dy = (int)(((Long)wide*knot2.vny)/size);
                knot2.dz = (int)(((Long)wide*knot2.vnz)/size);
            } else if( (group->flag|group->gnext->flag)&RibbonFlag )
               {} CalculateVInten( &knot2 );
        }
 
        if( !(col1 = group->col1) )
            col1 = captr->col;
 
        if( prev )
        {   /* Approximate spline segment with plane! */
 
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
            {   
		wide = (int)(group->width);
		R3DCylinder(knot1.px+CenX, knot1.py+CenY, knot1.pz+CenZ,
                              mid1.px+CenX, mid1.py+CenY, mid1.pz+CenZ, col1, scale );
		R3DCylinder(mid1.px+CenX, mid1.py, mid1.pz,
                              mid2.px+CenX, mid2.py+CenY, mid2.pz+CenZ, col1, scale );
		R3DCylinder(mid2.px+CenX, mid2.py, mid2.pz,
                              mid3.px+CenX, mid3.py+CenY, mid3.pz+CenZ, col1, scale );
		R3DCylinder(mid3.px+CenX, mid3.py, mid3.pz,
                              knot2.px+CenX, knot2.py+CenY, knot2.pz+CenZ, col1, scale );

            } else if( group->flag & DotsFlag )
            {
		wide = (int)(group->width);
		R3DSphere(knot1.px+CenX, knot1.py+CenY, knot1.pz+CenZ, wide, col1,scale);
		R3DSphere(mid2.px+CenX, mid2.py+CenY, mid2.pz+CenZ, wide, col1,scale);

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
                { 
			if( !(col2 = group->col2) )
                        	col2 = captr->col;
			
			R3DStrandRibbon( &knot1, &mid1,  col1, col2, scale );
                        R3DStrandRibbon( &mid1,  &mid2,  col1, col2, scale );
                        R3DStrandRibbon( &mid2,  &mid3,  col1, col2, scale );
                        R3DStrandRibbon( &mid3,  &knot2, col1, col2, scale );
                    
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
                        {
/*			    SolidRibbon2( &knot1, &mid1,  col1, col2 );
                            SolidRibbon2( &mid1,  &mid2,  col1, col2 );
                            SolidRibbon2( &mid2,  &mid3,  col1, col2 );
                            SolidRibbon2( &mid3,  &knot2, col1, col2 );*/
                        } else
                        { 
 			    ribdata = Poly_ribdata( &knot1, &mid1, ribdata, col1, scale );  
			    ribdata = Poly_ribdata( &mid1,  &mid2, ribdata, col1, scale );
			    ribdata = Poly_ribdata( &mid2,  &mid3, ribdata, col1, scale );
			    ribdata = Poly_ribdata( &mid3, &knot2, ribdata, col1, scale );
                        }
                    } else /* Cartoon! */
                    {   /* Calculate Spline Heights */
                        wide = (int)(CartoonHeight);
 
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
 
			cartoon_flag = 1;
			Cartoon_ribdata( &knot1, &mid1, &front, &back, &side1, &side2, col1, scale );  
			Cartoon_ribdata( &mid1,  &mid2, &front, &back, &side1, &side2, col1, scale );  
			Cartoon_ribdata( &mid2,  &mid3, &front, &back, &side1, &side2, col1, scale );  
			Cartoon_ribdata( &mid3, &knot2, &front, &back, &side1, &side2, col1, scale );  
                    }
                }
            }
        } else if( group == chain->glist )
        {   knot1 = knot2;
            knot1.px = captr->xorg + captr->fxorg- CenX;
            knot1.py = captr->yorg + captr->fyorg - CenY;
            knot1.pz = captr->zorg + captr->fzorg - CenZ;
 
            if( group->flag & RibbonFlag )
            {
		ribdata=Poly_ribdata(&knot1, &knot2, ribdata, col1, scale);    

            } else if( group->flag & RibbonFlag )
            {  
		Cartoon_ribdata( &knot1, &knot2, &front, &back, &side1, &side2, col1, scale );  

            } else if( group->flag & (StrandFlag|DashStrandFlag) )
            {
		if( !(col2 = group->col2) )
                	col2 = captr->col;

                R3DStrandRibbon( &knot1,  &knot2, col1, col2, scale);

            } else if( group->flag & TraceFlag )
	    {	

		R3DCylinder(knot1.px+CenX, knot1.py+CenY, knot1.pz+CenZ,
                            knot2.px+CenX, knot2.py+CenY, knot2.pz+CenZ, col1, scale);

            } else if( group->flag & DotsFlag )
            {  
		wide = (int)(group->width);
		R3DSphere(knot1.px+CenX,knot1.py+CenY,knot1.pz+CenZ,wide,col1,scale);
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
            {
		wide = (3*group->width)>>1;
                knot2.px = captr->xorg + captr->fxorg + (knot2.tx/2) - CenX;
                knot2.py = captr->yorg + captr->fyorg + (knot2.ty/2) - CenY;
                knot2.pz = captr->zorg + captr->fyorg + (knot2.tz/2) - CenZ;
 
                arrow = True;
            } else
            {  
		wide = group->width;
                knot2.px = captr->xorg + captr->fxorg - CenX;
                knot2.py = captr->yorg + captr->fyorg - CenY;
                knot2.pz = captr->zorg + captr->fzorg - CenZ;
                arrow = False;
            }
 
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
 
	Cartoon_ribdata( &knot1, &knot2, &front, &back, &side1, &side2, col1, scale );  

        } else /* !Cartoon */
        {   knot2.px = captr->xorg + captr->fxorg - CenX;
            knot2.py = captr->yorg + captr->fyorg - CenY;
            knot2.pz = captr->zorg + captr->fzorg - CenZ;
 
            if( group->flag & RibbonFlag )
            {
		ribdata= Poly_ribdata(&knot1, &knot2, ribdata, col1, scale);    

            } else if( group->flag & (StrandFlag|DashStrandFlag) )
            {  
			if( !(col2 = group->col2) )
                	 col2 = captr->col;

            	R3DStrandRibbon(&knot1, &knot2, col1, col2, scale);

            } else if( group->flag & TraceFlag )
            { 
			R3DCylinder(knot1.px+CenX, knot1.py+CenY, knot1.pz+CenZ,
                            knot2.px+CenX, knot2.py+CenY, knot2.pz+CenZ, col1, scale);

            } else if( group->flag & DotsFlag )
            { 
			wide = (int)(group->width);
			R3DSphere(knot1.px+CenX,knot1.py+CenY,knot1.pz+CenZ,wide,col1,scale);
  	        R3DSphere(knot2.px+CenX,knot2.py+CenX,knot2.pz+CenX,wide,col1,scale);
            }   
        }
    }

	if( group->flag & RibbonFlag )
	{
		R3DSolidRib(ribdata);
	}
	else if(cartoon_flag)
	{
		R3DSolidRib(front);
		R3DSolidRib(back);
		R3DSolidRib(side1);
		R3DSolidRib(side2);
	}
}
 


static void WriteR3DItems( PSItemPtr __far *data, char __far *type, int count,int scale )
{
	register Monitor __far *monit;
	register HBond __far *hbond;
	register Bond __far *bond;
	register RAtom __far *src;
	register RAtom __far *dst;
	register Chain __far *chain;
	register int i;
	

	for( i=0; i<count; i++ )
		switch( type[i] )
		{
			case(PSAtom): 
				WriteR3DSphere(data,type,i,scale);
			break;

			case(PSBond): 
				bond = (Bond __far*)data[i];
				src = bond->srcatom;
				dst = bond->dstatom;

				if( bond->flag & WireFlag )
					WriteR3DStick(src,dst,bond->col,10,scale);

				else if( bond->flag & CylinderFlag )
					WriteR3DStick(src,dst,bond->col,bond->radius,scale);    

                           	else /* bond->flag & DashFlag */
	                        	WriteR3DStick(src,dst,bond->col,bond->radius,scale);
			break;

			case(PSSSBond): 
			case(PSHBond):
				hbond = (HBond __far*)data[i];
				if( (type[i]==PSHBond)? HBondMode : SSBondMode )
				{
					src = hbond->srcCA;
					dst = hbond->dstCA;
				}
				else
				{
					src = hbond->src;
					dst = hbond->dst;
				}

				if( hbond->flag & WireFlag )
					WriteR3DStick(src,dst,hbond->col,10,scale);

				else /* bond->flag & CylinderFlag */
					WriteR3DStick(src,dst,hbond->col,hbond->radius,scale);    
			break;

			case(PSMonit):
				monit = (Monitor __far*)data[i];
				WriteR3DMonitor(monit,10,scale);
			break;

			case(PSRibbon):
				chain = (Chain __far*)data[i];
				WriteR3DRibbon(chain, scale);
			break;

      }
}


int WriteR3DFile( char* name)
{
	register int scale;
	register Long count;

	PSItemPtr __far *data;
	char __far *type;

	count = CountPSItems();
	if( !count ) return( True );


#ifdef IBMPC
	if( count > 16383 )
	{
		InvalidateCmndLine();
		WriteString("Output Error: Too many objects!\n");
		return( False );
	}
#endif
   
   scale = XRange;
   if (YRange > scale) scale= YRange;

	/* Allocate arrays for objects! */
	data = (PSItemPtr __far*)_fmalloc((size_t)count*sizeof(PSItemPtr));
	type = (char __far*)_fmalloc((size_t)count*sizeof(char));
	if( !data || !type )
	{
		InvalidateCmndLine();
		WriteString("Output Error: Not enough memory to create raster3d!\n");

		if( data ) _ffree( data );
		if( type ) _ffree( type );
		return( False );
	}


	OutFile = fopen(name,"w");
	if( !OutFile )
	{
		FatalOutputError(name);
		return(False);
	}

 
	/* creating the R3D header */
   
	fprintf(OutFile,"Raster3d file: %s   Creator: RasMol Version %s\n",name,VERSION);
	fprintf(OutFile,"%d %d		tiles in x,y\n",NTX, NTY);
	fprintf(OutFile,"%d %d		pixels (x,y) per tile\n",NPX, NPY);
	fprintf(OutFile,"4		anti-aliasing level 4; 3X3->2X2\n");
	fprintf(OutFile,"%.2f %.2f %.2f		background color\n",BackR/255.0,BackG/255.0,BackB/255.0);
	fprintf(OutFile,"F		shadows cast\n");
	if (FakeSpecular) {
	fprintf(OutFile,"10		Phong power\n");
	fprintf(OutFile,"0.10		secondary light contribution\n");
	fprintf(OutFile,"0.05		ambient light contribution\n");
	fprintf(OutFile,"0.50		specular reflection component\n");
	} else {
	fprintf(OutFile,"25		Phong power\n");
	fprintf(OutFile,"0.25		secondary light contribution\n");
	fprintf(OutFile,"0.05		ambient light contribution\n");
	fprintf(OutFile,"0.25		specular reflection component\n");
	}
	fprintf(OutFile,"0.0		eye position\n");
	fprintf(OutFile,"1 1 1		main light source position( from over right shoulder)\n");
	fprintf(OutFile,"%f %f %f 0		view matrix for coordinate transformations\n",
									   1.0, 0.0, 0.0);
	fprintf(OutFile,"%f %f %f 0\n",    0.0, 1.0, 0.0);
	fprintf(OutFile,"%f %f %f 0\n",    0.0, 0.0, 1.0);
	fprintf(OutFile,"%f %f %f %f		translation\n",
                                          0.0, 0.0, 0.0,
                                           1.0); 
	fprintf(OutFile,"3\n*\n*\n*\n");
	if (UseDepthPlane) {
  	  fprintf(OutFile,"16\nBACKCLIP %f\n", (Real)(DepthValue-ZRange/2+1)/(Real)scale);
	}
	if (UseSlabPlane) {
	  fprintf(OutFile,"16\nFRONTCLIP %f\n", (Real)(SlabValue-ZRange/2-1)/(Real)scale);
	}


	FetchPSItems(data,type);

	if( count>1 )
		DepthSort(data,type,(int)count);

	WriteR3DItems(data,type,(int)count,scale);


/*
    if( !VectSolid )
    {   fputs("[] 0 setdash\n",OutFile);
        VectSolid = True;
    }

    if( DotPtr )
        WriteVectDots();
    if( DrawMonitDistance && MonitList )
        WriteVectMonitors();
*/

	if( LabelList )
		WriteR3DLabels(scale);


	fclose(OutFile);

#ifdef APPLEMAC
	/* Avoid ANSI trigraph problems! */
	SetFileInfo(name,'vgrd','TEXT',134);
#endif

	_ffree( data );
	_ffree( type );
	return(True);
}


/*==================================*/
/*  Macintosh PICT File Generation  */
/*==================================*/

static void FlushPICTBuffer( void )
{
    if( PacketLen )
    {   if( RLEOutput )
        {   WriteByte(PacketLen-1);
            fwrite((char*)Buffer,1,PacketLen,OutFile);
        } else RLELineSize += PacketLen+1;
        PacketLen = 0;
    }
}


static void FlushPICTPacket( void )
{
    register int i;

    if( RLELength>2 )
    {   FlushPICTBuffer();

        if( RLEOutput )
        {   WriteByte(257-RLELength);
            WriteByte(RLEChar);
        } else RLELineSize += 2;
    } else 
        for( i=0; i<RLELength; i++ )
        {   Buffer[PacketLen++] = RLEChar;
            if( PacketLen == 128 ) 
                FlushPICTBuffer();
        }
}


static void WritePICTCode( int val )
{
    if( !RLELength )
    {   RLEChar = val;
        RLELength = 1;
    } else if( (val!=RLEChar) || (RLELength==128) )
    {   FlushPICTPacket();
        RLEChar = val;
        RLELength = 1;
    } else RLELength++;
}


static void WritePICTData( void )
{
    register Pixel __huge *ptr;
    register Pixel __huge *tmp;
    register int x,y;

#ifdef MSWIN
    FBuffer = (Pixel __huge*)GlobalLock(FBufHandle);
#endif

    RLEFileSize = 0;

#ifndef INVERT
    ptr = FBuffer;
#endif
    for( y=YRange-1; y>=0; y-- )
    {
#ifdef INVERT
        ptr = FBuffer + (Long)y*XRange;
#endif

        RLELineSize = 0;
        RLEOutput = False;
        PacketLen = 0;
        RLELength = 0;

#ifdef EIGHTBIT
        tmp = ptr;
        for( x=0; x<XRange; x++ )
            WritePICTCode( LutInv[*tmp++] );
#else
        tmp = ptr;
        for( x=0; x<XRange; x++ )
            WritePICTCode( (int)RComp(*tmp++) );
        tmp = ptr;
        for( x=0; x<XRange; x++ )
            WritePICTCode( (int)GComp(*tmp++) );
        tmp = ptr;
        for( x=0; x<XRange; x++ )
            WritePICTCode( (int)BComp(*tmp++) );
#endif
        FlushPICTPacket();
        FlushPICTBuffer();

#ifdef EIGHTBIT
        if( XRange > 250 )
        {   WriteMSBShort(RLELineSize);
            RLEFileSize += (RLELineSize+2);
        } else
        {   WriteByte(RLELineSize);
            RLEFileSize += (RLELineSize+1);
        }
#else
        WriteMSBShort(RLELineSize);
        RLEFileSize += (RLELineSize+2);
#endif

        RLEOutput = True;
        PacketLen = 0;
        RLELength = 0;

#ifdef EIGHTBIT
        for( x=0; x<XRange; x++ )
            WritePICTCode( LutInv[*ptr++] );
#else
        tmp = ptr;
        for( x=0; x<XRange; x++ )
            WritePICTCode( (int)RComp(*tmp++) );
        tmp = ptr;
        for( x=0; x<XRange; x++ )
            WritePICTCode( (int)GComp(*tmp++) );
        for( x=0; x<XRange; x++ )
            WritePICTCode( (int)BComp(*ptr++) );
#endif
        FlushPICTPacket();
        FlushPICTBuffer();
    }

#ifdef MSWIN
    GlobalUnlock(FBufHandle);
#endif
}


int WritePICTFile( char *name )
{
#ifdef EIGHTBIT
    register int j,r,g,b;
    register int cols;
#endif
    register int i;

#if defined(IBMPC) || defined(APPLEMAC)
    OutFile = fopen(name,"wb");
#else
    OutFile = fopen(name,"w");
#endif
    if( !OutFile )
    {    FatalOutputError(name);
         return( False );
    }

#ifdef EIGHTBIT
    cols = CompactColourMap();
#endif

    /* Write out header */
    for( i=0; i<512; i++ )
        WriteByte( 0x00 );

    WriteMSBShort(0);       /* picSize         */
    WriteMSBShort(0);       /* picFrame.top    */
    WriteMSBShort(0);       /* picFrame.left   */
    WriteMSBShort(YRange);  /* picFrame.bottom */
    WriteMSBShort(XRange);  /* picFrame.right  */

    WriteMSBShort(PICTpicversion);
    WriteMSBShort(0x02FF);

    WriteMSBShort(PICTheaderop);
    WriteMSBLong((Card)0xffffffff);
    WriteMSBShort(0);      WriteMSBShort(0);
    WriteMSBShort(0);      WriteMSBShort(0);
    WriteMSBShort(XRange); WriteMSBShort(0);
    WriteMSBShort(YRange); WriteMSBShort(0);
    WriteMSBLong(0);

    WriteMSBShort(PICTcliprgn);
    WriteMSBShort(10);      /* rgnSize */
    WriteMSBShort(0);       /* rgnBBox.top    */
    WriteMSBShort(0);       /* rgnBBox.left   */
    WriteMSBShort(YRange);  /* rgnBBox.bottom */
    WriteMSBShort(XRange);  /* rgnBBox.right  */

#ifdef EIGHTBIT
    WriteMSBShort(PICTpackbitsrect);
#else
    WriteMSBShort(PICTdirectbitsrect);
    WriteMSBShort(0x0000);  /* baseAddr      */
    WriteMSBShort(0x00ff);
#endif
    i = (int)((XRange*sizeof(Pixel)) | 0x8000);
    WriteMSBShort( i );     /* rowBytes      */
    WriteMSBShort(0);       /* bounds.top    */
    WriteMSBShort(0);       /* bounds.left   */
    WriteMSBShort(YRange);  /* bounds.bottom */
    WriteMSBShort(XRange);  /* bounds.right  */
    WriteMSBShort(0);       /* pmVersion     */
#ifdef EIGHTBIT
    WriteMSBShort(0);       /* packType      */
#else
    WriteMSBShort(4);       /* packType      */
#endif
    WriteMSBLong(0);        /* packSize      */
    WriteMSBLong(72);       /* hRes          */
    WriteMSBLong(72);       /* vRes          */

#ifdef EIGHTBIT
    WriteMSBShort(0);       /* pixelType     */
    WriteMSBShort(8);       /* pixelSize     */
    WriteMSBShort(1);       /* cmpCount      */
    WriteMSBShort(8);       /* cmpSize       */
#else
    WriteMSBShort(16);      /* pixelType     */
    WriteMSBShort(32);      /* pixelSize     */
    WriteMSBShort(3);       /* cmpCount      */
    WriteMSBShort(8);       /* cmpSize       */
#endif

    WriteMSBLong(0);        /* planeBytes    */
    WriteMSBLong(0);        /* pmTable       */
    WriteMSBLong(0);        /* pmReserved    */

#ifdef EIGHTBIT
    WriteMSBLong(0);        /* ctSeed        */
    WriteMSBShort(0);       /* ctFlags       */
    WriteMSBShort(cols-1);  /* ctSize        */

    for( i=0; i<cols; i++ )
    {    WriteMSBShort(i);  /* value */
         j=Node[i]; r=RLut[j]; g=GLut[j]; b=BLut[j];
         WriteMSBShort( (r<<8)|r );  /* rgb.red */
         WriteMSBShort( (g<<8)|g );  /* rgb.green */
         WriteMSBShort( (b<<8)|b );  /* rgb.blue  */
    }
#endif

    WriteMSBShort(0);       /* srcRect.top    */
    WriteMSBShort(0);       /* srcRect.left   */
    WriteMSBShort(YRange);  /* srcRect.bottom */
    WriteMSBShort(XRange);  /* srcRect.right  */
    WriteMSBShort(0);       /* dstRect.top    */
    WriteMSBShort(0);       /* dstRect.left   */
    WriteMSBShort(YRange);  /* dstRect.bottom */
    WriteMSBShort(XRange);  /* dstRect.right  */
    WriteMSBShort(0);       /* mode (srcCopy) */

    WritePICTData();
    if( RLEFileSize & 0x01 ) WriteByte(0x00);
    WriteMSBShort(PICTendofpict);
    fclose(OutFile);
#ifdef APPLEMAC
    SetFileInfo(name,'ttxt','PICT',134);
#endif
    return True;
}



/*===========================*/
/*  SGI IRIS RGB Generation  */
/*===========================*/
  
static void FlushIRISBuffer( void )
{
    if( PacketLen )
    {   if( RLEOutput )
        {   WriteByte(PacketLen|0x80);
            fwrite((char*)Buffer,1,PacketLen,OutFile);
        } else RLELineSize += PacketLen+1;
        PacketLen = 0;
    }
}


static void FlushIRISPacket( void )
{
    register int i;

    if( RLELength>2 )
    {   FlushIRISBuffer();

        if( RLEOutput )
        {   WriteByte(RLELength);
            WriteByte(RLEChar);
        } else RLELineSize += 2;
    } else
        for( i=0; i<RLELength; i++ )
        {   Buffer[PacketLen++] = RLEChar;
            if( PacketLen == 127 )
                FlushIRISBuffer();
        }
    RLELength = 0;
}


static void WriteIRISCode( int val )
{
    if( !RLELength )
    {   RLELength = 1;
        RLEChar = val;
    } else if( (RLEChar!=val) || (RLELength==127) )
    {   FlushIRISPacket();
        RLELength = 1;
        RLEChar = val;
    } else RLELength++;
}


static void DetermineIRISSizes(  Long __far *rowstart, 
                                 short __far *rowsize,
                                 int *min, int *max )
{                    
    register Pixel __huge *ptr;
    register Pixel __huge *tmp;
    register int i,x,y;

    *max = 0;
    *min = 255;
    RLEFileSize = (int)( 512 + 6*YRange*sizeof(Long));

    RLEOutput = False;
    PacketLen = 0;
    RLELength = 0;

#ifdef INVERT
    ptr = FBuffer;
#endif

    for( y=0; y<YRange; y++ )
    {
#ifndef INVERT
        ptr = FBuffer + (Long)((YRange-1)-y)*XRange;
#endif

        tmp = ptr;
        RLELineSize = 0;
        /* Red Component */
        for( x=0; x<XRange; x++ )
        {   i = RComp(*ptr++);
            if( i<*min ) *min=i;
            if( i>*max ) *max=i;
            WriteIRISCode(i);
        }
        FlushIRISPacket();
        FlushIRISBuffer();

        rowsize[y] = RLELineSize;
        rowstart[y] = RLEFileSize;
        RLEFileSize += RLELineSize;

        ptr = tmp;
        RLELineSize = 0;
        /* Green Component */
        for( x=0; x<XRange; x++ )
        {   i = GComp(*ptr++);
            if( i<*min ) *min=i;
            if( i>*max ) *max=i;
            WriteIRISCode(i);
        }
        FlushIRISPacket();
        FlushIRISBuffer();

        i = y+YRange;
        rowsize[i] = RLELineSize;
        rowstart[i] = RLEFileSize;
        RLEFileSize += RLELineSize;

        ptr = tmp;
        RLELineSize = 0;
        /* Blue Component */
        for( x=0; x<XRange; x++ )
        {   i = BComp(*ptr++);
            if( i<*min ) *min=i;
            if( i>*max ) *max=i;
            WriteIRISCode(i);
        }
        FlushIRISPacket();
        FlushIRISBuffer();

        i = y+(YRange<<1);
        rowsize[i] = RLELineSize;
        rowstart[i] = RLEFileSize;
        RLEFileSize += RLELineSize;
    }
}

                             
static void WriteIRISHeader( Long __far *rowstart,
                             short __far *rowsize, 
                             int min, int max )
{              
    register int i,size;
    
    WriteMSBShort(474);     /* imagic     */
    WriteMSBShort(257);     /* type       */
    WriteMSBShort(3);       /* dim        */
    WriteMSBShort(XRange);  /* xsize      */
    WriteMSBShort(YRange);  /* ysize      */
    WriteMSBShort(3);       /* zsize      */
    WriteMSBLong(min);      /* min        */
    WriteMSBLong(max);      /* max        */
    WriteMSBLong(0);        /* wastebytes */

                            /* name       */
    fputs("RasMol IRIS RGB format output",OutFile);
    for( i=0; i<51; i++ ) WriteByte(0x00);
    WriteMSBLong(0);        /* colormap   */
                       
    size = 3*YRange;
    for( i=0; i<404; i++ )  WriteByte(0x00);
    for( i=0; i<size; i++ ) WriteMSBLong(rowstart[i]);
    for( i=0; i<size; i++ ) WriteMSBLong(rowsize[i]);
}


static void WriteIRISData( void )
{
    register Pixel __huge *ptr;
    register Pixel __huge *tmp;
    register int x,y,i;

    RLEOutput = True;
    PacketLen = 0;
    RLELength = 0;

#ifdef INVERT
    ptr = FBuffer;
#endif

    for( y=0; y<YRange; y++ )
    {
#ifndef INVERT
        ptr = FBuffer + (Long)((YRange-1)-y)*XRange;
#endif

        tmp = ptr;
        /* Red Component */
        for( x=0; x<XRange; x++ )
        {   i = RComp(*ptr++);
            WriteIRISCode(i);
        }
        FlushIRISPacket();
        FlushIRISBuffer();

        ptr = tmp;
        /* Green Component */
        for( x=0; x<XRange; x++ )
        {   i = GComp(*ptr++);
            WriteIRISCode(i);
        }
        FlushIRISPacket();
        FlushIRISBuffer();

        ptr = tmp;
        /* Blue Component */
        for( x=0; x<XRange; x++ )
        {   i = BComp(*ptr++);
            WriteIRISCode(i);
        }
        FlushIRISPacket();
        FlushIRISBuffer();
    }
}

                             
int WriteIRISFile( char *name )
{
    register Long __far *rowstart;
    register short __far *rowsize;
    static int min,max;
    register int size;


#if defined(IBMPC) || defined(APPLEMAC)
    OutFile = fopen(name,"wb");
#else
    OutFile = fopen(name,"w");
#endif
    if( !OutFile )
    {    FatalOutputError(name);
         return( False );
    }

    CalcInvColourMap();

#ifdef MSWIN
    FBuffer = (Pixel __huge*)GlobalLock(FBufHandle);
#endif

    size = 3*YRange;
    /* Allocate RLE encoded row length table */
    rowsize = (short __far*)_fmalloc(size*sizeof(short));
    rowstart = (Long __far*)_fmalloc(size*sizeof(Long));

    if( !rowsize || !rowstart )
    {   InvalidateCmndLine();
        WriteString("Output Error: Unable to allocate memory!\n");
        if( rowstart ) _ffree(rowstart);
        if( rowsize ) _ffree(rowsize);
        fclose(OutFile);
        return( False );
    }
    DetermineIRISSizes(rowstart,rowsize,&min,&max);
    WriteIRISHeader(rowstart,rowsize,min,max);    
    _ffree( rowstart );
    _ffree( rowsize );
                  
    WriteIRISData();
    fclose( OutFile );

#ifdef APPLEMAC
    /* Avoid ANSI trigraph problems! */
    SetFileInfo(name,'\?\?\?\?','\?\?\?\?',134);
#endif
#ifdef MSWIN
    GlobalUnlock(FBufHandle); 
#endif
    return True;
}

void InitialiseOutFile( void )
{
#ifdef EIGHTBIT
#if defined(IBMPC) || defined(APPLEMAC)
    /* Allocate Tables on FAR Heap */
    ABranch = (short __far*)_fmalloc(4096*sizeof(short));
    DBranch = (short __far*)_fmalloc(4096*sizeof(short));
    Hash = (short __far*)_fmalloc(256*sizeof(short));
    Node = (Byte __far*)_fmalloc(4096*sizeof(Byte));
#endif
#endif

    UseTransparent = False;
    KinemageFlag = False;
    UseOutLine = False;
}
