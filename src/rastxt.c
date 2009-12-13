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
/* rastxt.c
 */

#ifndef sun386
#include <stdlib.h>
#endif
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <math.h>


#define RASMOL
#define GRAPHICS
#include "rasmol.h"
#include "graphics.h"
#include "molecule.h"
#include "infile.h"
#include "abstree.h"
#include "transfor.h"
#include "cmndline.h"
#include "command.h"
#include "render.h"
#include "repres.h"
#include "pixutils.h"
#include "outfile.h"


#ifdef IBMPC
#include <conio.h>
#endif
#ifdef UNIX
#include <signal.h>
#endif

#ifdef TERMIOS
#include <sys/types.h>
#include <sys/time.h>
#include <termios.h>

#ifdef esv
#include <sysv/unistd.h>
#else
#include <unistd.h>
#endif
#endif /* TERMIOS */



#define TwoPi           6.28318531
#define IsIdentChar(x)  ((isalnum(x))||((x)=='_')||((x)=='$'))

/* Either stdout or stderr */
#define OutFp stdout

#ifdef TERMIOS
static struct termios OrigTerm;
static struct termios IntrTerm;
#endif



static char *FileNamePtr;
static char *ScriptNamePtr;
static int FileFormat;
static int ProfCount;


void WriteMsg( char *ptr )
{
    WriteString(ptr);
    WriteChar ('\n');
}


void WriteChar( int ch )
{   putc(ch,OutFp);
}


void WriteString( char *ptr )
{   fputs(ptr,OutFp);
}


static int InitTerminal( void )
{
#ifdef TERMIOS
    register int fd;
#endif

    setbuf(stdin,(char*)NULL);

#ifdef SIGTTIN
    signal(SIGTTIN,SIG_IGN);
#endif
#ifdef SIGTTOU
    signal(SIGTTOU,SIG_IGN);
#endif

#ifdef TERMIOS
    fd = fileno(stdin);
    if( !isatty(fd) )
        return False;

    if( tcgetattr(fd,&OrigTerm) < 0 )
        return False;

    IntrTerm = OrigTerm;
    IntrTerm.c_iflag |= IGNBRK|IGNPAR;
    IntrTerm.c_iflag &= ~(BRKINT|PARMRK|INPCK|IXON|IXOFF);
    IntrTerm.c_lflag &= ~(ICANON|ISIG|ECHO|ECHOE|ECHOK|ECHONL|NOFLSH);
    /* IntrTerm.c_lflag |= ISIG; */

    IntrTerm.c_cc[VMIN] = 1;
    IntrTerm.c_cc[VTIME] = 0;

#ifdef VSUSP /* Disable ^Z */
    IntrTerm.c_cc[VSUSP] = 0;
#endif

    tcsetattr(fd,TCSANOW,&IntrTerm);
#endif /* TERMIOS */
    return True;
}


static void ResetTerminal( void )
{
#ifdef TERMIOS
    register int fd;

    fd = fileno(stdin);
    if( isatty(fd) )
        tcsetattr(fd,TCSANOW,&OrigTerm);

#endif
}


void RasMolExit( void )
{
    WriteChar('\n');
    if( CommandActive )
        WriteChar('\n');
    ResetTerminal();
    exit(0);
}


void RasMolFatalExit( char *msg )
{
    WriteChar('\n');
    WriteString(msg);
    WriteChar('\n');
    WriteChar(0x07);
    ResetTerminal();
    exit(1);
}


void RasMolSignalExit( int i )
{
    UnusedArgument(i);

    RasMolFatalExit("*** Quit ***");
}


static int FetchCharacter( void )
{
#ifdef IBMPC
    return _getch();
#else
    return getc(stdin);
#endif
}


static int ReadCharacter( void )
{
    register int ch;

    ch = FetchCharacter();
#ifdef IBMPC
    if( ch && (ch!=0xe0) ) 
        return ch;

    ch = FetchCharacter();
    switch( ch )
    {   case('H'): return( 0x10 ); /* Up    */
        case('P'): return( 0x0e ); /* Down  */
        case('K'): return( 0x02 ); /* Left  */
        case('M'): return( 0x06 ); /* Right */
    }
#else
    if( ch != 0x1b )
        return ch;
    ch = FetchCharacter();
    if( (ch!='[') && (ch!='O') )
        return ch;

    ch = FetchCharacter();
    switch( ch )
    {   case('A'): return( 0x10 ); /* Up    */
        case('B'): return( 0x0e ); /* Down  */
        case('C'): return( 0x06 ); /* Right */
        case('D'): return( 0x02 ); /* Left  */
    }
#endif
    return 0;
}


