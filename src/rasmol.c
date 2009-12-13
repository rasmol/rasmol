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
/* rasmol.c
 $Log$
 Revision 1.5  2008/03/22 18:42:54  yaya
 Post release cleanup and credit to Ikonen in file headers. -- HJB

 Revision 1.4  2008/03/17 03:01:31  yaya
 Update to agree with 2.7.4.2 release and T. Ikonen GTK mods -- HJB

 Revision 1.4  2008/03/17 01:32:41  yaya
 Add gtk mods by tpikonen, and intergate with 2.7.4.2 mods -- HJB

 Revision 1.3  2008/03/16 22:38:09  yaya
 Update stable release to 2.7.4.2; Update rasmol_install and rasmol_run
 scripts to handle Japanese and Chiness (using cxterm), changing
 Japanese for unix back to EUCJP; and align command line options
 to set initial window size and position to agree between unix and
 windows -- HJB

 Revision 1.3  2008/03/16 22:25:22  yaya
 Align comments with production version; Update rasmol_install and
 rasmol_run shell scripts for Japanese and Chinese; Align logic for
 positioning and sizing initial window with windows version -- HJB

 Revision 1.4  2008/02/21 15:11:46  tpikonen
 Add GTK GUI.

 Revision 1.3  2008/01/30 03:44:00  yaya-hjb
 More post 2.7.4.1 release cleanup -- HJB

 Revision 1.2  2008/01/28 03:29:38  yaya
 Update CVS to RasMol_2.7.4.1 -- HJB

 Revision 1.2  2007/11/19 03:28:39  yaya
 Update to credits for 2.7.4 in manual and headers
 Mask code added -- HJB

 Revision 1.1.1.1  2007/03/01 01:16:33  todorovg
 Chinese working versio from rasmol_ru initial import

 Revision 1.9  2007/02/02 21:08:59  yaya
 Remove // comments for AIX build
 Fix signed length conflict
 Fix array bounds violation for molecule names in multiple.c -- HJB

 Revision 1.8  2006/12/29 04:07:37  yaya
 Update x11win.c and rasmol.c to add links to list of browsers
 and to kill About dialog when the menu bar is selected
 Update rasmol_install.sh to allow recompilation of fonts
 on install to handle openwin and other old systems that
 can't handle byte-swapped bdf files, and add enviroment
 variable RASMOL_NOSPAWN to suppress spawn in intermediate
 xterm from rasmol_run.sh. -- HJB

 Revision 1.7  2006/12/23 23:18:00  yaya
 Detect remote X server that does not share memory
 Add new rasmol_install.sh and rasmol_run.sh scripts -- HJB

 Revision 1.6  2006/12/10 03:32:45  yaya
 Additional updates for linux build with Russian, cleaning
 up X11 font selection for CP1251 and recovering when fonts
 are missing. -- HJB

 Revision 1.5  2006/12/03 02:53:10  yaya
 Clean up compilation warnings in outfile.c
 Mods for about screen under Linux -- HJB

 Revision 1.4  2006/11/29 16:08:10  yaya
 Fix missing raswin.idm in src and missing include of sys/stat.h in rasmol.c
 -- HJB

 Revision 1.3  2006/11/28 03:12:48  yaya
 Changes for Russian and About dialog in unix
 This is a variant tried under Mac OS X.  Changes
 for Linux still needed.  note that more work is
 needed on font selection. -- HJB

 Revision 1.2  2006/09/17 10:53:56  yaya
 Clean up headers and start on code for X11 -- HJB

 Revision 1.1.1.1  2006/09/16 18:45:57  yaya
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
#include <errno.h>


#define RASMOL
#include "rasmol.h"
#include "raswin.idm"
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
#include "script.h"
#include "tokens.h"

#ifdef GTKWIN
#include "gtkwin.h"
#include <gtk/gtk.h>
extern char filaid[];
extern char fillang[];
int initial_ui_elements = UI_MENUS;
#endif

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


#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

static char fpnamebuf[1048];


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
int FileNo;


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

static int firstpass=1;

static char *FileNamePtrs[MAX_MOLECULES];
static char *ScriptNamePtr;
static int FileFormat;
static int ProfCount;
static int LexState;



/*=======================*/
/*  Function Prototypes  */
/*=======================*/

static int HandleEvents( int );
extern int ProcessCommand( void );

void WriteMsg( char *ptr )
{
    WriteString(ptr);
    WriteChar('\n');
}

#ifndef GTKWIN
void WriteChar( int ch )
{
    putc(ch,OutFp);
}


