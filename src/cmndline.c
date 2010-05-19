/***************************************************************************
 *                             RasMol 2.7.5                                *
 *                                                                         *
 *                                 RasMol                                  *
 *                 Molecular Graphics Visualisation Tool                   *
 *                              13 June 2009                               *
 *                          (rev. 9 August 2009)                           *
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
/* cmndline.c
 */

#include "rasmol.h"

#ifdef IBMPC
#include <windows.h>
#include <malloc.h>
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
#ifndef sun386
#include <stdlib.h>
#endif

#include <string.h>
#include <ctype.h>
#include <stdio.h>

#define CMNDLINE
#include "cmndline.h"
#include "molecule.h"
#include "abstree.h"
#include "command.h"
#include "render.h"
#include "transfor.h"
#include "graphics.h"
#include "vector.h"
#include "wbrotate.h"
#include "langsel.h"


/* Determine Mouse Sensitivity! */
#define IsClose(u,v) (((u)>=(v)-1) && ((u)<=(v)+1))


#define MM_NONE   0x00
#define MM_ROTX   0x01
#define MM_ROTY   0x02
#define MM_ROTZ   0x03
#define MM_TRNX   0x04
#define MM_TRNY   0x05
#define MM_ZOOM   0x06
#define MM_CLIP   0x07
#define MM_DEPT   0x08

#define MM_PICK   0x01
#define MM_NEXT   0x02
#define MM_LABL   0x03
#define MM_SELE   0x04
#define MM_PREV   0x05



typedef struct {
        Byte dxfunc, dxinvrt;
        Byte dyfunc, dyinvrt;
        Byte click;
    } MouseMapping;


/* RasMol Mouse Bindings:
 *  XY Rotation:   Left (and any other) Button
 *  XY Translaion: Middle or Right Buttons
 *  Scale:         Shift (and Control) Left (and any other) Button
 *  Z Rotation:    Shift (and Control) Middle or Right Buttons
 *  Clipping:      Control Left (and any other) Button
 */

#ifdef INVERT
#define	INV	1
#else
#define INV 0
#endif
 
 
static MouseMapping MouseRasMol[32] = {
        { MM_NONE, 0, MM_NONE, INV, MM_PICK },  /*                     */
        { MM_ROTY, 0, MM_ROTX, INV, MM_PICK },  /* Lft                 */
        { MM_TRNX, 0, MM_TRNY, INV, MM_PICK },  /*     Mid             */
        { MM_ROTY, 0, MM_ROTX, INV, MM_PICK },  /* Lft+Mid             */
        { MM_TRNX, 0, MM_TRNY, INV, MM_PICK },  /*         Rgt         */
        { MM_ROTY, 0, MM_ROTX, INV, MM_PICK },  /* Lft    +Rgt         */
        { MM_TRNX, 0, MM_TRNY, INV, MM_PICK },  /*     Mid+Rgt         */
        { MM_ROTY, 0, MM_ROTX, INV, MM_PICK },  /* Lft+Mid+Rgt         */
        { MM_NONE, 0, MM_NONE, INV, MM_NEXT },  /*             Sft     */
        { MM_NONE, 0, MM_ZOOM, INV, MM_NEXT },  /* Lft        +Sft     */
        { MM_ROTZ, 0, MM_NONE, INV, MM_NEXT },  /*     Mid    +Sft     */
        { MM_NONE, 0, MM_ZOOM, INV, MM_NEXT },  /* Lft+Mid    +Sft     */
        { MM_ROTZ, 0, MM_NONE, INV, MM_NEXT },  /*         Rgt+Sft     */
        { MM_NONE, 0, MM_ZOOM, INV, MM_NEXT },  /* Lft    +Rgt+Sft     */
        { MM_ROTZ, 0, MM_NONE, INV, MM_NEXT },  /*     Mid+Rgt+Sft     */
        { MM_NONE, 0, MM_ZOOM, INV, MM_NEXT },  /* Lft+Mid+Rgt+Sft     */
        { MM_NONE, 0, MM_NONE, INV, MM_PREV },  /*                 Ctl */
        { MM_NONE, 0, MM_CLIP, INV, MM_PREV },  /* Lft            +Ctl */
        { MM_NONE, 0, MM_NONE, INV, MM_PREV },  /*     Mid        +Ctl */
        { MM_NONE, 0, MM_CLIP, INV, MM_PREV },  /* Lft+Mid        +Ctl */
        { MM_NONE, 0, MM_DEPT, INV, MM_PREV },  /*         Rgt    +Ctl */
        { MM_NONE, 0, MM_NONE, INV, MM_PREV },  /* Lft    +Rgt    +Ctl */
        { MM_NONE, 0, MM_DEPT, INV, MM_PREV },  /*     Mid+Rgt    +Ctl */
        { MM_NONE, 0, MM_NONE, INV, MM_PREV },  /* Lft+Mid+Rgt    +Ctl */
        { MM_NONE, 0, MM_NONE, INV, MM_NEXT },  /*             Sft+Ctl */
        { MM_NONE, 0, MM_ZOOM, INV, MM_NEXT },  /* Lft        +Sft+Ctl */
        { MM_ROTZ, 0, MM_NONE, INV, MM_NEXT },  /*     Mid    +Sft+Ctl */
        { MM_NONE, 0, MM_ZOOM, INV, MM_NEXT },  /* Lft+Mid    +Sft+Ctl */
        { MM_ROTZ, 0, MM_NONE, INV, MM_NEXT },  /*         Rgt+Sft+Ctl */
        { MM_NONE, 0, MM_ZOOM, INV, MM_NEXT },  /* Lft    +Rgt+Sft+Ctl */
        { MM_ROTZ, 0, MM_NONE, INV, MM_NEXT },  /*     Mid+Rgt+Sft+Ctl */
        { MM_NONE, 0, MM_ZOOM, INV, MM_NEXT },  /* Lft+Mid+Rgt+Sft+Ctl */
    };        
           
           
