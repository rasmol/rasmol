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
/* transfor.c
 $Log$
 Revision 1.13  2008/06/18 20:04:53  yaya
 Start in infrastructure for animation
 Start on WPDB code -- HJB

 Revision 1.12  2008/06/09 17:48:12  hk0i
 added loadSelection() and saveSelection() routines for new color commands. *gm*

 Revision 1.11  2008/04/15 19:25:37  hk0i
 fixed 'color bond' bug

 Revision 1.10  2008/04/01 17:31:19  hk0i
 updated new color mode feature for dots

 Revision 1.9  2008/03/22 18:42:55  yaya
 Post release cleanup and credit to Ikonen in file headers. -- HJB

 Revision 1.8  2008/03/17 03:01:31  yaya
 Update to agree with 2.7.4.2 release and T. Ikonen GTK mods -- HJB

 Revision 1.5  2008/03/17 01:32:41  yaya
 Add gtk mods by tpikonen, and intergate with 2.7.4.2 mods -- HJB

 Revision 1.7  2008/03/16 22:25:22  yaya
 Align comments with production version; Update rasmol_install and
 rasmol_run shell scripts for Japanese and Chinese; Align logic for
 positioning and sizing initial window with windows version -- HJB

 Revision 1.4  2008/02/21 15:11:46  tpikonen
 Add GTK GUI.

 Revision 1.4  2008/01/30 03:15:55  yaya
 More post 2.7.4.1 release cleanup -- HJB

 Revision 1.6  2008/01/29 04:12:11  yaya
 Post release cleanup of problems discovered. -- HJB

 Revision 1.3  2008/01/29 04:35:26  yaya
 Postrelease update to fix problems discovered -- HJB

 Revision 1.2  2008/01/28 03:29:38  yaya
 Update CVS to RasMol_2.7.4.1 -- HJB

 Revision 1.5  2007/11/19 03:28:40  yaya
 Update to credits for 2.7.4 in manual and headers
 Mask code added -- HJB

 Revision 1.4  2007/11/16 22:48:31  yaya
 Remove use of MapNumber if favor of size of vector
 Clean up selection logic; start on script writing code -- HJB

 Revision 1.3  2007/11/13 03:22:17  yaya
 Changes to support map selectors.  Needs more work. -- HJB

 Revision 1.2  2007/09/06 12:11:26  yaya
 Changes for map resolution -- HJB

 Revision 1.1.1.1  2007/03/01 01:16:32  todorovg
 Chinese working versio from rasmol_ru initial import

 Revision 1.3  2006/11/01 03:23:51  yaya
 Update NSIS windows installer for more script types and to fix
 misplaced script instructions for data files; add document and
 script icons directly in raswin.exe; add credit line to
 G. A. Pozhvanov in comments for Russian translations. -- HJB

 Revision 1.2  2006/09/17 10:53:56  yaya
 Clean up headers and start on code for X11 -- HJB

 Revision 1.1.1.1  2006/09/16 18:46:02  yaya
 Start of RasMol Russian Translation Project based on translations
 by Gregory A. Pozhvanov of Saint Petersburg State University -- HJB

 Revision 1.1.1.1  2006/06/19 22:05:14  todorovg
 Initial Rasmol 2.7.3 Import

 Revision 1.3  2004/09/29 22:39:14  chigboc
 *** empty log message ***

 Revision 1.2  2004/09/27 14:27:50  chigboc
 *** empty log message ***

 Revision 1.1  2004/05/07 19:46:16  yaya
 Initial revision

 Revision 1.3  2004/02/15 00:24:00  yaya
 *** empty log message ***

 Revision 1.2  2003/12/13 19:26:11  yaya
 *** empty log message ***

 Revision 1.1  2003/12/12 21:10:38  yaya
 Initial revision

 Revision 1.1  2001/01/31 02:13:45  yaya
 Initial revision

 Revision 1.10  2000/08/27 00:54:51  yaya
 create rotation bond database

 Revision 1.9  2000/08/26 18:12:48  yaya
 Updates to header comments in all files

 Revision 1.8  2000/08/26 17:31:10  yaya
 Fix for world rot, remove refs to toolbar

 Revision 1.6  2000/08/21 21:07:52  yaya
 semi-final ucb mods

 Revision 1.5  2000/08/18 16:40:49  yaya
 *** empty log message ***

 Revision 1.4  2000/08/13 20:56:32  yaya
 Conversion from toolbar to menus

 Revision 1.3  2000/08/09 01:18:21  yaya
 Rough cut with ucb

 */
#include "rasmol.h"

#ifdef IBMPC
#include <windows.h>
#endif
#ifdef APPLEMAC
#include <Types.h>
#include <Errors.h>
#ifdef __CONDITIONALMACROS__
#include <Printing.h>
#else
#include <PrintTraps.h>
#endif
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRANSFORM
#include "molecule.h"
#include "abstree.h"
#include "transfor.h"
#include "cmndline.h"
#include "command.h"
#include "render.h"
#include "repres.h"
#include "graphics.h"
#include "multiple.h" /* [GSG 11/9/95] */
#include "vector.h"   /* [GSG 11/14/95] */
#include "wbrotate.h" /* [GSG 11/14/95] */
#include "langsel.h"
#include "maps.h"

#define CPKMAX  16
static ShadeRef CPKShade[] = {
     { 0, 0, 200, 200, 200 },       /*  0 Light Grey   */
     { 0, 0, 143, 143, 255 },       /*  1 Sky Blue     */
     { 0, 0, 240,   0,   0 },       /*  2 Red          */
     { 0, 0, 255, 200,  50 },       /*  3 Yellow       */
     { 0, 0, 255, 255, 255 },       /*  4 White        */
     { 0, 0, 255, 192, 203 },       /*  5 Pink         */
     { 0, 0, 218, 165,  32 },       /*  6 Golden Rod   */
     { 0, 0,   0,   0, 255 },       /*  7 Blue         */
     { 0, 0, 255, 165,   0 },       /*  8 Orange       */
     { 0, 0, 128, 128, 144 },       /*  9 Dark Grey    */
     { 0, 0, 165,  42,  42 },       /* 10 Brown        */
     { 0, 0, 160,  32, 240 },       /* 11 Purple       */
     { 0, 0, 255,  20, 147 },       /* 12 Deep Pink    */
     { 0, 0,   0, 255,   0 },       /* 13 Green        */
     { 0, 0, 178,  34,  34 },       /* 14 Fire Brick   */
     { 0, 0,  34, 139,  34 } };     /* 15 Forest Green */

#define CpkNewMax 16
static ShadeRef CpkNewShade[] = {
     { 0, 0, 211, 211, 211 },       /*  0 Light Grey   */
     { 0, 0, 135, 206, 235 },       /*  1 Sky Blue     */
     { 0, 0, 255,   0,   0 },       /*  2 Red          */
     { 0, 0, 255, 255,   0 },       /*  3 Yellow       */
     { 0, 0, 255, 255, 255 },       /*  4 White        */
     { 0, 0, 255, 192, 203 },       /*  5 Pink         */
     { 0, 0, 218, 165,  32 },       /*  6 Golden Rod   */
     { 0, 0,   0,   0, 255 },       /*  7 Blue         */
     { 0, 0, 255, 170,   0 },       /*  8 Orange       */
     { 0, 0, 105, 105, 105 },       /*  9 Dark Grey    */
     { 0, 0, 128,  40,  40 },       /* 10 Brown        */
     { 0, 0, 160,  32, 240 },       /* 11 Purple       */
     { 0, 0, 250,  22, 145 },       /* 12 Deep Pink    */
     { 0, 0,   0, 255,   0 },       /* 13 Green        */
     { 0, 0, 178,  33,  33 },       /* 14 Fire Brick   */
     { 0, 0,  34, 139,  34 } };     /* 15 Forest Green */


static ShadeRef Shapely[] = {
     { 0, 0, 140, 255, 140 },    /* ALA */
     { 0, 0, 255, 255, 255 },    /* GLY */
     { 0, 0,  69,  94,  69 },    /* LEU */
     { 0, 0, 255, 112,  66 },    /* SER */
     { 0, 0, 255, 140, 255 },    /* VAL */
     { 0, 0, 184,  76,   0 },    /* THR */
     { 0, 0,  71,  71, 184 },    /* LYS */
     { 0, 0, 160,   0,  66 },    /* ASP */
     { 0, 0,   0,  76,   0 },    /* ILE */
     { 0, 0, 255, 124, 112 },    /* ASN */
     { 0, 0, 102,   0,   0 },    /* GLU */
     { 0, 0,  82,  82,  82 },    /* PRO */
     { 0, 0,   0,   0, 124 },    /* ARG */
     { 0, 0,  83,  76,  66 },    /* PHE */
     { 0, 0, 255,  76,  76 },    /* GLN */
     { 0, 0, 140, 112,  76 },    /* TYR */
     { 0, 0, 112, 112, 255 },    /* HIS */
     { 0, 0, 255, 255, 112 },    /* CYS */
     { 0, 0, 184, 160,  66 },    /* MET */
     { 0, 0,  79,  70,   0 },    /* TRP */

     { 0, 0, 255,   0, 255 },    /* ASX */
     { 0, 0, 255,   0, 255 },    /* GLX */
     { 0, 0, 255,   0, 255 },    /* PCA */
     { 0, 0, 255,   0, 255 },    /* HYP */

     { 0, 0, 160, 160, 255 },    /*   A */
     { 0, 0, 255, 140,  75 },    /*   C */
     { 0, 0, 255, 112, 112 },    /*   G */
     { 0, 0, 160, 255, 160 },    /*   T */

     { 0, 0, 184, 184, 184 },    /* 28 -> BackBone */
     { 0, 0,  94,   0,  94 },    /* 29 -> Special  */
     { 0, 0, 255,   0, 255 } };  /* 30 -> Default  */

     
static ShadeRef AminoShade[] = {
     { 0, 0, 230,  10,  10 },    /*  0  ASP, GLU      */
     { 0, 0,  20,  90, 255 },    /*  1  LYS, ARG      */
     { 0, 0, 130, 130, 210 },    /*  2  HIS           */
     { 0, 0, 250, 150,   0 },    /*  3  SER, THR      */
     { 0, 0,   0, 220, 220 },    /*  4  ASN, GLN      */
     { 0, 0, 230, 230,   0 },    /*  5  CYS, MET      */
     { 0, 0, 200, 200, 200 },    /*  6  ALA           */
     { 0, 0, 235, 235, 235 },    /*  7  GLY           */
     { 0, 0,  15, 130,  15 },    /*  8  LEU, VAL, ILE */
     { 0, 0,  50,  50, 170 },    /*  9  PHE, TYR      */
     { 0, 0, 180,  90, 180 },    /* 10  TRP           */
     { 0, 0, 220, 150, 130 },    /* 11  PRO, PCA, HYP */
     { 0, 0, 190, 160, 110 } };  /* 12  Others        */

static int AminoIndex[] = {
      6, /*ALA*/   7, /*GLY*/   8, /*LEU*/   3,  /*SER*/
      8, /*VAL*/   3, /*THR*/   1, /*LYS*/   0,  /*ASP*/
      8, /*ILE*/   4, /*ASN*/   0, /*GLU*/  11,  /*PRO*/
      1, /*ARG*/   9, /*PHE*/   4, /*GLN*/   9,  /*TYR*/
      2, /*HIS*/   5, /*CYS*/   5, /*MET*/  10,  /*TRP*/
      4, /*ASX*/   4, /*GLX*/  11, /*PCA*/  11   /*HYP*/
                          };

static ShadeRef HBondShade[] = {
     { 0, 0, 255, 255, 255 },    /* 0  Offset =  2   */
     { 0, 0, 255,   0, 255 },    /* 1  Offset =  3   */
     { 0, 0, 255,   0,   0 },    /* 2  Offset =  4   */
     { 0, 0, 255, 165,   0 },    /* 3  Offset =  5   */
     { 0, 0,   0, 255, 255 },    /* 4  Offset = -3   */
     { 0, 0,   0, 255,   0 },    /* 5  Offset = -4   */
     { 0, 0, 255, 255,   0 } };  /* 6  Others        */


static ShadeRef StructShade[] = {
     { 0, 0, 255, 255, 255 },    /* 0  Default     */
     { 0, 0, 255,   0, 128 },    /* 1  Alpha Helix */
     { 0, 0, 255, 200,   0 },    /* 2  Beta Sheet  */
     { 0, 0,  96, 128, 255 } };  /* 3  Turn        */

static ShadeRef PotentialShade[] = {
     { 0, 0, 255,   0,   0 },    /* 0  Red     25 < V       */
     { 0, 0, 255, 165,   0 },    /* 1  Orange  10 < V <  25 */
     { 0, 0, 255, 255,   0 },    /* 2  Yellow   3 < V <  10 */
     { 0, 0,   0, 255,   0 },    /* 3  Green    0 < V <   3 */
     { 0, 0,   0, 255, 255 },    /* 4  Cyan    -3 < V <   0 */
     { 0, 0,   0,   0, 255 },    /* 5  Blue   -10 < V <  -3 */
     { 0, 0, 160,  32, 240 },    /* 6  Purple -25 < V < -10 */
     { 0, 0, 255, 255, 255 } };  /* 7  White        V < -25 */


/* Macros for commonly used loops */
#define ForEachAtom  for(chain=Database->clist;chain;chain=chain->cnext) \
                     for(group=chain->glist;group;group=group->gnext)    \
                     for(ptr=group->alist;ptr;ptr=ptr->anext)
#define ForEachBond  for(bptr=Database->blist;bptr;bptr=bptr->bnext) 
#define ForEachSurfBond  for(sbptr=Database->sblist;sbptr;sbptr=sbptr->sbnext)
#define ForEachBack  for(chain=Database->clist;chain;chain=chain->cnext) \
                     for(bptr=chain->blist;bptr;bptr=bptr->bnext)

#define MatchChar(a,b)   (((a)=='#')||((a)==(b)))

static int MaskColour[MAXMASK];
static int MaskShade[MAXMASK];


void DetermineClipping( void )
{
    register int temp;
    register int max;

    max = 0;
    if( (DrawAtoms || DrawStars || DrawSurf) && (MaxAtomRadius>max) )
      max = MaxAtomRadius;
    if( DrawBonds && (MaxBondRadius>max) )  max = MaxBondRadius;
       
    temp = ImageRadius + max;
    if( (YOffset>=temp) && (XOffset>=temp) && (YOffset+temp<YRange) )
    {   if( UseStereo )
        {   UseScreenClip = (XOffset+temp) >= (XRange>>1);
        } else UseScreenClip = (XOffset+temp) >= XRange;
    } else UseScreenClip = True;
}


void SetRadiusValue( int rad , int flag)
{
    register int irad,change;
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *ptr;
    register int incr;

    if( !Database )
        return;

    irad = (int)rint(Scale*(Real)(rad));
    iProbeRad = (int)rint(Scale*(Real)ProbeRadius);
    MaxAtomRadius = 0;
	DrawAtoms = False;
	DrawStars = False; 
    DrawSurf = False; 
     change = False;

    ForEachAtom
        {  incr = (ptr->flag&ExpandFlag)?iProbeRad:0;
        if( ptr->flag & SelectFlag )
            {   if( (irad+incr)>MaxAtomRadius )
                MaxAtomRadius = irad+incr;
		if (flag & SphereFlag )
		{  ptr->flag |= SphereFlag|(flag&ExpandFlag);
		   ptr->flag &= ~(StarFlag|TouchFlag);
		} else if (flag & StarFlag)
		{  ptr->flag |= StarFlag|(flag&ExpandFlag);
                   ptr->flag &= ~(SphereFlag|TouchFlag);
                } else if (flag & TouchFlag)
                {  ptr->flag |= TouchFlag|(flag&ExpandFlag);
                   ptr->flag &= ~(SphereFlag|StarFlag);
			}
            ptr->radius = rad;
            ptr->irad = irad;
            change = True;
        } else if( ptr->flag & SphereFlag )
        {	DrawAtoms = True;
            if( (ptr->irad+incr)>MaxAtomRadius )
                MaxAtomRadius = ptr->irad+incr;
        } else if( ptr->flag & StarFlag )
		{	DrawStars = True;
            if( (ptr->irad+incr)>MaxAtomRadius )
                MaxAtomRadius = ptr->irad+incr;
        } else if( ptr->flag & TouchFlag )
              {       DrawSurf = True;
            if( (ptr->irad+incr)>MaxAtomRadius )
                MaxAtomRadius = ptr->irad+incr;
        }
        }

    if( change )
    {   if ((flag&SphereFlag) == SphereFlag )
        { DrawAtoms = True;
        } else if ((flag&StarFlag) == StarFlag )
        { DrawStars = True;
        } else
          DrawSurf = True;
        DetermineClipping();
        VoxelsClean = False;
        BucketFlag = False;
    }
}


