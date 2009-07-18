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
/* mswin31.c
 $Log$
 Revision 1.8  2008/06/27 02:47:58  yaya
 Finished update of windows code for 32-bit color -- HJB

 Revision 1.7  2008/06/11 01:40:54  yaya
 Improve gradient for map surfaces and brighten image;
 Add parenthesized selections before all commands;
 Change saveSelection and loadSelection to
 SaveAtomSelection and LoadAtomSelection -- HJB

 Revision 1.6  2008/03/22 17:06:48  yaya
 Post release cleanup with credits to Ikonen in file headers. -- HJB

 Revision 1.5  2008/03/21 19:13:47  yaya
 Update documentation and comments -- HJB

 Revision 1.5  2008/03/17 03:01:31  yaya
 Update to agree with 2.7.4.2 release and T. Ikonen GTK mods -- HJB

 Revision 1.4  2008/03/17 01:32:41  yaya
 Add gtk mods by tpikonen, and intergate with 2.7.4.2 mods -- HJB

 Revision 1.3  2008/03/16 22:38:09  yaya
 Update stable release to 2.7.4.2; Update rasmol_install and rasmol_run
 scripts to handle Japanese and Chiness (using cxterm), changing
 Japanese for unix back to EUCJP; and align command line options
 to set initial window size and position to agree between unix and
 windows -- HJB

 Revision 1.4  2008/03/16 22:25:22  yaya
 Align comments with production version; Update rasmol_install and
 rasmol_run shell scripts for Japanese and Chinese; Align logic for
 positioning and sizing initial window with windows version -- HJB

 Revision 1.3  2008/03/09 18:04:06  yaya
 As per a suggestion by Gregory A. Pozhvanov, fixed handling of quoted
 filename strings in raswin and added new command line options
 -width nnnn, -height nnnn, -xpos nnnn, and -ypos nnnn. -- HJB

 Revision 1.2  2008/01/28 03:29:37  yaya
 Update CVS to RasMol_2.7.4.1 -- HJB

 Revision 1.2  2007/11/25 04:11:58  yaya
 Updates to map mask logic and inverse transforms -- HJB

 Revision 1.1.1.1  2007/03/01 01:16:33  todorovg
 Chinese working versio from rasmol_ru initial import

 Revision 1.4  2006/11/01 03:23:50  yaya
 Update NSIS windows installer for more script types and to fix
 misplaced script instructions for data files; add document and
 script icons directly in raswin.exe; add credit line to
 G. A. Pozhvanov in comments for Russian translations. -- HJB

 Revision 1.3  2006/10/02 21:24:49  yaya
 Changes to allow disabling of about dialog using RASWIN.FLG flag file,
 Restore windows Help menu adding register and donate menu items
 Enable language support for about dialog -- HJB

 Revision 1.2  2006/09/17 10:53:55  yaya
 Clean up headers and start on code for X11 -- HJB

 Revision 1.1.1.1  2006/09/16 18:45:52  yaya
 Start of RasMol Russian Translation Project based on translations
 by Gregory A. Pozhvanov of Saint Petersburg State University -- HJB

 Revision 1.1.1.1  2006/06/19 22:05:14  todorovg
 Initial Rasmol 2.7.3 Import

 Revision 1.1  2004/05/07 19:46:16  yaya
 Initial revision

 Revision 1.2  2004/02/15 00:24:00  yaya
 *** empty log message ***

 Revision 1.1  2003/12/12 21:10:38  yaya
 Initial revision

 Revision 1.2  2001/02/08 01:14:46  yaya
 *** empty log message ***

 Revision 1.1  2001/01/31 02:13:45  yaya
 Initial revision

 Revision 1.3  2000/08/26 18:12:35  yaya
 Updates to header comments in all files

 Revision 1.2  2000/02/23 00:00:00  yaya
 Prelininary 2.7.2 build

 */

#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdio.h>


#define GRAPHICS
#include "rasmol.h"
#include "raswin.idm"
#include "graphics.h"
#include "langsel.h"


static int ColCount;
static BITMAPINFO __far *BitInfo;
static HCURSOR WaitCursor;
static HCURSOR OldCursor;
static HMENU hMenu;


