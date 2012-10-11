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
/* molecule.h
 $Log$
 Revision 1.9  2008/06/11 01:40:54  yaya
 Improve gradient for map surfaces and brighten image;
 Add parenthesized selections before all commands;
 Change saveSelection and loadSelection to
 SaveAtomSelection and LoadAtomSelection -- HJB

 Revision 1.8  2008/06/09 17:48:11  hk0i
 added loadSelection() and saveSelection() routines for new color commands. *gm*

 Revision 1.7  2008/03/22 18:42:53  yaya
 Post release cleanup and credit to Ikonen in file headers. -- HJB

 Revision 1.6  2008/03/17 03:01:31  yaya
 Update to agree with 2.7.4.2 release and T. Ikonen GTK mods -- HJB

 Revision 1.3  2008/03/17 01:32:41  yaya
 Add gtk mods by tpikonen, and intergate with 2.7.4.2 mods -- HJB

 Revision 1.5  2008/03/16 22:25:22  yaya
 Align comments with production version; Update rasmol_install and
 rasmol_run shell scripts for Japanese and Chinese; Align logic for
 positioning and sizing initial window with windows version -- HJB

 Revision 1.2  2008/01/28 03:29:37  yaya
 Update CVS to RasMol_2.7.4.1 -- HJB

 Revision 1.4  2007/11/19 03:28:39  yaya
 Update to credits for 2.7.4 in manual and headers
 Mask code added -- HJB

 Revision 1.3  2007/10/23 02:27:55  yaya
 Preliminary mods for revised PDB format derived from Rutgers mods.
 Partial changes for map tangles -- HJB

 Revision 1.2  2007/07/02 12:44:39  yaya
 Partial preliminary map code -- HJB

 Revision 1.1.1.1  2007/03/01 01:16:33  todorovg
 Chinese working versio from rasmol_ru initial import

 Revision 1.3  2006/11/01 03:23:50  yaya
 Update NSIS windows installer for more script types and to fix
 misplaced script instructions for data files; add document and
 script icons directly in raswin.exe; add credit line to
 G. A. Pozhvanov in comments for Russian translations. -- HJB

 Revision 1.2  2006/09/17 10:53:55  yaya
 Clean up headers and start on code for X11 -- HJB

 Revision 1.1.1.1  2006/09/16 18:45:51  yaya
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

 Revision 1.1  2001/01/31 02:13:45  yaya
 Initial revision

 Revision 1.6  2000/08/27 18:30:53  yaya
 fix for nested bond rotation bug

 Revision 1.5  2000/08/26 18:12:56  yaya
 Updates to header comments in all files

 Revision 1.4  2000/08/21 21:08:03  yaya
 semi-final ucb mods

 Revision 1.3  2000/08/09 01:18:33  yaya
 Rough cut with ucb

 Revision 1.2  2000/08/03 18:32:43  yaya
 Parametrization for alt conformer bond radius

 */
#define MAXMASK 40
#define MAXELEM 1024
#define MINELEM 29
#define MAXRES  104
#define MINRES  59
#define CIS     90  /* max. omega-angle to form a cis-peptide bond */


#define IsAmino(x)       ((x)<=23)
#define IsAminoNucleo(x) ((x)<=42 || ((x)>=54 && (x)<=58))
#define IsNucleo(x)      ((((x)>=24) && ((x)<=42)) || ((x)>=54 && (x)<=58))
#define IsProtein(x)     (((x)<=23) || (((x)>=43) && ((x)<=45)))
#define IsDNA(x)         ((((x)>=24) && ((x)<=27))||  ((x)>=54 && (x)<=58))
#define IsSolvent(x)     (((x)>=46) && ((x)<=49))
#define IsWater(x)       (((x)==46) || ((x)==47))
#define IsIon(x)         (((x)==48) || ((x)==49))