static void LoadInitFile( void )
{
    register char *src,*dst;
    register FILE *initrc;
    register char *fname;
    char fnamebuf[128];

    fname = "RASMOL.INI";
    initrc = fopen(fname,"rb");
    if( !initrc && (src=(char*)getenv("HOME")) )
    {   dst = fnamebuf; 
        while( *src )
            *dst++ = *src++;
        *dst++ = '\\';

        src = fname; fname = fnamebuf;
        while( (*dst++ = *src++) );
        initrc = fopen(fname,"rb");
    }

    if( !initrc && (src=(char*)getenv("RASMOLPATH")) )
    {   dst = fnamebuf; 
        while( *src )
            *dst++ = *src++;
        *dst++ = '\\';

        src = "rasmolrc"; fname = fnamebuf;
        while( (*dst++ = *src++) );
        initrc = fopen(fname,"rb");
    }

    if( initrc )
        LoadScriptFile(initrc,fname);
}


int CreateImage( void )
{
    register Long size;
    
    if( FBuffer ) _ffree(FBuffer);
    size = (Long)XRange*YRange*sizeof(Pixel);
    FBuffer = (Pixel*)_fmalloc( size+32 );
    return( (int)FBuffer );
}


void TransferImage( void )
{
}


int ClipboardImage( void )
{
    return False;
}


void ClearImage( void )
{
}


int PrintImage( void )
{
    return False;
}



void AllocateColourMap( void )
{
}


void UpdateScrollBars( void )
{
}


int LookUpColour( char *name, int *r, int *g, int *b )
{
    UnusedArgument(name);
    UnusedArgument(r);
    UnusedArgument(g);
    UnusedArgument(b);

    return False;
}


void SetMouseUpdateStatus( int bool )
{
    MouseUpdateStatus = bool;
}
                         
                         
void SetMouseCaptureStatus( int bool )
{
    MouseCaptureStatus = bool;
}
                         

void SetCanvasTitle( char *ptr )
{
    UnusedArgument(ptr);
}


void EnableMenus( int flag )
{
    UnusedArgument(flag);
}


void CloseDisplay( void )
{
}


void BeginWait( void )
{
}


void EndWait( void )
{
}


int OpenDisplay( void )
{
    register int i;

    for( i=0; i<10; i++ )
        DialValue[i] = 0.0;
    
    XRange = x;   WRange = XRange>>1;
    YRange = y;   HRange = YRange>>1;
    Range = MinFun(XRange,YRange);
    ZRange = 20000;
    
    /* Initialise Palette! */
    for( i=0; i<256; i++ )
        ULut[i] = False;
    AllocateColourMap();
    return False;
}


void AdviseUpdate( int item )
{
    UnusedArgument(item);
}


void RefreshScreen( void )
{
    int ReDrawFlagSave;
    if( !UseSlabPlane )
    {   ReDrawFlag &= ~RFTransZ|RFSlab;
    } else ReDrawFlag &= ~RFTransZ;
    
    ReDrawFlagSave = ReDrawFlag;
    if( ReDrawFlag )
    {   if( ReDrawFlag & RFReSize )
            ReSizeScreen();

        if( ReDrawFlag & RFColour )
            DefineColourMap();
        
        NextReDrawFlag = 0;
        if( Database )
        {   if( ReDrawFlag & RFApply ) 
                ApplyTransform();
            DrawFrame();
        }
        if ((ReDrawFlagSave & RFApply) && record_on[0] && !RecordPause ) {
	      WriteMovieFrame();
	      record_frame[0]++;
	      record_frame[1] = 0;
	    } else if ((ReDrawFlagSave & RFAppear) && record_on[1] && !RecordPause) {
	      WriteMovieFrame();
	      record_frame[0]++;
	      record_frame[1]++;
	      if ((double)(record_frame[1]) <= record_fps*record_dwell) {
	        NextReDrawFlag |= RFRefresh;
	      } else {
	      	NextReDrawFlag = 0;
	      	record_frame[1] = 0;
	      }
	    }
    }

    }
}



