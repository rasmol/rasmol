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
/* pixutils.h
 $Log$
 Revision 1.7  2008/03/22 18:42:54  yaya
 Post release cleanup and credit to Ikonen in file headers. -- HJB

 Revision 1.6  2008/03/17 03:01:31  yaya
 Update to agree with 2.7.4.2 release and T. Ikonen GTK mods -- HJB

 Revision 1.3  2008/03/17 01:32:41  yaya
 Add gtk mods by tpikonen, and intergate with 2.7.4.2 mods -- HJB

 Revision 1.5  2008/03/16 22:25:22  yaya
 Align comments with production version; Update rasmol_install and
 rasmol_run shell scripts for Japanese and Chinese; Align logic for
 positioning and sizing initial window with windows version -- HJB

 Revision 1.2  2008/01/28 03:29:38  yaya
 Update CVS to RasMol_2.7.4.1 -- HJB

 Revision 1.4  2007/12/14 02:04:50  yaya
 Correct Chinese data for missing line in langsel_utf.c
 Rewrite code for handling of slab mode in stereo -- HJB

 Revision 1.3  2007/11/25 04:11:58  yaya
 Updates to map mask logic and inverse transforms -- HJB

 Revision 1.2  2007/10/23 02:27:55  yaya
 Preliminary mods for revised PDB format derived from Rutgers mods.
 Partial changes for map tangles -- HJB

 Revision 1.1.1.1  2007/03/01 01:16:33  todorovg
 Chinese working versio from rasmol_ru initial import

 Revision 1.3  2006/11/01 03:23:51  yaya
 Update NSIS windows installer for more script types and to fix
 misplaced script instructions for data files; add document and
 script icons directly in raswin.exe; add credit line to
 G. A. Pozhvanov in comments for Russian translations. -- HJB

 Revision 1.2  2006/09/17 10:53:56  yaya
 Clean up headers and start on code for X11 -- HJB

 Revision 1.1.1.1  2006/09/16 18:45:54  yaya
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

 Revision 1.4  2000/08/26 18:12:58  yaya
 Updates to header comments in all files

 Revision 1.3  2000/08/13 20:56:42  yaya
 Conversion from toolbar to menus

 Revision 1.2  2000/08/03 18:32:43  yaya
 Parametrization for alt conformer bond radius

 */

#ifndef KNOT_DEFINED
typedef struct {
        int px, py, pz;      /* Spline Control Co-ordinate */
        int tx, ty, tz;      /* Spline Direction Vector    */
        int hnx, hny, hnz;   /* Horizontal Normal Vector   */
        int vnx, vny, vnz;   /* Vertical Normal Vector     */
        int dx, dy, dz;      /* Ribbon Height Vector       */
        int wx, wy, wz;      /* Ribbon Width Vector        */
        char hinten;         /* Horizontal Intensity       */
        char vinten;         /* Vertical Intensity         */
        short hsize;         /* Horizontal Vector Length   */
        short vsize;         /* Vertical Vector Length     */
        short wide;          /* Ribbon Width               */
    } Knot;
#define KNOT_DEFINED
#endif

typedef struct {
        Pixel __huge *fbuf;
        short __huge *dbuf;
        short __huge *slbuf;
        short __huge *dlbuf;
        int   __huge *cbuf;
        int shift;
        int xmax, ymax;
        int yskip;
        int offmax;
    } ViewStruct;


typedef struct {
  int rad;
  Long x1, y1, z1, x2, y2, z2; 
  Long U[3]; 
  int  c1, c2;
  char altl;
  Long u1, u2, wp, w1, w2, t1, t2;
  Long sxyz, syz, sxz;
  Long Us0Us1, Us0Us0_Us1Us1_Us2Us2, Us0Us0_Us2Us2, Us1Us1_Us2Us2;
  int s0, s1, s2;
} SBDstruct;


#define MAXVERT  6
typedef struct {
        int x, y, z;
        int inten;
    } Vert;

typedef struct {
        Vert v[MAXVERT];
        int count;
    } Poly;

#define ZValid(x,z)     ((!UseSlabPlane) || ((z)<SlabValue))
#define ZBack(x,z)      ((!UseDepthPlane) || ((z)>DepthValue))
#define ZBValid(x,z)  (((!UseSlabPlane) || ((z)<View.slbuf[x]))&&((!UseDepthPlane) || ((z)>View.dlbuf[x])))
#define XValid(x)     (((x)>=0)&&((x)<View.xmax))
#define YValid(y)     (((y)>=0)&&((y)<View.ymax))
#define OValid(o)     (((o)>=0)&&((o)<View.offmax))

#ifdef INVERT
#define InvertY(y) (y)
#define ProperY(y) (-(y))
#else
#define InvertY(y) (-(y))
#define ProperY(y) (y)
#endif

#define RootSix       2.44948974278
 
/* These define light source position */
#define LightDot(x,y,z)  ((x)+InvertY(y)+(z)+(z))
#define LightLength      RootSix
#define LightXComp       1
#define LightYComp       1
#define LightZComp       2




#ifdef PIXUTILS
ViewStruct View;
int SplineCount;
int FontSize;
int FontPS;
int FontStroke;
SBDstruct SBD;

#else
extern ViewStruct View;
extern int SplineCount;
extern int FontSize;
extern int FontPS;
extern int FontStroke;
extern SBDstruct SBD;
#endif

void ClipCylinder( int, int, int, int, int, int, int, int, int, char, int );
void ClipDashLine( int, int, int, int, int, int, int, int, char );
void ClipDeepPoint( int, int, int, int );
void ClipLine( int, int, int, int, int, int, int,  char );
void ClipPolygon( Poly * );
void ClipSphere( int, int, int, int, int );
void ClipStar( int, int, int, int, int );
void ClipSurfaceBond( int, int, int, int, int, int, int, 
     int, int, int, int, char);
void ClipSurfSphere( int, int, int, int, int );
void ClipTwinLine( int, int, int, int, int, int, int, int, char );
void ClipTwinVector( int, int, int, int, int, int, int, int, char );
void ClipVector( int, int, int, int, int, int, int, char );
void ClipDashVector( int, int, int, int, int, int, int, int, char );
void DashRibbon( Knot __far*, Knot __far*, int, int );
void DisplayRasString( int, int, int, unsigned char *, int );
void DrawCylinder( int, int, int, int, int, int, int, int, int, char, int );
void DrawSphere( int, int, int, int, int );
void DrawStar( int, int, int, int, int );
void DrawCircle( void );
void DrawTorus( int, int, int, int, int, int, int, int, int, int, int, char );
void DrawSurfSphere( int, int, int, int, int );
void DrawTwinLine( int, int, int, int, int, int, int, int, char );
void DrawTwinVector( int, int, int, int, int, int, int, int, char );
void InitialisePixUtils( void );
void PlotDeepPoint( int, int, int, int );
void RectRibbon( Knot __far*, Knot __far*, int );
void SetFontSize( int );
void SetFontStroke( int );
void SolidRibbon2( Knot __far*, Knot __far*, int, int );
void SolidRibbon( Knot __far*, Knot __far*, int );
void StrandRibbon( Knot __far*, Knot __far*, int, int );