void SetRadiusTemperature( int flag )
{
    register int rad,irad,change;
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *ptr;
    register int incr;

    if( !Database )
        return;

    MaxAtomRadius = 0;
	DrawAtoms = False;
	DrawStars = False; 
    change = False;
    iProbeRad = (int)rint(Scale*(Real)ProbeRadius);

    ForEachAtom
        {  incr = (ptr->flag&ExpandFlag)?iProbeRad:0;
        if( (ptr->flag&SelectFlag) && (ptr->temp>0) )
        {   rad = (5*ptr->temp)>>1;
            if( rad>750 ) rad = 750;

            irad = (int)rint(Scale*(Real)(rad));
            if( irad+incr>MaxAtomRadius )
                MaxAtomRadius = irad+incr;
			if (flag == SphereFlag )
			{	ptr->flag |= SphereFlag|(flag&ExpandFlag);
				ptr->flag &= ~StarFlag;
			} else 
			{	ptr->flag |= StarFlag|(flag&ExpandFlag);
				ptr->flag &= ~SphereFlag;
			}
            ptr->radius = rad;
            ptr->irad = irad;
            change = True;
        } else if( ptr->flag & SphereFlag )
        {	DrawAtoms = True;
            if( (ptr->irad+incr)>MaxAtomRadius )
                MaxAtomRadius = ptr->irad+incr;
        } else if( ptr->flag & StarFlag )
		{	DrawStars = True;
            if( (ptr->irad+incr)>MaxAtomRadius )
                MaxAtomRadius = ptr->irad+incr;
        }
        }

    if( change )
    {   if ((flag&SphereFlag) == SphereFlag )
        { DrawAtoms = True;
        } else { 
          DrawStars = True;
        }
        DetermineClipping();
        VoxelsClean = False;
        BucketFlag = False;
    }
}


void SetVanWaalRadius( int flag )
{
    register int rad,change;
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *ptr;

    if( !Database )
        return;

    MaxAtomRadius = 0;
	DrawAtoms = False;
	DrawStars = False; 
    DrawSurf = False; 
    change = False;

    iProbeRad = (int)rint(Scale*(Real)ProbeRadius);

    ForEachAtom
        if( ptr->flag&SelectFlag )
        {   rad = ElemVDWRadius(ptr->elemno);
            ptr->irad = (int)rint(Scale*(Real)(rad));
            ptr->radius = rad;
            change = True;

			if ( flag&SphereFlag )
			{	ptr->flag |= SphereFlag;
				ptr->flag &= ~(StarFlag|TouchFlag);
			} else if ( flag&StarFlag )
			{	ptr->flag |= StarFlag;
				ptr->flag &= ~(SphereFlag|TouchFlag);
			} else 
                          {       ptr->flag |= TouchFlag;
                                  ptr->flag &= ~(SphereFlag | StarFlag);
			}
            if (flag&ExpandFlag)
            {
              if( (ptr->irad)+iProbeRad>MaxAtomRadius )
                MaxAtomRadius = (ptr->irad)+iProbeRad;
                ptr->flag |= ExpandFlag;
            } else {
            if( ptr->irad>MaxAtomRadius )
                MaxAtomRadius = ptr->irad;
                ptr->flag &= ~ExpandFlag;
            }
        } else if( ptr->flag & SphereFlag )
        {   int iroff;
            iroff = (ptr->flag&ExpandFlag)?iProbeRad:0;
            DrawAtoms = True;
            if( (ptr->irad)+iroff>MaxAtomRadius )
                MaxAtomRadius = (ptr->irad)+iroff;
        } else if( ptr->flag & StarFlag )
          {   int iroff;
              iroff = (ptr->flag&ExpandFlag)?iProbeRad:0;
              DrawStars = True;
              if( (ptr->irad)+iroff>MaxAtomRadius )
              MaxAtomRadius = (ptr->irad)+iroff;
        } else if( ptr->flag & TouchFlag )
          {   int iroff;
              iroff = (ptr->flag&ExpandFlag)?iProbeRad:0;
              DrawSurf = True;
              if( (ptr->irad)+iroff>MaxAtomRadius )
              MaxAtomRadius = (ptr->irad)+iroff;
        }

    if( change )
    {   if ((flag&SphereFlag) == SphereFlag )
        { DrawAtoms = True;
        } else if ((flag&StarFlag) == StarFlag ) { 
          DrawStars = True;
        } else if ((flag&TouchFlag) == TouchFlag ) { 
          DrawSurf = True;
        }
        DetermineClipping();
        VoxelsClean = False;
        BucketFlag = False;
    }
}


void DisableSpacefill( void )
{
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *ptr;
    register int incr;

    if( !Database )
        return;

    MaxAtomRadius = 0;
    DrawAtoms = False;
    DrawStars = False;
    DrawSurf  = False;
    iProbeRad = (int)rint(Scale*(Real)ProbeRadius);    
    
    ForEachAtom
        {  incr = (ptr->flag&ExpandFlag)?iProbeRad:0;
        if( !(ptr->flag&SelectFlag) )
        {   if( ptr->flag&SphereFlag )
            {   if( (ptr->irad+incr)>MaxAtomRadius )
                    MaxAtomRadius = ptr->irad+incr;
                DrawAtoms = True;
            } 
            if( ptr->flag&StarFlag )
            {   if( (ptr->irad+incr)>MaxAtomRadius )
                    MaxAtomRadius = ptr->irad+incr;
                DrawStars = True;
            }
            if( ptr->flag&TouchFlag )
            {   if( (ptr->irad+incr)>MaxAtomRadius )
                    MaxAtomRadius = ptr->irad+incr;
                DrawSurf = True;
            }
        } else if( ptr->flag&SphereFlag ||
                   ptr->flag&StarFlag ||
                   ptr->flag&TouchFlag ||
                   ptr->flag&ExpandFlag )
          {
            ptr->flag &= ~(SphereFlag|StarFlag|TouchFlag|ExpandFlag);
          }
          }

    DetermineClipping();
    VoxelsClean = False;
    BucketFlag = False;
}


void EnableWireframe( int mask, int rad, int arad )
{
    register Bond __far *bptr;
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *ptr;
    register int flag, irad, iarad;
    register int starrad, istarrad, change;

    if( !Database )
        return;

    DrawBonds = False;
    MaxBondRadius = 0;
    irad = (int)rint(Scale*(Real)(rad));
    if ( arad < rad ) {
      iarad = (int)rint(Scale*(Real)(arad));
    } else {
      iarad = irad;
    }

    ForEachBond
    {   flag = ZoneBoth? bptr->dstatom->flag & bptr->srcatom->flag
                       : bptr->dstatom->flag | bptr->srcatom->flag;

        if( flag&SelectFlag )
        {   DrawBonds = True;
            bptr->flag &= ~DrawBondFlag;
            bptr->flag |= mask;
            if( mask == CylinderFlag )
            {   if( irad>MaxBondRadius )
                    MaxBondRadius = irad;
                bptr->radius = rad;
                bptr->irad = irad;
                if ( arad < rad ) {
                  bptr->aradius = arad;
                  bptr->iarad = iarad;
                } else {
		  bptr->aradius = rad;
                  bptr->iarad = irad;
                }
            }
        } else if( bptr->flag&DrawBondFlag )
        {    DrawBonds = True;
             if( bptr->flag&CylinderFlag )
                 if( bptr->irad>MaxBondRadius )
                     MaxBondRadius = bptr->irad;
        }
    }

    if ( MarkAtoms & (AllAtomFlag | NonBondFlag) )
    { if( rad <= 50 )
		starrad = 75;
	  else
		starrad = (int) (1.5*rad);
      istarrad = (int)rint(Scale*(Real)(starrad));
      change = False;
      ForEachAtom
      { if ( (ptr->flag & SelectFlag) &&
          ((MarkAtoms&AllAtomFlag) || (ptr->flag&NonBondFlag)) ) 
        {	if( rad == 0 )
			{	ptr->flag |= StarFlag;
				ptr->flag &= ~SphereFlag;
			} else
			{	ptr->flag |= SphereFlag;
				ptr->flag &= ~StarFlag;
			}
           ptr->radius = starrad;
           ptr->irad = istarrad;
           change = True;
        }
      }
      if ( change )
	{   if ( rad == 0 )
	    {  DrawStars = True;
        } else {
           DrawAtoms = True;
        }
        MaxAtomRadius = istarrad;
        DetermineClipping();
        VoxelsClean = False;
        BucketFlag = False;        
      }
    }
    DetermineClipping();
}


void DisableWireframe( void )
{
    register Bond __far *bptr;
    register int flag;

    if( !Database || !DrawBonds )
        return;

    DrawBonds = False;
    MaxBondRadius = 0;

    ForEachBond
    {   flag = ZoneBoth? bptr->dstatom->flag & bptr->srcatom->flag
                       : bptr->dstatom->flag | bptr->srcatom->flag;

        if( flag&SelectFlag )
        {   bptr->flag &= ~DrawBondFlag;
        } else if( bptr->flag&DrawBondFlag )
        {   DrawBonds = True;
            if( bptr->flag&CylinderFlag )
                if( bptr->irad>MaxBondRadius )
                    MaxBondRadius = bptr->irad;
        }
    }
    DetermineClipping();
}


void EnableBackbone( int mask, int rad, int arad )
{
    register Chain __far *chain;
    register Bond __far *bptr;
    register int flag,irad,iarad;

    if( !Database )
        return;

    irad = (int)rint(Scale*(Real)(rad));
    if ( arad < rad ) {
      iarad = (int)rint(Scale*(Real)(arad));
    } else {
      iarad = irad;
    }

    ForEachBack
    {   flag = ZoneBoth? bptr->dstatom->flag & bptr->srcatom->flag
                       : bptr->dstatom->flag | bptr->srcatom->flag;

        if( flag&SelectFlag )
        {   bptr->flag &= ~DrawBondFlag;
            bptr->flag |= mask;
            if( mask == CylinderFlag )
            {   bptr->radius = rad;
                bptr->irad = irad;
                if (arad < rad) {
                  bptr->aradius = arad;
                  bptr->iarad = iarad;
                } else {
                  bptr->aradius = rad;
                  bptr->iarad = irad;
                }
            }
        } 
    }
}


void DisableBackbone( void )
{
    register Chain __far *chain;
    register Bond __far *bptr;

    if( !Database )
        return;

    if( ZoneBoth )
    {   ForEachBack
            if( (bptr->dstatom->flag&bptr->srcatom->flag) & SelectFlag )
                bptr->flag &= ~DrawBondFlag;
    } else ForEachBack
        if( (bptr->dstatom->flag|bptr->srcatom->flag) & SelectFlag )
            bptr->flag &= ~DrawBondFlag;
}


void SetHBondStatus( int hbonds, int enable, int rad, int arad )
{
    register HBond __far *list;
    register HBond __far *ptr;
    register RAtom __far *src;
    register RAtom __far *dst;
    register int flag, irad, iarad;

    if( !Database )
        return;

    if( hbonds )
    {   if( enable && (Info.hbondcount<0) )
            CalcHydrogenBonds();
        list = Database->hlist;
    } else 
    {   if( enable && (Info.ssbondcount<0) )
            FindDisulphideBridges();
        list = Database->slist;
    }

    irad = (int)rint(Scale*(Real)(rad));
    if ( arad < rad ) {
      iarad = (int)rint(Scale*(Real)(arad));
    } else {
      iarad = irad;
    }

    for( ptr=list; ptr; ptr=ptr->hnext )
    {   src = ptr->src;  dst = ptr->dst;

        flag = ZoneBoth? src->flag&dst->flag : src->flag|dst->flag;
        if( flag & SelectFlag ) 
        {   ptr->flag &= ~DrawBondFlag;
            if( enable )
            {   if( rad )
                {   ptr->flag |= CylinderFlag;
                    ptr->radius = rad;
                    ptr->irad = irad;
                    if ( arad < rad ) {
                      ptr->aradius = arad;
                      ptr->iarad = iarad;
                    } else {
                      ptr->aradius = rad;
                      ptr->iarad = irad;
                    }
                } else ptr->flag |= WireFlag;
            }
        }
    }
}


void SetRibbonStatus( int enable, int flag, int width )
{
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *ptr;

    if( !Database )
        return;

    /* Ribbons already disabled! */
    if( !enable && !DrawRibbon )
        return;

    if( Info.helixcount < 0 )
        DetermineStructure(False);

    DrawRibbon = False;
    for( chain=Database->clist; chain; chain=chain->cnext )
        for( group=chain->glist; group; group=group->gnext )
            if( enable )
            {   if( group->flag & DrawKnotFlag )
                    DrawRibbon = True;
                
                for( ptr=group->alist; ptr; ptr=ptr->anext )
                    if( IsAlphaCarbon(ptr->refno) )
                    {   if( ptr->flag&SelectFlag )
                        {   group->flag &= ~DrawKnotFlag;
                            group->flag |= flag;
                            if( !width )
                            {   if( group->struc & (HelixFlag|SheetFlag) )
                                {      group->width = 380;
                                } else group->width = 100;
                            } else group->width = width;
                            DrawRibbon = True;
                        }
                        break;

                    } else if( IsSugarPhosphate(ptr->refno) )
                    {   if( ptr->flag&SelectFlag )
                        {   group->width = width? width : 720;
                            group->flag &= ~DrawKnotFlag;
                            group->flag |= flag;
                            DrawRibbon = True;
                        }
                        break;
                    }


            } else  /* Disable Ribbon */
                if( group->flag & DrawKnotFlag )
                {   for( ptr=group->alist; ptr; ptr=ptr->anext )
                        if( IsAlphaCarbon(ptr->refno) ||
                            IsSugarPhosphate(ptr->refno) )
                        {   if( ptr->flag&SelectFlag )
                                group->flag &= ~DrawKnotFlag;
                            break;
                        }
                    if( group->flag & DrawKnotFlag ) 
                        DrawRibbon = True;
                }
}


void SetRibbonCartoons( void )
{
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *ptr;

    if( !Database )
        return;

    if( Info.helixcount < 0 )
        DetermineStructure(False);

    /* DrawBetaArrows = True; */
    /* CartoonHeight = 120;   */

    DrawRibbon = False;
    for( chain=Database->clist; chain; chain=chain->cnext )
        for( group=chain->glist; group; group=group->gnext )
        {   if( group->flag & DrawKnotFlag )
                DrawRibbon = True;
                
            for( ptr=group->alist; ptr; ptr=ptr->anext )
                if( IsAlphaCarbon(ptr->refno) )
                {   if( ptr->flag&SelectFlag )
                    {   group->flag &= ~DrawKnotFlag;
                        if( group->struc & (HelixFlag|SheetFlag) )
                        {   group->flag |= CartoonFlag;
                            group->width = 380;
                        } else 
                        {   group->flag |= TraceFlag;
                            group->width = 100;
                        }
                        DrawRibbon = True;
                    }
                    break;

                } else if( IsSugarPhosphate(ptr->refno) )
                {   if( ptr->flag&SelectFlag )
                    {   group->flag &= ~DrawKnotFlag;
                        group->flag |= RibbonFlag;
                        group->width = 720;
                        DrawRibbon = True;
                    }
                    break;
                }
            }
}