#define IsPyrimidine(x)  (IsCytosine(x) || IsThymine(x))
#define IsPurine(x)      (IsAdenine(x) || IsGuanine(x))
#define IsRNA(x)         ((((x)>=24) && ((x)<=26)) || ((x)>=28 && (x)<=42))
#define NucleicCompl(x)  ((x)^3)


#define IsProline(x)     ((x)==11)
#define IsCysteine(x)    ((x)==17)

#define IsAdenine(x)     ((x)==24 || (x)==54)
#define IsCytosine(x)    ((x)==25 || (x)==55 )
#define IsGuanine(x)     ((x)==26 || (x)==56 )
#define IsThymine(x)     ((x)==27 || (x)==57 )

#define IsAlphaCarbon(x)     ((x)==1)
#define IsSugarPhosphate(x)  ((x)==7)
#define IsAminoBackbone(x)   ((x)<=3)
#define IsShapelyBackbone(x) ((x)<=7)
#define IsNucleicBackbone(x) (((x)>=7) && ((x)<=18))
#define IsShapelySpecial(x)  ((x)==19)
#define IsCysteineSulphur(x) ((x)==20)
#define IsCoenzyme(x)        (((x)>=50) && ((x)<=53))


/*=================*/
/*  Database Flags */
/*=================*/

#define SelectFlag      0x01
#define SaveFlag		0x1000
#define DrawBondFlag    0x0e
#define AllAtomFlag     0x1c
#define HelixFlag       0x03
#define DrawKnotFlag    0x7e
#define WideKnotFlag    0x0e

/* Atom Flags */
#define SphereFlag      0x02     /* Sphere representation         */
#define HeteroFlag      0x04     /* HETATM record                 */
#define HydrogenFlag    0x08     /* Hydrogen atom                 */
#define NormAtomFlag    0x10
#define NonBondFlag     0x20
#define BreakFlag       0x40     /* Break in backbone              */
#define StarFlag        0x80     /* Star representation            */
#define TouchFlag       0x100    /* Touch by probe                 */
#define ExpandFlag      0x200    /* Expand by probe radius         */
#define SurfBondFlag    0x400    /* Atom is part of a surface bond */


/* Bond Flags */
#define WireFlag        0x02     /* Depth-cued wireframe         */
#define DashFlag        0x04     /* Dashed Depth-cued wireframe  */
#define CylinderFlag    0x08     /* Line/Cylinder representation */

#define HydrBondFlag    0x00     /* Hydrogen bond [place keeper] */
#define NormBondFlag    0x10
#define DoubBondFlag    0x20
#define TripBondFlag    0x40
#define AromBondFlag    0x80


/* Group Flags */
#define CystineFlag     0x01     /* Disulphide bonded cysteine  */
#define StrandFlag      0x02     /* Strands representation      */
#define DashStrandFlag  0x04     /* Dash Strands representation */
#define RibbonFlag      0x08     /* Solid Ribbon representation */
#define TraceFlag       0x10     /* Smooth trace representation */
#define CartoonFlag     0x20     /* Richardson protein cartoon  */
#define DotsFlag        0x40     /* Dotted trace representation */
#define CisBondFlag     0x80     /* Cis bonded residue          */

/* Structure Flags */
#define Helix3Flag      0x01     /* 3,10-Helix structure       */
#define Helix4Flag      0x02     /* Alpha Helix structure      */
#define Helix5Flag      0x03     /* 5-Helix structure          */
#define SheetFlag       0x04     /* Beta Sheet structure       */
#define TurnFlag        0x08     /* Turn Secondary structure   */


/*=====================*/
/*  Molecule Database  */
/*=====================*/

#define MaxBonds 6

