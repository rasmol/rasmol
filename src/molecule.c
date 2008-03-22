/***************************************************************************
 *                             RasMol 2.7.4.2                              *
 *                                                                         *
 *                                 RasMol                                  *
 *                 Molecular Graphics Visualisation Tool                   *
 *                            19 November 2007                             *
 *                          (rev. 21 March 2008)                           *
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
 * The code for use of RasMol under GTK in RasMol 2.7.4.2 was written by   *
 * Teemu  Ikonen.                                                          *
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
/* molecule.c
 $Log: not supported by cvs2svn $
 Revision 1.8  2008/03/17 11:35:22  yaya-hjb
 Release 2.7.4.2 update and T. Ikonen GTK update -- HJB

 Revision 1.4  2008/03/17 03:26:06  yaya-hjb
 Align with RasMol 2.7.4.2 release to use cxterm to support Chinese and
 Japanese for Linux and Mac OS X versions using rasmol_install and
 rasmol_run scripts, and align command line options for size and
 position of initial window. -- HJB

 Revision 1.5  2008/03/17 01:32:41  yaya
 Add gtk mods by tpikonen, and intergate with 2.7.4.2 mods -- HJB

 Revision 1.16  2008/03/16 22:25:21  yaya
 Align comments with production version; Update rasmol_install and
 rasmol_run shell scripts for Japanese and Chinese; Align logic for
 positioning and sizing initial window with windows version -- HJB

 Revision 1.4  2008/01/30 03:15:55  yaya
 More post 2.7.4.1 release cleanup -- HJB

 Revision 1.15  2008/01/29 04:12:11  yaya
 Post release cleanup of problems discovered. -- HJB

 Revision 1.3  2008/01/29 04:35:26  yaya
 Postrelease update to fix problems discovered -- HJB

 Revision 1.2  2008/01/28 03:29:37  yaya
 Update CVS to RasMol_2.7.4.1 -- HJB

 Revision 1.14  2008/01/16 21:35:11  yaya
 Change default resolution from .5 Angstrom to 1 Angstrom
 Correct map xlow, xhigh calculations
 Correct map axis output -- HJB

 Revision 1.13  2007/11/25 17:12:18  yaya
 Refresh colours on map load.  Put default spread back to 1/6 -- HJB

 Revision 1.12  2007/11/25 04:11:58  yaya
 Updates to map mask logic and inverse transforms -- HJB

 Revision 1.11  2007/11/19 03:28:39  yaya
 Update to credits for 2.7.4 in manual and headers
 Mask code added -- HJB

 Revision 1.10  2007/11/16 22:48:30  yaya
 Remove use of MapNumber if favor of size of vector
 Clean up selection logic; start on script writing code -- HJB

 Revision 1.9  2007/10/23 02:27:55  yaya
 Preliminary mods for revised PDB format derived from Rutgers mods.
 Partial changes for map tangles -- HJB

 Revision 1.8  2007/10/22 00:46:53  yaya
 Add start of code for normal to map needed for solid surface.
 Make new title revisions contingent on Interactive flag.
 --HJB

 Revision 1.7  2007/10/03 16:56:34  kamburop
 (in molecule.c) "RasMol - " string added to the title of the window
 (in multiple.c) Window title is updated when different molecule is selected

 Revision 1.6  2007/09/13 19:23:22  yaya
 RasMol 2.7.4 PreRelease 1 -- HJB

 Revision 1.5  2007/09/03 14:25:10  yaya
 Upload of more of the map load and map generate commands -- HJB

 Revision 1.4  2007/08/03 02:02:34  yaya
 Add MEAN to map level command, and move the various map settings
 under the map command, and set the defaults to make a nice map
 on a default generate (spread .1667, level mean, spacing .5) -- HJB

 Revision 1.3  2007/07/09 13:57:06  yaya
 Add spacing and spread commands -- HJB

 Revision 1.2  2007/07/07 21:54:31  yaya
 Next round of preliminary updates for maps, allowing multiple maps,
 code to set the contour level and some fixes to the languages files -- HJB

 Revision 1.1.1.1  2007/03/01 01:16:33  todorovg
 Chinese working versio from rasmol_ru initial import

 Revision 1.3  2006/11/01 03:23:50  yaya
 Update NSIS windows installer for more script types and to fix
 misplaced script instructions for data files; add document and
 script icons directly in raswin.exe; add credit line to
 G. A. Pozhvanov in comments for Russian translations. -- HJB

 Revision 1.2  2006/09/17 10:53:55  yaya
 Clean up headers and start on code for X11 -- HJB

 Revision 1.1.1.1  2006/09/16 18:45:50  yaya
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

 Revision 1.5  2000/08/26 18:12:33  yaya
 Updates to header comments in all files

 Revision 1.4  2000/08/21 21:07:37  yaya
 semi-final ucb mods

 Revision 1.3  2000/08/09 01:18:03  yaya
 Rough cut with ucb

 Revision 1.2  2000/02/23 00:00:00  yaya
 Prelininary 2.7.2 build

 */

#include "rasmol.h"

#ifdef IBMPC
#include <windows.h>
#include <malloc.h>
#endif
#ifdef APPLEMAC
#include <Types.h>
#endif
#ifndef sun386
#include <stdlib.h>
#endif

#include <string.h>
#if defined(IBMPC) || defined(VMS) || defined(APPLEMAC)
#include "string_case.h"
#else
#include <strings.h>
#endif
#include <ctype.h>
#include <stdio.h>
#include <math.h>

#define MOLECULE
#include "molecule.h"
#include "cmndline.h"
#include "command.h"
#include "abstree.h"
#include "transfor.h"
#include "render.h"
#include "langsel.h"
#include "repres.h"
#include "graphics.h"
#include "maps.h"

#define HBondPool   32
#define BondPool    32
#define AtomPool    32

#define NoLadder     0x00
#define ParaLadder   0x01
#define AntiLadder   0x02

#define Cos70Deg     0.34202014332567

#define MaxHBondDist   ((int)300)
#define MaxBondDist    ((int)475)
#define MinBondDist    ((int)100)

#define MaxHBondDsq    ((Long)(MaxHBondDist*MaxHBondDist))
#define MaxBondDsq     ((Long)(MaxBondDist*MaxBondDist))
#define MinBondDsq     ((Long)(MinBondDist*MinBondDist))
#define AbsMaxBondDist 600      /* 2.4 Angstroms */
#define AbsMaxAtomRad  750      /* 3.0 Angstroms */
#define AbsMaxAtomDiam AbsMaxAtomRad*2

#ifdef APPLEMAC
#define AllocSize   256
typedef struct _AllocRef {
        struct _AllocRef *next;
        void *data[AllocSize];
        int count;
        } AllocRef;
static AllocRef *AllocList;  
#endif


static Molecule __far *FreeMolecule;
static Chain __far *FreeChain;
static Group __far *FreeGroup;
static RAtom __far *FreeAtom;


static Group __far *Cache;
static RAtom __far *ACache;
static IntCoord __far *IntPrev;
static HBond __far * __far *CurHBond;
static size_t MemSize;

/* Macros for commonly used loops */
#define ForEachAtom  for(chain=Database->clist;chain;chain=chain->cnext) \
                     for(group=chain->glist;group;group=group->gnext)    \
                     for(aptr=group->alist;aptr;aptr=aptr->anext)
#define ForEachBond  for(bptr=Database->blist;bptr;bptr=bptr->bnext)


/*=======================*/
/*  Function Prototypes  */
/*=======================*/

RAtom __far *FindCysSulphur(  Group __far* );
static IntCoord __far* GetInternalCoord( int );
Bond __far *ProcessBond( RAtom __far*, RAtom __far*, int );
static void CreateHydrogenBond( RAtom __far*, RAtom __far*,
                                RAtom __far*, RAtom __far*, int, int );
static int CalculateBondEnergy( Group __far* );
static void CalcProteinHBonds( Chain __far* );
static void CalcNucleicHBonds( Chain __far* );
static int IsHBonded( RAtom __far*, RAtom __far*, HBond __far* );
static void TestLadder( Chain __far* );


#ifdef APPLEMAC
/* External RasMac Function Declaration! */
void SetFileInfo( char*, OSType, OSType, short );
#endif



static void FatalDataError( char *ptr )
{
    char buffer[80];

    sprintf(buffer,"Database Error: %s!",ptr);
    RasMolFatalExit(buffer);
}


void ReviseTitle( void )
{
    char buffer[60];

    buffer[0] = 0;
    buffer[58] = 0;
    buffer[59] = 0;
    
    strncpy(buffer,"RasMol - ", 9);
    buffer[9]=0;
    
    if( *Info.identcode ) {
      strncat(buffer,Info.identcode, 10);
      strncat(buffer," ",1);
    }

    if( *Info.technique ) {
      strncat(buffer,Info.technique, 49-strlen(Info.identcode));
    }

    SetCanvasTitle( buffer );
}

void DescribeMolecule( void )
{
    char buffer[40];

    InvalidateCmndLine();

    if( *Info.moleculename )
    {   WriteString(MsgStrs[StrMolNam]); /* "Molecule name ......... " */
        WriteString(Info.moleculename);
        WriteChar('\n');
    }

    if( *Info.classification )
    {   WriteString(MsgStrs[StrClass]); /* "Classification ........ " */
        WriteString(Info.classification);
        WriteChar('\n');
    }

    if( Database && (MainGroupCount>1) )
    {   WriteString(MsgStrs[StrSecSt]); /* "Secondary Structure ... " */
        if( Info.structsource == SourceNone )
        {   WriteString(MsgStrs[StrNoAsmt]); /* "No Assignment\n" */
        } else if( Info.structsource == SourcePDB )
        {   WriteString(MsgStrs[StrPDBRec]); /* "PDB Data Records\n" */
        } else WriteString(MsgStrs[StrCalc]); /* "Calculated\n" */
    }


    if( *Info.identcode )
    {   WriteString(MsgStrs[StrDBCode]); /* "Database Code ......... " */
        WriteString(Info.identcode);
        WriteChar('\n');
    }

    if( *Info.technique )
    {   WriteString(MsgStrs[StrExpTec]); /* "Experiment Technique .. " */
        WriteString(Info.technique);
        WriteChar('\n');
    }

    if( Info.chaincount > 1 )
    {   sprintf(buffer,"%s%d\n",MsgStrs[StrNumChn],Info.chaincount);
                                         /* "Number of Chains ...... " */
        WriteString(buffer);
    }

    sprintf(buffer,"%s%d",MsgStrs[StrNumGrp],MainGroupCount);
                                         /* "Number of Groups ...... " */
    WriteString(buffer);
    if( HetaAtomCount )
    {   sprintf(buffer," (%d)\n",HetaGroupCount);
        WriteString(buffer);
    } else WriteChar('\n');

    sprintf(buffer,"%s%ld",MsgStrs[StrNumAtm],(long)MainAtomCount);
                                         /* "Number of Atoms ....... " */
    WriteString(buffer);
    if( HetaAtomCount )
    {   sprintf(buffer," (%ld)\n",HetaAtomCount);
        WriteString(buffer);
    } else WriteChar('\n');

    if( Info.bondcount )
    {   sprintf(buffer,"%s%ld\n",MsgStrs[StrNumBnd],(long)Info.bondcount);
                                         /* "Number of Bonds ....... " */
        WriteString(buffer);
    }

    if( Info.ssbondcount != -1 )
    {   WriteString(MsgStrs[StrNumBrg]); /* "Number of Bridges ..... " */
        sprintf(buffer,"%d\n\n",Info.ssbondcount);
        WriteString(buffer);
    }

    if( Info.hbondcount != -1 )
    {   WriteString(MsgStrs[StrNumHbd]); /* "Number of H-Bonds ..... " */
        sprintf(buffer,"%d\n",Info.hbondcount);
        WriteString(buffer);
    }

    if( Info.helixcount != -1 )
    {   WriteString(MsgStrs[StrNumHel]); /* "Number of Helices ..... " */
        sprintf(buffer,"%d\n",Info.helixcount);
        WriteString(buffer);

       WriteString(MsgStrs[StrNumStrnd]); /* "Number of Strands ..... " */
        sprintf(buffer,"%d\n",Info.laddercount);
        WriteString(buffer);

       WriteString(MsgStrs[StrNumTrn]); /* "Number of Turns ....... " */
        sprintf(buffer,"%d\n",Info.turncount);
        WriteString(buffer);
    }
}


#ifdef APPLEMAC
/* Avoid System Memory Leaks! */
void RegisterAlloc( void *data )
{
    register AllocRef *ptr;
    
    if( !AllocList || (AllocList->count==AllocSize) )
    {   ptr = (AllocRef *)_fmalloc( sizeof(AllocRef) );
        if( !ptr ) FatalDataError(MsgStrs[StrMalloc]);
        
        ptr->next = AllocList;
        ptr->data[0] = data;
        ptr->count = 1;
        AllocList = ptr;
    } else AllocList->data[AllocList->count++] = data;
}
#else
#define RegisterAlloc(x)
#endif



/*==================================*/
/* Group & Chain Handling Functions */
/*==================================*/

