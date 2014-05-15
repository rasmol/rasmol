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
/* x11win.c
 $Log: x11win.c,v $
 Revision 1.1  2012/04/28 02:08:54  yaya
 Initial revision

 Revision 1.13  2008/06/28 14:25:26  yaya
 Make more IPC errors non-fatal.  -- HJB

 Revision 1.12  2008/06/28 14:06:37  yaya
 Fix unused variable warning in command.c
 Start changes for loading models in infile.c
 Make handling of IPC errors non-fatal in x11win.c -- HJB

 Revision 1.11  2008/06/18 20:04:53  yaya
 Start in infrastructure for animation
 Start on WPDB code -- HJB

 Revision 1.10  2008/03/22 18:42:56  yaya
 Post release cleanup and credit to Ikonen in file headers. -- HJB

 Revision 1.9  2008/03/17 03:01:32  yaya
 Update to agree with 2.7.4.2 release and T. Ikonen GTK mods -- HJB

 Revision 1.6  2008/03/17 01:32:41  yaya
 Add gtk mods by tpikonen, and intergate with 2.7.4.2 mods -- HJB

 Revision 1.5  2008/03/16 22:38:10  yaya
 Update stable release to 2.7.4.2; Update rasmol_install and rasmol_run
 scripts to handle Japanese and Chiness (using cxterm), changing
 Japanese for unix back to EUCJP; and align command line options
 to set initial window size and position to agree between unix and
 windows -- HJB

 Revision 1.8  2008/03/16 22:25:22  yaya
 Align comments with production version; Update rasmol_install and
 rasmol_run shell scripts for Japanese and Chinese; Align logic for
 positioning and sizing initial window with windows version -- HJB

 Revision 1.7  2008/03/08 21:41:03  yaya
 Updates to switch Japanese in unix to EUC_CN, and to reorganize
 languagues directory for split between mswin and unix. -- HJB

 Revision 1.6  2008/03/08 15:26:50  yaya
 Fixes to get Chinese working under MacOSX for RasMol 2.7.4
 Based on suggested fixes by Mamoru Yamanishi. -- HJB

 Revision 1.4  2008/01/28 03:29:38  yaya
 Update CVS to RasMol_2.7.4.1 -- HJB

 Revision 1.5  2007/11/19 03:28:40  yaya
 Update to credits for 2.7.4 in manual and headers
 Mask code added -- HJB

 Revision 1.4  2007/03/13 21:48:19  todorovg
 Fixed a few typo errors that were causing xforms to crash

 Revision 1.3  2007/03/13 21:09:28  todorovg
 fixed bug when you run rasmol in chinese and japanese; added catch for fontset to print an error and not give segfault

 Revision 1.2  2007/03/05 22:27:26  todorovg
 Fixed japanese

 Revision 1.10  2007/02/26 18:40:31  todorovg
 fixed menu click bug

 Revision 1.9  2006/12/29 04:07:37  yaya
 Update x11win.c and rasmol.c to add links to list of browsers
 and to kill About dialog when the menu bar is selected
 Update rasmol_install.sh to allow recompilation of fonts
 on install to handle openwin and other old systems that
 can't handle byte-swapped bdf files, and add enviroment
 variable RASMOL_NOSPAWN to suppress spawn in intermediate
 xterm from rasmol_run.sh. -- HJB

 Revision 1.8  2006/12/24 03:48:28  yaya
 Clean up conditionals for MITSHM if it is not defined
 Fix choice of license files for install -- HJB

 Revision 1.7  2006/12/23 23:18:01  yaya
 Detect remote X server that does not share memory
 Add new rasmol_install.sh and rasmol_run.sh scripts -- HJB

 Revision 1.6  2006/12/11 02:45:39  yaya
 Migrate some of the language switching tables to mac and mswin version
 and update the icons for mswin and X11 versions. -- HJB

 Revision 1.5  2006/12/10 03:32:45  yaya
 Additional updates for linux build with Russian, cleaning
 up X11 font selection for CP1251 and recovering when fonts
 are missing. -- HJB

 Revision 1.4  2006/12/03 02:53:10  yaya
 Clean up compilation warnings in outfile.c
 Mods for about screen under Linux -- HJB

 Revision 1.3  2006/11/28 03:12:48  yaya
 Changes for Russian and About dialog in unix
 This is a variant tried under Mac OS X.  Changes
 for Linux still needed.  note that more work is
 needed on font selection. -- HJB

 Revision 1.2  2006/09/17 10:53:56  yaya
 Clean up headers and start on code for X11 -- HJB

 Revision 1.1.1.1  2006/09/16 18:46:03  yaya
 Start of RasMol Russian Translation Project based on translations
 by Gregory A. Pozhvanov of Saint Petersburg State University -- HJB

 Revision 1.2  2006/06/19 22:06:41  todorovg
 Rasmol 2.7.3.1

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

 Revision 1.3  2001/02/07 20:30:31  yaya
 *** empty log message ***

 Revision 1.2  2001/02/06 21:58:18  yaya
 *** empty log message ***

 Revision 1.1  2001/01/31 02:13:45  yaya
 Initial revision

 Revision 1.8  2000/08/27 00:54:54  yaya
 create rotation bond database

 Revision 1.7  2000/08/26 18:12:50  yaya
 Updates to header comments in all files

 Revision 1.6  2000/08/21 21:07:56  yaya
 semi-final ucb mods

 Revision 1.5  2000/08/18 16:40:56  yaya
 *** empty log message ***

 Revision 1.4  2000/08/13 20:56:35  yaya
 Conversion from toolbar to menus

 Revision 1.3  2000/08/12 21:10:41  yaya
 Minimal X windows mods

 */


#ifndef sun386
#include <stdlib.h>
#endif
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

#ifdef VMS
#include <in.h>
#endif

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>
#include <X11/keysym.h>
#include <X11/cursorfont.h>

#ifdef X_LOCALE
#include <X11/Xlocale.h>
#define SetLocale _Xsetlocale
#else
#include <locale.h>
#define SetLocale setlocale
#endif

#define GRAPHICS
#include "rasmol.h"
#include "bitmaps.h"
#include "command.h"
#include "cmndline.h"
#include "molecule.h"
#include "abstree.h"
#include "render.h"
#include "multiple.h"
#include "transfor.h"
#include "vector.h"
#include "wbrotate.h"
#include "langsel.h"
#include "graphics.h"



/* Menu Definitions */
#define mbEnable    0x01
#define mbOption    0x02
#define mbSepBar    0x08
#define mbAccel     0x10


typedef struct _MenuItem {
            char **text;
            int flags;
            int *pos;
            int *len;
            int *enable;
            int value;
        } MenuItem;

static int zero = 0;

static MenuItem FilMenu[21] = {
    { &MsgStrs[StrMOpen]   /* "Open..."   */,   0x11,  &MsgAuxl[StrMOpen],
        &MsgLens[StrMOpen],     NULL, 0     },
    { &MsgStrs[StrMSaveAs] /*" Save As..."*/,   0x11,  &MsgAuxl[StrMSaveAs],
        &MsgLens[StrMSaveAs],   NULL, 0     },
    { &MsgStrs[StrMClose]  /* "Close"     */,   0x11,  &MsgAuxl[StrMClose],
        &MsgLens[StrMClose],    NULL, 0     },
    { &MsgStrs[StrMEmpty]  /*  ""         */,   0x08,  &MsgAuxl[StrMEmpty],
        &MsgLens[StrMEmpty],    NULL, 0    },
    { &MsgStrs[StrMExit]   /*  "Exit"     */,   0x11,  &MsgAuxl[StrMExit],
        &MsgLens[StrMExit],     NULL, 0    },
    { &MsgStrs[StrMEmpty]  /*  ""         */,   0x08,  &MsgAuxl[StrMEmpty],
        &MsgLens[StrMEmpty],    NULL, 0    },
    { &(MolNStr[0]),                            0x01,  &zero,
        &MolNLen[0],            &MoleculeIndex, 0 },  
    { &(MolNStr[1]),                            0x01,  &zero,
        &MolNLen[1],            &MoleculeIndex, 1 },  
    { &(MolNStr[2]),                            0x01,  &zero,
        &MolNLen[2],            &MoleculeIndex, 2 },  
    { &(MolNStr[3]),                            0x01,  &zero,
        &MolNLen[3],            &MoleculeIndex, 3 },  
    { &(MolNStr[4]),                            0x01,  &zero,
        &MolNLen[4],            &MoleculeIndex, 4 },
    { &(MolNStr[5]),                            0x01,  &zero,
        &MolNLen[5],            &MoleculeIndex, 5 },  
    { &(MolNStr[6]),                            0x01,  &zero,
        &MolNLen[6],            &MoleculeIndex, 6 },  
    { &(MolNStr[7]),                            0x01,  &zero,
        &MolNLen[7],            &MoleculeIndex, 7 },  
    { &(MolNStr[8]),                            0x01,  &zero,
        &MolNLen[8],            &MoleculeIndex, 8 },  
    { &(MolNStr[9]),                            0x01,  &zero,
        &MolNLen[9],            &MoleculeIndex, 9 },
    { &(MolNStr[10]),                            0x01,  &zero,
        &MolNLen[10],            &MoleculeIndex, 10 },  
    { &(MolNStr[11]),                            0x01,  &zero,
        &MolNLen[11],            &MoleculeIndex, 11 },  
    { &(MolNStr[12]),                            0x01,  &zero,
        &MolNLen[12],            &MoleculeIndex, 12 },  
    { &(MolNStr[13]),                            0x01,  &zero,
        &MolNLen[13],            &MoleculeIndex, 13 },  
    { &(MolNStr[14]),                            0x01,  &zero,
        &MolNLen[14],            &MoleculeIndex, 14 }};

static MenuItem DisMenu[9] = {
    { &MsgStrs[StrMWirefr] /* "Wireframe"    */,     0x11,  &MsgAuxl[StrMWirefr],
        &MsgLens[StrMWirefr],    NULL, 0     },
    { &MsgStrs[StrMBackbn] /* "Backbone"     */,     0x11,  &MsgAuxl[StrMBackbn],
        &MsgLens[StrMBackbn],    NULL, 0     },
    { &MsgStrs[StrMSticks] /* "Sticks"       */,     0x11,  &MsgAuxl[StrMSticks],
        &MsgLens[StrMSticks],    NULL, 0     },
    { &MsgStrs[StrMSpacefl]/* "Spacefill"    */,     0x11,  &MsgAuxl[StrMSpacefl],
        &MsgLens[StrMSpacefl],   NULL, 0     },
    { &MsgStrs[StrMBallStk]/* "Ball & Stick" */,     0x11,  &MsgAuxl[StrMBallStk],
        &MsgLens[StrMBallStk],   NULL, 0     },
    { &MsgStrs[StrMRibbons]/* "Ribbons"      */,     0x11,  &MsgAuxl[StrMRibbons],
        &MsgLens[StrMRibbons],   NULL, 0     },
    { &MsgStrs[StrMStrands]/* "Strands"      */,     0x11,  &MsgAuxl[StrMStrands],
        &MsgLens[StrMStrands],   NULL, 0     },
    { &MsgStrs[StrMCartoon]/* "Cartoons"     */,     0x11,  &MsgAuxl[StrMCartoon],
        &MsgLens[StrMCartoon],   NULL, 0     },
    { &MsgStrs[StrMMolSurf]/* "Molecular Surface"    */,     0x11,  &MsgAuxl[StrMMolSurf],
        &MsgLens[StrMMolSurf],   NULL, 0     }};
 


static MenuItem ColMenu[10] = {
    { &MsgStrs[StrMMonochr]/* "Monochrome"   */,     0x11,  &MsgAuxl[StrMMonochr],
        &MsgLens[StrMMonochr],   NULL, 0 },
    { &MsgStrs[StrMCPK]    /* "CPK"          */,     0x11,  &MsgAuxl[StrMCPK],
        &MsgLens[StrMCPK],       NULL, 0 },
    { &MsgStrs[StrMShapely]/*" Shapely"      */,     0x11,  &MsgAuxl[StrMShapely],
        &MsgLens[StrMShapely],   NULL, 0 },
    { &MsgStrs[StrMGroup]  /* "Group"        */,     0x11,  &MsgAuxl[StrMGroup],
        &MsgLens[StrMGroup],     NULL, 0 },
    { &MsgStrs[StrMChain]  /* "Chain"        */,     0x11,  &MsgAuxl[StrMChain],
        &MsgLens[StrMChain],     NULL, 0 },
    { &MsgStrs[StrMTemp]   /* "Temperature"  */,     0x11,  &MsgAuxl[StrMTemp],
        &MsgLens[StrMTemp],      NULL, 0 },
    { &MsgStrs[StrMStruct] /* "Structure"    */,     0x11,  &MsgAuxl[StrMStruct],
        &MsgLens[StrMStruct],    NULL, 0 },
    { &MsgStrs[StrMUser]   /* "User"         */,     0x11,  &MsgAuxl[StrMUser],
        &MsgLens[StrMUser],      NULL, 0 }, 
    { &MsgStrs[StrMModel]  /* "Model"        */,     0x11,  &MsgAuxl[StrMModel],
        &MsgLens[StrMModel],     NULL, 0 },
    { &MsgStrs[StrMAlt]    /* "Alt"          */,     0x11,  &MsgAuxl[StrMAlt],
        &MsgLens[StrMAlt],       NULL, 0 }};

static MenuItem OptMenu[7] = {
    { &MsgStrs[StrMSlab]   /* "Slab Mode"    */,     0x13,  &MsgAuxl[StrMSlab],
        &MsgLens[StrMSlab],   &UseSlabPlane, True },
    { &MsgStrs[StrMHydr]   /* "Hydrogens"    */,     0x13,  &MsgAuxl[StrMHydr],
        &MsgLens[StrMHydr],   &Hydrogens,    True },
    { &MsgStrs[StrMHet]    /* "Hetero Atoms" */,     0x13,  &MsgAuxl[StrMHet],
        &MsgLens[StrMHet],    &HetaGroups,   True },
    { &MsgStrs[StrMSpec]   /* "Specular"     */,     0x13,  &MsgAuxl[StrMSpec],
        &MsgLens[StrMSpec],   &FakeSpecular, True },
    { &MsgStrs[StrMShad]   /* "Shadows"      */,     0x13,  &MsgAuxl[StrMShad],
        &MsgLens[StrMShad],   &UseShadow,    True },
    { &MsgStrs[StrMStereo] /* "Stereo"       */,     0x13,  &MsgAuxl[StrMStereo],
        &MsgLens[StrMStereo], &UseStereo,    True },
    { &MsgStrs[StrMLabel]  /* "Labels"       */,     0x13,  &MsgAuxl[StrMLabel],
        &MsgLens[StrMLabel],  &LabelOptFlag, True } };

static MenuItem SetMenu[13] = {
    { &MsgStrs[StrMPOff]   /* "Pick Off"     */,     0x13,  &MsgAuxl[StrMPOff],
        &MsgLens[StrMPOff],   &PickMode,     PickNone   },
    { &MsgStrs[StrMPIdent] /* "Pick Ident"   */,     0x13,  &MsgAuxl[StrMPIdent],
        &MsgLens[StrMPIdent], &PickMode,     PickIdent  },
    { &MsgStrs[StrMPDist]  /* "Pick Distance"*/,     0x13,  &MsgAuxl[StrMPDist],
        &MsgLens[StrMPDist],  &PickMode,     PickDist   },
    { &MsgStrs[StrMPMon]   /* "Pick Monitor" */,     0x13,  &MsgAuxl[StrMPMon],
        &MsgLens[StrMPMon],   &PickMode,     PickMonit  },
    { &MsgStrs[StrMPAng]   /* "Pick Angle"   */,     0x13,  &MsgAuxl[StrMPAng],
        &MsgLens[StrMPAng],   &PickMode,     PickAngle  },
    { &MsgStrs[StrMPTrsn]  /* "Pick Torsion" */,     0x13,  &MsgAuxl[StrMPTrsn],
        &MsgLens[StrMPTrsn],  &PickMode,     PickTorsn  },
    { &MsgStrs[StrMPLabl]  /* "Pick Label"   */,     0x13,  &MsgAuxl[StrMPLabl],
        &MsgLens[StrMPLabl],  &PickMode,     PickLabel  },
    { &MsgStrs[StrMPCent]  /* "Pick Centre"  */,     0x13,  &MsgAuxl[StrMPCent],
        &MsgLens[StrMPCent],  &PickMode,     PickOrign  },
    { &MsgStrs[StrMPCoord] /* "Pick Coord"   */,     0x13,  &MsgAuxl[StrMPCoord],
        &MsgLens[StrMPCoord], &PickMode,     PickCoord  },
    { &MsgStrs[StrMPBond]  /* "Pick Bond"    */,     0x13,  &MsgAuxl[StrMPBond],
        &MsgLens[StrMPBond],  &PickMode,     PickBond   },
    { &MsgStrs[StrMRBond]  /* "Rotate Bond"  */,     0x13,  &MsgAuxl[StrMRBond],
        &MsgLens[StrMRBond],  &RotMode,      RotBond    },
    { &MsgStrs[StrMRMol]   /* "Rotate Mol"   */,     0x13,  &MsgAuxl[StrMRMol],
        &MsgLens[StrMRMol],   &RotMode,      RotMol     },
    { &MsgStrs[StrMRAll]   /* "Rotate All"   */,     0x13,  &MsgAuxl[StrMRAll],
        &MsgLens[StrMRAll],   &RotMode,      RotAll     } };

