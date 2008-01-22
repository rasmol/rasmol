/***************************************************************************
 *                               RasMol 2.7.4                              *
 *                                                                         *
 *                                 RasMol                                  *
 *                 Molecular Graphics Visualisation Tool                   *
 *                            19 November 2007                             *
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
 *Bernstein          RasMol 2.7.1   Jun 99         1998-2007               *
 *                   RasMol 2.7.1.1 Jan 01                                 *
 *                   RasMol 2.7.2   Aug 00                                 *
 *                   RasMol 2.7.2.1 Apr 01                                 *
 *                   RasMol 2.7.2.1.1 Jan 04                               *
 *                   RasMol 2.7.3   Feb 05                                 *
 *                   RasMol 2.7.3.1 Apr 06                                 *
 *                   RasMol 2.7.4   Nov 07                                 *
 *                                                                         *
 * RasMol 2.7.3 incorporates changes by Clarice Chigbo, Ricky Chachra,     *
 * and Mamoru Yamanishi.  Work on RasMol 2.7.3 supported in part by        *
 * grants DBI-0203064, DBI-0315281 and EF-0312612 from the U.S. National   *
 * Science Foundation and grant DE-FG02-03ER63601 from the U.S. Department *
 * of Energy.  RasMol 2.7.4 incorporates changes by G. Todorov, Nan Jia,   *
 * N. Darakev, P. Kamburov, G. McQuillan, J. Jemilawon.  Work on RasMol    *
 * 2.7.4 supported in part by grant 1R15GM078077-01 from the National      *
 * Institute of General Medical Sciences (NIGMS). The content is solely    *
 * the responsibility of the authors and does not necessarily represent    * 
 * the official views of the funding organizations.                        *
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
 *               Copyright(C) Herbert J. Bernstein 1998-2007               *
 *                                                                         *
 *                READ THE FILE NOTICE FOR RASMOL LICENSES                 *
 *Please read the file NOTICE for important notices which apply to this    *
 *package and for license terms (GPL or RASLIC).                           *
 ***************************************************************************/
/* graphics.h
 */

#ifdef APPLEMAC      
#define DefaultWide  400
#define DefaultHigh  400
#endif

#ifdef IBMPC
#define DefaultWide  480
#define DefaultHigh  480
#endif

#ifndef DefaultWide
#define DefaultWide  576
#define DefaultHigh  576
#endif


#ifdef EIGHTBIT
#define LutSize  256
#else
#define LutSize  1024
#endif


#define RFRotateX  0x0001
#define RFRotateY  0x0002
#define RFRotateZ  0x0004
#define RFZoom     0x0008
#define RFTransX   0x0010
#define RFTransY   0x0020
#define RFTransZ   0x0040
#define RFSlab     0x0080
#define RFReSize   0x0100
#define RFColour   0x0200
#define RFRefresh  0x0400
#define RFRotBond  0x0800

#define RFTrans    0x0070
#define RFRotate   0x0807
#define RFApply    0x097F
#define RFDials    0x00FF
#define RFMagnify  0x0108
#define RFInitial  0x09FF


#define DialRX      0
#define DialRY      1
#define DialRZ      2
#define DialZoom    3
#define DialTX      4
#define DialTY      5
#define DialTZ      6
#define DialSlab    7
#define DialBClip   8
#define DialBRot    9

#ifdef X11WIN
#define DLGScale        ((FontHigh+8)/9)
typedef struct _DLGItem {
    int DLGtype;         /* type of the dialog item */
    char ** text;        /* text for the dialog item */
    int  Identifier;     /* identifier of the field */
    int x, y, width, height, status;
} DLGItem;

#include "raswin.idm"
#define IDD_OK 0

#define DLGCTEXT        1
#define DLGLTEXT        2
#define DLGPUSHBUTTON   3
#define DLGCHECKBOX     4
#define DLGICON         5

#define AboutDLGXpos  20
#define AboutDLGWidth 260
#define AboutDLGHeight 116
#define AboutDLGMItem  MenuBarMax
#define AboutDLGCount  13
/*  WARNING:  The IDD_NOSHOW checkbox must be last */
#define AboutDLGNOSHOWindex AboutDLGCount-1

#endif




#ifdef GRAPHICS
double DialValue[10];
int XRange, WRange;
int YRange, HRange;
int ZRange;
int UseHourGlass;
int DisableMenu;
int ReDrawFlag;
int Range;

int MouseCaptureStatus;
int MouseUpdateStatus;

Pixel __huge *FBuffer;
short __huge *DBuffer;
short __huge *SLineBuffer;
short __huge *DLineBuffer;

Pixel Lut[LutSize];
Byte RLut[LutSize];
Byte GLut[LutSize];
Byte BLut[LutSize];
Byte ULut[LutSize];


#ifdef MSWIN
#include <windows.h>
LOGPALETTE __far *Palette;
HPALETTE ColourMap;
HGLOBAL FBufHandle;
HGLOBAL DBufHandle;
HGLOBAL SLineHandle;
HGLOBAL DLineHandle;
HGLOBAL CBufHandle;
HBITMAP PixMap;
HWND CanvWin;
#endif /* MSWIN */

#ifdef APPLEMAC
ControlHandle HScroll;
ControlHandle VScroll;
CursHandle CanvCursor;
CursHandle CmndCursor;
CursHandle WaitCursor;
WindowPtr CanvWin;
WindowPtr CmndWin;
THPrint PrintHand;
Handle FBufHandle;
Handle DBufHandle;
Handle SLineHandle;
Handle DLinehandle;
Handle CBufHandle;
#endif /* APPLEMAC */

