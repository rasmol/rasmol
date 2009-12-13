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
/* rasmac.c
 $Log$
 Revision 1.9  2008/03/22 18:42:54  yaya
 Post release cleanup and credit to Ikonen in file headers. -- HJB

 Revision 1.8  2008/03/17 03:01:31  yaya
 Update to agree with 2.7.4.2 release and T. Ikonen GTK mods -- HJB

 Revision 1.3  2008/03/17 01:32:41  yaya
 Add gtk mods by tpikonen, and intergate with 2.7.4.2 mods -- HJB

 Revision 1.7  2008/03/16 22:25:22  yaya
 Align comments with production version; Update rasmol_install and
 rasmol_run shell scripts for Japanese and Chinese; Align logic for
 positioning and sizing initial window with windows version -- HJB

 Revision 1.2  2008/01/28 03:29:38  yaya
 Update CVS to RasMol_2.7.4.1 -- HJB

 Revision 1.6  2007/12/14 02:04:50  yaya
 Correct Chinese data for missing line in langsel_utf.c
 Rewrite code for handling of slab mode in stereo -- HJB

 Revision 1.5  2007/11/19 03:28:39  yaya
 Update to credits for 2.7.4 in manual and headers
 Mask code added -- HJB

 Revision 1.4  2007/07/07 21:54:31  yaya
 Next round of preliminary updates for maps, allowing multiple maps,
 code to set the contour level and some fixes to the languages files -- HJB

 Revision 1.3  2007/07/02 12:44:39  yaya
 Partial preliminary map code -- HJB

 Revision 1.2  2007/03/14 03:26:29  yaya
 Update langsel_mac.c with latest translations (Bulgarian, Chinese, Japanese)
 and setup rasmac.c for font size adjustments. -- HJB

 Revision 1.1.1.1  2007/03/01 01:16:33  todorovg
 Chinese working versio from rasmol_ru initial import

 Revision 1.6  2006/12/11 02:45:38  yaya
 Migrate some of the language switching tables to mac and mswin version
 and update the icons for mswin and X11 versions. -- HJB

 Revision 1.5  2006/12/03 02:53:10  yaya
 Clean up compilation warnings in outfile.c
 Mods for about screen under Linux -- HJB

 Revision 1.4  2006/10/30 15:18:12  yaya
 Add NSIS installer, make language sticky for windows and mac
 Set up RASMOLPATH environment variable on install -- HJB

 Revision 1.3  2006/10/14 21:05:51  yaya
 Changes for build of Mac Classic versions with Russian
 and with new About and Help dialogs -- HJB

 Revision 1.2  2006/09/17 10:53:56  yaya
 Clean up headers and start on code for X11 -- HJB

 Revision 1.1.1.1  2006/09/16 18:45:56  yaya
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

 Revision 1.10  2000/08/27 00:54:42  yaya
 create rotation bond database

 Revision 1.9  2000/08/26 18:12:38  yaya
 Updates to header comments in all files

 Revision 1.8  2000/08/26 03:14:04  yaya
 Mods for mac compilations

 Revision 1.6  2000/08/18 16:40:32  yaya
 *** empty log message ***

 Revision 1.5  2000/08/13 20:56:22  yaya
 Conversion from toolbar to menus

 Revision 1.4  2000/08/09 01:18:10  yaya
 Rough cut with ucb

 Revision 1.3  2000/08/03 18:32:42  yaya
 Parametrization for alt conformer bond radius

 */

#define RASMOL
#include "rasmol.h"

#include <string.h>
#include <stdio.h>

#include <Errors.h>
#ifdef __CONDITIONALMACROS__
#include <Printing.h>
#else
#include <PrintTraps.h>
#endif

#ifdef USEOLDROUTINENAMES
#include <GestaltEqu.h>
#include <OSEvents.h>
#include <Desk.h>
#else
#include <Devices.h>
#include <Gestalt.h>
#endif

#include <StandardFile.h>
#include <AppleEvents.h>
#include <ToolUtils.h>
#include <Resources.h>
#include <DiskInit.h>
#include <Printing.h>
#include <OSUtils.h>
#include <SegLoad.h>
#include <Events.h>
#include <Memory.h>
#include <Finder.h>
#include <Files.h>
#include <Types.h>
#include <Scrap.h>
#include <EPPC.h>

#include <Quickdraw.h>
#include <Controls.h>
#include <Palettes.h>
#include <TextEdit.h>
#include <Windows.h>
#include <Dialogs.h>
#include <Menus.h>
#include <Fonts.h>

#include "molecule.h"
#include "abstree.h"
#include "graphics.h"
#include "pixutils.h"
#include "transfor.h"
#include "cmndline.h"
#include "command.h"
#include "render.h"
#include "repres.h"
#include "outfile.h"
#include "multiple.h" /* [GSG 11/9/95] */
#include "vector.h"   /* [GSG 11/13/95] */
#include "wbrotate.h" /* [GSG 11/14/95] */
#include "langsel.h"
#include "maps.h"

#include "rasmac.h"

#ifndef __CONDITIONALMACROS__
/* Undocumented System Functions */
pascal OSErr SetDialogDefaultItem( DialogPtr theDialog,
        short newItem ) = {0x303C,0x0304,0xAA68};
#endif

#define ScrlMax    80
#define CmndRows   160
#define CmndCols   132
#define CmndSize   (CmndRows*CmndCols)

#define ClipCaret  (CaretX<CmndWin->portRect.right-15)
static long LastCaretTime;
static int CaretX,CaretY;
static int CaretFlag;

/* Terminal Emulation Variables */
static Rect CmndRect;
static char TermScreen[CmndSize];
static int CharWide,CharHigh;
static int TermXPos,TermYPos;
static int TermRows,TermCols;
static int TermCursor;
static int CmndStart;
static int ScrlStart;
static int CharSkip;

static ControlHandle CmndScroll;
static short RasMolResFile;
static char Filename[1024];
static int DialogFormat;

/* About Dialog Variables */

static int ShowAbout = 0;


#ifdef __CONDITIONALMACROS__
#define ArrowCursor   SetCursor(&qd.arrow)
#else
#define ArrowCursor   SetCursor(&arrow)
#endif


#ifdef __CONDITIONALMACROS__
/* Global RoutineDescriptors */
AEEventHandlerUPP HandleAEIgnorePtr;
AEEventHandlerUPP HandleAEOpenDocPtr;
AEEventHandlerUPP HandleAEQuitAppPtr;
ControlActionUPP CanvScrollProcPtr;
ControlActionUPP CmndScrollProcPtr;
DlgHookYDUPP OpenDlgHookPtr;
DlgHookYDUPP SaveDlgHookPtr;
#endif



/*=======================*/
/*  Function Prototypes  */
/*=======================*/

static void PaintScreen( void );
static void ReSizeCmndWin( void );



void RasMolExit( void )
{
    /* Restore System Event Mask */
    SetEventMask( everyEvent & ~keyUp );
    
    /* Free System Memory Resources */
    if( FBuffer ) _ffree( FBuffer );
    if( DBuffer ) _ffree( DBuffer );
    if( SLineBuffer ) _ffree( SLineBuffer );
    if( DlineBuffer ) _ffree( DLineBuffer );
    if( DotPtr ) DeleteSurface();
    if( MapInfoPtr ) DeleteAllMaps();
    PurgeDatabase();
    CloseDisplay();
    ExitToShell();
}


void RasMolFatalExit( char *msg )
{
    register char *ptr;
    register int len;
    
    Str255 buffer;
    DialogPtr dlg;
    Handle hand;
    short item;
    Rect rect;
    
    dlg = GetNewDialog(171,(Ptr)0,(WindowPtr)-1);
    SetDialogDefaultItem(dlg,1);
    
    /* Error Message Text! */
    ptr = (char*)&buffer[1];
    while( *msg ) 
        *ptr++ = *msg++;
    
    len = ptr - (char*)&buffer[1];
    buffer[0] = (unsigned char)len;
#ifdef USEOLDROUTINENAMES
    GetDItem(dlg,4,&item,&hand,&rect);
    SetIText(hand,buffer);
#else    
    GetDialogItem(dlg,4,&item,&hand,&rect);
    SetDialogItemText(hand,buffer);
#endif
    ShowWindow(dlg);

    do {
#ifdef __CONDITIONALMACROS__
        ModalDialog((ModalFilterUPP)0,&item);
#else
        ModalDialog((ProcPtr)0,&item);
#endif
    } while( item != 1 );
    
#ifdef USEOLDROUTINENAMES    
    DisposDialog(dlg);
#else
    DisposeDialog(dlg);
#endif

    /* Restore System Event Mask */
    SetEventMask( everyEvent & ~keyUp );
    
    /* Free System Memory Resources */
    if( FBuffer ) _ffree( FBuffer );
    if( DBuffer ) _ffree( DBuffer );
    if( SLineBuffer ) _ffree( SlineBuffer );
    if( DLineBuffer ) _ffree( DLineBuffer );
    if( DotPtr ) DeleteSurface();
    if( MapInfoPtr ) DeleteAllMaps();
    PurgeDatabase();
    CloseDisplay();
    ExitToShell();
}


/*==================================*/
/*  Externally File Type Function!  */
/*==================================*/

static void CopyResource( ResType type, short file, short id )
{
    register Handle hand;
    Str255 name;

    UseResFile(RasMolResFile);
    hand = GetResource(type,id);
    if( hand )
    {   GetResInfo(hand,&id,&type,name);
        DetachResource(hand);

        UseResFile(file);
        AddResource(hand,type,kCustomIconResource,name);
        if( !ResError() ) WriteResource(hand);
        ReleaseResource(hand);
        UseResFile(RasMolResFile);
    }
}


void SetFileInfo( char *ptr, OSType appl, OSType type, short icon )
{
    register char *dst;
    register short file;
    register int len;
    
    Str255 buffer;
    FSSpec fss;
    FInfo info;
    
    /* Create Pascal Filename */
    dst = (char*)&buffer[1];
    while( *ptr ) *dst++ = *ptr++;
    len = dst - (char*)&buffer[1];
    buffer[0] = (unsigned char)len;
    
    FSMakeFSSpec(0,0,buffer,&fss);
    
    if( icon )
    {   /* smSystemScript not always defined! */
        FSpCreateResFile(&fss,appl,type,0);
        file = FSpOpenResFile(&fss,fsRdWrPerm);
        CopyResource('icl4',file,icon);
        CopyResource('icl8',file,icon);
        CopyResource('ICN#',file,icon);
        CopyResource('ics#',file,icon);
        CopyResource('ics4',file,icon);
        CopyResource('ics8',file,icon);
        CloseResFile(file);
    }
    
    if( !FSpGetFInfo(&fss,&info) )
    {   info.fdType = type;
        info.fdCreator = appl;
        if( icon )
            info.fdFlags |= kHasCustomIcon;
        FSpSetFInfo(&fss,&info);
    }
    FlushVol(NULL,fss.vRefNum);
}