void SetTraceTemperature( void )
{
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *ptr;
    register int init,flag;
    register int min = 0,max = 0;
    register Real coeff;

    if( !Database )
        return;

    flag = 0;
    init = False;
    for( chain=Database->clist; chain; chain=chain->cnext )
        for( group=chain->glist; group; group=group->gnext )
            for( ptr=group->alist; ptr; ptr=ptr->anext )
                if( IsAlphaCarbon(ptr->refno) || IsSugarPhosphate(ptr->refno) )
                {   flag |= ptr->flag;
                    if( init )
                    {   if( ptr->temp<min ) 
                        {   min = ptr->temp;
                        } else if( ptr->temp>max )
                            max = ptr->temp;
                    } else
                    {   min = max = ptr->temp;
                        init = True;
                    }
                    break;
                }

    /* No groups selected! */
    if( !(flag&SelectFlag) )
        return;

    if( Info.helixcount < 0 )
        DetermineStructure(False);

    if( max != min )
    {   coeff = 200.0/(max-min);
    } else coeff = 0.0;

    DrawRibbon = False;
    for( chain=Database->clist; chain; chain=chain->cnext )
        for( group=chain->glist; group; group=group->gnext )
        {   if( group->flag & DrawKnotFlag )
                DrawRibbon = True;
                
            for( ptr=group->alist; ptr; ptr=ptr->anext )
                if( IsAlphaCarbon(ptr->refno) || IsSugarPhosphate(ptr->refno) )
                {   if( ptr->flag&SelectFlag )
                    {   group->width = (int)(coeff*(ptr->temp-min))+50;
                        group->flag &= ~DrawKnotFlag;
                        group->flag |= TraceFlag;
                        DrawRibbon = True;
                    }
                    break;
                }
        }
}



/*===========================*/
/* Atom Selection Functions! */
/*===========================*/

void DisplaySelectCount( void )
{
    char buffer[40];

    if( FileDepth == -1 )
    {   InvalidateCmndLine();
        if( SelectCount==0 )
        {   WriteString("No atoms selected!\n");
        } else if( SelectCount>1 )
        {   sprintf(buffer,"%ld atoms selected!\n",(long)SelectCount);
            WriteString(buffer);
        } else WriteString("1 atom selected!\n");
    }

    if( DisplayMode )
        ReDrawFlag |= RFRefresh;
    AdviseUpdate(AdvSelectCount);
}


void SelectArea( int mode, int count, int xo, int yo, int x, int y )
{
    register Bond __far *bptr;
	register SurfBond __far *sbptr;
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *ptr;
	register int x1,x2,y1,y2;
	register int Cx,Cy;

    if( !Database )
        return;

#ifdef INVERT
	yo = YRange - yo;
	y = YRange - y;
#endif

/*Adjust to cursor display*/
#ifdef IBMPC
	Cx = 0;
	Cy = 1;
#else
	Cx = 0;
	Cy = 0;
#endif
	
	x1 = MinFun(xo,x) - Cx;
	x2 = MaxFun(xo,x) - Cx;
	y1 = MinFun(yo,y) - Cy;
	y2 = MaxFun(yo,y) - Cy;

	if( DrawArea )
	{	AreaX1 = x1;
		AreaX2 = x2;
		AreaY1 = y1;
		AreaY2 = y2;
	}
  
	/*if count, perform a full atom selection and count atoms*/
	if( count )
	{	SelectCount = 0;
		if( mode==0 )
		{    ForEachAtom
			   if( ptr->x>x1 && ptr->x<=x2 && ptr->y>y1 && ptr->y<=y2 )
			    {   ptr->flag |= SelectFlag;
			        SelectCount++;
			    } else ptr->flag &= ~SelectFlag;
		} else if( mode==1 )
		{    ForEachAtom
			   if( ptr->x>x1 && ptr->x<=x2 && ptr->y>y1 && ptr->y<=y2 )
			    {   ptr->flag |= SelectFlag;
			        SelectCount++;
			    } else if( ptr->flag&SelectFlag )
				{   SelectCount++;
				}
		} else /*mode = -1 */
		{    ForEachAtom
			   if( ptr->x>x1 && ptr->x<=x2 && ptr->y>y1 && ptr->y<=y2 )
			    {   ptr->flag &= ~SelectFlag;
			    } else if( ptr->flag&SelectFlag )
				{   SelectCount++;
				}
		}

	    if( ZoneBoth )
	    {   ForEachBond
	           if( (bptr->srcatom->flag&bptr->dstatom->flag) & SelectFlag )
	           {   bptr->flag |= SelectFlag;
	           } else bptr->flag &= ~SelectFlag;
	        ForEachSurfBond
	           if( (sbptr->srcatom->flag&sbptr->dstatom->flag) & SelectFlag )
	           {   sbptr->flag |= SelectFlag;
	           } else sbptr->flag &= ~SelectFlag;
	    } else {
	        ForEachBond
	           if( (bptr->srcatom->flag|bptr->dstatom->flag) & SelectFlag )
	           {   bptr->flag |= SelectFlag;
	           } else bptr->flag &= ~SelectFlag;
	        ForEachSurfBond
	           if( (sbptr->srcatom->flag|sbptr->dstatom->flag) & SelectFlag )
	           {   sbptr->flag |= SelectFlag;
	           } else sbptr->flag &= ~SelectFlag;
	    }
		DisplaySelectCount();
	} else {	/*Go fast for quick redraw*/
		if( mode==0 )
		{    ForEachAtom
			    if( ptr->x>x1 && ptr->x<=x2 && ptr->y>y1 && ptr->y<=y2 )
			    {   ptr->flag |= SelectFlag;
			    } else ptr->flag &= ~SelectFlag;
		} else if( mode==1 )
		{    ForEachAtom
			    if( ptr->x>x1 && ptr->x<=x2 && ptr->y>y1 && ptr->y<=y2 )
					ptr->flag |= SelectFlag;
		} else /*mode = -1 */
		{    ForEachAtom
			    if( ptr->x>x1 && ptr->x<=x2 && ptr->y>y1 && ptr->y<=y2 )
					ptr->flag &= ~SelectFlag;
		}
	}
}


void SelectZone( int mask )
{
    register Bond __far *bptr;
    register SurfBond __far *sbptr;
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *ptr;

    if( !Database )
        return;

    SelectCount = 0;
    ForEachAtom
        if( ptr->flag & mask )
        {   ptr->flag |= SelectFlag;
            SelectCount++;
        } else ptr->flag &= ~SelectFlag;
    DisplaySelectCount();

    if( ZoneBoth )
    {   ForEachBond
           if( (bptr->srcatom->flag&bptr->dstatom->flag) & SelectFlag )
           {   bptr->flag |= SelectFlag;
           } else bptr->flag &= ~SelectFlag;
        ForEachSurfBond
           if( (sbptr->srcatom->flag&sbptr->dstatom->flag) & SelectFlag )
           {   sbptr->flag |= SelectFlag;
               DrawSurf = True;
               sbptr->dstatom->flag |= TouchFlag;
               sbptr->srcatom->flag |= TouchFlag;
           } else sbptr->flag &= ~SelectFlag;
    } else {
        ForEachBond
           if( (bptr->srcatom->flag|bptr->dstatom->flag) & SelectFlag )
           {   bptr->flag |= SelectFlag;
           } else bptr->flag &= ~SelectFlag;
         ForEachSurfBond
           if( (sbptr->srcatom->flag|sbptr->dstatom->flag) & SelectFlag )
           {   sbptr->flag |= SelectFlag;
               DrawSurf = True;
               sbptr->dstatom->flag |= TouchFlag;
               sbptr->srcatom->flag |= TouchFlag;
           } else sbptr->flag &= ~SelectFlag;
    }
}


void RestrictZone( int mask )
{
    register Bond __far *bptr;
    register SurfBond __far *sbptr;
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *ptr;
    register int flag;

    if( !Database )
        return;

    DrawAtoms = False;   MaxAtomRadius = 0;
    DrawStars = False;
    DrawSurf = False;
    DrawBonds = False;   MaxBondRadius = 0;
    
    SelectCount = 0;
    ForEachAtom
        if( ptr->flag & mask )
        {   ptr->flag |= SelectFlag;
            SelectCount++;

            if( ptr->flag & SphereFlag )
            {   DrawAtoms = True;
                if( ptr->irad>MaxAtomRadius )
                    MaxAtomRadius = ptr->irad;
            }
            if( ptr->flag & StarFlag )
            {   DrawStars = True;
                if( ptr->irad>MaxAtomRadius )
                    MaxAtomRadius = ptr->irad;
            }
            if( ptr->flag & TouchFlag )
            {   DrawSurf = True;
                if( ptr->irad>MaxAtomRadius )
                     MaxAtomRadius = ptr->irad;
            }
            if( ptr->flag & ExpandFlag )
            {  if( (ptr->irad)+iProbeRad > MaxAtomRadius )
                   MaxAtomRadius = (ptr->irad)+iProbeRad;
            }
        } else 
        {   ptr->flag &= ~(SelectFlag|SphereFlag|StarFlag|TouchFlag|ExpandFlag);
            if( ptr->label )
            {   DeleteLabel( (Label*)ptr->label );
                ptr->label = (void*)0;
            }
        }
    DisplaySelectCount();
    
    ForEachBond
    {   /* Ignore ZoneBoth setting! */
        flag = bptr->dstatom->flag & bptr->srcatom->flag;
        if( flag & SelectFlag )
        {   bptr->flag |= SelectFlag;
            if( bptr->flag&DrawBondFlag )
            {   DrawBonds = True;
                if( bptr->flag & CylinderFlag )
                    if( bptr->irad>MaxBondRadius )
                        MaxBondRadius = bptr->irad;
            } 
        } else bptr->flag &= ~(SelectFlag|DrawBondFlag);
    }
    
    ForEachSurfBond
    {   /* Ignore ZoneBoth setting! */
        flag = sbptr->dstatom->flag & sbptr->srcatom->flag;
        if( flag & SelectFlag )
        {   sbptr->flag |= SelectFlag;
            DrawSurf = True;
            sbptr->dstatom->flag |= TouchFlag;
            sbptr->srcatom->flag |= TouchFlag;
        } else sbptr->flag &= ~(SelectFlag);
    }

    ForEachBack
    {   /* Ignore ZoneBoth setting! */
        flag = bptr->dstatom->flag & bptr->srcatom->flag;
        if( !(flag&SelectFlag) )
            bptr->flag &= ~(SelectFlag|DrawBondFlag);
    }

    if( DrawRibbon )
    {   DrawRibbon = False;
        for( chain=Database->clist; chain; chain=chain->cnext )
            for( group=chain->glist; group; group=group->gnext )
                if( group->flag & DrawKnotFlag )
                {   for( ptr=group->alist; ptr; ptr=ptr->anext )
                        if( IsAlphaCarbon(ptr->refno) ||
                            IsSugarPhosphate(ptr->refno) )
                        {   if( !(ptr->flag&SelectFlag) )
                                group->flag &= ~DrawKnotFlag;
                            break;
                        }
                    if( group->flag & DrawKnotFlag ) 
                        DrawRibbon = True;
                }
    }

    DetermineClipping();
    VoxelsClean = False;
    BucketFlag = False;
}


void SelectZoneExpr( Expr *expr )
{
    register Bond __far *bptr;
    register SurfBond __far *sbptr;
    register AtomSet __far *pset;
	register int i;

    if( !Database )
        return;

    SelectCount = 0;
	/*Shortcut for defined atomsets*/
	if( expr->type==OpMember )
	{	for( QChain=Database->clist; QChain; QChain=QChain->cnext )
		    for( QGroup=QChain->glist; QGroup; QGroup=QGroup->gnext )
		        for( QAtom=QGroup->alist; QAtom; QAtom=QAtom->anext )
		            QAtom->flag &= ~SelectFlag;

		pset = expr->rgt.set;
	    while( pset )
		{   for( i=0; i<pset->count; i++ )
		    {   QAtom = pset->data[i];
				QAtom->flag |= SelectFlag;
		        SelectCount++;
			}
			pset = pset->next;
		}
    } else
	{	for( QChain=Database->clist; QChain; QChain=QChain->cnext )
        for( QGroup=QChain->glist; QGroup; QGroup=QGroup->gnext )
            for( QAtom=QGroup->alist; QAtom; QAtom=QAtom->anext )
                if( EvaluateExpr(expr) )
                {   QAtom->flag |= SelectFlag;
                    SelectCount++;
                } else QAtom->flag &= ~SelectFlag;
    }
    
    DisplaySelectCount();

    if( ZoneBoth )
    {   ForEachBond
           if( (bptr->srcatom->flag&bptr->dstatom->flag) & SelectFlag )
           {   bptr->flag |= SelectFlag;
           } else bptr->flag &= ~SelectFlag;
        ForEachSurfBond
           if( (sbptr->srcatom->flag&sbptr->dstatom->flag) & SelectFlag )
           {   sbptr->flag |= SelectFlag;
           } else sbptr->flag &= ~SelectFlag;
    } else 
    {
        ForEachBond
           if( (bptr->srcatom->flag|bptr->dstatom->flag) & SelectFlag )
           {   bptr->flag |= SelectFlag;
           } else bptr->flag &= ~SelectFlag;	
        ForEachSurfBond
           if( (sbptr->srcatom->flag|sbptr->dstatom->flag) & SelectFlag )
           {   sbptr->flag |= SelectFlag;
           } else sbptr->flag &= ~SelectFlag;
    }
}


void RestrictZoneExpr( Expr *expr )
{
    register Bond __far *bptr;
    register SurfBond __far *sbptr;
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *ptr;
    register int flag;

    if( !Database )
        return;

    DrawAtoms = False;   MaxAtomRadius = 0;
    DrawStars = False;
    DrawBonds = False;   MaxBondRadius = 0;

    SelectCount = 0;
    for( QChain=Database->clist; QChain; QChain=QChain->cnext )
        for( QGroup=QChain->glist; QGroup; QGroup=QGroup->gnext )
            for( QAtom=QGroup->alist; QAtom; QAtom=QAtom->anext )
                if( EvaluateExpr(expr) )
                {   QAtom->flag |= SelectFlag;
                    SelectCount++;

                    if( QAtom->flag & SphereFlag )
                    {   DrawAtoms = True;
                        if( QAtom->irad>MaxAtomRadius )
                            MaxAtomRadius = QAtom->irad;
                    }
                    if( QAtom->flag & StarFlag )
                    {   DrawStars = True;
                        if( QAtom->irad>MaxAtomRadius )
                            MaxAtomRadius = QAtom->irad;
                    }
                    if( QAtom->flag & ExpandFlag )
                    {   if( (QAtom->irad)+iProbeRad>MaxAtomRadius )
                            MaxAtomRadius = (QAtom->irad)+iProbeRad;
                    }

                }  else 
                {   QAtom->flag &=
                        ~(SelectFlag|SphereFlag|StarFlag|ExpandFlag);
                    if( QAtom->label )
                    {   DeleteLabel( (Label*)QAtom->label );
                        QAtom->label = (void*)0;
                    }
                }
    DisplaySelectCount();

    ForEachBond
    {   /* Ignore ZoneBoth setting! */
        flag = bptr->dstatom->flag & bptr->srcatom->flag;
        if( flag & SelectFlag )
        {   bptr->flag |= SelectFlag;
            if( bptr->flag & CylinderFlag )
            {   DrawBonds = True;
                if( bptr->irad>MaxBondRadius )
                    MaxBondRadius = bptr->irad;
            } else if( bptr->flag&WireFlag )
                DrawBonds = True;
        } else bptr->flag &= ~(SelectFlag|DrawBondFlag);
    }
    
    ForEachSurfBond
    {   /* Ignore ZoneBoth setting! */
        flag = sbptr->dstatom->flag & sbptr->srcatom->flag;
        if( flag & SelectFlag )
        {   sbptr->flag |= SelectFlag;
            DrawSurf = True;
            sbptr->dstatom->flag |= TouchFlag;
            sbptr->srcatom->flag |= TouchFlag;
        } else sbptr->flag &= ~(SelectFlag);
    }


    ForEachBack
    {   /* Ignore ZoneBoth setting! */
        flag = bptr->dstatom->flag & bptr->srcatom->flag;
        if( !(flag&SelectFlag) )
            bptr->flag &= ~(SelectFlag|DrawBondFlag);
    }

    if( DrawRibbon )
    {   DrawRibbon = False;
        for( chain=Database->clist; chain; chain=chain->cnext )
            for( group=chain->glist; group; group=group->gnext )
                if( group->flag & DrawKnotFlag )
                {   for( ptr=group->alist; ptr; ptr=ptr->anext )
                        if( IsAlphaCarbon(ptr->refno) ||
                            IsSugarPhosphate(ptr->refno) )
                        {   if( !(ptr->flag&SelectFlag) )
                                group->flag &= ~DrawKnotFlag;
                            break;
                        }
                    if( group->flag & DrawKnotFlag )
                        DrawRibbon = True;
                }
    }

    DetermineClipping();
    VoxelsClean = False;
    BucketFlag = False;
}

