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
/* command.h
 $Log$
 Revision 1.12  2008/04/10 13:42:54  yaya
 Fix handling of load pdb and add Bulgarian to rasmol_run.sh -- HJB

 Revision 1.11  2008/04/01 17:31:19  hk0i
 updated new color mode feature for dots

 Revision 1.10  2008/03/22 18:42:51  yaya
 Post release cleanup and credit to Ikonen in file headers. -- HJB

 Revision 1.9  2008/03/17 03:01:31  yaya
 Update to agree with 2.7.4.2 release and T. Ikonen GTK mods -- HJB

 Revision 1.3  2008/03/17 01:32:41  yaya
 Add gtk mods by tpikonen, and intergate with 2.7.4.2 mods -- HJB

 Revision 1.8  2008/03/16 22:25:21  yaya
 Align comments with production version; Update rasmol_install and
 rasmol_run shell scripts for Japanese and Chinese; Align logic for
 positioning and sizing initial window with windows version -- HJB

 Revision 1.2  2008/01/28 03:29:37  yaya
 Update CVS to RasMol_2.7.4.1 -- HJB

 Revision 1.7  2007/12/06 18:47:09  hk0i
 added NoToggle and ColourMode commands + messages (translations needed), README for lang files, script to generate all langsel files (uses previous scripts).

 Revision 1.6  2007/11/25 04:11:58  yaya
 Updates to map mask logic and inverse transforms -- HJB

 Revision 1.5  2007/11/19 03:28:39  yaya
 Update to credits for 2.7.4 in manual and headers
 Mask code added -- HJB

 Revision 1.3  2007/11/13 03:22:17  yaya
 Changes to support map selectors.  Needs more work. -- HJB

 Revision 1.2  2007/07/14 14:09:03  yaya
 Update to command.c to add load option for maps
 Introduce display to map bonds

 Revision 1.1.1.1  2007/03/01 01:16:32  todorovg
 Chinese working versio from rasmol_ru initial import

 Revision 1.3  2006/11/01 03:23:50  yaya
 Update NSIS windows installer for more script types and to fix
 misplaced script instructions for data files; add document and
 script icons directly in raswin.exe; add credit line to
 G. A. Pozhvanov in comments for Russian translations. -- HJB

 Revision 1.2  2006/09/17 10:53:55  yaya
 Clean up headers and start on code for X11 -- HJB

 Revision 1.1.1.1  2006/09/16 18:45:43  yaya
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

 Revision 1.4  2000/08/26 18:12:54  yaya
 Updates to header comments in all files

 Revision 1.3  2000/08/09 01:18:31  yaya
 Rough cut with ucb

 */

/* Format values are related to Tokens */
#define Tok2Format(x) ((x)-PDBTok+1)
#define Format2Tok(x) ((x)+PDBTok-1)

#define IsMoleculeFormat(x)  ((x)<=16)

#define FormatPDB        1
#define FormatMacroMod   2
#define FormatGaussian   3
#define FormatAlchemy    4
#define FormatNMRPDB     5
#define FormatCharmm     6
#define FormatBiosym     7
#define FormatMOPAC      8
#define FormatSHELX      9
#define FormatMol2      10
#define FormatFDAT      11
#define FormatMMDB      12
#define FormatMDL       13
#define FormatXYZ       14
#define FormatCIF       15
#define FormatCEX       16
#define FormatSCR       17  // not converted to token

#define FormatDots      20
#define FormatMap       21


#define IPC_Ok      0
#define IPC_Error   1
#define IPC_Exit    2
#define IPC_Quit    3

#ifdef COMMAND
int DataFileFormat;
char DataFileName[1024];
char RecordTemplate[1024];
char PlayTemplate[1024];
double RecordCurrent, RecordFrom, RecordUntil, PlayCurrent, PlayFrom, PlayUntil;
int RecordOption, RecordSubOption, RecordPause;
Long SelectCount;
int Interactive;
int FileDepth;
int IsPaused;
int UseCIF=0;

int CalcBondsFlag;
int CalcSurfFlag;
int AllowWrite;

int DefaultBackground = True;
int UseOldColorCode   = 0;
int NoToggle          = 0;

#else
extern int DataFileFormat;
extern char DataFileName[1024];
extern char RecordTemplate[1024];
extern char PlayTemplate[1024];
extern double RecordCurrent, RecordFrom, RecordUntil, PlayCurrent, PlayFrom, PlayUntil;
extern int RecordOption, RecordSubOption, RecordPause;
extern Long SelectCount;
extern int Interactive;
extern int FileDepth;
extern int IsPaused;
extern int UseCIF;

extern int CalcBondsFlag;
extern int CalcSurfFlag;
extern int AllowWrite;

extern int DefaultBackground;

extern int UseOldColorCode;
extern int NoToggle;
#endif

int ProcessCharacter( int );
int FetchFile( int, int, char* );
int ProcessFile( int, int, FILE* );
void LoadScriptFile( FILE*, char* );
void ResetCommandLine( int );
void InitialiseCommand( void );
int ExecuteIPCCommand( char __huge * );
int ExecuteCommand( void );
void CommandError( char *);
void ZapDatabase( void );
void InitHelpFile( void );
void ResumePauseCommand( void );
void InterruptPauseCommand( void );
void ApplyMapColour( void );
void ApplyMapShow( void );
void WriteMovieFrame( void );