static void SetTermScroll( int pos )
{
    GrafPtr savePort;
    
    GetPort(&savePort);
    SetPort(CmndWin);
#ifdef USEOLDROUTINENAMES
    SetCtlValue(CmndScroll,pos);
#else
    SetControlValue(CmndScroll,pos);
#endif
    ScrlStart = ScrlMax - pos;
    InvalRect(&CmndWin->portRect);
    SetPort(savePort);
}


static void ShowCaret( void )
{
    GrafPtr savePort;
    
    if( !CaretFlag && ClipCaret )
    {   GetPort(&savePort);
        SetPort(CmndWin);
        PenMode(patCopy);
        MoveTo(CaretX,CaretY);
        Line(0,CharSkip);
        SetPort(savePort);
    }
    LastCaretTime = TickCount();
    CaretFlag = True;
}


static void HideCaret( void )
{
    GrafPtr savePort;
    
    if( CaretFlag && ClipCaret )
    {   GetPort(&savePort);
        SetPort(CmndWin);
        PenMode(patBic);
        MoveTo(CaretX,CaretY);
        Line(0,CharSkip);
        SetPort(savePort);
    }
    CaretFlag = False;
}


static void SetCaretPos( int x, int y )
{
    if( CaretFlag )
    {   HideCaret();
        CaretX = x;
        CaretY = y;
        ShowCaret();
    } else
    {   CaretX = x;
        CaretY = y;
    }
}


static void HandleCaret( void )
{
    register long ticks;
    
    ticks = TickCount();
    if(  ticks > LastCaretTime + GetCaretTime() )
    {   if( CaretFlag )
       {   LastCaretTime = ticks;
           HideCaret();
       } else ShowCaret();
    }
}


void WriteChar( int ch )
{
    register int i;
    
    GrafPtr savePort;
    FontInfo finfo;
    Str255 fnamebuf;
    short fontid;
    int x, y, cols, rows;
    int ii;
    
      if ( TermLanguage != Language) {
        for (ii=0; ii < NUMLANGS; ii++) {
        if (Language == langfonts[ii].lang) {
          strcpy((char *)(fnamebuf+1),langfonts[ii].menufontlist);
          fnamebuf[0] = strlen(langfonts[ii].menufontlist);
          break;
        }
      }

      fontid = 0;
      GetFNum(fnamebuf,&fontid);
      if (fontid == 0) {
        SwitchLang(English);
        TermLanguage = English;
        strncpy((char *)(fnamebuf+1),"Monaco",7);
        fnamebuf[0] = 6;
        GetFNum(fnamebuf,&fontid);
      }
      GetPort(&savePort);
      SetPort(CmndWin);
      TextFont(fontid);
      if (Language == Russian || Language == Bulgarian ) TextSize(14);
      else if (Language == Chinese || Language == Japanese ) TextSize(16);
      else TextSize(10);
      TextFace(0);
      CharExtra(0);
      
      GetFontInfo(&finfo);
      CharSkip = finfo.ascent + finfo.descent + finfo.leading;
      CharHigh = finfo.ascent;
      CharWide = finfo.widMax;
      if (Language == Russian || Language == Bulgarian) CharWide-=2;
      SetPort(savePort);
      TermLanguage = Language;
          
      ReSizeCmndWin();
      
    }

    
    /* Scroll to bottom! */
    if( ScrlStart )
        SetTermScroll( ScrlMax );

    switch( ch )
    {   case(0x07):  SysBeep(15);
                     break;
                     
        case(0x08):  if( TermXPos>0 )
                     {   TermXPos--;
                         if( TermCursor )
                             SetCaretPos(TermXPos*CharWide,
                                         TermYPos*CharSkip);
                     }
                     break;
                     
#ifdef ORIG
        case(0x0D):  if( TermXPos )
                     {   if( TermCursor )
                             SetCaretPos(0,TermYPos*CharSkip);
                         TermXPos = 0;
                     }
                     break;
#else
        case(0x0D):
#endif
                     
        case(0x0A):  if( TermYPos==TermRows-1 )
                     {   CmndStart++;
                         if( CmndStart == CmndRows )
                             CmndStart = 0;
                             
                         i = TermYPos + CmndStart;
                         if( i >= CmndRows ) i -= CmndRows;
                         memset(TermScreen+i*CmndCols,32,CmndCols);
                         
                         GetPort(&savePort);
                         SetPort(CmndWin);
                         /* InvalRect(&CmndWin->portRect); */
                         PaintScreen();
                         SetPort(savePort);
                     } else TermYPos++;
                     TermXPos = 0;
                     
                     if( TermCursor )
                         SetCaretPos(0,TermYPos*CharSkip);
                     break;
                     
        default:     i = TermYPos + CmndStart;
                     if( i >= CmndRows ) i -= CmndRows;
                     TermScreen[i*CmndCols+TermXPos] = ch;
                     if( TermXPos < TermCols )
                     {   GetPort(&savePort);
                         SetPort(CmndWin);
                         MoveTo(TermXPos*CharWide+1,TermYPos*CharSkip+CharHigh);
                         DrawChar(ch);
                         SetPort(savePort);
                     }
                     
                     if( TermXPos==CmndCols-1 )
                     {   if( TermYPos==TermRows-1 )
                         {  CmndStart++;
                            if( CmndStart == CmndRows )
                                CmndStart = 0;
                             
                            i = TermYPos + CmndStart;
                            if( i >= CmndRows ) i-= CmndRows;
                            memset(TermScreen+i*CmndCols,32,CmndCols);
                            
                            GetPort(&savePort);
                            SetPort(CmndWin);
                            /* InvalRect(&CmndWin->portRect); */
                            PaintScreen();
                            SetPort(savePort);
                         } else TermYPos++;
                         TermXPos = 0;
                     } else TermXPos++;
                     
                     if( TermCursor )
                         SetCaretPos(TermXPos*CharWide,
                                     TermYPos*CharSkip);
                     break;
    }

}


void WriteMsg( char *ptr )
{
    WriteString(ptr);
    WriteChar ('\n');
}


void WriteString( char *ptr )
{
    while( *ptr )
        WriteChar( *ptr++ );
}


#ifndef topLeft
#define topLeft(r) (*((Point*)(&(r))))
#endif


static void InitTerminal( void )
{
    register WindowPeek wpeek;
    register WStateData *wsdp;
    register Region *rgn;
    register int mb,tb;
    register int x, y;
    FontInfo finfo;
    Point pnt;
    Rect rect;
    
    TermCursor = False;
    CaretFlag = False;
    
    /* Default Window Size */
    TermCols = 80;  TermRows = 24;
    ScrlStart = CmndStart = 0;
    TermXPos = TermYPos = 0;

    CmndWin = GetNewWindow(151,0,CanvWin);
    SetPort(CmndWin);
    
    /* Font Style */
    TextMode(srcCopy);
#ifdef USEOLDROUTINENAMES
    TextFont(monaco);
#else
#ifdef kFontIDMonaco
    TextFont(kFontIDMonaco);
#else
#ifdef monoco
    TextFont(monaco);
#else
    TextFont(kFontIDMonaco);
#endif
#endif
#endif
    TextSize(10);
    TextFace(0);
    
    GetFontInfo(&finfo);
    CharSkip = finfo.ascent + finfo.descent + finfo.leading;
    CharHigh = finfo.ascent;
    CharWide = finfo.widMax;
    
    /* Set Initial Terminal Size */
    x = TermCols*CharWide;
    y = TermRows*CharSkip;
    SizeWindow(CmndWin,x+16,y,true);
    ShowWindow(CmndWin);

    /* Create Scroll Bar */
    rect.left = x+1;   rect.right = x+17;
    rect.top = -1;     rect.bottom = y-14;
    CmndScroll = NewControl(CmndWin,&rect,"\p",false,ScrlMax,
                            0,ScrlMax,scrollBarProc,0L);
    
    wpeek = (WindowPeek)CmndWin;
    pnt = topLeft(CmndWin->portRect);
    rgn = *(wpeek->strucRgn);
    LocalToGlobal(&pnt);

    /* Title & Menu Bar Heights */
    tb = pnt.v - rgn->rgnBBox.top;
    mb = GetMBarHeight()+tb+4;

#ifdef __CONDITIONALMACROS__    
    y = (qd.screenBits.bounds.bottom-(mb+1))/CharSkip;
#else
    y = (screenBits.bounds.bottom-(mb+1))/CharSkip;
#endif
    if( y>CmndRows ) y = CmndRows;

    CmndRect.bottom = y*CharSkip+1;
    CmndRect.right = CmndCols*CharWide+17;
    CmndRect.left = CharWide+49;
    CmndRect.top = 62;   

    /* Set Zoom-In Size */
    wsdp = (WStateData*) *(wpeek->dataHandle);
    wsdp->stdState.bottom = CmndRect.bottom+mb;
    wsdp->stdState.right = CmndRect.right+4;
    wsdp->stdState.left = 4;
    wsdp->stdState.top = mb;
    
    memset(TermScreen,32,CmndSize);
}


static void DrawCmndGrowIcon( void )
{
    register RgnHandle saveRgn;
    GrafPtr savePort;
    Rect rect;
    
    GetPort(&savePort);
    SetPort(CmndWin);
    saveRgn = NewRgn();
    GetClip(saveRgn);
    
    rect = CmndWin->portRect;
    rect.left = rect.right-15;
    ClipRect(&rect);
    DrawGrowIcon(CmndWin);
    
    SetClip(saveRgn);
    DisposeRgn(saveRgn);
    SetPort(savePort);
}


static void PaintScreen( void )
{
    register char *ptr;
    register WindowPtr win;
    register int SRow,ERow;
    register int SCol,ECol;
    register int row,len;
    register int x,y;
    Rect rect;
    
    /* Toolbox Components */
    DrawControls(CmndWin);
    DrawCmndGrowIcon();
    
    /* Determine Invalid Rect? */
    SRow = 0;   ERow = TermRows-1;
    SCol = 0;   ECol = TermCols-1;
    
    len = ECol-SCol+1;
    x = SCol*CharWide + 1;
    y = SRow*CharSkip + CharHigh;
    
    SRow += CmndStart - ScrlStart;
    if( SRow >= CmndRows )
    {   SRow -= CmndRows;
    } else if( SRow < 0 )
        SRow += CmndRows;
        
    ERow += CmndStart - ScrlStart;
    if( ERow >= CmndRows )
    {   ERow -= CmndRows;
    } else if( ERow < 0 )
        ERow += CmndRows;
            
    row = SRow;
    ptr = TermScreen + SRow*CmndCols + SCol;
    while( True )
    {   MoveTo(x,y);
        DrawText(ptr,0,len);
        if( row != ERow )
        {   ptr += CmndCols;
            row++;
            if( row == CmndRows )
            {   ptr = TermScreen + SCol;
                row = 0;
            }
        } else break;
        y += CharSkip;
    }
    
    /* Erase Screen Edges! */
    rect = CmndWin->portRect;
    rect.right -= 15;
    
    x = TermCols*CharWide+1;
    y = TermRows*CharSkip;
    if( x<rect.right )
    {   rect.left = x;
        EraseRect(&rect);
    }
    
    if( y<rect.bottom )
    {   rect.left = 0;
        rect.top = y;
        EraseRect(&rect);
    }
    
    win = FrontWindow();
    if( (win==CanvWin) || (win==CmndWin) )
    {   row = TermYPos + ScrlStart;
        if( row < TermRows )
        {   SetCaretPos(TermXPos*CharWide,row*CharSkip);
            TermCursor = True;
            ShowCaret();
        } else 
        {   TermCursor = False;
            HideCaret();
        }
    } else
    {   TermCursor = False;
        HideCaret();
    }
    
    /* Validate CmndWin */
    ValidRect(&CmndWin->portRect);
}


