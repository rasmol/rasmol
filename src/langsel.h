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
/* langsel.h
 */


typedef enum {
       English     =    0,
       French      =    1,
       German      =    2,
       Italian     =    3,
       Spanish     =    4,
       Russian     =    5,
       Chinese     =    6,
       Japanese    =    7,
       Bulgarian   =    8
} language;

#define NUMLANGS 9

typedef enum {
       ErrSyntax   =    0,
       ErrBigNum   =    1,
       ErrBadOpt   =    2,
       ErrParam    =    3,
       ErrFilNam   =    4,
       ErrBadLoad  =    5,
       ErrNotNum   =    6,
       ErrNotSep   =    7,
       ErrNotBrac  =    8,
       ErrNoCol    =    9,
       ErrColour   =   10,
       ErrBadArg   =   11,
       ErrBadExpr  =   12,
       ErrParen    =   13,
       ErrScript   =   14,
       ErrFunc     =   15,
       ErrSetName  =   16,
       ErrBadSet   =   17,
       ErrInScrpt  =   18,
       ErrOutScrpt =   19,
       ErrBadMolDB =   20,
       ErrNoBond   =   21,
       ErrBlocSel  =   22,
	   ErrNoToggle =  172,

	   StrCCompOn  =  173,
	   StrCCompOff =  174,
	   StrNoTogOn  =  175,
	   StrNoTogOff =  176,

       StrErrFile  =   30,
       StrNotFnd   =   31,
       StrCFmt     =   32,
       StrDcmp     =   33,
       StrSLong    =   34,
       StrSMem     =   35,
       StrHFil     =   36,
       StrHTop     =   37,
       StrHNone    =   38,
       StrHROpn    =   39,
       StrCTerm    =   40,
       StrCLong    =   41,
       StrFNum     =   42,
       StrCent     =   43,
       StrCClip    =   44,
       StrDFile    =   45,
       StrNPrint   =   46,
       StrUCell    =   47,
       StrSGroup   =   48,
       StrSymm     =   49,
       StrUnrec    =   50,
       StrIgnore   =   51,
       StrRCLong   =   52,
       StrSFile    =   53,
       StrILong    =   54,
       StrMolNam   =   55,
       StrClass    =   56,
       StrSecSt    =   57,
       StrNoAsmt   =   58,
       StrPDBRec   =   59,
       StrCalc     =   60,
       StrDBCode   =   61,
       StrExpTec   =   62,
       StrNumChn   =   63,
       StrNumGrp   =   64,
       StrNumAtm   =   65,
       StrNumBnd   =   66,
       StrNumBrg   =   67,
       StrNumHbd   =   68,
       StrNumHel   =   69,
       StrNumStrnd =   70,
       StrNumTrn   =   71,
       StrMalloc   =   72,
       StrXSRes    =   73,
       StrXSAtyp   =   74,

       StrMOpen    =   80,
       StrMInfo    =   81,
       StrMSaveAs  =   82,
       StrMClose   =   83,
       StrMPrint   =   84,
       StrMPSetup  =   85,
       StrMExit    =   86,
       StrMEmpty   =   87,

       StrMWirefr  =   90,
       StrMBackbn  =   91,
       StrMSticks  =   92,
       StrMSpacefl =   93,
       StrMBallStk =   94,
       StrMRibbons =   95,
       StrMStrands =   96,
       StrMCartoon =   97,
       StrMMolSurf =   98,

       StrMMonochr =   99,
       StrMCPK     =  100,
       StrMShapely =  101,
       StrMGroup   =  102,
       StrMChain   =  103,
       StrMTemp    =  104,
       StrMStruct  =  105,
       StrMUser    =  106,
       StrMModel   =  107,
       StrMAlt     =  108,

       StrMSlab    =  109,
       StrMHydr    =  110,
       StrMHet     =  111,
       StrMSpec    =  112,
       StrMShad    =  113,
       StrMStereo  =  114,
       StrMLabel   =  115,
       
       StrMPOff    =  116,
       StrMPIdent  =  117,
       StrMPDist   =  118,
       StrMPMon    =  119,
       StrMPAng    =  120,
       StrMPTrsn   =  121,
       StrMPLabl   =  122,
       StrMPCent   =  123,
       StrMPCoord  =  124,
       StrMPBond   =  125,
       StrMRBond   =  126,
       StrMRMol    =  127,
       StrMRAll    =  128,

       StrMBMP     =  129,
       StrMGIF     =  130,
       StrMIRGB    =  131,
       StrMPPM     =  132,
       StrMSRast   =  133,
       StrMPostscr =  134,
       StrMPICT    =  135,
       StrMVECPS   =  136,
       StrMMSCR    =  137,
       StrMKine    =  138,
       StrMPOVRAY  =  139,
       StrMVRML    =  140,
       StrMRPP     =  141,
       StrMR3D     =  142,
       StrMSCR     =  143,


       StrMAbout   =  144,
       StrMUserM   =  145,
       
       StrMUndo    =  146,
       StrMCut     =  147,
       StrMCopy    =  148,
       StrMPaste   =  149,
#ifdef APPLEMAC
       StrMClear   =  150,
#else
       StrMDelete  =  150,
#endif
       StrMSelAll  =  151,

       StrMFile    =  152,
       StrMEdit    =  153,
       StrMDisplay =  154,
       StrMColour  =  155,
       StrMOpt     =  156,
       StrMSettings=  157,
       StrMExport  =  158,
#ifdef APPLEMAC
       StrMWindow  =  159,
       StrMHelp    =  160,
       StrMMainWin =  161,
       StrMCmndLin =  162,
#else
       StrMHelp    =  159,
#endif

       StrPrmtPDB  =  163,
       StrPrmtImg  =  164,
       StrPrmtMol  =  165,
       StrWarn     =  166,
       StrChain    =  167,
       
       StrRegister =  168,
       StrDonate   =  169,
       StrWarranty =  170,
       StrNoShow   =  171


} strflag;

#define MaxStrFlag     177
typedef struct {
      char *    msg;
      strflag   msgno;
      language  lang;
      int       aux;
} langstr;

typedef struct {
      char *   menufontvar;
#ifdef MSWIN
      BYTE     menucharset;
#endif
      char *   menufontlist;
      language lang;	
} langfont;


#ifdef LANGSEL

char * MsgStrs[MaxStrFlag];
int    MsgLens[MaxStrFlag];
int    MsgAuxl[MaxStrFlag];
language     Language;
language    TermLanguage;

#else

extern char * MsgStrs[MaxStrFlag];
extern int    MsgLens[MaxStrFlag];
extern int    MsgAuxl[MaxStrFlag];
extern language   Language;
extern language   TermLanguage;
extern langfont langfonts[NUMLANGS];

#endif

void SwitchLang( language );
language str2lang ( const char * );
const char * lang2str ( language lang);
void UpdateLanguage ( void );
