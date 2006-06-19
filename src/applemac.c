
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
/* applemac.c
 $Log: not supported by cvs2svn $
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

 Revision 1.7  2000/08/27 00:54:27  yaya
 create rotation bond database

 Revision 1.6  2000/08/26 18:12:24  yaya
 Updates to header comments in all files

 Revision 1.5  2000/08/26 03:13:51  yaya
 Mods for mac compilations

 Revision 1.3  2000/08/13 20:56:09  yaya
 Conversion from toolbar to menus

 Revision 1.2  2000/08/09 01:17:54  yaya
 Rough cut with ucb

 */

#include <QuickDraw.h>
#include <Controls.h>
#include <Palettes.h>
#include <Windows.h>
#include <Errors.h>
#include <Menus.h>
#include <Fonts.h>

#ifdef __CONDITIONALMACROS__
#include <Printing.h>
#else
#include <PrintTraps.h>
#endif
#include <ToolUtils.h>
#include <Memory.h>
#include <Types.h>
#include <Scrap.h>

#include <stdlib.h>
#include <stdio.h>

#define GRAPHICS
#include "rasmol.h"
#include "graphics.h"
#include "molecule.h"
#include "abstree.h"
#include "transfor.h"
#include "render.h"
#include "command.h"
#include "multiple.h" /* [GSG 11/16/95] */
#include "vector.h"   /* [GSG 11/16/95] */
#include "wbrotate.h" /* [GSG 11/16/95] */
#include "langsel.h"


#ifdef __CONDITIONALMACROS__
#define ArrowCursor   SetCursor(&qd.arrow)
#else
#define ArrowCursor   SetCursor(&arrow)
#endif


static PixPatHandle BackHand;
static PaletteHandle CMap;
static PixMap *PixelMap;



int CreateImage( void )
{
    register Long size;
    
    if( FBuffer ) _ffree(FBuffer);
    size = (Long)XRange*YRange*sizeof(Pixel);
    FBuffer = (Pixel*)_fmalloc( size+32 );

#ifdef EIGHTBIT
    PixelMap->rowBytes = XRange | 0x8000;
#else
    PixelMap->rowBytes = (XRange<<2) | 0x8000;
#endif

    PixelMap->baseAddr = (Ptr)FBuffer;
    PixelMap->bounds.right = XRange;
    PixelMap->bounds.bottom = YRange;
    return (int)FBuffer;
}


void TransferImage( void )
{
    register PixMapHandle pmHand;
    register GDHandle gdHand;
    register int mode;
    GrafPtr savePort;
    Rect rect;
   
    GetPort(&savePort);
    SetPort(CanvWin);
   
    ForeColor(blackColor);
    BackColor(whiteColor);
   
    rect.top = 0;   rect.bottom = YRange;
    rect.left = 0;  rect.right = XRange;

    gdHand = GetMaxDevice(&CanvWin->portRect);
    pmHand = (**gdHand).gdPMap;
    if( (**pmHand).pixelSize < (sizeof(Pixel)<<3) )
    {   mode = srcCopy+ditherCopy;
    } else mode = srcCopy;
    
    /* ClipRect(&rect); */
    CopyBits((BitMap*)PixelMap,
             (BitMap*)&CanvWin->portBits,
             &rect,&rect,mode,(RgnHandle)0);

    BackColor(blackColor);
    SetPort(savePort);
}


void ClearImage( void )
{
    GrafPtr savePort;
    RGBColor col;
    Rect rect;

    GetPort(&savePort);
    SetPort(CanvWin);
    
    rect.bottom = CanvWin->portRect.bottom-15;
    rect.right = CanvWin->portRect.right-15;
    rect.left = 0;    
    rect.top = 0;
    
    col.red   = BackR<<8 | BackR;
    col.green = BackG<<8 | BackG;
    col.blue  = BackB<<8 | BackB;
    
    MakeRGBPat(BackHand,&col);
    FillCRect(&rect,BackHand);
    SetPort(savePort);
}


