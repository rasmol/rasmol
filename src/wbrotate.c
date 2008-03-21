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
/* wbrotate.c
 $Log: not supported by cvs2svn $
 Revision 1.8  2008/03/19 01:33:11  yaya
 Documentation update. -- HJB

 Revision 1.8  2008/03/17 11:35:23  yaya-hjb
 Release 2.7.4.2 update and T. Ikonen GTK update -- HJB

 Revision 1.5  2008/03/17 03:26:07  yaya-hjb
 Align with RasMol 2.7.4.2 release to use cxterm to support Chinese and
 Japanese for Linux and Mac OS X versions using rasmol_install and
 rasmol_run scripts, and align command line options for size and
 position of initial window. -- HJB

 Revision 1.5  2008/03/17 01:32:41  yaya
 Add gtk mods by tpikonen, and intergate with 2.7.4.2 mods -- HJB

 Revision 1.6  2008/03/16 22:25:22  yaya
 Align comments with production version; Update rasmol_install and
 rasmol_run shell scripts for Japanese and Chinese; Align logic for
 positioning and sizing initial window with windows version -- HJB

 Revision 1.4  2008/02/21 15:11:46  tpikonen
 Add GTK GUI.

 Revision 1.4  2008/01/30 03:15:55  yaya
 More post 2.7.4.1 release cleanup -- HJB

 Revision 1.5  2008/01/29 04:12:11  yaya
 Post release cleanup of problems discovered. -- HJB

 Revision 1.3  2008/01/29 04:35:26  yaya
 Postrelease update to fix problems discovered -- HJB

 Revision 1.2  2008/01/28 03:29:38  yaya
 Update CVS to RasMol_2.7.4.1 -- HJB

 Revision 1.4  2008/01/14 15:49:16  yaya
 More of code for CBF style map save
 More use of stdlib as per Ladislav Michnovic
 --HJB

 Revision 1.3  2007/12/14 02:04:50  yaya
 Correct Chinese data for missing line in langsel_utf.c
 Rewrite code for handling of slab mode in stereo -- HJB

 Revision 1.2  2007/11/19 03:28:40  yaya
 Update to credits for 2.7.4 in manual and headers
 Mask code added -- HJB

 Revision 1.1.1.1  2007/03/01 01:16:32  todorovg
 Chinese working versio from rasmol_ru initial import

 Revision 1.4  2006/11/01 03:23:51  yaya
 Update NSIS windows installer for more script types and to fix
 misplaced script instructions for data files; add document and
 script icons directly in raswin.exe; add credit line to
 G. A. Pozhvanov in comments for Russian translations. -- HJB

 Revision 1.3  2006/10/20 13:53:02  yaya
 Move about dialog flag file RASWIN.FLG to APPDATA style directories
 Translate three "not founds" that had been missed before -- HJB

 Revision 1.2  2006/09/17 10:53:56  yaya
 Clean up headers and start on code for X11 -- HJB

 Revision 1.1.1.1  2006/09/16 18:46:02  yaya
 Start of RasMol Russian Translation Project based on translations
 by Gregory A. Pozhvanov of Saint Petersburg State University -- HJB

 Revision 1.1.1.1  2006/06/19 22:05:14  todorovg
 Initial Rasmol 2.7.3 Import

 Revision 1.1  2004/05/07 19:46:16  yaya
 Initial revision

 Revision 1.2  2003/12/13 19:26:11  yaya
 *** empty log message ***

 Revision 1.1  2003/12/12 21:10:38  yaya
 Initial revision

 Revision 1.1  2001/01/31 02:13:45  yaya
 Initial revision

 Revision 1.7  2000/08/27 18:30:46  yaya
 fix for nested bond rotation bug

 Revision 1.6  2000/08/27 00:54:53  yaya
 create rotation bond database

 Revision 1.5  2000/08/26 17:31:13  yaya
 Fix for world rot, remove refs to toolbar

 Revision 1.4  2000/08/26 03:14:16  yaya
 Mods for mac compilations

 Revision 1.3  2000/08/21 21:07:55  yaya
 semi-final ucb mods

 Revision 1.2  2000/08/18 16:40:54  yaya
 *** empty log message ***

 Revision 1.1  2000/08/09 01:18:25  yaya
 Rough cut with ucb

 */

/* Original header for this routine:
 */
