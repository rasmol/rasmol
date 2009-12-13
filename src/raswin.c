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
/* raswin.c
 $Log$
 Revision 1.8  2008/06/27 02:47:58  yaya
 Finished update of windows code for 32-bit color -- HJB

 Revision 1.7  2008/06/11 01:40:54  yaya
 Improve gradient for map surfaces and brighten image;
 Add parenthesized selections before all commands;
 Change saveSelection and loadSelection to
 SaveAtomSelection and LoadAtomSelection -- HJB

 Revision 1.6  2008/03/22 17:06:49  yaya
 Post release cleanup with credits to Ikonen in file headers. -- HJB

 Revision 1.5  2008/03/21 19:13:48  yaya
 Update documentation and comments -- HJB

 Revision 1.5  2008/03/17 03:01:31  yaya
 Update to agree with 2.7.4.2 release and T. Ikonen GTK mods -- HJB

 Revision 1.4  2008/03/17 01:32:41  yaya
 Add gtk mods by tpikonen, and intergate with 2.7.4.2 mods -- HJB

 Revision 1.3  2008/03/16 22:38:10  yaya
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

 Revision 1.2  2008/01/28 03:29:38  yaya
 Update CVS to RasMol_2.7.4.1 -- HJB

 Revision 1.2  2007/11/19 03:28:39  yaya
 Update to credits for 2.7.4 in manual and headers
 Mask code added -- HJB

 Revision 1.1.1.1  2007/03/01 01:16:33  todorovg
 Chinese working versio from rasmol_ru initial import

 Revision 1.13  2006/12/24 16:12:53  yaya
 Fix typos in raswin.c introduced in the prior patch. -- HJB

 Revision 1.10  2006/12/03 02:53:10  yaya
 Clean up compilation warnings in outfile.c
 Mods for about screen under Linux -- HJB

 Revision 1.9  2006/11/28 03:12:48  yaya
 Changes for Russian and About dialog in unix
 This is a variant tried under Mac OS X.  Changes
 for Linux still needed.  note that more work is
 needed on font selection. -- HJB

 Revision 1.8  2006/11/01 03:23:51  yaya
 Update NSIS windows installer for more script types and to fix
 misplaced script instructions for data files; add document and
 script icons directly in raswin.exe; add credit line to
 G. A. Pozhvanov in comments for Russian translations. -- HJB

 Revision 1.7  2006/10/30 15:18:12  yaya
 Add NSIS installer, make language sticky for windows and mac
 Set up RASMOLPATH environment variable on install -- HJB

 Revision 1.6  2006/10/21 18:22:00  yaya
 Correct logic for missing intermediate directories
 Change from RASWIN to RasWin -- HJB

 Revision 1.5  2006/10/20 13:53:02  yaya
 Move about dialog flag file RASWIN.FLG to APPDATA style directories
 Translate three "not founds" that had been missed before -- HJB

 Revision 1.4  2006/10/02 21:24:49  yaya
 Changes to allow disabling of about dialog using RASWIN.FLG flag file,
 Restore windows Help menu adding register and donate menu items
 Enable language support for about dialog -- HJB

 Revision 1.3  2006/09/18 00:30:31  yaya
 Add hooks for registration and donation and update icon -- HJB

 Revision 1.2  2006/09/17 10:53:56  yaya
 Clean up headers and start on code for X11 -- HJB

 Revision 1.1.1.1  2006/09/16 18:45:58  yaya
 Start of RasMol Russian Translation Project based on translations
 by Gregory A. Pozhvanov of Saint Petersburg State University -- HJB

 Revision 1.1.1.1  2006/06/19 22:05:14  todorovg
 Initial Rasmol 2.7.3 Import

 Revision 1.1  2004/05/07 19:46:16  yaya
 Initial revision

 Revision 1.2  2004/01/26 23:53:12  yaya
 *** empty log message ***

 Revision 1.1  2003/12/12 21:10:38  yaya
 Initial revision

 Revision 1.2  2001/02/08 01:14:46  yaya
 *** empty log message ***

 Revision 1.1  2001/01/31 02:13:45  yaya
 Initial revision

 Revision 1.6  2000/08/26 18:12:41  yaya
 Updates to header comments in all files

 Revision 1.5  2000/08/13 20:56:25  yaya
 Conversion from toolbar to menus

 Revision 1.4  2000/08/09 01:18:13  yaya
 Rough cut with ucb

 Revision 1.3  2000/08/03 18:32:42  yaya
 Parametrization for alt conformer bond radius

 Revision 1.2  2000/02/23 00:00:00  yaya
 Prelininary 2.7.2 build

 */

#define RASMOL
#include "rasmol.h"

#include <windows.h>
#include <shellapi.h>
#include <commdlg.h>
#include <direct.h>
#include <dde.h>
#include <process.h>

#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

#include "raswin.idm"
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
#include "multiple.h"
#include "tokens.h"
#include "vector.h"
#include "wbrotate.h"
#include "langsel.h"


#ifdef SOCKETS
#include <winsock.h>
#define WM_WINSOCK  WM_USER+1
#endif


/* Microsoft C vs Borland Turbo C */
#ifndef __TURBOC__
#define stricmp _stricmp
#define getcwd  _getcwd
#endif


#define TwoPi 2.0*PI
#define IsIdentChar(x)  ((isalnum(x))||((x)=='_')||((x)=='$'))


/*===========================*/
/* Microsoft Windows DDE IPC */
/*===========================*/

#define DefaultDDETimeOut 10000
#define MaxDDEAdviseNum   32
#define MaxDDEConvNum     8

#define ColdLink       0x01
#define WarmLink       0x02
#define HotLink        0x03
#define AckLink        0x04


typedef struct {
	    HWND  server;
	    HWND  client;
	    Byte  closed;
	} DDEConv;
	
typedef struct {
	    HANDLE data;
	    HWND  server;
	    HWND  client;
	    ATOM  atom;
	    Byte  mode;
	    Byte  item;
	    Byte  wait;
       } DDEAdvise;

static int DDETimeOut;
static DDEAdvise DDEAdviseData[MaxDDEAdviseNum];
static DDEConv DDEConvData[MaxDDEConvNum];
static int RasWinDDEReady;
static int DDEAdviseCount;
static int DDEConvCount;
static int firstpass=1;


#ifdef SOCKETS
/*===============================*/
/* Microsoft Windows Socket IPC  */
/*===============================*/

/* Supported Protocols */
#define ProtoRasMol   0x01

typedef struct {
        SOCKET socket;
        int protocol;
        int advise;
    } IPCConv;

#define MaxIPCConvNum     8
static IPCConv IPCConvData[MaxIPCConvNum];

static SOCKET SocketNo;
static int ServerPort;
static int UseSockets;
#endif


/*=============================*/
/* Generic Advise Information  */
/*=============================*/

#define AMNone         0x00
#define AMPickAtom     0x01
#define AMPickNumber   0x02
#define AMSelectCount  0x04
#define AMMolName      0x08
#define AMPickCoord    0x10

typedef struct {
        int bitmask;
        char *name;
    } AdviseType;

static AdviseType AdviseMap[ItemCount] = {
    { AMPickAtom,    "Pick"    },  /* AdvPickAtom    */
    { AMPickNumber,  "PickNo"  },  /* AdvPickNumber  */
    { AMSelectCount, "Count"   },  /* AdvSelectCount */
    { AMMolName,     "Name"    },  /* AdvName        */
    { AMNone,        "Ident"   },  /* AdvIdent       */
    { AMNone,        "Class"   },  /* AdvClass       */
    { AMNone,        "Image"   },  /* AdvImage       */
    { AMPickCoord,   "PickXYZ" }   /* AdvPickCoord   */
        };

static char AdviseBuffer[256];
static int AdviseLen;


/*================================*/
/* Command Line Terminal Emulator */
/*================================*/

#define CmndSize   (CmndRows*CmndCols)
#define ScrlMax    80
#define CmndRows   160
#define CmndCols   80


static int CmndStart;
static int ScrlStart;
static int TermCursor;
static int CharWide,CharHigh;
static int TermXPos,TermYPos;
static int TermRows,TermCols;
static char __far *TermScreen;
static HFONT TermFont;
static HWND CmndWin;

static int PointX,PointY;
static int InitX,InitY;
static int HeldButton;
static int FileFormat;

static char snamebuf[1024];
static char fnamebuf[1048];
static char fpnamebuf[1048];
static char ifilters[1024];
static char ofilters[2048];
static OPENFILENAME ofn1;
static OPENFILENAME ofn2;
static HINSTANCE hInstance;
static char Text[256];
static char filaid [1025];
static char macaid [1025];
static char fillang [81];


