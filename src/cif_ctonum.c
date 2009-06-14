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
/**********************************************************************
 *  cif_ctonum.c                                                      *
 *                                                                    *
 *  routine to convert a string to a number and esd                   *
 *  derived in large part from ctonum in ciftbx.f from CIFtbx 2 by    *
 *  by S. R. Hall and H. J. Bernstein                                 *
 *                                                                    *
 *  Herbert J. Bernstein                                              *
 *  Bernstein + Sons, P.O. Box 177, Bellport, NY 11713                *
 *  yaya@bernstein-plus-sons.com                                      *
 *                                                                    *
 *  Rev, 1 Sep 98, 19 Feb 99                                          *
 **********************************************************************/

/**********************************************************************
 *  SYNOPSIS                                                          *
 *                                                                    *
 *  #include "cif_ctonum.h"                                           *
 *                                                                    *
 *  int cif_ctonum(char __far *strg, int slong, double __far *number, *
 *    double __far *stddev, char __far *type,                         *
 *    int __far *posdec, int __far *esddig, int __far *lzero,         *
 *    int __far *decp, int __far (*cif_warn) (char __far *msg) )      *
 *                                                                    *
 *  DESCRIPTION                                                       *
 *                                                                    *
 *  Converts a character string into a number and its esd.  The       *
 *  arguments are:                                                    *
 *       strg   - pointer to a null terminated string of the form:    *
 *                                                                    *
 *                                          Q                         *
 *                                          D+                        *
 *                                          E-                        *
 *                                +         +                         *
 *           number string        -xxxx.xxxx-xxx(x)                   *
 *           component count ccnt 11111222223333444                   *
 *           (with at least 1 digit in the mantissa)                  *
 *       slong  - the maximum number of characters in strg to         *
 *                convert                                             *
 *       number - pointer to the converted number, or NULL if no      *
 *                number is to be converted.                          *
 *       stddev - pointer to the converted standard deviation, or     *
 *                NULL if no standard deviation is to be converted.   *
 *                The value of stddev will be -1. if no standard      *
 *                standard deviation was given in *strg.              *
 *       type   - pointer to a null-terminated character string       *
 *                which will be set to "char" if the string does      *
 *                not appear to be a number, or "numb", if it does.   *
 *       posdec - pointer to the character position (0...) at which   *
 *                a decimal point was found in the string, -1 if      *
 *                no decimal point is found.                          *
 *       esddig - pointer to count of the number of characters in the *
 *                esd, not counting the parentheses.                  *
 *       lzero  - pointer to a logical value, set true (1) for        *
 *                leading  zeros before the decimal point, false (0)  *
 *                otherwise.                                          *
 *       decp   - pointer to a logical value, set true (1) if a       *
 *                decimal point is found, false (0) otherwise         *
 *       cif_warn - pointer to a procedure to call if there is an     *
 *                exponent overflow or underflow.  Use NULL if        *
 *                no warning is needed.                               *
 *                                                                    *
 *  RETURN VALUES                                                     *
 *                                                                    *
 *  ctonum returns 0 (false) if a number was found, 1 (true)          *
 *  otherwise.  Values to be returned via pointers may be suppressed  *
 *  by using NULL pointers.                                           *
 *                                                                    *
 **********************************************************************/


/**********************************************************************
 *                                 NOTICE                             *
 * Creative endeavors depend on the lively exchange of ideas. There   *
 * are laws and customs which establish rights and responsibilities   *
 * for authors and the users of what authors create.  This notice     *
 * is not intended to prevent you from using the software and         *
 * documents in this package, but to ensure that there are no         *
 * misunderstandings about terms and conditions of such use.          *
 *                                                                    *
 * Please read the following notice carefully.  If you do not         *
 * understand any portion of this notice, please seek appropriate     *
 * professional legal advice before making use of the software and    *
 * documents included in this software package.  In addition to       *
 * whatever other steps you may be obliged to take to respect the     *
 * intellectual property rights of the various parties involved, if   *
 * you do make use of the software and documents in this package,     *
 * please give credit where credit is due by citing this package,     *
 * its authors and the URL or other source from which you obtained    *
 * it, or equivalent primary references in the literature with the    *
 * same authors.                                                      *
 *                                                                    *
 * Some of the software and documents included within this software   *
 * package are the intellectual property of various parties, and      *
 * placement in this package does not in any way imply that any       *
 * such rights have in any way been waived or diminished.             *
 *                                                                    *
 * With respect to any software or documents for which a copyright    *
 * exists, ALL RIGHTS ARE RESERVED TO THE OWNERS OF SUCH COPYRIGHT.   *
 *                                                                    *
 * Even though the authors of the various documents and software      *
 * found here have made a good faith effort to ensure that the        *
 * documents are correct and that the software performs according     *
 * to its documentation, and we would greatly appreciate hearing of   *
 * any problems you may encounter, the programs and documents any     *
 * files created by the programs are provided **AS IS** without any   *
 * warranty as to correctness, merchantability or fitness for any     *
 * particular or general use.                                         *
 *                                                                    *
 * THE RESPONSIBILITY FOR ANY ADVERSE CONSEQUENCES FROM THE USE OF    *
 * PROGRAMS OR DOCUMENTS OR ANY FILE OR FILES CREATED BY USE OF THE   *
 * PROGRAMS OR DOCUMENTS LIES SOLELY WITH THE USERS OF THE PROGRAMS   *
 * OR DOCUMENTS OR FILE OR FILES AND NOT WITH AUTHORS OF THE          *
 * PROGRAMS OR DOCUMENTS.                                             *
 **********************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#define _USE_RASMOL_H_
#ifdef _USE_RASMOL_H_
#include "rasmol.h"
#else
#if !defined(IBMPC) || defined(_WIN32)
#ifndef __far
#define __far
#endif
#endif
#endif

#ifndef DBL_MIN_10_EXP
#include <float.h>
#endif

#include "cif_ctonum.h"
#include <math.h>
#include <string.h>
#if defined(IBMPC) || defined(VMS) || defined(APPLEMAC)
#include "string_case.h"
#else
#include <strings.h>
#endif

int cif_ctonum(char __far *strg, int slong, double __far *number,
   double __far *stddev, char __far *type, 
   int __far *posdec, int __far *esddig, int __far *lzero, 
   int __far *decp, int __far (*cif_warn) (char __far * msg) )
{
    /* Initialized data */
                            /*          1         2 *
                             *012345687901234567890*/
    static char test[22+1] = "0123456789+.-()EDQedq ";
    static int minexp = DBL_MIN_10_EXP;
    static int maxexp = DBL_MAX_10_EXP;

    /* Local variables */
    static int ndec, ccnt, esin;
    static double mant, numb, sdev;
    static int msin;
    static int expn;
    static char c;
    static int m, nchar;
    static double ntemp;
    static int ids, nmd, nms, ned, nef, nes;
    char __far *indptr;

    if (number) *number = 0.;
    if (stddev) *stddev = -1.;
    numb = 1.;
    sdev = 0.;
    ccnt = 0;
    mant = 0.;
    expn = 0;
    msin = 1;
    esin = 1;
    ndec = 0;
    ids = 0;
    nmd = 0;
    nms = 0;
    ned = 0;
    nef = 0;
    nes = 0;
    if (type) strcpy(type, "char");
    if (posdec) *posdec = -1;
    if (esddig) *esddig = 0;
    if (lzero)  *lzero = 0;
    if (decp)   *decp = 0;
    if (slong == 1 && !strchr("0123456789", strg[0])) return 1;

