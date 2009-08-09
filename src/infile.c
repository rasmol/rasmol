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
/* infile.c
 $Log: infile.c,v $
 Revision 1.14  2008/07/18 01:11:01  yaya
 Report a syntax error on rotate all 3 in command.c
 Change const char * to char * for datablock name in infile.c -- HJB

 Revision 1.13  2008/06/28 22:38:45  yaya
 Update for mmCIF CHEM_COMP ligand support.  Add notes
 to rasmol.doc; cif_datablock_name and cif_rewind_datablock;
 add logic to read CHEM_COMP_ATOM and CHEM_COMP_BOND parses
 to LoadCIFMolecule, putting models in a NMR models. -- HJB

 Revision 1.12  2008/06/28 14:06:37  yaya
 Fix unused variable warning in command.c
 Start changes for loading models in infile.c
 Make handling of IPC errors non-fatal in x11win.c -- HJB

 Revision 1.11  2008/06/19 18:41:57  yaya
 Correct missing ) -- HJB

 Revision 1.9  2008/03/22 18:42:52  yaya
 Post release cleanup and credit to Ikonen in file headers. -- HJB

 Revision 1.8  2008/03/17 03:01:31  yaya
 Update to agree with 2.7.4.2 release and T. Ikonen GTK mods -- HJB

 Revision 1.6  2008/03/17 01:32:41  yaya
 Add gtk mods by tpikonen, and intergate with 2.7.4.2 mods -- HJB

 Revision 1.7  2008/03/16 22:25:21  yaya
 Align comments with production version; Update rasmol_install and
 rasmol_run shell scripts for Japanese and Chinese; Align logic for
 positioning and sizing initial window with windows version -- HJB

 Revision 1.5  2008/01/30 03:15:55  yaya
 More post 2.7.4.1 release cleanup -- HJB

 Revision 1.6  2008/01/29 04:12:10  yaya
 Post release cleanup of problems discovered. -- HJB

 Revision 1.4  2008/01/29 04:35:25  yaya
 Postrelease update to fix problems discovered -- HJB

 Revision 1.3  2008/01/28 03:29:37  yaya
 Update CVS to RasMol_2.7.4.1 -- HJB

 Revision 1.5  2008/01/14 15:49:16  yaya
 More of code for CBF style map save
 More use of stdlib as per Ladislav Michnovic
 --HJB

 Revision 1.4  2007/11/19 03:28:39  yaya
 Update to credits for 2.7.4 in manual and headers
 Mask code added -- HJB

 Revision 1.3  2007/11/06 04:53:52  yaya
 Patches for window builds with CodeWarrior
 Fix error in surface normal calculation -- HJB

 Revision 1.2  2007/10/23 02:27:55  yaya
 Preliminary mods for revised PDB format derived from Rutgers mods.
 Partial changes for map tangles -- HJB

 Revision 1.1.1.1  2007/03/01 01:16:33  todorovg
 Chinese working versio from rasmol_ru initial import

 Revision 1.3  2006/11/01 03:23:50  yaya
 Update NSIS windows installer for more script types and to fix
 misplaced script instructions for data files; add document and
 script icons directly in raswin.exe; add credit line to
 G. A. Pozhvanov in comments for Russian translations. -- HJB

 Revision 1.2  2006/09/17 10:53:55  yaya
 Clean up headers and start on code for X11 -- HJB

 Revision 1.1.1.1  2006/09/16 18:45:46  yaya
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

 Revision 1.1  2001/01/31 02:13:45  yaya
 Initial revision

 Revision 1.4  2000/08/26 18:12:31  yaya
 Updates to header comments in all files

 Revision 1.3  2000/08/09 01:18:01  yaya
 Rough cut with ucb

 Revision 1.2  2000/02/23 00:00:00  yaya
 Prelininary 2.7.2 build

 */

/* Ladislav Michnovic, 10 Jan 08 start */
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
/* Ladislav Michnovic, 10 Jan 08 end */


#include "rasmol.h"
/* Ladislav Michnovic, 10 Jan 08 start */
#include <string.h>
/* Ladislav Michnovic, 10 Jan 08 end */



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

#define INFILE
#include "infile.h"
#include "molecule.h"
#include "abstree.h"
#include "command.h"
#include "cmndline.h"
#include "transfor.h"
#include "langsel.h"
#include "cif.h"
#include "cif_fract.h"
#include "cif_ctonum.h"

#ifndef APPLEMAC
#ifndef IBMPC
#ifndef VMS
#include <sys/types.h>
#endif
#include <sys/time.h>
#endif
#include <time.h>
#endif
 

#ifdef MMIOLIB
#include "mmio.h"
#endif


#define FeatHelix    1
#define FeatSheet    2
#define FeatTurn     3


/* Macros for commonly used loops */
#define ForEachAtom  for(chain=Database->clist;chain;chain=chain->cnext) \
                     for(group=chain->glist;group;group=group->gnext)    \
                     for(aptr=group->alist;aptr;aptr=aptr->anext)
#define ForEachBond  for(bptr=Database->blist;bptr;bptr=bptr->bnext)


typedef struct {
	int init, term;
	char chain;
	char type;
	} FeatEntry;

#define FeatSize    32
typedef struct _Feature {
	struct _Feature __far *fnext;
        FeatEntry data[FeatSize];
        int count;
    } Feature;


typedef struct {
	  char src[4];
	  char dst[4];
	  } ConvTable;

#define MAXALCATOM   5
static ConvTable AlcAtomTable[MAXALCATOM] = {
    { { 'S', 'O', '2', ' ' }, { ' ', 'S', '2', ' ' } },  /*  1 */
    { { 'C', 'A', 'R', ' ' }, { ' ', 'C', ' ', ' ' } },  /*  2 */
    { { 'N', 'A', 'R', ' ' }, { ' ', 'N', ' ', ' ' } },  /*  3 */
    { { 'N', 'A', 'M', ' ' }, { ' ', 'N', ' ', ' ' } },  /*  4 */
    { { 'N', 'P', 'L', '3' }, { ' ', 'N', '3', ' ' } },  /*  5 */
				 };

static char PDBInsert;
static Feature __far *FeatList;
static RAtom __far *ConnectAtom;
static char __far Record[256];
static FILE *DataFile;
static int WPDB;



/*=======================*/
/*  Function Prototypes  */
/*=======================*/

static void UpdateFeature( FeatEntry __far*, int );
int LoadCIFMolecule( FILE* );

#ifdef APPLEMAC
/* External RasMac Function Declaration! */
void SetFileInfo( char*, OSType, OSType, short );
#endif



static void FatalInFileError( char *ptr )
{
    char buffer[80];

    sprintf(buffer,"InFile Error: %s!",ptr);
    RasMolFatalExit(buffer);
}


/*==================================*/
/*  File/String Handling Functions  */
/*==================================*/

int FetchRecord( FILE *fp, char *buffer )
{
    register char *ptr;
    register int ch;

    if (Recycle) {
      strncpy(buffer,Recycle,MAXBUFFLEN-1);
      buffer[MAXBUFFLEN] = 0;
      Recycle = 0;
      return True;
    }

    ptr = buffer;
    do {
        ch = getc(fp);
        if( ch >= ' ' )
	{   *ptr++ = ch; 
        } else if( ch == '\n' )
        {   *ptr = 0;
            return True;
        } else if( ch == '\r' )
        {   ch = getc(fp);
            if( ch != '\n' )
                ungetc(ch,fp);
            *ptr = 0;
            return True;
        } else if( ch == EOF )
        {   *ptr = 0;
            return( ptr != buffer );
        } else *ptr++ = ch;
    } while( ptr < buffer+255 );

    /* skip to the end of the line! */
    do { ch = getc(fp);
    } while( (ch!='\n') && (ch!='\r') && (ch!=EOF) );

    if( ch == '\r' )
    {   ch = getc(fp);
        if( ch != '\n' )
            ungetc(ch,fp);
    }
    *ptr = 0;
    return True;
}


static void ExtractString( int len, char *src, char *dst )
{
    register char *ptr;
    register char ch;
    register int i;

    ptr = dst;
    for( i=0; i<len; i++ )
    {   if( *src )
	{   ch = *src++;
            *dst++ = ch;
            if( ch != ' ' ) 
		ptr = dst;
	} else break;
    }
    *ptr = 0;
}

static void ExtractNBString( int len, char *src, char *dst )
{
    register char *ptr;
    register char xm, ch, och;
    register int i;

    ptr = dst;
    xm = och = ' ';
    for (i=0; (ch=*src++)  && (i < len) 
      && !(ch==';' && (och == '\n' || och=='\r') );) {
      if(!(ch == xm) && !(ch == '\n') && !(ch == '\r') 
         && !(ch == '\t') && !(ch == '\0') 
         && !(ch == och && och == ' ')) {
        *dst++ = och = ch;
        i++;
        if (!(ch == ' ')) {
          ptr = dst;
          xm = '\0';
	}
      } else {
        if (xm == '\0' && (ch == '\n' || ch == '\r')) {
          och = ch;
          *dst++ = ' ';
          i++;
        }
      }
    }
    *ptr = 0;
}



static Long ReadValue( int pos, int len )
{
    register Long result;
    register char *ptr;
    register char ch;
    register int neg;

    result = 0;
    neg = False;
    ptr = Record+pos;
    while( len-- )
    {   ch = *ptr++;
	if( isdigit(ch) )
	{   result = (10*result)+(ch-'0');
	} else if( ch=='-' )
	    neg = True;
    }
    return( neg? -result : result );
}

double ReadDecValue( int pos, int len )
{
    register double result, mul1, mul2;
    register char *ptr;
    register char ch;
    register int neg, postdec;;

    result = 0.;
    mul1 = 10.;
    mul2 = 1.;
    neg = False;
    postdec = False;
    ptr = Record+pos;
    while( len-- )
    {   ch = *ptr++;
      if ( ch == '.' ) {
        mul1 = 1.;
        mul2 = 1.;
        postdec = True;
      } else {
        if (postdec) mul2 *= .1;
	if( (ch>='0') && (ch<='9') )
	{   result = (mul1*result)+((double)(ch-'0'))*mul2;
	} else if( ch=='-' )
	    neg = True;
      }
    }
    return( neg? -result : result );
}



/*===================================*/
/* File Format Independent Functions */
/*===================================*/

static FeatEntry __far *AllocFeature( void )
{
    register Feature __far *ptr;
 
    if( !FeatList || (FeatList->count==FeatSize) )
    {   ptr = (Feature __far*)_fmalloc(sizeof(Feature));
        if( !ptr ) FatalInFileError(MsgStrs[StrMalloc]);
        /* Features are always deallocated! */
 
        ptr->fnext = FeatList;
        ptr->count = 0;
        FeatList = ptr;
    } else ptr = FeatList;
 
    return( &(ptr->data[ptr->count++]) );
}


static void UpdateFeature( FeatEntry __far *ptr, int mask )
{
    register Chain __far *chain;
    register Group __far *group;
 
    for( chain=Database->clist; chain; chain=chain->cnext )
        if( chain->ident == ptr->chain )
        {   group=chain->glist;
            while( group && (group->serno<ptr->init) )
                group = group->gnext;
 
            while( group && (group->serno<=ptr->term) )
            {   group->struc |= mask;
                group = group->gnext;
            }
 
            if( NMRModel )
            {  continue;
            } else return;
        }
}
 
 
static void ProcessFeatures( void )
{
    register Feature __far *next;
    register Feature __far *ptr;
    register int i;
 
    Info.turncount = 0;
    Info.helixcount = 0;
    Info.laddercount = 0;
    Info.structsource = SourcePDB;
 
    for( ptr=FeatList; ptr; ptr=next )
    {    if( Database ) {
             for( i=0; i<ptr->count; i++ )
                 if( ptr->data[i].type==FeatHelix )
                 {   UpdateFeature( &ptr->data[i], HelixFlag );
                     Info.helixcount++;
                 } else if( ptr->data[i].type==FeatSheet )
                 {   UpdateFeature( &ptr->data[i], SheetFlag );
                     Info.laddercount++;
                 } else /* FeatTurn */
                 {   UpdateFeature( &ptr->data[i], TurnFlag );
                     Info.turncount++;
                 }
         }

         /* Deallocate Memory */
         next = ptr->fnext;
         _ffree( ptr );
    }
}
 
static void ApplyConfInfo( char __far *ResName1, char Chain1, int ResNum1, 
                           char Icode1, int sResNum1, char sIcode1,
                           char __far *ResName2, char Chain2, int ResNum2, 
                           char Icode2, int sResNum2, char sIcode2,
                           char __far *CType )
{
    register Chain __far *chn1;
    register Chain __far *chn2;
    register Group __far *group1;
    register Group __far *group2;
    register int   refno1=0, refno2=0;
    register FeatEntry __far *ptr;

   if ( !Database ) return;

   if ( ResName1[0] != '\0' ) refno1 = FindResNo( ResName1 );
   if ( ResName2[0] != '\0' ) refno2 = FindResNo( ResName2 );
   for(chn1=Database->clist;chn1;chn1=chn1->cnext)
   if ( (Chain1 == '\0') ||  (Chain1 == chn1->ident) )
     for(chn2=Database->clist;chn2;chn2=chn2->cnext)
     if ( (Chain2 == '\0' || Chain2 == chn2->ident ) )
       for(group1=chn1->glist;group1;group1=group1->gnext)
       if ( ( ResName1[0] == '\0' || group1->refno == refno1) &&
	 (ResNum1 == -9999 || group1->serno == ResNum1) &&
         (Icode1 == '\0' || Icode1 == group1->insert) &&
	 (sResNum1 == -9999 || group1->sserno == sResNum1) &&
         (sIcode1 == '\0' || sIcode1 == group1->sinsert) )
         for(group2=chn2->glist; group2;group2=group2->gnext)
         if ( (ResName2[0] == '\0' || group2->refno == refno2) &&
   	   (ResNum2==-9999 || group2->serno == ResNum2) &&
           (Icode2 == '\0' || Icode2 == group2->insert) &&
   	   (sResNum2==-9999 || group2->sserno == sResNum2) &&
           (sIcode2 == '\0' || sIcode2 == group2->sinsert) &&
	   (group1->model == group2->model) ) {
           if (CType[0] == 'h' || CType[0] == 'H') {
             ptr = AllocFeature();
             ptr->type = FeatHelix;
           } else {
             if (CType[0] == 't' || CType[0] == 'T') {
               ptr = AllocFeature();
               ptr->type = FeatTurn;
             } else {
               if (CType[0] == 's' || CType[0] == 'S') {
               ptr = AllocFeature();
               ptr->type = FeatSheet;
	       } else {
                 return;
               }
             }             
           }
           ptr->chain = chn1->ident;
           ptr->init = group1->serno;
           ptr->term = group2->serno;       
	 }

}

static void ApplyBondInfo( char __far *ResName1, char Chain1,int ResNum1, 
                           char Icode1, int sResNum1, char sIcode1,
                           char __far *AtomName1, int AtomNum1, 
                           char __far  Altl1, short Model1, char __far *Symm1,
                           char __far *ResName2, char Chain2, int ResNum2, 
                           char Icode2, int sResNum2, char sIcode2,
                           char __far *AtomName2, int AtomNum2, 
                           char __far  Altl2, short Model2, char __far *Symm2,
                           char __far *CType )
{
    register Chain __far *chn1;
    register Chain __far *chn2;
    register Group __far *group1;
    register Group __far *group2;
    register int   refno1=0, refno2=0;
    register RAtom __far *aptr1, __far *aptr2;
    int xbonds = 0;
    char Symmd[6] = "1_555";

   if ( !Database ) return;

   if (AtomNum1 != 0 && AtomNum2 != 0 &&
     !((CType[0] && ((CType[0]=='d' || CType[0]=='D') ||
     (CType[0]=='h' || CType[0]=='H'))))) {
     CreateNewBond (AtomNum1, AtomNum2);
     return;
     }
   if ((AtomNum1 == 0 && AtomName1[0] == 0) ||
       (AtomNum2 == 0 && AtomName2[0] == 0) ) {
     NullBonds++;
     return;
   }
   if (Symm1[0]=='\0') Symm1 = Symmd;
   if (Symm2[0]=='\0') Symm2 = Symmd;
   if (strcmp(Symm1,Symm2) != 0) return;
   if ( ResName1[0] != '\0' ) refno1 = FindResNo( ResName1 );
   if ( ResName2[0] != '\0' ) refno2 = FindResNo( ResName2 );
   for(chn1=Database->clist;chn1;chn1=chn1->cnext)
   if ( (Chain1 == '\0') ||  (Chain1 == chn1->ident) )
     for(chn2=Database->clist;chn2;chn2=chn2->cnext)
     if ( (Chain2 == '\0' || Chain2 == chn2->ident ) )
       for(group1=chn1->glist;group1;group1=group1->gnext)
       if ( ( ResName1[0] == '\0' || group1->refno == refno1) &&
	 (ResNum1 == -9999 || group1->serno == ResNum1) &&
         (Icode1 == '\0' || Icode1 == group1->insert) &&
	 (sResNum1 == -9999 || group1->sserno == sResNum1) &&
         (sIcode1 == '\0' || sIcode1 == group1->sinsert) &&
         (Model1 == 0 || Model1 == group1->model) )
         for(group2=chn2->glist; group2;group2=group2->gnext)
         if ( (ResName2[0] == '\0' || group2->refno == refno2) &&
   	   (ResNum2==-9999 || group2->serno == ResNum2) &&
           (Icode2 == '\0' || Icode2 == group2->insert) &&
   	   (sResNum2==-9999 || group2->sserno == sResNum2) &&
           (sIcode2 == '\0' || sIcode2 == group2->sinsert) &&
           (Model2 == 0 || Model2 == group2->model) )
           for(aptr1=group1->alist; aptr1; aptr1=aptr1->anext)
           if ( ((AtomName1[0] == '\0') || (strncmp(AtomName1, 
             ElemDesc[(aptr1->refno)],12)==0)) && 
             ((Altl1 == '\0' && aptr1->altl == ' ')
             || Altl1 == aptr1->altl) &&
	     (AtomNum1 == 0 || AtomNum1 == aptr1->serno)) {
             for(aptr2=group2->alist; aptr2; aptr2=aptr2->anext)
               if ( ((AtomName2[0] == '\0') || (strncmp(AtomName2, 
                 ElemDesc[(aptr2->refno)],12)==0)) && 
                 ((Altl2 == '\0'&&aptr2->altl == ' ') 
                 || Altl2 == aptr2->altl) &&
		 (AtomNum2 == 0 || AtomNum2 == aptr2->serno)) {
                   if (CType && (CType[0] == 'h' || CType[0] == 'H')) {
                     xbonds++;
                     if ( aptr1->serno < aptr2->serno )
                       CreateBond (aptr1->serno, aptr2->serno, HydrBondFlag);
                   } else {
                     if ((CType && (CType[0] == 'd' || CType[0] == 'D')) ||
                       ((IsCysteine(group1->refno)) && 
                       (aptr1==FindCysSulphur(group1)) && 
                       (IsCysteine(group2->refno)) &&
		       (aptr2==FindCysSulphur(group2)))) {
                       xbonds++;
                       TestDisulphideBridge(group1, group2, aptr1);
		     } else {
                       xbonds++;
                       CreateNewBond (aptr1->serno, aptr2->serno);
                     }
                   }
                 if (AtomNum2) break;
	       }
               if (AtomNum1) break;
	    }
    if (!xbonds) NullBonds++;
    return;
}