void CreateChain( int ident )
{
    register Chain __far *prev;

    if( !CurMolecule )
    {   if( !(CurMolecule = FreeMolecule) )
        {   MemSize += sizeof(Molecule);
            CurMolecule = (Molecule __far *)_fmalloc(sizeof(Molecule));
            if( !CurMolecule ) FatalDataError(MsgStrs[StrMalloc]);
            RegisterAlloc( CurMolecule );
        } else FreeMolecule = (void __far*)0;

        CurChain = (void __far*)0;
        CurMolecule->slist = (void __far*)0;
        CurMolecule->hlist = (void __far*)0;
        CurMolecule->blist = (void __far*)0;
        CurMolecule->sblist = (void __far*)0;
        CurMolecule->clist = (void __far*)0;
        Database = CurMolecule;
    }

    /* Handle chain breaks! */
    prev = CurChain;
    if( !prev )
    {   prev = CurMolecule->clist;
        if( prev )
            while( prev->cnext )
                prev = prev->cnext;
    }

    if( !(CurChain = FreeChain) )
    {   MemSize += sizeof(Chain);
        CurChain = (Chain __far *)_fmalloc(sizeof(Chain));
        if( !CurChain ) FatalDataError(MsgStrs[StrMalloc]);
        RegisterAlloc( CurChain );
    } else FreeChain = FreeChain->cnext;

    if( prev )
    {   prev->cnext = CurChain;
    } else CurMolecule->clist = CurChain;
    CurChain->cnext = (void __far*)0;
     
    CurChain->ident = ident;
    CurChain->model = NMRModel;
    CurChain->glist = (void __far*)0;
    CurChain->blist = (void __far*)0;
    CurGroup = (void __far*)0;
    Info.chaincount++;

    Cache = (Group __far*)0;
}


void CreateGroup( int pool )
{
    register Group __far *ptr;
    register int i;

    if( !(ptr = FreeGroup) )
    {   MemSize += pool*sizeof(Group);
        ptr = (Group __far *)_fmalloc( pool*sizeof(Group) );
        if( !ptr ) FatalDataError(MsgStrs[StrMalloc]);
        RegisterAlloc( ptr );
        for( i=1; i<pool; i++ )
        {   ptr->gnext = FreeGroup;
            FreeGroup = ptr++;
        } 
    } else FreeGroup = ptr->gnext;
    
    if( CurGroup )
    {   ptr->gnext = CurGroup->gnext;
        CurGroup->gnext = ptr;
    } else 
    {   ptr->gnext = CurChain->glist;
        CurChain->glist = ptr;
    }
    CurGroup = ptr;

    CurAtom = (void __far*)0;
    ptr->alist = (void __far*)0;
    ptr->serno = -9999;
    ptr->sserno = -9999;
    ptr->insert = ' ';
    ptr->sinsert = ' ';
    ptr->struc = 0;
    ptr->flag = 0;
    ptr->col1 = 0;
    ptr->col2 = 0;
    ptr->model = NMRModel;
}


int FindResNo( char *ptr )
{
    register int ch1,ch2,ch3;
    register int refno;

    ch1 = ToUpper(ptr[0]);
    ch2 = ToUpper(ptr[1]);
    ch3 = ToUpper(ptr[2]);

    switch( ch1 )
    {   case(' '): if( ch2 == ' ' )
                   {   switch( ch3 )
                       {   case('A'):  return( 24 );
                           case('C'):  return( 25 );
                           case('G'):  return( 26 );
                           case('T'):  return( 27 );
                           case('U'):  return( 28 );
                           case('I'):  return( 30 );
                       }
                   } else if( ch2 == '+' )
                   {   if( ch3 == 'U' )
                           return( 29 );
                   } else if( ch2 == 'Y' )
                   {   if( ch3 == 'G' )
                           return( 39 );
                   } else if( ch2 == 'D') 
                   {   switch( ch3 )
                       {   case('A'):  return( 54 );
                           case('C'):  return( 55 );
                           case('G'):  return( 56 );
                           case('T'):  return( 57 );
                           case('I'):  return( 58 );
                       } 
                   }
                   break;

        case('0'): if( ch2 == 'M' )
                   {   if( ch3 == 'C' )
                       {   return( 33 );
                       } else if( ch3 == 'G' )
                           return( 38 );
                   }
                   break;

        case('1'): if( ch2 == 'M' )
                   {   if( ch3 == 'A' )
                       {   return( 31 );
                       } else if( ch3 == 'G' )
                           return( 34 );
                   }
                   break;

        case('2'): if( ch2 == 'M' )
                   {   if( ch3 == 'G' )
                           return( 35 );
                   }
                   break;

        case('5'): if( ch2 == 'M' )
                   {   if( ch3 == 'C' )
                       {   return( 32 );
                       } else if( ch3 == 'U' )
                           return( 41 );
                   }
                   break;

        case('7'): if( ch2 == 'M' )
                   {   if( ch3 == 'G' )
                           return( 37 );
                   }
                   break;

        case('A'): if( ch2 == 'L' )
                   {   if( ch3 == 'A' )
                           return(  0 );
                   } else if( ch2 == 'S' )
                   {   if( ch3 == 'P' )
                       {   return(  7 );
                       } else if( ch3 == 'N' )
                       {   return(  9 );
                       } else if( ch3 == 'X' )
                           return( 20 );
                   } else if( ch2 == 'R' )
                   {   if( ch3 == 'G' )
                           return( 12 );
                   } else if( ch2 == 'C' )
                   {   if( ch3 == 'E' )
                           return( 44 );
                   } else if( ch2 == 'D' )
                   {   if( ch3 == 'E' )
                           return( 24 );    /* "ADE" -> "  A" */
                   }
                   break;

        case('C'): if( ch2 == 'Y' )
                   {   if( ch3 == 'S' )
                       {   return( 17 );
                       } else if( ch3 == 'H' )
                       {   return( 17 );    /* "CYH" -> "CYS" */
                       } else if( ch3 == 'T' )
                           return( 25 );    /* "CYT" -> "  C" */
                   } else if( ch2 == 'O' )
                   {   if( ch3 == 'A' )
                           return( 51 );
                   } else if( ch2 == 'P' )
                   {   if( ch3 == 'R' )
                           return( 11 );    /* "CPR" -> "PRO" */
                   } else if( ch2 == 'S' )
                   {   if( ch3 == 'H' )
                       {   return( 17 );    /* "CSH" -> "CYS" */
                       } else if( ch3 == 'M' )
                           return( 17 );    /* "CSM" -> "CYS" */
                   }
                   break;

        case('D'): if( ch2 == 'O' )
                   {   if( ch3 == 'D' )
                           return( 47 );
                   } else if( ch2 == '2' )
                   {   if( ch3 == 'O' )
                           return( 47 );    /* "D2O" -> "DOD" */
                   }
                   break;

        case('F'): if( ch2 == 'O' )
                   {   if( ch3 == 'R' )
                           return( 45 );
                   }
                   break;

        case('G'): if( ch2 == 'L' )
                   {   if( ch3 == 'Y' )
                       {   return(  1 );
                       } else if( ch3 == 'U' )
                       {   return( 10 );
                       } else if( ch3 == 'N' )
                       {   return( 14 );
                       } else if( ch3 == 'X' )
                           return( 21 );
                   } else if( ch2 == 'U' )
                   {   if( ch3 == 'A' )
                           return( 26 );    /* "GUA" -> "  G" */
                   }
                   break;

        case('H'): if( ch2 == 'I' )
                   {   if( ch3 == 'S' )
                           return( 16 );
                   } else if( ch2 == 'O' )
                   {   if( ch3 == 'H' )
                           return( 46 );
                   } else if( ch2 == 'Y' )
                   {   if( ch3 == 'P' )
                           return( 23 );
                   } else if( ch2 == '2' )
                   {   if( ch3 == 'O' )
                       {   return( 46 );    /* "H20" -> "HOH" */
                       } else if( ch3 == 'U' )
                           return( 40 );
                   }
                   break;

        case('I'): if( ch2 == 'L' )
                   {   if( ch3 == 'E' )
                           return(  8 );
                   }
                   break;

        case('L'): if( ch2 == 'E' )
                   {   if( ch3 == 'U' )
                           return(  2 );
                   } else if( ch2 == 'Y' )
                   {   if( ch3 == 'S' )
                           return(  6 );
                   }
                   break;

        case('M'): if( ch2 == 'E' )
                   {   if( ch3 == 'T' )
                           return( 18 );
                   } else if( ch2 == '2' )
                   {   if( ch3 == 'G' )
                           return( 36 );
                   }
                   break;

        case('N'): if( ch2 == 'A' )
                   {   if( ch3 == 'D' )
                       {   return( 50 );
                       } else if( ch3 == 'P' )
                           return( 52 );
                   } else if( ch2 == 'D' )
                   {   if( ch3 == 'P' )
                           return( 53 );
                   }
                   break;

        case('P'): if( ch2 == 'R' )
                   {   if( ch3 == 'O' )
                           return( 11 );
                   } else if( ch2 == 'H' )
                   {   if( ch3 == 'E' )
                           return( 13 );
                   } else if( ch2 == 'C' )
                   {   if( ch3 == 'A' )
                           return( 22 );
                   } else if( ch2 == 'O' )
                   {   if( ch3 == '4' )
                           return( 49 );
                   } else if( ch2 == 'S' )
                   {   if( ch3 == 'U' )
                           return( 42 );
                   }
                   break;

        case('S'): if( ch2 == 'E' )
                   {   if( ch3 == 'R' )
                           return(  3 );
                   } else if( ch2 == 'O' )
                   {   if( ch3 == '4' )
                       {   return( 48 );
                       } else if( ch3 == 'L' )
                           return( 46 );    /* "SOL" -> "HOH" */
                   } else if( ch2 == 'U' )
                   {   if( ch3 == 'L' )
                           return( 48 );    /* "SUL" -> "SO4" */
                   }
                   break;

        case('T'): if( ch2 == 'H' )
                   {   if( ch3 == 'R' )
                       {   return(  5 );
                       } else if( ch3 == 'Y' )
                           return( 27 );    /* "THY" -> "  T" */
                   } else if( ch2 == 'Y' )
                   {   if( ch3 == 'R' )
                           return( 15 );
                   } else if( ch2 == 'R' )
                   {   if( ch3 == 'P' )
                       {   return( 19 );
                       } else if( ch3 == 'Y' )
			 return( 19 );    /* "TRY" -> "TRP" */
                   } else if( ch2 == 'I' )
                   {   if( ch3 == 'P' )
                           return( 46 );    /* "TIP" -> "HOH" */
                   }
                   break;

        case('U'): if( ch2 == 'N' )
                   {   if( ch3 == 'K' )
                           return( 43 );
                   } else if( ch2 == 'R' )
                   {   if( ch3 == 'A' )
                       {   return( 28 );    /* "URA" -> "  U" */
                       } else if( ch3 == 'I' )
                           return( 28 );    /* "URI" -> "  U" */
                   }
                   break;

        case('V'): if( ch2 == 'A' )
                   {   if( ch3 == 'L' )
                           return(  4 );
                   }
                   break;

        case('W'): if( ch2 == 'A' )
                   {   if( ch3 == 'T' )
                           return( 46 );    /* "WAT" -> "HOH" */
                   }
                   break;
    }

    for( refno=MINRES; refno<ResNo; refno++ )
        if( !strncasecmp(Residue[refno],ptr,3) )
            return refno;

    if( ResNo++ == MAXRES )
        FatalDataError(MsgStrs[StrXSRes]); /* "Too many new residues" */
    Residue[refno][0] = ch1;
    Residue[refno][1] = ch2;
    Residue[refno][2] = ch3;
    return refno;
}


void ProcessGroup( int heta )
{
    register int serno;

    serno = CurGroup->serno;
    if( IsSolvent(CurGroup->refno) )
        heta = True;

    if( heta )
    {   HetaGroupCount++;
        if( HMinMaxFlag )
        {   if( serno > MaxHetaRes )
            {   MaxHetaRes = serno;
            } else if( serno < MinHetaRes )
                MinHetaRes = serno;
        } else MinHetaRes = MaxHetaRes = serno;
    } else
    {   MainGroupCount++;
        if( MMinMaxFlag )
        {   if( serno > MaxMainRes )
            {   MaxMainRes = serno;
            } else if( serno < MinMainRes )
                MinMainRes = serno;
        } else MinMainRes = MaxMainRes = serno;
    }
    if (CurGroup->model && !(MaxModel)){
      MaxModel = MinModel = CurGroup->model;
    }
    if (CurGroup->model > MaxModel) MaxModel = CurGroup->model;
    if (CurGroup->model < MinModel) MinModel = CurGroup->model;
}


void CreateMolGroup( void )
{
    strcpy(Info.filename,DataFileName);

    CreateChain( ' ' );
    CreateGroup( 1 );

    CurGroup->refno = FindResNo( "MOL" );
    CurGroup->serno = 1;
        
    MinMainRes = MaxMainRes = 1;
    MinHetaRes = MaxHetaRes = 0;
    MainGroupCount = 1;
}


void CreateNextMolGroup( void )
{
    if( CurGroup->alist )
    {   CreateChain(' ');
        CreateGroup(1);
        MainGroupCount++;
        CurGroup->refno = FindResNo( "MOL" );
        CurGroup->serno = MainGroupCount;
        MaxMainRes++;
    }
}



/*=========================*/
/* Atom Handling Functions */
/*=========================*/

