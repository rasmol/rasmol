
/***************************************************************************
 *                               RasMol 2.7.3                              *
 *                                                                         *
 *                                 RasMol                                  *
 *                 Molecular Graphics Visualisation Tool                   *
 *                             6 February 2005                             *
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
 *Bernstein          RasMol 2.7.1   Jun 99         1998-2001               *
 *                   RasMol 2.7.1.1 Jan 01                                 *
 *                   RasMol 2.7.2   Aug 00                                 *
 *                   RasMol 2.7.2.1 Apr 01                                 *
 *                   RasMol 2.7.2.1.1 Jan 04                               *
 *                   RasMol 2.7.3   Feb 05                                 *
 *                                                                         *
 *with RasMol 2.7.3 incorporating changes by Clarice Chigbo, Ricky Chachra,*
 *and Mamoru Yamanishi.  Work on RasMol 2.7.3 supported in part by         *
 *grants DBI-0203064, DBI-0315281 and EF-0312612 from the U.S. National    *
 *Science Foundation and grant DE-FG02-03ER63601 from the U.S. Department  *
 *of Energy.                                                               *
 *                                                                         *
 *                    and Incorporating Translations by                    *
 *  Author                               Item                      Language*
 *  Isabel Servan Martinez,                                                *
 *  Jose Miguel Fernandez Fernandez      2.6   Manual              Spanish *
 *  Jose Miguel Fernandez Fernandez      2.7.1 Manual              Spanish *
 *  Fernando Gabriel Ranea               2.7.1 menus and messages  Spanish *
 *  Jean-Pierre Demailly                 2.7.1 menus and messages  French  *
 *  Giuseppe Martini, Giovanni Paolella, 2.7.1 menus and messages          *
 *  A. Davassi, M. Masullo, C. Liotto    2.7.1 help file           Italian *
 *                                                                         *
 *                             This Release by                             *
 * Herbert J. Bernstein, Bernstein + Sons, P.O. Box 177, Bellport, NY, USA *
 *                       yaya@bernstein-plus-sons.com                      *
 *               Copyright(C) Herbert J. Bernstein 1998-2005               *
 *                                                                         *
 *                READ THE FILE NOTICE FOR RASMOL LICENSES                 *
 *Please read the file NOTICE for important notices which apply to this    *
 *package and for license terms (GPL or RASLIC).                           *
 ***************************************************************************/
/* abstree.c
 */

#include "rasmol.h"

#ifdef IBMPC
#include <malloc.h>
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

#define ABSTREE
#include "molecule.h"
#include "abstree.h"
#include "transfor.h"
#include "langsel.h"


/* Macros for commonly used loops */
#define ForEachAtom  for(chain=Database->clist;chain;chain=chain->cnext) \
                     for(group=chain->glist;group;group=group->gnext)    \
                     for(aptr=group->alist;aptr;aptr=aptr->anext)


#define BitAcidic       0x001
#define BitAliphatic    0x002
#define BitAromatic     0x004
#define BitBasic        0x008
#define BitBuried       0x010
#define BitCyclic       0x020
#define BitHydrophobic  0x040
#define BitMedium       0x080
#define BitNeutral      0x100
#define BitSmall        0x200

#define BitCharged      0x009
#define BitNotLarge     0x280

/* Acyclic = !Cyclic         */
/* Large = !Medium && !Small */
/* Polar = !Hydrophobic      */
/* Surface = !Buried         */


static int AminoProp[] = {
        /*ALA*/  BitAliphatic | BitBuried | BitHydrophobic | BitNeutral |
                 BitSmall,
        /*GLY*/  BitAliphatic | BitHydrophobic | BitNeutral | BitSmall,
        /*LEU*/  BitAliphatic | BitBuried | BitHydrophobic | BitNeutral,
        /*SER*/  BitNeutral | BitSmall,
        /*VAL*/  BitAliphatic | BitBuried | BitHydrophobic | BitMedium |
                 BitNeutral,
        /*THR*/  BitMedium | BitNeutral,
        /*LYS*/  BitBasic,
        /*ASP*/  BitAcidic | BitMedium,
        /*ILE*/  BitAliphatic | BitBuried | BitHydrophobic | BitNeutral,
        /*ASN*/  BitMedium | BitNeutral,
        /*GLU*/  BitAcidic,
        /*PRO*/  BitCyclic | BitHydrophobic | BitMedium | BitNeutral,
        /*ARG*/  BitBasic,
        /*PHE*/  BitAromatic | BitBuried | BitCyclic | BitHydrophobic |
                 BitNeutral,
        /*GLN*/  BitNeutral,
        /*TYR*/  BitAromatic | BitCyclic | BitNeutral,
        /*HIS*/  BitAromatic | BitBasic | BitCyclic | BitNeutral,
        /*CYS*/  BitBuried | BitMedium | BitNeutral,
        /*MET*/  BitBuried | BitHydrophobic | BitNeutral,
        /*TRP*/  BitAromatic | BitBuried | BitCyclic | BitHydrophobic |
                 BitNeutral,
        /*ASX*/  BitMedium | BitNeutral,
        /*GLX*/  BitNeutral,
        /*PCA*/  BitCyclic | BitHydrophobic | BitMedium | BitNeutral,
        /*HYP*/  BitCyclic | BitMedium | BitNeutral
        };


#define AminoCodeMax  28
static char *AminoCode = "AGLSVTKDINEPRFQYHCMWBZPPACGTX";


#define ExprPool    16
#define SetPool     4

static SymEntry __far *FreeEntry;
static AtomSet __far *FreeSet;
static Expr *FreeExpr;
static Expr FalseExpr;
static Expr TrueExpr;



/*=======================*/
/*  Function Prototypes  */
/*=======================*/

static AtomSet __far *SetInsert( AtomSet __far*, RAtom __far* );
static int IsWithinRadius( AtomSet __far*, Long );
static int IsSetMember( AtomSet __far* );
static void DeleteSymEntry( SymEntry __far* );



static void FatalExprError( char *ptr )
{
    char buffer[80];

    sprintf(buffer,"Expression Error: %s!",ptr);
    RasMolFatalExit(buffer);
}


static AtomSet __far *SetInsert( AtomSet __far *ptr, RAtom __far *item )
{
    register AtomSet __far *temp;
    register int i;

    if( ptr && (ptr->count<SetSize) )
    {   ptr->data[ptr->count] = item;
        ptr->count++;
        return ptr;
    }

    if( !FreeSet )
    {   temp = (AtomSet __far*)_fmalloc( SetPool*sizeof(AtomSet) );
        if( !temp ) FatalExprError(MsgStrs[StrMalloc]);
        for( i=1; i<SetPool; i++ )
        {    temp->next = FreeSet;
             FreeSet = temp++;
        }
    } else
    {   temp = FreeSet;
        FreeSet = temp->next;
    }

    temp->data[0] = item;
    temp->next = ptr;
    temp->count = 1;
    return temp;
}