typedef struct _Atom {
        struct _Atom __far *anext;        /* Linked list of atoms  */
        struct _Atom __far *bucket;       /* Sphere Y-Bucket       */
        struct _Atom __far *next;         /* Active Object List    */
        Long   xorg, yorg, zorg;          /* World Co-ordinates    */
        Long   fxorg, fyorg, fzorg;       /* Offsets for rotations */
        Long   x, y, z;                   /* Image Co-ordinates    */
                                          /* also used as scratch  */
        short  xtrl, ytrl, ztrl;          /* Trailing Bits         */
        short  radius;                    /* World Radius          */
        short  temp;                      /* Temperature Factor    */
        short  col;                       /* Atom Colour           */
        Long   serno;                     /* Atom Serial Number    */
        void   *label;                    /* Atom Label Structure  */
        Byte   elemno;                    /* Atomic Number         */
        int    refno;                     /* ElemDesc index number */
        short  flag;                      /* Database flags        */
        char   altl;                      /* Alternate Location    */
        short  irad;                      /* Image Radius          */
        short  mbox;                      /* Shadow Casting NOnce  */
        short  model;                     /* Atom Model Number     */
        short  visited;                   /* For bond rotation     */
        short  nbonds;                    /* For bond rotation     */ 
        struct _Atom __far *bonds[MaxBonds];
        void   *surfbonds;                /* Surface bonds list    */
    } RAtom;


typedef struct _Bond {
        struct _Bond __far *bnext;       /* Linked list of bonds  */
        RAtom __far *srcatom;            /* Source Atom Ptr       */
        RAtom __far *dstatom;            /* Destination Atom Ptr  */
        short radius;                    /* World Radius          */
        short irad;                      /* Image Radius          */
        short aradius;                   /* World Alt Radius      */
        short iarad;                     /* Image Alt Radius      */
        short col;                       /* Bond Colour           */
        short flag;                      /* Database flags        */
        char  altl;                      /* Bond Alternate Loc    */
    } Bond;

typedef struct _SurfBond {
        struct _SurfBond __far *sbnext;   /* Linked list of bonds  */
        RAtom  __far *srcatom;            /* Source Atom Ptr       */
        RAtom  __far *dstatom;            /* Destination Atom Ptr  */
        Long   sxyz;                      /* Bond length           */
        Long   wp;                        /* Torus waist           */
        Long   w1,w2;                     /* Torus throats         */
        Long   u1,u2;                     /* Probe offsets         */
        Long   t1,t2;                     /* Torus offsets         */
        short  col;                       /* Bond Colour           */
        short  flag;                      /* Database flags        */
        char   altl;                      /* Bond Alternate Loc    */
    } SurfBond;


typedef struct _Group {
        struct _Group __far *gnext;       /* Linked list of groups */
        RAtom __far *alist;               /* Linked list of atoms  */
        short serno;                      /* Group serial number   */
        short sserno;                     /* Secondary serial no.  */ 
        short width;                      /* Ribbon Width          */
        short col1;                       /* Ribbon Colour #1      */
        short col2;                       /* Ribbon Colour #2      */
        char  insert;                     /* PDB insertion code    */
        char  sinsert;                    /* Secondary insert code */
        Byte  refno;                      /* Residue index number  */
        Byte  struc;                      /* Secondary Structure   */
        short flag;                       /* Database flags        */
        short model;                      /* Group Model Number    */
    } Group;
 
#ifdef APPLEMAC
/* Avoid Name Clash! */
#define Chain ChainSeg
#endif

typedef struct _ChainSeg {
        struct _ChainSeg __far *cnext;    /* Linked list of chains     */
        Group __far *glist;               /* Linked list of groups     */
        Bond __far *blist;                /* Linked list of back bonds */
        char ident;                       /* Chain identifier          */
        Byte model;                       /* NMR Model / Symmetry      */
    } Chain;

typedef struct _AtomRef {
        Chain __far *chn;
        Group __far *grp;
        RAtom  __far *atm;
    } AtomRef;