void SelectAtom( int shift, RAtom __far *PAtom, Group __far *PGroup )
{	register Bond __far *bptr;
    register SurfBond __far *sbptr;
	
	SelectCount = 0;
	for( QChain=Database->clist; QChain; QChain=QChain->cnext )
		for( QGroup=QChain->glist; QGroup; QGroup=QGroup->gnext )
			for( QAtom=QGroup->alist; QAtom; QAtom=QAtom->anext )
				if( QAtom->serno == PAtom->serno || 
					(ModelInclude && 
					 QGroup->serno == PGroup->serno &&
					 QAtom->serno - QGroup->alist->serno == 
					 PAtom->serno - PGroup->alist->serno) )
	            {	if( shift == -1 )
					{	QAtom->flag &= ~SelectFlag;
					} else
					{	QAtom->flag |= SelectFlag;
						SelectCount++;
					}
				} else 
				{	if( !shift ) 
					{	QAtom->flag &= ~SelectFlag;
					} else
					{	if( QAtom->flag & SelectFlag)
							SelectCount++;
					}
				}

	DisplaySelectCount();

	if( ZoneBoth )
	{   ForEachBond
		if( (bptr->srcatom->flag&bptr->dstatom->flag) & SelectFlag )
           {   bptr->flag |= SelectFlag;
           } else bptr->flag &= ~SelectFlag;
	} else {
	    ForEachSurfBond
        if( (sbptr->srcatom->flag|sbptr->dstatom->flag) & SelectFlag )
           {  sbptr->flag |= SelectFlag;
           } else sbptr->flag &= ~SelectFlag;

	}
}

void SelectGroup( int shift, Group __far *PGroup )
{	register Bond __far *bptr;
    register SurfBond __far *sbptr;

	SelectCount = 0;
	for( QChain=Database->clist; QChain; QChain=QChain->cnext )
		for( QGroup=QChain->glist; QGroup; QGroup=QGroup->gnext )
			for( QAtom=QGroup->alist; QAtom; QAtom=QAtom->anext )
				if( QGroup->serno == PGroup->serno && 
					(ModelInclude || QGroup->model == PGroup->model) )
	            {	if( shift == -1 )
					{	QAtom->flag &= ~SelectFlag;
					} else
					{	QAtom->flag |= SelectFlag;
						SelectCount++;
					}
				} else 
				{	if( !shift ) 
					{	QAtom->flag &= ~SelectFlag;
					} else
					{	if( QAtom->flag & SelectFlag)
							SelectCount++;
					}
				}

	DisplaySelectCount();

	if( ZoneBoth )
	{   ForEachBond
		if( (bptr->srcatom->flag&bptr->dstatom->flag) & SelectFlag )
           {   bptr->flag |= SelectFlag;
           } else bptr->flag &= ~SelectFlag;
        ForEachSurfBond
		if( (sbptr->srcatom->flag&sbptr->dstatom->flag) & SelectFlag )
           {   sbptr->flag |= SelectFlag;
           } else sbptr->flag &= ~SelectFlag;
	} else {
        ForEachBond
           if( (bptr->srcatom->flag|bptr->dstatom->flag) & SelectFlag )
           {   bptr->flag |= SelectFlag;
           } else bptr->flag &= ~SelectFlag;		
        ForEachSurfBond
           if( (sbptr->srcatom->flag|sbptr->dstatom->flag) & SelectFlag )
           {   sbptr->flag |= SelectFlag;
           } else sbptr->flag &= ~SelectFlag;		
	}
}

void SelectChain( int shift, Chain __far *PChain )
{	register Bond __far *bptr;
    register SurfBond __far *sbptr;

	SelectCount = 0;
	for( QChain=Database->clist; QChain; QChain=QChain->cnext )
		for( QGroup=QChain->glist; QGroup; QGroup=QGroup->gnext )
			for( QAtom=QGroup->alist; QAtom; QAtom=QAtom->anext )
				if( QChain->ident == PChain->ident &&
					(ModelInclude || QChain->model == PChain->model) )
	            {	if( shift == -1)
					{	QAtom->flag &= ~SelectFlag;
					} else
					{	QAtom->flag |= SelectFlag;
						SelectCount++;
					}
				} else 
				{	if( !shift  ) 
					{	QAtom->flag &= ~SelectFlag;
					} else
					{	if( QAtom->flag & SelectFlag)
							SelectCount++;
					}
				}

	DisplaySelectCount();

	if( ZoneBoth )
	{   ForEachBond
		if( (bptr->srcatom->flag&bptr->dstatom->flag) & SelectFlag )
           {   bptr->flag |= SelectFlag;
           } else bptr->flag &= ~SelectFlag;
        ForEachSurfBond
		if( (sbptr->srcatom->flag&sbptr->dstatom->flag) & SelectFlag )
           {   sbptr->flag |= SelectFlag;
           } else sbptr->flag &= ~SelectFlag;
	} else {
        ForEachBond
           if( (bptr->srcatom->flag|bptr->dstatom->flag) & SelectFlag )
           {   bptr->flag |= SelectFlag;
           } else bptr->flag &= ~SelectFlag;	
        ForEachSurfBond
           if( (sbptr->srcatom->flag|sbptr->dstatom->flag) & SelectFlag )
           {   sbptr->flag |= SelectFlag;
           } else sbptr->flag &= ~SelectFlag;
	}
}


int DefineShade( int r, int g, int b )
{
    register int d,dr,dg,db;
    register int dist,best;
    register int i;

    /* Already defined! */
    for( i=0; i<LastShade; i++ )
        if( Shade[i].refcount )
            if( (Shade[i].r==r)&&(Shade[i].g==g)&&(Shade[i].b==b) )
                return i;

    /* Allocate request */
    for( i=0; i<LastShade; i++ )
         if( !Shade[i].refcount )
         {   Shade[i].r = r;
             Shade[i].g = g;
             Shade[i].b = b;
             Shade[i].refcount = 0;
             return i;
         }

    InvalidateCmndLine();
    WriteString("Warning: Unable to allocate shade!\n");

    /* To avoid lint warning! */
    best = dist = 0;

    /* Nearest match */
    for( i=0; i<LastShade; i++ )
    {   dr = Shade[i].r - r;
        dg = Shade[i].g - g;
        db = Shade[i].b - b;
        d = dr*dr + dg*dg + db*db;
        if( !i || (d<dist) )
        {   dist = d;
            best = i;
        }
    }
    return best;
}


void ScaleColourMap( int count )
{
    register int i, r, g, b;
    register int fract;

    ScaleCount=0;
    for( i=0; i<LastShade; i++ )
        if( !Shade[i].refcount )
            ScaleCount++;

    /* If there are no shades free! */
    if( !ScaleCount ) ScaleCount = LastShade;

    if( count && (count<ScaleCount) )
        ScaleCount = count;

    if( ScaleCount == 1 )
    {   ScaleRef[i].r = 0;
        ScaleRef[i].g = 0;
        ScaleRef[i].b = 255;
        ScaleRef[i].shade = 0;
        ScaleRef[i].col = 0;
        return;
    }
    
    for( i=0; i<ScaleCount; i++ )
    {   fract = (int)((1023*i)/(ScaleCount-1));
        if( fract < 256 )
        {   r = 0;  g = fract;  b = 255;
        } else if( fract < 512 )
        {   r = 0;  g = 255;  b = 511-fract;
        } else if( fract < 768 )
        {   r = fract-512;  g = 255;  b = 0;
        } else /* fract < 1024 */                             
        {   r = 255;  g = 1023-fract;  b = 0;
        }
        ScaleRef[i].r = r;
        ScaleRef[i].g = g;
        ScaleRef[i].b = b;
        ScaleRef[i].shade = 0;
        ScaleRef[i].col = 0;
    }
}


void SetLutEntry( int i, int r, int g, int b )
{
    ULut[i] = True;
    RLut[i] = r;
    GLut[i] = g;
    BLut[i] = b;

#ifdef EIGHTBIT
    Lut[i] = i;
#else
    Lut[i] = ( (Card)((r<<8)|g)<<8 ) | b;
#endif
}


static Real Power( Real x, int y )
{
    register Real result;

    result = x;
    while( y >= 1 )
    {   result *= x;
        y -= 1;
    }
    return result;
}


void DefineColourMap( void )
{
    register Real diffuse,fade;
    register Real temp,inten;
    register int col,r,g,b;
    register int i,j,k=0;

    for( i=0; i<LutSize; i++ )
        ULut[i] = False;

    if( !DisplayMode )
    {   SetLutEntry(BackCol,BackR,BackG,BackB);
        SetLutEntry(LabelCol,LabR,LabG,LabB);
        SetLutEntry(BoxCol,BoxR,BoxG,BoxB);
    } else SetLutEntry(BackCol,80,80,80);

    diffuse = 1.0 - Ambient;
    if( DisplayMode )
    {   for( i=0; i<ColourDepth; i++ )
        {   temp = (Real)i/ColourMask;
            inten = diffuse*temp + Ambient;

            /* Unselected [40,40,255] */
            /* Selected   [255,160,0]  */
            r = (int)(255*inten);
            g = (int)(160*inten);
            b = (int)(40*inten);

            /* Avoid Borland Compiler Warning! */
            /* Shade2Colour(0) == FirstCol     */
            SetLutEntry( FirstCol+i, b, b, r );
            SetLutEntry( Shade2Colour(1)+i, r, g, 0 );
        }
    } else
        for( i=0; i<ColourDepth; i++ )
        {   temp = (Real)i/ColourMask;
 			
			if( ShadePower )
				temp = pow(temp,exp((double)ShadePower/10));

            inten = diffuse*temp + Ambient;
            fade = 1.0-inten;

            if( FakeSpecular )
            {   temp = Power(temp,SpecPower);
                k = (int)(255*temp);
                temp = 1.0 - temp;
                inten *= temp;
                fade *= temp;
            }

            for( j=0; j<LastShade; j++ )
                if( Shade[j].refcount )
                {   col = Shade2Colour(j);
                    if( UseBackFade )
                    {   temp = 1.0-inten;
                        r = (int)(Shade[j].r*inten + fade*BackR); 
                        g = (int)(Shade[j].g*inten + fade*BackG);
                        b = (int)(Shade[j].b*inten + fade*BackB);
                    } else
                    {   r = (int)(Shade[j].r*inten); 
                        g = (int)(Shade[j].g*inten);
                        b = (int)(Shade[j].b*inten);
                    }

                    if( FakeSpecular )
                    {   r += k;
                        g += k;
                        b += k;
                    }
                    SetLutEntry( col+i, r, g, b );
                }
        }

    if( Interactive )
        AllocateColourMap();
}


void ResetColourMap( void )
{
    register int i;

#ifdef EIGHTBIT
    for( i=0; i<256; i++ )
        ULut[i] = False;
#endif

    SpecPower = 8;
    FakeSpecular = False;
    ShadePower = 0;
    Ambient = DefaultAmbient;
    UseBackFade = False;
	UseDotColPot = False;

    BackR = BackG = BackB = 0;
    BoxR = BoxG = BoxB = 255;
    LabR = LabG = LabB = 255;
	DotR = DotG = DotB = 255;
	UseDotColPot = False;

    for( i=0; i<LastShade; i++ )
        Shade[i].refcount = 0;
    ScaleCount = 0;

    for (i=0; i<AltlDepth; i++)
      AltlColours[i] = 0;

}


void ColourBondNone( void )
{
    register Bond __far *bptr;

    if( Database )
        ForEachBond
            if( (bptr->flag&SelectFlag) && bptr->col )
            {   Shade[Colour2Shade(bptr->col)].refcount--;
                bptr->col = 0;
            }
}


void ColourBondAttrib( int r, int g, int b )
{
    register Bond __far *bptr;
    register int shade,col;

    if( Database )
    {   ForEachBond
            if( (bptr->flag&SelectFlag) && bptr->col )
                Shade[Colour2Shade(bptr->col)].refcount--;

        shade = DefineShade(r,g,b);
        col = Shade2Colour(shade);

        ForEachBond
            if( bptr->flag&SelectFlag )
            {   Shade[shade].refcount++;
                bptr->col = col;
            }
    }
}


void ColourBackNone( void )
{
    register Chain __far *chain;
    register Bond __far *bptr;
    register int flag;

    if( Database )
        ForEachBack
        {   flag = ZoneBoth? bptr->dstatom->flag & bptr->srcatom->flag
                           : bptr->dstatom->flag | bptr->srcatom->flag;

            if( flag&SelectFlag )
            {   bptr->flag |= SelectFlag;
                if( bptr->col )
                {   Shade[Colour2Shade(bptr->col)].refcount--;
                    bptr->col = 0;
                }
            } else bptr->flag &= ~SelectFlag;
        }
}


void ColourBackAttrib( int r, int g, int b )
{
    register int shade,col;
    register Chain __far *chain;
    register Bond __far *bptr;

    if( Database )
    {   ColourBackNone();
        shade = DefineShade(r,g,b);
        col = Shade2Colour(shade);

        ForEachBack
            if( bptr->flag&SelectFlag )
            {   Shade[shade].refcount++;
                bptr->col = col;
            }
    }
}


void ColourHBondNone( int hbonds )
{
    register HBond __far *list;
    register HBond __far *ptr;
    register RAtom __far *src;
    register RAtom __far *dst;

    if( !Database )
        return;

    list = hbonds? Database->hlist : Database->slist;

    if( ZoneBoth )
    {   for( ptr=list; ptr; ptr=ptr->hnext )
        {   src = ptr->src;  dst = ptr->dst;

            if( (src->flag&dst->flag) & SelectFlag )
            {   ptr->flag |= SelectFlag;
                if( ptr->col )
                {   Shade[Colour2Shade(ptr->col)].refcount--;
                    ptr->col = 0;
                }
            } else ptr->flag &= ~SelectFlag;
        }
    } else
        for( ptr=list; ptr; ptr=ptr->hnext )
        {   src = ptr->src;  dst = ptr->dst;

            if( (src->flag|dst->flag) & SelectFlag )
            {   ptr->flag |= SelectFlag;
                if( ptr->col )
                {   Shade[Colour2Shade(ptr->col)].refcount--;
                    ptr->col = 0;
                }
            } else ptr->flag &= ~SelectFlag;
        }
}


