
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
/* rasmol.c
 $Log: not supported by cvs2svn $
 Revision 1.1  2004/05/07 19:46:16  yaya
 Initial revision

 Revision 1.3  2004/02/15 00:24:00  yaya
 *** empty log message ***

 Revision 1.2  2003/12/13 19:26:11  yaya
 *** empty log message ***

 Revision 1.1  2003/12/12 21:10:38  yaya
 Initial revision

 Revision 1.2  2001/02/07 20:30:31  yaya
 *** empty log message ***

 Revision 1.1  2001/01/31 02:13:45  yaya
 Initial revision

 Revision 1.7  2000/08/26 18:12:39  yaya
 Updates to header comments in all files

 Revision 1.6  2000/08/26 03:14:06  yaya
 Mods for mac compilations

 Revision 1.5  2000/08/13 20:56:24  yaya
 Conversion from toolbar to menus

 Revision 1.4  2000/08/12 21:10:30  yaya
 Minimal X windows mods

 Revision 1.3  2000/08/09 01:18:11  yaya
 Rough cut with ucb

 Revision 1.2  2000/08/03 18:32:42  yaya
 Parametrization for alt conformer bond radius

 */

#ifndef sun386
#include <stdlib.h>
#endif
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

#include <signal.h>


#define RASMOL
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
#include "multiple.h" /* [GSG 11/9/95] */
#include "vector.h"
#include "wbrotate.h"
#include "langsel.h"



#ifdef esv
#include <sysv/unistd.h>
#else
#include <unistd.h>
#endif

#ifdef PROFILE
#include <sys/types.h>
#ifndef TIME
#include <sys/time.h>
#else
#include <time.h>
#endif /* TIME    */
#endif /* PROFILE */

#ifdef TERMIOS
#include <sys/types.h>
#include <sys/time.h>
#include <termios.h>

#if defined(_SEQUENT_) || defined(_AIX)
#include <sys/select.h>
#endif

#ifdef __sgi
/* Avoid 'bzero' Compiler Warnings! */
#include <bstring.h>
#endif
#endif /* TERMIOS */


#ifdef VMS
#include <tt2def.h>
#include <iodef.h>
#include <starlet.h>
#include <string.h>
#include <time.h>
#endif

#ifdef SOCKETS
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#endif

#ifdef XFORMSLIB
#include <sys/stat.h>
#include <forms.h>
#define	XFORMS_FONTSIZE		14
#define	XFORMS_OPENDIALOG	0
#define	XFORMS_SAVEDIALOG	1
#endif

#define IsIdentChar(x)  ((isalnum(x))||((x)=='_')||((x)=='$'))
#define TwoPi           2.0*PI

/* Either stdout or stderr */
#define OutFp stdout


#ifdef VMS
static struct {
        unsigned short size; 
        unsigned short type;
        char *string;
        } StdInDesc = { 10, 0, "SYS$INPUT:" };