static PicHandle CreateMacPicture( void )
{
    GrafPtr savePort;
    RgnHandle saveRgn;
    PicHandle pict;
    Rect rect;

    saveRgn = NewRgn();
    GetPort(&savePort);
    SetPort(CanvWin);
    GetClip( saveRgn );
    
    rect.top = 0;   rect.bottom = YRange;
    rect.left = 0;  rect.right = XRange;
    pict = OpenPicture(&rect);
  
    ForeColor(blackColor);
    BackColor(whiteColor);
   
    ClipRect( &rect );
    CopyBits((BitMap*)PixelMap,
             (BitMap*)&CanvWin->portBits,
             &rect,&rect,srcCopy,(RgnHandle)0);

    ClosePicture();
    
    SetClip(saveRgn);
    BackColor(blackColor);
    DisposeRgn(saveRgn);
    SetPort(savePort);
    return pict;
}


int PrintImage( void )
{
    register int xsize,ysize;
    register int high,wide;
    
    TPrStatus prStatus;
    TPPrPort printPort;
    GrafPtr savePort;
    PicHandle pict;
    short prErr;
    Rect *page;
    Rect rect;

    /* [GSG 11/29/95] */
    int SaveBackR, SaveBackG, SaveBackB;

    if (DefaultBackground) {
	ReDrawFlag |= RFColour;
	SaveBackR = BackR;
	SaveBackG = BackG;
	SaveBackB = BackB;
	BackR = BackG = BackB = 255;
	RefreshScreen();
    }

    PrOpen();
    if( !PrintHand )
    {   PrintHand = (THPrint)NewHandle(sizeof(TPrint));
        PrintDefault(PrintHand);
    }

    if( PrJobDialog(PrintHand) )
    {   pict = CreateMacPicture();
        printPort = PrOpenDoc(PrintHand,0,0);
        GetPort(&savePort);    
        SetPort(&printPort->gPort);
        
        PrOpenPage( printPort, 0 );
        page = &(**PrintHand).prInfo.rPage; 
        wide = page->right - page->left;
        high = page->bottom - page->top;
        
        xsize = XRange;
        ysize = YRange;
        if( xsize > wide )
        {   ysize = (int)(((Long)ysize*wide)/xsize);
            xsize = wide;
        }
        if( ysize > high )
        {   xsize = (int)(((Long)xsize*high)/ysize);
            ysize = high;
        }
        
        rect.top  = page->top  + (high-ysize)>>1;
        rect.left = page->left + (wide-xsize)>>1;
        rect.bottom = rect.top + ysize;
        rect.right = rect.left + xsize;
        
        DrawPicture( pict, &rect );
        PrClosePage( printPort );
        
        SetPort(savePort);
        PrCloseDoc(printPort);
        KillPicture(pict);
        
        if( !(prErr = PrError()) )
            if( (*PrintHand)->prJob.bJDocLoop == bSpoolLoop )
            {   PrPicFile(PrintHand,0,0,0,&prStatus);
                prErr = PrError();
            }
         
    } else prErr = False;  /* Cancel Print */

    PrClose();

    if (DefaultBackground) {
	ReDrawFlag |= RFColour;
	BackR = SaveBackR;
	BackG = SaveBackG;
	BackB = SaveBackB;
	RefreshScreen();
    }

    return !prErr;
}


int ClipboardImage( void )
{
    register long clipErr;
    register long length;
    PicHandle pict;
    
    ZeroScrap();
    pict = CreateMacPicture();
    
    HLock((Handle)pict);
    length = (long)GetHandleSize((Handle)pict);
    clipErr = PutScrap(length,'PICT',(Ptr)*pict);
    HUnlock((Handle)pict);
    
    KillPicture(pict);   
    return !clipErr;
}