void ColourHBondType( void )
{
    register HBond __far *ptr;
    register ShadeRef *ref;
    register int i;

    if( !Database ) return;
    for( i=0; i<7; i++ )
        HBondShade[i].col = 0;

    if( Info.hbondcount < 0 )
    {   CalcHydrogenBonds();
    } else ColourHBondNone( True );

    for( ptr=Database->hlist; ptr; ptr=ptr->hnext )
        if( ptr->flag & SelectFlag )
        {   switch( ptr->offset )
            {   case(  2 ):  ref = HBondShade;     break;
                case(  3 ):  ref = HBondShade+1;   break;
                case(  4 ):  ref = HBondShade+2;   break;
                case(  5 ):  ref = HBondShade+3;   break;
                case( -3 ):  ref = HBondShade+4;   break;
                case( -4 ):  ref = HBondShade+5;   break;
                default:     ref = HBondShade+6;   break;
            }

            if( !ref->col )
            {   ref->shade = DefineShade( ref->r, ref->g, ref->b );
                ref->col = Shade2Colour(ref->shade);
            }
            Shade[ref->shade].refcount++;
            ptr->col = (Byte)ref->col;
        }
}


void ColourHBondAttrib( int hbonds, int r, int g, int b )
{
    register HBond __far *list;
    register HBond __far *ptr;
    register int col,shade;

    if( !Database )
        return;

    if( hbonds )
    {   if( Info.hbondcount < 0 )
        {   CalcHydrogenBonds();
        } else ColourHBondNone(True);
    } else
        if( Info.ssbondcount < 0 )
        {   FindDisulphideBridges();
        } else ColourHBondNone(False);


    shade = DefineShade(r,g,b);
    col = Shade2Colour(shade);

    list = hbonds? Database->hlist : Database->slist;
    for( ptr=list; ptr; ptr=ptr->hnext )
        if( ptr->flag & SelectFlag )
        {   Shade[shade].refcount++;
            ptr->col = col;
        }
}


void ColourRibbonNone( int flag )
{
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *aptr;

    if( !Database )
        return;

    if( Info.helixcount < 0 )
        return;

    for( chain=Database->clist; chain; chain=chain->cnext )
        for( group=chain->glist; group; group=group->gnext )
            for( aptr=group->alist; aptr; aptr=aptr->anext )
                if( (aptr->flag&SelectFlag) && 
                    (IsAlphaCarbon(aptr->refno)||
                     IsSugarPhosphate(aptr->refno)) )
                {   if( (flag&RibColInside) && group->col1 )
                    {   Shade[Colour2Shade(group->col1)].refcount--;
                        group->col1 = 0;
                    }
                    if( (flag&RibColOutside) && group->col2 )
                    {   Shade[Colour2Shade(group->col2)].refcount--;
                        group->col2 = 0;
                    }
                    break;
                }
}


void ColourRibbonAttrib( int flag, int r, int g, int b )
{
    register int shade, col;
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *aptr;

    if( Database )
    {   if( Info.helixcount >= 0 )
        {   ColourRibbonNone( flag );
        } else DetermineStructure(False);

        shade = DefineShade(r,g,b);
        col = Shade2Colour(shade);

        for( chain=Database->clist; chain; chain=chain->cnext )
            for( group=chain->glist; group; group=group->gnext )
                for( aptr=group->alist; aptr; aptr=aptr->anext )
                    if( (aptr->flag&SelectFlag) && 
                        (IsAlphaCarbon(aptr->refno)||
                         IsSugarPhosphate(aptr->refno)) )
                    {   if( flag & RibColInside )
                        {   Shade[shade].refcount++;
                            group->col1 = col;
                        }
                        if( flag & RibColOutside )
                        {   Shade[shade].refcount++;
                            group->col2 = col;
                        }
                        break;
                    }
    }
}


void ColourMonitNone( void )
{
    register Monitor *ptr;
    register int flag;

    if( Database )
        for( ptr=MonitList; ptr; ptr=ptr->next )
            if( ptr->col )
            {   flag = ZoneBoth? ptr->src->flag & ptr->dst->flag
                               : ptr->src->flag | ptr->dst->flag;
                if( flag & SelectFlag )
                {   Shade[Colour2Shade(ptr->col)].refcount--;
                    ptr->col = 0;
                }
            }
}


void ColourMonitAttrib( int r, int g, int b )
{
    register Monitor *ptr;
    register int shade,col;
    register int flag;

    if( !Database )
        return;

    ColourMonitNone();
    shade = DefineShade(r,g,b);
    col = Shade2Colour(shade);

    for( ptr=MonitList; ptr; ptr=ptr->next )
    {   flag = ZoneBoth? ptr->src->flag & ptr->dst->flag 
                       : ptr->src->flag | ptr->dst->flag;
        if( flag & SelectFlag )
        {   Shade[shade].refcount++;
            ptr->col = col;
        }
    }
}


void ColourDotsAttrib( int r, int g, int b )
{
    register DotStruct __far *ptr;
    register int i,shade,col;

	DotR = r;
	DotG = g;
	DotB = b;
	UseDotColPot = False;

    if( Database )
    {   for( ptr=DotPtr; ptr; ptr=ptr->next )
            for( i=0; i<ptr->count; i++ )
            {    shade = Colour2Shade(ptr->col[i]);
                 Shade[shade].refcount--;
            }

        shade = DefineShade(r,g,b);
        col = Shade2Colour(shade);
        for( ptr=DotPtr; ptr; ptr=ptr->next )
            for( i=0; i<ptr->count; i++ )
            {   Shade[shade].refcount++;
                ptr->col[i] = col;
            }
    }
}


/* Coulomb's Law */
#define CoulombScale  ((Long)(1<<12))
int CalculatePotential( Long x, Long y, Long z )
{
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *ptr;
    register Long dx,dy,dz;
    register Long result;
    register Card dist;
    register Card max;


    /* Calculated charges have b-values < 0.0     */
    /* if( MinFun(MinMainTemp,MinHetaTemp) >= 0 ) */
    /*     CalculateCharges();                    */

    /* 8.0 Angstrom Cut Off */
    max = (Long)2000*2000;

    result = 0;
    ForEachAtom
    {   dx = ptr->xorg + ptr->fxorg - x;
        if( (dist=dx*dx) < max )
        {   dy = ptr->yorg + ptr->fyorg - y;
            if( (dist+=dy*dy) < max )
            {   dz = ptr->zorg + ptr->fzorg - z;
                if( (dist+=dz*dz) < max )
                    result += (CoulombScale*(Real)(ptr->temp)) / (int)isqrt(dist);
            }
        }
    }
    /* Dielectric Constant = 10.0 */
    /* (332.0*250.0)/(10.0*100.0) */
    result = (result*83)/CoulombScale;
    return (int)result;
}


void ColourDotsPotential( void )
{
    register DotStruct __far *ptr;
    register int i,shade,result;
    register ShadeRef *ref;

	UseDotColPot = True;

    if( Database )
    {   for( i=0; i<8; i++ )
            PotentialShade[i].col = 0;

        /* Colour Dots None! */
        for( ptr=DotPtr; ptr; ptr=ptr->next )
            for( i=0; i<ptr->count; i++ )
            {    shade = Colour2Shade(ptr->col[i]);
                 Shade[shade].refcount--;
            }

        for( ptr=DotPtr; ptr; ptr=ptr->next )
            for( i=0; i<ptr->count; i++ )
            {   result = CalculatePotential( ptr->xpos[i],
                                             ptr->ypos[i],
                                             ptr->zpos[i] );

                /* Determine Colour Bucket */
                if( result >= 0 )
                {   if( result > 10 )
                    {      if( result > 24 )
                           {      ref = PotentialShade + 0;
                           } else ref = PotentialShade + 1;
                    } else if( result > 3 )
                           {      ref = PotentialShade + 2;
                           } else ref = PotentialShade + 3;
                } else 
                    if( result > -10 )
                    {      if( result > -3 )
                           {      ref = PotentialShade + 4;
                           } else ref = PotentialShade + 5;
                    } else if( result > -24 )
                           {      ref = PotentialShade + 6;
                           } else ref = PotentialShade + 7;

                if( !ref->col )
                {   ref->shade = DefineShade( ref->r, ref->g, ref->b );
                    ref->col = Shade2Colour(ref->shade);
                }
                Shade[ref->shade].refcount++;
                ptr->col[i] = ref->col;
            }
    }
}

void ColourPointAttrib( int r, int g, int b, int mapno )
{
    register int i,shade,nshade,result;
    register Long x, y, z;
    
    MapPointVec __far *MapPointsPtr;
    MapInfo mapinfo;

	MapRGBCol[0] = r;
	MapRGBCol[1] = g;
	MapRGBCol[2] = b;
	UseDotColPot = False;
    
    nshade = DefineShade(r,g,b);
    
    if (MapInfoPtr)
      if (mapno >= 0 && mapno < MapInfoPtr->size) {
      	vector_get_element((GenericVec __far *)MapInfoPtr,(void __far *)&mapinfo,mapno );
      	MapPointsPtr = mapinfo.MapPointsPtr;
      	
        if (MapPointsPtr)
        for (i=0; i<MapPointsPtr->size; i++) {
          if (!(MapPointsPtr->array[i]).flag&SelectFlag) continue;
          x = (MapPointsPtr->array[i]).xpos;
          y = (MapPointsPtr->array[i]).ypos;
          z = (MapPointsPtr->array[i]).zpos;
        	
          shade = Colour2Shade((MapPointsPtr->array[i]).col);
          Shade[shade].refcount--;
        	
          result = CalculatePotential( x, y, z );
        	
          Shade[nshade].refcount++;
          (MapPointsPtr->array[i]).col = Shade2Colour(nshade);
              
        }
              
        }
}



void ColourPointPotential( int mapno )
{
    register int i,shade,result;
    register ShadeRef *ref;
    
    MapPointVec __far *MapPointsPtr;
    MapInfo mapinfo;
    Long x, y, z;

	UseDotColPot = True;

    if (MapInfoPtr)
      if (mapno >= 0 && mapno < MapInfoPtr->size) {
      	vector_get_element((GenericVec __far *)MapInfoPtr,(void __far *)&mapinfo,mapno );
      	MapPointsPtr = mapinfo.MapPointsPtr;
      	
        if (MapPointsPtr)
        for (i=0; i<MapPointsPtr->size; i++) {
          if (!(MapPointsPtr->array[i]).flag&SelectFlag) continue;
          x = (MapPointsPtr->array[i]).xpos;
          y = (MapPointsPtr->array[i]).ypos;
          z = (MapPointsPtr->array[i]).zpos;
        	
          shade = Colour2Shade((MapPointsPtr->array[i]).col);
          Shade[shade].refcount--;
        	
          result = CalculatePotential( x, y, z );
        	
          /* Determine Colour Bucket */
          if( result >= 0 ) {
            if( result > 10 ) {
              if( result > 24 ) {
                 ref = PotentialShade + 0;
              } else ref = PotentialShade + 1;
            } else if( result > 3 ) {
              ref = PotentialShade + 2;
            } else ref = PotentialShade + 3;
          } else if( result > -10 ) {
            if( result > -3 ) {
              ref = PotentialShade + 4;
            } else ref = PotentialShade + 5;
          } else if( result > -24 ) {
            ref = PotentialShade + 6;
          } else ref = PotentialShade + 7;

          if( !ref->col ) {
            ref->shade = DefineShade( ref->r, ref->g, ref->b );
            ref->col = Shade2Colour(ref->shade);
          }
          Shade[ref->shade].refcount++;
          (MapPointsPtr->array[i]).col = ref->col;
              
        }
              
        }


}


static void ResetColourAttrib( void )
{
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *ptr;

    ForEachAtom
        if( (ptr->flag&SelectFlag) && ptr->col )
            Shade[Colour2Shade(ptr->col)].refcount--;
}


void MonoColourAttrib( int r, int g, int b )
{
    register int shade,col;
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *ptr;

    if( Database )
    {   ResetColourAttrib();
        shade = DefineShade(r,g,b);
        col = Shade2Colour(shade);

        ForEachAtom
            if( ptr->flag&SelectFlag )
            {   Shade[shade].refcount++;
                ptr->col = col;
            }
    }
}

void AddAltlColours( void )
{
    int i, ic;
    register ShadeRef *ref;
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *ptr;

    /* Add colours for any alternate conformations used */    

    ForEachAtom
        if( ptr->flag&SelectFlag )
	  {   if(! (ptr->altl == '\0' || ptr->altl == ' ') ){
            ic = (((int)(ptr->altl))&(AltlDepth-1))+1;
            i = (int)((Long)ScaleCount*(ic--)/(AltlDepth));

            if( i >= ScaleCount )
            {   ref = ScaleRef + (ScaleCount-1);
            } else if( i >= 0 )
            {   ref = ScaleRef + i;
            } else ref = ScaleRef;

            if( !(ref->col && Shade[ref->shade].refcount) )
            {   ref->shade = DefineShade(ref->r,ref->g,ref->b);
                ref->col = Shade2Colour(ref->shade);
            }
            Shade[ref->shade].refcount++;
             AltlColours[ic] = ref->col;
           }
	}
 }