static MenuItem ExpMenu[15] = {
    { &MsgStrs[StrMBMP]     /* "BMP..."           */,    0x11,  &MsgAuxl[StrMBMP],
        &MsgLens[StrMBMP],     NULL, 0 },
    { &MsgStrs[StrMGIF]     /* "GIF..."           */,    0x11,  &MsgAuxl[StrMGIF],
        &MsgLens[StrMGIF],     NULL, 0 },
    { &MsgStrs[StrMIRGB]    /* "IRIS RGB..."      */,    0x11,  &MsgAuxl[StrMIRGB],
        &MsgLens[StrMIRGB],    NULL, 0 },
    { &MsgStrs[StrMPPM]     /* "PPM..."           */,    0x11,  &MsgAuxl[StrMPPM],
        &MsgLens[StrMPPM],     NULL, 0 },
    { &MsgStrs[StrMSRast]   /* "Sun Raster..."    */,    0x11,  &MsgAuxl[StrMSRast],
        &MsgLens[StrMSRast],   NULL, 0 },
    { &MsgStrs[StrMPostscr] /* "PostScript..."    */,    0x11,  &MsgAuxl[StrMPostscr],
        &MsgLens[StrMPostscr], NULL, 0 },
    { &MsgStrs[StrMPICT]    /* "PICT..."          */,    0x11,  &MsgAuxl[StrMPICT],
        &MsgLens[StrMPICT], NULL, 0 },
    { &MsgStrs[StrMVECPS]    /* "Vector PS ..."   */,    0x11,  &MsgAuxl[StrMVECPS],
        &MsgLens[StrMVECPS],   NULL, 0 },
    { &MsgStrs[StrMMSCR]    /* "Molscript ..."    */,    0x11,  &MsgAuxl[StrMMSCR],
        &MsgLens[StrMMSCR],    NULL, 0 },
    { &MsgStrs[StrMKine]    /* "Kinemage ..."     */,    0x11,  &MsgAuxl[StrMKine],
        &MsgLens[StrMKine],    NULL, 0 },
    { &MsgStrs[StrMPOVRAY]  /*"POVRay 3 ..."      */,    0x11,  &MsgAuxl[StrMPOVRAY],
        &MsgLens[StrMPOVRAY],  NULL, 0 },
    { &MsgStrs[StrMVRML]    /* "VRML ..."         */,    0x11,  &MsgAuxl[StrMVRML],
        &MsgLens[StrMVRML],    NULL, 0 },
    { &MsgStrs[StrMRPP]     /* "Ramachandran ..." */,    0x11,  &MsgAuxl[StrMRPP],
        &MsgLens[StrMRPP],     NULL, 0 },
    { &MsgStrs[StrMR3D]     /* "Raster3D ..."     */,    0x11,  &MsgAuxl[StrMR3D],
        &MsgLens[StrMR3D],     NULL, 0 },
    { &MsgStrs[StrMSCR]     /* "RasMol Script ..."*/,    0x11,  &MsgAuxl[StrMSCR],
        &MsgLens[StrMSCR],     NULL, 0 } };

static MenuItem HelMenu[4] = {
    { &MsgStrs[StrMAbout]   /* "About RasMol..."*/,  0x11,  &MsgAuxl[StrMAbout],
        &MsgLens[StrMAbout], NULL, 0 },
    { &MsgStrs[StrMUserM]   /* "User Manual..." */,  0x11,  &MsgAuxl[StrMUserM],
        &MsgLens[StrMUserM], NULL, 0 },
    { &MsgStrs[StrRegister] /* "Register ..."*/,     0x11,  &MsgAuxl[StrRegister],
        &MsgLens[StrRegister], NULL, 0 },
    { &MsgStrs[StrDonate]   /* "Donate..."*/,        0x11,  &MsgAuxl[StrDonate],
        &MsgLens[StrDonate], NULL, 0 }
};


typedef struct _BarItem {
            MenuItem *menu;
            char **text;
            int count;
            int flags;
            int *pos;
            int *len;
            int *increment; 
        } BarItem;

#define MenuBarMax 7
static BarItem MenuBar[MenuBarMax] = { 
    { FilMenu,  &MsgStrs[StrMFile]    /* "File"     */,  5, 0x01,&MsgAuxl[StrMFile],
        &MsgLens[StrMFile], &NumMolecules},
    { DisMenu,  &MsgStrs[StrMDisplay] /* "Display"  */,  9, 0x01,&MsgAuxl[StrMDisplay],
        &MsgLens[StrMDisplay], NULL },
    { ColMenu,  &MsgStrs[StrMColour]  /* "Colours"  */, 10, 0x01,&MsgAuxl[StrMColour],
        &MsgLens[StrMColour], NULL },
    { OptMenu,  &MsgStrs[StrMOpt]     /* "Options"  */,  7, 0x01,&MsgAuxl[StrMOpt],
        &MsgLens[StrMOpt], NULL },
    { SetMenu, &MsgStrs[StrMSettings] /* "Settings" */, 13, 0x01,&MsgAuxl[StrMSettings],
        &MsgLens[StrMSettings], NULL },
    { ExpMenu,  &MsgStrs[StrMExport]  /* "Export"   */, 15, 0x01,&MsgAuxl[StrMExport],
        &MsgLens[StrMExport], NULL },
    { HelMenu,  &MsgStrs[StrMHelp]    /* "Help"     */,  4, 0x01,&MsgAuxl[StrMHelp],
        &MsgLens[StrMHelp], NULL } 
};




static int MenuFocus;
static int ItemFocus;
static int MenuItemSelect;
static int MenuBarSelect;
static int MenuBarCount;
static int PopUpWide;
static int PopUpHigh;
static int PopUpFlag;
static int ItemFlag;


#ifdef DIALBOX
#include <X11/extensions/XInput.h>

static char *DialLabel[] = { "ROTATE X", "ROTATE Y", "ROTATE Z", "  ZOOM  ",
                             "TRANS X ", "TRANS Y ", "TRANS Z ", "  SLAB  " };