/* MSI (Biosym) Insight Bindings:
 *     Needs to be verified!
 */
static MouseMapping MouseInsight[32] = {
        { MM_NONE, 0, MM_NONE, INV, MM_PICK },  /*                     */
        { MM_ROTY, 0, MM_ROTX, INV, MM_PICK },  /* Lft                 */
        { MM_TRNX, 0, MM_TRNY, INV, MM_PICK },  /*     Mid             */
        { MM_ZOOM, 0, MM_ZOOM, INV, MM_PICK },  /* Lft+Mid             */
        { MM_NONE, 0, MM_NONE, INV, MM_PICK },  /*         Rgt         */
        { MM_ROTZ, 0, MM_ROTZ, INV, MM_PICK },  /* Lft    +Rgt         */
        { MM_NONE, 0, MM_NONE, INV, MM_PICK },  /*     Mid+Rgt         */
        { MM_CLIP, 0, MM_CLIP, INV, MM_PICK },  /* Lft+Mid+Rgt         */
        { MM_NONE, 0, MM_NONE, INV, MM_NEXT },  /*             Sft     */
        { MM_ROTY, 0, MM_ROTX, INV, MM_NEXT },  /* Lft        +Sft     */
        { MM_TRNY, 0, MM_TRNY, INV, MM_NEXT },  /*     Mid    +Sft     */
        { MM_ZOOM, 0, MM_ZOOM, INV, MM_NEXT },  /* Lft+Mid    +Sft     */
        { MM_NONE, 0, MM_NONE, INV, MM_NEXT },  /*         Rgt+Sft     */
        { MM_ROTZ, 0, MM_ROTZ, INV, MM_NEXT },  /* Lft    +Rgt+Sft     */
        { MM_NONE, 0, MM_NONE, INV, MM_NEXT },  /*     Mid+Rgt+Sft     */
        { MM_CLIP, 0, MM_CLIP, INV, MM_NEXT },  /* Lft+Mid+Rgt+Sft     */
        { MM_NONE, 0, MM_NONE, INV, MM_PREV },  /*                 Ctl */
        { MM_ROTY, 0, MM_ROTX, INV, MM_PREV },  /* Lft            +Ctl */
        { MM_TRNX, 0, MM_TRNY, INV, MM_PREV },  /*     Mid        +Ctl */
        { MM_ZOOM, 0, MM_ZOOM, INV, MM_PREV },  /* Lft+Mid        +Ctl */
        { MM_NONE, 0, MM_NONE, INV, MM_PREV },  /*         Rgt    +Ctl */
        { MM_ROTZ, 0, MM_ROTZ, INV, MM_PREV },  /* Lft    +Rgt    +Ctl */
        { MM_NONE, 0, MM_NONE, INV, MM_PREV },  /*     Mid+Rgt    +Ctl */
        { MM_CLIP, 0, MM_CLIP, INV, MM_PREV },  /* Lft+Mid+Rgt    +Ctl */
        { MM_NONE, 0, MM_NONE, INV, MM_NEXT },  /*             Sft+Ctl */
        { MM_ROTY, 0, MM_ROTX, INV, MM_NEXT },  /* Lft        +Sft+Ctl */
        { MM_TRNX, 0, MM_TRNY, INV, MM_NEXT },  /*     Mid    +Sft+Ctl */
        { MM_ZOOM, 0, MM_ZOOM, INV, MM_NEXT },  /* Lft+Mid    +Sft+Ctl */
        { MM_NONE, 0, MM_NONE, INV, MM_NEXT },  /*         Rgt+Sft+Ctl */
        { MM_ROTZ, 0, MM_ROTZ, INV, MM_NEXT },  /* Lft    +Rgt+Sft+Ctl */
        { MM_NONE, 0, MM_NONE, INV, MM_NEXT },  /*     Mid+Rgt+Sft+Ctl */
        { MM_CLIP, 0, MM_CLIP, INV, MM_NEXT },  /* Lft+Mid+Rgt+Sft+Ctl */
    };        


/* MSI Quanta Mouse Bindings:
 *     Needs to be verified!
 */