/**********************************************************************
  Copyright (c) 1995 UC Regents, ModularCHEM Consortium

  wbrotate.c
  World Rotate/Bond Rotate
  
  Author:      Gary Grossman (garyg@cory.EECS.Berkeley.EDU)
  Last Update: November 14, 1995
 **********************************************************************/

#include "rasmol.h"

#ifdef IBMPC
#include <windows.h>
#endif
#ifdef APPLEMAC
#ifdef __CONDITIONALMACROS__
#include <Printing.h>
#else
#include <PrintTraps.h>
#endif
#include <Types.h>
#endif
#include <stdio.h>
#include <math.h>
/* Ladislav Michnovic, 10 Jan 08 start */
#include <stdlib.h>
/* Ladislav Michnovic, 10 Jan 08 end */

#define WBROTATE
#include "molecule.h"
#include "abstree.h"
#include "transfor.h"
#include "command.h"
#include "render.h"
#include "repres.h"
#include "graphics.h"
#include "multiple.h"
#include "vector.h"
#include "wbrotate.h"
#include "cmndline.h"
#include "langsel.h"

/* Macros for commonly used loops */
#define ForEachAtom  for(chain=Database->clist;chain;chain=chain->cnext) \
		     for(group=chain->glist;group;group=group->gnext)    \
		     for(ptr=group->alist;ptr;ptr=ptr->anext)
#define ForEachBond  for(bptr=Database->blist;bptr;bptr=bptr->bnext) 
#define ForEachHBond for(hptr=Database->hlist;hptr;hptr=hptr->hnext) 
#define ForEachSBond for(sptr=Database->slist;sptr;sptr=sptr->hnext) 
#define ForEachBack  for(chain=Database->clist;chain;chain=chain->cnext) \
		     for(bptr=chain->blist;bptr;bptr=bptr->bnext)

static void ResetVisited( void )
{
    /* Construct a graph of the current molecule */
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *ptr;
    
    ForEachAtom {
	ptr->visited = 0;
    }
}

static void ResetCoord( void )
{
   /* Reset the bond rotation coordinate shifts */
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *ptr;
    
    ForEachAtom {
	ptr->fxorg = ptr->fyorg = ptr->fzorg = 0;
        ptr->x = ptr->y = ptr->z = 0;
    }
}

static void UpdateCoord( void )
{
   /* Reset the bond rotation coordinate shifts */
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *ptr;
    
    ForEachAtom {
        ptr->fxorg += ptr->x;
        ptr->fyorg += ptr->y;
        ptr->fzorg += ptr->z;
        ptr->x = ptr->y = ptr->z = 0;
    }
}


int ConstructGraph( void )
{
    /* Construct a graph of the current molecule */
    register Chain __far *chain;
    register Group __far *group;
    register Bond __far *bptr;
    register RAtom __far *ptr;
    
    /*  Initialize graph */
    int count = 0;
    ForEachAtom {
	ptr->visited = 0;
	ptr->nbonds = 0;
	count++;
    }
    
    /* Go through each edge (bond), insert edge in our graph */
    count = 0;
    ForEachBond {
	if (bptr->srcatom->nbonds == MaxBonds) return 0;
	if (bptr->dstatom->nbonds == MaxBonds) return 0;
	bptr->srcatom->bonds[bptr->srcatom->nbonds++] = bptr->dstatom;
	bptr->dstatom->bonds[bptr->dstatom->nbonds++] = bptr->srcatom;
	count++;
    }
    
    return 1;
}

