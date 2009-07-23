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
/* cexio.c
 */

#include <stdlib.h>
#include <stdio.h>

#include "rasmol.h"
#include "molecule.h"
#include "command.h"
#include "infile.h"

#include "cx.h"
#include "cx_molecule.h"

#define PROP_ATSYM   "atomic symbol"
#define PROP_BONDO   "bond order"

#define PROP_MNAME   "molname"
#define PROP_ALABS   "atomname"
#define PROP_RESID   "resname"
#define PROP_CHAIN   "chain"
#define PROP_RESNO   "resno"
#define PROP_COORD   "coordinates"
#define PROP_BVALU   "bvalue"
#define PROP_CHARG   "charge"
#define PROP_RADIU   "radius"


static cx_String prop_alabs;
static cx_String prop_resid;
static cx_String prop_chain;
static cx_String prop_resno;
static cx_String prop_coord;
static cx_String prop_tempr;



static cx_String get_atom_tuple(  cx_Object mol,  cx_String prop )
{
    cx_Object tupleseq, tuple;

    if( (tupleseq = cx_prefix2atuples(mol,prop)) )
    {   tuple = cx_next(tupleseq);
    } else tuple = (cx_Object)NULL;
 
    if( !tuple )
    {   /* No such property! */
        cx_destroy( tupleseq );
        return (cx_String)NULL;
    }
 
    /* Ambiguous atom property prefix! */
    /* cx_next(tupleseq) or !cx_atend(tupleseq) */

    cx_destroy(tupleseq);
    return cx_atomtuple_name(tuple);
}
 

static void padfield( char *dst, char *src, int len )
{
    register int i;

    for( i=0; i<len; i++ )
    {   if( *src )
        {   *dst++ = *src++;
        } else *dst++ = ' ';
    }
    *dst = '\0';
}
 

static int process_cx_atom( cx_Object atom, int serno )
{
    auto char buffer[5];
    register Group __far *group;
    register Atom __far *ptr;
    register int refno,resno;
    register int chain;
    cx_String prop;
    float x,y,z,t;

    /* Test for valid 3D co-ordinates */
    prop = cx_sprop(atom,prop_coord);
    if( !prop ) return False;
    if( sscanf(prop,"%g,%g,%g",&x,&y,&z) != 3 )
        return False;

    /* Determine Chain */
    prop = cx_sprop(atom,prop_chain);
    if( prop && *prop ) 
    {   chain = *prop;
    } else chain = ' ';

    if( CurChain && (CurChain->ident!=chain) )
    {   CurChain = CurMolecule->clist;
        while( CurChain )
            if( CurChain->ident != chain )
            {   CurChain = CurChain->cnext;
            } else break;
    }
    if( !CurChain ) CreateChain( chain );

    /* Determine Residue */
    resno = cx_iprop(atom,prop_resno);
    prop = cx_sprop(atom,prop_resid);
    if( !prop || !*prop ) 
    {   refno = FindResNo("MOL");
    } else refno = FindResNo(prop);

    if( !CurGroup || CurGroup->refno!=refno || CurGroup->serno!=resno )
    {   group = CurChain->glist;
        CurGroup = (Group __far*)0;
        CurAtom = (Atom __far*)0;

        while( group && group->serno <= resno )
        {   CurGroup = group;
            if( (group->serno==resno) && (group->refno==refno) ) break;
            group = group->gnext;
        }

        if( !group || (group->serno>resno) ) 
        {   CreateGroup( GroupPool );
            CurGroup->serno = resno;
            CurGroup->refno = refno;
            ProcessGroup( False );
        }
    }

    /* Process Atom */
    ptr = CreateAtom();
    ptr->serno = serno;

    prop = cx_sprop(atom,prop_alabs);
    if( prop )
    {   padfield(buffer,prop,4);
        ptr->refno = ComplexAtomType(buffer);
    } else
    {   prop = cx_sprop(atom,PROP_ATSYM);
        if( prop )
        {   padfield(buffer,prop,4);
            ptr->refno = SimpleAtomType(buffer);
        } else ptr->refno = SimpleAtomType("Du  ");
    }

    t = (float)cx_rprop(atom,prop_tempr);
    ptr->temp = (short)(t*100.0);

    ptr->xorg =  (Long)(x*250.0);
    ptr->yorg =  (Long)(y*250.0);
    ptr->zorg = -(Long)(z*250.0);
    ProcessAtom( ptr );
    return True;
}


