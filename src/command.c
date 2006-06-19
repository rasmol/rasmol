
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

#include <math.h>


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

static void CommandError( char *error )
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
static char *ProcessFileName( char *name )
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
static char *ProcessFileName( char *name )
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
static char *ProcessFileName( char *name )
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


static char *ProcessFileName( char *name )
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
    ReviseTitle();
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
    {   switch( format )
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

        if( src && *src )
        {   
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
            sprintf(buffer,"trap \"\" 13; uncompress -c %s 2> /dev/null\n",
                                                              DataFileName);
        } else if( done == 0x8b )
        {   /* Should #include <signal.h> and trap "" SIGPIPE */
            sprintf(buffer,"trap \"\" 13; gzip -cdq %s 2> /dev/null\n",
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
        ptr = (char*)malloc(len);
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
                            free(NameStack[FileDepth]);
                            FileDepth--;
                        }
                        RasMolExit();
                    } else /* ExitTok */
                        break;
                } else if( IsPaused )
                    return;

            } else CommandError(MsgStrs[StrSLong]);
        } while( ch!=EOF );
        free(NameStack[FileDepth]);
        fclose( fp );
        FileDepth--;
    } else
    {   CommandError( (char*)NULL );
        WriteString(MsgStrs[StrSFile]);
        WriteString(name);  WriteString("'\n");
    }
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
        int icen, negcen;

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

    FetchToken();
    format = FormatPDB;
    if( !*TokenPtr || *TokenPtr==' ' )
    {   if( IsMoleculeToken(CurToken) )
        {   format = Tok2Format(CurToken);
            FetchToken();
        } else if( CurToken == DotsTok )
        {   format = FormatDots;
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
        {      FetchFile(format,info,TokenIdent);
        } else FetchFile(format,info,TokenStart);
        DefaultRepresentation();
    } else /* format == FormatDots */
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
        } else
        {   LoadDotsFile(fp,info);
            fclose(fp);
        }
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
            if( !CurToken || (CurToken==RasMolTok) )
            {   if( Interactive )
                    SetMouseMode( MMRasMol );
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

                if( TokenValue>750 )
                {   CommandError(MsgStrs[ErrBigNum]);
                } else ProbeRadius = (int)TokenValue;
            } else if( CurToken=='.' )
            {   FetchFloat(0,250);
                if( TokenValue>750 )
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
            } else CommandError(MsgStrs[ErrSyntax]);
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

        default:
            CommandError(MsgStrs[ErrParam]);
    }
}