void AdviseUpdate( int item )
{
    if( item == AdvName )
        EnableMenus( !DisableMenu );
}


void RefreshScreen( void )
{
    int ReDrawFlagSave;
    ReDrawFlag &= ~RFTransZ;
    
    if( ReDrawFlag )
    {   if( ReDrawFlag & RFReSize )
            ReSizeScreen();
            
        if( ReDrawFlag & RFColour )
        {   ClearImage();
            DefineColourMap();
        }
        
        NextReDrawFlag = 0;
        if( Database )
        {   BeginWait();
            if( ReDrawFlag & RFApply )
                ApplyTransform();
            DrawFrame();

            TransferImage();
            EndWait();
        } else
        {   ClearBuffers();
            ClearImage();
        }
        if ((ReDrawFlagSave & RFApply) && record_on[0] && !RecordPause ) {
	      WriteMovieFrame();
	      record_frame[0]++;
	      record_frame[1] = 0;
	    } else if ((ReDrawFlagSave & RFAppear) && record_on[1] && !RecordPause) {
	      WriteMovieFrame();
	      record_frame[0]++;
	      record_frame[1]++;
	      if ((double)(record_frame[1]) <= record_fps*record_dwell) {
	        NextReDrawFlag |= RFRefresh;
        } else {
	      	NextReDrawFlag = 0;
	      	record_frame[1] = 0;
	    }
	  }

    }
}


static void ConvertFilename( FSSpec *fss )
{
    char buffer[1024];
    register char *src;
    register char *dst;
    register int i;
    
    Str255 dirname;
    DirInfo dinfo;
    
    src = buffer;
    dinfo.ioDrParID = fss->parID;
    dinfo.ioNamePtr = dirname;
    do {
        dinfo.ioVRefNum = fss->vRefNum;
        dinfo.ioFDirIndex = -1;
        dinfo.ioDrDirID = dinfo.ioDrParID;
#ifdef USEOLDROUTINENAMES
        PBGetCatInfo((CInfoPBPtr)&dinfo,0);
#else        
        PBGetCatInfoSync((CInfoPBPtr)&dinfo);
#endif
        
        *src++ = ':';
        for( i=dirname[0]; i; i-- )
            *src++ = dirname[i];
    } while( dinfo.ioDrDirID != 2 );
    
    /* Reverse the file path! */
    dst = Filename;
    while( src != buffer )
        *dst++ = *(--src);
    for( i=1; i<=fss->name[0]; i++ )
        *dst++ = fss->name[i];
    *dst = '\0';
}
 
static void HelpScreen()
{
    DialogPtr dlg;
    short item;
        
    dlg = GetNewDialog(177,(Ptr)0,(WindowPtr)-1);
    SetDialogDefaultItem(dlg,1);
    
    /* Display Dialog Box! */    
    ShowWindow(dlg);
    do {
#ifdef __CONDITIONALMACROS__
        ModalDialog((ModalFilterUPP)0,&item);
#else
        ModalDialog((ProcPtr)0,&item);
#endif
    } while( item != 1 );
#ifdef USEOLDROUTINENAMES
    DisposDialog(dlg);
#else
    DisposeDialog(dlg);
#endif
}

void WriteNumberString(int i) {
  char buffer[80];
  sprintf(buffer," %x ",i);
  WriteString(buffer);
  return;
}

static void Register( void ) {
  if (LaunchBrowserWithURL("http://www.rasmol.org/register.shtml"))
     HelpScreen();
  return;
}

static void Donate( void ) {
  if (LaunchBrowserWithURL("http://www.rasmol.org/donate.shtml"))
     HelpScreen();
  return;
}


static size_t DetermineApplicationIdentifier( char * aid, size_t maxlen ) {


  Str255 macname;
  char * src, * dst;
    
  dst = aid;
  if (!GetMacName(macname) ) { 	
    src = 1+(char *)macname;
    while(macname[0]) {*dst++ = *src++; macname[0]--;}
    *dst = '\0';
  }
  
  return dst-aid;
	
}


static int getraid ( char * aid, size_t maxlen, char * langstr, size_t maxlstr ) {
  Str255 buffer;
  Str255 username;
  char * src, *dst;
  int charlen;
  int sind;
  
  
  if (!GetUserName(username)) {
     if (!(sind = FindPreferenceString(username,RASMOL_AID_UID))) {
       if (!(sind = SetPreferenceString(username,RASMOL_AID_UID,0))) {
       	  sind = RASMOL_AID_IND;
       }
  	 }
  }
  
  *langstr = '\0';
  if (GetPreferenceString(buffer,RASMOL_LANG_ID,sind)) {
    src = ((char *)buffer)+1;
    dst = langstr;
    charlen = buffer[0];
    if (charlen >= maxlstr) charlen = maxlstr-1;
    while( charlen > 0 )  {
      *dst++ = *src++;
      charlen--;
    }
    *dst = '\0';
  }

  if (GetPreferenceString(buffer,RASMOL_AID_ID,sind)) {
    src = ((char *)buffer)+1;
    dst = aid;
    charlen = buffer[0];
    if (charlen >= maxlen) charlen = maxlen-1;
    while( charlen > 0 )  {
      *dst++ = *src++;
      charlen--;
    }
    *dst = '\0';
    return dst-aid+strlen(langstr);
  }
  *aid = '\0';
  return 0;
  	
}

static int setraid ( const char * aid, const char * langstr ) {
  Str255 buffer;
  Str255 username;
  int sind;
  
  if (!GetUserName(username)) {
     if (!(sind = FindPreferenceString(username,RASMOL_AID_UID))) {
       if (!(sind = SetPreferenceString(username,RASMOL_AID_UID,0))) {
       	  sind = RASMOL_AID_IND;
       }
  	 }
  }
  if (SetPreferenceString(tostr255(buffer,aid),RASMOL_AID_ID,sind)
    && SetPreferenceString(tostr255(buffer,langstr),RASMOL_LANG_ID,sind)){
    return strlen(aid) + strlen(langstr);
  }	else {
    return 0;
  }

}

void UpdateLanguage( void ) {

  char filaid[255];
  char fillang[81];

  if (getraid(filaid, 255, fillang, 81))
    setraid(filaid,lang2str(Language));
}


static char filaid[1025];
static char macaid[1025];

