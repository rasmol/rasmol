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
/* command.c
 */

/* With post-2.7.2.1-release mod,
 Update for inline script loading in UCB multiple
 molecule environment.  HJB, 18 April 2001  */
/* With post-2.7.2.1-release mod,
 Disable STRICT checking in ExecuteLoadCommand
 To fix load inline for Windows.  HJB 19 April 2001 */
/* With post-2.7.2.1-release mod,
 Correct logic for inline load of new molecule
 from data file treated as a script.  HJB 29 June 2001 */

#include "rasmol.h"

#ifdef IBMPC
#include <windows.h>
#include <shellapi.h>
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
#if defined(IBMPC) || defined(VMS) || defined(APPLEMAC)
#include "string_case.h"
#else
#include <strings.h>
#endif
#include <ctype.h>
#include <stdio.h>
#include <time.h>


#if !defined(IBMPC) && !defined(VMS) && !defined(APPLEMAC)
#include <pwd.h>
#endif

#define COMMAND
#include "command.h"
#include "tokens.h"
#include "molecule.h"
#include "infile.h"
#include "abstree.h"
#include "transfor.h"
#include "cmndline.h"
#include "render.h"
#include "repres.h"
#include "graphics.h"
#include "pixutils.h"
#include "outfile.h"
#include "script.h"
#include "multiple.h" /* [GSG 11/9/95] */
/* #include "toolbar.h" */ /* [GSG 11/11/95] */
#include "vector.h"
#include "wbrotate.h"
#include "langsel.h"
#include "maps.h"

#include <math.h>
#include <cqrlib.h>
#include <CVector.h>
#ifndef CVECTOR_FAR
#define CVECTOR_FAR
#endif


#if defined(__sun) && !defined(_XOPEN_SOURCE)
/* SUN doesn't always define popen in stdio! */
extern FILE *popen( const char*, const char* );
#endif

/* Macros for commonly used loops */
#define ForEachAtom  for(chain=Database->clist;chain;chain=chain->cnext) \
                     for(group=chain->glist;group;group=group->gnext)    \
                     for(ptr=group->alist;ptr;ptr=ptr->anext)
#define ForEachBond  for(bptr=Database->blist;bptr;bptr=bptr->bnext)
#define ForEachSurfBond  for(sbptr=Database->sblist;sbptr;sbptr=sbptr->sbnext)


#define IsIdentChar(x)  ((isalnum(x))||((x)=='_')||((x)=='$'))

#ifdef INVERT
#define InvertY(y) (y)
#else
#define InvertY(y) (-(y))
#endif

#define Round(x)       ((int)rint(x))



#ifndef VMS
#ifdef IBMPC
#define DirChar  '\\'
#else
#define DirChar  '/'
#endif
#endif



typedef struct {
        Byte red;
        Byte grn;
        Byte blu;
    } RGBStruct;

static RGBStruct ColourTable[34] = {
    {   0,   0,   0 },  /* Black      */
    {   0,   0, 255 },  /* Blue       */
    { 175, 214, 255 },  /* BlueTint   */
    { 175, 117,  89 },  /* Brown      */
    {   0, 255, 255 },  /* Cyan       */
    { 255, 156,   0 },  /* Gold       */
    { 125, 125, 125 },  /* Gray       */
    {   0, 255,   0 },  /* Green      */
    {  46, 139,  87 },  /* GreenBlue  */
    { 152, 255, 179 },  /* GreenTint  */
    { 255,   0, 101 },  /* HotPink    */
    { 255,   0, 255 },  /* Magenta    */
    { 255, 165,   0 },  /* Orange     */
    { 255, 101, 117 },  /* Pink       */
    { 255, 171, 187 },  /* PinkTint   */
    { 160,  32, 240 },  /* Purple     */
    { 255,   0,   0 },  /* Red        */
    { 255,  69,   0 },  /* RedOrange  */
    {   0, 250, 109 },  /* SeaGreen   */
    {  58, 144, 255 },  /* SkyBlue    */
    { 238, 130, 238 },  /* Violet     */
    { 255, 255, 255 },  /* White      */
    { 255, 255,   0 },  /* Yellow     */
    { 246, 246, 117 }   /* YellowTint */
        };


typedef struct _HlpEntry {
                struct _HlpEntry __far *next;
                struct _HlpEntry __far *info;
                char __far *keyword;
                long fpos;
                } HlpEntry;

#define HelpPool   16
static char *HelpFileName;
static char HelpFileBuf[80];
static HlpEntry __far *FreeInfo;
static HlpEntry __far *HelpInfo;


static char ResidueChar[29] = {
        'A', 'G', 'L', 'S', 'V', 'T', 'K', 'D', 'I', 'N',
        'E', 'P', 'R', 'F', 'Q', 'Y', 'H', 'C', 'M', 'W',
        'B', 'Z', '*', 'P',
        'A', 'C', 'G', 'T',
        'U'
    };


#define STACKSIZE  32
static char *NameStack[STACKSIZE];
static FILE *FileStack[STACKSIZE];
static int LineStack[STACKSIZE];
static char AcceptData[STACKSIZE];

static int TokenLength;
static Long TokenValue;
static char TokenIdent[128];
static char *TokenStart;
static char *TokenPtr;
static int CurToken;


static int RVal, GVal, BVal;
static int SeqFormat;


/*=======================*/
/*  Function Prototypes  */
/*=======================*/

int ExecuteCommand( void );
int ExecuteIPCCommand( char __huge* );
static int PrefixString( char __far*, char __far* );
static char __far * xfgets( char __far*, int, FILE __far *);
static int FetchToken( void );
void WriteImageFile( char *, int, int );

void CommandError( char *error )
{
    register char *ptr;
    char buffer[40];
    
    if( TokenPtr )
    {   if( FileDepth > -1 )
        {   InvalidateCmndLine();
            WriteString(CurLine);
            WriteChar('\n');
        } else WriteString("        ");

        for( ptr=CurLine; ptr<TokenStart; ptr++ )
            WriteChar(' ');
        WriteString("^\n");
    }
    
    if( FileDepth > -1 )
    {   if( LineStack[FileDepth] )
        {   if( NameStack[FileDepth] )
            {   WriteChar('"');
				ptr = NameStack[FileDepth];
				while( *ptr ) ptr++;
				while( *ptr != '\\' && ptr != NameStack[FileDepth] ) ptr--;
				if( *ptr == '\\' ) ptr++;
                WriteString(ptr);
                WriteString("\", ");
            }
            sprintf(buffer,"line %d: ",LineStack[FileDepth]);
            WriteString(buffer);
        } else
        {   WriteString(NameStack[FileDepth]);
            WriteString(": ");
        }
    }

    if( error )
    {   WriteString(error);
        if (strlen(error)>(size_t)0 && !(error[strlen(error)-(size_t)1]=='\n')) {
            WriteString("\n");
        }
    }
    CommandActive = False;
    CurToken = 0;
}



/*==========================*/
/*  File Handling Services  */
/*==========================*/

#ifdef IBMPC
char *ProcessFileName( char *name )
{
    register char *ptr;
    
    while( *name==' ' )
        name++;
    
    ptr = DataFileName;
    while( *name )
    {   *ptr++ = ToUpper(*name);
        name++;
    }
    
    /* Strip trailing spaces! */
    while( (ptr!=DataFileName) && (ptr[-1]==' ') )
        ptr--;
    *ptr = '\0';
    return ptr;
}
#endif

#ifdef APPLEMAC
char *ProcessFileName( char *name )
{
    register char *ptr;
    
    while( *name==' ' )
        name++;
    
    ptr = DataFileName;
    while( *name )
        *ptr++ = *name++;
    
    /* Strip trailing spaces! */
    while( (ptr!=DataFileName) && (ptr[-1]==' ') )
        ptr--;
    *ptr = '\0';
    return ptr;
}
#endif

#ifdef VMS 
char *ProcessFileName( char *name )
{
    register char *ptr;
    
    while( *name==' ' )
        name++;
    
    ptr = DataFileName;
    while( *name && (*name!=' ') )
    {   *ptr++ = ToUpper(*name);
        name++;
    }
    *ptr = '\0';
    return ptr;
}
#endif


#if !defined(IBMPC) && !defined(APPLEMAC) && !defined(VMS)
static int IsSecure( int ch )
{
    switch( ch )
    {   /* Dangerous characters in UNIX "popen"!  */
        case('<'):  case('>'):  case('('):  case(')'):
        case('{'):  case('}'):  case('['):  case(']'):
        case('\''): case(';'):  case('|'):  case('&'):
            return False;
    }
    return True;
}


char *ProcessFileName( char *name )
{
    register struct passwd *entry;
    register char *temp;
    register char *ptr;
    char username[64];
    
    while( *name==' ' )
        name++;
    
    /* Perform filename globbing */
    if( *name=='~' )
    {   ptr = username;  name++;
        while( *name && (*name!=' ') && (*name!='/') )
            *ptr++ = *name++;
        *ptr = '\0';
        
        ptr = DataFileName;
        if( *username )
        {   if( (entry=getpwnam(username)) )
            {   temp = entry->pw_dir;
                endpwent();
            } else /* Unknown user! */
            {   temp = username;
                *ptr++ = '~';
            }

        } else if( !(temp=(char*)getenv("HOME")) )
            temp = ".";
        
        while( *temp )
            *ptr++ = *temp++;
    } else ptr = DataFileName;
    
    /* Strip dubious characters! */
    while( *name && (*name!=' ') )
        if( IsSecure(*name) )
        {   *ptr++ = *name++;
        } else name++;
    *ptr = '\0';
    return ptr;
}
#endif


#ifdef UNIX

#define MaxFileExt  4
/* UNIX Compressed Filename extensions! */
static char *FileExt[MaxFileExt] = { "", ".Z", ".gz", ".z" };

static FILE *OpenDataFile( char *begin, char *end )
{
    register char *src, *dst;
    register FILE *fp;
    register int i;
    
    for( i=0; i<MaxFileExt; i++ )
    {   dst = end; src = FileExt[i];
        while( (*dst++ = *src++) );
        if( (fp=fopen(begin,"rb")) ) {
          *end = '\0';
          return fp;
        }
    }
    fp = fopen(begin,"rb");
    *end = '\0';
    return fp;
}
#else /* !defined(UNIX) */

static FILE *OpenDataFile( char *begin, char *end )
{
    register FILE *fp;
    
    fp = fopen(begin,"rb");
    return fp;
}
#endif


int ProcessFile( int format, int info, FILE *fp )
{
    register int done;
    char __far *temp;
    
    temp = getenv("RASMOLCIF");
    if (temp) {
        UseCIF = 0;
        if (!strncasecmp(temp,"cif",3)) UseCIF = 1;
    }
    DataFileFormat = 0;
    switch( format )
    {   case(FormatPDB):      done = LoadPDBMolecule(fp,False);  break;
        case(FormatNMRPDB):   done = LoadPDBMolecule(fp,True);   break;
        case(FormatMacroMod): done = LoadMacroModelMolecule(fp); break;
        case(FormatAlchemy):  done = LoadAlchemyMolecule(fp);    break;
        case(FormatCharmm):   done = LoadCharmmMolecule(fp);     break;
        case(FormatBiosym):   done = LoadBiosymMolecule(fp);     break;
        case(FormatMOPAC):    done = LoadMOPACMolecule(fp);      break;
        case(FormatSHELX):    done = LoadSHELXMolecule(fp);      break;
        case(FormatMol2):     done = LoadMol2Molecule(fp);       break;
        case(FormatFDAT):     done = LoadFDATMolecule(fp);       break;
        case(FormatMDL):      done = LoadMDLMolecule(fp);        break;
        case(FormatXYZ):      done = LoadXYZMolecule(fp);        break;
        case(FormatCIF):      done = LoadCIFMolecule(fp);        break;
#ifdef CEXIOLIB
        case(FormatCEX):      done = LoadCEXMolecule(fp);        break;
#endif
        default:              done = False;
    }
    
    if( !done )
    {   return False;
    } else if( !Database )
        return True;
    if (Interactive) ReviseTitle();
    if( info )
        DescribeMolecule();
    if (!DataFileFormat) DataFileFormat = format;
    AdviseUpdate(AdvName);
    AdviseUpdate(AdvClass);
    AdviseUpdate(AdvIdent);

#ifdef X11WIN
    if( Interactive )
        FetchEvent(False);
#endif
    
    ReDrawFlag |= RFInitial;
    if( CalcBondsFlag )
    {   if( Info.bondcount < (MainAtomCount+HetaAtomCount)-Info.chaincount )
        {   if( MainAtomCount+HetaAtomCount > 255 )
            {   CreateMoleculeBonds(info,False,False);
            } else CreateMoleculeBonds(info,True,False);
        }
    }
    if( CalcSurfFlag ) CreateSurfaceBonds();
    
    /* Explicit Hydrogen Bonds! */
    if( Info.hbondcount > 0 )
        SetHBondStatus(True,True,0,0);
    
    /* Explicit SSbonds!        */
    if (Info.ssbondcount > 0 ) {
        SetHBondStatus(False,True,0,0);
        SSBondMode = True;
    }
    
    InitialTransform();
    
    VoxelsClean = False;
    ApplyTransform();
    return True;
}


static int FetchFileOne( int format, int info, char *name )
{
#ifndef APPLEMAC
#ifdef UNIX
    register int comp;
#endif /* UNIX */
    register char *src,*dst;
    register char *tmp;
    char buffer[128];
#endif /* APPLEMAC */
    
    register int done = 0;
    register FILE *fp;
    
    DataFileFormat = 0;
    name = ProcessFileName(name);
    fp = OpenDataFile(DataFileName,name);
    
#ifndef APPLEMAC
    /* Search for directory specification! */
#ifndef VMS
    if( !fp )
    {   src = DataFileName;
        while( *src && (*src!=DirChar) )
            src++;
        done = !(*src);
    }
#else
    done = True;
#endif
    
    /* Try using a default file path! */
    if( !fp && done )
    {   char* datadir;
        datadir = "";
        switch( format )
        {   case(FormatNMRPDB):
            case(FormatPDB):     src = (char*)getenv("RASMOLPDBPATH");  break;
            case(FormatMol2):    src = (char*)getenv("RASMOLMOL2PATH"); break;
            case(FormatMMDB):    src = (char*)getenv("RASMOLMMDBPATH"); break;
            case(FormatAlchemy): src = (char*)getenv("RASMOLMOLPATH");  break;
            case(FormatMDL):     src = (char*)getenv("RASMOLMDLPATH");  break;
            case(FormatXYZ):     src = (char*)getenv("RASMOLXYZPATH");  break;
            case(FormatCIF):     src = (char*)getenv("RASMOLCIFPATH");  break;
            default:             src = NULL;
        }
        if (!src || !*src) {
            src = (char*)getenv("RASMOLPATH");
            datadir = "Data";
        }
        if( src && *src ) {    
#ifdef VMS
            dst = buffer;
            while( *src ) *dst++ = *src++;
            
            tmp = DataFileName;
            while( *dst = *tmp++ ) dst++;
            if( fp = OpenDataFile(buffer,dst) )
                strcpy(DataFileName,buffer);
#else
            while( *src )
            {   dst = buffer;
                while( *src && (*src!=':') ) 
                    *dst++ = *src++;
                if( *src == ':' ) 
                    src++;
                
                if( dst != buffer )
                {   if( *(dst-1) != DirChar )
                    *dst++ = DirChar;
                    if (strcmp(datadir,"")) {
                        tmp = datadir;
                        while( (*dst = *tmp++)) dst++;
                        if( *(dst-1) != DirChar )
                            *dst++ = DirChar;
                    }
                    tmp = DataFileName;
                    while( (*dst = *tmp++) ) dst++;
                    if( (fp = OpenDataFile(buffer,dst)) )
                    {   strcpy(DataFileName,buffer);
                        break;
                    }
                }
            }
#endif
        }
    }
#endif /* APPLEMAC */
    
    
#ifdef CEXIOLIB
    if( !fp && (format==FormatCEX) )
    {   if( ProcessFile(format,info,fp) )
        return True;
    }
#endif
    
    if( !fp )
    {   *name = '\0';
        InvalidateCmndLine();
        WriteString(MsgStrs[StrErrFile]);
        WriteString(DataFileName);
        WriteString(MsgStrs[StrNotFnd]);
        CommandActive=False;
        return False;
    }
    
#ifdef UNIX
    done = getc(fp);
    if( done == 0x1f )
    {   done = getc(fp);
        fclose(fp);
        
        if( done == 0x9d )
        {   /* Should #include <signal.h> and trap "" SIGPIPE */
            sprintf(buffer,"trap \"\" 13; uncompress -c '%s' 2> /dev/null\n",
                    DataFileName);
        } else if( done == 0x8b )
        {   /* Should #include <signal.h> and trap "" SIGPIPE */
            sprintf(buffer,"trap \"\" 13; gzip -cdq '%s' 2> /dev/null\n",
                    DataFileName);
        } else /* bad magic number! */
        {   InvalidateCmndLine();
            WriteString(MsgStrs[StrCFmt]);
            return False;
        }
        
        comp = True;
        fp = popen(buffer,"r");
        if( !fp )
        {   InvalidateCmndLine();
            WriteString(MsgStrs[StrDcmp]);
            return False;
        }
    } else /* Uncompressed! */
    {   ungetc(done,fp);
        comp = False;
    }
#endif
    
    done = ProcessFile(format,info,fp);
    
#ifdef UNIX
    if( comp )
    {   if( pclose(fp) )
        {   InvalidateCmndLine();
            WriteString(MsgStrs[StrDcmp]);
            return False;
        }
    } else fclose(fp);
#else /* !defined(UNIX) */
    fclose(fp);
#endif
    return done;
}

/* [GSG 11/9/95] Multiple Molecule Support */
int FetchFile( int format, int info, char *name )
{
    int SaveMolecule = MoleculeIndex;
    int result;
    
    if (NumMolecules >= MAX_MOLECULES) {
        return 0;
    }
    SwitchMolecule(NumMolecules);
    result = FetchFileOne( format, info, name );
    if (result && Database) {
        NumMolecules++;
        DrawMoleculeList();
    } else {
        SwitchMolecule(SaveMolecule);
    }
    return result;
}

int FetchStdin( int format )
{
    int SaveMolecule = MoleculeIndex;
    int result;

    if (NumMolecules >= MAX_MOLECULES) {
	return 0;
    }
    SwitchMolecule(NumMolecules);
    result = ProcessFile( format, True, stdin );
    if (result && Database) {
	NumMolecules++;
        DrawMoleculeList();
    } else {
	SwitchMolecule(SaveMolecule);
    }
    return result;
}

static int SetNewMolecule( void )
{
    if (NumMolecules >= MAX_MOLECULES) {
        return False;
    }
    SwitchMolecule(NumMolecules);
	NumMolecules++;
	return True;
}

int DivertToData( int format, int info )
{
    register int ch,len,done;
    register long pos;
    FILE *fp;
    
    fp = FileStack[FileDepth];
    pos = ftell(fp);
    do 
    {   len = 0;
        ch = getc(fp);
        while( (ch!='\n') && (ch!='\r') &&  (ch!=EOF) )
        {   if( len<MAXBUFFLEN )
            CurLine[len++] = ch;
            ch = getc(fp);
        }
        
        if( ch == '\r' )
        {   ch = getc(fp);
            if( ch != '\n' )
                ungetc(ch,fp);
        }
        
        if( len<MAXBUFFLEN )
        {   CurLine[len] = '\0';
            TokenPtr = CurLine;
            if( FetchToken() ) {
                if ( CurToken == QuitTok || CurToken == ExitTok )
                {   if ( SetNewMolecule()) {
                    done = ProcessFile( format, info, fp );
                    fseek(fp,pos,SEEK_SET);
                    strcpy (Info.filename,"inline");
                    return done;
                } else {
                    CommandError(MsgStrs[ErrBadLoad]);
                    return False;
                  }
              } else {
                  if ( CurToken == HeaderTok || CurToken == CIFDataTok ) 
                  {
                    Recycle = &CurLine[0];
                    AcceptData[FileDepth] = 'N';
                    if ( SetNewMolecule()) {
                      done = ProcessFile( format, info, fp );
                      fseek(fp,pos,SEEK_SET);
                      strcpy (Info.filename,"inline");
                      return done;
                    } else {
                      CommandError(MsgStrs[ErrBadLoad]);
                      return False;
                    }
                  }
                }
            }
        } else CommandError(MsgStrs[StrSLong]);
    } while( ch!=EOF );
    
	if( SetNewMolecule() )
	{	fseek(fp,0,SEEK_SET);
		AcceptData[FileDepth] = 'N';
		done = ProcessFile( format, info, fp );
		fseek(fp,pos,SEEK_SET);
		return done;
	} else {
	    CommandError(MsgStrs[ErrBadLoad]);
	}
    
    return False;
}


void LoadScriptFile( FILE *fp,  char *name )
{
    register char *ptr;
    register int ch;
    register size_t len;
    register int stat;
    
    if( fp )
    {   FileDepth++;
        len = strlen(name)+1;
        ptr = (char*)_fmalloc(len);
        memcpy(ptr,name,len);
        NameStack[FileDepth] = ptr;
        FileStack[FileDepth] = fp;
        LineStack[FileDepth] = 0;
        AcceptData[FileDepth] = 'Y';
        
        do {
            len = 0;
            ch = getc(fp);
            while( (ch!='\n') && (ch!='\r') &&  (ch!=EOF) )
            {   if( len<(size_t)MAXBUFFLEN )
                CurLine[len++] = ch;
                ch = getc(fp);
            }
            
            if( ch == '\r' )
            {   ch = getc(fp);
                if( ch != '\n' )
                    ungetc(ch,fp);
            }

            LineStack[FileDepth]++;
            if( len<(size_t)MAXBUFFLEN )
            {   CurLine[len] = '\0';
                stat = ExecuteCommand();
                if( stat )
                {   if( stat == QuitTok )
                    {   while( FileDepth >= 0 )
                        {   fclose(FileStack[FileDepth]);
                            _ffree(NameStack[FileDepth]);
                            FileDepth--;
                        }
                        RasMolExit();
                    } else /* ExitTok */
                        break;
                } else if( IsPaused )
                    return;
                
            } else CommandError(MsgStrs[StrSLong]);
        } while( ch!=EOF );
        _ffree(NameStack[FileDepth]);
        fclose( fp );
        FileDepth--;
    } else
    {   CommandError( (char*)NULL );
        WriteString(MsgStrs[StrSFile]);
        WriteString(name);  WriteString("'\n");
    }
    *CurLine = '\0';
}

/*============================*/
/*  Deferred Command Support  */
/*============================*/


static int Define_Symbol(const char __far * string, const char __far * definition) {
    
    int clead, is;
    Symbol __far * symbol;
    Symbol __far * prevsymbol;
    
    clead = string[0];
    clead &= 0xFF;
    symbol = Defer_Symbols[clead];
    prevsymbol = NULL;
    while (symbol) {
        if (!strcasecmp(string,symbol->string)) {
            if (symbol->definition_capacity < strlen(definition)+1)  {
                _ffree((void *)symbol->definition);
                symbol->definition = (const char __far *)_fmalloc(strlen(definition)+1);
                if (!symbol->definition)return -1;
                symbol->definition_capacity = symbol->definition_size = strlen(definition)+1;
            }
            strcpy((char *)(symbol->definition),definition);
            
            return 0;
        }
        prevsymbol = symbol;
        symbol = symbol->Symbol_Next;
    }
    if (!FreeSymbol) {
        symbol = (Symbol __far *)_fmalloc(SymbolPool*sizeof(Symbol));
        if (!symbol)return -1;
        for (is = 0; is < SymbolPool-1; is++)  {
            (symbol[is]).Symbol_Next= &(symbol[is+1]);
        }
        symbol[SymbolPool-1].Symbol_Next = NULL;
        for (is = 0; is < SymbolPool; is ++) {
            (symbol[is]).string = NULL;
            (symbol[is]).definition = NULL;
            (symbol[is]).definition_size=0;
            (symbol[is]).definition_capacity=0;
        }
        FreeSymbol = symbol;
    }
    symbol = FreeSymbol;
    FreeSymbol = symbol->Symbol_Next;
    symbol->string = (const char __far *)_fmalloc(strlen(string)+1);
    if (!symbol->string) return -1;
    strcpy((char *)(symbol->string),string);
    symbol->definition = (const char __far *)_fmalloc(strlen(definition)+1);
    if (!symbol->definition)
    {
        _ffree((void *)symbol->string);
        return -1;
    }
    symbol->definition_capacity = symbol->definition_size = strlen(definition)+1;
    strcpy((char *)(symbol->definition),definition);
    if (prevsymbol) {
        prevsymbol->Symbol_Next = symbol;
    } else {
        Defer_Symbols[clead] = symbol;
    }
    symbol->Symbol_Next = NULL;
    return 0;
}


static int Append_Symbol_Definition(const char __far * string, const char __far * definition, int bylines) {
    
    int clead, is, il;
    Symbol __far * symbol;
    Symbol __far * prevsymbol;
    
    size_t xsize;
    il = bylines?1:0;
    clead = string[0];
    clead &= 0xFF;
    symbol = Defer_Symbols[clead];
    prevsymbol = NULL;
    while (symbol) {
        if (!strcasecmp(string,symbol->string)) {
            xsize = strlen(symbol->definition)+strlen(definition)+il+1;
            if (symbol->definition_capacity < xsize)  {
                const char * old_definition;
                old_definition = symbol->definition;
                symbol->definition = (const char __far *)_fmalloc(xsize);
                if (!symbol->definition)return -1;
                strcpy((char *)symbol->definition,old_definition);
                symbol->definition_size = strlen(old_definition+1);
                symbol->definition_capacity = xsize;
                _ffree((void *)old_definition);
            }
            if (bylines) strcat((char *)(symbol->definition),"\n");
            strcat((char *)(symbol->definition),definition);
            
            return 0;
        }
        prevsymbol = symbol;
        symbol = symbol->Symbol_Next;
    }
    if (!FreeSymbol) {
        symbol = (Symbol __far *)_fmalloc(SymbolPool*sizeof(Symbol));
        if (!symbol)return -1;
        for (is = 0; is < SymbolPool-1; is++)  {
            (symbol[is]).Symbol_Next= &(symbol[is+1]);
        }
        symbol[SymbolPool-1].Symbol_Next = NULL;
        for (is = 0; is < SymbolPool; is ++) {
            (symbol[is]).string = NULL;
            (symbol[is]).definition = NULL;
            (symbol[is]).definition_size=0;
            (symbol[is]).definition_capacity=0;
        }
        FreeSymbol = symbol;
    }
    symbol = FreeSymbol;
    FreeSymbol = symbol->Symbol_Next;
    symbol->string = (const char __far *)_fmalloc(strlen(string)+1);
    if (!symbol->string) return -1;
    strcpy((char *)(symbol->string),string);
    symbol->definition = (const char __far *)_fmalloc(strlen(definition)+1);
    if (!symbol->definition)
    {
        _ffree((void *)(symbol->string));
        return -1;
    }
    symbol->definition_capacity = symbol->definition_size = strlen(definition)+1;
    strcpy((char *)(symbol->definition),definition);
    if (prevsymbol) {
        prevsymbol->Symbol_Next = symbol;
    } else {
        Defer_Symbols[clead] = symbol;
    }
    symbol->Symbol_Next = NULL;
    return 0;
}

static int Free_Symbol(const char __far * string) {
    
    int clead;
    Symbol __far * symbol;
    Symbol __far * prevsymbol;
    
    clead = string[0];
    clead &= 0xFF;
    symbol = Defer_Symbols[clead];
    prevsymbol = NULL;
    while (symbol) {
        if (!strcasecmp(string,symbol->string)) {
            _ffree((void *)(symbol->definition));
            _ffree((void *)(symbol->string));
            symbol->string = NULL;
            symbol->definition = NULL;
            symbol->definition_size=0;
            symbol->definition_capacity=0;
            if (prevsymbol) {
                prevsymbol->Symbol_Next = symbol->Symbol_Next;
            } else {
                Defer_Symbols[clead] = symbol->Symbol_Next;
            }
            symbol->Symbol_Next = FreeSymbol;
            FreeSymbol = symbol;
            return 0;
        }
        prevsymbol = symbol;
        symbol = symbol->Symbol_Next;
    }
    return 1;
}

static int Find_Symbol_Definition(const char __far * string, const char __far * __far * definition) {

  int clead;
  Symbol __far * symbol;
  Symbol __far * prevsymbol;
  
  clead = string[0];
  clead &= 0xFF;
  symbol = Defer_Symbols[clead];
  prevsymbol = NULL;
  while (symbol) {
    if (!strcasecmp(string,symbol->string)) {
      *definition = symbol->definition;
      return 0;
    }
    prevsymbol = symbol;
    symbol = symbol->Symbol_Next;
  }
  return 1;
}

void ExecuteDeferCommand( void ) {
    const char * strptr;
    char ch;
    
    FetchToken();
    if (CurToken == ZapTok) {
        Free_Symbol("");
        return;
    }
    if (CurToken == '(') {
        if (Append_Symbol_Definition("", TokenStart, True)==-1) {
            InvalidateCmndLine();
            RasMolFatalExit(MsgStrs[StrMalloc]);
        }
        return;
    }
    if( !CurToken ){
        CommandError(MsgStrs[ErrSyntax]);
        return;
    }
    strptr = TokenIdent;
    CurToken = 0;
    ch = *TokenPtr++;
    while( ch && (ch!='#') ){
        if( isspace(ch) ){ 
            ch = *TokenPtr++;
            continue;
        }
        TokenPtr--;
        break;
    }
    if (!strncasecmp("zap",TokenPtr,3) && (!(*(TokenPtr+3)) ||isspace(*(TokenPtr+3)))){
        Free_Symbol(strptr);
    } else {
        if (Append_Symbol_Definition(strptr, TokenPtr, True)==-1) {
            InvalidateCmndLine();
            RasMolFatalExit(MsgStrs[StrMalloc]);
        }
    }
    return;
}


void ShowDeferCommand( void ) {
    const char * definition;
    FetchToken();
    if( !CurToken ){
        CommandError(MsgStrs[ErrSyntax]);
        return;
    }
    if (!Find_Symbol_Definition(TokenIdent,&definition)) {
        WriteString((char *)definition);
    } else {
        WriteString("'");
        WriteString(TokenIdent);
        WriteString(MsgStrs[StrNotFnd]);
        return;
    }
    WriteString("\n=================\n");
    return;
}

void ExecuteExecuteCommand( void ) {
    const char * definition;
    register int ch;
    register size_t len;
    int stat;
    int save_Interactive;
    int save_molecule, save_num_molecules;
    int im;
    double * dialsave_old;
    double * dialsave_new;
    int RDF;
    
    
    FetchToken();
    if( !CurToken ){
        CommandError(MsgStrs[ErrSyntax]);
        return;
    }
    if (!Find_Symbol_Definition(TokenIdent,&definition)) 
    {   
        save_Interactive = Interactive;
        
        dialsave_old = (double *)_fmalloc(sizeof(double)*11*NumMolecules);
        if (!dialsave_old) {
            RasMolFatalExit(MsgStrs[StrMalloc]);
        }
        save_molecule = MoleculeIndex;
        save_num_molecules = NumMolecules;
        
        for (im=0; im<NumMolecules; im++) {
            SwitchMolecule(im);
            memmove((char *)(dialsave_old+im*11),(char *)DialValue,11*sizeof(double));
        }
        SwitchMolecule(save_molecule);
        
        Interactive=False;      /* Supress all screen activity while
         executing the commands first time around */
        do {
            len = 0;
            ch = *definition++;
            while( ch && (ch!='\n') && (ch!='\r') ){
                if( len<(size_t)MAXBUFFLEN )
                    CurLine[len++] = ch;
                ch = *definition++;
            }
            if( ch == '\r' )
            {   ch = *definition++;
                if( ch != '\n' )
                    definition--;
            }
            if( len<(size_t)MAXBUFFLEN )
            {   CurLine[len] = '\0';
                stat = ExecuteCommand();
                if( stat )
                {   if( stat == QuitTok ) { 
                    Interactive = save_Interactive;
                    RasMolExit();
                } else /* ExitTok */
                    break;
                }
            } else CommandError(MsgStrs[StrSLong]);
        } while( ch );
        
        dialsave_new = (double *)_fmalloc(sizeof(double)*11*NumMolecules);
        if (!dialsave_new) {
            _ffree(dialsave_old);
            RasMolFatalExit(MsgStrs[StrMalloc]);
        }
        save_molecule = MoleculeIndex;
        
        for (im=0; im<NumMolecules; im++) {
            SwitchMolecule(im);
            memmove((char *)(dialsave_new+im*11),(char *)DialValue,11*sizeof(double));
            if (im<save_num_molecules) 
            {
                memmove((char *)DialValue,(char *)(dialsave_old+im*11),11*sizeof(double));
            }
        }
        
        SwitchMolecule(save_molecule);
        
        RDF = ReDrawFlag;
        
        RefreshScreen();
        
        ReDrawFlag |= RDF;
        
        Interactive = save_Interactive;
        
        for (im=0; im<NumMolecules; im++) {
            SwitchMolecule(im);
            memmove((char *)DialValue,(char *)(dialsave_new+im*11),11*sizeof(double));
        }
        
        SwitchMolecule(save_molecule);
        
        
    }
    return;
}


/*===========================*/
/*  Movie Support Utilities  */
/*===========================*/



void ShowRecordCommand( void ) {
	int millisec;
	char param[1024];
	millisec = RecordFrom + 1000.*((double)record_frame[0])/record_fps;
	if (RecordPause 
	    || RecordTemplate[0] == '\0'
	    || (millisec > RecordMaxMS && RecordMaxMS > 1.) 
	    || (RecordUntil >= RecordFrom 
            && millisec > RecordUntil + 1000.*((double)record_frame[0])/record_fps)) {
        WriteString("record off\n");
    } else {
        sprintf(param,"record from %g until %g\n",RecordFrom/1000., RecordUntil/1000.);
        WriteString(param);
        if (record_fps > 0.) {
        	sprintf(param,"set record.fps %g\n",record_fps);
            WriteString(param);
        }
        if (record_aps > 0.) {
        	sprintf(param,"set record.aps %g\n",record_aps);
            WriteString(param);
        }
        if (record_dwell > 0.) {
        	sprintf(param,"set record.dwell %g\n",record_dwell);
            WriteString(param);
        }
        if (record_on[0]) WriteString("record motion on\n");
        else WriteString("record motion off\n");
        if (record_on[1]) WriteString("record appearance on\n");
        else WriteString("record apperance off\n");
        if (RecordMaxMS == 1.) {
            sprintf(param,"%s",RecordTemplate);
        } else{
            sprintf(param,RecordTemplate,millisec<0?0:millisec);
        }
        WriteString("record on ");
        switch(RecordOption) {
                
            case (0):
#ifdef EIGHTBIT
                WriteString("GIF "); break;
#else
                WriteString("PPM "); break;
#endif
            case(NMRPDBTok):
            case(PDBTok):
                WriteString("PDB "); break;
            case(MDLTok):
                WriteString("MDL "); break;
            case(XYZTok):
                WriteString("XYZ "); break;
            case(CIFTok):
                WriteString("CIF "); break;
            case(AlchemyTok):
                WriteString("ALCHEMY "); break;
            case(GIFTok):
                WriteString("GIF "); break;
            case(BMPTok):
                WriteString("BMP "); break;
            case(PPMTok):
                WriteString("PPM "); break;
            case(SUNTok):
                WriteString("SUN "); break;
            case(SUNRLETok):
                WriteString("SUNRLE "); break;
            case(PICTTok):
                WriteString("PICT "); break;
            case(IRISTok):
                WriteString("IRIS "); break;
            case(EPSFTok):
                WriteString("EPSF "); break;
            case(MonoPSTok):
                WriteString("MONOPS "); break;
            case(VectPSTok):
                WriteString("VECTPS "); break;
            case(Raster3DTok):
                WriteString("R3D "); break;
                
            case(RasMolTok):
            case(ScriptTok):
                WriteString("SCRIPT "); break;
            case(KinemageTok):
                WriteString("KINEMAGE "); break;
            case(MolScriptTok):
                WriteString("MOLSCRIPT "); break;
            case(POVRayTok):
                WriteString("POVRAY "); break;
            case(POVRay3Tok):
                WriteString("POVRAY3 "); break;
            case(PhiPsiTok):
                WriteString("PHIPSI "); break;
            case(RamachanTok):
                WriteString("RAMACHAN "); break;
            case(RamPrintTok):
                WriteString("RPP "); break;
            case(VRMLTok):
                WriteString("VRML ");
                if (RecordSubOption == MirrorTok) WriteString("MIRROR ");
                if (RecordSubOption == RotateTok) WriteString("ROTATE ");
                break;
            	
        }
        WriteString(param);
        WriteString("\n");
    }
	return;
}