void ScaleColourAttrib( int attr )
{
    register ShadeRef *ref;
    register int count, attrno, factor;
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *ptr;
    register Long temp;
    register int i;

    if( !Database ) return;
	ColourBondNone();

    switch( attr )
    {   case(ChainAttr):   attrno = Info.chaincount;   
                           factor = 1;
                           break;

        case(GroupAttr):   factor = MinMainRes;
                           attrno = MaxMainRes;
                           if( HetaGroups && HetaGroupCount )
                           {   if( MinHetaRes < factor )
                                   factor = MinHetaRes;
                               if( MaxHetaRes > attrno )
                                   attrno = MaxHetaRes;
                           } 
                           attrno -= (factor-1);
                           break;

        case(ModelAttr):   factor = MinModel;
                           attrno = MaxModel-MinModel+1;
                           break;

        case(AltAttr):     factor = 1;
                           attrno = AltlDepth;
                           break;

        case(ChargeAttr):
        case(TempAttr):    factor = MinMainTemp;
                           attrno = MaxMainTemp;
                           if( HetaGroups && HetaGroupCount )
                           {   if( MinHetaTemp < factor )
                                   factor = MinHetaTemp;
                               if( MaxHetaTemp > attrno )
                                   attrno = MaxHetaTemp;
                           }
                           attrno -= (factor-1);
                           break;

        default:           return;
    }

    if( attrno<2 )
    {   MonoColourAttrib(255,255,255);
        return;
    } 

    ResetColourAttrib();
    ScaleColourMap(attrno);

        switch( attr )
        {    case(ChainAttr):
                 count = 0;
                 for( chain=Database->clist; chain; chain=chain->cnext )
                 {   ref = &(ScaleRef[(count*ScaleCount)/attrno]);
                     if( !(ref->col && Shade[ref->shade].refcount) )
                     {   ref->shade = DefineShade(ref->r,ref->g,ref->b);
                         ref->col = Shade2Colour(ref->shade);
                     }
                     for( group=chain->glist; group; group=group->gnext )
                         for( ptr=group->alist; ptr; ptr=ptr->anext )
                             if( ptr->flag&SelectFlag )
                             {   Shade[ref->shade].refcount++;
                                 ptr->col = ref->col;
                             }
                     count++;
                 }
                 break;


         case(GroupAttr):
                 for( chain=Database->clist; chain; chain=chain->cnext )
                     for( group=chain->glist; group; group=group->gnext )
                     {   temp = (Long)ScaleCount*(group->serno-factor);
                         i = (int)(temp/attrno);

                         if( i >= ScaleCount )
                         {   ref = ScaleRef + (ScaleCount-1);
                         } else if( i >= 0 )
                         {   ref = ScaleRef + i;
                         } else ref = ScaleRef;

                         if( !(ref->col && Shade[ref->shade].refcount) )
                         {   ref->shade = DefineShade(ref->r,ref->g,ref->b);
                             ref->col = Shade2Colour(ref->shade);
                         }

                         for( ptr=group->alist; ptr; ptr=ptr->anext )
                             if( ptr->flag&SelectFlag )
                             {   Shade[ref->shade].refcount++;
                                 ptr->col = ref->col;
                             }
                     }
                 break;

         case(ModelAttr):
                 for( chain=Database->clist; chain; chain=chain->cnext )
                     for( group=chain->glist; group; group=group->gnext )
                     {   temp = (Long)ScaleCount*(group->model-factor);
                         i = (int)(temp/attrno);

                         if( i >= ScaleCount )
                         {   ref = ScaleRef + (ScaleCount-1);
                         } else if( i >= 0 )
                         {   ref = ScaleRef + i;
                         } else ref = ScaleRef;

                         if( !(ref->col && Shade[ref->shade].refcount) )
                         {   ref->shade = DefineShade(ref->r,ref->g,ref->b);
                             ref->col = Shade2Colour(ref->shade);
                         }

                         for( ptr=group->alist; ptr; ptr=ptr->anext )
                             if( ptr->flag&SelectFlag )
                             {   Shade[ref->shade].refcount++;
                                 ptr->col = ref->col;
                             }
                     }
                 break;


         case(AltAttr):
                 ForEachAtom
                     if( ptr->flag&SelectFlag )
		     {   if (ptr->altl == '\0' || ptr->altl == ' ') i=0;
                         else i = (((int)(ptr->altl))&(AltlDepth-1))+1;
                         i = (int)((Long)ScaleCount*i/attrno);

                         if( i >= ScaleCount )
                         {   ref = ScaleRef + (ScaleCount-1);
                         } else if( i >= 0 )
                         {   ref = ScaleRef + i;
                         } else ref = ScaleRef;

                         if( !(ref->col && Shade[ref->shade].refcount) )
                         {   ref->shade = DefineShade(ref->r,ref->g,ref->b);
                             ref->col = Shade2Colour(ref->shade);
                         }
                         Shade[ref->shade].refcount++;
                         ptr->col = ref->col;
                     }
                 break;


                 
         case(TempAttr):
                 ForEachAtom
                     if( ptr->flag&SelectFlag )
                     {   i = (int)(((Long)ScaleCount*(ptr->temp-factor))
                                    /attrno);

                         if( i >= ScaleCount )
                         {   ref = ScaleRef + (ScaleCount-1);
                         } else if( i >= 0 )
                         {   ref = ScaleRef + i;
                         } else ref = ScaleRef;

                         if( !(ref->col && Shade[ref->shade].refcount) )
                         {   ref->shade = DefineShade(ref->r,ref->g,ref->b);
                             ref->col = Shade2Colour(ref->shade);
                         }
                         Shade[ref->shade].refcount++;
                         ptr->col = ref->col;
                     }
                 break;

        case(ChargeAttr):
                ForEachAtom
                     if( ptr->flag&SelectFlag )
                     {   i = (int)(((Long)ScaleCount*(ptr->temp-factor))
                                    /attrno);

                         if( i <= 0 )
                         {   ref = ScaleRef + (ScaleCount-1);
                         } else if( i < ScaleCount )
                         {   ref = ScaleRef + ((ScaleCount-1)-i);
                         } else ref = ScaleRef;

                         if( !(ref->col && Shade[ref->shade].refcount) )
                         {   ref->shade = DefineShade(ref->r,ref->g,ref->b);
                             ref->col = Shade2Colour(ref->shade);
                         }
                         Shade[ref->shade].refcount++;
                         ptr->col = ref->col;
                     }
                 break;
        }
           
    /* Now add colours for any alternate conformations used */    

    AddAltlColours();
	if (DotCount && !UseOldColorCode)
		CalculateSurface(DotCount);
    return;      

}



/*====================================*/
/*  Raster3D Color Record Processing  */
/*====================================*/

static int MatchNumber( int len, int value, char *mask )
{
    register char digit, template;
    register int result;
    register int i;

    result = True;
    for( i=0; i<len; i++ )
    {   digit = (value%10) + '0';
        template = mask[len-i];
        if( template==' ' )
        {   if( value ) result = False;
        } else if( !MatchChar(template,digit) )
            result = False;
        value /= 10;
    }
    return result;
}


void UserMaskAttrib( int fields )
{
    register MaskDesc *mptr;
    register char *temp, *name;
    register int shade, change;
    register int i, rad, match;
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *ptr;

    if( !Database ) return;

    if( !MaskCount )
    {   InvalidateCmndLine();
        WriteString("Warning: No user supplied colour records!\n");
        return;
    }

    /* Avoid Compiler Warning! */
    mptr = (MaskDesc*)0;
    match = False;

    change = False;
    ResetColourAttrib();
    if( fields & MaskColourFlag )
        for( i=0; i<MaskCount; i++ )
            MaskShade[i] = -1;

    if( fields & MaskRadiusFlag )
    {   MaxAtomRadius = 0;
        DrawAtoms = False;
        DrawStars = False;
    }

    ForEachAtom
    if( ptr->flag & SelectFlag )
    {   for( i=0; i<MaskCount; i++ )
        {   mptr = UserMask+i;
            temp = mptr->mask;
            match = True;

            if( !MatchChar(temp[13],chain->ident) ) match=False;
            if( !MatchChar(temp[9],ptr->altl) )     match=False;

            /* Atom Name */
            if( match )
            {   name = ElemDesc[ptr->refno];
                if( !MatchChar(temp[5],name[0]) ) match=False;
                if( !MatchChar(temp[6],name[1]) ) match=False;
                if( !MatchChar(temp[7],name[2]) ) match=False;
                if( !MatchChar(temp[8],name[3]) ) match=False;
            }

            /* Group Name */
            if( match )
            {   name = Residue[group->refno];
                if( !MatchChar(temp[10],name[0]) ) match=False;
                if( !MatchChar(temp[11],name[1]) ) match=False;
                if( !MatchChar(temp[12],name[2]) ) match=False;
            }

            if( match && (mptr->flags&SerNoFlag) )
                match = MatchNumber(4,ptr->serno,&temp[0]);
            if( match && (mptr->flags&ResNoFlag) )
                match = MatchNumber(3,group->serno,&temp[14]);
            if( match ) break;
        }

        if( fields & MaskColourFlag )
        {   if( match )
            {   if( MaskShade[i] == -1 )
                {   MaskShade[i] = DefineShade(mptr->r,mptr->g,mptr->b);
                    MaskColour[i] = Shade2Colour(MaskShade[i]);
                }
                Shade[MaskShade[i]].refcount++;
                ptr->col = MaskColour[i];
            } else
            {   shade = DefineShade(255,255,255);
                ptr->col = Shade2Colour(shade);
                Shade[shade].refcount++;
            }
        }

        if( fields & MaskRadiusFlag )
        {   rad = match? mptr->radius : 375;
            ptr->irad = (int)rint(Scale*(Real)(rad));
            ptr->flag |= SphereFlag;
            ptr->radius = rad;

            if( ptr->irad>MaxAtomRadius )
                MaxAtomRadius = ptr->irad;
            change = True;
        }
    } else 
    {   if( ptr->flag & (SphereFlag|TouchFlag|ExpandFlag) )
        {   DrawAtoms = True;
        if( ptr->irad>MaxAtomRadius )
            MaxAtomRadius = ptr->irad;
        }
        if( ptr->flag & StarFlag )
        {   DrawStars = True;
        if( ptr->irad>MaxAtomRadius )
            MaxAtomRadius = ptr->irad;
        }
        if( ptr->flag & TouchFlag )
        {   DrawSurf = True;
        if( ptr->irad>MaxAtomRadius )
            MaxAtomRadius = ptr->irad;
        }
        if( ptr->flag & ExpandFlag )
        {
          if( (ptr->irad)+iProbeRad>MaxAtomRadius )
            MaxAtomRadius = (ptr->irad)+iProbeRad;
        }
     }

    if( change )
    {   DrawAtoms = True;
        DetermineClipping();
        VoxelsClean = False;
        BucketFlag = False;
    }
}

/* REMOVE THIS... maybe */
void testFlags (void)
{
	/* test function for loadSelection and saveSelection */
	register Chain __far *chain;
	register Group __far *group;
	register RAtom __far *ptr;

	int i = 0;
	char tmp[255];

	WriteString("Showing Flags:\n"
			  "\tAtom#\tName\tSaved?\tSelected?\n");

	ForEachAtom
	{
		sprintf(tmp,"\t%d\t%s",i,ElemDesc[ptr->refno]);
		WriteString(tmp);
		if (ptr->flag & SaveFlag)
		{
			sprintf(tmp, "\tSaved");
			WriteString(tmp);
		}
		else
		{
			sprintf(tmp,"\tNo");
			WriteString(tmp);
		}

		if (ptr->flag & SelectFlag)
		{
			sprintf(tmp,"\tSelected");
			WriteString(tmp);
		}
		else
		{
			sprintf(tmp,"\tNo");
			WriteString(tmp);
		}
		sprintf(tmp,"\n");
		WriteString(tmp);
		i++;
	}
}



	

void CPKColourAttrib( void )
{
    register ShadeRef *ref;
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *ptr;
    register int i;

    if( !Database ) return;
	ColourBondNone();
    for( i=0; i<CPKMAX; i++ )
        CPKShade[i].col = 0;
    ResetColourAttrib();
    ScaleColourMap(CPKMAX);

	/* test for saveSelection 
	WriteString("Saving Selection...\n");
	saveSelection();
	testFlags();

	SelectZone(AllAtomFlag);
	testFlags();*/

    ForEachAtom
        if( ptr->flag&SelectFlag )
        {   ref = CPKShade + Element[ptr->elemno].cpkcol;

            if( !ref->col )
            {   ref->shade = DefineShade( ref->r, ref->g, ref->b );
                ref->col = Shade2Colour(ref->shade);
            }
            Shade[ref->shade].refcount++;
            ptr->col = ref->col;
        }

    AddAltlColours();
	if (DotCount && !UseOldColorCode)
		CalculateSurface(DotCount);

	/*WriteString("Loading selection...\n");
	loadSelection();
	testFlags();*/

}

void CpkNewColourAttrib( void )
{
    register ShadeRef *ref;
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *ptr;
    register int i;

    if ( !Database ) return;
	ColourBondNone();
    for ( i=0; i<CpkNewMax; i++ )
	 CpkNewShade[i].col = 0;
    ResetColourAttrib();
    ScaleColourMap(CpkNewMax);

    ForEachAtom
	if( ptr->flag&SelectFlag )
	{   ref = CpkNewShade + Element[ptr->elemno].cpkcol;

	    if( !ref->col )
	    {   ref->shade = DefineShade( ref->r, ref->g, ref->b );
		ref->col = Shade2Colour(ref->shade);
	    }
	    Shade[ref->shade].refcount++;
	    ptr->col = ref->col;
	}
    AddAltlColours();
	if (DotCount && !UseOldColorCode)
		CalculateSurface(DotCount);
}



void AminoColourAttrib( void )
{
    register ShadeRef *ref;
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *ptr;
    register int i;

    if( !Database ) return;
	ColourBondNone();
    for( i=0; i<13; i++ )
        AminoShade[i].col = 0;
    ResetColourAttrib();
    ScaleColourMap(13);

    ForEachAtom
        if( ptr->flag&SelectFlag )
        {   if( IsAmino(group->refno) )
            {   ref = AminoShade + AminoIndex[group->refno];
            } else ref = AminoShade+12;

            if( !ref->col )
            {   ref->shade = DefineShade( ref->r, ref->g, ref->b );
                ref->col = Shade2Colour(ref->shade);
            }
            Shade[ref->shade].refcount++;
            ptr->col = ref->col;
        }

    AddAltlColours();
	if (DotCount && !UseOldColorCode)
		CalculateSurface(DotCount);

}


void ShapelyColourAttrib( void )
{
    register ShadeRef *ref;
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *ptr;
    register int i;

    if( !Database ) return;
	ColourBondNone();
    for( i=0; i<30; i++ )
        Shapely[i].col = 0;
    ResetColourAttrib();
    ScaleColourMap(30);

    ForEachAtom
        if( ptr->flag&SelectFlag )
        {   if( IsAminoNucleo(group->refno) )
            {   ref = Shapely + group->refno;
            } else ref = Shapely+30;

/*  Original Colour Scheme
 *
 *  ref = &(Shapely[26]);
 *  if( IsNucleo(group->refno) )
 *  {   ref = Shapely + group->refno;
 *  } else if( IsShapelyBackbone(ptr->refno) )
 *  {   ref = &(Shapely[24]);
 *  } else if( IsShapelySpecial(ptr->refno) )
 *  {   ref = &(Shapely[25]);
 *  } else if( IsAmino(group->refno) )
 *      ref = Shapely + group->refno;
 */

            if( !ref->col )
            {   ref->shade = DefineShade( ref->r, ref->g, ref->b );
                ref->col = Shade2Colour(ref->shade);
            }
            Shade[ref->shade].refcount++;
            ptr->col = ref->col;
        }

    AddAltlColours();
	if (DotCount && !UseOldColorCode)
		CalculateSurface(DotCount);

}


void StructColourAttrib( void )
{
    register ShadeRef *ref;
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *ptr;
    register int i;

    if( !Database )
        return;
	ColourBondNone();

    if( Info.helixcount < 0 )
        DetermineStructure(False);

    for( i=0; i<4; i++ )
        StructShade[i].col = 0;
    ResetColourAttrib();

    ForEachAtom
        if( ptr->flag&SelectFlag )
        {   if( group->struc & HelixFlag )
            {   ref = StructShade+1;
            } else if( group->struc & SheetFlag )
            {   ref = StructShade+2;
            } else if( group->struc & TurnFlag )
            {   ref = StructShade+3;
            } else ref = StructShade;

            if( !ref->col )
            {   ref->shade = DefineShade( ref->r, ref->g, ref->b );
                ref->col = Shade2Colour(ref->shade);
            }
            Shade[ref->shade].refcount++;
            ptr->col = ref->col;
        }

    AddAltlColours();
	if (DotCount && !UseOldColorCode)
		CalculateSurface(DotCount);

}


int IsCPKColour( RAtom __far *ptr )
{
    register ShadeRef *cpk;
    register ShadeDesc *col;

    cpk = CPKShade + Element[ptr->elemno].cpkcol;
    col = Shade + Colour2Shade(ptr->col);
    return( (col->r==cpk->r) && 
            (col->g==cpk->g) && 
            (col->b==cpk->b) );
}


int IsCpkNewColour( RAtom __far *ptr )
{
    register ShadeRef *cpknew;
    register ShadeDesc *col;

    cpknew = CpkNewShade + Element[ptr->elemno].cpkcol;
    col = Shade + Colour2Shade(ptr->col);
    return( (col->r==cpknew->r) &&
            (col->g==cpknew->g) &&
	    (col->b==cpknew->b) );
}
	

int IsVDWRadius( RAtom __far *ptr )
{
    register int rad;

    if( ptr->flag & SphereFlag )
    {   rad = ElemVDWRadius( ptr->elemno );
        return( ptr->radius == rad );
    } else return False;
}


void DefaultRepresentation( void )
{
    if( Database )
    {   ReDrawFlag |= RFRefresh | RFColour;
        if( Info.bondcount < 1 )
        {   EnableBackbone(CylinderFlag,80,64);
        } else EnableWireframe(WireFlag,0,0);
        CPKColourAttrib();
    }
}

