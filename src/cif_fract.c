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
 *  cif_fract.c                                                       *
 *                                                                    *
 *  cell2mat, matmul, det, invxfrm                                    *
 *  - Routines for manipulation of fractional coordinates             *
 *                                                                    *
 *  Herbert J. Bernstein                                              *
 *  Bernstein + Sons, P.O. Box 177, Bellport, NY 11713                *
 *  yaya@bernstein-plus-sons.com                                      *
 *                                                                    *
 *  Rev, 15 Aug 98                                                    *
 **********************************************************************/

/**********************************************************************
 *  SYNOPSIS                                                          *
 *                                                                    *
 *  #include "cif_fract.h"                                            *
 *                                                                    *
 *  int cell2mat(double __far cell[6],                                *
 *    double __far matf2o[3][3], double __far mato2f[3][3]);          *
 *  double __far *matmul(double __far mat1[3][3],                     *
 *    double __far mat2[3][3],  double __far mat3[3][3]);             *
 *  double __far *matvec(double __far mat[3][3],                      *
 *    double __far vec1[3], double __far vec2[3]);                    *
 *  double det(double __far mat[3][3]);                               *
 *  int invxfrm(double __far mato2f[3][3], double __far veco2f[3],    *
 *    double __far matf2o[3][3], double __far vecf2o[3]);             *
 *                                                                    *
 *  DESCRIPTION                                                       *
 *                                                                    *
 *  cell2mat converts a cell to matrices, creating matrices for an    *
 *  orthogonal system with a along x, b in the x-y plane.  The        *
 *  arguments are:                                                    *
 *      cell   - double array of a, b, c, alpha, beta, gamma.         *
 *               the angles may be given in degrees or as cosines.    *
 *      matf2o - double 3x3 matrix to convert from fractional         *
 *               to orthogonal coordinates.                           *
 *      mato2f - double 3x3 matrix to convert from orthogonal         *
 *               to fractional coordinates.                           *
 *                                                                    *
 *  matmul multiplies 3x3 matrix mat1 by 3x3 matrix mat2 to produce   *
 *  3x3 matrix mat3.                                                  *
 *                                                                    *
 *  matvec multiplies 3x3 matrix mat by 3-vector vec1 to produce      *
 *  3-vector vec2.                                                    *
 *                                                                    *
 *  det returns the determinant of its 3x3 matrix argument.           *
 *                                                                    *
 *  invxfrm computes the inverse of the transform given by            *
 *  3x3 matrix mato2f and 3-vector veco2f to produce 3x3 matrix       *
 *  matf2o and 3-vector vecf2o.  matf2o is the inverse of mato2f      *
 *  vecf2o is  -matf2o*veco2f.                                        *
 *                                                                    *
 *  RETURN VALUES                                                     *
 *                                                                    *
 *  cell2mat returns 0 if the cell permits the calculation, 1 if      *
 *  either matrix is singular or nearly singular.                     *
 *                                                                    *
 *  matmul returns mat3 (i.e. the result array pointer).              *
 *                                                                    *
 *  matvec returns vec2 (i.e. the result vector pointer).             *
 *                                                                    *
 *  det returns the determinant.                                      *
 *                                                                    *
 *  invxfrm  returns 1 if the inversion fails, 0 otherwise.           *
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

#ifdef _USE_RASMOL_H_
#include "rasmol.h"
#else
#if !defined(IBMPC) || defined(_WIN32)
#ifndef __far
#define __far
#endif
#endif
#endif


#include "cif_fract.h"
#include <math.h>

int cell2mat( double __far cell[6], 
    double __far matf2o[3][3], double __far mato2f[3][3])
{
    /* Initialized data */

    static double pi = 3.14159265359;
    register double d1, d2, d3, d4;


    /* Local variables */
    static double torad, fromrad, cell_a, cell_b, cell_c;
    static double cell_alpha, cell_beta, cell_gamma;
    static int ii, jj;


/*      cell2mat -- convert a cell to matrices                      */

/*      Herbert J. Bernstein, yaya@bernstein-plus-sons.com          */
/*      20 May 1998 */

/*      Creates matrices for an orthogonal system with              */
/*         a along x, b in the x-y plane                            */

/*      cell   - double array of a, b, c, alpha, beta, gamma        */
/*      matf2o - double 3x3 matrix to convert from fractional       */
/*               to orthogonal */
/*      mato2f - double 3x3 matrix to convert from orthogonal       */
/*               to fractional */


    torad = pi / 180.;
    fromrad = 180. /pi ;
    cell_a = cell[0];
    cell_b = cell[1];
    cell_c = cell[2];
    cell_alpha = cell[3];
    if (fabs(cell[3]) < 1.) {
	cell_alpha = acos(cell[3]) * fromrad;
    }
    cell_beta = cell[4];
    if (fabs(cell[4]) < 1.) {
	cell_beta  = acos(cell[4]) * fromrad;
    }
    cell_gamma = cell[5];
    if (fabs(cell[5]) < 1.) {
	cell_gamma = acos(cell[5]) * fromrad;
    }

    for (ii = 0; ii < 3; ++ii) {
	for (jj = 0; jj < 3; ++jj) {
	    matf2o[ii][jj] = 0.;
	    mato2f[ii][jj] = 0.;
	}
    }
    d1 = cos(torad*cell_alpha);
    d2 = cos(torad*cell_beta);
    d3 = cos(torad*cell_gamma);
    if ( fabs (d4 = sin(torad * cell_gamma)) <  1.e-6)
      return 1;
    matf2o[0][0] = cell_a;
    matf2o[0][1] = cell_b*d3;
    matf2o[1][1] = cell_b*d4;
    matf2o[0][2] = cell_c*d2;
    matf2o[1][2] = cell_c*((d1 - d2*d3)/d4);
    d1 = cell_c;
    d2 = matf2o[0][2];
    d3 = matf2o[1][2];
    matf2o[2][2] = sqrt(fabs(d1*d1 - d2*d2 - d3*d3));
    if ( fabs(det(matf2o)) < 
        (fabs(cell_a*cell_b*cell_c) + 1.)*1.e-9 ) return 1;
    mato2f[0][0] = ((double)1.) / matf2o[0][0];
    mato2f[1][1] = ((double)1.) / matf2o[1][1];
    mato2f[2][2] = ((double)1.) / matf2o[2][2];
    mato2f[0][1] = -matf2o[0][1] / (matf2o[0][0]*matf2o[1][1]);
    mato2f[1][2] = -matf2o[1][2] / (matf2o[1][1]*matf2o[2][2]);
    mato2f[0][2] = (matf2o[0][1]*matf2o[1][2]-matf2o[0][2]*matf2o[1][1])/
                   (matf2o[0][0]*matf2o[1][1]*matf2o[2][2]);
    if ( fabs(det(mato2f)) < 
         (1./(fabs(cell_a*cell_b*cell_c)+1.))*1.e-9 ) return 1;
    return 0;
} /* cell2mat */