RAtom __far *CreateAtom( void )
{
    register RAtom __far *ptr;
    register int i;

    if( !(ptr = FreeAtom) )
    {   MemSize += AtomPool*sizeof(RAtom);
        ptr = (RAtom __far *)_fmalloc( AtomPool*sizeof(RAtom) );
        if( !ptr ) FatalDataError(MsgStrs[StrMalloc]);
        RegisterAlloc( ptr );
        for( i=1; i<AtomPool; i++ )
        {   ptr->anext = FreeAtom;
            FreeAtom = ptr++;
        } 
    } else FreeAtom = ptr->anext;

    if( CurAtom )
    {   ptr->anext = CurAtom->anext;
        CurAtom->anext = ptr;
    } else 
    {   ptr->anext = CurGroup->alist;
        CurGroup->alist = ptr;
    }
    CurAtom = ptr;

    SelectCount++;
    ptr->flag = SelectFlag | NonBondFlag;
    ptr->label = (void*)0;
    ptr->radius = 375;
    ptr->altl = ' ';
    ptr->mbox = 0;
    ptr->col = 0;
    ptr->model = 0;
    ptr->xtrl = 0;
    ptr->ytrl = 0;
    ptr->ztrl = 0;
    ptr->fxorg = 0;
    ptr->fyorg = 0;
    ptr->fzorg = 0;
    return ptr;
}


void ProcessAtomType( RAtom __far *ptr, char etype[2] )
{
    int altc;

    if ((etype[0]==' '&&etype[1]==' ')|| isdigit(etype[0]) || isdigit(etype[1]))
      ptr->elemno = GetElemNumber(CurGroup,ptr);
    else
      ptr->elemno = GetElemDescNumber(etype);
    if( ptr->elemno == 1 )
    {   ptr->flag |= HydrogenFlag;
        HasHydrogen = True;
    }

    if( !IsSolvent(CurGroup->refno) )
    {   if( !(ptr->flag&(HydrogenFlag|HeteroFlag)) )
            ptr->flag |= NormAtomFlag;
    } else ptr->flag |= HeteroFlag;

#ifdef INVERT
    ptr->yorg = -ptr->yorg;
    ptr->ytrl = -ptr->ytrl;
#endif

    ptr->fxorg = 0;
    ptr->fyorg = 0;
    ptr->fzorg = 0;

    if( HMinMaxFlag || MMinMaxFlag )
    {   if( ptr->xorg < MinX ) 
        {   MinX = ptr->xorg;
        } else if( ptr->xorg > MaxX ) 
            MaxX = ptr->xorg;

        if( ptr->yorg < MinY ) 
        {   MinY = ptr->yorg;
        } else if( ptr->yorg > MaxY ) 
            MaxY = ptr->yorg;

        if( ptr->zorg < MinZ ) 
        {   MinZ = ptr->zorg;
        } else if( ptr->zorg > MaxZ ) 
            MaxZ = ptr->zorg;
    } else 
    {   MinX = MaxX = ptr->xorg;
        MinY = MaxY = ptr->yorg;
        MinZ = MaxZ = ptr->zorg;
    }
            
    if( ptr->flag & HeteroFlag )
    {   if( HMinMaxFlag )
        {   if( ptr->temp < MinHetaTemp ) 
            {   MinHetaTemp = ptr->temp;
            } else if( ptr->temp > MaxHetaTemp ) 
                MaxHetaTemp = ptr->temp;
        } else MinHetaTemp = MaxHetaTemp = ptr->temp;
        HMinMaxFlag = True;
        HetaAtomCount++;
    } else
    {   if( MMinMaxFlag )
        {   if( ptr->temp < MinMainTemp ) 
            {   MinMainTemp = ptr->temp;
            } else if( ptr->temp > MaxMainTemp ) 
                MaxMainTemp = ptr->temp;
        } else MinMainTemp = MaxMainTemp = ptr->temp;
        MMinMaxFlag = True;
        MainAtomCount++;
    }

    if ( ptr->altl != '\0' && ptr->altl != ' ')
    {
        altc = (((int)ptr->altl)&(AltlDepth-1))+1;
        if (MaxAltl < altc) MaxAltl = altc;
    }
}

void ProcessAtom ( RAtom __far *ptr ) {
  ProcessAtomType( ptr, "  ");
  return;
}


RAtom __far *FindGroupAtom( Group __far *group, int n )
{
    register RAtom __far *ptr;

    for( ptr=group->alist; ptr; ptr=ptr->anext )
        if( ptr->refno == n ) return( ptr );
    return( (RAtom __far*)0 );
}


int NewAtomType( char *ptr )
{
    register int refno;
    register int i;

    for( refno=0; refno<ElemNo; refno++ )
        if( !strncasecmp(ElemDesc[refno],ptr,12) )
            return refno;

    if( ElemNo++ == MAXELEM )
        FatalDataError(MsgStrs[StrXSAtyp]);  /* "Too many new atom types" */

    for( i=0; i<12; i++ )
        ElemDesc[refno][i] = '\0';
    for( i=0; ptr[i]&&i<12; i++)
        ElemDesc[refno][i] = ptr[i];
    return refno;
}


int SimpleAtomType( char *type )
{
    char name[5];

    name[2] = name[3] = ' ';
    name[4] = '\0';
    if( type[1] && (type[1]!=' ') )
    {   name[0] = ToUpper(type[0]);
        name[1] = ToUpper(type[1]);
    } else
    {   name[1] = ToUpper(type[0]);
        name[0] = ' ';
    }
    return NewAtomType(name);
}


int ComplexAtomType( char *ptr )
{
    char name[5];
    register int i;

    name[4] ='\0';
    if( isdigit(ptr[1]) )
    {   /* IDATM PDB files! */
        name[0] = ' ';
        name[1] = ToUpper(ptr[0]);
        name[2] = ToUpper(ptr[1]);
        name[3] = ToUpper(ptr[2]);
    } else if( ptr[1] == ' ' )
    {   /* Corina PDB files! */
        name[0] = ' ';
        name[1] = ToUpper(ptr[0]);
        name[2] = ToUpper(ptr[2]);
        name[3] = ToUpper(ptr[3]);
    } else for( i=0; i<4; i++ )
        name[i] = ToUpper(ptr[i]);

    /* Handle Unconventional Naming */
    if( IsProtein(CurGroup->refno) )
    {   if( name[0]=='H' )
        {   name[0]=' ';
            name[1]='H';
        }
    } else if( IsNucleo(CurGroup->refno) )
    {   if( name[3]=='\'' )
            name[3] = '*';

        if( (name[1]=='O') && (name[2]=='P') )
        {   if( !strncmp(name," OP1",4) ||
                !strncmp(name,"1OP ",4) )
                return( 8 );
            if( !strncmp(name," OP2",4) ||
                !strncmp(name,"2OP ",4) )
                return( 9 );
        }
    }
    return NewAtomType(name);
}



/*===============================*/
/* Z-Matrix Conversion Functions */
/*===============================*/

void InitInternalCoords( void )
{
    IntList = (IntCoord __far*)0;
    IntPrev = (IntCoord __far*)0;
}


IntCoord __far* AllocInternalCoord( void )
{
    register IntCoord __far *ptr;

    ptr = (IntCoord __far*)_fmalloc(sizeof(IntCoord));
    if( !ptr ) FatalDataError(MsgStrs[StrMalloc]);
    ptr->inext = (IntCoord __far*)0;

    if( IntPrev )
    {   IntPrev->inext = ptr;
    } else IntList = ptr;
    IntPrev = ptr;
    return( ptr );
}


static IntCoord __far* GetInternalCoord( int index )
{
    register IntCoord __far *ptr;

    ptr = IntList;
    while( (index>1) && ptr->inext )
    {   ptr = ptr->inext;
        index--;
    }
    return ptr;
}


void FreeInternalCoords( void )
{
    register IntCoord __far *ptr;

    while( IntList )
    {    ptr = IntList;
         IntList = ptr->inext;
         _ffree( ptr );
    }
}


int ConvertInternal2Cartesian( void )
{
    register IntCoord __far *ptr;
    register IntCoord __far *na;
    register IntCoord __far *nb;
    register IntCoord __far *nc;
    register double cosph,sinph,costh,sinth,coskh,sinkh;
    register double cosa,sina,xcosd,xsind;
    register double dist,angle,dihed;

    register double xpd,ypd,zpd,xqd,yqd,zqd;
    register double xa,ya,za,xb,yb,zb;
    register double rbc,xyb,yza,temp;
    register double xpa,ypa,zqa;
    register double xd,yd,zd;
    register int flag;

    /* Atom #1 */
    ptr = IntList;
    ptr->dist  = 0.0;
    ptr->angle = 0.0;
    ptr->dihed = 0.0;

    ptr = ptr->inext;
    if( !ptr ) return( True );

    /* Atom #2 */
    ptr->angle = 0.0;
    ptr->dihed = 0.0;

    ptr = ptr->inext;
    if( !ptr ) return( True );

    /* Atom #3 */
    dist = ptr->dist;
    angle = Deg2Rad*ptr->angle;
    cosa = cos(angle);
    sina = sin(angle);
    if( ptr->na == 1 )
    {   na = IntList;
        ptr->dist = na->dist + cosa*dist;
    } else /* ptr->na == 2 */
    {   na = IntList->inext;
        ptr->dist = na->dist - cosa*dist;
    }
    ptr->angle = sina*dist;
    ptr->dihed = 0.0;

    while( ptr->inext )
    {   ptr = ptr->inext;
        dist = ptr->dist;
        angle = Deg2Rad*ptr->angle;
        dihed = Deg2Rad*ptr->dihed;

        /* Optimise this access?? */
        na = GetInternalCoord(ptr->na);
        nb = GetInternalCoord(ptr->nb);
        nc = GetInternalCoord(ptr->nc);

        xb = nb->dist  - na->dist;
        yb = nb->angle - na->angle;
        zb = nb->dihed - na->dihed;

        rbc = xb*xb + yb*yb + zb*zb;
        if( rbc < 0.0001 )
            return( False );
        rbc= 1.0/sqrt(rbc);

        cosa = cos(angle);
        sina = sin(angle);


        if( fabs(cosa) >= 0.999999 )
        {   /* Colinear */
            temp = dist*rbc*cosa;
            ptr->dist  = na->dist  + temp*xb;
            ptr->angle = na->angle + temp*yb;
            ptr->dihed = na->dihed + temp*zb;
        } else
        {   xa = nc->dist  - na->dist;
            ya = nc->angle - na->angle;
            za = nc->dihed - na->dihed;

            xsind = -sin(dihed);
            xcosd = cos(dihed);

            xd = dist*cosa;
            yd = dist*sina*xcosd;
            zd = dist*sina*xsind;

            xyb = sqrt(xb*xb + yb*yb);
            if( xyb < 0.1 )
            {   /* Rotate about y-axis! */
                temp = za; za = -xa; xa = temp;
                temp = zb; zb = -xb; xb = temp;
                xyb = sqrt(xb*xb + yb*yb);
                flag = True;
            } else flag = False;

            costh = xb/xyb;
            sinth = yb/xyb;
            xpa = costh*xa + sinth*ya;
            ypa = costh*ya - sinth*xa;

            sinph = zb*rbc;
            cosph = sqrt(1.0 - sinph*sinph);
            zqa = cosph*za  - sinph*xpa;

            yza = sqrt(ypa*ypa + zqa*zqa);

            if( yza > 1.0E-10 )
            {   coskh = ypa/yza;
                sinkh = zqa/yza;

                ypd = coskh*yd - sinkh*zd;
                zpd = coskh*zd + sinkh*yd;
            } else
            {   /* coskh = 1.0; */
                /* sinkh = 0.0; */
                ypd = yd;
                zpd = zd;
            }

            xpd = cosph*xd  - sinph*zpd;
            zqd = cosph*zpd + sinph*xd;
            xqd = costh*xpd - sinth*ypd;
            yqd = costh*ypd + sinth*xpd;

            if( flag )
            {   /* Rotate about y-axis! */
                ptr->dist  = na->dist  - zqd;
                ptr->angle = na->angle + yqd;
                ptr->dihed = na->dihed + xqd;
            } else
            {   ptr->dist  = na->dist  + xqd;
                ptr->angle = na->angle + yqd;
                ptr->dihed = na->dihed + zqd;
            }
        }
    }
    return True;
}



/*=========================*/
/* Bond Handling Functions */
/*=========================*/