void InitialTransform( void )
{
    register Card dist,max;
    register double fdist,fmax;
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *ptr;
    register Card ax, ay, az;
    register Long dx, dy, dz;

    dx = MaxX-MinX;   OrigCX = (dx>>1)+MinX;
    dy = MaxY-MinY;   OrigCY = (dy>>1)+MinY;
    dz = MaxZ-MinZ;   OrigCZ = (dz>>1)+MinZ;

    MaxX -= OrigCX;   MinX -= OrigCX;
    MaxY -= OrigCY;   MinY -= OrigCY;
    MaxZ -= OrigCZ;   MinZ -= OrigCZ;

    SideLen = MaxFun(dx,dy);
    if( dz>SideLen ) SideLen = dz;
    SideLen += 1500;  Offset = SideLen>>1;
    XOffset = WRange;  YOffset = HRange;
    ZOffset = 10000;

    ForEachAtom
    {   ptr->xorg -= OrigCX;
        ptr->yorg -= OrigCY;
        ptr->zorg -= OrigCZ;
        ptr->fxorg = 0;
        ptr->fyorg = 0;
        ptr->fzorg = 0;
    }

    if( Offset > 37836 )
    {   fmax = 0.0;
        ForEachAtom
        {   ax = (Card)AbsFun(ptr->xorg);
            ay = (Card)AbsFun(ptr->yorg);
            az = (Card)AbsFun(ptr->zorg);
            fdist = (double)ax*ax + 
                    (double)ay*ay + 
                    (double)az*az;
            if( fdist > fmax )
                fmax = fdist;
        }
    } else
    {   max = 1;
        ForEachAtom
        {   ax = (Card)AbsFun(ptr->xorg);
            ay = (Card)AbsFun(ptr->yorg);
            az = (Card)AbsFun(ptr->zorg);
            dist = ax*ax + ay*ay + az*az;
            if( dist > max )
                max = dist;
        }
        fmax = (double)max;
    }

    LocalRadius = ((Card)sqrt(fmax))+750.;
    if (LocalRadius > WorldRadius) {
      WorldRadius = LocalRadius;
      WorldSize = WorldRadius<<1;
      DScale = 1.0/WorldSize;

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
    
    /* Movie and animation intialization */
    
    play_fps = record_fps = 24.;  /* default to 24 fps */;
    record_aps = 10.;             /* default to 10 Angstroms per second */
    record_dwell = 0.5;           /* dwell half second per command (12 frames) */
    RecordTemplate[0] = 0;        /* no initial recording */
    PlayTemplate[0] = 0;          /* no initial playback  */
    RecordCurrent = RecordFrom = RecordUntil 
    = PlayCurrent = PlayFrom = PlayUntil = 0.;
    RecordPause = 1;
}


void ReviseInvMatrix( void )
{
    /* The inverse of a rotation matrix
     * is its transpose, and the inverse
     * of Scale is 1.0/Scale [IScale]!
     */
    InvX[0] = IScale*RotX[0];
    InvX[1] = IScale*RotY[0];
    InvX[2] = IScale*RotZ[0];

    InvY[0] = IScale*RotX[1];
    InvY[1] = IScale*RotY[1];
    InvY[2] = IScale*RotZ[1];

    InvZ[0] = IScale*RotX[2];
    InvZ[1] = IScale*RotY[2];
    InvZ[2] = IScale*RotZ[2];
    ShadowTransform();
}

/*
    RMatInv computes the inverse of a rotation matrix given
    three vectors.
  */

void RMatInv( Real RMX[3], Real RMY[3], Real RMZ[3],
              Real RIX[3], Real RIY[3], Real RIZ[3] ) {
              
  RIX[0] = RMX[0];
  RIX[1] = RMY[0];
  RIX[2] = RMZ[0];
  
  RIY[0] = RMX[1];
  RIY[1] = RMY[1];
  RIY[2] = RMZ[1];
  
  RIZ[0] = RMX[2];
  RIZ[1] = RMY[2];
  RIZ[2] = RMZ[2];

  return;
  
}

/*
    RMatVec applies a rotation matrix given a three rows
  
      |  RMX  |
      |  RMY  |
      |  RMZ  |
      
    applies it to VecIn and returns VecOut
  */
  
void RMatVec( Real VecOut[3], 
              Real RMX[3], Real RMY[3], Real RMZ[3],
              Real VecIn[3] ) {
              
  VecOut[0] = RMX[0]*VecIn[0] + RMX[1]*VecIn[1] + RMX[2]*VecIn[2];
  VecOut[1] = RMY[0]*VecIn[0] + RMY[1]*VecIn[1] + RMY[2]*VecIn[2];
  VecOut[2] = RMZ[0]*VecIn[0] + RMZ[1]*VecIn[1] + RMZ[2]*VecIn[2];
  return;
}
 
/*
   RMatRMat applies a rotation matrix given as three rows
   and applies it to 3x3 matrix MatIn and returns MatOut

   */
 
void RMatRMat( Real MatOut[3][3], 
              Real RMX[3], Real RMY[3], Real RMZ[3],
              Real MatIn[3][3] ) {
              
  int ii;
  
  for (ii = 0; ii < 3; ii++) {              
  MatOut[0][ii] = RMX[0]*MatIn[0][ii] + RMX[1]*MatIn[1][ii] + RMX[2]*MatIn[2][ii];
  MatOut[1][ii] = RMY[0]*MatIn[0][ii] + RMY[1]*MatIn[1][ii] + RMY[2]*MatIn[2][ii];
  MatOut[2][ii] = RMZ[0]*MatIn[0][ii] + RMZ[1]*MatIn[1][ii] + RMZ[2]*MatIn[2][ii];
  }
  return;
}

/*
    Rv2RMat creates a rotation matrix as three rows from
    three rotation dial values ranging from -1 for -PI radians
    to +1 for PI radians

  */

void RV2RMat( Real RX, Real RY, Real RZ, 
  Real RMX[3], Real RMY[3], Real RMZ[3]  ) {
  
  Real theta, cost, sint, x, y, z;
      
  theta = PI*RX;
  if (theta > PI ) theta = theta - 2*PI;
  if (theta < -PI ) theta = theta + 2*PI;
  cost = cos(theta);  sint = sin(theta);

  RMY[1]=cost;
  RMZ[1]=-sint;

  RMY[2]=sint;
  RMZ[2]=cost;

  theta = PI*RY;
  if (theta > PI ) theta = theta - 2*PI;
  if (theta < -PI ) theta = theta + 2*PI;
  cost = cos(theta);  sint = sin(theta);

  RMX[0]=cost;
  RMZ[0]=-sint;

  z=RMZ[1];
  RMX[1]=sint*z;
  RMZ[1]=cost*z;

  z=RMZ[2];
  RMX[2]=sint*z;
  RMZ[2]=cost*z;
    
  theta = PI*RZ;
  if (theta > PI ) theta = theta - 2*PI;
  if (theta < -PI ) theta = theta + 2*PI;
  cost = cos(theta);  sint = sin(theta);

  x=RMX[0];
  RMX[0]=cost*x;
  RMY[0]=sint*x;

  x=RMX[1]; y=RMY[1];
  RMX[1]=cost*x-sint*y;
  RMY[1]=cost*y+sint*x;

  x=RMX[2]; y=RMY[2];
  RMX[2]=cost*x-sint*y;
  RMY[2]=cost*y+sint*x;
  
  return;

}

void RMat2RV( Real __far *RX, Real __far *RY, Real __far *RZ, 
  Real RMX[3], Real RMY[3], Real RMZ[3]  ) {
  
  Real SRX, SRY, SRZ, TRX, TRY, TRZ;
  Real NSum;
  Real TSum;

  if (RMZ[0] < 1. ) {
    if (RMZ[0] > -1.) {
      SRY = asin(-RMZ[0])/PI;
    } else {
      SRY = .5;
    }
  } else {
    SRY = -.5;
  } 
  TRY = 1.-SRY;
  if ( TRY > 2. ) TRY -= 2.;
  TRZ = 1.;
  if (RMZ[0] > .9999995) {
    SRX = atan2(-RMX[1],RMY[1])/PI;
    TRX = SRX;
    SRZ = 0;
  } else {
    if (RMZ[0] < -.9999995 ) {
    SRX = atan2(RMX[1],RMY[1])/PI;
    TRX = SRX;
    SRZ = 0;
    } else {
      SRX = atan2(-RMZ[1],RMZ[2])/PI;
      TRX = 1.+SRX;
      if ( TRX > 2. ) TRX -= 2.;
      SRZ = atan2(RMY[0],RMX[0])/PI;
      TRZ = 1.+SRZ;
      if ( TRZ > 2. ) TRZ -= 2.;
    }
  }
  
  NSum = 0;
  TSum = 0;
  NSum += fabs(cos(SRX*PI)-cos((*RX)*PI)) + fabs(sin(SRX*PI)-sin((*RX)*PI))
    + fabs(cos(SRY*PI)-cos((*RY)*PI)) + fabs(sin(SRY*PI)-sin((*RY)*PI))
    + fabs(cos(SRZ*PI)-cos((*RZ)*PI)) + fabs(sin(SRZ*PI)-sin((*RZ)*PI));
  TSum += fabs(cos(TRX*PI)-cos((*RX)*PI)) + fabs(sin(TRX*PI)-sin((*RX)*PI))
    + fabs(cos(TRY*PI)-cos((*RY)*PI)) + fabs(sin(TRY*PI)-sin((*RY)*PI))
    + fabs(cos(TRZ*PI)-cos((*RZ)*PI)) + fabs(sin(TRZ*PI)-sin((*RZ)*PI));
  
  if (NSum < TSum) {
    *RX = SRX; *RY = SRY; *RZ = SRZ;
  } else {
    *RX = TRX; *RY = TRY; *RZ = TRZ;
  }
  
}
void PrepareTransform( void )
{
    register int ii;
    
    Real NRotX[3], NRotY[3], NRotZ[3];
    Real RMat[3][3], SMat[3][3], TMat[3][3];
    Real DialValueOffset[11], DialValueBalance[11];
    Real VecIn[3], VecOut[3];

    if ( BondSelected )
	BondRotate();

    for (ii=DialTX; ii<DialTZ+1; ii++) {
    	DialValueOffset[ii] = DialValue[ii];
    	DialValueBalance[ii] = 0;
    }
    for (ii=DialRX; ii<DialRZ+1; ii++) {
    	DialValueOffset[ii] = DialValue[ii];
    	DialValueBalance[ii] = 0;
    }
    DialValueOffset[DialTX] -= LastTX;
    DialValueOffset[DialTY] -= LastTY;
    DialValueOffset[DialTZ] -= LastTZ;
    DialValueOffset[DialRX] -= LastRX;
    DialValueOffset[DialRY] -= LastRY;
    DialValueOffset[DialRZ] -= LastRZ;

    if( ReDrawFlag )
    {         
 
    if ( (DialValueOffset[DialTX] != 0 ) ||
         (DialValueOffset[DialTY] != 0 ) ||
         (DialValueOffset[DialTZ] != 0 ) ) {

      if (record_aps > 0. || record_fps > 0.) 
      {
      	Real tlimit;
      	tlimit = Scale*250.*record_aps/record_fps;
        DialValueOffset[DialTX] *= XRange;
        DialValueOffset[DialTY] *= YRange;
        DialValueOffset[DialTZ] *= ZRange;
          
      	if (DialValueOffset[DialTX]>tlimit) { 
      	   DialValueBalance[DialTX] = DialValueOffset[DialTX] - tlimit;
      	   DialValueOffset[DialTX]=tlimit; NextReDrawFlag = ReDrawFlag;
      	}
      	if (DialValueOffset[DialTX]<-tlimit) { 
      	   DialValueBalance[DialTX] = DialValueOffset[DialTX] + tlimit;
      	   DialValueOffset[DialTX]=-tlimit;  NextReDrawFlag = ReDrawFlag;
      	}
      	if (DialValueOffset[DialTY]>tlimit) { 
      	   DialValueBalance[DialTY] = DialValueOffset[DialTY] - tlimit;
      	   DialValueOffset[DialTY]=tlimit; NextReDrawFlag = ReDrawFlag;
      	}
      	if (DialValueOffset[DialTY]<-tlimit) {
      	   DialValueBalance[DialTY] = DialValueOffset[DialTY] + tlimit;
      	   DialValueOffset[DialTY]=-tlimit;  NextReDrawFlag = ReDrawFlag;
      	}
      	if (DialValueOffset[DialTZ]>tlimit) { 
      	   DialValueBalance[DialTZ] = DialValueOffset[DialTZ] - tlimit;
      	   DialValueOffset[DialTZ]=tlimit; NextReDrawFlag = ReDrawFlag;
      	}
      	if (DialValueOffset[DialTZ]<-tlimit) { 
      	   DialValueBalance[DialTZ] = DialValueOffset[DialTZ] + tlimit;
      	   DialValueOffset[DialTZ]=-tlimit;  NextReDrawFlag = ReDrawFlag;
      	}
      } 
         
      VecIn[0] = DialValueOffset[DialTX];
      VecIn[1] = DialValueOffset[DialTY];
      VecIn[2] = DialValueOffset[DialTZ];

      RMatVec(VecOut,WIRotX,WIRotY,WIRotZ,VecIn);
      
      LastTX += VecOut[0]/XRange;
      LastTY += VecOut[1]/YRange;
      LastTZ += VecOut[2]/ZRange;
      
      DialValue[DialTX] = LastTX+DialValueBalance[DialTX]/XRange;
      DialValue[DialTY] = LastTY+DialValueBalance[DialTY]/YRange;
      DialValue[DialTZ] = LastTZ+DialValueBalance[DialTZ]/ZRange;
     
    } 

    LOffset[0] = WRange + (int)rint(Zoom*LastTX*XRange);
    LOffset[1] = HRange + (int)rint(Zoom*LastTY*YRange);
    LOffset[2] = 10000 + (int)rint(Zoom*LastTZ*ZRange);
        

    if ( ( DialValueOffset[DialRX] != LastRX ) || 
         ( DialValueOffset[DialRY] != LastRY ) ||
        ( DialValueOffset[DialRZ] != LastRZ ) ) {
        
        if (record_aps > 0. || record_fps > 0.) 
        {
            Real slimit;
            slimit = 39.788*record_aps/record_fps/WorldRadius;
            if (DialValueOffset[DialRX] > 1. ) DialValueOffset[DialRX] -=2.;
            if (DialValueOffset[DialRX] < -1. ) DialValueOffset[DialRX] +=2.;
            if (DialValueOffset[DialRY] > 1. ) DialValueOffset[DialRY] -=2.;
            if (DialValueOffset[DialRY] < -1. ) DialValueOffset[DialRY] +=2.;
            if (DialValueOffset[DialRZ] > 1. ) DialValueOffset[DialRZ] -=2.;
            if (DialValueOffset[DialRZ] < -1. ) DialValueOffset[DialRZ] +=2.;
            if (DialValueOffset[DialRX]>slimit) { 
                DialValueBalance[DialRX] = DialValueOffset[DialRX] - slimit;
                DialValueOffset[DialRX]=slimit; NextReDrawFlag = ReDrawFlag;
            }
            if (DialValueOffset[DialRX]<-slimit) { 
                DialValueBalance[DialRX] = DialValueOffset[DialRX] + slimit;
                DialValueOffset[DialRX]=-slimit;  NextReDrawFlag = ReDrawFlag;
            }
            if (DialValueOffset[DialRY]>slimit) { 
                DialValueBalance[DialRY] = DialValueOffset[DialRY] - slimit;
                DialValueOffset[DialRY]=slimit; NextReDrawFlag = ReDrawFlag;
            }
            if (DialValueOffset[DialRY]<-slimit) {
                DialValueBalance[DialRY] = DialValueOffset[DialRY] + slimit;
                DialValueOffset[DialRY]=-slimit;  NextReDrawFlag = ReDrawFlag;
            }
            if (DialValueOffset[DialRZ]>slimit) { 
                DialValueBalance[DialRZ] = DialValueOffset[DialRZ] - slimit;
                DialValueOffset[DialRZ]=slimit; NextReDrawFlag = ReDrawFlag;
            }
            if (DialValueOffset[DialRZ]<-slimit) { 
                DialValueBalance[DialRZ] = DialValueOffset[DialRZ] + slimit;
                DialValueOffset[DialRZ]=-slimit;  NextReDrawFlag = ReDrawFlag;
            }
        } 
      	
        RV2RMat(DialValueOffset[DialRX], DialValueOffset[DialRY], DialValueOffset[DialRZ],
                SMat[0],SMat[1],SMat[2]);
        
        /* SMat is the incremental rotation on the World frame       */
        /* We transform to WInv S W, the rotation in the local frame */
        
        RMatRMat(TMat,WIRotX,WIRotY,WIRotZ,SMat);
        
        for (ii = 0; ii < 3; ii++) {
            RMat[0][ii] = WLRotX[ii];
            RMat[1][ii] = WLRotY[ii];
            RMat[2][ii] = WLRotZ[ii];
        }
        RMatRMat(SMat,TMat[0],TMat[1],TMat[2],RMat);
        
        for (ii = 0; ii < 3; ii++) {
            RMat[0][ii] = LRotX[ii];
            RMat[1][ii] = LRotY[ii];
            RMat[2][ii] = LRotZ[ii];
            NRotX[ii] = SMat[0][ii];
            NRotY[ii] = SMat[1][ii];
            NRotZ[ii] = SMat[2][ii];
        }
        
        LRotX[0] = NRotX[0]*RMat[0][0]+NRotX[1]*RMat[1][0]+NRotX[2]*RMat[2][0];
        LRotX[1] = NRotX[0]*RMat[0][1]+NRotX[1]*RMat[1][1]+NRotX[2]*RMat[2][1];
        LRotX[2] = NRotX[0]*RMat[0][2]+NRotX[1]*RMat[1][2]+NRotX[2]*RMat[2][2];
        
        LRotY[0] = NRotY[0]*RMat[0][0]+NRotY[1]*RMat[1][0]+NRotY[2]*RMat[2][0];
        LRotY[1] = NRotY[0]*RMat[0][1]+NRotY[1]*RMat[1][1]+NRotY[2]*RMat[2][1];
        LRotY[2] = NRotY[0]*RMat[0][2]+NRotY[1]*RMat[1][2]+NRotY[2]*RMat[2][2];
        
        LRotZ[0] = NRotZ[0]*RMat[0][0]+NRotZ[1]*RMat[1][0]+NRotZ[2]*RMat[2][0];
        LRotZ[1] = NRotZ[0]*RMat[0][1]+NRotZ[1]*RMat[1][1]+NRotZ[2]*RMat[2][1];
        LRotZ[2] = NRotZ[0]*RMat[0][2]+NRotZ[1]*RMat[1][2]+NRotZ[2]*RMat[2][2];
        
        RMat2RV(&LastRX, 
                &LastRY, 
                &LastRZ, 
                LRotX, LRotY, LRotZ);
        
        DialValue[DialRX] = LastRX+DialValueBalance[DialRX];
        DialValue[DialRY] = LastRY+DialValueBalance[DialRY];
        DialValue[DialRZ] = LastRZ+DialValueBalance[DialRZ];
        
        for (ii=DialRX; ii <=DialRY; ii++) {
            if (DialValue[ii] > 1.) DialValue[ii] -=2.;
            if (DialValue[ii] < -1.) DialValue[ii] +=2.;
        }
        
        RV2RMat(LastRX, LastRY, LastRZ,
                LRotX, LRotY, LRotZ);
    }
    }
    WorldRotate();
}


static void ApplyTransformOne( void )
{
    register Real x, y, z;
    register Chain __far *chain;
    register Group __far *group;
    register HBond __far *hptr;
    register Bond __far *bptr;
    register RAtom __far *ptr;

    if( ReDrawFlag & (RFMagnify | RFZoom) )
    {   Real ZoomSave, zlimit;
        
        ZoomSave = Zoom;

        if( DialValue[DialZoom] <= 0.0 )
        {   Zoom = DialValue[DialZoom]+1.0;
            if( Zoom<0.1 ) Zoom=0.1;
        } else Zoom = (DialValue[DialZoom]*MaxZoom) + 1.0;
        
        if (record_aps != 0. && record_fps != 0) {
            zlimit = 250.*record_aps/record_fps/WorldRadius;
            if (Zoom-ZoomSave > zlimit ) {
                Zoom = ZoomSave+zlimit;
                NextReDrawFlag |= RFMagnify | RFZoom;
            }
            if (Zoom-ZoomSave < -zlimit )  {
                Zoom = ZoomSave-zlimit;
                NextReDrawFlag |= RFMagnify | RFZoom;
            }
        }

        Scale = Zoom*DScale*Range;
        LScale = (Long)(Scale*256);
        iProbeRad = (int)(Scale*ProbeRadius);
        ImageSize = (int)(Scale*WorldSize);
        if( ImageSize < 2 )
        {   ImageRadius = 1;
            ImageSize = 2;
        } else 
            ImageRadius = ImageSize>>1;
        IScale = 1.0/Scale;

        MaxAtomRadius = 0;
        MaxBondRadius = 0;

    }

    if( ReDrawFlag & (RFRotate|RFMagnify|RFZoom|RFTrans) )
    {   PrepareTransform();
        if( UseShadow )
            ShadowTransform();
    }

    if( ReDrawFlag & (RFRotate|RFMagnify|RFZoom|RFTrans) )
    {   MatX[0] = Scale*RotX[0]; 
        MatX[1] = Scale*RotX[1];
        MatX[2] = Scale*RotX[2];

        MatY[0] = Scale*RotY[0];
        MatY[1] = Scale*RotY[1];
        MatY[2] = Scale*RotY[2];

        MatZ[0] = Scale*RotZ[0];
        MatZ[1] = Scale*RotZ[1];
        MatZ[2] = Scale*RotZ[2];

        if( UseShadow )
        {   InvX[0] = IScale*RotX[0]; 
            InvX[1] = IScale*RotY[0];
            InvX[2] = IScale*RotZ[0];

            InvY[0] = IScale*RotX[1];
            InvY[1] = IScale*RotY[1];
            InvY[2] = IScale*RotZ[1];

            InvZ[0] = IScale*RotX[2];
            InvZ[1] = IScale*RotY[2];
            InvZ[2] = IScale*RotZ[2];
        }
    }
   
    switch( ReDrawFlag )
    {

        case(RFRotateX):
            ForEachAtom
            {   x = ptr->xorg + ptr->fxorg - CenX; 
                y = ptr->yorg + ptr->fyorg - CenY; 
                z = ptr->zorg + ptr->fzorg - CenZ;
                ptr->y = (int)rint(x*MatY[0]+y*MatY[1]+z*MatY[2])+YOffset;
                ptr->z = (int)rint(x*MatZ[0]+y*MatZ[1]+z*MatZ[2])+ZOffset;
            }
            break;

        case(RFRotateY):
            ForEachAtom
            {   x = ptr->xorg + ptr->fxorg - CenX; 
                y = ptr->yorg + ptr->fyorg - CenY; 
                z = ptr->zorg + ptr->fzorg - CenZ;
                ptr->x = (int)rint(x*MatX[0]+y*MatX[1]+z*MatX[2])+XOffset;
                ptr->z = (int)rint(x*MatZ[0]+y*MatZ[1]+z*MatZ[2])+ZOffset;
            }
            break;

        case(RFRotateZ):
            ForEachAtom
            {   x = ptr->xorg + ptr->fxorg - CenX; 
                y = ptr->yorg + ptr->fyorg - CenY; 
                z = ptr->zorg + ptr->fzorg - CenZ;
                ptr->x = (int)rint(x*MatX[0]+y*MatX[1]+z*MatX[2])+XOffset;
                ptr->y = (int)rint(x*MatY[0]+y*MatY[1]+z*MatY[2])+YOffset;
            }
            break;

        default:
            /* This condition scales atomic radii! */
            if( (DrawAtoms || DrawStars || DrawSurf) &&
                (ReDrawFlag&(RFMagnify | RFZoom)) )
            {   ForEachAtom 
                {   x = ptr->xorg + ptr->fxorg - CenX; 
                    y = ptr->yorg + ptr->fyorg - CenY; 
                    z = ptr->zorg + ptr->fzorg - CenZ;
                    ptr->x = (int)rint(x*MatX[0]+y*MatX[1]+z*MatX[2])+XOffset;
                    ptr->y = (int)rint(x*MatY[0]+y*MatY[1]+z*MatY[2])+YOffset;
                    ptr->z = (int)rint(x*MatZ[0]+y*MatZ[1]+z*MatZ[2])+ZOffset;
                    if( ptr->flag&(SphereFlag|StarFlag|TouchFlag|ExpandFlag) )
                    {   ptr->irad = (int)(Scale*(Real)(ptr->radius));
                        if( ptr->irad>MaxAtomRadius )
                            MaxAtomRadius = ptr->irad;
                        if (ptr->flag&ExpandFlag)
                        {
                           if ((ptr->irad)+iProbeRad > MaxAtomRadius )
                             MaxAtomRadius = (ptr->irad)+iProbeRad;
                        }
                    }
                }
            } else
                ForEachAtom 
                {   x = ptr->xorg + ptr->fxorg - CenX; 
                    y = ptr->yorg + ptr->fyorg - CenY; 
                    z = ptr->zorg + ptr->fzorg - CenZ;
                    ptr->x = (int)rint(x*MatX[0]+y*MatX[1]+z*MatX[2])+XOffset;
                    ptr->y = (int)rint(x*MatY[0]+y*MatY[1]+z*MatY[2])+YOffset;
                    ptr->z = (int)rint(x*MatZ[0]+y*MatZ[1]+z*MatZ[2])+ZOffset;
                }

            if( ReDrawFlag & ( RFMagnify | RFZoom ) )
            {   if( DrawBonds )
                    ForEachBond
                        if( bptr->flag&CylinderFlag )
                        {   bptr->irad = (int)rint(Scale*(Real)(bptr->radius));
                            bptr->iarad = (int)rint(Scale*(Real)(bptr->aradius));
                            if( bptr->irad>MaxBondRadius )
                            MaxBondRadius = bptr->irad;
                        }

                for( hptr=Database->hlist; hptr; hptr=hptr->hnext )
		    if( hptr->flag&CylinderFlag ) {
                        hptr->irad = (int)rint(Scale*(Real)(hptr->radius));
                        hptr->iarad = (int)rint(Scale*(Real)(hptr->aradius));
                    }

                for( hptr=Database->slist; hptr; hptr=hptr->hnext )
		    if( hptr->flag&CylinderFlag ) {
                        hptr->irad = (int)rint(Scale*(Real)(hptr->radius));
                        hptr->iarad = (int)rint(Scale*(Real)(hptr->aradius));
		    }

                ForEachBack
		    if( bptr->flag&CylinderFlag ) {
                        bptr->irad = (int)rint(Scale*(Real)(bptr->radius));
                        bptr->iarad = (int)rint(Scale*(Real)(bptr->aradius));
                    }
            }
    }

    DetermineClipping();
    if( UseScreenClip || ReDrawFlag!=RFRotateY )
        BucketFlag = False;
}



void CentreTransform( int xo, int yo, int zo, int xlatecen )
{	register Real x, y, z;

	x = xo - CenX;
	y = yo - CenY; 
	z = zo - CenZ;

	if( xlatecen )
	{	DialValue[DialTX] += (x*MatX[0]+y*MatX[1]+z*MatX[2])/XRange;
		DialValue[DialTY] += (x*MatY[0]+y*MatY[1]+z*MatY[2])/YRange;
		DialValue[DialTZ] += (x*MatZ[0]+y*MatZ[1]+z*MatZ[2])/ZRange;
	}

	if( UseSlabPlane )
	{	DialValue[DialSlab] -= (x*MatZ[0]+y*MatZ[1]+z*MatZ[2])/ImageRadius;
		if( DialValue[DialSlab]<-1 )
		{	DialValue[DialSlab] = -1;
			UseSlabPlane = False;
			UseShadow = True;
		}
		if( DialValue[DialSlab]>1 )
			DialValue[DialSlab] = 1;
	}

	if( UseDepthPlane )
	{	DialValue[DialBClip] -= (x*MatZ[0]+y*MatZ[1]+z*MatZ[2])/ImageRadius;
		if( DialValue[DialBClip]<-1 )
			DialValue[DialBClip] = -1;
		if( DialValue[DialBClip]>1 )
		{	DialValue[DialBClip] = 1;
			UseDepthPlane = False;
			UseShadow = True;
		}
	}

	CenX = xo;
    CenY = yo;
    CenZ = zo;

    ReDrawFlag |= RFRotate;
}


/* [GSG 11/9/95] Multiple ApplyTransform added */
void ApplyTransform( void )
{
    /* Do global operation if scaling */
    int Global, i, SaveMolecule, SaveRD;

    Global = (ReDrawFlag & RFMagnify) || (RotMode == RotAll);
    
    if (Global) {
	SaveMolecule = MoleculeIndex;
      SaveRD = ReDrawFlag;
	  for (i=0; i<NumMolecules; i++) {
	    SwitchMolecule(i);
            ReDrawFlag |= SaveRD;
	    ApplyTransformOne();
	  }
	  SwitchMolecule(SaveMolecule);
    } else
	ApplyTransformOne();
    
}


void ResetTransform( void )
{
    RotX[0] = 1.0;  RotX[1] = 0.0;  RotX[2] = 0.0;
    RotY[0] = 0.0;  RotY[1] = 1.0;  RotY[2] = 0.0;
    RotZ[0] = 0.0;  RotZ[1] = 0.0;  RotZ[2] = 1.0;

    LRotX[0] = 1.0;  LRotX[1] = 0.0;  LRotX[2] = 0.0;
    LRotY[0] = 0.0;  LRotY[1] = 1.0;  LRotY[2] = 0.0;
    LRotZ[0] = 0.0;  LRotZ[1] = 0.0;  LRotZ[2] = 1.0;
    
    LastRX = LastRY = LastRZ = 0.0;
    LastTX = LastTY = LastTZ = 0.0;
    
    WRotValue[0] = 0;
    WRotValue[1] = 0;
    WRotValue[2] = 0;

    WLRotX[0] = 1.0;  WLRotX[1] = 0.0;  WLRotX[2] = 0.0;
    WLRotY[0] = 0.0;  WLRotY[1] = 1.0;  WLRotY[2] = 0.0;
    WLRotZ[0] = 0.0;  WLRotZ[1] = 0.0;  WLRotZ[2] = 1.0;
 
    WIRotX[0] = 1.0;  WIRotX[1] = 0.0;  WIRotX[2] = 0.0;
    WIRotY[0] = 0.0;  WIRotY[1] = 1.0;  WIRotY[2] = 0.0;
    WIRotZ[0] = 0.0;  WIRotZ[1] = 0.0;  WIRotZ[2] = 1.0;

    WLastRX = WLastRY = WLastRZ = 0;
    WTransX = WTransY = WTransZ = 0;
    WLastTX = WLastTY = WLastTZ = 0;
    
       /* Remove all bonds from the list of selected bonds */

    if (BondsSelected) {
      BondRot __far *brptr=BondsSelected;

      while (brptr) {
        if( BondSelected == brptr ) {
          BondSelected = brptr->brnext;
        }
        BondsSelected = brptr->brnext;
        _ffree(brptr);
        brptr = BondsSelected;
      }
    }

    BondsSelected = (BondRot __far *)NULL;
    BondSelected = (BondRot __far *)NULL;
#ifdef GTKWIN
    if(Interactive)
	   EnableRotBondMenu(False);
#endif 
    CenX = CenY = CenZ = 0;
    ShiftS = 0;
    XlateCen = False;
    BLastRot = -99999.;
}


void InitialiseTransform( void )
{
    ResetColourMap();
    ResetTransform();

    ZoneBoth = True;
    HetaGroups = True;
    Hydrogens = True;
    MarkAtoms = 0;
}