void AllocateColourMap( void )
{ 
#ifdef EIGHTBIT
    register PixMapHandle pmHand;
    register GDHandle gdHand;
    register CTabHandle cmap;
    register int i;
    RGBColor col;
    
    ULut[0] = True;
    ULut[255] = True;
    
    HLock((Handle)CMap);
    cmap = PixelMap->pmTable;
    (**cmap).ctSeed = GetCTSeed();
    for( i=0; i<256; i++ )
    {   if( ULut[i] )
        {   col.red   = RLut[i]<<8 | RLut[i];
            col.green = GLut[i]<<8 | GLut[i];
            col.blue  = BLut[i]<<8 | BLut[i];
            Lut[i] = i;
        } else col.red = col.green = col.blue = 0;
        (**cmap).ctTable[i].rgb = col;
        SetEntryColor(CMap,i,&col);
    }
    HUnlock((Handle)CMap);
    
    gdHand = GetMaxDevice(&CanvWin->portRect);
    pmHand = (**gdHand).gdPMap;
    if( (**pmHand).pixelSize >= 8 )
        ActivatePalette(CanvWin);
    FBClear = False;
#endif
}


void UpdateScrollBars( void )
{
    register int pos;
    /* [GSG 11/16/95] */
    float x, y;

    if (( RotMode == RotBond ) && BondSelected)
      x = BondSelected->BRotValue;
    else if ( RotMode == RotAll )
      x = WRotValue[DialRY];
    else
      x = DialValue[DialRY];
    
    pos = 50+(int)(50.0*x);
#ifdef USEOLDROUTINENAMES
    SetCtlValue(HScroll,pos);
#else
    SetControlValue(HScroll,pos);
#endif
    
    if ( RotMode == RotAll )
	y = WRotValue[DialRX];
    else
	y = DialValue[DialRX];
    
    pos = 50+(int)(50.0*y);
#ifdef USEOLDROUTINENAMES
    SetCtlValue(VScroll,pos);
#else
    SetControlValue(VScroll,pos);
#endif
}



unsigned char * ReWriteStr255(unsigned char buffer[255], char* str)
{   unsigned char *dst;
    unsigned char *src;
    unsigned int limit;

    limit = buffer[0]+1;
    dst = buffer+1;
    src = (unsigned char *)str;
    while( *src && (dst<buffer+254) && ((dst-buffer)< limit) )
      *dst++ = *src++;
    while ((dst-buffer)< limit )
      *dst++ = '\0';
    return buffer;
}

unsigned char * tostr255(unsigned char buffer[255], char* str)
{   unsigned char *dst;
    unsigned char *src;

    buffer[0]=0;
    dst = buffer+1;
    src = (unsigned char *)str;
    while( *src && (dst<buffer+254) )
      *dst++ = *((unsigned char *)src++);
    buffer[0] = (unsigned char)((dst-buffer)-1);
    *dst = (unsigned char)'\0';
    return buffer;
}