double __far  *matmul(double __far mat1[3][3], 
    double __far mat2[3][3], double __far mat3[3][3])
{
    static int ii, jj, kk;


/*      multiply mat1 times mat2 and return mat3                   */

/*      Herbert J. Bernstein, yaya@bernstein-plus-sons.com         */
/*      20 May 1998                                                */

    for (ii = 0; ii < 3; ++ii) {
	for (jj = 0; jj < 3; ++jj) {
	    mat3[ii][jj] = mat1[ii][0] * mat2[0][jj];
	    for (kk = 1; kk < 3; ++kk) {
		mat3[ii][jj] += mat1[ii][kk] * mat2[kk][jj];
	    }
	}
    }
    return (double *)mat3;
} /* matmul */

double __far *matvec(double __far mat[3][3], 
    double __far vec1[3], double __far vec2[3])
{
    static int ii, jj;


/*      multiply mat times vec1 and return vec2                   */

/*      Herbert J. Bernstein, yaya@bernstein-plus-sons.com         */
/*      20 May 1998                                                */

    for (ii = 0; ii < 3; ++ii) {
        vec2[ii] = mat[ii][0]*vec1[0];
	for (jj = 1; jj < 3; ++jj) {
	    vec2[ii] += mat[ii][jj]*vec1[jj];
	}
    }
    return (double *)vec2;
} /* matvec */

double det(double __far mat[3][3])
{


/*      compute the double determinant of a double matrix */

/*      Herbert J. Bernstein, yaya@bernstein-plus-sons.com */
/*      6 March 1998 */

      return  ( mat[0][0] * mat[1][1] * mat[2][2] 
              + mat[1][0] * mat[2][1] * mat[0][2] 
              + mat[2][0] * mat[0][1] * mat[1][2] 
              - mat[0][2] * mat[1][1] * mat[2][0]
              - mat[0][1] * mat[1][0] * mat[2][2] 
              - mat[0][0] * mat[1][2] * mat[2][1]);

} /* det */

int invxfrm(double __far mato2f[3][3], double __far veco2f[3], 
            double __far matf2o[3][3], double __far vecf2o[3])
{
    static int ii, jj;
    register double newvol, xdet;
    
    extern double det();



/*      compute the inverse of a transform */

/*      Herbert J. Bernstein, yaya@bernstein-plus-sons.com */
/*      6 March 1998 */

/*      mato2f - 3x3 double input matrix */
/*      veco2f - 3 element double input vector */
/*      matf2o - 3x3 double output matrix */
/*      vecf2o - 3 element double output vector */

/*      matf2o is the inverse of mato2f */
/*      vecf2o = -matf2o veco2f */

    xdet = det(mato2f);
    if ( fabs(xdet) < 1.e-24 ) return 1;
    newvol =  1. / xdet;

    matf2o[0][0] = newvol*(mato2f[1][1]*mato2f[2][2] 
                            - mato2f[2][1]*mato2f[1][2]);
    matf2o[0][1] = newvol*(mato2f[0][2]*mato2f[2][1] 
                            - mato2f[0][1]*mato2f[2][2]);
    matf2o[0][2] = newvol*(mato2f[0][1]*mato2f[1][2] 
                            - mato2f[0][2]*mato2f[1][1]);

    matf2o[1][0] = newvol*(mato2f[1][2]*mato2f[2][0] 
                            - mato2f[1][0]*mato2f[2][2]);
    matf2o[1][1] = newvol*(mato2f[0][0]*mato2f[2][2] 
                            - mato2f[0][2]*mato2f[2][0]);
    matf2o[1][2] = newvol*(mato2f[0][2]*mato2f[1][0] 
                            - mato2f[0][0]*mato2f[1][2]);

    matf2o[2][0] = newvol*(mato2f[1][0]*mato2f[2][1] 
                            - mato2f[2][0]*mato2f[1][1]);
    matf2o[2][1] = newvol*(mato2f[0][1]*mato2f[2][0] 
                            - mato2f[0][0]*mato2f[2][1]);
    matf2o[2][2] = newvol*(mato2f[0][0]*mato2f[1][1] 
                            - mato2f[0][1]*mato2f[1][0]);
    for (ii = 0; ii < 3; ++ii) {
	vecf2o[ii] =  0.;
	for (jj = 0; jj < 3; ++jj) {
	    vecf2o[ii] -= matf2o[ii][jj]*veco2f[jj];
	}
    }
    return 0;
} /* invxfrm */


#ifdef __cplusplus
}
#endif