static void ProfileExecution( void )
{
    register long start,stop;
    register Real delta;
    register int i;

    delta = TwoPi/ProfCount;

    printf("Profiling Execution!\n");

    start = time((time_t *)NULL);
    for( i=0; i<ProfCount; i++ )
    {   DrawFrame();
        ReDrawFlag |= RFRotateY;
        DialValue[1] += delta;
        /* UpdateScrollBars(); */
        ApplyTransform();
    }

    stop = time((time_t *)NULL);
    fprintf(stderr,"Execution of %d frames\n",ProfCount);
    fprintf(stderr,"Duration = %ld seconds\n",stop-start);
}


static void InitDefaultValues( void )
{
    Interactive = False;

    FileNamePtr = NULL;
    ScriptNamePtr = NULL;
    InitWidth = InitHeight = InitXPos = InitYPos = 0;
    ProfCount = 0;

    FileFormat = FormatPDB;
    CalcBondsFlag = True;
    CalcSurfFlag = False;
}


static void DisplayUsage( void )
{
    fputs("usage: rastxt [-script scriptfile] ",OutFp);
    fputs("[[-format] file]\n    formats: -cif -pdb -nmrpdb ",OutFp);
    fputs("-mopac -mdl -mol2 -xyz -alchemy -charmm\n\n",OutFp);
    exit(1);
}


#define FORMATOPTMAX   15
static struct {
        char *ident;
        int format;
    } FormatOpt[FORMATOPTMAX] = { 
            { "alchemy",    FormatAlchemy  },
            { "biosym",     FormatBiosym   },
            { "cif",        FormatCIF      },
            { "charmm",     FormatCharmm   },
            { "fdat",       FormatFDAT     },
            { "gaussian",   FormatGaussian },
            { "macromodel", FormatMacroMod },
            { "mdl",        FormatMDL      },
            { "mmdb",       FormatMMDB     },
            { "mol2",       FormatMol2     },
            { "mopac",      FormatMOPAC    },
            { "nmrpdb",     FormatNMRPDB   },
            { "pdb",        FormatPDB      },
            { "shelx",      FormatSHELX    },
            { "xyz",        FormatXYZ      }
                                };


static void ProcessOptions( int argc, char *argv[] )
{
    register char *ptr;
    register int i,j;

    for( i=1; i<argc; i++ )
    {   ptr = argv[i];
        if( (*ptr=='-') && ptr[1] )
        {   ptr++;

            if( !strcmp(ptr,"prof") ||
                !strcmp(ptr,"profile") )
            {   ProfCount = 200;
            } else if( !strcmp(ptr,"noconnect") )
            {   CalcBondsFlag = False;
            } else if( !strcmp(ptr,"connect") )
            {   CalcBondsFlag = True;

            } else if( !strcmp(ptr,"script") )
            {   if( i == argc-1 ) DisplayUsage();
                ScriptNamePtr = argv[++i];
            } else if( !strcmp(ptr,"insecure") )
            {   AllowWrite = True;
            } else if( !strcmp(ptr,"width") ||
                       !strcmp(ptr,"wide") )
            {   if( i == argc-1 ) DisplayUsage();
                InitWidth = atoi(argv[++i]);
                if( InitWidth < 48 )
                    InitWidth = 48;
                else if( (j = InitWidth%4) )
                    InitWidth += 4-j;

            } else if( !strcmp(ptr,"height") ||
                       !strcmp(ptr,"high") )
            {   if( i == argc-1 ) DisplayUsage();
                InitHeight = atoi(argv[++i]);
                if( InitHeight < 48 )
                    InitHeight = 48;

            } else if( !strcmp(ptr,"sybyl") )
            {   FileFormat = FormatMol2;
            } else if( !strcmp(ptr,"pdbnmr") )
            {   FileFormat = FormatNMRPDB;
            } else if( !strcmp(ptr,"cif") )
	    {  FileFormat = FormatCIF;
#ifdef CEXIOLIB
            } else if( !strcmp(ptr,"cex") )
            {   FileFormat = FormatCEX;
#endif

            } else  /* File Formats! */
            {   for( j=0; j<FORMATOPTMAX; j++ )
                    if( !strcmp(ptr,FormatOpt[j].ident) )
                    {   FileFormat = FormatOpt[j].format;
                        break;
                    }

                if( j==FORMATOPTMAX )
                    DisplayUsage();
            }
        } else
            if( !FileNamePtr )
            {   FileNamePtr = ptr;
            } else DisplayUsage();
    }
}