static MouseMapping MouseQuanta[32] = {
        { MM_NONE, 0, MM_NONE, INV, MM_PICK },  /*                     */
        { MM_ROTY, 0, MM_ROTX, INV, MM_PICK },  /* Lft                 */
        { MM_ROTY, 0, MM_ROTX, INV, MM_PICK },  /*     Mid             */
        { MM_ROTY, 0, MM_ROTX, INV, MM_PICK },  /* Lft+Mid             */
        { MM_ROTZ, 0, MM_NONE, INV, MM_PICK },  /*         Rgt         */
        { MM_ROTY, 0, MM_ROTX, INV, MM_PICK },  /* Lft    +Rgt         */
        { MM_ROTY, 0, MM_ROTX, INV, MM_PICK },  /*     Mid+Rgt         */
        { MM_ROTY, 0, MM_ROTX, INV, MM_PICK },  /* Lft+Mid+Rgt         */
        { MM_NONE, 0, MM_ZOOM, INV, MM_NEXT },  /*             Sft     */
        { MM_NONE, 0, MM_CLIP, INV, MM_NEXT },  /* Lft        +Sft     */
        { MM_TRNX, 0, MM_TRNY, INV, MM_NEXT },  /*     Mid    +Sft     */
        { MM_NONE, 0, MM_CLIP, INV, MM_NEXT },  /* Lft+Mid    +Sft     */
        { MM_TRNX, 0, MM_TRNY, INV, MM_NEXT },  /*         Rgt+Sft     */
        { MM_NONE, 0, MM_CLIP, INV, MM_NEXT },  /* Lft    +Rgt+Sft     */
        { MM_TRNX, 0, MM_TRNY, INV, MM_NEXT },  /*     Mid+Rgt+Sft     */
        { MM_NONE, 0, MM_CLIP, INV, MM_NEXT },  /* Lft+Mid+Rgt+Sft     */
        { MM_NONE, 0, MM_NONE, INV, MM_PREV },  /*                 Ctl */
        { MM_ROTY, 0, MM_ROTX, INV, MM_PREV },  /* Lft            +Ctl */
        { MM_ROTY, 0, MM_ROTX, INV, MM_PREV },  /*     Mid        +Ctl */
        { MM_ROTY, 0, MM_ROTX, INV, MM_PREV },  /* Lft+Mid        +Ctl */
        { MM_ROTZ, 0, MM_NONE, INV, MM_PREV },  /*         Rgt    +Ctl */
        { MM_ROTY, 0, MM_ROTX, INV, MM_PREV },  /* Lft    +Rgt    +Ctl */
        { MM_ROTY, 0, MM_ROTX, INV, MM_PREV },  /*     Mid+Rgt    +Ctl */
        { MM_ROTY, 0, MM_ROTX, INV, MM_PREV },  /* Lft+Mid+Rgt    +Ctl */
        { MM_NONE, 0, MM_ZOOM, INV, MM_NEXT },  /*             Sft+Ctl */
        { MM_NONE, 0, MM_CLIP, INV, MM_NEXT },  /* Lft        +Sft+Ctl */
        { MM_TRNX, 0, MM_TRNY, INV, MM_NEXT },  /*     Mid    +Sft+Ctl */
        { MM_NONE, 0, MM_CLIP, INV, MM_NEXT },  /* Lft+Mid    +Sft+Ctl */
        { MM_TRNX, 0, MM_TRNY, INV, MM_NEXT },  /*         Rgt+Sft+Ctl */
        { MM_NONE, 0, MM_CLIP, INV, MM_NEXT },  /* Lft    +Rgt+Sft+Ctl */
        { MM_TRNX, 0, MM_TRNY, INV, MM_NEXT },  /*     Mid+Rgt+Sft+Ctl */
        { MM_NONE, 0, MM_CLIP, INV, MM_NEXT },  /* Lft+Mid+Rgt+Sft+Ctl */
    };        
                 
/* Tripos Sybyl 6.2 Mouse Bindings:
 *    Tripos Graphics Manual, July 1995
 *  Selection:      Left Button
 *  Scale:          Middle & Right Buttons
 *  XY Rotation:    Right Button
 *  Z Rotation:     Left & Right Buttons
 *  XY Translation: Middle Button
 *  Z Translation:  Left & Middle Buttons
 */
 
static MouseMapping MouseSybyl[32] = {
        { MM_NONE, 0, MM_NONE, INV, MM_PICK },  /*                     */
        { MM_NONE, 0, MM_NONE, INV, MM_PICK },  /* Lft                 */
        { MM_TRNX, 0, MM_TRNY, INV, MM_PICK },  /*     Mid             */
        { MM_NONE, 0, MM_NONE, INV, MM_PICK },  /* Lft+Mid             */
        { MM_ROTY, 0, MM_ROTX, INV, MM_PICK },  /*         Rgt         */
        { MM_ROTZ, 0, MM_NONE, INV, MM_PICK },  /* Lft    +Rgt         */
        { MM_ZOOM, 0, MM_ZOOM, INV, MM_PICK },  /*     Mid+Rgt         */
        { MM_NONE, 0, MM_NONE, INV, MM_PICK },  /* Lft+Mid+Rgt         */
        { MM_NONE, 0, MM_NONE, INV, MM_NEXT },  /*             Sft     */
        { MM_NONE, 0, MM_NONE, INV, MM_NEXT },  /* Lft        +Sft     */
        { MM_TRNX, 0, MM_TRNY, INV, MM_NEXT },  /*     Mid    +Sft     */
        { MM_NONE, 0, MM_NONE, INV, MM_NEXT },  /* Lft+Mid    +Sft     */
        { MM_ROTY, 0, MM_ROTX, INV, MM_NEXT },  /*         Rgt+Sft     */
        { MM_ROTZ, 0, MM_NONE, INV, MM_NEXT },  /* Lft    +Rgt+Sft     */
        { MM_ZOOM, 0, MM_ZOOM, INV, MM_NEXT },  /*     Mid+Rgt+Sft     */
        { MM_NONE, 0, MM_NONE, INV, MM_NEXT },  /* Lft+Mid+Rgt+Sft     */
        { MM_NONE, 0, MM_NONE, INV, MM_PREV },  /*                 Ctl */
        { MM_NONE, 0, MM_NONE, INV, MM_PREV },  /* Lft            +Ctl */
        { MM_TRNX, 0, MM_TRNY, INV, MM_PREV },  /*     Mid        +Ctl */
        { MM_NONE, 0, MM_NONE, INV, MM_PREV },  /* Lft+Mid        +Ctl */
        { MM_ROTY, 0, MM_ROTX, INV, MM_PREV },  /*         Rgt    +Ctl */
        { MM_ROTZ, 0, MM_NONE, INV, MM_PREV },  /* Lft    +Rgt    +Ctl */
        { MM_ZOOM, 0, MM_ZOOM, INV, MM_PREV },  /*     Mid+Rgt    +Ctl */
        { MM_NONE, 0, MM_NONE, INV, MM_PREV },  /* Lft+Mid+Rgt    +Ctl */
        { MM_NONE, 0, MM_NONE, INV, MM_NEXT },  /*             Sft+Ctl */
        { MM_NONE, 0, MM_NONE, INV, MM_NEXT },  /* Lft        +Sft+Ctl */
        { MM_TRNX, 0, MM_TRNY, INV, MM_NEXT },  /*     Mid    +Sft+Ctl */
        { MM_NONE, 0, MM_NONE, INV, MM_NEXT },  /* Lft+Mid    +Sft+Ctl */
        { MM_ROTY, 0, MM_ROTX, INV, MM_NEXT },  /*         Rgt+Sft+Ctl */
        { MM_ROTZ, 0, MM_NONE, INV, MM_NEXT },  /* Lft    +Rgt+Sft+Ctl */
        { MM_ZOOM, 0, MM_ZOOM, INV, MM_NEXT },  /*     Mid+Rgt+Sft+Ctl */
        { MM_NONE, 0, MM_NONE, INV, MM_NEXT },  /* Lft+Mid+Rgt+Sft+Ctl */
    };        