void WriteString( char *ptr )
{
    fputs(ptr,OutFp);
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
#endif /* GTKWIN */


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
    auto unsigned int length;
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
#ifndef GTKWIN
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
#endif //GTKWIN
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
	"PDB",
	"BMP",
	"GIF",
	"IRIS",
	"PPM",
	"RAS",
	"PS",
	"PICT",
	"VectPS",
	"Molscript",
	"Kinemage",
	"POVray3",
	"VRML",
	"RPP",
	"R3D",
	"script"
	
    };
    static const char * suffix[] = {
	"*.pdb",
	"*.bmp",
	"*.gif",
	"*.rgb",
	"*.ppm",
	"*.ras",
	"*.ps",
	"*.pict",
	"*.ps",
	"*.min",
	"*.kin",
	"*.pov",
	"*.vrml",
	"*.rpp",
	"*.r3d",
	"*.scr"
    };
    static const char * mesg[] = {
	"Save current molecule as",
	"Save BMP image as",
	"Save GIF image as",
	"Save IRIS RGB image as",
	"Save PPM image as",
	"Save Sun Raster image as",
	"Save Postscript image as",
	"Save PICT image as",
	"Save Vector PS image as",
	"Save Molscript file as",
	"Save Kinemage file as",
	"Save POVray image as",
	"Save VRML image as",
	"Save Ramachandran file as",
	"Save Raster3D file as",
	"Save RasMol Script file as"
    };

    if (selector < 0 || selector > 15) {
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
       {   case 1:   WriteBMPFile(r);             break;
           case 2:   WriteGIFFile(r);             break;
           case 3:   WriteIRISFile(r);            break;
           case 4:   WritePPMFile(r,True);        break;
           case 5:   WriteRastFile(r,True);       break;
           case 6:   WriteEPSFFile(r,True,True);  break;
           case 7:   WritePICTFile(r);            break;
           case 8:   WriteVectPSFile(r);          break;
           case 9:   WriteMolScriptFile(r);       break;
           case 10:  WriteKinemageFile(r);        break;
           case 11:  WritePOVRay3File(r);         break;
           case 12:  WriteVRMLFile(r,0);          break;
           case 13:  WritePhiPsiAngles(r,-1);     break;
           case 14:  WriteR3DFile(r);             break;
           case 15:  WriteScriptFile(r);          break;
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
	dir = _fmalloc(len);
	if (dir == NULL) {
		fl_show_alert("ERROR:", "NO memory", "", 0);
		return;
	}

	strcpy(dir, parent);
	strcat(dir, "/");
	strcat(dir, ans);

	if (mkdir(dir, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH))
		fl_show_alert("Cannot create", dir, "", 0);
	_ffree(dir);
	fl_refresh_fselector();
}
#endif


/* EnsurePath 

   When possible, ensure the the path for the given file has been
   created.  The path must be in a mutable array, since the
   check is done by progressively changing backshlashes into
   nulls, checking the partial path and then restoring the slash.
*/

static void EnsurePath(char * path) {

  char * ptr;
  
  int quoted;
  int depth;
  
  quoted = 0;
  depth = 0;
  ptr = path;
  
  while (*ptr)  {
    if (*ptr== '"') quoted = 1-quoted;
    if (*ptr == '/' && !quoted) {
      *ptr = '\0';
      depth++;
      if ((depth > 1 || ptr-path > 0 ) && 
         mkdir(path, 
           S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH)) {
        if (errno != EEXIST) {
          WriteString(MsgStrs[StrErrFile]);
          WriteString(path);
          WriteString(MsgStrs[StrNotFnd]);
          *ptr = '/';
          WriteString("in ");
          WriteString(path);
          WriteString("\n");
          break;
        }
      }
      *ptr = '/';
    }
    ptr++;
  }	
  return;
}


/* Determine where the RasMol Application is loaded 

   If the environment variable RASMOLPATH is set, that is used
   Otherwise, if the symbol RASMOLDIR is defined, that is returned.
   Finally, if neither of these are set, the current working directory
   is returned.
*/

static size_t DetermineRasMolPath( char * rpath, size_t maxlen) {

  char * src, * dst;
  
  dst = rpath;
  
  if ((src = (char*)(getenv("RASMOLPATH"))) ) { 
    while(*src && dst-rpath < maxlen-1) { *dst++ = *src++; }
    *dst++ = '\0';
    return dst-rpath-1;	
  }
  
  
#ifdef RASMOLDIR

  src = RASMOLDIR;
  while(*src && dst-rpath < maxlen-1) { *dst++ = *src++; }
  *dst++ = '\0';
  return dst-rpath-1;	
  
#endif
  
  if ( getcwd(rpath,maxlen-2)) {
  
    dst = rpath;
    while (*dst) dst++;
    if( dst !=rpath && *(dst -1) != '\\' ) {
      *dst++ = '\\';
    }
    *dst++ = '\0';
    return dst-rpath-1;
  	
  } else {
  
    return 0;
  	
  }
	
}

/* Determine where the RasMol.flg file is located

   If the environment variable RASMOLFLAGPATH is set, that is used
   Otherwise, $HOME/.rasmol/RasMol.flg is used

*/


static size_t DetermineRasMolFlagPath( char *rfpath, size_t maxlen ) {

  char * src, * dst;
    
  dst = rfpath;
  
  if ((src = (char*)(getenv("RASMOLFLAGPATH"))) ) { 
    while(*src && dst-rfpath < maxlen-1) { *dst++ = *src++; }
    *dst++ = '\0';
    return dst-rfpath-1;	
  }

  if ((src = (char*)(getenv("HOME"))) ) { 
    while(*src && dst-rfpath < maxlen-1) { *dst++ = *src++; }
    src = "/.rasmol/RasMol.flg";
    while(*src && dst-rfpath < maxlen-1) { *dst++ = *src++; }
    *dst++ = '\0';
    return dst-rfpath-1;	
  }

  return 0;
}

/*  Launch a particular browser with a URL
    attempts to launch a browser with the URL as an argument
    
    Tries the browser in the given argument string.
    The string is parsed left to right using the substrings
    delimited by colons as trial browser execution commands.  Each trial
    browser command string is scanned for a "$".  if a "$" is found, the
    URL is put in place of the $.  If not, the trial browser with the URL
    appended is inserted into a command string of the form
    
        which browser > /dev/null 2>&1 &&(browser URL > /dev/null 2>&1 &);exit
        
    A literal $ may be included if elided with a backslash.
    
    Note that RasMol will block until the system call returns, so it
    is important to place the spawned browser in the background and
    to exit from the command string.
    
    */

static int LaunchThisBrowserWithURL(const char * browser, const char * URL) {

  char browsercmd[1026];
  register char * src, *dst, *url, *xbrowser, *tail ;
  int charcnt, nodollar, status;
  
  src = (char *)browser;
  
  while(*src){

    dst = browsercmd;
    status = -1;
    charcnt = 0;
    nodollar = 1;
    xbrowser = src;

    while(*src && *src != ':' && charcnt < 1024) {
      if (*src == '$' && (charcnt==0 || *(src-1) != '\\') ) {
        nodollar = 0;
        url = (char *)URL;
        while (*url && charcnt < 1024) { *dst++ = *url++; charcnt++;}
        src++;
      continue;
      } else {
        *dst++ = *src++; charcnt++;
      }
    }
    if (nodollar && src-browser > 0 && charcnt+charcnt+18+34< 1024) {
      charcnt = 0;
      dst =  browsercmd;
      tail = "which ";
      while (*tail && charcnt < 1024) { *dst++ = *tail++; charcnt++;}
      tail = xbrowser;
      while (*tail && charcnt < 1024 && *tail != ':') { *dst++ = *tail++; charcnt++;}
      tail = "> /dev/null 2>&1 &&(";
      while (*tail && charcnt < 1024) { *dst++ = *tail++; charcnt++;}
      tail = xbrowser;
      while (*tail && charcnt < 1024 && *tail != ':') { *dst++ = *tail++; charcnt++;}
      charcnt = strlen(browsercmd);
      *dst++ = ' ';
      charcnt++;
      url = (char *)URL;
      while (*url && charcnt < 1024-9-17) { *dst++ = *url++; charcnt++;}
      tail = "> /dev/null 2>&1 &);exit;";
      while (*tail && charcnt < 1024) { *dst++ = *tail++; charcnt++;}
        	  
    }
    *dst = '\0';
    if(strlen(browsercmd) > strlen(URL)+1)  {
      status = system(browsercmd);
      if (!status) return 0;
      InvalidateCmndLine();
      WriteString(MsgStrs[StrWarn]);
      WriteString("'");
      WriteString(browsercmd);
      WriteString(MsgStrs[StrNotFnd]);
      if (WTERMSIG(status) == SIGINT || WTERMSIG(status) == SIGQUIT) break;
    }
    src++;
  }
  return -1;
}


/*  Launch a Browser with a URL
    attempts to launch a browser with the URL as an argument
    
    Tries several browsers in turn:
    
      First from the value of the environment variable RASMOL_BROWSER
      Second from the value of the environment variable BROWSER
      Third from the value of preprocessor variable RASMOL_BROWSER
      if defined, or from the string
       
"which open > /dev/null 2>&1&&(open $ > /dev/null 2>&1);exit:mozilla:firefox:opera:safari:netscape"

concatenated with the string

":which links > /dev/null 2&1&&(xterm -e links $ &) >/dev/null 2>1);exit" 

    In all cases, the string is parsed left to right using the substrings
    delimited by colons as trial browser execution commands.  Each trial
    browser command string is scanned for a "$".  if a "$" is found, the
    URL is put in place of the $.  If not, the trial browser with the URL
    appended is inserted into a command string of the form
    
        which browser&&(browser URL & > /dev/null 2>&1);exit
        
    A literal $ may be included if elided with a backslash.
    
    Note that RasMol will block until the system call returns, so it
    is important to place the spawned browser in the background and
    to exit from the command string.
    
    */

static int LaunchBrowserWithURL( const char * URL ) {

  char * trial;
  
  if ((trial=getenv("RASMOL_BROWSER"))) {
  	if (!LaunchThisBrowserWithURL(trial,URL)) return 0;
  }
  if ((trial=getenv("BROWSER"))) {
  	if (!LaunchThisBrowserWithURL(trial,URL)) return 0;
  }
  return LaunchThisBrowserWithURL(
#ifdef RASMOL_BROWSER
  RASMOL_BROWSER
#else
"which open > /dev/null 2>&1&&(open $ > /dev/null 2>&1);exit:mozilla:firefox:opera:safari:netscape"
":which links > /dev/null 2&1&&(xterm -e links $ &) >/dev/null 2>1);exit" 
#endif
  ,URL);
}

static void HelpScreen( void ) {
  if (LaunchBrowserWithURL("http://www.rasmol.org/help.shtml")) 
  {  InvalidateCmndLine();
     WriteString("'");
     WriteString("http://www.rasmol.org/help.shtml"); 
     WriteString(MsgStrs[StrNotFnd]);
  }
  return;
}

static void Register( void ) {
  if (LaunchBrowserWithURL("http://www.rasmol.org/register.shtml"))
     HelpScreen();
  return;
}

static void Donate( void ) {
  if (LaunchBrowserWithURL("http://www.rasmol.org/donate.shtml"))
     HelpScreen();
  return;
}


size_t DetermineApplicationIdentifier( char * aid, size_t maxlen ) {

  char macname[255];
  
  char *src, *dst;
  size_t curlen;
  
  dst = aid;
  curlen = 0;
  
  src = "RasMol_";
  while (*src && curlen < maxlen-1 ) {*dst++ = *src++; curlen++;}
  src = VERSION;
  while (*src && curlen < maxlen-1 ) {*dst++ = *src++; curlen++;}
  
  if (curlen < maxlen-1) {*dst++ = '_'; curlen++;}
  
  if (gethostname(macname,255)) {
    src = macname;
  	while (*src && curlen < maxlen-1 && (src-macname)<255 ) {
  	  *dst++ = *src++; curlen++;
  	}
  }
  
  if (curlen >= maxlen) return 0;
  *dst++ = '\0';
  
  return dst-aid;
	
}

int getraid ( char * aid, size_t maxlen, char * langstr, size_t maxlstr) {

  FILE *fraid;
  size_t count, ncount;
  size_t lenread;

  if (DetermineRasMolFlagPath(fpnamebuf,1047)) {
    
    EnsurePath(fpnamebuf);
    fraid = fopen(fpnamebuf,"r");
    
    if (fraid
      && (lenread=fread(aid,1,maxlen,fraid)) ) {
      count = 0;
      while (*aid && count<maxlen-1 && count < lenread) {
        if (*aid=='\n' || *aid=='\r') break;
      	count++;
      	aid++;
      }
      if (count < lenread && (*aid == '\n' || *aid == '\r')) {
        *aid++ = '\0';
        count++;
        ncount = 0;
        if (count < maxlen-1 && count < lenread && *aid=='\n') {
          aid++;
          count++;
        }
        while(*aid && count < maxlen-1 && ncount < maxlstr-1 && count < lenread) {
          if(*aid == '\n' || *aid == '\r') break;
          *langstr++ = *aid++;
          count++;
          ncount++;
        }
        *langstr++ = '\0';
      } else  {
      	*aid++ = '\0';
      }
      
      fclose(fraid);
      return count;
    }

    if (fraid ) fclose(fraid);
  	
  }

  *aid = '\0';
  return 0;
	
}

int setraid ( const char * aid, const char * langstr ) {

  FILE *fraid;
  size_t lenwritten;
  
  lenwritten = 0;
  if (DetermineRasMolFlagPath(fpnamebuf,1047)) {

      EnsurePath(fpnamebuf);
  
    fraid = fopen(fpnamebuf,"w+");
          
    if (fraid)  {
      lenwritten=fwrite(aid,1,strlen(aid),fraid);
      lenwritten+=fwrite("\n",1,1,fraid);
      lenwritten+=fwrite(langstr,1,strlen(langstr)+1,fraid);
      fclose(fraid);
      return lenwritten;
    }
  	
  }
  return lenwritten;
}

void HandleMenu( int hand )
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
                   switch( item ) {   
                      case(1):   /* About RasMol */
                        DisplayAboutDLG(); break;
                      case(2):   /* User Manual  */
                        HelpScreen(); break;
                      case(3):   /* Register     */
                        Register(); break;
                      case(4):   /* Donate       */
                        Donate(); break;
                  }
                  break;
#ifndef GTKWIN
    	case(7):  /* About Dialog  */
    	           if (AboutDLG[item-1].DLGtype==DLGCHECKBOX) {    	           	  
                       AboutDLG[item-1].status = (AboutDLG[item-1].status)?0:1;
    	               DrawAboutDLG(); break;
       	           } else {
       	           	  if (AboutDLG[item-1].DLGtype==DLGPUSHBUTTON) {
       	           	    AboutDLG[item-1].status = (AboutDLG[item-1].status)?0:1;
       	           	    DrawAboutDLG();
       	           	    switch ( AboutDLG[item-1].Identifier) {
       	           	      case (IDD_OK):
       	           	        AboutDLG[item-1].status = 0;
       	           	        UnDisplayAboutDLG();
       	           	        break;
       	           	      case (IDM_REGISTER):
       	           	        Register(); 
       	           	        AboutDLG[item-1].status = (AboutDLG[item-1].status)?0:1;
       	           	        DrawAboutDLG();
       	           	        break;
       	           	      case (IDM_DONATE):  
       	           	        Donate();
       	           	        AboutDLG[item-1].status = (AboutDLG[item-1].status)?0:1;
       	           	        DrawAboutDLG();
       	           	        break;
       	           	    }
       	
       	           	  }
       	           }
		   break;
#endif /* GTKWIN */
    }
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
        {   if( Interactive ) 
                ClearImage();
            DefineColourMap();
        }
        
          NextReDrawFlag = 0;
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
	  if ((ReDrawFlagSave & RFApply) && record_on[0] && !RecordPause) {
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
	      	record_frame[1] = 0;
	      }
	  } 
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
                  {   case(1):    WriteBMPFile(CurLine);            break;
                      case(2):    WriteGIFFile(CurLine);            break;
                      case(3):    WriteIRISFile(CurLine);           break;
                      case(4):    WritePPMFile(CurLine,True);       break;
                      case(5):    WriteRastFile(CurLine,True);      break;
                      case(6):    WriteEPSFFile(CurLine,True,True); break;
                      case(7):    WritePICTFile(CurLine);           break;
                      case(8):    WriteVectPSFile(CurLine);         break;
                      case(9):    WriteMolScriptFile(CurLine);      break;
                      case(10):   WriteKinemageFile(CurLine);       break;
                      case(11):   WritePOVRay3File(CurLine);        break;
                      case(12):   WriteVRMLFile(CurLine,0);         break;
                      case(13):   WritePhiPsiAngles(CurLine,-1);     break;
                      case(14):   WriteR3DFile(CurLine);            break;
                      case(15):   WriteScriptFile(CurLine);         break;
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

    NextReDrawFlag = 0;
    result = FetchEvent( wait );
    while( ReDrawFlag || result )
    {   if( !result )
        {   if( ReDrawFlag )  {
              RefreshScreen();
              ReDrawFlag = NextReDrawFlag;
            }
                
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
    int i;

    for(i = 0; i < MAX_MOLECULES; i++) {
        FileNamePtrs[i]= NULL;
    }
    ScriptNamePtr = NULL;
    InitWidth = InitHeight = InitXPos = InitYPos = 0;
    ProfCount = 0;

    CalcBondsFlag = True;
    CalcSurfFlag = False;
    LabelOptFlag = False;
    FileFormat = FormatPDB;
    AllowWrite = False;
#ifdef GRAPHICS
    RepDefault = REP_WIREFRAME;
    ColDefault = CPKTok;
#endif
#ifdef SOCKETS
    ServerPort = 21069;
#endif
}


static void DisplayUsage(int retval)
{
    fputs("usage: rasmol [-nodisplay] [-script scriptfile] ", OutFp);
    fputs("[[-format] file]\n    formats: -cif -pdb -nmrpdb ", OutFp);
    fputs("-mopac -mdl -mol2 -xyz -alchemy -charmm\n\n", OutFp);
    exit(retval);
}


#define FORMATOPTMAX   17
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
            { "sybyl",      FormatMol2     },
            { "mopac",      FormatMOPAC    },
            { "nmrpdb",     FormatNMRPDB   },
            { "pdbnmr",     FormatNMRPDB   },
            { "pdb",        FormatPDB      },
            { "shelx",      FormatSHELX    },
            { "xyz",        FormatXYZ      }
                                };
    
static void ProcessOptions( int argc, char *argv[] )
{
    register char *ptr;
    register int i, j, argok, nfiles;
    register language klang;

    nfiles = 0;
    for( i=1; i<argc; i++ )
    {   ptr = argv[i];
#ifdef VMS
        if( (*ptr=='/') || (*ptr=='-') ) {
#else
        if( (*ptr=='-') && ptr[1] ) {
#endif
            ptr++;
            if (*ptr=='-')
                ptr++;

            if (!strcasecmp(ptr, "nodisplay")) {
                Interactive = False;
#ifdef PROFILE
            } else if (!strcasecmp(ptr, "prof") || !strcasecmp(ptr, "profile")) {
                ProfCount = 200;
#endif
            } else if (!strcasecmp(ptr, "help")) {
                DisplayUsage(0);
            } else if (!strcasecmp(ptr, "version")) {
                fprintf (OutFp, "%s\nVersion %s %s\n%s\n",
                        MAIN_COPYRIGHT, VERSION,
                        VER_DATE, VER_COPYRIGHT);
            } else if (!strcasecmp(ptr, "noconnect")) {
                CalcBondsFlag = False;
            } else if (!strcasecmp(ptr, "connect")) {
                CalcBondsFlag = True;
            } else if (!strcasecmp(ptr, "insecure")) {
                AllowWrite = True;
            } else if (!strcasecmp(ptr, "secure")) {
                AllowWrite = False;
            } else if (!strcasecmp(ptr, "script")) {
                if (i == argc - 1)
                    DisplayUsage(1);
                ScriptNamePtr = argv[++i];
            } else if (!strcasecmp(ptr, "wireframe")) {
                RepDefault = REP_WIREFRAME;
            } else if (!strcasecmp(ptr, "backbone")) {
                RepDefault = REP_BACKBONE;
            } else if (!strcasecmp(ptr, "sticks")) {
                RepDefault = REP_STICKS;
            } else if (!strcasecmp(ptr, "spacefill")) {
                RepDefault = REP_SPHERES;
            } else if (!strcasecmp(ptr, "spheres")) {
                RepDefault = REP_SPHERES;
            } else if (!strcasecmp(ptr, "ballstick")) {
                RepDefault = REP_BALLSTICK;
            } else if (!strcasecmp(ptr, "ribbons")) {
                RepDefault = REP_RIBBONS;
            } else if (!strcasecmp(ptr, "strands")) {
                RepDefault = REP_STRANDS;
            } else if (!strcasecmp(ptr, "cartoons")) {
                RepDefault = REP_CARTOONS;
            } else if (!strcasecmp(ptr, "color") || !strcasecmp(ptr, "colour")) {
                char *p;
                if (i == (argc - 1))
                    DisplayUsage(1);
                p = argv[++i];
                if(!strcasecmp(p, "monochrome")) {
                    ColDefault = WhiteTok;
                } else if(!strcasecmp(p, "alt")) {
                    ColDefault = AltlTok;
                } else if(!strcasecmp(p, "amino")) {
                    ColDefault = AminoTok;
                } else if(!strcasecmp(p, "chain")) {
                    ColDefault = ChainTok;
                } else if(!strcasecmp(p, "charge")) {
                    ColDefault = ChargeTok;
                } else if(!strcasecmp(p, "cpk")) {
                    ColDefault = CPKTok;
                } else if(!strcasecmp(p, "cpknew")) {
                    ColDefault = CpkNewTok;
                } else if(!strcasecmp(p, "group")) {
                    ColDefault = GroupTok;
                } else if(!strcasecmp(p, "model")) {
                    ColDefault = ModelTok;
                } else if(!strcasecmp(p, "shapely")) {
                    ColDefault = ShapelyTok;
                } else if(!strcasecmp(p, "structure")) {
                    ColDefault = StructureTok;
                } else if(!strcasecmp(p, "temperature")) {
                    ColDefault = TemperatureTok;
                } else if(!strcasecmp(p, "user")) {
                    ColDefault = UserTok;
                } else {
                    fprintf(OutFp, "Unknown colour definition\n");
                }
#ifdef GTKWIN
            } else if (!strcasecmp(ptr, "prompt")) {
                initial_ui_elements |= UI_COMMAND;
            } else if (!strcasecmp(ptr, "noprompt")) {
                initial_ui_elements &= ~UI_COMMAND;
            } else if (!strcasecmp(ptr, "scrollbars")) {
                initial_ui_elements |= UI_SCROLLS;
            } else if (!strcasecmp(ptr, "noscrollbars")) {
                initial_ui_elements &= ~UI_SCROLLS;
            } else if (!strcasecmp(ptr, "menu")) {
                initial_ui_elements |= UI_MENUS;
            } else if (!strcasecmp(ptr, "nomenu")) {
                initial_ui_elements &= ~UI_MENUS;
            } else if (!strcasecmp(ptr, "fullscreen")) {
                initial_ui_elements |= UI_FULLSCREEN;
#endif /* GTKWIN */
            } else if (!strcasecmp(ptr, "width") || !strcasecmp(ptr, "wide")) {
                if (i == argc - 1)
                    DisplayUsage(1);
                InitWidth = atoi(argv[++i]);
                if (InitWidth < 48) {
                    InitWidth = 48;
                } else if ((j = InitWidth % 4))
                    InitWidth += 4 - j;
            } else if (!strcasecmp(ptr, "height") || !strcasecmp(ptr, "high")) {
                if (i == argc - 1)
                    DisplayUsage(1);
                InitHeight = atoi(argv[++i]);
                if (InitHeight < 48)
                    InitHeight = 48;
            } else if (!strcasecmp(ptr, "xpos")) {
                if (i == argc - 1)
                    DisplayUsage(1);
                InitXPos = atoi(argv[++i]);
            } else if (!strcasecmp(ptr, "ypos")) {
                if (i == argc - 1)
                    DisplayUsage(1);
                InitYPos = atoi(argv[++i]);
#ifdef SOCKETS
            } else if (!strcasecmp(ptr, "port")) {
                if (i == argc - 1)
                    DisplayUsage(1);
                ServerPort = atoi(argv[++i]);
#endif
#ifdef CEXIOLIB
            } else if (!strcasecmp(ptr, "cex")) {
                FileFormat = FormatCEX;
#endif

            } else {
                argok = False;
                /* Languages */
                for (klang=(language)0; klang < NUMLANGS; klang++) {
                    if (!strcasecmp(ptr+1,lang2str(klang))) {
                        Language = klang;
                        argok = True;
                        break;
                    }
                }
                if (argok) continue;
                /* File Formats! */
                for( j=0; j<FORMATOPTMAX; j++ )
                    if( !strcasecmp(ptr,FormatOpt[j].ident) ) {
                        FileFormat = FormatOpt[j].format;
                        break;
                    }
                if( j==FORMATOPTMAX )
                    DisplayUsage(1);
            }
        } else
            if( nfiles < MAX_MOLECULES )
            {   FileNamePtrs[nfiles++] = ptr;
            } else DisplayUsage(1);
    }
}

#ifdef XFORMSLIB
static void InitialiseFSDialogs(void)
{
    FD_FSELECTOR *fs;
    int dummycount=1;
    char * dummyargv="rasmol";

    if ( ! Interactive )
	return;

/*  fl_initialize(&argc, argv, VersionStr, 0, 0);  */
    fl_initialize(&dummycount,&dummyargv,dummyargv,0,0);

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

#ifdef GTKWIN
language bestlang( void ) 
{
    return English;
}
#else
language bestlang( void ) 
{

    language mylang;
    char * lang, * lc_all, * lctest;
    
    mylang = English;
    
    if (getraid(filaid, 1025, fillang, 81) &&
      strlen(fillang) > 0 ) {
      return str2lang(fillang);
    }
    
    lang = getenv("LANG");
    lc_all = getenv("LC_ALL");
	
	lctest = lang;
    if (lc_all)  lctest = lc_all;
    
    if (lctest)  {
    
      if (!strncasecmp(lctest,"fr",2)) mylang = French;
      if (!strncasecmp(lctest,"it",2)) mylang = Italian;
      if (!strncasecmp(lctest,"de",2)) mylang = German;
      if (!strncasecmp(lctest,"en",2)) mylang = English;
      if (!strncasecmp(lctest,"es",2)) mylang = Spanish;
      if (!strncasecmp(lctest,"ru",2)) mylang = Russian;
      if (!strncasecmp(lctest,"bg",2)) mylang = Bulgarian;
      if (!strncasecmp(lctest,"cn",2)) mylang = Chinese;
      if (!strncasecmp(lctest,"jp",2)) mylang = Japanese;
    	
    }
        
    return mylang;
    
}
#endif /* GTKWIN */

void UpdateLanguage( void ) {

    getraid(filaid, 1025, fillang, 81);
    setraid(filaid,lang2str(Language));
}



int main( int argc, char *argv[] )
{
    register FILE *fp;
    register int temp;
    register int done;
    register char ch;
    static char VersionStr[255];
    int i, read_from_stdin;
  
    Interactive = False;
	TermLanguage = English;
    SwitchLang (bestlang());

    sprintf (VersionStr,"%s\nVersion %s %s\n%s\n", 
             MAIN_COPYRIGHT, VERSION, 
             VER_DATE, VER_COPYRIGHT);

    InitDefaultValues();
#ifdef GTKWIN
    gtk_init(&argc, &argv);
#endif    
    ProcessOptions(argc,argv);
    ReDrawFlag = 0;
#ifdef GTKWIN
    temp = True;
    Interactive = True;
#else	
    temp = Interactive;
    setbuf(OutFp,(char *)NULL);
#endif
    Interactive = OpenDisplay();
    InitTerminal(Interactive);
#ifdef GTKWIN
    set_ui_elements(initial_ui_elements);
#endif
    SwitchLang (Language);
 
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
    {
      /* Only use the first filename arg when profiling */
      if( FileNamePtrs[0] )
        {   strcpy(DataFileName,FileNamePtrs[0]);

            if( strcmp(FileNamePtrs[0],"-") )
            {   done = FetchFile(FileFormat,True,FileNamePtrs[0]);
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
        ReDrawFlag = NextReDrawFlag;

        /* Avoid Pending Events */
        if( Interactive ) 
        {   FetchEvent(False);
            if( ReDrawFlag ) {
            	RefreshScreen();
                ReDrawFlag = NextReDrawFlag;
            }
                
        }
        ProfileExecution();
        RasMolExit();
    }
#endif

    i = 0;
    read_from_stdin = False;
    while( i < MAX_MOLECULES && FileNamePtrs[i] )
    {   strcpy(DataFileName,FileNamePtrs[i]);

        if( !strcmp(FileNamePtrs[i],"-") ) {
            done = FetchStdin(FileFormat);
            read_from_stdin = True;
        } else
            done = FetchFile(FileFormat,True,FileNamePtrs[i]);

        if( done )
        {
#ifdef GTKWIN
            char tmp[PATH_MAX+10];

            strcpy(tmp, "file://");
            if(realpath(FileNamePtrs[i], tmp+7)) {
                gtk_recent_manager_add_item(gtk_recent_manager_get_default(),
                                            tmp);
            }
#endif // GTKWIN
            DefaultRepresentation();
            RefreshScreen();
            ReDrawFlag = NextReDrawFlag;
        }
        i++;
    }

    LexState = 0;
    ResetCommandLine(1);

    LoadInitFile();
    if( ScriptNamePtr )
    {   if( !(fp=fopen(ScriptNamePtr,"rb")) )
        {   fprintf(OutFp,"Error: File '%s' not found!\n",ScriptNamePtr);
        } else LoadScriptFile(fp,ScriptNamePtr);
    }

    if( read_from_stdin )
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

#ifdef GTKWIN
	if( Interactive ) {
		gtk_main();
	}
	else 
	{   done = False;
    	while( !done )
        {   /* Command Line Only! */
            ch = ReadCharacter();
            if( ProcessCharacter(ch) )
            {   if( !ProcessCommand() )
                {   RefreshScreen();
                    ReDrawFlag = NextReDrawFlag;
                } else done = True;
            }
        }
    }	
#else
    if (Interactive) {
      if (firstpass) {
        firstpass = 0;
        if (!(getraid(filaid, 1025, fillang, 81)
          && DetermineApplicationIdentifier(macaid, 1025)
          && !strncasecmp(filaid,macaid,1024)) ){
          DisplayAboutDLG();
        }
      }           
    }

#ifdef TERMIOS
    done = False;
    while( !done )
    {   ch = ReadCharacter();
        if( ProcessCharacter(ch) )
        {   if( !ProcessCommand() )
            {   RefreshScreen();
                ReDrawFlag = NextReDrawFlag;
            } else done = True;
        }
    }
#else /* !TERMIOS */
    if( Interactive )
#ifdef X11WIN
    {   /* X Windows Only! */
        while( HandleEvents(True) )
            if( !CommandActive )
                ResetCommandLine(0);
    } else
#endif 	
    {   done = False;
        while( !done )
        {   /* Command Line Only! */
            ch = ReadCharacter();
            if( ProcessCharacter(ch) )
            {   if( !ProcessCommand() )
                {   RefreshScreen();
                    ReDrawFlag = NextReDrawFag;
                } else done = True;
            }
        }
    }
#endif /* TERMIOS */
    RasMolExit();
#endif /* GTKWIN */
    return 0;
}