Bond __far *ProcessBond( RAtom __far *src, RAtom __far *dst, int flag )
{
    register Bond __far *ptr;
    register int i;

    if( flag & (DoubBondFlag|TripBondFlag) )
        DrawDoubleBonds = True;

    if( !(ptr = FreeBond) )
    {   MemSize += BondPool*sizeof(Bond);
        ptr = (Bond __far *)_fmalloc( BondPool*sizeof(Bond) );
        if( !ptr ) FatalDataError(MsgStrs[StrMalloc]);
        RegisterAlloc( ptr );
        for( i=1; i<BondPool; i++ )
        {   ptr->bnext = FreeBond;
            FreeBond = ptr++;
        } 
    } else FreeBond = ptr->bnext;

    ptr->flag = flag | SelectFlag;
    ptr->srcatom = src;
    ptr->dstatom = dst;
    ptr->radius = 0;
    ptr->irad = 0;
    ptr->aradius = 0;
    ptr->iarad = 0;
    ptr->col = 0;

    ptr->altl = '\0';
    if (src && src->altl != '\0' && src->altl != ' ') ptr->altl = src->altl;
    if (dst && dst->altl != '\0' && dst->altl != ' ') ptr->altl = dst->altl;

    return ptr;
}
SurfBond __far *ProcessSurfBond( RAtom __far *src, RAtom __far *dst )
{
    register SurfBond __far *ptr;
    register int i;
    register Long lx, ly, lz, lxyzsq;
    register Long xrad1, xrad2, wpsq;

    DrawSurf = True;

    if( !(ptr = FreeSurfBond) )
    {   MemSize += BondPool*sizeof(SurfBond);
        ptr = (SurfBond __far *)_fmalloc( BondPool*sizeof(SurfBond) );
        if( !ptr ) FatalDataError(MsgStrs[StrMalloc]);
        RegisterAlloc( ptr );
        for( i=1; i<BondPool; i++ )
        {   ptr->sbnext = FreeSurfBond;
            FreeSurfBond = ptr++;
        } 
    } else FreeSurfBond = ptr->sbnext;

    ptr->srcatom = src;
    ptr->dstatom = dst;
    ptr->col = 0;

    ptr->altl = '\0';
    if (src && src->altl != '\0' && src->altl != ' ') ptr->altl = src->altl;
    if (dst && dst->altl != '\0' && dst->altl != ' ') ptr->altl = dst->altl;
    lx = src->xorg+src->fxorg-dst->xorg-dst->fxorg;
    ly = src->yorg+src->fyorg-dst->yorg-dst->fyorg;
    lz = src->zorg+src->fzorg-dst->zorg-dst->fzorg;
    lxyzsq = lx*lx + ly*ly + lz*lz;
    ptr->sxyz = (Long)(sqrt((double)lxyzsq)+.5);
    xrad1 = src->radius;
    xrad2 = dst->radius;
    ptr->u1 = ((ptr->sxyz)+
      (((((xrad1+xrad2+(ProbeRadius+ProbeRadius))*
      (xrad1-xrad2)))/ptr->sxyz))+1)>>1;
    /* if (ptr->u1 > ptr->sxyz) ptr->u1 = ptr->sxyz; */
    ptr->u2 = ptr->sxyz-ptr->u1;
    wpsq = ((((xrad1+ProbeRadius))*((xrad1+ProbeRadius))))
      -ptr->u1*ptr->u1;
    if (wpsq < 0 ) wpsq = 0;
    ptr->wp = (Long)rint(sqrt((double)wpsq));
    ptr->t1 = (ptr->u1*xrad1)/(xrad1+ProbeRadius);
    ptr->t2 = (ptr->u2*xrad2)/(xrad2+ProbeRadius);
    ptr->w1 = (ptr->wp*xrad1)/(xrad1+ProbeRadius);
    ptr->w2 = (ptr->wp*xrad2)/(xrad2+ProbeRadius);
    return ptr;
}

static void CreateHydrogenBond( RAtom __far *srcCA, RAtom __far *dstCA,
                                RAtom __far *src, RAtom __far *dst,
                                int energy, int offset )
{
    register HBond __far *ptr;
    register int i,flag;

    if( !(ptr = FreeHBond) )
    {   MemSize += HBondPool*sizeof(HBond);
        ptr = (HBond __far *)_fmalloc( HBondPool*sizeof(HBond) );
        if( !ptr ) FatalDataError(MsgStrs[StrMalloc]);
        RegisterAlloc( ptr );
        for( i=1; i<HBondPool; i++ )
        {   ptr->hnext = FreeHBond;
            FreeHBond = ptr++;
        } 
    } else FreeHBond = ptr->hnext;

    if( (offset>=-128) && (offset<127) )
    {   ptr->offset = (Char)offset;
    } else ptr->offset = 0;

    flag = ZoneBoth? src->flag&dst->flag : src->flag|dst->flag;
    ptr->flag = flag & SelectFlag;

    ptr->src = src;
    ptr->dst = dst;
    ptr->srcCA = srcCA;
    ptr->dstCA = dstCA;
    ptr->energy = energy;
    ptr->col = 0;

    ptr->altl = '\0';
    if (src && src->altl != '\0' && src->altl != ' ') ptr->altl = src->altl;
    if (dst && dst->altl != '\0' && dst->altl != ' ') ptr->altl = dst->altl;

    *CurHBond = ptr;
    ptr->hnext = (void __far*)0;
    CurHBond = &ptr->hnext;
    Info.hbondcount++;
}


static RAtom __far *LocateAtom( Long serno, int flag )
{
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *aptr;

    if( Cache )
    {   for( aptr=ACache; aptr; aptr=aptr->anext )
            if( aptr->serno == serno )
            {   ACache = aptr;
                return( aptr );
            }

        for( aptr=Cache->alist; aptr != ACache; aptr=aptr->anext )
            if( aptr->serno == serno )
            {   ACache = aptr;
                return( aptr );
            }

        if( Cache->gnext )
            for( aptr=Cache->gnext->alist; aptr; aptr=aptr->anext )
                if( aptr->serno == serno )
                {   if( flag )
                    {   Cache = Cache->gnext;
                        ACache = aptr;
                    }
                    return( aptr );
                }
    }

    if( CurChain )
    {   for( group=CurChain->glist; group; group=group->gnext )
            for( aptr=group->alist; aptr; aptr=aptr->anext )
                if( aptr->serno == serno )
                {   Cache = group;
                    ACache = aptr;
                    return( aptr );
                }
    }

    for( chain=Database->clist; chain; chain=chain->cnext )
        if( chain != CurChain )
            for( group=chain->glist; group; group=group->gnext )
                for( aptr=group->alist; aptr; aptr=aptr->anext )
                    if( aptr->serno == serno )
                    {   Cache = group;
                        ACache = aptr;
                        return( aptr );
                    }

    return (RAtom __far*)0;
}


void CreateBond( Long src, Long dst, int flag )
{
    register RAtom __far *sptr;
    register RAtom __far *dptr;
    register Bond __far *bptr;

    NewBond = NULL;

    if( src == dst )
        return;

    sptr = LocateAtom(src,False);  if( !sptr ) return;
    dptr = LocateAtom(dst,False);  if( !dptr ) return;

    if( flag != HydrBondFlag )
    {   /* Reset Non-bonded flags! */
        sptr->flag &= ~NonBondFlag;
        dptr->flag &= ~NonBondFlag;

        bptr = ProcessBond( sptr, dptr, flag );
        bptr->bnext = CurMolecule->blist;
        CurMolecule->blist = bptr;
        Info.bondcount++;
        NewBond = bptr;

    } else /* Hydrogen Bond! */
    {   if( Info.hbondcount < 0 ) 
        {   CurHBond = &CurMolecule->hlist;
            Info.hbondcount = 0;
        }
        CreateHydrogenBond( NULL, NULL, sptr, dptr, 0, 0 );
    }
}


void CreateBondOrder( Long src, Long dst )
{
    register RAtom __far *sptr;
    register RAtom __far *dptr;
    register Bond __far *bptr;

    if( src == dst )
        return;

    sptr = LocateAtom(src,True);  if( !sptr ) return;
    dptr = LocateAtom(dst,False); if( !dptr ) return;

    if( !(sptr->flag&NonBondFlag) && !(dptr->flag&NonBondFlag) )
    {   ForEachBond
            if( ((bptr->srcatom==sptr)&&(bptr->dstatom==dptr)) || 
                ((bptr->srcatom==dptr)&&(bptr->dstatom==sptr)) )
            {   DrawDoubleBonds = True;
                if( bptr->flag & NormBondFlag )
                {  /* Convert Single to Double */
                   bptr->flag &= ~(NormBondFlag);
                   bptr->flag |= DoubBondFlag;
                } else if( bptr->flag & DoubBondFlag )
                {  /* Convert Double to Triple */
                   bptr->flag &= ~(DoubBondFlag);
                   bptr->flag |= TripBondFlag;
                }
                return;
            }
    }

    /* Reset Non-bonded flags! */
    sptr->flag &= ~NonBondFlag;
    dptr->flag &= ~NonBondFlag;

    bptr = ProcessBond( sptr, dptr, NormBondFlag );
    bptr->bnext = CurMolecule->blist;
    CurMolecule->blist = bptr;
    bptr->flag |= DashFlag;
    Info.bondcount++;
}

void CreateNewBond (Long src, Long dst )
{
    register Bond __far *bptr;
    register Long bs,bd;

    ForEachBond
    {   bs = bptr->srcatom->serno;
        bd = bptr->dstatom->serno;

        if( ((bs==src)&&(bd==dst)) || ((bs==dst)&&(bd==src)) )
                   return;
    }
    CreateBond( src, dst, NormBondFlag );
}

/* PreTestSurface
      sptr -- pointer to source atom
	  dptr -- pointer to destination atom
	  C    -- an array to receive the center of the
	          intersection circle of the probe-radius
		      extended atoms
	  crad -- pointer to the radius of the intersection
	          circle of the probe-radius extended
			  atoms
	  Un   -- an array of the normalized axis from
	          sptr to dptr, scaled by 4096 (2**12)
	  
	  returns -- 
	          -1 if the atoms are too far apart for
			     the probe to touch
			   0 if the atoms can be touched by the
			     probe, but do not overlap
			   1 if the atoms overlap (centers
				 within half the average of the radii)
 */


static int PreTestSurface(  RAtom __far *sptr,  RAtom __far *dptr, 
      Long C[3],  int *crad, Long Un[3] )
{
    register Long dx, dy, dz;
    register Long maxS, maxT, dist;
    register int srad,drad;
	Long lx, ly, lz, lxyzsq, sxyz, u1, rat, wpsq;

    if ( !(sptr->model == dptr->model) ) return -1;
    if ( !(sptr->altl == ' ' || sptr->altl == '\0') &&
         !(dptr->altl == ' ' || dptr->altl == '\0') &&
         !(sptr->altl == dptr->altl) ) return -1;
    srad = sptr->radius;
    drad = dptr->radius;
    if (srad < 10 ) srad = Element[sptr->elemno].vdwrad;
    if (drad < 10 ) drad = Element[dptr->elemno].vdwrad;
    
    /* Sum of van der Waals radii */
	dist = srad + drad;
	maxT = dist*dist/16;
    dist += ProbeRadius+ProbeRadius;
    maxS = dist*dist;  
    
    dx = sptr->xorg-dptr->xorg 
         + sptr->fxorg-dptr->fxorg;   if( (dist=dx*dx)>=maxS ) return -1;
    dy = sptr->yorg-dptr->yorg
         + sptr->fyorg-dptr->fyorg;   if( (dist+=dy*dy)>=maxS ) return -1;
    dz = sptr->zorg-dptr->zorg
         + sptr->fzorg-dptr->fzorg;   if( (dist+=dz*dz)>=maxS ) return -1;

	lx = sptr->xorg+sptr->fxorg-dptr->xorg-dptr->fxorg;
    ly = sptr->yorg+sptr->fyorg-dptr->yorg-dptr->fyorg;
    lz = sptr->zorg+sptr->fzorg-dptr->zorg-dptr->fzorg;
    lxyzsq = lx*lx + ly*ly + lz*lz;
    sxyz = (Long)(sqrt((double)lxyzsq)+.5);
    u1 = (sxyz+
      (((((srad+drad+(ProbeRadius+ProbeRadius))*
      (srad-drad)))/sxyz))+1)>>1;
	rat = (4096*u1)/sxyz;
	C[0] = (rat*(sptr->xorg+sptr->fxorg)+(4096-rat)*(dptr->xorg+dptr->fxorg))/4096;
	C[1] = (rat*(sptr->yorg+sptr->fyorg)+(4096-rat)*(dptr->yorg+dptr->fyorg))/4096;
	C[2] = (rat*(sptr->zorg+sptr->fzorg)+(4096-rat)*(dptr->zorg+dptr->fzorg))/4096;
    wpsq = ((((srad+ProbeRadius))*((srad+ProbeRadius))))
      -u1*u1;
    if (wpsq < 0 ) wpsq = 0;
    *crad = (Long)rint(sqrt((double)wpsq));
	Un[0] = -(lx*4096)/sxyz;
	Un[1] = -(ly*4096)/sxyz;
	Un[2] = -(lz*4096)/sxyz;

	if (dist > maxT ) return 0;
	return 1;	

}


static void TestSurface(  RAtom __far *sptr,  RAtom __far *dptr )
{
    register SurfBond __far *sbptr;
    register Long dx, dy, dz;
    register Long maxS, dist;
    register int srad,drad;

    if ( !(sptr->model == dptr->model) ) return;
    if ( !(sptr->altl == ' ' || sptr->altl == '\0') &&
         !(dptr->altl == ' ' || dptr->altl == '\0') &&
         !(sptr->altl == dptr->altl) ) return;
    srad = sptr->radius;
    drad = dptr->radius;
    if (srad < 10 ) srad = Element[sptr->elemno].vdwrad;
    if (drad < 10 ) drad = Element[dptr->elemno].vdwrad;
    
    /* Sum of van der Walls radii */
    dist = srad + drad + ProbeRadius+ProbeRadius;
    maxS = dist*dist;  
    
    dx = sptr->xorg-dptr->xorg 
         + sptr->fxorg-dptr->fxorg;   if( (dist=dx*dx)>=maxS ) return;
    dy = sptr->yorg-dptr->yorg
         + sptr->fyorg-dptr->fyorg;   if( (dist+=dy*dy)>=maxS ) return;
    dz = sptr->zorg-dptr->zorg
         + sptr->fzorg-dptr->fzorg;   if( (dist+=dz*dz)>=maxS ) return;

    if( dist > (srad+drad-ProbeRadius)*(srad+drad-ProbeRadius) )
    {   /* Reset Non-bonded flags! */
        sptr->flag &= ~NonBondFlag;
        dptr->flag &= ~NonBondFlag;

        sbptr = ProcessSurfBond(sptr,dptr);
        sbptr->sbnext = CurMolecule->sblist;
        CurMolecule->sblist = sbptr;
        Info.srfbondcount++;
    }
}