static int IsWithinRadius( AtomSet __far *ptr, Long limit )
{
    register RAtom __far *aptr;
    register Long dx,dy,dz;
    register Long dist;
    register int i;

    while( ptr )
    {   for( i=0; i<ptr->count; i++ )
        {    aptr = ptr->data[i];
             dx = QAtom->xorg-aptr->xorg + QAtom->fxorg-aptr->fxorg; 
             if( (dist=dx*dx)>limit ) continue;
             dy = QAtom->yorg-aptr->yorg + QAtom->fyorg-aptr->fyorg; 
             if( (dist+=dy*dy)>limit ) continue;
             dz = QAtom->zorg-aptr->zorg + QAtom->fzorg-aptr->fzorg; 
             if( (dist+=dz*dz)>limit ) continue;
             return True;
        }
        ptr = ptr->next;
    }
    return False;
}


static int IsSetMember( AtomSet __far *ptr )
{
    register int i;

    while( ptr )
    {   for( i=0; i<ptr->count; i++ )
            if( ptr->data[i] == QAtom )
                return True;
        ptr = ptr->next;
    }
    return False;
}


void DeleteAtomSet( AtomSet __far *ptr )
{
    register AtomSet __far *temp;

    if( ptr )
    {   temp = ptr;
        while( temp->next )
            temp = temp->next;
        temp->next = FreeSet;
        FreeSet = ptr;
    }
}


Expr *AllocateNode( void )
{
    register Expr *ptr;
    register int i;

    if( !FreeExpr )
    {   ptr = (Expr*)_fmalloc( ExprPool*sizeof(Expr) );
        if( !ptr ) FatalExprError("Memory allocation failed");
		RegisterAlloc( ptr );
        for( i=1; i<ExprPool; i++ )
        {   ptr->rgt.ptr = FreeExpr;
            FreeExpr = ptr++;
        }
    } else
    {   ptr = FreeExpr;
        FreeExpr = ptr->rgt.ptr;
    }
    ptr->rgt.ptr = NULL;
    ptr->lft.ptr = NULL;
    return ptr;
}


void DeAllocateExpr( Expr *expr )
{
    if( !expr ) return;
    if( (expr == &FalseExpr) ||
        (expr == &TrueExpr) ) 
        return;

    if( expr->type!=OpWithin )
    {   if( !(expr->type&(OpLftProp|OpLftVal)) )
            DeAllocateExpr( expr->lft.ptr );
        if( !(expr->type&(OpRgtProp|OpRgtVal)) )
            DeAllocateExpr( expr->rgt.ptr );
    } else DeleteAtomSet( expr->rgt.set );
        
    expr->rgt.ptr = FreeExpr;
    FreeExpr = expr;
}