/* ....... Loop over the string and identify components */

/*        The scan works in phases */
/*          ccnt = 0   processing looking for first digit */
/*          ccnt = 1   processing before decimal point */
/*          ccnt = 2   processing after decimal point */
/*          ccnt = 3   processing exponent */
/*          ccnt = 4   processing standard deviation */

    for (nchar = 0; (c = strg[nchar]) && (nchar < slong); ++nchar) {
      if ( !(indptr = strchr(test,c))) return 1;
        m = (int)(indptr - test);
        if (m < 10) {

        /* ....... Process the digits */

  	if (ccnt == 0)  ccnt = 1;
        if (ccnt == 2)  ++ndec;
	if (ccnt < 3) {
          ntemp = (double) (m);
	  if (ndec == 0) {
	    mant = mant * 10. + ntemp;
	  } else {
	    mant += ntemp / pow(10., (double) ndec);
  	  }
	    ++nmd;
	    if (ccnt == 1 && mant != 0.) ++ids;
  	  } else {
            if (ccnt < 4) {
              ++ned;
  	      expn = expn * 10 + m;
	    } else {
	      if (esddig) ++(*esddig);
	      ntemp = (double) (m);
	      sdev = sdev * 10. + ntemp;
	      if (stddev) *stddev = 1.;
            }
          }
        } else {

        /* ....... Process the characters    + . - ( ) E D Q e d q    *
	 *                                   | | | | | | | | | | |    *
         *                                   10| 12| 14| 16| 18| 20   *
         *                                     11  13  15  17  10     */
	if (c == '.') {
          if (decp) *decp = 1;
	  if (nchar > 0 && mant == 0.) {
            if (lzero && strg[nchar] == '0') *lzero = 1;
          }
  	  if (ccnt > 1) return 1;
	  if (posdec) *posdec = nchar;
	  ccnt = 2;
	} else {
  	  if (nmd == 0 && m > 12 && c !=' ') return 1;
  	  if (c == '(') {
  	    if (posdec && *posdec == -1) *posdec = nchar;
	    ccnt = 4;
	  } else {
  	    if (posdec && *posdec == -1 && ccnt > 0) *posdec = nchar;
            if (c != ')' && c != ' ') {
	      if (ccnt == 3  && ned) return 1;
  	      if (m > 12)  {
                if (nef) return 1;
                ++nef;
                ccnt = 3;
                esin = 1;
	      } else {
  	        if (ccnt > 0) {
                  if (nes) return 1;
                  ++nes;
  	          ccnt = 3;
	          esin = 11 - m;
                } else {
                  if (nms) return 1;
                  ++nms;
                  ccnt = 1;
	          msin = 11 - m;
                }
	      }
	    }
          }
        }
      }
    }
    if (posdec && *posdec == -1) *posdec = nchar;


/* ....... String parsed; construct the numbers */

    expn *= esin;
    if (expn + ids > maxexp) {
	if (cif_warn) (*cif_warn)(" Exponent overflow in numeric input");
	expn = -minexp - ids;
    }
    if (expn < minexp) {
	if (cif_warn) (*cif_warn)(" Exponent underflow in numeric input");
	expn = minexp;
    }
    if (expn - ndec < 0) numb = 1. / pow(10.,fabs( (double) (expn - ndec)));
    if (expn - ndec > 0) numb = pow(10.,(double) (expn - ndec));
    if (stddev && *stddev > 0.) *stddev = numb * sdev;
    numb = 1.;
    if (expn < 0) numb = 1. / pow (10., fabs((double)(expn)));
    if (expn > 0) numb = pow (10., (double) expn);
    ntemp = (double) msin;
    if (number) *number = numb * mant * ntemp;
    if (type) strcpy(type, "numb");

    return 0;
} /* ctonum */


#ifdef __cplusplus
}
#endif
