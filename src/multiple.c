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
/* multiple.c
 $Log$
 Revision 1.16  2008/03/22 18:42:53  yaya
 Post release cleanup and credit to Ikonen in file headers. -- HJB

 Revision 1.15  2008/03/17 03:01:31  yaya
 Update to agree with 2.7.4.2 release and T. Ikonen GTK mods -- HJB

 Revision 1.5  2008/03/17 01:32:41  yaya
 Add gtk mods by tpikonen, and intergate with 2.7.4.2 mods -- HJB

 Revision 1.4  2008/03/16 22:38:09  yaya
 Update stable release to 2.7.4.2; Update rasmol_install and rasmol_run
 scripts to handle Japanese and Chiness (using cxterm), changing
 Japanese for unix back to EUCJP; and align command line options
 to set initial window size and position to agree between unix and
 windows -- HJB

 Revision 1.4  2008/02/21 15:11:46  tpikonen
 Add GTK GUI.

 Revision 1.3  2008/01/30 03:44:00  yaya-hjb
 More post 2.7.4.1 release cleanup -- HJB

 Revision 1.14  2008/01/29 04:12:11  yaya
 Post release cleanup of problems discovered. -- HJB

 Revision 1.13  2008/01/14 15:49:16  yaya
 More of code for CBF style map save
 More use of stdlib as per Ladislav Michnovic
 --HJB

 Revision 1.12  2007/11/19 03:28:39  yaya
 Update to credits for 2.7.4 in manual and headers
 Mask code added -- HJB

 Revision 1.11  2007/11/16 22:48:30  yaya
 Remove use of MapNumber if favor of size of vector
 Clean up selection logic; start on script writing code -- HJB

 Revision 1.10  2007/11/13 03:22:17  yaya
 Changes to support map selectors.  Needs more work. -- HJB

 Revision 1.9  2007/10/22 00:46:54  yaya
 Add start of code for normal to map needed for solid surface.
 Make new title revisions contingent on Interactive flag.
 --HJB

 Revision 1.8  2007/10/15 02:25:56  yaya
 Fix scaling and colors for maps larger than the molecule. -- HJB

 Revision 1.7  2007/10/03 16:56:34  kamburop
 (in molecule.c) "RasMol - " string added to the title of the window
 (in multiple.c) Window title is updated when different molecule is selected

 Revision 1.6  2007/09/03 14:25:10  yaya
 Upload of more of the map load and map generate commands -- HJB

 Revision 1.5  2007/08/03 02:02:34  yaya
 Add MEAN to map level command, and move the various map settings
 under the map command, and set the defaults to make a nice map
 on a default generate (spread .1667, level mean, spacing .5) -- HJB

 Revision 1.4  2007/07/09 13:57:06  yaya
 Add spacing and spread commands -- HJB

 Revision 1.3  2007/07/07 21:54:31  yaya
 Next round of preliminary updates for maps, allowing multiple maps,
 code to set the contour level and some fixes to the languages files -- HJB

 Revision 1.2  2007/07/02 12:44:39  yaya
 Partial preliminary map code -- HJB

 Revision 1.1.1.1  2007/03/01 01:16:33  todorovg
 Chinese working versio from rasmol_ru initial import

 Revision 1.4  2007/02/02 21:08:59  yaya
 Remove // comments for AIX build
 Fix signed length conflict
 Fix array bounds violation for molecule names in multiple.c -- HJB

 Revision 1.3  2006/11/01 03:23:50  yaya
 Update NSIS windows installer for more script types and to fix
 misplaced script instructions for data files; add document and
 script icons directly in raswin.exe; add credit line to
 G. A. Pozhvanov in comments for Russian translations. -- HJB

 Revision 1.2  2006/09/17 10:53:55  yaya
 Clean up headers and start on code for X11 -- HJB

 Revision 1.1.1.1  2006/09/16 18:45:52  yaya
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

 Revision 1.2  2001/02/07 20:30:31  yaya
 *** empty log message ***

 Revision 1.1  2001/01/31 02:13:45  yaya
 Initial revision

 Revision 1.6  2000/08/27 18:30:33  yaya
 fix for nested bond rotation bug

 Revision 1.5  2000/08/26 18:12:35  yaya
 Updates to header comments in all files

 Revision 1.4  2000/08/26 03:14:01  yaya
 Mods for mac compilations

 Revision 1.3  2000/08/25 22:17:44  yaya
 *** empty log message ***

 Revision 1.2  2000/08/13 20:56:19  yaya
 Conversion from toolbar to menus

 Revision 1.1  2000/08/09 01:18:04  yaya
 Rough cut with ucb

 */

