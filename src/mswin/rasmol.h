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
/* rasmol.h
 */


/*===========================*/
/*  User Definable Options!  */
/*===========================*/

#define IBMPC
#define MSWIN
/* #define APPLEMAC     */
/* #define X11WIN       */
/* #define UNIX         */

/* #define DIALBOX      */
/* #define SOCKETS      */
#define TERMIOS
#define PROFILE
#define MITSHM

/* #define HAVEZLIB     */
/* #define HAVELIBJPEG  */
/* #define HAVELIBPNG   */

/* #define HPUX_LEGACY  */     /* define this for old-style hpux select */

/* #define MMIOLIB      */
/* #define CEXIOLIB     */

#if !defined(EIGHTBIT) && !defined(THIRTYTWOBIT) && !defined(SIXTEENBIT)
/* #define THIRTYTWOBIT */
/* #define SIXTEENBIT   */
/* #define EIGHTBIT     */
#endif

/* #define XPROCARCH    */
/* #define USE_UNAME    */

#define USE_CBFLIB

#if !defined(IBMPC)

#ifndef CNEARTREE_FAR
#define CNEARTREE_FAR 
#endif

#ifndef VECTOR_FAR
#define VECTOR_FAR 
#endif

#endif

/*========================*/
/*  Default User Options! */
/*========================*/

#ifdef IBMPC
#undef SIXTEENBIT
#endif

#if !defined(EIGHTBIT) && !defined(THIRTYTWOBIT) && !defined(SIXTEENBIT)
#define THIRTYTWOBIT
#endif

#ifndef RASMOLDIR
#ifdef IBMPC
#define RASMOLDIR  "C:\\RASWIN\\"
#endif

#if !defined(IBMPC) && !defined(APPLEMAC) && !defined(VMS)
#define RASMOLDIR "/usr/local/lib/rasmol/"
#endif
#endif

#if !defined(INVERT) && defined(IBMPC)
#define INVERT
#endif

#if !defined(TIME) && defined(VMS)
#define TIME
#endif

/*===============================*/
/*  Fix for acos/asin problems   */
/*===============================*/

#include <math.h>
#ifdef asin
#undef asin
#endif
#ifdef acos
#undef acos
#endif

#define acos(x) (atan2(sqrt(1.-(x)*(x)),(x)))
#define asin(x) (atan2((x),sqrt(1.-(x)*(x))))

/*===============================*/
/*  Fix for rint VMS problems    */
/*===============================*/

#ifdef VMS
#ifndef rint
#define rint(x) ((x)>0?floor((x)+.5):-floor(.5-(x)))
#endif
#endif

/*==============================*/
/*  Application-wide Constants  */
/*==============================*/

#define MAIN_COPYRIGHT "Copyright (C) Roger Sayle 1992-1999"
#define VERSION "2.7.5.2"
#define VER_COPYRIGHT "Copyright (C) Herbert J. Bernstein 1998-2011"
#define VER_DATE "May 2011"

#ifndef True
#define True  1
#define False 0
#endif

#ifndef PI   /* Avoid Linux Warnings! */
#define PI   3.14159265358979323846
#endif


typedef double Real;
#ifndef APPLEMAC
typedef unsigned char Byte;
#endif

#ifdef __STDC__
typedef signed char Char;
#else
typedef char Char;
#endif

#ifdef _LONGLONG
typedef unsigned int Card;
typedef int Long;
#else
typedef unsigned long Card;
typedef long Long;
#endif

#ifdef EIGHTBIT
typedef unsigned char Pixel;
#else
#ifdef THIRTYTWOBIT
typedef Long Pixel;
#else
typedef short Pixel;
#endif
#endif


#if defined(__sgi)
#define UnusedArgument(x)  ((x)=(x))
#else
#define UnusedArgument(x)
#endif


#define Rad2Deg      (180.0/PI)
#define Deg2Rad      (PI/180.0)
#define AbsFun(a)    (((a)<0)? -(a) : (a))
#define MinFun(a,b)  (((a)<(b))? (a) : (b) )
#define MaxFun(a,b)  (((a)>(b))? (a) : (b) )

#if defined(__STDC__) || defined(IBMPC)  || defined(APPLEMAC) || defined(__sgi)
#define ToUpper(x)   (toupper((x)))
#else
#define ToUpper(x)   (islower((x))?toupper((x)):(x))
#endif


#if !defined(IBMPC) || defined(_WIN32)
#ifdef APPLEMAC
#define _fmalloc   NewPtrSys
#define _ffree(x)  DisposePtr((Ptr)(x))
#else
#include <stdlib.h>
#define _fmalloc   malloc
#define _ffree     free
#endif
#define _fstrnicmp strnicmp
#define _fstrcmp   strcmp
#define _fmemset   memset
#define __huge
#define __far
#else
#ifdef USE_CBFLIB
#define _fmalloc   halloc
#define _ffree     hfree
#define __far      __huge
#endif
#endif


#define ItemCount       8
#define AdvPickAtom     0
#define AdvPickNumber   1
#define AdvSelectCount  2
#define AdvName         3
#define AdvIdent        4
#define AdvClass        5
#define AdvImage        6
#define AdvPickCoord    7


#define MSG_MAX 256
void WriteChar( int );
void WriteString( char* );
void WriteMsg( char* );
void RasMolFatalExit( char* );
void AdviseUpdate( int );
void RefreshScreen( void );
void RasMolExit( void );
#if !defined(IBMPC)
void HandleMenu( int hand );
#endif

#ifdef APPLEMAC
#include "rasmac.h"
#endif