void ShowPlayCommand( void ) {
	int millisec;
	char param[1024];
	millisec = PlayFrom + 1000.*((double)play_frame[0])/play_fps;
	if (PlayPause 
	    || PlayTemplate[0] == '\0'
	    || (millisec > PlayMaxMS && PlayMaxMS > 1.) 
	    || (PlayUntil >= PlayFrom 
            && millisec > PlayUntil + 1000.*((double)play_frame[0])/play_fps)) {
        WriteString("play off\n");
    } else {
        sprintf(param,"play from %g until %g\n",PlayFrom/1000., PlayUntil/1000.);
        WriteString(param);
        if (play_fps > 0.) {
        	sprintf(param,"set play.fps %g\n",record_fps);
            WriteString(param);
        }
        if (PlayMaxMS == 1.) {
            sprintf(param,"%s",PlayTemplate);
        } else{
            sprintf(param,PlayTemplate,millisec<0?0:millisec);
        }
        WriteString("play on ");
        switch(PlayOption) {
                
            case (0):
#ifdef EIGHTBIT
                WriteString("GIF "); break;
#else
                WriteString("PPM "); break;
#endif
            case(NMRPDBTok):
            case(PDBTok):
                WriteString("PDB "); break;
            case(MDLTok):
                WriteString("MDL "); break;
            case(XYZTok):
                WriteString("XYZ "); break;
            case(CIFTok):
                WriteString("CIF "); break;
            case(AlchemyTok):
                WriteString("ALCHEMY "); break;
            case(GIFTok):
                WriteString("GIF "); break;
            case(BMPTok):
                WriteString("BMP "); break;
            case(PPMTok):
                WriteString("PPM "); break;
            case(SUNTok):
                WriteString("SUN "); break;
            case(SUNRLETok):
                WriteString("SUNRLE "); break;
            case(PICTTok):
                WriteString("PICT "); break;
            case(IRISTok):
                WriteString("IRIS "); break;
            case(EPSFTok):
                WriteString("EPSF "); break;
            case(MonoPSTok):
                WriteString("MONOPS "); break;
            case(VectPSTok):
                WriteString("VECTPS "); break;
            case(Raster3DTok):
                WriteString("R3D "); break;
                
            case(RasMolTok):
            case(ScriptTok):
                WriteString("SCRIPT "); break;
            case(KinemageTok):
                WriteString("KINEMAGE "); break;
            case(MolScriptTok):
                WriteString("MOLSCRIPT "); break;
            case(POVRayTok):
                WriteString("POVRAY "); break;
            case(POVRay3Tok):
                WriteString("POVRAY3 "); break;
            case(PhiPsiTok):
                WriteString("PHIPSI "); break;
            case(RamachanTok):
                WriteString("RAMACHAN "); break;
            case(RamPrintTok):
                WriteString("RPP "); break;
            case(VRMLTok):
                WriteString("VRML ");
                if (PlaySubOption == MirrorTok) WriteString("MIRROR ");
                if (PlaySubOption == RotateTok) WriteString("ROTATE ");
                break;
            	
        }
        WriteString(param);
        WriteString("\n");
    }
	return;
}

void WriteMovieFrame( void ) {
	int millisec;
	char param[1024];
	millisec = RecordFrom + 1000.*((double)record_frame[0])/record_fps;
	if (RecordTemplate[0] == '\0'
	    || (millisec > RecordMaxMS && RecordMaxMS > 1.) 
	    || (RecordUntil >= RecordFrom 
        && millisec > RecordUntil)) {
        RecordPause = True;
    } else {
        if (RecordMaxMS == 1.) {
          sprintf(param,"%s",RecordTemplate);
        } else{
          sprintf(param,RecordTemplate,millisec);
        }
        if (!IsMoleculeToken(RecordOption)) {
            WriteImageFile( param, RecordOption, RecordSubOption );
        } else switch(RecordOption) {
            case(NMRPDBTok):
            case(PDBTok):  SavePDBMolecule(param); break;
            case(MDLTok):  SaveMDLMolecule(param); break;
            case(XYZTok):  SaveXYZMolecule(param); break;
            case(CIFTok):  SaveCIFMolecule(param); break;
            case(AlchemyTok): SaveAlchemyMolecule(param);
                break;
        }
    }
	return;
}

static int PlayMovieFrame( void ) {
  	int millisec;
  	int checkfile;
	char param[1024];
    FILE * moviefp;
	millisec = PlayFrom + 1000.*((double)play_frame[0])/play_fps;
	if (PlayTemplate[0] == '\0'
	    || (millisec > PlayMaxMS && PlayMaxMS > 1.) 
	    || (PlayUntil >= PlayFrom 
            && millisec > PlayUntil)) {
        PlayPause = True;
        return 1;
    } else {
        checkfile = False;
        for (play_frame[1] = 0;play_frame[1]<=millisec; play_frame[1]++) 
        {
            if (RecordMaxMS == 1.) {
                sprintf(param,"%s",PlayTemplate);
            } else{
                sprintf(param,PlayTemplate,millisec-play_frame[1]);
            }
            ProcessFileName(param);
            moviefp = fopen(DataFileName,"rb");
            if (moviefp) {
                if (PlayOption == ScriptTok) {
                    LoadScriptFile(moviefp,DataFileName);
                    return 0;
                }
                ZapDatabase();
                SwitchMolecule(NumMolecules);
                if (!ProcessFile(Tok2Format(PlayOption),False,moviefp)) return -1;
                if (Database) {
                    NumMolecules++;
                    DrawMoleculeList();
                    DefaultRepresentation();
                }
                return 0;
            }
        }
        return -1;
    }
}

static void PlayMovie( void ) {
    int interactive_save;
    int SaveMolecule = MoleculeIndex;
    int status;
    if ((!IsMoleculeToken(PlayOption) && PlayOption != ScriptTok)
        || NumMolecules >= MAX_MOLECULES ){
        CommandError(MsgStrs[ErrBadLoad]);
        return;
    }
    if (FileDepth == -1) ShowPlayCommand();
    interactive_save = Interactive;
    if (IsMoleculeToken(PlayOption)) {
        SwitchMolecule(NumMolecules);
    }
    while (!PlayPause && PlayTemplate[0]) {
        Interactive = False;
        status = PlayMovieFrame();
        Interactive = interactive_save;
        ReDrawFlag |= RFRefresh;
        RefreshScreen();
        if (status) break;
        play_frame[0]++;
    }
    if (IsMoleculeToken(PlayOption)) {
        SwitchMolecule(SaveMolecule);
    }
    
    return;
}


/* Convert a Play/Record file name template
   The first string of s...s (case insensitive s's or digits) is changed to %.nd where
   n is the number of s's.  An s in the template can be protected
   from this conversion with a backslash.  Each % is converted to %%.
   
   *** Warning:  if the length of param is K, then the size of the
   template must be at least max(1+2*K,3+K)
   
   The result is a conversion string for sprintf */

static int ConvPRTemplate(char * template, const char * param, size_t limit, double *numfiles) {
  char c;
  int swid;
  int cwid;
  int ii;
  int escape;
  char * torig;
  
  torig = template;
  escape = 0;
  *numfiles = 1.;
  while ((c=*param++)) {
    if (!escape && c=='\\') {
      escape++;
      continue;
    }
    if (escape || (c != 's' && c != 'S' && !(isdigit(c)))){
      *template++ = c;
      if ( template-torig >= limit ) return -1;
      if (c=='%') *template++ = c;
      if ( template-torig >= limit ) return -1;
      escape = 0;
      continue;
    }
    break;
  }
  if (c) {
  	swid = 1;
    *numfiles = 10.;
    while ((c=*param++)) {
      if (c != 's' && c != 'S' && !(isdigit(c))) break;
      swid++;
      *numfiles *= 10.;
    }
    *template++='%';
    if ( template-torig >= limit ) return -1;
    *template++='.';
    if ( template-torig >= limit ) return -1;

    cwid = 1;
    do {
      *template = (swid%10)+'0';
      swid /= 10;
      if (swid) {
        if ( template+cwid-torig >= limit ) return -1;
        for (ii=0; ii<cwid; ii++) {
          template[cwid-ii]=template[cwid-ii-1];
        }
        cwid++;
      }
    	
    } while (swid);
  	template += cwid;
  	*template++ = 'd';
  	if ( template-torig >= limit ) return -1;

  }
  escape=0;
  if (c) {
    param--;
    while ((c=*param++)) {
      if (!escape && c=='\\') {
        escape++;
        continue;
      }
      escape = 0;
      *template++ = c;
      if ( template-torig >= limit ) return -1;
      if (c=='%') *template++ = c;
      if ( template-torig >= limit ) return -1;
    }
  }
  *template++ = '\0';
  return 0;
}


/*====================================*/
/*  Command Line On-Line Help System  */
/*====================================*/

static int PrefixString( char __far *str1, char  __far *str2 )
{
    while( *str1 )
        if( *str1++ != *str2++ )
            return False;
    return True;
}

static char __far *xfgets( char __far* s, int n,  FILE __far *fp )
{
    register int i;
    register int c;
    register char __far *cs;
    cs = s;
    c = '\0';
    for (i = 0; i < n-1; i++)
    {
      if ((c = fgetc(fp)) == EOF)
      {
        *cs++ = '\0';
        return NULL;
      }
      if (c == '\r' || c == '\n' || c == '\0') break;
      *cs++ = c;
    }
    if (c == '\r') {
        c = getc(fp);
        if ( c != '\n' ) ungetc(c,fp);
    }
    *cs++ = '\n';
    *cs++ = '\0';
    return s;             
}



static HlpEntry __far *EnterHelpInfo( char *text )
{
    register HlpEntry __far * __far *tmp;
    register HlpEntry __far *ptr;
    register int res,len,i;
    register char ch;
    char keyword[32];
    
    ptr = (void __far*)0;
    while( *text && (*text!='\n') )
    {   while( *text && (*text!='\n') && (*text==' ') )
        text++;
        
        len = 0;
        while( *text && (*text!='\n') && (*text!=' ') )
            if( len<31 )
            {   ch = *text++;
                keyword[len++] = ToUpper(ch);
            } else text++;
        keyword[len]='\0';
        
        if( ptr )
        {   tmp = &ptr->info;
            ptr = (void __far*)0;
        } else tmp = &HelpInfo;
        
        while( *tmp )
        {   res = _fstrcmp(keyword,(*tmp)->keyword);
            if( res==0 ) /* Exact Match */
            {   ptr = *tmp;
                break;
            } else if( res<0 )
                break;
            tmp = &(*tmp)->next;
        }
        
        if( !ptr )
        {   if( !FreeInfo )
            {   ptr = (HlpEntry __far*)_fmalloc(HelpPool*sizeof(HlpEntry));
                if( !ptr ) 
                    RasMolFatalExit(MsgStrs[StrSMem]);
                for( i=1; i<HelpPool; i++ )
                {   ptr->next = FreeInfo;
                    FreeInfo = ptr++;
                }
            } else
            {   ptr = FreeInfo;
                FreeInfo = ptr->next;
            }

            ptr->keyword = (char __far*)_fmalloc(len+1);
            for( i=0; i<=len; i++ )
                ptr->keyword[i] = keyword[i];
            
            ptr->info = (void __far*)0;
            ptr->next = *tmp;
            ptr->fpos = 0;
            *tmp = ptr;
        }
    }
    return ptr;
}


void InitHelpFile( void )
{
    register char *src,*dst;
    register HlpEntry __far *fix;
    register HlpEntry __far *ptr;
    register FILE *fp;
    register long pos;
    char buffer[82];
    
    HelpFileName = "rasmol.hlp";
    fp=fopen(HelpFileName,"rb");
    
    if( !fp )
    {   src = (char*)getenv("RASMOLPATH");
        if( src )
        {   HelpFileName = dst = HelpFileBuf; 
            while( *src )
                *dst++ = *src++;
#ifndef VMS
            if( (dst!=HelpFileBuf) && (*(dst-1)!=DirChar) )
                *dst++ = DirChar;
#endif
            
            strcpy(dst,"rasmol.hlp");
            fp = fopen(HelpFileName,"rb");
        }
    }
    
#ifdef RASMOLDIR
    if( !fp )
    {   src = RASMOLDIR;
        HelpFileName = dst = HelpFileBuf;
        while( *src )
            *dst++ = *src++;
#ifndef VMS
        if( (dst!=HelpFileBuf) && (*(dst-1)!=DirChar) )
            *dst++ = DirChar;
#endif
        
        src = "rasmol.hlp"; 
        while( (*dst++ = *src++) );
        fp = fopen(HelpFileName,"rb");
    }
#endif
    
    if( !fp )
    {   InvalidateCmndLine();
        WriteString(MsgStrs[StrHFil]);
        HelpFileName = NULL;
        return;
    }
    
    pos = 0;
    xfgets(buffer,80,fp);
    while( !feof(fp) )
    {    fix = (void __far*)0;
        while( *buffer=='?' )
        {   ptr = EnterHelpInfo(buffer+1);
            if( ptr )
            {   ptr->info = fix;
                fix = ptr;
            }
            
            pos = ftell(fp);
            if( !xfgets(buffer,80,fp) )
                break;
        }
        
        while( fix )
        {   ptr = fix->info;
            fix->info = (void __far*)0;
            fix->fpos = pos;
            fix = ptr;
        }
        
        while( xfgets(buffer,80,fp) )
            if( *buffer=='?' )
                break;
    }
    fclose(fp);
}


static void FindHelpInfo( void )
{
    register HlpEntry __far * __far *tmp;
    register HlpEntry __far *ptr;
    register int res,len;
    register long pos;
    register FILE *fp;
    register char ch;
    char keyword[32];
    char buffer[82];
    
    while( *TokenPtr && (*TokenPtr==' ') )
        TokenPtr++;
    
    if( *TokenPtr )
    {   ptr = NULL;
        do {
            len = 0;
            while( *TokenPtr && (*TokenPtr!=' ') )
                if( len<31 )
                {   ch = *TokenPtr++;
                    keyword[len++] = ToUpper(ch);
                } else TokenPtr++;
            keyword[len]='\0';
            
            if( ptr )
            {   tmp = &ptr->info;
                ptr = (void __far*)0;
            } else tmp = &HelpInfo;
            
            while( *tmp )
            {   res = _fstrcmp(keyword,(*tmp)->keyword);
                if( res<0 )
                {   if( PrefixString(keyword,(*tmp)->keyword) )
                {   ptr = *tmp;
                    if( ptr->next && 
                       PrefixString(keyword,ptr->next->keyword) )
                    {   InvalidateCmndLine();
                        WriteString(MsgStrs[StrHTop]);
                        return;
                    } else break;
                } else break;
                } else if( res==0 ) 
                {   ptr = *tmp;
                    break;
                }
                tmp = &(*tmp)->next;
            }
            
            while( *TokenPtr && (*TokenPtr==' ') )
                TokenPtr++;
        } while( *TokenPtr && ptr );
        
        if( !ptr || !ptr->fpos )
        {   InvalidateCmndLine();
            WriteString(MsgStrs[StrHNone]);
            return;
        } else pos=ptr->fpos;
    } else pos=0;
    
    
    if( !(fp=fopen(HelpFileName,"rb")) )
        RasMolFatalExit(MsgStrs[StrHROpn]);
    
    InvalidateCmndLine();
    
    fseek(fp,pos,SEEK_SET);
    while( xfgets(buffer,80,fp) )
        if( *buffer!='?' )
        {   WriteString(buffer);
        } else break;
    fclose(fp);
}



/*=================================*/
/*  Command Line Lexical Analysis  */
/*=================================*/

static int FetchToken( void )
{
    register char ch;
    
    CurToken = 0;
    ch = *TokenPtr++;
    while( ch && (ch!='#') )
    {   if( isspace(ch) )
    {   ch = *TokenPtr++;
        continue;
    }
        
        TokenStart = TokenPtr-1;
        if( isalpha(ch) )
        {   TokenLength = 1;
            *TokenIdent = ToUpper(ch);
            while( IsIdentChar(*TokenPtr) && (TokenLength<32) )
            {   ch = *TokenPtr++;
                TokenIdent[TokenLength++] = ToUpper(ch);
            }
            if( TokenLength==32 )
            {   CommandError(MsgStrs[StrILong]);
                return(0);
            } else TokenIdent[TokenLength] = '\0';
            return( CurToken = LookUpKeyword(TokenIdent) );
            
        } else if( isdigit(ch) )
        {   TokenValue = ch-'0';
            while( isdigit(*TokenPtr) )
                TokenValue = 10*TokenValue + (*TokenPtr++)-'0';
            return( CurToken = NumberTok );
            
        } else if( (ch=='\'') || (ch=='\"') || (ch=='`') )
        {   TokenLength = 0;
            while( *TokenPtr && (TokenLength<128) && (*TokenPtr!=ch) )
                TokenIdent[TokenLength++] = *TokenPtr++;
            
            if( ch != *TokenPtr )
            {   if( *TokenPtr )
            {   CommandError(MsgStrs[StrCTerm]);
            } else CommandError(MsgStrs[StrCLong]);
                return( 0 );
            } else TokenPtr++;
            
            TokenIdent[TokenLength]='\0';
            return( CurToken = StringTok );
        } else if( ispunct(ch) )
            return( CurToken = ch );
        
        ch = *TokenPtr++;
    }
    TokenPtr--;
    return 0;
}


static int NextIf( int tok, int err )
{
    if( FetchToken() != tok )
    {   CommandError(MsgStrs[err]);
        return True;
    } else return False;
}


static void FetchFloat( Long value, int scale )
{
    register int count;
    register int mant;
    
    if( !value && !isdigit(*TokenPtr) )
    {   CommandError(MsgStrs[StrFNum]);
        TokenValue = 0;
        return;
    }
    
    mant = 0;
    count = 1;
    while( isdigit(*TokenPtr) )
    {   if( count < scale )
    {   mant = 10*mant + (*TokenPtr-'0');
        count *= 10;
    }
        TokenPtr++;
    }
    
    mant = (scale*mant)/count;
    TokenValue = value*scale + mant;
}

static void FetchBracketedTriple(Long Triple[3]) {
	int index, neg;
	for (index = 0; index < 3; index++) {
		FetchToken();
		Triple[index] = 0;
		if (CurToken == '-') {
			FetchToken();
			neg = True;
		} else {
			neg = False;
		}
		if (CurToken == NumberTok)  {
		    if (*TokenPtr=='.')  {
		    	TokenPtr++;
                FetchFloat(TokenValue,250);
		    }
		} else if( CurToken=='.' ) {
		    FetchFloat(0,250);
        } else CommandError(MsgStrs[ErrNotNum]);
	    Triple[index] = neg?(-TokenValue):TokenValue;
	    FetchToken();
	    if( !(CurToken == ',' && index < 2) && 
           !(CurToken == ']' && index == 2 )) {   
            CommandError(MsgStrs[ErrSyntax]);
            return;
        }
	}
	return;
}

static void FetchBracketedArray(Long * Array, int arraydim, int * arrayfound ) {
	int index, neg;
	*arrayfound = 0;
	for (index = 0; index < arraydim; index++) {
		FetchToken();
		Array[index] = 0;
		if (CurToken == '-') {
			FetchToken();
			neg = True;
		} else {
			neg = False;
		}
		if (CurToken == NumberTok)  {
		    if (*TokenPtr=='.')  {
		    	TokenPtr++;
                FetchFloat(TokenValue,250);
		    }
		} else if( CurToken=='.' ) {
		    FetchFloat(0,250);
        } else CommandError(MsgStrs[ErrNotNum]);
	    Array[index] = neg?(-TokenValue):TokenValue;
	    FetchToken();
	    if( CurToken == ']') {
	        *arrayfound = index+1;
	        return;
	    }
	    if( !(CurToken == ',' && index < arraydim-1)) {   
            CommandError(MsgStrs[ErrSyntax]);
            return;
        }
	}
	*arrayfound = index;
	return;
}



static int ParseColour( void )
{
    register RGBStruct *rgb;
    
    if( IsColourToken(CurToken) )
    {   rgb = ColourTable + Token2Colour(CurToken);
        RVal = rgb->red;
        GVal = rgb->grn;
        BVal = rgb->blu;
        return True;
        
    } else if( CurToken == '[' )
    {   RVal = GVal = BVal = 0;
        
        if( NextIf(NumberTok,ErrNotNum) ) 
        {   return False;
        } else if( TokenValue>255 )
        {   CommandError(MsgStrs[ErrBigNum]); 
            return False;
        } else RVal = (int)TokenValue;
        
        if( NextIf(',',ErrNotSep) ) 
            return False;
        
        if( NextIf(NumberTok,ErrNotNum) ) 
        {   return False;
        } else if( TokenValue>255 )
        {   CommandError(MsgStrs[ErrBigNum]); 
            return False;
        } else GVal = (int)TokenValue;
        
        if( NextIf(',',ErrNotSep) ) 
            return False;
        
        if( NextIf(NumberTok,ErrNotNum) ) 
        {   return False;
        } else if( TokenValue>255 )
        {   CommandError(MsgStrs[ErrBigNum]);
            return False;
        } else BVal = (int)TokenValue;
        
        return !NextIf(']',ErrNotBrac);
        
    } else if( !CurToken && (*TokenPtr=='#') )
    {   RVal = 0;
        GVal = 0;
        BVal = 0;
        
    } else if( CurToken == IdentTok )
        if( Interactive )
            return LookUpColour(TokenIdent,&RVal,&GVal,&BVal);
    
    return False;
}


static Expr *ParseRange( int neg )
{
    register Expr *tmp1,*tmp2;
    register char ch;
    
    tmp1 = AllocateNode();
    tmp1->type = OpLftProp|OpRgtVal;
    tmp1->rgt.val = neg? -(int)TokenValue : (int)TokenValue;
    tmp1->lft.val = PropResId;
    
    if( *TokenPtr == '-' )
    {   TokenPtr++;
        neg = (*TokenPtr=='-');
        if( neg ) TokenPtr++;
        FetchToken();
        
        if( CurToken != NumberTok )
        {   CommandError(MsgStrs[ErrNotNum]);
            DeAllocateExpr( tmp1 );
            return( (Expr*)NULL );
        }
        
        tmp1->type |= OpMoreEq;
        tmp2 = AllocateNode();
        tmp2->rgt.ptr = tmp1;
        tmp2->type = OpAnd;
        
        tmp1 = AllocateNode();
        tmp1->type = OpLftProp|OpRgtVal|OpLessEq;
        tmp1->rgt.val = neg? -(int)TokenValue : (int)TokenValue;
        tmp1->lft.val = PropResId;
        tmp2->lft.ptr = tmp1;
        tmp1 = tmp2;
    } else tmp1->type |= OpEqual;
    
    if( *TokenPtr == ':' )
        TokenPtr++;
    
    ch = *TokenPtr;
    if( isalnum(ch) )
    {   ch = ToUpper(ch);
        TokenPtr++;
        
        tmp2 = AllocateNode();
        tmp2->type = OpAnd;
        tmp2->rgt.ptr = tmp1;
        
        tmp1 = AllocateNode();
        tmp1->type = OpEqual | OpLftProp | OpRgtVal;
        tmp1->lft.val = PropChain;               
        tmp1->rgt.val = ch;
        
        tmp2->lft.ptr = tmp1;
        tmp1 = tmp2;
    } else if( (ch=='?') || (ch=='%') || (ch=='*') )
        TokenPtr++;
    
    FetchToken();
    return tmp1;
}


static Expr *ParseExpression( int level )
{
    register Expr *tmp1,*tmp2;
    register int done, pred = 0;
    register int neg;
    
    switch( level )
    {    case(0): /* Disjunctions */
            tmp1 = ParseExpression(1);
            while( (CurToken==OrTok) || (CurToken=='|') ||
                  (CurToken==',') )
            {   if( CurToken=='|' )
            {   if( FetchToken()=='|' )
                FetchToken();
            } else FetchToken();
                
                tmp2 = AllocateNode();
                tmp2->type = OpOr;
                tmp2->lft.ptr = tmp1;
                tmp2->rgt.ptr = NULL;
                if( !(tmp1=ParseExpression(1)) )
                {   DeAllocateExpr(tmp2);
                    return( tmp1 );
                }
                tmp2->rgt.ptr = tmp1;
                tmp1 = tmp2;
            }
            return( tmp1 );
            
        case(1): /* Conjunctions */
            tmp1 = ParseExpression(2);
            while( (CurToken==AndTok) || (CurToken==YTok) || (CurToken=='&') )
            {   if( CurToken=='&' )
            {   if( FetchToken()=='&' )
                FetchToken();
            } else FetchToken();
                
                tmp2 = AllocateNode();
                tmp2->type = OpAnd;
                tmp2->lft.ptr = tmp1;
                tmp2->rgt.ptr = NULL;
                if( !(tmp1=ParseExpression(2)) )
                {   DeAllocateExpr(tmp2);
                    return( tmp1 );
                }
                tmp2->rgt.ptr = tmp1;
                tmp1 = tmp2;
            }
            return( tmp1 );
            
        case(2): /* Primitives */
            if( IsPredTok(CurToken) || (CurToken==BackboneTok) )
            {   switch( CurToken )
                {   case(HelixTok):    if( Info.helixcount < 0 )
                    DetermineStructure(False);
                        pred = PredHelix;
                        break;
                    case(SheetTok):    if( Info.laddercount < 0 )
                        DetermineStructure(False);
                        pred = PredSheet;
                        break;
                    case(TurnTok):     if( Info.turncount < 0 )
                        DetermineStructure(False);
                        pred = PredTurn;
                        break;
                    case(CystineTok):  if( Info.ssbondcount < 0 )
                        FindDisulphideBridges();
                        pred = PredCystine;     
                        break;
                    case(CisBondedTok):if( Info.cisbondcount<0 )
                        FindCisBonds();
                        pred = PredCisBond;   
                        break;		     
                    case(BackboneTok): pred = PredMainChain;   break;
                    case(SelectedTok): pred = PropSelect;      break;
                    default:  pred = PredAbsChr(PredTokOrd(CurToken));
                }
                
                tmp1 = AllocateNode();
                tmp1->type = OpConst|OpLftProp|OpRgtVal;
                tmp1->lft.val = pred;
                FetchToken();
                return( tmp1 );
                
            } else if( IsPropTok(CurToken) )
            {   tmp1 = AllocateNode();
                tmp1->type = OpLftProp|OpRgtVal;
                switch( CurToken )
                {   case(TemperatureTok): pred = PropTemp;    break;
                    case(RadiusTok):      pred = PropRad;     break;
                    case(AtomNoTok):      pred = PropIdent;   break;
                    case(ElemNoTok):      pred = PropElemNo;  break;
                    case(ResNoTok):       pred = PropResId;   break;
                    case(ModelTok):       pred = PropModel;   break;
                    case(AltlTok):        pred = PropAltl;    break;
                }
                tmp1->lft.val = pred;
                
                FetchToken();
                if( CurToken=='=' )
                {   tmp1->type |= OpEqual;
                    if( FetchToken()=='=' )
                        FetchToken();
                } else if( CurToken=='<' )
                {   FetchToken();
                    if( CurToken=='>' )
                    {   tmp1->type |= OpNotEq;
                        FetchToken();
                    } else if( CurToken=='=' )
                    {   tmp1->type |= OpLessEq;
                        FetchToken();
                    } else tmp1->type |= OpLess;
                } else if( CurToken=='>' )
                {   if( FetchToken()=='=' )
                {   tmp1->type |= OpMoreEq;
                    FetchToken();
                } else tmp1->type |= OpMore;
                } else if( (CurToken=='!') || (CurToken=='/') )
                {   if( NextIf('=',ErrBadExpr) )
                {   DeAllocateExpr( tmp1 );
                    return( (Expr*)NULL );
                } else tmp1->type |= OpNotEq;
                    FetchToken();
                } else
                {   CommandError(MsgStrs[ErrBadExpr]);
                    DeAllocateExpr( tmp1 );
                    return( (Expr*)NULL );
                }
                
                
                if( CurToken == '-' )
                {   FetchToken();
                    neg = True;
                } else neg = False;
                
                if( CurToken!=NumberTok )
                {   CommandError(MsgStrs[ErrNotNum]);
                    DeAllocateExpr( tmp1 );
                    return( (Expr*)NULL );
                } 
                
                if( neg )
                {     tmp1->rgt.val = -(int)TokenValue; 
                } else tmp1->rgt.val = (int)TokenValue;
                FetchToken();
                return( tmp1 );
                
            } else switch( CurToken )
            {   case('('):    FetchToken();
                    if( !(tmp1=ParseExpression(0)) )
                        return( (Expr*)NULL );
                    
                    if( CurToken!=')' )
                    {   CommandError(MsgStrs[ErrParen]);
                        DeAllocateExpr( tmp1 );
                        return( (Expr*)NULL );
                    }
                    FetchToken();
                    return(tmp1);
                    
                case('!'): case('~'):
                case(NotTok): FetchToken();
                    if( !(tmp1=ParseExpression(2)) )
                        return( (Expr*)NULL );
                    
                    tmp2 = AllocateNode();
                    tmp2->type = OpNot | OpRgtVal;
                    tmp2->lft.ptr = tmp1;
                    return( tmp2 );
                    
                case('-'):    if( NextIf(NumberTok,ErrNotNum) )
                    return( (Expr*)NULL );
                    return( ParseRange(True) );
                    
                case(NumberTok):
                    return( ParseRange(False) );
                    
                case(WithinTok):
                    if( NextIf('(',ErrFunc) )
                        return( (Expr*)NULL );
                    
                    FetchToken();
                    if( CurToken==NumberTok )
                    {   if( *TokenPtr=='.' )
                    {   TokenPtr++;
                        FetchFloat(TokenValue,250);
                    }
                    } else if( CurToken!='.' )
                    {   CommandError(MsgStrs[ErrNotNum]);
                        return( (Expr*)NULL );
                    } else FetchFloat(0,250);
                    
                    if( TokenValue>10000 )
                    {   CommandError(MsgStrs[ErrBigNum]);
                        return( (Expr*)NULL );
                    } else pred = (int)TokenValue;
                    if( NextIf(',',ErrNotSep) )
                        return( (Expr*)NULL );
                    
                    FetchToken();
                    if( !(tmp1=ParseExpression(0)) )
                        return( (Expr*)NULL );
                    
                    if( CurToken!=')' )
                    {   CommandError(MsgStrs[ErrParen]);
                        DeAllocateExpr( tmp1 );
                        return( (Expr*)NULL );
                    }
                    
                    FetchToken();
                    if( !pred )
                        return( tmp1 );
                    
                    tmp2 = AllocateNode();
                    tmp2->type = OpWithin;
                    tmp2->lft.limit = (Long)pred*pred;
                    tmp2->rgt.set = BuildAtomSet(tmp1);
                    DeAllocateExpr(tmp1);
                    return( tmp2 );
                    
                default:      if( CurToken==IdentTok )
                {   tmp1 = LookUpSetExpr(TokenIdent);
                    if( !tmp1 ) 
                        tmp1 = LookUpElement(TokenIdent);
                    
                    if( tmp1 )
                    {   FetchToken();
                        return(tmp1);
                    }
                }
                    
                    TokenPtr = TokenStart;
                    done = ParsePrimitiveExpr(&TokenPtr);
                    FetchToken();
                    
                    if( !done )
                    {   CommandError(MsgStrs[ErrBadExpr]);
                        DeAllocateExpr( QueryExpr );
                        return( (Expr*)NULL );
                    } else return( QueryExpr );
            }
    }
    return (Expr*)NULL;
}



/*======================================*/
/*  RasMol Command Parsing & Execution  */
/*  Commands listed alphabetically      */
/*======================================*/

static void ExecuteAxesCommand( void )
{
    FetchToken();
    if( !CurToken || (CurToken==FalseTok) )
    {   ReDrawFlag |= RFRefresh;
        DrawAxes = False;
    } else if( CurToken == TrueTok )
    {   ReDrawFlag |= RFRefresh;
        DrawAxes = True;
    } else CommandError(MsgStrs[ErrBadOpt]);
}


static void ExecuteBoundBoxCommand( void )
{
    FetchToken();
    if( !CurToken || (CurToken==FalseTok) )
    {   ReDrawFlag |= RFRefresh;
        DrawBoundBox = False;
    } else if( CurToken == TrueTok )
    {   ReDrawFlag |= RFRefresh;
        DrawBoundBox = True;
    } else CommandError(MsgStrs[ErrBadOpt]);
}