void ReDrawWindow( void )
{    MenuHandle hand;
     unsigned char buffer[255];
     int menu;
     
     for( menu=140; menu < 149; menu++) {

#ifdef USEOLDROUTINENAMES
       hand = GetMHandle(menu);
#else
       hand = GetMenuHandle(menu);
#endif

        switch( menu )
        {   case(140):  /* Apple Menu */
              SetMenuItemText(hand,1,tostr255(buffer,MsgStrs[StrMAbout]));
              SetMenuItemText(hand,2,tostr255(buffer,MsgStrs[StrMUserM]));
              break;
                      
            case(141):  /* File Menu */
              SetMenuItemText(hand,1,tostr255(buffer,MsgStrs[StrMOpen]));
              SetMenuItemText(hand,2,tostr255(buffer,MsgStrs[StrMSaveAs]));
              SetMenuItemText(hand,3,tostr255(buffer,MsgStrs[StrMClose]));
              SetMenuItemText(hand,5,tostr255(buffer,MsgStrs[StrMPSetup]));
              SetMenuItemText(hand,6,tostr255(buffer,MsgStrs[StrMPrint]));
              SetMenuItemText(hand,8,tostr255(buffer,MsgStrs[StrMExit]));
              ReWriteStr255((*hand)->menuData,MsgStrs[StrMFile]);
              break;
                      
                      
            case(142):  /* Edit Menu */
              SetMenuItemText(hand,1,tostr255(buffer,MsgStrs[StrMUndo]));
              SetMenuItemText(hand,2,tostr255(buffer,MsgStrs[StrMCut]));
              SetMenuItemText(hand,3,tostr255(buffer,MsgStrs[StrMCopy]));
              SetMenuItemText(hand,4,tostr255(buffer,MsgStrs[StrMPaste]));
              SetMenuItemText(hand,5,tostr255(buffer,MsgStrs[StrMClear]));
              SetMenuItemText(hand,7,tostr255(buffer,MsgStrs[StrMSelAll]));
              ReWriteStr255((*hand)->menuData,MsgStrs[StrMEdit]);
              break;
                         
            case(143):  /* Display Menu */
              SetMenuItemText(hand,1,tostr255(buffer,MsgStrs[StrMWirefr]));
              SetMenuItemText(hand,2,tostr255(buffer,MsgStrs[StrMBackbn]));
              SetMenuItemText(hand,3,tostr255(buffer,MsgStrs[StrMSticks]));
              SetMenuItemText(hand,4,tostr255(buffer,MsgStrs[StrMSpacefl]));
              SetMenuItemText(hand,5,tostr255(buffer,MsgStrs[StrMBallStk]));
              SetMenuItemText(hand,6,tostr255(buffer,MsgStrs[StrMRibbons]));
              SetMenuItemText(hand,7,tostr255(buffer,MsgStrs[StrMStrands]));
              SetMenuItemText(hand,8,tostr255(buffer,MsgStrs[StrMCartoon]));
              SetMenuItemText(hand,9,tostr255(buffer,MsgStrs[StrMMolSurf]));
              ReWriteStr255((*hand)->menuData,MsgStrs[StrMDisplay]);
              break;              
                            
            case(144):  /* Colours Menu */
              SetMenuItemText(hand,1,tostr255(buffer,MsgStrs[StrMMonochr]));
              SetMenuItemText(hand,2,tostr255(buffer,MsgStrs[StrMCPK]));
              SetMenuItemText(hand,3,tostr255(buffer,MsgStrs[StrMShapely]));
              SetMenuItemText(hand,4,tostr255(buffer,MsgStrs[StrMGroup]));
              SetMenuItemText(hand,5,tostr255(buffer,MsgStrs[StrMChain]));
              SetMenuItemText(hand,6,tostr255(buffer,MsgStrs[StrMTemp]));
              SetMenuItemText(hand,7,tostr255(buffer,MsgStrs[StrMStruct]));
              SetMenuItemText(hand,8,tostr255(buffer,MsgStrs[StrMUser]));
              SetMenuItemText(hand,9,tostr255(buffer,MsgStrs[StrMModel]));
              SetMenuItemText(hand,10,tostr255(buffer,MsgStrs[StrMAlt]));
              ReWriteStr255((*hand)->menuData,MsgStrs[StrMColour]);
              break;
                                                     
            case(145):  /* Option Menu */
              SetMenuItemText(hand,1,tostr255(buffer,MsgStrs[StrMSlab]));
              SetMenuItemText(hand,2,tostr255(buffer,MsgStrs[StrMHydr]));
              SetMenuItemText(hand,3,tostr255(buffer,MsgStrs[StrMHet]));
              SetMenuItemText(hand,4,tostr255(buffer,MsgStrs[StrMSpec]));
              SetMenuItemText(hand,5,tostr255(buffer,MsgStrs[StrMShad]));
              SetMenuItemText(hand,6,tostr255(buffer,MsgStrs[StrMStereo]));
              SetMenuItemText(hand,7,tostr255(buffer,MsgStrs[StrMLabel]));
              ReWriteStr255((*hand)->menuData,MsgStrs[StrMOpt]);
              break;

            case(146):  /* Settings Menu */
              SetMenuItemText(hand,1,tostr255(buffer,MsgStrs[StrMPOff]));
              SetMenuItemText(hand,2,tostr255(buffer,MsgStrs[StrMPIdent]));
              SetMenuItemText(hand,3,tostr255(buffer,MsgStrs[StrMPDist]));
              SetMenuItemText(hand,4,tostr255(buffer,MsgStrs[StrMPMon]));
              SetMenuItemText(hand,5,tostr255(buffer,MsgStrs[StrMPAng]));
              SetMenuItemText(hand,6,tostr255(buffer,MsgStrs[StrMPTrsn]));
              SetMenuItemText(hand,7,tostr255(buffer,MsgStrs[StrMPLabl]));
              SetMenuItemText(hand,8,tostr255(buffer,MsgStrs[StrMPCent]));
              SetMenuItemText(hand,9,tostr255(buffer,MsgStrs[StrMPCoord]));
              SetMenuItemText(hand,10,tostr255(buffer,MsgStrs[StrMPBond]));
              SetMenuItemText(hand,11,tostr255(buffer,MsgStrs[StrMRBond]));
              SetMenuItemText(hand,12,tostr255(buffer,MsgStrs[StrMRMol]));
              SetMenuItemText(hand,13,tostr255(buffer,MsgStrs[StrMRAll]));
              ReWriteStr255((*hand)->menuData,MsgStrs[StrMSettings]);
              break;

                        
            case(147):  /* Export Menu */
              SetMenuItemText(hand,1,tostr255(buffer,MsgStrs[StrMGIF]));
              SetMenuItemText(hand,2,tostr255(buffer,MsgStrs[StrMPostscr]));
              SetMenuItemText(hand,3,tostr255(buffer,MsgStrs[StrMPPM]));
              SetMenuItemText(hand,4,tostr255(buffer,MsgStrs[StrMSRast]));
              SetMenuItemText(hand,5,tostr255(buffer,MsgStrs[StrMBMP]));
              SetMenuItemText(hand,6,tostr255(buffer,MsgStrs[StrMPICT]));
              ReWriteStr255((*hand)->menuData,MsgStrs[StrMExport]);
              break;
                        
            case(148):  /* Windows Menu */
              SetMenuItemText(hand,1,tostr255(buffer,MsgStrs[StrMMainWin]));
              SetMenuItemText(hand,2,tostr255(buffer,MsgStrs[StrMCmndLin]));
              ReWriteStr255((*hand)->menuData,MsgStrs[StrMWindow]);
              break; 
         }    
     }
     SetMenuBar(GetMenuBar());
     DrawMenuBar();
    

}


