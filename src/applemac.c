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
/* applemac.c
 $Log$
 Revision 1.5  2008/03/22 18:42:51  yaya
 Post release cleanup and credit to Ikonen in file headers. -- HJB

 Revision 1.4  2008/03/17 03:01:31  yaya
 Update to agree with 2.7.4.2 release and T. Ikonen GTK mods -- HJB

 Revision 1.3  2008/03/17 01:32:41  yaya
 Add gtk mods by tpikonen, and intergate with 2.7.4.2 mods -- HJB

 Revision 1.3  2008/03/16 22:25:21  yaya
 Align comments with production version; Update rasmol_install and
 rasmol_run shell scripts for Japanese and Chinese; Align logic for
 positioning and sizing initial window with windows version -- HJB

 Revision 1.2  2008/01/28 03:29:37  yaya
 Update CVS to RasMol_2.7.4.1 -- HJB

 Revision 1.2  2007/11/19 03:28:39  yaya
 Update to credits for 2.7.4 in manual and headers
 Mask code added -- HJB

 Revision 1.1.1.1  2007/03/01 01:16:33  todorovg
 Chinese working versio from rasmol_ru initial import

 Revision 1.6  2006/11/28 03:12:48  yaya
 Changes for Russian and About dialog in unix
 This is a variant tried under Mac OS X.  Changes
 for Linux still needed.  note that more work is
 needed on font selection. -- HJB

 Revision 1.5  2006/11/01 03:23:50  yaya
 Update NSIS windows installer for more script types and to fix
 misplaced script instructions for data files; add document and
 script icons directly in raswin.exe; add credit line to
 G. A. Pozhvanov in comments for Russian translations. -- HJB

 Revision 1.4  2006/10/30 15:18:12  yaya
 Add NSIS installer, make language sticky for windows and mac
 Set up RASMOLPATH environment variable on install -- HJB

 Revision 1.3  2006/10/14 21:05:51  yaya
 Changes for build of Mac Classic versions with Russian
 and with new About and Help dialogs -- HJB

 Revision 1.2  2006/09/17 10:53:55  yaya
 Clean up headers and start on code for X11 -- HJB

 Revision 1.1.1.1  2006/09/16 18:45:39  yaya
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
#ifndef __MC68K__
  #include <InternetConfig.h>
#endif

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

/* GetPreferenceString
     retrieves the string in the STR# resource of ID sid at
     index sind and stores it as a pascal string in buffer
     
     Returns the length of the string or 0 if no string is found*/

int GetPreferenceString (Str255 buffer, int sid, int sind) {

    OSErr pferr;
    long pfdid;
    short pfvid;
    Str255 pfname;
    FSSpec pfspec;
    int pfrefno;
    short oldresfile;
    
    buffer[0] = 0;
    oldresfile = CurResFile();
    pferr = FindFolder(kOnSystemDisk, kPreferencesFolderType, kDontCreateFolder, &pfvid, &pfdid);
    if (pferr == noErr) pferr = FSMakeFSSpec(pfvid, pfdid,
        tostr255(pfname,("RasMol_" VERSION " Settings")), &pfspec );	
    if (pferr == noErr) pfrefno = FSpOpenResFile(&pfspec, fsRdPerm);
    
    if (pferr == noErr && (pferr = ResError())== noErr) {
      GetIndString(buffer,sid,sind);
      CloseResFile(pfrefno);
    }
    UseResFile(oldresfile);
    return (pferr == noErr)?(int)buffer[0]:0;
}



/* Launch a browser with a URL */

int LaunchBrowserWithURL(const char * URL) {

#ifdef __MC68K__

  return 1;

#else

  OSStatus launcherr;
  ICInstance instance;
  long start, end;
  
  if (ICStart == (void *) kUnresolvedCFragSymbolAddress
   || ICFindConfigFile == (void *) kUnresolvedCFragSymbolAddress
   || ICLaunchURL == (void *) kUnresolvedCFragSymbolAddress
   || ICStop == (void *) kUnresolvedCFragSymbolAddress) return 1;
  if ( noErr==(launcherr=ICStart(&instance,'????') ) ){ 
    if ( noErr == (launcherr=ICFindConfigFile(instance, 0, nil))) {
      start = 0; end = strlen(URL);
      launcherr = ICLaunchURL(instance,"\p", URL, strlen(URL), &start, &end);
    }
    ICStop(instance);
  }
  
  return (launcherr==noErr)?0:1;
  
#endif
	
}