/* Character Terminator Mask! */
static int StdInMask[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

static short StdInBlck[4];
static int StdInMode[3];
static int StdInOrig[3];
static short StdInChan;
static int StdInStatus;
static char StdInChar;
static int StdInFlag;
#endif

#ifdef TERMIOS
static struct termios OrigTerm;
static struct termios IntrTerm;

static struct timeval TimeOut;
static fd_set OrigWaitSet;
static fd_set WaitSet;
static int WaitWidth;
static int FileNo;

#ifdef SOCKETS
/* Supported Protocols */
#define ProtoRasMol   0x01

#define AMNone         0x00
#define AMPickAtom     0x01
#define AMPickNumber   0x02
#define AMSelectCount  0x04
#define AMMolName      0x08
#define AMPickCoord    0x10

typedef struct {
    int bitmask;
    char *name;
    } AdviseType;

static AdviseType AdviseMap[ItemCount] = {
    { AMPickAtom,    "Pick"    },  /* AdvPickAtom    */
    { AMPickNumber,  "PickNo"  },  /* AdvPickNumber  */
    { AMSelectCount, "Count"   },  /* AdvSelectCount */
    { AMMolName,     "Name"    },  /* AdvName        */
    { AMNone,        "Ident"   },  /* AdvIdent       */
    { AMNone,        "Class"   },  /* AdvClass       */
    { AMNone,        "Image"   },  /* AdvImage       */
    { AMPickCoord,   "PickXYZ" }   /* AdvPickCoord   */
        };

static char AdviseBuffer[256];
static size_t AdviseLen;


typedef struct {
        int protocol;
        int socket;
        int advise;
    } IPCConv;

#define MaxIPCConvNum     8
static IPCConv IPCConvData[MaxIPCConvNum];

static int ServerPort;
static int UseSockets;
static int SocketNo;
#endif  /* SOCKETS */
#endif  /* TERMIOS */


static int InitialWide;
static int InitialHigh;

static char *FileNamePtr;
static char *ScriptNamePtr;
static int FileFormat;
static int ProfCount;
static int LexState;



/*=======================*/
/*  Function Prototypes  */
/*=======================*/

static int HandleEvents( int );
extern int ProcessCommand( void );


void WriteChar( int ch )
{   putc(ch,OutFp);
}


void WriteString( char *ptr )
{   fputs(ptr,OutFp);
}


static void ResetTerminal( void )
{
#ifdef SOCKETS
    register int i;
#endif

#ifdef TERMIOS
    if( isatty(FileNo) )
        tcsetattr(FileNo, TCSANOW, &OrigTerm);
#endif

#ifdef SOCKETS
    if( UseSockets )
    {   close(SocketNo);

        for( i=0; i<MaxIPCConvNum; i++ )
            if( IPCConvData[i].protocol )
            {   close(IPCConvData[i].socket);
                IPCConvData[i].protocol = 0;
            }
    }
#endif

#ifdef VMS
    StdInFlag = False;
    if( StdInStatus & 0x01 )
        sys$cancel(StdInChan);

    sys$qiow( 0, StdInChan, IO$_SETMODE, 0, 0, 0,
              StdInOrig, 12, 0, 0, 0, 0 );
#endif
}


void RasMolExit( void )
{
    WriteChar('\n');
    if( CommandActive )
        WriteChar('\n');

    if( Interactive )
        CloseDisplay();
    ResetTerminal();
    exit(0);
}


void RasMolFatalExit( char *msg )
{
    WriteChar('\n');
    WriteString(msg);
    WriteChar('\n');
    WriteChar(0x07);

    if( Interactive )
        CloseDisplay();
    ResetTerminal();
    exit(1);
}


#ifdef VMS
static int StdInASTEvent( void )
{
    register int ch;
    register int i;

    if( !StdInFlag )
        return( False );

    if( StdInBlck[0] & 0x01 )
    {   if( StdInBlck[1] )
        {   if( StdInChar == 0x03 )
                RasMolFatalExit("*** Quit ***");

            if( LexState == 0 )
            {   if( StdInChar == 0x1b )
                {   LexState = 1;  ch = 0;
                } else ch = StdInChar;

            } else if( LexState == 1 )
            {   if( StdInChar=='[' )
                {   LexState = 2;  ch = 0;
                } else if( StdInChar=='O' )
                {   LexState = 3;  ch = 0;
                } else if( StdInChar != 0x1b )
                {   LexState = 0;  ch = StdInChar;
                } else ch = 0;

            } else /* LexState == 2 or 3 */
            {   LexState = 0;
                switch( StdInChar )
                {   case('A'): ch = 0x10;  break;
                    case('B'): ch = 0x0e;  break;
                    case('C'): ch = 0x06;  break;
                    case('D'): ch = 0x02;  break;
                    default:   if( LexState==2 )
                               {      ProcessCharacter('[');
                               } else ProcessCharacter('O');

                               if( StdInChar == 0x1b )
                               {   LexState = 1;  ch = 0;
                               } else ch = StdInChar;
                }
            }
        } else ch = '\n';

        if( ch && ProcessCharacter(ch) )
        {   if( ProcessCommand() )
                RasMolExit();

            if( !CommandActive )
                ResetCommandLine(0);
        }
    }

    /* Queue an Asynchronous I/O Request */
    StdInStatus = sys$qio( 0, StdInChan, IO$_READVBLK|IO$M_NOECHO, 
                           StdInBlck, StdInASTEvent, 0, &StdInChar, 
                           1, 0, StdInMask, 0, 0);
    return( True );
}
#endif  /* VMS */


#ifdef SOCKETS
static int OpenSocket( void )
{
    struct sockaddr_in addr;
    auto int length;
    register int i;

    UseSockets = False;
    SocketNo = socket(AF_INET, SOCK_STREAM, 0);
    if( SocketNo < 0 ) return( False );

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons((short)ServerPort);

    if( bind(SocketNo, (struct sockaddr*)&addr, sizeof(addr)) )
    {   close(SocketNo);
        return( False );
    }

    if( !ServerPort )
    {   length = sizeof(addr);
        if( !getsockname(SocketNo, (struct sockaddr*)&addr, &length) )
        {   ServerPort = ntohs(addr.sin_port);
            fprintf(stderr,"RasMol Server TCP/IP Port: %d\n",ServerPort);
        }
    }

    UseSockets = True;
    for( i=0; i<MaxIPCConvNum; i++ )
        IPCConvData[i].protocol = 0;

    listen( SocketNo, 5 );
    return( True );
}


static int OpenIPCConnection( int xsocket )
{
    register int i;

    if( xsocket < 0 )
        return False;

    for( i=0; i<MaxIPCConvNum; i++ )
        if( !IPCConvData[i].protocol )
        {   FD_SET((long)xsocket,(fd_set *)&OrigWaitSet);
            if( xsocket >= WaitWidth )
                WaitWidth = xsocket+1;

            IPCConvData[i].protocol = ProtoRasMol;
            IPCConvData[i].socket = xsocket;
            IPCConvData[i].advise = AMNone;
            return( True );
        }

    close( xsocket );
    return( False );
}


static void CloseIPCConnection( int conv )
{
    FD_CLR(IPCConvData[conv].socket,&OrigWaitSet);
    close( IPCConvData[conv].socket );
    IPCConvData[conv].protocol = 0;
}


static int CaseInsensitiveCompare( char *ptr1, char *ptr2 )
{
    register unsigned char *rptr1;
    register unsigned char *rptr2;
    register unsigned char c1;
    register unsigned char c2;

    rptr1 = (unsigned char*)ptr1;
    rptr2 = (unsigned char*)ptr2;

    do {
        c1 = ToUpper(*rptr1++);
        c2 = ToUpper(*rptr2++);
    } while( c1 && (c1==c2) );
    return c1 - c2;
}


static int IsIPCAdviseRequest( char *ptr, int conv )
{
    auto char item[34];
    register char *dst;
    register char *src;
    register int i,ch;
    register int flag;

    if( !strncmp(ptr,"Advise:",7) )
    {   src = ptr+7;
        flag = True;
    } else if( !strncmp(ptr,"Unadvise:",9) )
    {   src = ptr+9;
        flag = False;
    } else return False;

    while( *src )
    {   ch = *src++;
        if( isspace(ch) )
            continue;

        if( isalpha(ch) )
        {   dst = item;
            *dst++ = ch;
            while( IsIdentChar(*src) )
            {   if( dst < item+32 )
                {   *dst++ = *src++;
                } else src++;
            }
            *dst = '\0';

            for( i=0; i<ItemCount; i++ )
                if( !CaseInsensitiveCompare(item,AdviseMap[i].name) )
                {   if( flag )
                    {      IPCConvData[conv].advise |=  AdviseMap[i].bitmask;
                    } else IPCConvData[conv].advise &= ~AdviseMap[i].bitmask;
                    break;
                }

                /* Warning: Unknown Advise Item! */
        } else if( ch != ',' )
            break;
    }
    return True;
}


static void HandleSocketData( int conv )
{
    register char *src,*dst;
    register int result;
    register int ch,len;
    char buffer[4097];

    len = recv( IPCConvData[conv].socket, buffer, 4096, 0 );
    if( len > 0 )
    {   buffer[len] = '\0';
        src = dst = buffer;
        while( (ch = *src++) )
            if( (ch>=' ') && (ch<='~') )
                *dst++ = ch;
        *dst = '\0';

        if( !IsIPCAdviseRequest(buffer,conv) )
        {   result = ExecuteIPCCommand(buffer);
            if( result == IPC_Exit )
            {   CloseIPCConnection( conv );
            } else if( result == IPC_Quit )
                RasMolExit();
        }
    } else CloseIPCConnection( conv );
}
#endif /* SOCKETS */


static void InitTerminal( int sockets )
{
#ifdef TERMIOS
    register int i;
#endif

#ifdef SIGTTIN
    signal(SIGTTIN,SIG_IGN);
#endif
#ifdef SIGTTOU
    signal(SIGTTOU,SIG_IGN);
#endif

#ifdef TERMIOS
    FileNo = fileno(stdin);
    FD_ZERO(&OrigWaitSet);
    FD_SET(FileNo,&OrigWaitSet);
    WaitWidth = FileNo+1;

#ifdef SOCKETS
    OpenSocket();
    if( UseSockets )
    {   FD_SET(SocketNo,&OrigWaitSet);
        if( SocketNo >= WaitWidth )
            WaitWidth = SocketNo+1;
    }
#endif

    for( i=0; i<32; i++ )
        if( sockets & (1<<i) )
        {   if( i >= WaitWidth )
                WaitWidth = i+1;
            FD_SET(i,&OrigWaitSet);
        }


    if( isatty(FileNo) )
    {   tcgetattr(FileNo, &OrigTerm);

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

        tcsetattr(FileNo,TCSANOW,&IntrTerm);
    }
#endif /* TERMIOS */

#ifdef VMS
    /* Associate "SYS$INPUT" with channel StdInChan! */
    StdInStatus = sys$assign(&StdInDesc, &StdInChan, 0, 0, 0);
    if( StdInStatus & 0x01 )
    {   StdInFlag = True;

        /* Determine Original Terminal Mode */
        sys$qiow( 0, StdInChan, IO$_SENSEMODE, 0, 0, 0,
                  StdInOrig, 12, 0, 0, 0, 0 );

        StdInMode[0] = StdInOrig[0];
        StdInMode[1] = StdInOrig[1];
        StdInMode[2] = StdInOrig[2];

        /* Select "RAW" Terminal Mode */
        StdInMode[2] |= TT2$M_PASTHRU;

        /* Set Current Terminal Mode */
        sys$qiow( 0, StdInChan, IO$_SETMODE, 0, 0, 0,
                  StdInMode, 12, 0, 0, 0, 0 );

        if( sockets )
        {   /* Queue an Asynchronous I/O Request */
            StdInStatus = sys$qio( 0, StdInChan, IO$_READVBLK|IO$M_NOECHO, 
                                   StdInBlck, StdInASTEvent, 0, &StdInChar, 
                                   1, 0, StdInMask, 0, 0);
        } else StdInStatus = False;
    } else StdInFlag = False;

#else /* !VMS */
    setbuf(stdin,(char*)NULL);
#endif
}


static int FetchCharacter( void )
{
#ifdef TERMIOS
    register int status;
#ifdef SOCKETS
    register int i;
#endif

#ifdef SOCKETS
    if( Interactive || UseSockets )
#else
    if( Interactive )
#endif
        do {
            if( !CommandActive )
                ResetCommandLine(0);

            if( Interactive )
            {   HandleEvents(False);

                /* avoid slow response time */
                if( !CommandActive )
                    ResetCommandLine(0);
            }

            TimeOut.tv_sec = 1;
            TimeOut.tv_usec = 0;
            WaitSet = OrigWaitSet;
#ifdef HPUX_LEGACY
            status = select( WaitWidth, (int*)&WaitSet, (int*)NULL, 
                                        (int*)NULL, &TimeOut );
#else
            status = select( WaitWidth, &WaitSet, (fd_set*)NULL, 
                                        (fd_set*)NULL, &TimeOut );
#endif

#ifdef SOCKETS
            if( UseSockets )
            {   if( FD_ISSET(SocketNo,&WaitSet) )
                {   OpenIPCConnection( accept(SocketNo,0,0) );
                } else for( i=0; i<MaxIPCConvNum; i++ )
                    if( IPCConvData[i].protocol )
                        if( FD_ISSET(IPCConvData[i].socket,&WaitSet) )
                            HandleSocketData( i );
            }
#endif
        } while( (status<1) || !FD_ISSET(FileNo,&WaitSet) );
#endif /* TERMIOS */

    if( !CommandActive )
        ResetCommandLine(0);

#ifdef VMS
    sys$qiow( 0, StdInChan, IO$_READVBLK|IO$M_NOECHO, StdInBlck,
              0, 0, &StdInChar, 1, 0, StdInMask, 0, 0);
    return( StdInChar );
#else
    return( getc(stdin) );
#endif
}


static int ReadCharacter( void )
{
    register int tmp;
    register int ch;

    if( LexState )
    {   ch = LexState;
        LexState = 0;
        return( ch );
    }

    ch = FetchCharacter();
    if( ch!=0x1b ) return( ch );

    ch = FetchCharacter();
    if( (ch!='[') && (ch!='O') ) 
        return( ch );

    switch( tmp=FetchCharacter() )
    {   case('A'): return( 0x10 );
        case('B'): return( 0x0e );
        case('C'): return( 0x06 );
        case('D'): return( 0x02 );
    }
    LexState = tmp;
    return(ch);
}


void RasMolSignalExit( int arg )
{
    UnusedArgument(arg);

    RasMolFatalExit("*** Quit ***");
}


static void LoadInitFile( void )
{
    register char *src,*dst;
    register FILE *initrc;
    register char *fname;
    char fnamebuf[128];

#ifdef VMS
    fname = "RASMOL.INI";
#else
    fname = ".rasmolrc";
#endif

    initrc = fopen(fname,"rb");
    if( !initrc && (src=(char*)getenv("HOME")) )
    {   dst = fnamebuf; 
        while( *src )
            *dst++ = *src++;
#ifndef VMS
        *dst++ = '/';
#endif

        src = fname; fname = fnamebuf;
        while( (*dst++ = *src++) );
        initrc = fopen(fname,"rb");
    }

    if( !initrc && (src=(char*)getenv("RASMOLPATH")) )
    {   dst = fnamebuf; 
        while( *src )
            *dst++ = *src++;
#ifndef VMS
        *dst++ = '/';
#endif

        src = "rasmolrc"; fname = fnamebuf;
        while( (*dst++ = *src++) );
        initrc = fopen(fname,"rb");
    }

    if( initrc )
        LoadScriptFile(initrc,fname);
}

#ifdef XFORMSLIB
static void HandleFileOpen( void )
{
    char *r;

    fl_use_fselector(XFORMS_OPENDIALOG);
    r = (char *)fl_show_fselector("Open Structure file", "", "", "");

    if (r && *r) {
       WriteString("load ");
       WriteString(r);
       WriteChar(' ');
       if ( FetchFile(FormatPDB,False,r) )
               DefaultRepresentation();
       ResetCommandLine(0);
    }
}

static void HandleFileSave( int selector )
{
    char *r;
    struct stat status;
    static char * cmd[] = {
	"pdb",
	"gif",
	"epsf",
	"ppm",
	"iris",
	"ras",
	"bpm",
	"pict"
    };
    static const char * suffix[] = {
	"*.pdb",
	"*.gif",
	"*.epsf",
	"*.ppm",
	"*.rgb",
	"*.ras",
	"*.bpm",
	"*.pict"
    };
    static const char * mesg[] = {
	"Save current molecule as",
	"Save GIF image as",
	"Save EPSF file as",
	"Save PPM image as",
	"Save IRIS image as",
	"Save Raster format as",
	"Save BPM image as",
	"Save PICT file as"
    };

    if (selector < 0 || selector > 7) {
	WriteString("Error: command not supported");
	return;
    }

    fl_use_fselector(XFORMS_SAVEDIALOG);
    do {
        r = (char *)fl_show_fselector(mesg[selector], "", suffix[selector], "");

        if (r == NULL || *r == 0)
		break;

        if (stat(r, &status))
		break;

	if (status.st_mode & S_IFREG) {
		if (fl_show_question("Overwrite existing file?", 0))
			break;
		continue;
	}
	
        fl_show_alert("Following name is directory or used for another purpose:", r, "Please chose another.", 0);
    } while (r);

    if (r && *r) {
       if (selector)
           WriteString("write ");
       else
           WriteString("save ");
       WriteString(cmd[selector]);
       WriteChar(' ');
       WriteString(r);
       WriteChar(' ');
       switch (selector) 
       {   case 1:   WriteGIFFile(r);            break;
           case 2:   WriteEPSFFile(r,True,True); break;
           case 3:   WritePPMFile(r,True);       break;
           case 4:   WriteIRISFile(r);           break;
           case 5:   WriteRastFile(r,True);      break;
           case 6:   WriteBMPFile(r);            break;
           case 7:   WritePICTFile(r);           break;
           default:  SavePDBMolecule(r);
                     break;
       }
       ResetCommandLine(0);
    }
}

#define	MAX_PATH_LEN	256

static void CreateNewFolder(void * name)
{
	char *dir, *parent, *ans;
	long len;

	do {
		ans = (char *)fl_show_input("Create New Folder as:", name);
		if (ans == NULL)
			break;
		if (strlen(ans) < MAX_PATH_LEN)
			break;
		fl_show_alert("Too long", "", "", 0);
	} while (0);

	parent = (char *)fl_get_directory();
	len = strlen(parent) + MAX_PATH_LEN;
	dir = malloc(len);
	if (dir == NULL) {
		fl_show_alert("ERROR:", "NO memory", "", 0);
		return;
	}

	strcpy(dir, parent);
	strcat(dir, "/");
	strcat(dir, ans);

	if (mkdir(dir, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH))
		fl_show_alert("Cannot create", dir, "", 0);
	free(dir);
	fl_refresh_fselector();
}
#endif

static void HandleMenu( int hand )
{
    register int menu;
    register int item;
    register int mask;

    menu = hand>>8;
    item = hand&0xff;
    switch( menu )
    {   case(0):  /* File Menu */
                  switch( item )
                  {   case(1):  /* Open */
                                if( NumMolecules < MAX_MOLECULES )
#ifdef XFORMSLIB
                                    HandleFileOpen();
#else
                                    ResetCommandLine(2);
#endif
                                break;

                      case(2):  /* Save As */
                                if( Database )
#ifdef	XFORMSLIB
                                    HandleFileSave(0);
#else
                                    ResetCommandLine(4);
#endif
                                break;

                      case(3):  /* Close */
                                ZapDatabase();
                                break;

                      case(5):  /* Exit */
                                RasMolExit();
                                break;

                      case(7):  /* Molecule 1 */
                      case(8):  /* Molecule 2 */
                      case(9):  /* Molecule 3 */
                      case(10): /* Molecule 4 */
                      case(11): /* Molecule 5 */
                                SelectMolecule(item-7);
                                break;
                  } 
                  break;

        case(1):  /* Display Menu */
                  switch( item )
                  {   case(1):  /* Wireframe */
                                DisableSpacefill();
                                EnableWireframe(WireFlag,0,0);
                                SetRibbonStatus(False,0,0);
                                DisableBackbone();
                                ReDrawFlag |= RFRefresh;
                                break;

                      case(2):  /* Backbone */
                                DisableSpacefill();
                                DisableWireframe();
                                SetRibbonStatus(False,0,0);
                                EnableBackbone(CylinderFlag,80,64);
                                ReDrawFlag |= RFRefresh;
                                break;

                      case(3):  /* Sticks */
                                DisableSpacefill();
                                if( MainAtomCount<256 )
                                { EnableWireframe(CylinderFlag,40,32);
                                } else {
                                  EnableWireframe(CylinderFlag,80,64);
                                }
                                SetRibbonStatus(False,0,0);
                                ReDrawFlag |= RFRefresh;
                                DisableBackbone();
                                break;

                      case(4):  /* Spheres */
                                SetVanWaalRadius(SphereFlag);
                                DisableWireframe();
                                SetRibbonStatus(False,0,0);
                                DisableBackbone();
                                DrawSurf = False;
                                ReDrawFlag |= RFRefresh;
                                break;

                      case(5):  /* Ball & Stick */
                                SetRadiusValue(120, SphereFlag);
                                EnableWireframe(CylinderFlag,40,32);
                                SetRibbonStatus(False,0,0);
                                DisableBackbone();
                                ReDrawFlag |= RFRefresh;
                                break;

                      case(6):  /* Ribbons */
                                DisableSpacefill();
                                DisableWireframe();
                                SetRibbonStatus(True,RibbonFlag,0);
                                DisableBackbone();
                                ReDrawFlag |= RFRefresh;
                                break;

                      case(7):  /* Strands */
                                DisableSpacefill();
                                DisableWireframe();
                                SetRibbonStatus(True,StrandFlag,0);
                                DisableBackbone();
                                ReDrawFlag |= RFRefresh;
                                break;

                      case(8):  /* Cartoons */
                                DisableSpacefill();
                                DisableWireframe();
                                SetRibbonCartoons();
                                DisableBackbone();
                                ReDrawFlag |= RFRefresh;
                                break;

                      case(9):  /* MolSurf */
                                DrawSurf = True;
                                ProbeRadius = 350;
                                SetVanWaalRadius(SphereFlag | TouchFlag);
                                DisableWireframe();
                                SetRibbonStatus(False,0,0);
                                DisableBackbone();
                                CreateSurfaceBonds();
                                ReDrawFlag |= RFRefresh;
                                break;
                  }
                  break;

        case(2):  /* Colours Menu */
                  switch( item )
                  {   case(1):  /* Monochrome */
                                MonoColourAttrib(255,255,255);
                                ReDrawFlag |= RFColour;  break;
                      case(2):  /* CPK */
                                CPKColourAttrib();
                                ReDrawFlag |= RFColour;  break;
                      case(3):  /* Shapely */
                                ShapelyColourAttrib();
                                ReDrawFlag |= RFColour;  break;
                      case(4):  /* Group */
                                ScaleColourAttrib( GroupAttr );
                                ReDrawFlag |= RFColour;  break;
                      case(5):  /* Chain */
                                ScaleColourAttrib( ChainAttr );
                                ReDrawFlag |= RFColour;  break;
                      case(6):  /* Temperature */
                                ScaleColourAttrib( TempAttr );
                                ReDrawFlag |= RFColour;  break;
                      case(7):  /* Structure */
                                StructColourAttrib();
                                ReDrawFlag |= RFColour;  break;
                      case(8):  /* User */
                                UserMaskAttrib(MaskColourFlag);
                                ReDrawFlag |= RFColour;  break;
                      case(9):  /* Model */
                                ScaleColourAttrib( ModelAttr );
                                ReDrawFlag |= RFColour;  break;
                      case(10): /* Alt */
                                ScaleColourAttrib( AltAttr );
                                ReDrawFlag |= RFColour;  break;
                  }
                  break;

        case(3):  /* Option Menu */
                  switch( item )
                  {   case(1):  /* Slabbing */
                                ReDrawFlag |= RFRefresh;
                                UseSlabPlane = !UseSlabPlane;
                                if( UseSlabPlane )
                                    UseShadow = False;
                                break;

                      case(2):  /* Hydrogens */
                                mask = NormAtomFlag;
                                if( HetaGroups )
                                    mask |= HeteroFlag;
                                Hydrogens = !Hydrogens;
                                ReDrawFlag |= RFRefresh;
                                      
                                if( Hydrogens )
                                {   SelectZone(mask|HydrogenFlag);
                                } else RestrictZone(mask);
                                break;

                      case(3):  /* Hetero Atoms */
                                mask = NormAtomFlag;
                                if( Hydrogens )
                                    mask |= HydrogenFlag;
                                HetaGroups = !HetaGroups;
                                ReDrawFlag |= RFRefresh;
                                
                                if( HetaGroups )
                                {   SelectZone(mask|HeteroFlag);
                                } else RestrictZone(mask);
                                break;

                      case(4):  /* Specular */
                                FakeSpecular = !FakeSpecular;
                                ReDrawFlag |= RFColour;
                                break;

                      case(5):  /* Shadows */
                                ReDrawFlag |= RFRefresh;
                                UseShadow = !UseShadow;
                                if( UseShadow )
                                {   ReviseInvMatrix();
                                    VoxelsClean = False;
                                    UseSlabPlane = False;
                                    ReAllocBuffers();
                                }
                                break;

                      case(6):  /* Stereo */
                                if( UseStereo )
                                {   StereoAngle = -StereoAngle;
                                    if ( StereoAngle > 0.0 ) {
                                      SetStereoMode(False);
                                    } else {
                                       SetStereoMode(True);
                                    }
                                } else SetStereoMode(True);
                                ReDrawFlag |= RFRefresh;
                                break;

                      case(7):  /* Labels */
                                LabelOptFlag = !LabelOptFlag;
                                DefaultLabels(LabelOptFlag);
                                ReDrawFlag |= RFRefresh;
                                break;
                  }
                  break;

        case(4):  /* Settings Menu */
                   switch( item )
                  {   case(1):  /* Pick Off */
                                SetPickMode(PickNone); break;
                      case(2):  /* Pick Ident */
                                SetPickMode(PickIdent); break;
                      case(3):  /* Pick Distance */
                                SetPickMode(PickDist); break;
                      case(4):  /* Pick Monitor */
                                SetPickMode(PickMonit); break;
                      case(5):  /* Pick Angle */
                                SetPickMode(PickAngle); break;
                      case(6):  /* Pick Torsion */
                                SetPickMode(PickTorsn); break;
                      case(7):  /* Pick Label */
                                SetPickMode(PickLabel); break;
                      case(8):  /* Pick Centre */
                                SetPickMode(PickOrign); break;
                      case(9):  /* Pick Coord */
                                SetPickMode(PickCoord); break;
                      case(10): /* Pick Bond */
                                SetPickMode(PickBond); break;
                      case(11): /* Rotate Bond */
                                if ( BondSelected ) {
                                  RotMode = RotBond; break;
                                }
                      case(12): /* Rotate Mol */
                                RotMode = RotMol; UpdateScrollBars(); break;
                      case(13): /* Rotate All */
                                RotMode = RotAll; UpdateScrollBars(); break;
                  }
                  break;

        case(5):  /* Export Menu */
#ifdef	XFORMSLIB
                  HandleFileSave(item);
#else
                  ResetCommandLine(3);
                  StateOption = item;
#endif
                  break;

        case(6):  /* Help Menu */
                  break;
    }
}


void RefreshScreen( void )
{
    if( !UseSlabPlane )
    {   ReDrawFlag &= ~RFTransZ|RFSlab;
    } else ReDrawFlag &= ~RFTransZ;

    if( ReDrawFlag )
    {   if( ReDrawFlag & RFReSize )
            ReSizeScreen();

        if( ReDrawFlag & RFColour )
        {   if( Interactive ) 
                ClearImage();
            DefineColourMap();
        }

        if( Database )
        {   if( Interactive )
                BeginWait();
            if( ReDrawFlag & RFApply ) 
                ApplyTransform();
            DrawFrame();
            if( Interactive )
            {   TransferImage();
                EndWait();
            }
        } else if( Interactive )
        {   ClearBuffers();
            TransferImage();
        }
        ReDrawFlag = 0;
    }
}


#ifdef SOCKETS
static void PrepareIPCAdviseItem( int item )
{
    register char *src, *dst;
    register int i,flag;

    dst = AdviseBuffer;
    src = AdviseMap[item].name;
    while( *src ) *dst++ = *src++;
    *dst++ = ':';  *dst++ = ' ';

    switch( item )
    {   case(AdvPickAtom):
                  if( QAtom )
                  {   src = Residue[QGroup->refno];
                      flag = False;
                      for( i=0; i<3; i++ )
                          if( (src[i]!=' ') && !isalpha(src[i]) )
                              flag = True;

                      if( flag ) *dst++ = '[';
                      for( i=0; i<3; i++ )
                          if( src[i]!=' ' )
                              *dst++ = src[i];
                      if( flag ) *dst++ = ']';
                      sprintf(dst,"%d",QGroup->serno);
                      for( dst=AdviseBuffer; *dst; dst++ );
                      if( QChain->ident!=' ' )
                      {   if( isdigit(QChain->ident) ) *dst++ = ':';
                          *dst++ = QChain->ident;
                      }
                      *dst++ = '.';

                      src = ElemDesc[QAtom->refno];
                      for( i=0; i<4; i++ )
                          if( src[i]!=' ' ) 
                              *dst++ = src[i];
                  }
                  *dst++ = '\n';
                  *dst = '\0';
                  break;

        case(AdvPickNumber):
                  if( !QAtom )
                  {   *dst++ = '\n'; *dst = '\0';
                  } else sprintf(dst,"%ld\n",(long)QAtom->serno);
                  break;

        case(AdvSelectCount):
                  sprintf(dst,"%ld\n",(long)SelectCount);
                  break;
                 
        case(AdvName):
                  src = Info.moleculename;
                  while( *src ) *dst++ = *src++;
                  *dst++ = '\n'; *dst = '\0';
                  break;

        case(AdvPickCoord):
                  if( !QAtom )
                  {   *dst++ = '\n'; *dst = '\0';
                  } else sprintf( dst, "%ld\t%ld\t%ld\n",
                             (long)(QAtom->xorg+QAtom->fxorg),
#ifdef INVERT
                             -(long)(QAtom->yorg+QAtom->fyorg),
#else
                             (long)(QAtom->yorg+QAtom->fyorg),
#endif 
                             -(long)(QAtom->zorg+QAtom->fzorg));
                  break;

        default:  *dst++ = '\n';
                  *dst = '\0';
                  break;
    }
    AdviseLen = strlen(AdviseBuffer)+1;
}
#endif


void AdviseUpdate( int item )
{
#ifdef SOCKETS
    register int mask;
    register int i;

    if( UseSockets )
    {   mask = AdviseMap[item].bitmask;
        if( !mask ) return;

    AdviseLen = 0;
    for( i=0; i<MaxIPCConvNum; i++ )
        if( IPCConvData[i].protocol && (IPCConvData[i].advise&mask) )
        {   if( !AdviseLen ) PrepareIPCAdviseItem(item);
            send(IPCConvData[i].socket,AdviseBuffer,(int)AdviseLen,0);
        }
    }
#endif
}


int ProcessCommand( void )
{
    switch(CurState)
    {   case(1):  /* RasMol Prompt */
                  return( ExecuteCommand() );

        case(2):  /* PDB Filename */
                  if( *CurLine && FetchFile(FormatPDB,False,CurLine) )
                      DefaultRepresentation();
                  ResetCommandLine(1);
                  break;

        case(3):  /* Export Image Filename */
                  if( *CurLine ) switch( StateOption )
                  {   case(1):   WriteGIFFile(CurLine);            break;
                      case(2):   WriteEPSFFile(CurLine,True,True); break;
                      case(3):   WritePPMFile(CurLine,True);       break;
                      case(4):   WriteIRISFile(CurLine);           break;
                      case(5):   WriteRastFile(CurLine,True);      break;
                      case(6):   WriteBMPFile(CurLine);            break;
                      case(7):   WritePICTFile(CurLine);           break;
                  }
                  ResetCommandLine(1);
                  break;

        case(4):  /* Save Molecule Filename */
                  if( *CurLine )
                      SavePDBMolecule(CurLine);
                  ResetCommandLine(1);
                  break;
    }
    return False;
}


static int HandleEvents( int wait )
{
    register int result;

    result = FetchEvent( wait );
    while( ReDrawFlag || result )
    {   if( !result )
        {   if( ReDrawFlag )
                RefreshScreen();
        } else if( !IsPaused )
            HandleMenu( result );
        result = FetchEvent( False );
    }
    return( True );
}


#ifdef PROFILE
static void ProfileExecution( void )
{
#ifdef TIME
    register long start,stop;
#else
    static struct timeval start;
    static struct timeval stop;
    register double secs;
#endif
    register Real delta;
    register int i;

    delta = TwoPi/ProfCount;

    printf("Profiling Execution!\n");

#ifdef TIME
    start = time((time_t *)NULL);
#else
    gettimeofday(&start,(struct timezone *)NULL);
#endif

    for( i=0; i<ProfCount; i++ )
    {   DrawFrame();
        if( Interactive )
            TransferImage();
        ReDrawFlag |= RFRotateY;
        DialValue[1] += delta;
        /* UpdateScrollBars(); */
        ApplyTransform();
    }

#ifdef TIME
    stop = time((time_t *)NULL);
    fprintf(stderr,"Execution of %d frames\n",ProfCount);
    fprintf(stderr,"Duration = %ld seconds\n",stop-start);
#else
    gettimeofday(&stop,(struct timezone *)NULL);
    secs = (stop.tv_sec - start.tv_sec) + (double)
           (stop.tv_usec - start.tv_usec)/1000000.0;
    fprintf(stderr,"Execution of %d frames\n",ProfCount);
    fprintf(stderr,"Duration = %g seconds\n",secs);
#endif
}
#endif


static void InitDefaultValues( void )
{
    Interactive = True;

    FileNamePtr = NULL;
    ScriptNamePtr = NULL;
    InitialWide = DefaultWide;
    InitialHigh = DefaultHigh;
    ProfCount = 0;

    CalcBondsFlag = True;
    CalcSurfFlag = False;
    LabelOptFlag = False;
    FileFormat = FormatPDB;
    AllowWrite = False;

#ifdef SOCKETS
    ServerPort = 21069;
#endif
}


static void DisplayUsage( void )
{
    fputs("usage: rasmol [-nodisplay] [-script scriptfile] ",OutFp);
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
#ifdef VMS
        if( (*ptr=='/') || (*ptr=='-') )
#else
        if( (*ptr=='-') && ptr[1] )
#endif
        {   ptr++;

            if( !strcmp(ptr,"nodisplay") )
            {   Interactive = False;
#ifdef PROFILE
            } else if( !strcmp(ptr,"prof") ||
                       !strcmp(ptr,"profile") )
            {   ProfCount = 200;
#endif
            } else if( !strcmp(ptr,"noconnect") )
            {   CalcBondsFlag = False;
            } else if( !strcmp(ptr,"connect") )
            {   CalcBondsFlag = True;
            } else if( !strcmp(ptr,"insecure") )
            {   AllowWrite = True;
            } else if( !strcmp(ptr,"secure") )
            {   AllowWrite = False;

            } else if( !strcmp(ptr,"script") )
            {   if( i == argc-1 ) DisplayUsage();
                ScriptNamePtr = argv[++i];
            } else if( !strcmp(ptr,"width") ||
                       !strcmp(ptr,"wide") )
            {   if( i == argc-1 ) DisplayUsage();
                InitialWide = atoi(argv[++i]);
                if( InitialWide < 48 )
                {   InitialWide = 48;
                } else if( (j = InitialWide%4) )
                    InitialWide += 4-j;

            } else if( !strcmp(ptr,"height") ||
                       !strcmp(ptr,"high") )
            {   if( i == argc-1 ) DisplayUsage();
                InitialHigh = atoi(argv[++i]);
                if( InitialHigh < 48 )
                    InitialHigh = 48;

#ifdef SOCKETS
            } else if( !strcmp(ptr,"port") )
            {   if( i == argc-1 ) DisplayUsage();
                ServerPort = atoi(argv[++i]);
#endif

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

#ifdef XFORMSLIB
static void InitialiseFSDialogs(void)
{
    FD_FSELECTOR *fs;

    if ( ! Interactive )
	return;

/*  fl_initialize(&argc, argv, VersionStr, 0, 0);  */
    fl_init();

    /* Open File Dialog */
    fl_use_fselector(XFORMS_OPENDIALOG);
    fl_set_fselector_fontsize(XFORMS_FONTSIZE);
    fs = fl_get_fselector_fdstruct();
    fl_set_object_label(fs->ready, "Load");
    fl_fit_object_label(fs->ready, 1, 1);

    /* Save File Dialog */
    fl_use_fselector(XFORMS_SAVEDIALOG);
    fl_set_fselector_fontsize(XFORMS_FONTSIZE);
    fl_add_fselector_appbutton("New Folder", CreateNewFolder, (void *)"Untitled") ;
    fs = fl_get_fselector_fdstruct();
    fl_set_object_label(fs->ready, "Save as");
    fl_fit_object_label(fs->ready, 1, 1);

}
#endif

int main( int argc, char *argv[] )
{
    register FILE *fp;
    register int temp;
    register int done;
    register char ch;
    static char VersionStr[255];
  
    Interactive = False;
    SwitchLang (English);

    sprintf (VersionStr,"%s\nVersion %s %s\n%s\n", 
             MAIN_COPYRIGHT, VERSION, 
             VER_DATE, VER_COPYRIGHT);

    InitDefaultValues();
    ProcessOptions(argc,argv);
    ReDrawFlag = 0;
    
    temp = Interactive;
    setbuf(OutFp,(char *)NULL);
    Interactive = OpenDisplay(InitialWide,InitialHigh);
    InitTerminal(Interactive);

    SwitchLang (English);

    signal(SIGINT,RasMolSignalExit);
    signal(SIGPIPE,SIG_IGN);

    WriteString("RasMol Molecular Renderer\n");
    WriteString("Roger Sayle, August 1995\n");
    WriteString(VersionStr);
    WriteString("*** See \"help notice\" for further notices ***\n");

#ifdef EIGHTBIT
    WriteString("[8-bit version]\n\n");
#else
#ifdef SIXTEENBIT
    WriteString("[16-bit version]\n\n");
#else
    WriteString("[32-bit version]\n\n");
#endif
#endif

    if( !Interactive )
    {   if( temp )
        {   WriteString("No suitable display detected!\n");
        } else WriteString("Display window disabled!\n");
    }

#ifdef XFORMSLIB
    InitialiseFSDialogs();
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
    /* [GSG 11/9/95] Added InitialiseMultiple */
    InitialiseMultiple();
    /* InitialiseToolBar(); */
    InitialiseWBRotate();

#ifdef PROFILE
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

        /* SetVanWaalRadius( SphereFlag); */
        /* CPKColourAttrib();  */

        FakeSpecular = True;
        ScaleColourAttrib(GroupAttr);
        SetRibbonCartoons();
        EnableWireframe(WireFlag,0,0);
        RefreshScreen();

        /* Avoid Pending Events */
        if( Interactive ) 
        {   FetchEvent(False);
            if( ReDrawFlag )
                RefreshScreen();
        }
        ProfileExecution();
        RasMolExit();
    }
#endif

    if( FileNamePtr )
    {   strcpy(DataFileName,FileNamePtr);

        if( !strcmp(FileNamePtr,"-") )
        {   done = ProcessFile(FileFormat,True,stdin);
        } else done = FetchFile(FileFormat,True,FileNamePtr);

        if( done )
        {   DefaultRepresentation();
            RefreshScreen();
        }
    }

    LexState = 0;
    ResetCommandLine(1);

    LoadInitFile();
    if( ScriptNamePtr )
    {   if( !(fp=fopen(ScriptNamePtr,"rb")) )
        {   fprintf(OutFp,"Error: File '%s' not found!\n",ScriptNamePtr);
        } else LoadScriptFile(fp,ScriptNamePtr);
    }

    if( FileNamePtr && !strcmp(FileNamePtr,"-") )
    {   /* Finished Processing after stdin? */
#ifdef TERMIOS
        if( Interactive )
        {   FD_CLR(FileNo,&OrigWaitSet);
            fclose(stdin);
        } else RasMolExit();
#else
        if( !Interactive )
            RasMolExit();
#endif
    }


#ifdef TERMIOS
    done = False;
    while( !done )
    {   ch = ReadCharacter();
        if( ProcessCharacter(ch) )
        {   if( !ProcessCommand() )
            {   RefreshScreen();
            } else done = True;
        }
    }
#else /* !TERMIOS */
    if( Interactive )
    {   /* X Windows Only! */
        while( HandleEvents(True) )
            if( !CommandActive )
                ResetCommandLine(0);
    } else 
    {   done = False;
        while( !done )
        {   /* Command Line Only! */
            ch = ReadCharacter();
            if( ProcessCharacter(ch) )
            {   if( !ProcessCommand() )
                {   RefreshScreen();
                } else done = True;
            }
        }
    }
#endif
    RasMolExit();
    return 0;
}