/* Original File Header:
 */
/**********************************************************************
  Copyright (c) 1995 UC Regents, ModularCHEM Consortium

  multiple.c
  Multiple Molecule Support for Rasmol
  
  Author:      Gary Grossman (garyg@cory.EECS.Berkeley.EDU)
  Last Update: November 11, 1995
 **********************************************************************/

#include "rasmol.h"

#ifdef IBMPC
#include <windows.h>
#include <malloc.h>
#endif
#ifdef APPLEMAC
#ifdef __CONDITIONALMACROS__
#include <Printing.h>
#else
#include <PrintTraps.h>
#endif
#include <Types.h>
#include <QDOffscreen.h>
#endif
#ifndef sun386
#include <stdlib.h>
#endif

/* Ladislav Michnovic, 10 Jan 08 start */
#include <string.h>
/* Ladislav Michnovic, 10 Jan 08 end */
#include <ctype.h>
#include <stdio.h>
/* #include <string.h> */  /* Ladislav Michnovic, 10 Jan 08 */

#if !defined(IBMPC) && !defined(VMS) && !defined(APPLEMAC)
#include <pwd.h>
#endif

#include <stdarg.h>

#define MULTIPLE_C

#include "command.h"
#include "tokens.h"
#include "molecule.h"
#include "abstree.h"
#include "transfor.h"
#include "render.h"
#include "repres.h"
#include "graphics.h"
#include "pixutils.h"
#include "multiple.h"
#include "outfile.h"
#include "script.h"
#include "vector.h"
#include "wbrotate.h"
#include "langsel.h"
#include "maps.h"

#ifdef APPLEMAC
  #define DirChar ':'
#else
  #ifndef VMS
    #ifdef IBMPC
      #define DirChar  '\\'
    #else
      #define DirChar  '/'
    #endif
  #else
    #define DirChar ']'
  #endif
#endif

static char *frindex(char *s, char c)
{
	register char *t = s;
	
	while (*t)
		t++;
	while (t != s) {
		if (*t == c)
			return t;
		t--;
	}
	return NULL;
}



#define MSG_LINES 4

/**********************************************************************
  Each molecule has an "instance" of these variables 

  To switch between molecules, the current variables are swapped
  out, and the new molecule's variables are swapped in.
 **********************************************************************/
  
/* transfor.c */
extern Real Zoom;