int RemoveBond(  Long nsrc, Long ndst )
{  
    int found = False;
    register RAtom __far *src;
    register RAtom __far *dst;
    register Bond __far *bptr;
    register Bond __far *pbptr;
    register HBond __far *hptr;
    register HBond __far *phptr;
    register HBond __far *sptr;
    register HBond __far *psptr;
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *aptr;
    register int done;
    char buffer[20];

    /* Avoid compiler warnings */
    phptr = psptr = (HBond __far *)0;
 
    if( nsrc == ndst )
    {   InvalidateCmndLine();
        WriteString("Error: Duplicate atom serial numbers!\n");
        return False;
    }
 
    done = False;
    src = (RAtom __far*)NULL;
    dst = (RAtom __far*)NULL;
 
    for( chain=Database->clist; chain && !done; chain=chain->cnext )
        for( group=chain->glist; group && !done; group=group->gnext )
            for( aptr=group->alist; aptr; aptr=aptr->anext )
            {   if( aptr->serno == nsrc )
                {   src = aptr;
                    if( dst )
                    {   done = True;
                        break;
                    }
                } else if( aptr->serno == ndst )
                {   dst = aptr;
                    if( src )
                    {   done = True;
                        break;
                    }
                }
            }
 
    if( !done )
    {   InvalidateCmndLine();
        WriteString("Error: Atom serial number");
        if( src )
        {   sprintf(buffer," %ld",ndst);
        } else if( dst )
        {   sprintf(buffer," %ld",nsrc);
        } else sprintf(buffer,"s %ld and %ld",nsrc,ndst);
        WriteString(buffer); WriteString(MsgStrs[StrNotFnd]);
 
   } else {
   
   pbptr = NULL;

   ForEachBond {
      if ( ( bptr->srcatom == src && bptr->dstatom == dst ) ||
        ( bptr->dstatom == src && bptr->srcatom == dst ) )
      { found = True;
        if (pbptr) {
          pbptr->bnext = bptr->bnext;
        } else {
          Database->blist = bptr->bnext;
        }
        Info.bondcount--;
        bptr->bnext = FreeBond;
        FreeBond = bptr->bnext;
      } else {
        pbptr = bptr;
      }
   }

   ForEachHBond {
      if ( ( hptr->src == src && hptr->dst == dst ) ||
        ( hptr->dst == src && hptr->src == dst ) )
      { found = True;
        if (phptr) {
          phptr->hnext = hptr->hnext;
        } else {
          Database->hlist = hptr->hnext;
        }
        Info.hbondcount--;
        hptr->hnext = FreeHBond;
        FreeHBond = hptr->hnext;
      } else {
        phptr = hptr;
      }
   }

   ForEachSBond {
      if ( ( sptr->src == src && sptr->dst == dst ) ||
        ( sptr->dst == src && sptr->src == dst ) )
      { found = True;
        if (psptr) {
          psptr->hnext = sptr->hnext;
        } else {
          Database->slist = sptr->hnext;
        }
        Info.ssbondcount--;
        sptr->hnext = FreeHBond;
        FreeHBond = sptr->hnext;
      } else {
        psptr = sptr;
      }
   }

   /* Remove the bond from the list of selected bonds */

   if (BondsSelected) {
     BondRot __far *brptr=BondsSelected;
     BondRot __far *pbrptr=NULL;

     while (brptr) {
       if ( (src == brptr->BSrcAtom && dst == brptr->BDstAtom) ||
         (src == brptr->BDstAtom && dst == brptr->BSrcAtom) ) {
         if (pbrptr) {
           pbrptr->brnext = brptr->brnext;
           if( BondSelected == brptr ) {
             BondSelected = brptr->brnext;
             if(!BondSelected) {
               BondSelected = pbrptr;
               WriteString("Previous rotation bond selected.\n");
             } else {
               WriteString("Next rotation bond selected.\n");
             }
           }
           _ffree(brptr);
           brptr = pbrptr->brnext;
         } else {
           if( BondSelected == brptr ) {
             BondSelected = brptr->brnext;
             if(!BondSelected) {
#ifdef GTKWIN
				if(Interactive)	
				EnableRotBondMenu(False);
#endif	
               WriteString("No rotation bond selected.\n");
             } else {
               WriteString("Next rotation bond selected.\n");
             }
           }
           BondsSelected = brptr->brnext;
           _ffree(brptr);
           brptr = BondsSelected;
         }
         BLastRot = -999999.;
       } else {
         brptr = brptr->brnext;
       }
     }
   }

   FindCisBonds();

   return found;
   }
   return False;
}


void ResetBondsSel( void )
{
   /* Remove all bonds from the list of selected bonds */

   if (BondsSelected) {
     BondRot __far *brptr=BondsSelected;

     while (brptr) {
       BondsSelected = brptr->brnext;
       _ffree(brptr);
       brptr = BondsSelected;
     }
     BLastRot = -999999.;
   } 
   BondsSelected = (BondRot __far *)NULL;
   BondSelected = (BondRot __far *)NULL;
#ifdef GTKWIN
   if(Interactive)
	   EnableRotBondMenu(False);
#endif   
}


static int visits;

int BondRotatable( RAtom __far *atom )
{
    int i;
    
    if (atom == NULL)
	return 1;
    if (atom->visited)
	return 1;
    if (atom == BSrcAtom)
	return 0;
    atom->visited = 1;
    
    for (i=0; i<atom->nbonds; i++)
	if (atom == BDstAtom && atom->bonds[i] == BSrcAtom)
	    continue;
	else if (!BondRotatable(atom->bonds[i]))
	    return 0;
    return 1;
}