static void process_cx_bond( cx_Object bond )
{
    cx_Object atoms,atom;
    register int src,dst;
    register int i,flag;

    i = cx_iprop(bond,PROP_BONDO);
    if( i==2 )
    {   flag = DoubBondFlag;
    } else if( i == 3 )
    {   flag = TripBondFlag;
    } else flag = NormBondFlag;

    atoms = cx_stream(bond,CX_OB_ATOM);
    if( atom = cx_next(atoms) )
        if( src = cx_iprop(atom,"_serno") )
            if( atom = cx_next(atoms) )
                if( dst = cx_iprop(atom,"_serno") )
                    CreateBond(src,dst,flag);
    cx_destroy(atoms);
}


static void load_cx_molecule( cx_Object mol )
{
    cx_String molname;
    cx_Object atoms,atom;
    cx_Object bonds,bond;
    register int serno;
    register int i;

    if( (molname = cx_sprop(mol,PROP_MNAME)) )
    {   for( i=0; molname[i] && (i<62); i++ )
            Info.moleculename[i] = molname[i];
        while( i && molname[i-1]==' ' ) i--;
        Info.moleculename[i] = '\0';
    }

    /* Molecule must have 3d co-ordinates */
    prop_coord = get_atom_tuple(mol,PROP_COORD);
    if( !prop_coord ) return;

    prop_alabs = get_atom_tuple(mol,PROP_ALABS);
    prop_resid = get_atom_tuple(mol,PROP_RESID);

    prop_tempr=get_atom_tuple(mol,PROP_BVALU);
    if( !prop_tempr ) prop_tempr = get_atom_tuple(mol,PROP_CHARG);
    if( !prop_tempr ) prop_tempr = get_atom_tuple(mol,PROP_RADIU);

    prop_chain = get_atom_tuple(mol,PROP_CHAIN);
    prop_resno = get_atom_tuple(mol,PROP_RESNO);

    serno = 1;
    atoms = cx_stream(mol,CX_OB_ATOM);
    while( atom = cx_next(atoms) )
    {   if( process_cx_atom(atom,serno) )
        {   cx_set_iprop(atom,"_serno",serno++);
        } else cx_set_iprop(atom,"_serno",0);
    }
    cx_destroy(atoms);

    bonds = cx_stream(mol,CX_OB_BOND);
    while( bond = cx_next(bonds) )
        process_cx_bond(bond);
    cx_destroy(bonds);
}


int LoadCEXMolecule( FILE *fp )
{
#ifdef CX_OB_IOSTREAM
    register cx_Object ins;
    register cx_Object obj;

    UnusedArgument(fp);

    cx_molecule_pkg();
    ins = cx_create_iostream(DataFileName,CX_IO_READ);
    while( (obj = cx_next(ins)) ) 
    {   if( cx_type(obj) == CX_OB_MOLECULE )
        {   load_cx_molecule(obj);
            cx_destroy(obj);
            break;
        } else cx_destroy(obj);
    }
    cx_destroy(ins);
    /* cx_cleanup(); */
    return True;
    
#else
    register cx_Object obj;

    if( !fp ) return False;

    cx_molecule_pkg();
    while( (obj = cx_receive(NULL,fp,NULL)) ) 
    {   if( cx_type(obj) == CX_OB_MOLECULE )
        {   load_cx_molecule(obj);
            cx_destroy(obj);
            break;
        } else cx_destroy(obj);
    }
    /* cx_cleanup(); */
    return True;
#endif
}
 
 
int SaveCEXMolecule( char *filename )
{
    UnusedArgument(filename);

    if( !Database )
        return False;
    return True;
}