struct {
    void   *data;
    int     size;
    int     offset;
} VarList[] = {

   /* graphics.h */
    
    { DialValue,          sizeof (DialValue),      0 },
     	
    { &DialQRot,          sizeof (DialQRot),       0 },


    /* molecule.h */
    { &Info,              sizeof (Info),           0 },
    { &MainGroupCount,    sizeof (MainGroupCount), 0 },
    { &HetaGroupCount,    sizeof (HetaGroupCount), 0 },
    { &MainAtomCount,     sizeof (MainAtomCount),  0 },
    { &HetaAtomCount,     sizeof (HetaAtomCount),  0 },
    { &CisBondCutOff,     sizeof (CisBondCutOff),  0 },
    { &MinX,              sizeof (MinX),           0 },
    { &MinY,              sizeof (MinY),           0 },
    { &MinZ,              sizeof (MinZ),           0 },
    { &MaxX,              sizeof (MaxX),           0 },
    { &MaxY,              sizeof (MaxY),           0 },
    { &MaxZ,              sizeof (MaxZ),           0 },
    { &HMinMaxFlag,       sizeof (HMinMaxFlag),    0 },
    { &MMinMaxFlag,       sizeof (MMinMaxFlag),    0 },
    { &MinMainTemp,       sizeof (MinMainTemp),    0 },
    { &MaxMainTemp,       sizeof (MaxMainTemp),    0 },
    { &MinHetaTemp,       sizeof (MinHetaTemp),    0 },
    { &MaxHetaTemp,       sizeof (MaxHetaTemp),    0 },
    { &MinMainRes,        sizeof (MinMainRes),     0 },
    { &MaxMainRes,        sizeof (MaxMainRes),     0 },
    { &MinHetaRes,        sizeof (MinHetaRes),     0 },
    { &MaxHetaRes,        sizeof (MaxHetaRes),     0 },
    { &MinAltl,           sizeof (MinAltl),        0 },
    { &MaxAltl,           sizeof (MaxAltl),        0 },
    { &CurMolecule,       sizeof (CurMolecule),    0 },
    { &CurChain,          sizeof (CurChain),       0 },
    { &CurGroup,          sizeof (CurGroup),       0 },
    { &CurAtom,           sizeof (CurAtom),        0 },
    { &IntList,           sizeof (IntList),        0 },
    { &Database,          sizeof (Database),       0 },
    { UserMask,           sizeof (UserMask),       0 },
    { &MinHBondDist,      sizeof (MinHBondDist),   0 },
    { &MaxHBondDist,      sizeof (MaxHBondDist),   0 },
    { &MinBondDist,       sizeof (MinBondDist),    0 },
    { &MaxBondDist,       sizeof (MaxBondDist),    0 },
    { &ElemNo,            sizeof (ElemNo),         0 },
    { &ResNo,             sizeof (ResNo),          0 },
    { &HasHydrogen,       sizeof (HasHydrogen),    0 },
    { &MaskCount,         sizeof (MaskCount),      0 },
    { &NMRModel,          sizeof (NMRModel),       0 },
    { &NullBonds,         sizeof (NullBonds),      0 },
    { &MarkAtoms,         sizeof (MarkAtoms),      0 },
    { &HBondChainsFlag,   sizeof (HBondChainsFlag), 0 },
    { &AtomTree,          sizeof (AtomTree),       0 },
    { &NeedAtomTree,      sizeof (NeedAtomTree),   0 },

    /* render.h */
    { &VoxelsClean,       sizeof (VoxelsClean),    0 },

    /* repres.h */
    { &DotPtr,            sizeof (DotPtr),         0 },
    { &ProbeRadius,       sizeof (ProbeRadius),    0 },
    { &iProbeRad,         sizeof (iProbeRad),      0 },

    /* maps.h  */
    { &MapInfoPtr,        sizeof (MapInfoPtr),     0 },
    { &MapLevel,          sizeof (MapLevel),       0 },
    { &MapMeshRad,        sizeof (MapMeshRad),     0 },
    { &MapPointRad,       sizeof (MapPointRad),    0 },
    { &MapSpacing,        sizeof (MapSpacing),     0 },
    { &MapSpread,         sizeof (MapSpread),      0 },
    { &MapFlag,           sizeof (MapFlag),        0 },
    { &MapRGBCol[0],      sizeof (MapRGBCol[0]),   0 },
    { &MapRGBCol[1],      sizeof (MapRGBCol[1]),   0 },
    { &MapRGBCol[2],      sizeof (MapRGBCol[2]),   0 },
    { &MapRadius,         sizeof (MapRadius),      0 },
    { &MapLabel,          sizeof (MapLabel),       0 },


    /* command.h */

    { &SelectCount,       sizeof (SelectCount),    0 },
     
    /* transfor.h */
    { &LastDialValue[DialRX],            sizeof (LastDialValue[DialRX]),         0 },
    { &LastDialValue[DialRY],            sizeof (LastDialValue[DialRY]),         0 },
    { &LastDialValue[DialRZ],            sizeof (LastDialValue[DialRZ]),         0 },
    { &LastDialValue[DialTX],            sizeof (LastDialValue[DialTX]),         0 },
    { &LastDialValue[DialTY],            sizeof (LastDialValue[DialTY]),         0 },
    { &LastDialValue[DialTZ],            sizeof (LastDialValue[DialTZ]),         0 },
    { &CenX,              sizeof (CenX),           0 },
    { &CenY,              sizeof (CenY),           0 },
    { &CenZ,              sizeof (CenZ),           0 },
    { &ShiftS,            sizeof (ShiftS),         0 },
    { &XlateCen,          sizeof (XlateCen),       0 },
    { &OrigCX,            sizeof (OrigCX),         0 },
    { &OrigCY,            sizeof (OrigCY),         0 },
    { &OrigCZ,            sizeof (OrigCZ),         0 },
    { RotX,               sizeof (RotX),           0 },
    { RotY,               sizeof (RotY),           0 },
    { RotZ,               sizeof (RotZ),           0 },
    { LRotX,              sizeof (LRotX),          0 },
    { LRotY,              sizeof (LRotY),          0 },
    { LRotZ,              sizeof (LRotZ),          0 },
    { LOffset,            sizeof (LOffset),        0 },
    { MatX,               sizeof (MatX),           0 },
    { MatY,               sizeof (MatY),           0 },
    { MatZ,               sizeof (MatZ),           0 },
    { InvX,               sizeof (InvX),           0 },
    { InvY,               sizeof (InvY),           0 },
    { InvZ,               sizeof (InvZ),           0 },
    { &Zoom,              sizeof (Zoom),           0 },
    { &Scale,             sizeof (Scale),          0 },
    { &IScale,            sizeof (IScale),         0 },
     
    { &XOffset,           sizeof (XOffset),        0 },
    { &YOffset,           sizeof (YOffset),        0 },
    { &ZOffset,           sizeof (ZOffset),        0 },
     
    /* transfor.h */
    { &UseScreenClip,     sizeof (UseScreenClip),  0 },
    { &DrawAtoms,         sizeof (DrawAtoms),      0 },
    { &DrawSurf,          sizeof (DrawSurf),       0 },
    { &DrawBonds,         sizeof (DrawBonds),      0 },
    { &DrawRibbon,        sizeof (DrawRibbon),     0 },
    { &LocalRadius,       sizeof (LocalRadius),    0 },
    { &MaxAtomRadius,     sizeof (MaxAtomRadius),  0 },
    { &MaxBondRadius,     sizeof (MaxBondRadius),  0 },
    { &ZoneBoth,          sizeof (ZoneBoth),       0 },

    /* bond rotation stuff */
    { &BLastRot, sizeof (BLastRot), 0 },
    { BAxis, sizeof (BAxis), 0 },
    { &BSrcAtom, sizeof (BSrcAtom), 0 },
    { &BDstAtom, sizeof (BDstAtom), 0 },
    { &BondSelected, sizeof (BondSelected), 0 },
    { &BondsSelected, sizeof (BondsSelected), 0 },     
    { NULL, 0, 0}
    };

