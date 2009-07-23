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
/* font.h
 $Log$
 Revision 1.5  2008/03/22 18:42:51  yaya
 Post release cleanup and credit to Ikonen in file headers. -- HJB

 Revision 1.4  2008/03/17 03:01:31  yaya
 Update to agree with 2.7.4.2 release and T. Ikonen GTK mods -- HJB

 Revision 1.3  2008/03/17 01:32:41  yaya
 Add gtk mods by tpikonen, and intergate with 2.7.4.2 mods -- HJB

 Revision 1.3  2008/03/16 22:25:21  yaya
 Align comments with production version; Update rasmol_install and
 rasmol_run shell scripts for Japanese and Chinese; Align logic for
 positioning and sizing initial window with windows version -- HJB

 Revision 1.2  2008/01/28 03:29:37  yaya
 Update CVS to RasMol_2.7.4.1 -- HJB

 Revision 1.2  2007/11/19 03:28:39  yaya
 Update to credits for 2.7.4 in manual and headers
 Mask code added -- HJB

 Revision 1.1.1.1  2007/03/01 01:16:33  todorovg
 Chinese working versio from rasmol_ru initial import

 Revision 1.4  2007/02/02 21:08:59  yaya
 Remove // comments for AIX build
 Fix signed length conflict
 Fix array bounds violation for molecule names in multiple.c -- HJB

 Revision 1.3  2006/11/01 03:23:50  yaya
 Update NSIS windows installer for more script types and to fix
 misplaced script instructions for data files; add document and
 script icons directly in raswin.exe; add credit line to
 G. A. Pozhvanov in comments for Russian translations. -- HJB

 Revision 1.2  2006/09/17 10:53:55  yaya
 Clean up headers and start on code for X11 -- HJB

 Revision 1.1.1.1  2006/09/16 18:45:45  yaya
 Start of RasMol Russian Translation Project based on translations
 by Gregory A. Pozhvanov of Saint Petersburg State University -- HJB

 Revision 1.1.1.1  2006/06/19 22:05:14  todorovg
 Initial Rasmol 2.7.3 Import

 Revision 1.1  2004/05/07 19:46:16  yaya
 Initial revision

 Revision 1.2  2004/02/15 00:24:00  yaya
 *** empty log message ***

 Revision 1.1  2003/12/12 21:10:38  yaya
 Initial revision

 Revision 1.1  2001/01/31 02:13:45  yaya
 Initial revision

 Revision 1.3  2000/08/26 18:12:55  yaya
 Updates to header comments in all files

 Revision 1.2  2000/08/09 01:18:32  yaya
 Rough cut with ucb

 */
/*font declarations for pixutils.c and outfile.c*/