int GetElemNumber( Group __far *group, RAtom __far *aptr )
{
    register char ch1,ch2;
    register char *ptr;

    ptr = ElemDesc[aptr->refno];
    if( IsCoenzyme(group->refno) )
    {   /* Exceptions to PDB Atom Naming! */
        ch1 = ' ';
    } else 
    {   ch1 = ToUpper(ptr[0]);
        /* Handle HG, HD etc.. in Amino Acids! */
        if( (ch1=='H') && IsProtein(group->refno) )
            return 1;
    }
    ch2 = ToUpper(ptr[1]);

    switch( ch1 )
    {   case(' '):  switch( ch2 )
                    {   case('B'):  return(  5 );
                        case('C'):  return(  6 );
                        case('D'):  return(  1 );
                        case('F'):  return(  9 );
                        case('H'):  return(  1 );
                        case('I'):  return( 53 );
                        case('K'):  return( 19 );
                        case('L'):  return(  1 );
                        case('N'):  return(  7 );
                        case('O'):  return(  8 );
                        case('P'):  return( 15 );
                        case('S'):  return( 16 );
                        case('U'):  return( 92 );
                        case('V'):  return( 23 );
                        case('W'):  return( 74 );
                        case('Y'):  return( 39 );
                    }
                    break;

        case('A'):  switch( ch2 )
                    {   case('C'):  return( 89 );
                        case('G'):  return( 47 );
                        case('L'):  return( 13 );
                        case('M'):  return( 95 );
                        case('R'):  return( 18 );
                        case('S'):  return( 33 );
                        case('T'):  return( 85 );
                        case('U'):  return( 79 );
                    }
                    break;

        case('B'):  switch( ch2 )
                    {   case(' '):  return(  5 );
                        case('A'):  return( 56 );
                        case('E'):  return(  4 );
                        case('I'):  return( 83 );
                        case('K'):  return( 97 );
                        case('R'):  return( 35 );
                    }
                    break;

        case('C'):  switch( ch2 )
                    {   case(' '):  return(  6 );
                        case('A'):  return( 20 );
                        case('D'):  return( 48 );
                        case('E'):  return( 58 );
                        case('F'):  return( 98 );
                        case('L'):  return( 17 );
                        case('M'):  return( 96 );
                        case('O'):  return( 27 );
                        case('R'):  return( 24 );
                        case('S'):  return( 55 );
                        case('U'):  return( 29 );
                    }
                    break;

        case('D'):  if( ch2==' ' )
                    {   return(  1 );
                    } else if( ch2=='Y' )
                    {   return( 66 );
                    } else if( ch2=='U' )
                        return(  0 );
                    break;

        case('E'):  if( ch2=='R' )
                    {   return( 68 );
                    } else if( ch2=='S' )
                    {   return( 99 );
                    } else if( ch2=='U' )
                        return( 63 );
                    break;

        case('F'):  if( ch2==' ' )
                    {   return(   9 );
                    } else if( ch2=='E' )
                    {   return(  26 );
                    } else if( ch2=='M' )
                    {   return( 100 );
                    } else if( ch2=='R' )
                        return(  87 );
                    break;

        case('G'):  if( ch2=='A' )
                    {   return( 31 );
                    } else if( ch2=='D' )
                    {   return( 64 );
                    } else if( ch2=='E' )
                        return( 32 );
                    break;

        case('H'):  if( ch2==' ' )
                    {   return(  1 );
                    } else if( ch2=='E' )
                    {   return(  2 );
                    } else if( ch2=='F' )
                    {   return( 72 );
                    } else if( ch2=='G' )
                    {   return( 80 );
                    } else if( ch2=='O' )
                        return( 67 );
                    break;

        case('I'):  if( ch2==' ' )
                    {   return( 53 );
                    } else if( ch2=='N' )
                    {   return( 49 );
                    } else if( ch2=='R' )
                        return( 77 );
                    break;

        case('K'):  if( ch2==' ' )
                    {   return( 19 );
                    } else if( ch2=='R' )
                        return( 36 );
                    break;

        case('L'):  switch( ch2 )
                    {   case('A'):  return(  57 );
                        case('I'):  return(   3 );
                        case('P'):  return(   0 );
                        case('R'):  return( 103 );
                        case('W'):  return( 103 );
                        case('U'):  return(  71 );
                    }
                    break;

        case('M'):  if( ch2=='D' )
                    {   return( 101 );
                    } else if( ch2=='G' )
                    {   return(  12 );
                    } else if( ch2=='N' )
                    {   return(  25 );
                    } else if( ch2=='O' )
                        return(  42 );
                    break;

        case('N'):  switch( ch2 )
                    {   case(' '):  return(   7 );
                        case('A'):  return(  11 );
                        case('B'):  return(  41 );
                        case('D'):  return(  60 );
                        case('E'):  return(  10 );
                        case('I'):  return(  28 );
                        case('O'):  return( 102 );
                        case('P'):  return(  93 );
                    }
                    break;

        case('O'):  if( ch2==' ' )
                    {   return(  8 );
                    } else if( ch2=='S' )
                        return( 76 );
                    break;

        case('P'):  switch( ch2 )
                    {   case(' '):  return( 15 );
                        case('A'):  return( 91 );
                        case('B'):  return( 82 );
                        case('D'):  return( 46 );
                        case('M'):  return( 61 );
                        case('O'):  return( 84 );
                        case('R'):  return( 59 );
                        case('T'):  return( 78 );
                        case('U'):  return( 94 );
                    }
                    break;

        case('R'):  switch( ch2 )
                    {   case('A'):  return( 88 );
                        case('B'):  return( 37 );
                        case('E'):  return( 75 );
                        case('H'):  return( 45 );
                        case('N'):  return( 86 );
                        case('U'):  return( 44 );
                    }
                    break;

        case('S'):  switch( ch2 )
                    {   case(' '):  return( 16 );
                        case('B'):  return( 51 );
                        case('C'):  return( 21 );
                        case('E'):  return( 34 );
                        case('I'):  return( 14 );
                        case('M'):  return( 62 );
                        case('N'):  return( 50 );
                        case('R'):  return( 38 );
                    }
                    break;

        case('T'):  switch( ch2 )
                    {   case(' '):  return(  1 );
                        case('A'):  return( 73 );
                        case('B'):  return( 65 );
                        case('C'):  return( 43 );
                        case('E'):  return( 52 );
                        case('H'):  return( 90 );
                        case('I'):  return( 22 );
                        case('L'):  return( 81 );
                        case('M'):  return( 69 );
                    }
                    break;

        case('U'):  if( ch2==' ' )
                        return( 92 );
                    break;

        case('V'):  if( ch2==' ' )
                        return( 23 );
                    break;

        case('W'):  if( ch2==' ' )
                        return( 74 );
                    break;

        case('X'):  if( ch2=='E' )
                        return( 54 );
                    break;

        case('Y'):  if( ch2==' ' )
                    {   return( 39 );
                    } else if( ch2=='B' )
                        return( 70 );
                    break;

        case('Z'):  if( ch2=='N' )
                    {   return( 30 );
                    } else if( ch2=='R' )
                        return( 40 );
                    break;
    }

    /* Numeric Prefix! */
    if( (ch1>='0') && (ch1<='9') )
        ch1 = ch2;

    /* If all else fails! */
    switch( ch1 )
    {   case('B'):  return(  5 );
        case('C'):  return(  6 );
        case('D'):  return(  1 );
        case('F'):  return(  9 );
        case('H'):  return(  1 );
        case('I'):  return( 53 );
        case('K'):  return( 19 );
        case('L'):  return(  1 );
        case('N'):  return(  7 );
        case('O'):  return(  8 );
        case('P'):  return( 15 );
        case('S'):  return( 16 );
        case('U'):  return( 92 );
        case('V'):  return( 23 );
        case('W'):  return( 74 );
        case('Y'):  return( 39 );
    }
    return 0;
}


int ElemVDWRadius( int elem )
{
    if( !HasHydrogen )
        switch( elem )
        {   case  6:  return VDWCarbon;
            case  7:  return VDWNitrogen;
            case  8:  return VDWOxygen;    
            case 16:  return VDWSulphur;
        }
    return Element[elem].vdwrad;
}