/*==============================*/
/* Molecule File Format Parsing */
/*==============================*/

static Long ReadPDBCoord( int offset )
{
    register int len,neg,decpos;
    register Long result;
    register char *ptr;
    register char ch;
 
    result = 0;
    neg = False;
	decpos = -1;
    len = 8;
	if (WPDB) len = 13;
 
    ptr = Record+offset;
    while( len-- )
    {   ch = *ptr++;
        if( (ch>='0') && (ch<='9') )
        {   result = (10*result)+(ch-'0');
        } else if( ch=='-' )
		  {
            neg = True;
		  } else if (ch=='.')
		    {
			  decpos = len;
		    } else if (ch==' ')
			  {
	             result *= 10;
			  }
    }
	if (decpos == -1) {
	  if (WPDB) result /= 100;
	} else {
	  decpos -= 3;
	  while (decpos > 0) {
        result /= 10;
		decpos--;
	  }
	}
    return( neg? -result : result );
}


static void ProcessPDBGroup( int heta, int serno )
{
    PDBInsert = Record[WPDB?64:26];
    if( !CurChain || (CurChain->ident!=Record[WPDB?54:21]) )
    {   ConnectAtom = (RAtom __far*)0;
        CreateChain( Record[WPDB?54:21] );
    }
    CreateGroup( GroupPool );
 
    CurGroup->refno = FindResNo( Record+(WPDB?42:17) );
    CurGroup->serno = serno;
    ProcessGroup( heta );
}
 


static void ProcessPDBAtom( int heta, double pdb_version )
{
    register Bond __far *bptr;
    register RAtom __far *ptr;
    register Long dx,dy,dz;
    register int temp,serno;
 
    if (WPDB) {
      dx = ReadPDBCoord(65);
	  dy = ReadPDBCoord(78);
      dz = ReadPDBCoord(91);
	} else {
    dx = ReadPDBCoord(30);
    dy = ReadPDBCoord(38);
    dz = ReadPDBCoord(46);
	}
 
    /* Process Pseudo Atoms Limits!! */

    if( (WPDB && (Record[23]=='Q') && (Record[22]==' ')) ||
	    ( (!WPDB) && (Record[13]=='Q') && (Record[12]==' ') ))
    {   if (WPDB) {
	      temp = (int)ReadValue(110,6);
		} else {
	      temp = (int)ReadValue(60,6);
		}
        if( MMinMaxFlag )
        {   if( temp < MinMainTemp )
            {   MinMainTemp = temp;
            } else if( temp > MaxMainTemp )
                MaxMainTemp = temp;
        }
 
        /* Dummy co-ordinates! */
        if( (dx==dy) && (dx==dz) )
        {   if( !dx || (dx == 9999000L) )
                return;
        }
 
        if( HMinMaxFlag || MMinMaxFlag )
        {   if( dx < MinX )
            {   MinX = dx;
            } else if( dx > MaxX )
                MaxX = dx;
 
            if( dy < MinY )
            {   MinY = dy;
            } else if( dy > MaxY )
                MaxY = dy;
 
            if( dz < MinZ )
            {   MinZ = dz;
            } else if( dz > MaxZ )
                MaxZ = dz;
        }
        return;
    }
 
 
    /* Ignore XPLOR Pseudo Atoms!! */
    if( (dx==9999000L) && (dy==9999000L) && (dz==9999000L) )
        return;
 
    if (WPDB) {
    serno = (int)ReadValue(55,9);
    if( !CurGroup || (CurGroup->serno!=serno)
        || (CurChain->ident!=Record[54])
        || (PDBInsert!=Record[64]) )
        ProcessPDBGroup( heta, serno );
	} else {
    serno = (int)ReadValue(22,4);
    if( !CurGroup || (CurGroup->serno!=serno)
        || (CurChain->ident!=Record[21])
        || (PDBInsert!=Record[26]) )
        ProcessPDBGroup( heta, serno );
	}
 
    /* Handle Strange PDB Files */
	if (!WPDB) {
    if( (Record[12]==' ') && (Record[13]==' ') )
    {   /* Right Justified Atom Name! */
        if( Record[14] == ' ' )
        {   Record[13] = Record[15];
            Record[15] = ' ';
        } else
        {   Record[13] = Record[14];
            Record[14] = Record[15];
            Record[15] = ' ';
        }
    }
	}
 
    ptr = CreateAtom();
    ptr->refno = ComplexAtomType(Record+(WPDB?22:12));
    ptr->serno = ReadValue(WPDB?8:6,WPDB?9:5);
    ptr->temp = (int)ReadValue(WPDB?110:60,6);
    ptr->altl = Record[WPDB?32:16];
    ptr->model = NMRModel;
 
    /* Handle CONCORD PDB Files */
	if (!WPDB) {
    if( (Record[12]==' ') && islower(Record[14])
        && !strncmp(Record+15,"       ",7) ) 
        ptr->refno = SimpleAtomType(Record+13);
	}

    ptr->xorg =  dx/4;
    ptr->yorg =  dy/4;
    ptr->zorg = -dz/4;
    ptr->xtrl =  (short) (10*(dx-4*ptr->xorg));
    ptr->ytrl =  (short) (10*(dy-4*ptr->yorg));
    ptr->ztrl =  (short) (10*(-dz-4*ptr->zorg));
 
    if( heta ) ptr->flag |= HeteroFlag;
    if (pdb_version < 3.)
      ProcessAtomType( ptr, "  ");
    else 
      ProcessAtomType( ptr, Record+(WPDB?128:76));
 
    /* Create biopolymer Backbone */
    if( IsAlphaCarbon(ptr->refno) && IsProtein(CurGroup->refno) )
    {   if( ConnectAtom )
        {   dx = ConnectAtom->xorg - ptr->xorg;
            dy = ConnectAtom->yorg - ptr->yorg;
            dz = ConnectAtom->zorg - ptr->zorg;
 
            /* Break backbone if CA-CA > 4.20A */
            if( dx*dx+dy*dy+dz*dz < (Long)1050*1050 )
            {   bptr = ProcessBond(ptr,ConnectAtom,NormBondFlag);
                bptr->bnext = CurChain->blist;
                CurChain->blist = bptr;
            } else ptr->flag |= BreakFlag;
        }
        ConnectAtom = ptr;
    } else if( IsSugarPhosphate(ptr->refno) && IsNucleo(CurGroup->refno) )
    {   if( ConnectAtom )
        {   bptr = ProcessBond(ConnectAtom,ptr,NormBondFlag);
            bptr->bnext = CurChain->blist;
            CurChain->blist = bptr;
        }
        ConnectAtom = ptr;
    }
}
 

static void ProcessPDBBond( void )
{
    register Long srcatm;
    register Long dstatm;
    register int i;
    register size_t len;

    len = strlen(Record);
    if( len < (size_t)16 ) return;
    srcatm = (Long)ReadValue(WPDB?22:6,WPDB?9:5);
    if( !srcatm ) return;

    for( i=(WPDB?32:11); i<=(WPDB?62:26) && Record[i]; i+=(WPDB?10:5) )
    { if( len < (size_t)(i+(WPDB?9:5)) ) return;
      dstatm = (Long)ReadValue(i,WPDB?9:5);
      if( dstatm )
      CreateNewBond(srcatm,dstatm);
    }

    for( i=(WPDB?72:31); i<=(WPDB?122:56) && Record[i]; i+=(WPDB?10:5) )
    { if( len < (size_t)(i+(WPDB?9:5)) ) return;
      dstatm = (int)ReadValue(i,WPDB?9:5);
      if( i < (WPDB?92:41) || (i > (WPDB?101:45) && i < (WPDB?122:56))) {
        if( dstatm && srcatm < dstatm )
          CreateBond(srcatm,dstatm,HydrBondFlag);
      } else {
        if( dstatm )
          CreateNewBond(srcatm,dstatm);
      }
    }
    return;
}


static void ProcessPDBColourMask( void )
{
    register MaskDesc *ptr;
    register char *mask;
    register int i;
 
    if( MaskCount == MAXMASK )
        FatalInFileError("Too many COLOR records in file");
    ptr = &UserMask[MaskCount];
    mask = ptr->mask;
 
 
    ptr->flags = 0;
    for( i=6; i<11; i++ )
        if( (*mask++ = Record[i]) != '#' )
            ptr->flags |= SerNoFlag;
 
    for( i=12; i<20; i++ )
        *mask++ = Record[i];
    *mask++ = Record[21];
 
    for( i=22; i<26; i++ )
        if( (*mask++ = Record[i]) != '#' )
            ptr->flags |= ResNoFlag;
    *mask++ = Record[26];
 
    ptr->r = (int)(ReadPDBCoord(30)>>2) + 5;
    ptr->g = (int)(ReadPDBCoord(38)>>2) + 5;
    ptr->b = (int)(ReadPDBCoord(46)>>2) + 5;
    ptr->radius = (short)(5*ReadValue(54,6))>>1;
    MaskCount++;
}
 

static void ProcessPDBUnitCell( void )
{
    int i, j, result_cell;
    register char *src;
    register char *dst;

    dst = Info.spacegroup;  src=Record+(WPDB?94:55);
    while( *src && src<Record+(WPDB?107:66) )
    if( *src!=' ' ) 
    {   *dst++ = *src++;
    } else src++;
    *dst = 0;
 
    Info.cella = Info.cell[0] = ReadDecValue(WPDB?22:6,WPDB?13:9);
    Info.cellb = Info.cell[1] = ReadDecValue(WPDB?22:15,WPDB?13:9);
    Info.cellc = Info.cell[2] = ReadDecValue(WPDB?50:24,WPDB?13:9);

    Info.cellalpha = Deg2Rad*(Info.cell[3] = ReadDecValue(WPDB?64:33,WPDB?9:7));
    Info.cellbeta  = Deg2Rad*(Info.cell[4] = ReadDecValue(WPDB?74:40,WPDB?9:7));
    Info.cellgamma = Deg2Rad*(Info.cell[5] = ReadDecValue(WPDB?84:47,WPDB?9:7));

    result_cell = cell2mat(Info.cell, Info.matf2o, Info.mato2f);
    if( !result_cell )
      result_cell |= invxfrm(Info.mato2f,Info.veco2f,Info.matf2o,Info.vecf2o);
    if (result_cell) { 
      WriteString("Error: Invalid CRYST1\n\n");
      for ( i=0; i<3; i++ ) {
        Info.vecf2o[i] =  Info.veco2f[i] =  Info.cell[i] = 0.;
        Info.cell[i+3] = 90.;
        for ( j=0; j<3; j++) { 
          Info.matf2o[i][j] = Info.mato2f[i][j] = ((i!=j)?0.:1.);
        }
      }
    }

    return;
}

int LoadPDBMolecule( FILE *fp,  int flag )
{
    register FeatEntry __far *ptr;
    register int ignore, notCIF;
    double pdb_version;
 
    if (UseCIF)  return (LoadCIFMolecule (fp));
      

    ignore = False;
    notCIF = False;
	WPDB = False;
    FeatList = (void __far*)0;
    DataFile = fp;
    NMRModel = 0;
    pdb_version = 0.;
 
    while( FetchRecord(DataFile,Record) )
      { if(!notCIF) {
          register int ich;
          ich = 0;
          while (Record[ich] && (Record[ich]!='#') )
	  {  if( isspace(Record[ich] ) )
	     {  ich++;
                continue;
             }
             if (!strncasecmp("data_",&Record[ich],5)) {
               Recycle = &Record[0];
               return (LoadCIFMolecule (fp));
             } else {
               notCIF = True;
               break;
             }
	   }          
        }
        if( *Record == 'A' )
        {   if( !ignore && !strncmp("ATOM",Record,4) ) {
                ProcessPDBAtom( False, pdb_version );
            }

        } else switch(*Record)
        {   case('C'):    if( !strncmp("CONE",Record,4) )
                          {   if( ignore || flag ) continue;
                              ProcessPDBBond();
                                                                 
                          } else if( !strncmp("COMP",Record,4) )
                          {   /* First or MOLECULE: COMPND record */
                              if( (Record[WPDB?21:9]==' ') && 
                                  strncmp(Record+(WPDB?22:10),"MOL_ID:",7) )  
                              {   ExtractString(60,Record+(WPDB?22:10),
                                                Info.moleculename);
                              } else if( !Info.moleculename[0] &&
                                         !strncmp(Record+(WPDB?22:11),"MOLECULE: ",10) )
                                  ExtractString(49,Record+(WPDB?32:21),
                                                Info.moleculename);
                          } else if( !strncmp("CRYS",Record,4) )
                          {   ProcessPDBUnitCell();
                          } else if( !strncmp("COLO",Record,4) )
                              ProcessPDBColourMask();
                          break;

            case('E'):    if( !strncmp("ENDM",Record,4) )
                          {   /* break after single model??? */
                              NMRModel = 0;
                              if( flag )
                              {   ConnectAtom = (void __far*)0;
                                  CurGroup = (void __far*)0;
                                  CurChain = (void __far*)0;
                              } else ignore = True;
 
                          } else if( !strncmp("END",Record,3) )
                          {
                              if( !Record[3] || (Record[3]==' ') )
                              {   /* Treat END same as TER! */
                                  ConnectAtom = (void __far*)0;
                                  CurGroup = (void __far*)0;
                                  CurChain = (void __far*)0;
                              }
                          } else if( !strncmp("EXPD",Record,4) )
                              ExtractString(60,Record+10,
                                                Info.technique);
                          break;

            case('H'):    if( !strncmp("HETA",Record,4) )
                          {   if( !ignore ) {
                                ProcessPDBAtom( True, pdb_version );
                              }
                          } else if( !strncmp("HELI",Record,4) )
                          {   if( ignore ) continue;
 
                              /* Remaining HELIX record fields   */
                              /* 38-39 .... Helix Classification */
                              /* 31 ....... Same Chain as 19?    */
                              ptr = AllocFeature();
                              ptr->type = FeatHelix;
                              ptr->chain = Record[19];
                              ptr->init = (int)ReadValue(21,4);
                              ptr->term = (int)ReadValue(33,4);
                              
                          } else if( !strncmp("HEAD",Record,4) )
                          {   ExtractString(40,Record+10,
                                Info.classification);
                              ExtractString(10,Record+62,Info.identcode);
                              ExtractString(11,Record+50,Info.date);
                          }
                          break;

			case('L'):    if( !strncmp("LEAD",Record,4) )
                          {   ExtractString(60,Record+22,
                                Info.classification);
                              ExtractString(15,Record+95,Info.identcode);
                              ExtractString(11,Record+83,Info.date);
							  WPDB = True;
                          }
                          break;

            case('M'):    if( !strncmp("MODE",Record,4) ) {
			                  if(WPDB) {
							    NMRModel = (int)ReadValue(8,9);
							  } else {
                              NMRModel = (int)ReadValue(10,5);
							  }
                              flag = True;
						  }
                          break;

        	case('R'):    if( !strncmp(Record, "REMARK   4", 10) 
        	                && strcasestr(Record,"FORMAT V.")){
        	                char * fmt;
        	                fmt = strcasestr(Record, "FORMAT V.");
        	                fmt += 9;
                            sscanf(fmt, "%lf", &pdb_version);
        	              }
 
            case('S'):    if( !strncmp("SHEE",Record,4) )
                          {   if( ignore ) break;
						      if (WPDB && (Record[6]!='S')) break;
                              /* Remaining SHEET record fields   */
                              /* 38-39 .... Strand Parallelism   */
                              /* 32 ....... Same Chain as 21?    */
                              ptr = AllocFeature();
                              ptr->type = FeatSheet;
                              ptr->chain = Record[WPDB?52:21];
                              ptr->init = (int)ReadValue(WPDB?53:22,WPDB?9:4);
                              ptr->term = (int)ReadValue(WPDB?84:33,WPDB?9:4);
                          } else if (!strncmp("SCAL",Record,4) )
			  { 
                            int rownum;

                            rownum = (int)ReadValue(5,1);
                            if ((rownum > 0) && (rownum < 4) ) {
                              Info.mato2f[rownum-1][0] =  ReadDecValue(WPDB?22:10,WPDB?13:10);
                              Info.mato2f[rownum-1][1] =  ReadDecValue(WPDB?36:20,WPDB?13:10);
                              Info.mato2f[rownum-1][2] =  ReadDecValue(WPDB?50:30,WPDB?13:10);
                              Info.veco2f[rownum-1] =  ReadDecValue(WPDB?64:45,WPDB?13:10);
                            if (rownum == 3) {
                                if (invxfrm(Info.mato2f,Info.veco2f,
                                  Info.matf2o,Info.vecf2o) ) {
                                  int i, j;

                                  WriteString
                                    ("Error: Invalid SCALE ignored\n");
                                  for ( i=0; i<3; i++ ) {
                                    Info.vecf2o[i] = 
                                      Info.veco2f[i] = 0.;
                                    for ( j=0; j<3; j++) {
                                      Info.matf2o[i][j] = 
                                        Info.mato2f[i][j] = ((i!=j)?0.:1.);
                                    }
                                  }
                                }
			      }
                            }
                          }
                          break;

            case('T'):    if( !strncmp("TURN",Record,4) )
                          {   if( ignore ) continue;
 
                              ptr = AllocFeature();
                              ptr->type = FeatTurn;
                              ptr->chain = Record[WPDB?52:19];
                              ptr->init = (int)ReadValue(WPDB?53:20,WPDB?9:4);
                              ptr->term = (int)ReadValue(WPDB?84:31,WPDB?9:4);
                          } else if( !strncmp("TER",Record,3) )
                          {   if( !Record[3] || (Record[3]==' ') )
                              {   ConnectAtom = (void __far*)0;
                                  CurGroup = (void __far*)0;
                                  CurChain = (void __far*)0;
                              }
                          }
                          break;
        }
    }
 
    if( Database )
        strcpy(Info.filename,DataFileName);
    if( FeatList ) ProcessFeatures();
    DataFileFormat = FormatPDB;
    return True;
}