#define HISTSIZE    4096
#define HISTMASK    4095
static char HistBuff[HISTSIZE];
static int MinHist,MaxHist;
static int CurHist;

static char *CurPrompt;
static int CurPos,MaxPos;

static MouseMapping *MouseBinding;
static int PointX,PointY;
static int InitX,InitY;




static void UpdateLine( void )
{
    register int i;

    for( i=CurPos; i<MaxPos; i++ )
        WriteChar(CurLine[i]);
    WriteChar(' ');
    for( i=MaxPos+1; i>CurPos; i-- )
        WriteChar(0x08);
}


static void CopyHistory( void )
{
    register int i;

    for( i=CurPos; i>0; i-- )
        WriteChar(0x08);
    for( i=0; i<MaxPos; i++ )
        WriteChar(' ');
    WriteChar(0x0D);
    WriteString(CurPrompt);

    CurPos = 0;
    if( (i=CurHist) != MaxHist )
        while( HistBuff[i] )
        {   CurLine[CurPos++] = HistBuff[i];
            WriteChar(HistBuff[i]);
            i = (i+1) & HISTMASK;
        }
    CurLine[CurPos] = 0;
    MaxPos = CurPos;
}


int ProcessCharacter( int ch )
{
    register int i;

    if( !ch ) return( False );

    if( IsPaused )
    {   if( (ch==0x04) || (ch==0x1a) || (ch==0x1b) )
        {   InterruptPauseCommand();
        } else ResumePauseCommand();
        return( False );
    }

    if( (ch>=' ') && (ch<='~') )
    {   if( MaxPos<MAXLINELEN )
        {   for( i=MaxPos; i>CurPos; i-- )
                CurLine[i] = CurLine[i-1];
            CurLine[CurPos++] = ch;
            CurLine[++MaxPos] = 0;

            WriteChar(ch);
            if( CurPos<MaxPos )
                UpdateLine();
        } else
            WriteChar(0x07);

    } else
        switch( ch )
        {    case( 0x7f ):  /* DEL and ^H */
             case( 0x08 ):  if( CurPos>0 )
                            {   for( i=CurPos; i<=MaxPos; i++ )
                                    CurLine[i-1] = CurLine[i];
                                CurPos--; MaxPos--;
                                WriteChar(0x08);
                                UpdateLine();
                            }
                            break;

             case( 0x04 ):  if( CurPos<MaxPos ) /* ^D */
                            {   for( i=CurPos; i<MaxPos; i++ )
                                    CurLine[i] = CurLine[i+1];
                                MaxPos--; UpdateLine();
                            }
                            break;

             case( 0x0d ):  /* ^M and ^J */
             case( 0x0a ):  WriteChar('\n');
                            if( MaxPos )
                                for( i=0; i<=MaxPos; i++ )
                                {    HistBuff[MaxHist] = CurLine[i];
                                     MaxHist=(MaxHist+1)&HISTMASK;
                                     if( MaxHist==MinHist )
                                     {   while( HistBuff[MinHist] )
                                             MinHist=(MinHist+1)&HISTMASK;
                                         MinHist=(MinHist+1)&HISTMASK;
                                     }
                                }
                            CommandActive = False;
                            return( True );

             case( 0x02 ):  if( CurPos>0 )  /* ^B */
                            {    WriteChar(0x08);
                                 CurPos--;
                            }
                            break;

             case( 0x06 ):  if( CurPos<MaxPos )  /* ^F */
                                WriteChar(CurLine[CurPos++]);
                            break;

             case( 0x01 ):  while( CurPos>0 )   /* ^A */
                            {    WriteChar(0x08);
                                 CurPos--;
                            }
                            break;

             case( 0x05 ):  while( CurPos<MaxPos )  /* ^E */
                                WriteChar(CurLine[CurPos++]);
                            break;

             case( 0x0c ):  WriteChar('\n');    /* ^L */
                            WriteString(CurPrompt);
                            for( i=0; i<MaxPos; i++ )
                                WriteChar(CurLine[i]);
                            for( i=CurPos; i<MaxPos; i++ )
                                WriteChar(0x08);
                            break;

             case( 0x10 ):  if( CurHist != MinHist ) /* ^P */
                            {   CurHist -= 2;
                                if( CurHist<0 )
                                    CurHist += HISTSIZE;
                                while( HistBuff[CurHist] )
                                    CurHist=CurHist?CurHist-1:HISTMASK;
                                CurHist = (CurHist+1)&HISTMASK;
                                CopyHistory();
                            }
                            break;

             case( 0x0e ):  if( CurHist != MaxHist ) /* ^N */
                            {   while( HistBuff[CurHist] )
                                    CurHist = (CurHist+1)&HISTMASK;
                                CurHist = (CurHist+1)&HISTMASK;
                                CopyHistory();
                            }
                            break;
        }
    return False;
}