/*
    TestBuriedSurface
	    aprt -- pointer to one atom of the pair being checked
		dprt -- pointer to the other atom of the par being checked
		eptr -- an atom that might bury the surface bond
		C    -- the center of the circle at the neck of the surface bond
		crad -- the radius of the orbit of the probe center around C
		Un   -- the unit normal *4096 of the axis of the surface bond
 */

static int TestBuriedSurface( RAtom __far *aptr, RAtom __far *dptr, RAtom __far *eptr, 
                              Long C[3], int crad, Long Un[3]) { 

 
	register Long dx, dy, dz;
    register Long maxS, dist, dec, decun;
    register int erad;
	Long ECxUn[3];

    if ( eptr->model != aptr->model ) return -1; /* different models cannot bury each other */
    if ( ( eptr->altl != ' ' && aptr->altl != ' ' && eptr->altl != aptr->altl) ||
	     ( eptr->altl != ' ' && dptr->altl != ' ' && eptr->altl != dptr->altl) ) return -1;
    erad = eptr->radius;
    if (erad < 10 ) erad = Element[eptr->elemno].vdwrad;
    
    /* Sum of van der Walls radii */
    dist = erad + crad + ProbeRadius;
    maxS = dist*dist;  
    
    dx = eptr->xorg-C[0] 
         + eptr->fxorg;   if( (dist=dx*dx)>=maxS ) return -1;
    dy = eptr->yorg-C[1]
         + eptr->fyorg;   if( (dist+=dy*dy)>=maxS ) return -1;
    dz = eptr->zorg-C[2]
         + eptr->fzorg;   if( (dist+=dz*dz)>=maxS ) return -1;

    /* Compute the cross product of (E-C)XUn  */
    ECxUn[0] = dy*Un[2]-dz*Un[1];
	ECxUn[1] = dz*Un[0]-dx*Un[2];
	ECxUn[2] = dx*Un[1]-dy*Un[0];
	
	/* Compute the hypotenuse */
	
	dec = (Long)(rint(4096*sqrt((double)dist)));
	decun = (Long)(rint(sqrt((double)(ECxUn[0]*ECxUn[0] + ECxUn[1]*ECxUn[1] + ECxUn[2]*ECxUn[2]))));
	dist += crad*crad + (2*crad*decun)/dec;
	/* fprintf(stderr,"TBS E-C = {%ld,%ld,%ld} C={%ld,%ld,%ld}, re=%d, wp=%d, c=%ld,a=%ld,h=%d\n",
	      dx, dy, dz, C[0],C[1],C[2],erad+ProbeRadius, crad, dec/4096,crad*decun/dec,
		  (int)sqrt((double)dist)); */
	if (dist < (erad+ProbeRadius)*(erad+ProbeRadius)) return 0;
    
    return 1;
} 


static void TestBonded(  RAtom __far *sptr,  RAtom __far *dptr, int flag )
{
    register Bond __far *bptr;
    register Long dx, dy, dz;
    register Long max, dist;

    if ( !(sptr->model == dptr->model) ) return;
    if ( !(sptr->altl == ' ' || sptr->altl == '\0') &&
         !(dptr->altl == ' ' || dptr->altl == '\0') &&
         !(sptr->altl == dptr->altl) ) return;
    if( flag )
    {    /* Sum of covalent radii with 0.56A tolerance */
         dist = Element[sptr->elemno].covalrad + 
                Element[dptr->elemno].covalrad + 140;
         max = dist*dist;  
    } else 
    {    /* Fast Bio-Macromolecule Bonding Calculation */
         if( (sptr->flag|dptr->flag) & HydrogenFlag )
         {      max = MaxHBondDsq;
         } else max = MaxBondDsq;
    }
    
    dx = sptr->xorg-dptr->xorg 
         + sptr->fxorg-dptr->fxorg;   if( (dist=dx*dx)>max ) return;
    dy = sptr->yorg-dptr->yorg
         + sptr->fyorg-dptr->fyorg;   if( (dist+=dy*dy)>max ) return;
    dz = sptr->zorg-dptr->zorg
         + sptr->fzorg-dptr->fzorg;   if( (dist+=dz*dz)>max ) return;

    if( dist > MinBondDsq )
    {   /* Reset Non-bonded flags! */
        sptr->flag &= ~NonBondFlag;
        dptr->flag &= ~NonBondFlag;

        bptr = ProcessBond(sptr,dptr,NormBondFlag);
        bptr->bnext = CurMolecule->blist;
        CurMolecule->blist = bptr;
        Info.bondcount++;
    }
}


static void ReclaimHBonds( HBond __far *ptr )
{
    register HBond __far *temp;

    if( ptr )
    {   temp = ptr;
        while( temp->hnext )
            temp=temp->hnext;
        temp->hnext = FreeHBond;
        FreeHBond = ptr;
    }
}
static void ReclaimSurfBonds( Molecule __far *Mol)
{
    register SurfBond __far *ptr;
    register SurfBond __far *temp;

    ptr = Mol->sblist;

    if( ptr )
    {   temp = ptr;
        while( temp->sbnext )
            temp=temp->sbnext;
        temp->sbnext = FreeSurfBond;
        FreeSurfBond = ptr;
    }
    Mol->sblist = (SurfBond __far*)0;
}


static void ReclaimBonds( Molecule __far *Mol)
{
    register Bond __far *ptr;
    register Bond __far *temp;
    ptr = Mol->blist;

    if( ptr )
    {   temp = ptr;
        while( temp->bnext )
            temp=temp->bnext;
        temp->bnext = FreeBond;
        FreeBond = ptr;
    }
    Mol->blist = (Bond __far*)0;
}

static void ReclaimChainBonds( Chain __far *Chn)
{
    register Bond __far *ptr;
    register Bond __far *temp;
    ptr = Chn->blist;

    if( ptr )
    {   temp = ptr;
        while( temp->bnext )
            temp=temp->bnext;
        temp->bnext = FreeBond;
        FreeBond = ptr;
    }
    Chn->blist = (Bond __far*)0;
}


static Bond __far *ExtractBonds( Bond __far *ptr )
{
    register RAtom __far *src;
    register RAtom __far *dst;
    register Long dx, dy, dz;
    register Long max, dist;
    register Bond __far *result;
    register Bond __far *temp;

    result = (Bond __far*)0;

    while( ptr )
    {   temp = ptr;
        src = ptr->srcatom;
        dst = ptr->dstatom;

        ptr = temp->bnext;
        dist = Element[src->elemno].covalrad + 
                Element[dst->elemno].covalrad + 140;

        max = dist*dist;  
        dx = src->xorg-dst->xorg
             + src->fxorg-dst->fxorg; dist = dx*dx;
        if (!(dist > max)) {
          dy = src->yorg-dst->yorg
               + src->fyorg-dst->fyorg; dist += dy*dy;
        }
        if (!(dist > max)) {
          dz = src->zorg-dst->zorg
               + src->fzorg-dst->fzorg; dist += dz*dz;
        }

        if( ((temp->flag & NormBondFlag) &&  !(dist > max)))
        {   temp->bnext = FreeBond;
            FreeBond = temp;
        } else /* Long or Double or Triple or Aromatic */
        {   temp->bnext = result;
            result = temp;
        }
    }
    return result;
}


static void InsertBonds( Bond __far **list,  Bond __far *orig )
{
    register RAtom __far *src;
    register RAtom __far *dst;
    register Bond __far *temp;
    register Bond __far *ptr;

    while( orig )
    {   ptr = orig;
        orig = ptr->bnext;
        src = ptr->srcatom;
        dst = ptr->dstatom;
        for( temp = *list; temp; temp=temp->bnext )
            if( ((temp->srcatom==src)&&(temp->dstatom==dst)) ||
                ((temp->srcatom==dst)&&(temp->dstatom==src)) )
                break;

        if( temp )
        {   temp->flag = ptr->flag;
            ptr->bnext = FreeBond;
            FreeBond = ptr;
        } else
        {   ptr->bnext = *list;
            *list = ptr;
        }
    }
}


void CreateMoleculeBonds( int info, int flag, int force )
{
    register int i, x, y, z;
    register Long tx, ty, tz;
    register Long mx, my, mz; 
    register Long dx, dy, dz;
    register int lx, ly, lz, ux, uy, uz;
    register RAtom __far *aptr, __far *dptr;
    register Chain __far *chain;
    register Group __far *group;
    register Bond __far *list;
    char buffer[40];

    if( !Database ) 
        return;

    dx = (MaxX-MinX)+1;
    dy = (MaxY-MinY)+1;
    dz = (MaxZ-MinZ)+1;

    /* Save Explicit Long, Double and Triple Bonds on File Load */
    list = (Bond __far*)0;
    if (!force) {
      list = ExtractBonds( CurMolecule->blist );
    }
     /* else {
      ReclaimBonds (CurMolecule);
    } */
    CurMolecule->blist = (Bond __far*)0;
    Info.bondcount = 0;

    ResetVoxelData();

    for( chain=Database->clist; chain; chain=chain->cnext )
    {  /*  ResetVoxelData(); */
        for( group=chain->glist; group; group=group->gnext )
            for( aptr=group->alist; aptr; aptr=aptr->anext )
            {   /* Initially non-bonded! */
                aptr->flag |= NonBondFlag;

                mx = aptr->xorg + aptr->fxorg - MinX;
                my = aptr->yorg + aptr->fyorg - MinY;
                mz = aptr->zorg + aptr->fzorg - MinZ;

                tx = mx-AbsMaxBondDist;  
                ty = my-AbsMaxBondDist;  
                tz = mz-AbsMaxBondDist;  

                lx = (tx>0)? (int)((VOXORDER*tx)/dx) : 0;
                ly = (ty>0)? (int)((VOXORDER*ty)/dy) : 0;
                lz = (tz>0)? (int)((VOXORDER*tz)/dz) : 0;

                tx = mx+AbsMaxBondDist;  
                ty = my+AbsMaxBondDist;  
                tz = mz+AbsMaxBondDist;

                ux = (tx<dx)? (int)((VOXORDER*tx)/dx) : VOXORDER-1;
                uy = (ty<dy)? (int)((VOXORDER*ty)/dy) : VOXORDER-1;
                uz = (tz<dz)? (int)((VOXORDER*tz)/dz) : VOXORDER-1;

                for( x=lx; x<=ux; x++ )
                {   i = VOXORDER2*x + VOXORDER*ly;
                    for( y=ly; y<=uy; y++ )
                    {   for( z=lz; z<=uz; z++ )
                        {   dptr = (RAtom __far*)HashTable[i+z];
                            while( dptr )
                            {   TestBonded(aptr,dptr,flag);
                                dptr = dptr->next;
                            }
                        }
                        i += VOXORDER;
                    }
                }
                
                x = (int)((VOXORDER*mx)/dx);
        	y = (int)((VOXORDER*my)/dy);
                z = (int)((VOXORDER*mz)/dz);

                i = VOXORDER2*x + VOXORDER*y + z;
                aptr->next = (RAtom __far*)HashTable[i];
                HashTable[i] = (void __far*)aptr;
            }
        VoxelsClean = False;
    }

    /* Replace Long, Double & Triple Bonds! */
    InsertBonds(&CurMolecule->blist,list);

    if( info )
    {   InvalidateCmndLine();
        sprintf(buffer,"%s%ld\n\n",MsgStrs[StrNumBnd],(long)Info.bondcount);
                                       /* "Number of Bonds ....... " */
        WriteString(buffer);
    }
}