static int EvaluateProperty( int prop )
{
    switch( prop )
    {   case( PropIdent ):    return( (int)QAtom->serno );
        case( PropXCord ):    return( (int)(QAtom->xorg + QAtom->fxorg) );
        case( PropYCord ):    return( (int)(QAtom->yorg + QAtom->fyorg) );
        case( PropZCord ):    return( (int)(QAtom->zorg + QAtom->fzorg) );
        case( PropTemp ):     return( QAtom->temp );
        case( PropName ):     return( QAtom->refno );
        case( PropResId ):    return( QGroup->serno );
        case( PropResName ):  return( QGroup->refno );
        case( PropChain ):    return( QChain->ident );
        case( PropSelect ):   return( QAtom->flag&SelectFlag );
        case( PropElemNo ):   return( QAtom->elemno );
        case( PropModel ):    return( (int)QChain->model );
        case( PropAltl ):     return( (int)QAtom->altl );
        case( PropRad ):      if( QAtom->flag&SphereFlag )
                              {   return( QAtom->radius );
                              } else return( 0 );
        
        /* Predicates stored in flags */
        case( PredBonded ):       return( !(QAtom->flag&NonBondFlag) );
        case( PredHydrogen ):     return( QAtom->flag&HydrogenFlag );
        case( PredHetero ):       return( QAtom->flag&HeteroFlag );
        case( PredCystine ):      return( QGroup->flag&CystineFlag );
        case( PredHelix ):        return( QGroup->struc&HelixFlag );
        case( PredSheet ):        return( QGroup->struc&SheetFlag );
        case( PredTurn ):         return( QGroup->struc&TurnFlag );
        case( PredCisBond ):      return( QGroup->flag&CisBondFlag );

        /* Residue type predicates */
        case( PredDNA ):          return( IsDNA(QGroup->refno) );
        case( PredRNA ):          return( IsRNA(QGroup->refno) );
        case( PredNucleic ):      return( IsNucleo(QGroup->refno) );
        case( PredProtein ):      return( IsProtein(QGroup->refno) );
        case( PredAmino ):        return( IsAmino(QGroup->refno) );
        case( PredWater ):        return( IsWater(QGroup->refno) );
        case( PredSolvent ):      return( IsSolvent(QGroup->refno) );
        case( PredIon ):          return( IsIon(QGroup->refno) );

        /* General Predicates */
        case( PredAlpha ):        return( IsAmino(QGroup->refno) &&
                                          IsAlphaCarbon(QAtom->refno) );
        case( PredMainChain ):    return( (IsAmino(QGroup->refno) && 
                                           IsAminoBackbone(QAtom->refno)) ||
                                          (IsNucleo(QGroup->refno) &&
                                           IsNucleicBackbone(QAtom->refno)) );
        case( PredSidechain ):    return( IsAmino(QGroup->refno) &&
                                          !IsAminoBackbone(QAtom->refno) );
        case( PredLigand ):       return( (QAtom->flag&HeteroFlag) &&
                                          !IsSolvent(QGroup->refno) );

        /* Nucleic Acid Classifications */
        case( PredAT ):           return( IsAdenine(QGroup->refno) ||
                                          IsThymine(QGroup->refno) );
        case( PredCG ):           return( IsCytosine(QGroup->refno) ||
                                          IsGuanine(QGroup->refno) );
        case( PredPyrimidine ):   return( IsPyrimidine(QGroup->refno) );
        case( PredPurine ):       return( IsPurine(QGroup->refno) );


        /* Amino Acid Classifications */
        case( PredAcidic ):       return( IsAmino(QGroup->refno) &&
                                  AminoProp[QGroup->refno]&BitAcidic );

        case( PredAcyclic ):      return( IsAmino(QGroup->refno) &&
                                  !(AminoProp[QGroup->refno]&BitCyclic) );

        case( PredAliphatic ):    return( IsAmino(QGroup->refno) &&
                                  AminoProp[QGroup->refno]&BitAliphatic );

        case( PredAromatic ):     return( IsAmino(QGroup->refno) &&
                                  AminoProp[QGroup->refno]&BitAromatic );

        case( PredBasic ):        return( IsAmino(QGroup->refno) &&
                                  AminoProp[QGroup->refno]&BitBasic );

        case( PredBuried ):       return( IsAmino(QGroup->refno) &&
                                  AminoProp[QGroup->refno]&BitBuried );

        case( PredCharged ):      return( IsAmino(QGroup->refno) &&
                                  AminoProp[QGroup->refno]&BitCharged );

        case( PredCyclic ):       return( IsAmino(QGroup->refno) &&
                                  AminoProp[QGroup->refno]&BitCyclic );

        case( PredHydrophobic ):  return( IsAmino(QGroup->refno) &&
                                  AminoProp[QGroup->refno]&BitHydrophobic );
                 
        case( PredLarge ):        return( IsAmino(QGroup->refno) &&
                                  !(AminoProp[QGroup->refno]&BitNotLarge) );

        case( PredMedium ):       return( IsAmino(QGroup->refno) &&
                                  AminoProp[QGroup->refno]&BitMedium );

        case( PredNeutral ):      return( IsAmino(QGroup->refno) &&
                                  AminoProp[QGroup->refno]&BitNeutral );

        case( PredPolar ):        return( IsAmino(QGroup->refno) &&
                                  !(AminoProp[QGroup->refno]&BitHydrophobic) );

        case( PredSmall ):        return( IsAmino(QGroup->refno) &&
                                  AminoProp[QGroup->refno]&BitSmall );

        case( PredSurface ):      return( IsAmino(QGroup->refno) &&
                                  !(AminoProp[QGroup->refno]&BitBuried) );

    }
    return True;
}


int EvaluateExpr( Expr *expr )
{
    register int lft, rgt;

    if( !expr )
        return True;

    if( expr->type==OpWithin )
    {   if( expr->lft.limit )
        {   return( IsWithinRadius(expr->rgt.set,expr->lft.limit) );
        } else return( IsSetMember(expr->rgt.set) );
    } else if( expr->type==OpMember )
        return( IsSetMember(expr->rgt.set) );

    if( expr->type & OpLftVal )
    {   lft = expr->lft.val;
    } else if( expr->type & OpLftProp )
    {   lft = EvaluateProperty( expr->lft.val );
    } else lft = EvaluateExpr( expr->lft.ptr );

    if( OpCode(expr)==OpConst ) return( lft );
    if( (OpCode(expr)==OpAnd) && !lft ) return False;
    if( (OpCode(expr)==OpOr) && lft ) return True;
    if( OpCode(expr)==OpNot ) return( !lft );

    if( expr->type & OpRgtVal )
    {   rgt = expr->rgt.val;
    } else if( expr->type & OpRgtProp )
    {   rgt = EvaluateProperty( expr->rgt.val );
    } else rgt = EvaluateExpr( expr->rgt.ptr );

    switch( OpCode(expr) )
    {   case(OpOr):
        case(OpAnd):     return( rgt );
        case(OpLess):    return( lft<rgt );
        case(OpMore):    return( lft>rgt );
        case(OpEqual):   return( lft==rgt );
        case(OpNotEq):   return( lft!=rgt );
        case(OpLessEq):  return( lft<=rgt );
        case(OpMoreEq):  return( lft>=rgt );
    }
    return True;
}


AtomSet __far *BuildAtomSet( Expr *expr )
{
    register AtomSet __far *pset;
    register AtomSet __far *ptr;
    register int i;

    ptr = (AtomSet __far*)0;
  
	/*Shortcut for defined atomsets*/
	if( expr->type==OpMember )
	{	pset = expr->rgt.set;
	    while( pset )
		{   for( i=0; i<pset->count; i++ )
		    {	QAtom = pset->data[i];
			    ptr = SetInsert( ptr, QAtom );
			}
			pset = pset->next;
		}
		return ptr;
	}

    if( Database )
        for( QChain=Database->clist; QChain; QChain=QChain->cnext )
            for( QGroup=QChain->glist; QGroup; QGroup=QGroup->gnext )
                for( QAtom=QGroup->alist; QAtom; QAtom=QAtom->anext )
                    if( EvaluateExpr(expr) )
                        ptr = SetInsert( ptr, QAtom );
    return ptr;
}