void ResetCommandLine( int state )
{
    if( state )
    {   EnableMenus(state==1);
        switch( CurState=state )
        {   case(1):   CurPrompt="RasMol> ";            break;
            case(2):   CurPrompt= MsgStrs[StrPrmtPDB];  break;
            case(3):   CurPrompt= MsgStrs[StrPrmtImg];  break;
            case(4):   CurPrompt= MsgStrs[StrPrmtMol];  break;
        }
    }

    if( CommandActive )
        WriteChar('\n');
    CommandActive = True;
    WriteString(CurPrompt);

    CurHist = MaxHist;
    CurPos = MaxPos = 0;
    CurLine[0] = 0;
    Recycle = (char *)0;
}


void InvalidateCmndLine( void )
{
    if( CommandActive )
        WriteChar('\n');
    CommandActive=False;
}


static void ClampDial( int dial, Real value )
{
    register Real temp;

    /* invert mouse for slabbing and backclipping */
    if(dial==DialSlab || dial==DialBClip ) {
      temp = DialValue[dial] - value;
    } else {
      temp = DialValue[dial] + value;
    }

    if( temp > 1.0 )
    {   temp = 1.0;
    } else if( temp < -1.0 )
    {   temp = -1.0;
    }
    DialValue[dial] = temp;
}


static void WrapDial( int dial, Real value )
{
    register Real temp;

    temp = DialValue[dial] + value;
    while( temp < -1.0 )  temp += 2.0;
    while( temp > 1.0 )   temp -= 2.0;
    DialValue[dial] = temp;
}


void ProcessMouseDown( int x, int y, int stat )
{   
    register MouseMapping *map;
    
    map = &MouseBinding[stat];
    if( map->dxfunc || map->dyfunc )
        SetMouseCaptureStatus(True);
    InitX = PointX = x;
    InitY = PointY = y;
    HeldButton = True;
    if (PickMode == PickAtom ) {
      DrawArea = True;
    }
}


void ProcessMouseUp( int x, int y, int stat )
{                      
    register MouseMapping *map;
    register int area;
    
    area = DrawArea;
    DrawArea = False;
    
    map = &MouseBinding[(stat&31)];
    SetMouseCaptureStatus(False);

    if( !HeldButton )
        return;

    HeldButton = False;
                                  
    if( Database && IsClose(x,InitX) && IsClose(y,InitY) )
    {
    
#ifdef INVERT
      y = YRange - y;
#endif

      switch( map->click )
        {   case(MM_PICK):  if( PickAtoms(False,x,y) )
                            {   AdviseUpdate(AdvPickNumber);
                                AdviseUpdate(AdvPickAtom);
                                AdviseUpdate(AdvPickCoord);
                            }
                            break;
                   
            case(MM_NEXT):  if( PickAtoms(1,x,y) )
                            {   AdviseUpdate(AdvPickNumber);
                                AdviseUpdate(AdvPickAtom);
                                AdviseUpdate(AdvPickCoord);
                            }
                            break;
                            
            case(MM_PREV):  if( PickAtoms(-1,x,y) )
                              {   AdviseUpdate(AdvPickNumber);
                                  AdviseUpdate(AdvPickAtom);
                                  AdviseUpdate(AdvPickCoord);
                              }
                              break;
            }
        } else if( Database && area )
    {   /*SelectArea treats inversion*/
		switch( map->click )
        {   case(MM_PICK):  SelectArea(0,True,InitX,InitY,x,y);
                            break;
                   
            case(MM_NEXT):  SelectArea(1,True,InitX,InitY,x,y);
                            break;
                   
            case(MM_PREV):  SelectArea(-1,True,InitX,InitY,x,y);
                            break;
        }
		ReDrawFlag |= RFRefresh;
    }
}


static int BindingActive( int stat )
{
    return( MouseBinding[stat].dxfunc || MouseBinding[stat].dyfunc );
}


void SetMouseMode( int mode )
{
    register int stat;
    
    switch( mode )
    {   case(MMRasMol):  MouseBinding = MouseRasMol;  MouseMode = MMRasMol;    break;
        case(MMRasOld):  MouseBinding = MouseRasMol;  MouseMode = MMRasOld;    break;
        case(MMInsight): MouseBinding = MouseInsight; MouseMode = MMInsight;   break;
        case(MMQuanta):  MouseBinding = MouseQuanta;  MouseMode = MMQuanta;    break;
        case(MMSybyl):   MouseBinding = MouseSybyl;   MouseMode = MMSybyl;     break;
    }

    /* Should also test for BindingActive(MMSft|MMCtl)! */
    stat = BindingActive(MMSft) || BindingActive(MMCtl);
    SetMouseUpdateStatus(stat);            
}