typedef struct _HBond {
        struct _HBond __far *hnext;       /* Ordered list of hbonds   */
        RAtom __far *srcCA;               /* Source Alpha Carbon      */
        RAtom __far *dstCA;               /* Destination Alpha Carbon */
        RAtom __far *dst;                 /* Acceptor [=CO] Atom Ptr  */
        RAtom __far *src;                 /* Donor [=NH] Atom Ptr     */
        short energy;                     /* Hydrogen bond energy     */
        short radius;                     /* World Radius             */
        short irad;                       /* Image Radius             */
        short aradius;                    /* World Alt Radius         */
        short iarad;                      /* Image Alt Radius         */
        Char offset;                      /* Signed Offset            */
        short flag;                       /* Database flags           */
        Byte col;                         /* Hydrogen bond colour     */
        char altl;                        /* Bond Alternate Loc       */
    } HBond;

typedef struct _Molecule {
        HBond __far *slist;               /* Linked list of SS bonds  */
        HBond __far *hlist;               /* Linked list of hbonds    */
        Chain __far *clist;               /* Linked list of chains    */
        Bond __far *blist;                /* Linked list of bonds     */
        SurfBond __far *sblist;           /* Linked list of surf bonds*/
    } Molecule;



/*========================*/
/* Other Consts & Structs */
/*========================*/

#define SourceNone   0
#define SourcePDB    1
#define SourceCalc   2
 
#define SerNoFlag 0x01
#define ResNoFlag 0x02

typedef struct {
        short radius;
        char  mask[19];
        Byte  flags;
        Byte  r;
        Byte  g;
        Byte  b;
        } MaskDesc;

typedef struct _IntCoord {
        struct _IntCoord __far *inext;
        short na,nb,nc;
        short refno;
        Real dihed;
        Real angle;
        Real dist;
    } IntCoord;

typedef struct _InfoStruct {
        char filename[1024];
        char moleculename[80];
        char classification[42];
        char date[12];
        char technique[80];
        char identcode[80];

        char spacegroup[12];
        Real cellalpha, cellbeta, cellgamma;
        Real cella, cellb, cellc;

        double vecf2o[3], veco2f[3], matf2o[3][3], mato2f[3][3];
        double cell[6];

        Long bondcount;
        Long srfbondcount;
        int chaincount;
        int ssbondcount;
        int hbondcount;
        int cisbondcount;

        int structsource;
        int laddercount;
        int helixcount;
        int turncount;
    } InfoStruct;

#ifdef APPLEMAC
void RegisterAlloc(void __far * );
#else
#define RegisterAlloc(x)
#endif
void FreeAlloc(void __far * );

/* used to describe an defined part of the selected molecule */
typedef enum{NO, ATM, CRD, GRP, CHN} Selection;

#include <CNearTree.h>
#ifdef MOLECULE
/* Avoid SGI Compiler Warnings! */
char Residue[MAXRES][4] = {
    /*===============*/
    /*  Amino Acids  */
    /*===============*/

/* Ordered by Cumulative Frequency in Brookhaven *
 * Protein Databank, December 1991               */

          "ALA", /* 8.4% */     "GLY", /* 8.3% */
          "LEU", /* 8.0% */     "SER", /* 7.5% */
          "VAL", /* 7.1% */     "THR", /* 6.4% */
          "LYS", /* 5.8% */     "ASP", /* 5.5% */
          "ILE", /* 5.2% */     "ASN", /* 4.9% */
          "GLU", /* 4.9% */     "PRO", /* 4.4% */
          "ARG", /* 3.8% */     "PHE", /* 3.7% */
          "GLN", /* 3.5% */     "TYR", /* 3.5% */
          "HIS", /* 2.3% */     "CYS", /* 2.0% */
          "MET", /* 1.8% */     "TRP", /* 1.4% */

          "ASX", "GLX", "PCA", "HYP",

    /*===================*/
    /*  DNA Nucleotides  */
    /*===================*/
          "  A", "  C", "  G", "  T",

    /*===================*/
    /*  RNA Nucleotides  */
    /*===================*/
          "  U", " +U", "  I", "1MA", 
          "5MC", "OMC", "1MG", "2MG", 
          "M2G", "7MG", "OMG", " YG", 
          "H2U", "5MU", "PSU",

    /*=================*/
    /*  Miscellaneous  */ 
    /*=================*/
          "UNK", "ACE", "FOR", "HOH",
          "DOD", "SO4", "PO4", "NAD",
          "COA", "NAP", "NDP",
          
    /*==========================================*/
    /*  DNA Nucleotides PDB Revision, Jul 2007  */
    /*==========================================*/
    
         " DA", " DC", " DG", " DT"," DI" 
};