void CreateSurfaceBonds( void )
{
    register int i, x, y, z, im, xm, ym, zm;
    register Long tx, ty, tz;
    register Long txm, tym, tzm;
    register Long mx, my, mz; 
    register Long mxm, mym, mzm; 
    register Long dx, dy, dz;
    register int lx, ly, lz, ux, uy, uz;
    register int lxm, lym, lzm, uxm, uym, uzm;
    register RAtom __far *aptr, __far *dptr, __far *eptr;
    register Chain __far *chain;
    register Group __far *group;
    register Long voxorder, voxorder2;
	register SurfBond __far *sbptr;
	Long C[3], Un[3];
	int crad;
	
    if( !Database ) 
        return;
	
    dx = (MaxX-MinX)+1;
    dy = (MaxY-MinY)+1;
    dz = (MaxZ-MinZ)+1;
	
    ReclaimSurfBonds( CurMolecule );
    CurMolecule->sblist = (SurfBond __far*)0;
    Info.srfbondcount = 0;
	
    ResetVoxelData();
	
    voxorder = VOXORDER;
    voxorder2 =VOXORDER2;
	
    if ( dx+749 < 750*VOXORDER && 
         dy+749 < 750*VOXORDER && 
         dz+749 < 750*VOXORDER ) {
		voxorder = (dx+749)/750;
		if (dy > dx && dy > dz) voxorder = (dy+749)/750;
		if (dz > dx && dz > dy) voxorder = (dz+749)/750;
		voxorder2 = voxorder*voxorder;
    } 
	
    /* Load the hash table with all selected atoms and
		clear SurfBondFlag */
	
    for( chain=Database->clist; chain; chain=chain->cnext ) {
        for( group=chain->glist; group; group=group->gnext ) {
            for( aptr=group->alist; aptr; aptr=aptr->anext ) {
				if (aptr->flag&SelectFlag) {  
					
					mx = aptr->xorg + aptr->fxorg - MinX;
					my = aptr->yorg + aptr->fyorg - MinY;
					mz = aptr->zorg + aptr->fzorg - MinZ;
					
					x = (int)((voxorder*mx)/dx);
					y = (int)((voxorder*my)/dy);
					z = (int)((voxorder*mz)/dz);
					
					i = voxorder2*x + voxorder*y + z;
					aptr->next = (RAtom __far*)HashTable[i];
					aptr->flag &= ~SurfBondFlag;
					HashTable[i] = (void __far*)aptr;
				}
				VoxelsClean = False;
			}
		}
	}
	
    /* Now run through the atoms again and check each atom
		against the others using the hash table */
	
    for( chain=Database->clist; chain; chain=chain->cnext ) {
        for( group=chain->glist; group; group=group->gnext ) {
            for( aptr=group->alist; aptr; aptr=aptr->anext ) {
				if (aptr->flag&SelectFlag && (!(aptr->flag&ExpandFlag))) {
					
					/* Look for atoms within 6 Angstroms plus 2
					probe radii of atom aptr */
					
					mx = aptr->xorg + aptr->fxorg - MinX;
					my = aptr->yorg + aptr->fyorg - MinY;
					mz = aptr->zorg + aptr->fzorg - MinZ;
					
					tx = mx-AbsMaxAtomDiam-ProbeRadius-ProbeRadius;  
					ty = my-AbsMaxAtomDiam-ProbeRadius-ProbeRadius;  
					tz = mz-AbsMaxAtomDiam-ProbeRadius-ProbeRadius;  
					
					lx = (tx>0)? (int)((voxorder*tx)/dx) : 0;
					ly = (ty>0)? (int)((voxorder*ty)/dy) : 0;
					lz = (tz>0)? (int)((voxorder*tz)/dz) : 0;
					
					tx = mx+AbsMaxAtomDiam+ProbeRadius+ProbeRadius;  
					ty = my+AbsMaxAtomDiam+ProbeRadius+ProbeRadius;  
					tz = mz+AbsMaxAtomDiam+ProbeRadius+ProbeRadius;
					
					ux = (tx<dx)? (int)((voxorder*tx)/dx) : voxorder-1;
					uy = (ty<dy)? (int)((voxorder*ty)/dy) : voxorder-1;
					uz = (tz<dz)? (int)((voxorder*tz)/dz) : voxorder-1;
					
					for( x = lx; x <= ux; x++ ) { 
						i = voxorder2*x + voxorder*ly;
						for( y = ly; y<=uy; y++ ) {   
							for( z = lz; z<=uz; z++ ) {
							    register int abort; 
								dptr = (RAtom __far*)HashTable[i+z];
								while( dptr ) {
								  if( dptr->serno <  aptr->serno ) { 
									
									abort = 0;
									switch (PreTestSurface(aptr,dptr,C,&crad,Un)) {
										
										case 0:
											/* Look for atoms centers within ProbeRadius+AbsMaxAtomRad of C
											i.e. 3 Angstroms plus the ProbeRadius of C */ 
											mxm = C[0] - MinX; 
											mym = C[1] - MinY; 
											mzm = C[2] - MinZ;
											
											txm = mx-AbsMaxAtomRad-ProbeRadius;  
											tym = my-AbsMaxAtomRad-ProbeRadius;  
											tzm = mz-AbsMaxAtomRad-ProbeRadius;  
											
											lxm = (txm>0)? (int)((voxorder*txm)/dx) : 0;
											lym = (tym>0)? (int)((voxorder*tym)/dy) : 0;
											lzm = (tzm>0)? (int)((voxorder*tzm)/dz) : 0;
											
											txm = mxm+AbsMaxAtomRad+ProbeRadius; 
											tym = mym+AbsMaxAtomRad+ProbeRadius;  
											tzm = mzm+AbsMaxAtomRad+ProbeRadius;
											
											uxm = (txm<dx)? (int)((voxorder*txm)/dx) : voxorder-1;
											uym = (tym<dy)? (int)((voxorder*tym)/dy) : voxorder-1;
											uzm = (tzm<dz)? (int)((voxorder*tzm)/dz) : voxorder-1;
											
											for ( xm = lxm; (xm < uxm&& !abort) ; xm++ ) { 
												im = voxorder2*xm + voxorder*lym;
												for ( ym = lym; (ym<=uym && !abort) ; ym++ ) {   
													for( zm = lz; (zm<=uzm && !abort); zm++ ) {
														eptr = (RAtom __far*)HashTable[im+zm];
														while( eptr && (eptr != dptr)  && (eptr != aptr) && !abort ) {
															if (!TestBuriedSurface(aptr,dptr,eptr,C,crad,Un)) {  
																abort = 1;
																break;
															}
															eptr = eptr->next;
														}
													}
													im += voxorder;
												}
											}
												
											break;
										case 1:  abort = 0;
											break;
										case -1: abort = -1;
											break;
									}
									if ( !abort ) {
										sbptr = ProcessSurfBond(aptr,dptr);
										sbptr->sbnext = CurMolecule->sblist;
										CurMolecule->sblist = sbptr;
										Info.srfbondcount++;
									}
								  }
								  dptr = dptr->next;
                                }
                            }
                            i += voxorder;
                        }
					}
                }
            }
        }
    }

}



/*=================================*/
/*  Disulphide bridging functions  */
/*=================================*/


RAtom __far *FindCysSulphur( Group __far *group )
{
    register RAtom __far *ptr;
    register char *elem;

    for( ptr=group->alist; ptr; ptr=ptr->anext )
    {   elem = ElemDesc[ptr->refno];
        if( (elem[1]=='S') && (elem[0]==' ')  )
            return( ptr );
    }
    return (RAtom __far*)0;
}


void TestDisulphideBridge( Group __far *group1, Group __far *group2,
                                  RAtom __far *cys1 )
{
    register HBond __far *ptr;
    register RAtom __far *cys2;
    register int dx, dy, dz;
    register Long max,dist;

    if( !(cys2=FindCysSulphur(group2)) )
        return;

    if ((group1->model) && (group2->model) &&
      (group1->model != group2->model)) return;

    max = (Long)750*750;
    dx = (int)(cys1->xorg-cys2->xorg
           + cys1->fxorg-cys2->fxorg);   if( (dist=(Long)dx*dx)>max ) return;
    dy = (int)(cys1->yorg-cys2->yorg
           + cys1->fyorg-cys2->fyorg);   if( (dist+=(Long)dy*dy)>max ) return;
    dz = (int)(cys1->zorg-cys2->zorg
           + cys1->fzorg-cys2->fzorg);   if( (dist+=(Long)dz*dz)>max ) return;

    if( !(ptr = FreeHBond) )
    {   MemSize += sizeof(HBond);
        ptr = (HBond __far*)_fmalloc(sizeof(HBond));
        if( !ptr ) FatalDataError(MsgStrs[StrMalloc]);
        RegisterAlloc( ptr );
    } else FreeHBond = ptr->hnext;

    ptr->dst = cys1;
    if( !(ptr->dstCA=FindGroupAtom(group1,1)) )
        ptr->dstCA = cys1;

    ptr->src = cys2;
    if( !(ptr->srcCA=FindGroupAtom(group2,1)) )
        ptr->srcCA = cys2;

    ptr->offset = 0;
    ptr->energy = 0;
    ptr->flag = 0;
    ptr->col = 0;

    ptr->hnext = CurMolecule->slist;
    CurMolecule->slist = ptr;

    group1->flag |= CystineFlag;
    group2->flag |= CystineFlag;
    Info.ssbondcount++;
}


void FindDisulphideBridges( void )
{
    register Chain __far *chn1;
    register Chain __far *chn2;
    register Group __far *group1;
    register Group __far *group2;
    register RAtom __far *cys;
    char buffer[40];

    if( !Database ) return;
    ReclaimHBonds( CurMolecule->slist );
    CurMolecule->slist = (HBond __far*)0;
    Info.ssbondcount = 0;

    for(chn1=Database->clist;chn1;chn1=chn1->cnext)
        for(group1=chn1->glist;group1;group1=group1->gnext)
            if( IsCysteine(group1->refno) )
            {   cys = FindCysSulphur(group1);
                if( cys )
                {   for(group2=group1->gnext;group2;group2=group2->gnext)
                        if( IsCysteine(group2->refno) )
                            TestDisulphideBridge(group1,group2,cys);

                    for(chn2=chn1->cnext;chn2;chn2=chn2->cnext)
                        for(group2=chn2->glist;group2;group2=group2->gnext)
                            if( IsCysteine(group2->refno) )
                                TestDisulphideBridge(group1,group2,cys);
	        }
            }

    if( FileDepth == -1 )
    {   InvalidateCmndLine();
        sprintf(buffer,"%s%d\n\n",MsgStrs[StrNumBrg],Info.ssbondcount);
                                      /* "Number of Bridges ..... " */
        WriteString(buffer);
    }
}



void FindCisBonds( void )
{
  register Chain __far *chain;
  register Group __far *group;
  register Group __far *prev;

  if( !Database ) return;
  Info.cisbondcount = 0; /* Number of Bonds not used at the moment ... */
  
  /*zeroed CisBonFlag*/
  for(chain=Database->clist;chain;chain=chain->cnext)
    for(group=chain->glist;group;group=group->gnext)      
		group->flag &= (~CisBondFlag);
 
  for(chain=Database->clist;chain;chain=chain->cnext)
  { prev = (Group __far *)0;
    for(group=chain->glist;group;group=group->gnext)
    {  if( prev && IsAmino(prev->refno) && IsAmino(group->refno))
       {
        /* if( fabs(- (CalcOmegaAngle(prev, group) - 180.0)) < CisBondCutOff ){ */
	       if( fabs(CalcOmegaAngle(prev, group)) < CisBondCutOff )
	       {  group->flag |= CisBondFlag;
	          prev->flag |= CisBondFlag;
	          Info.cisbondcount++;  
	       }
        }
        prev = group;
    }
  }   
}


/*================================================*/
/*  Kabsch & Sander DSSP Structure Determination  */
/*================================================*/

/* Coupling constant for Electrostatic Energy   */
/* QConst = -332 * 0.42 * 0.2 * 1000.0 [*250.0] */
#define QConst (-6972000.0)
#define MaxHDist ((Long)2250*2250)
#define MinHDist ((Long)125*125)


/* Protein Donor RAtom Coordinates */
static int hxorg,hyorg,hzorg;
static int nxorg,nyorg,nzorg;
static RAtom __far *best1CA;
static RAtom __far *best2CA;
static RAtom __far *best1;
static RAtom __far *best2;
static RAtom __far *optr;
static int res1,res2;
static int off1,off2;


static int CalculateBondEnergy( Group __far *group )
{
    register double dho,dhc;
    register double dnc,dno;

    register RAtom __far *cptr;
    register Long dx,dy,dz;
    register Long dist;
    register int result;

    if( !(cptr=FindGroupAtom(group,2)) )  return(0);
    if( !(optr=FindGroupAtom(group,3)) )  return(0);

    dx = hxorg - optr->xorg - optr->fxorg;  
    dy = hyorg - optr->yorg - optr->fyorg;  
    dz = hzorg - optr->zorg - optr->fzorg;
    dist = dx*dx+dy*dy+dz*dz;
    if( dist < MinHDist ) 
        return( -9900 );
    dho = sqrt((double)dist);

    dx = hxorg - cptr->xorg - cptr->fxorg;  
    dy = hyorg - cptr->yorg - cptr->fyorg;  
    dz = hzorg - cptr->zorg - cptr->fzorg;
    dist = dx*dx+dy*dy+dz*dz;
    if( dist < MinHDist ) 
        return( -9900 );
    dhc = sqrt((double)dist);

    dx = nxorg - cptr->xorg - cptr->fxorg;  
    dy = nyorg - cptr->yorg - cptr->fyorg;  
    dz = nzorg - cptr->zorg - cptr->fzorg;
    dist = dx*dx+dy*dy+dz*dz;
    if( dist < MinHDist ) 
        return( -9900 );
    dnc = sqrt((double)dist);

    dx = nxorg - optr->xorg - optr->fxorg;  
    dy = nyorg - optr->yorg - optr->fyorg;  
    dz = nzorg - optr->zorg - optr->fzorg;
    dist = dx*dx+dy*dy+dz*dz;
    if( dist < MinHDist ) 
        return( -9900 );
    dno = sqrt((double)dist);

    result = (int)(QConst/dho - QConst/dhc + QConst/dnc - QConst/dno);

    if( result<-9900 ) 
    {   return -9900;
    } else if( result>-500 ) 
        return 0;
    return result;
}