/*
   PerformMouseFunc
     func:  MM_ROTX -- a change in the Y-direction for the purpose
                       of rotating around the X-axis
            MM_ROTY -- a change in the X-direction for the purpose
                       of rotating aount the Y-axis
 
     The mouse rasmol old interpretation is based on breaking
     the screen into zones, by eigths of the width and height.
     In the outer eighth in each direction, the rotations
     are actualy around the Z-axis.  In the middle 2-eights
     the rotations ar entirely around the X-axis for
     Y displacements, and entirely around the Y-axis for
     X dosplacements.  Between these two zones the two rotation
     modes are mixed
   
 
 
       (0,0)                                        (XRange,0)
         ------------------------------------------------
        |     |     |     |     |     |     |     |     |
        |  Z  |  Z  |  Z  |  Z  |  Z  |  Z  |  Z  |  Z  |
        |     |     |     |     |     |     |     |     |
         ------------------------------------------------
        |     |     |     |     |     |     |     |     |
        |  Z  |     |     |     |     |     |     |  Z  |
        |     |     |     |     |     |     |     |     |
         ------------------------------------------------
        |     |     |     |     |     |     |     |     |
        |  Z  |     |     |     |     |     |     |  Z  |
        |     |     |     |     |     |     |     |     |
         ------------------------------------------------
        |     |     |     |     |     |     |     |     |
        |  Z  |     |     |  XY | XY  |     |     |  Z  |
        |     |     |     |     |     |     |     |     |
         ------------------------------------------------
        |     |     |     |     |     |     |     |     |
        |  Z  |     |     |  XY | XY  |     |     |  Z  |
        |     |     |     |     |     |     |     |     |
         ------------------------------------------------
        |     |     |     |     |     |     |     |     |
        |  Z  |     |     |     |     |     |     |     |
        |     |     |     |     |     |     |     |     |
         ------------------------------------------------
        |     |     |     |     |     |     |     |     |
        |  Z  |     |     |     |     |     |     |     |
        |     |     |     |     |     |     |     |     |
         ------------------------------------------------
        |     |     |     |     |     |     |     |     |
        |  Z  |  Z  |  Z  |  Z  |  Z  |  Z  |  Z  |  Z  |
        |     |     |     |     |     |     |     |     |
         ------------------------------------------------
    (0,YRange)                                         (Xrange,YRange)
 
 This provides a approximation to track-ball behavior, where
 twisting of the trackball creates a Z-rotation.  In this case,
 the appropriate DialValues are incremented by the indicated
 motion, to eventually be used against as base set of Euler
 angles [LastDialValue[DialRX], LastDialValue[DialRY], LastDialValue[DialRZ]]
 
 In the new mode, the screen is treated as a continuous trackball,
 using any changes in [DialVaue[DialRX],DialValue[DialRY]] to infer
 a rotation around an axis at right angles to the displacement.
 The accumulated rotation is held in DialQRot.   The rotation is applied 
 in transfor.c.
 
 */