void CreateBondAxis( Long src, Long dst )
{
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *aptr;
    register RAtom __far *sptr;
    register RAtom __far *dptr;
    register int done;
    char buffer[20];
 
    if( src == dst )
    {   InvalidateCmndLine();
        WriteString("Error: Duplicate atom serial numbers!\n");
        return;
    }
 
    done = False;
    sptr = (RAtom __far*)0;
    dptr = (RAtom __far*)0;
 
    for( chain=Database->clist; chain && !done; chain=chain->cnext )
        for( group=chain->glist; group && !done; group=group->gnext )
            for( aptr=group->alist; aptr; aptr=aptr->anext )
            {   if( aptr->serno == src )
                {   sptr = aptr;
                    if( dptr )
                    {   done = True;
                        break;
                    }
                } else if( aptr->serno == dst )
                {   dptr = aptr;
                    if( sptr )
                    {   done = True;
                        break;
                    }
                }
            }
 
    if( !done )
    {   InvalidateCmndLine();
        WriteString("Error: Atom serial number");
        if( sptr )
        {   sprintf(buffer," %ld",dst);
        } else if( dptr )
        {   sprintf(buffer," %ld",src);
        } else sprintf(buffer,"s %ld and %ld",src,dst);
        WriteString(buffer); WriteString(MsgStrs[StrNotFnd]);
 
    } else SetBondAxis( sptr, dptr );
}

void SetBondAxis( RAtom __far *src, RAtom __far *dst )
{
    int i;
    BondRot __far *brptr;

    BSrcAtom = src;
    BDstAtom = dst;
    SubtractAtoms(BDstAtom, BSrcAtom, BAxis);
    NormalizeVector(BAxis);
    
    if (!ConstructGraph()) {
	WriteString("ConstructGraph failed\n");
	return;
    }
    
    /* Ensure that this is a bond-rotatable part */
    if (!BondRotatable(BDstAtom)) {
        for ( i=0; i<BSrcAtom->nbonds; i++ ) {
          if (BSrcAtom->bonds[i] == BDstAtom ) {
            WriteString("Can't bond-rotate this.\n");
            return;
          }
        }
        CreateBond (BSrcAtom->serno,BDstAtom->serno,NormBondFlag);
        if ( NewBond ) {
          WriteString("Bond created.\n");
          NewBond->radius = 0;
          NewBond->irad = 0;
          NewBond->aradius = 0;
          NewBond->iarad = 0;
          NewBond->flag |= DashFlag;
          ReDrawFlag |=RFInitial;
        }
        if (!ConstructGraph()) {
	WriteString("ConstructGraph failed\n");
	return;
        }

        if (!BondRotatable(BDstAtom)) {
          WriteString("Can't bond-rotate this.\n");
          return;
        }
    }
    
    WriteString("Bond selected.\n");
#ifdef GTKWIN
	if(Interactive)
		EnableRotBondMenu(True);
#endif	
    brptr = BondSelected;
    BondSelected = (BondRot __far *)_fmalloc(sizeof(BondRot));
    if (brptr) {
      brptr->brnext = BondSelected;
    } else {
      BondsSelected = BondSelected;
    }
    BondSelected->brnext = (BondRot __far *)NULL;
    BondSelected->BSrcAtom = BSrcAtom;
    BondSelected->BDstAtom = BDstAtom;
    BondSelected->BRotValue = 0;
    BLastRot = -999999.;
    UpdateScrollBars();
}