/* FindPreferenceString 
     Finds a string in the STR# resource of ID sid that matches the
     pascal string in buffer 
     
     Returns the index of the matching string or zero */

int FindPreferenceString (Str255 buffer, int sid) {


    OSErr pferr;
    long pfdid;
    short pfvid;
    Str255 pfname;
    Str255 testcase;
    FSSpec pfspec;
    int pfrefno;
    short oldresfile;
    int strlcur, strllen;
    unsigned char * sptr;
    SInt8  state;
    Handle strlres;
   
    strlcur = 0;
    oldresfile = CurResFile();
    pferr = FindFolder(kOnSystemDisk, kPreferencesFolderType, kDontCreateFolder, &pfvid, &pfdid);
    if (pferr == noErr) pferr = FSMakeFSSpec(pfvid, pfdid,
        tostr255(pfname,("RasMol_" VERSION " Settings")), &pfspec );	
    if (pferr == noErr) pfrefno = FSpOpenResFile(&pfspec, fsRdPerm);
    
    if (pferr == noErr && (pferr = ResError())== noErr) {
      strlres = GetResource('STR#',sid);
      strllen = 0;
      if (ResError() == noErr && strlres) {
        state = HGetState(strlres);
        HLock(strlres);
        strllen = 1+*((short *)(*strlres));
        sptr = 2+(unsigned char *)*strlres;
        for (strlcur = 1; strlcur <= strllen; strlcur++) {
          if (!str255casecmp(sptr,buffer)) break;
          sptr +=(1+*sptr);       
        }
        if (strlcur > strllen) strlcur = 0;
        HSetState(strlres, state);
        RemoveResource(strlres);
      }
      CloseResFile(pfrefno);
    }
    UseResFile(oldresfile);
    return (pferr == noErr)?strlcur:0;
}


int GetMacName (Str255 buffer) {

  long svers;
  Handle macstrH;
  SInt8  state;
  int ssize;
  unsigned char * src, * dst;
  short oldresfile;
  
  oldresfile = CurResFile();
  UseResFile(0);  
  buffer[0]=0;
  Gestalt(gestaltSystemVersion, &svers);
  if (svers < 0x01000L) {
    macstrH = GetResource('STR ',-16413);
    if ( macstrH != nil ) {
      state = HGetState(macstrH);
      HLock(macstrH);
      src = (unsigned char *)*macstrH;
      dst = buffer;
      ssize = 1+(int)*src;
      while (ssize) { *dst++ = *src++; ssize--; }
      HSetState(macstrH, state);
      UseResFile(oldresfile);
      if (buffer[0]==0) {
        strcpy((char *)buffer+1,"UNKNOWN");
        buffer[0] = strlen("UNKNOWN");
      }
      return 0;
    }
  } 
  UseResFile(oldresfile);
  return 1;
}

int GetUserName (Str255 buffer) {

  long svers;
  Handle macstrH;
  SInt8  state;
  int ssize;
  unsigned char * src, * dst;
  short oldresfile;
  
  oldresfile = CurResFile();
  UseResFile(0);
  buffer[0]=0;
  Gestalt(gestaltSystemVersion, &svers);
  if (svers < 0x01000L) {
    macstrH = GetResource('STR ',-16096);
    if ( macstrH != nil ) {
      state = HGetState(macstrH);
      HLock(macstrH);
      src = (unsigned char *)*macstrH;
      dst = buffer;
      ssize = 1+(int)*src;
      while (ssize) { *dst++ = *src++; ssize--; }
      HSetState(macstrH, state);
      UseResFile(oldresfile);
      if (buffer[0]==0) {
        strcpy((char *)buffer+1,"UNKNOWN");
        buffer[0] = strlen("UNKNOWN");
      }
      return 0;
    }
  } 
  UseResFile(oldresfile);
  return 1;
}


/* SetPreferenceString
     Inserts the pascal string in buffer into the STR# resource
     with ID sid at index sind.  If sind is 0, the string is
     appended to the resource.  If sind is the index of an
     existing string, the old string is replaced by the new
     string.
     
     Returns the index at which the new string is inserted,
     or 0 if there is an error */