static void PerformMouseFunc( int func, int delta, int max )
{   Real xcomp, ycomp, zcomp;
    Real dvalue, nvalue;
    int  dist;
    CQRQuaternion lrot,trot;
    CQRQuaternion q3;
    
    switch( func )
    {   case(MM_ROTX):  dvalue = ((Real)(2*delta))/((Real)(max));
            if ( (RotMode == RotBond) && BondSelected) {
                WrapDial( DialBRot, dvalue );
                BondSelected->BRotValue = DialValue[DialBRot];
                ReDrawFlag |= RFRotBond;
            } else if (MouseMode==MMRasOld) {
                dist = PointX-XRange/2;
                if (dist < -XRange/8) {
                    dist += XRange/8;
                    dist *= 2;
                    if (dist < -XRange/2) dist=-XRange/2;
                } else {
                    dist -= XRange/8;
                    if (dist < 0 ) dist = 0;
                    dist *=2;
                    if (dist > XRange/2) dist = XRange/2;
                }
                xcomp = dvalue*(Real)((XRange/2-AbsFun(dist)))/((Real)(XRange/2));
                zcomp = dvalue*(Real)(dist)/((Real)(XRange/2));
                WrapDial( DialRX, xcomp );
                WrapDial( DialRZ, zcomp);
                ReDrawFlag |= RFRotateX|RFRotateZ;
            } else if (MouseMode==MMRasMol) {
                xcomp = ((Real)(2*PointX-XRange))/((Real)(XRange));
                ycomp = ((Real)(2*PointY-YRange))/((Real)(YRange));
                zcomp = xcomp*xcomp+ycomp*ycomp;
                if (zcomp > 1.) {
                    zcomp = 0.;
                } else {
                    zcomp = sqrt(1.-zcomp);
                }
                CQRMSet(q3,0.,zcomp,0,xcomp)
                CQRMNormsq(nvalue,q3);
                if (DialQRot.w==0. && DialQRot.x==0. && DialQRot.y==0 &&DialQRot.z==0) {
                    if (nvalue==0.) {
                        CQRMSet(DialQRot,cos(PI*dvalue/2.),0.,0.,sin(PI*dvalue/2.));
                    } else {
                        nvalue = sqrt(nvalue);
                        CQRMSet(DialQRot,cos(PI*dvalue/2.),
                                sin(PI*dvalue/2.)*q3.x/nvalue,
                                sin(PI*dvalue/2.)*q3.y/nvalue,
                                sin(PI*dvalue/2.)*q3.z/nvalue);
                    }
                } else {
                    if (nvalue==0.) {
                        CQRMSet(lrot,cos(PI*dvalue),0.,0.,sin(PI*dvalue));
                    } else {
                        nvalue = sqrt(nvalue);
                        CQRMSet(lrot,cos(PI*dvalue/2.),
                                sin(PI*dvalue/2.)*q3.x/nvalue,
                                sin(PI*dvalue/2.)*q3.y/nvalue,
                                sin(PI*dvalue/2.)*q3.z/nvalue);
                    }
                    CQRMMultiply(trot,lrot,DialQRot);
                    CQRMCopy(DialQRot,trot);
                }
                ReDrawFlag |= RFRotateX|RFRotateY|RFRotateZ;
            } else {
                WrapDial( DialRX, (Real)(2*delta)/max );
                ReDrawFlag |= RFRotateX;
            }
            break;
            
        case(MM_ROTY):
            dvalue = ((Real)(2*delta))/((Real)(max));
            if ( (RotMode == RotBond) && BondSelected) {
                WrapDial( DialBRot, dvalue );
                BondSelected->BRotValue = DialValue[DialBRot];
                ReDrawFlag |= RFRotBond;
            } else if (MouseMode==MMRasOld) {
                dist = PointY-YRange/2;
                if (dist < -YRange/8) {
                    dist += YRange/8;
                    dist *= 2;
                    if (dist < -YRange/2) dist=-YRange/2;
                } else {
                    dist -= YRange/8;
                    if (dist < 0 ) dist = 0;
                    dist *=2;
                    if (dist > YRange/2) dist = YRange/2;
                }
                ycomp = dvalue*(Real)((YRange/2-AbsFun(dist)))/((Real)(YRange/2));
#ifdef INVERT
                zcomp = dvalue*(Real)(dist)/((Real)(YRange/2));
#else
                zcomp = dvalue*(Real)(-dist)/((Real)(YRange/2));
#endif
                WrapDial( DialRY, ycomp );
                WrapDial( DialRZ, zcomp );
                ReDrawFlag |= RFRotateY|RFRotateZ;
            } else if (MouseMode==MMRasMol) {
                xcomp = ((Real)(2*PointX-XRange))/((Real)(XRange));
                ycomp = ((Real)(2*PointY-YRange))/((Real)(YRange));
                zcomp = xcomp*xcomp+ycomp*ycomp;
                if (zcomp > 1.) {
                    zcomp = 0.;
                } else {
                    zcomp = sqrt(1.-zcomp);
                }
                CQRMSet(q3,0.,0.,zcomp,-ycomp);
                CQRMNormsq(nvalue,q3);
                if (DialQRot.w==0. && DialQRot.x==0. && DialQRot.y==0 &&DialQRot.z==0) {
                    if (nvalue==0.) {
                        CQRMSet(DialQRot,cos(PI*dvalue),0.,0.,sin(PI*dvalue/2.));
                    } else {
                        nvalue = sqrt(nvalue);
                        CQRMSet(DialQRot,cos(PI*dvalue/2.),
                                sin(PI*dvalue/2.)*q3.x/nvalue,
                                sin(PI*dvalue/2.)*q3.y/nvalue,
                                sin(PI*dvalue/2.)*q3.z/nvalue);
                    }
                } else {
                    if (nvalue==0.) {
                        CQRMSet(lrot,cos(PI*dvalue/2.),0.,0.,sin(PI*dvalue/2.));
                    } else {
                        nvalue = sqrt(nvalue);
                        CQRMSet(lrot,cos(PI*dvalue/2.),
                                sin(PI*dvalue/2.)*q3.x/nvalue,
                                sin(PI*dvalue/2.)*q3.y/nvalue,
                                sin(PI*dvalue/2.)*q3.z/nvalue);
                    }
                    CQRMMultiply(trot,lrot,DialQRot);
                    CQRMCopy(DialQRot,trot);
                }
                ReDrawFlag |= RFRotateX|RFRotateY|RFRotateZ;
            }else {
                WrapDial( DialRY, (Real)(2*delta)/max );
                ReDrawFlag |= RFRotateY;
            }
            break;
            
        case(MM_ROTZ):  WrapDial( DialRZ, (Real)(2*delta)/max );
            ReDrawFlag |= RFRotateZ;
            break;
            
        case(MM_ZOOM):  ClampDial( DialZoom, (Real)(2*delta)/max );
            ReDrawFlag |= RFZoom;
            break;
            
        case(MM_TRNX):  ClampDial( DialTX, (Real)delta/max );
            ReDrawFlag |= RFTransX|RFTransZ;
            break;
            
        case(MM_TRNY):  ClampDial( DialTY, (Real)delta/max );
            ReDrawFlag |= RFTransY|RFTransZ;
            break;
            
        case(MM_CLIP):  ClampDial( DialSlab, (Real)delta/max );
            ReDrawFlag |= RFSlab;
            UseSlabPlane = True;
            UseShadow = False;
            break;
            
        case(MM_DEPT):  ClampDial( DialBClip, (Real)delta/max );
            ReDrawFlag |= RFRotate;
            UseDepthPlane = True;
            break;
    }     
}

