/***************************************************************************
 *                              RasMol 2.7.1                               *
 *                                                                         *
 *                                 RasMol                                  *
 *                 Molecular Graphics Visualisation Tool                   *
 *                              22 June 1999                               *
 *                                                                         *
 *                   Based on RasMol 2.6 by Roger Sayle                    *
 * Biomolecular Structures Group, Glaxo Wellcome Research & Development,   *
 *                      Stevenage, Hertfordshire, UK                       *
 *         Version 2.6, August 1995, Version 2.6.4, December 1998          *
 *                   Copyright (C) Roger Sayle 1992-1999                   *
 *                                                                         *
 *                  and Based on Mods by Arne Mueller                      *
 *                      Version 2.6x1, May 1998                            *
 *                   Copyright (C) Arne Mueller 1998                       *
 *                                                                         *
 *           Version 2.7.0, 2.7.1 Mods by Herbert J. Bernstein             *
 *           Bernstein + Sons, P.O. Box 177, Bellport, NY, USA             *
 *                      yaya@bernstein-plus-sons.com                       *
 *                    2.7.0 March 1999, 2.7.1 June 1999                    *
 *              Copyright (C) Herbert J. Bernstein 1998-1999               *
 *                                                                         *
 * Please read the file NOTICE for important notices which apply to this   *
 * package. If you are not going to make changes to RasMol, you are not    *
 * only permitted to freely make copies and distribute them, you are       *
 * encouraged to do so, provided you do the following:                     *
 *   * 1. Either include the complete documentation, especially the file   *
 *     NOTICE, with what you distribute or provide a clear indication      *
 *     where people can get a copy of the documentation; and               *
 *   * 2. Please give credit where credit is due citing the version and    *
 *     original authors properly; and                                      *
 *   * 3. Please do not give anyone the impression that the original       *
 *     authors are providing a warranty of any kind.                       *
 *                                                                         *
 * If you would like to use major pieces of RasMol in some other program,  *
 * make modifications to RasMol, or in some other way make what a lawyer   *
 * would call a "derived work", you are not only permitted to do so, you   *
 * are encouraged to do so. In addition to the things we discussed above,  *
 * please do the following:                                                *
 *   * 4. Please explain in your documentation how what you did differs    *
 *     from this version of RasMol; and                                    *
 *   * 5. Please make your modified source code available.                 *
 *                                                                         *
 * This version of RasMol is not in the public domain, but it is given     *
 * freely to the community in the hopes of advancing science. If you make  *
 * changes, please make them in a responsible manner, and please offer us  *
 * the opportunity to include those changes in future versions of RasMol.  *
 ***************************************************************************/

/* rasmol.h
 */


/*===========================*/
/*  User Definable Options!  */
/*===========================*/

/* #define IBMPC        */
/* #define MSWIN        */
/* #define APPLEMAC     */
/* #define X11WIN       */
#define UNIX

/* #define DIALBOX      */
#define SOCKETS
#define TERMIOS
#define PROFILE
/* #define MITSHM       */

/* #define HAVEZLIB     */
/* #define HAVELIBJPEG  */
/* #define HAVELIBPNG   */

/* #define MMIOLIB      */
/* #define CEXIOLIB     */

#if !defined(EIGHTBIT) && !defined(THIRTYTWOBIT) && !defined(SIXTEENBIT)
/* #define THIRTYTWOBIT */
/* #define SIXTEENBIT   */
/* #define EIGHTBIT     */
#endif


/*========================*/
/*  Default User Options! */
/*========================*/

#ifdef IBMPC
#undef THIRTYTWOBIT
#undef SIXTEENBIT
#endif

#if !defined(EIGHTBIT) && !defined(THIRTYTWOBIT) && !defined(SIXTEENBIT)
#define EIGHTBIT
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


/*==============================*/
/*  Application-wide Constants  */
/*==============================*/

#define MAIN_COPYRIGHT "Copyright (C) Roger Sayle 1992-1999"
#define VERSION "2.7.2.1.1"
#define VER_COPYRIGHT "Copyright (C) Herbert J. Bernstein 1998-1999"
#define VER_DATE "January 2004"


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
#define _fmalloc   malloc
#define _ffree     free
#endif
#define _fstrnicmp strnicmp
#define _fstrcmp   strcmp
#define _fmemset   memset
#define __huge
#define __far
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


void WriteChar( int );
void WriteString( char* );
void WriteMsg( char* );
void RasMolFatalExit( char* );
void AdviseUpdate( int );
void RefreshScreen( void );
void RasMolExit( void );

#ifdef APPLEMAC
#include "rasmac.h"
#endif