static int *DialMap;
static int ESVDialMap[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
static int SGIDialMap[8] = { 3, 7, 2, 6, 1, 5, 0, 4 };

static Real DialRes[8];
static int DialPrev[8];
static int DialMode;

static int UseDialLEDs;
static XDevice *Dials;
static int DialEvent;
static int UseDials;
#endif


#ifdef MITSHM
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <X11/extensions/XShm.h>

XShmSegmentInfo xshminfo;
int SharedMemOption;
int SharedMemFlag;
#else
#define SharedMemOption False
#endif

#define XScrlSkip  8
#define YScrlSkip  8

typedef union {
    Long longword;
    Byte bytes[4];
    } ByteTest;


static int MenuHigh;
static int FontHigh;
static char* lastlocale;
static Cursor cross;
static Cursor arrow;
static Cursor hglass;
static Pixmap Scrl;
static Pixmap tilepix;
static Pixmap uppix, dnpix;
static Pixmap lfpix, rgpix;
static XFontStruct *MenuFont=NULL;
static XFontSet MenuFontSet=NULL;
static short XFascent;
static short XFdescent;
static XSetWindowAttributes attr;
static Window XScrlWin, YScrlWin;
static XWMHints hints;
static Colormap lmap;
static XImage *image;
static GC gcon;

#ifdef EIGHTBIT
static unsigned long Ident[256];
static int IdentCount;
#endif

static int XHeldButton;
static int XHeldStep;

static Byte Intensity[LutSize];
static Pixel WhiteCol;
static Pixel BlackCol;

#ifdef THIRTYTWOBIT
static int SwapBytes;
#endif

static int MaxWidth, MaxHeight;
static int MinWidth, MinHeight;
static int MainWide, MainHigh;
static int ScrlX,NewScrlX;
static int ScrlY,NewScrlY;


/* WM_PROTOCOLS */
static Atom AppNameAtom;
static Atom DelWinXAtom;
static Atom ProtoXAtom;
static Atom InterpAtom;
static Atom CommAtom;


/*=======================*/
/*  Function Prototypes  */
/*=======================*/
  
extern int ProcessCommand( void );
static int HandleMenuLoop( void );
static int HandleIPCError( Display *dpy, XErrorEvent *ptr );
#ifdef MITSHM
static int HandleShmError( Display *dpy, XErrorEvent *ptr );
#endif



void FatalGraphicsError( char *ptr )
{
    char buffer[80];

    sprintf(buffer,"Graphics Error: %s!",ptr);
    RasMolFatalExit(buffer);
}


void AllocateColourMap( void )
{
#ifdef EIGHTBIT
    static XColor Col;
    register int i,j;

    if( Monochrome )
    {   for( i=0; i<LutSize; i++ )
            Intensity[i] = (Byte)((int)(20*RLut[i]+32*GLut[i]+12*BLut[i])>>6);
        return;
    }

    if( LocalMap )
    {   XSetWindowColormap(dpy,MainWin,cmap);
        XSetWindowColormap(dpy,CanvWin,cmap);
        XUninstallColormap(dpy,lmap);
        XFreeColormap(dpy,lmap);
        LocalMap = False;
    } else if( IdentCount )
        XFreeColors(dpy,cmap,Ident,IdentCount,(long)0);
    IdentCount = 0;


    for( i=0; i<LutSize; i++ )
        if( ULut[i] )
        {   Col.red   = RLut[i]<<8 | RLut[i];
            Col.green = GLut[i]<<8 | GLut[i];
            Col.blue  = BLut[i]<<8 | BLut[i];
            Col.flags = DoRed | DoGreen | DoBlue;
            if( !XAllocColor(dpy,cmap,&Col) )
                break;
            Ident[IdentCount++] = Col.pixel;
            Lut[i] = (Pixel)Col.pixel;
        }

    if( i<LutSize )
    {   lmap = XCopyColormapAndFree(dpy,cmap);
        LocalMap = True;

        for( j=0; j<5; j++ )
        {   Col.red   = RLut[j]<<8 | RLut[j];
            Col.green = GLut[j]<<8 | GLut[j];
            Col.blue  = BLut[j]<<8 | BLut[j];
            XAllocColor(dpy,cmap,&Col);
            Lut[i] = (Pixel)Col.pixel;
        }

        for( j=i; j<LutSize; j++ )
            if( ULut[j] )
            {   Col.red   = RLut[j]<<8 | RLut[j];
                Col.green = GLut[j]<<8 | GLut[j];
                Col.blue  = BLut[j]<<8 | BLut[j];
                XAllocColor(dpy,lmap,&Col);
                Lut[j] = (Pixel)Col.pixel;
            }
        XSetWindowColormap(dpy,MainWin,lmap);
        XSetWindowColormap(dpy,CanvWin,lmap);
        XInstallColormap(dpy,lmap);
    }
#else /* EIGHTBIT */
#ifdef THIRTYTWOBIT
    static XColor Col;
    static ByteTest buf;
    register Byte temp;
    register int i;

    for( i=0; i<LutSize; i++ )
        if( ULut[i] )
        {   Col.red   = RLut[i]<<8 | RLut[i];
            Col.green = GLut[i]<<8 | GLut[i];
            Col.blue  = BLut[i]<<8 | BLut[i];
            XAllocColor(dpy,cmap,&Col);
            if( SwapBytes )
            {   buf.longword = (Long)Col.pixel;
                temp = buf.bytes[0];
                buf.bytes[0] = buf.bytes[3];
                buf.bytes[3] = temp;

                temp = buf.bytes[1];
                buf.bytes[1] = buf.bytes[2];
                buf.bytes[2] = temp;
                Lut[i] = buf.longword;
            } else Lut[i] = (Long)Col.pixel;
       }
#else /* THIRTYTWOBIT */
    static XColor Col;
    register int i;

    for( i=0; i<LutSize; i++ )
        if( ULut[i] )
        {   Col.red   = RLut[i]<<8 | RLut[i];
            Col.green = GLut[i]<<8 | GLut[i];
            Col.blue  = BLut[i]<<8 | BLut[i];
            XAllocColor(dpy,cmap,&Col);
            Lut[i] = (Pixel)Col.pixel;
       }
#endif /* THIRTYTWOBIT */
#endif /* EIGHTBIT */
    XSetWindowBackground(dpy,CanvWin,(unsigned long)Lut[5]);
}


static void OpenCanvas( int x, int y )
{
    register unsigned long mask;

    mask = CWEventMask;
    attr.event_mask = ExposureMask | ButtonPressMask | ButtonMotionMask 
                    | ButtonReleaseMask;
    attr.cursor = cross;                           mask |= CWCursor;
    attr.background_pixel = Lut[0];                mask |= CWBackPixel;

    CanvWin = XCreateWindow(dpy, MainWin, 14, MenuHigh+14, x, y, 0, 
                            CopyFromParent, InputOutput, vis, mask, &attr );
}


static XFontSet RasLoadQueryFontSet(Display *disp, const char *fontset_name)
{
    XFontSet MenuFontSet;
    int      missing_charset_count;
    char     **missing_charset_list;
    char     *def_string;
    char     buffer[255];

    MenuFontSet = XCreateFontSet(disp, fontset_name,
                             &missing_charset_list, &missing_charset_count,
                             &def_string);

    if (missing_charset_count) {
        if (strlen(fontset_name) < 200)
        sprintf(buffer, "Missing charsets in MenuFontSet (%s) creation.\n", fontset_name);
        else strcpy(buffer,"Missing charsets in MenuFontSet creation.\n");
        WriteString(buffer);
        for( ; missing_charset_count-- ; ){
          sprintf(buffer, "  missing %d: %s\n",
             missing_charset_count, missing_charset_list[missing_charset_count]);
        WriteString(buffer);
        }
        XFreeStringList(missing_charset_list);
    }
    return MenuFontSet;
}




static int RasOpenFonts( void )
{
    static char fontname [255];
    register int i;
    XFontSetExtents *extent;
    char *menufonts;
    XRectangle dummy;
    XRectangle bound;



	if ( Language != TermLanguage ) 
	{
	  if ( MenuFont && MenuFont->fid )  XUnloadFont(dpy,MenuFont->fid); 
	  MenuFont = 0;
	  if (MenuFontSet)  XFreeFontSet( dpy,MenuFontSet);
	  MenuFontSet=NULL;
	} 
	
	if (!MenuFont || !(MenuFont->fid ) ) {
	
	
	for (i=0; i < NUMLANGS; i++) {
	
	  if (langfonts[i].lang == Language) {
	    int kl;
	    if((menufonts = getenv(langfonts[i].menufontvar)) ) {
	      char * strend;
	      while ((strend = strchr(menufonts,':'))) {
	        /* fprintf(stderr,"menufonts: %s\n",menufonts); */
	        strncpy(fontname,menufonts,strend-menufonts<255?strend-menufonts:254);
	        fontname[strend-menufonts<255?strend-menufonts:254]='\0';
	        menufonts=strend+1;
	        if( (MenuFont=XLoadQueryFont(dpy,fontname)) ) break;
	      }
	      if (!MenuFont && (kl=strlen(menufonts))> 0  ) {
	        /* fprintf(stderr,"menufonts: %s\n",menufonts); */
	      	strncpy(fontname,menufonts,kl<255?kl:254);
	        fontname[kl<255?kl:254] = '\0';
	        if( (MenuFont=XLoadQueryFont(dpy,fontname)) ) break;
	      }
	      if (MenuFont) break;
	    	
	    }
	    if ((menufonts = langfonts[i].menufontlist) ) {
	      char * strend;
	      while ((strend = strchr(menufonts,':')) ) {
	        /* fprintf(stderr,"menufonts: %s\n",menufonts);*/
	        strncpy(fontname,menufonts,strend-menufonts<255?strend-menufonts:254);
	        fontname[strend-menufonts<255?strend-menufonts:254]='\0';
	        menufonts=strend+1;
	        if( (MenuFont=XLoadQueryFont(dpy,fontname)) ) break;
	      }
	      if (!MenuFont && (kl=strlen(menufonts))> 0) {
	        /* fprintf(stderr,"menufonts: %s\n",menufonts); */
	      	strncpy(fontname,menufonts,kl<255?kl:254);
	        fontname[kl<255?kl:254] = '\0';
	        if( (MenuFont=XLoadQueryFont(dpy,fontname)) ) break;
	      }
	      if (MenuFont) break;
	    }	  	
	  }
		
	}
	}
	
	/* if (MenuFont) fprintf(stderr,"Selected menufont %s\n",fontname); */
	
    if (!cross) cross = XCreateFontCursor(dpy,XC_tcross);
    if (!arrow) arrow = XCreateFontCursor(dpy,XC_top_left_arrow);

    if (Language == Chinese){
      
        strncat(fontname,",-*-helvetica-bold-o-normal-*-14-*-iso8859-1",
          254-strlen(fontname));

        SetLocale(LC_ALL, "zh_CN.GB2312");
        lastlocale = "chinese";
        MenuFontSet = RasLoadQueryFontSet(dpy,
        fontname);
	    if ( !MenuFontSet ) return 1;
	    extent = XExtentsOfFontSet(MenuFontSet);
        XFascent  = extent->max_logical_extent.height;
        XFdescent = extent->max_logical_extent.height *  1.0 / 10.0;
        FontHigh = extent->max_logical_extent.height + 6;
        XmbTextExtents( MenuFontSet, MsgStrs[StrWarranty], strlen(MsgStrs[StrWarranty]), &dummy, &bound );
        if (bound.height > FontHigh) FontHigh = bound.height;
        if (-dummy.y > XFascent ) XFascent = dummy.y;
        if (-dummy.y+dummy.height > XFdescent ) XFdescent = -dummy.y+dummy.height;
        if (XFdescent > 4) XFdescent = 4;
        MenuHigh = FontHigh + 6;
        if( !MenuFont ) return 1;
        return 0;

      } else if (Language == Japanese) {
      
        strncat(fontname,",-*-helvetica-bold-o-normal-*-14-*-iso8859-1",
          254-strlen(fontname));


        SetLocale(LC_ALL, "ja_JP.eucjp");
	    lastlocale = "japanese";
        MenuFontSet = RasLoadQueryFontSet(dpy,
        fontname);
        if ( !MenuFontSet ) return 1;
	    extent = XExtentsOfFontSet(MenuFontSet);
        XFascent  = extent->max_logical_extent.height;
        XFdescent = extent->max_logical_extent.height *  2.0 / 10.0;
        FontHigh = extent->max_logical_extent.height + 6;
        XmbTextExtents( MenuFontSet, MsgStrs[StrWarranty], strlen(MsgStrs[StrWarranty]), &dummy, &bound );
        if (bound.height > FontHigh) FontHigh = bound.height;
        if (-dummy.y > XFascent ) XFascent = dummy.y;
        if (-dummy.y+dummy.height > XFdescent ) XFdescent = -dummy.y+dummy.height;
        if (XFdescent > 4) XFdescent = 4;
        MenuHigh = FontHigh + 6;
        if( !MenuFont ) return 1;
        return 0;
        
      }else{
	if (Language == English ){
           SetLocale(LC_ALL, "en_US");
	   lastlocale = "english";
    }else if ( Language == Spanish ){
           SetLocale(LC_ALL, "es_ES");
	   lastlocale = "spanish";
	}else if ( Language == Italian ){
           SetLocale(LC_ALL, "it_IT");
	   lastlocale = "italian";
	}else if ( Language == French ){
           SetLocale(LC_ALL, "fr_FR");
	   lastlocale = "french";
	}else if ( Language == Russian ){
           SetLocale(LC_ALL, "ru_RU");
	   lastlocale = "russian";
	}else if ( Language == Bulgarian ){
           SetLocale(LC_ALL, "bg_BG");
	   lastlocale = "bulgarian";
	}

        if( !MenuFont ) return 1;

        FontHigh = MenuFont->max_bounds.descent +
               MenuFont->max_bounds.ascent + 1;
      }
    MenuHigh = FontHigh+6;
    XFascent = MenuFont->ascent;
    XFdescent = MenuFont->descent;
	return 0;
}


static void OpenCursors( void )
{
    Pixmap source,mask;
    XColor black,white;

    white.red = 65535;     black.red = 0;      
    white.green = 65535;   black.green = 0;
    white.blue = 65535;    black.blue = 0;
     
    white.flags = DoRed | DoGreen | DoBlue;
    black.flags = DoRed | DoGreen | DoBlue;

    source = XCreateBitmapFromData(dpy,MainWin,(char*)HGlassData,16,16);
    mask   = XCreateBitmapFromData(dpy,MainWin,(char*)HGlassMask,16,16);
    hglass = XCreatePixmapCursor(dpy,source,mask,&black,&white,7,7);
}


static void OpenColourMap( void )
{
    static XColor Col;
    register int i;

#ifdef EIGHTBIT
    if( !Monochrome )
    {   Col.flags = DoRed | DoGreen | DoBlue;

        for( i=0; i<5; i++ )
        {   Col.red   = RLut[i]<<8 | RLut[i];
            Col.green = GLut[i]<<8 | GLut[i];
            Col.blue  = BLut[i]<<8 | BLut[i];
            if( !XAllocColor(dpy,cmap,&Col) )
            {   cmap = XCopyColormapAndFree(dpy,cmap);
                XAllocColor(dpy,cmap,&Col);
            } 
            Lut[i] = (Pixel)Col.pixel;
        }
        Lut[5] = Lut[0];
    } else /* Black & White */
    {   Lut[0] = BlackCol;
        Lut[1] = BlackCol;
        Lut[2] = WhiteCol;
        Lut[3] = BlackCol;
        Lut[4] = WhiteCol;

        Intensity[5] = 0;
        Lut[5] = 5;         
    }

    LocalMap = False;
    IdentCount = 0;
#else
    Col.flags = DoRed | DoGreen | DoBlue;

    for( i=0; i<5; i++ )
    {   Col.red   = RLut[i]<<8 | RLut[i];
        Col.green = GLut[i]<<8 | GLut[i];
        Col.blue  = BLut[i]<<8 | BLut[i];
        XAllocColor(dpy,cmap,&Col);
        Lut[i] = (Pixel)Col.pixel;
    }
    Lut[5] = Lut[0];
#endif
}


int ShowInterpNames ( void )
{   static unsigned char *registry;
    static unsigned long len,left;
    static int format;
    static Atom type;
    register int (*handler)();
    register char *ptr;
    register int result;

    if (!dpy) return False;

    handler = XSetErrorHandler( HandleIPCError );
    result = XGetWindowProperty(dpy, RootWindow(dpy,0), InterpAtom,
                                0, 100000, False, XA_STRING, &type,
                                &format, &len, &left, &registry );
    XSync(dpy,False);
    XSetErrorHandler(handler);
    
    if ((result!=Success) || (format!=8) || (type!=XA_STRING) ) {
        WriteString(" No interpreters ");
        return True;
    }
    
    ptr = (char*)registry;
    while( *ptr )
    {   /* Skip Window ID */
        while( *ptr++ != ' ' )
            if( !*ptr ) break;
        
        WriteChar('{');
        WriteString(ptr);
        WriteString("}\n");
        while( *ptr++ );
    }
    return True;
}


int SendInterpCommand( char __huge *name, unsigned long interpid,
                      char __huge *command){
    char buffer[32];
    Window commWindow;
    register int (*handler)();
    
    commWindow = (Window)interpid;
    if (!TkSendPtr) {
        if (vector_create((GenericVec __far * __far *)&TkSendPtr,
                          sizeof(char),32) ){
            InvalidateCmndLine();
            RasMolFatalExit(MsgStrs[StrMalloc]);
        }
    }
    buffer[0] = '\0';
    buffer[1] = 'c';
    buffer[2] = '\0';
    sprintf(buffer+3,"-r %x %d",(int)MainWin,++TkSendSerial);
    /* copy the buffer with the c string and the
       -r mycommWindow serial string */
    vector_set_elements((GenericVec __far * )TkSendPtr,
                        (void __far *) buffer, 4+strlen(buffer+3),0);
    TkSendPtr->size=4+strlen(buffer+3);
    vector_add_elements((GenericVec __far * )TkSendPtr,
                        (void __far *) "-n ", 3);
    vector_add_elements((GenericVec __far * )TkSendPtr,
                        (void __far *) name, strlen(name)+1);
    vector_add_elements((GenericVec __far * )TkSendPtr,
                        (void __far *) "-s ", 3);
    vector_add_elements((GenericVec __far * )TkSendPtr,
                        (void __far *) command, strlen(command)+1);
    handler = XSetErrorHandler( HandleIPCError );
    XChangeProperty(dpy, commWindow ,CommAtom, XA_STRING, 8,
                    PropModeAppend,
                    (unsigned char*)(TkSendPtr->array),TkSendPtr->size);
    XSync(dpy,False);
    XSetErrorHandler(handler);
    sprintf(buffer,"Command %d sent to %s\n",TkSendSerial,name);
    WriteString(buffer);
    return True;
}


int CheckInterpName( char __huge *name, unsigned long __huge *interpid) {
    unsigned char *registry;
    unsigned long len,left;
    char buffer[32];
    int format;
    Atom type;
    
    register int result;
    register char *ptr;
    register int (*handler)();
    
    registry = NULL;
    *interpid = 0;
    handler = XSetErrorHandler( HandleIPCError );
    result = XGetWindowProperty(dpy, RootWindow(dpy,0), InterpAtom,
                                0, 100000, False, XA_STRING, &type,
                                &format, &len, &left, &registry );
    XSync(dpy,False);
    XSetErrorHandler(handler);
    
    if( (result!=Success) || (format!=8) || (type!=XA_STRING) )
    {   if( (type!=None) && registry ) XFree( (char*)registry );
        return( False );
    }
    
    ptr = (char*)registry;
    while( *ptr )
    {
        *interpid = 0;
        while( *ptr != ' ' ) {
            if (!*ptr ) break;
            if (isxdigit(*ptr)) {
                *interpid = ((*interpid)<<4)|(unsigned long)digittoint(*ptr);
            } else {
                break;
            }
            ptr++;
        }
        
        /* Strip leading blanks */
        
        while (*ptr == ' ') ptr++;
        
        /* Compare Interp Name */
        if( !strcmp(ptr,name) )
        {   XFree( (char*)registry );
            return True;
        }
        
        while( *ptr++ );
    }
    
    XFree( (char*)registry );
    return( False );
}

static int RegisterInterpName( char *name )
{
    static unsigned char *registry;
    static unsigned long len,left;
    static char buffer[32];
    static int format;
    static Atom type;

    register int result;
    register char *ptr;
    register int (*handler)();

    registry = NULL;
    handler = XSetErrorHandler( HandleIPCError );
    result = XGetWindowProperty(dpy, RootWindow(dpy,0), InterpAtom,
                                0, 100000, False, XA_STRING, &type,
                                &format, &len, &left, &registry );
    XSync(dpy,False);
    XSetErrorHandler(handler);

    if( (result!=Success) || (format!=8) || (type!=XA_STRING) )
    {   if( (type!=None) && registry ) XFree( (char*)registry );

        sprintf(buffer,"%x %s",(int)MainWin,name);
        handler = XSetErrorHandler( HandleIPCError );
        XChangeProperty( dpy, RootWindow(dpy,0), InterpAtom, XA_STRING, 
                         8, PropModeReplace, (unsigned char*)buffer, 
                         (int)strlen(buffer)+1 );
        XSync(dpy,False);
        XSetErrorHandler(handler);

        return( True );
    }

    ptr = (char*)registry;
    while( *ptr )
    {   /* Skip Window ID */
        while( *ptr++ != ' ' )
            if( !*ptr ) break;

        /* Compare Interp Name */
        if( !strcmp(ptr,name) )
        {   XFree( (char*)registry );
            return False;
        }

        while( *ptr++ );
    }

    XFree( (char*)registry );
    sprintf(buffer,"%x %s",(int)MainWin,name);
    handler = XSetErrorHandler( HandleIPCError );
    XChangeProperty( dpy, RootWindow(dpy,0), InterpAtom, XA_STRING, 
                     8, PropModeAppend, (unsigned char*)buffer, 
                     (int)strlen(buffer)+1 );
    XSync(dpy,False);
    XSetErrorHandler(handler);
    return( True );
}


static void DeRegisterInterpName( char *name )
{
    static unsigned char *registry;
    static unsigned long len,left;
    static int format;
    static Atom type;

    register char *src, *dst;
    register int result;
    register int (*handler)();

    /* Avoid compiler warnings */
    src = (char *)0;
 
    registry = NULL;
    handler = XSetErrorHandler( HandleIPCError );    
    result = XGetWindowProperty(dpy, RootWindow(dpy,0), InterpAtom,
                                0, 100000, False, XA_STRING, &type,
                                &format, &len, &left, &registry );
    XSync(dpy,False);
    XSetErrorHandler(handler);
    if( type==None )
        return;

    if( (result!=Success) || (format!=8) || (type!=XA_STRING) )
    {   handler = XSetErrorHandler( HandleIPCError );
        XDeleteProperty( dpy, RootWindow(dpy,0), InterpAtom );
        XSync(dpy,False);
        XSetErrorHandler(handler);
        if( registry ) XFree( (char*)registry );
        return;
    }

    dst = (char*)registry;
    while( *dst )
    {   /* Skip Window ID */
        src = dst;
        while( *src++ != ' ' )
            if( !*src ) break;

        /* Compare Interp Name */
        if( strcmp(src,name) )
        {   while( *dst++ );
        } else break;
    }

    if( *dst )
    {   /* Skip Interp Name */
        while( *src++ );
        
        /* Shuffle Registry */
        while( *src )
            while( (*dst++ = *src++) );
        *dst = 0;
        handler = XSetErrorHandler( HandleIPCError );
        XChangeProperty( dpy, RootWindow(dpy,0), InterpAtom, XA_STRING,
                         8, PropModeReplace, registry, (int)(dst-(char*)registry) );
        XSync(dpy,False);
        XSetErrorHandler(handler);
    }
    XFree( (char*)registry );
}


static void OpenIPCComms( void )
{
    auto char buffer[128];
    register int i;
    register int (*handler)();
    register size_t lentkname;
    FILE * TkNameFile;

    /* fprintf(stderr,"TkName %s, TkNameTo %s\n",TkName, TkNameTo); */
    CommAtom = XInternAtom( dpy, "Comm", False );
    InterpAtom = XInternAtom( dpy, "InterpRegistry", False );
    AppNameAtom = XInternAtom(dpy, "TK_APPLICATION", False );
    DelWinXAtom = XInternAtom(dpy, "WM_DELETE_WINDOW", False);
    XSync(dpy, False);
    /* XSetWMProtocols(dpy,MainWin,&DelWinXAtom,True); */
    if( (ProtoXAtom = XInternAtom(dpy,"WM_PROTOCOLS",False)) ) {
    	handler = XSetErrorHandler( HandleIPCError );
        XChangeProperty( dpy, MainWin, ProtoXAtom, XA_ATOM, 32, 
                        PropModeReplace, (Byte*)&DelWinXAtom, True );
        XSync(dpy,False);
        XSetErrorHandler(handler);
    }
    i = 0;
    XSync(dpy,False);
    if (!TkName) TkName = "rasmol";
    lentkname = strlen(TkName);
    if (lentkname > 120) {
        lentkname = 120;
    }
    strncpy(TkInterp,TkName,lentkname);
    TkInterp[lentkname] = '\0';
    if( !RegisterInterpName(TkInterp) )
    {   TkInterp[lentkname] = ' ';
        TkInterp[lentkname+1] = '#';
        TkInterp[lentkname+2] = '0';
        TkInterp[lentkname+3] = '\0';

        for( i=1; i<10; i++ )
        {    TkInterp[lentkname+2] = i+'0';
             if( RegisterInterpName(TkInterp) )
                 break;
        }

        if( i < 10 ) 
        {   /* Tk4.0 and later! */
            sprintf(buffer,"{%s}",TkInterp);
    	    handler = XSetErrorHandler( HandleIPCError );
            XChangeProperty( dpy, MainWin, AppNameAtom, XA_STRING, 
                             8, PropModeReplace, (Byte*)buffer, strlen(buffer) );
            XSync(dpy,False);
            XSetErrorHandler(handler);
        } else *TkInterp = 0;
    } else  {  
        handler = XSetErrorHandler( HandleIPCError );
        sprintf(buffer,"{%s}",TkInterp);
        XChangeProperty( dpy, MainWin, AppNameAtom, XA_STRING,
                         8, PropModeReplace, (Byte*)buffer, strlen(buffer) );
        XSync(dpy,False);
        XSetErrorHandler(handler);
    }
    XUngrabServer( dpy );
    if (TkNameTo) {
        ProcessFileName(TkNameTo);
        if (strcmp(DataFileName,"-")==0) {
            fprintf(stdout,"RasMol TkName: {");
            fprintf(stdout,TkInterp);
            fprintf(stdout,"}\n");
        } else {
            TkNameFile = fopen(DataFileName,"w");
            if (TkNameFile) {
                fprintf(TkNameFile,"RasMol TKName: {%s}\n",TkInterp);
                fclose(TkNameFile);
            } else {
                fprintf(stderr,"TkNameTo Error: Unable to create file `");
                fprintf(stderr, TkNameTo );  fprintf(stderr,"'!\n");
                fprintf(stderr,"RasMol TkName: {");
                fprintf(stderr,TkInterp);
                fprintf(stderr,"}\n");
}
        } 
    }
}


static void DrawUpCircle( Drawable wdw, int x1, int y1, int x2, int y2 )
{
    int width, height;
    
    width = x2-x1+1; height = y2-y1+1;

/*    XSetForeground(dpy,gcon,(unsigned long)Lut[2]);
    XFillArc(dpy,wdw,gcon,x1-1,y1-1,width+2,height+2,0,360*64);

    XSetForeground(dpy,gcon,(unsigned long)Lut[3]);
    XFillArc(dpy,wdw,gcon,x1,y1,width,height,-45*64,180*64);
    XFillArc(dpy,wdw,gcon,x1+1,y1+1,width-2,height-2,-45*64,180*64);

    XSetForeground(dpy,gcon,(unsigned long)Lut[1]);
    XFillArc(dpy,wdw,gcon,x1,y1,width,height,135*64,180*64);
    XFillArc(dpy,wdw,gcon,x1+1,y1+1,width-2,height-2,135*64,180*64);
    
    XSetForeground(dpy,gcon,(unsigned long)Lut[3]);
    XFillArc(dpy,wdw,gcon,x1+2,y1+2,width-4,height-4,0,360*64);
    */

    XSetForeground(dpy,gcon,(unsigned long)Lut[2]);
    XFillArc(dpy,wdw,gcon,x1-1,y1-1,width+2,height+2,0,360*64);

    XSetForeground(dpy,gcon,(unsigned long)Lut[1]);
    XFillArc(dpy,wdw,gcon,x1,y1,width,height,135*64,360*64);
    
    XSetForeground(dpy,gcon,(unsigned long)Lut[2]);
    XFillArc(dpy,wdw,gcon,x1+width/10,y1,width-width/10,height-height/10,135*64,360*64);
    
    XSetForeground(dpy,gcon,(unsigned long)Lut[3]);
    XFillArc(dpy,wdw,gcon,x1+width/9,y1,width-width/9,height-height/9,135*64,360*64);


}

static void DrawUpPieSlice( Drawable wdw, int x1, int y1, int x2, int y2 )
{
    int width, height;
    
    width = x2-x1+1; height = y2-y1+1;

/*    XSetForeground(dpy,gcon,(unsigned long)Lut[2]);
    XFillArc(dpy,wdw,gcon,x1-1,y1-1,width+2,height+2,135*64,90*64);

    XSetForeground(dpy,gcon,(unsigned long)Lut[1]);
    XFillArc(dpy,wdw,gcon,x1,y1,width,height,135*64,90*64);
    XFillArc(dpy,wdw,gcon,x1+1,y1+1,width-2,height-2,135*64,90*64);
    
    XSetForeground(dpy,gcon,(unsigned long)Lut[3]);
    XFillArc(dpy,wdw,gcon,x1+2,y1+2,width-4,height-4,135*64,90*64);
 */
    
    XSetForeground(dpy,gcon,(unsigned long)Lut[2]);
    XFillArc(dpy,wdw,gcon,x1-1,y1-1,width+2,height+2,155*64,50*64);

    XSetForeground(dpy,gcon,(unsigned long)Lut[1]);
    XFillArc(dpy,wdw,gcon,x1,y1,width,height,155*64,50*64);
    
    XSetForeground(dpy,gcon,(unsigned long)Lut[2]);
    XFillArc(dpy,wdw,gcon,x1+width/10,y1,width-width/10,height-height/10,150*64,60*64);
    
    XSetForeground(dpy,gcon,(unsigned long)Lut[3]);
    XFillArc(dpy,wdw,gcon,x1+width/9,y1,width-width/9,height-height/9,145*64,70*64);

}


static void DrawUpLine( Drawable wdw, int x1, int y1, int x2, int y2, int wid )
{
    XGCValues lineattr[4];
    
    XGetGCValues(dpy,gcon,GCLineWidth|GCLineStyle|GCCapStyle|GCJoinStyle,lineattr);
    XSetLineAttributes(dpy,gcon,wid,LineSolid,CapRound,JoinRound);
    XSetForeground(dpy,gcon,(unsigned long)Lut[1]);
    XDrawLine(dpy,wdw,gcon,x1,y1,x2,y2);    
    XSetLineAttributes(dpy,gcon,wid-1,LineSolid,CapRound,JoinRound);
    XSetForeground(dpy,gcon,(unsigned long)Lut[3]);
    XDrawLine(dpy,wdw,gcon,x1+1,y1-1,x2+1,y2-1);    
    XSetLineAttributes(dpy,gcon,wid-2,LineSolid,CapRound,JoinRound);
    XSetForeground(dpy,gcon,(unsigned long)Lut[2]);
    XDrawLine(dpy,wdw,gcon,x1,y1,x2,y2);    
    XChangeGC(dpy,gcon,GCLineWidth|GCLineStyle|GCCapStyle|GCJoinStyle,lineattr);
}


static void DrawUpBox( Drawable wdw, int x1, int y1, int x2, int y2 )
{
    register int lx,ly,ux,uy;

    lx = x1+1;  ly = y1+1;
    ux = x2-1;  uy = y2-1;

    XSetForeground(dpy,gcon,(unsigned long)Lut[3]);
    XDrawLine(dpy,wdw,gcon,x1,y1,x2,y1); /* top bar */
    XDrawLine(dpy,wdw,gcon,lx,ly,ux,ly); /* top bar */
    XDrawLine(dpy,wdw,gcon,x2,y1,x2,y2); /* right bar */
    XDrawLine(dpy,wdw,gcon,ux,ly,ux,uy); /* right bar */

    XSetForeground(dpy,gcon,(unsigned long)Lut[1]);
    XDrawLine(dpy,wdw,gcon,x1,y2,x2,y2); /* bottom bar */
    XDrawLine(dpy,wdw,gcon,lx,uy,ux,uy); /* bottom bar */
    XDrawLine(dpy,wdw,gcon,x1,y1,x1,y2); /* left bar */
    XDrawLine(dpy,wdw,gcon,lx,ly,lx,uy); /* left bar */
}


static void DrawDnBox(  Drawable wdw, int x1, int y1, int x2, int y2 )
{
    register int lx,ly,ux,uy;

    lx = x1+1;  ly = y1+1;
    ux = x2-1;  uy = y2-1;

    XSetForeground(dpy,gcon,(unsigned long)Lut[1]);
    XDrawLine(dpy,wdw,gcon,x1,y1,x2,y1); /* top bar */
    XDrawLine(dpy,wdw,gcon,lx,ly,ux,ly); /* top bar */
    XDrawLine(dpy,wdw,gcon,x2,y1,x2,y2); /* right bar */
    XDrawLine(dpy,wdw,gcon,ux,ly,ux,uy); /* right bar */

    XSetForeground(dpy,gcon,(unsigned long)Lut[3]);
    XDrawLine(dpy,wdw,gcon,x1,y2,x2,y2); /* bottom bar */
    XDrawLine(dpy,wdw,gcon,lx,uy,ux,uy); /* bottom bar */
    XDrawLine(dpy,wdw,gcon,x1,y1,x1,y2); /* left bar */
    XDrawLine(dpy,wdw,gcon,lx,ly,lx,uy); /* left bar */
}


static void DrawNoBox( Drawable wdw, int x1, int y1, int x2, int y2 )
{
    register int lx,ly,ux,uy;

    lx = x1+1;  ly = y1+1;
    ux = x2-1;  uy = y2-1;

    XSetForeground(dpy,gcon,(unsigned long)Lut[2]);

    XDrawLine(dpy,wdw,gcon,x1,y1,x2,y1);
    XDrawLine(dpy,wdw,gcon,x2,y1,x2,y2);
    XDrawLine(dpy,wdw,gcon,x2,y2,x1,y2);
    XDrawLine(dpy,wdw,gcon,x1,y2,x1,y1);

    XDrawLine(dpy,wdw,gcon,lx,ly,ux,ly);
    XDrawLine(dpy,wdw,gcon,ux,ly,ux,uy);
    XDrawLine(dpy,wdw,gcon,ux,uy,lx,uy);
    XDrawLine(dpy,wdw,gcon,lx,uy,lx,ly);
}


static void OpenMenuBar( void )
{
    register unsigned long mask;

    mask = CWEventMask;
    attr.event_mask = ExposureMask | ButtonPressMask | ButtonReleaseMask;
    MenuWin = XCreateWindow( dpy, MainWin, 2, 2, XRange+49, FontHigh+5, 0,
                             CopyFromParent, InputOnly, vis, mask, &attr );

    /* Create Unmapped PopUp Window! */
    mask = CWEventMask;
    attr.event_mask = ExposureMask | ButtonPressMask | ButtonReleaseMask | 
                      KeyPressMask | VisibilityChangeMask ;
    attr.background_pixel = Lut[2];     mask |= CWBackPixel;
    attr.border_pixel = Lut[2];         mask |= CWBorderPixel;
    attr.override_redirect = True;      mask |= CWOverrideRedirect;
    attr.save_under = True;             mask |= CWSaveUnder;
    attr.colormap = cmap;               mask |= CWColormap;

    PopUpWin = XCreateWindow(dpy, RootWin, 0, 0, 100, 100, 0, 
                             PixDepth, InputOutput, vis,
                             mask, &attr );
    MenuFocus = False;
    PopUpFlag = False;
}


static void OpenScrollBars( void )
{
    register unsigned long mask;

    Scrl = XCreatePixmap( dpy, MainWin, 16, 16, PixDepth );
    XSetForeground(dpy,gcon,(unsigned long)Lut[2]); 
    XFillRectangle(dpy,Scrl,gcon,0,0,15,15);
    XSetForeground(dpy,gcon,(unsigned long)Lut[0]); 
    XDrawRectangle(dpy,Scrl,gcon,0,0,15,15);
    DrawUpBox( Scrl, 1, 1, 14, 14 );

    tilepix = XCreatePixmapFromBitmapData( dpy, MainWin, (char*)ScrlTile, 8, 8,
                                           (unsigned long)Lut[0], 
                                           (unsigned long)Lut[2], PixDepth );

    mask = CWEventMask;
    attr.event_mask = ExposureMask | ButtonPressMask | ButtonMotionMask 
                    | ButtonReleaseMask;
    attr.background_pixmap = tilepix;              mask |= CWBackPixmap;

    XScrlWin = XCreateWindow(dpy,MainWin,14,YRange+MenuHigh+24,XRange,16, 
                             0,CopyFromParent,InputOutput,vis,mask,&attr);
    lfpix = XCreatePixmapFromBitmapData( dpy, MainWin, (char*)LfArrow, 16, 16,
                                         (unsigned long)Lut[0], 
                                         (unsigned long)Lut[2], PixDepth );
    rgpix = XCreatePixmapFromBitmapData( dpy, MainWin, (char*)RgArrow, 16, 16, 
                                         (unsigned long)Lut[0], 
                                         (unsigned long)Lut[2], PixDepth );

    YScrlWin = XCreateWindow(dpy,MainWin,XRange+24,MenuHigh+14,16,YRange, 
                             0,CopyFromParent,InputOutput,vis,mask,&attr);
    uppix = XCreatePixmapFromBitmapData( dpy, MainWin, (char*)UpArrow, 16, 16,
                                         (unsigned long)Lut[0], 
                                         (unsigned long)Lut[2], PixDepth );
    dnpix = XCreatePixmapFromBitmapData( dpy, MainWin, (char*)DnArrow, 16, 16,
                                         (unsigned long)Lut[0], 
                                         (unsigned long)Lut[2], PixDepth );

    ScrlX = (XRange/2)-8;
    ScrlY = (YRange/2)-8;
}


static void DrawXScroll( void )
{
    XCopyArea(dpy,rgpix,XScrlWin,gcon,0,0,16,16,XRange-16,0);
    XCopyArea(dpy,Scrl ,XScrlWin,gcon,0,0,16,16,ScrlX,0);
    XCopyArea(dpy,lfpix,XScrlWin,gcon,0,0,16,16,0,0);
}


static void DrawYScroll( void )
{
    XCopyArea(dpy,dnpix,YScrlWin,gcon,0,0,16,16,0,YRange-16);
    XCopyArea(dpy,Scrl ,YScrlWin,gcon,0,0,16,16,0,ScrlY);
    XCopyArea(dpy,uppix,YScrlWin,gcon,0,0,16,16,0,0);
}


void UpdateScrollBars( void )
{
    register int temp;


    if ( RotMode == RotAll ) {
      temp = (WorldDialValue[YScrlDial]+1.0)*(YRange-48); 
    } else {
      temp = (DialValue[YScrlDial]+1.0)*(YRange-48); 
    } 
    NewScrlY = (temp>>1)+16;

    if( NewScrlY != ScrlY )
    {   XClearArea(dpy,YScrlWin,0,ScrlY,16,16,False);
        XCopyArea(dpy,Scrl,YScrlWin,gcon,0,0,16,16,0,NewScrlY);
        ReDrawFlag |= (1<<YScrlDial);
        ScrlY = NewScrlY; 
    }

    if ( (RotMode == RotBond) && BondSelected ) {
      temp = ((BondSelected->BRotValue)+1.0)*(XRange-48);
    } else {
      if ( RotMode == RotAll ) {
        temp = (WorldDialValue[XScrlDial]+1.0)*(XRange-48);
      } else {
        temp = (DialValue[XScrlDial]+1.0)*(XRange-48);
      }
    } 
    NewScrlX = (temp>>1)+16;

    if( NewScrlX != ScrlX )
    {   XClearArea(dpy,XScrlWin,ScrlX,0,16,16,False);
        XCopyArea(dpy,Scrl,XScrlWin,gcon,0,0,16,16,NewScrlX,0);
        ReDrawFlag |= (1<<XScrlDial);
        ScrlX = NewScrlX;
    }
    XFlush(dpy);
}



#ifdef DIALBOX
static void SetDialLabel( int num, char *ptr )
{
    static XStringFeedbackControl ctrl;
    static KeySym text[8];
    register int length;

    length = 0;
    while( *ptr )
       text[length++] = *ptr++;

    ctrl.id = num;
    ctrl.num_keysyms = length;
    ctrl.class = ValuatorClass;
    ctrl.syms_to_display = text;
    XChangeFeedbackControl(dpy,Dials,DvString,
                           (XFeedbackControl*)&ctrl);
}


static void GetDialState( void )
{
    register XValuatorState *ptr;
    register XDeviceState *stat;
    register int i,j,max;

    stat = XQueryDeviceState(dpy,Dials);
    ptr = (XValuatorState*)stat->data;
    for( i=0; i<stat->num_classes; i++ )
    {   if( ptr->class == ValuatorClass )
        {   if( ptr->mode & 0x01 )
            {   DialMode = Absolute;
                max = MinFun(ptr->num_valuators,8);
                for( j=0; j<max; j++ )
                    DialPrev[j] = ptr->valuators[j];
            } else DialMode = Relative;
            break;
        } else ptr = (XValuatorState*)(((char*)ptr) + 
                                       ptr->length);
    }
    XFreeDeviceState(stat);
}


static void OpenDialsBox( void )
{
    register XValuatorInfo *valptr;
    register XFeedbackState *list;
    register XFeedbackState *feed;
    register XDeviceInfo *devlist;
    register XDeviceInfo *ptr;
    register Atom devtype;
    register int i,j,max;

    static XEventClass dclass;
    static int count;

    UseDials = False;
    /* Avoid X Server's without the extension */
    if( !XQueryExtension(dpy,"XInputExtension",
                         &count,&count,&count) )
        return;
    
    devlist = XListInputDevices(dpy,&count);
    devtype = XInternAtom(dpy,XI_KNOB_BOX,True );
    if( (devtype==None) || !devlist ) return;

    ptr = devlist;
    for( i=0; i<count; i++ )
        if( (ptr->use==IsXExtensionDevice) && (ptr->type==devtype) )
        {   valptr = (XValuatorInfo*)ptr->inputclassinfo;
            for( j=0; j<ptr->num_classes; j++ )
            {   if( valptr->class == ValuatorClass )
                    if( (Dials=XOpenDevice(dpy,ptr->id)) )
                    {   UseDials = True;
                        break;
                    }
                valptr = (XValuatorInfo*)(((char*)valptr) +
                                          valptr->length);
            }
            if( UseDials ) break;
        } else ptr++;
    /* XFreeDeviceList(devlist); */

    if( UseDials ) 
    {   /* Determine Dial Mapping! */
        if( !strcmp(ServerVendor(dpy),"Silicon Graphics") )
        {      DialMap = SGIDialMap;
        } else DialMap = ESVDialMap;

        DialMode = valptr->mode;
        max = MinFun(valptr->num_axes,8);
        for( i=0; i<max; i++ )
            DialRes[i] = (Real)valptr->axes[i].resolution;
        GetDialState();
    } else return;

    UseDialLEDs = 0;
    feed = list = XGetFeedbackControl( dpy, Dials, &count );
    for( i=0; i<count; i++ )
    {   if( feed->class == StringFeedbackClass ) UseDialLEDs++;
        feed = (XFeedbackState*)(((char*)feed) + feed->length);
    }
    XFreeFeedbackList( list );

    if( UseDialLEDs >= 8 )
    {   for( i=0; i<8; i++ )
            SetDialLabel(i,DialLabel[DialMap[i]]);
    } else UseDialLEDs = False;

    DeviceMotionNotify( Dials, DialEvent, dclass );
    XSelectExtensionEvent( dpy, MainWin, &dclass, 1 );
    XSelectExtensionEvent( dpy, MenuWin, &dclass, 1 );
    XSelectExtensionEvent( dpy, CanvWin, &dclass, 1 );
    XSelectExtensionEvent( dpy, XScrlWin, &dclass, 1 );
    XSelectExtensionEvent( dpy, YScrlWin, &dclass, 1 );
}


static void HandleDialEvent( XDeviceMotionEvent *ptr )
{
    register double temp;
    register int count;
    register int value;
    register int index;
    register int num;

    /* Limit Number of Dials */
    count = 8 - ptr->first_axis;
    if( count > (int)ptr->axes_count )
        count = (int)ptr->axes_count;

    for( index=0; index<count; index++ )
    {   num = ptr->first_axis+index;
        if( DialMode == Absolute )
        {   value = ptr->axis_data[index] - DialPrev[num];
            DialPrev[num] = ptr->axis_data[index];
        } else value = ptr->axis_data[index];

        if( value )
        {   temp = (Real)value/DialRes[num];
            num = DialMap[num];
            if (num == YScrlDial || num == XScrlDial) {
              if( (RotMode == RotBond) && BondSelected && num == XScrlDial) {
                temp += BondSelected->BRotValue;
                ReDrawFlag |= RFRotBond;
              } else {
                if ( RotMode == RotAll ) {
                  temp += WorldDialValue[num];
                  ReDrawFlag |= (1<<num);
                } else {
                  temp += DialValue[num];
                  ReDrawFlag |= (1<<num);
                }
              }
            } else {
              temp += DialValue[num];
              ReDrawFlag |= (1<<num);
            }

            if( num<3 )
            {   while( temp<-1.0 ) temp += 2.0;
                while( temp>1.0 )  temp -= 2.0;
            } else
            {   if( temp<-1.0 ) temp = -1.0;
                if( temp>1.0 )  temp = 1.0;
            }
            if (num == YScrlDial || num == XScrlDial) {
              if( (RotMode == RotBond) && BondSelected && num == XScrlDial) {
                BondSelected->BRotValue = temp;
                ReDrawFlag |= RFRotBond;
              } else {
                if ( RotMode == RotAll ) {
                  WorldDialValue[num] = temp;
                } else {
                  DialValue[num] = temp;
                }
              }
            } else {
              DialValue[num] = temp;
            }

            if( num==YScrlDial )
            {   value = (temp+1.0)*(YRange-48);
                NewScrlY = (value>>1)+16;
            }

            if( num==XScrlDial )
            {   value = (temp+1.0)*(XRange-48);
                NewScrlX = (value>>1)+16;
            }
        }
    }
}
#endif


static void DrawMainWin( void )
{
    register int temp;

    DrawUpBox(MainWin,0,0,MainWide,MainHigh);
    DrawUpBox(MainWin,0,0,MainWide-2,FontHigh+7);

    temp = YRange+MenuHigh;
    DrawDnBox(MainWin,12,MenuHigh+12,XRange+16,temp+16);
    DrawDnBox(MainWin,XRange+22,MenuHigh+12,XRange+41,temp+16);
    DrawDnBox(MainWin,12,temp+22,XRange+16,temp+41);
}


/*====================*/
/*  Menu Bar Display  */
/*====================*/

static void DisplayMenuBarText( BarItem *ptr, int x, int y )
{
    register unsigned long col;
    register int under, pos, wide;
    int slen;

    if( ptr->flags&mbEnable && !DisableMenu )
    {      col = Lut[0];
    } else col = Lut[1];
    XSetForeground( dpy, gcon, col );

    if (ptr->len) {
      slen = *(ptr->len);
    } else {
      slen = strlen(*(ptr->text));
    }
    if  ( MenuFontSet ) {
        XmbDrawString( dpy, MainWin, MenuFontSet, gcon, x, y, *(ptr->text), slen );
        under = y + XFdescent;
    }else{
        XDrawString( dpy, MainWin, gcon, x, y, *(ptr->text), slen );
        under = y + MenuFont->descent;
    }
    
    if (!isascii(*(*(ptr->text)+*(ptr->pos)) )) return;

    pos = x;
    if (*(ptr->pos)>0) pos += XTextWidth( MenuFont, *(ptr->text), *(ptr->pos) );
              
    if  ( MenuFontSet ) {
      if (*(ptr->pos)>0) pos += XmbTextEscapement(MenuFontSet, *(ptr->text), *(ptr->pos) );
      wide = - XmbTextEscapement( MenuFontSet, *(ptr->text)+*(ptr->pos)+1, slen-*(ptr->pos)-1 )
             + XmbTextEscapement( MenuFontSet, *(ptr->text)+*(ptr->pos), slen-*(ptr->pos) );
    }else{
      wide = - XTextWidth( MenuFont, *(ptr->text)+*(ptr->pos)+1, slen-*(ptr->pos)-1 )
             + XTextWidth( MenuFont, *(ptr->text)+*(ptr->pos), slen-*(ptr->pos) );
    }

    if (wide > 3) wide--;
    if (wide > 6) wide--;

    XDrawLine( dpy, MainWin, gcon, pos, under, pos+wide, under );

}


static void DrawMenuBar( void )
{
    register BarItem *ptr;
    register int wide;
    register int x,y;
    register int i;
	if (Language != TermLanguage ) {
	  if (RasOpenFonts()) {
	    Language = TermLanguage;
		RasOpenFonts();
	  }
	  TermLanguage = Language;
	}

    x = 6;
    if  ( MenuFontSet ) {
      y = XFascent+4;
    } else {
      y = MenuFont->ascent+4;	
      XSetFont( dpy, gcon, MenuFont->fid );
    }

    for( i=0; i<MenuBarMax; i++ )
    {   ptr = MenuBar+i;
        if ( MenuFontSet ) {
          wide = XmbTextEscapement( MenuFontSet, *(ptr->text), *(ptr->len) );
	    } else {
	      wide = XTextWidth(MenuFont, *(ptr->text), *(ptr->len));
	    }
        if( x+wide+24 > MainWide ) break;

        /* Right Justify "Help" */
        if( i == MenuBarMax-1 )
            x = MainWide - (wide+24);
        DisplayMenuBarText( ptr, x+8, y );

        if( MenuFocus && (i==MenuBarSelect) )
        {      DrawUpBox( MainWin, x, 2, x+wide+16, FontHigh+5 );
        } else DrawNoBox( MainWin, x, 2, x+wide+16, FontHigh+5 );
        x += wide+24;
    }
    MenuBarCount = i;
    XFlush(dpy);
}


/*=======================*/
/*  Pop-up Menu Display  */
/*=======================*/
static void DisplayPopUpText( MenuItem *ptr, int x, int y )
{
    register unsigned long col;
    register int pos, wide;
    register int under;
    int slen;

    col = (ptr->flags&mbEnable)? Lut[0] : Lut[1];
    XSetForeground( dpy, gcon, col );

    if (ptr->enable && (*(ptr->enable) == ptr->value)) {
       if ( MenuFontSet ) {
           XDrawLine( dpy, PopUpWin, gcon, x-9, y+XFdescent-FontHigh/2, 
                 x-7, y+XFdescent-2);
           XDrawLine( dpy, PopUpWin, gcon, x-7, y+XFdescent-2, 
                 x-3, y+XFdescent-FontHigh+2);
       } else {
           XDrawLine( dpy, PopUpWin, gcon, x-9, y+MenuFont->descent-FontHigh/2, 
                 x-7, y+MenuFont->descent-2);
           XDrawLine( dpy, PopUpWin, gcon, x-7, y+MenuFont->descent-2, 
                 x-3, y+MenuFont->descent-FontHigh+2);
        }
    }
    if (ptr->len) {
      slen = *(ptr->len);
    } else {
      slen = strlen(*(ptr->text));
    }
    if ( MenuFontSet ) {
      XmbDrawString( dpy, PopUpWin, MenuFontSet, gcon, x, y, *(ptr->text), slen );
      if( (ptr->flags & mbAccel ) && isascii(*(*(ptr->text)+*(ptr->pos)) ) )
      {   under = y + XFdescent;

        pos = x;
        if (*(ptr->pos)>0) pos += XmbTextEscapement( MenuFontSet, *(ptr->text), *(ptr->pos) );
        
        
        wide = - XmbTextEscapement(MenuFontSet, *(ptr->text)+*(ptr->pos)+1, slen-*(ptr->pos)-1 )
               + XmbTextEscapement(MenuFontSet, *(ptr->text)+*(ptr->pos), slen-*(ptr->pos) );
              
        if (wide > 3) wide--;
        if (wide > 6) wide--;

        XDrawLine( dpy, PopUpWin, gcon, pos, under, pos+wide, under );
      }
    }else{
      XDrawString( dpy, PopUpWin, gcon, x, y, *(ptr->text), slen );
      if( (ptr->flags & mbAccel ) && isascii(*(*(ptr->text)+*(ptr->pos)) ) )
      {   under = y + MenuFont->descent;

        pos = x;
        if (*(ptr->pos)>0) pos += XTextWidth( MenuFont, *(ptr->text), *(ptr->pos) );
        
        
        wide = - XTextWidth( MenuFont, *(ptr->text)+*(ptr->pos)+1, slen-*(ptr->pos)-1 )
              + XTextWidth( MenuFont, *(ptr->text)+*(ptr->pos), slen-*(ptr->pos) );
              
        if (wide > 3) wide--;
        if (wide > 6) wide--;

        XDrawLine( dpy, PopUpWin, gcon, pos, under, pos+wide, under );
      }
    }

    

}


static void DrawPopUpMenu( void )
{
    register MenuItem *ptr;
    register int count;
    register int x,y;
    register int i;

    DrawUpBox(PopUpWin,0,0,PopUpWide,PopUpHigh);

    if (MenuBarSelect < 0 ) MenuBarSelect = 0;
    if (MenuBarSelect >= MenuBarMax) MenuBarSelect = MenuBarMax-1;

    ptr = MenuBar[MenuBarSelect].menu;
    count = MenuBar[MenuBarSelect].count;
    if ( MenuBar[MenuBarSelect].increment && 
      *(MenuBar[MenuBarSelect].increment)) {
      count += 1+*(MenuBar[MenuBarSelect].increment);
    }

    y = 2;  x = 2;
    for( i=0; i<count; i++ )
    {   if( !(ptr->flags&mbSepBar) )
        {  
            DisplayPopUpText( ptr, x+12, y+XFascent+2 );

            if( ItemFlag && (i==MenuItemSelect) )
            {      DrawUpBox(PopUpWin,2,y,PopUpWide-2,y+FontHigh+3);
            } else DrawNoBox(PopUpWin,2,y,PopUpWide-2,y+FontHigh+3);
            y += FontHigh+4;
        } else
        {   XSetForeground( dpy, gcon, (unsigned long)Lut[1] );
            XDrawLine(dpy,PopUpWin,gcon,2,y,PopUpWide-2,y);
            XSetForeground( dpy, gcon, (unsigned long)Lut[3] );
            XDrawLine(dpy,PopUpWin,gcon,2,y+1,PopUpWide-2,y+1);
            y += 2;
        }
        ptr++;
    }
    /* XSync(dpy,False); */
    XFlush(dpy);
}


static void DisplayPopUpMenu( int i, int x )
{
    register int wide, count;
    register MenuItem *ptr;
    static int xpos, ypos;
    static Window win;
    XRectangle bound; 
    XRectangle dummy;


    if (PopUpFlag && MenuBarSelect == AboutDLGMItem) {
    	UnDisplayAboutDLG();
    }
    MenuBarSelect = i;
    DrawMenuBar();

    ptr = MenuBar[i].menu;
    count = MenuBar[i].count;
    if ( MenuBar[i].increment && *(MenuBar[i].increment)) {
      count += 1+*(MenuBar[i].increment);
    }

    PopUpHigh = 4;
    PopUpWide = 8;
    for( i=0; i<count; i++ )
    {   if( !(ptr->flags&mbSepBar) )
        {   
	    if ( MenuFontSet ) {
               wide = XmbTextExtents( MenuFontSet, *(ptr->text), *(ptr->len), &dummy, &bound );
	    }else{
	        wide = XTextWidth(MenuFont, *(ptr->text), *(ptr->len));
	    }
            if( wide+28 > PopUpWide ) PopUpWide = wide+28;
                PopUpHigh += FontHigh+4;
        } else PopUpHigh += 2;
        ptr++;
    }
    /* Determine pop-up menu position! */
    XTranslateCoordinates(dpy,MainWin,RootWin,x,FontHigh+6,
                          &xpos, &ypos, &win );

    if( ypos+PopUpHigh > MaxHeight )
        ypos -= (PopUpHigh+FontHigh+6);
    if( xpos+PopUpWide > MaxWidth )
        xpos = MaxWidth-PopUpWide;
    if( xpos < 0 ) xpos = 0;

    XUnmapWindow(dpy,PopUpWin);
    XMoveResizeWindow(dpy,PopUpWin,xpos,ypos,PopUpWide+1,PopUpHigh+1);
    XRaiseWindow(dpy,PopUpWin);
    XMapWindow(dpy,PopUpWin);
    PopUpFlag = True;
    DrawPopUpMenu();
}


static void DisplayAboutDLGText( DLGItem *ptr, int x, int y, int center )
{
    register unsigned long col;
    register int wide;
    int slen;

    col =  Lut[0];
    XSetForeground( dpy, gcon, col );

    slen = strlen(*(ptr->text) );
    
    if (center) {
    	 
      if ( MenuFontSet ) {

          wide = XmbTextEscapement(MenuFontSet,*(ptr->text),slen);

          XmbDrawString( dpy, PopUpWin, MenuFontSet,gcon, 
            x+(ptr->x+(ptr->width)/2)*DLGScale-wide/2, 
            y+(ptr->y)*DLGScale, *(ptr->text), slen );
      }else{
	      wide = XTextWidth(MenuFont, *(ptr->text), slen);

          XDrawString( dpy, PopUpWin,gcon, 
            x+(ptr->x+(ptr->width)/2)*DLGScale-wide/2, 
            y+(ptr->y)*DLGScale, *(ptr->text), slen );
      }
        
    } else  {
       
      if ( MenuFontSet ) {
          XmbDrawString( dpy, PopUpWin, MenuFontSet, gcon, 
            x+(ptr->x)*DLGScale, 
            y+(ptr->y)*DLGScale, *(ptr->text), slen );
      }else{
          XDrawString( dpy, PopUpWin, gcon,
            x+(ptr->x)*DLGScale,
            y+(ptr->y)*DLGScale, *(ptr->text), slen );
      }
    }

}


void DrawAboutDLG( void )
{
    register DLGItem *ptr;
    register int count;
    register int x,y;
    register int i;
    
    DrawUpBox(PopUpWin,0,0,PopUpWide,PopUpHigh);

    ptr = AboutDLG;
    count = AboutDLGCount;

    y = 2+FontHigh;  x = 2;
    for( i=0; i<count; i++ ) {
       switch (ptr->DLGtype){
       
       	case DLGICON: {

            int box1[4], box2[4], box3[4];
            
            DrawUpBox(PopUpWin,x+(ptr->x)*DLGScale-4,
                               y+(ptr->y)*DLGScale-4-(ptr->height)*DLGScale,
                               x+(ptr->x)*DLGScale+4+(ptr->width)*DLGScale,
                               y+(ptr->y)*DLGScale+4);
            
            box1[0] = x+(ptr->x)*DLGScale;
            box1[1] = box2[1] = y+(ptr->y)*DLGScale-(ptr->height)*9*DLGScale/200;
            box1[2] = box2[2] = box3[2] = (ptr->width/2-1)*DLGScale;
            box1[3] = box2[3] = box3[3] = (ptr->height/2-1)*DLGScale-(ptr->height)*9*DLGScale/200;
            
            box2[0] = x+(ptr->x)*DLGScale+(ptr->width)*DLGScale - box2[2];
            box3[0] = x+(box1[0] + box2[0]-1)/2;
            box3[1] = box1[1] - 178*(box2[0]-box1[0]+1)/200-(ptr->height)*9*DLGScale/200;
       	
         	DrawUpCircle(PopUpWin,box2[0], box2[1] - box2[3],
       	      box2[0] + box2[2], box2[1]);

       	    DrawUpLine (PopUpWin,box2[0]+box2[2]/2 
       	                         + (box3[0]-box2[0])/4,
       	                         box2[1]-box2[2]/2 
       	                         + (box3[1]-box2[1])/4,
       	                         box2[0]+box2[2]/2 
       	                         + 3*(box3[0]-box2[0])/4,
       	                         box2[1]-box2[3]/2 
       	                         + 3*(box3[1]-box2[1])/4,6);

     	    DrawUpCircle(PopUpWin,box3[0], box3[1] - box3[3],
       	      box3[0] + box3[2], box3[1]);
       	      
       	    DrawUpLine (PopUpWin,box3[0]+box3[2]/2 
       	                         + (box1[0]-box3[0])/4,
       	                         box3[1]-box3[2]/2 
       	                         + (box1[1]-box3[1])/4,
       	                         box3[0]+box3[2]/2 
       	                         + 3*(box1[0]-box3[0])/4,
       	                         box3[1]-box3[3]/2 
       	                         + 3*(box1[1]-box3[1])/4,6);

       	    DrawUpCircle(PopUpWin,box1[0], box1[1] - box1[3],
       	      box1[0] + box1[2], box1[1]);
       	      
       	    DrawUpLine (PopUpWin,box1[0]+box1[2]/2 
       	                         + (box2[0]-box1[0])/4,
       	                         box1[1]-box1[2]/2 
       	                         + (box2[1]-box1[1])/4,
       	                         box1[0]+box1[2]/2 
       	                         + 3*(box2[0]-box1[0])/4,
       	                         box1[1]-box1[3]/2 
       	                         + 3*(box2[1]-box1[1])/4,6);
         	DrawUpPieSlice(PopUpWin,box2[0], box2[1] - box2[3],
       	      box2[0] + box2[2], box2[1]);


       	    break;
       	}
       	case DLGCTEXT:
#ifdef USE_UNAME
            if (ptr->Identifier == IDD_HARDWARE  && 
              !uname(&AboutDLGUNAME) ) {
              int klen;
              
              klen = 0;
              strncpy(unamebuffer,AboutDLGUNAME.sysname,81);
              unamebuffer[80] = '\0';
              klen = strlen(unamebuffer);
              if (79-klen > strlen(AboutDLGUNAME.nodename)) {
              	unamebuffer[klen] = ' ';
              	strncpy(unamebuffer+klen+1,AboutDLGUNAME.nodename,81-klen);
                unamebuffer[80] = '\0';
                klen = strlen(unamebuffer);
              }
              /* if (79-klen > strlen(AboutDLGUNAME.release)) {
              	unamebuffer[klen] = ' ';
              	strncpy(unamebuffer+klen+1,AboutDLGUNAME.release,81-klen);
                unamebuffer[80] = '\0';
                klen = strlen(unamebuffer);
              } */
               if (79-klen > strlen(AboutDLGUNAME.version)) {
              	unamebuffer[klen] = ' ';
              	strncpy(unamebuffer+klen+1,AboutDLGUNAME.version,81-klen);
                unamebuffer[80] = '\0';
                klen = strlen(unamebuffer);
              }
               if (79-klen > strlen(AboutDLGUNAME.machine)) {
              	unamebuffer[klen] = ' ';
              	strncpy(unamebuffer+klen+1,AboutDLGUNAME.machine,81-klen);
                unamebuffer[80] = '\0';
                klen = strlen(unamebuffer);
              }
            }
#endif   	    
       	    DisplayAboutDLGText(ptr,x,y,True);
       	    /* WriteString("\n");WriteString(*(ptr->text) ); */
       	    break;
       	case DLGPUSHBUTTON:
       	    DisplayAboutDLGText(ptr,x,y-((ptr->height)*DLGScale+4-FontHigh)/2,True);
            if (ptr->status) {
         	  DrawDnBox(PopUpWin,x+(ptr->x)*DLGScale,
         	    y+(ptr->y)*DLGScale-((ptr->height)*DLGScale),
         	    x+(ptr->x)*DLGScale+(ptr->width)*DLGScale,
         	    y+(ptr->y)*DLGScale);
       	      break;
            } else {
         	  DrawUpBox(PopUpWin,x+(ptr->x)*DLGScale,
         	    y+(ptr->y)*DLGScale-((ptr->height)*DLGScale),
         	    x+(ptr->x)*DLGScale+(ptr->width)*DLGScale,
         	    y+(ptr->y)*DLGScale);
       	      break;
       	    }
       	case DLGCHECKBOX:
       	    DisplayAboutDLGText(ptr,x+(ptr->height)*DLGScale+2,y,False);
       	    if (ptr->status) {
       	      DrawDnBox(PopUpWin,x+(ptr->x)*DLGScale,
       	        y+(ptr->y)*DLGScale-(ptr->height)*DLGScale,
       	        x+(ptr->x)*DLGScale+(ptr->height)*DLGScale,
       	        y+(ptr->y)*DLGScale);
       	      break;
       	    } else {
       	      DrawUpBox(PopUpWin,x+(ptr->x)*DLGScale,
       	        y+(ptr->y)*DLGScale-(ptr->height)*DLGScale,
       	        x+(ptr->x)*DLGScale+(ptr->height)*DLGScale,
       	        y+(ptr->y)*DLGScale);
       	      break;
       	    }
       }
     ptr++;
    	
    }
    /* WriteString("\n\n"); */
    XFlush(dpy);
}


void DisplayAboutDLG( void ) {

    static int xpos, ypos;
    static Window win;

    MenuBarSelect = AboutDLGMItem;
    DrawMenuBar();
    
    if (AboutDLG[AboutDLGNOSHOWindex].DLGtype==DLGCHECKBOX
      &&  AboutDLG[AboutDLGNOSHOWindex].Identifier==IDD_NOSHOW) {
      if (getraid(filaid, 1025, fillang, 81)
        && DetermineApplicationIdentifier(macaid, 1025)
        && !strncasecmp(filaid,macaid,1024)) {
        AboutDLG[AboutDLGNOSHOWindex].status=1;
      } else { 
        AboutDLG[AboutDLGNOSHOWindex].status=0;
      }
    }

    ItemFlag = False;

    PopUpHigh = AboutDLGHeight*DLGScale+4;
    PopUpWide = AboutDLGWidth*DLGScale+4;    
    /* Determine pop-up menu position! */
    XTranslateCoordinates(dpy,MainWin,RootWin,AboutDLGXpos,FontHigh+6,
                          &xpos, &ypos, &win );
                          
    if( ypos+PopUpHigh > MaxHeight )
        ypos -= (PopUpHigh+FontHigh+6);
    if( xpos+PopUpWide > MaxWidth )
        xpos = MaxWidth-PopUpWide;
    if( xpos < 0 ) xpos = 0;

    XUnmapWindow(dpy,PopUpWin);
    XMoveResizeWindow(dpy,PopUpWin,xpos,ypos,PopUpWide+1,PopUpHigh+1);
    XRaiseWindow(dpy,PopUpWin);
    XMapWindow(dpy,PopUpWin);
    PopUpFlag = True;
    DrawAboutDLG();
    ItemFocus = True;	
}


void UnDisplayAboutDLG( void ) {

    MenuBarSelect = 0;
    DrawMenuBar();
    
    ItemFlag = False;

    if (AboutDLG[AboutDLGNOSHOWindex].DLGtype==DLGCHECKBOX
      &&  AboutDLG[AboutDLGNOSHOWindex].Identifier==IDD_NOSHOW) {
      if (AboutDLG[AboutDLGNOSHOWindex].status &&
        DetermineApplicationIdentifier(macaid, 1025)) {
        setraid(macaid,lang2str(Language));
      } else {
        setraid("",lang2str(Language));
      }
    } else {
      FatalGraphicsError("Improperly structured AboutDLG in graphics.h");
    }

    XUnmapWindow(dpy,PopUpWin);
    PopUpFlag = False;
}


/*==============================*/
/*  Pop-Up Menu Event Handling  */
/*==============================*/

static void HandleItemClick( int xpos, int ypos )
{
    register MenuItem *ptr;
    register DLGItem *qtr;
    register int count,i;
    register int xo, yo;

    /* Ignore by not setting ItemFocus! */
    if( (xpos<0) || (xpos>PopUpWide) ) return;
    if( (ypos<0) || (ypos>PopUpHigh) ) return;
    ItemFocus = True;

    if (MenuBarSelect == AboutDLGMItem) {
      MenuItemSelect = -1;
      qtr = AboutDLG;
      count = AboutDLGCount;
      yo = 2+FontHigh;
      xo = 2;
      for (i = 0; i < count; i++)  {
        if ( qtr->DLGtype == DLGPUSHBUTTON ) {
        	if ( xpos >= xo+(qtr->x)*DLGScale 
        	  && xpos <= xo+(qtr->x)*DLGScale+(qtr->width)*DLGScale
        	  && ypos >= yo+(qtr->y)*DLGScale-(qtr->height)*DLGScale
       	      && ypos <= yo+(qtr->y)*DLGScale) {
       	        MenuItemSelect = i;
       	        ItemFlag = True;
       	        return;
        	}
        } else if ( qtr->DLGtype == DLGCHECKBOX ) {
        	if ( xpos >= xo+(qtr->x)*DLGScale 
        	  && xpos <= xo+(qtr->x)*DLGScale+(qtr->height)*DLGScale
        	  && ypos >= yo+(qtr->y)*DLGScale-(qtr->height)*DLGScale
       	      && ypos <= yo+(qtr->y)*DLGScale) {
       	        MenuItemSelect = i;
       	        ItemFlag = True;
       	        return;
        	}
        }
        qtr++;
      }
      ItemFlag = False;
      return;
    	
    } else {

      ptr = MenuBar[MenuBarSelect].menu;
      count = MenuBar[MenuBarSelect].count;
      if ( MenuBar[MenuBarSelect].increment && 
        *(MenuBar[MenuBarSelect].increment)) {
        count += 1+*(MenuBar[MenuBarSelect].increment);
      }

      yo = 2;
      for( i=0; i<count; i++ )
      {   if( !(ptr->flags&mbSepBar) )
          {   if( (ypos>=yo) && (ypos<=yo+FontHigh+3) )
              {   if( ptr->flags & mbEnable )
                  {   if( !ItemFlag || (MenuItemSelect!=i) )
                      {   /* Avoid Flickering */
                          MenuItemSelect = i;
                          ItemFlag = True;
                          DrawPopUpMenu();
                      }
                      return;
                  } else break;
              }
              yo += FontHigh+4;
          } else yo += 2;
          ptr++;
      }
    }

    if( ItemFlag )
    {   ItemFlag = False;
        if (MenuBarSelect == AboutDLGMItem) {
          DrawAboutDLG();
        } else {
          DrawPopUpMenu();
        }
    }
}


static void HandleItemMove( int xpos, int ypos )
{
    register MenuItem *ptr;
    register DLGItem *qtr;
    register int count,i;

    static int xo, yo;

    if (MenuBarSelect == AboutDLGMItem) {
      if ((xpos>=0) && (xpos<=PopUpWide) 
        && (ypos>=0) && (ypos <= PopUpHigh)) {
        qtr = AboutDLG;
        count = AboutDLGCount;
        yo = 2+FontHigh;
        xo = 2;
        for (i = 0; i < count; i++)  {
          if ( qtr->DLGtype == DLGPUSHBUTTON ) {
        	if ( xpos >= xo+(qtr->x)*DLGScale 
        	  && xpos <= xo+(qtr->x)*DLGScale+(qtr->width)*DLGScale
        	  && ypos >= yo+(qtr->y)*DLGScale-(qtr->height)*DLGScale
       	      && ypos <= yo+(qtr->y)*DLGScale) {
       	        MenuItemSelect = i;
       	        ItemFlag = True;
       	        return;
        	}
          } else if ( qtr->DLGtype == DLGCHECKBOX ) {
        	if ( xpos >= xo+(qtr->x)*DLGScale 
        	  && xpos <= xo+(qtr->x)*DLGScale+(qtr->height)*DLGScale
        	  && ypos >= yo+(qtr->y)*DLGScale-(qtr->height)*DLGScale
       	      && ypos <= yo+(qtr->y)*DLGScale) {
       	        MenuItemSelect = i;
       	        ItemFlag = True;
       	        return;
        	}
          }

          qtr++;
        }
      }
    	
    } else {
    	

      if( (xpos>=0) && (xpos<=PopUpWide) )
      {   ptr = MenuBar[MenuBarSelect].menu;
          count = MenuBar[MenuBarSelect].count;
          if ( MenuBar[MenuBarSelect].increment && 
            *(MenuBar[MenuBarSelect].increment)) {
            count += 1+*(MenuBar[MenuBarSelect].increment);
          }

          yo = 2;
          for( i=0; i<count; i++ )
          {   if( !(ptr->flags&mbSepBar) )
              {   if( (ypos>=yo) && (ypos<=yo+FontHigh+3) )
                  {   if( !ItemFlag || (MenuItemSelect!=i) )
                      {   /* Avoid Flicker! */
                          MenuItemSelect = i;
                          ItemFlag = True;
                          DrawPopUpMenu();
                      }
                      ItemFocus = True;
                      return;
                  }
                  yo += FontHigh+4;
              } else yo += 2;
              ptr++;
          }
      }
    
    }

    if( ItemFlag )
    {   /* Avoid Flicker! */
        ItemFlag = False;
        if (MenuBarSelect == AboutDLGMItem) {
          DrawAboutDLG();
        } else {
          DrawPopUpMenu();
        }
    }
}


static int HandleItemKey( int key )
{
    register MenuItem *ptr;
    register int count;
    register int item;
    register int ch;
    register int i;

    key = ToUpper( key );
    item = MenuItemSelect;
    ptr = &MenuBar[MenuBarSelect].menu[item];
    count = MenuBar[MenuBarSelect].count;
    if ( MenuBar[MenuBarSelect].increment && 
      *(MenuBar[MenuBarSelect].increment)) {
      count += 1+*(MenuBar[MenuBarSelect].increment);
    }
    for( i=0; i<count; i++ )
    {   if( (ptr->flags&(mbEnable|mbAccel)) &&  isascii(*(*(ptr->text)+*(ptr->pos)) )  &&
           !(ptr->flags&mbSepBar) )
        {   ch = (*(ptr->text))[*(ptr->pos)];
            if( ToUpper(ch) == key )
                return( (MenuBarSelect<<8)+item+1 );
        }

        /* Advance to next item! */
        if( item == count-1 )
        {   ptr = MenuBar[MenuBarSelect].menu;
            item = 0;
        } else 
        {   item++;
            ptr++;
        }
    }
    return 0;
}


static void SelectFirstItem( int menu )
{
    register MenuItem *ptr;
    register int count;
    register int i;

    count = MenuBar[menu].count;
    if ( MenuBar[menu].increment && 
      *(MenuBar[menu].increment)) {
      count += 1+*(MenuBar[menu].increment);
    }
    ptr = MenuBar[menu].menu;

    ItemFlag = False;
    for( i=0; i<count; i++ )
        if( (ptr->flags&mbEnable) &&
           !(ptr->flags&mbSepBar) )
        {   MenuItemSelect = i;
            ItemFlag = True;
            break;
        } else ptr++;
}


static void SelectPrevItem( void )
{
    register BarItem *ptr;
    register int flags;
    register int item;
    register int i;

    if( !ItemFlag || MenuBarSelect == AboutDLGMItem )
        return;

    item = MenuItemSelect;
    ptr = MenuBar + MenuBarSelect;
    for( i=0; i<ptr->count; i++ )
    {   if( !item )
        {   item = ptr->count-1;
        } else item--;

        flags = ptr->menu[item].flags;
        if( (flags&mbEnable) && !(flags&mbSepBar) )
            break;
    }

    if( item != MenuItemSelect )
    {   MenuItemSelect = item;
        DrawPopUpMenu();
    }
}


static void SelectNextItem( void )
{
    register BarItem *ptr;
    register int flags;
    register int item;
    register int i;

    if( !ItemFlag || MenuBarSelect == AboutDLGMItem )
        return;

    item = MenuItemSelect;
    ptr = MenuBar + MenuBarSelect;
    for( i=0; i<ptr->count; i++ )
    {   if( item == ptr->count-1 )
        {   item = 0;
        } else item++;

        flags = ptr->menu[item].flags;
        if( (flags&mbEnable) && !(flags&mbSepBar) )
            break;
    }

    if( item != MenuItemSelect )
    {   MenuItemSelect = item;
        DrawPopUpMenu();
    }
}



/*===========================*/
/*  Menu Bar Event Handling  */
/*===========================*/

static void SelectMenu( int menu )
{
    register BarItem *ptr;
    register int wide;
    register int i,x;

    if( !PopUpFlag )
    {   MenuBarSelect = menu;
        DrawMenuBar();
        return;
    }

    if( menu != MenuBarMax-1 )
    {   x = 6;
        for( i=0; i<menu; i++ )
        {   ptr = MenuBar+i;
	   if ( MenuFontSet ){
            wide = XmbTextEscapement(MenuFontSet,*(ptr->text),*(ptr->len));
	   }else{
	    wide = XTextWidth(MenuFont, *(ptr->text), *(ptr->len));
           }
            x += wide+24;
        }
    } else 
    {   ptr = MenuBar+menu;
          if ( MenuFontSet ){
            wide = XmbTextEscapement(MenuFontSet,*(ptr->text),*(ptr->len));
	   }else{
	    wide = XTextWidth(MenuFont, *(ptr->text), *(ptr->len));
           }
        x = MainWide - (wide+24);
    }

    SelectFirstItem( menu );
    DisplayPopUpMenu( menu, x );
	ItemFocus = False;
}


static int HandleMenuClick( int pos )
{
    register BarItem *ptr;
    register int wide;
    register int x,i;

    if (PopUpFlag && MenuBarSelect == AboutDLGMItem) UnDisplayAboutDLG();
    x = 6;
    for( i=0; i<MenuBarCount; i++ )
    {   ptr = MenuBar+i;
        if ( MenuFontSet ){
          wide = XmbTextEscapement(MenuFontSet,*(ptr->text),*(ptr->len));
	    }else{
	      wide = XTextWidth(MenuFont, *(ptr->text), *(ptr->len));
           }
        if( i == MenuBarMax-1 ) x = MainWide - (wide+24);

        if( (pos>=x) && (pos<=x+wide+16) )
        {   if( !PopUpFlag || (MenuBarSelect!=i) )
            {   ItemFlag = False;
                DisplayPopUpMenu(i,x);
            } else if( ItemFlag )
            {   ItemFlag = False;
                DrawPopUpMenu();
            }
            ItemFocus = True;
            return True;
        } else x += wide+24;
    }
    return False;
}


static int HandleMenuKey( char key )
{
    register int i;

    key = ToUpper(key);
    for( i=0; i<MenuBarCount; i++ )
        if( ToUpper((*(MenuBar[i].text))[*(MenuBar[i].pos)]) == key )
        {   if (PopUpFlag && MenuBarSelect == AboutDLGMItem) {
    	      UnDisplayAboutDLG();
            }
            if( !PopUpFlag || (MenuBarSelect!=i) )
            {   PopUpFlag = True;
                SelectMenu( i );
            }
            return True;
        }
    return False;
}


void EnableMenus( int flag )
{
    DisableMenu = !flag;
    if( Interactive ) 
    {  DrawMenuBar();
        if (PopUpFlag && MenuBarSelect == AboutDLGMItem) {
          XRaiseWindow(dpy,PopUpWin);	
          DrawAboutDLG();
        }
    } 

}


static void ReSizeWindow( int wide, int high )
{
    register Real xpos;
    register Real ypos;
    register int dx;

    xpos = (XRange>48)? (Real)(ScrlX-16)/(XRange-48) : 0.0;
    ypos = (YRange>48)? (Real)(ScrlY-16)/(YRange-48) : 0.0;

    YRange = high-(MenuHigh+53);
    XRange = wide-53;
    ZRange = 20000;

    if( (dx = XRange%4) )
        XRange += 4-dx;

    MainHigh = YRange+(MenuHigh+53);  HRange = YRange>>1;
    MainWide = XRange+53;             WRange = XRange>>1;
    Range = MinFun(XRange,YRange);

    XResizeWindow( dpy, CanvWin, XRange, YRange);
    XResizeWindow( dpy, MenuWin, XRange+49, FontHigh+5 );
    XMoveResizeWindow( dpy, XScrlWin, 14, YRange+MenuHigh+24, XRange, 16 );
    XMoveResizeWindow( dpy, YScrlWin, XRange+24, MenuHigh+14, 16, YRange );

    NewScrlX = ScrlX = (xpos*(XRange-48))+16;
    NewScrlY = ScrlY = (ypos*(YRange-48))+16;

    XClearWindow( dpy, MainWin );
    XClearWindow( dpy, CanvWin );

    DrawXScroll();
    DrawYScroll();
    DrawMainWin();
    DrawMenuBar();
    if (PopUpFlag && MenuBarSelect == AboutDLGMItem) {
        int xpos, ypos;
        Window win;
        
        XTranslateCoordinates(dpy,MainWin,RootWin,AboutDLGXpos,FontHigh+6,
                          &xpos, &ypos, &win );

        if( ypos+PopUpHigh > MaxHeight )
          ypos -= (PopUpHigh+FontHigh+6);
        if( xpos+PopUpWide > MaxWidth )
          xpos = MaxWidth-PopUpWide;
        if( xpos < 0 ) xpos = 0;
        XMoveResizeWindow(dpy,PopUpWin,xpos,ypos,PopUpWide+1,PopUpHigh+1);
        XClearWindow( dpy, PopUpWin); 
        XRaiseWindow(dpy,PopUpWin);
    	DrawAboutDLG();
    }

    ReDrawFlag |= RFReSize;
    XSync(dpy,True);
}

void ReDrawWindow( void )
{
    if( Interactive )
        ReSizeWindow( MainWide, MainHigh );
} 


int FatalXError( Display *ptr )
{
     /* Avoid Compiler Warnings! */
    UnusedArgument(ptr);

    dpy = (Display*)NULL;
    RasMolFatalExit("*** Fatal X11 I/O Error! ***");
    return 0;
}


int OpenDisplay( void )
{
#ifdef THIRTYTWOBIT
    static ByteTest test;
#endif
    register unsigned long mask;
    register int i,num;
    register char *ptr;
 
    static XVisualInfo visinfo;
    static XClassHint xclass;
    static XSizeHints size;
    static int temp;
    static char VersionStr[50];
    int xpos, ypos, rxpos, rypos;
    Window win;

    sprintf (VersionStr,"RasMol Version %s", VERSION);

    image = (XImage*)NULL;

    MouseCaptureStatus = False;
    MouseUpdateStatus = False;
    UseHourGlass = True;
    DisableMenu = False;
    Monochrome = False;
    XHeldButton = -1;

    for( i=0; i<11; i++ )
         DialValue[i] = 0.0;
         
    CQRMSet(DialQRot,0.,0.,0.,0.);
    CQRMSet(AuxQRot,0.,0.,0.,0.);

    RLut[0]=0;   GLut[0]=0;   BLut[0]=0;    ULut[0]=True;
    RLut[1]=100; GLut[1]=100; BLut[1]=100;  ULut[1]=True;
    RLut[2]=150; GLut[2]=150; BLut[2]=150;  ULut[2]=True;
    RLut[3]=200; GLut[3]=200; BLut[3]=200;  ULut[3]=True;
    RLut[4]=255; GLut[4]=255; BLut[4]=255;  ULut[4]=True;

    XRange = DefaultWide;
    YRange = DefaultHigh;
    
    if (InitWidth  >= 48) XRange = InitWidth;
    if (InitHeight >= 48) YRange = InitHeight;

    WRange = XRange>>1;
    HRange = YRange>>1;
    Range = MinFun(XRange,YRange);
    
    xpos = InitXPos-14;
    ypos = InitYPos-MenuHigh-14;
    if (xpos < 0) xpos = 0;
    if (ypos < 0) ypos = 0;

    if( !Interactive ) return( False );
    if( (dpy=XOpenDisplay(NULL)) == NULL )
        return 0;

    num = DefaultScreen(dpy);
    RootWin = RootWindow(dpy,num);
    XSetIOErrorHandler( FatalXError );

#ifdef EIGHTBIT
    if( !(XMatchVisualInfo(dpy,num,8,PseudoColor,&visinfo) ||
          XMatchVisualInfo(dpy,num,8,GrayScale,&visinfo)) )
    {   /* Attempt to use Monochrome Mode! */
        if( !(XMatchVisualInfo(dpy,num,1,StaticColor,&visinfo) ||
              XMatchVisualInfo(dpy,num,1,StaticGray,&visinfo)) )
        {   XCloseDisplay(dpy);
            return 0;
        }
        Monochrome = True;
        PixDepth = 1;
    } else PixDepth = 8;
#else
#ifdef THIRTYTWOBIT
    if( XMatchVisualInfo(dpy,num,32,TrueColor,&visinfo) ||
        XMatchVisualInfo(dpy,num,32,DirectColor,&visinfo) )
    {   PixDepth = 32;
    } else if( XMatchVisualInfo(dpy,num,24,TrueColor,&visinfo) ||
               XMatchVisualInfo(dpy,num,24,DirectColor,&visinfo) )
    {   PixDepth = 24;
    } else /* No suitable display! */
    {   XCloseDisplay(dpy);
        return(0);
    }
#else /* SIXTEENBIT */
    if( XMatchVisualInfo(dpy,num,16,TrueColor,&visinfo) ||
        XMatchVisualInfo(dpy,num,16,DirectColor,&visinfo) )
    {   PixDepth = 16;
    } else if( XMatchVisualInfo(dpy,num,15,TrueColor,&visinfo) ||
               XMatchVisualInfo(dpy,num,15,DirectColor,&visinfo) )
    {   PixDepth = 15;
    } else /* No suitable display! */
    {   XCloseDisplay(dpy);
        return 0;
    }
#endif
#endif

    if( !Monochrome )
    {   vis = visinfo.visual;
        if( vis != DefaultVisual(dpy,num) )
        {   cmap = XCreateColormap(dpy,RootWin,vis,AllocNone);
        } else cmap = DefaultColormap(dpy,num);
    } else /* Black & White */
    {   /* PixDepth = DefaultDepth(dpy,num); */
        cmap = DefaultColormap(dpy,num);
        vis = visinfo.visual;

        BlackCol = (Pixel)(BlackPixel(dpy,num)&1);
        WhiteCol = (Pixel)(WhitePixel(dpy,num)&1);
    }

    if ( RasOpenFonts() ) {
	  if ( Language != Russian ) {
	    SwitchLang(English);
		if ( RasOpenFonts () ) 
	      FatalGraphicsError("Unable to find suitable font");
	  } else {
		FatalGraphicsError("Unable to find suitable font");
	  }
    }

    OpenColourMap();

    MaxHeight = DisplayHeight(dpy,num);  MinHeight = MenuHigh+101;
    MaxWidth = DisplayWidth(dpy,num);    MinWidth = 101;

    MainHigh = YRange+MenuHigh+53;
    MainWide = XRange+53;

    mask = CWEventMask;
    attr.event_mask = ExposureMask | KeyPressMask | StructureNotifyMask
                    | EnterWindowMask | LeaveWindowMask | PropertyChangeMask;
    attr.background_pixel = Lut[2];     mask |= CWBackPixel;
    attr.border_pixel = Lut[2];         mask |= CWBorderPixel;
    attr.colormap = cmap;               mask |= CWColormap;
    attr.cursor = arrow;                mask |= CWCursor;

    MainWin = XCreateWindow(dpy, RootWin, 0, 0, MainWide, MainHigh, 2,
			    PixDepth, InputOutput, vis, mask, &attr );

    gcon = XCreateGC(dpy,MainWin,0L,NULL);
    /* DefaultGC(dpy,num) */

    XSetGraphicsExposures(dpy,gcon,False);
    icon = XCreateBitmapFromData(dpy,MainWin,(char*)icon_bits,
                                 icon_width,icon_height );

    size.flags = PMinSize | PMaxSize;
    size.min_width = MinWidth;    size.max_width = MaxWidth;
    size.min_height = MinHeight;  size.max_height = MaxHeight;
    XSetStandardProperties(dpy, MainWin, VersionStr,
                           "RasMol", icon, NULL, 0, &size );

    xclass.res_name = "rasmol";
    xclass.res_class = "RasMol";
    XSetClassHint(dpy,MainWin,&xclass);

    hints.icon_pixmap = icon;       
    hints.flags = IconPixmapHint;
    XSetWMHints(dpy,MainWin,&hints);

    OpenCanvas( XRange, YRange );
    OpenScrollBars();
    OpenMenuBar();
    OpenCursors();
    OpenIPCComms();

#ifdef DIALBOX
    OpenDialsBox();
#endif

#ifdef MITSHM
    ptr = DisplayString(dpy);
    if( !ptr || (*ptr==':') || !strncmp(ptr,"localhost:",10) || 
        !strncmp(ptr,"unix:",5) || !strncmp(ptr,"local:",6) )
    {   SharedMemOption = XQueryExtension(dpy,"MIT-SHM",&temp,&temp,&temp);
        if( Monochrome && (PixDepth!=1) ) SharedMemOption = False;
    } else SharedMemOption = False;
    SharedMemFlag = False;
#endif

#ifdef THIRTYTWOBIT
    /* Determine Byte Ordering */
    test.longword = (Long)0x000000ff;
    if( ImageByteOrder(dpy) == MSBFirst )
    {      SwapBytes = test.bytes[0];
    } else SwapBytes = test.bytes[3];
#endif
    
    XMapSubwindows(dpy,MainWin);
    XMapWindow(dpy,MainWin);

    DrawXScroll();
    DrawYScroll();
    DrawMainWin();
    DrawMenuBar();

    XClearWindow( dpy, CanvWin );
    XSync(dpy,False);
    
    XTranslateCoordinates(dpy,MainWin,RootWin,xpos,ypos,
                          &rxpos, &rypos, &win );
    XMoveResizeWindow(dpy,MainWin,rxpos,rypos,MainWide, MainHigh);
    ReDrawWindow();


    num = 1<<ConnectionNumber(dpy);
    return( num );
}

#ifdef MITSHM
static int HandleShmError( Display *dpy, XErrorEvent *ptr )
{
    /* Avoid Compiler Warnings! */
    UnusedArgument(dpy);
    UnusedArgument(ptr);
    SharedMemOption = False;
    return 0;
}
#endif


int CreateImage( void )
{
    register long size, temp;
    register int format;
    register Pixel *ptr;
#ifdef MITSHM
    register int (*handler)();
#endif

    if( !Interactive )
    {   if( FBuffer ) _ffree(FBuffer);
        size = (long)XRange*YRange*sizeof(Pixel);
        FBuffer = (Pixel*)_fmalloc( size+32 );
	return((FBuffer!=(Pixel*)NULL)?True : False);
    }

    format = Monochrome? XYPixmap : ZPixmap;

    if( image ) 
    {   /* Monochrome Mode Frame Buffer! */
        if( FBuffer && (FBuffer!=(Pixel*)image->data) )
            _ffree(FBuffer);
#ifdef MITSHM
        if( SharedMemFlag )
        {   XShmDetach( dpy, &xshminfo );
            image->data = (char*)NULL;
            shmdt( xshminfo.shmaddr );
        }
#endif
        XDestroyImage( image );
        image = (XImage*)NULL;
    }

    if( Monochrome )
    {   /* Monochrome Mode Frame Buffer! */
        size = (long)XRange*YRange*sizeof(Pixel);
        FBuffer = (Pixel*)_fmalloc( size+32 );
	if( FBuffer == (Pixel*)NULL) return False;

        /* Bit per Pixel ScanLines! */
        temp = ((XRange+31)>>5)<<2;
        size = (long)temp*YRange + 32;
    } else 
        size = (long)XRange*YRange*sizeof(Pixel) + 32;

#ifdef MITSHM
    if( SharedMemOption )
    {   SharedMemFlag = False;
        image = XShmCreateImage( dpy, vis, PixDepth, format,
                                 NULL, &xshminfo, XRange, YRange );

        if( image )
        {   temp = (Long)image->bytes_per_line * image->height;
            if( temp > size ) size = temp;
            xshminfo.shmid = shmget( IPC_PRIVATE, size, IPC_CREAT|0777 );
            if( xshminfo.shmid != -1 ) 
            {   xshminfo.shmaddr = (char*)shmat(xshminfo.shmid,0,0);
                if( xshminfo.shmaddr != (char*)-1 )
                {   image->data = xshminfo.shmaddr;
                    if( !Monochrome )
                        FBuffer = (Pixel*)image->data;
                    xshminfo.readOnly = True;
                    handler = XSetErrorHandler ( HandleShmError );
                    SharedMemFlag = XShmAttach( dpy, &xshminfo );
                    XSync(dpy,False);
                    XSetErrorHandler (handler);
                    if (!SharedMemOption) SharedMemFlag = False;
                }
                /* Always Destroy Shared Memory Ident */
                shmctl( xshminfo.shmid, IPC_RMID, 0 );
            }

            if( SharedMemFlag )
            {   if( Monochrome )
                {   if( BlackCol )
                    {      memset((void*)image->data,255,size);
                    } else memset((void*)image->data,255,size);
                }
                return True;
            } else 
            {   XDestroyImage( image );
                image = (XImage*)NULL;
                SharedMemOption = False;
            }
        }
    }
#endif

    /* Allocate Frame Buffer! */
    ptr = (Pixel*)_fmalloc( size );
    if( ptr == (Pixel*)NULL) return False;

    if( !Monochrome ) FBuffer = ptr;
    image = XCreateImage( dpy, vis, PixDepth, format, 0, (char*)ptr, 
                          XRange, YRange, sizeof(Pixel)<<3, 0 );
    return ((image==(XImage *)NULL)? False : True);
}


static void DitherImage( void )
{
    register Card bits;
    register Card *dst;
    register Pixel *src;
    register int xmax,ymax;
    register int count,x,y;
    register int error;

    register Card bmask,wmask;
    register Card bhigh,whigh;
    register int wlen;
    register int blen;
    register int len;

    /* Avoid compiler warnings */
    bits = bmask = wmask = (Card)0;

    src = (Pixel*)FBuffer;
    dst = (Card*)image->data;

    wlen = XRange>>5;
    blen = XRange&31;
    if( blen )
    {   wmask = WhiteCol << (blen-1);
        bmask = BlackCol << (blen-1);
        len = wlen+1;
    } else len = wlen;

    whigh = WhiteCol << 31;
    bhigh = BlackCol << 31;

    /* Allow Compiler Optimisation */
    xmax = XRange;  ymax = YRange;

    error = 0;
    for( y=0; y<ymax; y++ )
    {    for( x=0; x<wlen; x++ )
         {   for( count=0; count<32; count++ )
             {   error += Intensity[*src++];
                 bits <<= 1;
                 if( error >= 128  )
                 {   error -= 255;
                        bits |= WhiteCol;
                 } else bits |= BlackCol;
             }
             *dst++ = bits;
         }

         if( blen )
         {   for( count=0; count<blen; count++ )
             {   error += Intensity[*src++];
                 bits <<= 1;
                 if( error >= 128  )
                 {   error -= 255;
                        bits |= WhiteCol;
                 } else bits |= BlackCol;
             }
             *dst++ = bits;
           
             /* Asymmetric Loop Unrolling! */
             if( ++y == ymax ) break;
             src += xmax;
             dst += wlen;

             bits = 0;
             for( count=0; count<blen; count++ )
             {   error += Intensity[*(--src)];
                 bits >>= 1;
                 if( error >= 128  )
                 {   error -= 255;
                        bits |= wmask;
                 } else bits |= bmask;
             }
             *(--dst) = bits;
         } else
         {   /* Asymmetric Loop Unrolling! */
             if( ++y == ymax ) break;
             src += xmax;
             dst += len;
         }

         for( x=wlen-1; x>=0; x-- )
         {   for( count=0; count<32; count++ )
             {   error += Intensity[*(--src)];
                 bits >>= 1;
                 if( error >= 128  )
                 {   error -= 255;
                        bits |= whigh;
                 } else bits |= bhigh;
             }
             *(--dst) = bits;
         }
         src += xmax;
         dst += len;
    }
}


void TransferImage( void )
{
    if( Monochrome )
        DitherImage();

#ifdef MITSHM
    if( SharedMemFlag )
    {   XShmPutImage(dpy,CanvWin,gcon,image,0,0,0,0,XRange,YRange,False);
        XSync(dpy,False);
    } else
    {   XPutImage( dpy, CanvWin, gcon,image,0,0,0,0,XRange,YRange);
        XFlush(dpy);
    }
#else
    XPutImage( dpy, CanvWin, gcon, image, 0, 0, 0, 0, XRange, YRange );
    XFlush(dpy);
#endif
}


void ClearImage( void )
{
    XClearWindow( dpy, CanvWin );
    XFlush(dpy);
}


int PrintImage( void )
{
    return False;
}


int ClipboardImage( void )
{
    return False;
}


void SetCanvasTitle( char *ptr )
{
    if( Interactive ) {
      XStoreName(dpy,MainWin,ptr);
    }
}


static int HandleIPCError( Display *dpy, XErrorEvent *ptr )
{
    /* Avoid Compiler Warnings! */
    UnusedArgument(dpy);
    UnusedArgument(ptr);
    return 0;
}


static void HandleIPCCommand( void )
{
    static unsigned long len,left;
    static unsigned char *command;
    static Window source;
    static int serial;
    static int format;
    static Atom type;
    char buffer[32];

    register size_t rlen;
    register int result;
    register int (*handler)();
    register char *cmnd;
    register char *ptr;
    char *serialstr;
    char *codestr;
    char *resultstr;
    char *errorInfostr;
    char *errorCodestr;
    int ii;

    command = NULL;
    result = XGetWindowProperty( dpy, MainWin, CommAtom, 0, 1024, True, 
                                 XA_STRING, &type, &format, &len, &left,
                                 &command );
    if( (result!=Success) || (type!=XA_STRING) || (format!=8) )
    {   if( command ) XFree( (char*)command );
        return;
    }

    if (!TkResponsePtr) {
        if (vector_create((GenericVec __far * __far *)&TkResponsePtr,
                          sizeof(char),32) ){
            InvalidateCmndLine();
            RasMolFatalExit(MsgStrs[StrMalloc]);      
        }
    }
    result = 0;
    ptr = (char*)command;
    if( !*ptr )
    {   /* Tcl/Tk4.0 and later */

        buffer[0]='\0';
        buffer[1]='r';
        buffer[2]='\0';
        buffer[3]='-';
        buffer[4]='r';
        buffer[5]=' ';
        buffer[6]='1';
        buffer[7]='\n';
        
        vector_set_elements((GenericVec __far * )TkResponsePtr,
                            (void __far *) buffer, 8,0);
        TkResponsePtr->size=8;

        ptr++;
        while( ptr < (char*)command+len )
        {    if( (ptr[0]=='c') && (ptr[1]=='\0') ) /* check for a command */
             {   ptr += 2;
                 cmnd = (char*)NULL;
                 source = serial = 0;
                 while( (ptr<(char*)command+len) && (*ptr=='-') )
                 {   if( (ptr[1]=='r') && (ptr[2]==' ') )
                     {   sscanf(ptr+3,"%x %d\n",(int*)&source,&serial);
                     } else if( (ptr[1]=='s') && (ptr[2]==' ') )
                         cmnd = ptr+3;
                     while( *ptr ) ptr++;
                     ptr++;
                 }

                 if( !cmnd ) continue;
                 
                 result = ExecuteIPCCommand(cmnd);
                 if( !source || !serial ) continue;

                 (TkResponsePtr->array)[6]= result? '1' : '0';
                 if (!TkResponseDetail) {
                   (TkResponsePtr->array)[7]='\0';
                   sprintf((TkResponsePtr->array)+8,"-s %d",serial);
                   rlen = strlen((TkResponsePtr->array)+8)+9;
                 } else {
                 buffer[0]='\0';
                    vector_add_element((GenericVec __far * )TkResponsePtr,
                                       (void __far *)buffer);
                    sprintf(buffer,"-s %d",serial);
                    vector_add_elements((GenericVec __far * )TkResponsePtr,
                                        (void __far *)buffer,strlen(buffer)+1);
                    rlen = TkResponsePtr->size;
                 }

                 /* Return Tcl/Tk v4.0 result! */
                 handler = XSetErrorHandler( HandleIPCError );
                 XChangeProperty(dpy,source,CommAtom, XA_STRING, 8,
                                 PropModeAppend,
                                 (unsigned char*)(TkResponsePtr->array),rlen);
                 XSync(dpy,False);
                 XSetErrorHandler(handler);
             } else if (ptr[0]=='r' && ptr[1]=='\0') /* Check for a response */
            {
                char xstr[149];
                int xlen;
                char * xp;
                serialstr = NULL;
                codestr = NULL;
                resultstr = NULL;
                errorInfostr = NULL;
                errorCodestr = NULL;
                ptr+=2;
                while((ptr<(char*)command+len)&& (*ptr=='-' )){
                    if (ptr[1]=='s' && ptr[2]==' ') {
                        serialstr = ptr+3;
                    } else if (ptr[1]=='c' && ptr[2]==' ') {
                        codestr = ptr+3;
                    } else if (ptr[1]=='r' && ptr[2]==' ') {
                        resultstr = ptr+3;
                    } else if (ptr[1]=='i' && ptr[2]==' ') {
                        errorInfostr = ptr+3;
                    } else if (ptr[1]=='e' && ptr[2]==' ') {
                        errorCodestr = ptr+3;
                    }
                    while( *ptr ) ptr++;
                    ptr++;
                }
                strcpy(xstr,"Interp response:");
                xlen = strlen(xstr);
                xp = xstr+xlen;
                if (serialstr && xlen < 148-19 && strlen(serialstr)>0) {
                    strncat(xp," serial: ",9);
                    strncat(xp+8,serialstr,10);
                    xlen += strlen(xp);
                    xp+=strlen(xp);
                }
                if (codestr && xlen < 148-18 && strlen(codestr)>0) {
                    strncat(xp," code: ",7);
                    xlen += strlen(xp);
                    xp+=strlen(xp);
                    strncat(xp+8,codestr,10);
                }
                if (resultstr && xlen < 148-69 && strlen(resultstr)>0) {
                    strncat(xp," result: ",9);
                    xlen += strlen(xp);
                    xp+=strlen(xp);
                    strncat(xp+8,resultstr,60);
                }
                if (errorInfostr && xlen < 148-72 && strlen(errorInfostr)>0) {
                    strncat(xp," errorInfo: ",12);
                    strncat(xp+8,errorInfostr,60);
                    xlen += strlen(xp);
                    xp+=strlen(xp);
                }
                if (errorCodestr && xlen < 148-72 && strlen(errorCodestr)>0) {
                    strncat(xp," errorCode: ",12);
                    xlen += strlen(xp);
                    xp+=strlen(xp);
                    strncat(xp+8,errorInfostr,60);
                }
                InterruptCommands(xstr);
             } else /* Unrecognised command! */
             {   while( *ptr ) ptr++;
                 ptr++;
             }
        }

    } else while( *ptr )
    {   /* Tcl/Tk3.0 and later */
        if( *ptr=='C' )
        {   sscanf(ptr+1,"%x %x\n",(int*)&source,&serial);
            while( *ptr && (*ptr!='|') ) ptr++;
            if( *ptr=='|' )
            {   result = ExecuteIPCCommand(ptr+1);
            } else result = 0;

            sprintf(buffer,"R %x 0 %d",serial,result);
            handler = XSetErrorHandler( HandleIPCError );
            XChangeProperty( dpy, source, CommAtom, XA_STRING, 8,
                             PropModeAppend, (unsigned char*)buffer, 
                             (int)strlen(buffer)+1 );
            XSync(dpy,False);
            XSetErrorHandler(handler);
        } 

        /* Next Command! */
        while( *ptr++ );
    }
    XFree( (char*)command );

    if( (result==IPC_Quit) || (result==IPC_Exit) )
        RasMolExit();
}


void SetMouseUpdateStatus( int bool )
{
    if( MouseUpdateStatus != bool )
    {   /* Enable/Disable Pointer Motion Events! */
        attr.event_mask = ExposureMask | ButtonPressMask | ButtonMotionMask 
                        | ButtonReleaseMask;
        if( bool ) attr.event_mask |= PointerMotionMask;
        XChangeWindowAttributes( dpy, CanvWin, CWEventMask, &attr );
    }
    MouseUpdateStatus = bool;
}


void SetMouseCaptureStatus( int bool )
{
    MouseCaptureStatus = bool;
}
                         

static int GetStatus( int mask )
{
    register int status;
    
    status = 0;                             
    if( mask & Button1Mask ) status |= MMLft;
    if( mask & Button2Mask ) status |= MMMid;
    if( mask & Button3Mask ) status |= MMRgt;
    if( mask & ControlMask ) status |= MMCtl;          
    if( mask & ShiftMask )   status |= MMSft;
    return status;
}
  

static int CropRange( int val, int min, int  max )
{
    if( val<min ) return min;
    if( val>max ) return max;
    return val;
}


static void DoneEvents( void )
{
    register Real temp;
    register int index;

    if( XHeldButton == YScrlDial )
    {   index = NewScrlY+XHeldStep;
#ifdef ORIG
        if( YScrlDial < 3 )
        {   if( index<16 )             
            {   index += YRange-48;
            } else if( index > YRange-32 ) 
                index -= YRange-48;
            NewScrlY = index;
        } else NewScrlY = CropRange(index,16,YRange-32);
#else
        if( index < 16 )
        {   index += YRange-48;
        } else if( index > YRange-32 )
            index -= YRange-48;
        NewScrlY = index;
#endif
    }

    if( NewScrlY != ScrlY )
    {   XClearArea(dpy,YScrlWin,0,ScrlY,16,16,False);
        XCopyArea(dpy,Scrl,YScrlWin,gcon,0,0,16,16,0,NewScrlY);

        temp = ((Real)(NewScrlY-16))/(YRange-48);
        if( RotMode == RotAll ) {
          WorldDialValue[YScrlDial] = 2.0*temp - 1.0;
        } else {
          DialValue[YScrlDial] = 2.0*temp - 1.0;
        }
        ReDrawFlag |= (1<<YScrlDial);
        ScrlY = NewScrlY;
    }

    if( XHeldButton == XScrlDial )
    {   index = NewScrlX+XHeldStep;
#ifdef ORIG
        if( XScrlDial<3 )
        {   if( index < 16 ) 
            {   index += XRange-48;
            } else if( index > XRange-32 ) 
                index -= XRange-48;
            NewScrlX = index;
        } else NewScrlX = CropRange(index,16,XRange-32);
#else
        if( index < 16 )
        {   index += XRange-48;
        } else if( index > XRange-32 )
            index -= XRange-48;
        NewScrlX = index;
#endif
    }

    if( NewScrlX != ScrlX )
    {   XClearArea(dpy,XScrlWin,ScrlX,0,16,16,False);
        XCopyArea(dpy,Scrl,XScrlWin,gcon,0,0,16,16,NewScrlX,0);

        temp = ((Real)(NewScrlX-16))/(XRange-48);
        if( (RotMode == RotBond) && BondSelected ) {
          BondSelected->BRotValue =  2.0*temp - 1.0;
          ReDrawFlag |= RFRotBond;
        } else {
          if( RotMode == RotAll ) {
            WorldDialValue[XScrlDial] = 2.0*temp - 1.0;
            ReDrawFlag |= (1<<XScrlDial);
          } else {
            DialValue[XScrlDial] = 2.0*temp - 1.0;
            ReDrawFlag |= (1<<XScrlDial);
          }
        }
        ScrlX = NewScrlX;
    }
    /* XSync(dpy,False); */
    XFlush(dpy);
}


static int ProcessEvent(  XEvent *event )
{
    register int result;
    register int index;
    register int stat;

    result = 0;

    switch( event->type )
    {   case(ButtonPress):
            {   XButtonPressedEvent *ptr;

                XHeldButton = -1;
                ptr = (XButtonPressedEvent*)event;

                if( ptr->window==CanvWin )
                {   stat = GetStatus(ptr->state);
                    ProcessMouseDown(ptr->x,ptr->y,stat);
                } else if( ptr->window==MenuWin )
                {   if( !DisableMenu )
                        if( HandleMenuClick(ptr->x) )
                            result = HandleMenuLoop();
                } else if( ptr->window==XScrlWin )
                {   ReDrawFlag |= RFRotateY;
                    if( ptr->x<16 )
                    {   XHeldButton = XScrlDial;
                        XHeldStep = -XScrlSkip;
                    } else if( ptr->x>=XRange-16 )
                    {   XHeldButton = XScrlDial;
                        XHeldStep = XScrlSkip;
                    } else
                    {   index = ptr->x-8;
#ifdef ORIG
                        if( XScrlDial<3 )
                        {   if( index>XRange-32 )
                            {   index -= XRange-48;
                            } else if( index<16 )
                                index += XRange-48;
                            NewScrlX = index;
                        } else NewScrlX = CropRange(index,16,XRange-32);
#else
                        if( index > XRange-32 )
                        {   index -= XRange-48;
                        } else if( index < 16 )
                            index += XRange-48;
                        NewScrlX = index;
#endif
                    }

                } else if( ptr->window==YScrlWin )
                {   ReDrawFlag |= RFRotateX;
                    if( ptr->y<16 )
                    {   XHeldButton = YScrlDial;
                        XHeldStep = -YScrlSkip;
                    } else if( ptr->y>=YRange-16 )
                    {   XHeldButton = YScrlDial;
                        XHeldStep = YScrlSkip;
                    } else
                    {   index = ptr->y-8;
#ifdef ORIG
                        if( YScrlDial<3 )
                        {   if( index > YRange-32 )
                            {   index -= YRange-48;
                            } else if( index < 16 )
                                index += YRange-48;
                            NewScrlY = index;
                        } else NewScrlY = CropRange(index,16,YRange-32);
#else
                        if( index > YRange-32 )
                        {   index -= YRange-48;
                        } else if( index < 16 )
                            index += YRange-48;
                        NewScrlY = index;
#endif
                    } 

	        }
            } break;

        case(MotionNotify):
            {   XMotionEvent *ptr;

                ptr = (XMotionEvent*)event;
                if( ptr->window==PopUpWin && MenuBarSelect == AboutDLGMItem) {
                    HandleItemMove(ptr->x,ptr->y);
                } else if( ptr->window==CanvWin )
                {   stat = GetStatus(ptr->state);
                    ProcessMouseMove(ptr->x,ptr->y,stat);
                } else if( XHeldButton == -1 )
                {   if( ptr->window==XScrlWin )
                    {   index = ptr->x-8;
                        NewScrlX = CropRange(index,16,XRange-32);
                    } else /* if( ptr->window==YScrlWin ) */
                    {   index = ptr->y-8;
                        NewScrlY = CropRange(index,16,YRange-32);
                    }
                }
            } break;

        case(CirculateNotify):
            {   XCirculateEvent *ptr;

                ptr = (XCirculateEvent*)event;
                if( ptr->window==MainWin && ptr->place==PlaceOnTop
                  && PopUpFlag && MenuBarSelect == AboutDLGMItem) {
                	XRaiseWindow(dpy,PopUpWin);
                	DrawAboutDLG();
                }
            } break;
            
    	case(VisibilityNotify):
             {   XVisibilityEvent *ptr;

                ptr = (XVisibilityEvent*)event;
                if( ptr->window==PopUpWin && ptr->state != VisibilityUnobscured
                  && PopUpFlag && MenuBarSelect == AboutDLGMItem) {
                	XRaiseWindow(dpy,PopUpWin);
                	DrawAboutDLG();
                }
            } break;
   	
            
        case(ButtonRelease):
            {   XButtonReleasedEvent *ptr;

                if( XHeldButton != -1 )
                {   /* Three button emulation fix! */
                    DoneEvents();  XHeldButton = -1;
                }

                ptr = (XButtonReleasedEvent*)event;
 
                if( ptr->window==PopUpWin && MenuBarSelect == AboutDLGMItem) {
                    HandleItemClick(ptr->x,ptr->y);
                    result = (MenuBarSelect<<8) +
                                         MenuItemSelect+1;
                } else if( ptr->window==CanvWin )                
                if( ptr->window==CanvWin )
                {   stat = GetStatus(ptr->state);
                    ProcessMouseUp(ptr->x,ptr->y,stat);
                }
            } break;

        case(KeyPress):
            {   XKeyPressedEvent *ptr;
                static KeySym symbol;
                static char keychar;

                keychar = '\0';
                ptr = (XKeyPressedEvent*)event;
                index = XLookupString(ptr,&keychar,1,&symbol,NULL);
                switch( symbol )
                {   case(XK_Begin):
                    case(XK_Home):  ProcessCharacter(0x01);  break;
                    case(XK_Right): ProcessCharacter(0x06);  break;
                    case(XK_Left):  ProcessCharacter(0x02);  break;
                    case(XK_End):   ProcessCharacter(0x05);  break;
                    case(XK_Up):
                    case(XK_Prior): ProcessCharacter(0x10);  break;
                    case(XK_Down):
                    case(XK_Next):  ProcessCharacter(0x0e);  break;

                    case(XK_F10):   if( !DisableMenu )
                                    {   SelectMenu(0);
                                        result = HandleMenuLoop();
                                    }
                                    break;

                    default:        if( index == 1 )
                                    {
                                        if( !(ptr->state&Mod1Mask) )
                                        {   if( ProcessCharacter(keychar) )
                                            {   if( ProcessCommand() )
                                                    RasMolExit();

                                                if( !CommandActive )
                                                    ResetCommandLine(0);
                                            }
                                        } else if( !DisableMenu )
                                            if( HandleMenuKey(keychar) )
                                                result = HandleMenuLoop();
                                        }
                                    }
            } break;


        case(Expose):
            {   XExposeEvent *ptr;
 
                ptr = (XExposeEvent*)event;
                if( ptr->window==CanvWin )
                {   if( image ) {
#ifdef MITSHM
                        if( SharedMemFlag )
                        {   XShmPutImage( dpy, CanvWin, gcon, image,
                                          ptr->x, ptr->y, ptr->x, ptr->y,
                                          ptr->width, ptr->height, False);
                            XSync(dpy,False);
                        } else
#endif 
                        XPutImage( dpy, CanvWin, gcon, image,
                                   ptr->x, ptr->y, ptr->x, ptr->y,
                                   ptr->width, ptr->height );
                    } else XClearWindow( dpy, CanvWin );
                } else if( ptr->window==MainWin )
                {   DrawMainWin();
                    DrawMenuBar();
                } else if( ptr->window==XScrlWin )
                {   DrawXScroll();
                } else if( ptr->window==YScrlWin )
                {   DrawYScroll();
                }
                if (PopUpFlag
                   && MenuBarSelect == AboutDLGMItem)  {
                   XRaiseWindow(dpy,PopUpWin);
                   DrawAboutDLG();
                }
                XFlush(dpy);
            } break;

        case(EnterNotify):
            {   XCrossingEvent *ptr;

                ptr = (XCrossingEvent*)event;
                if( ptr->detail != NotifyInferior )
                {   if( LocalMap )
                        XInstallColormap(dpy,lmap);
                }
#ifdef DIALBOX
                if( UseDials )
                    GetDialState();
#endif
            }
            break;

        case(LeaveNotify):
            if( LocalMap )
            {   XCrossingEvent *ptr;

                ptr = (XCrossingEvent*)event;
                if( ptr->detail != NotifyInferior )
                    XUninstallColormap(dpy,lmap);
            }
            break;

        case(ConfigureNotify):
            {   XConfigureEvent *ptr;
                register int wide,high;

                ptr = (XConfigureEvent*)event;
                if (ptr->window==MainWin) 
                { high = CropRange(ptr->height,MinHeight,MaxHeight);
                  wide = CropRange(ptr->width, MinWidth, MaxWidth );

                  if( (wide!=MainWide) || (high!=MainHigh) )
                    ReSizeWindow(wide,high);
                  XFlush(dpy);
                }
                if (PopUpFlag && MenuBarSelect == AboutDLGMItem) {
                  int xpos, ypos;
                  Window win;
               
                  XTranslateCoordinates(dpy,MainWin,RootWin,AboutDLGXpos,FontHigh+6,
                          &xpos, &ypos, &win );
                          
                  if( ypos+PopUpHigh > MaxHeight )
                    ypos -= (PopUpHigh+FontHigh+6);
                  if( xpos+PopUpWide > MaxWidth )
                    xpos = MaxWidth-PopUpWide;
                  if( xpos < 0 ) xpos = 0;
                  
                  XMoveWindow(dpy,PopUpWin,xpos,ypos);
                  XRaiseWindow(dpy,PopUpWin);
                  DrawAboutDLG();
                  XFlush(dpy);
                }
            } break;

        case(ClientMessage):
            {   XClientMessageEvent *ptr;

                ptr = (XClientMessageEvent*)event;
                if( (ptr->message_type==ProtoXAtom) && 
                    (ptr->data.l[0]==DelWinXAtom) )
                    RasMolExit();
            } break;

        case(PropertyNotify):
            {   XPropertyEvent *ptr;

                ptr = (XPropertyEvent*)event;
                if( (ptr->atom==CommAtom) &&
                    (ptr->state==PropertyNewValue) )
                    HandleIPCCommand();
            } break;

        case(MapNotify):
            DrawXScroll();
            DrawYScroll();
            DrawMainWin();
            DrawMenuBar();
            if (PopUpFlag && MenuBarSelect == AboutDLGMItem) {
            	XRaiseWindow(dpy,PopUpWin);
                DrawAboutDLG();
            }
            break;

        default:  
#ifdef DIALBOX
            if( event->type == DialEvent )
                HandleDialEvent(  (XDeviceMotionEvent*)event );
#endif
            break;
    }
    return result;
}



/*=========================*/
/*  Modal Dialog Handling  */
/*=========================*/

static int HandleMenuLoop( void )
{
    register unsigned int mask;
    register int result;
    register int done;
    auto XEvent event;

    /* Passive Pointer Grab */
    mask = ButtonPressMask | ButtonReleaseMask | ButtonMotionMask;
    XGrabPointer(dpy,MenuWin,False,mask,
                 GrabModeAsync,GrabModeAsync,
                 None,None,CurrentTime);

    XHeldButton = -1;
    MenuFocus = True;
    DrawMenuBar();
    if (PopUpFlag && MenuBarSelect == AboutDLGMItem) {
      XRaiseWindow(dpy,PopUpWin);
      DrawAboutDLG();
    }

    result = 0;
    done = False;
    while( !done )
    {   XNextEvent( dpy, &event );
        switch( event.type )
        {   case(Expose):
                {   XExposeEvent *ptr;

                    ptr = (XExposeEvent*)&event;
                    if( ptr->window==PopUpWin )
                    { if (MenuBarSelect == AboutDLGMItem)
                      DrawAboutDLG(); else
                      DrawPopUpMenu();
                    } else ProcessEvent(&event);
                } break;


            case(ButtonPress): 
                {   XButtonPressedEvent *ptr;

                    ptr = (XButtonPressedEvent*)&event;
                    /* All Events Relative to MenuWin */
                    if( (ptr->y>=0) && (ptr->y<=FontHigh+5) )
                    {   HandleMenuClick(ptr->x);
                    } else if( PopUpFlag )
                    {         int xpos, ypos;
                              Window win;
                              XTranslateCoordinates(dpy,MenuWin,PopUpWin,ptr->x,ptr->y,
                                &xpos,&ypos,&win);
                              HandleItemClick(xpos,ypos);
                    } else done = True;
                } break;

            case(MotionNotify):
                    if( ItemFocus )
                    {   XMotionEvent *ptr;

                        ptr = (XMotionEvent*)&event;
                        /* All Events Relative to MenuWin */
                        if( (ptr->y>=0) && (ptr->y<=FontHigh+5) )
                        {   HandleMenuClick( ptr->x );
                        } else if( PopUpFlag ) {
                            int xpos, ypos;
                            Window win;
                            XTranslateCoordinates(dpy,MenuWin,PopUpWin,ptr->x,ptr->y,
                               &xpos,&ypos,&win);
                            HandleItemMove(xpos,ypos);
                        }
                    } break;

            case(ButtonRelease):
                    {   XButtonReleasedEvent *ptr;

                        ptr = (XButtonReleasedEvent*)&event;
                        /* All Events Relative to MenuWin */
                        if( (ptr->y>=0) && (ptr->y<=FontHigh+5) )
                        {   if( HandleMenuClick( ptr->x ) )
                            {   SelectFirstItem(MenuBarSelect);
                                DrawPopUpMenu();
                            } else done = True;
                        } else if( PopUpFlag )
                        {   if( ItemFocus || MenuBarSelect == AboutDLGMItem) {
                              int xpos, ypos;
                              Window win;
                              XTranslateCoordinates(dpy,MenuWin,PopUpWin,ptr->x,ptr->y,
                                &xpos,&ypos,&win);
                              HandleItemClick(xpos,ypos);
                            }
                            if( ItemFlag )
                                result = (MenuBarSelect<<8) +
                                         MenuItemSelect+1;
                            done = True;
                        } else done = False;
                        ItemFocus = False;
                    }
                    break;
     
            case(KeyPress):
                if( !ItemFocus )
                {   XKeyPressedEvent *ptr;
                    static KeySym symbol;
                    static char keychar;
                    register int index;

                    ptr = (XKeyPressedEvent*)&event;
                    index = XLookupString(ptr,&keychar,1,&symbol,NULL);
                    switch( symbol )
                    {   case(XK_Right): index = MenuBarSelect+1;
                                        if( index < MenuBarCount )
                                        {   SelectMenu( index );
                                        } else SelectMenu( 0 );
                                        break;

                        case(XK_Left):  if( MenuBarSelect )
                                        {   SelectMenu( MenuBarSelect-1 );
                                        } else SelectMenu( MenuBarCount-1 );
                                        break;

                        case(XK_Up):    if( !PopUpFlag )
                                        {   PopUpFlag = True;
                                            SelectMenu(MenuBarSelect);
                                        } else SelectPrevItem();
                                        break;

                        case(XK_Down):  if( !PopUpFlag )
                                        {   PopUpFlag = True;
                                            SelectMenu(MenuBarSelect);
                                        } else SelectNextItem();
                                        break;

                        case(XK_KP_Enter):
                        case(XK_Linefeed):
                        case(XK_Return):   if( PopUpFlag && ItemFlag )
                                               result = (MenuBarSelect<<8) +
                                                        MenuItemSelect+1;
                                           done = True;
                                           break;

                        default:    if( (index==1) && (keychar>=' ') ) 
                                    {   if( !(ptr->state&Mod1Mask) )
                                        {   if( PopUpFlag )
                                            {   result = HandleItemKey(keychar);
                                                if( result ) done = True;
                                            } else HandleMenuKey(keychar);
                                        } else HandleMenuKey(keychar);
                                    }
                    }
                } break;

            default:                ProcessEvent(&event);
        }
    }

    /* Passive Grab Release */
    XUngrabPointer(dpy,CurrentTime);
    if (PopUpFlag && MenuBarSelect == AboutDLGMItem) {
      UnDisplayAboutDLG();
    }
    XUnmapWindow(dpy,PopUpWin);
    PopUpFlag = False;
    MenuFocus = False;
    DrawMenuBar();
    return result;
}


int FetchEvent( int wait )
{
    register int result;
    auto XEvent event;

    NewScrlX = ScrlX;
    NewScrlY = ScrlY;

    if( XHeldButton != -1 ) wait = False;
    while( XPending(dpy) || (wait && !ReDrawFlag) )
    {   XNextEvent( dpy, &event );
        result = ProcessEvent(&event);
        if( result ) return result;
    }
    DoneEvents();
    return 0;
}


int LookUpColour( char *name, int *red, int *grn, int *blu )
{
    static XColor exact, close;
    register Colormap map;

    map = (LocalMap)? lmap : cmap;
    if( XLookupColor(dpy,map,name,&exact,&close) )
    {   *red = exact.red>>8;
        *grn = exact.green>>8;
        *blu = exact.blue>>8;
        return True;
    }
    return False;
}


void BeginWait( void )
{
    if( UseHourGlass )
    {   XDefineCursor(dpy,CanvWin,hglass);
        XDefineCursor(dpy,MainWin,hglass);
        XFlush(dpy);
    }
}


void EndWait( void )
{
    if( UseHourGlass )
    {   XDefineCursor(dpy,CanvWin,cross);
        XDefineCursor(dpy,MainWin,arrow);
        XFlush(dpy);
    }
}


void CloseDisplay( void )
{
#ifdef DIALBOX
    register int num;
#endif

    /* FatalXError! */
    if( !dpy ) return;

    if( image ) 
    {
#ifdef MITSHM
        if( SharedMemFlag )
        {   XShmDetach( dpy, &xshminfo );
            image->data = (char*)NULL;
            shmdt( xshminfo.shmaddr );
        }
#endif
        XDestroyImage( image );
    }

    if( *TkInterp )
    {   XGrabServer( dpy );
        DeRegisterInterpName(TkInterp);
        XUngrabServer( dpy );
    }

#ifdef DIALBOX
    if( UseDials )
    {   if( UseDialLEDs )
            for( num=0; num<8; num++ )
                SetDialLabel(num,"");
        XCloseDevice(dpy,Dials);
    }
#endif
    XCloseDisplay( dpy );
}