void Traverse( RAtom __far *atom, Real matrix[4][4] )
{
    int i;
    Real x, y, z;
    
    if (atom == NULL)
	return;
    
    if (atom->visited)
	return;
    
    atom->visited = 1;
    
    x = (double)(atom->xorg-BSrcAtom->xorg+atom->fxorg-BSrcAtom->fxorg)
        +(double)((atom->xtrl-BSrcAtom->xtrl)/40.);
    y = (double)(atom->yorg-BSrcAtom->yorg+atom->fyorg-BSrcAtom->fyorg)
        +(double)((atom->ytrl-BSrcAtom->ytrl)/40.);
    z = (double)(atom->zorg-BSrcAtom->zorg+atom->fzorg-BSrcAtom->fzorg)
        +(double)((atom->ytrl-BSrcAtom->ytrl)/40.);
    
    atom->x = x*matrix[0][0]+y*matrix[0][1]+z*matrix[0][2]
                  +BSrcAtom->xorg-atom->xorg+BSrcAtom->fxorg-atom->fxorg;
    atom->y = x*matrix[1][0]+y*matrix[1][1]+z*matrix[1][2]
                  +BSrcAtom->yorg-atom->yorg+BSrcAtom->fyorg-atom->fyorg;
    atom->z = x*matrix[2][0]+y*matrix[2][1]+z*matrix[2][2]
                  +BSrcAtom->zorg-atom->zorg+BSrcAtom->fzorg-atom->fzorg;
    
    for (i=0; i<atom->nbonds; i++)
	Traverse(atom->bonds[i], matrix);
    
    visits++;
}

void BondRotate( void )
{
    Real matrix[4][4];
    BondRot __far *brptr;
    
    if (!BondSelected)
	return;

    if (BondSelected->BRotValue == BLastRot)
	return;

    visits = 0;
    ResetCoord();
    
    brptr = BondsSelected;
    while (brptr) {
      BSrcAtom = brptr->BSrcAtom;
      BDstAtom = brptr->BDstAtom;
      SubtractAtoms(BDstAtom, BSrcAtom, BAxis);
      NormalizeVector(BAxis);
      ResetVisited();
      RotateAxisMatrix(matrix, PI*(brptr->BRotValue),
		     BAxis[0], BAxis[1], BAxis[2]);
      BSrcAtom->visited = 1;
      Traverse(BDstAtom, matrix);
      UpdateCoord();
      brptr = brptr->brnext;
    }
    BLastRot = BondSelected->BRotValue;

    /* Make transfor.c recalculate everything */
    ReDrawFlag |= RFRefresh;
}