int LoadMDLMolecule( FILE *fp )
{
    register Bond __far *bptr;
    register RAtom __far *src;
    register RAtom __far *dst;
    register RAtom __far *ptr;
 
    register int i,type;
    register int atoms, bonds;
    register int srcatm,dstatm;
    register Long dx, dy, dz;
    register Card dist2;
    register Real scale=0.0;
    register char *cptr;
 
    DataFile = fp;
 
    FetchRecord(DataFile,Record); /* Molecule Name */
    ExtractString(78,Record,Info.moleculename);
 
    FetchRecord(DataFile,Record); /* Program Details */
    FetchRecord(DataFile,Record); /* Comments */
 
    FetchRecord(DataFile,Record);
    atoms = (int)ReadValue(0,3);
    bonds = (int)ReadValue(3,3);
 
    if( !atoms )
        return False;
 
    CreateMolGroup();
    for( i=1; i<=atoms; i++ )
    {   FetchRecord(DataFile,Record);
        ptr = CreateAtom();
 
        cptr = Record+31;
        while( *cptr == ' ' ) cptr++;
        ptr->refno = SimpleAtomType(cptr);
 
        switch( (int)ReadValue(36,3) )
        {   case(1):  ptr->temp =  300;  break;
            case(2):  ptr->temp =  200;  break;
            case(3):  ptr->temp =  100;  break;
            case(5):  ptr->temp = -100;  break;
            case(6):  ptr->temp = -200;  break;
            case(7):  ptr->temp = -300;  break;
            default:  ptr->temp = 0;
        }
        ptr->serno = i;
        
        dx = ReadValue( 0,10);
        dy = ReadValue(10,10);
        dz = ReadValue(20,10);
        ptr->xorg =  dx/40;
        ptr->yorg =  dy/40;
        ptr->zorg = -dz/40;
        ptr->xtrl  = (short)(dx-40*ptr->xorg);
        ptr->ytrl  = (short)(dy-40*ptr->yorg);
        ptr->ztrl  = (short)(-dz-40*ptr->zorg);
        ProcessAtom( ptr );
    }
 
    for( i=0; i<bonds; i++ )
    {   FetchRecord(DataFile,Record);
        srcatm = (int)ReadValue(0,3);
        dstatm = (int)ReadValue(3,3);
        type =   (int)ReadValue(6,3);
 
        if( type==2 )                 /* DOUBLE */
        {   CreateBond(srcatm,dstatm,DoubBondFlag);
        } else if( type==3 )          /* TRIPLE */
        {   CreateBond(srcatm,dstatm,TripBondFlag);
        } else if( type==4 )          /* AROMATIC */
        {   CreateBond(srcatm,dstatm,AromBondFlag);
        } else                        /* SINGLE */
            CreateBond(srcatm,dstatm,NormBondFlag);
    }
 
    for( bptr=Database->blist; bptr; bptr=bptr->bnext )
        if( bptr->flag & NormBondFlag )
        {   src = bptr->srcatom;
            dst = bptr->dstatom;
            if( (src->refno==2) && (dst->refno==2) )
            {   dx = dst->xorg - src->xorg;
                dy = dst->yorg - src->yorg;
                dz = dst->zorg - src->zorg;
                if( dx || dy || dz )
                {   dist2 = dx*dx + dy*dy + dz*dz;
                    scale = 385.0/sqrt(dist2);
                    break;
                }
            }
        }
 
    if( bptr )
    {   for( ptr=CurGroup->alist; ptr; ptr=ptr->anext )
        {   ptr->xorg = (Long)(ptr->xorg*scale);
            ptr->yorg = (Long)(ptr->yorg*scale);
            ptr->zorg = (Long)(ptr->zorg*scale);
            ptr->xtrl = (short)(ptr->xtrl*scale);
            ptr->ytrl = (short)(ptr->ytrl*scale);
            ptr->ztrl = (short)(ptr->ztrl*scale);
        }
        MinX = (Long)(MinX*scale);  MaxX = (Long)(MaxX*scale);
        MinY = (Long)(MinY*scale);  MaxY = (Long)(MaxY*scale);
        MinZ = (Long)(MinZ*scale);  MaxZ = (Long)(MaxZ*scale);
    }
    return True;
}
 

int LoadXYZMolecule( FILE *fp )
{
    auto char type[12];
    auto double xpos, ypos, zpos;
    auto double charge, u, v, w;
    auto long atoms;
 
    register RAtom __far *ptr;
    register char *src,*dst;
    register int count;
    register Long i;
 
 
    DataFile = fp;
    /* Number of Atoms */
    FetchRecord(DataFile,Record);
    sscanf(Record,"%ld",&atoms);
 
    /* Molecule (step) Description */
    FetchRecord(DataFile,Record);
    src = Record;
    while( *src == ' ' )
        src++;
 
    dst = Info.moleculename;
    for( i=0; i<78; i++ )
        if( *src ) *dst++ = *src++;
    *dst = '\0';
 
    if( atoms )
    {   CreateMolGroup();
        for( i=0; i<atoms; i++ )
        {   do {
            if( !FetchRecord(DataFile,Record) )
                return False;
                xpos = ypos = zpos = 0.0;
                count = sscanf(Record,"%s %lf %lf %lf %lf %lf %lf %lf",
                       type, &xpos, &ypos, &zpos, &charge, &u, &v, &w );
                if( (count<1) || ((count==1) && !type[0]) ) 
                    CreateNextMolGroup();
            } while( count < 4 );

            ptr = CreateAtom();
            ptr->serno = i;
 
            ptr->refno = SimpleAtomType(type);
            ptr->xorg =  (Long)(250.0*xpos);
            ptr->yorg =  (Long)(250.0*ypos);
            ptr->zorg = -(Long)(250.0*zpos);
            ptr->xtrl = (short)(10000.0*xpos-40.*(double)ptr->xorg);
            ptr->ytrl = (short)(10000.0*ypos-40.*(double)ptr->yorg);
            ptr->ztrl = (short)(-10000.0*zpos-40.*(double)ptr->zorg);
 
            if( (count==5) || (count==8) )
            {   ptr->temp = (short)(100.0*charge);
            } else ptr->temp = 0;
            ProcessAtom( ptr );
        }
    }
    return True;
}
 

static int FindSybylRefNo( char *ptr )
{
    register char *src,*dst;
    auto char name[5];
 
    src = ptr;
    dst = name;
    if( ptr[1] && (ptr[1]!='.') )
    {   *dst++ = ToUpper(*src);  src++;
        *dst++ = ToUpper(*src);  src++;
    } else
    {   *dst++ = ' ';
        *dst++ = ToUpper(*src);
        src++;
    }
 
    if( *src )
    {   src++;
 
        if( *src == 'a' )
        {   *dst++ = ' ';
            *dst = ' ';
        } else if( *src == 'p' )
        {   *dst++ = '3';
            *dst = ' ';
        } else
        {   *dst++ = *src++;
            if( *src && (*src!='+') )
            {   *dst = *src;
            } else *dst = ' ';
        }
    } else
    {   *dst++ = ' ';
        *dst = ' ';
    }
    name[4]  = '\0';
    return NewAtomType(name);
}
 
 
int LoadMol2Molecule( FILE *fp )
{
    double xpos, ypos, zpos;
    long features, sets, serno;
    long atoms, bonds, structs;
    Long srcatm, dstatm;
 
    char name[20];
    char type[8];
 
    register RAtom __far *ptr;
    register char *src;
    register Long i;
 
    DataFile = fp;
    while( FetchRecord(DataFile,Record) )
    {   if( !*Record || *Record=='#' )
            continue;
 
        if( !strncmp("@<TRIPOS>MOLECULE",Record,17) ||
            !strncmp("@MOLECULE",Record,9) )
        {   FetchRecord(DataFile,Record);  /* Molecule Name */
            src = Record;
            while( *src==' ' ) src++;
            strcpy(Info.moleculename,src);
 
            FetchRecord(DataFile,Record);
            atoms = bonds = structs = features = sets = 0;
            sscanf(Record,"%ld %ld %ld %ld %ld", &atoms, &bonds, 
                          &structs, &features, &sets );
 
            FetchRecord(DataFile,Record);  /* Molecule Type  */
            FetchRecord(DataFile,Record);  /* Charge Type    */
 
        } else if( !strncmp("@<TRIPOS>ATOM",Record,13) ||
                   !strncmp("@ATOM",Record,5) )
        {   if( !atoms ) continue;
 
            CreateMolGroup();
            for( i=0; i<atoms; i++ )
            {    FetchRecord(DataFile,Record);
                 sscanf(Record,"%ld %s %lf %lf %lf %s", &serno, name,
                                &xpos, &ypos, &zpos, type );
 
                 ptr = CreateAtom(); 
                 ptr->refno = FindSybylRefNo( type );
                 ptr->serno = (Long)serno;
                 /* ptr->serno = i; */
 
                 ptr->xorg =  (Long)(250.0*xpos);
                 ptr->yorg =  (Long)(250.0*ypos);
                 ptr->zorg = -(Long)(250.0*zpos);
                 ptr->xtrl = (short)(10000.0*xpos-40.*(double)ptr->xorg);
                 ptr->ytrl = (short)(10000.0*ypos-40.*(double)ptr->yorg);
                 ptr->ztrl = (short)(-10000.0*zpos-40.*(double)ptr->zorg);
                 ProcessAtom( ptr );
            }
 
        } else if( !strncmp("@<TRIPOS>BOND",Record,13) ||
                   !strncmp("@BOND",Record,5) )
            for( i=0; i<bonds; i++ )
            {   FetchRecord(DataFile,Record);
                sscanf(Record,"%ld %ld %ld %s",
                              &serno,&srcatm,&dstatm,type);
                if( !strncmp(type,"ar",2) )
                {   CreateBond(srcatm,dstatm,AromBondFlag);
                } else if( *type == '2' )
                {   CreateBond(srcatm,dstatm,DoubBondFlag);
                } else /* *type == '1' */
                    CreateBond(srcatm,dstatm,NormBondFlag);
            }
    }
    return True;
}


static int FindAlchemyRefNo( void )
{
    register char *ptr;
    register int i;
    char name[5];
 
    ptr = Record+6;
    name[4] = '\0';
    if( !isalpha(ptr[1]) )
    {   name[0] = ' ';
        for( i=0; i<3; i++ )
            name[i+1] = ToUpper(ptr[i]);
        ptr = name;
    } else
    {   for( i=0; i<4; i++ )
            ptr[i] = ToUpper(ptr[i]);
 
        for( i=0; i<MAXALCATOM; i++ )
            if( !strncmp(AlcAtomTable[i].src,ptr,4) )
            {   ptr = AlcAtomTable[i].dst;
                break;
            }
    }
    return NewAtomType(ptr);
}
 

int LoadAlchemyMolecule( FILE *fp )
{
    auto Long serno,srcatm,dstatm;
    register RAtom __far *ptr;
    register Long atoms, bonds;
    register char *chptr;
    register Long i;
    register Long dx, dy, dz;
 
    DataFile = fp;
    FetchRecord(DataFile,Record);
    atoms = ReadValue(0,5);
    bonds = ReadValue(13,5);
    ExtractString(38,Record+41,Info.moleculename);
 
    if( !atoms )
        return False;
 
    CreateMolGroup();
    for( i=0; i<atoms; i++ )
    {   FetchRecord(DataFile,Record);
        ptr = CreateAtom();
 
        ptr->refno = FindAlchemyRefNo();
        ptr->temp = (int)ReadValue(40,8);
        ptr->serno = (int)ReadValue(0,5);
        /* ptr->serno = i+1; */
 
        dx = ReadValue(12,7);
        dy = ReadValue(21,7);
        dz = -ReadValue(30,7);
        ptr->xorg =  dx/4;
        ptr->yorg =  dy/4;
        ptr->zorg = -dz/4;
        ptr->xtrl =  (short)(10*(dx-4*ptr->xorg));
        ptr->ytrl =  (short)(10*(dy-4*ptr->yorg));
        ptr->ztrl =  (short)(10*(-dz-4*ptr->zorg));

        ProcessAtom( ptr );
    }
 
    for( i=0; i<bonds; i++ )
    {   FetchRecord(DataFile,Record);
        sscanf(Record,"%ld %ld %ld",&serno,&srcatm,&dstatm);
 
        chptr = Record;
        while( *chptr && !isalpha(*chptr) )
            chptr++;
 
        if( *chptr =='A' )             /* AROMATIC */
        {   CreateBond(srcatm,dstatm,AromBondFlag);
        } else if( *chptr == 'D' )     /* DOUBLE */
        {   CreateBond(srcatm,dstatm,DoubBondFlag);
        } else if( *chptr == 'T' )     /* TRIPLE */
        {   CreateBond(srcatm,dstatm,TripBondFlag);
        } else if( *chptr == 'H' )     /* HYDROGEN */
        {   CreateBond(srcatm,dstatm,HydrBondFlag);
        } else /* (*chptr == 'S') */   /* SINGLE */
            CreateBond(srcatm,dstatm,NormBondFlag);
    }
    return True;
}
 
 
int LoadCharmmMolecule( FILE *fp )
{
    auto char buffer[4];
    register RAtom __far *ptr;
    register Long atoms,serno;
    register Long dx, dy, dz;
    register int chain,resno;
    register int i;

    DataFile = fp;
 
    do {
        FetchRecord(DataFile,Record);
    } while( *Record=='*' );
    atoms = ReadValue(0,5);
    if( !atoms ) return False;
 
    MinHetaRes = MaxHetaRes = 0;
    strcpy(Info.filename,DataFileName);
    MainGroupCount = 0;
 
    chain = 0;
    CurChain = NULL;
    for( serno=0; serno<atoms; serno++ )
    {   FetchRecord(DataFile,Record);
 
        if( !CurChain || strncmp(Record+51,buffer,4) )
        {   for( i=0; i<4; i++ )
                buffer[i] = Record[51+i];
            ConnectAtom = (RAtom __far*)0;
            CreateChain(chain+49);
            chain++;
        }

        /* Non-standard Sequential Residue Numbering */
        /* resno = (int)ReadValue(5,5); */

        resno = (int)ReadValue(56,5);
        if( !CurGroup || (CurGroup->serno!=resno) )
        {   CreateGroup( GroupPool );
            CurGroup->refno = FindResNo(Record+11);
            CurGroup->serno = resno;
            ProcessGroup( False );
        }
 
        ptr = CreateAtom();
        ptr->refno = ComplexAtomType(Record+15);
        ptr->temp = (int)ReadValue(60,9);
        ptr->serno = ReadValue(0,5);
        /* ptr->serno = serno+1; */
 

        dx = ReadValue(20,8);
        dy = ReadValue(30,8);
        dz = ReadValue(40,8);
        ptr->xorg =  dx/4;
        ptr->yorg =  dy/4;
        ptr->zorg = -dz/4;
        ptr->xtrl =  (short)(10*(dx-4*ptr->xorg));
        ptr->ytrl =  (short)(10*(dy-4*ptr->yorg));
        ptr->ztrl =  (short)(10*(-dz-4*ptr->zorg));
        ProcessAtom( ptr );
    }
    return True;
}
 

static int MOPACAtomType( char *type )
{
    auto char name[4];
    register char ch1,ch2;
    register int i;
 
    if( *type == ' ' )
        type++;
 
    name[2] = name[3] = ' ';
    if( isdigit(type[0]) )
    {   i = *type++ - '0';
        while( isdigit(*type) )
            i = (10*i) + (*type++ - '0');
 
        /* Last Atom in File! */
        if( i == 0 )
        {   return( -1 );
        } else if( i >= 99 )
            return( 1 );
 
        /* Construct Name */
        ch1 = Element[i].symbol[0];
        ch2 = Element[i].symbol[1];
        if( ch2 == ' ' )
        {   name[1] = ch1;
            name[0] = ' ';
        } else
        {   name[1] = ToUpper(ch2);
            name[0] = ch1;
        }
 
    } else
    {   ch1 = ToUpper(type[0]);
        ch2 = ToUpper(type[1]);
        if( (ch1=='X') || (ch1=='+') || (ch1=='-') )
        {   return( 1 );
        } else if( (ch1=='T') && (ch2=='V') )
            return( 1 );
 
        if( ch2 && (ch2!=' ') && (ch2!='(') && !isdigit(ch2) )
        {   name[0] = ch1;
            name[1] = ch2;
        } else
        {   name[1] = ch1;
            name[0] = ' ';
        }
    }
    return NewAtomType(name);
}
 
 
static int ReadMOPACOutputFile( void )
{
    register RAtom __far *atm;
    register int i,init;
    register char *ptr;
    register Long dx, dy, dz;

    /* Avoid compiler warnings */
    atm = (RAtom __far *)0;
 
    init = False;
    while( FetchRecord(DataFile,Record) )
    {   ptr = Record;
        while( *ptr == ' ' )
            ptr++;
 
        if( !strncmp(ptr,"CARTESIAN COORDINATES",21) )
        {   for( i=0; i<3; i++ )
                FetchRecord(DataFile,Record);
 
            if( Database )
            {   atm = CurGroup->alist;
                MMinMaxFlag = False;
                HasHydrogen = False;
                MainAtomCount = 0;
            }
 
            while( FetchRecord(DataFile,Record) && 
                   *Record && isdigit(Record[5]) )
            {   if( !Database )
                {   atm = (RAtom __far*)0;
                    CreateMolGroup();
                    init = True;
                }
 
                if( !atm )
                {   atm = CreateAtom();
                    atm->serno = (int)ReadValue(0,6);
                    atm->refno = MOPACAtomType(Record+14);
                    atm->temp = 0;
 
                    dx = ReadValue(20,10);
                    dy = ReadValue(30,10);
                    dz = ReadValue(40,10);
                } else
                {   dx = ReadValue(30,10);
                    dy = ReadValue(40,10);
                    dz = ReadValue(50,10);
                }
                atm->xorg =  dx/40;
                atm->yorg =  dy/40;
                atm->zorg = -dz/40;
                atm->xtrl  = (short)(dx-40*atm->xorg);
                atm->ytrl  = (short)(dy-40*atm->yorg);
                atm->ztrl  = (short)(-dz-40*atm->zorg);

                ProcessAtom(atm);
                atm = atm->anext;
            }
             
        } else if( !strncmp(ptr,"NET ATOMIC CHARGES",18) )
        {   FetchRecord(DataFile,Record);
            FetchRecord(DataFile,Record);
 
            if( Database )
            {   atm = CurGroup->alist;
                MMinMaxFlag = False;
                HasHydrogen = False;
                MainAtomCount = 0;
            }
 
            while( FetchRecord(DataFile,Record) && 
                   strncmp(Record," DIPOLE",7) )
            {   if( !Database )
                {   atm = (RAtom __far*)0;
                    CreateMolGroup();
                }
 
                if( !atm )
                {   atm = CreateAtom();
                    atm->serno = (int)ReadValue(0,12);
                    atm->refno = MOPACAtomType(Record+21);
                    atm->temp = (int)(ReadValue(27,13)/100);
                    atm->xorg = atm->yorg = atm->zorg = 0;
                } else
                    atm->temp = (int)(ReadValue(27,13)/100);
                ProcessAtom(atm);
                atm = atm->anext;
            }
        }
    }
 
    if( !init )
    {   if( Database )
            DestroyDatabase();
        return False;
    } else return True;
}
 
 
static int MoreMOPACKeywords( void )
{
    register char *ptr;
 
    ptr = Record;
    while( *ptr )
    {   if( *ptr == '+' )
            if( !ptr[1] || (ptr[1]==' ') )
                return(True);
 
        /* Skip Next Keyword */
        while( *ptr && *ptr!=' ' ) ptr++;
        while( *ptr == ' ' ) ptr++;
    }
    return False;
}
 
 
int LoadMOPACMolecule( FILE *fp )
{
    static int na,nb,nc,lopt;
    static double dist,angle,dihed;
    register IntCoord __far *coord;
    register RAtom __far *aptr;
    register int count,refno;
    register int cartflag;
    register char *ptr;
 
    DataFile = fp;
    FetchRecord(DataFile,Record);
 
    /* Test for MOPAC output file */
    if( !strncmp(Record," ***",4) )
        return( ReadMOPACOutputFile() );
 
    /* MOPAC Keywords */
    while( MoreMOPACKeywords() )
        FetchRecord(DataFile,Record);
 
    FetchRecord(DataFile,Record); /* Molecule Name */
    ExtractString(78,Record,Info.moleculename);
    FetchRecord(DataFile,Record); /* Comments */
 
    count = 0;
    cartflag = False;
    InitInternalCoords();
    while( FetchRecord(DataFile,Record) )
    {   /* Process Record! */
        for( ptr=Record; *ptr; ptr++ )
            if( (*ptr==',') || (*ptr==0x09) )
                *ptr = ' ';
 
        ptr = Record;
        while( *ptr == ' ' )
           ptr++;
 
        if( !*ptr ) break;
        refno = MOPACAtomType(ptr);
        if( refno == -1 ) break;
 
        while( *ptr && (*ptr!=' ') )
            if( *ptr == '(' )
            {   /* Skip Atom Label */
                while( *ptr && (*ptr!=')') )
                    ptr++;
            } else ptr++;
 
        na = nb = nc = 0;
        dist = angle = dihed = 0.0;
        sscanf(ptr,"%lf %*d %lf %*d %lf %d %d %d %d",
               &dist, &angle, &dihed, &lopt, &na, &nb, &nc );
        count++;
 
        if( count == 3 )
        {   /* Handle missing dihedral */
            if( lopt == 2 )
            {   na = 1;  nb = 2;
                dihed = 0.0;
            } else if( lopt == 1)
            {   /* Safe FP comparison for Cartesian */
                if( (dihed>=1.9999) && (dihed<=2.0001) )
                {   na = 2;  nb = 1;
                    dihed = 0.0;
                }
            }
        } else if( count == 4 )
            cartflag = (na == 0);
 
        coord = AllocInternalCoord();
        coord->na = na; coord->nb = nb; coord->nc = nc;
        coord->refno = refno;
        coord->angle = angle;
        coord->dihed = dihed;
        coord->dist = dist;
    }
 
    if( !count )
        return False;
 
    /* Co-ordinate conversion! */
    if( !cartflag )
        if( !ConvertInternal2Cartesian() )
        {   InvalidateCmndLine();
            WriteString("Error: Invalid MOPAC z-matrix file!\n\n");
            FreeInternalCoords();
            return False;
        }
 
    count = 0;
    for( coord=IntList; coord; coord=coord->inext )
        if( coord->refno != 1 )
        {   if( !Database )
                CreateMolGroup();
 
            aptr = CreateAtom();
            aptr->refno = (Byte)coord->refno;
            aptr->serno = ++count;
            aptr->temp = 0;
 
            aptr->xorg =  (Long)(250.0*coord->dist);
            aptr->yorg =  (Long)(250.0*coord->angle);
            aptr->zorg = -(Long)(250.0*coord->dihed);
            ProcessAtom(aptr);
        } else count++;
 
    FreeInternalCoords();
    return True;
}
 