static void CalcProteinHBonds( Chain __far *chn1 )
{
    register int energy, offset;
    register Chain __far *chn2;
    register Group __far *group1;
    register Group __far *group2;
    register RAtom __far *ca1;
    register RAtom __far *ca2;
    register RAtom __far *pc1;
    register RAtom __far *po1;
    register RAtom __far *n1;
    register int pos1,pos2;
    register int dx,dy,dz;
    register double dco;
    register Long dist;

    pos1 = 0;
    pc1 = po1 = (void __far*)0;
    for(group1=chn1->glist;group1;group1=group1->gnext)
    {   pos1++;
        if( pc1 && po1 )
        {   dx = (int)(pc1->xorg - po1->xorg + pc1->fxorg - po1->fxorg );
            dy = (int)(pc1->yorg - po1->yorg + pc1->fyorg - po1->fyorg);
            dz = (int)(pc1->zorg - po1->zorg + pc1->fzorg - po1->fzorg);
        } else
        {   pc1 = FindGroupAtom(group1,2);
            po1 = FindGroupAtom(group1,3);
            continue;
        }

        pc1 = FindGroupAtom(group1,2);
        po1 = FindGroupAtom(group1,3);

        if( !IsAmino(group1->refno) || IsProline(group1->refno) )
            continue;

        if( !(ca1=FindGroupAtom(group1,1)) ) continue;
        if( !(n1=FindGroupAtom(group1,0)) )  continue;

        dist = (Long)dx*dx + (Long)dy*dy + (Long)dz*dz;
        dco = sqrt( (double)dist )/250.0;

        nxorg = (int)(n1->xorg + n1->fxorg);   hxorg = nxorg + (int)(dx/dco);
        nyorg = (int)(n1->yorg + n1->fyorg);   hyorg = nyorg + (int)(dy/dco);
        nzorg = (int)(n1->zorg + n1->fzorg);   hzorg = nzorg + (int)(dz/dco);
        res1 = res2 = 0;

        if( HBondChainsFlag )
        {   /* Hydrogen bond between chains! */
            chn2=Database->clist;
        } else chn2 = chn1;

        
        do {
            /* Only consider non-empty peptide chains! */
            if( !chn2->glist || !IsProtein(chn2->glist->refno) )
            {   chn2 = chn2->cnext;
                continue;
            }

            pos2 = 0;
            for(group2=chn2->glist;group2;group2=group2->gnext)
            {   pos2++;
                if( (group2==group1) || (group2->gnext==group1) )
                    continue;

                if( !IsAmino(group2->refno) ) 
                    continue;
                if( !(ca2=FindGroupAtom(group2,1)) ) 
                    continue;

                dx = (int)(ca1->xorg-ca2->xorg + ca1->fxorg-ca2->fxorg);
                if( (dist=(Long)dx*dx) > MaxHDist )
                    continue;

                dy = (int)(ca1->yorg-ca2->yorg + ca1->fyorg-ca2->fyorg);
                if( (dist+=(Long)dy*dy) > MaxHDist )
                    continue;

                dz = (int)(ca1->zorg-ca2->zorg + ca1->fzorg-ca2->fzorg);
                if( (dist+=(Long)dz*dz) > MaxHDist )
                    continue;

                energy = CalculateBondEnergy(group2);
                if( energy )
                {   if( chn1 == chn2 )
                    {   offset = pos1 - pos2;
                    } else offset = 0;

                    if( energy<res1 )
                    {   best2CA = best1CA;  best1CA = ca2;
                        best2 = best1;      best1 = optr;
                        res2 = res1;        res1 = energy;
                        off2 = off1;        off1 = offset;
                    } else if( energy<res2 )
                    {   best2CA = ca2;
                        best2 = optr;
                        res2 = energy;
                        off2 = offset;
                    }
                }
            }  /* group2 */
            chn2 = chn2->cnext;
        } while( HBondChainsFlag && chn2 );

        if( res1 ) 
        {   if( res2 ) 
                CreateHydrogenBond(ca1,best2CA,n1,best2,res2,off2);
            CreateHydrogenBond(ca1,best1CA,n1,best1,res1,off1);
        }
    }
}


static void CalcNucleicHBonds( Chain __far *chn1 )
{
    register Chain __far *chn2;
    register Group __far *group1;
    register Group __far *group2;
    register Group __far *best;
    register RAtom __far *ca1;
    register RAtom __far *ca2;
    register RAtom __far *n1;
    register Long max,dist;
    register int dx,dy,dz;
    register int refno;

    for(group1=chn1->glist;group1;group1=group1->gnext)
    {   if( !IsPurine(group1->refno) ) continue;
        /* Find N1 of Purine Group */
        n1 = FindGroupAtom(group1,21);
        if( !n1 ) continue;

        /* Maximum N1-N3 distance 5A */
        refno = NucleicCompl(group1->refno);
        max = (Long)1250*1250;
        best = (void __far*)0;

        for(chn2=Database->clist;chn2;chn2=chn2->cnext)
        {   /* Only consider non-empty nucleic acid chains! */
            if( (chn1==chn2) || !chn2->glist || 
                !IsDNA(chn2->glist->refno) )
                continue;

            for(group2=chn2->glist;group2;group2=group2->gnext)
                if( group2->refno == (Byte)refno )
                {   /* Find N3 of Pyramidine Group */
                    if( !(ca1=FindGroupAtom(group2,23)) )
                        continue;

                    dx = (int)(ca1->xorg - n1->xorg + ca1->fxorg - n1->fxorg);
                    if( (dist=(Long)dx*dx) >= max ) 
                        continue;

                    dy = (int)(ca1->yorg - n1->yorg + ca1->fyorg - n1->fyorg);
                    if( (dist+=(Long)dy*dy) >= max ) 
                        continue;

                    dz = (int)(ca1->zorg - n1->zorg + ca1->fzorg - n1->fzorg);
                    if( (dist+=(Long)dz*dz) >= max )
                        continue;

                    best1 = ca1;
                    best = group2;
                    max = dist;
                }
        }

        if( best )
        {   /* Find the sugar phosphorous atoms */
            ca1 = FindGroupAtom( group1, 7 );
            ca2 = FindGroupAtom( best, 7 );

            CreateHydrogenBond( ca1, ca2, n1, best1, 0, 0 );
            if( IsGuanine(group1->refno) )
            {   /* Guanine-Cytosine */
                ca1 = FindGroupAtom(group1,22);   /* G.N2 */
                ca2 = FindGroupAtom(best,26);     /* C.O2 */
                if( ca1 && ca2 )
                    CreateHydrogenBond( (void __far*)0, (void __far*)0,
                                        ca1, ca2, 0, 0 );

                ca1 = FindGroupAtom(group1,28);   /* G.O6 */
                ca2 = FindGroupAtom(best,24);     /* C.N4 */
                if( ca1 && ca2 )
                    CreateHydrogenBond( (void __far*)0, (void __far*)0,
                                        ca1, ca2, 0, 0 );

            } else /* Adenine-Thymine */
            {   ca1 = FindGroupAtom(group1,25);  /* A.N6 */
                ca2 = FindGroupAtom(best,27);    /* T.O4 */
                if( ca1 && ca2 )
                    CreateHydrogenBond( (void __far*)0, (void __far*)0,
                                        ca1, ca2, 0, 0 );
            }
        }
    }
}


void CalcHydrogenBonds( void )
{
    register Chain __far *chn1;
    char buffer[40];

    if( !Database ) return;
    ReclaimHBonds( CurMolecule->hlist );
    CurMolecule->hlist = (void __far*)0;
    CurHBond = &CurMolecule->hlist;
    Info.hbondcount = 0;

    if( MainAtomCount > 10000 )
    {   InvalidateCmndLine();
        WriteString("Please wait... ");
    }

    for(chn1=Database->clist; chn1; chn1=chn1->cnext)
        if( chn1->glist )
        {   if( IsProtein(chn1->glist->refno) )
            {   CalcProteinHBonds(chn1);
            } else if( IsDNA(chn1->glist->refno) )
                CalcNucleicHBonds(chn1);
        }

    if( FileDepth == -1 )
    {   InvalidateCmndLine();
        sprintf(buffer,"%s%d\n",MsgStrs[StrNumHbd],Info.hbondcount);
                                 /* "Number of H-Bonds ..... " */
        WriteString(buffer);
    }
}


static int IsHBonded( RAtom __far *src, RAtom __far *dst, HBond __far *ptr )
{
    while( ptr && (ptr->srcCA==src) )
        if( ptr->dstCA == dst )
        {   return True;
        } else ptr=ptr->hnext;
    return False;
}


static void FindAlphaHelix( int pitch, int flag )
{
    register HBond __far *hbond;
    register Chain __far *chain;
    register Group __far *group;
    register Group __far *first;
    register Group __far *ptr;
    register RAtom __far *srcCA;
    register RAtom __far *dstCA;
    register int res,dist,prev;

    /* Protein chains only! */
    hbond = Database->hlist;
    for( chain=Database->clist; chain; chain=chain->cnext )
    {   first = chain->glist;
        if( first  && IsProtein(first->refno) )
        {   /* Scan Protein Chain for Helix */
            prev = False; dist = 0;
            for( group=chain->glist; hbond && group; group=group->gnext )
            {   if( IsAmino(group->refno) )
                {   srcCA = FindGroupAtom(group,1);
                    if( srcCA )
                    {   if( dist == pitch )
                        {   res = False;
                            dstCA = FindGroupAtom(first,1);
                            while( hbond && (hbond->srcCA==srcCA) )
                            {   if( hbond->dstCA==dstCA ) res = True;
                                hbond = hbond->hnext;
                            }

                            if( res )
                            {   if( prev )
                                {   if( !(first->struc&HelixFlag) ) 
                                    Info.helixcount++;

                                    ptr = first;
                                    do {
                                        ptr->struc |= flag;
                                        ptr = ptr->gnext;
                                    } while( ptr != group );
                                } else prev = True;
                            } else prev = False;
                        } else while( hbond && (hbond->srcCA==srcCA) )
                            hbond = hbond->hnext;
                    } else prev = False;
                } else prev = False;

                if( group->struc & HelixFlag )
                {   first = group; prev = False; dist = 1;
                } else if( dist == pitch )
                {   first = first->gnext;
                } else dist++;
            }

        } else if( first && IsNucleo(first->refno) )
            while( hbond && !IsAminoBackbone(hbond->src->refno) )
                hbond = hbond->hnext;
    }
}


static RAtom __far *cprevi, __far *ccurri, __far *cnexti;
static HBond __far *hcurri, __far *hnexti;
static Group __far *curri, __far *nexti;


static void TestLadder( Chain __far *chain )
{
    register RAtom __far *cprevj, __far *ccurrj, __far *cnextj;
    register HBond __far *hcurrj, __far *hnextj;
    register Group __far *currj, __far *nextj;
    register int count, result, found;

    /* Avoid Compiler Warnings! */
    cprevj = ccurrj = (RAtom __far*)0;
    hcurrj = (HBond __far*)0;
    currj  = (Group __far*)0;

    /* Already part of atleast one ladder */
    found = curri->flag & SheetFlag;
    nextj = nexti->gnext;

    hnextj = hnexti;
    while( hnextj && hnextj->srcCA==cnexti )
        hnextj = hnextj->hnext;

    while( chain )
    {   if( nextj ) {
            if( IsProtein(chain->glist->refno) )
            {   count = 1;
                do {
                    cnextj = FindGroupAtom(nextj,1);
                    if( count == 3 )
                    {   if( IsHBonded(cnexti,ccurrj,hnexti) &&
                            IsHBonded(ccurrj,cprevi,hcurrj) )
                        {   result = ParaLadder;
                        } else if( IsHBonded(cnextj,ccurri,hnextj) &&
                                   IsHBonded(ccurri,cprevj,hcurri) )
                        {   result = ParaLadder;
                        } else if( IsHBonded(cnexti,cprevj,hnexti) &&
                                   IsHBonded(cnextj,cprevi,hnextj) )
                        {   result = AntiLadder;
                        } else if( IsHBonded(ccurrj,ccurri,hcurrj) &&
                                   IsHBonded(ccurri,ccurrj,hcurri) )
                        {   result = AntiLadder;
                        } else result = NoLadder;

                        if( result )
                        {   curri->struc |= SheetFlag;
                            currj->struc |= SheetFlag;
                            if( found ) return;
                            found = True;
                        }
                    } else count++;

		    cprevj = ccurrj; ccurrj = cnextj; 
		    currj = nextj;   hcurrj = hnextj;

		    while( hnextj && hnextj->srcCA==cnextj )
			hnextj = hnextj->hnext;
	            nextj = nextj->gnext;
		} while( nextj );

	    } else if( IsNucleo(chain->glist->refno) ) {
		while( hnextj && !IsAminoBackbone(hnextj->src->refno) ) {
		    hnextj = hnextj->hnext;
            }
            }
        }
        chain = chain->cnext;
	if( chain )
	    nextj = chain->glist;
    }
}


