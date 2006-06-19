
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
/* outfile.c
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

static void DetermineIRISSizes( Long __far*, short __far*, int*, int* );
static void WriteIRISHeader( Long __far*, short __far*, int, int );

#ifdef APPLEMAC
/* External RasMac Function Declaration! */
void SetFileInfo( char*, OSType, OSType, short );
#endif



static void FatalOutputError( char *ptr )
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
            if( (xi<0.0) || (xi>=XRange) ) continue;
            yi = (x*MatY[0]+y*MatY[1]+z*MatY[2]) + YOffset;
            if( (yi<0.0) || (yi>=YRange) ) continue;

            zi = (int)(x*MatZ[0]+y*MatZ[1]+z*MatZ[2]);
            if( UseSlabPlane && (zi>=temp) ) continue;
            if( UseDepthPlane && (zi<=tump) ) continue;

            inten = (ColourDepth*(zi+ImageRadius))/ImageSize;
            WriteVectColour( ptr->col[i]+inten );
            fprintf(OutFile,"%g %g Dot\n",xi,yi);
        }
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

        if( ZValid( (s->z+d->z)/2 ) && ZBack( (s->z+d->z)/2 ))
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