int LoadMacroModelMolecule( FILE *fp )
{
#ifdef MMIOLIB
    return True;
#else
    register char *src,*dst;
    register int i;
    auto int atoms;
 
    DataFile = fp;
 
    /* Number of Atoms & Description */
    FetchRecord(DataFile,Record);
    sscanf(Record,"%d",&atoms);
 
    src = Record;
    dst = Info.moleculename;
    for( i=0; i<78; i++ )
        if( *src ) *dst++ = *src++;
    *dst = '\0';
 
    for( i=0; i<atoms; i++ )
    {    FetchRecord(DataFile,Record);
    }
    return True;
#endif
}

int RightJustify( char __far *str, int len )
{
    register int lstr, ii;

    lstr = (int)strlen(str);
    for (ii = lstr; ii > 0; ii--)
    {
      if (str[ii-1] != ' ' && str[ii-1] != '\t') {
        lstr = ii;
        break;
      }
    }
    if (lstr < len) {
      str[len--] = '\0';
      for (ii = lstr; ii > 0; ) str[len--] = str[--ii];
      for (ii = len+1; ii > 0; ) str[--ii] = ' ';
    }
    return 0;
      
}

int ReadCIFDouble( cif_handle cif, double __far *dvalue,
                   char __far *tag, char __far *alttag )
{
  char __far * value;
  if (!cif_findtag(cif, tag)
     || (alttag && (!cif_findtag(cif, alttag)))) {
    cif_get_value(cif, (char __far * __far *) &value);
    return cif_ctonum(value, (int)strlen(value), dvalue, 
      NULL, NULL, NULL, NULL, NULL, NULL, NULL);
  }
  return 1;
}

int ReadCIFRowValue( cif_handle cif, double __far *dvalue,
                     unsigned int column )
{
  char __far * value;
  if (column == -1) return 1;
  if (!cif_select_column(cif,column)){
    cif_get_value(cif, (char __far * __far *) &value);
    if (cif_ctonum(value, (int)strlen(value), dvalue, 
      NULL, NULL, NULL, NULL, NULL, NULL, NULL)) return 1;
    return 0;
  }
  return 1;
}

int ReadCIFstr( cif_handle cif, unsigned int colnum, 
                char __far  *strg, int width )
{
    char __far * value;

    *strg = '\0';
    if (colnum == -1) return 1;
    cif_select_column(cif,colnum);
    cif_get_value(cif, (char __far * __far *) &value);
    if (*(value-1) == CIF_TOKEN_NULL) value++;
    ExtractNBString(width,value,strg);
    return 0;
}

int ReadcurCIFstr( cif_handle cif, char __far  *strg, int width)
{
    char __far * value;

    *strg = '\0';
    cif_get_value(cif, (char __far * __far *) &value);
    if (*(value-1) == CIF_TOKEN_NULL) value++;
    ExtractNBString(width,value,strg);
    return 0;
}



void ConvertNames( char __far type_symbol[5],  char __far label_atom_id[5] )
{
    int i, laid, lat;
    char __far tmparg[5];
    char symbol[5]="  ";

    laid = (int)strlen(label_atom_id);
    lat = type_symbol?(int)strlen(type_symbol):0;
    if (lat > 1) {
      if ((type_symbol[lat-1] =='+') || (type_symbol[lat-1] == '-')) {
        if (strchr("0123456789",type_symbol[lat-2])) {
          lat -= 2;
        } else {
          lat--;
        }
      }
    } else {
      if ( (!type_symbol) && (laid > 1) && 
	   islower(label_atom_id[1]) && isupper(label_atom_id[0])) {
           strncpy(symbol,label_atom_id,2);
           type_symbol = symbol; 
           lat = 2;       
      }
    }
    for (i = laid; i < 5; i++) label_atom_id[i] = '\0';
    strcpy(tmparg,label_atom_id);
    if ((label_atom_id[0] < '0') || (label_atom_id[0] > '9') ){
      if (laid>0 && laid < 4 && lat > 0 ) {
        if ((strncmp(label_atom_id, type_symbol, lat) == 0) &&
          lat ==1) {
          label_atom_id[0] = ' ';
          strcpy(label_atom_id+1,tmparg);
         } 
      } else {
        if ((laid > 0) && (laid < 4)) {
          label_atom_id[0] = ' ';
          strcpy(label_atom_id+1,tmparg);
        }
      }
    }
    if (lat == 1) {
      strncpy(tmparg,type_symbol,4);
      type_symbol[0] = ' ';
      strncpy(type_symbol+1,tmparg,3);
      type_symbol[4] = '\0';
    }
    if (laid > 1) {
      label_atom_id[0] = ToUpper(label_atom_id[0]);
      label_atom_id[1] = ToUpper(label_atom_id[1]);
    }
    if (label_atom_id[3] == '\0') label_atom_id[3] = ' ';
    if (label_atom_id[2] == '\0') label_atom_id[2] = ' ';
    return;
}

static Long find_chem_comp_id(cif_handle cif, char __far * comp_id, char __far * atom_id ) {
  	if ((!cif_findtag(cif,"_chem_comp_atom.model_Cartn_x")) ||
      (!cif_findtag(cif,"_chem_comp_atom.model_Cartn_x_ideal"))||
      (!cif_findtag(cif,"_chem_comp_atom.pdbx_model_Cartn_x_ideal"))){
      unsigned int 
        col_comp_id=-1,
        col_atom_id=-1;
      unsigned int rows, rownum;
      
      char __far label_atom_id[5], idstr[11], 
        label_comp_id[4]="   "; 
        
                
      /* Load column numbers for the tags we have */
      if ((!cif_find_column(cif,"comp_id"))||
          (!cif_find_column(cif,"pdbx_alt_comp_id"))||
          (!cif_find_column(cif,"alt_comp_id")))
          cif_column_number(cif,&col_comp_id);
        
      if ((!cif_find_column(cif,"atom_id"))||
          (!cif_find_column(cif,"pdbx_alt_atom_id"))||
          (!cif_find_column(cif,"alt_atom_id")))
          cif_column_number(cif,&col_atom_id);
 
          /* Process atom_site rows, one at a time */

      cif_count_rows(cif,(unsigned int __far *)&rows);
      for (rownum = 0; rownum < rows; ++rownum){
        cif_select_row(cif,rownum);
        ReadCIFstr(cif,col_atom_id,label_atom_id,4);
        if (strncasecmp(label_atom_id, atom_id, 5)) continue;
        ReadCIFstr(cif,col_comp_id,label_comp_id,3);
        if (strncasecmp(label_comp_id, comp_id, 4)) continue;
        {
          char __far * endptr;
          Long serno;
          serno = (int)strtol(idstr, (char __far * __far *)&endptr,10);
          if (*endptr != '\0') serno = rownum+1;
          return serno;
        } 
      }

    } 

    return -1;

}