static void ExecuteCentreCommand( void )
{
    register Real x, y, z;
    register Long count;
    int xlatecen;
    
    xlatecen = XlateCen;
    
    FetchToken();
    if( !CurToken || (CurToken==AllTok) )
    {   CentreTransform(0,0,0,xlatecen);
        return;
    }
    
    if( (CurToken==CentreTok) || (CurToken==TranslateTok) ) {
        xlatecen = XlateCen = (CurToken==TranslateTok)?True:False;
        FetchToken();
        if ( !CurToken ) return;
        if ( CurToken==AllTok ) {
            CentreTransform(0,0,0,xlatecen);
            return;
        }
    }
    
    
    /* Check for Centre [CenX, CenY, CenZ] syntax */
    
    if ( CurToken == '[' )
    {   Long CenV[3];
        
        
        /*      int icen, negcen;
         
         for (icen = 0; icen < 3; icen++)
         { FetchToken();
         CenV[icen] = 0;
         if( CurToken == '-' )
         {  FetchToken();
         negcen = True;
         } else negcen = False;
         if( CurToken == NumberTok )
         {  if (negcen )
	     { CenV[icen] = -TokenValue;
         } else CenV[icen] = TokenValue;
         FetchToken();
         } 
         if( !(CurToken == ',' && icen < 2) && 
         !(CurToken == ']' && icen == 2 ))
         {   CommandError(MsgStrs[ErrSyntax]);
         return;
         }
         }
         */
        
        FetchBracketedTriple(CenV);
        
#ifdef INVERT
        CenV[1] = -CenV[1];
#endif
        FetchToken();
        if( CurToken ) {
            if (  (CurToken==CentreTok) || (CurToken==TranslateTok) ) {
                xlatecen = (CurToken==TranslateTok)?True:False;
            } else {
                CommandError(MsgStrs[ErrSyntax]);
                return;
            }
        }
		CentreTransform(CenV[0],CenV[1],-CenV[2],xlatecen);
        return;
    }
    
    QueryExpr = ParseExpression(0);
    if( !QueryExpr ) return;
    
    if( CurToken )
    {   CommandError(MsgStrs[ErrSyntax]);
        DeAllocateExpr(QueryExpr);
        return;
    }
    
    /* CentreZoneExpr(QueryExpr); */
    if( !Database ) return;
    
    count = 0;
    x = y = z = 0.0;
    for( QChain=Database->clist; QChain; QChain=QChain->cnext )
        for( QGroup=QChain->glist; QGroup; QGroup=QGroup->gnext )
            for( QAtom=QGroup->alist; QAtom; QAtom=QAtom->anext )
                if( EvaluateExpr(QueryExpr) )
                {   x += (Real)(QAtom->xorg+QAtom->fxorg);
                    y += (Real)(QAtom->yorg+QAtom->fyorg);
                    z += (Real)(QAtom->zorg+QAtom->fzorg);
                    count++;
                }
    
    if( count )
    {   FetchToken();
        if( CurToken ) {
            if (  (CurToken==CentreTok) || (CurToken==TranslateTok) ) {
                xlatecen = (CurToken==TranslateTok)?True:False;
            } else {
                CommandError(MsgStrs[ErrSyntax]);
                return;
            }
        } 
        CentreTransform((Long)(x/count),(Long)(y/count),(Long)(z/count),xlatecen);
    } else
    {   InvalidateCmndLine();
        WriteString(MsgStrs[StrCent]);
    }
    DeAllocateExpr(QueryExpr);
}


static void ExecuteClipboardCommand( void )
{
    if( !ClipboardImage() )
    {   InvalidateCmndLine();
        WriteString(MsgStrs[StrCClip]);
    }
}


static void ExecuteLoadCommand( void )
{
    register int format;
    register int info;
    register FILE *fp;
	int checkfile = False;
    
    FetchToken();
    format = FormatPDB;
    if( !*TokenPtr || *TokenPtr==' ' )
    {   if( IsMoleculeToken(CurToken) )
    {   format = Tok2Format(CurToken);
        FetchToken();
    } else if( CurToken == DotsTok )
    {   format = FormatDots;
        FetchToken();
    } else if (CurToken == MapTok) 
    {   format = FormatMap;
        if (!Database){
            CommandError(MsgStrs[ErrBadMolDB]);
            return;
        }
        FetchToken();
    }
    }
    
    if( !CurToken )
    {   CommandError(MsgStrs[ErrFilNam]);
        return;
    }
    /*
     #ifdef STRICT
     if( (CurToken!=StringTok) && (CurToken!=IdentTok) )
     {   CommandError(MsgStrs[ErrFilNam]);
     return;
     }
     #endif
     */
    info = (FileDepth == -1);
    if( IsMoleculeFormat(format) )
    {   if( NumMolecules >= MAX_MOLECULES )
    {   CommandError(MsgStrs[ErrBadLoad]);
        return;
    }
        
        if( CurToken==InLineTok )
        {   if( (FileDepth!=-1) && LineStack[FileDepth] )
  	    { DivertToData( format, info );
        } else CommandError(MsgStrs[ErrOutScrpt]);
        } else if( CurToken==StringTok )
        {      checkfile = FetchFile(format,info,TokenIdent);
        } else checkfile = FetchFile(format,info,TokenStart);
		
		/* don't color the molecule unless it's actually loaded! */
		if (checkfile == True)
			DefaultRepresentation();
    } else /* format == FormatDots  || format == FormatMap */
    {   if( !Database )
    {   CommandError(MsgStrs[ErrBadMolDB]);
        return;
    }
        
        if( CurToken==StringTok )
        {      ProcessFileName(TokenIdent);
        } else ProcessFileName(TokenStart);
        
        if( !(fp=fopen(DataFileName,"rb")) )
        {   CommandError( (char*)NULL );
            WriteString(MsgStrs[StrDFile]);
            WriteString(DataFileName);
            WriteString("'!\n");
            return;
        } else if (format == FormatDots) {
            LoadDotsFile(fp,info);
            fclose(fp);
        } 
#ifdef USE_CBFLIB        
        else { /* format == FormatMap */
            if(LoadCCP4MapFile(fp,info, -1)) {
                if( !(fp=fopen(DataFileName,"rb")) ) {
                    CommandError( (char*)NULL );
                    WriteString(MsgStrs[StrDFile]);
                    WriteString(DataFileName);
                    WriteString("'!\n");
                    return;
                } else if (LoadCBFMapFile(fp,info,-1)) {
                    CommandError( (char*)NULL );
                    WriteString(MsgStrs[StrErrFile]);
                    WriteString(DataFileName);
                    WriteString("'!\n");
                    return;
                }
            }
            ReDrawFlag |= RFInitial|RFColour;
        }
#endif
    }
    CurToken = 0;
}


static void ExecutePauseCommand( void )
{
    if( FileDepth == -1 )
    {   CommandError(MsgStrs[ErrOutScrpt]);
        return;
    }
    
    /* Ignore Pause Commands via IPC! */
    if( LineStack[FileDepth] )
    {   CommandActive = True;
        IsPaused = True;
        
#ifdef MSWIN
        /* Disable Drag & Drop! */
        DragAcceptFiles(CanvWin,FALSE);
#endif
    }
    
	ReDrawFlag |= RFRefresh;
}


static void ExecutePickingCommand( void )
{
    switch( FetchToken() )
    {   case(TrueTok):     case(0):
        case(IdentifyTok): SetPickMode(PickIdent); break;
        case(FalseTok):
        case(NoneTok):     SetPickMode(PickNone);  break;
        case(LabelTok):    SetPickMode(PickLabel); break;
        case(DistanceTok): SetPickMode(PickDist);  break;
        case(AngleTok):    SetPickMode(PickAngle); break;
        case(TorsionTok):  SetPickMode(PickTorsn); break;
        case(MonitorTok):  SetPickMode(PickMonit); break;
        case(CentreTok):   SetPickMode(PickCentr); break;
        case(OriginTok):   SetPickMode(PickOrign); break;
        case(CoordTok):    SetPickMode(PickCoord); break;
        case(AtomTok):     SetPickMode(PickAtom);  break;
        case(GroupTok):    SetPickMode(PickGroup); break;
        case(ChainTok):    SetPickMode(PickChain); break;
        case(BondTok):     SetPickMode(PickBond);  break;
        default:           CommandError(MsgStrs[ErrBadOpt]);
    }
}


static void ExecutePrintCommand( void )
{
    if( !PrintImage() )
    {   InvalidateCmndLine();
        WriteString(MsgStrs[StrNPrint]);
    }
}


static void ExecuteTitleCommand( void )
{
    FetchToken();
    if( !CurToken )
    { char VersionStr[50];
        
        sprintf (VersionStr,"RasMol Version %s", VERSION);
        SetCanvasTitle(VersionStr);
    } else if( CurToken == StringTok )
    {      SetCanvasTitle(TokenIdent);
    } else SetCanvasTitle(TokenStart);
    CurToken = 0;
}


static void ExecuteUnitCellCommand( void )
{
    FetchToken();
    if( !CurToken || (CurToken==FalseTok) )
    {   ReDrawFlag |= RFRefresh;
        DrawUnitCell = False;
    } else if( CurToken == TrueTok )
    {   ReDrawFlag |= RFRefresh;
        DrawUnitCell = True;
    } else CommandError(MsgStrs[ErrBadOpt]);
}


/*=======================================*/
/*  IPC Send Command Parsing & Execution */
/*=======================================*/

static void ExecuteSendCommand( void )
{
    char * interptarg;
    char * command;
    char buffer[133];
    unsigned long interpid;
    
    FetchToken();
    if (!CurToken) {
        CommandError(MsgStrs[ErrSyntax]);
        return;
    }
    if ( CurToken==StringTok ) {
        interptarg = TokenIdent;
    } else {
        interptarg = TokenStart;
    }

    if (!CheckInterpName(interptarg, &interpid)) {
        size_t xlen;
        strcpy(buffer,"'");
        strncat(buffer,interptarg,131);
        buffer[132]='\0';
        xlen = strlen(buffer);
        if (xlen+strlen(MsgStrs[StrNotFnd])< 132) {
            strncat(buffer,MsgStrs[StrNotFnd],132);
            CommandError(buffer);
            return;
        }
        WriteString(buffer);
        CommandError(MsgStrs[StrNotFnd]);
        return;
    }
    strncpy(buffer,interptarg,132);
    buffer[132]='\0';
    
    FetchToken();
    if (!CurToken) {
        CommandError(MsgStrs[ErrSyntax]);
        return;
    }
    if ( CurToken==StringTok ) {
        command = TokenIdent;
    } else {
        command = TokenStart;
    }
    
    SendInterpCommand(buffer,interpid,command);
    
    return;

}


/*=======================================*/
/*  Generic Command Parsing & Execution  */
/*=======================================*/

static void ExecuteSetCommand( void )
{
    register int option;
    char buffer[50];
    
    switch( FetchToken() )
    {   case(SlabTok):
        case(SlabModeTok):
            option = -1;
            FetchToken();
            if( CurToken==RejectTok )
            {   option = SlabReject;
            } else if( CurToken==HalfTok )
            {   option = SlabHalf;
            } else if( CurToken==HollowTok )
            {   option = SlabHollow;
            } else if( CurToken==SolidTok )
            {   option = SlabClose;
            } else if( CurToken==SectionTok )
                option = SlabSection;
            
            if( option != -1 )
            {   if( UseSlabPlane && (SlabMode!=option) )
                ReDrawFlag |= RFRefresh;
                SlabMode = option;
            } else CommandError(MsgStrs[ErrBadOpt]);
            break;
            
        case(ShadowTok):
            FetchToken();
            if( CurToken==TrueTok )
            {   UseShadow = True;
                ReviseInvMatrix();
                VoxelsClean = False;
                UseSlabPlane = False;
                UseDepthPlane = False;
                ReDrawFlag |= RFRefresh;
                ReAllocBuffers();
            } else if( CurToken==FalseTok )
            {   ReDrawFlag |= RFRefresh;
                UseShadow = False;
            } else CommandError(MsgStrs[ErrBadOpt]);
            break;
            
        case(SpecularTok):
            FetchToken();
            if( CurToken==TrueTok )
            {   FakeSpecular = True;
                ReDrawFlag |= RFColour;
            } else if( CurToken==FalseTok )
            {   FakeSpecular = False;
                ReDrawFlag |= RFColour;
            } else CommandError(MsgStrs[ErrBadOpt]);
            break;
            
        case(SpecPowerTok):
            FetchToken();
            if( !CurToken )
            {   SpecPower = 8;
                ReDrawFlag |= RFColour;
            } else if( CurToken==NumberTok )
            {   if( TokenValue<=100 )
            {   ReDrawFlag |= RFColour;
                SpecPower = (int)TokenValue;
            } else 
                CommandError(MsgStrs[ErrBigNum]);
            } else CommandError(MsgStrs[ErrNotNum]);
            break;
            
            
        case(ShadePowerTok):
            FetchToken();
            if( !CurToken )
            {   ShadePower = 0;
                ReDrawFlag |= RFColour;
            } else if( CurToken==NumberTok )
            {   if( TokenValue<=100 )
            {   ReDrawFlag |= RFColour;
                ShadePower = (int)((TokenValue-50)*0.4);
            } else 
                CommandError(MsgStrs[ErrBigNum]);
            } else CommandError(MsgStrs[ErrNotNum]);
            break;
            
        case(AmbientTok):
            FetchToken();
            if( !CurToken )
            {   ReDrawFlag |= RFColour;
                Ambient = DefaultAmbient;
            } else if( CurToken==NumberTok )
            {   if( TokenValue<=100 )
            {   Ambient = TokenValue/100.0;
                ReDrawFlag |= RFColour;
            } else
                CommandError(MsgStrs[ErrBigNum]); 
            } else CommandError(MsgStrs[ErrNotNum]);
            break;
            
        case(HeteroTok):
            FetchToken();
            if( CurToken==TrueTok )
            {   HetaGroups = True;
            } else if( CurToken==FalseTok )
            {   HetaGroups = False;
            } else CommandError(MsgStrs[ErrBadOpt]);
            break;
            
        case(HydrogenTok):
            FetchToken();
            if( CurToken==TrueTok )
            {   Hydrogens = True;
            } else if( CurToken==FalseTok )
            {   Hydrogens = False;
            } else CommandError(MsgStrs[ErrBadOpt]);
            break;
            
            
        case(BackgroundTok):
            FetchToken();
            if( CurToken == TransparentTok )
            {   UseTransparent = True;
            } else if( CurToken == NormalTok )
            {   UseTransparent = False;
            } else if( ParseColour() )
            {   ReDrawFlag |= RFColour;
                BackR = RVal;
                BackG = GVal;
                BackB = BVal;
                DefaultBackground = False; /* [GSG 11/29/95] */
#ifndef IBMPC
                FBClear = False;
#endif
            } else if( CurToken )
            {   CommandError(MsgStrs[ErrColour]);
            } else CommandError(MsgStrs[ErrNoCol]);
            break;
            
        case(BondModeTok):
            FetchToken();
            if( !CurToken || (CurToken==AndTok) )
            {   ZoneBoth = True;
            } else if( CurToken==OrTok )
            {   ZoneBoth = False;
            } else if( CurToken==AllTok ) 
            {   MarkAtoms = AllAtomFlag;
            } else if( CurToken==NoneTok)
            {	MarkAtoms = 0;
            } else if( CurToken==NotTok )
            {   FetchToken();
                if( !CurToken || (CurToken==BondedTok) )
                { MarkAtoms = NonBondFlag;
                } else CommandError(MsgStrs[ErrBadOpt]);
            } else CommandError(MsgStrs[ErrBadOpt]);
            break;
            
        case(HBondTok):
            FetchToken();
            if( (CurToken==BackboneTok) || (CurToken==MainChainTok) )
            {   ReDrawFlag |= RFRefresh;
                HBondMode = True;
            } else if( !CurToken || (CurToken==SidechainTok) )
            {   ReDrawFlag |= RFRefresh;
                HBondMode = False;
            } else if( CurToken == ChainTok )
            {   FetchToken();
                if( !CurToken || (CurToken==TrueTok) )
                {   if( !HBondChainsFlag && (Info.hbondcount>=0) )
                {   ReDrawFlag |= RFRefresh;
                    HBondChainsFlag = True;
                    CalcHydrogenBonds();
                }
                } else if( CurToken == FalseTok )
                {   if( HBondChainsFlag && (Info.hbondcount>=0) )
                {   ReDrawFlag |= RFRefresh;
                    HBondChainsFlag = False;
                    CalcHydrogenBonds();
                }
                } else CommandError(MsgStrs[ErrBadOpt]);
            } else CommandError(MsgStrs[ErrBadOpt]);
            break;
            
        case(SSBondTok):
            FetchToken();
            if( (CurToken==BackboneTok) || (CurToken==MainChainTok) )
            {   ReDrawFlag |= RFRefresh;
                SSBondMode = True;
            } else if( !CurToken || (CurToken==SidechainTok) )
            {   ReDrawFlag |= RFRefresh;
                SSBondMode = False;
            } else CommandError(MsgStrs[ErrBadOpt]);
            break;
            
        case(HourGlassTok):
            FetchToken();
            if( CurToken==TrueTok )
            {   UseHourGlass = True;
            } else if( CurToken==FalseTok )
            {   UseHourGlass = False;
            } else CommandError(MsgStrs[ErrBadOpt]);
            break;
            
        case(StrandsTok):
            FetchToken();
            if( !CurToken )
            {   ReDrawFlag |= RFRefresh;
                SplineCount = 5;
            } else if( CurToken==NumberTok )
            {   if( (TokenValue>0) && (TokenValue<=5) )
            {   SplineCount = (int)TokenValue;
                ReDrawFlag |= RFRefresh;
            } else if( TokenValue==9 )
            {   ReDrawFlag |= RFRefresh;
                SplineCount = 9;
            } else CommandError(MsgStrs[ErrBadOpt]);
            } else CommandError(MsgStrs[ErrNotNum]);
            break;
            
        case(MouseTok):
            FetchToken();
            if( !CurToken || (CurToken==RasMolTok) || (CurToken==NewTok) || (CurToken==OldTok) )
            {   if( Interactive ) {
                  if (CurToken == RasMolTok) {
                    FetchToken();
                    if (!CurToken || CurToken==NewTok) {
                        SetMouseMode( MMRasMol );
                    } else if (CurToken==OldTok) {
                        SetMouseMode( MMRasOld );
                    } else CommandError(MsgStrs[ErrBadOpt]);
                    break;
                  } 
                  if (CurToken == NewTok) {
                    FetchToken();
                    if (!CurToken || CurToken==RasMolTok) {
                        SetMouseMode( MMRasMol );
                    } else CommandError(MsgStrs[ErrBadOpt]);
                    break;
                  } 
                  if (CurToken == OldTok) {
                    FetchToken();
                    if (!CurToken || CurToken==RasMolTok) {
                        SetMouseMode( MMRasOld );
                    } else CommandError(MsgStrs[ErrBadOpt]);
                    break;
                  } 
                  SetMouseMode( MMRasMol );
                }
            } else if( CurToken==InsightTok )
            {   if( Interactive )
                SetMouseMode( MMInsight );
            } else if( CurToken==QuantaTok )
            {   if( Interactive )
                SetMouseMode( MMQuanta );
            } else if( CurToken==SybylTok )
            {   if( Interactive )
                SetMouseMode( MMSybyl );
            } else CommandError(MsgStrs[ErrBadOpt]);
            break;
            
        case(DisplayTok):
            FetchToken();
            /* Affect StereoMode Parameters?? */
            if( !CurToken || (CurToken==NormalTok) )
            {   ReDrawFlag |= RFRefresh | RFColour;
                DisplayMode = 0;
            } else if( CurToken==SelectedTok )
            {   ReDrawFlag |= RFRefresh | RFColour;
                DisplayMode = 1;
            } else CommandError(MsgStrs[ErrBadOpt]);
            break;
            
        case(VectPSTok):
            FetchToken();
            if( !CurToken || (CurToken==FalseTok) )
            {   UseOutLine = False;
            } else if( CurToken == TrueTok )
            {   UseOutLine = True;
            } else CommandError(MsgStrs[ErrBadOpt]);
            break;
            
        case(Raster3DTok):
            FetchToken();
            if( !CurToken || (CurToken==FalseTok) )
            {   UseOutLine = False;
            } else if( CurToken == TrueTok )
            {   UseOutLine = True;
            } else CommandError(MsgStrs[ErrBadOpt]);
            break;
            
        case(KinemageTok):
            FetchToken();
            if( !CurToken || (CurToken==FalseTok) )
            {   KinemageFlag = False;
            } else if( CurToken == TrueTok )
            {   KinemageFlag = True;
            } else CommandError(MsgStrs[ErrBadOpt]);
            break;
            
        case(MenusTok):
            FetchToken();
            if( !CurToken || (CurToken==TrueTok) )
            {   EnableMenus(True);
            } else if( CurToken == FalseTok )
            {   EnableMenus(False);
            } else CommandError(MsgStrs[ErrBadOpt]);
            break;
            
        case(RadiusTok):
            FetchToken();
            if( !CurToken )
            {   ProbeRadius = SolventDots? 300 : 0;
            } else if( CurToken==NumberTok )
            {   if( *TokenPtr=='.' )
            {   TokenPtr++;
                FetchFloat(TokenValue,250);
            }
                
                if( TokenValue>1500 )
                {   CommandError(MsgStrs[ErrBigNum]);
                } else ProbeRadius = (int)TokenValue;
            } else if( CurToken=='.' )
            {   FetchFloat(0,250);
                if( TokenValue>1500 )
                {   CommandError(MsgStrs[ErrBigNum]);
                } else ProbeRadius = (int)TokenValue;
                
            } else CommandError(MsgStrs[ErrNotNum]);
            iProbeRad = (int)(Scale*(Real)ProbeRadius);
            ReDrawFlag |= RFRefresh;
            break;
            
        case(SolventTok):
            FetchToken();
            if( !CurToken || (CurToken==FalseTok) )
            {   SolventDots = False;
                ProbeRadius = 0;
            } else if( CurToken == TrueTok )
            {   SolventDots = True;
                ProbeRadius = 300;
            } else CommandError(MsgStrs[ErrBadOpt]);
            iProbeRad = (int)(Scale*(Real)ProbeRadius);
            ReDrawFlag |= RFRefresh;
            break;
            
        case(FontSizeTok):
            FetchToken();
            if( CurToken==NumberTok )
            {   if( TokenValue<=48 )
            {   int fsize;
                
                fsize = (int)TokenValue;
                FetchToken();
                if ( !CurToken || CurToken==FSTok )
                { SetFontSize(fsize);
                } else if ( CurToken ==PSTok ) 
                { SetFontSize(-fsize);
                } else CommandError(MsgStrs[ErrBadOpt]);
            } else CommandError(MsgStrs[ErrBigNum]);
            } else if( !CurToken )
            {   SetFontSize(8);
            } else if (CurToken == FSTok) 
            {   SetFontSize(abs(FontSize));
            } else if (CurToken == PSTok)
            {   SetFontSize(-abs(FontSize));
            } else CommandError(MsgStrs[ErrBadOpt]);
            break;
            
        case(FontStrokeTok):
            FetchToken();
            if( CurToken==NumberTok )
            {   if( TokenValue<=8 )
            {   if( LabelList || (MonitList && DrawMonitDistance) )
                ReDrawFlag |= RFRefresh;
                SetFontStroke((int)TokenValue);
            } else CommandError(MsgStrs[ErrBigNum]);
            } else if( !CurToken )
            {   if( LabelList )
                ReDrawFlag |= RFRefresh;
                SetFontStroke(0);
            } else CommandError(MsgStrs[ErrBadOpt]);
            break;
            
        case(WriteTok):
            FetchToken();
            if( !CurToken || (CurToken==FalseTok) )
            {   AllowWrite = False;
            } else if( CurToken == TrueTok )
            {   if( (FileDepth!=-1) && LineStack[FileDepth] )
            {   CommandError(MsgStrs[ErrInScrpt]);
            } else AllowWrite = True;
            } else CommandError(MsgStrs[ErrBadOpt]);
            break;
            
        case(StereoTok):  
            FetchToken();
            if( !CurToken )
            {   if (UseStereo) {
                StereoAngle = -StereoAngle;
                if (StereoAngle  < 0.0 ) {
                    SetStereoMode(True);
                } else {
                    SetStereoMode(False);
                }
            } else SetStereoMode(True);
            } else if( CurToken==TrueTok )
            {   SetStereoMode(True);
            } else if( CurToken==FalseTok )
            {   SetStereoMode(False);
            } else if( CurToken == '-' )
            {   if( !NextIf(NumberTok,ErrNotNum) )
            {   StereoAngle = -TokenValue;
                SetStereoMode(True);
            }
            } else if( CurToken == '+' )
            {   if( !NextIf(NumberTok,ErrNotNum) )
            {   StereoAngle = TokenValue;
                SetStereoMode(True);
            }
            } else if( CurToken==NumberTok )
            {   StereoAngle = TokenValue;
                SetStereoMode(True);
            } else {
                CommandError(MsgStrs[ErrSyntax]); 
                break;
            }
            if (StereoAngle > 60.) {
                StereoAngle = 6.;
                CommandError(MsgStrs[ErrBigNum]);
                break;            	
            }
            if (StereoAngle < -60.) {
                StereoAngle = -6.;
                CommandError(MsgStrs[ErrBigNum]);
                break;            	
            }
            break;
            
        case(BondTok):
            FetchToken();
            if( !CurToken || (CurToken==FalseTok) )
            {   ReDrawFlag |= RFRefresh;
                DrawDoubleBonds = False;
            } else if( CurToken == TrueTok )
            {   ReDrawFlag |= RFRefresh;
                DrawDoubleBonds = True;
            } else CommandError(MsgStrs[ErrBadOpt]);
            break;
            
        case(MonitorTok):
            FetchToken();
            if( !CurToken || (CurToken==TrueTok) )
            {   ReDrawFlag |= RFRefresh;
                DrawMonitDistance = True;
            } else if( CurToken == FalseTok )
            {   ReDrawFlag |= RFRefresh;
                DrawMonitDistance = False;
            } else CommandError(MsgStrs[ErrBadOpt]);
            break;
            
        case(CartoonTok):
            FetchToken();
            if( !CurToken )
            {   ReDrawFlag |= RFRefresh;
                DrawBetaArrows = True;
                CartoonHeight = 120;
            } else if( CurToken==TrueTok )
            {   ReDrawFlag |= RFRefresh;
                DrawBetaArrows = True;
            } else if( CurToken==FalseTok )
            {   ReDrawFlag |= RFRefresh;
                DrawBetaArrows = False;
            } else if( CurToken==NumberTok )
            {   if( *TokenPtr=='.' )
            {   TokenPtr++;
                FetchFloat(TokenValue,250);
            }
                
                if( TokenValue <= 500 )
                {   CartoonHeight = (int)TokenValue;
                    ReDrawFlag |= RFRefresh;
                } else CommandError(MsgStrs[ErrBigNum]);
            } else if( CurToken=='.' )
            {   FetchFloat(0,250);
                if( TokenValue <= 500 )
                {   CartoonHeight = (int)TokenValue;
                    ReDrawFlag |= RFRefresh;
                } else CommandError(MsgStrs[ErrBigNum]);
                
            } else CommandError(MsgStrs[ErrBadOpt]);
            break;
            
        case(BackFadeTok):
            FetchToken();
            if( !CurToken || (CurToken==FalseTok) )
            {   ReDrawFlag |= RFColour;
                UseBackFade = False;
            } else if( CurToken == TrueTok )
            {   ReDrawFlag |= RFColour;
                UseBackFade = True;
            } else CommandError(MsgStrs[ErrBadOpt]);
            break;
            
        case(TransparentTok):
            FetchToken();
            if( !CurToken || (CurToken==FalseTok) )
            {   UseTransparent = False;
            } else if( CurToken == TrueTok )
            {   UseTransparent = True;
            } else CommandError(MsgStrs[ErrBadOpt]);
            break;
            
        case(DepthCueTok):
            FetchToken();
            if( !CurToken || (CurToken==FalseTok) )
            {   ReDrawFlag |= RFColour;
                UseDepthCue = False;
            } else if( CurToken == TrueTok )
            {   ReDrawFlag |= RFColour;
                UseDepthCue = True;
            } else CommandError(MsgStrs[ErrBadOpt]);
            break;
            
        case(CisAngleTok):
            FetchToken();
            if( !CurToken )
            {   CisBondCutOff = CIS;
            } else {
                if( CurToken==NumberTok )
                {   if( TokenValue<=180 )
                {   CisBondCutOff = TokenValue;
                    Info.cisbondcount = -1; /* to recalculate peptide bonds */
                } else {
                    CommandError(MsgStrs[ErrBigNum]); 
                }
                } else {
                    CommandError(MsgStrs[ErrNotNum]);
                }
            }
            sprintf(buffer,"CisBondCutOff = %d\n", CisBondCutOff);
            WriteString( buffer );
            break;    
            
        case(SequenceTok):
            FetchToken();
            if( !CurToken || (CurToken==FalseTok) )
            {   SeqFormat = False;
            } else if( CurToken == TrueTok )
            {   SeqFormat = True;
            } else CommandError(MsgStrs[ErrBadOpt]);
            break;
            
        case(ConnectTok):
            FetchToken();
            if( !CurToken || (CurToken==TrueTok) )
            {   CalcBondsFlag = True;
            } else if( CurToken == FalseTok )
            {   CalcBondsFlag = False;
            } else CommandError(MsgStrs[ErrBadOpt]);
            break;
            
        case(AxesTok):     ExecuteAxesCommand();     break;
        case(BoundBoxTok): ExecuteBoundBoxCommand(); break;
        case(PickingTok):  ExecutePickingCommand();  break;
        case(TitleTok):    ExecuteTitleCommand();    break;
        case(UnitCellTok): ExecuteUnitCellCommand(); break;
            
        case(DotsTok):
			FetchToken();
            if( !CurToken )
            {   SurfaceChainsFlag = False;
                SolventDots = False;
                ProbeRadius = 0;
            } else if( CurToken == SolventTok )
            {   FetchToken();
                if( !CurToken || (CurToken==FalseTok) )
                {   SolventDots = False;
                    ProbeRadius = 0;
                } else if( CurToken == TrueTok )
                {   SolventDots = True;
                    ProbeRadius = 300;
                } else CommandError(MsgStrs[ErrBadOpt]);
            } else if( CurToken == ChainTok )
            {   FetchToken();
                if( !CurToken || (CurToken==TrueTok) )
                {   SurfaceChainsFlag = True;
                } else if( CurToken == FalseTok )
                {   SurfaceChainsFlag = False;
                } else CommandError(MsgStrs[ErrBadOpt]);
            } else if( CurToken == NumberTok )
            {   if( TokenValue<=20 )
            {   if( TokenValue )
            {   DotSize = TokenValue;
                ReDrawFlag |= RFRefresh;
            }
            } else CommandError(MsgStrs[ErrBigNum]);
            } else CommandError(MsgStrs[ErrBadOpt]);
            iProbeRad = (int)(Scale*(Real)ProbeRadius);
            ReDrawFlag |= RFRefresh;
            break;
            
            /* set notoggle command - gm */
		case (NoToggleTok):
			FetchToken();
			if (!CurToken || CurToken == TrueTok)
			{
				NoToggle = 1;
				WriteString(MsgStrs[StrNoTogOn]);
			}
			else if (CurToken == FalseTok)
			{
				NoToggle = 0;
				WriteString(MsgStrs[StrNoTogOff]);
			}
			break;
            
            /* set play.fps command */
        case (PlayTok):
        {   int errorcode = 0;
            
            FetchToken();
            if (CurToken == '.') {
                FetchToken();
                if(CurToken == FPSTok) {
                  FetchToken();
                    if (CurToken == NumberTok ) {
                        play_fps = (double)TokenValue;
                        if( *TokenPtr=='.') {
                            TokenPtr++;
                            FetchFloat(TokenValue,1000);
                            play_fps = (double)TokenValue/1000.;
                        }
                     } else if (CurToken=='.') {
                         FetchFloat(0,1000);
                         play_fps = (double)TokenValue/1000.;
                     } else {
                        if (!CurToken) {
                            play_fps = 24.;
                        } else errorcode++;
                    }
                } else errorcode++;
             }
             if (errorcode) CommandError(MsgStrs[ErrBadArg]);
            break;
        }
            
                        /* set record.fps <n> command 
                           set record.aps <n> command 
                           set record.dwell <n> <what> command
                         
                           handling of <what> deferred */
        case (RecordTok):
        {   int errorcode = 0;
            double __far * settarget;
            double targetdefault = 24.;
            
            FetchToken();
            if (CurToken == '.') {
                FetchToken();
                switch (CurToken) {
                    case FPSTok: settarget = &record_fps; break;
                    case APSTok: settarget = &record_aps; targetdefault = 10.;break;
                    case DwellTok: settarget = &record_dwell; targetdefault = 0.5; break;
                    default: settarget = (double __far *)NULL;
                }
                if(settarget) {
                  FetchToken();
                    if (CurToken == NumberTok ) {
                        *settarget = (double)TokenValue;
                        if( *TokenPtr=='.') {
                            TokenPtr++;
                            FetchFloat(TokenValue,1000);
                            *settarget = (double)TokenValue/1000.;
                        }
                     } else if (CurToken=='.') {
                         FetchFloat(0,1000);
                         *settarget = (double)TokenValue/1000.;
                     } else {
                        if (!CurToken) {
                           *settarget = targetdefault;
                        } else errorcode++;
                    }
                } else errorcode++;
             }
             if (errorcode) CommandError(MsgStrs[ErrBadArg]);
            break;
        }
            
        case(IPCDetailTok):
            FetchToken();
            if( !CurToken || (CurToken==TrueTok) )
            {   TkResponseDetail = True;
                IPCResponseDetail = True;
            } else if( CurToken == FalseTok )
            {   TkResponseDetail = False;
                IPCResponseDetail = False;
            } else CommandError(MsgStrs[ErrBadOpt]);
            break;


            
        default:
            CommandError(MsgStrs[ErrParam]);
    }
}