void AllocateColourMap( void )
{
#ifdef EIGHTBIT			
    register COLORREF ref;      
    register int i;
    
    if( ColourMap )
        DeleteObject(ColourMap);
        

    ColCount = 0;
    for( i=0; i<256; i++ )
        if( ULut[i] ) 
        {  Palette->palPalEntry[ColCount].peFlags = 0;
           Palette->palPalEntry[ColCount].peRed   = RLut[i];
           Palette->palPalEntry[ColCount].peGreen = GLut[i];
           Palette->palPalEntry[ColCount].peBlue  = BLut[i];

           BitInfo->bmiColors[ColCount].rgbBlue     = BLut[i];
           BitInfo->bmiColors[ColCount].rgbGreen    = GLut[i];
           BitInfo->bmiColors[ColCount].rgbRed      = RLut[i];
           BitInfo->bmiColors[ColCount].rgbReserved = 0;
           ColCount++;
        }   
    Palette->palNumEntries = ColCount;
    BitInfo->bmiHeader.biClrUsed = ColCount;   
    ColourMap = CreatePalette(Palette);

    for( i=0; i<256; i++ )
       if( ULut[i] )
       {   ref = RGB(RLut[i],GLut[i],BLut[i]);
           Lut[i] = GetNearestPaletteIndex(ColourMap,ref);
       } 
#endif   
}



int CreateImage( void )
{
    register Long size;

    if( FBufHandle ) GlobalFree(FBufHandle);
    size = (Long)XRange*YRange*sizeof(Pixel)+16;
    FBufHandle = GlobalAlloc(GMEM_MOVEABLE,size);
    return (int)FBufHandle;
}


void TransferImage( void )
{
#ifdef EIGHTBIT
    HPALETTE OldCMap;
#endif
    HDC hDC;
        
    if( PixMap )
        DeleteObject(PixMap);

    BitInfo->bmiHeader.biWidth = XRange;
    BitInfo->bmiHeader.biHeight = YRange;
        
    hDC = GetDC(NULL);
    FBuffer = (Pixel  __huge*)GlobalLock(FBufHandle);
    /* CreateBitMap(XRange,YRange,1,8,FBuffer); */

#ifdef EIGHTBIT
    if( ColourMap )
    {   OldCMap = SelectPalette(hDC,ColourMap,FALSE);
        RealizePalette(hDC);  /* GDI Bug?? */
    }
#endif
        
    PixMap = CreateDIBitmap( hDC, (BITMAPINFOHEADER __far *)BitInfo, 
                             CBM_INIT, FBuffer, BitInfo, DIB_RGB_COLORS);
#ifdef EIGHTBIT
    if( ColourMap && OldCMap )                         
        SelectPalette(hDC,OldCMap,False);
#endif

    GlobalUnlock(FBufHandle);
    ReleaseDC(NULL,hDC);
    
    InvalidateRect(CanvWin,NULL,FALSE);
    UpdateWindow(CanvWin);
}


void ClearImage( void )
{
    HBRUSH hand;
    RECT rect;
    HDC hDC;
    
    hDC = GetDC(CanvWin);
    hand = CreateSolidBrush(RGB(RLut[0],GLut[0],BLut[0]));
    GetClientRect(CanvWin,&rect);
    FillRect(hDC,&rect,hand);
    ReleaseDC(CanvWin,hDC);
    DeleteObject(hand);

    if( PixMap )
    {   DeleteObject(PixMap);
        PixMap = NULL;
    }
}