int DefineSetExpr( char *ident, Expr *expr )
{
    register SymEntry __far * __far *prev;
    register SymEntry __far *ptr;
    register AtomSet __far *set;
    register int result;
  
    /* Avoid Compiler Warning! */
    ptr = (SymEntry __far*)0;

    result = True;
    prev = &SymbolTable;
    while( *prev )
    {   ptr = *prev;
        result = strcmp(ident,ptr->ident);
        if( !result ) break;  /* Entry Exists! */
        prev = (result<0)? &(ptr->lft) : &(ptr->rgt);
    }

    if( result )
    {   if( FreeEntry )
        {   ptr = FreeEntry;
            FreeEntry = ptr->rgt;
        } else /* Allocate SymEntry! */
        {   ptr = (SymEntry __far*)_fmalloc(sizeof(SymEntry));
            if( !ptr ) return False;
			RegisterAlloc( ptr );
        }

        *prev = ptr;
        ptr->ident = ident;
        ptr->defn = (void __far*)0;
        ptr->lft = (void __far*)0;
        ptr->rgt = (void __far*)0;
    } else free(ident);

    if( expr )
    {   set = BuildAtomSet(expr);
        if( ptr->defn )
            DeleteAtomSet(ptr->defn);
        DeAllocateExpr(expr);
        ptr->defn = set;
    } else ptr->defn = (void __far*)0;
    return True;
}


Expr *LookUpSetExpr( char *ident )
{
    register SymEntry __far *ptr;
    register Expr *expr;
    register int result;

    result = True;
    ptr = SymbolTable;
    while( ptr )
    {   result = strcmp(ident,ptr->ident);
        if( !result ) break;  /* Entry Exists! */
        ptr = (result<0)? ptr->lft : ptr->rgt;
    }

    if( !result )
    {   expr = AllocateNode();
        expr->type = OpMember;
        expr->rgt.set = ptr->defn;
    } else expr = (Expr*)0;
    return expr;
}


static int ElemCompare( char *ident, char *elem )
{
    while( *elem )
        if( *elem++ != *ident++ )
            return False;

    /* Handle Plurals */
    if( (ident[0]=='S') && !ident[1] )
        return( (elem[-1]!='S') && (elem[-1]!='Y') );
    return !*ident;
}


Expr *LookUpElement( char *ident )
{
    register Expr *expr;
    register int elem;

    for( elem=1; elem<MAXELEMNO; elem++ )
        if( ElemCompare(ident,Element[elem].name) )
            break;

    /* Handle Difficult Plurals & US Spelling! */
    if( elem == MAXELEMNO )
    {   if( *ident=='A' )
        {   if( ElemCompare(ident,"ALUMINUM") )
            {   elem = 13;
            } else if( !strcmp(ident,"ANTIMONIES") )
                elem = 51;
        } else if( *ident=='C' )
        {   if( ElemCompare(ident,"CESIUM") )
                elem = 55;
        } else if( *ident=='M' )
        {   if( !strcmp(ident,"MERCURIES") )
                elem = 80;
        } else if( *ident=='P' )
        {   if( !strcmp(ident,"PHOSPHORUSES") )
                elem = 8;
        } else if( *ident=='S' )
        {   if( ElemCompare(ident,"SULFUR") )
                elem = 16;
        }
    }

    if( elem<MAXELEMNO )
    {   expr = AllocateNode();
        expr->type = OpEqual|OpLftProp|OpRgtVal;
        expr->lft.val = PropElemNo;
        expr->rgt.val = elem;
    } else expr = (Expr*)0;
    return expr;
}


static int MatchWildName( char *src, char *dst, int size, int len )
{
    register int i, left;

    left = size;
    while( *dst==' ' )
    {   dst++; left--;
    }

    for( i=0; i<len; i++ )
    {   if( left )
        {   if( (*dst == *src) || (*src=='?') )
            {   dst++;  src++;  left--;
            } else return False;
        } else if( *src++ != '?' )
            return False;
    }

    while( left )
         if( *dst++!=' ' )
         {   return False;
         } else left--;
    return True;
}