#ifdef PIXUTILS
	char FontDimen[23];
	int FontWid[97];

   	char *VectFont[97] = {
    /*  32 ' ' */  "",
    /*  33 '!' */  "ChdhdicichCkdkewbwck",
    /*  34 '"' */  "CvbvbwcwcubtFvevewfwfuet",
    /*  35 '#' */  "AlmlAqmqDidtJijt",
    /*  36 '$' */  "AjcihijjkljnhodobparbtduiuktFgfw",
    /*  37 '%' */  "AgmwIhlhmimllmimhlhiihCqfqgrgufvcvbubrcq",
    /*  38 '&' */  "Kgihbsbtcvewfwgugsfqboamakbichegfghhkk",
    /*  39 ''' */  "Evdvdweweucs",
    /*  40 '(' */  "Egchbiakasbucvew",
    /*  41 ')' */  "Agchdiekesducvaw",
    /*  42 '*' */  "AplpCkjuCujk",
    /*  43 '+' */  "CokoGkgs",
    /*  44 ',' */  "Dgcgchdhdgdfce",
    /*  45 '-' */  "Coko",
    /*  46 '.' */  "Ggfgfhghgg",
    /*  47 '/' */  "Agmw",
    /*  48 '0' */  "EwcvbtbjchegigkhljltkviwewChkv",
    /*  49 '1' */  "DtgwggDgjg",
    /*  50 '2' */  "Kgagaibkhojpkrktjvhwdwbvat",
    /*  51 '3' */  "AtbvdwhwjvktkrjphoeoHojnklkjjhhgdgbhaj",
    /*  52 '4' */  "Klalhwhg",
    /*  53 '5' */  "Kwawaocphpjokmkjjhhgcgah",
    /*  54 '6' */  "Jvhwdwbvatajbhdghgjhkjkmjohpdpboan",
    /*  55 '7' */  "Awkwdg",
    /*  56 '8' */  "DwbvatarbpdohojpkrktjvhwdwDobnalajbhdghgjhkjkljnho",
    /*  57 '9' */  "Bhdghgjhkjktjvhwdwbvataqbodnhnjokq",
    /*  58 ':' */  "GififjgjgiGpfpfqgqgp",
    /*  59 ';' */  "DicicjdjdidhcgCpdpdqcqcp",
    /*  60 '<' */  "Lgbolw",
    /*  61 '=' */  "AsisAnjn",
    /*  62 '>' */  "Bglobw",
    /*  63 '?' */  "ArasbucvewgwivjuktkrjphognflfjFhfgggghfh",
    /*  64 '@' */  "Knjlhkflenepfrhsjrkqkkljmjnkomosnumvkwewcvbuasakbichegkg",
    /*  65 'A' */  "AgcmhwmmogCmmm",
    /*  66 'B' */  "AgigkhlimklmkniokplqmslukviwawBwbgboio",
    /*  67 'C' */  "Milhjgegchbiakasbucvewjwlvmu",
    /*  68 'D' */  "AgigkhlimkmslukviwawBwbg",
    /*  69 'E' */  "KwawagkgAoho",
    /*  70 'F' */  "KwawagAoho",
    /*  71 'G' */  "MilhjgegchbiakasbucvewjwlvmuMgmmHmom",
    /*  72 'H' */  "AgawKgkwAoko",
    /*  73 'I' */  "AgggAwgwDgdw",
    /*  74 'J' */  "AmakbichegghhiikiwDwnw",
    /*  75 'K' */  "AgawAmkwCokg",
    /*  76 'L' */  "Kgagaw",
    /*  77 'M' */  "Agawhmowog",
    /*  78 'N' */  "Agawmgmw",
    /*  79 'O' */  "Akbichegigkhlimkmslukviwewcvbuasak",
    /*  80 'P' */  "Agawiwkvlumsmrlpkoinan",
    /*  81 'Q' */  "AkbichegigkhlimkmslukviwewcvbuasakHlmg",
    /*  82 'R' */  "AgawiwkvlumsmrlpkoinanInmg",
    /*  83 'S' */  "Ajchegigkhlimklmkncpbqasbucvewiwkvmt",
    /*  84 'T' */  "HghwAwow",
    /*  85 'U' */  "Awakbichegigkhlimkmw",
    /*  86 'V' */  "Awggmw",
    /*  87 'W' */  "Aweghokgow",
    /*  88 'X' */  "AwkgAgkw",
    /*  89 'Y' */  "AwfokwFgfo",
    /*  90 'Z' */  "Awkwagkg",
    /*  91 '[' */  "Igdgdwiw",
    /*  92 '\' */  "Awmg",
    /*  93 ']' */  "Dgigiwdw",
    /*  94 '^' */  "Cqgwkq",
    /*  95 '_' */  "Bglg",
    /*  96 '`' */  "Cvdvdwcwcues",
    /*  97 'a' */  "BqdrirjqkokhlgKhigdgbhajbldmimkk",
    /*  98 'b' */  "BichegggihjikkkmjoipgqeqcpboAwbwbgag",
    /*  99 'c' */  "Jqhrercqbpanakbicheghgjh",
    /* 100 'd' */  "KiggegchbiakanbpcqerhrjqkoLgkgkwlw",
    /* 101 'e' */  "Kiihggegchbiakanbpcqerhrjqkokmam",
    /* 102 'f' */  "BgdgCgcrdtfuhtirAnfn",
    /* 103 'g' */  "KiihggegchbiakambodphpjokmLpkpkdjbhaeacbbc",
    /* 104 'h' */  "AwbwbgagBncpeqhqjpknkg",
    /* 105 'i' */  "AgegCgcpbpCrcsbsbrcr",
    /* 106 'j' */  "GshshrgrgsGphphegcebdbbcae",
    /* 107 'k' */  "AgbgbwawBjhpIgem",
    /* 108 'l' */  "AgegCgcubu",
    /* 109 'm' */  "AqbqbgBncpeqfqhpiniginjplqmqoppnpg",
    /* 110 'n' */  "AqbqbgagBncpeqhqjpknkg",
    /* 111 'o' */  "Akbichegggihjikkkmjoipgqeqcpboamak",
    /* 112 'p' */  "BichegggihjikkkmjoipgqeqcpboAqbqbaaa",
    /* 113 'q' */  "KiggegchbiakanbpcqerhrjqkoLpkpkdlbna",
    /* 114 'r' */  "AqbqbgBncpeqhqjo",
    /* 115 's' */  "Ahcgggihjjikbmanbpdqhqjp",
    /* 116 't' */  "AqiqEuehfghgih",
    /* 117 'u' */  "AqakbichegggihjikkKqkglg",
    /* 118 'v' */  "Arfgkr",
    /* 119 'w' */  "Areghmkgor",
    /* 120 'x' */  "ArkgAgkr",
    /* 121 'y' */  "AqakbichegggihjikkKqkdjbhaeacbbc",
    /* 122 'z' */  "Arkragkg",
    /* 123 '{' */  "Egchbjblcnaocpbrbtcvew",
    /* 124 '|' */  "Gggw",
    /* 125 '}' */  "Agchdjdlcneocpdrdtcvaw",
    /* 126 '~' */  "Arbtcueuftfsgrirjsku",
    /* 127 'Angstroms' */  "AgdkhqlkogDklkHwjuhrfuhw", 
    /* 128 'Degrees' */  "Aqbocnemgminjokqksjuivgwewcvbuasaq" 

        };

#else
	extern char FontDimen[23];
	extern int FontWid[97];
   	extern char *VectFont[97];
#endif