static void OldExecuteColourCommand( void )
{
    register int flag;
    
    flag = 0;
    switch( FetchToken() )
    {   case(AtomTok):
            FetchToken();
        default:
            switch( CurToken )
        {   case(CPKTok):         CPKColourAttrib(); 
                ReDrawFlag |= RFColour; break;
                
            case(CpkNewTok):      CpkNewColourAttrib();
                ReDrawFlag |= RFColour; break;	      
                
            case(AminoTok):       AminoColourAttrib();
                ReDrawFlag |= RFColour; break;
                
            case(ShapelyTok):     ShapelyColourAttrib();
                ReDrawFlag |= RFColour; break;
                
            case(UserTok):        UserMaskAttrib(MaskColourFlag);
                ReDrawFlag |= RFColour; break;
                
            case(GroupTok):       ScaleColourAttrib(GroupAttr);
                ReDrawFlag |= RFColour; break;
                
            case(ChainTok):       ScaleColourAttrib(ChainAttr);
                ReDrawFlag |= RFColour; break;
                
            case(ModelTok):       ScaleColourAttrib(ModelAttr);
                ReDrawFlag |= RFColour; break;
                
            case(AltlTok):        ScaleColourAttrib(AltAttr);
                ReDrawFlag |= RFColour; break;
                
            case(ChargeTok):      ScaleColourAttrib(ChargeAttr);
                ReDrawFlag |= RFColour; break;
                
            case(TemperatureTok): ScaleColourAttrib(TempAttr);
                ReDrawFlag |= RFColour; break;
                
            case(StructureTok):   StructColourAttrib();
                ReDrawFlag |= RFColour; break;
                
            default:  if( ParseColour() )
            {   MonoColourAttrib(RVal,GVal,BVal);
                ReDrawFlag |= RFColour;
            } else if( CurToken )
            {      CommandError(MsgStrs[ErrColour]);
            } else CommandError(MsgStrs[ErrNoCol]);
        }
            break;
            
        case(BondTok):    
        case(DashTok):
            FetchToken();
            if( CurToken==NoneTok )
            {   ColourBondNone();
                ReDrawFlag |= RFColour;
            } else if( ParseColour() )
            {   ColourBondAttrib(RVal,GVal,BVal);
                ReDrawFlag |= RFColour;
            } else if( CurToken )
            {      CommandError(MsgStrs[ErrColour]);
            } else CommandError(MsgStrs[ErrNoCol]);
            break;
            
        case(BackboneTok):
            FetchToken();
            if( CurToken==NoneTok )
            {   ColourBackNone();
                ReDrawFlag |= RFColour;
            } else if( ParseColour() )
            {   ColourBackAttrib(RVal,GVal,BVal);
                ReDrawFlag |= RFColour;
            } else if( CurToken )
            {      CommandError(MsgStrs[ErrColour]);
            } else CommandError(MsgStrs[ErrNoCol]);
            break;
            
        case(SSBondTok):
            FetchToken();
            if( CurToken==NoneTok )
            {   ReDrawFlag |= RFColour;
                ColourHBondNone( False );
            } else if( ParseColour() )
            {   ReDrawFlag |= RFColour;
                ColourHBondAttrib(False,RVal,GVal,BVal);
            } else if( CurToken )
            {      CommandError(MsgStrs[ErrColour]);
            } else CommandError(MsgStrs[ErrNoCol]);
            break;
            
        case(HBondTok):
            FetchToken();
            if( CurToken==NoneTok )
            {   ReDrawFlag |= RFColour;
                ColourHBondNone( True );
            } else if( CurToken==TypeTok )
            {   ReDrawFlag |= RFColour;
                ColourHBondType();
            } else if( ParseColour() )
            {   ReDrawFlag |= RFColour;
                ColourHBondAttrib(True,RVal,GVal,BVal);
            } else if( CurToken )
            {      CommandError(MsgStrs[ErrColour]);
            } else CommandError(MsgStrs[ErrNoCol]);
            break;
            
        case(DotsTok):
            FetchToken();
            if( CurToken==PotentialTok )
            {   ReDrawFlag |= RFColour;
                ColourDotsPotential();
            } else if( ParseColour() )
            {   ReDrawFlag |= RFColour;
                ColourDotsAttrib(RVal,GVal,BVal);
            } else if( CurToken )
            {      CommandError(MsgStrs[ErrColour]);
            } else CommandError(MsgStrs[ErrNoCol]);
            break;
            
    	case(MapTok):
            FetchToken();
            if( CurToken==PotentialTok )
            {   ReDrawFlag |= RFColour;
                MapFlag |= MapColourPot;
                MapFlag &= ~MapColourAtom;
                ApplyMapColour();
            } else if( CurToken==AtomTok )
            {   ReDrawFlag |= RFColour;
                MapFlag |= MapColourAtom;
                MapFlag &= ~MapColourPot;
                ApplyMapColour();
            } else if( ParseColour() )
            {   ReDrawFlag |= RFColour;
                MapRGBCol[0] = RVal;
                MapRGBCol[1] = GVal;
                MapRGBCol[2] = BVal;
                MapFlag &= ~(MapColourPot|MapColourAtom);
                ApplyMapColour();
            } else if( CurToken )
            {      CommandError(MsgStrs[ErrColour]);
            } else CommandError(MsgStrs[ErrNoCol]);
            break;
            
            
        case(MonitorTok):
            FetchToken();
            if( CurToken == NoneTok )
            {   ColourMonitNone();
            } else if( ParseColour() )
            {   ReDrawFlag |= RFColour;
                ColourMonitAttrib(RVal,GVal,BVal);
            } else if( CurToken )
            {      CommandError(MsgStrs[ErrColour]);
            } else CommandError(MsgStrs[ErrNoCol]);
            break;
            
        case(AxesTok):
        case(BoundBoxTok):
        case(UnitCellTok):
            FetchToken();
            if( ParseColour() )
            {   BoxR = RVal;  BoxG = GVal;  BoxB = BVal;
                ReDrawFlag |= RFColour;
            } else if( CurToken )
            {      CommandError(MsgStrs[ErrColour]);
            } else CommandError(MsgStrs[ErrNoCol]);
            break;
            
        case(LabelTok):
            FetchToken();
            if( CurToken==NoneTok )
            {   ReDrawFlag |= RFColour;
                UseLabelCol = False;
            } else if( ParseColour() )
            {   LabR = RVal;  LabG = GVal;  LabB = BVal;
                ReDrawFlag |= RFColour;
                UseLabelCol = True;
            } else if( CurToken )
            {      CommandError(MsgStrs[ErrColour]);
            } else CommandError(MsgStrs[ErrNoCol]);
            break;
            
        case(TraceTok): 
        case(RibbonTok):
        case(StrandsTok):
        case(CartoonTok):  flag = RibColBoth;     break;
        case(Ribbon1Tok):  flag = RibColInside;   break;
        case(Ribbon2Tok):  flag = RibColOutside;  break;
    }
    
    if( flag )
    {   FetchToken();
        if( CurToken==NoneTok )
        {   ReDrawFlag |= RFColour;
            ColourRibbonNone(flag);
        } else if( ParseColour() )
        {   ReDrawFlag |= RFColour;
            ColourRibbonAttrib(flag,RVal,GVal,BVal);
        } else if( CurToken )
        {      CommandError(MsgStrs[ErrColour]);
        } else CommandError(MsgStrs[ErrNoCol]);
    }
}

static void ExecuteColourCommand( void )
{
	/* The new ExecuteColorCommand - at present this is a copy of the
	 * previous version */
    register int flag;
    
	/* in case we want to use the old code... */
	if (UseOldColorCode)
	{
		/* ... use it ... */
		OldExecuteColourCommand();
		return;
	}
    
    flag = 0;
    switch( FetchToken() )
    {   case(AtomTok):
            FetchToken();
        default:
            switch( CurToken )
        {   case(CPKTok):         CPKColourAttrib(); 
                ReDrawFlag |= RFColour; break;
                
            case(CpkNewTok):      CpkNewColourAttrib();
                ReDrawFlag |= RFColour; break;	      
                
            case(AminoTok):       AminoColourAttrib();
                ReDrawFlag |= RFColour; break;
                
            case(ShapelyTok):     ShapelyColourAttrib();
                ReDrawFlag |= RFColour; break;
                
            case(UserTok):        UserMaskAttrib(MaskColourFlag);
                ReDrawFlag |= RFColour; break;
                
            case(GroupTok):       ScaleColourAttrib(GroupAttr);
                ReDrawFlag |= RFColour; break;
                
            case(ChainTok):       ScaleColourAttrib(ChainAttr);
                ReDrawFlag |= RFColour; break;
                
            case(ModelTok):       ScaleColourAttrib(ModelAttr);
                ReDrawFlag |= RFColour; break;
                
            case(AltlTok):        ScaleColourAttrib(AltAttr);
                ReDrawFlag |= RFColour; break;
                
            case(ChargeTok):      ScaleColourAttrib(ChargeAttr);
                ReDrawFlag |= RFColour; break;
                
            case(TemperatureTok): ScaleColourAttrib(TempAttr);
                ReDrawFlag |= RFColour; break;
                
            case(StructureTok):   StructColourAttrib();
                ReDrawFlag |= RFColour; break;
                
            default:  if( ParseColour() )
            {   ColourBondNone();
                MonoColourAttrib(RVal,GVal,BVal);
                ReDrawFlag |= RFColour;
            } else if( CurToken )
            {      CommandError(MsgStrs[ErrColour]);
            } else CommandError(MsgStrs[ErrNoCol]);
        }
            break;
            
        case(BondTok):    
        case(DashTok):
            FetchToken();
            if( CurToken==NoneTok )
            {   ColourBondNone();
                ReDrawFlag |= RFColour;
            } else if( ParseColour() )
            {   ColourBondAttrib(RVal,GVal,BVal);
                ReDrawFlag |= RFColour;
            } else if( CurToken )
            {      CommandError(MsgStrs[ErrColour]);
            } else CommandError(MsgStrs[ErrNoCol]);
            break;
            
        case(BackboneTok):
            FetchToken();
            if( CurToken==NoneTok )
            {   ColourBackNone();
                ReDrawFlag |= RFColour;
            } else if( ParseColour() )
            {   ColourBackAttrib(RVal,GVal,BVal);
                ReDrawFlag |= RFColour;
            } else if( CurToken )
            {      CommandError(MsgStrs[ErrColour]);
            } else CommandError(MsgStrs[ErrNoCol]);
            break;
            
        case(FieldTok):
            FetchToken();
            if( CurToken==NoneTok )
            {   ColourFieldNone();
                ReDrawFlag |= RFColour;
            } else if( ParseColour() )
            {   ColourFieldAttrib(RVal,GVal,BVal);
                ReDrawFlag |= RFColour;
            } else if( CurToken )
            {      CommandError(MsgStrs[ErrColour]);
            } else CommandError(MsgStrs[ErrNoCol]);
            break;

            
        case(SSBondTok):
            FetchToken();
            if( CurToken==NoneTok )
            {   ReDrawFlag |= RFColour;
                ColourHBondNone( False );
            } else if( ParseColour() )
            {   ReDrawFlag |= RFColour;
                ColourHBondAttrib(False,RVal,GVal,BVal);
            } else if( CurToken )
            {      CommandError(MsgStrs[ErrColour]);
            } else CommandError(MsgStrs[ErrNoCol]);
            break;
            
        case(HBondTok):
            FetchToken();
            if( CurToken==NoneTok )
            {   ReDrawFlag |= RFColour;
                ColourHBondNone( True );
            } else if( CurToken==TypeTok )
            {   ReDrawFlag |= RFColour;
                ColourHBondType();
            } else if( ParseColour() )
            {   ReDrawFlag |= RFColour;
                ColourHBondAttrib(True,RVal,GVal,BVal);
            } else if( CurToken )
            {      CommandError(MsgStrs[ErrColour]);
            } else CommandError(MsgStrs[ErrNoCol]);
            break;
            
        case(DotsTok):
            FetchToken();
            if( CurToken==PotentialTok )
            {   ReDrawFlag |= RFColour;
                ColourDotsPotential();
            } else if( ParseColour() )
            {   ReDrawFlag |= RFColour;
                ColourDotsAttrib(RVal,GVal,BVal);
            } else if( CurToken )
            {      CommandError(MsgStrs[ErrColour]);
            } else CommandError(MsgStrs[ErrNoCol]);
            break;
            
    	case(MapTok):
            FetchToken();
            if( CurToken==PotentialTok )
            {   ReDrawFlag |= RFColour;
                MapFlag |= MapColourPot;
                MapFlag &= ~MapColourAtom;
                ApplyMapColour();
            } else if( CurToken==AtomTok )
            {   ReDrawFlag |= RFColour;
                MapFlag |= MapColourAtom;
                MapFlag &= ~MapColourPot;
                ApplyMapColour();
            } else if( ParseColour() )
            {   ReDrawFlag |= RFColour;
                MapRGBCol[0] = RVal;
                MapRGBCol[1] = GVal;
                MapRGBCol[2] = BVal;
                MapFlag &= ~(MapColourPot|MapColourAtom);
                ApplyMapColour();
            } else if( CurToken )
            {      CommandError(MsgStrs[ErrColour]);
            } else CommandError(MsgStrs[ErrNoCol]);
            break;
            
            
        case(MonitorTok):
            FetchToken();
            if( CurToken == NoneTok )
            {   ColourMonitNone();
            } else if( ParseColour() )
            {   ReDrawFlag |= RFColour;
                ColourMonitAttrib(RVal,GVal,BVal);
            } else if( CurToken )
            {      CommandError(MsgStrs[ErrColour]);
            } else CommandError(MsgStrs[ErrNoCol]);
            break;
            
        case(AxesTok):
        case(BoundBoxTok):
        case(UnitCellTok):
            FetchToken();
            if( ParseColour() )
            {   BoxR = RVal;  BoxG = GVal;  BoxB = BVal;
                ReDrawFlag |= RFColour;
            } else if( CurToken )
            {      CommandError(MsgStrs[ErrColour]);
            } else CommandError(MsgStrs[ErrNoCol]);
            break;
            
        case(LabelTok):
            FetchToken();
            if( CurToken==NoneTok )
            {   ReDrawFlag |= RFColour;
                UseLabelCol = False;
            } else if( ParseColour() )
            {   LabR = RVal;  LabG = GVal;  LabB = BVal;
                ReDrawFlag |= RFColour;
                UseLabelCol = True;
            } else if( CurToken )
            {      CommandError(MsgStrs[ErrColour]);
            } else CommandError(MsgStrs[ErrNoCol]);
            break;
            
        case(TraceTok): 
        case(RibbonTok):
        case(StrandsTok):
        case(CartoonTok):  flag = RibColBoth;     break;
        case(Ribbon1Tok):  flag = RibColInside;   break;
        case(Ribbon2Tok):  flag = RibColOutside;  break;
    }
    
    if( flag )
    {   FetchToken();
        if( CurToken==NoneTok )
        {   ReDrawFlag |= RFColour;
            ColourRibbonNone(flag);
        } else if( ParseColour() )
        {   ReDrawFlag |= RFColour;
            ColourRibbonAttrib(flag,RVal,GVal,BVal);
        } else if( CurToken )
        {      CommandError(MsgStrs[ErrColour]);
        } else CommandError(MsgStrs[ErrNoCol]);
    }
}


/* prints out information about all selected objects to terminal */
/* example: Describe(ATM) could print output in terms of:        */
/*          Chain: ?  Group:  ???  ??  Atom:  ???  ????          */
static void DescribeSelected( Selection type )
{
    
    register Chain __far *chain = (Chain __far*)NULL;
    register Group __far *group = (Group __far*)NULL;
    register RAtom __far *ptr   = (RAtom  __far*)NULL;
    AtomRef current;
    int touched    ;
    int ctouched   ;
    int Aselect    ;
    int Acount     ;
    int Gselect    ;
    int Gcount     ;
    int Cselect    ;
    int Ccount     ;
    int model      ;
    char buffer[80];
    
    if(!Database)
        return;
    
    model = -1;
    
    Cselect = Ccount = 0;
    current.chn = NULL;
    ctouched = False;
    for(chain=Database->clist;chain;chain=chain->cnext){
        if (model != chain->model) {
            if (model !=-1 && type==MDL) {
                if (Cselect) {
                sprintf(buffer, "Model: %d\t(%d/%d)\tchains\n",
                        model,Cselect, Ccount);
                WriteString(buffer);
                } else if (ctouched) {
                sprintf(buffer, "Model: %d\tno chain completely selected\n",
                        model);
                WriteString(buffer);
                }
            }
            model = chain->model;
            Cselect = Ccount = 0;
            ctouched = False;
        }
        Gselect =  Gcount = 0;
        touched = False;
        if (current.chn != chain) {
            Ccount++;
            current.chn = chain;
        }
        for(group=chain->glist;group;group=group->gnext){
            Aselect =  Acount = 0;
            current.grp = group;
            for(ptr=group->alist;ptr;ptr=ptr->anext) {
                current.atm = ptr;
                    if( ptr->flag&SelectFlag ) {
                        Aselect++;
                        touched = True;
                        ctouched = True;
                        if( type == ATM || type == CRD){        /* Atom or Coordinates */
                            WriteString(DescribeObj(&current, type));
                            WriteChar('\n');
                        }
                    }
                    Acount++; 
            }     
            if( touched && Acount == Aselect ) {
                Gselect++;
                ctouched++;
            }
            Gcount++;       
            if( Aselect && type == GRP) {	              /* Group */
                WriteString(DescribeObj(&current, GRP));
                sprintf(buffer, "\t(%d/%d)\tatoms\n",Aselect, Acount); 
                WriteString(buffer);
            }
        }
        if (ctouched && Gcount == Gselect) {
            Cselect++;
        }
        if( ctouched && type == CHN ) {                    /* Chain */      
            WriteString(DescribeObj(&current, CHN));
            if( Gselect > 0 ) {
                sprintf(buffer,"\t(%d/%d)\tgroups\n",Gselect, Gcount); 	
                WriteString(buffer);
            }
            else
                WriteString("\tno group completely selected\n");	
        }
    }
    if (model !=-1 && type==MDL) {
        if (Cselect) {
            sprintf(buffer, "Model: %d\t(%d/%d)\tchains\n",
                    model,Cselect, Ccount);
            WriteString(buffer);
        } else if (ctouched) {
            sprintf(buffer, "Model: %d\tno chain completely selected\n",
                    model);
            WriteString(buffer);
        }
    } else if (model == -1 && type==MDL) {
        if (Cselect) {
            sprintf(buffer, "One Model: \t(%d/%d)\tchains\n",
                    Cselect, Ccount);
            WriteString(buffer);
        } else if (ctouched) {
            sprintf(buffer, "%s", "One Model: \tno chain completely selected\n");
            WriteString(buffer);
        }
        
    }
}  


/* Selection for printing selected atoms || groups || chains to terminal  */
static void ExecuteSelectedCommand()
{
    
    switch( FetchToken() )
    {
        case(AtomTok):
            DescribeSelected(ATM);
            break;
        case(CoordTok):
            DescribeSelected(CRD);
            break;
        case(GroupTok):
            DescribeSelected(GRP);
            break;
        case(ChainTok):
            DescribeSelected(CHN);
            break;
        case(ModelTok):
            DescribeSelected(MDL);
            break;
        case(0):
            DescribeSelected(GRP);  /* default option for show selected is 'group' */
            break;
        default:
            CommandError(MsgStrs[ErrBadArg]);
    }
}


static void DescribeSequence( void )
{
    register Chain __far *chn;
    register Group __far *grp;
    register int chain,count;
	register int subcount;
    register char *str;
    char buffer[40];
    int  model;
    
    InvalidateCmndLine();
    if( !Database )
        return;
    
    model = -1;
    for( chn=Database->clist; chn; chn=chn->cnext )
    {   chain = (Info.chaincount<2);  count = 0;
		subcount = -1;
        for( grp=chn->glist; grp; grp=grp->gnext )
            if( grp->alist && !(grp->alist->flag&HeteroFlag) )
            {   if( !chain )
            {   if (!(model==grp->model))
            {   model = grp->model;
                if (model) 
                {  sprintf(buffer,"Model: %d  ",model);
                    WriteString(buffer);
                }
            }
                WriteString("Chain ");
                WriteString(ChIdents[chn->chrefno]);
                WriteString(":\n");
                chain = True;
            }
                
                if( !SeqFormat )
                {   if( count == 10 )
                {   WriteChar('\n');
                    count = 1;
                } else count++;
                    
                    str = Residue[grp->refno];
                    WriteChar(str[0]);
                    WriteChar(str[1]);
                    WriteChar(str[2]);
                    
                    sprintf(buffer,"%-3d ",grp->serno);
                    WriteString(buffer);
                } else
                {   if( count == 50 )
                {   WriteChar('\n');
                    count = 1;
                    subcount = 0;
                } else
                {   count++;
                    subcount++;
                }
                    
					if( subcount == 10)
					{	WriteChar(' ');
						subcount = 0;
					}
                    
                    if( grp->refno < 29 )
                    {   WriteChar(ResidueChar[grp->refno]);
                    } else WriteChar('*');
                }
            }
        WriteChar('\n');
    }
    WriteChar('\n');
}


static void ExecuteShowCommand( void )
{
    register Real temp;
    char buffer[140];
    Real theta,phi,psi;
    
    switch( FetchToken() )
    {   case(DeferTok):
            ShowDeferCommand();
            break;
        
        case(InfoTok):
            DescribeMolecule();
            break;
            
    	case(PlayTok):
    	    ShowPlayCommand();
            break;
            
    	case(RecordTok):
    		ShowRecordCommand();
    		break;
            
    	case(MapTok):
            ApplyMapShow();
            break;
            
        case(SequenceTok):
            DescribeSequence();
            break;
            
        case(SelectedTok):
            ExecuteSelectedCommand();
            break;   
            
        case(PhiPsiTok):
            WritePhiPsiAngles(NULL, False);  /* Writing to stderr/stdout */
            break;        	 
            
        case(RamPrintTok):
            WritePhiPsiAngles(NULL, -1);     /* Writing to stderr/stdout */
            break;        	 
            
        case(SymmetryTok):
            InvalidateCmndLine();
            
            if( *Info.spacegroup )
            {   sprintf(buffer,"%s ...... %s\n",MsgStrs[StrSGroup],Info.spacegroup);
                WriteString(buffer);
                
                sprintf(buffer,"%s A ...... %g\n",MsgStrs[StrUCell],Info.cella);
                WriteString(buffer);
                sprintf(buffer,"%s B ...... %g\n",MsgStrs[StrUCell],Info.cellb);
                WriteString(buffer);
                sprintf(buffer,"%s C ...... %g\n",MsgStrs[StrUCell],Info.cellc);
                WriteString(buffer);
                
                temp = Rad2Deg*Info.cellalpha;
                sprintf(buffer,"%s alpha .. %g\n",MsgStrs[StrUCell],temp);
                WriteString(buffer);
                temp = Rad2Deg*Info.cellbeta;
                sprintf(buffer,"%s beta ... %g\n",MsgStrs[StrUCell],temp);
                WriteString(buffer);
                temp = Rad2Deg*Info.cellgamma;
                sprintf(buffer,"%s gamma .. %g\n",MsgStrs[StrUCell],temp);
                WriteString(buffer);
                
            } else WriteString(MsgStrs[StrSymm]);
            WriteChar('\n');
            break;
            
        case(CentreTok):
            InvalidateCmndLine();
            if ( CenX || CenY || CenZ ) {
#ifdef INVERT
                sprintf(buffer,"centre [%ld,%ld,%ld]\n", CenX, -CenY, -CenZ);
#else
                sprintf(buffer,"centre [%ld,%ld,%ld]\n", CenX, CenY, -CenZ);
#endif
                WriteString(buffer);
            }
            break;
            
        case(RotateTok):
            InvalidateCmndLine();
            ReDrawFlag |= RFRotate;
            PrepareTransform();
            
            /*
             phi = Round(Rad2Deg*asin(RotX[2]));
             if( phi == 90 )
             {   theta = -Round(Rad2Deg*atan2(RotY[0],RotY[1]));
             psi = 0;
             } else if( phi == -90 )
             {   theta = Round(Rad2Deg*atan2(RotY[0],RotY[1]));
             psi = 0;
             } else
             {   theta = Round(Rad2Deg*atan2(RotY[2],RotZ[2]));
             psi =  Round(-Rad2Deg*atan2(RotX[1],RotX[0]));
             }
             */
            
            phi = psi = theta = 0.0;
            RMat2RV(&theta, &phi, &psi, RotX, RotY, RotZ);
            if (fabs(theta) > .0005 || fabs(phi) > .0005 || fabs(psi) > .0005 ){
                CQRQuaternion trot;
                CQRAngles2Quaternion (&trot, theta*PI,
                                      phi*PI,
                                      psi*PI);
                sprintf(buffer,"rotation quaternion: [%g,%g,%g,%g]\n",
                        trot.w,trot.x,trot.y,trot.z);
                WriteString(buffer);
            
            }
            theta *= 180.;
            phi *= 180.;
            psi *= 180.;
            
            
            if( Round(theta) ) {
                sprintf(buffer,"rotate x %d\n",Round(InvertY(-theta)));
                WriteString(buffer);
            }
            if( Round(phi) ) {
                sprintf(buffer,"rotate y %d\n",Round(phi));
                WriteString(buffer);
            }
            if( Round(psi) ) {
                sprintf(buffer,"rotate z %d\n",Round(InvertY(-psi)));
                WriteString(buffer);
            }
 
            if (BondsSelected) {
                BondRot __far *brptr;
                
                brptr = BondsSelected;
                while (brptr) {
                    sprintf(buffer,"bond %ld %ld pick\n", 
                            (brptr->BSrcAtom)->serno, (brptr->BDstAtom)->serno);
                    WriteString(buffer);
                    if( brptr->BRotValue ) {
                        sprintf(buffer,"rotate bond %d\n",
                                Round((brptr->BRotValue)*180.));
                        WriteString(buffer);
                    }
                    brptr = brptr->brnext;
                }
            }
            break;
            
        case(InterpTok):
            InvalidateCmndLine();
            ShowInterpNames();
            break;
            
        case(TranslateTok):
            InvalidateCmndLine();
            /* temp = 100.0*DialValue[DialTX]; */
            temp = (int)(100.0*(Real)(XOffset-WRange)/((Real)XRange*Zoom));
            if( temp ) {
                sprintf(buffer,"translate x %.2f\n",temp);
                WriteString(buffer);
            }
            /* temp = 100.0*DialValue[DialTY]; */
            temp = (int)(100.0*(Real)(YOffset-HRange)/((Real)YRange*Zoom));
            if( temp ) {
                sprintf(buffer,"translate y %.2f\n",InvertY(-temp));
                WriteString(buffer);
            }
            /* temp = 100.0*DialValue[DialTZ]; */
            temp = (int)(100.0*(Real)(ZOffset-10000)/((Real)ZRange*Zoom));
            if( temp ) {
                sprintf(buffer,"translate z %.2f\n",temp);
                WriteString(buffer);
            }
            break;
            
        case(ZoomTok):
            InvalidateCmndLine();
            if( DialValue[DialZoom] != 0.0 )
            {   if( DialValue[DialZoom]<0.0 )
            {   temp = 100.0*DialValue[DialZoom];
            } else temp = 100.0*MaxZoom*DialValue[DialZoom];
                sprintf(buffer,"zoom %d\n",(int)(temp+100));
                WriteString(buffer);
            }
            break;
            
        case(FPSTok):
            InvalidateCmndLine();
            sprintf(buffer,"set play.fps %g\n",play_fps);
                WriteString(buffer);
            sprintf(buffer,"set record.fps %g\n",record_fps);
                WriteString(buffer);
            break;
            
        case(APSTok):
            InvalidateCmndLine();
            sprintf(buffer,"set record.aps %g\n",record_aps);
            WriteString(buffer);
            break;
            
        default:
            CommandError(MsgStrs[ErrBadArg]);
    }
}




/*Function call on "select <...<" , start and continue selection,
 *                  "select <...>" , start and stop selection,
 *               or "select >...>" , continue and stop selection.
 * Escape the parser to make fast atom selection under the format:
 * "select (< or >) x1[-x2],...,xi[-x(i+1)](> or <)" where xi represent atomno.
 */ 
static void ReadAtomSelection( int start )
{	register Long ori=0, end=0;
	register int neg, bloc=0;
	register char ch;
	register Bond __far *bptr;
	register SurfBond __far *sbptr;
	
	if( !Database )
		return;
    
	/*Empty selection at start*/
	if( start )
	{	for( QChain=Database->clist; QChain; QChain=QChain->cnext )
        for( QGroup=QChain->glist; QGroup; QGroup=QGroup->gnext )
            for( QAtom=QGroup->alist; QAtom; QAtom=QAtom->anext )
                QAtom->flag &= ~SelectFlag;
		SelectCount = 0;
	}
	
	NeedAtomTree = 1;
	
	while( *TokenPtr )
	{	bloc = 0;
		neg = 0;
		ch = *TokenPtr++;
        
		/*first number*/
		while( *TokenPtr && isspace(ch) )
			ch= *TokenPtr++;
		if( ch == '-' )
			neg = 1;
		else if( ch != '+' )
			TokenPtr--;
		FetchToken();
		if( CurToken==NumberTok )
		{	ori = TokenValue;
			ch= *TokenPtr++;
			while( *TokenPtr && isspace(ch) )
				ch = *TokenPtr++;
			
			/*second number*/
			if( ch=='-' )
			{	neg = 0;
				ch= *TokenPtr++;
				while( *TokenPtr && isspace(ch) )
					ch = *TokenPtr++;
				if( ch == '-' )
					neg = 1;
				else if( ch != '+' )
					TokenPtr--;
				FetchToken();
				if( CurToken==NumberTok )
				{	end = TokenValue;
					if( neg )
						end = -end;
					ch = *TokenPtr++;
					while( *TokenPtr && isspace(ch) )
						ch = *TokenPtr++;
 					if( ch==','||ch=='>'||ch=='<' )
						bloc = 1;
				}
			} else if( ch==','||ch=='>'||ch=='<' )
			{	end = ori;
				bloc = 1;
			}
		}
        
		if( bloc==1 )
		{	for( QChain=Database->clist; QChain; QChain=QChain->cnext )
            for( QGroup=QChain->glist; QGroup; QGroup=QGroup->gnext )
                for( QAtom=QGroup->alist; QAtom; QAtom=QAtom->anext )
                    if( QAtom->serno >= ori && QAtom->serno <= end )
                    {	if( !(QAtom->flag&SelectFlag) )
                        SelectCount++;
                        QAtom->flag |= SelectFlag;
                    }
		} else
		{	if( ch!=',' && ch!='<' && ch!='>' )		/*not empty bloc*/
            CommandError(MsgStrs[ErrBlocSel]);
			while( *TokenPtr && ch!=',' && ch!='<' && ch!='>' )
				ch = *TokenPtr++;
		}
        
		if( ch==',' )
			continue;
		else if( ch=='<' )	
			bloc = 0;
		else
			bloc = 1;		
		while( *TokenPtr )
            TokenPtr++;
	}
    
	/*termination*/
	if( bloc!=0 )
	{	if( (FileDepth == -1) || !LineStack[FileDepth] )
        DisplaySelectCount( );
        
		if( ZoneBoth )
		{	ForEachBond
            if( (bptr->srcatom->flag&bptr->dstatom->flag) & SelectFlag )
            {   bptr->flag |= SelectFlag;
            } else bptr->flag &= ~SelectFlag;
			ForEachSurfBond
            if( (sbptr->srcatom->flag&sbptr->dstatom->flag) & SelectFlag )
            {   sbptr->flag |= SelectFlag;
            } else sbptr->flag &= ~SelectFlag;
		} else
		{	ForEachBond
            if( (bptr->srcatom->flag|bptr->dstatom->flag) & SelectFlag )
            {   bptr->flag |= SelectFlag;
            } else bptr->flag &= ~SelectFlag;
		    ForEachSurfBond
            if( (sbptr->srcatom->flag|sbptr->dstatom->flag) & SelectFlag )
            {   sbptr->flag |= SelectFlag;
            } else sbptr->flag &= ~SelectFlag;
		}
	}
}



void ZapDatabase( void )
{
    register int i;
	int s; 			/* 's' is for "shade" */
    
    for( i=0; i<10; i++ )
        DialValue[i] = 0.0;
    CQRMSet(DialQRot,0.,0.,0.,0.);
    CQRMSet(AuxQRot,0.,0.,0.,0.);

    SelectCount = 0;
    
    DestroyDatabase();
    ResetSymbolTable();
    ResetTransform();
    ResetRenderer();
    ResetRepres();
    ResetBondsSel();
    DeleteMaps();
    
    ZoneBoth = True;
    HetaGroups = True;    
    Hydrogens = True;
    
	for (s = 0; s < LastShade; s++)
		Shade[s].refcount = 0;
    
#if 0 /* [GSG 11/10/95] */
    BackR = BackG = BackB = 0;
#endif
#ifndef IBMPC
    FBClear = False;
#endif
    
    /* [11/10/95 GSG] Prevent colormap reset, refresh instead of clear */
#if 0
    ResetColourMap();
    DefineColourMap();
    ClearBuffers();
    ReDrawFlag = 0;
#else
    ReDrawFlag = RFRefresh;
#endif
    
    if( Interactive )
    {   UpdateScrollBars();
        /* ClearImage(); [GSG 11/10/95] */
    }
    AdviseUpdate(AdvName);
    AdviseUpdate(AdvClass);
    AdviseUpdate(AdvIdent);
    
    /* [GSG 11/10/95] */
    ZapMolecule();
    ReRadius();
}


void WriteImageFile( char *name, int type, int subtype )
{
    if( !type )
#ifdef EIGHTBIT
        type = GIFTok;
#else
    type = PPMTok;
#endif
    
    if ( (type != VRMLTok) && subtype ) {
        CommandError(MsgStrs[ErrSyntax]);
	}
	else
        
        switch( type )
    {   case(GIFTok):      WriteGIFFile(name);             break;
        case(BMPTok):      WriteBMPFile(name);             break;
        case(PPMTok):      WritePPMFile(name,True);        break;
        case(SUNTok):      WriteRastFile(name,False);      break;
        case(SUNRLETok):   WriteRastFile(name,True);       break;
        case(PICTTok):     WritePICTFile(name);            break;
        case(IRISTok):     WriteIRISFile(name);            break;
        case(EPSFTok):     WriteEPSFFile(name,True,True);  break;
        case(MonoPSTok):   WriteEPSFFile(name,False,True); break;
        case(VectPSTok):   WriteVectPSFile(name);          break;
        case(Raster3DTok): WriteR3DFile(name);             break;
            
        case(RasMolTok):
        case(ScriptTok):     WriteScriptFile(name);       break;
        case(KinemageTok):   WriteKinemageFile(name);     break;
        case(MolScriptTok):  WriteMolScriptFile(name);    break;
        case(POVRayTok):     WritePOVRayFile(name);       break;
        case(POVRay3Tok):    WritePOVRay3File(name);      break;
        case(PhiPsiTok):     WritePhiPsiAngles(name, False); break;
        case(RamachanTok):   WritePhiPsiAngles(name, 1);  break;
        case(RamPrintTok):   WritePhiPsiAngles(name, -1); break;     
        case(VRMLTok):       WriteVRMLFile(name, subtype); break;
            
    }
}


void ResumePauseCommand( void )
{
    register int ch,len;
    register FILE *fp;
    register int stat;
    
    CommandActive = False;
    IsPaused = False;
    
#ifdef MSWIN
    /* Re-enable Drag & Drop! */
    DragAcceptFiles(CanvWin,TRUE);
#endif
    
    while( FileDepth >= 0 )
    {   fp = FileStack[FileDepth];
        do {
            len = 0;
            ch = getc(fp);
            while( (ch!='\n') && (ch!='\r') && (ch!=EOF) )
            {   if( len<MAXBUFFLEN )
                CurLine[len++] = ch;
                ch = getc(fp);
            }
            
            LineStack[FileDepth]++;
            if( len<MAXBUFFLEN )
            {   CurLine[len] = '\0';
                stat = ExecuteCommand();
                if( stat )
                {   if( stat == QuitTok )
                {   while( FileDepth >= 0 )
                {   fclose(FileStack[FileDepth]);
                    _ffree(NameStack[FileDepth]);
                    FileDepth--;
                }
                    RasMolExit();
                } else /* ExitTok */
                    break;
                } else if( IsPaused )
                    return;
            } else CommandError(MsgStrs[StrSLong]);
        } while( ch!=EOF );
        _ffree(NameStack[FileDepth]);
        fclose( fp );
        FileDepth--;
    }
}


void InterruptPauseCommand( void )
{
    WriteString("*** RasMol script interrupted! ***\n\n");
    CommandActive = False;
    IsPaused = False;
    
#ifdef MSWIN
    /* Re-enable Drag & Drop! */
    DragAcceptFiles(CanvWin,TRUE);
#endif
    
    while( FileDepth >= 0 )
    {   fclose(FileStack[FileDepth]);
        _ffree(NameStack[FileDepth]);
        FileDepth--;
    }
}