int ParsePrimitiveExpr( char **orig )
{
    static char NameBuf[4];
    register Expr *tmp1,*tmp2;
    register Expr *wild;
    register char *ptr;
    register int i, j;
    register int neg;
    register int ch;
    
    QueryExpr = &TrueExpr;
    ptr = *orig;
    ch = *ptr++;
    i = 0;

    if( ch != ':' )
    {   /* Parse Residue Name */
        if( ch != '*' )
        {   if( ch == '[' )
            {   i = 0;
                while( (ch = *ptr++) != ']' )
                    if( ch && (i<3) )
                    {   NameBuf[i++] = ToUpper(ch);
                    } else return False;
                ch = *ptr++;
            } else
                for( i=0; i<3; i++ )
                    if( isalpha(ch) )
                    {   NameBuf[i] = ToUpper(ch);
                        ch = *ptr++;
                    } else if( (ch=='?') || (ch=='%') )
                    {   NameBuf[i] = '?';
                        ch = *ptr++;
                    } else break;
            if( !i ) return False;

            wild = &FalseExpr;
            for( j=0; j<ResNo; j++ )
                if( MatchWildName(NameBuf,Residue[j],3,i) )
                {   tmp1 = AllocateNode();
                    tmp1->type = OpEqual | OpLftProp | OpRgtVal;
                    tmp1->lft.val = PropResName;
                    tmp1->rgt.val = j;

                    tmp2 = AllocateNode();
                    tmp2->type = OpOr;
                    tmp2->lft.ptr = tmp1;
                    tmp2->rgt.ptr = wild;
                    wild = tmp2;
                }
            QueryExpr = wild;
        } else ch = *ptr++;

        /* Parse Residue Number */
        if( ch != '*' )
        {   if( ch == '-' )
            {   ch = *ptr++;
                neg = True;
            } else neg = False;

            if( isdigit(ch) )
            {   i = ch-'0';
                while( isdigit(*ptr) )
                    i = 10*i + (*ptr++)-'0';

                tmp1 = AllocateNode();
                tmp1->type = OpEqual | OpLftProp | OpRgtVal;
                tmp1->rgt.val = neg? -i : i;
                tmp1->lft.val = PropResId;
                if( QueryExpr != &TrueExpr )
                {   tmp2 = AllocateNode();
                    tmp2->type = OpAnd;
                    tmp2->rgt.ptr = QueryExpr;
                    tmp2->lft.ptr = tmp1;
                    QueryExpr = tmp2;
                } else QueryExpr = tmp1;
                ch = *ptr++;
            } else if( neg )
                return False;
        } else ch = *ptr++;
    }

    /* Parse Chain Ident */
    if( ch==':' )
        ch = *ptr++;

    if( isalnum(ch) )
    {   ch = ToUpper(ch);

        tmp1 = AllocateNode();
        tmp1->type = OpEqual | OpLftProp | OpRgtVal;
        tmp1->lft.val = PropChain;
        tmp1->rgt.val = ch;
        if( QueryExpr != &TrueExpr )
        {   tmp2 = AllocateNode();
            tmp2->type = OpAnd;
            tmp2->rgt.ptr = QueryExpr;
            tmp2->lft.ptr = tmp1;
            QueryExpr = tmp2;
        } else QueryExpr = tmp1;
        ch = *ptr++;
    } else if( (ch=='?') || (ch=='%') || (ch=='*') )
        ch = *ptr++;

    /* Parse Model Number */
    if( ch == ':' || ch =='/' )
    {   ch = *ptr++;
        if( isdigit(ch) )
        {   i = ch-'0';
            while( isdigit(*ptr) )
                i = 10*i + (*ptr++)-'0';

            tmp1 = AllocateNode();
            tmp1->type = OpEqual | OpLftProp | OpRgtVal;
            tmp1->lft.val = PropModel;
            tmp1->rgt.val = i;
            if( QueryExpr != &TrueExpr )
            {   tmp2 = AllocateNode();
                tmp2->type = OpAnd;
                tmp2->rgt.ptr = QueryExpr;
                tmp2->lft.ptr = tmp1;
                QueryExpr = tmp2;
            } else QueryExpr = tmp1;
            ch = *ptr++;
        } else return False;
    }

    /* Parse Atom Name */
    if( ch == '.' )
    {   ch = *ptr++;
        if( ch!='*' )
        {   for( i=0; i<4; i++ )
                if( isalnum(ch) || ch=='\'' || ch=='*' )
                {   NameBuf[i] = ToUpper(ch);
                    ch = *ptr++;
                } else if( (ch=='?') || (ch=='%') || (ch=='#') )
                {   NameBuf[i] = '?';
                    ch = *ptr++;
                } else break;
            if( !i ) return False;


            wild = &FalseExpr;
            for( j=0; j<ElemNo; j++ )
                if( MatchWildName(NameBuf,ElemDesc[j],4,i) )
                {   tmp1 = AllocateNode();
                    tmp1->type = OpEqual | OpLftProp | OpRgtVal;
                    tmp1->lft.val = PropName;
                    tmp1->rgt.val = j;

                    tmp2 = AllocateNode();
                    tmp2->type = OpOr;
                    tmp2->lft.ptr = tmp1;
                    tmp2->rgt.ptr = wild;
                    wild = tmp2;
                }

            if( (QueryExpr == &TrueExpr) || (wild == &FalseExpr) )
            {   DeAllocateExpr(QueryExpr);
                QueryExpr=wild;
            } else
            {   tmp1 = AllocateNode();
                tmp1->type = OpAnd;
                tmp1->lft.ptr = QueryExpr;
                tmp1->rgt.ptr = wild;
                QueryExpr = tmp1;
            }
        } else ch = *ptr++;
    }

    /* Parse Trailing Alternate Conformation Identifier */
    if( ch ==';' )
    {   ch = *ptr++;
        if( isalnum(ch) || ch=='\'' || ch=='*' )
        {   NameBuf[0] = ToUpper(ch);
             ch = *ptr++;
        } else if( (ch=='?') || (ch=='%') || (ch=='#') )
        {   NameBuf[0] = '?';
            ch = *ptr++;
        } else  return False;
        tmp1 = AllocateNode();
        tmp1->type = OpEqual | OpLftProp | OpRgtVal;
        tmp1->lft.val = PropAltl;
        tmp1->rgt.val = NameBuf[0];
        if( QueryExpr != &TrueExpr )
        {   tmp2 = AllocateNode();
            tmp2->type = OpAnd;
            tmp2->rgt.ptr = QueryExpr;
            tmp2->lft.ptr = tmp1;
            QueryExpr = tmp2;
        } else QueryExpr = tmp1;
    }

    /* Parse Trailing Model Number */
    if( ch =='/' )
    {   ch = *ptr++;
        if( isdigit(ch) )
        {   i = ch-'0';
            while( isdigit(*ptr) )
                i = 10*i + (*ptr++)-'0';

            tmp1 = AllocateNode();
            tmp1->type = OpEqual | OpLftProp | OpRgtVal;
            tmp1->lft.val = PropModel;
            tmp1->rgt.val = i;
            if( QueryExpr != &TrueExpr )
            {   tmp2 = AllocateNode();
                tmp2->type = OpAnd;
                tmp2->rgt.ptr = QueryExpr;
                tmp2->lft.ptr = tmp1;
                QueryExpr = tmp2;
            } else QueryExpr = tmp1;
            ch = *ptr++;
        } else return False;
    }
    *orig = --ptr;
    return( !ch || isspace(ch) || ispunct(ch) );
}


static char *FormatInteger( char *ptr, Long value )
{
    auto char buffer[10];
    register char *tmp;

    if( value<0 )
    {   value = -value;
        *ptr++ = '-';
    }

    if( value>9 )
    {   tmp = buffer;
        while( value>9 )
        {   *tmp++ = (char)(value%10) + '0';
            value /= 10;
        }

        *ptr++ = (char)value + '0';
        do { tmp--; 
            *ptr++ = *tmp;
        } while( tmp != buffer );
    } else *ptr++ = (char)value + '0';
    return ptr;
}


void FormatLabel( Chain __far *chain, Group __far *group, RAtom __far *aptr,
                  char *label, unsigned char *ptr )
{
    register char ch;
    register int i,j;

    while( *label )
    {  ch = *label++;
       if( ch=='%' )
       {   ch = *label++;

           switch( ch )
           {   case('a'):  /* Atom Name */
                           i = aptr->refno;
                           for( j=0; ElemDesc[i][j] && j<12; j++ )
                               if( ElemDesc[i][j]!=' ' )
                                   *ptr++ = ElemDesc[i][j];
                           break;

               case('b'):  /* Temperature/B-factor */
               case('B'):
               case('t'):
               case('T'):  ptr = (unsigned char *)FormatInteger((char *)ptr,aptr->temp);
                           break;

               case('c'):  /* Chain Identifier */
               case('C'):
               case('s'):
               case('S'):  *ptr++ = chain->ident;
                           break;

               case('e'):
               case('E'):  /* Element Type */
                           i = aptr->elemno;
                           *ptr++ = Element[i].symbol[0];
                           if( Element[i].symbol[1]!=' ' )
                               *ptr++ = Element[i].symbol[1];
                           break;

               case('i'):
               case('I'):  /* Atom Number */
                           ptr = (unsigned char *)FormatInteger((char *)ptr,(int)aptr->serno);
                           break;

               case('m'):  /* Amino (Nucliec) Acid Code */
                           if( group->refno <= AminoCodeMax )
                           {   *ptr++ = AminoCode[group->refno];
                           } else *ptr++ = '?';
                           break;

               case('n'):
               case('N'):  /* Residue Name   */
                           i = group->refno;
                           for( j=0; j<3; j++ )
                               if( Residue[i][j]!=' ' )
                                   *ptr++ = Residue[i][j];
                           break;

               case('r'):
               case('R'):  /* Residue Number */
                           ptr = (unsigned char *)FormatInteger((char *)ptr,group->serno);
                           break;

               case('A'):  /* Alternate Conformation ID */
                           if( !(aptr->altl == ' ') && 
                               !(aptr->altl == '\0')) {
                             *ptr++ = ';';
                             *ptr++ = aptr->altl;
                           }
                           break;

               case('M'):  /* NMR Model Number */
                           if ( aptr->model ) {
                             *ptr++ = '/';
                             ptr = (unsigned char *)FormatInteger((char *)ptr,(int)aptr->model);
                           } 
                           break;

               case('%'):  *ptr++ = '%';
                           break;
           }
       } else if( (ch>=' ') && (ch<='~') )
           *ptr++ = ch;
    }
    *ptr = '\0';
}