static void ExecuteColourCommand( void )
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
  int Aselect    ;
  int Acount     ;
  int Gselect    ;
  int Gcount     ;
  int model      ;
  char buffer[40];

  if(!Database)
    return;
    
  model = -1;
 
  for(chain=Database->clist;chain;chain=chain->cnext){
    Gselect =  Gcount = 0;
    touched = False;
    current.chn = chain;
    for(group=chain->glist;group;group=group->gnext){
      Aselect =  Acount = 0;
      current.grp = group;
      for(ptr=group->alist;ptr;ptr=ptr->anext) {
	current.atm = ptr;
	if( !(ptr->flag&HeteroFlag) || type != CHN) { 
	  if( ptr->flag&SelectFlag ) {
	    Aselect++;
	    touched = True;
	    if( type == ATM || type == CRD){        /* Atom or Coordinates */
	      WriteString(DescribeObj(&current, type));
	      WriteChar('\n');
	    }
	  }
	  Acount++; 
	}	  	 
      }     
      if( Acount == Aselect )
	  Gselect++;
      Gcount++;       
      if( Aselect && (type == GRP || type == CHN)) { 
        if (!(model == group->model)) {
          model = group->model;
          if (model) {
            sprintf(buffer,"Model: %d\n",model);
            WriteString(buffer);
          }
        }
      }
      if( Aselect && type == GRP) {	              /* Group */
	WriteString(DescribeObj(&current, GRP));
	sprintf(buffer, "\t(%d/%d)\tatoms\n",Aselect, Acount); 
        WriteString(buffer);
      }
    }
    if( touched && type == CHN ) {                    /* Chain */      
      WriteString(DescribeObj(&current, CHN));
      if( Gselect > 0 ) {
	    sprintf(buffer,"\t(%d/%d)\tgroups\n",Gselect, Gcount); 	
        WriteString(buffer);
	  }
      else
	WriteString("\tno group completely selected\n");	
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
                    WriteChar(chn->ident);
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
    char buffer[40];
    Real theta,phi,psi;

    switch( FetchToken() )
    {   case(InfoTok):
                DescribeMolecule();
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
			*TokenPtr--;
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
					*TokenPtr--;
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
				*TokenPtr++;
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

    for( i=0; i<10; i++ )
        DialValue[i] = 0.0;
    SelectCount = 0;

    DestroyDatabase();
    ResetSymbolTable();
    ResetTransform();
    ResetRenderer();
    ResetRepres();
    ResetBondsSel();

    ZoneBoth = True;
    HetaGroups = True;    
    Hydrogens = True;

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


static void WriteImageFile( char *name, int type )
{
    if( !type )
#ifdef EIGHTBIT
        type = GIFTok;
#else
        type = PPMTok;
#endif

    switch( type )
    {   case(GIFTok):     WriteGIFFile(name);             break;
        case(BMPTok):     WriteBMPFile(name);             break;
        case(PPMTok):     WritePPMFile(name,True);        break;
        case(SUNTok):     WriteRastFile(name,False);      break;
        case(SUNRLETok):  WriteRastFile(name,True);       break;
        case(PICTTok):    WritePICTFile(name);            break;
        case(IRISTok):    WriteIRISFile(name);            break;
        case(EPSFTok):    WriteEPSFFile(name,True,True);  break;
        case(MonoPSTok):  WriteEPSFFile(name,False,True); break;
        case(VectPSTok):  WriteVectPSFile(name);          break;

        case(RasMolTok):
        case(ScriptTok):     WriteScriptFile(name);       break;
        case(KinemageTok):   WriteKinemageFile(name);     break;
        case(MolScriptTok):  WriteMolScriptFile(name);    break;
        case(POVRayTok):     WritePOVRayFile(name);       break;
        case(POVRay3Tok):    WritePOVRay3File(name);      break;
        case(PhiPsiTok):     WritePhiPsiAngles(name, False); break;
        case(RamachanTok):   WritePhiPsiAngles(name, 1);  break;
        case(RamPrintTok):   WritePhiPsiAngles(name, -1); break;     
        case(VRMLTok):       WriteVRMLFile(name);         break;
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
                            free(NameStack[FileDepth]);
                            FileDepth--;
                        }
                        RasMolExit();
                    } else /* ExitTok */
                        break;
                } else if( IsPaused )
                    return;
            } else CommandError(MsgStrs[StrSLong]);
        } while( ch!=EOF );
        free(NameStack[FileDepth]);
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
        free(NameStack[FileDepth]);
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