int PrintImage( void )
{
    register char *device, *driver, *output;
    register int xsize, xres, yres;
    register int dx, dy, caps;
    char printer[255];
    PRINTDLG mypdlg;
    

    DOCINFO info;
    RECT rect;
    HDC hDC;

    GetProfileString("windows","device",",,,", printer, 255 );
    if( !(device = strtok(printer,",")) ||
        !(driver = strtok((char*)NULL,", ")) ||
        !(output = strtok((char*)NULL,", ")) ) {
        memset ((void *) &mypdlg, 0, sizeof(PRINTDLG));
        mypdlg.lStructSize = sizeof(PRINTDLG);
        mypdlg.hwndOwner = NULL;
        mypdlg.Flags = PD_RETURNDC;
        mypdlg.hInstance = NULL;
        
        if (PrintDlg(&mypdlg) == True) {
          if (mypdlg.hDevMode) GlobalFree (mypdlg.hDevMode);
          if (!mypdlg.hDC) return False;
          hDC = mypdlg.hDC;
        } else {
          WriteString("Unable to locate printer\n");
          return False;
        }
    } else {
      hDC = CreateDC(driver,device,output,NULL);
      if( !hDC ) {
        WriteString("Unable to locate printer\n");
        return False;
      }
    }

    caps = GetDeviceCaps( hDC, RASTERCAPS );
    if( !(caps & RC_STRETCHDIB) ) {
       WriteString("Unable to get necessary caps\n");
       return False;
    }
    
    xres = GetDeviceCaps( hDC, LOGPIXELSX );
    yres = GetDeviceCaps( hDC, LOGPIXELSY );
    xsize = GetDeviceCaps( hDC, HORZRES );

    dx = xsize - xres;
    dy = (int)(((long)dx*YRange)/XRange);

    /* Should set printer abort procedure */
    /* Position Image on Printed Page */
    rect.top = yres;        rect.bottom = rect.top + dy;
    rect.left = xres>>1;    rect.right = rect.left + dx;
    Escape( hDC, SET_BOUNDS, sizeof(RECT), (char __far*)&rect, NULL );

    /* Start RasWin Document */
    info.cbSize = sizeof(DOCINFO);
    info.lpszDocName = "RasWin";
    info.lpszOutput = NULL;
    StartDoc( hDC, &info );
    StartPage( hDC );
    


    BitInfo->bmiHeader.biWidth = XRange;
    BitInfo->bmiHeader.biHeight = YRange;
    FBuffer = (Pixel  __huge*)GlobalLock(FBufHandle);

    StretchDIBits( hDC, xres>>1, yres, dx, dy, 
                        0, 0, XRange, YRange, 
                        FBuffer, BitInfo, DIB_RGB_COLORS, SRCCOPY );

    GlobalUnlock(FBufHandle);

    EndPage( hDC );
    EndDoc( hDC );

    DeleteDC( hDC );
    return True;
}


int ClipboardImage( void )
{
    register BITMAPINFO __far *bitmap;
    register Pixel __huge *src;
    register Pixel __huge *dst;
    register long size,len;
    register HANDLE hand;
    register int i;


    if( OpenClipboard(CanvWin) )
    {   EmptyClipboard();

        /* SetClipboardData(CF_DIB,NULL);     */
        /* SetClipboardData(CF_PALETTE,NULL); */

        if( PixMap )
        {   len = (long)XRange*YRange*sizeof(Pixel);
#ifdef EIGHTBIT
            size = sizeof(BITMAPINFOHEADER) + 256*sizeof(RGBQUAD);
#else
            size = sizeof(BITMAPINFOHEADER);
#endif
            if( (hand=GlobalAlloc(GHND,size+len)) )
            {   bitmap = (BITMAPINFO __far *)GlobalLock(hand);
                bitmap->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
                bitmap->bmiHeader.biWidth = XRange;
                bitmap->bmiHeader.biHeight = YRange;
                bitmap->bmiHeader.biPlanes = 1;
#ifdef EIGHTBIT
                bitmap->bmiHeader.biBitCount = 8;
#else
                bitmap->bmiHeader.biBitCount = 32;
#endif
                bitmap->bmiHeader.biCompression = BI_RGB;
                bitmap->bmiHeader.biSizeImage = len;
                bitmap->bmiHeader.biXPelsPerMeter = 0;
                bitmap->bmiHeader.biYPelsPerMeter = 0;
                bitmap->bmiHeader.biClrImportant = 0;
                bitmap->bmiHeader.biClrUsed = 0;

#ifdef EIGHTBIT
                for( i=0; i<256; i++ )
                    if( ULut[i] )
                    {   bitmap->bmiColors[Lut[i]].rgbBlue  = BLut[i];
                        bitmap->bmiColors[Lut[i]].rgbGreen = GLut[i];
                        bitmap->bmiColors[Lut[i]].rgbRed   = RLut[i];
                    }
#endif


                src = (Pixel __huge*)GlobalLock(FBufHandle);
#ifdef EIGHTBIT
                dst = ((Pixel __huge*)bitmap)+size;
#else
                dst = ((Pixel __huge*)bitmap)+size/4;
#endif

                /* Transfer the frame buffer */
                while( len-- ) *dst++ = *src++;

                GlobalUnlock(FBufHandle);
                GlobalUnlock(hand);
                SetClipboardData(CF_DIB,hand);
            }
        }

        if( ColourMap )
        {   if( (hand = CreatePalette(Palette)) )
                SetClipboardData(CF_PALETTE,hand);
        }
        CloseClipboard();
        return True;
    } else return False;
}