void WorldRotate( void )
{
    /* Fill out a 4x4 matrix representing our current transformation */
    static Real A[4][4], R[4][4], B[4][4];
    Real NRotX[3], NRotY[3], NRotZ[3];
    Real SRotX[3], SRotY[3], SRotZ[3];
    Real RMat[3][3];
    
 
    int i;
    

    if (ReDrawFlag || WRotValue[0] != WLastRX || 
      WRotValue[1] != WLastRY ||
      WRotValue[2] != WLastRZ ||
      WRotStereo != WLastRS   ||
      WTransX != WLastTX ||
      WTransY != WLastTY ||
      WTransZ != WLastTZ ) {

      if ( ( WRotValue[0] != WLastRX ) || 
        ( WRotValue[1] != WLastRY ) ||
        ( WRotValue[2] != WLastRZ ) ||
        ( WRotStereo != WLastRS  ) ) {
        
        RV2RMat(WRotValue[0]-WLastRX, 
          WRotValue[1]-WLastRY, 
          WRotValue[2]-WLastRZ,
          NRotX, NRotY, NRotZ);

        RV2RMat(WLastRX, WLastRY, WLastRZ,
          RMat[0], RMat[1], RMat[2]);

        WLRotX[0] = NRotX[0]*RMat[0][0]+NRotX[1]*RMat[1][0]+NRotX[2]*RMat[2][0];
        WLRotX[1] = NRotX[0]*RMat[0][1]+NRotX[1]*RMat[1][1]+NRotX[2]*RMat[2][1];
        WLRotX[2] = NRotX[0]*RMat[0][2]+NRotX[1]*RMat[1][2]+NRotX[2]*RMat[2][2];

        WLRotY[0] = NRotY[0]*RMat[0][0]+NRotY[1]*RMat[1][0]+NRotY[2]*RMat[2][0];
        WLRotY[1] = NRotY[0]*RMat[0][1]+NRotY[1]*RMat[1][1]+NRotY[2]*RMat[2][1];
        WLRotY[2] = NRotY[0]*RMat[0][2]+NRotY[1]*RMat[1][2]+NRotY[2]*RMat[2][2];

        WLRotZ[0] = NRotZ[0]*RMat[0][0]+NRotZ[1]*RMat[1][0]+NRotZ[2]*RMat[2][0];
        WLRotZ[1] = NRotZ[0]*RMat[0][1]+NRotZ[1]*RMat[1][1]+NRotZ[2]*RMat[2][1];
        WLRotZ[2] = NRotZ[0]*RMat[0][2]+NRotZ[1]*RMat[1][2]+NRotZ[2]*RMat[2][2];
      
        RMat2RV(&(WRotValue[0]), 
          &(WRotValue[1]), 
          &(WRotValue[2]), 
          WLRotX, WLRotY, WLRotZ);

        if (WRotStereo != 0.) {
          RV2RMat(0.,  WRotStereo, 0.,
            SRotX, SRotY, SRotZ);       	
          NRotX[0] = SRotX[0]*WLRotX[0]+SRotX[1]*WLRotY[0]+SRotX[2]*WLRotZ[0];
          NRotX[1] = SRotX[0]*WLRotX[1]+SRotX[1]*WLRotY[1]+SRotX[2]*WLRotZ[1];
          NRotX[2] = SRotX[0]*WLRotX[2]+SRotX[1]*WLRotY[2]+SRotX[2]*WLRotZ[2];

          NRotY[0] = SRotY[0]*WLRotX[0]+SRotY[1]*WLRotY[0]+SRotY[2]*WLRotZ[0];
          NRotY[1] = SRotY[0]*WLRotX[1]+SRotY[1]*WLRotY[1]+SRotY[2]*WLRotZ[1];
          NRotY[2] = SRotY[0]*WLRotX[2]+SRotY[1]*WLRotY[2]+SRotY[2]*WLRotZ[2];

          NRotZ[0] = SRotZ[0]*WLRotX[0]+SRotZ[1]*WLRotY[0]+SRotZ[2]*WLRotZ[0];
          NRotZ[1] = SRotZ[0]*WLRotX[1]+SRotZ[1]*WLRotY[1]+SRotZ[2]*WLRotZ[1];
          NRotZ[2] = SRotZ[0]*WLRotX[2]+SRotZ[1]*WLRotY[2]+SRotZ[2]*WLRotZ[2];
          
          for (i=0;i<3;i++) {
            WLRotX[i]=NRotX[i];
            WLRotY[i]=NRotY[i];
            WLRotZ[i]=NRotZ[i];          	
          }
        }

          
        RMatInv( WLRotX, WLRotY, WLRotZ, WIRotX, WIRotY, WIRotZ);

        WLastRX = WRotValue[0];
        WLastRY = WRotValue[1];
        WLastRZ = WRotValue[2];
 
      }
    
    IdentityMatrix(A);
    for (i=0; i<3; i++) {
	  A[0][i] = Scale*LRotX[i];
	  A[1][i] = Scale*LRotY[i];
	  A[2][i] = Scale*LRotZ[i];
      A[i][3] = (double)LOffset[i];
    }
    A[0][3] -= (Real)WRange;
    A[1][3] -= (Real)HRange;
    A[2][3] -= (Real)10000;
        
    /* Fill out a matrix representing the rotation we wish to do */
    IdentityMatrix(R);
    for (i=0; i<3; i++) {
      R[0][i]=WLRotX[i];
      R[1][i]=WLRotY[i];
      R[2][i]=WLRotZ[i];      
    }

    MultMatrix(R, A, B);
    
    /* Get the new values for RotX,Y,Z and X,Y,ZOffset */
    for (i=0; i<3; i++) {
	  RotX[i] = B[0][i]/Scale;
	  RotY[i] = B[1][i]/Scale;
	  RotZ[i] = B[2][i]/Scale;
    }
    XOffset = B[0][3]+WRange+WTransX*Zoom*XRange;
    YOffset = B[1][3]+HRange+WTransY*Zoom*YRange;
    ZOffset = B[2][3]+10000+WTransZ*Zoom*ZRange;
    
    
    if (UseStereo) {
      XOffset -= XRange/4;
    }
    
    
    WLastRX = WRotValue[0];
    WLastRY = WRotValue[1];
    WLastRZ = WRotValue[2];
    WLastTX = WTransX;
    WLastTY = WTransY;
    WLastTZ = WTransZ;
    WLastRS = WRotStereo;
    
    /* Make transfor.c recalculate everything */
    ReDrawFlag |= (RFRefresh|RFRotate|RFTrans);

    } 
    
}

void InitialiseWBRotate( void )
{
    BondsSelected = BondSelected = (BondRot __far *)NULL;
    WRotValue[0] = 0;
    WRotValue[1] = 0;
    WRotValue[2] = 0;
    WLastRX = WLastRY = WLastRZ = 0;
    WTransX = WTransY = WTransZ = 0;
    WLastTX = WLastTY = WLastTZ = 0;
}