/* Avoid SGI Compiler Warnings! */
char ElemDesc[MAXELEM][12] = {
    { ' ', 'N', ' ', ' ', '\0' },  /* 0*/
    { ' ', 'C', 'A', ' ', '\0' },  /* 1*/
    { ' ', 'C', ' ', ' ', '\0' },  /* 2*/
    { ' ', 'O', ' ', ' ', '\0' },  /* 3*/   /* 0-3   Amino Acid Backbone    */
    { ' ', 'C', '\'', ' ', '\0' }, /* 4*/
    { ' ', 'O', 'T', ' ', '\0' },  /* 5*/
    { ' ', 'S', ' ', ' ', '\0' },  /* 6*/
    { ' ', 'P', ' ', ' ', '\0' },  /* 7*/   /* 4-7   Shapely Amino Backbone */
    { ' ', 'O', '1', 'P', '\0' },  /* 8*/
    { ' ', 'O', '2', 'P', '\0' },  /* 9*/
    { ' ', 'O', '5', '*', '\0' },  /*10*/
    { ' ', 'C', '5', '*', '\0' },  /*11*/
    { ' ', 'C', '4', '*', '\0' },  /*12*/
    { ' ', 'O', '4', '*', '\0' },  /*13*/
    { ' ', 'C', '3', '*', '\0' },  /*14*/
    { ' ', 'O', '3', '*', '\0' },  /*15*/
    { ' ', 'C', '2', '*', '\0' },  /*16*/
    { ' ', 'O', '2', '*', '\0' },  /*17*/
    { ' ', 'C', '1', '*', '\0' },  /*18*/   /* 7-18  Nucleic Acid Backbone  */
    { ' ', 'C', 'A', '2', '\0' },  /*19*/   /* 19    Shapely Special        */
    { ' ', 'S', 'G', ' ', '\0' },  /*20*/   /* 20    Cysteine Sulphur       */
    { ' ', 'N', '1', ' ', '\0' },  /*21*/
    { ' ', 'N', '2', ' ', '\0' },  /*22*/
    { ' ', 'N', '3', ' ', '\0' },  /*23*/
    { ' ', 'N', '4', ' ', '\0' },  /*24*/
    { ' ', 'N', '6', ' ', '\0' },  /*25*/
    { ' ', 'O', '2', ' ', '\0' },  /*26*/
    { ' ', 'O', '4', ' ', '\0' },  /*27*/
    { ' ', 'O', '6', ' ', '\0' }   /*28*/   /* 21-28 Nucleic Acid H-Bonding */
    };


InfoStruct Info;
int MainGroupCount;
int HetaGroupCount;
Long MainAtomCount; 
Long HetaAtomCount;
int CisBondCutOff;

Long MinX, MinY, MinZ;
Long MaxX, MaxY, MaxZ;

int HMinMaxFlag, MMinMaxFlag;
int MinMainTemp, MaxMainTemp;
int MinHetaTemp, MaxHetaTemp;
int MinMainRes,  MaxMainRes;
int MinHetaRes,  MaxHetaRes;
int MinAltl,     MaxAltl;

short MinModel, MaxModel;

Molecule __far *CurMolecule;
Chain __far *CurChain;
Group __far *CurGroup;
RAtom __far *CurAtom;