void SetCanvasTitle( char *ptr )
{
    SetWindowText(CanvWin,ptr);
}


void UpdateScrollBars( void )
{
    register int pos;
    
    pos = 50-(int)(50.0*DialValue[0]);
    SetScrollPos(CanvWin,SB_VERT,pos,TRUE);
    
    pos = (int)(50.0*DialValue[1])+50;
    SetScrollPos(CanvWin,SB_HORZ,pos,TRUE);
}

void ReDrawWindow( void )
{
 
  HMENU mentop[20];
  MENUITEMINFO miteminfo;
  int ii, nmen;

  ModifyMenu(hMenu,IDM_OPEN,     MF_STRING, IDM_OPEN,    MsgStrs[StrMOpen]);
  ModifyMenu(hMenu,IDM_INFO,     MF_STRING, IDM_INFO,    MsgStrs[StrMInfo]);
  ModifyMenu(hMenu,IDM_CLOSE,    MF_STRING, IDM_CLOSE,   MsgStrs[StrMClose]);
  ModifyMenu(hMenu,IDM_PRINT,    MF_STRING, IDM_PRINT,   MsgStrs[StrMPrint]);
  ModifyMenu(hMenu,IDM_SETUP,    MF_STRING, IDM_SETUP,   MsgStrs[StrMPSetup]);
  ModifyMenu(hMenu,IDM_EXIT,     MF_STRING, IDM_EXIT,    MsgStrs[StrMExit]);

  ModifyMenu(hMenu,IDM_SELECT,   MF_STRING, IDM_SELECT,  MsgStrs[StrMSelAll]);
  ModifyMenu(hMenu,IDM_CUT,      MF_STRING, IDM_CUT,     MsgStrs[StrMCut]);
  ModifyMenu(hMenu,IDM_COPY,     MF_STRING, IDM_COPY,    MsgStrs[StrMCopy]);
  ModifyMenu(hMenu,IDM_PASTE,    MF_STRING, IDM_PASTE,   MsgStrs[StrMPaste]);
  ModifyMenu(hMenu,IDM_DELETE,   MF_STRING, IDM_DELETE,  MsgStrs[StrMDelete]);

  ModifyMenu(hMenu,IDM_WIREFRAME,MF_STRING,IDM_WIREFRAME,MsgStrs[StrMWirefr]);
  ModifyMenu(hMenu,IDM_BACKBONE, MF_STRING,IDM_BACKBONE, MsgStrs[StrMBackbn]);
  ModifyMenu(hMenu,IDM_STICKS,   MF_STRING,IDM_STICKS,   MsgStrs[StrMSticks]);
  ModifyMenu(hMenu,IDM_SPHERES,  MF_STRING,IDM_SPHERES,  MsgStrs[StrMSpacefl]);
  ModifyMenu(hMenu,IDM_BALLSTICK,MF_STRING,IDM_BALLSTICK,MsgStrs[StrMBallStk]);
  ModifyMenu(hMenu,IDM_RIBBONS,  MF_STRING,IDM_RIBBONS,  MsgStrs[StrMRibbons]);
  ModifyMenu(hMenu,IDM_STRANDS,  MF_STRING,IDM_STRANDS,  MsgStrs[StrMStrands]);
  ModifyMenu(hMenu,IDM_CARTOONS, MF_STRING,IDM_CARTOONS, MsgStrs[StrMCartoon]);
  ModifyMenu(hMenu,IDM_MOLSURF,  MF_STRING,IDM_MOLSURF,  MsgStrs[StrMMolSurf]);

  ModifyMenu(hMenu,IDM_MONO,     MF_STRING,IDM_MONO,     MsgStrs[StrMMonochr]);
  ModifyMenu(hMenu,IDM_CPK,      MF_STRING,IDM_CPK,      MsgStrs[StrMCPK]);
  ModifyMenu(hMenu,IDM_SHAPELY,  MF_STRING,IDM_SHAPELY,  MsgStrs[StrMShapely]);
  ModifyMenu(hMenu,IDM_GROUP,    MF_STRING,IDM_GROUP,    MsgStrs[StrMGroup]);
  ModifyMenu(hMenu,IDM_CHAIN,    MF_STRING,IDM_CHAIN,    MsgStrs[StrMChain]);
  ModifyMenu(hMenu,IDM_TEMPER,   MF_STRING,IDM_TEMPER,   MsgStrs[StrMTemp]);
  ModifyMenu(hMenu,IDM_STRUCT,   MF_STRING,IDM_STRUCT,   MsgStrs[StrMStruct]);
  ModifyMenu(hMenu,IDM_USER,     MF_STRING,IDM_USER,     MsgStrs[StrMUser]);
  ModifyMenu(hMenu,IDM_MODEL,    MF_STRING,IDM_MODEL,    MsgStrs[StrMModel]);
  ModifyMenu(hMenu,IDM_ALT,      MF_STRING,IDM_ALT,      MsgStrs[StrMAlt]);

  ModifyMenu(hMenu,IDM_SLAB,     MF_STRING,IDM_SLAB,     MsgStrs[StrMSlab]);
  ModifyMenu(hMenu,IDM_HYDROGEN, MF_STRING,IDM_HYDROGEN, MsgStrs[StrMHydr]);
  ModifyMenu(hMenu,IDM_HETERO,   MF_STRING,IDM_HETERO,   MsgStrs[StrMHet]);
  ModifyMenu(hMenu,IDM_SPECULAR, MF_STRING,IDM_SPECULAR, MsgStrs[StrMSpec]);
  ModifyMenu(hMenu,IDM_SHADOW,   MF_STRING,IDM_SHADOW,   MsgStrs[StrMShad]);
  ModifyMenu(hMenu,IDM_STEREO,   MF_STRING,IDM_STEREO,   MsgStrs[StrMStereo]);
  ModifyMenu(hMenu,IDM_LABELS,   MF_STRING,IDM_LABELS,   MsgStrs[StrMLabel]);

  ModifyMenu(hMenu,IDM_PKNONE,   MF_STRING,IDM_PKNONE,   MsgStrs[StrMPOff]);
  ModifyMenu(hMenu,IDM_PKIDENT,  MF_STRING,IDM_PKIDENT,  MsgStrs[StrMPIdent]);
  ModifyMenu(hMenu,IDM_PKDIST,   MF_STRING,IDM_PKDIST,   MsgStrs[StrMPDist]);
  ModifyMenu(hMenu,IDM_PKMONIT,  MF_STRING,IDM_PKMONIT,  MsgStrs[StrMPMon]);
  ModifyMenu(hMenu,IDM_PKANGLE,  MF_STRING,IDM_PKANGLE,  MsgStrs[StrMPAng]);
  ModifyMenu(hMenu,IDM_PKTORSN,  MF_STRING,IDM_PKTORSN,  MsgStrs[StrMPTrsn]);
  ModifyMenu(hMenu,IDM_PKLABEL,  MF_STRING,IDM_PKLABEL,  MsgStrs[StrMPLabl]);
  ModifyMenu(hMenu,IDM_PKORIGN,  MF_STRING,IDM_PKORIGN,  MsgStrs[StrMPCent]);
  ModifyMenu(hMenu,IDM_PKCOORD,  MF_STRING,IDM_PKCOORD,  MsgStrs[StrMPCoord]);
  ModifyMenu(hMenu,IDM_PKBOND,   MF_STRING,IDM_PKBOND,   MsgStrs[StrMPBond]);
  ModifyMenu(hMenu,IDM_RTBOND,   MF_STRING,IDM_RTBOND,   MsgStrs[StrMRBond]);
  ModifyMenu(hMenu,IDM_RTMOL,    MF_STRING,IDM_RTMOL,    MsgStrs[StrMRMol]);
  ModifyMenu(hMenu,IDM_RTALL,    MF_STRING,IDM_RTALL,    MsgStrs[StrMRAll]);
 
  ModifyMenu(hMenu,IDM_BMP,      MF_STRING,IDM_BMP,      MsgStrs[StrMBMP]);
  ModifyMenu(hMenu,IDM_GIF,      MF_STRING,IDM_GIF,      MsgStrs[StrMGIF]);
  ModifyMenu(hMenu,IDM_IRIS,     MF_STRING,IDM_IRIS,     MsgStrs[StrMIRGB]);
  ModifyMenu(hMenu,IDM_PPM,      MF_STRING,IDM_PPM,      MsgStrs[StrMPPM]);
  ModifyMenu(hMenu,IDM_RAST,     MF_STRING,IDM_RAST,     MsgStrs[StrMSRast]);
  ModifyMenu(hMenu,IDM_EPSF,     MF_STRING,IDM_EPSF,     MsgStrs[StrMPostscr]);
  ModifyMenu(hMenu,IDM_PICT,     MF_STRING,IDM_PICT,     MsgStrs[StrMPICT]);
  ModifyMenu(hMenu,IDM_VECPS,    MF_STRING,IDM_VECPS,    MsgStrs[StrMVECPS]);
  ModifyMenu(hMenu,IDM_MOLSCRIPT,MF_STRING,IDM_MOLSCRIPT,MsgStrs[StrMMSCR]);
  ModifyMenu(hMenu,IDM_KINEMAGE, MF_STRING,IDM_KINEMAGE, MsgStrs[StrMKine]);
  ModifyMenu(hMenu,IDM_POVRAY,   MF_STRING,IDM_POVRAY,   MsgStrs[StrMPOVRAY]);
  ModifyMenu(hMenu,IDM_VRML,     MF_STRING,IDM_VRML,     MsgStrs[StrMVRML]);
  ModifyMenu(hMenu,IDM_RPP,      MF_STRING,IDM_RPP,      MsgStrs[StrMRPP]);
  ModifyMenu(hMenu,IDM_R3D,      MF_STRING,IDM_R3D,      MsgStrs[StrMR3D]);
  ModifyMenu(hMenu,IDM_SCR,      MF_STRING,IDM_SCR,      MsgStrs[StrMSCR]);

  ModifyMenu(hMenu,IDM_SPLASH,   MF_STRING,IDM_SPLASH,   MsgStrs[StrMAbout]);
  ModifyMenu(hMenu,IDM_RMANUAL,  MF_STRING,IDM_RMANUAL,  MsgStrs[StrMUserM]);
  ModifyMenu(hMenu,IDM_REGISTER, MF_STRING,IDM_REGISTER, MsgStrs[StrRegister]);
  ModifyMenu(hMenu,IDM_DONATE,   MF_STRING,IDM_DONATE,   MsgStrs[StrDonate]);
  
  

  nmen = GetMenuItemCount(hMenu);
  if (nmen > 20) nmen = 20;
  
/*  
  for (ii = nmen; ii > 0; ii--) {
    mentop[ii-1] = GetSubMenu(hMenu,ii-1);
    RemoveMenu(hMenu,ii-1,MF_BYPOSITION);
  }
  for (ii = 0; ii < nmen; ii++) {
    AppendMenu(hMenu, MF_POPUP | MF_STRING , (UINT) mentop[ii], MsgStrs[StrMFile+ii]);
  } 
*/
  
  for (ii = 0; ii < nmen; ii++) {
    miteminfo.cbSize = sizeof(MENUITEMINFO);
    miteminfo.fMask = MIIM_TYPE;
    miteminfo.fType = MFT_STRING;
    miteminfo.dwTypeData =  MsgStrs[StrMFile+ii];
  	SetMenuItemInfo(hMenu,ii,True,&miteminfo);
  }
  
  EnableMenus(True);
  DrawMenuBar(CanvWin);

}
  