static void ExecuteConnectCommand( void )
{
    register Bond __far *bptr;
    register int info,flag;
    
    FetchToken();
    if( !CurToken )
    {   flag = (MainAtomCount+HetaAtomCount<256);
    } else if( CurToken == TrueTok )
    {   flag = True;
    } else if( CurToken == FalseTok )
    {   flag = False;
    } else 
    {   CommandError(MsgStrs[ErrSyntax]);
        return;
    }
    
    if( Database )
    {   ForEachBond
        if( bptr->col )
            Shade[Colour2Shade(bptr->col)].refcount--;
        info = (FileDepth == -1);
        CreateMoleculeBonds(info,flag,True);
        ReDrawFlag |= RFRefresh|RFColour;
        EnableWireframe(WireFlag,0,0);
    }
    
	CalcBondsFlag = True;
}


/* Select Maps 
 
 The format of a map command is
 map {<map_selector>} subcommand parameters
 
 where the optional map_selector is one of the following:
 m -- a map number m indicating a particular map for the currently active molecule
 m1-m2 -- a range of map numbers indicating all maps for the current molecule 
 with numbers between m1 and m2, inclusive.   If m1 is blank, m1 is assumed
 to be the number of the first map.  If m2 is blank, m2 is assumed to be the 
 number of the last map.
 next -- the next map number after the highest number selected map in circular order.
 If all maps are already selected or no maps are selected, the result will be selection
 of the first map.  If there are no maps, next has the same effect as new
 new (or none) -- no maps are selected, but if the subcommand changes any parameters 
 or setting, they are changed for the next map to be created
 all -- all maps are selected
 a quoted string to be used as a map label, or one of the above followed by a
 quoted string to be used as a map label
 
 SelectMaps parses map_selector tokens until it is positioned on the
 token after the last token of the map selector, setting the MapMarkedFlag
 for each selected map and, if it is to be applied to the next map,
 the global map flag.  The MapSelectFlag is not changed at this stage.
 The transfer will be done in a call to ApplyMapSelection, to allow the
 processing to be aborted on errors in the subcommand or parameters
 
 
 */

static void SelectMaps( void ) {
    
    int lomap, himap, labfound, nextflag, newflag, j, nummaps;
    int nomapselected;
    int maxmapsel;
    MapInfo *mapinfo;
    
    lomap = -1;
    himap = -1;
    labfound = 0;
    nextflag = 0;
    newflag = 0;
    nummaps = 0;
    nomapselected=1;
    
    if (!MapInfoPtr) InitialiseMaps();
    
    if (MapInfoPtr) nummaps = MapInfoPtr->size;
    FetchToken();
    if ( CurToken ) {
        if (CurToken == NewTok || CurToken == NoneTok) {
            nomapselected = 0;
            newflag = 1;
            FetchToken();
            if (CurToken == StringTok) labfound = 1;
        } else if (CurToken == NextTok)  {
            nomapselected = 0;
            nextflag = 1;
            FetchToken();
            if (CurToken == StringTok) labfound = 1;
        } else if (CurToken == AllTok)  {
            nomapselected = 0;
            lomap = 1;
            himap = nummaps;
            FetchToken();
            if (CurToken == StringTok) labfound = 1;
        } else if (CurToken == NumberTok)  {
            nomapselected = 0;
            lomap = (int)TokenValue;
            himap = lomap;
            FetchToken();
            if (CurToken == '-') {
                himap = nummaps;
                FetchToken();
                if (CurToken == NumberTok) {
                    himap = (int)TokenValue;	
                } else  {
                    if (CurToken == StringTok) labfound = 1;
                }
            } else  {
                if (CurToken == StringTok) labfound = 1;
            }
            
        } else  {
            lomap = 1;
            if (CurToken == '-') {
                nomapselected = 0;
                himap = nummaps;
                FetchToken();
                if (CurToken == NumberTok) {
                    himap = (int)TokenValue;	
                } else  {
                    if (CurToken == StringTok) labfound = 1;
                }
            } else  {
                if (CurToken == StringTok) labfound = 1;
            }
            
        }
        
    }
    
    if (labfound) {
        if (MapLabel)  {
            _ffree(MapLabel);
        }
        MapLabel = _fmalloc(strlen(TokenIdent)+1);
        strcpy(MapLabel,TokenIdent);
    }
    
    MapFlag &= ~(MapMarkedFlag|MapNoSelectFlag);
    if (nomapselected) MapFlag |= MapNoSelectFlag;
    if (MapInfoPtr)  {
        maxmapsel = -1;
        for (j=0; j < MapInfoPtr->size; j++) {
            vector_get_elementptr((GenericVec __far *)MapInfoPtr,(void __far * __far *)&mapinfo,j );
            mapinfo->flag &= (~MapMarkedFlag);
            if (labfound){
                if (j+1 >= lomap && j+1 <=himap
                    && mapinfo->MapLabel 
                    && !strcasecmp(mapinfo->MapLabel,MapLabel)) {
                    maxmapsel = j;
                    mapinfo->flag |= MapMarkedFlag;
                }
            } else {
                if (j+1 >= lomap && j+1 <=himap) {
                    maxmapsel = j;        	
                    mapinfo->flag |= MapMarkedFlag;
                }
            }
        }
        
        if (nextflag) {
            maxmapsel++;
            if ( maxmapsel >= MapInfoPtr->size ) maxmapsel = 1;
            for (j=0; j < MapInfoPtr->size; j++) {
                vector_get_elementptr((GenericVec __far *)MapInfoPtr,(void __far * __far *)&mapinfo,j );
                if (j != maxmapsel) mapinfo->flag &= (~MapMarkedFlag);
                else mapinfo->flag |= MapMarkedFlag;
            }
        }
        
        if (newflag) MapFlag |= MapMarkedFlag;
        
    }
    
    return;
	
}

static void ApplyMapSelection( void ) {
    int j;
    MapInfo *mapinfo;
    
    if (MapFlag&MapNoSelectFlag) return;
    MapFlag &= (~MapSelectFlag);
    if (MapFlag&MapMarkedFlag) MapFlag |= MapSelectFlag;
    
    if (MapInfoPtr)  {
        for (j=0; j < MapInfoPtr->size; j++) {
            vector_get_elementptr((GenericVec __far *)MapInfoPtr,(void __far * __far *)&mapinfo,j );
            mapinfo->flag &= (~MapSelectFlag);
            if (mapinfo->flag&MapMarkedFlag) mapinfo->flag |= MapSelectFlag;
        }
    }
    return;
}

/* 
  ApplyMapAtomSelection
 
     Searchs for atoms within the specified SearchRadius of the points of
     the currently selected maps.  If clear is set, all selections are
     cleared prior to the search.  If current is not set, all atoms are
     selected prior to the search.
 
 */

static void ApplyMapAtomSelection(int dontadd, int searchwithin, int SearchRadius) {
    int i, j;
    MapInfo *mapinfo;
    void CNEARTREE_FAR * objClosest;
    MapPointVec __far *MapPointsPtr;
    double coord[3];
    clock_t tc1,tc2;
    tc1 = clock();

    /*  First we need to set up the selection flags for CreateAtomTree
     
        If we are adding to the selection (dontadd is false)
        we need to save the current selection using SaveFlag
        and restore those selections at the end.
          
        If we are not searching within (searchwithin is false)
        we need to set all selection flags
     
     */
    
    for( QChain=Database->clist; QChain; QChain=QChain->cnext )
        for( QGroup=QChain->glist; QGroup; QGroup=QGroup->gnext )
            for( QAtom=QGroup->alist; QAtom; QAtom=QAtom->anext ) {
                QAtom->flag &= ~SaveFlag;
                if (!dontadd && ((QAtom->flag)&SelectFlag)) QAtom->flag |= SaveFlag;
                if (searchwithin==False)  QAtom->flag |= SelectFlag;
            }
    
    if (!AtomTree || dontadd==True || searchwithin==False || NeedAtomTree) {
        if (CreateAtomTree()) {
            RasMolFatalExit(MsgStrs[StrMalloc]);
        }
    }
#ifdef CNEARTREE_INSTRUMENTED
    visits = 0;
    CNearTreeSetNodeVisits(AtomTree,visits);
#endif
    
    /* Now, clear all selection flags */

    for( QChain=Database->clist; QChain; QChain=QChain->cnext )
        for( QGroup=QChain->glist; QGroup; QGroup=QGroup->gnext )
            for( QAtom=QGroup->alist; QAtom; QAtom=QAtom->anext ) {
                QAtom->flag &= ~SelectFlag;
            }
    

    if (MapInfoPtr)  {
        for (j=0; j < MapInfoPtr->size; j++) {
            vector_get_elementptr((GenericVec __far *)MapInfoPtr,(void __far * __far *)&mapinfo,j );
            if (mapinfo->flag&MapSelectFlag) {
                MapPointsPtr = mapinfo->MapPointsPtr;
                if (MapPointsPtr)
                for (i=0; i<MapPointsPtr->size; i++) {
                    if (!(MapPointsPtr->array[i]).flag&SelectFlag) continue;
                    coord[0] = (double)(MapPointsPtr->array[i]).xpos;
                    coord[1] = (double)(MapPointsPtr->array[i]).ypos;
                    coord[2] = (double)(MapPointsPtr->array[i]).zpos;
                    
                    if (!CNearTreeNearestNeighbor(AtomTree,(double)(SearchRadius),NULL,&objClosest,coord)) {
                        (*((RAtom __far * *)objClosest))->flag |= SelectFlag;
                    }
                 }
           
            }
        }
    }
    
    if (dontadd==False) {
        for( QChain=Database->clist; QChain; QChain=QChain->cnext )
            for( QGroup=QChain->glist; QGroup; QGroup=QGroup->gnext )
                for( QAtom=QGroup->alist; QAtom; QAtom=QAtom->anext ) {
                    if ((QAtom->flag)&SaveFlag) {
                        QAtom->flag |= SelectFlag;
                        QAtom->flag &= ~SaveFlag;
                    }
                }
     }
    
    tc2 = clock();
    fprintf(stderr,"Map select time %g size %ld depth %ld\n",
            ((double)(tc2-tc1))/CLOCKS_PER_SEC,
            (long)(AtomTree->m_szsize),(long)(AtomTree->m_szdepth));  
#ifdef CNEARTREE_INSTRUMENTED
    CNearTreeGetNodeVisits(AtomTree,&visits);
    fprintf(stderr,"Node visits %ld\n", (long)visits);
#endif
    
    NeedAtomTree = 1;
    
    return;
 
	
}

void ApplyMapColour( void ) {
    int i, j;
    MapInfo *mapinfo;
    
    if (MapInfoPtr)  {
        for (j=0; j < MapInfoPtr->size; j++) {
            vector_get_elementptr((GenericVec __far *)MapInfoPtr,(void __far * __far *)&mapinfo,j );
            if (mapinfo->flag&MapSelectFlag) {
                mapinfo->flag &= ~(MapColourPot|MapColourAtom);
                mapinfo->flag |= (MapFlag&(MapColourPot|MapColourAtom));
                for (i=0;i<3;i++) mapinfo->MapRGBCol[i]=MapRGBCol[i];
                if (mapinfo->flag&MapColourPot) ColourPointPotential(j);
                else if(mapinfo->flag&MapColourAtom) ColourPointAtom(j);
                else ColourPointAttrib(mapinfo->MapRGBCol[0],mapinfo->MapRGBCol[1],mapinfo->MapRGBCol[2],j);
            }
        }
    }
    return;
}



static void ApplyMapFlag( void ) {
    int j, mapflag;
    MapInfo *mapinfo;
    
    
    mapflag = MapFlag&(MapPointFlag|MapMeshDashFlag|MapSurfFlag);
    
    if (MapInfoPtr)  {
        for (j=0; j < MapInfoPtr->size; j++) {
            vector_get_elementptr((GenericVec __far *)MapInfoPtr,(void __far * __far *)&mapinfo,j );
            if (mapinfo->flag&MapSelectFlag) {
                mapinfo->flag |= mapflag;
                DeleteMap(j,True);
                if (mapinfo->MapPtr) {
                    if (mapinfo->flag&(MapPointFlag|MapMeshFlag|MapSurfFlag)) {
                        vector_create((GenericVec __far **)&mapinfo->MapPointsPtr,sizeof(MapPoint),1000);
                        if (mapinfo->flag&(MapMeshFlag))
                            vector_create((GenericVec __far **)&mapinfo->MapBondsPtr,sizeof(MapBond),1000);
                        if (mapinfo->flag&(MapSurfFlag))
                            vector_create((GenericVec __far **)&mapinfo->MapTanglePtr,sizeof(MapTangle),1000);
                        map_points(mapinfo->MapPtr, 
                                   mapinfo->MapLevel+((mapinfo->flag&MapMeanFlag)?mapinfo->MapPtr->mapdatamean:0.), 
                                   mapinfo->MapSpacing, mapinfo->MapPointsPtr,mapinfo->MapBondsPtr,mapinfo->MapTanglePtr,
                                   mapinfo->MapMaskPtr, mapinfo->MapRGBCol );
                        if (mapinfo->flag&MapColourPot) ColourPointPotential(j);
                        if (mapinfo->flag&MapColourAtom) ColourPointAtom(j);
                    }
                }
            }
        }
    }
    MapReRadius();
    ReRadius();
    ReDrawFlag |= RFInitial|RFColour;
    return;
}

static void ApplyMapLevel( void ) {
    int j, mapflag;
    MapInfo *mapinfo;
    
    mapflag = MapFlag&MapMeanFlag;
    
    if (MapInfoPtr)  {
        for (j=0; j < MapInfoPtr->size; j++) {
            vector_get_elementptr((GenericVec __far *)MapInfoPtr,(void __far * __far *)&mapinfo,j );
            if (mapinfo->flag&MapSelectFlag) {
                mapinfo->flag &= ~MapMeanFlag;
                mapinfo->flag |= mapflag;
                mapinfo->MapLevel = MapLevel;      	
            }
        }
    }
    return;
}


static void ApplyMapSpread( void ) {
    int j;
    MapInfo *mapinfo;
    
    if (MapInfoPtr)  {
        for (j=0; j < MapInfoPtr->size; j++) {
            vector_get_elementptr((GenericVec __far *)MapInfoPtr,(void __far * __far *)&mapinfo,j );
            if (mapinfo->flag&MapSelectFlag) {
                mapinfo->MapSpread = MapSpread;
            }
        }
    }
    return;
}


static void ApplyMapSpacing( void ) {
    int j;
    MapInfo *mapinfo;
    
    if (MapInfoPtr)  {
        for (j=0; j < MapInfoPtr->size; j++) {
            vector_get_elementptr((GenericVec __far *)MapInfoPtr,(void __far * __far *)&mapinfo,j );
            if (mapinfo->flag&MapSelectFlag) {
                mapinfo->MapSpacing = MapSpacing;
            }
        }
    }
    return;
}

static void ApplyMapZap( void ) {
    int j;
    MapInfo *mapinfo;
    
    if (MapInfoPtr)  {
        for (j=0; j < MapInfoPtr->size; j++) {
            vector_get_elementptr((GenericVec __far *)MapInfoPtr,(void __far * __far *)&mapinfo,j );
            if (mapinfo->flag&MapSelectFlag) {
                DeleteMap(j,False);
            }
        }
    }
    return;
}

static void ApplyMapRestriction( void ) {
    int j;
    MapInfo *mapinfo;
    
    if (MapInfoPtr)  {
        for (j=0; j < MapInfoPtr->size; j++) {
            vector_get_elementptr((GenericVec __far *)MapInfoPtr,(void __far * __far *)&mapinfo,j );
            if (!mapinfo->flag&MapSelectFlag) {
                DeleteMap(j,True);
            }
        }
    }
    return;
}


/*  Code for calculation of the distance from a point to the Lee-Richards
    Surface of a pair of atoms
    
      x is the location of the test point
      a is the location of the first atom
      b is the location of the second atom
      ra, rb and rp are the radii of a, b and the probe */
      
#define vsub(result,src,dst) \
      result[0] = dst[0]-src[0]; result[1] = dst[1]-src[1]; result[2] = dst[2]-src[2];
#define vadd(result,src,dst) \
      result[0] = dst[0]+src[0]; result[1] = dst[1]+src[1]; result[2] = dst[2]+src[2];
#define vdot(u,v) \
      u[0]*v[0] + u[1]*v[1] + u[2]*v[2]
#define vscale(result,scalar,vector) \
      result[0] = scalar*vector[0]; result[1] = scalar*vector[1]; result[2] = scalar*vector[2]; 

/*
                                p
                               _*_
                               /|\
                              / | \
                             /  |  \
                            /   |   \
                           /    |    \
                       rp /     |     \ rp
                         /      |      \
                        /       |       \
                       /      rp|        \
                      /         |         \                 *x
                     /          |          \
                   \/           |           \/
                   /|           |           |\
                  / |          _|           | \
                 /  |           |           |  \
             ra /   |           |           |   \ rb
               /    |           |           |    \
              /     |           |           |     \
             /      |          dpc          |      \
            /       |           |           |       \
         \ /        |           |           |        \ /
          *---------*-----------*-----------*---------*
          a         e           c           f         b
          |---dae---|-----dec---|---dfc-----|---dfb---|
          |---------dac---------|---------dbc---------|
          |--------------------dab--------------------|

*/






#include <math.h>



double surfdist(double x[3], double a[3], double b[3], 
                double ra,   double rb,   double rp) {
    
    double dxas, dxbs;      /* signed distances from x to vdw surfaces */
    double xa[3], xb[3];    /* vectors from x to a and b */
    double dab;             /* distance from a to b */
    double dpc;             /* distance from probe center, p, to c */
    double vab[3];          /* vector from a to b */
    double uab[3];          /* unit vector along a to b vector */
    double c[3];            /* break point between ends of the reentrant surface */
    double dac, dbc;        /* distances from a to c and b to c */
    double xc[3];           /* x redone as vector from c to x */
    double xcaxial[3];      /* the axial vector component of xc */
    double dxcaxial;        /* the axial coordinate of xcaxial */ 
    double xcperp[3];       /* the orthogonal vector component of xc */
    double dxcperp;         /* the orthogonal coordinate of xc */
    double dpasq, dpbsq;    /* squares of lengths from probe center to a and b */
    double dpxsq;           /* square of length from probe center to x */
    double rtot;            /* ra + rb + 2*rb */
    double vdwdist;         /* the distance to the van der Waals surface */
    
    vsub(xa,a,x)
    vsub(xb,b,x)
    dxas = sqrt(vdot(xa,xa)) -ra;
    dxbs = sqrt(vdot(xb,xb)) -rb;
    vsub(vab,a,b)
    dab = sqrt(vdot(vab,vab));
    rtot = ra+rb+rp+rp;
    if ((dxas * dxbs) >= 0. ) {
        
        if (fabs(dxas)<fabs(dxbs)) {
            
            vdwdist = dxas;
            
        } else {
            
            vdwdist = dxbs;
            
        }
        
    } else {
        
        if ( dxas < dxbs ) {
            
            vdwdist = dxas;
            
        } else {
            
            vdwdist = dxbs;
            
        }
    }
    
    /* if the distance is too large or too small ignore the reentrant surface */
    if (dab > rtot || dab < (ra+rb)/2.) {
        
        return vdwdist;
        
    }  else {
        
        vscale(uab,1./dab,vab)
        dac = .5*((rtot)*(ra-rb)/dab + dab);
        dbc = .5*((rtot)*(rb-ra)/dab + dab);
        vscale(c,dac,uab)
        vadd(c,a,c)
        vsub(xc,c,x)
        dxcaxial = vdot(xc,uab);
        vscale(xcaxial,dxcaxial,uab)
        vsub(xcperp,xcaxial,xc)
        dxcperp = sqrt(vdot(xcperp,xcperp));
        dpc = sqrt((rp+rb)*(rp+rb) - dbc*dbc);
        
        /* If x is further from the axis than p
         just return the van der Waals distance 
         otherwise we will need to check if the
         angle between x-p and c-p is less than
         the angle between a-p or b-p and c-p*/
        
        if (dxcperp >= dpc || dpc < rp ) {
            
            return vdwdist;    
            
        } else {
            
            /* In the (axial, perp) coordinate frame centered on c:
             
             x = (dxcaxial,dxcperp)
             p = (o,dpc)
             a = (-dac,0)
             b = (dbc,0)
             
             
             so (a-p).(c-p) = (-dac,-dpc).(0,-dpc) = dpc*dpc
             (b-p).(c-p) = dpc*dpc
             ||a-p|| = sqrt(dac*dac+dpc*dpc)
             ||b-p|| = sqrt(dbc*dbc+dpc*dpc)
             
             We are inside a sector from p to the reentrant surface, on,
             say, the a side, if the cosine of the angle between a-p and
             c-p is larger than the cosine of the angle between x-p and c-p:
             
             |(a-p).(c-p)|/(||a-p||.||c-p||) >= |(x-p).(c-p)|/(||x-p||.||c-p||)
             or
             ||x-p||*|(a-p).(c-p)|>=||a-p||*|(x-p).(c-p)|
             or 
             ||x-p||*dpc*dpc >= sqrt(dac*dac+dpc*dpc)*|(dxcperp-dpc)*dpc|
             or
             ||x-p||*dpc >= sqrt(dac*dac+dpc*dpc)*|(dxcperp-dpc)|
             
             
             */
            
            dpxsq = dxcaxial*dxcaxial + (dxcperp-dpc)*(dxcperp-dpc);
            
            if (dxcaxial > 0.){
                /* x is on the b-side */
                
                dpbsq =  dbc*dbc + dpc*dpc;
                
                if (dpc*dpc*dpxsq >= (dxcperp-dpc)*(dxcperp-dpc)*dpbsq) {
                    
                    return vdwdist;
                    
                } else {
                    
                    return rp - sqrt(dpxsq);
                    
                }
                
            } else {
                
                dpasq =  dac*dac + dpc*dpc;
                
                if (dpc*dpc*dpxsq >= (dxcperp-dpc)*(dxcperp-dpc)*dpasq) {
                    
                    return vdwdist;
                    
                } else {
                    
                    return rp - sqrt(dpxsq);
                    
                }
                
                
            }
            
        }
        
    }
    
}




/* 
 ApplyMapAtomShow
 
 Searchs for atoms within the specified SearchRadius of the points of
 the currently selected maps.  Show the statistics of the distances
 from the map points to the molecular surface of those atoms
 
 */

static void ApplyMapAtomShow(int SearchRadius) {
    int i, j;
    MapInfo *mapinfo;
    void CNEARTREE_FAR * objClosest;
    MapPointVec __far *MapPointsPtr;
    double coord[3], acoord[3], bcoord[3], arad, brad;
    CVectorHandle atomsclosest;
    double vdwdistmin, vdwdistmax, vdwdistmean, vdwvariance;
    double lrdistmin, lrdistmax, lrdistmean, lrvariance;    
    double dtemp, vdwdtemp;
    int vdwpcount, vdwptotal, lrpcount, lrptotal;
    char buffer[133];
    
    CVectorCreate(&atomsclosest,sizeof(void CVECTOR_FAR *),2);
    
    vdwpcount = vdwptotal = 0;
    
    vdwdistmean = 0.;
    vdwvariance = 0.;
    vdwdistmin = 1.e9;
    vdwdistmax = -1.e9;
    
    lrpcount = lrptotal =0;
    
    lrdistmean = 0.;
    lrvariance = 0;
    lrdistmin = 1.e9;
    lrdistmax = -1.e9;
    
    
    if (!AtomTree || NeedAtomTree ) {
        if (CreateAtomTree()) {
            RasMolFatalExit(MsgStrs[StrMalloc]);
        }
    }
    
    if (MapInfoPtr)  {
        for (j=0; j < MapInfoPtr->size; j++) {
            vector_get_elementptr((GenericVec __far *)MapInfoPtr,(void __far * __far *)&mapinfo,j );
            if (mapinfo->flag&MapSelectFlag) {
                MapPointsPtr = mapinfo->MapPointsPtr;
                if (MapPointsPtr)
                    for (i=0; i<MapPointsPtr->size; i++) {
                        if (!(MapPointsPtr->array[i]).flag&SelectFlag) continue;
                        coord[0] = (double)(MapPointsPtr->array[i]).xpos;
                        coord[1] = (double)(MapPointsPtr->array[i]).ypos;
                        coord[2] = (double)(MapPointsPtr->array[i]).zpos;
                        vdwptotal ++;
                        lrptotal ++;
                        
                        if (!CNearTreeNearestNeighbor(AtomTree,(double)(SearchRadius),NULL,&objClosest,coord)) {
                            acoord[0] =  (double)(*((RAtom __far * *)objClosest))->xorg
                                         + (double)(*((RAtom __far * *)objClosest))->fxorg
                                         + ((double)(*((RAtom __far * *)objClosest))->xtrl)/40.;
                            acoord[1] =  (double)(*((RAtom __far * *)objClosest))->yorg
                                         + (double)(*((RAtom __far * *)objClosest))->fyorg
                                         + ((double)(*((RAtom __far * *)objClosest))->ytrl)/40.;
                            acoord[2] =  (double)(*((RAtom __far * *)objClosest))->zorg
                                         + (double)(*((RAtom __far * *)objClosest))->fzorg
                                         + ((double)(*((RAtom __far * *)objClosest))->ztrl)/40.;
                            arad = (double)ElemVDWRadius((*((RAtom __far * *)objClosest))->elemno);
                            vdwdtemp = sqrt((coord[0]-acoord[0])*(coord[0]-acoord[0]) +
                                         (coord[1]-acoord[1])*(coord[1]-acoord[1]) +
                                         (coord[2]-acoord[2])*(coord[2]-acoord[2]))-arad;
                            if (fabs(vdwdtemp) <= SearchRadius-((ProbeRadius < 10)?350:ProbeRadius)) {
                                vdwpcount++;
                                if (vdwpcount == 1) {
                                    vdwdistmin = vdwdistmax = vdwdtemp;
                                } else {
                                    if (vdwdtemp < vdwdistmin) vdwdistmin = vdwdtemp;
                                    if (vdwdtemp > vdwdistmax) vdwdistmax = vdwdtemp;
                                }
                                vdwdistmean += vdwdtemp;
                                vdwvariance += vdwdtemp*vdwdtemp;
                            }
                        }                            

                        
                        if (!CNearTreeFindKNearest(AtomTree,2,(double)(SearchRadius),NULL,atomsclosest,coord,1)) {
                            switch (CVectorSize(atomsclosest)) {
                                case 0: break;
                                case 1: 
                                    objClosest = CVectorElementAt(atomsclosest,0);
                                    acoord[0] =  (double)(**((RAtom __far * * *)objClosest))->xorg
                                                 + (double)(**((RAtom __far * * *)objClosest))->fxorg
                                                 + ((double)(**((RAtom __far * * *)objClosest))->xtrl)/40.;
                                    acoord[1] =  (double)(**((RAtom __far * * *)objClosest))->yorg
                                                 + (double)(**((RAtom __far * * *)objClosest))->fyorg
                                                 + ((double)(**((RAtom __far * * *)objClosest))->ytrl)/40.;
                                    acoord[2] =  (double)(**((RAtom __far * * *)objClosest))->zorg
                                                 + (double)(**((RAtom __far * * *)objClosest))->fzorg
                                                 + ((double)(**((RAtom __far * * *)objClosest))->ztrl)/40.;
                                    arad = (double)ElemVDWRadius((**((RAtom __far * * * )objClosest))->elemno);
                                    dtemp = sqrt((coord[0]-acoord[0])*(coord[0]-acoord[0]) +
                                                 (coord[1]-acoord[1])*(coord[1]-acoord[1]) +
                                                 (coord[2]-acoord[2])*(coord[2]-acoord[2]))-arad;
                                    if (fabs(dtemp) <= SearchRadius-((ProbeRadius < 10)?350:ProbeRadius)) {
                                        lrpcount++;
                                        if (lrpcount == 1) {
                                            lrdistmin = lrdistmax = dtemp;
                                        } else {
                                            if (dtemp < lrdistmin) lrdistmin = dtemp;
                                            if (dtemp > lrdistmax) lrdistmax = dtemp;
                                        }
                                        lrdistmean += dtemp;
                                        lrvariance += dtemp*dtemp;
                                    }
                                    break;
                                case 2: 
                                    objClosest = CVectorElementAt(atomsclosest,0);
                                    acoord[0] =  (double)(**((RAtom __far * * *)objClosest))->xorg
                                                 + (double)(**((RAtom __far * * *)objClosest))->fxorg
                                                 + ((double)(**((RAtom __far * * *)objClosest))->xtrl)/40.;
                                    acoord[1] =  (double)(**((RAtom __far * * *)objClosest))->yorg
                                                 + (double)(**((RAtom __far * * *)objClosest))->fyorg
                                                 + ((double)(**((RAtom __far * * *)objClosest))->ytrl)/40.;
                                    acoord[2] =  (double)(**((RAtom __far * * *)objClosest))->zorg
                                                 + (double)(**((RAtom __far * * *)objClosest))->fzorg
                                                 + ((double)(**((RAtom __far * * *)objClosest))->ztrl)/40.;
                                    arad = (double)ElemVDWRadius((**((RAtom __far * * *)objClosest))->elemno);
                                    objClosest = CVectorElementAt(atomsclosest,1);
                                    bcoord[0] =  (double)(**((RAtom __far * * *)objClosest))->xorg
                                                 + (double)(**((RAtom __far * * *)objClosest))->fxorg
                                                 + ((double)(**((RAtom __far * * *)objClosest))->xtrl)/40.;
                                    bcoord[1] =  (double)(**((RAtom __far * * *)objClosest))->yorg
                                                 + (double)(**((RAtom __far * * *)objClosest))->fyorg
                                                 + ((double)(**((RAtom __far * * *)objClosest))->ytrl)/40.;
                                    bcoord[2] =  (double)(**((RAtom __far * * *)objClosest))->zorg
                                                 + (double)(**((RAtom __far * * *)objClosest))->fzorg
                                                 + ((double)(**((RAtom __far * * *)objClosest))->ztrl)/40.;
                                    brad = (double)ElemVDWRadius((**((RAtom __far * * *)objClosest))->elemno);
                                    dtemp = surfdist(coord,acoord,bcoord,arad,brad,(double)((ProbeRadius < 10)?350:ProbeRadius));
                                    lrpcount++;
                                    if (lrpcount == 1) {
                                        lrdistmin = lrdistmax = dtemp;
                                    } else {
                                        if (dtemp < lrdistmin) lrdistmin = dtemp;
                                        if (dtemp > lrdistmax) lrdistmax = dtemp;
                                    }
                                    lrdistmean += dtemp;
                                    lrvariance += dtemp*dtemp;
                                    break;  
                             }
                        
                        } 
                    }
                         
                
            }
        }
    }
    
    sprintf(buffer,"        points in mesh, points used in distances:\n          total %d, used %d, within %g of surface\n",
            vdwptotal, vdwpcount, ((double)(SearchRadius-((ProbeRadius < 10)?350:ProbeRadius)))/250.);
    WriteString(buffer);
    if (vdwpcount > 0) {
        vdwdistmean /= (250.*(double)vdwpcount);
        vdwvariance /= (250.*250.*(double)vdwpcount)-vdwdistmean;
        vdwdistmin /= 250.;
        vdwdistmax /= 250.;
        sprintf(buffer,"        distance to selected van der Waals surface:\n          mean %#g, min %#g, max %#g, esd %#g\n",
                vdwdistmean, vdwdistmin, vdwdistmax, sqrt(vdwvariance) );
        WriteString(buffer);
    }
 
    if (lrpcount > 0) {
        lrdistmean /= (250.*(double)lrpcount);
        lrvariance /= (250.*250.*(double)lrpcount)-lrdistmean;
        lrdistmin /= 250.;
        lrdistmax /= 250.;
        sprintf(buffer,"        distance to selected Lee-Richards  surface:\n          mean %#g, min %#g, max %#g, esd %#g\n",
                lrdistmean, lrdistmin, lrdistmax, sqrt(lrvariance) );
        WriteString(buffer);
    }
    
    CVectorFree(&atomsclosest);
    return;
    
	
}


void ApplyMapShow( void ) {
    int j;
    MapInfo *mapinfo;
    char buffer[1124];
    
    InvalidateCmndLine();
    
    if (MapFlag & MapSelectFlag) {
        sprintf(buffer,"map new %s %s %#lg spacing %#lg spread %#lg\n",
                MapFlag&MapSurfFlag?"surface":(MapFlag&MapMeshFlag?"mesh":(
                                                                           MapFlag&MapPointFlag?"dots":"unknown") ),
                MapFlag&MapMeanFlag?"level MEAN ":"level ",(double)MapLevel,
                (double)MapSpacing/250., (double)MapSpread);
        WriteString(buffer); 
        if (MapMaskPtr) {
            sprintf(buffer,"mask: mean %#g, esd %#g, min %#g, max %#g\n", 
                    MapMaskPtr->mapdatamean,
                    MapMaskPtr->mapdataesd,
                    MapMaskPtr->mapdatamin,
                    MapMaskPtr->mapdatamax );
            WriteString(buffer);         
        }
    }
    
    if (MapInfoPtr)  {
        for (j=0; j < MapInfoPtr->size; j++) {
            vector_get_elementptr((GenericVec __far *)MapInfoPtr,(void __far * __far *)&mapinfo,j );
            if (mapinfo->flag&MapSelectFlag) {
                sprintf(buffer,"map %d: %s %s %lg spacing %#lg spread %#lg %s %s\n",j+1,
                        mapinfo->flag&MapSurfFlag?"surface":(mapinfo->flag&MapMeshFlag?"mesh":(
                                                                                               mapinfo->flag&MapPointFlag?"dots":"unknown") ),
                        mapinfo->flag&MapMeanFlag?"level MEAN ":"level ",(double)mapinfo->MapLevel,
                        (double)mapinfo->MapSpacing/250., (double)mapinfo->MapSpread,
                        mapinfo->MapFile?"file: ":"",
                        mapinfo->MapFile?mapinfo->MapFile:"");
                WriteString(buffer);
                if (mapinfo->MapLabel) {
                    WriteString("label: ");
                    WriteString(mapinfo->MapLabel);
                    WriteString("\n");
                }
                if (mapinfo->MapPtr) {
                    sprintf(buffer,"map:    mean %#g, esd %#g, min %#g, max %#g\n", 
                            mapinfo->MapPtr->mapdatamean,
                            mapinfo->MapPtr->mapdataesd,
                            mapinfo->MapPtr->mapdatamin,
                            mapinfo->MapPtr->mapdatamax );
                    WriteString(buffer);
                    ApplyMapAtomShow( 1000 + ((ProbeRadius< 10)?350:ProbeRadius) );
                } else {
                    WriteString("map: NONE\n");
                }
                if (mapinfo->MapMaskPtr) {
                    sprintf(buffer,"mask:   mean %#g, esd %#g, min %#g, max %#g\n", 
                            mapinfo->MapMaskPtr->mapdatamean,
                            mapinfo->MapMaskPtr->mapdataesd,
                            mapinfo->MapMaskPtr->mapdatamin,
                            mapinfo->MapMaskPtr->mapdatamax );
                    WriteString(buffer);         
                }
            }
        }
    }
    return;
}