#if defined(_powerpc) || !defined(APPLEMAC)
#define my_memcpy memcpy
#else

void    my_memcpy (t, s, n)
char *t, *s;
int n;
{
    while   (--n >= 0)
	*t++ = *s++;
}
#endif

int     GetMoleculeVariable (mol, field, data)
int mol;
void *field, *data;
{
    /* Find this field */
    int     i;
    for (i = 0; VarList[i].data; i++)
	if (VarList[i].data == field) {
	    my_memcpy (data, Molecules[mol] + VarList[i].offset,
		       VarList[i].size);
	    return 1;
	}
    return 0;
}


int  SetMoleculeVariable (int mol, void *field, void *data)
{
    /* Find this field */
    int     i,
    start,
    end;
    for (i = 0; VarList[i].data; i++)
	if (VarList[i].data == field) {
	    if (mol == -1) {
		start = 0;
		end = MAX_MOLECULES - 1;
	    }
	    else
		start = end = mol;
	    for (mol = start; mol <= end; i++)
		my_memcpy (Molecules[mol] + VarList[i].offset,
			   data, VarList[i].size);
	    return 1;
	}
    return 0;
}

void StoreMoleculeData (int index)
{
    int     i;
    char   *data = Molecules[index];
    
    for (i = 0; VarList[i].data; i++) {
	my_memcpy (data, VarList[i].data, VarList[i].size);
	data += VarList[i].size;
    }
}


void    RestoreMoleculeData (index)
int index;
{
    int     i;
    char   *data = Molecules[index];
    double  temp;
    
    /* Horrible hack to keep scaling factor same */
    temp = DialValue[DialZoom];
    
    for (i = 0; VarList[i].data; i++) {
	my_memcpy (VarList[i].data, data, VarList[i].size);
	data += VarList[i].size;
    }
    
    DialValue[DialZoom] = temp;
}