int ExecuteCommand( void )
{
    register char *param;
    register int option;
    register int i,done;
    register Long temp;
    FILE *script;

    TokenPtr = CurLine;
    if( !FetchToken() )
    {   TokenPtr = NULL;
        return False;
    }

    switch( CurToken )
    {   case(AxesTok):       ExecuteAxesCommand();       break;
        case(BoundBoxTok):   ExecuteBoundBoxCommand();   break;
        case(CentreTok):     ExecuteCentreCommand();     break;
        case(ClipboardTok):  ExecuteClipboardCommand();  break;
        case(ColourTok):     ExecuteColourCommand();     break;
        case(ConnectTok):    ExecuteConnectCommand();    break;
        case(EnglishTok):    SwitchLang(English);        break;
        case(FrenchTok):     SwitchLang(French);         break;
        case(ItalianTok):    SwitchLang(Italian);        break;
        case(LoadTok):       ExecuteLoadCommand();       break;
        case(WaitTok):       ExecutePauseCommand();      break;
        case(PickingTok):    ExecutePickingCommand();    break;
        case(PrintTok):      ExecutePrintCommand();      break;
        case(SetTok):        ExecuteSetCommand();        break;
        case(ShowTok):       ExecuteShowCommand();       break;
        case(SpanishTok):    SwitchLang(Spanish);        break;
        case(TitleTok):      ExecuteTitleCommand();      break;
        case(UnitCellTok):   ExecuteUnitCellCommand();   break;

        case(RefreshTok):    RefreshScreen();            break;
        case(ZapTok):        ZapDatabase();              break;
 


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

                              if( TokenValue<=750 )
                              {   SetRadiusValue(MaxFun((int)TokenValue,1),
                                    SphereFlag);
                                    DrawSurf = False;
                                  ReDrawFlag |= RFRefresh;
                              } else CommandError(MsgStrs[ErrBigNum]);
                          } else if( CurToken=='.' )
                          {   FetchFloat(0,250);
                              if( TokenValue<=750 )
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
                              if( TokenValue<=750 )
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
                            if( TokenValue<=750 )
                              {   ProbeRadius = (int)TokenValue;
                                  DrawSurf = True;
                                  ReDrawFlag |= RFRefresh;
                                  SetVanWaalRadius( SphereFlag | TouchFlag );
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

                              if( TokenValue<=750 )
                              {   SetRadiusValue(MaxFun((int)TokenValue,1),
                                    SphereFlag);
                                    DrawSurf = True;
                                  ReDrawFlag |= RFRefresh;
                              } else CommandError(MsgStrs[ErrBigNum]);
                          } else if( CurToken=='.' )
                          {   FetchFloat(0,250);
                              if( TokenValue<=750 )
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
                                    while( BRotValue > 1.0 )
                                        BondSelected->BRotValue -= 2.0;
                                  } else {
                                    double xtemp;
                                    
                                    if (RotMode == RotAll) {
                                      xtemp = WRotValue[option];
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
                                      WRotValue[option] = xtemp;
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
                                WRotValue[option] = 0.0;
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
                                    WTransX = wtemp;
                                  } else { 
                                    if( RotMode == RotAll && option == 5 ) {
                                      WTransY = wtemp;
                                    } else {
                                      if( RotMode == RotAll && option == 6 ) {
                                        WTransZ = wtemp;
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
                          } else CommandError(MsgStrs[ErrSyntax]);
                          break;

        case(ResizeTok):  FetchToken();
                          break;

        case(ResetTok):   for( i=0; i<10; i++ )
                              DialValue[i] = 0.0;
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

        case(WriteTok):
        case(SaveTok):    i = CurToken; /* Save keyword! */
                          if( !AllowWrite )
                              if( (FileDepth!=-1) && LineStack[FileDepth] )
                              {   CommandError(MsgStrs[ErrInScrpt]);
                                  break;
                              }

                          option = FetchToken();
                          if( (option==RasMolTok) || (option==ScriptTok)
                              || (IsMoleculeToken(option))
                              || (IsImageToken(option)) )
                          {   if( !*TokenPtr || *TokenPtr==' ' )
                                  FetchToken();
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
                          {   if( ReDrawFlag ) RefreshScreen();
                              WriteImageFile( param, option );

                          } else switch(option)
                          {   case(NMRPDBTok):
                              case(PDBTok):  SavePDBMolecule(param); break;
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
    HelpFileName = NULL;
    FreeInfo = (void __far*)0;
    HelpInfo = (void __far*)0;

    SelectCount = 0;
    TokenPtr = NULL;
    FileDepth = -1;

    SeqFormat = False;
    IsPaused = False;
}