int LoadCIFMolecule( FILE *fp )
{
    cif_handle cif;
    double length_a = 1., 
           length_b = 1.,
           length_c = 1., 
           ang_alpha = 90., 
           ang_beta  = 90.,
           ang_gamma = 90.;
    int result_a, result_b, result_c,
       result_alpha, result_beta, result_gamma;
    int result_scale, result_vector, result_cell;
    long minsernum, maxsernum, maxnmrmodel;
    
    minsernum = 99999999L;
    maxsernum = -99999999L;
    maxnmrmodel = 0;
   
    DataFile = fp;
    cif_make_handle (&cif);
    cif_read_file (cif, fp);
    FeatList = (void __far*)0;
    
    strcpy (Info.classification,"");
    strcpy (Info.identcode,"");
    strcpy (Info.moleculename,"");
    strcpy (Info.technique,"");
    strcpy (Info.spacegroup,"");
    
    cif_rewind_datablock(cif);

    /*  Recover the HEADER information */
    if (!cif_findtag(cif, "_struct_biol.details")) {
      ReadcurCIFstr(cif,Info.classification,40);
    }
    Info.identcode[0] = '\0';
    if (!cif_findtag(cif, "_database_2.database_code") ||
      !cif_findtag(cif, "_entry.id") ||
      !cif_findtag(cif, "_struct_biol.id") ||
      !cif_findtag(cif, "_audit_block_code")) {
      ReadcurCIFstr(cif,Info.identcode,9);
    }

    /* Recover the Title */

    if ((!cif_findtag(cif, "_struct.title")) ||
      (!cif_findtag(cif, "_chemical_name_common")) ||
      (!cif_findtag(cif, "_chemical_name_systematic")) ||
      (!cif_findtag(cif, "_chemical_name_mineral"))) {
      ReadcurCIFstr(cif,Info.moleculename,56);
    } else {
      char * dbname;
      if (!cif_datablock_name (cif, &dbname))
        strncpy(Info.moleculename,dbname,55);
        Info.moleculename[55] = '\0';
    }

    /* Recover the Experimental Technique */

    if ((!cif_findtag(cif, "_exptl.method")) ||
      (!cif_findtag(cif, "_diffrn_radiation.probe")) ||
      (!cif_findtag(cif, "_diffrn_radiation_probe"))) {
      ReadcurCIFstr(cif,Info.technique,56);
    }


    /* Recover the Space Group */
    if ((!cif_findtag(cif, "_symmetry.space_group_name_H-M")) ||
      (!cif_findtag(cif, "_symmetry_space_group_name_H-M"))) {
      ReadcurCIFstr(cif,Info.spacegroup,12);
    }

    /* Recover Cell */
    result_a =
      ReadCIFDouble (cif, &length_a, "_cell.length_a", "_cell_length_a");
    result_b =
      ReadCIFDouble (cif, &length_b, "_cell.length_b", "_cell_length_b");
    result_c =
      ReadCIFDouble (cif, &length_c, "_cell.length_c", "_cell_length_c");
    result_alpha =
      ReadCIFDouble (cif, &ang_alpha, "_cell.angle_alpha", 
        "_cell_angle_alpha");
    result_beta =
      ReadCIFDouble (cif, &ang_beta,  "_cell.angle_beta",  
        "_cell_angle_beta");
    result_gamma =
      ReadCIFDouble (cif, &ang_gamma, "_cell.angle_gamma", 
        "_cell_angle_gamma");
    if (result_a || result_b || result_c || 
      result_alpha || result_beta || result_gamma) {
      WriteString("Error: Missing or Incomplete CIF Cell\n\n");
      WriteString(" 1,1,1,90.,90.,90. assumed\n\n");
      Info.cell[0] = 1.;
      Info.cell[1] = 1.;
      Info.cell[2] = 1.;
      Info.cell[3] = 90.;
      Info.cell[4] = 90.;
      Info.cell[5] = 90.;
    } else { 
    Info.cell[0] = length_a;
    Info.cell[1] = length_b;
    Info.cell[2] = length_c;
    Info.cell[3] = ang_alpha;
    Info.cell[4] = ang_beta;
    Info.cell[5] = ang_gamma;
    }
    result_cell =
      cell2mat(Info.cell, Info.matf2o, Info.mato2f);
    if (!result_cell)
      result_cell |=
        invxfrm(Info.mato2f,Info.veco2f,Info.matf2o,Info.vecf2o); 
    if (result_cell) {
      int i,j;

      WriteString("Error: Invalid CIF Cell\n\n");                    
      for ( i=0; i<3; i++ ) {
         Info.vecf2o[i] =  Info.veco2f[i] = Info.cell[i] = 0.;
         Info.cell[i+3] = 90.;
         for ( j=0; j<3; j++) { Info.matf2o[i][j] = 
           Info.mato2f[i][j] = ((i!=j)?0.:1.);
         }
      }
    }
    Info.cella = Info.cell[0];
    Info.cellb = Info.cell[1];
    Info.cellc = Info.cell[2];
    Info.cellalpha = Deg2Rad*Info.cell[3];
    Info.cellbeta  = Deg2Rad*Info.cell[4];
    Info.cellgamma = Deg2Rad*Info.cell[5];

    /* Process Transformation to Fractional Coordinates */
    result_scale = True;
    result_vector = True;
    if ((!cif_findtag(cif,"_atom_sites.fract_transf_matrix[1][1]")) ||
	(!cif_findtag(cif,"_atom_sites_fract_tran_matrix_11"))){
      int i, j;
      char mmcifname[40];
      char corecifname[40];

      result_scale = False;
      for ( i=0; (!result_scale && i<3); i++ ) {
        for ( j=0; (!result_scale && j<3); j++ ) {
          sprintf(mmcifname,"_atom_sites.fract_transf_matrix[%i][%i]",i+1,j+1);
          sprintf(corecifname,"_atom_sites_fract_tran_matrix_%i%i",i+1,j+1);
          result_scale |=
           ReadCIFDouble (cif, &(Info.mato2f[i][j]), mmcifname, 
           corecifname);
        }
      }
      result_vector = False;
      for ( i=0; (!result_vector && i<3); i++ ) {
        sprintf(mmcifname,"_atom_sites.fract_transf_vector[%i]",i+1);
        sprintf(corecifname,"_atom_sites_fract_tran_vector_%i",i+1);
          result_vector |=
           ReadCIFDouble (cif, &(Info.veco2f[i]), mmcifname, 
           corecifname);
      }
      if (result_vector) {
        for (i=0; i<3; i++ ) Info.veco2f[i] = 0;
      }
      if (!result_scale) {
        result_scale |=
          invxfrm(Info.mato2f,Info.veco2f,Info.matf2o,Info.vecf2o);
      } 
      if (result_scale) {                     
        WriteString
          ("Error: Invalid CIF fractional transformation matrix\n\n");
        for ( i=0; i<3; i++ ) {
           Info.vecf2o[i] =  Info.veco2f[i] = 0.;
           for ( j=0; j<3; j++) { Info.matf2o[i][j] = 
             Info.mato2f[i][j] = ((i!=j)?0.:1.);
           }
        }
      }
    }

    /* Process Transformation from Fractional Coordinates */
    if (result_scale &&
      ((!cif_findtag(cif,"_atom_sites.cartn_transf_matrix[1][1]")) ||
	(!cif_findtag(cif,"_atom_sites_cartn_tran_matrix_11")))){
      int i, j;
      char mmcifname[40];
      char corecifname[40];

      result_scale = False;
      for ( i=0; (!result_scale && i<3); i++ ) {
        for ( j=0; (!result_scale && j<3); j++ ) {
          sprintf(mmcifname,"_atom_sites.cartn_transf_matrix[%i][%i]",i+1,j+1);
          sprintf(corecifname,"_atom_sites_cartn_tran_matrix_%i%i",i+1,j+1);
          result_scale |=
           ReadCIFDouble (cif, &(Info.matf2o[i][j]), mmcifname, 
           corecifname);
        }
      }
      result_vector = False;
      for ( i=0; (!result_vector && i<3); i++ ) {
        sprintf(mmcifname,"_atom_sites.cartn_transf_vector[%i]",i+1);
        sprintf(corecifname,"_atom_sites_cartn_tran_vector_%i",i+1);
          result_vector |=
           ReadCIFDouble (cif, &(Info.vecf2o[i]), mmcifname, 
           corecifname);
      }
      if (result_vector) {
        for (i=0; i<3; i++ ) Info.veco2f[i] = 0;
      }
      if (! result_scale) {
        result_scale |=
          invxfrm(Info.matf2o,Info.vecf2o, Info.mato2f,Info.veco2f);
      } 
      if (result_scale) {                     
        WriteString
          ("Error: Invalid CIF Cartesian transformation matrix\n\n");
        for ( i=0; i<3; i++ ) {
           Info.vecf2o[i] =  Info.veco2f[i] = 0.;
           for ( j=0; j<3; j++) { Info.matf2o[i][j] = 
             Info.mato2f[i][j] = ((i!=j)?0.:1.);
           }
        }
      }
    }


    /* Process Coordinates */

    if ((!cif_findtag(cif,"_atom_site.cartn_x")) ||
      (!cif_findtag(cif,"_atom_site_cartn_x"))||
      (!cif_findtag(cif,"_atom_site.fract_x"))||
      (!cif_findtag(cif,"_atom_site_fract_x"))){
      unsigned int 
        col_cartn_x=-1,       col_cartn_y=-1,       col_cartn_z=-1,
        col_fract_x=-1,       col_fract_y=-1,       col_fract_z=-1,
        col_group_PDB=-1,     col_label_atom_id=-1, col_label_alt_id=-1,
        col_label_comp_id=-1, col_label_asym_id=-1, col_auth_asym_id=-1,
        col_auth_seq_id=-1,   col_label_seq_id=-1,  col_B_iso=-1,
        col_U_iso=-1,         col_type_symbol=-1,   col_model_id=-1,
        col_id=-1;
      unsigned int rows, rownum;
      char __far group_PDB[7], idstr[6], oidstr[6], label_atom_id[5],
           label_alt_id[2], label_comp_id[4]="   ", label_asym_id[2],
           auth_asym_id[5], label_seq_id[6], type_symbol[5], modelstr[6];
      double cartn_x, cartn_y, cartn_z, fract_xyz[3];
      double B_iso, U_iso;
      int heta;
      int fcoord=False;
      register Bond __far *bptr;
      register RAtom __far *ptr;
      int oNMRModel;
  
      /* Load column numbers for the tags we have */
      if ((!cif_find_column(cif,"cartn_x"))||
        (!cif_find_column(cif,CIF_PRFX "atom_site_cartn_x")))
          cif_column_number(cif,&col_cartn_x);
      if ((!cif_find_column(cif,"cartn_y"))||
        (!cif_find_column(cif,CIF_PRFX "atom_site_cartn_y")))
          cif_column_number(cif,&col_cartn_y);
      if ((!cif_find_column(cif,"cartn_z"))||
        (!cif_find_column(cif,CIF_PRFX "atom_site_cartn_z")))
          cif_column_number(cif,&col_cartn_z);
      if ((!cif_find_column(cif,"fract_x"))||
        (!cif_find_column(cif,CIF_PRFX "atom_site_fract_x")))
          cif_column_number(cif,&col_fract_x);
      if ((!cif_find_column(cif,"fract_y"))||
        (!cif_find_column(cif,CIF_PRFX "atom_site_fract_y")))
          cif_column_number(cif,&col_fract_y);
      if ((!cif_find_column(cif,"fract_z"))||
        (!cif_find_column(cif,CIF_PRFX "atom_site_fract_z")))
          cif_column_number(cif,&col_fract_z);
      if ((!cif_find_column(cif,"group_pdb")))
          cif_column_number(cif,&col_group_PDB);
      if ((!cif_find_column(cif,"label_atom_id")))
          cif_column_number(cif,&col_label_atom_id);
      if ((!cif_find_column(cif,"label_alt_id"))||
        (!cif_find_column(cif,CIF_PRFX "atom_site_disorder_group")))
          cif_column_number(cif,&col_label_alt_id);
      if ((!cif_find_column(cif,"label_comp_id")))
          cif_column_number(cif,&col_label_comp_id);
      if ((!cif_find_column(cif,"label_asym_id")))
          cif_column_number(cif,&col_label_asym_id);
      if ((!cif_find_column(cif,"auth_asym_id")))
          cif_column_number(cif,&col_auth_asym_id);
      if ((!cif_find_column(cif,"label_seq_id")))
          cif_column_number(cif,&col_label_seq_id);
      if ((!cif_find_column(cif,"auth_seq_id")))
          cif_column_number(cif,&col_auth_seq_id);
      if ((!cif_find_column(cif,"b_iso_or_equiv"))||
        (!cif_find_column(cif,CIF_PRFX "atom_site_b_iso_or_equiv")))
          cif_column_number(cif,&col_B_iso);
      if ((!cif_find_column(cif,"u_iso_or_equiv"))||
        (!cif_find_column(cif,CIF_PRFX "atom_site_u_iso_or_equiv")))
          cif_column_number(cif,&col_U_iso);
      if ((!cif_find_column(cif,"type_symbol"))||
        (!cif_find_column(cif,CIF_PRFX "atom_site_type_symbol")))
          cif_column_number(cif,&col_type_symbol);
      if ((!cif_find_column(cif,"label_model_id"))||
        (!cif_find_column(cif,"pdb2cif_label_model_id")))
          cif_column_number(cif,&col_model_id);
      if ((!cif_find_column(cif,"id"))||
        (!cif_find_column(cif,CIF_PRFX "atom_site_label")))
          cif_column_number(cif,&col_id);

      NMRModel = 0;
      oNMRModel = -1;

      /* Process atom_site rows, one at a time */

      cif_count_rows(cif,(unsigned int __far *)&rows);
      for (rownum = 0; rownum < rows; ++rownum){
        cif_select_row(cif,rownum);
        ReadCIFstr(cif,col_group_PDB,group_PDB,5);
        heta = False;
        if (group_PDB[0]=='H' || group_PDB[0]=='h') heta = True; 
        ReadCIFstr(cif,col_id,idstr,5);
        strncpy(oidstr,idstr,5);
        ReadCIFstr(cif,col_label_atom_id,label_atom_id,4);
        ReadCIFstr(cif,col_type_symbol,type_symbol,4);
        ReadCIFstr(cif,col_label_alt_id,label_alt_id,1);
        if (label_alt_id[0] == '\0') strcpy(label_alt_id," ");
        ReadCIFstr(cif,col_label_comp_id,label_comp_id,3);
        if (strlen(label_comp_id)<(size_t)3) RightJustify(label_comp_id,3);
        ReadCIFstr(cif,col_label_asym_id,label_asym_id,1);
        if (label_asym_id[0] == '\0') {
          strcpy(label_asym_id," ");
          ReadCIFstr(cif,col_auth_asym_id,auth_asym_id,4);
          if (auth_asym_id[0] == '\0') {
            strcpy(auth_asym_id," ");
          } else {
            strcpy(label_asym_id,auth_asym_id);
          }
        } else {
          ReadCIFstr(cif,col_auth_asym_id,auth_asym_id,4);
          if (auth_asym_id[0] == '\0') strcpy(auth_asym_id," ");
        }
        {
          int seqnum, sseqnum, icode, sicode, auth_seq;
          char __far * endptr;
          ReadCIFstr(cif,col_model_id,modelstr,5);
          NMRModel = 0;
          if (modelstr[0]) {
            NMRModel = (int)strtol(modelstr,
              (char __far * __far *)&endptr, 10);
            if (! (NMRModel == oNMRModel) ) {
               if (NMRModel > maxnmrmodel) maxnmrmodel = NMRModel;
               ConnectAtom = (void __far*)0;
               CurGroup = (void __far*)0;
               CurChain = (void __far*)0;
            }
            oNMRModel = NMRModel;
          }
          seqnum = sseqnum = -9999;
          icode = sicode = ' ';
          if((auth_seq=!ReadCIFstr(cif,col_auth_seq_id,label_seq_id,5))||
	    (!ReadCIFstr(cif,col_label_seq_id,label_seq_id,5))){
            seqnum = (int)strtol(label_seq_id, 
              (char __far * __far *)&endptr, 10);
            icode = ' ';
            if (*endptr != '\0') icode = *endptr;
          }
          if (auth_seq &&
	    (!ReadCIFstr(cif,col_label_seq_id,label_seq_id,5))){
            sseqnum = (int)strtol(label_seq_id, 
              (char __far * __far *)&endptr, 10);
            sicode = ' ';
            if (*endptr != '\0') sicode = *endptr;
          }
          if ( !CurGroup || (CurGroup->serno!=seqnum)
            || (CurChain->ident!=label_asym_id[0])
	    || (PDBInsert != icode) ) {
            PDBInsert = icode;
            if( !CurChain || (CurChain->ident!=label_asym_id[0] )) {
              ConnectAtom = (RAtom __far*)0;
              CreateChain (label_asym_id[0]);
            }
            CreateGroup( GroupPool );
            CurGroup->refno = FindResNo(label_comp_id);
            CurGroup->serno = seqnum;
            CurGroup->insert = icode;
            CurGroup->sserno = sseqnum;
            CurGroup->sinsert = sicode;
            ProcessGroup (heta);              
          }
        }
        ptr = CreateAtom();
        {
          char __far * endptr;
          ptr->serno = (int)strtol(idstr, (char __far * __far *)&endptr,10);
          if (*endptr != '\0') ptr->serno = rownum+1;
          if (maxsernum < minsernum) {
            maxsernum=minsernum=ptr->serno;
          } else  {
            if (ptr->serno > maxsernum) maxsernum=ptr->serno;
            if (ptr->serno < minsernum) minsernum=ptr->serno;
          } 
        }
        ptr->altl = label_alt_id[0];
        ptr->model = NMRModel;
        cartn_x = 0.;
        cartn_y = 0.;
        cartn_z = 0.;
        if (!fcoord) {
          fcoord =  ReadCIFRowValue(cif, 
                              (double __far *)&cartn_x, col_cartn_x) ||
                    ReadCIFRowValue(cif, 
                              (double __far *)&cartn_y, col_cartn_y) ||
                    ReadCIFRowValue(cif, 
                              (double __far *)&cartn_z, col_cartn_z);
        }
        if (fcoord) {
          fcoord = !( ReadCIFRowValue(cif, 
                       (double __far *)&fract_xyz[0], col_fract_x)  ||
                    ReadCIFRowValue(cif, 
                        (double __far *)&fract_xyz[1], col_fract_y) ||
                    ReadCIFRowValue(cif, 
                        (double __far *)&fract_xyz[2], col_fract_z));
        }
        if (fcoord) {
          int jj;

          cartn_x = Info.vecf2o[0];
          cartn_y = Info.vecf2o[1];
          cartn_z = Info.vecf2o[2];
          for (jj=0; jj<3; jj++){
            cartn_x += Info.matf2o[0][jj]*fract_xyz[jj];
            cartn_y += Info.matf2o[1][jj]*fract_xyz[jj];
            cartn_z += Info.matf2o[2][jj]*fract_xyz[jj];
	  }
        }
        ptr->xorg = (Long)(cartn_x*250.);
        ptr->yorg = (Long)(cartn_y*250.);
        ptr->zorg = -(Long)(cartn_z*250.);
        ptr->xtrl = (short)(10000.0*cartn_x-40.0*(double)ptr->xorg);
        ptr->ytrl = (short)(10000.0*cartn_y-40.0*(double)ptr->yorg);
        ptr->ztrl = (short)(-10000.0*cartn_z-40.0*(double)ptr->zorg);

        if (label_atom_id[0]=='\0')  strncpy(label_atom_id,oidstr,4);
	{
          int i, laid, lat;
          char __far tmparg[5];

          lat = (int)strlen(type_symbol);
          if (lat > 1) {
            if ((type_symbol[lat-1] =='+') || (type_symbol[lat-1] == '-')) {
              if (strchr("0123456789",type_symbol[lat-2])) {
                lat -= 2;
              } else {
                lat--;
              }
            }
          }
          laid = (int)strlen(label_atom_id);
          for (i = laid; i < 5; i++) label_atom_id[i] = '\0';
          strcpy(tmparg,label_atom_id);
          if ((label_atom_id[0] < '0') || (label_atom_id[0] > '9') ){
            if (laid>0 && laid < 4 && lat > 0 ) {
              if ((strncmp(label_atom_id, type_symbol, lat) == 0) &&
                lat ==1) {
                label_atom_id[0] = ' ';
                strcpy(label_atom_id+1,tmparg);
              } 
            } else {
              if ((laid > 0) && (laid < 4)) {
                label_atom_id[0] = ' ';
                strcpy(label_atom_id+1,tmparg);
              }
            }
	  }
          if (lat == 1) {
            strncpy(tmparg,type_symbol,4);
            type_symbol[0] = ' ';
            strncpy(type_symbol+1,tmparg,3);
            type_symbol[4] = '\0';
          }

          if (label_atom_id[3] == '\0') label_atom_id[3] = ' ';
          if (label_atom_id[2] == '\0') label_atom_id[2] = ' ';
          ptr->refno = ComplexAtomType(label_atom_id);
            
        }

        if (heta) ptr->flag |= HeteroFlag;
        if (!ReadCIFRowValue(cif,(double __far *)&B_iso,col_B_iso)) {
          ptr->temp = (int) (B_iso*100.);
        } else {
          if (!ReadCIFRowValue(cif,(double __far *)&U_iso,col_U_iso)) {
            ptr->temp = (int) (U_iso*100.*8.*PI*PI);
          }
	}
       
        ProcessAtom(ptr);
         /* Create biopolymer Backbone */
        if( IsAlphaCarbon(ptr->refno) && IsProtein(CurGroup->refno) )
        {   if( ConnectAtom )
            {   register Long dx,dy,dz;

                dx = ConnectAtom->xorg - ptr->xorg;
                dy = ConnectAtom->yorg - ptr->yorg;
                dz = ConnectAtom->zorg - ptr->zorg;
 
                /* Break backbone if CA-CA > 7.00A */
                if( dx*dx+dy*dy+dz*dz < (Long)1750*1750 )
                {   bptr = ProcessBond(ptr,ConnectAtom,NormBondFlag);
                    bptr->bnext = CurChain->blist;
                    CurChain->blist = bptr;
                } else ptr->flag |= BreakFlag;
            }
            ConnectAtom = ptr;
        } else if( IsSugarPhosphate(ptr->refno) && IsNucleo(CurGroup->refno) )
        {   if( ConnectAtom )
            {   bptr = ProcessBond(ConnectAtom,ptr,NormBondFlag);
                bptr->bnext = CurChain->blist;
                CurChain->blist = bptr;
            }
            ConnectAtom = ptr;
        }
    
      }
      ConnectAtom = (void __far*)0;
      CurGroup = (void __far*)0;
      CurChain = (void __far*)0;
    }

    /* Process Bonds */

    NullBonds = 0;
    if (!cif_findtag(cif,"_struct_conn.id")){
      unsigned int 
        col_conn_type_id,
        col_ptnr1_label_alt_id=-1,       col_ptnr1_label_asym_id=-1, 
        col_ptnr1_label_atom_id=-1,      col_ptnr1_label_comp_id=-1,
        col_ptnr1_label_seq_id=-1,       col_ptnr1_label_model_id=-1,
        col_ptnr1_atom_site_id=-1,       col_ptnr1_symmetry=-1,
        col_ptnr1_auth_alt_id=-1,        col_ptnr1_auth_asym_id=-1, 
        col_ptnr1_auth_atom_id=-1,       col_ptnr1_auth_comp_id=-1,
        col_ptnr1_auth_seq_id=-1,
        col_ptnr2_label_alt_id=-1,       col_ptnr2_label_asym_id=-1, 
        col_ptnr2_label_atom_id=-1,      col_ptnr2_label_comp_id=-1,
        col_ptnr2_label_seq_id=-1,       col_ptnr2_label_model_id=-1,
        col_ptnr2_atom_site_id=-1,       col_ptnr2_symmetry=-1,
        col_ptnr2_auth_alt_id=-1,        col_ptnr2_auth_asym_id=-1, 
        col_ptnr2_auth_atom_id=-1,       col_ptnr2_auth_comp_id=-1,
        col_ptnr2_auth_seq_id=-1;
      unsigned int rows, rownum;
      char __far CType[7];
      char __far Alt1[2], AtomName1[13], Asym1[2], CompId1[4]="   ", 
        SeqId1[6], ModelId1[6], SiteId1[7], Symm1[8], 
        Alt2[2], AtomName2[13], Asym2[2], CompId2[4]="   ", 
        SeqId2[6], ModelId2[6], SiteId2[7], Symm2[8];
      char Icode1, Icode2, sIcode1, sIcode2;
      int ResNum1, ResNum2, sResNum1, sResNum2;
      int Sitenum1, Sitenum2;
      short Model1, Model2;
  
      char __far * endptr;
       
  
      /* Load column numbers for the tags we have */
      if ((!cif_find_column(cif,"conn_type_id")))
        cif_column_number(cif,&col_conn_type_id);
      if ((!cif_find_column(cif,"ptnr1_label_alt_id")))
        cif_column_number(cif,&col_ptnr1_label_alt_id);
      if ((!cif_find_column(cif,"ptnr1_label_asym_id")))
        cif_column_number(cif,&col_ptnr1_label_asym_id);
      if ((!cif_find_column(cif,"ptnr1_label_atom_id")))
        cif_column_number(cif,&col_ptnr1_label_atom_id);
      if ((!cif_find_column(cif,"ptnr1_label_comp_id")))
        cif_column_number(cif,&col_ptnr1_label_comp_id);
      if ((!cif_find_column(cif,"ptnr1_label_seq_id")))
        cif_column_number(cif,&col_ptnr1_label_seq_id);
      if ((!cif_find_column(cif,"ptnr1_label_model_id")) ||
        (!cif_find_column(cif,"pdb2cif_ptnr1_label_model_id")))
        cif_column_number(cif,&col_ptnr1_label_model_id);
      if ((!cif_find_column(cif,"ptnr1_atom_site_id")) ||
        (!cif_find_column(cif,"pdb2cif_ptnr1_atom_site_id")))
        cif_column_number(cif,&col_ptnr1_atom_site_id);
      if ((!cif_find_column(cif,"ptnr1_symmetry")))
        cif_column_number(cif,&col_ptnr1_symmetry);
      if ((!cif_find_column(cif,"ptnr1_auth_alt_id")))
        cif_column_number(cif,&col_ptnr1_auth_alt_id);
      if ((!cif_find_column(cif,"ptnr1_auth_asym_id")))
        cif_column_number(cif,&col_ptnr1_auth_asym_id);
      if ((!cif_find_column(cif,"ptnr1_auth_atom_id")))
        cif_column_number(cif,&col_ptnr1_auth_atom_id);
      if ((!cif_find_column(cif,"ptnr1_auth_comp_id")))
        cif_column_number(cif,&col_ptnr1_auth_comp_id);
      if ((!cif_find_column(cif,"ptnr1_auth_seq_id")))
        cif_column_number(cif,&col_ptnr1_auth_seq_id);

      if ((!cif_find_column(cif,"ptnr2_label_alt_id")))
        cif_column_number(cif,&col_ptnr2_label_alt_id);
      if ((!cif_find_column(cif,"ptnr2_label_asym_id")))
        cif_column_number(cif,&col_ptnr2_label_asym_id);
      if ((!cif_find_column(cif,"ptnr2_label_atom_id")))
        cif_column_number(cif,&col_ptnr2_label_atom_id);
      if ((!cif_find_column(cif,"ptnr2_label_comp_id")))
        cif_column_number(cif,&col_ptnr2_label_comp_id);
      if ((!cif_find_column(cif,"ptnr2_label_seq_id")))
        cif_column_number(cif,&col_ptnr2_label_seq_id);
      if ((!cif_find_column(cif,"ptnr2_label_model_id")) ||
        (!cif_find_column(cif,"pdb2cif_ptnr2_label_model_id")))
        cif_column_number(cif,&col_ptnr2_label_model_id);
      if ((!cif_find_column(cif,"ptnr2_atom_site_id")) ||
        (!cif_find_column(cif,"pdb2cif_ptnr2_atom_site_id")))
        cif_column_number(cif,&col_ptnr2_atom_site_id);
      if ((!cif_find_column(cif,"ptnr2_symmetry")))
        cif_column_number(cif,&col_ptnr2_symmetry);
      if ((!cif_find_column(cif,"ptnr2_auth_alt_id")))
        cif_column_number(cif,&col_ptnr2_auth_alt_id);
      if ((!cif_find_column(cif,"ptnr2_auth_asym_id")))
        cif_column_number(cif,&col_ptnr2_auth_asym_id);
      if ((!cif_find_column(cif,"ptnr2_auth_atom_id")))
        cif_column_number(cif,&col_ptnr2_auth_atom_id);
      if ((!cif_find_column(cif,"ptnr2_auth_comp_id")))
        cif_column_number(cif,&col_ptnr2_auth_comp_id);
      if ((!cif_find_column(cif,"ptnr2_auth_seq_id")))
        cif_column_number(cif,&col_ptnr2_auth_seq_id);

      /* Process STRUCT_CONN rows, one at a time */

      cif_count_rows(cif,(unsigned int __far *)&rows);
      for (rownum = 0; rownum < rows; ++rownum){

        cif_select_row(cif,rownum);
        ReadCIFstr(cif,col_conn_type_id,CType,6);
        if (ReadCIFstr(cif,col_ptnr1_label_alt_id,Alt1,1))
          ReadCIFstr(cif,col_ptnr1_auth_alt_id,Alt1,1);
        if (ReadCIFstr(cif,col_ptnr1_label_asym_id,Asym1,1))
          ReadCIFstr(cif,col_ptnr1_auth_asym_id,Asym1,1);
        if (ReadCIFstr(cif,col_ptnr1_label_atom_id,AtomName1,12))
          ReadCIFstr(cif,col_ptnr1_auth_atom_id,AtomName1,12);
        if (ReadCIFstr(cif,col_ptnr1_label_comp_id,CompId1,3))
          ReadCIFstr(cif,col_ptnr1_auth_comp_id,CompId1,3);
        if (CompId1[0] &&strlen(CompId1)<3) RightJustify(CompId1,3);
        if (CompId1[0] &&strlen(CompId1)<(size_t)3) RightJustify(CompId1,3);
        ReadCIFstr(cif,col_ptnr1_label_model_id,ModelId1,5);
        ReadCIFstr(cif,col_ptnr1_atom_site_id,SiteId1,6);
        ReadCIFstr(cif,col_ptnr1_symmetry,Symm1,7);


        if (ReadCIFstr(cif,col_ptnr2_label_alt_id,Alt2,1))
          ReadCIFstr(cif,col_ptnr2_auth_alt_id,Alt2,1);
        if (ReadCIFstr(cif,col_ptnr2_label_asym_id,Asym2,1))
          ReadCIFstr(cif,col_ptnr2_auth_asym_id,Asym2,1);
        if (ReadCIFstr(cif,col_ptnr2_label_atom_id,AtomName2,12))
          ReadCIFstr(cif,col_ptnr2_auth_atom_id,AtomName2,12);
        if (ReadCIFstr(cif,col_ptnr2_label_comp_id,CompId2,3))
          ReadCIFstr(cif,col_ptnr2_auth_comp_id,CompId2,3);
        if (CompId2[0] &&strlen(CompId2)<3) RightJustify(CompId2,3);
        if (CompId2[0] &&strlen(CompId2)<(size_t)3) RightJustify(CompId2,3);
        ReadCIFstr(cif,col_ptnr2_label_model_id,ModelId2,5);
        ReadCIFstr(cif,col_ptnr2_atom_site_id,SiteId2,6);
        ReadCIFstr(cif,col_ptnr2_symmetry,Symm2,7);

        Icode1 = Icode2 = '\0';
        ResNum1 = ResNum2 = -9999;
        if (SeqId1[0]){
            ResNum1 = (int)strtol(SeqId1, 
              (char __far * __far *)&endptr, 10);
            Icode1 = ' ';
            if (*endptr != '\0') Icode1 = *endptr;
        }
        if (SeqId2[0]){
            ResNum2 = (int)strtol(SeqId2, 
              (char __far * __far *)&endptr, 10);
            Icode2 = ' ';
            if (*endptr != '\0') Icode2 = *endptr;
        }

        sIcode1 = sIcode2 = '\0';
        sResNum1 = sResNum2 = -9999;
        if(!ReadCIFstr(cif,col_ptnr1_label_seq_id,SeqId1,5))
        if (SeqId1[0]){
            sResNum1 = (int)strtol(SeqId1, 
              (char __far * __far *)&endptr, 10);
            sIcode1 = ' ';
            if (*endptr != '\0') sIcode1 = *endptr;
        }
        if(!ReadCIFstr(cif,col_ptnr2_label_seq_id,SeqId2,5))
        if (SeqId2[0]){
            sResNum2 = (int)strtol(SeqId2, 
              (char __far * __far *)&endptr, 10);
            sIcode2 = ' ';
            if (*endptr != '\0') sIcode2 = *endptr;
        }

        Sitenum1 = Sitenum2 =0;
        if (SiteId1[0]) {
            Sitenum1 = (int)strtol(SiteId1, 
              (char __far * __far *)&endptr, 10);
        }
        if (SiteId2[0]) {
            Sitenum2 = (int)strtol(SiteId2, 
              (char __far * __far *)&endptr, 10);
        }

        Model1 = Model2 =0;
        if (ModelId1[0]) {
            Model1 = (short) strtol(ModelId1, 
              (char __far * __far *)&endptr, 10);
        }
        if (ModelId2[0]) {
            Model2 = (short) strtol(ModelId2, 
              (char __far * __far *)&endptr, 10);
        }
        ConvertNames(NULL,AtomName1);
        ConvertNames(NULL,AtomName2);

        ApplyBondInfo(CompId1, Asym1[0], ResNum1, Icode1, sResNum1, sIcode1,
                          AtomName1, Sitenum1, Alt1[0], Model1, Symm1,
                          CompId2, Asym2[0], ResNum2, Icode2, sResNum2, 
                          sIcode2, AtomName2, Sitenum2, Alt2[0], Model2, 
                          Symm2, CType);
        ApplyBondInfo(CompId2, Asym2[0], ResNum2, Icode2, sResNum2, sIcode2,
                          AtomName2, Sitenum2, Alt2[0], Model2, Symm2,
                          CompId1, Asym1[0], ResNum1, Icode1, sResNum1,
                          sIcode1, AtomName1, Sitenum1, Alt1[0], Model1, 
                          Symm1, CType);
      }
      if (NullBonds) WriteString("Warning: Null bonds in STRUCT_CONN!\n");

    }

    NullBonds = 0;
    if (!cif_findtag(cif,"_geom_bond.atom_site_id_1") ||
     !cif_findtag(cif,"_geom_bond_atom_site_label_1") ){
      unsigned int 
        col_atom_site_id_1=-1,           col_label_alt_id_1=-1,
        col_label_atom_id_1=-1,          col_label_comp_id_1=-1,
        col_label_seq_id_1=-1,           col_label_asym_id_1=-1,
        col_symmetry_1=-1,               col_auth_alt_id_1=-1,
        col_auth_atom_id_1=-1,           col_auth_asym_id_1=-1,
        col_auth_comp_id_1=-1,           col_auth_seq_id_1=-1, 

        col_atom_site_id_2=-1,           col_label_alt_id_2=-1,
        col_label_atom_id_2=-1,          col_label_comp_id_2=-1,
        col_label_seq_id_2=-1,           col_label_asym_id_2=-1,
        col_symmetry_2=-1,               col_auth_alt_id_2=-1,
        col_auth_atom_id_2=-1,           col_auth_asym_id_2=-1,
        col_auth_comp_id_2=-1,           col_auth_seq_id_2=-1, 

        col_dist=-1,                     col_dist_esd=-1;

      unsigned int rows, rownum;
      char __far Alt1[2], AtomName1[13], Asym1[2], CompId1[4]="   ", 
        SeqId1[6], ModelId1[6], SiteId1[7], oidstr1[6], Symm1[8], 
        Alt2[2], AtomName2[13], Asym2[2], CompId2[4]="   ", 
        SeqId2[6], ModelId2[6], SiteId2[7], oidstr2[6], Symm2[8];
      char Icode1, Icode2, sIcode1, sIcode2;
      int ResNum1, ResNum2, sResNum1, sResNum2;
      int Sitenum1, Sitenum2;
      short Model1, Model2;
  
      char __far * endptr;
       
  
      /* Load column numbers for the tags we have */
      if ((!cif_find_column(cif,CIF_PRFX "atom_site_id_1")) ||
        (!cif_find_column(cif,"geom_bond_atom_site_label_1")))
        cif_column_number(cif,&col_atom_site_id_1);
      if ((!cif_find_column(cif,CIF_PRFX "atom_site_label_alt_id_1")))
        cif_column_number(cif,&col_label_alt_id_1);
      if ((!cif_find_column(cif,CIF_PRFX "atom_site_label_atom_id_1")))
        cif_column_number(cif,&col_label_atom_id_1);
      if ((!cif_find_column(cif,CIF_PRFX "atom_site_label_comp_id_1")))
        cif_column_number(cif,&col_label_comp_id_1);
      if ((!cif_find_column(cif,CIF_PRFX "atom_site_label_seq_id_1")))
        cif_column_number(cif,&col_label_seq_id_1);
      if ((!cif_find_column(cif,CIF_PRFX "atom_site_label_asym_id_1")))
        cif_column_number(cif,&col_label_asym_id_1);
      if ((!cif_find_column(cif,"site_symmetry_1")) ||
        (!cif_find_column(cif,"geom_bond_site_symmetry_1")))
        cif_column_number(cif,&col_symmetry_1);
      if ((!cif_find_column(cif,CIF_PRFX "atom_site_auth_atom_id_1")))
        cif_column_number(cif,&col_auth_atom_id_1);
      if ((!cif_find_column(cif,CIF_PRFX "atom_site_auth_asym_id_1")))
        cif_column_number(cif,&col_auth_asym_id_1);
      if ((!cif_find_column(cif,CIF_PRFX "atom_site_auth_comp_id_1")))
        cif_column_number(cif,&col_auth_comp_id_1);
      if ((!cif_find_column(cif,CIF_PRFX "atom_site_auth_seq_id_1")))
        cif_column_number(cif,&col_auth_seq_id_1);

      if ((!cif_find_column(cif,CIF_PRFX "atom_site_id_2")) ||
        (!cif_find_column(cif,"geom_bond_atom_site_label_2")))
        cif_column_number(cif,&col_atom_site_id_2);
      if ((!cif_find_column(cif,CIF_PRFX "atom_site_label_alt_id_2")))
        cif_column_number(cif,&col_label_alt_id_2);
      if ((!cif_find_column(cif,CIF_PRFX "atom_site_label_atom_id_2")))
        cif_column_number(cif,&col_label_atom_id_2);
      if ((!cif_find_column(cif,CIF_PRFX "atom_site_label_comp_id_2")))
        cif_column_number(cif,&col_label_comp_id_2);
      if ((!cif_find_column(cif,CIF_PRFX "atom_site_label_seq_id_2")))
        cif_column_number(cif,&col_label_seq_id_2);
      if ((!cif_find_column(cif,CIF_PRFX "atom_site_label_asym_id_2")))
        cif_column_number(cif,&col_label_asym_id_2);
      if ((!cif_find_column(cif,"site_symmetry_2")) ||
        (!cif_find_column(cif,"geom_bond_site_symmetry_2")))
        cif_column_number(cif,&col_symmetry_2);
      if ((!cif_find_column(cif,CIF_PRFX "atom_site_auth_atom_id_2")))
        cif_column_number(cif,&col_auth_atom_id_2);
      if ((!cif_find_column(cif,CIF_PRFX "atom_site_auth_asym_id_2")))
        cif_column_number(cif,&col_auth_asym_id_2);
      if ((!cif_find_column(cif,CIF_PRFX "atom_site_auth_comp_id_2")))
        cif_column_number(cif,&col_auth_comp_id_2);
      if ((!cif_find_column(cif,CIF_PRFX "atom_site_auth_seq_id_2")))
        cif_column_number(cif,&col_auth_seq_id_2);

      if ((!cif_find_column(cif,"dist")) ||
        (!cif_find_column(cif,"geom_bond_distance")))
        cif_column_number(cif,&col_dist);
      if ((!cif_find_column(cif,"dist_esd")))
        cif_column_number(cif,&col_dist_esd);


      /* Process GEOM_BOND rows, one at a time */

      cif_count_rows(cif,(unsigned int __far *)&rows);
      for (rownum = 0; rownum < rows; ++rownum){

        cif_select_row(cif,rownum);
        if (ReadCIFstr(cif,col_label_alt_id_1,Alt1,1))
          ReadCIFstr(cif,col_auth_alt_id_1,Alt1,1);
        if (ReadCIFstr(cif,col_label_asym_id_1,Asym1,1))
          ReadCIFstr(cif,col_auth_asym_id_1,Asym1,1);
        if (ReadCIFstr(cif,col_label_atom_id_1,AtomName1,12))
          ReadCIFstr(cif,col_auth_atom_id_1,AtomName1,12);
        if (ReadCIFstr(cif,col_label_comp_id_1,CompId1,3))
          ReadCIFstr(cif,col_auth_comp_id_1,CompId1,3);
        if (CompId1[0] &&strlen(CompId1)<3) RightJustify(CompId1,3);
        if (CompId1[0] &&strlen(CompId1)<(size_t)3) RightJustify(CompId1,3);
        ReadCIFstr(cif,col_atom_site_id_1,SiteId1,6);
        strncpy(oidstr1,SiteId1,5);
        ReadCIFstr(cif,col_symmetry_1,Symm1,7);


        if (ReadCIFstr(cif,col_label_alt_id_2,Alt2,1))
          ReadCIFstr(cif,col_auth_alt_id_2,Alt2,1);
        if (ReadCIFstr(cif,col_label_asym_id_2,Asym2,1))
          ReadCIFstr(cif,col_auth_asym_id_2,Asym2,1);
        if (ReadCIFstr(cif,col_label_atom_id_2,AtomName2,12))
          ReadCIFstr(cif,col_auth_atom_id_2,AtomName2,12);
        if (ReadCIFstr(cif,col_label_comp_id_2,CompId2,3))
          ReadCIFstr(cif,col_auth_comp_id_2,CompId2,3);
        if (CompId1[0] &&strlen(CompId2)<3) RightJustify(CompId2,3);
        if (CompId1[0] &&strlen(CompId2)<(size_t)3) RightJustify(CompId2,3);
        ReadCIFstr(cif,col_atom_site_id_2,SiteId2,6);
        strncpy(oidstr2,SiteId2,5);
        ReadCIFstr(cif,col_symmetry_2,Symm2,7);

        if (AtomName1[0]=='\0')  strncpy(AtomName1,oidstr1,4);
        if (AtomName2[0]=='\0')  strncpy(AtomName2,oidstr2,4);

        Icode1 = Icode2 = '\0';
        ResNum1 = ResNum2 = -9999;
        if (SeqId1[0]){
            ResNum1 = (int)strtol(SeqId1, 
              (char __far * __far *)&endptr, 10);
            Icode1 = ' ';
            if (*endptr != '\0') Icode1 = *endptr;
        }
        if (SeqId2[0]){
            ResNum2 = (int)strtol(SeqId2, 
              (char __far * __far *)&endptr, 10);
            Icode2 = ' ';
            if (*endptr != '\0') Icode2 = *endptr;
        }

        sIcode1 = sIcode2 = '\0';
        sResNum1 = sResNum2 = -9999;
        if(!ReadCIFstr(cif,col_label_seq_id_1,SeqId1,5))
        if (SeqId1[0]){
            sResNum1 = (int)strtol(SeqId1, 
              (char __far * __far *)&endptr, 10);
            sIcode1 = ' ';
            if (*endptr != '\0') sIcode1 = *endptr;
        }
        if(!ReadCIFstr(cif,col_label_seq_id_1,SeqId2,5))
        if (SeqId2[0]){
            sResNum2 = (int)strtol(SeqId2, 
              (char __far * __far *)&endptr, 10);
            sIcode2 = ' ';
            if (*endptr != '\0') sIcode2 = *endptr;
        }

        Sitenum1 = Sitenum2 =0;
        if (SiteId1[0]) {
            Sitenum1 = (int)strtol(SiteId1, 
              (char __far * __far *)&endptr, 10);
        }
        if (SiteId2[0]) {
            Sitenum2 = (int)strtol(SiteId2, 
              (char __far * __far *)&endptr, 10);
        }

        Model1 = Model2 =0;
        if (ModelId1[0]) {
            Model1 = (short) strtol(ModelId1, 
              (char __far * __far *)&endptr, 10);
        }
        if (ModelId2[0]) {
            Model2 = (short) strtol(ModelId2, 
              (char __far * __far *)&endptr, 10);
        }
        ConvertNames(NULL,AtomName1);
        ConvertNames(NULL,AtomName2);

        ApplyBondInfo(CompId1, Asym1[0], ResNum1, Icode1, sResNum1, sIcode1,
                          AtomName1, Sitenum1, Alt1[0], Model1, Symm1,
                          CompId2, Asym2[0], ResNum2, Icode2, sResNum2, 
                          sIcode2, AtomName2, Sitenum2, Alt2[0], Model2, 
                          Symm2, NULL);
        ApplyBondInfo(CompId2, Asym2[0], ResNum2, Icode2, sResNum2, sIcode2,
                          AtomName2, Sitenum2, Alt2[0], Model2, Symm2,
                          CompId1, Asym1[0], ResNum1, Icode1, sResNum1,
                          sIcode1, AtomName1, Sitenum1, Alt1[0], Model1, 
                          Symm1, NULL);
      }
      if (NullBonds) WriteString("Warning: Null bonds in GEOM_BOND!\n");

    }

    /* Process STRUCT_CONF (Helices and Turns) */
    /* And STRUCT_SHEET_RANGE (Sheets)         */

    {
    int ipass;

    for (ipass = 0; ipass < 2; ipass++) {
      
    if (((ipass == 0) && !cif_findtag(cif,"_struct_conf.id")) ||
      ((ipass == 1) && !cif_findtag(cif,"_struct_sheet_range.id"))){
      unsigned int 
        col_id=-1,                     col_conf_type_id=-1,
        col_beg_label_asym_id=-1, 
        col_beg_label_comp_id=-1,
        col_beg_label_seq_id=-1,
        col_beg_auth_asym_id=-1, 
        col_beg_auth_comp_id=-1,
        col_beg_auth_seq_id=-1,
        col_end_label_asym_id=-1, 
        col_end_label_comp_id=-1,
        col_end_label_seq_id=-1,
        col_end_auth_asym_id=-1, 
        col_end_auth_comp_id=-1,
        col_end_auth_seq_id=-1;
      unsigned int rows, rownum;
      char __far CType[20];
      char __far Asym1[2], CompId1[4]="   ", 
        SeqId1[6],  
        Asym2[2], CompId2[4]="   ", 
        SeqId2[6] ;
      char Icode1, Icode2, sIcode1, sIcode2;
      int ResNum1, ResNum2, sResNum1, sResNum2;
  
      char __far * endptr;
      int i;
       
  
      /* Load column numbers for the tags we have */
      if ((!cif_find_column(cif,"id")))
        cif_column_number(cif,&col_id);
      if ((ipass==0)&&(!cif_find_column(cif,"conf_type_id")))
        cif_column_number(cif,&col_conf_type_id);
      if ((!cif_find_column(cif,"beg_label_asym_id")))
        cif_column_number(cif,&col_beg_label_asym_id);
      if ((!cif_find_column(cif,"beg_label_comp_id")))
        cif_column_number(cif,&col_beg_label_comp_id);
      if ((!cif_find_column(cif,"beg_label_seq_id")))
        cif_column_number(cif,&col_beg_label_seq_id);
      if ((!cif_find_column(cif,"beg_auth_asym_id")))
        cif_column_number(cif,&col_beg_auth_asym_id);
      if ((!cif_find_column(cif,"beg_auth_comp_id")))
        cif_column_number(cif,&col_beg_auth_comp_id);
      if ((!cif_find_column(cif,"beg_auth_seq_id")))
        cif_column_number(cif,&col_beg_auth_seq_id);

      if ((!cif_find_column(cif,"end_label_asym_id")))
        cif_column_number(cif,&col_end_label_asym_id);
      if ((!cif_find_column(cif,"end_label_comp_id")))
        cif_column_number(cif,&col_end_label_comp_id);
      if ((!cif_find_column(cif,"end_label_seq_id")))
        cif_column_number(cif,&col_end_label_seq_id);
      if ((!cif_find_column(cif,"end_auth_asym_id")))
        cif_column_number(cif,&col_end_auth_asym_id);
      if ((!cif_find_column(cif,"end_auth_comp_id")))
        cif_column_number(cif,&col_end_auth_comp_id);
      if ((!cif_find_column(cif,"end_auth_seq_id")))
        cif_column_number(cif,&col_end_auth_seq_id);

      /* Process STRUCT_CONF rows, one at a time */

      cif_count_rows(cif,(unsigned int __far *)&rows);
      for (rownum = 0; rownum < rows; ++rownum){

        cif_select_row(cif,rownum);
        if (ipass == 0) {
          ReadCIFstr(cif,col_conf_type_id,CType,19);
        } else {
          strcpy(CType,"sheet");
        }
        if (ReadCIFstr(cif,col_beg_label_asym_id,Asym1,1))
          ReadCIFstr(cif,col_beg_auth_asym_id,Asym1,1);
        if (ReadCIFstr(cif,col_beg_label_comp_id,CompId1,3))
          ReadCIFstr(cif,col_beg_auth_comp_id,CompId1,3);
        if (CompId1[0] &&(i=(int)strlen(CompId1))<3) RightJustify(CompId1,3);
        ReadCIFstr(cif,col_beg_auth_seq_id,SeqId1,5);

        if (ReadCIFstr(cif,col_end_label_asym_id,Asym2,1))
          ReadCIFstr(cif,col_end_auth_asym_id,Asym2,1);
        if (ReadCIFstr(cif,col_end_label_comp_id,CompId2,3))
          ReadCIFstr(cif,col_end_auth_comp_id,CompId2,3);
        if (CompId2[0] &&(i=(int)strlen(CompId2))<3) RightJustify(CompId2,3);
        ReadCIFstr(cif,col_end_auth_seq_id,SeqId2,5);

        Icode1 = Icode2 = '\0';
        ResNum1 = ResNum2 = -9999;
        if (SeqId1[0]){
            ResNum1 = (int)strtol(SeqId1, 
              (char __far * __far *)&endptr, 10);
            Icode1 = ' ';
            if (*endptr != '\0') Icode1 = *endptr;
        }
        if (SeqId2[0]){
            ResNum2 = (int)strtol(SeqId2, 
              (char __far * __far *)&endptr, 10);
            Icode2 = ' ';
            if (*endptr != '\0') Icode2 = *endptr;
        }

        sIcode1 = sIcode2 = '\0';
        sResNum1 = sResNum2 = -9999;
        if(!ReadCIFstr(cif,col_beg_label_seq_id,SeqId1,5))
        if (SeqId1[0]){
            sResNum1 = (int)strtol(SeqId1, 
              (char __far * __far *)&endptr, 10);
            sIcode1 = ' ';
            if (*endptr != '\0') sIcode1 = *endptr;
        }
        if(!ReadCIFstr(cif,col_end_label_seq_id,SeqId2,5))
        if (SeqId2[0]){
            sResNum2 = (int)strtol(SeqId2, 
              (char __far * __far *)&endptr, 10);
            sIcode2 = ' ';
            if (*endptr != '\0') sIcode2 = *endptr;
        }


        ApplyConfInfo(CompId1, Asym1[0], ResNum1, Icode1, sResNum1, sIcode1,
                      CompId2, Asym2[0], ResNum2, Icode2, sResNum2, sIcode2,
                      CType);
      }

    }
    }
    }
    
    
    if ((!cif_findtag(cif,"_chem_comp_atom.model_Cartn_x")) ||
      (!cif_findtag(cif,"_chem_comp_atom.model_Cartn_x_ideal"))||
      (!cif_findtag(cif,"_chem_comp_atom.pdbx_model_Cartn_x_ideal"))){
        unsigned int 
        col_comp_id=-1,
        col_atom_id=-1,
        col_type_symbol=-1,
        col_substruct_code=-1,
        col_model_cartn_x=-1, col_model_cartn_y=-1, col_model_cartn_z=-1,
        col_ideal_cartn_x=-1, col_ideal_cartn_y=-1, col_ideal_cartn_z=-1,
        col_ordinal;
        int ipass;
        unsigned int rows, rownum;
        char __far label_atom_id[5], idstr[10], 
            label_comp_id[4]="   ",
            olabel_comp_id[4]="   ", label_asym_id[2]=" ",
            type_symbol[5];
        double cartn_x, cartn_y, cartn_z;
        int heta;
        register RAtom __far *ptr;
        int oNMRModel;
        int seroffset;
        
        /*  _chem_comp_atom.comp_id
            _chem_comp_atom.alt_comp_id
            _chem_comp_atom.pdbx_alt_comp_id
            
            _chem_comp_atom.atom_id
            _chem_comp_atom.alt_atom_id
            _chem_comp_atom.pdbx_alt_atom_id
            
            _chem_comp_atom.type_symbol
            _chem_comp_atom.substruct_code
            
            _chem_comp_atom.model_Cartn_x
            _chem_comp_atom.model_Cartn_y
            _chem_comp_atom.model_Cartn_z
            
            _chem_comp_atom.model_Cartn_x_ideal
            _chem_comp_atom.model_Cartn_y_ideal
            _chem_comp_atom.model_Cartn_z_ideal
            
            _chem_comp_atom.pdbx_model_Cartn_x_ideal
            _chem_comp_atom.pdbx_model_Cartn_y_ideal
            _chem_comp_atom.pdbx_model_Cartn_z_ideal
            
            _chem_comp_atom.ordinal
            _chem_comp_atom.pdbx_ordinal
            
            */
        
        
        
        /* Load column numbers for the tags we have */
        if ((!cif_find_column(cif,"comp_id"))||
            (!cif_find_column(cif,"pdbx_alt_comp_id"))||
            (!cif_find_column(cif,"alt_comp_id")))
            cif_column_number(cif,&col_comp_id);
        
        if ((!cif_find_column(cif,"atom_id"))||
            (!cif_find_column(cif,"pdbx_alt_atom_id"))||
            (!cif_find_column(cif,"alt_atom_id")))
            cif_column_number(cif,&col_atom_id);
        
        if ((!cif_find_column(cif,"type_symbol")))
            cif_column_number(cif,&col_type_symbol);
        
        if ((!cif_find_column(cif,"substruct_code")))
            cif_column_number(cif,&col_substruct_code);
        
        if ((!cif_find_column(cif,"model_cartn_x")))
            cif_column_number(cif,&col_model_cartn_x);
        if ((!cif_find_column(cif,"model_cartn_y")))
            cif_column_number(cif,&col_model_cartn_y);
        if ((!cif_find_column(cif,"model_cartn_z")))
            cif_column_number(cif,&col_model_cartn_z);
        
        if ((!cif_find_column(cif,"model_cartn_x_ideal"))||
            (!cif_find_column(cif,"pdbx_model_cartn_x_ideal")))
            cif_column_number(cif,&col_ideal_cartn_x);
        if ((!cif_find_column(cif,"model_cartn_y_ideal"))||
            (!cif_find_column(cif,"pdbx_model_cartn_y_ideal")))
            cif_column_number(cif,&col_ideal_cartn_y);
        if ((!cif_find_column(cif,"model_cartn_z_ideal"))||
            (!cif_find_column(cif,"pdbx_model_cartn_z_ideal")))
            cif_column_number(cif,&col_ideal_cartn_z);
        
        
        if ((!cif_find_column(cif,"ordinal"))||
            (!cif_find_column(cif,"pdbx_ordinal")))
            cif_column_number(cif,&col_ordinal);
        
        
        for (ipass=0; ipass< 2; ipass++) {

            oNMRModel = NMRModel;
            ConnectAtom = (void __far*)0;
            CurGroup = (void __far*)0;
            CurChain = (void __far*)0;
        
            strncpy(olabel_comp_id,"   ",4);
        
            
            seroffset = 0;
            if (maxsernum >= minsernum)  {
                NMRModel = maxnmrmodel;
                seroffset=maxsernum+1;
            } else {
            	NMRModel = 0;
            }
            
            if (ipass==0) {
                if (cif_findtag(cif,"_chem_comp_atom.model_Cartn_x")
                  || col_model_cartn_x == (unsigned int)(-1) 
                  || col_model_cartn_y == (unsigned int)(-1) 
                  || col_model_cartn_z == (unsigned int)(-1)  )
                     break;
            } else {
                if((cif_findtag(cif,"_chem_comp_atom.model_Cartn_x_ideal")&&
                  cif_findtag(cif,"_chem_comp_atom.pdbx_model_Cartn_x_ideal"))
                  || col_ideal_cartn_x == (unsigned int)(-1) 
                  || col_ideal_cartn_y == (unsigned int)(-1) 
                  || col_ideal_cartn_z == (unsigned int)(-1)  )
                    break;
            }
            
            /* Process atom_site rows, one at a time */
            
            cif_count_rows(cif,(unsigned int __far *)&rows);
            for (rownum = 0; rownum < rows; ++rownum) {
                cif_select_row(cif,rownum);
                heta = False;
                ReadCIFstr(cif,col_atom_id,label_atom_id,4);
                ReadCIFstr(cif,col_type_symbol,type_symbol,4);
                ReadCIFstr(cif,col_comp_id,label_comp_id,3);
                if (strlen(label_comp_id)<(size_t)3) RightJustify(label_comp_id,3);
                strcpy(label_asym_id," ");
                {
                    int seqnum, sseqnum, icode, sicode;
                    if (strncasecmp(olabel_comp_id,label_comp_id,4)) {
                        oNMRModel = NMRModel;
                        ConnectAtom = (void __far*)0;
                        CurGroup = (void __far*)0;
                        CurChain = (void __far*)0;
                        NMRModel = ++maxnmrmodel;
                        strncpy(olabel_comp_id,label_comp_id,4);
                    }
                    
                    seqnum = sseqnum = 1;
                    icode = sicode = ' ';
                    if ( !CurGroup || (CurGroup->serno!=seqnum)
                         || (CurChain->ident!=label_asym_id[0])
                         || (PDBInsert != icode) ) {
                        PDBInsert = icode;
                        if( !CurChain || (CurChain->ident!=label_asym_id[0] )) {
                            ConnectAtom = (RAtom __far*)0;
                            CreateChain (label_asym_id[0]);
                        }
                        CreateGroup( GroupPool );
                        CurGroup->refno = FindResNo(label_comp_id);
                        CurGroup->serno = seqnum;
                        CurGroup->insert = icode;
                        CurGroup->sserno = sseqnum;
                        CurGroup->sinsert = sicode;
                        ProcessGroup (heta);              
                    }
                }
                ptr = CreateAtom();
                ReadCIFstr(cif,col_ordinal,idstr,10);
                if (idstr[0] == '\0') sprintf(idstr,"%d",rownum+1);
                {
                    char __far * endptr;
                    ptr->serno = seroffset+(int)strtol(idstr, (char __far * __far *)&endptr,10);
                    if (*endptr != '\0') ptr->serno = seroffset+rownum+1;
                    if (ptr->serno > maxsernum) maxsernum = ptr->serno;
                    if (ptr->serno < minsernum) minsernum = ptr->serno;
                } 
                ptr->altl = ' ';
                ptr->model = NMRModel;
                cartn_x = 0.;
                cartn_y = 0.;
                cartn_z = 0.;
                if (ipass==0) {
                    ReadCIFRowValue(cif,  (double __far *)&cartn_x, col_model_cartn_x);
                    ReadCIFRowValue(cif,  (double __far *)&cartn_y, col_model_cartn_y);
                    ReadCIFRowValue(cif,  (double __far *)&cartn_z, col_model_cartn_z);
                } else {
                    ReadCIFRowValue(cif,  (double __far *)&cartn_x, col_ideal_cartn_x);
                    ReadCIFRowValue(cif,  (double __far *)&cartn_y, col_ideal_cartn_y);
                    ReadCIFRowValue(cif,  (double __far *)&cartn_z, col_ideal_cartn_z);
                    
                }
                ptr->xorg = (Long)(cartn_x*250.);
                ptr->yorg = (Long)(cartn_y*250.);
                ptr->zorg = -(Long)(cartn_z*250.);
                ptr->xtrl = (short)(10000.0*cartn_x-40.0*(double)ptr->xorg);
                ptr->ytrl = (short)(10000.0*cartn_y-40.0*(double)ptr->yorg);
                ptr->ztrl = (short)(-10000.0*cartn_z-40.0*(double)ptr->zorg);
                
                if (label_atom_id[0]=='\0')  strncpy(label_atom_id,idstr,4);
                {
                    int i, laid, lat;
                    char __far tmparg[5];
                    
                    lat = (int)strlen(type_symbol);
                    if (lat > 1) {
                        if ((type_symbol[lat-1] =='+') || (type_symbol[lat-1] == '-')) {
                            if (strchr("0123456789",type_symbol[lat-2])) {
                                lat -= 2;
                            } else {
                                lat--;
                            }
                        }
                    }
                    laid = (int)strlen(label_atom_id);
                    for (i = laid; i < 5; i++) label_atom_id[i] = '\0';
                    strcpy(tmparg,label_atom_id);
                    if ((label_atom_id[0] < '0') || (label_atom_id[0] > '9') ){
                        if (laid>0 && laid < 4 && lat > 0 ) {
                            if ((strncmp(label_atom_id, type_symbol, lat) == 0) &&
                                lat ==1) {
                                label_atom_id[0] = ' ';
                                strcpy(label_atom_id+1,tmparg);
                            } 
                        } else {
                            if ((laid > 0) && (laid < 4)) {
                                label_atom_id[0] = ' ';
                                strcpy(label_atom_id+1,tmparg);
                            }
                        }
                    }
                    if (lat == 1) {
                        strncpy(tmparg,type_symbol,4);
                        type_symbol[0] = ' ';
                        strncpy(type_symbol+1,tmparg,3);
                        type_symbol[4] = '\0';
                    }
                    
                    if (label_atom_id[3] == '\0') label_atom_id[3] = ' ';
                    if (label_atom_id[2] == '\0') label_atom_id[2] = ' ';
                    ptr->refno = ComplexAtomType(label_atom_id);
                    
                }
                
                
                ProcessAtom(ptr);
                
            }
            ConnectAtom = (void __far*)0;
            CurGroup = (void __far*)0;
            CurChain = (void __far*)0;
            
            
            /* Process Bonds */
            NullBonds = 0;
            if (!cif_findtag(cif,"_chem_comp_bond.ordinal")||
                !cif_findtag(cif,"_chem_comp_bond.pdbx_ordinal")) {
                unsigned int
                col_comp_id,
                col_atom_id_1=-1, col_atom_id_2=-1,
                col_bond_value=-1,col_ordinal=-1;
                unsigned int rows, rownum;
                char __far atom_id_1[10],atom_id_2[10],
                    label_comp_id[4], bond_value[6];
                
                int bvalue;
                Long id1,id2; 
                
                
                if ((!cif_find_column(cif,"comp_id")) )
                    cif_column_number(cif,&col_comp_id);
                
                if ((!cif_find_column(cif,"atom_id_1")) )
                    cif_column_number(cif,&col_atom_id_1);
                
                if ((!cif_find_column(cif,"atom_id_2")) )
                    cif_column_number(cif,&col_atom_id_2);
                
                if ((!cif_find_column(cif,"value_order")) )
                    cif_column_number(cif,&col_bond_value);
                
                if ((!cif_find_column(cif,"ordinal"))||
                    (!cif_find_column(cif,"pdbx_ordinal")) )
                    cif_column_number(cif,&col_ordinal);
                
                
                cif_count_rows(cif,(unsigned int __far *)&rows);
                rownum=rows;
                
                for (rownum = 0; rownum < rows; ++rownum) {
                    cif_select_row(cif,rownum);
                    
                    ReadCIFstr(cif,col_comp_id, label_comp_id,3);
                    ReadCIFstr(cif,col_atom_id_1, atom_id_1,4);
                    ReadCIFstr(cif,col_atom_id_2, atom_id_2,4);
                    ReadCIFstr(cif,col_bond_value, bond_value,5);
                    if(!strncasecmp(bond_value, "SING",5)){
                        bvalue=NormBondFlag;
                    }else if(!strncasecmp(bond_value, "DOUB",5)){
                        bvalue=DoubBondFlag;
                    }else if(!strncasecmp(bond_value, "TRIP",5)){
                        bvalue=TripBondFlag;
                    }else if(!strncasecmp(bond_value, "AROM",5)){
                        bvalue=AromBondFlag;
                    }else
                        bvalue=NormBondFlag;
                    id1 = seroffset + find_chem_comp_id(cif,label_comp_id, atom_id_1);
                    id2 = seroffset + find_chem_comp_id(cif,label_comp_id, atom_id_2);
                    if (id1 > seroffset && id2 > seroffset) CreateBond(id1,id1,bvalue);
                    else NullBonds++;
                    if (cif_findtag(cif,"_chem_comp_bond.ordinal"))
                        cif_findtag(cif,"_chem_comp_bond.pdbx_ordinal");
                }
            }
            if (NullBonds && ipass==0) WriteString("Warning: Null bonds in models in CHEM_COMP_BOND!\n");
            if (NullBonds && ipass==1) WriteString("Warning: Null bonds in ideal models in CHEM_COMP_BOND!\n");
        }
    }


    cif_free_handle(cif);
    
    if( Database )
        strcpy(Info.filename,DataFileName);
    if( FeatList ) ProcessFeatures();
    DataFileFormat = FormatCIF;
    return True;
}