static void HandleAboutDialog( void )
{
    register char *fpu;
    register char *src;
    register char *dst;
    register int len;
    char fillang[81];
    
    Str255 temp;
    Str255 buffer;
    DialogPtr dlg;
    Handle hand;
    long reply;
    short item, jtem;
    Rect rect;
    
    dlg = GetNewDialog(DLG_ABOUT,(Ptr)0,(WindowPtr)-1);
    SetDialogDefaultItem(dlg,1);

    
    /* Fix dialog localized text */
    
#ifdef USEOLDROUTINENAMES
    GetDItem(dlg,DLG_ABOUT_REGISTER,&item,&hand,&rect);
    SetCTitle((ControlHandle)hand,tostr255(buffer,MsgStrs[StrRegister]); 
#else
    GetDialogItem(dlg,DLG_ABOUT_REGISTER,&item,&hand,&rect);
    SetControlTitle((ControlRef)hand,tostr255(buffer,MsgStrs[StrRegister])); 
#endif
#ifdef USEOLDROUTINENAMES
    GetDItem(dlg,DLG_ABOUT_DONATE,&item,&hand,&rect);
    SetCTitle((ControlHandle)hand,tostr255(buffer,MsgStrs[StrDonate]));
#else
    GetDialogItem(dlg,DLG_ABOUT_DONATE,&item,&hand,&rect);
    SetControlTitle((ControlRef)hand,tostr255(buffer,MsgStrs[StrDonate]));
#endif
#ifdef USEOLDROUTINENAMES
    GetDItem(dlg,DLG_ABOUT_NOSHOW,&item,&hand,&rect);
    SetCTitle((ControlHandle)hand,tostr255(buffer,MsgStrs[StrNoShow]);
#else
    GetDialogItem(dlg,DLG_ABOUT_NOSHOW,&item,&hand,&rect);
    SetControlTitle((ControlRef)hand,tostr255(buffer,MsgStrs[StrNoShow]));
#endif
    
    /* See if noshow button should be checked */
    if (getraid(filaid, 1025, fillang, 81)
      && DetermineApplicationIdentifier(macaid, 1025)
      && !strncmp(filaid,macaid,1024)) {
#ifdef USEOLDROUTINENAMES
      SetCtlValue((ControlRef)hand,1);
#else
      SetControlValue((ControlRef)hand,1);
#endif
    }


#ifdef USEOLDROUTINENAMES
    GetDItem(dlg,DLG_ABOUT_WARRANTY,&item,&hand,&rect);
    SetIText(hand,tostr255(buffer,MsgStrs[StrWarranty]));
#else
    GetDialogItem(dlg,DLG_ABOUT_WARRANTY,&item,&hand,&rect);
    SetDialogItemText(hand,tostr255(buffer,MsgStrs[StrWarranty]));
#endif



    
    /* System Information! */
    dst = (char*)&buffer[1];
    Gestalt(gestaltPhysicalRAMSize,&reply);
    reply = (long)reply>>10;
   
    if( reply >= (long)1024 )
    {   len = sprintf(dst,"%ldMb ",reply>>10);
    } else len = sprintf(dst,"%ldKb ",reply);
    dst += len;
    
    Gestalt(gestaltMachineType,&reply);
    GetIndString(temp,kMachineNameStrID,(short)reply);
    for( len=1; len<=temp[0]; len++ ) 
        *dst++ = temp[len];        
    
    if( Gestalt(gestaltAUXVersion,&reply) )
    {   for( src=" (System "; *src; src++ )
            *dst++ = *src;
            
        Gestalt(gestaltSystemVersion,&reply);
        *dst++ = (char)((reply>>8)&0x0f) + '0';  *dst++ = '.';
        *dst++ = (char)((reply>>4)&0x0f) + '0';  *dst++ = '.';
        *dst++ = (char)(reply&0x0f) + '0';       *dst++ = ')';
    } else /* A/UX */
        for( src=" (A/UX)"; *src; src++ )
            *dst++ = *src;
            
    len = dst - (char*)&buffer[1];
    buffer[0] = (unsigned char)len;
#ifdef USEOLDROUTINENAMES    
    GetDItem(dlg,DLG_ABOUT_MACTYPE,&item,&hand,&rect);
    SetIText(hand,buffer);
#else
    GetDialogItem(dlg,DLG_ABOUT_MACTYPE,&item,&hand,&rect);
    SetDialogItemText(hand,buffer);
#endif
    
    /* Machine Information! */
    dst = (char*)&buffer[1];
    if( Gestalt(gestaltNativeCPUtype,&reply) )
    {   /* NativeCPUtype not available! */
        Gestalt(gestaltProcessorType,&reply);
        switch( reply )
        {   case(gestalt68000):  src = "MC68000"; break;
            case(gestalt68010):  src = "MC68010"; break;
            case(gestalt68020):  src = "MC68020"; break;
            case(gestalt68030):  src = "MC68030"; break;
            case(gestalt68040):  src = "MC68040"; break;
            default:   src = "Unknown processor";
        }
    } else switch( reply )
        {   case(gestaltCPU68000):  src = "MC68000";  break;
            case(gestaltCPU68010):  src = "MC68010";  break;
            case(gestaltCPU68020):  src = "MC68020";  break;
            case(gestaltCPU68030):  src = "MC68030";  break;
            case(gestaltCPU68040):  src = "MC68040";  break;
            case(gestaltCPU601):    src = "PPC601";   break;
            case(gestaltCPU603):    src = "PPC603";   break;
            case(gestaltCPU604):    src = "PPC604";   break;
            case(gestaltPPC603e):   src = "PPC603e";  break;
            case(gestaltPPC603ev):  src = "PPC603ev"; break;
            case(gestaltG3):        src = "G3";       break;
            case(gestaltG4):
        	case(gestaltG4x):       src = "G4";       break;
            case(gestaltPPC604e):   src = "PPC604e";  break;
            default:   sprintf((char*)temp,"Unkown processor (0x%04x)",reply);
                       src = (char*)temp;
        }

    if( *src == 'M' )
    {   Gestalt(gestaltFPUType,&reply);
        switch( reply )
        {   default:               fpu=" unknown";  break;
            case(gestalt68881):    fpu=" 68881";    break;
            case(gestalt68882):    fpu=" 68882";    break;
            case(gestalt68040FPU): fpu=" internal"; break;
            case(gestaltNoFPU):    
                        fpu="out";
                        if( !strcmp(src,"MC68040") )
                            src = "MC68LC040";       
                        break;
        }
    } else if( *src != 'U' )
        fpu = " internal";
    
    while( *src ) *dst++ = *src++;
    for( src=" with"; *src; src++ )
        *dst++ = *src;
    while( *fpu ) *dst++ = *fpu++;
    for( src=" maths coprocessor"; *src; src++ )
        *dst++ = *src;
        
    len = dst - (char*)&buffer[1];
    buffer[0] = (unsigned char)len;
#ifdef USEOLDROUTINENAMES
    GetDItem(dlg,DLG_ABOUT_CPUTYPE,&item,&hand,&rect);
    SetIText(hand,buffer);
#else
    GetDialogItem(dlg,DLG_ABOUT_CPUTYPE,&item,&hand,&rect);
    SetDialogItemText(hand,buffer);
#endif
    /* Display Dialog Box! */    
    ShowWindow(dlg);
    do {
#ifdef __CONDITIONALMACROS__
        ModalDialog((ModalFilterUPP)0,&item);
#else
        ModalDialog((ProcPtr)0,&item);
#endif
        if ( item == DLG_ABOUT_NOSHOW ) {
#ifdef USEOLDROUTINENAMES
    GetDItem(dlg,DLG_ABOUT_NOSHOW,&item,&hand,&rect);
    SetCtlValue((ControlHandle)hand,1-GetCtlValue((ControlHandle)hand));
#else
    GetDialogItem(dlg,DLG_ABOUT_NOSHOW,&item,&hand,&rect);
    SetControlValue((ControlHandle)hand,1-GetControlValue((ControlHandle)hand));
#endif
        }
    } while( item != DLG_ABOUT_OK 
      && item != DLG_ABOUT_DONATE
      && item != DLG_ABOUT_REGISTER);
    
    /* Get final noshow status */
    
#ifdef USEOLDROUTINENAMES
    GetDItem(dlg,DLG_ABOUT_NOSHOW,&jtem,&hand,&rect);
    if ( GetCtlValue((ControlHandle)hand)) {
#else
    GetDialogItem(dlg,DLG_ABOUT_NOSHOW,&jtem,&hand,&rect);
    if ( GetControlValue((ControlHandle)hand)) {
#endif
      DetermineApplicationIdentifier(macaid, 1025);
    } else {
      strcpy(macaid,"SHOWME");	
    }
    setraid(macaid,lang2str(Language));
    
#ifdef USEOLDROUTINENAMES
    DisposDialog(dlg);
#else
    DisposeDialog(dlg);
#endif

    if (item == DLG_ABOUT_DONATE) {
       Donate();
       ShowAbout = 1;
    }
    if (item == DLG_ABOUT_REGISTER) {
       Register();
       ShowAbout = 1;
    }
}


static void PasteCommandText( void )
{
    register Handle hand;
    register long i,len;
    register char *ptr;
    register char ch;
    long offset;
    
    hand = NewHandle(0);
    len = GetScrap(hand,'TEXT',&offset);
    if( len > 0 )
    {   HLock(hand);
        ptr = (char*)*hand;
        for( i=0; i<len; i++ )
        {   ch = *ptr++;
            if( ch >= ' ' )
            {   ProcessCharacter(ch);
            } else if( (ch==0x0d) || (ch==0x0a) )
            {   ProcessCharacter(ch);
                if( !ExecuteCommand() )
                {   ResetCommandLine(0);
                } else RasMolExit();
            } else if( ch>=' ' )
                ProcessCharacter(ch);
        }
        HUnlock(hand);
    }
}


pascal short OpenDlgHook( short item,  DialogPtr dialog, void *data )
{
    Handle hand;
    short type;
    Rect rect;

    if( ((DialogPeek)dialog)->window.refCon != sfMainDialogRefCon )
        return( item );
 
    if( item == sfHookFirstCall )
    {   item = sfHookNullEvent;
#ifdef USEOLDROUTINENAMES
        GetDItem(dialog,10,&type,&hand,&rect);
        SetCtlValue((ControlHandle)hand,DialogFormat);
#else
        GetDialogItem(dialog,10,&type,&hand,&rect);
        SetControlValue((ControlHandle)hand,DialogFormat);
#endif
    } else if( item == 10 )
    {   item = sfHookNullEvent;
#ifdef USEOLDROUTINENAMES
        GetDItem(dialog,10,&type,&hand,&rect);
        DialogFormat = GetCtlValue((ControlHandle)hand);
#else
        GetDialogItem(dialog,10,&type,&hand,&rect);
        DialogFormat = GetControlValue((ControlHandle)hand);
#endif
    }
    return item;
}


pascal short SaveDlgHook( short item, DialogPtr dialog, void *data )
{
    Handle hand;
    short type;
    Rect rect;

    if( ((DialogPeek)dialog)->window.refCon != sfMainDialogRefCon )
        return item;
    
    if( item == sfHookFirstCall )
    {   item = sfHookNullEvent;
#ifdef USEOLDROUTINENAMES
        GetDItem(dialog,13,&type,&hand,&rect);
        SetCtlValue((ControlHandle)hand,DialogFormat);
#else
        GetDialogItem(dialog,13,&type,&hand,&rect);
        SetControlValue((ControlHandle)hand,DialogFormat);
#endif
    } else if( item == 13 )
    {   item = sfHookNullEvent;
#ifdef USEOLDROUTINENAMES
        GetDItem(dialog,14,&type,&hand,&rect);
        DialogFormat = GetCtlValue((ControlHandle)hand);
#else
        GetDialogItem(dialog,13,&type,&hand,&rect);
        DialogFormat = GetControlValue((ControlHandle)hand);
#endif
    }
    return item;
}


static int HandleFileOpen( void )
{
    register int format;
    StandardFileReply reply;
    SFTypeList types;
    Point pnt;
    
    /* File Types */
    types[0]='TEXT';
    types[1]='RSML';
    types[2]='mMOL';
    types[3]='????';

    DialogFormat = 1;
    pnt.v = pnt.h = -1;
/*  CustomGetFile( NULL, 4, types, &reply, 172, pnt,   */
/*    For use in Mac OS X's Classic, remove the filter */
    CustomGetFile( NULL, -1, types, &reply, 172, pnt,
#ifdef __CONDITIONALMACROS__
                   OpenDlgHookPtr,
#else
                   (DlgHookYDProcPtr)OpenDlgHook,
#endif 
                   NULL, 0, NULL, NULL );
    
    if( reply.sfGood )
    {   ConvertFilename( &reply.sfFile );
        switch( DialogFormat )
        {   case(1):  format = FormatPDB;      break;
            case(2):  format = FormatAlchemy;  break;
            case(3):  format = FormatMol2;     break;
            case(4):  format = FormatMDL;      break;
            case(5):  format = FormatXYZ;      break;
            case(6):  format = FormatCharmm;   break;
            case(7):  format = FormatMOPAC;    break;
            case(8):  format = FormatCIF;      break;
            case(9):      
                      strcpy(CurLine,"script ");
		              CurLine[MAXBUFFLEN-1]='\0';
		              strncpy(CurLine+7,Filename,MAXBUFFLEN-8);
		              /* WriteString(CurLine); */
		              return 1;
                      break;
        }
        
        FetchFile(format,True,Filename);
        DefaultRepresentation();
    }
    return 0;
}


static void HandleFileSave( void )
{
    StandardFileReply reply;
    Point pnt;
    
    DialogFormat = 1;
    pnt.v = pnt.h = -1;
    CustomPutFile("\pSave Coordinate File:","\p",&reply,173,pnt,
#ifdef __CONDITIONALMACROS__
                   SaveDlgHookPtr,
#else
                   (DlgHookYDProcPtr)SaveDlgHook, 
#endif
                   NULL, 0, NULL, NULL );
    
    if( reply.sfGood )
    {   ConvertFilename( &reply.sfFile );
        switch( DialogFormat )
        {   default:
            case(1): SavePDBMolecule(Filename);      break;
            case(2): SaveAlchemyMolecule(Filename);  break;
            case(3): SaveMDLMolecule(Filename);      break;
            case(4): SaveCIFMolecule(Filename);      break;
        }
    }
}


static void HandleExportMenu( int item )
{
    StandardFileReply reply;
    register unsigned char *ptr;
    register int resid;
    Point pnt;
    
    switch( item )
    {   case(1):  resid=0;   ptr="\pSave Microsoft BMP File:"; break;
        case(2):  resid=0;   ptr="\pSave GIF Image:";          break;
		case(3):  resid=0;   ptr="\pSave IRIS RGB:";           break;
        case(4):  resid=175; ptr="\pSave Portable PixMap:";    break;
        case(5):  resid=176; ptr="\pSave SUN Rasterfile:";     break;
        case(6):  resid=174; ptr="\pSave PostScript File:";    break;
        case(7):  resid=0;   ptr="\pSave PICT Image:";         break;
        case(8):  resid=174; ptr="\pSave Vector PS File:";     break;
        case(9):  resid=0;   ptr="\pSave Molscript File:";     break;
        case(10):  resid=0;   ptr="\pSave Kinemage File:";     break;
        case(11):  resid=0;   ptr="\pSave POVRay 3 File:";     break;
        case(12):  resid=0;   ptr="\pSave VRML File:";         break;
        case(13):  resid=0;   ptr="\pSave Ramachandran PP:";   break;
        case(14):  resid=0;   ptr="\pSave Raster3D script:";   break;
        case(15):  resid=0;   ptr="\pSave RasMol Script:";     break;
        default:  return;
    }
    
    if( resid )
    {   DialogFormat = 1;
        if (item == 8) DialogFormat = 3;
        pnt.v = pnt.h = -1;
        CustomPutFile( ptr, "\p", &reply, resid, pnt,
#ifdef __CONDITIONALMACROS__
                       SaveDlgHookPtr,
#else
                      (DlgHookYDProcPtr)SaveDlgHook,
#endif 
                      NULL, 0, NULL, NULL );
    } else StandardPutFile( ptr, "\p", &reply );
    if( !reply.sfGood ) return;
    
    ConvertFilename( &reply.sfFile );
    switch( item )
    {   case(1):  WriteBMPFile(Filename);             break;
        case(2):  WriteGIFFile(Filename);             break;
        case(3):  WriteIRISFile(Filename);            break;
        case(4):  
                  if( DialogFormat == 1)
                  {  WritePPMFile(Filename,True);
                  } else 
                     WritePPMFile(Filename,False);    break;
        case(5):  
                  if( DialogFormat == 1)
                  {  WriteRastFile(Filename,True);
                  } else 
                     WriteRastFile(Filename,False);   break;
        case(6):
        case(8):  if( DialogFormat == 1 )
                  {   WriteEPSFFile(Filename,True,True);
                  } else if( DialogFormat == 2 )
                  {   WriteEPSFFile(Filename,False,True); 
                  } else /* DialogFormat == 3 */
                      WriteVectPSFile(Filename);
                  break;
        case(7):  WritePICTFile(Filename);            break;
                 
		case(9):  WriteMolScriptFile(Filename);       break;
		case(10): WriteKinemageFile(Filename);        break;
		case(11): WritePOVRay3File(Filename);         break;
		case(12): WriteVRMLFile(Filename,0);          break;
		case(13): WritePhiPsiAngles(Filename,-1);     break;
		case(14): WriteR3DFile(Filename);             break;
		case(15): WriteScriptFile(Filename);          break;

    }
}


static void HandleAppleMenu( int item )
{
    GrafPtr port;
    Str255 name;
    
    GetPort(&port);
#ifdef USEOLDROUTINENAMES    
    GetItem( GetMHandle(140), item, name );
#else
    GetMenuItemText( GetMenuHandle(140), item, name );
#endif
    OpenDeskAcc(name);
    SetPort(port);
}


static void HandleMenu( long hand )
{
    register int i,mask;
    register int menu;
    register int item;
    
    menu = HiWord(hand);
    if( menu )
    {   item = LoWord(hand);
        switch( menu )
        {   case(140):  /* Apple Menu */
        
                        switch( item ) {
                          case(1):  /* About */
                            HandleAboutDialog(); break;
                          case(2):  /* Help  */
                            HelpScreen(); break;
                          case(3):  /* Register */
                            Register(); break;
                          case(4):  /* Donate */
                            Donate(); break;
                          default: HandleAppleMenu(item);
                        }
                        break;
                      
            case(141):  /* File Menu */
                        switch( item )
                        {   case(1):  /* Open */
			              if( NumMolecules < MAX_MOLECULES )
                                          if (HandleFileOpen()) ExecuteCommand();
                                      break;
                            case(2):  /* Save As */
                                      if( Database )
                                          HandleFileSave();
                                      break;
                            case(3):  /* Close */
                                      ZapDatabase();
                                      break;
                                      
                            case(5):  /* Page Setup */
                                      PrOpen();
                                      if( !PrintHand )
                                      {   PrintHand = (THPrint)
                                              NewHandle(sizeof(TPrint));
                                          PrintDefault(PrintHand);
                                      }
                                      PrStlDialog(PrintHand);
                                      PrClose();
                                      break;
                                      
                            case(6):  /* Print */
                                      PrintImage();
                                      break;
                                      
                            case(8):  /* Quit */
                                      RasMolExit();
                                      
                                      
                            case(10): /* Molecule 1 */
                            case(11): /* Molecule 2 */
                            case(12): /* Molecule 3 */
                            case(13): /* Molecule 4 */
                            case(14): /* Molecule 5 */
                                      SelectMolecule(item-10);

                        }
                        break;
                      
            case(142):  /* Edit Menu */
                        switch( item )
                        {   case(1):  /* Undo */
                                      for( i=0; i<10; i++ )
                                          DialValue[i] = 0.0;
                                      CQRMSet(DialQRot,0.,0.,0.,0.);
                                      ReDrawFlag |= RFDials;
                                      ResetTransform();
                                      UpdateScrollBars();
                                      break;
                                      
                            case(3):  /* Copy */
                                      ClipboardImage();
                                      break;
                            
                            case(4):  /* Paste */
                                      PasteCommandText();
                                      break;
                                      
                            case(7):  /* Select All */
                                      mask = NormAtomFlag;
                                      if( HetaGroups ) mask |= HeteroFlag;
                                      if( Hydrogens )  mask |= HydrogenFlag;
                                      SelectZone(mask);
                                      break;
                        }
                        break;
                        
            case(143):  /* Display Menu */
                        switch( item )
                        {   case(1):  /* Wireframe */
                                      DisableSpacefill();
                                      EnableWireframe(WireFlag,0,0);
                                      SetRibbonStatus(False,0,0);
                                      DisableBackbone();
                                      ReDrawFlag |= RFRefresh;
                                      break;
                                      
                            case(2):  /* Backbone */
                                      DisableSpacefill();
                                      DisableWireframe();
                                      SetRibbonStatus(False,0,0);
                                      EnableBackbone(CylinderFlag,80,64);
                                      ReDrawFlag |= RFRefresh;
                                      break;
                                      
                            case(3):  /* Sticks */
                                      DisableSpacefill();
                                      if( MainAtomCount<256 )
                                      {   EnableWireframe(CylinderFlag,40,32);
                                      } else {
                                        EnableWireframe(CylinderFlag,80,64);
                                      }
                                      SetRibbonStatus(False,0,0);
                                      DisableBackbone();
                                      ReDrawFlag |= RFRefresh;
                                      break;
                                      
                            case(4):  /* Spheres */
                                      SetVanWaalRadius( SphereFlag);
                                      DisableWireframe();
                                      SetRibbonStatus(False,0,0);
                                      DisableBackbone();
                                      ReDrawFlag |= RFRefresh;
                                      break;
                                      
                            case(5):  /* Ball & Stick */
                                      SetRadiusValue(120, SphereFlag );
                                      EnableWireframe(CylinderFlag,40,32);
                                      SetRibbonStatus(False,0,0);
                                      DisableBackbone();
                                      ReDrawFlag |= RFRefresh;
                                      break;
                                      
                            case(6):  /* Ribbons */
                                      DisableSpacefill();
                                      DisableWireframe();
                                      SetRibbonStatus(True,RibbonFlag,0);
                                      DisableBackbone();
                                      ReDrawFlag |= RFRefresh;
                                      break;
                                      
                            case(7):  /* Strands */
                                      DisableSpacefill();
                                      DisableWireframe();
                                      SetRibbonStatus(True,StrandFlag,0);
                                      DisableBackbone();
                                      ReDrawFlag |= RFRefresh;
                                      break;

                            case(8):  /* Cartoons */
                                      DisableSpacefill();
                                      DisableWireframe();
                                      SetRibbonCartoons();
                                      DisableBackbone();
                                      ReDrawFlag |= RFRefresh;
                                      break;

                            case(9):  /* Molecular Surface */
                                      DrawSurf = True;
                                      ProbeRadius = 350;
                                      SetVanWaalRadius( SphereFlag | TouchFlag );
                                      DisableWireframe();
                                      SetRibbonStatus(False,0,0);
                                      DisableBackbone();
                                      CreateSurfaceBonds();
                                      ReDrawFlag |= RFRefresh;
                                      break;
                        }
                        break;              
                            
            case(144):  /* Colours Menu */
                        switch( item )
                        {   case(1):  /* Monochrome */
                                      MonoColourAttrib(255,255,255);
                                      ReDrawFlag |= RFColour;  break;
                            case(2):  /* CPK */
                                      CPKColourAttrib();
                                      ReDrawFlag |= RFColour;  break;
                            case(3):  /* Shapely */
                                      ShapelyColourAttrib();
                                      ReDrawFlag |= RFColour;  break;
                            case(4):  /* Group */
                                      ScaleColourAttrib( GroupAttr );
                                      ReDrawFlag |= RFColour;  break;
                            case(5):  /* Chain */
                                      ScaleColourAttrib( ChainAttr );
                                      ReDrawFlag |= RFColour;  break;
                            case(6):  /* Temperature */
                                      ScaleColourAttrib( TempAttr );
                                      ReDrawFlag |= RFColour;  break;
                            case(7):  /* Structure */
                                      StructColourAttrib();
                                      ReDrawFlag |= RFColour;  break;
                            case(8):  /* User */
                                      UserMaskAttrib(MaskColourFlag);
                                      ReDrawFlag |= RFColour;  break;
                            case(9):  /* Model */
                                      ScaleColourAttrib( ModelAttr );
                                      ReDrawFlag |= RFColour;  break;
                            case(10): /* Alt */
                                      ScaleColourAttrib( AltAttr );
                                      ReDrawFlag |= RFColour;  break;
                       }
                        break;
                                                    
            case(145):  /* Option Menu */
                        switch( item )
                        {   case(1):  /* Slabbing */
                                      ReDrawFlag |= RFRefresh;
                                      UseSlabPlane = !UseSlabPlane;
                                      if( UseSlabPlane )
                                          UseShadow = False;
                                      break;
                                      
                            case(2):  /* Hydrogens */
                                      mask = NormAtomFlag;
                                      if( HetaGroups )
                                          mask |= HeteroFlag;
                                      Hydrogens = !Hydrogens;
                                      ReDrawFlag |= RFRefresh;
                                      
                                      if( Hydrogens )
                                      {   SelectZone(mask|HydrogenFlag);
                                      } else RestrictZone(mask);
                                      break;
                                      
                            case(3):  /* Hetero Atoms */
                                      mask = NormAtomFlag;
                                      if( Hydrogens )
                                          mask |= HydrogenFlag;
                                      HetaGroups = !HetaGroups;
                                      ReDrawFlag |= RFRefresh;
                                      
                                      if( HetaGroups )
                                      {   SelectZone(mask|HeteroFlag);
                                      } else RestrictZone(mask);
                                      break;
                                      
                            case(4):  /* Specular */
                                      FakeSpecular = !FakeSpecular;
                                      ReDrawFlag |= RFColour;
                                      break;
                                      
                            case(5):  /* Shadows */
                                      ReDrawFlag |= RFRefresh;
                                      UseShadow = !UseShadow;
                                      if( UseShadow )
                                      {   ReviseInvMatrix();
                                          VoxelsClean = False;
                                          UseSlabPlane = False;
                                          ReAllocBuffers();
                                      }
                                      break;

                            case(6):  /* Stereo */
                                      if( UseStereo )
                                      {   StereoAngle = -StereoAngle;
                                          if ( StereoAngle > 0.0 ) {
                                            SetStereoMode(False);
                                          } else {
                                            SetStereoMode(True);
                                          }
                                      } else SetStereoMode(True);
                                      ReDrawFlag |= RFRefresh;
                                      break;

                            case(7):  /* Labels */
                                      LabelOptFlag = !LabelOptFlag;
                                      DefaultLabels(LabelOptFlag);
                                      ReDrawFlag |= RFRefresh;
                                      break;
                        }
                        break;
                        
            case(146):  /* Settings Menu */
                        switch( item )
                       {   case(1):  /* Pick Off */
                                     SetPickMode(PickNone); break;
                           case(2):  /* Pick Ident */
                                     SetPickMode(PickIdent); break;
                           case(3):  /* Pick Distance */
                                     SetPickMode(PickDist); break;
                           case(4):  /* Pick Monitor */
                                     SetPickMode(PickMonit); break;
                           case(5):  /* Pick Angle */
                                     SetPickMode(PickAngle); break;
                           case(6):  /* Pick Torsion */
                                     SetPickMode(PickTorsn); break;
                           case(7):  /* Pick Label */
                                     SetPickMode(PickLabel); break;
                           case(8):  /* Pick Centre */
                                     SetPickMode(PickCentr); break;
                           case(9):  /* Pick Coord */
                                     SetPickMode(PickCoord); break;
                           case(10): /* Pick Bond */
                                     SetPickMode(PickBond); break;
                           case(11): /* Rotate Bond */
                                     if ( BondSelected ) {
                                       RotMode = RotBond; break;
                                     }
                           case(12): /* Rotate Mol */
                                     RotMode = RotMol; UpdateScrollBars(); break;
                           case(13): /* Rotate All */
                                     RotMode = RotAll; UpdateScrollBars(); break;
                        }
                        break;
                        
            case(147):  /* Export Menu */
                        if( Database )
                            HandleExportMenu( item );
                        break;
                        
            case(148):  /* Windows Menu */
                        if( item == 1 )
                        {   SelectWindow(CanvWin);
                            ShowWindow(CanvWin);
                        } else {
                          if( item == 2 ) {
                            SelectWindow(CmndWin);
                            ShowWindow(CmndWin);
                          }
                        }
                        break;
        }
        HiliteMenu(0);
    }
}


static void AdjustMenus( void )
{
    register MenuHandle menu;
    register WindowPtr win;
    register int i;
    register int curitems;
    register unsigned char * src;
    register unsigned char * dst;
    unsigned char buffer[255];
    
    /* Refresh Menus */
    EnableMenus(!DisableMenu);
    
    /* Adjust File Menu */


#ifdef USEOLDROUTINENAMES
    menu = GetMHandle(141);
    curitems = CountMItems(menu);
    if (curitems > 8) {
      for (i = curitems; i > 8; i--) {
      /* warning -- this routine may not be available */
      DeleteMItem(menu,i);
      }
    }
#else
    menu = GetMenuHandle(141);
    curitems = CountMenuItems(menu);
    if (curitems > 8) {
      for (i = curitems; i > 8; i--) {
      DeleteMenuItem(menu,i);
      }
    }
#endif
    if (NumMolecules > 0 ) {
      DrawMoleculeList();
      buffer[0]=1;
      buffer[1]='-';
      buffer[2]='\0';
      AppendMenu(menu,(const unsigned char*)buffer);
      for (i = 0; i < NumMolecules; i++) {
        dst = buffer+1;
        src = (unsigned char *)MolName[i];
        while( *src && (dst<buffer+254) )
          *dst++ = *((unsigned char *)src++);
        buffer[0] = (unsigned char)((dst-buffer)-1);
        *dst = (unsigned char)'\0';
        AppendMenu(menu,(const unsigned char*)buffer);
        CheckItem(menu,10+i,(i==MoleculeIndex));
      }
    }
    
    /* Options Menu */
#ifdef USEOLDROUTINENAMES
    menu = GetMHandle(145);
#else
    menu = GetMenuHandle(145);
#endif
    CheckItem(menu,1,UseSlabPlane);
    CheckItem(menu,2,Hydrogens);
    CheckItem(menu,3,HetaGroups);
    CheckItem(menu,4,FakeSpecular);
    CheckItem(menu,5,UseShadow);
    CheckItem(menu,6,UseStereo);
    CheckItem(menu,7,LabelOptFlag);
    
    /* Settings Menu */
#ifdef USEOLDROUTINENAMES
    menu = GetMHandle(146);
#else
    menu = GetMenuHandle(146);
#endif
    CheckItem(menu,1,(PickMode==PickNone));
    CheckItem(menu,2,(PickMode==PickIdent));
    CheckItem(menu,3,(PickMode==PickDist));
    CheckItem(menu,4,(PickMode==PickMonit));
    CheckItem(menu,5,(PickMode==PickAngle));
    CheckItem(menu,6,(PickMode==PickTorsn));
    CheckItem(menu,7,(PickMode==PickLabel));
    CheckItem(menu,8,(PickMode==PickOrign));
    CheckItem(menu,9,(PickMode==PickCoord));
    CheckItem(menu,10,(PickMode==PickBond));
    CheckItem(menu,11,(RotMode==RotBond));
    CheckItem(menu,12,(RotMode==RotMol));
    CheckItem(menu,13,(RotMode==RotAll));    

    /* Windows Menu */
    win = FrontWindow();
#ifdef USEOLDROUTINENAMES
    menu = GetMHandle(148);
#else
    menu = GetMenuHandle(148);
#endif
    CheckItem(menu,1,(win==CanvWin));
    CheckItem(menu,2,(win==CmndWin));
}


static void ReSizeCanvWin( void )
{
    register int x,y;

    x = CanvWin->portRect.right - CanvWin->portRect.left;
    y = CanvWin->portRect.bottom - CanvWin->portRect.top;

    /* ClipRect(&CanvWin->portRect); */
    InvalRect(&CanvWin->portRect);
    
    HidePen();
    HideControl(HScroll);
    HideControl(VScroll);
    MoveControl(HScroll,-1,y-15);  SizeControl(HScroll,x-14,16);    
    MoveControl(VScroll,x-15,-1);  SizeControl(VScroll,16,y-14);
    ShowPen();
    
    ShowControl(HScroll);
    ShowControl(VScroll);
    DrawGrowIcon(CanvWin);

    XRange = x-15;   WRange = XRange>>1;
    YRange = y-15;   HRange = YRange>>1;
    ZRange = 20000;
    Range = MinFun(XRange,YRange);
    ReDrawFlag |= RFReSize;
    ClearImage();
}


static void GrowCanvWin( Point pos )
{
    register long size;
    register int x,y,dx;
    GrafPtr savePort;
    Rect rect;
    
#ifdef __CONDITIONALMACROS__
    rect.bottom = qd.screenBits.bounds.bottom;
    rect.right = qd.screenBits.bounds.right;
#else
    rect.bottom = screenBits.bounds.bottom;
    rect.right = screenBits.bounds.right;
#endif

    rect.left = 128;
    rect.top = 128;
    
    size = GrowWindow(CanvWin,pos,&rect);
    if( !size ) return; /* No Change! */
    
    GetPort(&savePort);
    SetPort(CanvWin);
    
    x = LoWord(size)-15;
    y = HiWord(size);
    
    /* Ensure Long Aligned */
    dx = x%4;
    if( dx ) x += 4-dx;

    SizeWindow(CanvWin,x+15,y,false);
    ReSizeCanvWin();
    SetPort(savePort);
}


static void ReSizeCmndWin( void )
{
    register int rows,cols;
    register int sr,er;
    register int x, y;
    
    x = CmndWin->portRect.right - CmndWin->portRect.left;
    y = CmndWin->portRect.bottom - CmndWin->portRect.top;
    
    InvalRect(&CmndWin->portRect);
    MoveControl(CmndScroll,x-15,-1);
    SizeControl(CmndScroll,16,y-14);    
    
    cols = (x-16)/CharWide;
    rows = y/CharSkip;
    
    /* Scroll to bottom */
    if( ScrlStart )
        SetTermScroll( ScrlMax );

    if( rows < TermRows )
    {   if( TermYPos >= rows )
        {   CmndStart += (TermYPos-rows) + 1;
            if( CmndStart > CmndRows )
                CmndStart -= CmndRows;
            TermYPos = rows-1;
        }
        
    } else if( rows > TermRows )
    {   sr = TermRows + CmndStart;
        if( sr >= CmndRows )
            sr -= CmndRows;
            
        er = CmndStart + rows;
        if( er >= CmndRows )
            er -= CmndRows;
            
        do {
            memset(TermScreen+sr*CmndCols,32,CmndCols);
            sr++; if( sr == CmndRows ) sr = 0;
        } while( sr != er );
    }
    
    if( cols > CmndCols )
    {   TermCols = CmndCols;
    } else TermCols = cols;
    TermRows = rows;
}


static void GrowCmndWin( Point pos )
{
    register long size;
    GrafPtr savePort;
    
    size = GrowWindow(CmndWin,pos,&CmndRect);
    if( !size ) return;  /* No Change! */
    
    GetPort(&savePort);
    SetPort(CmndWin);
    SizeWindow(CmndWin,LoWord(size),HiWord(size),false);
    ReSizeCmndWin();
    SetPort(savePort);
}


/*=========================*/
/* Mouse Handling Routines */
/*=========================*/

#define ShiftModifier   0x2200
#define CntrlModifier   0x9000
#define LButtModifier   0x0080  /* set if Mouse button up */
#define MButtModifier   0x0800  /* set if [Option] down  */
#define RButtModifier   0x4100  /* set if [Command] down */

static int GetStatus( int mask )
{
    register int status;

    /* Invert Button Bit */
    mask ^= LButtModifier;
    
    status = 0;                             
    if( mask & LButtModifier ) status |= MMLft;
    if( mask & MButtModifier ) status |= MMMid;
    if( mask & RButtModifier ) status |= MMRgt;
    if( mask & CntrlModifier ) status |= MMCtl;          
    if( mask & ShiftModifier ) status |= MMSft;
    return status;
}


/* [GSG 11/16/95] */
void SetHScroll(int pos)
{
    float temp = (pos/50.0)-1.0;

    if ( (RotMode == RotBond) && BondSelected) {
	  BondSelected->BRotValue = temp;
    } else {
      if ( RotMode == RotAll ) {
	    WorldDialValue[DialRY] = temp;
      } else {
	    DialValue[DialRY] = temp;
	  }
	}
    ReDrawFlag |= RFRotateY;
}
  
void SetVScroll(int pos)
{
    float temp = (pos/50.0)-1.0;

    if ( RotMode == RotAll ) {
	  WorldDialValue[DialRX] = temp;
    } else {
	  DialValue[DialRX] = temp;
	}
    ReDrawFlag |= RFRotateX;
}

pascal void CanvScrollProc( ControlHandle cntrl, short code )
{   
    register int pos;
    
#ifdef USEOLDROUTINENAMES
    pos = GetCtlValue(cntrl);
#else
    pos = GetControlValue(cntrl); 
#endif

    switch( code )
    {
#ifdef USEOLDROUTINENAMES
        case(inUpButton):    pos -= 5;   break;
        case(inDownButton):  pos += 5;   break;
        case(inPageUp):      pos -= 10;  break;
        case(inPageDown):    pos += 10;  break;
#else
        case(kControlUpButtonPart):    pos -= 5;   break;
        case(kControlDownButtonPart):  pos += 5;   break;
        case(kControlPageUpPart):      pos -= 10;  break;
        case(kControlPageDownPart):    pos += 10;  break;
#endif
        default:             return;       
    }
    
    if( pos>100 )
    {   pos -= 100;
    } else if( pos<0 )
        pos += 100;
        
#ifdef USEOLDROUTINENAMES        
    SetCtlValue(cntrl,pos);
#else
    SetControlValue(cntrl,pos);
#endif

    if( cntrl == HScroll )
    {   
        SetHScroll(pos); /* [GSG 11/16/95] */
    } else /* cntrl == VScroll */
    {   SetVScroll(pos); /* [GSG 11/16/95] */
    }
    RefreshScreen();
}


static void ClickCanvWin( EventRecord *ptr )
{
    register int code,pos;
    register int stat;

    ControlHandle hand;
    GrafPtr savePort;
    
    if( CanvWin == FrontWindow() )
    {   GetPort(&savePort);
        SetPort(CanvWin);
        
        GlobalToLocal(&ptr->where);
        code = FindControl(ptr->where,CanvWin,&hand);
        if( !code )
        {   stat = GetStatus(ptr->modifiers);
            ProcessMouseDown(ptr->where.h,ptr->where.v,stat);
            
#ifdef USEOLDROUTINENAMES            
        } else if( code == inThumb )   
        {   TrackControl(hand,ptr->where,0L);
            pos = GetCtlValue(hand);
#else
        } else if( code == kControlIndicatorPart )   
        {   TrackControl(hand,ptr->where,0L);
            pos = GetControlValue(hand);
#endif

            if( hand == HScroll )
            {   SetHScroll(pos); /* [GSG 11/16/95] */
	        /* DialValue[1] = (pos/50.0)-1.0;
		   ReDrawFlag |= RFRotateY; */
            } else /* hand == VScroll */
            {   SetVScroll(pos); /* [GSG 11/16/95] */
	        /* DialValue[0] = (pos/50.0)-1.0;
		   ReDrawFlag |= RFRotateX; */
            }
            RefreshScreen();
        } else TrackControl(hand,ptr->where,
#ifdef __CONDITIONALMACROS__
                         CanvScrollProcPtr);
#else
                         (ProcPtr)CanvScrollProc );
#endif
        SetPort(savePort);
    } else SelectWindow( CanvWin );
}


pascal void CmndScrollProc( ControlHandle cntrl, short code )
{
    switch( code )
    {   
#ifdef USEOLDROUTINENAMES
        case(inUpBotton):
#else
        case(kControlUpButtonPart):
#endif
                             if( ScrlStart < ScrlMax )
                             {   SetTermScroll((ScrlMax-ScrlStart)-1);
                                 PaintScreen();
                             }
                             break;
                             
#ifdef USEOLDROUTINENAMES
        case(inDownButton):
#else                             
        case(kControlDownButtonPart):  
#endif
                             if( ScrlStart > 0 )
                             {   SetTermScroll((ScrlMax-ScrlStart)+1);
                                 PaintScreen();
                             }
                             break;
                                 
#ifdef USEOLDROUTINENAMES
        case(inPageUp):
#else
        case(kControlPageUpPart):
#endif
                             if( ScrlStart < (ScrlMax-10) )
                             {   SetTermScroll((ScrlMax-ScrlStart)-10);
                                 PaintScreen();
                             }
                             break;
                             
#ifdef USEOLDROUTINENAMES
        case(inPageDown):
#else
        case(kControlPageDownPart):
#endif
                             if( ScrlStart > 10 )
                             {   SetTermScroll((ScrlMax-ScrlStart)+10);
                                 PaintScreen();
                             }
                             break;
    }
}


static void ClickCmndWin( EventRecord *ptr )
{
    register int code;
    ControlHandle hand;
    GrafPtr savePort;
    
    if( CmndWin == FrontWindow() )
    {   GetPort(&savePort);
        SetPort(CmndWin);
        
        GlobalToLocal(&ptr->where);
        code = FindControl(ptr->where,CmndWin,&hand);
#ifdef USEOLDROUTINENAMES
        if( code == inThumb )   
        {   TrackControl(CmndScroll,ptr->where,0L);
            SetTermScroll(GetCtlValue(CmndScroll));
#else 
        if( code == kControlIndicatorPart )
        {   TrackControl(CmndScroll,ptr->where,0L);
            SetTermScroll(GetControlValue(CmndScroll));
#endif
        } else if( code )
            TrackControl(CmndScroll,ptr->where,
#ifdef __CONDITIONALMACROS__
                         CmndScrollProcPtr);
#else
                         (ProcPtr)CmndScrollProc );
#endif
        SetPort(savePort);
    } else SelectWindow( CmndWin );
}


static void ZoomCanvWin( Point pos, int code )
{
    GrafPtr savePort;
    
    if( TrackBox(CanvWin,pos,code) )
    {   GetPort(&savePort);
        SetPort(CanvWin);
        /* EraseRect(&CanvWin->portRect); */
        ZoomWindow(CanvWin,code,true);
        ReSizeCanvWin();
        SetPort(savePort);
    }   
}


static void ZoomCmndWin( Point pos, int code )
{
    GrafPtr savePort;
                                    
    if( TrackBox(CmndWin,pos,code) )
    {   GetPort(&savePort);
        SetPort(CmndWin);
        EraseRect(&CmndWin->portRect);
        ZoomWindow(CmndWin,code,true);
        ReSizeCmndWin();
        SetPort(savePort);
     }
}


static void HandleMouseDownEvent( EventRecord *ptr )
{
    register long hand;
    register int code;
    WindowPtr win;
    GrafPtr savePort;
    
    code = FindWindow(ptr->where,&win);
    switch( code )
    {   case(inMenuBar):    AdjustMenus();
                            hand = MenuSelect(ptr->where);
                            if( !IsPaused )
                                HandleMenu( hand );
                            break;
                            
        case(inSysWindow):  SystemClick(ptr,win);
                            break;

        case(inContent):    // Need to recheck that ptr is in the window
                            GetPort(&savePort);
                            SetPort(CanvWin);
                            GlobalToLocal(&ptr->where);
                            if((win == CmndWin) || ( win == CanvWin && 
                               ptr->where.h >=0 && ptr->where.h<=XRange &&
                               ptr->where.v >=0 && ptr->where.v<=YRange)) {
                              LocalToGlobal(&ptr->where);
                              SetPort(savePort);
                              if( win == CanvWin )
                              {   ClickCanvWin( ptr );
                              } else {
                                if( win == CmndWin )
                                {   ClickCmndWin( ptr );
                                }
                              }
                              break;
                            } else {
                              if (win == CanvWin &&
                                  ptr->where.h >=XRange && ptr->where.h<=XRange+24 &&
                                  ptr->where.v >=YRange && ptr->where.v<=YRange+24) {
                                  LocalToGlobal(&ptr->where);
                                  SetPort(savePort);
                                  GrowCanvWin( ptr->where );
                                  break;
                              }
                            }
                            SetPort(savePort);
                            break;
        
        case(inDrag):       if( (win==CanvWin) 
                              || (win==CmndWin) 
                              )
#ifdef __CONDITIONALMACROS__
                                DragWindow(win,ptr->where,&qd.screenBits.bounds);
#else
                                DragWindow(win,ptr->where,&screenBits.bounds);
#endif
                            break;
                             
        case(inGrow):       if( win==CanvWin )
                            {   GrowCanvWin( ptr->where );
                            } else if( win==CmndWin )
                                GrowCmndWin( ptr->where );
                            break;
        
        case(inGoAway):     if( (win==CanvWin) 
                              || (win==CmndWin)
                              )
                                if( TrackGoAway(win,ptr->where) )
                                    HideWindow(win);
                            break;
                            
        case(inZoomIn):     
        case(inZoomOut):    if( win==CanvWin )
                            {   ZoomCanvWin(ptr->where,code);
                            } else if( win==CmndWin )
                                ZoomCmndWin(ptr->where,code);
                            break;
    }
}


static void HandleMouseUpEvent( EventRecord *ptr )
{
    register int stat;
    GrafPtr savePort;
    
    if( CanvWin == FrontWindow() )
    {   GetPort(&savePort);
        SetPort(CanvWin);
        GlobalToLocal(&ptr->where);
        SetPort(savePort);
                                    
        stat = GetStatus(ptr->modifiers);
        ProcessMouseUp(ptr->where.h,ptr->where.v,stat);
    }
}


static void HandleMoveEvent( int mask )
{
    register WindowPtr win;
    GrafPtr savePort;
    Point pos;
    
    win = FrontWindow();
    if( win == CanvWin )
    {   GetPort(&savePort);
        SetPort(CanvWin);
        GetMouse(&pos);
        
        ProcessMouseMove(pos.h,pos.v,GetStatus(mask));

        if( MouseCaptureStatus || ((pos.h>0) && (pos.v>0) &&
              (pos.v<CanvWin->portRect.bottom-15) &&
              (pos.h<CanvWin->portRect.right-15)) )
        {   SetCursor(*CanvCursor);
        } else ArrowCursor;
        SetPort(savePort);
    } else if( win == CmndWin )
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


static int MacKeyMap[32] = { 0x00, 0x01, 0x00, 0x0d, 0x05, 0x00, 0x00, 0x00,
                             0x08, 0x00, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00,
                             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                             0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x10, 0x0e };
                              
static void HandleEvents( void )
{
    register int key,row;
    register long hand;

    EventRecord event;
    GrafPtr savePort;
    WindowPtr win;

    SystemTask();
    if( GetNextEvent(everyEvent,&event) )
    {   switch( event.what )
        {   case(mouseDown):    HandleMouseDownEvent(&event);
                                break;
                                
            case(mouseUp):      HandleMouseUpEvent(&event);
                                break;
            
            case(autoKey):
            case(keyDown):      key = (char)(event.message & charCodeMask);
                                if( event.modifiers & cmdKey )
                                {   AdjustMenus();
                                    hand = MenuKey(key);
                                    if( !IsPaused )
                                        HandleMenu(hand);
                                } else if( key<32 )
                                {   if( !(event.modifiers & controlKey) )
                                        key = MacKeyMap[key];
                                    if( ProcessCharacter(key) )
                                        if( ExecuteCommand() )
                                            RasMolExit();
                                } else if( key==127 )
                                {   /* Forward Delete */
                                    ProcessCharacter(0x04);
                                } else ProcessCharacter(key);
                                break;
            
            case(keyUp):        break;
            
            case(updateEvt):    GetPort(&savePort);
                                win = (WindowPtr)event.message;
                                if( win == CanvWin )
                                {   SetPort(CanvWin);
                                    BeginUpdate(CanvWin);
                                    /* ActivatePalette(CanvWin); */
                                    DrawGrowIcon(CanvWin);
                                    
                                    /* Macintosh 128K ROMs and later.       */ 
                                    /* UpdtControl(CanvWin,CanvWin->visRgn); */
                                    DrawControls(CanvWin);
                                    
                                    /* CopyBits(PixMap);   */
                                    /* EraseRect(updRect);*/
                                    if( Database )
                                    {   TransferImage();
                                    } else ClearImage();
                                    
                                    EndUpdate(CanvWin);
                                } else if( win == CmndWin )
                                {   SetPort(CmndWin);
                                    BeginUpdate(CmndWin);
                                    PaintScreen();
                                    EndUpdate(CmndWin);
                                } 
                                SetPort(savePort);
                                break;
            
            case(activateEvt):  HiliteMenu(0);
                                win = (WindowPtr)event.message;
                                if( win==CanvWin )
                                {   DrawGrowIcon(CanvWin);
                                    if( event.modifiers & activeFlag )
                                    {   ShowControl(HScroll);
                                        ShowControl(VScroll);
                                    } else /* deactiveEvt */
                                    {   HideControl(HScroll);
                                        HideControl(VScroll);
                                    }
                                } else /* win == CmndWin */
                                {   DrawCmndGrowIcon();
                                    if( event.modifiers & activeFlag )
                                    {   ShowControl(CmndScroll);
                                    } else /* deactiveEvt */
                                        HideControl(CmndScroll);
                                }
                                
                                /* Caret Handling! */
                                win = FrontWindow();
                                if( (win==CanvWin) || (win==CmndWin) )
                                {   row = TermYPos + ScrlStart;
                                    if( row < TermRows )
                                    {   SetCaretPos( TermXPos*CharWide,
                                                     row*CharSkip );
                                        TermCursor = True;
                                        ShowCaret();
                                    } else
                                    {   TermCursor = False;
                                        HideCaret();
                                    }      
                                } else
                                {   TermCursor = False;
                                    HideCaret();
                                }                                
                                break;
                                
            case(kHighLevelEvent):
                                AEProcessAppleEvent(&event);
                                break;
                                
        }
    } else if( TermCursor )
        HandleCaret();
        
    HandleMoveEvent( event.modifiers );
    
    if( ReDrawFlag )
        RefreshScreen();
        ReDrawFlag = NextReDrawFlag;
    if( !CommandActive )
        ResetCommandLine(0);
    if( ShowAbout ) {
      ShowAbout = 0;
      HandleAboutDialog();
    }
}


static int HandleFileSpec( FSSpec *fss )
{
    register int format;
    register FILE *fp;
    FInfo info;
    
    FSpGetFInfo(fss,&info);
    if( info.fdType == 'RSML' )
    {   fp = fopen(Filename,"rb");
        if( fp )
        {   LoadScriptFile(fp,Filename);
            return True;
        } else return False;
    }
    
    /* if( Database )
       ZapDatabase(); */

    if( info.fdType == 'mMOL' )
    {      format = FormatMDL;
#ifdef CEXIOLIB
    } else if( (info.fdType == 'CEX0') ||
               (info.fdType == 'CEX1') )
    {      format = FormatCEX;
#endif
    } else format = FormatPDB;
        
    FetchFile(format,True,Filename);
    if( Database )
    {   DefaultRepresentation();
        return True;
    }
    return False;
}


/* Apple Event Handler Prototypes! */
pascal OSErr HandleAEOpenDoc( AppleEvent*, AppleEvent*, long );
pascal OSErr HandleAEQuitApp( AppleEvent*, AppleEvent*, long );
pascal OSErr HandleAEIgnore( AppleEvent*, AppleEvent*, long );


pascal OSErr HandleAEOpenDoc( AppleEvent *event, AppleEvent *reply, long ref )
{
    register OSErr stat;
    register long i;
    
    AEDescList list;
    AEKeyword keywd;
    DescType dtype;
    FSSpec fss;
    long count;
    Size size;

    /* Disable event while paused! */
    if( IsPaused ) return( noErr );

    stat = AEGetParamDesc(event,keyDirectObject,
                          typeAEList,&list);
    if( stat ) return( stat );
    
    stat = AEGetAttributePtr(event,keyMissedKeywordAttr,
                             typeWildCard, &dtype, 0, 0, &size );
    if( stat != errAEDescNotFound ) 
    {   AEDisposeDesc( &list );
        return( stat? stat : errAEEventNotHandled );
    }
    
    AECountItems( &list, &count );
    for( i=1; i<=count; i++ )
    {   stat = AEGetNthPtr(&list,i,typeFSS,&keywd,
                           &dtype,(Ptr)&fss,sizeof(fss),
                           &size);
        if( !stat )
        {   ConvertFilename(&fss);
            if( HandleFileSpec(&fss) )
            {   RefreshScreen();
                if( Database && ref )
                    PrintImage();
                break;
            }
        }
    }
    AEDisposeDesc( &list );         
    return noErr;
}


pascal OSErr HandleAEQuitApp( AppleEvent *event, AppleEvent *reply, long ref )
{
    UnusedArgument(event);
    UnusedArgument(reply);
    UnusedArgument(ref);

    RasMolExit();
    return noErr;
}


pascal OSErr HandleAEIgnore( AppleEvent *event, AppleEvent *reply, long ref )
{
    UnusedArgument(event);
    UnusedArgument(reply);
    UnusedArgument(ref);

    return noErr;
}


static void InitialiseApplication( void )
{
    register PScrapStuff ptr;
    
    /* Init Mac ToolBox */
#ifdef __CONDITIONALMACROS__
    InitGraf(&qd.thePort);
#else
    InitGraf(&thePort);
#endif

    InitCursor();
    InitFonts();
    InitWindows();
    InitMenus();
    TEInit();
    InitDialogs(0L);

    RasMolResFile = CurResFile();
    FlushEvents(everyEvent,0);
    MaxApplZone();
    
    /* Initialise Clipboard */
    ptr = InfoScrap();
    if( ptr && (ptr->scrapState<0) )
        ZeroScrap();
    
    /* Enable KeyUp Events  */
    SetEventMask(everyEvent);
    
#ifdef __CONDITIONALMACROS__
    /* Create Routine Descriptors */
    HandleAEIgnorePtr = NewAEEventHandlerProc(HandleAEIgnore);
    HandleAEOpenDocPtr = NewAEEventHandlerProc(HandleAEOpenDoc);
    HandleAEQuitAppPtr = NewAEEventHandlerProc(HandleAEQuitApp);
    CanvScrollProcPtr = NewControlActionProc(CanvScrollProc);
    CmndScrollProcPtr = NewControlActionProc(CmndScrollProc);
    OpenDlgHookPtr = NewDlgHookYDProc(OpenDlgHook);
    SaveDlgHookPtr = NewDlgHookYDProc(SaveDlgHook);

    /* Install Required Event Handlers */
    AEInstallEventHandler(kCoreEventClass,kAEOpenApplication,
                          HandleAEIgnorePtr, 0, false);
    AEInstallEventHandler(kCoreEventClass,kAEOpenDocuments,
                          HandleAEOpenDocPtr, 0, false);
    AEInstallEventHandler(kCoreEventClass,kAEPrintDocuments,
                          HandleAEOpenDocPtr, 1, false);
    AEInstallEventHandler(kCoreEventClass,kAEQuitApplication,
                          HandleAEQuitAppPtr, 0, false);

#else
    /* Install Required Event Handlers */
    AEInstallEventHandler(kCoreEventClass,kAEOpenApplication,
                          HandleAEIgnore, 0, false);
    AEInstallEventHandler(kCoreEventClass,kAEOpenDocuments,
                          HandleAEOpenDoc, 0, false);
    AEInstallEventHandler(kCoreEventClass,kAEPrintDocuments,
                          HandleAEOpenDoc, 1, false);
    AEInstallEventHandler(kCoreEventClass,kAEQuitApplication,
                          HandleAEQuitApp, 0, false);
#endif
}


static void InitDefaultValues( void )
{
    Interactive = True;

    ReDrawFlag = RFInitial;
    LabelOptFlag = False;
    CalcBondsFlag = True;
    CalcSurfFlag = False;
    AllowWrite = False;
}


int main( void )
{
    static char VersionStr[255];
    char fillang[81];

    Interactive = False;
    InitialiseApplication();
    InitDefaultValues();
    OpenDisplay(DefaultWide,DefaultHigh);
    InitTerminal();

    fillang[0]='\0';
    if (getraid(filaid, 1025, fillang, 81)
      && DetermineApplicationIdentifier(macaid, 1025)
      && !strncmp(filaid,macaid,1024)) {
      ShowAbout = 0;
    } else {
      ShowAbout = 1;
    }
    if (strlen(fillang) > 0) {
    	SwitchLang(str2lang(fillang));
    	TermLanguage = Language;
    } else {
    	SwitchLang(English);
    	TermLanguage = English;
    }

    sprintf (VersionStr,"%s\nVersion %s %s\n%s\n", 
             MAIN_COPYRIGHT, VERSION, 
             VER_DATE, VER_COPYRIGHT);
    


    
    WriteString("RasMol Molecular Renderer\n");
    WriteString("Roger Sayle, August 1995\n");
    WriteString(VersionStr);
    WriteString("*** See \"help notice\" for further notices ***\n");

#ifdef __powerc
    WriteString("[PowerPC Native]\n");
#endif

#ifdef EIGHTBIT
    WriteString("[8-bit version]\n\n");
#endif
#ifdef SIXTEENBIT
    WriteString("[16-bit version]\n\n");
#endif
#ifdef THIRTYTWOBIT
    WriteString("[32-bit version]\n\n");
#endif

    InitialiseCmndLine();
    InitialiseCommand();
    InitialiseTransform();
    InitialiseDatabase();
    InitialiseRenderer();
    InitialisePixUtils();
    InitialiseAbstree();
    InitialiseOutFile();
    InitialiseRepres();
    InitHelpFile();
    InitialiseMultiple(); /* [GSG 11/9/95] */
    InitialiseWBRotate();

    /* LoadInitFile(); */
    
    ResetCommandLine(1);
    RefreshScreen();
    ReDrawFlag = NextReDrawFlag;    

        
    while( True )
        HandleEvents();
}
