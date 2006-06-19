
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
/* pixutils.h
 $Log: not supported by cvs2svn $
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

typedef struct {
        Pixel __huge *fbuf;
        short __huge *dbuf;
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

#define ZValid(z)     ((!UseSlabPlane) || ((z)<SlabValue))
#define ZBack(z)      ((!UseDepthPlane) || ((z)>DepthValue))
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