int main( int argc, char *argv[] )
{
    register FILE *fp;
    register int done;
    register char ch;


    static char VersionStr[100];

    sprintf (VersionStr,"%s\nVersion %s %s\n%s\n\n", 
             MAIN_COPYRIGHT, VERSION, 
             VER_DATE, VER_COPYRIGHT);

    InitDefaultValues();
    ProcessOptions(argc,argv);
    ReDrawFlag = 0;
    
    setbuf(OutFp,(char *)NULL);
    OpenDisplay();
    InitTerminal();

#ifdef UNIX
    signal(SIGINT,RasMolSignalExit);
    signal(SIGPIPE,SIG_IGN);
#endif

    WriteString("RasMol Molecular Renderer\n");
    WriteString("Roger Sayle, August 1995\n");
    WriteString(VersionStr);
    WriteString("*** See \"help notice\" for further notices ***\n");

#ifdef EIGHTBIT
    WriteString("[8-bit version]\n\n");
#endif
#ifdef SIXTEENBIT
    WriteString("[16-bit version]\n\n");
#endif
#ifdef THIRTYTWOBIT
    WriteString("[32-bit version]\n\n");
#endif

    InitialiseCmndLine();
    InitialiseCommand();
    InitialiseTransform();
    InitialiseDatabase();
    InitialiseRenderer();
    InitialisePixUtils();
    InitialiseAbstree();
    InitialiseOutFile();
    InitialiseRepres();
    InitHelpFile();

    if( ProfCount )
    {   if( FileNamePtr )
        {   strcpy(DataFileName,FileNamePtr);

            if( strcmp(FileNamePtr,"-") )
            {   done = FetchFile(FileFormat,True,FileNamePtr);
            } else done = ProcessFile(FileFormat,True,stdin);
            if( !done )
                RasMolFatalExit("Profile Error: Unable to read data file!");
        } else RasMolFatalExit("Profile Error: No molecule filename!");

        ReDrawFlag |= RFRefresh | RFColour;

        /* SetVanWaalRadius(); */
        /* CPKColourAttrib();  */

        FakeSpecular = True;
        ScaleColourAttrib(GroupAttr);
        SetRibbonCartoons();
        EnableWireframe(WireFlag,0,0);
        RefreshScreen();
        ReDrawFlag = NextReDrawFlag;

        /* Avoid Pending Events */
        ProfileExecution();
        RasMolExit();
    }

    if( FileNamePtr )
    {   strcpy(DataFileName,FileNamePtr);

        if( !strcmp(FileNamePtr,"-") )
        {   done = ProcessFile(FileFormat,True,stdin);
        } else done = FetchFile(FileFormat,True,FileNamePtr);

        if( done )
        {   DefaultRepresentation();
            RefreshScreen();
            ReDrawFlag = NextReDrawFlag;
        }
    }

    ResetCommandLine(1);

    LoadInitFile();
    if( ScriptNamePtr )
    {   if( !(fp=fopen(ScriptNamePtr,"rb")) )
        {   fprintf(OutFp,"Error: File '%s' not found!\n",ScriptNamePtr);
        } else LoadScriptFile(fp,ScriptNamePtr);
    }

    if( FileNamePtr && !strcmp(FileNamePtr,"-") )
    {   /* Finished Processing after stdin? */
        RasMolExit();
    }


    done = False;
    while( !done )
    {   /* Command Line Only! */
        ch = ReadCharacter();
        if( ProcessCharacter(ch) )
        {   if( !ExecuteCommand() )
            {   RefreshScreen();
                if( !CommandActive )
                    ResetCommandLine(0);
                ReDrawFlag = NextReDrawFlag;
            } else done = True;
        }
    }
    RasMolExit();
    return 0;
}