IntCoord __far *IntList;
Molecule __far *Database;
MaskDesc UserMask[MAXMASK];
Long MinHBondDist, MaxHBondDist;
Long MinBondDist,  MaxBondDist;
int ElemNo,ResNo;
int HasHydrogen;
int MaskCount;
int NMRModel;
int NullBonds;
int MarkAtoms;

int HBondChainsFlag;

SurfBond __far *FreeSurfBond;
HBond __far *FreeHBond;
Bond __far *FreeBond;
Bond __far *NewBond;

CNearTreeHandle AtomTree;
int NeedAtomTree;


#else
extern char Residue[MAXRES][4];
extern char ElemDesc[MAXELEM][12];
extern InfoStruct Info;

extern int MainGroupCount;
extern int HetaGroupCount;
extern Long MainAtomCount;
extern Long HetaAtomCount;
extern int CisBondCutOff;

extern Long MinX, MinY, MinZ;
extern Long MaxX, MaxY, MaxZ;

extern int HMinMaxFlag, MMinMaxFlag;
extern int MinMainTemp, MaxMainTemp;
extern int MinHetaTemp, MaxHetaTemp;
extern int MinMainRes,  MaxMainRes;
extern int MinHetaRes,  MaxHetaRes;
extern int MinAltl,     MaxAltl;

extern short MinModel, MaxModel;

extern Molecule __far *CurMolecule;
extern Chain __far *CurChain;
extern Group __far *CurGroup;
extern RAtom __far *CurAtom;

extern IntCoord __far *IntList;
extern Molecule __far *Database;
extern MaskDesc UserMask[MAXMASK];
extern Long MinHBondDist, MaxHBondDist;
extern Long MinBondDist,  MaxBondDist;
extern int ElemNo,ResNo;
extern int HasHydrogen;
extern int MaskCount;
extern int NMRModel;
extern int NullBonds;
extern int MarkAtoms;

extern int HBondChainsFlag;

extern SurfBond __far *FreeSurfBond;
extern HBond __far *FreeHBond;
extern Bond __far *FreeBond;
extern Bond __far *NewBond;

extern CNearTreeHandle AtomTree;
extern int NeedAtomTree;

#ifndef APPLEMAC
#define RegisterAlloc(x)
#endif
#endif

void CreateChain( int );
void CreateGroup( int );
void ProcessGroup( int );
void CreateMolGroup( void );
void CreateNextMolGroup( void );
int FindResNo( char* );

RAtom __far *CreateAtom( void );
RAtom __far *FindGroupAtom( Group __far*, int );
void ProcessAtomType( RAtom __far*, char[2] );
void ProcessAtom( RAtom __far* );

int NewAtomType( char* );
int SimpleAtomType( char* );
int ComplexAtomType( char* );

Bond __far *ProcessBond( RAtom __far*, RAtom __far*, int );
void CreateBond( Long, Long, int );
void CreateBondOrder( Long, Long );
void CreateNewBond( Long, Long );
int PreTestSurface(  RAtom __far *,  RAtom __far *, 
                   Long [3],  int *, Long [3] );
void CreateMoleculeBonds( int, int, int );
int CreateAtomTree( void );
void CreateSurfaceBonds( void );
RAtom __far *FindCysSulphur( Group __far *group );
void FindDisulphideBridges( void );
void TestDisulphideBridge( Group __far *, Group __far *, RAtom __far * );
void FindCisBonds( void );
void CalcHydrogenBonds( void );

void InitInternalCoords( void );
IntCoord __far* AllocInternalCoord( void );
int ConvertInternal2Cartesian( void );
void FreeInternalCoords( void );

void DetermineStructure( int );
void RenumberMolecule( int );

void InitialiseDatabase( void );
void ReviseTitle( void );
void DescribeMolecule( void );
void DestroyDatabase( void );
void PurgeDatabase( void );

void LoadAtomSelection( void );
void SaveAtomSelection( void );
#ifdef APPLEMAC
void RegisterAlloc( void *);
#endif