int ApplyMapMask(int mapno ) {
    int i,j;
    MapInfo *mapinfo, *omapinfo;
    MapStruct __far *mapmaskptr;
    MapAtmSelVec __far *mapmaskgensel;
    Long flag;
    
    ApplyMapSelection();
    if (MapSpacing <= 0) MapSpacing = 250L;
    
    if (MapInfoPtr)  {
        if (mapno != -1 && mapno > MapInfoPtr->size)  {
            CommandError(MsgStrs[ErrBadArg]);
            return 1;
        }
        if (mapno > 0) {
            vector_get_elementptr((GenericVec __far *)MapInfoPtr,(void __far * __far *)&mapinfo,mapno-1);
            if (!mapinfo || !mapinfo->MapPtr) {
                CommandError(MsgStrs[ErrBadArg]);
                return 1;
            }
        }
        for (j=-1; j==-1 || j < MapInfoPtr->size; j++) {
            mapmaskgensel = NULL;
            mapmaskptr = NULL;
            
            if (j >=0 ) {
                vector_get_elementptr((GenericVec __far *)MapInfoPtr,(void __far * __far *)&mapinfo,j );
                flag = mapinfo->flag;
            } else  {
                flag=MapFlag;
            }
            
            if (flag&MapSelectFlag) {
                if (mapno == 0) {
                    
                    if (MapSpread < 0.) MapSpread = 2.*(double)MapSpacing/750.;
                    
                    if(generate_map(&mapmaskptr,MapSpacing, 
                                    MapSpacing, MapSpacing, 0L, 0L, 0L,
                                    (Long)(250.*(1.+MapSpread)+MapSpacing), 
                                    (MapSpread > 0.)?(1./MapSpread):0., 
                                    (flag&MapScaleFlag)?1:0,
                                    flag&MapSASurfFlag)){
                        CommandError(MsgStrs[StrMalloc]);
                        return 1;
                    }
                    
                    vector_create((GenericVec __far **)&mapmaskgensel,sizeof(MapAtmSel),10);
                    WriteMapAtoms(mapmaskgensel);
                } else if (mapno > 0) {
                    if ( mapno <= MapInfoPtr->size ) {
                        vector_get_elementptr((GenericVec __far *)MapInfoPtr,(void __far * __far *)&omapinfo,mapno-1 );
                        if (omapinfo && omapinfo->MapPtr) {
                            mapmaskptr = (MapStruct __far *)_fmalloc(sizeof(MapStruct));
                            if(!mapmaskptr) {
                                CommandError(MsgStrs[StrMalloc]);
                                return 1;	
                            }
                            mapmaskptr->mapdata = _fmalloc(omapinfo->MapPtr->elsize*
                                                           ((omapinfo->MapPtr)->xhigh-(omapinfo->MapPtr)->xlow+1)*
                                                           ((omapinfo->MapPtr)->yhigh-(omapinfo->MapPtr)->ylow+1)*
                                                           ((omapinfo->MapPtr)->zhigh-(omapinfo->MapPtr)->zlow+1));
                            if(!mapmaskptr->mapdata) {
                                _ffree(mapmaskptr);
                                CommandError(MsgStrs[StrMalloc]);
                                return 1;
                            }
                            mapmaskptr->elsize=omapinfo->MapPtr->elsize;
                            mapmaskptr->eltype=omapinfo->MapPtr->eltype;
                            mapmaskptr->maptype=omapinfo->MapPtr->maptype;
                            mapmaskptr->adiv=omapinfo->MapPtr->adiv;
                            mapmaskptr->bdiv=omapinfo->MapPtr->bdiv;
                            mapmaskptr->cdiv=omapinfo->MapPtr->cdiv;
                            mapmaskptr->xint=omapinfo->MapPtr->xint;
                            mapmaskptr->yint=omapinfo->MapPtr->yint;
                            mapmaskptr->zint=omapinfo->MapPtr->zint;
                            mapmaskptr->xorig=omapinfo->MapPtr->xorig;
                            mapmaskptr->yorig=omapinfo->MapPtr->yorig;
                            mapmaskptr->zorig=omapinfo->MapPtr->zorig;
                            mapmaskptr->xlow=omapinfo->MapPtr->xlow;
                            mapmaskptr->ylow=omapinfo->MapPtr->ylow;
                            mapmaskptr->zlow=omapinfo->MapPtr->zlow;
                            mapmaskptr->xhigh=omapinfo->MapPtr->xhigh;
                            mapmaskptr->yhigh=omapinfo->MapPtr->yhigh;
                            mapmaskptr->zhigh=omapinfo->MapPtr->zhigh;
                            mapmaskptr->mapdatamin=omapinfo->MapPtr->mapdatamin;
                            mapmaskptr->mapdatamax=omapinfo->MapPtr->mapdatamax;
                            mapmaskptr->mapdatamean=omapinfo->MapPtr->mapdatamean;
                            mapmaskptr->mapdataesd=omapinfo->MapPtr->mapdataesd;
                            for (i=0; i<9; i++) {
                                mapmaskptr->mapm2r[i]=omapinfo->MapPtr->mapm2r[i];
                                mapmaskptr->mapr2m[i]=omapinfo->MapPtr->mapr2m[i];
                            }
                            for (i=0; i<3; i++) {
                                mapmaskptr->mapxlate[i]=omapinfo->MapPtr->mapxlate[i];
                            }
                            memmove(mapmaskptr->mapdata,omapinfo->MapPtr->mapdata,
                                    ((mapmaskptr)->xhigh-(mapmaskptr)->xlow+1)
                                    *((mapmaskptr)->yhigh-(mapmaskptr)->ylow+1)
                                    *((mapmaskptr)->zhigh-(mapmaskptr)->zlow+1)
                                    *((mapmaskptr)->elsize));
                            if (omapinfo->MapGenSel) {
                                MapAtmSel *mapatmsel;
                                vector_create((GenericVec __far **)&mapmaskgensel,sizeof(MapAtmSel),10);
                                for (i = 0; i < omapinfo->MapGenSel->size; i++) {
                                    vector_get_elementptr((GenericVec __far *)omapinfo->MapGenSel,(void __far * __far *)&mapatmsel,i );
                                    vector_set_element((GenericVec __far *)mapmaskgensel,mapatmsel,i);
                                }
                            }
                        }
                    }
                }
                if (j < 0 )  {
                    if (MapMaskPtr)  {
                        if (MapMaskPtr->mapdata)_ffree((void __far *)MapMaskPtr->mapdata);
                        _ffree((void __far *)MapMaskPtr);            	
                    }
                    MapMaskPtr = mapmaskptr;
                } else {
                    if (mapinfo->MapMaskPtr) {
                        if (mapinfo->MapMaskPtr->mapdata)_ffree((void __far *)mapinfo->MapMaskPtr->mapdata);
                        _ffree((void __far *)mapinfo->MapMaskPtr);
                    }
                    mapinfo->MapMaskPtr = mapmaskptr;
                }
                if (j < 0 )  {
                    if (MapMaskGenSel)  {
                        vector_free((GenericVec __far * __far *)&(MapMaskGenSel ) );
                    }
                    MapMaskGenSel=mapmaskgensel;
                } else {
                    if (mapinfo->MapMaskGenSel) {
                        vector_free((GenericVec __far * __far *)&(mapinfo->MapMaskGenSel ) );
                    }
                    mapinfo->MapMaskGenSel=mapmaskgensel;
                }
            }       
        }
    }
    MapReRadius();
    ReRadius();
    ReDrawFlag |= RFInitial|RFColour;
    return 0;
}

/* Generate a new map for the current molecule */

static int ExecuteGenerateCommand( int mapflags ) {
    int i, j;
    MapInfo mapinfo;
    MapInfo *omapinfo;
    MapStruct __far *mapmaskptr;
    MapAtmSelVec __far *mapmaskgensel;
    Long MapSpaceAdjust;
    int mapallocfailed;
    int SASflag;
    char buffer[60];
    
    ApplyMapSelection();
    if (MapSpacing <= 0) MapSpacing = 250L;
    
    /* Initialize a mapinfo struct */
    
    mapinfo.MapLevel = MapLevel;
    mapinfo.MapSpacing = MapSpacing;
    if (mapinfo.MapSpacing < 25) mapinfo.MapSpacing = 25;
    if (MapSpread < 0.) MapSpread = 2.*((double)(MapSpacing))/750.;
    mapinfo.MapSpread = MapSpread;
    mapinfo.flag = SelectFlag|mapflags;
    SASflag = mapinfo.flag&MapSASurfFlag;
    if (mapinfo.flag&(MapLRSurfFlag|MapSASurfFlag)) {
        mapinfo.MapSpread = 0.;
        mapinfo.MapLevel = 1.;
        mapinfo.flag &= ~(MapMeanFlag|MapScaleFlag);
    }
    mapinfo.MapPointsPtr = NULL;
    mapinfo.MapBondsPtr = NULL;
    mapinfo.MapTanglePtr = NULL;
    mapinfo.MapPtr = NULL;
    mapinfo.MapMaskPtr = NULL;
    mapinfo.MapFile = NULL;
    mapinfo.MapGenSel = NULL;
    mapinfo.MapMaskGenSel = NULL;
    mapinfo.MapRGBCol[0] = MapRGBCol[0];
    mapinfo.MapRGBCol[1] = MapRGBCol[1];
    mapinfo.MapRGBCol[2] = MapRGBCol[2];
    mapinfo.MapMeshRad = MapMeshRad;
    mapinfo.MapPointRad = MapPointRad;
    mapinfo.MapLabel = MapLabel;
    MapLabel = NULL;
    if (MapMaskPtr) {
        mapmaskptr = (MapStruct __far *)_fmalloc(sizeof(MapStruct));
        if(!mapmaskptr) {
            CommandError(MsgStrs[StrMalloc]);
            return 1;	
        }
        mapmaskptr->mapdata = _fmalloc(MapMaskPtr->elsize*
                                       ((MapMaskPtr)->xhigh-(MapMaskPtr)->xlow+1)*
                                       ((MapMaskPtr)->yhigh-(MapMaskPtr)->ylow+1)*
                                       ((MapMaskPtr)->zhigh-(MapMaskPtr)->zlow+1));
        if(!mapmaskptr->mapdata) {
            _ffree(mapmaskptr);
            CommandError(MsgStrs[StrMalloc]);
            return 1;
        }
        mapmaskptr->elsize=MapMaskPtr->elsize;
        mapmaskptr->eltype=MapMaskPtr->eltype;
        mapmaskptr->maptype=MapMaskPtr->maptype;
        mapmaskptr->adiv=MapMaskPtr->adiv;
        mapmaskptr->bdiv=MapMaskPtr->bdiv;
        mapmaskptr->cdiv=MapMaskPtr->cdiv;
        mapmaskptr->xint=MapMaskPtr->xint;
        mapmaskptr->yint=MapMaskPtr->yint;
        mapmaskptr->zint=MapMaskPtr->zint;
        mapmaskptr->xorig=MapMaskPtr->xorig;
        mapmaskptr->yorig=MapMaskPtr->yorig;
        mapmaskptr->zorig=MapMaskPtr->zorig;
        mapmaskptr->xlow=MapMaskPtr->xlow;
        mapmaskptr->ylow=MapMaskPtr->ylow;
        mapmaskptr->zlow=MapMaskPtr->zlow;
        mapmaskptr->xhigh=MapMaskPtr->xhigh;
        mapmaskptr->yhigh=MapMaskPtr->yhigh;
        mapmaskptr->zhigh=MapMaskPtr->zhigh;
        mapmaskptr->mapdatamin=MapMaskPtr->mapdatamin;
        mapmaskptr->mapdatamax=MapMaskPtr->mapdatamax;
        mapmaskptr->mapdatamean=MapMaskPtr->mapdatamean;
        mapmaskptr->mapdataesd=MapMaskPtr->mapdataesd;
        for (i=0; i<9; i++) {
            mapmaskptr->mapm2r[i]=MapMaskPtr->mapm2r[i];
            mapmaskptr->mapr2m[i]=MapMaskPtr->mapr2m[i];
        }
        for (i=0; i<3; i++) {
            mapmaskptr->mapxlate[i]=MapMaskPtr->mapxlate[i];
        }
        memmove(mapmaskptr->mapdata,MapMaskPtr->mapdata,
                ((mapmaskptr)->xhigh-(mapmaskptr)->xlow+1)
                *((mapmaskptr)->yhigh-(mapmaskptr)->ylow+1)
                *((mapmaskptr)->zhigh-(mapmaskptr)->zlow+1)
                *((mapmaskptr)->elsize));
        mapinfo.MapMaskPtr = mapmaskptr;
    }
    if (MapMaskGenSel) {
        MapAtmSel *mapatmsel;
        vector_create((GenericVec __far **)&mapmaskgensel,sizeof(MapAtmSel),10);
        for (i = 0; i < MapMaskGenSel->size; i++) {
            vector_get_elementptr((GenericVec __far *)MapMaskGenSel,(void __far * __far *)&mapatmsel,i );
            vector_set_element((GenericVec __far *)mapmaskgensel,mapatmsel,i);
        }
        mapinfo.MapMaskGenSel = mapmaskgensel;
    }
    
    MapSpaceAdjust = 1.;
    

    do {
        mapallocfailed=
        generate_map(&mapinfo.MapPtr,mapinfo.MapSpacing*MapSpaceAdjust, mapinfo.MapSpacing*MapSpaceAdjust, mapinfo.MapSpacing*MapSpaceAdjust, 0L, 0L, 0L,
                     (Long)(250.*(1.+mapinfo.MapSpread)+mapinfo.MapSpacing), (mapinfo.MapSpread>0.)?1./mapinfo.MapSpread:0.,
                     (mapinfo.flag&MapScaleFlag)?1:0, SASflag);
        if (!mapallocfailed || MapSpaceAdjust >= 8) break;
        MapSpaceAdjust *= 2;
        sprintf(buffer," Trying coarser map spacing %g\n",((double)(mapinfo.MapSpacing*MapSpaceAdjust))/250.);
        WriteString(buffer);
    } while (True);
    
    if (mapallocfailed) {
        CommandError(MsgStrs[StrMalloc]);
        if (mapinfo.MapMaskGenSel) vector_free((GenericVec __far * __far *)&(mapinfo.MapMaskGenSel));
        if (mapinfo.MapMaskPtr) {
            _ffree((void __far *)(mapinfo.MapMaskPtr)->mapdata);
            _ffree((void __far *)mapinfo.MapMaskPtr);
        }
    }
        
    mapinfo.MapSpacing *= MapSpaceAdjust;
    vector_create((GenericVec __far **)&mapinfo.MapGenSel,sizeof(MapAtmSel),10);
    WriteMapAtoms(mapinfo.MapGenSel);
    
    
    if (mapinfo.flag&(MapPointFlag|MapMeshFlag|MapSurfFlag)) {
        vector_create((GenericVec __far **)&mapinfo.MapPointsPtr,sizeof(MapPoint),1000);
        if (mapinfo.flag&(MapMeshFlag))
            vector_create((GenericVec __far **)&mapinfo.MapBondsPtr,sizeof(MapBond),1000);
        if (mapinfo.flag&(MapSurfFlag))
            vector_create((GenericVec __far **)&mapinfo.MapTanglePtr,sizeof(MapTangle),1000);
        map_points(mapinfo.MapPtr, 
                   mapinfo.MapLevel+((mapinfo.flag&MapMeanFlag)?mapinfo.MapPtr->mapdatamean:0.), 
                   mapinfo.MapSpacing, mapinfo.MapPointsPtr,mapinfo.MapBondsPtr,mapinfo.MapTanglePtr,
                   mapinfo.MapMaskPtr, mapinfo.MapRGBCol );
        
        if (MapFlag&MapNoSelectFlag) {
            vector_add_element((GenericVec __far *)MapInfoPtr,(void __far *)&mapinfo);
        } else {
            if (MapFlag&MapSelectFlag) {
                vector_add_element((GenericVec __far *)MapInfoPtr,(void __far *)&mapinfo);
            } else {
                for (j=0; j < MapInfoPtr->size; j++) {
                    vector_get_elementptr((GenericVec __far *)MapInfoPtr,(void __far * __far *)&omapinfo,j );
                    if (omapinfo->flag&MapSelectFlag) {
                        DeleteMap(j, False);
                        vector_set_element((GenericVec __far *)MapInfoPtr,(void __far *)&mapinfo,j);
                        break;
                    }
                }
                
            }
            
        }
        
        MapReRadius();
        ReRadius();
        ReDrawFlag |= RFInitial|RFColour;
    }
    return 0;
}

int ExecuteAtomCommand(int heta) {
    Long atomno;
    double __far *pcoords;
    double coords[3];
    double __far *poffsetss;
    double offsets[3];
    
    
}

/* Execute a command given as
 {(<selection>){.}}command
 if a selection is provided, it applies only during
 execution of this command, except for the following
 commands, the prior selection is not restored:
 
 Select
 Restrict
 Script
 
 */


int ExecuteCommandOne( int * );

int ExecuteCommand( void )
{
    
    int xret;
    int restore;
    
    TokenPtr = CurLine;
    if( !FetchToken() )
    {   TokenPtr = NULL;
        return False;
    }
    
    restore = 1;
    
    if (CurToken == '(') {
        SaveAtomSelection();
        FetchToken();
        if( CurToken==AllTok )
        {   SelectZone(AllAtomFlag);
        } else if( CurToken==NoneTok )
        {   SelectZone(0x00);
        } else if( CurToken==ViewTok )
        {   SelectArea(False,True,1,1,XRange,YRange);
        } else if( CurToken=='<' )
        {	  ReadAtomSelection(True);
        } else if( CurToken=='>' )
        {	  ReadAtomSelection(False);
        } else if ( CurToken != ')')
        {   QueryExpr = ParseExpression(0);
            if( QueryExpr )
            {   if( CurToken == ')' )
            {   SelectZoneExpr(QueryExpr);
                FetchToken();
                xret=ExecuteCommandOne(&restore);
                if ( restore ) LoadAtomSelection();
                DeAllocateExpr(QueryExpr);
                return xret;
            } else CommandError(MsgStrs[ErrSyntax]);
                DeAllocateExpr(QueryExpr);
            }
        } else 
        {  CommandError(MsgStrs[ErrSyntax]);
            return False;      	
        }
        NeedAtomTree = 1;
        FetchToken();
        if( CurToken == ')' )  {
            FetchToken();
            xret=ExecuteCommandOne(&restore);
            if ( restore ) {
                LoadAtomSelection();
                NeedAtomTree = 1;
            }
            return xret;
        }else 
        {  CommandError(MsgStrs[ErrSyntax]);
            return False;      	
        }
        
    }
    else return ExecuteCommandOne(&restore);
}