#ifdef X11WIN
Display *dpy;
Pixmap icon;
Visual *vis;
int Monochrome;
int PixDepth;
int LocalMap;
Colormap cmap;
Window PopUpWin;
Window MainWin;
Window CanvWin;
Window MenuWin;
Window RootWin;
char filaid [1025];
char macaid [1025];
char fillang [81];


#endif

#ifdef X11WIN
static char * EMPTY = "";
static char * RMG = "RasMol Molecular Graphics";
static char * RURL = "http://www.rasmol.org/";
static char * RVERS  = "X11 Version 2.7.3.1";
static char * RCOP = "Copyright (C) R.Sayle 1992-1999";
static char * RCOP2 = "Copyright (C) H. Bernstein 1998-2006";
static char * REMAIL = "yaya@bernstein-plus-sons.com";
static char * ROK = "OK";

#ifdef USE_UNAME
#include <sys/utsname.h>

struct utsname AboutDLGUNAME;
char _unamebuffer[81];
static char * unamebuffer=_unamebuffer;
#endif


/* WARNING:  Change the definition of  AboutDLGCount if this array chnges */
DLGItem AboutDLG[AboutDLGCount] = {
  { DLGICON,  &EMPTY,                      -1,           16,  45,  45, 45, 0 },
  { DLGCTEXT, &RMG,                        -1,           80,   5, 100,  8, 0 },
  { DLGCTEXT, &RURL,                       -1,           80,  14, 100,  8, 0 },
  { DLGCTEXT, &RCOP,                       -1,           80,  25, 100,  8, 0 },
  { DLGCTEXT, &RVERS,                      -1,           80,  34, 100,  8, 0 },
  { DLGCTEXT, &RCOP2,                      -1,           80,  43, 100,  8, 0 },
  { DLGCTEXT, &REMAIL,                     -1,           60,  52, 140,  8, 0 },
  { DLGCTEXT,
#ifdef USE_UNAME
  &unamebuffer,
#else 
  &EMPTY,
#endif
                                           IDD_HARDWARE, 40,  70, 180,  8, 0 },
  { DLGCTEXT, &MsgStrs[StrWarranty],       IDD_WARRANTY,  0,  79, 260,  8, 0 },
  { DLGPUSHBUTTON, &ROK,                   IDD_OK,      115,  95,  30, 14, 0 },
  { DLGPUSHBUTTON, &MsgStrs[StrRegister],  IDM_REGISTER, 32,  95,  81, 14, 0 },
  { DLGPUSHBUTTON, &MsgStrs[StrDonate],    IDM_DONATE,  147,  95,  81, 14, 0 },
/*  WARNING:  The IDD_NOSHOW checkbox must be last */
  { DLGCHECKBOX, &MsgStrs[StrNoShow],      IDD_NOSHOW,   32, 104, 180,  8, 0 }	
};

#endif /* X11WIN */


#else /* GRAPHICS */
extern double DialValue[10];
extern int XRange, WRange;
extern int YRange, HRange;
extern int ZRange;
extern int UseHourGlass;
extern int DisableMenu;
extern int ReDrawFlag;
extern int Range;

extern int MouseCaptureStatus;
extern int MouseUpdateStatus;

extern Pixel __huge *FBuffer;
extern short __huge *DBuffer;
extern short __huge *SLineBuffer;
extern short __huge *DLineBuffer;


extern Pixel Lut[LutSize];
extern Byte RLut[LutSize];
extern Byte GLut[LutSize];
extern Byte BLut[LutSize];
extern Byte ULut[LutSize];


#ifdef MSWIN
extern LOGPALETTE __far *Palette;
extern HPALETTE ColourMap;
extern HGLOBAL FBufHandle;
extern HGLOBAL SLineHandle;
extern HGLOBAL DLineHandle;
extern HGLOBAL DBufHandle;
extern HGLOBAL CBufHandle;
extern HBITMAP PixMap;
extern HWND CanvWin;
#endif /* MSWIN */

#ifdef APPLEMAC
extern ControlHandle HScroll;
extern ControlHandle VScroll;
extern CursHandle CanvCursor;
extern CursHandle CmndCursor;
extern CursHandle WaitCursor;
extern WindowPtr CanvWin;
extern WindowPtr CmndWin;
extern THPrint PrintHand;
extern Handle FBufHandle;
extern Handle DBufHandle;
extern Handle CBufHandle;
#endif /* APPLEMAC */

#ifdef X11WIN
extern DLGItem AboutDLG[AboutDLGCount];
extern char filaid [1025];
extern char macaid [1025];
extern char fillang [81];

#endif /* X11WIN */


#endif

int CreateImage( void );
void TransferImage( void );
int ClipboardImage( void );
void ClearImage( void );
int PrintImage( void );

void AllocateColourMap( void );
void UpdateScrollBars( void );
int LookUpColour( char*, int*, int*, int* );
void SetMouseUpdateStatus( int );
void SetMouseCaptureStatus( int );
void SetCanvasTitle( char* );
void ReDrawWindow( void );
void EnableMenus( int );
void CloseDisplay( void );
void BeginWait( void );
void EndWait( void );

#ifdef MSWIN
int OpenDisplay( HANDLE, int );
#else
int OpenDisplay( int, int );
#endif

#if !defined(IBMPC) && !defined(APPLEMAC)
int FetchEvent( int );
void DisplayAboutDLG( void );
void UnDisplayAboutDLG( void );
void DrawAboutDLG( void );
#endif

#ifdef X11WIN
void FatalGraphicsError( char *ptr );
int getraid ( char *, size_t, char *, size_t);
int setraid ( const char *, const char * );
size_t DetermineApplicationIdentifier( char *, size_t );


#endif