int LoadBiosymMolecule( FILE *fp )
{
    UnusedArgument(fp);
    return True;
}
 
 
int LoadSHELXMolecule( FILE *fp )
{
    UnusedArgument(fp);
    return True;
}
 

int LoadFDATMolecule( FILE *fp )
{
    UnusedArgument(fp);
    return True;
}



/*=================================*/
/* Molecule File Format Generation */
/*=================================*/

int SavePDBMolecule( char *filename )
{
    register double x, y, z;
    register Group __far *prev;
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *aptr;
    register char *ptr;
    register int count;
    register int model;
    register char ch = '\0';
    register int i;
    char eltype[2];
 
    if( !Database )
        return False;
 
    DataFile = fopen( filename, "w" );
    if( !DataFile )
    {   InvalidateCmndLine();
        WriteString("Error: Unable to create file!\n\n");
        return False;
    }
 
    if( *Info.classification || *Info.identcode )
    {   fputs("HEADER    ",DataFile);
 
        ptr = Info.classification;
        for( i=11; i<=50; i++ )
            putc( (*ptr ? *ptr++ : ' '), DataFile );
        fprintf(DataFile,"%-11.11s %-10.10s\n",Info.date,Info.identcode);
    }
 
    if( *Info.moleculename )
        fprintf(DataFile,"COMPND    %.60s\n",Info.moleculename);
    if( *Info.technique )
        fprintf(DataFile,"EXPDTA    %.60s\n",Info.technique);
 
    prev = (void __far*)0; 
    count = 1;
    model = 0;
    ch = ' ';

    ForEachAtom
        if( aptr->flag&SelectFlag )
        {   if( prev && (chain->ident!=ch) )
                fprintf( DataFile, "TER   %5d      %.3s %c%4d \n",
                         count++, Residue[prev->refno], ch, prev->serno);
            if( chain->model != model )
            {   if( model )
                    fputs("ENDMDL\n",DataFile);
                fprintf(DataFile,"MODEL     %4d\n",chain->model);
                model = chain->model;
            }
 
            if( aptr->flag&HeteroFlag )
            {      fputs("HETATM",DataFile);
            } else fputs("ATOM  ",DataFile);
            eltype[0] = ElemDesc[aptr->refno][0];
            eltype[1] = ElemDesc[aptr->refno][1];
            if (isdigit(eltype[1])) eltype[1]=' ';
            if (isdigit(eltype[0])) eltype[0]=' ';
            if (eltype[0]!=' '
              && GetElemDescNumber(eltype)!=aptr->elemno)
              { char c[5];
                int ic;
                c[0]=ElemDesc[aptr->refno][3];
                c[1]=ElemDesc[aptr->refno][0];
                c[2]=ElemDesc[aptr->refno][1];
                c[3]=ElemDesc[aptr->refno][2];
                c[4]=0;
                for (ic=0; ic<4; ic++) if (!c[ic]) c[ic]=' ';
                fprintf( DataFile, "%5d %-4.4s%c%3.3s %c%4d    ",
                     count++, c,
                     aptr->altl, Residue[group->refno],
                     chain->ident, group->serno );
            	
            } else {
              fprintf( DataFile, "%5d %-4.4s%c%3.3s %c%4d    ",
                     count++, ElemDesc[aptr->refno],
                     aptr->altl, Residue[group->refno],
                     chain->ident, group->serno );
            }   
 
            x = (double)(aptr->xorg + aptr->fxorg + OrigCX)/250.0
                +(double)(aptr->xtrl)/10000.0;
            y = (double)(aptr->yorg + aptr->fyorg + OrigCY)/250.0
                +(double)(aptr->ytrl)/10000.0;
            z = (double)(aptr->zorg + aptr->fzorg + OrigCZ)/250.0
                +(double)(aptr->ztrl)/10000.0;
 
#ifdef INVERT
            fprintf(DataFile,"%8.3f%8.3f%8.3f",x,-y,-z);
#else
            fprintf(DataFile,"%8.3f%8.3f%8.3f",x,y,-z);
#endif
            fprintf(DataFile,"  1.00%6.2f\n",aptr->temp/100.0);
 
            ch = chain->ident;
            prev = group;
        }
 
    if( prev )
        fprintf( DataFile, "TER   %5d      %.3s %c%4d \n",
                 count, Residue[prev->refno], ch, prev->serno);
    if( model )
        fputs("ENDMDL\n",DataFile);
    fputs("END   \n",DataFile);
    fclose( DataFile );
#ifdef APPLEMAC
    SetFileInfo(filename,'RSML','TEXT',131);
#endif
    return True;
}
 