int ExecuteCommandOne( int * restore )
{
    register char *param;
    register int option;
    register int i,done;
    register Long temp;
	int suboption;
    FILE *script;
    
    if( !CurToken ) {
        TokenPtr = NULL;
        return False;
    }
    
    if (CurToken=='.')  {
        if( !FetchToken() ) {
            TokenPtr = NULL;
            return False;
        }
    }
    
    *restore = 1;
    if (CurToken == SelectTok 
        || CurToken == RestrictTok
        || CurToken == ScriptTok) *restore = 0;
    
    switch( CurToken )
    {   case(AtomTok):       ExecuteAtomCommand(False);  break;
        case(AxesTok):       ExecuteAxesCommand();       break;
        case(BoundBoxTok):   ExecuteBoundBoxCommand();   break;
        case(BulgarianTok):  SwitchLang(Bulgarian);      break;
        case(CentreTok):     ExecuteCentreCommand();     break;
        case(ChineseTok):    SwitchLang(Chinese);        break;
        case(ClipboardTok):  ExecuteClipboardCommand();  break;
        case(ColourTok):     ExecuteColourCommand();     break;
        case(ConnectTok):    ExecuteConnectCommand();    break;
    	case(DeferTok):      ExecuteDeferCommand();      break;
        case(EnglishTok):    SwitchLang(English);        break;
    	case(ExecuteTok):    ExecuteExecuteCommand();    break;
        case(FrenchTok):     SwitchLang(French);         break;
    	case(GenerateTok):   ExecuteGenerateCommand(MapMeshFlag);
            break;
        case(HetAtomTok):    ExecuteAtomCommand(True);   break;
        case(ItalianTok):    SwitchLang(Italian);        break;
        case(JapaneseTok):   SwitchLang(Japanese);       break;
        case(LoadTok):       ExecuteLoadCommand();       break;
        case(WaitTok):       ExecutePauseCommand();      break;
        case(PickingTok):    ExecutePickingCommand();    break;
        case(PrintTok):      ExecutePrintCommand();      break;
    	case(RussianTok):    SwitchLang(Russian);        break;
        case(SendTok):       ExecuteSendCommand();       break;
        case(SetTok):        ExecuteSetCommand();        break;
        case(ShowTok):       ExecuteShowCommand();       break;
        case(SpanishTok):    SwitchLang(Spanish);        break;
        case(TitleTok):      ExecuteTitleCommand();      break;
        case(UnitCellTok):   ExecuteUnitCellCommand();   break;
            
        case(TimeTok):
            {   double prevtime;
                char buffer[40];
                prevtime = CommandTime;
                CommandTime = ((double)(clock()))/CLOCKS_PER_SEC;
                if (prevtime) {
                    sprintf(buffer," Time: %g, Delta Time: %g\n", CommandTime, CommandTime-prevtime);
                } else {
                    sprintf(buffer," Time: %g\n", CommandTime);
                }
                WriteString(buffer);
            }
            break;
            
        case(RefreshTok):    RefreshScreen();
                             ReDrawFlag = NextReDrawFlag; break;
            
        /* align <molnum> {kabsch|local} {none|angles|distance} {translate|centre}
             {structure|substructure selectionscripts} */
                             
        case(AlignTok):
            FetchToken();
            if (CurToken != NumberTok) {
                CommandError(MsgStrs[ErrBadArg]);
                break;
            }
            if (TokenValue < 1 || TokenValue > NumMolecules
                || TokenValue-1 == MoleculeIndex) {
                CommandError(MsgStrs[ErrBadArg]);
                break;
            }
        {
            double rmsd;
            CQRQuaternion q;
            CV3Vector trans;
            int seqrange;
            double mindist, maxdist;
            int kabsch_local;
            int none_ang_dist;
            int molnum;
            int xlatecen;
            int findsubstructure;
            char * scripts;
            
            molnum = TokenValue-1;
            seqrange = 5;
            mindist = 0.5;
            maxdist = 7.5;
            kabsch_local = 0;
            none_ang_dist = 0;
            xlatecen = 0;
            findsubstructure = 0;
            scripts = NULL;
            
            FetchToken();
            while (CurToken) {
                if( !Database ) {
                    CommandError(MsgStrs[ErrBadMolDB]);
                    break;
                }
                 if (CurToken==CentreTok || CurToken==TranslateTok) {
                    if (!xlatecen) {
              	  	  xlatecen = CurToken;
                    } else {
                      CommandError(MsgStrs[ErrBadArg]);
              	      break;
                    }
                 } else if (CurToken==KabschTok) {
                    if (!kabsch_local) {
              	  	  kabsch_local = ALIGN_KABSCH;
                    } else {
                      CommandError(MsgStrs[ErrBadArg]);
              	      break;
                    }
              	  } else if (CurToken==LocalTok){
              	    if (!kabsch_local) {
              	  	  kabsch_local = ALIGN_LOCAL;
                    } else {
                      CommandError(MsgStrs[ErrBadArg]);
              	      break;
                    }
              	  } else if (CurToken==NoneTok){
              	    if (!none_ang_dist) {
              	  	  none_ang_dist = ALIGN_NONE;
                    } else {
                      CommandError(MsgStrs[ErrBadArg]);
              	      break;
                    }
              	  } else if (CurToken==AngleTok){
              	    if (!none_ang_dist) {
              	  	  none_ang_dist = ALIGN_ANGLE;
                    } else {
                      CommandError(MsgStrs[ErrBadArg]);
              	      break;
                    }
              	  } else if (CurToken==DistanceTok){
              	    if (!none_ang_dist) {
              	  	  none_ang_dist = ALIGN_DISTANCE;
                    } else {
                      CommandError(MsgStrs[ErrBadArg]);
              	      break;
                    }
              	  } else if (CurToken==SubstructureTok){
                      if (!findsubstructure) {
                          findsubstructure = ALIGN_SUBSTRUCTURE;
                          if (!AllowWrite ) {
                              if( (FileDepth!=-1) && LineStack[FileDepth] )
                              {   CommandError(MsgStrs[ErrInScrpt]);
                                  break;
                              }
                          }
                          FetchToken();
                          if( !CurToken ) {
                              scripts = NULL;
                              break;
                          } else if( CurToken==StringTok ) {
                              ProcessFileName(TokenIdent);
                          } else ProcessFileName(TokenStart);
                          
                          scripts = DataFileName;
                          CurToken = 0;
                      } else {
                          CommandError(MsgStrs[ErrBadArg]);
                          break;
                      }
              	  } else if (CurToken==StructureTok){
                      if (!findsubstructure) {
                          findsubstructure = ALIGN_STRUCTURE;
                      } else {
                          CommandError(MsgStrs[ErrBadArg]);
                          break;
                      }
              	  } else if (CurToken=='+' || CurToken == AddTok)  {
              	    if (!none_ang_dist) {
              	      none_ang_dist = ALIGN_DISTANCE_SUM;
              	    } else if (none_ang_dist == ALIGN_ANGLE) {
              	      none_ang_dist = ALIGN_ANGLE_SUM;
              	    } else if (none_ang_dist == ALIGN_DISTANCE) {
              	      none_ang_dist = ALIGN_DISTANCE_SUM;
              	    } else {
                      CommandError(MsgStrs[ErrBadArg]);
              	      break;
                    }
              	  } else break;
                  FetchToken();
              }
              if (CurToken) break;
            if (!kabsch_local) kabsch_local = ALIGN_LOCAL;
            if (!none_ang_dist) none_ang_dist = ALIGN_DISTANCE;
            if (!findsubstructure) findsubstructure = ALIGN_STRUCTURE;
            if (xlatecen)  {
            	XlateCen = (xlatecen==TranslateTok)?True:False;
            }
            
            AlignToMolecule(TokenValue-1,&rmsd,&q, 
            &trans, seqrange, mindist, maxdist, 
            kabsch_local,none_ang_dist, XlateCen,
            findsubstructure, scripts);
            fprintf(stderr," rmsd %g\n",rmsd);
            ReDrawFlag |= RFInitial;
        }
         break;
            
        case(ZapTok):        FetchToken();
            if ( CurToken == MapTok )  {
                DeleteMaps(); break;	
            } else if (!CurToken) {
                ZapDatabase(); break;
            } else CommandError(MsgStrs[ErrBadArg]);
            break;
            
		case (ColourModeTok): /* gm */
            FetchToken();
            if (CurToken == TrueTok)
            {
                UseOldColorCode = 1;
                WriteString(MsgStrs[StrCCompOn]);
            }
            else if (CurToken == FalseTok)
            {
                UseOldColorCode = 0;
                WriteString(MsgStrs[StrCCompOff]);
            }
            else {
                if (!NoToggle) {
                    if (UseOldColorCode)
                    {
                        UseOldColorCode = 0;
                        WriteString(MsgStrs[StrCCompOff]);
                    }
                    else
                    {
                        UseOldColorCode = 1;
                        WriteString(MsgStrs[StrCCompOn]);
                    }
                }
                else
                {
                    CommandError(MsgStrs[ErrNoToggle]);
                }
            }
            break;
            
		case (NoToggleTok): /* gm */
            
            FetchToken();
            if (CurToken == TrueTok)
            {
                NoToggle = 1;
                WriteString(MsgStrs[StrNoTogOn]);
            }
            else if (CurToken == FalseTok)
            {
                NoToggle = 0;
                WriteString(MsgStrs[StrNoTogOff]);
            }
            else {
                NoToggle = 1;
                WriteString(MsgStrs[StrNoTogOn]);
            }
            break;
            
            
        case(BondTok):    FetchToken();
            if( CurToken == NumberTok )
            { temp = TokenValue;
                FetchToken();
                if( CurToken == ',' )
                    FetchToken();
                if( CurToken == NumberTok )
                {   Long temp2;
                    
                    temp2 = TokenValue;
                    FetchToken();
                    if ( (!CurToken) || CurToken == '+' ) {
                        CreateBondOrder(temp, temp2);
                        ReDrawFlag |= RFInitial;
                    } else if ( CurToken == PickingTok ) { 
                        CreateBondAxis(temp,TokenValue);
                        ReDrawFlag |= RFInitial;
                    } else CommandError(MsgStrs[ErrBadArg]);
                } else CommandError(MsgStrs[ErrNotNum]);
            } else if (CurToken==RotateTok)
            { FetchToken();
                if(BondSelected &&
                   (!CurToken || CurToken==TrueTok))
                { RotMode = RotBond;
                    ReDrawFlag |= RFRotBond;
                } else if(CurToken==FalseTok)
                { if( RotMode == RotBond )
                { RotMode = RotMol;
                    ReDrawFlag |= RFRotate;
                }
                } else CommandError(MsgStrs[ErrBadArg]);
            } else CommandError(MsgStrs[ErrBadArg]);
            break;
            
        case(UnBondTok):  FetchToken();
            if( CurToken == NumberTok )
            { temp = TokenValue;
                FetchToken();
                if( CurToken == ',' )
                    FetchToken();
                if( CurToken == NumberTok )
                {   if (RemoveBond(temp,TokenValue)) {
                    ReDrawFlag |= RFInitial;
                } else {
                    CommandError(MsgStrs[ErrBadArg]);
                }
                } else CommandError(MsgStrs[ErrNotNum]);
            } else if( (!CurToken) && BondSelected )
            { if (RemoveBond(BSrcAtom->serno,BDstAtom->serno)) {
                BSrcAtom = NULL; BDstAtom = NULL;
                ReDrawFlag |= RFRefresh;
                BondSelected = False;
            } else {
                CommandError(MsgStrs[ErrBadArg]);
            }
            } else CommandError(MsgStrs[ErrBadArg]);
            break;
            
        case(MoleculeTok):
            FetchToken();
            if (CurToken == NewTok ) {
                if (!SetNewMolecule()) {
                    CommandError(MsgStrs[ErrBadArg]);
                }
                break;
            }
            if (CurToken != NumberTok) {
                CommandError(MsgStrs[ErrBadArg]);
                break;
            }
            if (TokenValue < 1 || TokenValue > NumMolecules) {
                CommandError(MsgStrs[ErrBadArg]);
                break;
            }
            SelectMolecule(TokenValue-1);
            break;
            
        case(SelectTok):  FetchToken();
            if( !CurToken )
            {   option = NormAtomFlag;
                if( HetaGroups ) option |= HeteroFlag;
                if( Hydrogens )  option |= HydrogenFlag;
                SelectZone(option);
            } else if( CurToken==AllTok )
            {   SelectZone(AllAtomFlag);
            } else if( CurToken==NoneTok )
            {   SelectZone(0x00);
            } else if( CurToken==ViewTok )
            {   SelectArea(False,True,1,1,XRange,YRange);
            } else if( CurToken=='<' )
            {	  ReadAtomSelection(True);
            } else if( CurToken=='>' )
            {	  ReadAtomSelection(False);
            } else
            {   QueryExpr = ParseExpression(0);
                if( QueryExpr )
                {   if( !CurToken )
                {   SelectZoneExpr(QueryExpr);
                } else CommandError(MsgStrs[ErrSyntax]);
                    DeAllocateExpr(QueryExpr);
                }
            }
            NeedAtomTree = 1;
            break;
            
        case(RestrictTok):
            FetchToken();
            if( !CurToken )
            {   option = NormAtomFlag;
                if( HetaGroups ) option |= HeteroFlag;
                if( Hydrogens )  option |= HydrogenFlag;
                RestrictZone(option);
                ReDrawFlag |= RFRefresh;
            } else if( CurToken==AllTok )
            {   RestrictZone(AllAtomFlag);
                ReDrawFlag |= RFRefresh;
            } else if( CurToken==NoneTok )
            {   RestrictZone(0x00);
                ReDrawFlag |= RFRefresh;
            } else
            {   QueryExpr = ParseExpression(0);
                if( QueryExpr )
                {   if( !CurToken )
                {   RestrictZoneExpr(QueryExpr);
                    ReDrawFlag |= RFRefresh;
                } else CommandError(MsgStrs[ErrSyntax]);
                    DeAllocateExpr(QueryExpr);
                }
            } 
            NeedAtomTree = 1;
            break;
            
            
        case(MapTok):
            SelectMaps();
            if (CurToken) {
                switch (CurToken) {
                        int mapflags, j;
                        FILE *fp;
                        
                    case(DotsTok):
                        FetchToken();
                        if (CurToken==FalseTok) {
                            MapFlag &= ~MapPointFlag;
                        } else if( (CurToken==TrueTok) || !CurToken ) {
                            MapFlag &= ~(MapPointFlag|MapMeshDashFlag|MapSurfFlag);
                            MapFlag |= MapPointFlag;
                        } else if( CurToken==NumberTok && TokenValue >=0)
                        { if( *TokenPtr=='.' )
                        { TokenPtr++;
                            FetchFloat(TokenValue,250);
                        }
                            
                            if( TokenValue<=500 )
                            { if (TokenValue !=0) {
                                MapFlag &= ~(MapPointFlag|MapMeshDashFlag|MapSurfFlag);
                                MapFlag |= MapPointFlag;
                                MapPointRad = TokenValue;
                            } else {
                                MapFlag &= ~MapPointFlag;
                            }
                            } else { CommandError(MsgStrs[ErrBigNum]); break;}
                        } else if( CurToken=='.' ) {
                            FetchFloat(0,250);
                            if( TokenValue<=500 ) {
                                MapFlag &= ~(MapPointFlag|MapMeshDashFlag|MapSurfFlag);
                                MapFlag |= MapPointFlag;
                                MapPointRad = TokenValue;
                            } else { CommandError(MsgStrs[ErrBigNum]); break;}
                        } else if (!CurToken) {
                            MapFlag &= ~(MapPointFlag|MapMeshDashFlag|MapSurfFlag);
                            MapFlag |= MapPointFlag;
                            MapPointRad = 0;
                        } else { CommandError(MsgStrs[ErrBadArg]); break; }
                        ApplyMapSelection();
                        ApplyMapFlag();
                        ReDrawFlag |= RFRefresh;
                        break;
                        
                    case(WireframeTok):
                        FetchToken();
                        if (CurToken==FalseTok) {
                            MapFlag &= ~MapMeshDashFlag;
                        } else if( (CurToken==TrueTok) || !CurToken ) {
                            MapFlag &= ~(MapPointFlag|MapMeshDashFlag|MapSurfFlag);
                            MapFlag |= MapMeshFlag;
                        } else if( CurToken==DashTok )
                        { MapFlag &= ~(MapPointFlag|MapMeshDashFlag|MapSurfFlag);
                            MapFlag |= MapMeshDashFlag;
                        } else if( CurToken==NumberTok && TokenValue >=0)
                        { if( *TokenPtr=='.' )
                        { TokenPtr++;
                            FetchFloat(TokenValue,250);
                        }
                            
                            if( TokenValue<=500 )
                            { MapFlag &= ~(MapPointFlag|MapMeshDashFlag|MapSurfFlag);
                                MapFlag |= MapMeshFlag;
                                MapMeshRad = TokenValue;
                            } else { CommandError(MsgStrs[ErrBigNum]); break;}
                        } else if( CurToken=='.' ) {
                            FetchFloat(0,250);
                            if( TokenValue<=500 ) {
                                MapFlag &= ~(MapPointFlag|MapMeshDashFlag|MapSurfFlag);
                                MapFlag |= MapMeshFlag;
                                MapMeshRad = TokenValue;
                            } else { CommandError(MsgStrs[ErrBigNum]); break;}
                        } else if (!CurToken) {
                            MapFlag &= ~(MapPointFlag|MapMeshDashFlag|MapSurfFlag);
                            MapFlag |= MapMeshFlag;
                            MapMeshRad = 0;
                        } else { CommandError(MsgStrs[ErrBadArg]); break; }
                        ApplyMapSelection();
                        ApplyMapFlag();
                        ReDrawFlag |= RFRefresh;
                        break;
                        
                    case(SurfaceTok):
                        MapFlag &= ~(MapPointFlag|MapMeshFlag|MapSurfFlag);
                        MapFlag |= MapSurfFlag;
                        FetchToken();
                        if (CurToken)  CommandError(MsgStrs[ErrBadArg]);
                        else {
                            ApplyMapSelection();
                            ApplyMapFlag();
                        }
                        ReDrawFlag |= RFRefresh;
                        break;
                        
                    case(ScaleTok):
                        FetchToken();
                        if (CurToken == TrueTok || CurToken==ZTok || !CurToken) {
                            MapFlag |= MapScaleFlag;
                        } else if (CurToken == NoneTok || CurToken == FalseTok)  {
                            MapFlag &= ~MapScaleFlag;                              		
                        } else { CommandError(MsgStrs[ErrBadArg]);
                            break;
                        }
                        ApplyMapSelection();
                        ReDrawFlag |= RFRefresh;
                        break;
                        ApplyMapFlag();
                        
                        
                    case(GenerateTok):
                        mapflags = MapFlag;
                        FetchToken();
                        if (CurToken==MolSurfTok) {
                            mapflags |= MapLRSurfFlag;
                            FetchToken();
                        } 
                        if (CurToken==SASurfTok) {
                            mapflags |= MapSASurfFlag;
                            FetchToken();
                        }
                        if (CurToken==DotsTok) {
                            mapflags &= ~(MapPointFlag|MapMeshFlag|MapSurfFlag);
                            mapflags |= MapPointFlag;
                            FetchToken();
                        } else if (CurToken==WireframeTok) {
                            mapflags &= ~(MapPointFlag|MapMeshFlag|MapSurfFlag);
                            mapflags |= MapMeshFlag;
                            FetchToken();
                        } else if (CurToken==SurfaceTok) {
                            mapflags &= ~(MapPointFlag|MapMeshFlag|MapSurfFlag);
                            mapflags |= MapSurfFlag;
                            FetchToken();
                        }   else if (CurToken) { 
                            CommandError(MsgStrs[ErrBadArg]);
                            break;
                        }
                        if (!(mapflags &(MapPointFlag|MapMeshFlag|MapSurfFlag)))
                            mapflags |= MapPointFlag;
                        ExecuteGenerateCommand(mapflags);  
                        break;
                        
                    case(LoadTok):
                        FetchToken();
                        if( !Database ) { 
                            CommandError(MsgStrs[ErrBadMolDB]);
                            break;
                        }
                        
                        if( CurToken==StringTok ) {
                            ProcessFileName(TokenIdent);
                        } else ProcessFileName(TokenStart);
                        
                        if( !(fp=fopen(DataFileName,"rb")) ) {
                            CommandError( (char*)NULL );
                            WriteString(MsgStrs[StrDFile]);
                            WriteString(DataFileName);
                            WriteString("'!\n");
                            break;
                        } 
#ifdef USE_CBFLIB        
                        else {
                            int mapno=0;
                            MapInfo *omapinfo;
                            if (MapFlag&MapNoSelectFlag) mapno=-1;
                            else {
                                ApplyMapSelection();
                                if (MapFlag&MapSelectFlag) {
                                    mapno = -1;
                                } else {
                                    for (j=0; j < MapInfoPtr->size; j++) {
                                        vector_get_elementptr((GenericVec __far *)MapInfoPtr,(void __far * __far *)&omapinfo,j );
                                        if (omapinfo->flag&MapSelectFlag) {
                                            DeleteMap(j,False);
                                            mapno=j;
                                            break;
                                        }
                                    }
                                }
                            }
                            if(LoadCCP4MapFile(fp,(FileDepth == -1),mapno)) {
                                if( !(fp=fopen(DataFileName,"rb")) ) {
                                    CommandError( (char*)NULL );
                                    WriteString(MsgStrs[StrErrFile]);
                                    WriteString(DataFileName);
                                    WriteString("'!\n");
                                    break;
                                } else if (LoadCBFMapFile(fp,(FileDepth == -1),mapno)) {
                                    CommandError( (char*)NULL );
                                    WriteString(MsgStrs[StrErrFile]);
                                    WriteString(DataFileName);
                                    WriteString("'!\n");
                                    break;
                                }
                            }
                            CurToken = 0;
                            ReDrawFlag |= RFInitial|RFColour;
                        }
#else
                        CommandError(MsgStrs[ErrBadArg]);
#endif
                        break;
                        
                        
                    case(LevelTok):
                    {
                        int neg;
                        
                        FetchToken();
                        MapFlag &= ~MapMeanFlag;
                        MapLevel = 1.;
                        neg = False;
                        if ( CurToken==MeanTok) {
                            MapFlag |= MapMeanFlag;
                            FetchToken();
                            MapLevel = 0.;
                        }
                        if ( CurToken == '-' ) {
                            neg = True;
                            MapLevel *= -1.;
                            FetchToken();
                        }
                        if ( CurToken==NumberTok)
                        {   if( *TokenPtr=='.' )
                        {   TokenPtr++;
                            FetchFloat(TokenValue,1000);
                        }  else {
                            TokenValue *= 1000;
                        }
                            if( TokenValue<=50000 )
                            {   if (TokenValue > 0 || MapFlag&MapMeanFlag)  {
                                MapLevel = ((Real)TokenValue)/1000.; 
                                if (neg) MapLevel *= -1.;
                                ApplyMapSelection();
                                ApplyMapLevel();
                                ReDrawFlag |= RFRefresh;
                                break;
                            }  else CommandError(MsgStrs[ErrBigNum]);
                            } else CommandError(MsgStrs[ErrBigNum]);
                        } else if( CurToken=='.' ) {   FetchFloat(0,1000);
                            if( TokenValue<=50000 )
                            {   MapLevel = ((Real)TokenValue)/1000.;
                                if (neg) MapLevel *= -1.;
                                ApplyMapSelection();
                                ApplyMapLevel();
                                ReDrawFlag |= RFRefresh;
                                break;
                            } else CommandError(MsgStrs[ErrBigNum]);
                        } 
                        if (!CurToken && (MapFlag&MapMeanFlag)) {
                            ApplyMapSelection();
                            ApplyMapLevel();
                            break;
                        } else CommandError(MsgStrs[ErrBadArg]);
                        break;
                    }
                        
                     
                    case(SaveTok):
                    case(WriteTok):
                        if( !AllowWrite )
                            if( (FileDepth!=-1) && LineStack[FileDepth] )
                            {   CommandError(MsgStrs[ErrInScrpt]);
                                break;
                            }
                        FetchToken();
                        if( !Database ) { 
                            CommandError(MsgStrs[ErrBadMolDB]);
                            break;
                        }

                        
                        if( !CurToken ) {
                            CommandError(MsgStrs[ErrFilNam]);
                            break;
                        } else if( CurToken==StringTok ) {
                            ProcessFileName(TokenIdent);
                        } else ProcessFileName(TokenStart);
                        
                        param = DataFileName;
                        CurToken = 0;
                        
#ifdef USE_CBFLIB        
                        if( !(fp=fopen(DataFileName,"w+b")) ) {
                            CommandError( (char*)NULL );
                            FatalOutputError(DataFileName);
                            break;
                        } 
                        else {
                            MapInfo *omapinfo;
                            {
                                ApplyMapSelection();
                                if (MapFlag&MapSelectFlag) {
                                    CommandError(MsgStrs[ErrBadArg]);
                                    fclose(fp);
                                    break;
                                } else {
                                    for (j=0; j < MapInfoPtr->size; j++) {
                                        vector_get_elementptr((GenericVec __far *)MapInfoPtr,(void __far * __far *)&omapinfo,j );
                                        if (omapinfo->flag&MapSelectFlag) {
                                            if(SaveMapFile(fp,(FileDepth == -1),j))  {
                                                CommandError( (char*)NULL );
                                                WriteString(MsgStrs[StrErrFile]);
                                                WriteString(DataFileName);
                                                WriteString("'!\n");
                                                break;
                                            }
                                            break;
                                        }
                                    }
                                    fclose(fp);
                                }
                            }
                            CurToken = 0;
                        }
#else
                        CommandError(MsgStrs[ErrBadArg]);
#endif
                        break;
                        
                        
                    case(MaskTok):
                        FetchToken();
                        if (CurToken == SelectedTok) {
                            ApplyMapMask(0);
                        } else if (CurToken==NumberTok && TokenValue>0) {
                            ApplyMapMask(TokenValue);
                        } else if (CurToken==NoneTok) {
                            ApplyMapMask(-1);
                        }
                        else CommandError(MsgStrs[ErrBadArg]);
                        break;
                        
                    case(ResolutionTok):
                        FetchToken();
                        if ( CurToken==NumberTok && TokenValue >=0)
                        {   if( *TokenPtr=='.' )
                        {   TokenPtr++;
                            FetchFloat(TokenValue,1000);
                        } else {
                            TokenValue *= 1000;
                        }
                            if( TokenValue<=50000 )
                            {   if (TokenValue !=0)
                                MapSpacing = 250.*((Real)TokenValue)/1000.;
                                MapSpread = .6667*((Real)TokenValue)/1000.;
                                ApplyMapSelection();
                                ApplyMapSpacing();
                                ApplyMapSpread();
                                ReDrawFlag |= RFRefresh;
                            } else CommandError(MsgStrs[ErrBigNum]);
                        } else if( CurToken=='.' )
                        {   FetchFloat(0,1000);
                            if( TokenValue<=50000 )
                            {   MapSpacing = 250.*((Real)TokenValue)/1000.;
                                MapSpread = .6667*((Real)TokenValue)/1000.;
                                ApplyMapSelection();
                                ApplyMapSpacing();
                                ApplyMapSpread();
                                ReDrawFlag |= RFRefresh;
                            } else CommandError(MsgStrs[ErrBigNum]);
                        } else CommandError(MsgStrs[ErrBadArg]);
                        break;
                        
                        
                        
                    case(SpreadTok):
                        FetchToken();
                        if ( CurToken==NumberTok && TokenValue >=0)
                        {   if( *TokenPtr=='.' )
                        {   TokenPtr++;
                            FetchFloat(TokenValue,1000);
                        } else {
                            TokenValue *= 1000;
                        }
                            if( TokenValue<=50000 )
                            {   MapSpread = ((Real)TokenValue)/1000.;                          
                                ApplyMapSelection();
                                ApplyMapSpread();
                                ReDrawFlag |= RFRefresh;
                            } else CommandError(MsgStrs[ErrBigNum]);
                        } else if( CurToken=='.' )
                        {   FetchFloat(0,1000);
                            if( TokenValue<=50000 )
                            {   MapSpread = ((Real)TokenValue)/1000.;
                                ApplyMapSelection();
                                ApplyMapSpread();
                                ReDrawFlag |= RFRefresh;
                            } else CommandError(MsgStrs[ErrBigNum]);
                        } else CommandError(MsgStrs[ErrBadArg]);
                        break;
                        
                    case(SpacingTok):
                        FetchToken();
                        if ( CurToken==NumberTok && TokenValue >=0)
                        {   if( *TokenPtr=='.' )
                        {   TokenPtr++;
                            FetchFloat(TokenValue,250);
                        }
                            if( TokenValue<=50000 )
                            {   if (TokenValue !=0)
                                MapSpacing = TokenValue;                          
                                ApplyMapSelection();
                                ApplyMapSpacing();
                                ReDrawFlag |= RFRefresh;
                            } else CommandError(MsgStrs[ErrBigNum]);
                        } else if( CurToken=='.' )
                        {   FetchFloat(0,250);
                            if( TokenValue<=50000 )
                            {   MapSpacing = TokenValue;
                                ApplyMapSelection();
                                ApplyMapSpacing();
                                ReDrawFlag |= RFRefresh;
                            } else CommandError(MsgStrs[ErrBigNum]);
                        } else CommandError(MsgStrs[ErrBadArg]);
                        break;
                        
                    case(ColourTok):
                        FetchToken();
                        if( CurToken==PotentialTok )
                        {   ReDrawFlag |= RFColour;
                            MapFlag |= MapColourPot;
                            MapFlag &= ~MapColourAtom;
                        } else if( CurToken==AtomTok )
                        {   ReDrawFlag |= RFColour;
                            MapFlag |= MapColourAtom;
                            MapFlag &= ~MapColourPot;
                        } else if( ParseColour() )
                        {   ReDrawFlag |= RFColour;
                            MapRGBCol[0] = RVal;
                            MapRGBCol[1] = GVal;
                            MapRGBCol[2] = BVal;
                            MapFlag &= ~(MapColourPot|MapColourAtom);
                        } else if( CurToken )
                        {      CommandError(MsgStrs[ErrColour]);
                        } else CommandError(MsgStrs[ErrNoCol]);
                        ApplyMapSelection();
                        ApplyMapColour();
                        break;
                        
                    case(ZapTok):
                        FetchToken();
                        if (!CurToken) {
                            ApplyMapSelection();
                            ApplyMapZap();
                        }
                        else CommandError(MsgStrs[ErrSyntax]);
                        break;
                        
                    /*  map {<mapselection>} select
                        map {<mapselection>} select atom {SearchRadius} {+|add} {-|within}
                        map {<mapselection>} restrict atom {SearchRadius} {+|add} {-|within}
                     
                        The default SearchRadius is 6 Angstroms + probe radius
                        The default is to discard all current selections first
                           use '+' or 'add' to add to the current selections instead
                        The default is to search through all atoms
                           use '-' or 'within' to search through only currently selected atoms
                        It is an error to use both add and within
                     */
                    case(SelectTok):
                        FetchToken();
                        if (!CurToken) {
                            ApplyMapSelection();
                        } else if (CurToken == AtomTok){
                            int dontadd, searchwithin, SearchRadius;
                            SearchRadius = 1000+((ProbeRadius<10)?350:ProbeRadius);
                            dontadd = True;
                            searchwithin = False;
                            while (FetchToken()) {
                                if( CurToken==NumberTok ) {
                                    if( *TokenPtr=='.' ) {
                                        TokenPtr++;
                                        FetchFloat(TokenValue,250);
                                    }
                                    if( TokenValue>7500 ) {
                                        CommandError(MsgStrs[ErrBigNum]);
                                        break;
                                    } else SearchRadius = (int)TokenValue;
                                    continue;
                                } else if( CurToken=='.' ) {
                                    FetchFloat(0,250);
                                    if( TokenValue>7500 ){
                                        CommandError(MsgStrs[ErrBigNum]);
                                        break;
                                    } else SearchRadius = (int)TokenValue;
                                    continue;
                                } else if( CurToken == '+' || CurToken == AddTok ) {
                                    dontadd = False;
                                    continue;
                                } else if( CurToken == '-' || CurToken == WithinTok) {
                                    searchwithin = True;
                                    continue;
                                } else  {
                                    CommandError(MsgStrs[ErrSyntax]);
                                    break;
                                }
                            }
                            if (CurToken) {
                                break;
                            }
                            ApplyMapAtomSelection(dontadd,searchwithin,SearchRadius);
                        	SelectZone(SelectFlag);
                        	NeedAtomTree = 1;
                        	ReDrawFlag |= RFRefresh;
                        }
                        else CommandError(MsgStrs[ErrSyntax]);
                        break;
                        
                    case(RestrictTok):
                        FetchToken();
                        if (!CurToken) {
                            ApplyMapSelection();
                            ApplyMapRestriction();
                        } else if (CurToken == AtomTok){
                            int dontadd, searchwithin, SearchRadius;
                            SearchRadius = 1000+((ProbeRadius<10)?350:ProbeRadius);
                            dontadd = True;
                            searchwithin = False;
                            while (FetchToken()) {
                                if( CurToken==NumberTok ) {
                                    if( *TokenPtr=='.' ) {
                                        TokenPtr++;
                                        FetchFloat(TokenValue,250);
                                    }
                                    if( TokenValue>7500 ) {
                                        CommandError(MsgStrs[ErrBigNum]);
                                        break;
                                    } else SearchRadius = (int)TokenValue;
                                    continue;
                                } else if( CurToken=='.' ) {
                                    FetchFloat(0,250);
                                    if( TokenValue>7500 ){
                                        CommandError(MsgStrs[ErrBigNum]);
                                        break;
                                    } else SearchRadius = (int)TokenValue;
                                    continue;
                                } else if( CurToken == '+' || CurToken == AddTok) {
                                    dontadd = False;
                                    continue;
                                } else if( CurToken == '-' || CurToken == WithinTok) {
                                    searchwithin = True;
                                    continue;
                                } else  {
                                    CommandError(MsgStrs[ErrSyntax]);
                                    break;
                                }
                            }
                            if (CurToken) {
                                break;
                            }
                            ApplyMapAtomSelection(dontadd,searchwithin,SearchRadius);
                            RestrictZone(SelectFlag);
                            NeedAtomTree = 1;
                        	ReDrawFlag |= RFRefresh;
                       }
                        else CommandError(MsgStrs[ErrSyntax]);
                        break;
                        
                    case(ShowTok):
                        FetchToken();
                        if (!CurToken) {
                            ApplyMapSelection();
                            ApplyMapShow();
                        }
                        else CommandError(MsgStrs[ErrSyntax]);
                        break;
                        
                        
                    default:  CommandError(MsgStrs[ErrBadArg]); break;
                        
                }
            } else CommandError(MsgStrs[ErrSyntax]);
            break;
            
            
            
        case(WireframeTok):
            FetchToken();
            if( CurToken==FalseTok )
            {   ReDrawFlag |= RFRefresh;
                DisableWireframe();
            } else if( (CurToken==TrueTok) || !CurToken )
            {   ReDrawFlag |= RFRefresh;
                EnableWireframe(WireFlag,0,0);
            } else if( CurToken==DashTok )
            {   ReDrawFlag |= RFRefresh;
                EnableWireframe(DashFlag,0,0);
            } else if( CurToken==NumberTok && TokenValue >=0)
            {   if( *TokenPtr=='.' )
            {   TokenPtr++;
                FetchFloat(TokenValue,250);
            }
                
                if( TokenValue<=500 )
                {   if (TokenValue !=0)
                {   EnableWireframe(CylinderFlag,
                                    (int)TokenValue,
                                    (int)((TokenValue*4)/5));
                    ReDrawFlag |= RFRefresh;
                } else
                {
                    ReDrawFlag |= RFRefresh;
                    DisableWireframe();
                }
                } else CommandError(MsgStrs[ErrBigNum]);
            } else if( CurToken=='.' )
            {   FetchFloat(0,250);
                if( TokenValue<=500 )
                {   EnableWireframe(CylinderFlag,
                                    (int)TokenValue,
                                    (int)((TokenValue*4)/5));
                    ReDrawFlag |= RFRefresh;
                } else CommandError(MsgStrs[ErrBigNum]);
            } else CommandError(MsgStrs[ErrBadArg]);
            break;
            
        case(BackboneTok):
            FetchToken();
            if( CurToken==FalseTok )
            {   ReDrawFlag |= RFRefresh;
                DisableBackbone();
            } else if( (CurToken==TrueTok) || !CurToken )
            {   ReDrawFlag |= RFRefresh;
                EnableBackbone(WireFlag,0,0);
            } else if( CurToken==DashTok )
            {   ReDrawFlag |= RFRefresh;
                EnableBackbone(DashFlag,0,0);
            } else if( CurToken==NumberTok && TokenValue>=0)
            {   if( *TokenPtr=='.' )
            {   TokenPtr++;
                FetchFloat(TokenValue,250);
            }
                
                
                if( TokenValue<=500 )
                {   if (TokenValue!=0)                                                                 { EnableBackbone(CylinderFlag,
                                                                                                                        (int)TokenValue,
                                                                                                                        (int)((4*TokenValue)/5));
                ReDrawFlag |= RFRefresh;                                                             } else                                                                           {                                                                               ReDrawFlag |= RFRefresh;                                                        DisableBackbone();                                                              }                                                                     } else CommandError(MsgStrs[ErrBigNum]);
            } else if( CurToken=='.' )
            {   FetchFloat(0,250);
                if( TokenValue<=500 )
                {   EnableBackbone(CylinderFlag,
                                   (int)TokenValue,
                                   (int)((4*TokenValue)/5));
                    ReDrawFlag |= RFRefresh;
                } else CommandError(MsgStrs[ErrBigNum]);
            } else CommandError(MsgStrs[ErrBadArg]);
            break;
            
        case(CPKTok):
        case(SpacefillTok):
            FetchToken();
            if( CurToken==FalseTok )
            {   ReDrawFlag |= RFRefresh;
                DisableSpacefill();
            } else if( CurToken==NumberTok )
            {   if( *TokenPtr=='.' )
            {   TokenPtr++;
                FetchFloat(TokenValue,250);
            }
                
                if( TokenValue<=3000 )
                {   SetRadiusValue(MaxFun((int)TokenValue,1),
                                   SphereFlag);
                    DrawSurf = False;
                    ReDrawFlag |= RFRefresh;
                } else CommandError(MsgStrs[ErrBigNum]);
            } else if( CurToken=='.' )
            {   FetchFloat(0,250);
                if( TokenValue<=3000 )
                {   SetRadiusValue(MaxFun((int)TokenValue,1),
                                   SphereFlag);
                    DrawSurf = False;
                    ReDrawFlag |= RFRefresh;
                } else CommandError(MsgStrs[ErrBigNum]);
            } else if( CurToken==UserTok )
            {   UserMaskAttrib(MaskRadiusFlag);
                DrawSurf = False;
                ReDrawFlag |= RFRefresh;
            } else if( CurToken==TemperatureTok )
            {   ReDrawFlag |= RFRefresh;
                DrawSurf = False;
                SetRadiusTemperature( SphereFlag );
            } else if( CurToken==SolventTok )
            {   ReDrawFlag |= RFRefresh;
                SetVanWaalRadius( SphereFlag | ExpandFlag );
            } else if( (CurToken==TrueTok) || !CurToken )
            {   ReDrawFlag |= RFRefresh;
                DrawSurf = False;
                SetVanWaalRadius( SphereFlag );
            } else CommandError(MsgStrs[ErrBadArg]);
            break;
        case(SurfaceTok):
            FetchToken();
            if( CurToken == SolventTok) {
                FetchToken();
                if( CurToken == DotsTok ) {
                } else if( CurToken == SolidTok ) {
                } else if( CurToken == NumberTok )
                {   if( *TokenPtr=='.' )
                {   TokenPtr++;
                    FetchFloat(TokenValue,250);   
                }
                    if( TokenValue<=3000 )
                    {   ProbeRadius = (int)TokenValue;
                        DrawSurf = True;
                        ReDrawFlag |= RFRefresh;
                        SetVanWaalRadius( SphereFlag |  
                                         ExpandFlag );
                    } else CommandError(MsgStrs[ErrBigNum]);
                } else CommandError(MsgStrs[ErrBadArg]);
                
            } else if( CurToken == MoleculeTok) {   
                FetchToken();
                if( CurToken == DotsTok ) {
                } else if( CurToken == SolidTok ) {
                } else if( CurToken == NumberTok )
                {   if( *TokenPtr=='.' )   
                {   TokenPtr++;
                    FetchFloat(TokenValue,250);
                }
                    if( TokenValue<=3000 )
                    {   ProbeRadius = (int)TokenValue;
                        DrawSurf = True;
                        ReDrawFlag |= RFRefresh;
                        FetchToken();
                        if (!CurToken)
                            SetVanWaalRadius( SphereFlag | TouchFlag );
                        else if( CurToken==NumberTok ) {
                            if( *TokenPtr=='.' ) {
                                TokenPtr++; 
                                FetchFloat(TokenValue,250);
                            }
                            if( TokenValue<=3000 ) {
                                SetRadiusValue(MaxFun((int)TokenValue,1),
                                               SphereFlag | TouchFlag);
                            } else CommandError(MsgStrs[ErrBigNum]);
                        } else if( CurToken=='.' ) {
                            FetchFloat(0,250);
                            if( TokenValue<=3000 ) {
                                SetRadiusValue(MaxFun((int)TokenValue,1),
                                               SphereFlag | TouchFlag);
                            } else CommandError(MsgStrs[ErrBigNum]);
                        } else if( CurToken==UserTok ) {
                            UserMaskAttrib(MaskRadiusFlag);
                        } else if( CurToken==TemperatureTok ) {
                            ReDrawFlag |= RFRefresh;
                        } else CommandError(MsgStrs[ErrBadArg]);
                        /* if( MainAtomCount+HetaAtomCount > 255 ) */
                        CreateSurfaceBonds();
                    } else CommandError(MsgStrs[ErrBigNum]);
                } else CommandError(MsgStrs[ErrBadArg]);
            } else CommandError(MsgStrs[ErrBadArg]);
            break;
            
        case(MolSurfTok):
            FetchToken();
            if( CurToken==FalseTok )
            {   DrawSurf = False;
                ReDrawFlag |= RFRefresh;
                DisableSpacefill();
            } else if( CurToken==NumberTok )
            {   if( *TokenPtr=='.' )
            {   TokenPtr++;
                FetchFloat(TokenValue,250);
            }
                
                if( TokenValue<=1500 )
                {   SetRadiusValue(MaxFun((int)TokenValue,1),
                                   SphereFlag);
                    DrawSurf = True;
                    ReDrawFlag |= RFRefresh;
                } else CommandError(MsgStrs[ErrBigNum]);
            } else if( CurToken=='.' )
            {   FetchFloat(0,250);
                if( TokenValue<=1500 )
                {   SetRadiusValue(MaxFun((int)TokenValue,1),
                                   SphereFlag);
                    DrawSurf = True;
                    ReDrawFlag |= RFRefresh;
                } else CommandError(MsgStrs[ErrBigNum]);
            } else if( CurToken==UserTok )
            {   UserMaskAttrib(MaskRadiusFlag);
                DrawSurf = True;
                ReDrawFlag |= RFRefresh;
            } else if( CurToken==TemperatureTok )
            {   DrawSurf = True;
                ReDrawFlag |= RFRefresh;
                SetRadiusTemperature( SphereFlag );
            } else if( (CurToken==TrueTok) || !CurToken )
            {   DrawSurf = True;
                ReDrawFlag |= RFRefresh;
                SetVanWaalRadius( SphereFlag );
            } else CommandError(MsgStrs[ErrBadArg]);
            break;
            
        case(FieldTok):
            FetchToken();
            { Long Field[4];
              int neg;
              int fieldtowrite;
              fieldtowrite = False;
              while (CurToken) { 
                if( CurToken==FalseTok ) {
                  ReDrawFlag |= RFRefresh|RFRotate;
                  DisableField();
                } else if( CurToken=='[' ) {
              	  int ifound;
            	  FetchBracketedArray(Field,4, &ifound);
            	  if (ifound<3) {
            	    CommandError(MsgStrs[ErrBadArg]);
            	    break;
            	  }
#ifdef INVERT
                  Field[1] = -Field[1];
#endif
                  Field[2] = -Field[2];
                  if (ifound < 4) {
                    Field[3] = 0;
                  }
                  fieldtowrite = True;
                } else if (CurToken == AngleTok && fieldtowrite == True)  {
                  FetchToken();
                  neg=False;
                  if (CurToken == '-') {
			        FetchToken();
			        neg = True;
                  }
                  if( CurToken==NumberTok ) {
                    if( *TokenPtr=='.' ) {
                      TokenPtr++;
                      FetchFloat(TokenValue,1000);
                    } else {
                        TokenValue *= 1000;
                    }
                    if( TokenValue<=360000 ) {
                      Field[3] = TokenValue;
                    } else CommandError(MsgStrs[ErrBigNum]);
                  } else if( CurToken=='.' ) {
                    FetchFloat(0,1000);
                    if( TokenValue<=360000 ) {
                      Field[3] = TokenValue;
                    } else CommandError(MsgStrs[ErrBigNum]);
                  }
                  if (Field[3] > 180000) {
                    Field[3] = 360000 - Field[3];
                    neg = !neg;
                  }
                  if (neg) {
                     Field[0] = -Field[0];
                     Field[1] = -Field[1];
                     Field[2] = -Field[2];                     
                  }
                  Field[3] = -Field[3];
                  Field[3] = rint(PI*(double)Field[3]/180.);
                } else if( (CurToken==TrueTok) || !CurToken ) {
                  ReDrawFlag |= RFRefresh|RFRotate;
                  SetOneFieldValue(NULL,NULL,False);
                } else if (CurToken==RadiusTok) {
                  FetchToken();
                  if( CurToken==NumberTok ) {
                    if( *TokenPtr=='.' ) {
                      TokenPtr++;
                      FetchFloat(TokenValue,250);
                    }
                    if( TokenValue<=3000 ) {
                      SetRadiusValue(MaxFun((int)TokenValue,1),
                                   FieldFlag);
                      DrawField = True;
                      ReDrawFlag |= RFRefresh|RFRotate;
                    } else CommandError(MsgStrs[ErrBigNum]);
                  } else if( CurToken=='.' ) {
                    FetchFloat(0,250);
                    if( TokenValue<=3000 ) {
                      SetRadiusValue(MaxFun((int)TokenValue,1),
                                   FieldFlag);
                      DrawField = True;
                      ReDrawFlag |= RFRefresh|RFRotate;
                    } else CommandError(MsgStrs[ErrBigNum]);
                  }
                }else if (CurToken=='*' || CurToken == ScaleTok) {
                    FetchToken();
                    if( CurToken==NumberTok ) {
                        if( *TokenPtr=='.' ) {
                            TokenPtr++;
                            FetchFloat(TokenValue,1000);
                            ScaleFieldValue(TokenValue);
                            DrawField = True;
                            ReDrawFlag |= RFRefresh|RFRotate;
                            FetchToken();
                            continue;
                        }
                        if( TokenValue<=3000000 ) {
                            ScaleFieldValue(TokenValue*1000);
                            DrawField = True;
                            ReDrawFlag |= RFRefresh|RFRotate;
                        } else CommandError(MsgStrs[ErrBigNum]);
                    } else if( CurToken=='.' ) {
                        FetchFloat(0,1000);
                        if( TokenValue<=3000000 ) {
                            ScaleFieldValue(TokenValue);
                            DrawField = True;
                            ReDrawFlag |= RFRefresh|RFRotate;
                        } else CommandError(MsgStrs[ErrBigNum]);
                    }
                } else  {
            	  CommandError(MsgStrs[ErrBadArg]);
            	  break;
                }
                FetchToken();
              }
              if (fieldtowrite) {
                SetFieldValue(Field);
                ReDrawFlag |= RFRefresh|RFRotate;
              }
              RefreshScreen();
            }
            break;

        case(StarTok):
            FetchToken();
            if( CurToken==FalseTok )
            {   ReDrawFlag |= RFRefresh;
                DisableSpacefill();
            } else if( CurToken==NumberTok )
            {   if( *TokenPtr=='.' )
            {   TokenPtr++;
                FetchFloat(TokenValue,250);
            }
                if( TokenValue<=750 )
                {   SetRadiusValue(MaxFun((int)TokenValue,1),
                                   StarFlag);
                    ReDrawFlag |= RFRefresh;
                } else CommandError(MsgStrs[ErrBigNum]);
            } else if( CurToken=='.' )
            {   FetchFloat(0,250);
                if( TokenValue<=750 )
                {   SetRadiusValue(MaxFun((int)TokenValue,1),
                                   StarFlag);
                    ReDrawFlag |= RFRefresh;
                } else CommandError(MsgStrs[ErrBigNum]);
            } else if( CurToken==UserTok )
            {   UserMaskAttrib(MaskRadiusFlag);
                ReDrawFlag |= RFRefresh;
            } else if( CurToken==TemperatureTok )
            {   ReDrawFlag |= RFRefresh;
                SetRadiusTemperature( StarFlag );
            } else if( (CurToken==TrueTok) || !CurToken )
            {   ReDrawFlag |= RFRefresh;
                SetVanWaalRadius( StarFlag );
            } else CommandError(MsgStrs[ErrBadArg]);
            break;
            
        case(DashTok):    FetchToken();
            if( CurToken==FalseTok )
            {   ReDrawFlag |= RFRefresh;
                DisableWireframe();
            } else if( (CurToken==TrueTok) || !CurToken )
            {   ReDrawFlag |= RFRefresh;
                EnableWireframe(DashFlag,0,0);
            } else CommandError(MsgStrs[ErrBadArg]);
            break;
            
        case(SSBondTok):  FetchToken();
            if( CurToken==NumberTok )
            {   if( *TokenPtr=='.' )
            {   TokenPtr++;
                FetchFloat(TokenValue,250);
            }
                
                if( TokenValue<=500 )
                {   SetHBondStatus(False,True,(int)TokenValue,
                                   (int)((4*TokenValue)/5));
                    ReDrawFlag |= RFRefresh;
                } else CommandError(MsgStrs[ErrBigNum]);
            } else if( CurToken=='.' )
            {   FetchFloat(0,250);
                if( TokenValue<=500 )
                {   SetHBondStatus(False,True,(int)TokenValue,
                                   (int)((4*TokenValue)/5));
                    ReDrawFlag |= RFRefresh;
                } else CommandError(MsgStrs[ErrBigNum]);
            } else if( CurToken==FalseTok )
            {   ReDrawFlag |= RFRefresh;
                SetHBondStatus(False,False,0,0);
            } else if( (CurToken==TrueTok) || !CurToken )
            {   ReDrawFlag |= RFRefresh;
                SetHBondStatus(False,True,0,0);
            } else CommandError(MsgStrs[ErrBadArg]);
            break;
            
        case(HBondTok):   FetchToken();
            if( CurToken==NumberTok )
            {   if( *TokenPtr=='.' )
            {   TokenPtr++;
                FetchFloat(TokenValue,250);
            }
                
                if( TokenValue<=500 )
                {   SetHBondStatus(True,True,(int)TokenValue,
                                   (int)((4*TokenValue)/5));
                    ReDrawFlag |= RFRefresh;
                } else CommandError(MsgStrs[ErrBigNum]);
            } else if( CurToken=='.' )
            {   FetchFloat(0,250);
                if( TokenValue<=500 )
                {   SetHBondStatus(True,True,(int)TokenValue,
                                   (int)((4*TokenValue)/5));
                    ReDrawFlag |= RFRefresh;
                } else CommandError(MsgStrs[ErrBigNum]);
            } else if( CurToken==FalseTok )
            {   ReDrawFlag |= RFRefresh;
                SetHBondStatus(True,False,0,0);
            } else if( (CurToken==TrueTok) || !CurToken )
            {   ReDrawFlag |= RFRefresh;
                SetHBondStatus(True,True,0,0);
            } else CommandError(MsgStrs[ErrBadArg]);
            break;
            
        case(RibbonTok):  FetchToken();
            if( CurToken==NumberTok && TokenValue>=0)
            {   if( *TokenPtr=='.' )
            {   TokenPtr++;
                FetchFloat(TokenValue,250);
            }
                
                if( TokenValue<=1000 )
                {  if (TokenValue !=0)
                {SetRibbonStatus(True,RibbonFlag,
                                 (int)TokenValue);
                    ReDrawFlag |= RFRefresh;
                } else { ReDrawFlag |= RFRefresh; 
                    SetRibbonStatus(False, RibbonFlag,0);
                }
                } else CommandError(MsgStrs[ErrBigNum]);
            } else if( CurToken=='.' )
            {   FetchFloat(0,250);
                if( TokenValue<=1000 )
                {   SetRibbonStatus(True,RibbonFlag,
                                    (int)TokenValue);
                    ReDrawFlag |= RFRefresh;
                } else CommandError(MsgStrs[ErrBigNum]);
            } else if( CurToken==FalseTok )
            {   ReDrawFlag |= RFRefresh;
                SetRibbonStatus(False,RibbonFlag,0);
            } else if( (CurToken==TrueTok) || !CurToken )
            {   ReDrawFlag |= RFRefresh;
                SetRibbonStatus(True,RibbonFlag,0);
            } else CommandError(MsgStrs[ErrBadArg]);
            break;
            
        case(StrandsTok): FetchToken();
            if( CurToken == DashTok )
            {   option = DashStrandFlag;
                FetchToken();
            } else option = StrandFlag;
            
            if( CurToken==NumberTok && TokenValue>=0)
            {   if( *TokenPtr=='.' )
            {   TokenPtr++;
                FetchFloat(TokenValue,250);
            }
                
                if( TokenValue<=1000 )
                { if (TokenValue !=0)
                {   SetRibbonStatus(True,option,(int)TokenValue);
                    ReDrawFlag |= RFRefresh;
                } else {
                    ReDrawFlag |= RFRefresh;
                    SetRibbonStatus (False,option,0);
                }
                } else CommandError(MsgStrs[ErrBigNum]);
            } else if( CurToken=='.' )
            {   FetchFloat(0,250);
                if( TokenValue<=1000 )
                {   SetRibbonStatus(True,option,(int)TokenValue);
                    ReDrawFlag |= RFRefresh;
                } else CommandError(MsgStrs[ErrBigNum]);
            } else if( CurToken==FalseTok )
            {   ReDrawFlag |= RFRefresh;
                SetRibbonStatus(False,option,0);
            } else if( (CurToken==TrueTok) || !CurToken )
            {   ReDrawFlag |= RFRefresh;
                SetRibbonStatus(True,option,0);
            } else CommandError(MsgStrs[ErrBadArg]);
            break;
            
        case(TraceTok):   FetchToken();
            if( CurToken==FalseTok )
            {   ReDrawFlag |= RFRefresh;
                SetRibbonStatus(False,TraceFlag,80);
            } else if( (CurToken==TrueTok) || !CurToken )
            {   ReDrawFlag |= RFRefresh;
                SetRibbonStatus(True,TraceFlag,80);
            } else if( CurToken==TemperatureTok )
            {   ReDrawFlag |= RFRefresh;
                SetTraceTemperature();
            } else if( CurToken==DotsTok )
            {   ReDrawFlag |= RFRefresh;
                SetRibbonStatus(True,DotsFlag,80);
            } else if( CurToken==NumberTok && TokenValue>=0)
            {   if( *TokenPtr=='.' )
            {   TokenPtr++;
                FetchFloat(TokenValue,250);
            }
                
                if( TokenValue<=500)
                {   if (TokenValue !=0) 
                {   SetRibbonStatus(True,TraceFlag,
                                    (int)TokenValue);
                    ReDrawFlag |= RFRefresh;
                } else 
                {
                    ReDrawFlag |= RFRefresh;
                    SetRibbonStatus(False,TraceFlag,80);
                }			      
                } else CommandError(MsgStrs[ErrBigNum]);
            } else if( CurToken=='.' )
            {   FetchFloat(0,250);
                if( TokenValue<=500 )
                {   SetRibbonStatus(True,TraceFlag,
                                    (int)TokenValue);
                    ReDrawFlag |= RFRefresh;
                } else CommandError(MsgStrs[ErrBigNum]);
            } else CommandError(MsgStrs[ErrBadArg]);
            break;
            
        case(CartoonTok): FetchToken();
            if( CurToken==NumberTok && TokenValue>=0)
            {   if( *TokenPtr=='.' )
            {   TokenPtr++;
                FetchFloat(TokenValue,250);
            }
                
                if( TokenValue<=1000 )
                {  if (TokenValue !=0)
                {   SetRibbonStatus(True,CartoonFlag,
                                    (int)TokenValue);
                    ReDrawFlag |= RFRefresh;
                } else 
                {
                    ReDrawFlag |= RFRefresh;
                    SetRibbonStatus(False,CartoonFlag,0);
                }  
                } else CommandError(MsgStrs[ErrBigNum]);
            } else if( CurToken=='.' )
            {   FetchFloat(0,250);
                if( TokenValue<=1000 )
                {   SetRibbonStatus(True,CartoonFlag,
                                    (int)TokenValue);
                    ReDrawFlag |= RFRefresh;
                } else CommandError(MsgStrs[ErrBigNum]);
            } else if( CurToken==FalseTok )
            {   ReDrawFlag |= RFRefresh;
                SetRibbonStatus(False,CartoonFlag,0);
            } else if( (CurToken==TrueTok) || !CurToken )
            {   ReDrawFlag |= RFRefresh;
                SetRibbonStatus(True,CartoonFlag,0);
            } else CommandError(MsgStrs[ErrBadArg]);
            break;
            
        case(DotsTok):    FetchToken();
            if( CurToken==NumberTok )
            {   if( TokenValue<=1000 )
            {   if( TokenValue )
            {   CalculateSurface((int)TokenValue);
            } else CalculateSurface(1);
                ReDrawFlag |= RFRefresh;
            } else CommandError(MsgStrs[ErrBigNum]);
            } else if( CurToken==FalseTok )
            {   ReDrawFlag |= RFRefresh;
                DeleteSurface();
                DotCount = 0;
            } else if( (CurToken==TrueTok) || !CurToken )
            {   ReDrawFlag |= RFRefresh;
                CalculateSurface(100);
            } else CommandError(MsgStrs[ErrBadArg]);
            break;
            
        case(MonitorTok): FetchToken();
            if( CurToken == NumberTok )
            {   temp = TokenValue;
                FetchToken();
                if( CurToken == ',' )
                    FetchToken();
                
                if( CurToken == NumberTok )
                {   CreateMonitor(temp,TokenValue);
                    ReDrawFlag |= RFRefresh;
                } else CommandError(MsgStrs[ErrNotNum]);
            } else if( CurToken == FalseTok )
            {   ReDrawFlag |= RFRefresh;
                DeleteMonitors();
            } else if( !CurToken || CurToken == TrueTok )
            {   ReDrawFlag |= RFRefresh;
                DrawMonitDistance = True;
            }else CommandError(MsgStrs[ErrBadArg]);
            break;
            
        case(SlabTok):    FetchToken();
            if( (CurToken==NumberTok) || (CurToken=='.') )
            {   if( CurToken==NumberTok )
            {   if( *TokenPtr=='.' )
            {   TokenPtr++;
                FetchFloat(TokenValue,100);
            } else TokenValue *= 100;
            } else FetchFloat(0,100);
                
                if( TokenValue<=10000 )
                {   DialValue[DialSlab] = (TokenValue-5000)/5000.0;
                    /* UpdateScrollBars(); */
                    ReDrawFlag |= RFSlab;
                    UseSlabPlane = True;
                    UseShadow = False;
                } else CommandError(MsgStrs[ErrBigNum]);
                
            } else if( CurToken==FalseTok )
            {   if( UseSlabPlane )
            {   ReDrawFlag |= RFRefresh;
                UseSlabPlane = False;
            }
            } else if( !CurToken || (CurToken==TrueTok) )
            {   if( !UseSlabPlane )
            {   ReDrawFlag |= RFRefresh;
                UseSlabPlane = True;
                UseShadow = False;
            }
            } else CommandError(MsgStrs[ErrSyntax]);
            break;
            
        case(DepthTok):    FetchToken();
            if( (CurToken==NumberTok) || (CurToken=='.') )
            {   if( CurToken==NumberTok )
            {   if( *TokenPtr=='.' )
            {   TokenPtr++;
                FetchFloat(TokenValue,100);
            } else TokenValue *= 100;
            } else FetchFloat(0,100);
                
                if( TokenValue<=10000 )
                {   DialValue[DialBClip] = (TokenValue-5000)/5000.0;
                    /* UpdateScrollBars(); */
                    ReDrawFlag |= RFRotate;
                    UseDepthPlane = True;
                    UseShadow = False;
                } else CommandError(MsgStrs[ErrBigNum]);
                
            } else if( CurToken==FalseTok )
            {   if( UseDepthPlane )
            {   ReDrawFlag |= RFRotate;
                UseDepthPlane = False;
            }
            } else if( !CurToken || (CurToken==TrueTok) )
            {   if( !UseSlabPlane )
            {   ReDrawFlag |= RFRotate;
                UseDepthPlane = True;
                UseShadow = False;
            }
            } else CommandError(MsgStrs[ErrSyntax]);
            break;
            
        case(ZoomTok):    FetchToken();
            if( (CurToken==NumberTok) || (CurToken=='.') )
            {   if( CurToken==NumberTok )
            {   if( *TokenPtr=='.' )
            {   TokenPtr++;
                FetchFloat(TokenValue,100);
            } else TokenValue *= 100;
            } else FetchFloat(0,100);
                
                if( TokenValue<=10000 )
                {   DialValue[DialZoom] = (TokenValue-10000)/10000.0;
                    ReDrawFlag |= RFZoom;
                } else if( Database )
                {   /* Magnification */
                    TokenValue -= 10000;
                    temp = (Long)(MaxZoom*10000);
                    if( TokenValue<=temp )
                    {   DialValue[DialZoom] = (Real)TokenValue/temp;
                        ReDrawFlag |= RFZoom;
                    } else CommandError(MsgStrs[ErrBigNum]);
                }
            } else if( CurToken==TrueTok )
            {   ReDrawFlag |= RFZoom;
                DialValue[DialZoom] = 0.5;
            } else if( !CurToken || (CurToken==FalseTok) )
            {   ReDrawFlag |= RFZoom;
                DialValue[DialZoom] = 0.0;
            } else CommandError(MsgStrs[ErrSyntax]);
            /* UpdateScrollBars(); */
            break;
            
        case(RotateTok):  FetchToken();
            if( CurToken==XTok )
            {   option = 0;
            } else if( CurToken==YTok )
            {   option = 1;
            } else if( CurToken==ZTok )
            {   option = 2;
            } else if( CurToken==BondTok )
            {   if (!BondSelected) {
                CommandError(MsgStrs[ErrNoBond]);
                break;
            } else {
                option = -1;
            }
            } else if( CurToken==AllTok )
            {   option = -3;
            } else if( CurToken==MoleculeTok )
            {   option = -2;
            } else
            {   CommandError(MsgStrs[ErrSyntax]);
                break;
            }
            
            FetchToken();
            if( option < 0 && 
               (!CurToken || CurToken==FalseTok || 
                CurToken==TrueTok))
            { if( (option == -1 && 
                   CurToken==FalseTok && RotMode==RotBond) ||
                 (option == -2 && 
                  (!CurToken || CurToken==TrueTok)) ||
                 (option == -3 && 
                  CurToken==FalseTok && RotMode==RotAll) )
            { RotMode = RotMol;
                ReDrawFlag |= RFRotate;
            }
                if( option == -1 && CurToken==TrueTok )
                { RotMode = RotBond;
                    ReDrawFlag |= RFRotBond;
                }
                if( option == -3 &&
                   (!CurToken || CurToken==TrueTok))
                { RotMode = RotAll;
                    ReDrawFlag |= RFRotate;
                }
                break;
            } else if( CurToken == '-' )
            {   FetchToken();
                done = True;
            } else done = False;
#ifdef INVERT
            if( option != 1 )
                done = !done;
#endif
            if( (CurToken==NumberTok) || (CurToken=='.') )
            {   if( CurToken==NumberTok )
            {   if( *TokenPtr=='.' )
            {   TokenPtr++;
                FetchFloat(TokenValue,100);
            } else TokenValue *= 100;
            } else FetchFloat(0,100);
                
                if( TokenValue )
                {   if( ReDrawFlag & RFRotate )
                    PrepareTransform();
                    if( done ) TokenValue = -TokenValue;
                    if (option == -1) {
                        ReDrawFlag |= RFRotBond;
                        BondSelected->BRotValue += 
                        TokenValue/18000.0;
                        while( BondSelected->BRotValue < -1.0 )
                            BondSelected->BRotValue += 2.0;
                        while( BondSelected->BRotValue > 1.0 )
                            BondSelected->BRotValue -= 2.0;
                    } else {
                        double xtemp;
                        
                        if (option < 0) {
                            CommandError(MsgStrs[ErrSyntax]);
                            break;                                 	
                        }
                        if (RotMode == RotAll) {
                            xtemp = WorldDialValue[option];
                        } else {
                            xtemp = DialValue[option];
                        }
                        
                        ReDrawFlag |= (1<<option);
                        
                        xtemp += TokenValue/18000.0;
                        
                        while( xtemp<-1.0 )
                            xtemp += 2.0;
                        while( xtemp>1.0 )
                            xtemp -= 2.0;
                        
                        if (RotMode == RotAll) {
                            WorldDialValue[option] = xtemp;
                        } else {
                            DialValue[option] = xtemp;
                        }
                    }
                    if( Interactive )
                        UpdateScrollBars();
                    ReDrawFlag |= RFRefresh;
                }
            } else if (CurToken == ResetTok) {
                if (option == -1) {
                    BondSelected->BRotValue = 0.0;
                    ReDrawFlag |=RFRotBond;
                } else {
                    ReDrawFlag |= (1<<option);
                    if (RotMode == RotAll) {
                        WorldDialValue[option] = 0.0;
                    } else {
                        DialValue[option] = 0.0;
                    }
                }
                if( Interactive )
                    UpdateScrollBars();
                ReDrawFlag |= RFRefresh;  
            } else CommandError(MsgStrs[ErrNotNum]);
            break;
            
        case(TranslateTok):
            FetchToken();
            if( CurToken==XTok )
            {   option = 4;
            } else if( CurToken==YTok )
            {   option = 5;
            } else if( CurToken==ZTok )
            {   option = 6;
            } else
            {   CommandError(MsgStrs[ErrSyntax]);
                break;
            }
            
            FetchToken();
            if( CurToken == '-' )
            {   FetchToken();
                done = True;
            } else done = False;
#ifdef INVERT
            if( option == 5 )
                done = !done;
#endif
            
            if( (CurToken==NumberTok) || (CurToken=='.') )
            {   if( CurToken==NumberTok )
            {   if( *TokenPtr=='.' )
            {   TokenPtr++;
                FetchFloat(TokenValue,100);
            } else TokenValue *= 100;
            } else FetchFloat(0,100);
                
                if( TokenValue<=10000 )
                {   double wtemp;
                    
                    ReDrawFlag |= RFTrans;
                    if( done ) TokenValue = -TokenValue;
                    wtemp = TokenValue/10000.0;
                    if( RotMode == RotAll && option == 4 ) {
                        WorldDialValue[DialTX] = wtemp;
                    } else { 
                        if( RotMode == RotAll && option == 5 ) {
                            WorldDialValue[DialTY] = wtemp;
                        } else {
                            if( RotMode == RotAll && option == 6 ) {
                                WorldDialValue[DialTZ] = wtemp;
                            } else {
                                DialValue[option] = TokenValue/10000.0;
                            }
                        }
                    }
                    
                    /* UpdateScrollBars(); */
                } else CommandError(MsgStrs[ErrBigNum]);
            } else CommandError(MsgStrs[ErrNotNum]);
            break;
            
        case(StereoTok):  FetchToken();
            if( !CurToken || (CurToken==TrueTok) )
            {   SetStereoMode(True);
            } else if( CurToken==FalseTok )
            {   SetStereoMode(False);
            } else if( CurToken == '-' )
            {   if( !NextIf(NumberTok,ErrNotNum) )
            {   StereoAngle = -TokenValue;
                SetStereoMode(True);
            }
            } else if( CurToken==NumberTok )
            {   StereoAngle = TokenValue;
                SetStereoMode(True);
            } else {
                CommandError(MsgStrs[ErrSyntax]);
                break;
            }
            if (StereoAngle > 60.) {
                StereoAngle = 6.;
                CommandError(MsgStrs[ErrBigNum]);
                break;            	
            }
            if (StereoAngle < -60.) {
                StereoAngle = -6.;
                CommandError(MsgStrs[ErrBigNum]);
                break;            	
            }
            break;
            
        case(ResizeTok):  FetchToken();
            break;
            
        case(ResetTok):
            for( i=0; i<10; i++ ) DialValue[i] = 0.0;
            ReDrawFlag |= RFDials;
            ResetTransform();
            
            /* ReDrawFlag |= RFRefresh|RFColour; */
            /* DisplayMode = 0;                  */
            
            if( Interactive )
                UpdateScrollBars();
            break;
            
        case('?'):
        case(HelpTok):    if( !HelpFileName )
            InitHelpFile();
            if( HelpInfo )
                FindHelpInfo();
            CurToken=0;
            break;
            
        case(LabelTok):   FetchToken();
            if( !CurToken || (CurToken==TrueTok) )
            {   if( Info.chaincount>1 )
            {   DefineLabels("%n%r:%c.%a%A");
            } else if( MainGroupCount>1 )
            {   DefineLabels("%n%r.%a%A");
            } else DefineLabels("%e%i%A");
            } else if( CurToken==FalseTok )
            {   DeleteLabels();
            } else if( CurToken!=StringTok )
            {   DefineLabels(TokenStart);
                CurToken = 0;
            } else DefineLabels(TokenIdent);
            ReDrawFlag |= RFRefresh;
            break;
            
        case(EchoTok):    FetchToken();
            InvalidateCmndLine();
            if( CurToken==StringTok )
            {   WriteString(TokenIdent);
            } else if( CurToken )
                WriteString(TokenStart);
            WriteChar('\n');
            CurToken = 0;
            break;
            
        case(DefineTok):  FetchToken();
            if( CurToken != IdentTok ) 
            {   CommandError(MsgStrs[ErrSetName]);
                break;
            }
            
            param = (char*)malloc(TokenLength+1);
            if( param )
            {   memcpy(param,TokenIdent,TokenLength+1);
                if( FetchToken() )
                {   QueryExpr = ParseExpression(0);
                    if( QueryExpr )
                    {   done = DefineSetExpr(param,QueryExpr);
                    } else done = True;
                } else done = DefineSetExpr(param,(Expr*)NULL);
            } else done = False;
            
            if( !done )
                CommandError(MsgStrs[ErrBadSet]);
            break;
            
        case(BackgroundTok):
            FetchToken();
            if( CurToken == TransparentTok )
            {   UseTransparent = True;
            } else if( CurToken == NormalTok )
            {   UseTransparent = False;
            } else if( ParseColour() )
            {   ReDrawFlag |= RFColour;
                BackR = RVal;
                BackG = GVal;
                BackB = BVal;
#ifndef IBMPC
                FBClear = False;
#endif
            } else if( CurToken )
            {      CommandError(MsgStrs[ErrColour]);
            } else CommandError(MsgStrs[ErrNoCol]);
            break;

        case(PlayTok):
        {
            int newPlayFrom, newPlayUntil;
            
            newPlayFrom = PlayFrom;
            newPlayUntil = PlayUntil;
            if (PlayTemplate[0]==0){
                newPlayFrom = 0;
                newPlayUntil = -1;
            }
            FetchToken();
            do {
                if (CurToken == FromTok) {
                    FetchToken();
                    if( (CurToken==NumberTok) || (CurToken=='.') ) {   
                        if( CurToken==NumberTok ) {
                            if( *TokenPtr=='.' ) {   
                                TokenPtr++;
                                FetchFloat(TokenValue,1000);
                            } else TokenValue *= 1000;
                        } else FetchFloat(0,1000);
                        newPlayFrom = (double)TokenValue;
                        PlayFrom = newPlayFrom;
                    } else {
                        CommandError(MsgStrs[ErrSyntax]);
                        break;
                    }
                } else if (CurToken == UntilTok) {
                    FetchToken();
                    if( (CurToken==NumberTok) || (CurToken=='.') ) {   
                        if( CurToken==NumberTok ) {
                            if( *TokenPtr=='.' ) {   
                                TokenPtr++;
                                FetchFloat(TokenValue,1000);
                            } else TokenValue *= 1000;
                        } else FetchFloat(0,1000);
                        newPlayUntil = (double)TokenValue;
                        PlayUntil = newPlayUntil;
                    } else {
                        CommandError(MsgStrs[ErrSyntax]);
                        break;
                    }
                } else if (CurToken == OnTok){
                    FetchToken();
                    option = CurToken;
                    suboption = 0;
                    if( (option==RasMolTok) || (option==ScriptTok)
                       || (IsMoleculeToken(option))
                       || (IsImageToken(option)) )
                    {   if( !*TokenPtr || *TokenPtr==' ' )
                        suboption = FetchToken();
                        if (suboption == MirrorTok || suboption == RotateTok) 
                        {  if (!*TokenPtr || *TokenPtr==' ')
                            FetchToken();
                        }
                        else suboption = 0;
                    } else option = 0;
                    
                    if( !CurToken )
                    {   CommandError(MsgStrs[ErrFilNam]);
                        break;
                    } else if( CurToken==StringTok )
                    {      ProcessFileName(TokenIdent);
                    } else {
                        ProcessFileName(TokenStart);
                        CurToken=0;
                    }
                    if (ConvPRTemplate(PlayTemplate,DataFileName,1024,&PlayMaxMS)) {
                        CommandError(MsgStrs[StrCLong]);
                        break;
                    }
                    PlayOption = option;
                    PlaySubOption = suboption;
                    PlayPause = 0;
                    if (play_fps <= 0.) play_fps = 24.;
                    play_frame[0] = play_frame[1] = 0;
                    PlayFrom = newPlayFrom;
                    PlayUntil = newPlayUntil;
                    if (PlayUntil == 0) PlayUntil = PlayMaxMS-1.;
                    if (PlayUntil > PlayMaxMS-1. && PlayMaxMS > 1.) PlayUntil = PlayMaxMS-1.;
                } else if (CurToken == OffTok ) {
                    PlayPause = 1;
                    FetchToken();
                    if (!CurToken) break;
                    PlayTemplate[0] = 0;
                } else {
                    CommandError(MsgStrs[ErrSyntax]);
                    break;
                }
                if (CurToken) FetchToken();
            } while (CurToken != 0);
            if (!PlayPause && PlayTemplate[0] != '\0') PlayMovie();
            break;
        }
            
        case(RecordTok):
        {
            int newRecordFrom, newRecordUntil;
            
            newRecordFrom = RecordFrom;
            newRecordUntil = RecordUntil;
            if (RecordTemplate[0]==0){
                newRecordFrom = 0;
                newRecordUntil = -1;
            }
            if( !AllowWrite )
                if( (FileDepth!=-1) && LineStack[FileDepth] )
                {   CommandError(MsgStrs[ErrInScrpt]);
                    break;
                }
            if( !Database ) { 
                CommandError(MsgStrs[ErrBadMolDB]);
                break;
            }
            FetchToken();
            do {
                if (CurToken == FromTok) {
                    FetchToken();
                    if( (CurToken==NumberTok) || (CurToken=='.') ) {   
                        if( CurToken==NumberTok ) {
                            if( *TokenPtr=='.' ) {   
                                TokenPtr++;
                                FetchFloat(TokenValue,1000);
                            } else TokenValue *= 1000;
                        } else FetchFloat(0,1000);
                        newRecordFrom = (double)TokenValue;
                        RecordFrom = newRecordFrom;
                    } else {
                        CommandError(MsgStrs[ErrSyntax]);
                        break;
                    }
                } else if (CurToken == UntilTok) {
                    FetchToken();
                    if( (CurToken==NumberTok) || (CurToken=='.') ) {   
                        if( CurToken==NumberTok ) {
                            if( *TokenPtr=='.' ) {   
                                TokenPtr++;
                                FetchFloat(TokenValue,1000);
                            } else TokenValue *= 1000;
                        } else FetchFloat(0,1000);
                        newRecordUntil = (double)TokenValue;
                        RecordUntil = newRecordUntil;
                    } else {
                        CommandError(MsgStrs[ErrSyntax]);
                        break;
                    }
                } else if (CurToken == OnTok){
                    FetchToken();
                    option = CurToken;
                    suboption = 0;
                    if( (option==RasMolTok) || (option==ScriptTok)
                       || (IsMoleculeToken(option))
                       || (IsImageToken(option)) )
                    {   if( !*TokenPtr || *TokenPtr==' ' )
                        suboption = FetchToken();
                        if (suboption == MirrorTok || suboption == RotateTok) 
                        {  if (!*TokenPtr || *TokenPtr==' ')
                            FetchToken();
                        }
                        else suboption = 0;
                    } else option = 0;
                    
                    if( !CurToken )
                    {   CommandError(MsgStrs[ErrFilNam]);
                        break;
                    } else if( CurToken==StringTok )
                    {      ProcessFileName(TokenIdent);
                    } else {
                        ProcessFileName(TokenStart);
                        CurToken=0;
                    }
                    if (ConvPRTemplate(RecordTemplate,DataFileName,1024,&RecordMaxMS)) {
                      CommandError(MsgStrs[StrCLong]);
                      break;
                    }
                    RecordOption = option;
                    RecordSubOption = suboption;
                    RecordPause = 0;
                    record_frame[0] = record_frame[1] = 0;
                    if (record_fps <= 0.) record_fps = 24.;
                    RecordFrom = newRecordFrom;
                    RecordUntil = newRecordUntil;
                    if (RecordUntil == 0) RecordUntil = RecordMaxMS-1.;
                    if (RecordUntil > RecordMaxMS-1. && RecordMaxMS > 1.) RecordUntil = RecordMaxMS-1.;
                } else if (CurToken == OffTok ) {
                    RecordPause = 1;
                    FetchToken();
                    if (!CurToken) break;
                    RecordTemplate[0] = 0;
                } else if (CurToken == MotionTok || CurToken==MouseTok) {
                    FetchToken();
                    if (CurToken ==0 || CurToken == OnTok)  {
                    	record_on[0] = True;
                    } else if (CurToken == OffTok ){
                        record_on[0] = False;
                    }
                } else if (CurToken == AppearanceTok ) {
                    FetchToken();
                    if (CurToken ==0 || CurToken == OnTok)  {
                    	record_on[1] = True;
                    } else if (CurToken == OffTok ){
                        record_on[1] = False;
                    }
                	
                } else {
                    CommandError(MsgStrs[ErrSyntax]);
                    break;
                }
                if (CurToken) FetchToken();
            } while (CurToken != 0);
            break;
        }

            
        case(WriteTok):
        case(SaveTok):    i = CurToken; /* Save keyword! */
            if( !AllowWrite )
                if( (FileDepth!=-1) && LineStack[FileDepth] )
                {   CommandError(MsgStrs[ErrInScrpt]);
                    break;
                }
            if( !Database ) { 
                CommandError(MsgStrs[ErrBadMolDB]);
                break;
            }
            
            option = FetchToken();
            suboption = 0;
            if( (option==RasMolTok) || (option==ScriptTok)
               || (IsMoleculeToken(option))
               || (IsImageToken(option)) )
            {   if( !*TokenPtr || *TokenPtr==' ' )
                suboption = FetchToken();
                if (suboption == MirrorTok || suboption == RotateTok) 
                {  if (!*TokenPtr || *TokenPtr==' ')
                    FetchToken();
                }
                else suboption = 0;
            } else if( i==SaveTok )
            {   option = PDBTok;
            } else option = 0;
            
            if( !CurToken )
            {   CommandError(MsgStrs[ErrFilNam]);
                break;
            } else if( CurToken==StringTok )
            {      ProcessFileName(TokenIdent);
            } else ProcessFileName(TokenStart);
            param = DataFileName;
            CurToken = 0;
            
            if( !IsMoleculeToken(option) )
            {   if( ReDrawFlag )  {
            	  RefreshScreen();
                  ReDrawFlag = NextReDrawFlag;
                }
                WriteImageFile( param, option, suboption );
                
            } else switch(option)
            {   case(NMRPDBTok):
                case(PDBTok):  SavePDBMolecule(param); break;
                case(WPDBTok): SaveWPDBMolecule(param); break;
                case(MDLTok):  SaveMDLMolecule(param); break;
                case(XYZTok):  SaveXYZMolecule(param); break;
                case(CIFTok):  SaveCIFMolecule(param); break;
#ifdef CEXIOLIB
                case(CEXTok):  SaveCEXMolecule(param); break;
#endif
                case(AlchemyTok): SaveAlchemyMolecule(param);
                    break;
            } break;
            
        case(SourceTok):
        case(ScriptTok):  FetchToken();
            if( FileDepth<STACKSIZE )
            {   if( !CurToken )
            {   CommandError(MsgStrs[ErrFilNam]);
                break;
            } else if( CurToken==StringTok )
            {      ProcessFileName(TokenIdent);
            } else ProcessFileName(TokenStart);
                CurToken = 0;
                
                script = fopen(DataFileName,"rb");
                LoadScriptFile(script,DataFileName);
            } else CommandError(MsgStrs[ErrScript]);
            break;
            
        case(RenumTok):   FetchToken();
            if( CurToken )
            {   if( CurToken=='-' )
            {    FetchToken();
                done = True;
            } else done = False;
                
                if( CurToken == NumberTok )
                {   if( done )
                {     RenumberMolecule(-(int)TokenValue);
                } else RenumberMolecule((int)TokenValue); 
                } else CommandError(MsgStrs[ErrNotNum]);
            } else RenumberMolecule(1);
            break;
            
        case(StructureTok):
            FetchToken();
            if( !CurToken || (CurToken==FalseTok) )
            {   DetermineStructure(False);
            } else if( CurToken==TrueTok )
            {   DetermineStructure(True);
            } else CommandError(MsgStrs[ErrSyntax]);
            break;
            
        case(HeaderTok):
        case(CIFDataTok):
            if( AcceptData[FileDepth] == 'Y' ) {
                if( (FileDepth != -1) && LineStack[FileDepth] ) {
                    Recycle = &CurLine[0];
                    switch( CurToken )
                    {  case(HeaderTok):
                            if (SetNewMolecule()){
                                ProcessFile(FormatPDB,False,
                                            FileStack[FileDepth]);
                            } else {
                                CommandError(MsgStrs[ErrBadLoad]);
                            }
                            break;
                            
                        case(CIFDataTok):
                            if (SetNewMolecule()){
                                ProcessFile(FormatCIF,False,
                                            FileStack[FileDepth]);
                            } else {
                                CommandError(MsgStrs[ErrBadLoad]);
                            }
                            break;
                    }
                    DefaultRepresentation();
                } else {
                    CommandError(MsgStrs[ErrOutScrpt]);
                }
            }
            CurToken = 0;
            return( ExitTok );
            
        case(ExitTok):    return( ExitTok );
        case(QuitTok):    return( QuitTok );
        default:          CommandError(MsgStrs[StrUnrec]);
            break;
    }
    
    if( CurToken )
        if( FetchToken() )
            CommandError(MsgStrs[StrIgnore]);
    TokenPtr = NULL;
    return False;
}