#ifdef _WIN32
LRESULT CALLBACK MainCallB(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK CmndCallB(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK DDECallB( HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK AboutCallB(  HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK InfoCallB(   HWND, UINT, WPARAM, LPARAM);
#else
LONG FAR PASCAL MainCallB( HWND, UINT, WPARAM, LPARAM);
LONG FAR PASCAL CmndCallB( HWND, UINT, WPARAM, LPARAM);
LONG FAR PASCAL DDECallB(  HWND, UINT, WPARAM, LPARAM); 
BOOL FAR PASCAL AboutCallB(HWND, UINT, WPARAM, LPARAM);
BOOL FAR PASCAL InfoCallB( HWND, UINT, WPARAM, LPARAM);
#endif



static void CloseDDELinks( void )
{
    register long alarm;
    register int i;
    MSG message;
    
    for( i=0; i<MaxDDEConvNum; i++ )
	if( DDEConvData[i].server )
	{   DDEConvData[i].closed = True;
	    PostMessage( DDEConvData[i].client, WM_DDE_TERMINATE,
			 (WPARAM)DDEConvData[i].server, (LPARAM)0 );
	} 
   
    alarm = GetTickCount() + DDETimeOut;
    while( PeekMessage(&message,NULL,WM_DDE_FIRST,WM_DDE_LAST,PM_REMOVE) )
    {   DispatchMessage( &message );
	if( message.message == WM_DDE_TERMINATE )
	    if( !DDEConvCount ) break;
	    
	/* Terminate Time Out */
	if( (long)GetTickCount() > alarm )
	{   for( i=0; i<MaxDDEConvNum; i++ )
		if( DDEConvData[i].server )
		    DestroyWindow( DDEConvData[i].server );
	    break;
	}
    }

    for( i=0; i<MaxDDEAdviseNum; i++ )
        if( DDEAdviseData[i].server && DDEAdviseData[i].wait )
        {   GlobalDeleteAtom(DDEAdviseData[i].atom);
            GlobalFree(DDEAdviseData[i].data);
            DDEAdviseData[i].wait = False;
            break;
        }
}


#ifdef SOCKETS
static void CloseSockets( void )
{
    register int i;

    if( UseSockets )
    {   if( SocketNo != INVALID_SOCKET )
            closesocket(SocketNo);

        for( i=0; i<MaxIPCConvNum; i++ )
            if( IPCConvData[i].protocol )
            {   closesocket(IPCConvData[i].socket);
                IPCConvData[i].protocol = 0;
            }

        SocketNo = INVALID_SOCKET;
        UseSockets = False;
        WSACleanup();
    }
}
#endif


void RasMolExit( void )
{
    DeleteObject(TermFont);
    CloseDDELinks();
#ifdef SOCKETS
    CloseSockets();
#endif
    CloseDisplay();
    exit(0);
}


void RasMolFatalExit( char *msg )
{
    MessageBox(NULL,msg,"RasMol Fatal Error!",
	MB_OK | MB_ICONEXCLAMATION | MB_APPLMODAL );
    
    /* PostQuitMessage(0); */
    DeleteObject(TermFont);
    CloseDDELinks();
#ifdef SOCKETS
    CloseSockets();
#endif
    CloseDisplay();
    exit(1);    
}


static void LoadInitFile( void )
{
    register char *src,*dst;
    register FILE *initrc;
    register char *fname;

    fname = "RASMOL.INI";
    initrc = fopen(fname,"rb");
    if( !initrc && (src=(char*)getenv("HOME")) )
    {   dst = fnamebuf; 
	while( *src )
	    *dst++ = *src++;
	*dst++ = '\\';

	src = fname; fname = fnamebuf;
	while( *dst++ = *src++ );
	initrc = fopen(fname,"rb");
    }

    if( !initrc && (src=(char*)getenv("RASMOLPATH")) )
    {   dst = fnamebuf; 
	while( *src )
	    *dst++ = *src++;
	*dst++ = '\\';

	src = fname; fname = fnamebuf;
	while( *dst++ = *src++ );
	initrc = fopen(fname,"rb");
    }

    if( initrc )
	LoadScriptFile(initrc,fname);
}


static void SetTermScroll( int pos )
{
    SetScrollPos(CmndWin,SB_VERT,pos,True);
    InvalidateRect(CmndWin,NULL,True);
    ScrlStart = ScrlMax - pos;
}


void WriteChar( int ch )
{
    register int i;
    RECT rect;

    /* Scroll to bottom! */
    if( ScrlStart )
	SetTermScroll( ScrlMax );
	
    switch( ch )
    {    case(0x07):  MessageBeep(0);
		      break;
		      
	 case(0x08):  if( TermXPos>0 )
		      {   TermXPos--;
			  if( TermCursor )
			      SetCaretPos(TermXPos*CharWide,
					  TermYPos*CharHigh);
		      }
		      break;
		      
	 case(0x0D):  if( TermXPos )
		      {   if( TermCursor )
			      SetCaretPos(0,TermYPos*CharHigh);
			  TermXPos=0;
		      }
		      break;
		      
	 case(0x0A):  if( TermYPos==TermRows-1 )
		      {   CmndStart++;
			  if( CmndStart == CmndRows )
			      CmndStart = 0;
			      
			  i = TermYPos + CmndStart;
			  if( i >= CmndRows ) i -= CmndRows;
			  _fmemset(TermScreen+i*CmndCols,' ',CmndCols);
			  InvalidateRect(CmndWin,NULL,FALSE);
		      } else TermYPos++;
		      TermXPos = 0;

		      if( TermCursor )
			  SetCaretPos(0,TermYPos*CharHigh);
		      UpdateWindow(CmndWin);
		      break;
		      
	 
	 default:     i = TermYPos + CmndStart;
		      if( i >= CmndRows ) i -= CmndRows;
		      TermScreen[i*CmndCols+TermXPos]=ch;
		      if( TermXPos < TermCols )
		      {   rect.top = TermYPos*CharHigh; 
			  rect.left = TermXPos*CharWide;
			  rect.bottom = rect.top+CharHigh;
			  rect.right = rect.left+CharWide;
			  InvalidateRect(CmndWin,&rect,FALSE);
		      }
		      
		      if( TermXPos==CmndCols-1 )
		      {   if( TermYPos==TermRows-1 )
			  {   CmndStart++;
			      if( CmndStart == CmndRows )
				  CmndStart = 0;
				  
			      i = TermYPos + CmndStart;
			      if( i >= CmndRows ) i -= CmndRows;
			      _fmemset(TermScreen+i*CmndCols,' ',CmndCols);
			      InvalidateRect(CmndWin,NULL,FALSE);
			  } else TermYPos++;
			  TermXPos=0;
		      } else TermXPos++;

		      if( TermCursor )
			  SetCaretPos(TermXPos*CharWide,
				      TermYPos*CharHigh);
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
	WriteChar(*ptr++);
}


static int InitTerminal( HANDLE instance )
{
    TEXTMETRIC Text;
    LOGFONT LogFont;
    long style;
    RECT rect;
    HDC hDC;
    int ii;
    
    LogFont.lfHeight     = 14;
    LogFont.lfWidth      = 0;
    LogFont.lfEscapement = 0;
    LogFont.lfWeight     = 500;
    LogFont.lfItalic     = 0;
    LogFont.lfUnderline  = 0;
    LogFont.lfStrikeOut  = 0;
    
    LogFont.lfCharSet        = ANSI_CHARSET;
    setlocale(LC_ALL,"English");
    
    for (ii=0; ii < NUMLANGS; ii++) {
      if (Language == langfonts[ii].lang) {
        setlocale(LC_ALL,lang2str(Language));
        LogFont.lfCharSet = langfonts[ii].menucharset;
        break;
      }
    }
    LogFont.lfOutPrecision   = OUT_DEFAULT_PRECIS;
    LogFont.lfClipPrecision  = CLIP_DEFAULT_PRECIS;
    LogFont.lfQuality        = DEFAULT_QUALITY;
    LogFont.lfPitchAndFamily = FIXED_PITCH | FF_DONTCARE;
    LogFont.lfFaceName[0]    = '\0';
    TermFont = CreateFontIndirect(&LogFont);
	TermLanguage = Language;

    /* TermFont = GetStockObject(ANSI_FIXED_FONT); */

    /* Default Window Size */
    TermCols = 80;  TermRows = 24;
    ScrlStart = CmndStart = 0;
    TermXPos = TermYPos = 0;
    
    TermScreen = (char __far*)_fmalloc(CmndSize*sizeof(char));
    if( !TermScreen ) return( False );
    _fmemset(TermScreen,' ',CmndSize);
    TermCursor = False;

    hDC = GetDC(NULL);
    SelectObject(hDC,TermFont);
    GetTextMetrics(hDC,&Text);  
    ReleaseDC(NULL,hDC);
    
    CharWide = Text.tmAveCharWidth;
    CharHigh = Text.tmHeight + Text.tmExternalLeading;

    rect.top  = 0;   rect.bottom = TermRows*CharHigh;
    rect.left = 0;   rect.right  = TermCols*CharWide;
    style = WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL | WS_SIZEBOX;
    
    AdjustWindowRect(&rect,style,False);
#ifdef WS_EX_CLIENTEDGE
    CmndWin = CreateWindowEx(WS_EX_CLIENTEDGE,
                           "RasCliClass", "RasMol Command Line",
			   style, CW_USEDEFAULT, CW_USEDEFAULT,
			   rect.right-rect.left, rect.bottom-rect.top,
			   NULL, NULL, instance, NULL );
#else
    CmndWin = CreateWindow("RasCliClass", "RasMol Command Line",
			   style, CW_USEDEFAULT, CW_USEDEFAULT,
			   rect.right-rect.left, rect.bottom-rect.top,
			   NULL, NULL, instance, NULL );
#endif
			   
    if( !CmndWin ) return( False );
   
    SetScrollRange(CmndWin,SB_VERT,0,ScrlMax,FALSE); 
    SetScrollPos(CmndWin,SB_VERT,ScrlMax,FALSE);
    ShowWindow(CmndWin,SW_SHOWMINNOACTIVE);
    return True;
}


static void PaintScreen( void )
{
    int SRow,ERow,SCol,ECol;
    register char __far *ptr;
    register int row,len;
    register int x,y;
    int ii;
    
    PAINTSTRUCT ps;
    HFONT font;
    RECT rect;
    HDC hDC;
    
	LOGFONT LogFont;
	
    if (Language != TermLanguage) {
	DeleteObject(TermFont);
	    
    LogFont.lfHeight     = 14;
    LogFont.lfWidth      = 0;
    LogFont.lfEscapement = 0;
    LogFont.lfWeight     = 500;
    LogFont.lfItalic     = 0;
    LogFont.lfUnderline  = 0;
    LogFont.lfStrikeOut  = 0;
    
    LogFont.lfCharSet        = ANSI_CHARSET;
    for (ii=0; ii < NUMLANGS; ii++) {
      if (Language == langfonts[ii].lang) {
        LogFont.lfCharSet = langfonts[ii].menucharset;
        break;
      }
    }
    LogFont.lfOutPrecision   = OUT_DEFAULT_PRECIS;
    LogFont.lfClipPrecision  = CLIP_DEFAULT_PRECIS;
    LogFont.lfQuality        = DEFAULT_QUALITY;
    LogFont.lfPitchAndFamily = FIXED_PITCH | FF_DONTCARE;
    LogFont.lfFaceName[0]    = '\0';
    TermFont = CreateFontIndirect(&LogFont);
	TermLanguage = Language;
	}

    
    hDC = BeginPaint(CmndWin,&ps);
    font = SelectObject(hDC,TermFont);
    SetBkColor(hDC,GetSysColor(COLOR_WINDOW));
    SetTextColor(hDC,RGB(0,0,0));
    SetBkMode(hDC,OPAQUE);
    
    SRow = ps.rcPaint.top/CharHigh;
    if( SRow >= TermRows )
    {   SRow = TermRows-1;
    } else if( SRow < 0 )
	SRow = 0;

    ERow = ps.rcPaint.bottom/CharHigh;
    if( ERow >= TermRows )
    {   ERow = TermRows-1;
    } else if( ERow < 0 ) 
	ERow = 0;
    
    SCol = ps.rcPaint.left/CharWide;
    if( SCol >= TermCols )
    {   SCol = TermCols-1;
    } else if( SCol < 0 ) 
	SCol = 0;
    
    ECol = ps.rcPaint.right/CharWide;
    if( ECol >= TermCols )
    {   ECol = TermCols-1;
    } else if( ECol < 0 ) 
	ECol = 0;

    len = ECol-SCol+1;
    x = SCol*CharWide;
    y = SRow*CharHigh;
    
    rect.right = x+len*CharWide;
    rect.left = x;   

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
    ptr = TermScreen + CmndCols*row + SCol;
    while( True )
    {   rect.top = y;    
	rect.bottom = y+CharHigh;
	ExtTextOut(hDC,x,y,ETO_OPAQUE|ETO_CLIPPED,
		   &rect,ptr,len,NULL);
		   
	if( row != ERow )
	{   ptr += CmndCols;
	    row++;
	    if( row == CmndRows )
	    {   ptr = TermScreen + SCol;
		row = 0;
	    }
	} else break;
	y += CharHigh;
    }
    
    SelectObject(hDC,font);
    EndPaint(CmndWin,&ps);
    
    if( TermCursor )
    {   row = TermYPos + ScrlStart;
	if( row < TermRows )
	{   SetCaretPos(TermXPos*CharWide,row*CharHigh);
	    ShowCaret(CmndWin);
	} else HideCaret(CmndWin);
    }    
}

/* EnsurePath 

   When possible, ensure the the path for the given file has been
   created.  The path must be in a mutable array, since the
   check is done by progressively changing backshlashes into
   nulls, checking the partial path and then restoring the backslash.
*/

static void EnsurePath(char * path) {

  char * ptr;
  
  int quoted;
  int depth;
  
  quoted = 0;
  depth = 0;
  ptr = path;
  
  while (*ptr)  {
    if (*ptr== '"') quoted = 1-quoted;
    if (*ptr == '\\' && !quoted) {
      *ptr = '\0';
      depth++;
      if ((depth > 1 || (ptr-path > 0 && *(ptr-1)!=':')) && ! CreateDirectory(path, NULL)) {
        if (GetLastError() == ERROR_PATH_NOT_FOUND) {
          WriteString(MsgStrs[StrErrFile]);
          WriteString(path);
          WriteString(MsgStrs[StrNotFnd]);
          *ptr = '\\';
          WriteString("in ");
          WriteString(path);
          WriteString("\n");
          break;
        }
      }
      *ptr = '\\';
    }
    ptr++;
  }	
  return;
}


/* Determine where the RasMol Application is loaded 

   If the environment variable RASMOLPATH is set, that is used
   Otherwise, if the enviroment variable PROGRAMFILES is set,
   the string %PROGRAMFILES%\RasWin is returned.
   Otherwise, if the symbol RASMOLDIR is defined, that is returned.
   Finally, if none of these are set, the current working directory
   is returned.
*/

static size_t DetermineRasMolPath( char * rpath, size_t maxlen) {

  char * src, * dst;
  
  dst = rpath;
  
  if (src = (char*)(getenv("RASMOLPATH"))) { 
    while(*src && dst-rpath < maxlen-1) { *dst++ = *src++; }
    *dst++ = '\0';
    return dst-rpath-1;	
  }
  
  if (src = (char*)(getenv("PROGRAMFILES"))) { 
    while(*src && dst-rpath < maxlen-1) { *dst++ = *src++; }
    src = "\\RasWin";
    while(*src && dst-rpath < maxlen-1) { *dst++ = *src++; }
    *dst++ = '\0';
    return dst-rpath-1;	
  }
  
#ifdef RASMOLDIR

  src = RASMOLDIR;
  while(*src && dst-rpath < maxlen-1) { *dst++ = *src++; }
  *dst++ = '\0';
  return dst-rpath-1;	
  
#endif

  if ( getcwd(rpath,maxlen-2)) {
  
    dst = rpath;
    while (*dst) dst++;
    if( dst !=rpath && *(dst -1) != '\\' ) {
      *dst++ = '\\';
    }
    *dst++ = '\0';
    return dst-rpath-1;
  	
  } else {
  
    return 0;
  	
  }
	
}

/* Determine where the RasWin.flg file is located

   If the environment variable RASMOLFLAGPATH is set, that is used
   Otherwise, if the environment variable APPDATA is set, then
   the string %APPDATA%\RasWin\RasWin.flg is used
   Othewise, if the environment variable USERNAME is set then
     if the environment variable WINDIR is defined
     return %WINDIR%\Profiles\%USERNAME%\Application Data\RasWin\RasWin.flg
     or C:\Windows\Profiles\%USERNAME%\Application Data\RasWin\RasWin.flg
   If the environment variable USERNAME is not defined,
     return %WINDIR%\Profiles\Application Data\RasWin\RasWin.flg
     or C:\Windows\Profiles\Application Data\RasWin\RasWin.flg

*/


static size_t DetermineRasMolFlagPath( char *rfpath, size_t maxlen ) {

  char * src, * dst, *windir;
    
  size_t rfplen;
  
  dst = rfpath;
  
  if (src = (char*)(getenv("RASMOLFLAGPATH"))) { 
    while(*src && dst-rfpath < maxlen-1) { *dst++ = *src++; }
    *dst++ = '\0';
    return dst-rfpath-1;	
  }

  if (src = (char*)(getenv("APPDATA"))) { 
    while(*src && dst-rfpath < maxlen-1) { *dst++ = *src++; }
    src = "\\RasWin\\RasWin.flg";
    while(*src && dst-rfpath < maxlen-1) { *dst++ = *src++; }
    *dst++ = '\0';
    return dst-rfpath-1;
  }
	

  if (!(windir=getenv("WINDIR"))) {	windir = "C:\\Windows"; }

  if (src = (char*)(getenv("USERNAME"))) { 
    while(*windir && dst-rfpath < maxlen-1) { *dst++ = *windir++; }
    windir = "\\Profiles\\";
    while(*windir && dst-rfpath < maxlen-1) { *dst++ = *windir++; }
    while(*src && dst-rfpath < maxlen-1) { *dst++ = *src++; }
    src = "\\Application Data\\RasWin\\RasWin.flg";
    while(*src && dst-rfpath < maxlen-1) { *dst++ = *src++; }
    *dst++ = '\0';
    return dst-rfpath-1;	
  } else {  	
    while(*windir && dst-rfpath < maxlen-1) { *dst++ = *windir++; }
    src = "\\Prtofiles\\Application\\RasWin\\RasWin.flg";
    while(*src && dst-rfpath < maxlen-1) { *dst++ = *src++; }
    *dst++ = '\0';
    return dst-rfpath-1;	
  }	
}

static size_t DetermineApplicationIdentifier( char * aid, size_t maxlen ) {

  TCHAR macname[1025];
  DWORD bufsiz;
  
  char *src, *dst;
  size_t curlen;
  
  dst = aid;
  curlen = 0;
  
  src = "RasWin_";
  while (*src && curlen < maxlen-1 ) {*dst++ = *src++; curlen++;}
  src = VERSION;
  while (*src && curlen < maxlen-1 ) {*dst++ = *src++; curlen++;}
  
  if (curlen < maxlen-1) {*dst++ = '_'; curlen++;}
  
  bufsiz = 1025;
  if (GetComputerName(macname,&bufsiz)) {
    src = macname;
  	while (*src && curlen < maxlen-1 ) {*dst++ = *src++; curlen++;}
  }
  
  if (curlen >= maxlen) return 0;
  *dst++ = '\0';
  
  return dst-aid;
	
}

static int getraid ( char * aid, size_t maxlen, char * langstr, size_t maxlstr) {

  HANDLE hraid;
  DWORD lenread;
  size_t count, ncount;

  if (DetermineRasMolFlagPath(fpnamebuf,1047)) {
    
    EnsurePath(fpnamebuf);
    hraid = CreateFile(fpnamebuf,FILE_READ_DATA,FILE_SHARE_READ,
      NULL,OPEN_EXISTING,0,NULL);
    
    if (hraid != INVALID_HANDLE_VALUE
      && ReadFile(hraid,aid,maxlen,&lenread,NULL)) {
      count = 0;
      while (*aid && count<maxlen-1 && count < lenread) {
        if (*aid=='\n' || *aid=='\r') break;
      	count++;
      	aid++;
      }
      if (count < lenread && (*aid == '\n' || *aid == '\r')) {
        *aid++ = '\0';
        count++;
        ncount = 0;
        if (count < maxlen-1 && count < lenread && *aid=='\n') {
          aid++;
          count++;
        }
        while(*aid && count < maxlen-1 && ncount < maxlstr-1 && count < lenread) {
          if(*aid == '\n' || *aid == '\r') break;
          *langstr++ = *aid++;
          count++;
          ncount++;
        }
        *langstr++ = '\0';
      } else  {
      	*aid++ = '\0';
      }
      
      CloseHandle(hraid);
      return count;
    }

    if (hraid != INVALID_HANDLE_VALUE ) CloseHandle(hraid);
    *aid = '\0';
    return 0;
  	
  }
	
}

static int setraid ( const char * aid, const char * langstr ) {

  HANDLE hraid;
  DWORD lenwritten;
  
  if (DetermineRasMolFlagPath(fpnamebuf,1047)) {

      EnsurePath(fpnamebuf);
  
  
    hraid = CreateFile(fpnamebuf,GENERIC_WRITE,0,
      NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_HIDDEN,NULL);
    
    if (hraid != INVALID_HANDLE_VALUE
      && WriteFile(hraid,aid,strlen(aid),&lenwritten,NULL)
      && WriteFile(hraid,"\r\n",2,&lenwritten,NULL)
      && WriteFile(hraid,langstr,strlen(langstr)+1,&lenwritten,NULL)) {
      SetEndOfFile(hraid);
      CloseHandle(hraid);
      return lenwritten;
    }

    if (hraid != INVALID_HANDLE_VALUE) CloseHandle(hraid);
    return 0;
  	
  }

}

static void DetermineHostInfo( void )
{
#ifdef _WIN32
    auto OSVERSIONINFO osinfo;
    auto SYSTEM_INFO sysinfo;
    register char *winver;
    register char *cpu;
    register int count;

    osinfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
#ifdef XPROCARCH
    GetVersionEx(&osinfo);
    if( osinfo.dwPlatformId == VER_PLATFORM_WIN32_NT )
    {   winver = "Windows NT";
    } else if( osinfo.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS )
    {   winver = "Windows95";
    } else if( osinfo.dwPlatformId == VER_PLATFORM_WIN32s )
    {   winver = "Win32s";
    } else winver = "Win32";
#else
    winver = "Windows";
#endif

#ifdef XPROCARCH
    if( osinfo.dwPlatformId == VER_PLATFORM_WIN32_NT )
    {   GetSystemInfo(&sysinfo);
        switch( sysinfo.wProcessorArchitecture )
        {   case PROCESSOR_ARCHITECTURE_INTEL:
                switch( sysinfo.wProcessorLevel )
                {   case 3:  cpu = "Intel 386";     break;
                    case 4:  cpu = "Intel 486";     break;
                    case 5:  cpu = "Intel Pentium"; break;
                    default: cpu = "Unknown Intel"; break;
                }
                break;

            case PROCESSOR_ARCHITECTURE_MIPS:
                switch( sysinfo.wProcessorLevel )
                {   case  1: cpu = "MIPS R2000";    break;
                    case  2: cpu = "MIPS R3000";    break;
                    case  3: cpu = "MIPS R6000";    break;
                    case  4: cpu = "MIPS R4000";    break;
                    case  6: cpu = "MIPS R6000A";   break;
                    case  9: cpu = "MIPS R10000";   break;
                    case 10: cpu = "MIPS R4200";    break;
                    case 11: cpu = "MIPS R4300";    break;
                    case 16: cpu = "MIPS R8000";    break;
                    case 32: cpu = "MIPS R4600";    break;
                    case 33: cpu = "MIPS R4700";    break;
                    case 34: cpu = "MIPS R4650";    break;
                    case 35: cpu = "MIPS R5000";    break;
                    default: cpu = "Unknown MIPS";  break;
                }
                break;

            case PROCESSOR_ARCHITECTURE_ALPHA:
                switch( sysinfo.wProcessorLevel )
                {   case 21064:  cpu = "Alpha 21064";  break;
                    case 21066:  cpu = "Alpha 21066";  break;
                    case 21164:  cpu = "Alpha 21164";  break;
                    default: cpu = "Unknown Alpha";    break;
                }
                break;

            case PROCESSOR_ARCHITECTURE_PPC:
                switch( sysinfo.wProcessorLevel )
                {   case 1:  cpu = "PPC 601";     break;
                    case 3:  cpu = "PPC 603";     break;
                    case 4:  cpu = "PPC 604";     break;
                    case 6:  cpu = "PPC 603+";    break;
                    case 9:  cpu = "PPC 604+";    break;
                    case 20: cpu = "PPC 620";     break;
                    default: cpu = "Unknown PPC"; break;
                }
                break;

            default:
                cpu = "unrecognised";
                break;
        }
    } else /* Windows 95 or Windows98 */
    {  
#endif 
        GetSystemInfo(&sysinfo);
        switch( sysinfo.dwProcessorType )
        {   case (386):   cpu = "Intel 386";       break;
            case (486):   cpu = "Intel 486";       break;
            case (586):   cpu = "Intel Pentium";   break;
            case (860):   cpu = "Intel i860";      break;
            case (2000):  cpu = "MIPS R2000";      break;
            case (3000):  cpu = "MIPS R3000";      break;
            case (4000):  cpu = "MIPS R4000";      break;
            case (4400):  cpu = "MIPS R4400";      break;
            case (4600):  cpu = "MIPS R4600";      break;
            case (5000):  cpu = "MIPS R5000";      break;
            case (8000):  cpu = "MIPS R8000";      break;
            case (10000): cpu = "MIPS R10000";     break;
            case (21064): cpu = "DEC Alpha 21064"; break;
            case (21066): cpu = "DEC Alpha 21066"; break;
            case (21164): cpu = "DEC Alpha 21164"; break;
            default:     cpu = "unrecognised";
        }
#ifdef XPROCARCH
    }
#endif

    count = sysinfo.dwNumberOfProcessors;
    if( count > 1 )
    {   sprintf(Text,"%s on %d %s CPUs\n",winver,count,cpu);
    } else sprintf(Text,"%s on a single %s CPU",winver,cpu);
#else
    register DWORD flags;
    register char *cpu;

    flags = GetWinFlags();
    if( flags & WF_CPU286 )
    {      cpu = "286";
    } else if( flags & WF_CPU386 )
    {      cpu = "386";
    } else cpu = "486";
                              
    if( !(flags&WF_80x87) )
    {   sprintf(Text,"%s without maths coprocessor",cpu);
    } else sprintf(Text,"%s with maths coprocessor",cpu); 
#endif
}


#ifdef _WIN32
BOOL CALLBACK AboutCallB( HWND hWin, UINT uMsg, WPARAM wArg, LPARAM lArg )
#else
BOOL FAR PASCAL AboutCallB( HWND hWin, UINT uMsg, WPARAM wArg, LPARAM lArg )
#endif
{

    UnusedArgument(lArg);

    switch(uMsg)
    {   case(WM_INITDIALOG):  
                DetermineHostInfo();
                SetDlgItemText(hWin,IDD_HARDWARE,Text);         
                SetDlgItemText(hWin,IDM_REGISTER,MsgStrs[StrRegister]);         
                SetDlgItemText(hWin,IDM_DONATE,MsgStrs[StrDonate]);         
                SetDlgItemText(hWin,IDD_WARRANTY,MsgStrs[StrWarranty]);         
                SetDlgItemText(hWin,IDD_NOSHOW,MsgStrs[StrNoShow]);
                if (getraid(filaid, 1025, fillang, 81)
                  && DetermineApplicationIdentifier(macaid, 1025)
                  && !strncasecmp(filaid,macaid,1024)) {
                  CheckDlgButton(hWin,IDD_NOSHOW,BST_CHECKED);
                }
                else { 
                  CheckDlgButton(hWin,IDD_NOSHOW,BST_UNCHECKED);
                }
                         
                return TRUE;
    
        case(WM_COMMAND):     
#ifdef _WIN32
                if( LOWORD(wArg) == IDOK )
#else
                if( wArg == IDOK )
#endif
                {   if (BST_CHECKED==IsDlgButtonChecked(hWin,IDD_NOSHOW)
                     && DetermineApplicationIdentifier(macaid, 1025)){
                	  setraid(macaid,lang2str(Language));
                     } else {
                      setraid("",lang2str(Language));
                    }
                    EndDialog(hWin,TRUE);
                    return TRUE;
                } else {
#ifdef _WIN32
                  if( LOWORD(wArg) == IDM_REGISTER )
#else
                  if( wArg == IDM_REGISTER )
#endif
                  { _spawnlp(_P_DETACH, "explorer", "explorer", 
                      "http://www.rasmol.org/register.shtml", NULL);
                    /* EndDialog(hWin,TRUE); */
                    return TRUE;
                  } else {
#ifdef _WIN32
                    if( LOWORD(wArg) == IDM_DONATE )
#else
                    if( wArg == IDM_DONATE )
#endif
                    { _spawnlp(_P_DETACH, "explorer", "explorer", 
                        "http://www.rasmol.org/donate.shtml", NULL);
                      /* EndDialog(hWin,TRUE); */
                      return TRUE;
                    }
                    
                  }
                	
                }
                break;
                
    	case(WM_CLOSE):
    	        if (BST_CHECKED==IsDlgButtonChecked(hWin,IDD_NOSHOW)
                  && DetermineApplicationIdentifier(macaid, 1025)){
                  setraid(macaid,lang2str(Language));
                } else {
                  setraid("",lang2str(Language));
                }
     	        EndDialog(hWin,TRUE);
                    return TRUE;
    }
    return 0;
}


static void DisplayMoleculeInfo( HWND hWin )
{
    register int line;
    register int len;

    line = IDD_INFOTEXT;
    
    if( *Info.moleculename )
    {   sprintf(Text," %s%s",MsgStrs[StrMolNam],Info.moleculename);
	SetDlgItemText(hWin,line++,Text);
    }
    
    if( *Info.classification )
    {   sprintf(Text," %s%s",MsgStrs[StrClass],Info.classification);
	SetDlgItemText(hWin,line++,Text);
    }
    
    if( *Info.identcode )
    {   sprintf(Text," %s%s",MsgStrs[StrDBCode],Info.identcode);
	SetDlgItemText(hWin,line++,Text);
    }
    
    if( Info.chaincount>1 )
    {   sprintf(Text," %s%d",MsgStrs[StrNumChn],Info.chaincount);
	SetDlgItemText(hWin,line++,Text);
    }
    
    len = sprintf(Text," %s%d",MsgStrs[StrNumGrp],MainGroupCount);
    if( HetaGroupCount ) sprintf(Text+len," (%d)",HetaGroupCount);
    SetDlgItemText(hWin,line++,Text);

    len = sprintf(Text," %s%ld",MsgStrs[StrNumAtm],MainAtomCount);
    if( HetaAtomCount ) sprintf(Text+len," (%d)",HetaAtomCount);
    SetDlgItemText(hWin,line++,Text);

    sprintf(Text," %s%ld",MsgStrs[StrNumBnd],Info.bondcount);
    SetDlgItemText(hWin,line++,Text);
}

	
#ifdef _WIN32
BOOL CALLBACK InfoCallB( HWND hWin, UINT uMsg, WPARAM wArg, LPARAM lArg )
#else
BOOL FAR PASCAL InfoCallB( HWND hWin, UINT uMsg, WPARAM wArg, LPARAM lArg )
#endif
{
    UnusedArgument(lArg);

    switch(uMsg)
    {   case(WM_INITDIALOG):
                DisplayMoleculeInfo(hWin);
	        return TRUE;
			      
	case(WM_COMMAND):
#ifdef _WIN32
                if( LOWORD(wArg) == IDOK )
#else
                if( wArg == IDOK )
#endif
	        {   EndDialog(hWin,TRUE);
		    return TRUE;
		}
	        break;
    }
    return 0;
}


static char *GetItemName( int item )
{
    switch( item )
    {   case  0:  return (char*)0;
        case -1:  return "Topics";
        case -2:  return "SysItems";
        case -3:  return "Formats";
        case -4:  return "Status";
        case -5:  return "Items";
    }

    if( item <= ItemCount )
        return AdviseMap[item-1].name;
    return "";
}


static HANDLE RenderClipboard( WPARAM format )
{
    register BITMAPINFO __far *bitmap;
    register Pixel __huge *src;
    register Pixel __huge *dst;
    register HANDLE result;
    register long size,len;
    register int i; 
   
    if( format==CF_PALETTE )
#ifdef EIGHTBIT
    {   if( ColourMap )
	{   return CreatePalette(Palette);
	} else return NULL;
    }
#else
      return NULL;
#endif
    
    if( !PixMap || (format!=CF_DIB) )
	return NULL;

    len = (long)XRange*YRange*sizeof(Pixel);
#ifdef EIGHTBIT
    size = sizeof(BITMAPINFOHEADER)  + 256*sizeof(RGBQUAD);
#else
    size = sizeof(BITMAPINFOHEADER);
#endif
    if( !(result=GlobalAlloc(GHND,size+len)) ) return NULL;
    
    bitmap = (BITMAPINFO __far *)GlobalLock(result);
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
    GlobalUnlock(result);
    return result;    
}


static void SendItemData( HWND hSrc, HWND hDst, 
                          int mode, int item, int advise )
{
    DDEDATA FAR *data;
    HANDLE FAR *hImage;
    HANDLE hData;
    LPARAM lArg;
    ATOM atom;

    register char __far *dest;
    register char *src, *dst;
    register char *name;
    register Long len;
    register int i;

    name = GetItemName(item);

    if( mode == WarmLink )
    {   atom = GlobalAddAtom(name);
#ifdef _WIN32
        lArg = PackDDElParam(WM_DDE_DATA,0,atom);
#else
        lArg = MAKELONG(0,atom);
#endif
	if( !PostMessage(hDst,WM_DDE_DATA,(WPARAM)hSrc,lArg) )
	    GlobalDeleteAtom(atom);
	return;
    }

    dst = AdviseBuffer;
    switch( (item<0)? item : item-1 )
    {   case(-1): /* Topics */
		  src="System\tRemoteControl"; 
		  while( *dst++ = *src++ ); break;

	case(-2): /* SysItems */
		  src = "Topics\tSysItems\tFormats\tStatus\tItems";
		  while( *dst++ = *src++ ); break;

	case(-3): /* Formats */
		  src = "DIB\tTEXT\tPalette\tLink";
		  while( *dst++ = *src++ ); break;

	case(-4): /* Status */
		  src = RasWinDDEReady? "Ready" : "Busy";
		  while( *dst++ = *src++ ); break;

	case(-5): /* Items */
		  for( i=0; i<ItemCount; i++ )
		  {   if( i ) *dst++ = '\t';
		      src = AdviseMap[i].name;
		      while( *src )
			  *dst++ = *src++;
		  }
		  *dst = '\0';
		  break;

	case(AdvPickAtom):
		  if( QAtom )
		  {   src = Residue[QGroup->refno];
		      if( src[0]!=' ' ) *dst++ = src[0];
		      *dst++  = src[1]; *dst++ = src[2];

		      sprintf(dst,"%d",QGroup->serno);
		      for( dst=Text; *dst; dst++ );
		      if( QChain->ident!=' ' )
		      {   *dst++ = ':';
			  *dst++ = QChain->ident;
		      }
		      *dst++ = '.';
		      
		      src = ElemDesc[QAtom->refno];
		      if( src[0]!=' ' ) *dst++ = src[0];
		      *dst++  = src[1]; *dst++ = src[2];
		      if( src[3]!=' ' ) *dst++ = src[3];
		  } 
		  *dst = '\0';
		  break;

	case(AdvPickNumber):
		  if( QAtom )
		  { sprintf(dst,"%d",QAtom->serno);
		  } else *dst = '\0';
		  break;

	case(AdvSelectCount):
		  sprintf(dst,"%ld",SelectCount);
		  break;
		  
	case(AdvName):
		  src = Info.moleculename;
		  while( *dst++ = *src++ );
		  break;

	case(AdvPickCoord):
		  if( QAtom )
		  { sprintf( dst, "%ld\t%ld\t%ld",
			     QAtom->xorg+QAtom->fxorg,
#ifdef INVERT
                             -(QAtom->yorg+QAtom->fxorg),
#else
                             QAtom->yorg+QAtom->fyorg,
#endif
                             -(QAtom->zorg+QAtom->fzorg));
		  } else *dst = '\0';
		  break;

	default:  *dst = '\0';
		  break;
    }

    len = sizeof(DDEDATA);
    if( item == AdvImage )
    {   len += sizeof(HANDLE);
        AdviseLen = 0;
    } else
    {   AdviseLen = strlen(AdviseBuffer)+1;
        len += AdviseLen;
    }

    if( hData = GlobalAlloc(GHND|GMEM_DDESHARE,len) )
    {   if( data = (DDEDATA FAR*)GlobalLock(hData) )
	{   data->fResponse = (mode!=AckLink);
	    data->fAckReq = (mode==ColdLink);
	    data->fRelease = True;

	    if( item == AdvImage )
	    {   data->cfFormat = CF_DIB;
		hImage = (HANDLE __far*)&data->Value[0];
		*hImage = RenderClipboard(CF_DIB);

	    } else 
	    {   data->cfFormat = CF_TEXT;
		dest = (char __far*)&data->Value[0];
		memcpy(dest,AdviseBuffer,len+1);
		/* Correctly terminate the data string */
		/* *dest++ = '\r'; *dest++ = '\n';     */
	    }
	    
	    GlobalUnlock(hData);
	    atom = GlobalAddAtom(name);
#ifdef _WIN32
            lArg = PackDDElParam(WM_DDE_DATA,(UINT)hData,(UINT)atom);
#else
            lArg = MAKELONG((UINT)hData,(UINT)atom);
#endif
            if( PostMessage(hDst,WM_DDE_DATA,(WPARAM)hSrc,lArg) )
	    {   if( mode==AckLink )
		{   SetTimer( hSrc, (UINT)hDst, DDETimeOut, NULL );
		    DDEAdviseData[advise].data = hData;
		    DDEAdviseData[advise].atom = atom;
		    DDEAdviseData[advise].wait = True;
		}
		return;
	    }
	    GlobalDeleteAtom(atom);
	}
	GlobalFree(hData);
    }
}


static int GetItemNumber( ATOM atom )
{
    register int i;

    GlobalGetAtomName(atom,Text,240);

    for( i=1; i<6; i++ )
	if( !stricmp(Text,GetItemName(-i)) )
	    return -i;

    for( i=0; i<ItemCount; i++ )
        if( !stricmp(Text,AdviseMap[i].name) )
	    return i+1;
    return 0;
}


#ifdef SOCKETS
static void PrepareIPCAdviseItem( int item )
{
    register char *src, *dst;
    register int i,flag;

    dst = AdviseBuffer;
    src = AdviseMap[item].name;
    while( *src ) *dst++ = *src++;
    *dst++ = ':';  *dst++ = ' ';

    switch( item )
    {   case(AdvPickAtom):
                  if( QAtom )
                  {   src = Residue[QGroup->refno];
                      flag = False;
                      for( i=0; i<3; i++ )
                          if( (src[i]!=' ') && !isalpha(src[i]) )
                              flag = True;

                      if( flag ) *dst++ = '[';
                      for( i=0; i<3; i++ )
                          if( src[i]!=' ' )
                              *dst++ = src[i];
                      if( flag ) *dst++ = ']';
                      sprintf(dst,"%d",QGroup->serno);
                      for( dst=AdviseBuffer; *dst; dst++ );
                      if( QChain->ident!=' ' )
                      {   if( isdigit(QChain->ident) ) *dst++ = ':';
                          *dst++ = QChain->ident;
                      }
                      *dst++ = '.';

                      src = ElemDesc[QAtom->refno];
                      for( i=0; i<4; i++ )
                          if( src[i]!=' ' )
                              *dst++ = src[i];
                  }
                  *dst++ = '\n';
                  *dst = '\0';
                  break;

        case(AdvPickNumber):
                  if( !QAtom )
                  {   *dst++ = '\n'; *dst = '\0';
                  } else sprintf(dst,"%ld\n",(long)QAtom->serno);
                  break;

        case(AdvSelectCount):
                  sprintf(dst,"%ld\n",(long)SelectCount);
                  break;

        case(AdvName):
                  src = Info.moleculename;
                  while( *src ) *dst++ = *src++;
                  *dst++ = '\n'; *dst = '\0';
                  break;

        case(AdvPickCoord):
                  if( !QAtom )
                  {   *dst++ = '\n'; *dst = '\0';
                  } else sprintf( dst, "%ld\t%ld\t%ld\n",
                             (long)(QAtom->xorg+QAtom->fxorg),
#ifdef INVERT
                             -(long)(QAtom->yorg+QAtom->fyorg),
#else
                             (long)(QAtom->yorg+QAtom->fyorg),
#endif
                             -(long)(QAtom->zorg+QAtom->fzorg));
                  break;

        default:  *dst++ = '\n';
                  *dst = '\0';
                  break;
    }
    AdviseLen = strlen(AdviseBuffer)+1;
}
#endif


void AdviseUpdate( int item )
{
    register DDEAdvise *ptr;
    register int i;

#ifdef SOCKETS
    register int mask;

    if( (item>=0) && UseSockets )
    {   mask = AdviseMap[item].bitmask;
        if( mask )
        {   AdviseLen = 0;
            for( i=0; i<MaxIPCConvNum; i++ )
                if( IPCConvData[i].protocol && (IPCConvData[i].advise&mask) )
                {   if( !AdviseLen ) PrepareIPCAdviseItem(item);
                    send(IPCConvData[i].socket,AdviseBuffer,AdviseLen,0);
                }
        }
    }
#endif

    if( DDEAdviseCount )
    {   if( item >= 0 ) item++;
        ptr = DDEAdviseData;
        for( i=0; i<MaxDDEAdviseNum; i++ )
        {   if( ptr->server && (ptr->item==(Byte)item) && !ptr->wait )
                SendItemData(ptr->server,ptr->client,ptr->mode,item,i);
            ptr++;
	}
    }
}



void RefreshScreen( void )
{
    int ReDrawFlagSave;
    ReDrawFlag &= ~RFTransZ;

    if( ReDrawFlag ) {
      if( RasWinDDEReady ) {
          RasWinDDEReady = False;
	      AdviseUpdate( -4 );
	  }
	
	  if( ReDrawFlag & RFReSize )
	    ReSizeScreen();

	  if( ReDrawFlag & RFColour )
	  {   ClearImage();
	      DefineColourMap();
	  }

      NextReDrawFlag = 0;
      ReDrawFlagSave = ReDrawFlag;
	  if( Database )
	  {   BeginWait();
	      if( ReDrawFlag & RFApply ) 
		  ApplyTransform();
	      DrawFrame();
	      TransferImage();
	      EndWait();
	  } else
	  {   ClearBuffers();
	      TransferImage();
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


static void GenerateDDEReply( HWND hDst, HWND hSrc, int flag, UINT data )
{
    register LPARAM lArg;

#ifdef _WIN32
    lArg = PackDDElParam(WM_DDE_ACK,(flag?0x8000:0),data);
#else
    lArg = MAKELPARAM((flag?0x8000:0),data);
#endif
    PostMessage( (HWND)hDst, WM_DDE_ACK, (WPARAM)hSrc, lArg );
}

  
#ifdef _WIN32
LRESULT CALLBACK DDECallB( HWND hWin, UINT uMsg, WPARAM wArg, LPARAM lArg )
#else
LONG FAR PASCAL DDECallB( HWND hWin, UINT uMsg, WPARAM wArg, LPARAM lArg )
#endif
{
    DDEADVISE FAR *options;
    auto UINT loword;
    auto UINT hiword;
    HWND hDest;

    register DDEConv *ptr;
    register char __huge *cmnd;
    register int item, stat;
    register int format,i;
    register int flag;
    
    switch( uMsg )
    {   case( WM_TIMER ):    
                    KillTimer( hWin, wArg );
                    for( i=0; i<MaxDDEAdviseNum; i++ )
                        if( (DDEAdviseData[i].server==hWin) &&
                             DDEAdviseData[i].wait )
                        {   GlobalDeleteAtom(DDEAdviseData[i].atom);
                            GlobalFree(DDEAdviseData[i].data);
                            DDEAdviseData[i].wait = False;
                            break;
                        }
                    return 0L;

	case( WM_DDE_ACK ):
		    KillTimer( hWin, wArg );
#ifdef _WIN32
                    if( UnpackDDElParam(uMsg,lArg,&loword,&hiword) )
                    {   FreeDDElParam(uMsg,lArg);
                    } else return 0L;
#else
                    loword = LOWORD(lArg);
                    hiword = HIWORD(lArg);
#endif

                    if( hiword )
                    {   item = GetItemNumber( (ATOM)hiword );
                        GlobalDeleteAtom( (ATOM)hiword );
                    } else item = 0;

                    if( !item )
                        return 0L;

                    if( !(loword&0x8000) )
                    {   for( i=0; i<MaxDDEAdviseNum; i++ )
                            if( (DDEAdviseData[i].server==hWin) &&
                                (DDEAdviseData[i].item==(Byte)item) &&
                                 DDEAdviseData[i].wait )
                            {   if( DDEAdviseData[i].atom != (ATOM)hiword )
                                    GlobalDeleteAtom(DDEAdviseData[i].atom);
                                GlobalFree(DDEAdviseData[i].data);
                                DDEAdviseData[i].wait = False;
                                break;
                            }
                    }
                    return 0L;

	case( WM_DDE_REQUEST ):
                    hiword = HIWORD(lArg);
                    if( hiword )
                    {   item = GetItemNumber( (ATOM)hiword );
                    } else item = 0;

                    if( !item )
                    {   GenerateDDEReply((HWND)wArg,hWin,False,hiword);
                        return 0L;
                    }

                    format = (item==AdvImage+1)? CF_DIB : CF_TEXT; 
                    if( format == (int)LOWORD(lArg) )
                    {   SendItemData(hWin,(HWND)wArg,ColdLink,item,0);
                        GlobalDeleteAtom( (ATOM)hiword );
                    } else GenerateDDEReply((HWND)wArg,hWin,False,hiword);
                    return 0L;

	case( WM_DDE_UNADVISE ):
                    hiword = HIWORD(lArg);
                    if( hiword )
                    {   item = GetItemNumber( (ATOM)hiword );
                        if( !item )
                        {   GenerateDDEReply((HWND)wArg,hWin,False,hiword);
                            return 0L;
                        }
                    } else item = 0;

                    flag = False;
                    for( i=0; i<MaxDDEAdviseNum; i++ )
                        if( (DDEAdviseData[i].server==hWin) &&
                            ( !hiword || DDEAdviseData[i].item==(Byte)item ) )
                        {   if( DDEAdviseData[i].wait )
                            {   GlobalDeleteAtom(DDEAdviseData[i].atom);
                                GlobalFree(DDEAdviseData[i].data);
                            }
                            DDEAdviseData[i].server = NULL;
                            DDEAdviseCount--;
                            flag = True;
                        }
                    GenerateDDEReply((HWND)wArg,hWin,flag,hiword);
                    return 0L;

	case( WM_DDE_ADVISE ):
#ifdef _WIN32
                    if( UnpackDDElParam(uMsg,lArg,&loword,&hiword) )
                    {   FreeDDElParam(uMsg,lArg);
                    } else return 0L;
#else
                    loword = LOWORD(lArg);
                    hiword = HIWORD(lArg);
#endif
                    if( hiword )
                    {   item = GetItemNumber( (ATOM)hiword );
                    } else item = 0;

                    if( !item || (DDEAdviseCount==MaxDDEAdviseNum ) )
                    {   GenerateDDEReply((HWND)wArg,hWin,False,hiword);
                        return 0L;
                    }

                    /* Check for established link! */
                    for( i=0; i<MaxDDEAdviseNum; i++ )
                        if( (DDEAdviseData[i].server==hWin) &&
                            (DDEAdviseData[i].item==(Byte)item) )
                            break;

                    if( i < MaxDDEAdviseNum )
                    {   /* Should we reuse the existing advise? */
                        GenerateDDEReply((HWND)wArg,hWin,False,hiword);
                        return 0L;
                    }

                    options = (DDEADVISE FAR*)GlobalLock((HGLOBAL)loword);
                    if( !options )
                    {   GenerateDDEReply((HWND)wArg,hWin,False,hiword);
                        return 0L;
                    }

                    format = (item==AdvImage+1)? CF_DIB : CF_TEXT;
                    if( options->cfFormat == format ) 
                    {   for( i=0; i<MaxDDEConvNum; i++ )
                           if( DDEConvData[i].server == hWin )
                           {   hDest = DDEConvData[i].client;
                               break;
                           }

                       for( i=0; i<MaxDDEAdviseNum; i++ )
                           if( !DDEAdviseData[i].server )
                               break;

                       DDEAdviseData[i].server = hWin;
                       DDEAdviseData[i].client = hDest;
                       DDEAdviseData[i].atom = hiword;
                       DDEAdviseData[i].wait = False;
                       DDEAdviseData[i].item = item;
                       DDEAdviseCount++;

                       if( options->fDeferUpd )
                       {      DDEAdviseData[i].mode = WarmLink;
                       } else if( options->fAckReq )
                       {      DDEAdviseData[i].mode = AckLink;
                       } else DDEAdviseData[i].mode = HotLink;

                       GenerateDDEReply((HWND)wArg,hWin,True,hiword);

                /* We could advise client of the current item value!      */
                /* SendItemData(hWin,hDest,DDEAdviseData[i].mode,item,i); */

                    } else GenerateDDEReply((HWND)wArg,hWin,False,hiword);
                    GlobalUnlock((HGLOBAL)loword);
                    return 0L;

	case( WM_DDE_EXECUTE ):  
#ifdef _WIN32
                    hiword = lArg;
#else
                    hiword = HIWORD(lArg);
#endif
                    cmnd = (char __huge*)GlobalLock((HANDLE)hiword);
                    if( !cmnd )
                    {   GenerateDDEReply((HWND)wArg,hWin,False,hiword);
                        return 0L;
                    }

                    stat = ExecuteIPCCommand( cmnd );
                    GlobalUnlock((HANDLE)hiword);
                    GenerateDDEReply((HWND)wArg,hWin,stat,hiword);

                    if( (stat==IPC_Quit) || (stat==IPC_Exit) )
                        RasMolExit();

                    if( ReDrawFlag ) {
	                    RefreshScreen();
                        ReDrawFlag = NextReDrawFlag;
                    }
                    
                    if( !CommandActive )
                        ResetCommandLine(0);
                    return 0L;
		    
	case( WM_DDE_TERMINATE ):
                    /* Destroy all Hot/Warm Links */
                    for( i=0; i<MaxDDEAdviseNum; i++ )
                        if( DDEAdviseData[i].server == hWin )
                        {   DDEAdviseData[i].server = NULL;
                            if( DDEAdviseData[i].wait )
                            {   GlobalDeleteAtom(DDEAdviseData[i].atom);
                                GlobalFree(DDEAdviseData[i].data);
                            }
                            DDEAdviseCount--;
                        }

                    /* Remove the Conversation */
                    for( i=0; i<MaxDDEConvNum; i++ )
                        if( DDEConvData[i].server == hWin )
                        {   ptr = &DDEConvData[i];
                            if( !ptr->closed )
                                PostMessage( ptr->client, WM_DDE_TERMINATE,
                                             (WPARAM)ptr->server, 0L );
                            DestroyWindow( ptr->server );
                            ptr->server = NULL;
                            DDEConvCount--;
                            break;
                        }
                    return 0L;
		    
	default:    return DefWindowProc(hWin,uMsg,wArg,lArg);
    }
}

/* [GSG 11/16/95] */
void SetHScroll(int pos)
{
    float temp = (pos/50.0)-1.0;

    if ( (RotMode == RotBond) && BondSelected)
	BondSelected->BRotValue = temp;
    else if ( RotMode == RotAll )
	WorldDialValue[1] = temp;
    else
	DialValue[1] = temp;
    ReDrawFlag |= RFRotateY;
}
  
void SetVScroll(int pos)
{
    float temp = 1.0-(pos/50.0);

    if ( RotMode == RotAll )
	WorldDialValue[DialRX] = temp;
    else
	DialValue[DialRX] = temp;
    ReDrawFlag |= RFRotateX;
}


static void ResizeTerminal( int x, int y )
{
    register int rows, cols;
    register int sr, er;

    HBRUSH hBr;
    RECT rect;
    HDC hDC;
    
    if( x > CharWide )
    {   cols = x/CharWide;
    } else cols = 1;
    
    if( y > CharHigh )
    {   rows = y/CharHigh;
    } else rows = 1;

    /* Scroll to bottom! */
    if( ScrlStart )
	SetTermScroll( ScrlMax );

    if( rows < TermRows )
    {   if( TermYPos >= rows )
	{   CmndStart += (TermYPos - rows) + 1;
	    if( CmndStart >= CmndRows )
		CmndStart -= CmndRows;
	    TermYPos = rows - 1;
	
	    hDC = GetDC(CmndWin);
	    GetClientRect(CmndWin,&rect);
	    hBr = CreateSolidBrush(GetSysColor(COLOR_WINDOW));
	    FillRect(hDC,&rect,hBr);
	    ReleaseDC(CmndWin,hDC);
	} 

    } else if( rows > TermRows )
    {   sr = TermRows + CmndStart;
	if( sr >= CmndRows )
	    sr -= CmndRows;
	    
	er = CmndStart + rows;
	if( er >= CmndRows )
	    er -= CmndRows;
	    
	do {
	    _fmemset(TermScreen+sr*CmndCols,' ',CmndCols);
	    sr++; if( sr == CmndRows ) sr = 0;
	} while( sr != er );
    }
    
    InvalidateRect(CmndWin,NULL,False);
    if( cols > CmndCols )
    {   TermCols = CmndCols;
    } else TermCols = cols;
    TermRows = rows;
}


#ifdef _WIN32
LRESULT CALLBACK CmndCallB( HWND hWin, UINT uMsg, WPARAM wArg, LPARAM lArg )
#else
LONG FAR PASCAL CmndCallB( HWND hWin, UINT uMsg, WPARAM wArg, LPARAM lArg )
#endif
{
    register int row;
    
    switch(uMsg)
    {   case(WM_CLOSE):       DestroyWindow(CanvWin);
			      DestroyWindow(CmndWin);
			      CommandActive = True;
			      ReDrawFlag = False;
			      break;

	case(WM_DESTROY):     /* Destroy RasWin */
			      PostQuitMessage(0);
			      break;

        case(WM_SYSCHAR):     if( lArg & (1L<<29) )  /* ALT-key pressed? */
				  return(DefWindowProc(hWin,uMsg,wArg,lArg));

	case(WM_CHAR):        if( ProcessCharacter(LOBYTE(wArg)) )
				  if( ExecuteCommand() )
				      RasMolExit();
			      break;

	case(WM_PAINT):       PaintScreen();
			      return(0L);
			      
	case(WM_SYSKEYDOWN):
	case(WM_KEYDOWN):     switch(LOBYTE(wArg))
			      {   case(0x23): ProcessCharacter(0x05); break;
				  case(0x24): ProcessCharacter(0x01); break;
				  case(0x25): ProcessCharacter(0x02); break;
				  case(0x26): ProcessCharacter(0x10); break;
				  case(0x27): ProcessCharacter(0x06); break;
				  case(0x28): ProcessCharacter(0x0e); break;
				  case(0x2e): ProcessCharacter(0x04); break;
				  
				  default:
				  return(DefWindowProc(hWin,uMsg,wArg,lArg));
			      }
			      break;
	
	 case(WM_SETFOCUS):   if( !TermCursor )
			      {   CreateCaret(hWin,NULL,CharWide,CharHigh);
				  TermCursor = True;
			      }
			      
			      row = TermYPos + ScrlStart;
			      if( row < TermRows )
			      {   SetCaretPos(TermXPos*CharWide,row*CharHigh);
				  ShowCaret(hWin);
			      } else HideCaret(hWin);
			      return(0L);
			      
	 case(WM_SIZE):       if( wArg != SIZE_MINIMIZED )
				  ResizeTerminal(LOWORD(lArg),HIWORD(lArg));
			      return(0L);
			      
	 case(WM_KILLFOCUS):  if( TermCursor )
			      {   TermCursor=False;
				  HideCaret(hWin);
				  DestroyCaret();
			      }
			      return(0L);

	 case(WM_VSCROLL):
#ifdef _WIN32
                              switch( LOWORD(wArg) )
#else
                              switch( wArg )
#endif
			      {  case(SB_TOP):    SetTermScroll(0);  break;
				 case(SB_BOTTOM): SetTermScroll(ScrlMax);  
						  break;
				 
				 case(SB_LINEUP):   
				     if( ScrlStart < ScrlMax )
					 SetTermScroll((ScrlMax-ScrlStart)-1);
				     break;
				     
				 case(SB_LINEDOWN):
				     if( ScrlStart > 0 )
					 SetTermScroll((ScrlMax-ScrlStart)+1);
				     break;
				     
				 case(SB_PAGEUP):
				     if( ScrlStart < (ScrlMax-10) )
				     {   SetTermScroll((ScrlMax-ScrlStart)-10);
				     } else SetTermScroll(0);
				     break;
				     
				 case(SB_PAGEDOWN):
				     if( ScrlStart > 10 )
				     {   SetTermScroll((ScrlMax-ScrlStart)+10);
				     } else SetTermScroll(ScrlMax);
				     break;
				     
				 case(SB_THUMBTRACK):
				 case(SB_THUMBPOSITION):
#ifdef _WIN32
                                     SetTermScroll(HIWORD(wArg));
#else
                                     SetTermScroll(LOWORD(lArg));
#endif
				     break;
			      }
			      break;
							    
	 default:  return DefWindowProc(hWin,uMsg,wArg,lArg);
    }

    if( ReDrawFlag ) {
	  RefreshScreen();
      ReDrawFlag = NextReDrawFlag;
    }
    if( !CommandActive )
	ResetCommandLine(0);
    return 0L;
}



static int LoadInputFile( int format )
{
    register char *ext;
    register int num;
	static FILE *script;

    switch( format )
    {   case(FormatPDB):      ext = "PDB";  num = 1;  break;
	case(FormatAlchemy):  ext = "MOL";  num = 2;  break;
	case(FormatMol2):     ext = "MOL";  num = 3;  break;
	case(FormatMDL):      ext = "MOL";  num = 4;  break;
	case(FormatXYZ):      ext = "XYZ";  num = 5;  break;
	case(FormatCharmm):   ext = "CHM";  num = 6;  break;
	case(FormatMOPAC):    ext = "MOP";  num = 7;  break;
	case(FormatCIF):      ext = "CIF";  num = 8;  break;
    case(FormatSCR):      ext = "SCR";  num = 9;  break;
    }

    ofn1.nFilterIndex = num;
    ofn1.lpstrDefExt = ext;
    *fnamebuf = '\0';

    if( GetOpenFileName(&ofn1) )
    {   switch( ofn1.nFilterIndex )
	{   case(1): FetchFile(FormatPDB,False,fnamebuf);     break;
	    case(2): FetchFile(FormatAlchemy,False,fnamebuf); break;
	    case(3): FetchFile(FormatMol2,False,fnamebuf);    break;
	    case(4): FetchFile(FormatMDL,False,fnamebuf);     break;
	    case(5): FetchFile(FormatXYZ,False,fnamebuf);     break;
	    case(6): FetchFile(FormatCharmm,False,fnamebuf);  break;
	    case(7): FetchFile(FormatMOPAC,False,fnamebuf);   break;
	    case(8): FetchFile(FormatCIF,False,fnamebuf);     break;
		case(9): 
		         strcpy(CurLine,"script ");
		         CurLine[MAXBUFFLEN-1]='\0';
		         strncpy(CurLine+7,fnamebuf,MAXBUFFLEN-8);
		         return 1;
		
		         /* script = fopen(fnamebuf,"rb");
		         DataFileName[1023] = '\0';
		         strncpy(DataFileName,fnamebuf,1023);
		         if (script) LoadScriptFile(script,DataFileName); */       
				                                          break;
	}
        DefaultRepresentation();
    }
    return 0;
}


static void SaveOutputFile( int format )
{
    register char *ext;
    register int num;

    switch( format )
    {	
	case(IDM_BMP):   ext="BMP";  num=1;   break;
	case(IDM_GIF):   ext="GIF";  num=2;   break;
	case(IDM_IRIS):  ext="RGB";  num=9;   break;
	case(IDM_PPM):   ext="PPM";  num=6;   break;
	case(IDM_RAST):  ext="RAS";  num=10;  break;
	case(IDM_EPSF):  ext="PS";   num=3;   break;
	case(IDM_PICT):  ext="PIC";  num=8;   break;
	case(IDM_VECPS): ext="PS";   num=5;   break;
	case(IDM_MOLSCRIPT): ext="MIN"; num=12; break;
	case(IDM_KINEMAGE): ext="KIN"; num=13; break;
	case(IDM_POVRAY): ext="POV", num=14;  break;
	case(IDM_VRML):  ext="WRL",  num=15;  break;
	case(IDM_RPP):   ext="RPP",  num=16;  break;
	case(IDM_R3D):   ext="R3D",  num=17;  break;
	case(IDM_SCR):   ext="SCR",  num=18;  break;
    }

    ofn2.nFilterIndex = num;
    ofn2.lpstrDefExt = ext;
    *fnamebuf = '\0';
    
/*  Default Filename   
 *  dst = fnamebuf;
 *  for( src="RASWIN."; *src; src++ ) *dst++ = *src;
 *  for( src=ext; *src; src++ ) *dst++ = *src;
 *  *dst++ = '\0';
 */
    
    if( GetSaveFileName(&ofn2) )    
	switch( ofn2.nFilterIndex )
	{   case(1):  WriteBMPFile(fnamebuf);             break;
	    case(2):  WriteGIFFile(fnamebuf);             break;
	    case(3):  WriteEPSFFile(fnamebuf,True,True);  break;
	    case(4):  WriteEPSFFile(fnamebuf,False,True); break;
		case(5):  WriteVectPSFile(fnamebuf);          break;
	    case(6):  WritePPMFile(fnamebuf,True);        break;
	    case(7):  WritePPMFile(fnamebuf,False);       break;
		case(8):  WritePICTFile(fnamebuf);            break;
		case(9):  WriteIRISFile(fnamebuf);            break;
	    case(10): WriteRastFile(fnamebuf,True);       break;
	    case(11): WriteRastFile(fnamebuf,False);      break;
		case(12): WriteMolScriptFile(fnamebuf);       break;
		case(13): WriteKinemageFile(fnamebuf);        break;
		case(14): WritePOVRay3File(fnamebuf);         break;
		case(15): WriteVRMLFile(fnamebuf,0);          break;
		case(16): WritePhiPsiAngles(fnamebuf,-1);     break;
		case(17): WriteR3DFile(fnamebuf);             break;
		case(18): WriteScriptFile(fnamebuf);          break;
	}
}


static void HandlePrintSetUp( void )
{
    PRINTDLG pd;

    memset(&pd,0,sizeof(PRINTDLG));
    pd.lStructSize = sizeof(PRINTDLG);
    pd.hwndOwner = CanvWin;
    pd.Flags = PD_PRINTSETUP;

    PrintDlg(&pd);

    if( pd.hDevNames ) GlobalFree(pd.hDevNames);
    if( pd.hDevMode )  GlobalFree(pd.hDevMode);
}


static BOOL HandleMenu( WPARAM option )
{
#ifndef _WIN32
    register FARPROC lpProc;
#endif
    register char *src, *dst;
    register int mask;
   
    switch(option)
    {   /* File Menu */
	case(IDM_OPEN): 
			      if (LoadInputFile(FormatPDB)) ExecuteCommand();
			  break;
			  
	case(IDM_INFO):
#ifdef _WIN32
                          DialogBox(hInstance,"InfoBox",CanvWin,InfoCallB);
#else   
                          lpProc = MakeProcInstance(InfoCallB,hInstance);
			  DialogBox(hInstance,"InfoBox",CanvWin,lpProc);
			  FreeProcInstance(lpProc);
#endif
			  break;
			  
	case(IDM_CLOSE):  ZapDatabase();
			  break;

	case(IDM_PRINT):  if( !PrintImage() )
			  {   if( CommandActive )
				  WriteChar('\n');
			      WriteString("Warning: No suitable printer!\n");
			      CommandActive = False;
			  }
			  break;
	
	case(IDM_SETUP):  HandlePrintSetUp();
                          break;

    case(IDM_EXIT):   PostMessage(CanvWin,WM_CLOSE,0,0L);
			  break;

    case(IDM_MOL1):   /* Molecule 1 */
    case(IDM_MOL2):   /* Molecule 2 */
    case(IDM_MOL3):   /* Molecule 3 */
    case(IDM_MOL4):   /* Molecule 4 */
    case(IDM_MOL5):   /* Molecule 5 */
                      SelectMolecule(option-IDM_MOL1);
                          break;

			  
        /* Edit Menu */
        case(IDM_SELECT): mask = NormAtomFlag;
                          if( HetaGroups ) mask |= HeteroFlag;
                          if( Hydrogens )  mask |= HydrogenFlag;
                          SelectZone(mask);
                          break;

	case(IDM_COPY):   if( !ClipboardImage() )
			  {   if( CommandActive )
				  WriteChar('\n');
			      WriteString("Unable to copy to clipboard!\n");
			      CommandActive = False;
			  }
			  break;
	
	/* Help Menu */
	case(IDM_SPLASH):  
#ifdef _WIN32
                          DialogBox(hInstance,"AboutBox",CanvWin,AboutCallB);
#else
                          lpProc = MakeProcInstance(AboutCallB,hInstance);
			  DialogBox(hInstance,"AboutBox",CanvWin,lpProc);
			  FreeProcInstance(lpProc);
#endif
			  break;

	case(IDM_RMANUAL):   if( DetermineRasMolPath(fnamebuf,1037) )
			  {   dst = fnamebuf;
			      while( *dst ) dst++;
			      if( *(dst-1) != '\\' ) 
				  *dst++ = '\\';
				  
			      src = "RASWIN.HLP";    
			      while( *dst++ = *src++ );
			      WinHelp(CanvWin,fnamebuf,HELP_INDEX,0L);
			  }
			  break;
			  
    case(IDM_REGISTER):
              _spawnlp(_P_DETACH, "explorer", "explorer", 
                      "http://www.rasmol.org/register.shtml", NULL);
              break;  

    case(IDM_DONATE):
              _spawnlp(_P_DETACH, "explorer", "explorer", 
                      "http://www.rasmol.org/donate.shtml", NULL);
			  break;
       
       
	/* Display Menu */
	case(IDM_WIREFRAME):  DisableSpacefill();
			      EnableWireframe(WireFlag,0,0);
			      SetRibbonStatus(False,0,0);
			      DisableBackbone();
			      ReDrawFlag |= RFRefresh;
			      break;

	case(IDM_BACKBONE):   DisableSpacefill();
			      DisableWireframe();
			      SetRibbonStatus(False,0,0);
			      EnableBackbone(CylinderFlag,80,64);
			      ReDrawFlag |= RFRefresh;
			      break;

	case(IDM_STICKS):     DisableSpacefill();
			      if( MainAtomCount<256 )
			      {   EnableWireframe(CylinderFlag,40,32);
			      } else EnableWireframe(CylinderFlag,80,64);
			      SetRibbonStatus(False,0,0);
			      DisableBackbone();
			      ReDrawFlag |= RFRefresh;
			      break;

	case(IDM_SPHERES):    SetVanWaalRadius( SphereFlag );
			      DisableWireframe();
			      SetRibbonStatus(False,0,0);
			      DisableBackbone();
			      ReDrawFlag |= RFRefresh;
			      break;

	case(IDM_BALLSTICK):  SetRadiusValue(120, SphereFlag);
			      EnableWireframe(CylinderFlag,40,32);
			      SetRibbonStatus(False,0,0);
			      DisableBackbone();
			      ReDrawFlag |= RFRefresh;
			      break;

	case(IDM_RIBBONS):    DisableSpacefill();
			      DisableWireframe();
			      SetRibbonStatus(True,RibbonFlag,0);
			      DisableBackbone();
			      ReDrawFlag |= RFRefresh;
			      break;

	case(IDM_STRANDS):    DisableSpacefill();
			      DisableWireframe();
			      SetRibbonStatus(True,StrandFlag,0);
			      DisableBackbone();
			      ReDrawFlag |= RFRefresh;
			      break;

	case(IDM_CARTOONS):   /* Cartoons */
                              DisableSpacefill();
                              DisableWireframe();
                              SetRibbonCartoons();
                              DisableBackbone();
                              ReDrawFlag |= RFRefresh;
			      break;

	case(IDM_MOLSURF):    /* Molecular Surface */
			      DrawSurf = True;
			      ProbeRadius = 350;
			      SetVanWaalRadius( SphereFlag | TouchFlag );
			      DisableWireframe();
			      SetRibbonStatus(False,0,0);
			      DisableBackbone();
			      CreateSurfaceBonds();
			      ReDrawFlag |= RFRefresh;
			      break;



	/* Colours Menu */
	case(IDM_MONO):     MonoColourAttrib(255,255,255);
			    ReDrawFlag |= RFColour;  break;
	case(IDM_CPK):      CPKColourAttrib();
			    ReDrawFlag |= RFColour;  break;
	case(IDM_SHAPELY):  ShapelyColourAttrib();
			    ReDrawFlag |= RFColour;  break;
	case(IDM_STRUCT):   StructColourAttrib();
			    ReDrawFlag |= RFColour;  break;
	case(IDM_GROUP):    ScaleColourAttrib( GroupAttr );
			    ReDrawFlag |= RFColour;  break;
	case(IDM_CHAIN):    ScaleColourAttrib( ChainAttr );
			    ReDrawFlag |= RFColour;  break;
	case(IDM_TEMPER):   ScaleColourAttrib( TempAttr );
			    ReDrawFlag |= RFColour;  break;
	case(IDM_USER):     UserMaskAttrib(MaskColourFlag);
			    ReDrawFlag |= RFColour;  break;
	case(IDM_MODEL):    ScaleColourAttrib( ModelAttr );
			    ReDrawFlag |= RFColour;  break;
	case(IDM_ALT):      ScaleColourAttrib( AltAttr   );
			    ReDrawFlag |= RFColour;  break;
	
       
       
	/* Options Menu */
	case(IDM_SLAB):      ReDrawFlag |= RFRefresh;
			     UseSlabPlane = !UseSlabPlane;
			     if( UseSlabPlane )
				 UseShadow = False;
			     break;

	case(IDM_HYDROGEN):  mask = NormAtomFlag;
			     if( HetaGroups )
				 mask |= HeteroFlag;
			     Hydrogens = !Hydrogens;
			     ReDrawFlag |= RFRefresh;

			     if( Hydrogens )
			     {      SelectZone(mask|HydrogenFlag);
			     } else RestrictZone(mask);
			     break;
	
	case(IDM_HETERO):    mask = NormAtomFlag;
			     if( Hydrogens )
				 mask |= HydrogenFlag;
			     HetaGroups = !HetaGroups;
			     ReDrawFlag |= RFRefresh;

			     if( HetaGroups )
			     {      SelectZone(mask|HeteroFlag);
			     } else RestrictZone(mask);
			     break;
	
	case(IDM_SPECULAR):  FakeSpecular = !FakeSpecular;
			     ReDrawFlag |= RFColour;
			     break;
	
	case(IDM_SHADOW):    ReDrawFlag |= RFRefresh;
			     UseShadow = !UseShadow;
			     if( UseShadow )
			     {   ReviseInvMatrix();
				 VoxelsClean = False;
				 UseSlabPlane = False;
				 ReAllocBuffers();
			     }
			     break;

	case(IDM_STEREO):    /* Stereo */
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

        case(IDM_LABELS):    /* Labels */
                             LabelOptFlag = !LabelOptFlag;
                             DefaultLabels(LabelOptFlag);
                             ReDrawFlag |= RFRefresh;
                             break;


        /* Settings Menu */
        case(IDM_PKNONE):    /* Pick Off */
                             SetPickMode(PickNone); break;
        case(IDM_PKIDENT):   /* Pick Ident */
                             SetPickMode(PickIdent); break;
        case(IDM_PKDIST):    /* Pick Distance */
                             SetPickMode(PickDist); break;
        case(IDM_PKMONIT):   /* Pick Monitor */
                             SetPickMode(PickMonit); break;
        case(IDM_PKANGLE):   /* Pick Angle */
                             SetPickMode(PickAngle); break;
        case(IDM_PKTORSN):   /* Pick Torsion */
                             SetPickMode(PickTorsn); break;
        case(IDM_PKLABEL):   /* Pick Label */
                             SetPickMode(PickLabel); break;
        case(IDM_PKORIGN):   /* Pick Centre */
                             SetPickMode(PickOrign); break;
        case(IDM_PKCOORD):   /* Pick Coord */
                             SetPickMode(PickCoord); break;
        case(IDM_PKBOND):    /* Pick Bond */
                             SetPickMode(PickBond); break;
        case(IDM_RTBOND):    /* Rotate Bond */
                             if ( BondSelected ) {
                               RotMode = RotBond; break;
                             }
        case(IDM_RTMOL):     /* Rotate Mol */
                             RotMode = RotMol; UpdateScrollBars(); break;
        case(IDM_RTALL):     /* Rotate All */
                             RotMode = RotAll; UpdateScrollBars(); break;


	/* Save Menu */
	    case(IDM_BMP):
	    case(IDM_GIF):
	    case(IDM_IRIS):
	    case(IDM_PPM):
	    case(IDM_RAST):
	    case(IDM_EPSF):
	    case(IDM_PICT):
	    case(IDM_VECPS):
	    case(IDM_MOLSCRIPT):
	    case(IDM_KINEMAGE):
	    case(IDM_POVRAY):
	    case(IDM_VRML):
        case(IDM_RPP):
        case(IDM_R3D):
        case(IDM_SCR):
                             SaveOutputFile( option ); 
			   break;
	
	default:  return FALSE;
    }
    return TRUE;
}    


static void InitiateServer( HWND hWinCli, LPARAM lParam )
{
    HWND hWinServ;
    ATOM aTopicIn, aTopicOut;
    ATOM aApplIn, aApplOut;
    
    char TopicName[16];
    char ApplName[16];
    register int i;

    if( DDEConvCount == MaxDDEConvNum )
	return;
	    
    if( aApplIn = LOWORD(lParam) )
    {   GlobalGetAtomName(aApplIn,ApplName,14);
	if( stricmp(ApplName,"RasWin") &&
            stricmp(ApplName,"RasWin32") )
	    return;
    } else return;
    
    if( aTopicIn = HIWORD(lParam) )
    {   GlobalGetAtomName(aTopicIn,TopicName,14);
	/* Test for Valid Topic */
	/* if( _stricmp(Topic,"System") &&
	 *     _stricmp(Topic,"RemoteControl") )
	 * return;
	 */
    } else *TopicName = '\0';
   
    hWinServ = CreateWindow("RasDDEClass","RasWinDDE",
			    WS_CHILD, 0, 0, 0, 0,
			    CanvWin, NULL, hInstance, NULL );
    if( !hWinServ ) return;
	 
    for( i=0; i<MaxDDEConvNum; i++ )
	if( !DDEConvData[i].server )
	    break;
	    
    DDEConvData[i].server = hWinServ;
    DDEConvData[i].client = hWinCli;
    DDEConvData[i].closed = False;
    DDEConvCount++;       
	  	 
    /* Main DDE Server */       
    aTopicOut = GlobalAddAtom("System");
#ifdef _WIN32
    aApplOut = GlobalAddAtom("RasWin32");
    SendMessage( hWinCli, WM_DDE_ACK, (WPARAM)hWinServ,
                 MAKELPARAM(aApplOut,aTopicOut) );
#else
    aApplOut = GlobalAddAtom("RasWin");
    SendMessage( hWinCli, WM_DDE_ACK, (WPARAM)hWinServ,
		 MAKELONG(aApplOut,aTopicOut) ); 
#endif
}


#ifdef SOCKETS
static int IsIPCAdviseRequest( char *ptr, int conv )
{
    auto char item[34];
    register char *dst;
    register char *src;
    register int i,ch;
    register int flag;

    if( !strncmp(ptr,"Advise:",7) )
    {   src = ptr+7;
        flag = True;
    } else if( !strncmp(ptr,"Unadvise:",9) )
    {   src = ptr+9;
        flag = False;
    } else return False;

    while( True )
    {   ch = *src++;
        if( isspace(ch) )
            continue;

        if( isalpha(ch) )
        {   dst = item;
            *dst++ = ch;
            while( IsIdentChar(*src) )
            {   if( dst < item+32 )
                {   *dst++ = *src++;
                } else src++;
            }
            *dst = '\0';

            for( i=0; i<ItemCount; i++ )
                if( !stricmp(item,AdviseMap[i].name) )
                {   if( flag )
                    {      IPCConvData[conv].advise |=  AdviseMap[i].bitmask;
                    } else IPCConvData[conv].advise &= ~AdviseMap[i].bitmask;
                    break;
                }

           /* Warning: Unknown Advise Item! */
        } else if( ch != ',' )
            break;
    }
    return True;
}


static void OpenSocket( HWND hWin )
{
    auto int length;
    auto struct sockaddr_in addr;
    auto WSADATA wsadata;
    register WORD vers;
    register int i;

    UseSockets = False;
    SocketNo = INVALID_SOCKET;

    vers = MAKEWORD(1,1);
    if( WSAStartup(vers,&wsadata) )
        return;

    if( LOBYTE(wsadata.wVersion) != 1 ||
        HIBYTE(wsadata.wVersion) != 1 )
    {   WSACleanup();
        return;
    }

    SocketNo = socket(AF_INET,SOCK_STREAM,0);
    if( SocketNo == INVALID_SOCKET )
    {   WSACleanup();
        return;
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons((short)ServerPort);

    if( bind(SocketNo,(struct sockaddr __far*)&addr,sizeof(addr)) )
    {   closesocket(SocketNo);
        WSACleanup();
        return;
    }

    if( !ServerPort )
    {   length = sizeof(addr);
        if( !getsockname(SocketNo,(struct sockaddr __far*)&addr,&length) )
        {   ServerPort = ntohs(addr.sin_port);
            sprintf(Text,"RasMol Server TCP/IP Port: %d\n",ServerPort);
            WriteString(Text);
        }
    }

    UseSockets = True;
    for( i=0; i<MaxIPCConvNum; i++ )
        IPCConvData[i].protocol = 0;

    listen(SocketNo,5);
    WSAAsyncSelect(SocketNo,hWin,WM_WINSOCK,FD_ACCEPT|FD_READ|FD_CLOSE);
}


static int OpenIPCConnection( SOCKET sock )
{
    register int i;

    if( sock == INVALID_SOCKET )
      return False;

    for( i=0; i<MaxIPCConvNum; i++ )
        if( !IPCConvData[i].protocol )
        {   IPCConvData[i].protocol = ProtoRasMol;
            IPCConvData[i].socket = sock;
            IPCConvData[i].advise = AMNone;
            return True;
        }
    closesocket(sock);
    return False;
}


static void CloseIPCConnection( SOCKET sock )
{
    register int i;

    if( sock != INVALID_SOCKET )
    {   for( i=0; i<MaxIPCConvNum; i++ )
            if( IPCConvData[i].protocol && (IPCConvData[i].socket==sock) )
                IPCConvData[i].protocol = 0;
        closesocket(sock);
    }
}


static void HandleSocketData( SOCKET sock )
{
    auto char buffer[4097];
    register char *src;
    register char *dst;
    register int result;
    register int len;
    register int ch;
    register int i;

    if( sock == INVALID_SOCKET )
        return;

    for( i=0; i<MaxIPCConvNum; i++ )
        if( IPCConvData[i].protocol && (IPCConvData[i].socket==sock) )
        {   len = recv( sock, buffer, 4096, 0 );
            if( len > 0 )
            {   buffer[len] = '\0';
                src = dst = buffer;
                while( (ch = *src++) )
                    if( (ch>=' ') && (ch<='~') )
                        *dst++ = ch;
                *dst = '\0';

                if( !IsIPCAdviseRequest(buffer,i) )
                {   result = ExecuteIPCCommand(buffer);
                    if( result == IPC_Exit )
                    {   CloseIPCConnection(sock);
                    } else if( result == IPC_Quit )
                        RasMolExit();
                }
            } else CloseIPCConnection(sock);
            return;
        }

    closesocket(sock);
}
#endif


static void ClampDial( int dial, Real value )
{
    register Real temp;

    temp = DialValue[dial] + value;

    if( temp > 1.0 )
    {   DialValue[dial] = 1.0;
    } else if( temp < -1.0 )
    {   DialValue[dial] = -1.0;
    } else DialValue[dial] = temp;
}


static void WrapDial( int dial, Real value )
{
    register Real temp;

    temp = DialValue[dial] + value;
    while( temp < -1.0 )  temp += 2.0;
    while( temp > 1.0 )   temp -= 2.0;
    DialValue[dial] = temp;
}


static int GetStatus( int mask )
{
    register int status;
    
    status = 0;                             
    if( mask & MK_LBUTTON ) status |= MMLft;
    if( mask & MK_MBUTTON ) status |= MMMid;
    if( mask & MK_RBUTTON ) status |= MMRgt;
    if( mask & MK_CONTROL ) status |= MMCtl;          
    if( mask & MK_SHIFT )   status |= MMSft;
    return status;
}
  

static void AdjustMenus( WPARAM wArg, LPARAM lArg )
{
    register HMENU hMenu;
    register int status;
    register int curitems;
    register int i;
 

    if( lArg == 0)
    {   /* File Menu */
        hMenu = (HMENU)wArg;
        curitems = GetMenuItemCount(hMenu);
        if (curitems > 8) {
          for (i = curitems; i > 8; i--) {
            RemoveMenu(hMenu, i-1, MF_BYPOSITION);
          }
        }
        if (NumMolecules > 0 ) {
          DrawMoleculeList();
          AppendMenu(hMenu,MF_SEPARATOR,0,NULL);
          for (i = 0; i < NumMolecules; i++) {
            AppendMenu(hMenu,MF_STRING|MF_ENABLED|MF_UNCHECKED,
              IDM_MOL1+i,MolName[i]);
            if (i==MoleculeIndex){
              CheckMenuItem(hMenu,IDM_MOL1+i,MF_CHECKED);
            }
          }
        }
    }
   
    if( lArg == 4 )
    {   /* Options Menu */
        hMenu = (HMENU)wArg;

        status = UseSlabPlane ? MF_CHECKED : MF_UNCHECKED;
        CheckMenuItem(hMenu,IDM_SLAB,status);

        status = Hydrogens ? MF_CHECKED : MF_UNCHECKED;
        CheckMenuItem(hMenu,IDM_HYDROGEN,status);

        status = HetaGroups ? MF_CHECKED : MF_UNCHECKED;
        CheckMenuItem(hMenu,IDM_HETERO,status);

        status = FakeSpecular ? MF_CHECKED : MF_UNCHECKED;
        CheckMenuItem(hMenu,IDM_SPECULAR,status);

        status = UseShadow ? MF_CHECKED : MF_UNCHECKED;
        CheckMenuItem(hMenu,IDM_SHADOW,status);

        status = UseStereo ? MF_CHECKED : MF_UNCHECKED;
        CheckMenuItem(hMenu,IDM_STEREO,status);

        status = LabelOptFlag ? MF_CHECKED : MF_UNCHECKED;
        CheckMenuItem(hMenu,IDM_LABELS,status);
    }

    if( lArg == 5 )
    {   /* Settings Menu */
        hMenu = (HMENU)wArg;

        status = (PickMode==PickNone) ? MF_CHECKED : MF_UNCHECKED;
        CheckMenuItem(hMenu,IDM_PKNONE,status);

        status = (PickMode==PickIdent) ? MF_CHECKED : MF_UNCHECKED;
        CheckMenuItem(hMenu,IDM_PKIDENT,status);

        status = (PickMode==PickDist) ? MF_CHECKED : MF_UNCHECKED;
        CheckMenuItem(hMenu,IDM_PKDIST,status);

        status = (PickMode==PickMonit) ? MF_CHECKED : MF_UNCHECKED;
        CheckMenuItem(hMenu,IDM_PKMONIT,status);

        status = (PickMode==PickAngle) ? MF_CHECKED : MF_UNCHECKED;
        CheckMenuItem(hMenu,IDM_PKANGLE,status);

        status = (PickMode==PickTorsn) ? MF_CHECKED : MF_UNCHECKED;
        CheckMenuItem(hMenu,IDM_PKTORSN,status);

        status = (PickMode==PickLabel) ? MF_CHECKED : MF_UNCHECKED;
        CheckMenuItem(hMenu,IDM_PKLABEL,status);

        status = (PickMode==PickOrign) ? MF_CHECKED : MF_UNCHECKED;
        CheckMenuItem(hMenu,IDM_PKORIGN,status);

        status = (PickMode==PickCoord) ? MF_CHECKED : MF_UNCHECKED;
        CheckMenuItem(hMenu,IDM_PKCOORD,status);

        status = (PickMode==PickBond) ? MF_CHECKED : MF_UNCHECKED;
        CheckMenuItem(hMenu,IDM_PKBOND,status);

        status = (RotMode==RotBond) ? MF_CHECKED : MF_UNCHECKED;
        CheckMenuItem(hMenu,IDM_RTBOND,status);

        status = (RotMode==RotMol) ? MF_CHECKED : MF_UNCHECKED;
        CheckMenuItem(hMenu,IDM_RTMOL,status);

        status = (RotMode==RotAll) ? MF_CHECKED : MF_UNCHECKED;
        CheckMenuItem(hMenu,IDM_RTALL,status);
  
    }
}


#ifdef _WIN32
LRESULT CALLBACK MainCallB( HWND hWin, UINT uMsg, WPARAM wArg, LPARAM lArg )
#else
LONG FAR PASCAL MainCallB( HWND hWin, UINT uMsg, WPARAM wArg, LPARAM lArg )
#endif
{
    register int pos,status;
    register int x,y;

    register COLORREF BackColRef;
#ifdef EIGHTBIT    
    register HPALETTE hCMap;
#endif
    register HANDLE hand;
    register HDC hMemDC;
    register HDC hDC;
    PAINTSTRUCT ps;
    RECT rc;
    
    CanvWin = hWin;
    

    
    switch(uMsg)
    {   case(WM_DROPFILES):   /* Disable Drag & Drop */
                              if( IsPaused ) break;

                              /* ZapDatabase(); */
			      *fnamebuf = '\0';
			      DragQueryFile((HDROP)wArg,0,fnamebuf,127);
			      FetchFile(FormatPDB,False,fnamebuf);
                              DefaultRepresentation();
			      DragFinish((HDROP)wArg);
			      break;

	case(WM_DESTROY):     /* Destroy RasWin */
			      DragAcceptFiles(CanvWin,FALSE);
			      PostQuitMessage(0);
			      break;

	case(WM_CLOSE):       DestroyWindow(CanvWin);
			      DestroyWindow(CmndWin);
			      break;

	case(WM_ACTIVATE):
                   if (firstpass)   {
                              firstpass=0;
                      if (!(getraid(filaid, 1025, fillang, 81)
                        && DetermineApplicationIdentifier(macaid, 1025)
                        && !strncasecmp(filaid,macaid,1024)) ){
#ifdef _WIN32
                              DialogBox(hInstance,"AboutBox",CanvWin,AboutCallB);
#else
                              lpProc = MakeProcInstance(AboutCallB,hInstance);
                              DialogBox(hInstance,"AboutBox",CanvWin,lpProc);
                              FreeProcInstance(lpProc);
#endif
                        }
                   }
#ifdef _WIN32
                              if( !LOWORD(wArg) || HIWORD(lArg) ) break;
#else
                              if( !wArg || HIWORD(lArg) ) break;
#endif

	case(WM_QUERYNEWPALETTE):
#ifdef EIGHTBIT
			      if( ColourMap )
			      {   hDC = GetDC(hWin);
				  hCMap = SelectPalette(hDC,ColourMap,False);
				  status = RealizePalette(hDC);
				  if( hCMap ) SelectPalette(hDC,hCMap,False);
				  ReleaseDC(hWin,hDC);
				  if( status )
				  {   InvalidateRect(hWin,NULL,True);
				      return True;
				  }
			      }
#endif
			      return 0L;
			      
	case(WM_PALETTECHANGED):
#ifdef EIGHTBIT
			      if( ColourMap && ((HWND)wArg != hWin) )
			      {   hDC = GetDC(hWin);
				  hCMap = SelectPalette(hDC,ColourMap,False);
				  if( RealizePalette(hDC) )
				      InvalidateRect(hWin,NULL,True);
				  if( hCMap ) SelectPalette(hDC,hCMap,False);
				  ReleaseDC(hWin,hDC);
			      }
#endif
			      return 0L;
			      			     
	case(WM_INITMENUPOPUP):  /* Initialise Checks */
                              AdjustMenus( wArg, lArg );
                              return 0L;                      

	case(WM_SIZE):        if( wArg != SIZE_MINIMIZED )
			      {   GetClientRect(hWin,&rc);
				  YRange = rc.bottom;
				  XRange = rc.right;
			      
				  /* Ensure Long Aligned */
				  if( x = XRange%4 )
				      XRange += 4-x;
			      
				  Range = MinFun(XRange,YRange);
				  ReDrawFlag |= RFReSize;
				  HRange = YRange>>1;
				  WRange = XRange>>1;
				  ClearImage();
			      }
			      break;

	case(WM_HSCROLL):     /* Horizontal Scroll */
			      pos = GetScrollPos(hWin,SB_HORZ);
#ifdef _WIN32
                              switch( LOWORD(wArg) )
#else
			      switch( wArg )
#endif
			      {   case(SB_LINEDOWN):  pos += 5;   break;
				  case(SB_PAGEDOWN):  pos += 10;  break;
				  case(SB_PAGEUP):    pos -= 10;  break;
				  case(SB_LINEUP):    pos -= 5;   break;
				  default:            return(0L);

				  case(SB_THUMBTRACK):
				  case(SB_THUMBPOSITION):
#ifdef _WIN32
                                             pos = HIWORD(wArg);
#else
					     pos = LOWORD(lArg);
					     break;
#endif
			      }
			      
			      if( pos>100 ) 
			      {   pos -= 100;
			      } else if( pos<0 ) 
				  pos += 100; 
			     
			      SetScrollPos(hWin,SB_HORZ,pos,TRUE);
                              SetHScroll(pos);
			      break;                      

	case(WM_VSCROLL):     /* Vertical Scroll */
			      pos = GetScrollPos(hWin,SB_VERT);
#ifdef _WIN32
                              switch( LOWORD(wArg) )
#else
			      switch( wArg )
#endif
			      {   case(SB_LINEDOWN):  pos += 5;   break;
				  case(SB_PAGEDOWN):  pos += 10;  break;
				  case(SB_PAGEUP):    pos -= 10;  break;
				  case(SB_LINEUP):    pos -= 5;   break;
				  default:            return(0L);

				  case(SB_THUMBTRACK):
				  case(SB_THUMBPOSITION):
#ifdef _WIN32
                                             pos = HIWORD(wArg);
#else
					     pos = LOWORD(lArg);
#endif
					     break;
			      }
			      
			      if( pos>100 ) 
			      {   pos -= 100;
			      } else if( pos<0 ) 
				  pos += 100; 
			     
			      SetScrollPos(hWin,SB_VERT,pos,TRUE);
                              SetVScroll(pos);
			      break;                      

	case(WM_LBUTTONDOWN): 
	case(WM_MBUTTONDOWN):
    case(WM_RBUTTONDOWN): x = LOWORD(lArg);
                              y = HIWORD(lArg);
                              status = GetStatus(wArg);
                              ProcessMouseDown(x,y,status);
                              break;
	
	case(WM_LBUTTONUP):
	case(WM_MBUTTONUP):
	case(WM_RBUTTONUP): /* Mouse Buttons */
                              x = LOWORD(lArg);
                              y = HIWORD(lArg);
                              status = GetStatus(wArg);
                              ProcessMouseUp(x,y,status);
			      break;


	case(WM_MOUSEMOVE):   /* Mouse Movement */
                              x = LOWORD(lArg);
                              y = HIWORD(lArg);
                              status = GetStatus(wArg);
                              ProcessMouseMove(x,y,status);
			      break;
				      
	case(WM_SETFOCUS):    /* Obtain Window Focus */ 
	case(WM_KILLFOCUS):   /* Release Window Focus */
			      SendMessage(CmndWin,uMsg,wArg,lArg);     
			      return 0L;
	
	case(WM_PAINT):       hDC = BeginPaint(hWin,&ps);
			      SetBkMode(hDC,TRANSPARENT);
#ifdef EIGHTBIT
			      if( PixMap )
			      {   hCMap = SelectPalette(hDC,ColourMap,False);
				  RealizePalette(hDC);
#endif
#ifdef _WIN32
				  SetWindowOrgEx(hDC,0,0,NULL);
#else
				  SetWindowOrg(hDC,0,0);
#endif
				  hMemDC = CreateCompatibleDC(hDC);
				  SelectObject(hMemDC,PixMap);
				  BitBlt(hDC,0,0,XRange,YRange,
					 hMemDC,0,0,SRCCOPY);
					 
#ifdef EIGHTBIT
				  SelectPalette(hDC,hCMap,False);
#endif      
				  DeleteDC(hMemDC);
#ifdef EIGHTBIT
			      } else /* Erase Update Region */
#endif
			      {
#ifdef EIGHTBIT
			       if( ColourMap )
				   {   hCMap=SelectPalette(hDC,ColourMap,0);
			           BackColRef = RGB(BackR,BackG,BackB);
				       RealizePalette(hDC);
				   } else {
				   	   BackColRef = RGB(0,0,0);
				   }
#else
				   BackColRef = RGB(BackR,BackG,BackB);
#endif
				   hand = CreateSolidBrush(BackColRef);
				   GetUpdateRect(hWin,&rc,False);
				   FillRect( hDC, &rc, hand );
#ifdef EIGHTBIT
				   if( ColourMap && hCMap )
				       SelectPalette(hDC,hCMap,False);
#endif
				   DeleteObject(hand);
			      }
			      EndPaint(hWin,&ps);
			      if( !RasWinDDEReady )
			      {   RasWinDDEReady = True;
				  AdviseUpdate(-4);
			      }
			      return 0L;
	
	case(WM_SYSCHAR):     if( lArg & (1L<<29) )  /* ALT-key pressed? */
				  return(DefWindowProc(hWin,uMsg,wArg,lArg));
	case(WM_CHAR):        if( ProcessCharacter(LOBYTE(wArg)) )
				  if( ExecuteCommand() )
				      RasMolExit();
			      break;

	case(WM_SYSKEYDOWN):
	case(WM_KEYDOWN):     switch(LOBYTE(wArg))
			      {   case(0x23): ProcessCharacter(0x05); break;
				  case(0x24): ProcessCharacter(0x01); break;
				  case(0x25): ProcessCharacter(0x02); break;
				  case(0x26): ProcessCharacter(0x10); break;
				  case(0x27): ProcessCharacter(0x06); break;
				  case(0x28): ProcessCharacter(0x0e); break;
				  case(0x2e): ProcessCharacter(0x04); break;
				  
				  default:
				  return(DefWindowProc(hWin,uMsg,wArg,lArg));
			      }
			      break;

	case(WM_RENDERALLFORMATS):
			      OpenClipboard(hWin);
			      SendMessage(hWin,WM_RENDERFORMAT,CF_DIB,0L);
			      SendMessage(hWin,WM_RENDERFORMAT,CF_PALETTE,0L);
			      CloseClipboard();
			      return 0L;
			      
	case(WM_RENDERFORMAT):
			      if( hand = RenderClipboard(wArg) )
				  SetClipboardData(wArg,hand);
			      return 0L;
			      

	case(WM_DDE_INITIATE): /* DDE Server Connection */
			      InitiateServer((HWND)wArg,lArg);
			      return 0L;
  
#ifdef SOCKETS
        case(WM_WINSOCK):     /* IPC Server Connection */
                              switch( WSAGETSELECTEVENT(lArg) )
                              {   case FD_ACCEPT:
                                      OpenIPCConnection(accept(wArg,0,0));
                                      return 0L;

                                  case FD_READ:
                                      HandleSocketData((SOCKET)wArg);
                                      break;

                                  case FD_CLOSE:
                                      CloseIPCConnection((SOCKET)wArg);
                                      return 0L;

                                  default:
                                      return 0L;
                              }
                              break;
#endif
					      
	case(WM_COMMAND):     
#ifdef _WIN32
                              if( !IsPaused && HandleMenu(LOWORD(wArg)) )
				  break;
#else
                              if( !IsPaused && HandleMenu(wArg) ) break;
#endif                              			      
	default:              return( DefWindowProc(hWin,uMsg,wArg,lArg) );

    }
	
    if( ReDrawFlag ) {
	  RefreshScreen();
      ReDrawFlag = NextReDrawFlag;
    }
    
    if( !CommandActive )
	ResetCommandLine(0);	
    return 0L;
}


static int InitialiseApplication( void )
{
    WNDCLASS wc;
    
    wc.hIcon = LoadIcon(hInstance,"RasWinIcon");
    wc.hInstance = hInstance;
    wc.cbWndExtra = 0;
    wc.cbClsExtra= 0;

    /* Canvas Window Class */
    wc.style = 0;
    wc.lpfnWndProc = MainCallB;
    wc.hbrBackground = CreateSolidBrush(RGB(0,0,0));
    wc.hCursor = LoadCursor(hInstance,"RasWinCursor");
    wc.lpszClassName = "RasWinClass";
    wc.lpszMenuName = NULL;

    if( !RegisterClass(&wc) )
	return False;

    /* Terminal Window Class */
    wc.style = CS_NOCLOSE;
    wc.lpfnWndProc = CmndCallB;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.hCursor = LoadCursor(NULL,IDC_ARROW);
    wc.lpszClassName = "RasCliClass";
    wc.lpszMenuName = NULL;

    if( !RegisterClass(&wc) )
	return False;

    /* DDE Server Window Class */
    wc.lpfnWndProc = DDECallB;
    wc.lpszClassName = "RasDDEClass";
    wc.hbrBackground = NULL;
    wc.hCursor = NULL;
    wc.hIcon = NULL;

    return RegisterClass(&wc);
}


static char *RegisterFormat( char *buffer, char *desc, char *ext )
{
    while( *buffer++ = *desc++ );
    while( *buffer++ = *ext++ );
    return buffer;
}


static void InitFileDialogBoxes( void )
{
    register char *dst;

    dst = ifilters;
    dst = RegisterFormat(dst,"Protein Databank","*.PDB;*.ENT");
    dst = RegisterFormat(dst,"Alchemy File Format","*.ALC;*.MOL");
    dst = RegisterFormat(dst,"Sybyl MOL2 Format","*.SYB;*.ML2;*.SY2;*.MOL");
    dst = RegisterFormat(dst,"MDL Mol File Format","*.MDL;*.MOL");
    dst = RegisterFormat(dst,"MSC (XMol) XYZ Format","*.XYZ");
    dst = RegisterFormat(dst,"CHARMm File Format","*.CHM");
    dst = RegisterFormat(dst,"MOPAC File Format","*.MOP");
    dst = RegisterFormat(dst,"CIF File Format","*.CIF");
    dst = RegisterFormat(dst,"RasMol Script","*.SCR;*.SPT");
    *dst = '\0';

    /* Load File Common Dialog Box */
    ofn1.lStructSize=sizeof(OPENFILENAME);
    ofn1.Flags = OFN_NOCHANGEDIR | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
    ofn1.lpstrFilter = ifilters;
    ofn1.lpstrTitle = "Select Molecular Coordinate File";
    ofn1.lpstrFile = fnamebuf;
    ofn1.nMaxFile = 128;

    ofn1.lpstrCustomFilter = NULL;
    ofn1.lpstrInitialDir = NULL;
    ofn1.lpstrFileTitle = NULL;
    ofn1.hwndOwner = NULL;

    dst = ofilters;
    dst = RegisterFormat(dst,"Microsoft Bitmap","*.BMP");         //  1
    dst = RegisterFormat(dst,"CompuServe GIF","*.GIF");           //  2
    dst = RegisterFormat(dst,"Colour PostScript","*.PS;*.EPS");   //  3
    dst = RegisterFormat(dst,"Mono PostScript","*.PS;*.EPS");     //  4
    dst = RegisterFormat(dst,"Vector PostScript","*.PS;*.EPS");   //  5
    dst = RegisterFormat(dst,"Raw Portable Pixmap","*.PPM");      //  6
    dst = RegisterFormat(dst,"ASCII Portable Pixmap","*.PPM");    //  7
    dst = RegisterFormat(dst,"Apple Macintosh PICT","*.PIC");     //  8
    dst = RegisterFormat(dst,"Silicon Graphics RGB","*.RGB");     //  9
    dst = RegisterFormat(dst,"RLE Sun Rasterfile","*.RAS;*.IM8"); // 10
    dst = RegisterFormat(dst,"Sun Rasterfile","*.RAS");           // 11
	dst = RegisterFormat(dst,"Molscript","*.MIN");                // 12
	dst = RegisterFormat(dst,"Kinemage","*.KIN");                 // 13
	dst = RegisterFormat(dst,"POVRay 3","*.POV");                 // 14
	dst = RegisterFormat(dst,"VMRL 1.0","*.WRL");                 // 15
	dst = RegisterFormat(dst,"Ramachandran Prt Plot","*.RPP");    // 16
	dst = RegisterFormat(dst,"Raster3D","*.R3D");                 // 17
	dst = RegisterFormat(dst,"RasMol Script","*.SCR;*.SPT");      // 18
    *dst = '\0';

    /* Save File Common Dialog Box */
    ofn2.lStructSize=sizeof(OPENFILENAME);
    ofn2.Flags = OFN_NOCHANGEDIR | OFN_HIDEREADONLY | OFN_NOREADONLYRETURN
               | OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST;
    ofn2.lpstrFilter = ofilters;
    ofn2.lpstrTitle = "Select Graphics Ouptut File";
    ofn2.lpstrFile = fnamebuf;
    ofn2.nMaxFile = 128;

    ofn2.lpstrCustomFilter = NULL;
    ofn2.lpstrInitialDir = NULL;
    ofn2.lpstrFileTitle = NULL;
    ofn2.hwndOwner = NULL;
}


static void InitWindowsProfiles( void )
{
#ifdef _WIN32
    if( !GetProfileString("extensions","pdb","",Text,128) )
        WriteProfileString("extensions","pdb","raswin32.exe ^.pdb");
    if( !GetProfileString("extensions","ent","",Text,128) )
        WriteProfileString("extensions","ent","raswin32.exe ^.ent");
#else
    if( !GetProfileString("extensions","pdb","",Text,128) )
        WriteProfileString("extensions","pdb","raswin.exe ^.pdb");
    if( !GetProfileString("extensions","ent","",Text,128) )
        WriteProfileString("extensions","ent","raswin.exe ^.ent");
#endif
    DDETimeOut = GetPrivateProfileInt("RasWin","DDETimeOut",
                                      DefaultDDETimeOut,"RASWIN.INI");
}


static void InitDefaultValues( void )
{
    register int i;

    Interactive = True;

    DDEConvCount = 0;
    DDEAdviseCount = 0;
    for( i=0; i<MaxDDEConvNum; i++ )
        DDEConvData[i].server = NULL;
    for( i=0; i<MaxDDEAdviseNum; i++ )
        DDEAdviseData[i].server = NULL;
    RasWinDDEReady = True;

    fnamebuf[0] = '\0';
    snamebuf[0] = '\0';
    
    InitWidth = InitHeight = InitXPos = InitYPos = 0;

    CalcBondsFlag = True;
    CalcSurfFlag = False;
    LabelOptFlag = False;
    FileFormat = FormatPDB;
    AllowWrite = False;

#ifdef SOCKETS
    ServerPort = 21069;
#endif
}


#define FORMATOPTMAX   15
static struct {
        char *ident;
        int format;
        int  len;
    } FormatOpt[FORMATOPTMAX] = {
            { "alchemy",    FormatAlchemy,   7 },
            { "biosym",     FormatBiosym,    6 },
            { "cif",        FormatCIF,       3 },
            { "charmm",     FormatCharmm,    6 },
            { "fdat",       FormatFDAT,      4 },
            { "gaussian",   FormatGaussian,  8 },
            { "macromodel", FormatMacroMod, 10 },
            { "mdl",        FormatMDL,       3 },
            { "mmdb",       FormatMMDB,      4 },
            { "mol2",       FormatMol2,      4 },
            { "mopac",      FormatMOPAC,     5 },
            { "nmrpdb",     FormatNMRPDB,    6 },
            { "pdb",        FormatPDB,       3 },
            { "shelx",      FormatSHELX,     5 },
            { "xyz",        FormatXYZ,       3 }
                                };
   

static int ProcessOptions( char __far *ptr )
{
    register char *dst;
    register int i, j, argok;
	register int quotemark;
    register language klang;

    while( *ptr )
    {   if( (*ptr==' ') || (*ptr=='=') )
	{   ptr++;
	} else if( (*ptr=='/') || (*ptr=='-') )
	{   ptr++;
            if (*ptr=='-') {
              argok = False;
              for (klang=(language)0; klang < NUMLANGS; klang++) {
                if (!strcasecmp(ptr+1,lang2str(klang))) {
                  Language = klang;
                  ptr += (1+strlen(lang2str(klang)));
                  while( *ptr && (*ptr==' ') )
		          ptr++; argok = True; break;	
                }
              }
              if (argok) continue;
            }
            for( i=0; i<FORMATOPTMAX; i++ )
	        if( !strncasecmp(ptr,FormatOpt[i].ident,FormatOpt[i].len) )
                    break;

            if( i < FORMATOPTMAX )
	    {   FileFormat = FormatOpt[i].format;
                ptr += FormatOpt[i].len;
	    } else if( !strncasecmp(ptr,"sybyl",5) )
	    {   FileFormat = FormatMol2;
                ptr += 5;
            } else if( !strncasecmp(ptr,"pdbnmr",6) )
            {   FileFormat = FormatNMRPDB;
                ptr += 6;
#ifdef CEXIOLIB
            } else if( !strncasecmp(ptr,"cex",3) )
            {   FileFormat = FormatCEX;
                ptr += 3;
#endif 

	    } else if( !strncasecmp(ptr,"script",6) ) { 
	      ptr += 6;
		  while( *ptr && (*ptr==' ') )  ptr++;

		  if( *ptr ) {   
		    dst = snamebuf;
		    quotemark = ' ';
            if( *ptr == '"' || *ptr == '\'')
            {   quotemark = *ptr++;
                while( *ptr && (*ptr!=quotemark) )
                    *dst++ = *ptr++;
                if( *ptr==quotemark ) {
                    ptr++;
				} else return False;
		    } else /* Unquoted! */
            {   while( *ptr && (*ptr!=' ') )
                    *dst++ = *ptr++;
            }
            *dst = '\0';
		  } else return False;

#ifdef SOCKETS
        } else if( !strncasecmp(ptr,"port",4) ) {
          ptr += 4;
          while( *ptr && (*ptr==' ') ) ptr++;

          if( isdigit(*ptr) ) { 
            ServerPort = (*ptr++)-'0';
            while( isdigit(*ptr) )
            ServerPort = (10*ServerPort)+(*ptr++)-'0';
          } else return False;
#endif
        } else if( !strncasecmp(ptr,"connect",7) )
        {   CalcBondsFlag = True;
            ptr += 7;
        } else if( !strncasecmp(ptr,"noconnect",9) )
        {   CalcBondsFlag = False;     
            ptr += 8;
        } else if( !strncasecmp(ptr,"insecure",8) )
        {   AllowWrite = True;
            ptr += 8;
        } else if( !strncasecmp(ptr,"secure",6) )
        {   AllowWrite = False;
            ptr += 6;
        } else if ( !strncasecmp(ptr,"height",6)) { 
          ptr += 6;
          while( *ptr && (*ptr==' ') ) ptr++;

          if( isdigit(*ptr) ) { 
            InitHeight = (*ptr++)-'0';
            while( isdigit(*ptr) )
            InitHeight = (10*InitHeight)+(*ptr++)-'0';
            if (InitHeight < 48) InitHeight = 48;
          } else return False;
        } else if ( !strncasecmp(ptr,"high",6)) { 
          ptr += 4;
          while( *ptr && (*ptr==' ') ) ptr++;

          if( isdigit(*ptr) ) { 
            InitHeight = (*ptr++)-'0';
            while( isdigit(*ptr) )
            InitHeight = (10*InitHeight)+(*ptr++)-'0';
            if (InitHeight < 48) InitHeight = 48;
          } else return False;
        } else if ( !strncasecmp(ptr,"width",5)) { 
          ptr += 5;
          while( *ptr && (*ptr==' ') ) ptr++;
          if( isdigit(*ptr) ) { 
            InitWidth = (*ptr++)-'0';
            while( isdigit(*ptr) )
            InitWidth = (10*InitWidth)+(*ptr++)-'0';
            if (InitWidth < 48) InitWidth = 48;
            else if( (j = InitWidth%4) )
              InitWidth += 4-j;
          } else return False;
        } else if ( !strncasecmp(ptr,"wide",4)) { 
          ptr += 4;
          while( *ptr && (*ptr==' ') ) ptr++;
          if( isdigit(*ptr) ) { 
            InitWidth = (*ptr++)-'0';
            while( isdigit(*ptr) )
            InitWidth = (10*InitWidth)+(*ptr++)-'0';
            if (InitWidth < 48) InitWidth = 48;
            else if( (j = InitWidth%4) )
              InitWidth += 4-j;
          } else return False;
        } else if ( !strncasecmp(ptr,"xpos",4)) { 
          ptr += 4;
          while( *ptr && (*ptr==' ') ) ptr++;
          if( isdigit(*ptr) ) { 
            InitXPos = (*ptr++)-'0';
            while( isdigit(*ptr) )
            InitXPos = (10*InitXPos)+(*ptr++)-'0';
          } else return False;
        } else if ( !strncasecmp(ptr,"ypos",4)) { 
          ptr += 4;
          while( *ptr && (*ptr==' ') ) ptr++;
          if( isdigit(*ptr) ) { 
            InitYPos = (*ptr++)-'0';
            while( isdigit(*ptr) )
            InitYPos = (10*InitYPos)+(*ptr++)-'0';
          } else return False;
        	
        	
        } else return False;
  
      } else if( !*fnamebuf )
        {   dst = fnamebuf;
		    quotemark = ' ';
            if( *ptr == '"' || *ptr == '\'')
            {   quotemark = *ptr++;
                while( *ptr && (*ptr!=quotemark) )
                    *dst++ = *ptr++;
                if( *ptr==quotemark ) {
                    ptr++;
				} else {
				  return False;
				}
            } else /* Unquoted! */
            {   while( *ptr && (*ptr!=' ') )
                    *dst++ = *ptr++;
            }
            *dst = '\0';
        } else return False;
    }
    return True;
}

language bestlang( void ) 
{

    static char lud[5],lsd[5];
    language mylang;
    char * lpd, * endptr;
    
    
    int lsdlen;
    int ludlen;
    
    long langcode;

    mylang = English;
    
    if (getraid(filaid, 1025, fillang, 81) &&
      strlen(fillang) > 0 ) {
      return str2lang(fillang);
    }
	
    lsdlen = GetLocaleInfo(LOCALE_SYSTEM_DEFAULT,LOCALE_ILANGUAGE,lsd,5);
    ludlen = GetLocaleInfo(LOCALE_USER_DEFAULT,LOCALE_ILANGUAGE,lud,5);
    
    lpd = (ludlen>0) ? lud:lsd;

    langcode = strtol((const char *)lpd, &endptr, 16);
    
    switch (langcode)  {
    
    	case (0x080c):  /* fr-BE */
    	case (0x0c0c):  /* fr-CA */
    	case (0x040c):  /* fr-FR */
    	case (0x140c):  /* fr-LU */
    	case (0x180c):  /* fr-MC */
    	case (0x100c):  /* fr-CH */
    	case (0x0462):  /* fy-NL */	
    	  mylang = French; break;
    	  
    	case (0x0410):  /* it-IT */
    	case (0x0810):  /* it-CH */
    	  mylang = Italian; break;
    	
    	case (0x2c0a):  /* es-AR */
    	case (0x400a):  /* es-BO */
    	case (0x340a):  /* es-CL */
    	case (0x240a):  /* es-CO */
     	case (0x140a):  /* es-CR */
     	case (0x1c0a):  /* es-DO */
     	case (0x300a):  /* es-EC */
     	case (0x440a):  /* es-SV */
     	case (0x100a):  /* es-GT */
     	case (0x480a):  /* es-HN */
     	case (0x080a):  /* es-MX */
     	case (0x4c0a):  /* es-NI */
     	case (0x180a):  /* es-PA */
     	case (0x3c0a):  /* es-PY */
     	case (0x280a):  /* es-PE */
     	case (0x040a):  /* es- */
     	case (0x500a):  /* es-PR */
     	case (0x0c0a):  /* es-ES */
     	case (0x540a):  /* es-US */
     	case (0x380a):  /* es-UV */
     	case (0x200a):  /* es-VE */
    	  mylang = Spanish; break;

    	case (0x0419):  /* ru-RU */
    	  mylang = Russian; break;

    }

    
    return mylang;
    
}

void UpdateLanguage( void ) {

    getraid(filaid, 1025, fillang, 81);
    setraid(filaid,lang2str(Language));
}


#ifdef _WIN32
int WINAPI WinMain( HINSTANCE hCurrent, HINSTANCE hPrevious,
                    LPSTR lpCmdLine, int nCmdShow )
#else
int PASCAL WinMain( HINSTANCE hCurrent, HINSTANCE hPrevious,
                    LPSTR lpCmdLine, int nCmdShow )
#endif
{
    register FILE *fp;
    MSG event;
    static char VersionStr[255];
    int ii;

 
    firstpass = 1;

    Interactive = False;
    
    
    SwitchLang (bestlang());

    sprintf (VersionStr,"%s\nVersion %s %s\n%s\n", 
             MAIN_COPYRIGHT, VERSION, 
             VER_DATE, VER_COPYRIGHT);


   hInstance = hCurrent;
   if( !hPrevious && !InitialiseApplication() )
	return False;

    InitDefaultValues();
    InitFileDialogBoxes();
    InitWindowsProfiles();
    ProcessOptions(lpCmdLine);
    
    for (ii=0; ii < NUMLANGS; ii++) {
      if (Language == langfonts[ii].lang) {
        setlocale(LC_ALL,lang2str(Language));
        break;
      }
    }

    /* Avoid Windows NT problems! */
    ReDrawFlag = RFInitial;
    CommandActive = True;

    if( !InitTerminal(hInstance) ||
	!OpenDisplay(hInstance,nCmdShow) )
       return False;

    SwitchLang(Language);

    WriteString("RasMol Molecular Renderer\n");
    WriteString("Roger Sayle, August 1995\n");
    WriteString(VersionStr);
    WriteString("*** See \"help notice\" for further notices ***\n");
	    
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
    InitialiseMultiple();
    InitialiseWBRotate();
    

#ifdef SOCKETS
    OpenSocket(CanvWin);
#endif
  
    if( *fnamebuf && FetchFile(FileFormat,True,fnamebuf) )
        DefaultRepresentation();
    ResetCommandLine(1);


    LoadInitFile();
    if( *snamebuf )
    {   if( !(fp=fopen(snamebuf,"rb")) )
	{   if( CommandActive )
		WriteChar('\n');
	    WriteString(MsgStrs[StrErrFile]);
	    WriteString(snamebuf);
	    WriteString(MsgStrs[StrNotFnd]);
	    CommandActive = False;
	} else LoadScriptFile(fp,snamebuf);
    }

    RefreshScreen();
    ReDrawFlag = NextReDrawFlag;
    if( !CommandActive )
	ResetCommandLine(0);

    DragAcceptFiles(CanvWin,TRUE);


    while( GetMessage(&event,NULL,0,0) )
    {   TranslateMessage(&event);
	DispatchMessage(&event);
    }
    DeleteObject(TermFont);
    CloseDDELinks();
#ifdef SOCKETS
    CloseSockets();
#endif
    CloseDisplay();

    return event.wParam;
}