void SetMouseUpdateStatus( int bool )
{
    MouseUpdateStatus = bool;
}


void SetMouseCaptureStatus( int bool )
{
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
    MenuHandle hand;
    long offset;
    
    /* File Menu */
#ifdef USEOLDROUTINENAMES
    hand = GetMHandle(141);
#else
    hand = GetMenuHandle(141);
#endif
    if( flag && NumMolecules < MAX_MOLECULES ) /* [GSG 11/16/95] */
    {   EnableItem(hand,1);
    } else DisableItem(hand,1);
    
    if( Database && flag )
    {   EnableItem(hand,2);
        EnableItem(hand,3);
        EnableItem(hand,5);
        EnableItem(hand,6);
    } else
    {   DisableItem(hand,2);
        DisableItem(hand,3);
        DisableItem(hand,5);
        DisableItem(hand,6);
    }
    
    /* Edit Menu */
#ifdef USEOLDROUTINENAMES
    hand = GetMHandle(142);
#else
    hand = GetMenuHandle(142);
#endif
    if( Database )
    {   EnableItem(hand,3);
    } else DisableItem(hand,3);
    
    if( flag && (GetScrap(0,'TEXT',&offset)>0) )
    {   EnableItem(hand,4);
    } else DisableItem(hand,4);
    
    if( flag && Database )
    {   EnableItem(hand,7);
    } else DisableItem(hand,7);
    
    /* Middle Menus */
#ifdef USEOLDROUTINENAMES
    if( Database && flag )
    {   EnableItem(GetMHandle(143),0);
        EnableItem(GetMHandle(144),0);
        EnableItem(GetMHandle(145),0);
        EnableItem(GetMHandle(146),0);
    } else
    {   DisableItem(GetMHandle(143),0);
        DisableItem(GetMHandle(144),0);
        DisableItem(GetMHandle(145),0);
        DisableItem(GetMHandle(146),0);
    }
#else 
    if( Database && flag )
    {   EnableItem(GetMenuHandle(143),0);
        EnableItem(GetMenuHandle(144),0);
        EnableItem(GetMenuHandle(145),0);
        EnableItem(GetMenuHandle(146),0);
    } else
    {   DisableItem(GetMenuHandle(143),0);
        DisableItem(GetMenuHandle(144),0);
        DisableItem(GetMenuHandle(145),0);
        DisableItem(GetMenuHandle(146),0);
    }
#endif
    
    /* Export Menu */
#ifdef USEOLDROUTINENAMES
    hand = GetMHandle(147);
#else 
    hand = GetMenuHandle(147);
#endif
    if( Database )
    {   EnableItem(hand,0);
    } else DisableItem(hand,0);
    DisableMenu = !flag;
    DrawMenuBar();
}