int SaveWPDBMolecule( char *filename )
{
    register double x, y, z;
    register Group __far *prev;
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *aptr;
    register char *ptr;
    register int count;
    register int model;
    register char ch = '\0';
    register int i;
    char eltype[2];
 
    if( !Database )
        return False;
 
    DataFile = fopen( filename, "w" );
    if( !DataFile )
    {   InvalidateCmndLine();
        WriteString("Error: Unable to create file!\n\n");
        return False;
    }
 
    if( *Info.classification || *Info.identcode )
             /*12345678901234567890123456789012*/
    {   fputs("HEADER                          ",DataFile);
 
        ptr = Info.classification;
        for( i=11; i<=60; i++ )
            putc( (*ptr ? *ptr++ : ' '), DataFile );
        fprintf(DataFile," %-11.11s %-15.15s\n",Info.date,Info.identcode);
    }
 
                        /*12345678901234567890123456789012*/
    if( *Info.moleculename )
        fprintf(DataFile,"COMPND                          %.110s\n",Info.moleculename);
    if( *Info.technique )
        fprintf(DataFile,"EXPDTA                          %.110s\n",Info.technique);
    prev = (void __far*)0; 
    count = 1;
    model = 0;
    ch = ' ';

    ForEachAtom
        if( aptr->flag&SelectFlag )
        {   if( prev && (chain->ident!=ch) )
                fprintf( DataFile, "TER     %9d                  %.10s         %c%9d \n",
                         count++, Residue[prev->refno], ch, prev->serno);
            if( chain->model != model )
            {   if( model )
                    fputs("ENDMDL\n",DataFile);
                fprintf(DataFile,"MODEL   %9d\n",chain->model);
                model = chain->model;
            }
 
            if( aptr->flag&HeteroFlag )
            {      fputs("HETATM",DataFile);
            } else fputs("ATOM  ",DataFile);

            eltype[0] = ElemDesc[aptr->refno][0];
            eltype[1] = ElemDesc[aptr->refno][1];
            if (isdigit(eltype[1])) eltype[1]=' ';
            if (isdigit(eltype[0])) eltype[0]=' ';
            if (eltype[0]!=' '
              && GetElemDescNumber(eltype)!=aptr->elemno )
              { char c[11];
                int ic;
                c[0]=' ';
                for (ic=0; ic<9; ic++){
                  c[ic+1]=ElemDesc[aptr->refno][ic];
                  if(!c[ic+1])c[ic+1]=' ';
                }
                c[10]=0;
                fprintf( DataFile, "  %9d     %-10.10s  %c%10.10s         %c%9d ",
                     count++, c,
                     aptr->altl, Residue[group->refno],
                     chain->ident, group->serno );
            	
            } else {
 
              fprintf( DataFile, "  %9d     %-10.10s  %c%10.10s         %c%9d ",
                     count++, ElemDesc[aptr->refno],
                     aptr->altl, Residue[group->refno],
                     chain->ident, group->serno );
            }
 
            x = (double)(aptr->xorg + aptr->fxorg + OrigCX)/250.0
                +(double)(aptr->xtrl)/10000.0;
            y = (double)(aptr->yorg + aptr->fyorg + OrigCY)/250.0
                +(double)(aptr->ytrl)/10000.0;
            z = (double)(aptr->zorg + aptr->fzorg + OrigCZ)/250.0
                +(double)(aptr->ztrl)/10000.0;
 
#ifdef INVERT
            fprintf(DataFile,"%13.3f%13.3f%13.3f",x,-y,-z);
#else
            fprintf(DataFile,"%13.3f%13.3f%13.3f",x,y,-z);
#endif
            fprintf(DataFile,"  1.00%6.2f\n",aptr->temp/100.0);
 
            ch = chain->ident;
            prev = group;
        }
 
    if( prev )
        fprintf( DataFile, "TER     %9d                  %.10s         %c%9d \n",
                 count, Residue[prev->refno], ch, prev->serno);
    if( model )
        fputs("ENDMDL\n",DataFile);
    fputs("END   \n",DataFile);
    fclose( DataFile );
#ifdef APPLEMAC
    SetFileInfo(filename,'RSML','TEXT',131);
#endif
    return True;
}
 
 
int SaveMDLMolecule( char *filename )
{
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *aptr;
    register Bond __far *bptr;
    register int atoms,bonds;
    register double x,y,z;
    register int ch,temp;
    register int atomno;

#ifndef APPLEMAC
    register struct tm *ptr;
    static time_t curtime;
#endif
 
    if( !Database )
        return False;

    DataFile = fopen( filename, "w" );
    if( !DataFile )
    {   InvalidateCmndLine();
        WriteString("Error: Unable to create file!\n\n");
        return False;
    }

    /* Write Mol file header */
    fprintf(DataFile,"%.80s\n  RasMol  ",Info.moleculename);

#ifndef APPLEMAC
    curtime = time((time_t*)0);
    ptr = localtime(&curtime);
    fprintf(DataFile,"%02d%02d%02d%02d%02d",ptr->tm_mon+1,ptr->tm_mday,
                             ptr->tm_year%100,ptr->tm_hour,ptr->tm_min);
#else
    fputs("0101951200",DataFile);
#endif

    atoms = 0;
    ForEachAtom
        if( aptr->flag & SelectFlag )
            atoms++;

    bonds = 0;
    ForEachBond
        if( bptr->srcatom->flag & bptr->dstatom->flag & SelectFlag )
             bonds++;

    fprintf(DataFile,"%cD\n\n", (MinZ||MaxZ)?'3':'2' );
    fprintf(DataFile,"%3d%3d",atoms,bonds);
    fputs("  0        0              1 V2000\n",DataFile);

    atomno = 1;
    ForEachAtom
        if( aptr->flag & SelectFlag )
        {   x = (double)(aptr->xorg + aptr->fxorg + OrigCX)/250.0
                +(double)(aptr->xtrl)/10000.0;
            y = (double)(aptr->yorg + aptr->fyorg + OrigCY)/250.0
                +(double)(aptr->ytrl)/10000.0;
            z = (double)(aptr->zorg + aptr->fzorg + OrigCZ)/250.0
                +(double)(aptr->ztrl)/10000.0;
#ifdef INVERT
#ifdef __STDC__
            fprintf(DataFile,"%10.4f%10.4f%10.4f ",x,-y,-z);
#else
            fprintf(DataFile,"%10.4lf%10.4lf%10.4lf ",x,-y,-z);
#endif
#else
#ifdef __STDC__
            fprintf(DataFile,"%10.4f%10.4f%10.4f ",x,y,-z);
#else
            fprintf(DataFile,"%10.4lf%10.4lf%10.4lf ",x,y,-z);
#endif
#endif

            fputc(Element[aptr->elemno].symbol[0],DataFile);
            fputc(Element[aptr->elemno].symbol[1],DataFile);
            fputs("  0  ",DataFile);

            ch = '0';
            /* Test for charges or b-factors */
            if( (MinMainTemp<0) || (MinHetaTemp<0) )
            {   temp = aptr->temp;
                if( temp > 50 )
                {   if( temp > 250 )
                    {   ch = '1';
                    } else if( temp > 150 )
                    {   ch = '2';
                    } else ch = '3';
                } else if( temp < -50 )
                {   if( temp < -250 )
                    {   ch = '7';
                    } else if( temp < -150 )
                    {   ch = '6';
                    } else ch = '5';
                } else ch = '0';
            } 
            fputc(ch,DataFile);

            fputs("  0  0  0  0  0  0  0  0  0  0\n",DataFile);
            aptr->mbox = atomno++;
        }

    ForEachBond
        if( bptr->srcatom->flag & bptr->dstatom->flag & SelectFlag )
        {   fprintf(DataFile,"%3d%3d  ",bptr->srcatom->mbox,
                                        bptr->dstatom->mbox);
            if( bptr->flag & AromBondFlag )
            {      fputc('4',DataFile);
            } else if( bptr->flag & TripBondFlag )
            {      fputc('3',DataFile);
            } else if( bptr->flag & DoubBondFlag )
            {      fputc('2',DataFile);
            } else fputc('1',DataFile);
            fputs("  0\n",DataFile);
        }

    fputs("M  END\n",DataFile);
    fclose( DataFile );
#ifdef APPLEMAC
    SetFileInfo(filename,'RSML','mMOL',131);
#endif
    return True;
}