static void FindBetaSheets( void )
{
    register Chain __far *chain;
    register int ladder;
    register int count;

    hnexti = Database->hlist;
    for( chain=Database->clist; chain; chain=chain->cnext )
    {   nexti = chain->glist;
	if( nexti )
	{   if( IsProtein(nexti->refno) )
	    {   count = 1;
		ladder = False;
		do {
		    cnexti = FindGroupAtom(nexti,1);

		    if( count == 3 )
		    {   TestLadder( chain );
			if( curri->struc & SheetFlag )
			{   if( !ladder )
			    {   Info.laddercount++;
				ladder = True;
			    }
			} else ladder = False;
		    } else count++;

		    cprevi = ccurri; ccurri = cnexti; 
		    curri = nexti;   hcurri = hnexti;
		    while( hnexti && hnexti->srcCA==cnexti )
			hnexti = hnexti->hnext;
	            nexti = nexti->gnext;
		} while( nexti );

	    } else if( IsNucleo(nexti->refno) )
		while( hnexti && !IsAminoBackbone(hnexti->src->refno) )
		    hnexti = hnexti->hnext;
        }
    }
}


static void FindTurnStructure( void )
{
    static RAtom __far *aptr[5];
    register Chain __far *chain;
    register Group __far *group;
    register Group __far *prev;
    register RAtom __far *ptr;
    register Long ux,uy,uz,mu;
    register Long vx,vy,vz,mv;
    register int i,found,len;
    register Real CosKappa;

    /* Avoid compiler warnings */
    prev = (Group __far*)0;

    for( chain=Database->clist; chain; chain=chain->cnext )
	if( chain->glist && IsProtein(chain->glist->refno) )
	{   len = 0;  found = False;
	    for( group=chain->glist; group; group=group->gnext )
	    {    ptr = FindGroupAtom(group,1);
		 if( ptr && (ptr->flag&BreakFlag) )
		 {   found = False;
		     len = 0;
		 } else if( len==5 )
		 {   for( i=0; i<4; i++ )
			 aptr[i] = aptr[i+1];
		     len = 4;
		 } else if( len==2 )
		     prev = group;

		 aptr[len++] = ptr;
		 if( len==5 ) 
		 {   if( !(prev->struc&(HelixFlag|SheetFlag)) &&
			 aptr[0] && aptr[2] && aptr[4] )
		     {   ux = aptr[2]->xorg - aptr[0]->xorg
                             + aptr[2]->fxorg - aptr[0]->fxorg;
			 uy = aptr[2]->yorg - aptr[0]->yorg
                             + aptr[2]->fyorg - aptr[0]->fyorg;
			 uz = aptr[2]->zorg - aptr[0]->zorg
                             + aptr[2]->fzorg - aptr[0]->fzorg;

			 vx = aptr[4]->xorg - aptr[2]->xorg
                             + aptr[4]->fxorg - aptr[2]->fxorg;
			 vy = aptr[4]->yorg - aptr[2]->yorg
                             + aptr[4]->fyorg - aptr[2]->fyorg;
			 vz = aptr[4]->zorg - aptr[2]->zorg
                             + aptr[4]->fzorg - aptr[2]->fzorg;
#ifdef INVERT
                         uy = -uy;
                         vy = -vy;
#endif
                         uz = -uz;
                         vz = -vz;

			 mu = ux*ux + uy*uy + uz*uz;
			 mv = vx*vx + vz*vz + vy*vy;
			 if( mu && mv )
			 {   CosKappa = (Real)(ux*vx + uy*vy + uz*vz);
			     CosKappa /= sqrt( (Real)mu*mv );
			     if( CosKappa<Cos70Deg )
			     {   if( !found )
				     Info.turncount++;
				 prev->struc |= TurnFlag;
			     }
			 }
		     }
		     found = prev->struc&TurnFlag;
		     prev = prev->gnext;
		 } /* len==5 */
	    }
	}
}


static void FindBetaTurns( void )
{
    static RAtom __far *aptr[4];
    register Chain __far *chain;
    register Group __far *group;
    register Group __far *prev;
    register Group __far *next;
    register RAtom __far *ptr;
    register Long dx,dy,dz;
    register int found,len;
    register int flag;

    for( chain=Database->clist; chain; chain=chain->cnext )
        if( chain->glist && IsProtein(chain->glist->refno) )
        {   prev = chain->glist;  
            len = 0;  found = False;
            for( next=chain->glist; next; next=next->gnext )
            {   ptr = FindGroupAtom(next,1);
                if( ptr && (ptr->flag&BreakFlag) )
                {   found = False;
                    prev = next;
                    len = 0;
                } else if( len==4 )
                {   aptr[0] = aptr[1];
                    aptr[1] = aptr[2];
                    aptr[2] = aptr[3];
                    aptr[3] = ptr;

                } else aptr[len++] = ptr;
                if( len==4 ) 
                {   flag = False;
                    if( aptr[0] && aptr[3] )
                    {   dx = aptr[3]->xorg - aptr[0]->xorg
                             + aptr[3]->fxorg - aptr[0]->fxorg;
                        dy = aptr[3]->yorg - aptr[0]->yorg
                             + aptr[3]->fyorg - aptr[0]->fyorg;
                        dz = aptr[3]->zorg - aptr[0]->zorg
                             + aptr[3]->fzorg - aptr[0]->fzorg;
                        if( dx*dx + dy*dy + dz*dz < (Long)1750*1750 )
                        {   group = prev;
                            while( group!=next->gnext )
                            {   if( !(group->struc&(HelixFlag|SheetFlag)) )
                                {   group->struc |= TurnFlag;
                                    flag = True;
                                }
                                group = group->gnext;
                            }
                            if( !found && flag ) 
                                Info.turncount++;
                        }
                    }
                    prev = prev->gnext;   
                    found = flag;
                } /* len==4 */
            }
        }
}


void DetermineStructure( int flag )
{
    register Chain __far *chain;
    register Group __far *group;
    char buffer[40];

    if( !Database )
	return;

    if( Info.hbondcount < 0 )
	CalcHydrogenBonds();

    if( Info.helixcount >= 0 )
	for( chain=Database->clist; chain; chain=chain->cnext )
	    for( group=chain->glist; group; group=group->gnext )
		group->struc = 0;

    Info.structsource = SourceCalc;
    Info.laddercount = 0;
    Info.helixcount = 0;
    Info.turncount = 0;

    if( Info.hbondcount )
    {   FindAlphaHelix(4,Helix4Flag);
	FindBetaSheets();
	FindAlphaHelix(3,Helix3Flag);
	FindAlphaHelix(5,Helix5Flag);

        if( !flag )
	{   FindTurnStructure();
        } else FindBetaTurns();
    }

    if( FileDepth == -1 )
    {   InvalidateCmndLine();

        sprintf(buffer,"%s%d\n",MsgStrs[StrNumHel],Info.helixcount);
        WriteString(buffer);
        sprintf(buffer,"%s%d\n",MsgStrs[StrNumStrnd],Info.laddercount);
        WriteString(buffer);
        sprintf(buffer,"%s%d\n",MsgStrs[StrNumTrn],Info.turncount);
        WriteString(buffer);
    }
}


void RenumberMolecule( int start )
{
    register Chain __far *chain;
    register Group __far *group;
    register int hinit, minit;
    register int resno;

    if( !Database )
	return;

    hinit = minit = False;
    for( chain=Database->clist; chain; chain=chain->cnext )
    {   resno = start;
	for( group=chain->glist; group; group=group->gnext )
	{   if( group->alist->flag & HeteroFlag )
	    {   if( hinit )
		{   if( resno > MaxHetaRes )
		    {   MaxHetaRes = resno;
		    } else if( resno < MinHetaRes )
			MinHetaRes = resno;
		} else MinHetaRes = MaxHetaRes = resno;
		hinit = True;
	    } else
	    {   if( minit )
		{   if( resno > MaxMainRes )
		    {   MaxMainRes = resno;
		    } else if( resno < MinMainRes )
			MinMainRes = resno;
		} else MinMainRes = MaxMainRes = resno;
		minit = True;
	    }
	    group->serno = resno++;
	}
    }
}



/*===============================*/
/* Molecule Database Maintenance */
/*===============================*/

static void ReclaimAtoms( RAtom __far *ptr )
{
    register RAtom __far *temp;

    if( ptr )
    {   temp = ptr;
        while( temp->anext )
	    temp=temp->anext;
	temp->anext = FreeAtom;
	FreeAtom = ptr;
    }
}


static void ResetDatabase( void )
{
    int i,j;

    Cache = (Group __far*)0;

    Database = CurMolecule = (void __far*)0;
    MainGroupCount = HetaGroupCount = 0;
    Info.chaincount = 0;
    Info.bondcount = 0;
    HetaAtomCount = 0;
    MainAtomCount = 0;  
    SelectCount = 0;

    Info.ssbondcount = -1;
    Info.hbondcount = -1;

    Info.structsource = SourceNone;
    Info.laddercount = -1;
    Info.helixcount = -1;
    Info.turncount = -1;

    CurGroup = (void __far*)0;
    CurChain = (void __far*)0;
    CurAtom = (void __far*)0;

    MinX = MinY = MinZ = 0;
    MaxX = MaxY = MaxZ = 0;

    MinMainTemp = MaxMainTemp = 0;
    MinHetaTemp = MaxHetaTemp = 0;
    MinMainRes = MaxMainRes = 0;
    MinHetaRes = MaxHetaRes = 0;
    MinAltl = MaxAltl = 0;

    MinModel = MaxModel = 0;

    *Info.moleculename = 0;
    *Info.classification = 0;
    *Info.spacegroup = 0;
    *Info.identcode = 0;
    *Info.filename = 0;
    *Info.technique = 0;
    *Info.date = 0;

    VoxelsClean = False;
    HMinMaxFlag = False;
    MMinMaxFlag = False;
    HasHydrogen = False;
    ElemNo = MINELEM;
    ResNo = MINRES;
    MaskCount = 0;
    NMRModel = 0;
    NullBonds = 0;
    
    MapLevel = 0.;
    MapFlag = MapMeanFlag;
    MapSpacing = 250L;
    MapSpread = .6667;
    MapRGBCol[0] = 0xFA;
    MapRGBCol[1] = 0xFF;
    MapRGBCol[2] = 0xFA;


    for ( i=0; i<3; i++ ) {
      Info.vecf2o[i] = Info.veco2f[i] = Info.cell[i] = 0.;
      Info.cell[i+3] = 90.;
      for ( j=0; j<3; j++) {
        Info.matf2o[i][j] = Info.mato2f[i][j] = ((i!=j)?0.:1.);
      }
    }

}


void DestroyDatabase( void )
{
    register void __far *temp;
    register Group __far *gptr;

    if( Database )
    {   ReclaimHBonds( Database->slist );
	ReclaimHBonds( Database->hlist );
	ReclaimBonds( Database );
	ReclaimSurfBonds( Database );

	while( Database->clist )
	{   ReclaimChainBonds(Database->clist);
	    gptr = Database->clist->glist;
	    if( gptr )
	    {   ReclaimAtoms(gptr->alist);
		while( gptr->gnext )
		{   gptr = gptr->gnext;
		    ReclaimAtoms(gptr->alist);
		}
		gptr->gnext = FreeGroup;
		FreeGroup = Database->clist->glist;
	    }
	    temp = Database->clist->cnext;
	    Database->clist->cnext = FreeChain;
	    FreeChain = Database->clist;
	    Database->clist = temp;
	}

	FreeMolecule = Database;
	Database = (void __far*)0;
    }
    ResetDatabase();
}

void FreeAlloc( data )
    void *data;
{
#ifdef APPLEMAC
    register AllocRef *ptr;
    register AllocRef *tmp;
    register int i;
    
    /* Avoid Memory Leaks */
    for( ptr=AllocList; ptr; ptr=tmp )
    {   for( i=0; i<ptr->count; i++ )
	  if (data == ptr->data[i]) {
            _ffree( ptr->data[i] );
            ptr->data[i] = 0;
            return;
	  }
	tmp = ptr->next;
    }
#endif
    _ffree(data);
}

void PurgeDatabase( void )
{
#ifdef APPLEMAC
    register AllocRef *ptr;
    register AllocRef *tmp;
    register int i;
    
    /* Avoid Memory Leaks */
    for( ptr=AllocList; ptr; ptr=tmp )
    {   for( i=0; i<ptr->count; i++ )
	  if (ptr->data[i])
            _ffree( ptr->data[i] );
	tmp = ptr->next;
	_ffree( ptr );
    }
#endif
}


void InitialiseDatabase( void )
{
    FreeMolecule = (void __far*)0;
    FreeSurfBond = (void __far*)0;
    FreeHBond = (void __far*)0;
    FreeChain = (void __far*)0;
    FreeGroup = (void __far*)0;
    FreeAtom = (void __far*)0;
    FreeBond = (void __far*)0;
    Info.cisbondcount = -1; /* to ititialize it has to be < 0 */   
    CisBondCutOff = CIS;
    MapLevel = 0.;
    MapFlag = MapMeanFlag;
    MapSpacing = 250L;
    MapSpread = .6667;
    MapRGBCol[0] = 0xFA;
    MapRGBCol[1] = 0xFF;
    MapRGBCol[2] = 0xFA;


#ifdef APPLEMAC
    AllocList = (void*)0;
#endif

    HBondChainsFlag = False;
    ResetDatabase();
}