void SetMouseUpdateStatus( int bool )
{
    MouseUpdateStatus = bool;
}
                         
                         
void SetMouseCaptureStatus( int bool )
{
    if( bool )
    {   if( !MouseCaptureStatus )
            SetCapture(CanvWin);
    } else
        if( MouseCaptureStatus )
            ReleaseCapture();
    MouseCaptureStatus = bool;
}


int LookUpColour( char *name, int *r, int *g, int *b )
{
    UnusedArgument(name);
    UnusedArgument(r);
    UnusedArgument(g);
    UnusedArgument(b);

    return False;
}    


void EnableMenus( int flag )
{
    if( flag )
    {   SetMenu(CanvWin,hMenu);
    } else SetMenu(CanvWin,0);
    DisableMenu = !flag;
}


int OpenDisplay( HANDLE instance, int mode )
{
    register int i,size;
    long style;
    RECT rect;
    LONG XPOS, YPOS;
    static char VersionStr[50];

    sprintf (VersionStr,"RasMol Version %s", VERSION);

    PixMap = NULL;
    ColourMap = NULL;

    MouseCaptureStatus = False;
    MouseUpdateStatus = False;   
    UseHourGlass = True;
    DisableMenu = False;

    for( i=0; i<10; i++ )
         DialValue[i] = 0.0;
         
    CQRMSet(DialQRot,0.,0.,0.,0.);

    ULut[0] = True;
    RLut[0] = GLut[0] = BLut[0] = 0;

    XRange = DefaultWide;
    YRange = DefaultHigh;
    
    if (InitWidth  >= 48) XRange = InitWidth;
    if (InitHeight >= 48) YRange = InitHeight;

    WRange = XRange>>1;
    HRange = YRange>>1;
    Range = MinFun(XRange,YRange);
    ZRange = 20000;

    rect.top = InitYPos;
    rect.left = InitXPos;
    rect.bottom = InitYPos+YRange;
    rect.right = InitXPos+XRange;
      
    style = WS_OVERLAPPEDWINDOW | WS_HSCROLL | WS_VSCROLL;

    hMenu = LoadMenu(instance,"RasWinMenu");
    AdjustWindowRect(&rect,style,TRUE);

    XPOS = YPOS = CW_USEDEFAULT;
    
    if (InitXPos > 0 && rect.left > 0 ) XPOS = rect.left;
    if (InitYPos > 0 && rect.top > 0) YPOS = rect.top;

    CanvWin = CreateWindow("RasWinClass",VersionStr, style,
                            XPOS, YPOS,
                            rect.right-rect.left, 
                            rect.bottom-rect.top,
                            NULL,hMenu,instance,NULL);
                            
    if( !CanvWin) return False;

    size = sizeof(LOGPALETTE) + 256*sizeof(PALETTEENTRY);
    Palette = (LOGPALETTE __far*)_fmalloc( size );
    size = sizeof(BITMAPINFOHEADER) + 256*sizeof(RGBQUAD);
    BitInfo = (BITMAPINFO __far*)_fmalloc( size );

    if( !Palette || !BitInfo )
        return False;
   
    WaitCursor = LoadCursor(NULL,IDC_WAIT);
        
    Palette->palVersion = 0x300;   
    
    BitInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    BitInfo->bmiHeader.biCompression = BI_RGB;
    BitInfo->bmiHeader.biXPelsPerMeter = 0;
    BitInfo->bmiHeader.biYPelsPerMeter = 0;
    BitInfo->bmiHeader.biClrImportant = 0;
    BitInfo->bmiHeader.biSizeImage = 0;
#ifdef EIGHTBIT
    BitInfo->bmiHeader.biBitCount = 8;
#else
    BitInfo->bmiHeader.biBitCount = 32;
#endif
    BitInfo->bmiHeader.biPlanes = 1;

    /* Initialise Palette! */
    for( i=1; i<256; i++ )
        ULut[i] = False;
    AllocateColourMap();

    ShowWindow(CanvWin,mode);
    UpdateScrollBars();
    UpdateWindow(CanvWin);
    return True;                       
}

    
void BeginWait( void )
{
    if( UseHourGlass )
        OldCursor = SetCursor(WaitCursor);
}


void EndWait( void )
{
    if( UseHourGlass )
        SetCursor(OldCursor);
}


void CloseDisplay( void )
{
    if( ColourMap )
        DeleteObject(ColourMap);
    if( PixMap )
        DeleteObject(PixMap);
}