static void DeleteSymEntry( SymEntry __far *ptr )
{
    if( ptr->lft )
        DeleteSymEntry( ptr->lft );
    if( ptr->rgt )
        DeleteSymEntry( ptr->rgt );

    if( ptr->defn )
        DeleteAtomSet( ptr->defn );
    free( ptr->ident );

    ptr->rgt = FreeEntry;
    FreeEntry = ptr;
}


void ResetSymbolTable( void )
{
    if( SymbolTable )
    {   DeleteSymEntry(SymbolTable);
        SymbolTable = (void __far*)0;
    }
}


double CalcDistance( RAtom __far *atm1, RAtom __far *atm2 )
{
    register double dx,dy,dz;
    register double dist2;

    dx = (double)(atm1->xorg - atm2->xorg + atm1->fxorg - atm2->fxorg);
    dy = (double)(atm1->yorg - atm2->yorg + atm1->fyorg - atm2->fyorg);
    dz = (double)(atm1->zorg - atm2->zorg + atm1->fzorg - atm2->fzorg);
    if( dx != 0.0 || dy != 0.0 || dz != 0.0 )
    {   dist2 = dx*dx + dy*dy + dz*dz;
        return( sqrt(dist2/62500.) );
    } else return 0.0;
}


double CalcAngle(  RAtom __far *atm1, RAtom __far *atm2,  RAtom __far *atm3 )
{
    register double ulen2,vlen2;
    register double ux,uy,uz;
    register double vx,vy,vz;
    register double temp;

    ux = atm1->xorg - atm2->xorg + atm1->fxorg - atm2->fxorg;
#ifdef INVERT
    uy = atm2->yorg - atm1->yorg + atm2->fyorg - atm1->fyorg;
#else
    uy = atm1->yorg - atm2->yorg + atm1->fyorg - atm2->fyorg;
#endif
    uz = atm1->zorg - atm2->zorg + atm1->fzorg - atm2->fzorg;
    if( !ux && !uy && !uz )
        return 0.0;
    ulen2 = ux*ux + uy*uy + uz*uz;

    vx = atm3->xorg - atm2->xorg + atm3->fxorg - atm2->fxorg;
#ifdef INVERT
    vy = atm2->yorg - atm3->yorg + atm2->fyorg - atm3->fyorg;
#else
    vy = atm3->yorg - atm2->yorg + atm3->fyorg - atm2->fyorg;
#endif
    vz = atm3->zorg - atm2->zorg + atm3->fzorg - atm2->fzorg;
    if( !vx && !vy && !vz )
        return 0.0;
    vlen2 = vx*vx + vy*vy + vz*vz;

    temp = (ux*vx + uy*vy + uz*vz)/sqrt(ulen2*vlen2);
    return Rad2Deg*acos(temp);
}


double CalcTorsion( RAtom __far *atm1, RAtom __far *atm2,
                    RAtom __far *atm3, RAtom __far *atm4 )
{
    register double ax, ay, az;
    register double bx, by, bz;
    register double cx, cy, cz;
    register double px, py, pz;
    register double qx, qy, qz;
    register double cosom, om;
    register double rx, ry, rz;
    register double plen,qlen;

    ax = atm2->xorg - atm1->xorg + atm2->fxorg - atm1->fxorg
         + (double)(atm2->xtrl - atm1->xtrl)/40.;
    ay = atm2->yorg - atm1->yorg + atm2->fyorg - atm1->fyorg
         + (double)(atm2->ytrl - atm1->ytrl)/40.;
    az = atm2->zorg - atm1->zorg + atm2->fzorg - atm1->fzorg
         + (double)(atm2->ztrl - atm1->ztrl)/40.;
    if( !ax && !ay && !az )
        return 0.0;

    bx = atm3->xorg - atm2->xorg + atm3->fxorg - atm2->fxorg
         + (double)(atm3->xtrl - atm2->xtrl)/40.;
    by = atm3->yorg - atm2->yorg + atm3->fyorg - atm2->fyorg
         + (double)(atm3->ytrl - atm2->ytrl)/40.;
    bz = atm3->zorg - atm2->zorg + atm3->fzorg - atm2->fzorg
         + (double)(atm3->ztrl - atm2->ztrl)/40.;
    if( !bx && !by && !bz )
        return 0.0;

    cx = atm4->xorg - atm3->xorg + atm4->fxorg - atm3->fxorg
         + (double)(atm4->xtrl - atm3->xtrl)/40.;
    cy = atm4->yorg - atm3->yorg + atm4->fyorg - atm3->fyorg
         + (double)(atm4->ytrl - atm3->ytrl)/40.;
    cz = atm4->zorg - atm3->zorg + atm4->fzorg - atm3->fzorg
         + (double)(atm4->ztrl - atm3->ztrl)/40.;
    if( !cx && !cy && !cz )
        return 0.0;

#ifdef INVERT
    ay = -ay;  by = -by;  cy = -cy;
#endif
    az = -az;  bz = -bz;  cz = -cz;

    px = ay*bz - az*by;
    py = az*bx - ax*bz;
    pz = ax*by - ay*bx;

    qx = by*cz - bz*cy;
    qy = bz*cx - bx*cz;
    qz = bx*cy - by*cx;

    plen = px*px + py*py + pz*pz;
    qlen = qx*qx + qy*qy + qz*qz;

    cosom = (px*qx+py*qy+pz*qz)/sqrt(plen*qlen);

    if( cosom > 1.0 )
    {   return 0.0;
    } else if( cosom < -1.0 )
         return 180.0;

    om = -Rad2Deg*acos(cosom);

    if ( om < -180. ) om += 360.;
    if ( om > 180. ) om -= 360.;

    rx = py*qz - pz*qy;
    ry = pz*qx - px*qz;
    rz = px*qy - py*qx;

    if (bx*rx+by*ry+bz*rz > 0.) return -om;

    return om;
}