static void ReDial( double SaveValue[10], CQRQuaternion * SaveQuat )
{
    int index;
    
    if ( !(RotMode == RotMol) ) {
	  if ( (RotMode == RotBond) && BondSelected) {
	    BondSelected->BRotValue = DialValue[DialBRot];
	  } else if ( RotMode == RotAll ) {
	    WorldDialValue[DialRX] = DialValue[DialRX];
	    WorldDialValue[DialRY] = DialValue[DialRY];
	    WorldDialValue[DialRZ] = DialValue[DialRZ];
	    WorldDialValue[DialTX] = DialValue[DialTX];
	    WorldDialValue[DialTY] = DialValue[DialTY];
	    WorldDialValue[DialTZ] = DialValue[DialTZ];
        WorldDialQRot.w = DialQRot.w;
        WorldDialQRot.x = DialQRot.x;
        WorldDialQRot.y = DialQRot.y;
        WorldDialQRot.z = DialQRot.z;

	  }
	  for (index = 0; index < 7; index++) {
	    if (!(index == DialZoom))
	    DialValue[index] = SaveValue[index];
	  }
	  DialQRot.w = SaveQuat->w;
	  DialQRot.x = SaveQuat->x;
	  DialQRot.y = SaveQuat->y;
	  DialQRot.z = SaveQuat->z;
	}
	return;
}


void ProcessMouseMove( int x, int y, int stat )
{   
    register MouseMapping *map;
    register int dx,dy;
    double SaveValue[10];
    CQRQuaternion SaveQuat;
    int index;
    
    SaveQuat.w =  SaveQuat.x =  SaveQuat.y =  SaveQuat.z =  0;


    if (! ( RotMode == RotMol ) ) {
      for (index=0; index<10; index++)
          SaveValue[index] = DialValue[index];
          SaveQuat.w =  DialQRot.w;
          SaveQuat.x =  DialQRot.x;
          SaveQuat.y =  DialQRot.y;
          SaveQuat.z =  DialQRot.z;
      if (( RotMode == RotBond ) && BondSelected)
          DialValue[DialBRot] = BondSelected->BRotValue;
      else if ( RotMode == RotAll ) {
          DialValue[DialRX] = WorldDialValue[DialRX];
          DialValue[DialRY] = WorldDialValue[DialRY];
          DialValue[DialRZ] = WorldDialValue[DialRZ];
	      DialValue[DialTX] = WorldDialValue[DialTX];
	      DialValue[DialTY] = WorldDialValue[DialTY];
	      DialValue[DialTZ] = WorldDialValue[DialTZ];
	      DialQRot.w = WorldDialQRot.w;
	      DialQRot.x = WorldDialQRot.x;
	      DialQRot.y = WorldDialQRot.y;
	      DialQRot.z = WorldDialQRot.z;
      }
    }
    
    map = &MouseBinding[stat];
    if( map->dxfunc || map->dyfunc || DrawArea)
    {   SetMouseCaptureStatus(True);
        if( !HeldButton )
        {   InitX = PointX = x;
            InitY = PointY = y;
            HeldButton = True;
            ReDial( SaveValue, &SaveQuat );
            return;
        }
    
        if( IsClose(x,InitX) && IsClose(y,InitY) ) {
            ReDial( SaveValue, &SaveQuat );
            return;
        }                         
        
        if( map->dxinvrt )
        {      dx = PointX - x;
        } else {
          dx = x - PointX;
        }  
    
        if( map->dyinvrt )
        {      dy = PointY - y;
        } else {
          dy = y - PointY;
        }

        if( !DrawArea )
        {  if( IsClose(x,InitX) && IsClose(y,InitY) ){
             ReDial( SaveValue, &SaveQuat );
             return;
           }                         
    
           if( dx ) PerformMouseFunc(map->dxfunc,dx,XRange);
           if( dy ) PerformMouseFunc(map->dyfunc,dy,YRange);
        } else {  
          if( (x<0&&dx<0)||(y<0&&-dy<0)||(x>XRange&&dx>0)||(y>YRange&&-dy>0) )
          {	
             if( !IsClose(x,InitX) && dx ) PerformMouseFunc(MM_TRNX,-dx,XRange);
             if( !IsClose(y,InitY) && dy ) PerformMouseFunc(MM_TRNY,-dy,YRange);
               InitX -= dx;
#ifdef INVERT	/*desinvert!*/
               InitY += dy;
#else
               InitY -= dy;
#endif		
         }
         
         switch( map->click )
         {   case(MM_PICK):  SelectArea(False,False,InitX,InitY,x,y);
                             break;

             case(MM_NEXT):  SelectArea(1,False,InitX,InitY,x,y);
                             break;
	           
             case(MM_PREV):  SelectArea(-1,False,InitX,InitY,x,y);
                             break;
         }
             ReDrawFlag |= RFRefresh;
       }

    
        if( ReDrawFlag & (RFRotateX|RFRotateY) )
            UpdateScrollBars();
    
        PointX = x;
        PointY = y; 
    } else              
    {   SetMouseCaptureStatus(False);
        HeldButton = False;
    }

    ReDial( SaveValue, &SaveQuat );
    return;
}


void InitialiseCmndLine( void )
{
    MaxHist = MinHist = 1;
    HistBuff[0] = 0;

    CommandActive = False;

    SetMouseMode(MMRasMol);
    HeldButton = False;
}