void SwitchMolecule ( int index)
{
    if ( MoleculeIndex != index ) {
      StoreMoleculeData   (MoleculeIndex);
      MoleculeIndex = index;
      RestoreMoleculeData (MoleculeIndex);
    }
}


void SelectMolecule(int index)
{
#ifdef GTKWIN
    set_gtk_open_file(index);
#endif
    SwitchMolecule(index);
    PickCount = 0;
    if (Interactive) {
        ReviseTitle();
    }
}

void ReRadius( void )
{
    int i, SaveMol;
    
    WorldRadius = 0;
    WorldSize = 0;
    DScale = 0;
    
    if (NumMolecules > 0 ) {
      SaveMol = MoleculeIndex;
      for (i = 0; i < NumMolecules; i++) {
        SwitchMolecule(i);
        if (LocalRadius > WorldRadius) {
          WorldRadius = LocalRadius;
          WorldSize = WorldRadius<<1;
          DScale = 1.0/WorldSize;
        }
        if (MapRadius > WorldRadius) {
          WorldRadius = MapRadius;
          WorldSize = WorldRadius<<1;
          DScale = 1.0/WorldSize;        	
        }
      }
      if ( NumMolecules > 1 ) SwitchMolecule(SaveMol);
      /* Code should match ReSizeScreen() */ 
      /* MaxZoom*DScale*Range*750 == 252  */
      MaxZoom = 0.336*WorldSize/Range;
      if( MaxZoom < 1.0 )
      {   DScale *= MaxZoom;
        MaxZoom = 1.0;
      }
      ZoomRange = Range;
      MaxZoom -= 1.0;
    }
    ReDrawFlag |= RFReSize;
}

void InitialiseMultiple( void )
{
    int i, size;

    size = 0;
    for (i = 0; VarList[i].data; i++) {
	VarList[i].offset = size;
	size += VarList[i].size;
    }
    
    for (i = 0; i < MAX_MOLECULES; i++) {
	Molecules[i] = (char __far *) _fmalloc (size);
	_fmemset((void __far *)Molecules[i],0,size);
	if (!Molecules[i])
	    RasMolFatalExit (MsgStrs[StrMalloc]);
	StoreMoleculeData (i);
    }
}

void ZapMolecule( void )
{
    int i;
    char *temp;

    if (NumMolecules > 0 ) {
    /* Put this molecule at the end of the list, shuffle the others forward */
    /* If this is the last molecule, select the second-to-last one */
    temp = Molecules[MoleculeIndex];
    for (i = MoleculeIndex; i < MAX_MOLECULES - 1; i++)
    	Molecules[i] = Molecules[i+1];
    Molecules[MAX_MOLECULES - 1] = temp;
    i = MoleculeIndex;
    MoleculeIndex = MAX_MOLECULES - 1;
    
    NumMolecules--;
    
    if (i != 0 && i == NumMolecules)
    	i--;
    SelectMolecule(i);
    DrawMoleculeList();
    }
}

void DrawMoleculeList( void )
{
    int i, save;
    char buf[MAX_MOLNAME], *s;

    save = MoleculeIndex;
    for (i = 0; i < NumMolecules; i++) {
	SwitchMolecule (i);
#ifdef DirChar
	s = frindex(Info.filename, DirChar);
	if (s == NULL)
	    s = Info.filename;
	else
	    s++;
#else
        s = Info.filename
#endif
        if ( strlen(s) > MAX_MOLNAME-6 ) {
          snprintf(buf, MAX_MOLNAME-4, "%d. %s", i+1, s);
		  snprintf(buf+(MAX_MOLNAME-5), 4, "%s", "...");
        } else {
          snprintf(buf, MAX_MOLNAME, "%d. %s", i+1, s);
        }
        MolName[i][MAX_MOLNAME-1]='\0';
        strncpy(MolName[i],buf,MAX_MOLNAME);
        MolNStr[i] = &(MolName[i][0]);
        MolNLen[i] = strlen(MolName[i]);
    }
    SwitchMolecule(save);
#ifdef GTKWIN
	if(Interactive)
		UpdateGtkMoleculeList();
#endif
}