static void DefineMenus( void )
{
    MenuHandle hand;
    register int i;
    
    /* Apple Menu */
    hand = GetMenu(140);
#ifdef USEOLDROUTINENAMES
    AddResMenu(hand,'DRVR');
#else
    AppendResMenu(hand,'DRVR');
#endif
    InsertMenu(hand,0);
    
    for( i=141; i<149; i++ )
        InsertMenu( GetMenu(i), 0 );
        
    /* if( GetEnvirons(smRegionCode) == verUS ) */
    /* SetItem(GetMenuHandle(144),0,'\pColors");   */
    EnableMenus( True );
}


int OpenDisplay( int x, int y )
{
#ifndef EIGHTBIT
    register CTabHandle cmap;
#endif
    register int i;
    Rect rect;
    
    MouseCaptureStatus = False;
    MouseUpdateStatus = False;
    UseHourGlass = True;
    DisableMenu = False;

    for( i=0; i<10; i++ )
        DialValue[i] = 0.0;
    
    ULut[0] = ULut[255] = True;
    RLut[255] = GLut[255] = BLut[255] = 0;
    RLut[0] = GLut[0] = BLut[0] = 255;
    
    XRange = x;   WRange = XRange>>1;
    YRange = y;   HRange = YRange>>1;
    Range = MinFun(XRange,YRange);
    ZRange = 20000;
    
    CanvWin = GetNewCWindow(150,0,(WindowPtr)-1);
    SetPort(CanvWin);
    
    SizeWindow(CanvWin,x+15,y+15,true);
    ShowWindow(CanvWin);
    
    /* Load Cursors */
    CanvCursor = GetCursor(160);
    CmndCursor = GetCursor(1);
    WaitCursor = GetCursor(4);   
    
    /* Create Scroll Bars */
    rect.left = -1;  rect.right = x+1;  
    rect.top = y;    rect.bottom = y+16;
    HScroll = NewControl(CanvWin,&rect,"\p",true,
                         50,0,100,scrollBarProc,0L);
    
    rect.left = x;   rect.right = x+16;
    rect.top = -1;   rect.bottom = y+1;
    VScroll = NewControl(CanvWin,&rect,"\p",true,
                         50,0,100,scrollBarProc,0L);
    
    DrawGrowIcon(CanvWin);
    
    /* PixMap! */
    PixelMap = (PixMap*)NewPtr(sizeof(PixMap));
    if( !PixelMap ) return True;
    
    /* 72.0 DPI Resolution! */
    PixelMap->hRes = 72;
    PixelMap->vRes = 72;
    PixelMap->bounds.left = 0;
    PixelMap->bounds.top = 0;
    PixelMap->cmpSize = 8;
    
    PixelMap->planeBytes = 0;
    PixelMap->pmReserved = 0;
    PixelMap->pmVersion = 0;
    PixelMap->packType = 0;
    PixelMap->packSize = 0;
    
#ifdef EIGHTBIT
    /* Indexed PixMap */
    PixelMap->pixelSize = 8;
    PixelMap->pixelType = 0;
    PixelMap->cmpCount = 1;
    
    PixelMap->pmTable = GetCTable(8);
    (**PixelMap->pmTable).ctSeed = GetCTSeed();
    
    CMap = NewPalette(256,(CTabHandle)0,pmTolerant,0);
    SetPalette(CanvWin,CMap,True);
#else
    /* Direct PixMap */
    PixelMap->pixelSize = 32;
    PixelMap->cmpSize = 8;
    PixelMap->pixelType = RGBDirect;
    PixelMap->cmpCount = 3;
    
    i = sizeof(ColorTable) - sizeof(CSpecArray);
    cmap = (CTabHandle)NewHandle(i);
    (**cmap).ctSeed = 32;
    (**cmap).ctFlags = 0;
    (**cmap).ctSize = 0;
    PixelMap->pmTable = cmap;
#endif
    
    /* Initialise Palette! */
    for( i=1; i<255; i++ )
        ULut[i] = False;
    AllocateColourMap();
    
    PrintHand = (THPrint)NULL;
    BackHand = NewPixPat();
    DefineMenus();
    return False;
}