int ExecuteIPCCommand( char __huge *ptr )
{
    auto char buffer[256];
    register int stat,result;
    register int len,depth;
    register char *dst;
    
    /* Ignore IPC commands while paused! */
    if( IsPaused ) return 0;
    
    FileDepth = 0;
    *LineStack = 0;
    result = IPC_Ok;
    *NameStack = "IPC Error";
    
    /* Save command line */
    strcpy(buffer,CurLine);
    
    while( *ptr && (*ptr==' ') )
        ptr++;
    
    if( *ptr == '[' )
    {   while( *ptr++ == '[' )
    {   dst = CurLine;
        depth = 0;  
        len = 0;
        
        while( *ptr )
        {   if( *ptr == ']' )
        {   if( !depth )
        {   ptr++; 
            break;
        } else depth--;
        } else if( *ptr=='[' )
            depth++;
            
            if( len < MAXBUFFLEN-1 )
            {   *dst++ = *ptr++;
                len++;
            } else ptr++;
        }
        *dst = '\0';
        
        if( len < MAXBUFFLEN-1 )
        {   stat = ExecuteCommand();
            if( stat == QuitTok )
            {  result = IPC_Quit;
            } else if( stat )
                result = IPC_Exit;
        } else
        {   InvalidateCmndLine();
            WriteString(MsgStrs[StrRCLong]);
        }
        
        while( *ptr && ((*ptr==' ')||(*ptr==';')) )
            ptr++;
    }
    } else if( *ptr )
    {   dst = CurLine;
        len = 0;
        while( *ptr )
        {   if( len < MAXBUFFLEN-1 )
        {   *dst++ = *ptr++;
            len++;
        } else break;
        }
        *dst = '\0';
        
        if( len < MAXBUFFLEN-1 )
        {   stat = ExecuteCommand();
            if( stat == QuitTok )
            {  result = IPC_Quit;
            } else if( stat )
                result = IPC_Exit;
        } else
        {   InvalidateCmndLine();
            WriteString(MsgStrs[StrRCLong]);
        }
    }
    
    FileDepth = -1;
    if( CommandActive )
    {   strcpy(CurLine,buffer);
        if( !result ) result = IPC_Error;
    }
    return result;
}


void InitialiseCommand( void )
{
    int ii;
    
    for (ii=0; ii < 256; ii++) Defer_Symbols[ii] = (Symbol __far *)NULL;
    FreeSymbol = (Symbol __far *)NULL;
    HelpFileName = NULL;
    FreeInfo = (void __far*)0;
    HelpInfo = (void __far*)0;
    
    SelectCount = 0;
    TokenPtr = NULL;
    FileDepth = -1;
    
    SeqFormat = False;
    IsPaused = False;
    
    /* Movie and animation intialization */
    
    play_fps = record_fps = 24.;  /* default to 24 fps */;
    record_aps = 10.;             /* default to 10 Angstroms per second */
    record_on[0] = record_on[1] = False; 
    /* default, not recording motion or appearance */
    record_frame[0] = record_frame[1] = 0;
    /* start the overall and dwell frame counts at 0 */ 
    play_frame[0] = play_frame[1] = 0;
    
    record_dwell = 0.5;           /* dwell half second per command (12 frames)   */
    RecordTemplate[0] = 0;        /* no initial recording */
    PlayTemplate[0] = 0;          /* no initial playback  */
    RecordCurrent = RecordFrom = RecordUntil 
    = PlayCurrent = PlayFrom = PlayUntil = RecordMaxMS = PlayMaxMS = 0.;
    RecordPause = True;
    PlayPause = False;
    
}

