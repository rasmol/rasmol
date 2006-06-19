
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
/* langsel.h
 */


typedef enum {
       English     =    0,
       French      =    1,
       German      =    2,
       Italian     =    3,
       Spanish     =    4
} language;

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

       StrMGIF     =  129,
       StrMPostscr =  130,
       StrMPPM     =  131,
       StrMIRGB    =  132,
       StrMSRast   =  133,
       StrMBMP     =  134,
       StrMPICT    =  135,

       StrMAbout   =  136,
       StrMUserM   =  137,
       
       StrMUndo    =  138,
       StrMCut     =  139,
       StrMCopy    =  140,
       StrMPaste   =  141,
#ifdef APPLEMAC
       StrMClear   =  142,
#else
       StrMDelete  =  142,
#endif
       StrMSelAll  =  143,

       StrMFile    =  144,
       StrMEdit    =  145,
       StrMDisplay =  146,
       StrMColour  =  147,
       StrMOpt     =  148,
       StrMSettings=  149,
       StrMExport  =  150,
#ifdef APPLEMAC
       StrMWindow  =  151,
       StrMHelp    =  152,
       StrMMainWin =  153,
       StrMCmndLin =  154,
#else
       StrMHelp    =  151,
#endif

       StrPrmtPDB  =  155,
       StrPrmtImg  =  156,
       StrPrmtMol  =  157,
       StrWarn     =  158,
       StrChain    =  159


} strflag;

#define MaxStrFlag     160
typedef struct {
      char *    msg;
      strflag   msgno;
      language  lang;
      int       aux;
} langstr;


#ifdef LANGSEL

char * MsgStrs[MaxStrFlag];
int    MsgLens[MaxStrFlag];
int    MsgAuxl[MaxStrFlag];

#else

extern char * MsgStrs[MaxStrFlag];
extern int    MsgLens[MaxStrFlag];
extern int    MsgAuxl[MaxStrFlag];

#endif

void SwitchLang( language );