void CloseDisplay( void )
{
}


void BeginWait( void )
{
    register WindowPtr win;
    
    if( UseHourGlass )
    {   win = FrontWindow();
        if( win==CanvWin || win==CmndWin )
            SetCursor(*WaitCursor);
    }
}



void EndWait( void )
{
    register WindowPtr win;
    GrafPtr savePort;
    Point pos;
    
    /* if( UseHourGlass )? */
    
    win = FrontWindow();
    if( win==CanvWin )
    {   GetPort(&savePort);
        SetPort(CanvWin);
        GetMouse(&pos);
        
        if( (pos.h>0) && (pos.v>0) &&
            (pos.v<CanvWin->portRect.bottom-15) &&
            (pos.h<CanvWin->portRect.right-15) )
        {   SetCursor(*CanvCursor);
        } else ArrowCursor;
        SetPort(savePort);
    } else if( win==CmndWin )
    {   GetPort(&savePort);
        SetPort(CmndWin);
        GetMouse(&pos);
        
        if( (pos.h>0) && (pos.v>0) &&
            (pos.v<CmndWin->portRect.bottom) &&
            (pos.h<CmndWin->portRect.right-15) )
        {   SetCursor(*CmndCursor);
        } else ArrowCursor;
        SetPort(savePort);
    }
}


void SetCanvasTitle( char *ptr )
{
    register unsigned char *dst;
    unsigned char buffer[255];

    if( ptr )
    {   dst = buffer+1;
        while( *ptr && (dst<buffer+254) )
            *dst++ = *((unsigned char *)ptr++);
        buffer[0] = (unsigned char)((dst-buffer)-1);
        *dst = (unsigned char)'\0';
    } else  /* No Title! */
    {   buffer[0] = (unsigned char)'\0';
        buffer[1] = (unsigned char)'\0';
    }
    SetWTitle(CanvWin,(Byte*)buffer);
}