int SetPreferenceString (Str255 buffer, int sid, int sind) {

    OSErr pferr;
    long pfdid;
    short pfvid;
    Str255 pfname;
    FSSpec pfspec;
    FCBPBRec pffcb;
    int pfrefno;
    int pfresult;
    short oldresfile;
    short strllen;
    short strlcur;
    int pfclose;
    Handle oldresm;
    Handle strlres;
    Handle nstrlres;
    unsigned char strllst[1025];
    unsigned char * src, * dst, *srcsave;
    int ssize;
    unsigned char zero = 0;
    SInt8   state;
    
    pfclose = False;
    oldresm = LMGetTopMapHndl();
    
    oldresfile = CurResFile();
    pferr = FindFolder(kOnSystemDisk, kPreferencesFolderType, kDontCreateFolder, &pfvid, &pfdid);
    if ( pferr == noErr) pferr = FSMakeFSSpec(pfvid, pfdid,
        tostr255(pfname,("RasMol_" VERSION " Settings")), &pfspec );	
    if ( pferr == noErr ) pfrefno = FSpOpenResFile(&pfspec, fsRdWrPerm);
    
    if ( pferr == fnfErr ) {
      FSpCreateResFile(&pfspec, 'RSML', 'pref',smRoman);
      pferr = noErr;
}

    if (pferr == noErr && (pferr = ResError())== noErr) {
    
      pfclose = (LMGetTopMapHndl() != oldresm);
      pffcb.ioNamePtr = nil;
      pffcb.ioVRefNum = 0;
      pffcb.ioRefNum = pfrefno;
      pffcb.ioFCBIndx = 0;
      if ( PBGetFCBInfoSync(&pffcb) == noErr ) {
        pfresult = ((pffcb.ioFCBFlags & (1 << 8)) != 0);
      } else {
        pfresult = False;
      }
      strlres = GetResource('STR#',sid);
      dst = strllst+2;
      if (ResError() == noErr && strlres) {
        state = HGetState(strlres);
        HLock(strlres);
        strllen = *((short *)(*strlres));
        src = ((unsigned char *)*(strlres))+2;
        for (strlcur = 1; strlcur <= strllen; strlcur++) {
          if (strlcur == sind) {
            srcsave = src;
          	src = buffer;
          }
          ssize = (int)*src+1;
          if ((dst-strllst)+ssize > 1024) {
             if (pfclose)CloseResFile(pfrefno);
             UseResFile(oldresfile);
             return (pferr == noErr)?0:1;    
          }
          while (ssize) { *dst++ = *src++; ssize--;}
          if ( strlcur == sind )  {
            src = srcsave + ((int)*srcsave+1);
          }
        }
        HSetState(strlres, state);
        RemoveResource(strlres);
      } else {
        strlcur = 1;
      }
      while( strlcur < sind && (dst-strllst) < 1024) {
        *dst++ = 0;
        strlcur++;
      }
      if (strlcur == sind || sind == 0) {
        src = buffer;
        ssize = (int)*src+1;
        if ((dst-strllst)+ssize > 1024) {
          if (pfclose)CloseResFile(pfrefno);
          UseResFile(oldresfile);
          return (pferr == noErr)?0:1;    
        }
        while (ssize) { *dst++ = *src++; ssize--; }
        strlcur++;	
      }
      *((short *)strllst) = strlcur-1;
      	
      pferr = PtrToHand(strllst, &nstrlres, dst-strllst);
      AddResource(nstrlres,'STR#',sid,&zero);
    }
    
    if (pfclose)CloseResFile(pfrefno);
    UseResFile(oldresfile);
    return (pferr == noErr)?strlcur:0;
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
      x = WorldDialValue[DialRY];
    else
      x = DialValue[DialRY];
    
    pos = 50+(int)(50.0*x);
#ifdef USEOLDROUTINENAMES
    SetCtlValue(HScroll,pos);
#else
    SetControlValue(HScroll,pos);
#endif
    
    if ( RotMode == RotAll )
	y = WorldDialValue[DialRX];
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

unsigned char * tostr255(unsigned char buffer[255], const char * str)
{   unsigned char *dst;
    unsigned char *src;

    buffer[0]=0;
    dst = buffer+1;
    src = (unsigned char *)str;
    while( *src && (dst<buffer+254) )
      *dst++ = *((unsigned char *)src++);
    buffer[0] = (unsigned char)((dst-buffer)-1);
    while ((dst-buffer)<255)*dst++ = (unsigned char)'\0';
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
              SetMenuItemText(hand,3,tostr255(buffer,MsgStrs[StrRegister]));
              SetMenuItemText(hand,4,tostr255(buffer,MsgStrs[StrDonate]));
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
        
    CQRMSet(DialQRot,0.,0.,0.,0.);
    
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