int SaveAlchemyMolecule( char *filename )
{
    register Real x, y, z;
    register float xpos, ypos, zpos;
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *aptr;
    register Bond __far *bptr;
    register char *ptr;
    register int atomno;
    register int bondno;
    register int num;
 
    if( !Database )
        return False;
 
    DataFile = fopen( filename, "w" );
    if( !DataFile )
    {   InvalidateCmndLine();
        WriteString("Error: Unable to create file!\n\n");
        return False;
    }
 
    atomno = 0;
    ForEachAtom
        if( aptr->flag & SelectFlag )
            aptr->mbox = 0;
 
    ForEachBond
        if( ((bptr->srcatom->flag&bptr->dstatom->flag)&SelectFlag) &&
           !((bptr->srcatom->flag|bptr->dstatom->flag)&HydrogenFlag) )
        {   if( bptr->flag&AromBondFlag )
            {   bptr->srcatom->mbox = -1;
                bptr->dstatom->mbox = -1;
            } else
            {   num = (bptr->flag&DoubBondFlag)? 2 : 1;
                if( bptr->srcatom->mbox>0 )
                    bptr->srcatom->mbox += num;
                if( bptr->dstatom->mbox>0 )
                    bptr->dstatom->mbox += num;
            }
        }
 
    fprintf(DataFile,"%5ld ATOMS, ",(long)(MainAtomCount+HetaAtomCount));
    fprintf(DataFile,"%5ld BONDS, ",(long)Info.bondcount);
    fprintf(DataFile,"    0 CHARGES, %s\n", Info.moleculename );
 
    atomno = 1;
    ForEachAtom
        if( aptr->flag & SelectFlag )
        {   aptr->mbox = atomno;
            fprintf(DataFile,"%5d ",atomno++);
 
            switch( aptr->elemno )
            {   case( 6 ):  if( aptr->mbox == -1 )
                            {   ptr = "CAR ";
                            } else if( aptr->mbox == 1 )
                            {   ptr = "C3  ";
                            } else ptr = "C2  ";
                            fputs( ptr, DataFile );
                            break;
 
                case( 7 ):  if( aptr->mbox == -1 )
                            {   ptr = "NAR ";
                            } else ptr = "N2  ";
                            fputs( ptr, DataFile );
                            break;
 
                case( 8 ):  if( aptr->mbox == 2 )
                            {   ptr = "O2  ";
                            } else ptr = "O3  ";
                            fputs( ptr, DataFile );
                            break;
 
                case( 1 ):  fputs( "H   ", DataFile );  break;
 
                default:    ptr = ElemDesc[aptr->refno];
                            if( *ptr==' ' )
                            {   fprintf(DataFile,"%.3s ",ptr+1);
                            } else fprintf(DataFile,"%.4s",ptr);
            }
 
            x = (double)(aptr->xorg + aptr->fxorg + OrigCX)/250.0
                +(double)(aptr->xtrl)/10000.0;
            y = (double)(aptr->yorg + aptr->fyorg + OrigCY)/250.0
                +(double)(aptr->ytrl)/10000.0;
            z = (double)(aptr->zorg + aptr->fzorg + OrigCZ)/250.0
                +(double)(aptr->ztrl)/10000.0;
 
            /* Apply Current Viewpoint Rotation Matrix */
            xpos = (float)(x*RotX[0] + y*RotX[1] + z*RotX[2]);
            ypos = (float)(x*RotY[0] + y*RotY[1] + z*RotY[2]);
            zpos = (float)(x*RotZ[0] + y*RotZ[1] + z*RotZ[2]);
 
#ifdef INVERT
            fprintf(DataFile,"  %8.4f %8.4f %8.4f",xpos,-ypos,-zpos);
#else
            fprintf(DataFile,"  %8.4f %8.4f %8.4f",xpos,ypos,-zpos);
#endif
            fprintf(DataFile,"    %7.4f\n",aptr->temp/1000.0);
        }
 
    bondno = 1;
    ForEachBond
        if( (bptr->srcatom->flag&bptr->dstatom->flag) & SelectFlag )
        {   fprintf(DataFile,"%5d %5d %5d  ", bondno++,
                        bptr->srcatom->mbox, bptr->dstatom->mbox );
            if( bptr->flag & AromBondFlag )
            {   ptr = "AROMATIC\n";
            } else if( bptr->flag & TripBondFlag )
            {   ptr = "TRIPLE\n";
            } else if( bptr->flag & DoubBondFlag )
            {   ptr = "DOUBLE\n";
            } else ptr = "SINGLE\n";
            fputs( ptr, DataFile );
        }
 
    ForEachAtom
            if( aptr->flag & SelectFlag )
                aptr->mbox = 0;
    fclose( DataFile );
#ifdef APPLEMAC
    SetFileInfo(filename,'RSML','TEXT',131);
#endif
    return True;
}


int SaveXYZMolecule( char *filename )
{
    register double x, y, z;
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *aptr;
    register int atoms;

    if( !Database )
        return False;

    DataFile = fopen( filename, "w" );
    if( !DataFile )
    {   InvalidateCmndLine();
        WriteString("Error: Unable to create file!\n\n");
        return False;
    }

    atoms = 0;
    ForEachAtom
        if( aptr->flag & SelectFlag )
            atoms++;

    fprintf(DataFile," %d\n",atoms);
    fprintf(DataFile,"%s\n",Info.moleculename);
    fprintf(DataFile,"%s\n",Info.classification);

    ForEachAtom
        if( aptr->flag & SelectFlag )
        {   fputc(Element[aptr->elemno].symbol[0],DataFile);
            fputc(Element[aptr->elemno].symbol[1],DataFile);
 
            x = (double)(aptr->xorg + aptr->fxorg + OrigCX)/250.0
                +(double)(aptr->xtrl)/10000.0;
            y = (double)(aptr->yorg + aptr->fyorg + OrigCY)/250.0
                +(double)(aptr->ytrl)/10000.0;
            z = (double)(aptr->zorg + aptr->fzorg + OrigCZ)/250.0
                +(double)(aptr->ztrl)/10000.0;

#ifdef INVERT
            fprintf(DataFile," %8.3f %8.3f %8.3f",x,-y,-z);
#else
            fprintf(DataFile," %8.3f %8.3f %8.3f",x,y,-z);
#endif
            fprintf(DataFile," %6.2f\n",aptr->temp/100.0);
        }


    fclose( DataFile );
#ifdef APPLEMAC
    SetFileInfo(filename,'RSML','TEXT',131);
#endif
    return True;
}
 
 
int SaveCIFMolecule( char *filename )
{
    UnusedArgument(filename);

    if( !Database )
        return False;
    return True;
}