double CalcDihedral( RAtom __far *atm1, RAtom __far *atm2,
                     RAtom __far *atm3, RAtom __far *atm4 )
{
    return( 180.0 - CalcTorsion(atm1,atm2,atm3,atm4) );
}


/* Note: curr == prev->gnext! */
double CalcPhiAngle( Group __far *prev, Group __far *curr )
{
    RAtom __far *prevc;
    RAtom __far *currca;
    RAtom __far *currc;
    RAtom __far *currn;

    if( !(prevc  = FindGroupAtom(prev,2)) ) return 360.0;
    if( !(currca = FindGroupAtom(curr,1)) ) return 360.0;
    if( !(currc  = FindGroupAtom(curr,2)) ) return 360.0;
    if( !(currn  = FindGroupAtom(curr,0)) ) return 360.0;

    return CalcTorsion(prevc,currn,currca,currc);
}


/* Note: next == curr->gnext! */
double CalcPsiAngle( Group __far *curr, Group __far *next )
{
    RAtom __far *nextn;
    RAtom __far *currca;
    RAtom __far *currc;
    RAtom __far *currn;

    if( !(nextn  = FindGroupAtom(next,0)) ) return 360.0;
    if( !(currca = FindGroupAtom(curr,1)) ) return 360.0;
    if( !(currc  = FindGroupAtom(curr,2)) ) return 360.0;
    if( !(currn  = FindGroupAtom(curr,0)) ) return 360.0;

    return CalcTorsion(currn,currca,currc,nextn);
}

/* Note: prev == prev->gnext! */
double CalcOmegaAngle( Group __far *prev, Group __far *curr )
{
    RAtom __far *prevc;
    RAtom __far *prevca;
    RAtom __far *currn;
    RAtom __far *currca;

    if( !(prevca = FindGroupAtom(prev,1)) ) return 360.0;
    if( !(prevc  = FindGroupAtom(prev,2)) ) return 360.0;
    if( !(currn  = FindGroupAtom(curr,0)) ) return 360.0;
    if( !(currca = FindGroupAtom(curr,1)) ) return 360.0;

    return( CalcTorsion(prevca,prevc,currn,currca) );
}


void InitialiseAbstree( void )
{
    FalseExpr.type = OpConst | OpLftVal | OpRgtVal;
    FalseExpr.rgt.val = FalseExpr.lft.val = 0;

    TrueExpr.type = OpConst | OpLftVal | OpRgtVal;
    TrueExpr.rgt.val = TrueExpr.lft.val = 1;

    QChain = (void __far*)0;
    QGroup = (void __far*)0;
    QAtom = (void __far*)0;

    SymbolTable = (void __far*)0;

    FreeEntry = (void __far*)0;
    FreeSet = (void __far*)0;
    FreeExpr = NULL;
}


/* returns a string with a description of the current object (atom)   */
/* example: "Chain: A  Group:  T 20  Atom: N3   404" for select == ATM */
char *DescribeObj( AtomRef *ptr, Selection select )
{
  
#define BS 110
#define bs 109

  register char *str;
  static char buffer[BS];
  int strucflag=' ';
  
  /* needs to be initialised with whiteespaces, expect the last one */
  memset(buffer, ' ', bs * sizeof (char));

  /* identification of 'chain' */
  if( select == CHN || select == GRP || select == ATM || select == CRD){
    if( ptr->chn->ident!=' ' ){
      sprintf(&buffer[0], "Chain: %c", ptr->chn->ident);
    }
    buffer[8] = '\0';
  }

  /* identification of 'group' */
  if( select == GRP || select == ATM || select == CRD){
    str = Residue[ptr->grp->refno];
    if( ptr->atm->flag&HeteroFlag ){
      strcpy(&buffer[8], "  Hetero: ");
    }
    else{ 
      strcpy(&buffer[8], "  Group:  ");
    }
    sprintf(&buffer[18], "%c%c%c %3d", str[0],str[1],str[2],ptr->grp->serno);
    if( IsAmino(ptr->grp->refno) ){
       strucflag = Helix3Flag|Helix4Flag|Helix5Flag;
       if( ptr->grp->struc&strucflag )
	  strucflag = 'H';
       else if( ptr->grp->struc&SheetFlag )
	  strucflag = 'S';
       else if( ptr->grp->struc&TurnFlag )
	  strucflag = 'T';
       else
	  strucflag = 'C';
       sprintf(&buffer[25], " (%c)", (char)strucflag);
    }
    else{
       sprintf(&buffer[25], "     ");
    }
  }

  /* identification of 'atom' */
  if( select == ATM || select == CRD ){
    char *eptr;
    str = ElemDesc[ptr->atm->refno];
    strcpy(&buffer[29],"  Atom: ");
    if ( (ptr->atm->altl == ' ') || (ptr->atm->altl == '\0') ) {
      sprintf(&buffer[37], "%c%c%c%c   %5ld ", 
	    str[0], str[1], str[2], str[3], ptr->atm->serno );
    } else {
      sprintf(&buffer[37], "%c%c%c%c;%c %5ld ",
	    str[0], str[1], str[2], str[3] ,ptr->atm->altl, ptr->atm->serno );
    }
    if ( ptr->atm->model ) {
      buffer[49] = '/';
      FormatInteger(&buffer[50],(int)ptr->atm->model);
    } else {
      buffer[49] = '\0';
    }
    eptr = buffer+strlen(buffer);
    if( select == CRD ){
      register double x, y, z;

      x = (double)(ptr->atm->xorg + ptr->atm->fxorg + OrigCX)/250.0
         +(double)(ptr->atm->xtrl)/10000.0;
      y = (double)(ptr->atm->yorg + ptr->atm->fyorg + OrigCY)/250.0
         +(double)(ptr->atm->ytrl)/10000.0;
      z = (double)(ptr->atm->zorg + ptr->atm->fzorg + OrigCZ)/250.0
         +(double)(ptr->atm->ztrl)/10000.0;

#ifdef INVERT
      sprintf(eptr, "\n  Coordinates: %9.3f %9.3f %9.3f\n",x,-y,-z);
#else
      sprintf(eptr, "\n  Coordinates: %9.3f %9.3f %9.3f\n",x,y,-z);
#endif
    }
  }
  buffer[bs] = '\0'; /* to be sure to terminate the string */

  return buffer;
}
