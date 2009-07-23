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
/* repres.h
 $Log$
 Revision 1.8  2008/04/01 17:31:19  hk0i
 updated new color mode feature for dots

 Revision 1.7  2008/03/22 18:42:55  yaya
 Post release cleanup and credit to Ikonen in file headers. -- HJB

 Revision 1.6  2008/03/17 03:01:31  yaya
 Update to agree with 2.7.4.2 release and T. Ikonen GTK mods -- HJB

 Revision 1.4  2008/03/17 01:32:41  yaya
 Add gtk mods by tpikonen, and intergate with 2.7.4.2 mods -- HJB

 Revision 1.5  2008/03/16 22:25:22  yaya
 Align comments with production version; Update rasmol_install and
 rasmol_run shell scripts for Japanese and Chinese; Align logic for
 positioning and sizing initial window with windows version -- HJB

 Revision 1.3  2008/01/28 03:29:38  yaya
 Update CVS to RasMol_2.7.4.1 -- HJB

 Revision 1.4  2007/11/19 03:28:40  yaya
 Update to credits for 2.7.4 in manual and headers
 Mask code added -- HJB

 Revision 1.3  2007/10/23 02:27:55  yaya
 Preliminary mods for revised PDB format derived from Rutgers mods.
 Partial changes for map tangles -- HJB

 Revision 1.2  2007/07/02 12:44:39  yaya
 Partial preliminary map code -- HJB

 Revision 1.1.1.1  2007/03/01 01:16:32  todorovg
 Chinese working versio from rasmol_ru initial import

 Revision 1.3  2006/11/01 03:23:51  yaya
 Update NSIS windows installer for more script types and to fix
 misplaced script instructions for data files; add document and
 script icons directly in raswin.exe; add credit line to
 G. A. Pozhvanov in comments for Russian translations. -- HJB

 Revision 1.2  2006/09/17 10:53:56  yaya
 Clean up headers and start on code for X11 -- HJB

 Revision 1.1.1.1  2006/09/16 18:45:59  yaya
 Start of RasMol Russian Translation Project based on translations
 by Gregory A. Pozhvanov of Saint Petersburg State University -- HJB

 Revision 1.2  2006/06/19 22:06:41  todorovg
 Rasmol 2.7.3.1

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

 Revision 1.4  2000/08/27 16:09:43  yaya
 monitor dynamics extensions

 Revision 1.3  2000/08/26 18:13:00  yaya
 Updates to header comments in all files

 Revision 1.2  2000/08/09 01:18:38  yaya
 Rough cut with ucb

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

#define DotMax    100
typedef struct _DotStruct {
        struct _DotStruct __far *next;
        short col[DotMax];
        Long xpos[DotMax];
        Long ypos[DotMax];
        Long zpos[DotMax];
        int count;
    } DotStruct;


typedef struct _Monitor {
        struct _Monitor *next;
        RAtom __far *src;
        RAtom __far *mid1;
        RAtom __far *mid2;
        RAtom __far *dst;
        int monmode;
        Long dist;
        short col;
        unsigned char units;
    } Monitor;


typedef struct _Label {
        struct _Label *next;
        Long  refcount;
        char *label;
    } Label;



#ifdef REPRES
DotStruct __far *DotPtr;
Monitor *MonitList;
Label *LabelList;

int CartoonHeight;
int SolventDots;
int ProbeRadius;
int iProbeRad;

int SurfaceChainsFlag;
int DotDensity;
int DotSize;
int DrawMonitDistance;
int DrawBetaArrows;

char LabelFormat[128];

int DotCount;

#else
extern DotStruct __far *DotPtr;
extern Monitor *MonitList;
extern Label *LabelList;

extern int CartoonHeight;
extern int ProbeRadius;
extern int iProbeRad;
extern int SolventDots;

extern int SurfaceChainsFlag;
extern int DotDensity;
extern int DotSize;
extern int DrawMonitDistance;
extern int DrawBetaArrows;

extern char LabelFormat[128];

extern int DotCount;
#endif


int DeleteLabels( void );
void DeleteLabel( Label* );
Label *CreateLabel( char*, int );
void LabelTerminii( int );
void DefaultLabels( int );
void DefineLabels( char* );
void DisplayLabels( void );

void DeleteMonitors( void );
void AddMonitors2( RAtom __far*, RAtom __far*,
  RAtom __far*, RAtom __far*, 
  Long, unsigned char, int );
void AddMonitors( RAtom __far*, RAtom __far* );
void CreateMonitor( Long, Long );
void DisplayMonitors( void );

void DeleteSurface( void );
void CalculateSurface( int );
void DisplaySurface( void );
void DisplayMapPoints( void );
void DisplayMapBonds( void );
void DisplayMapTangles( void );

/* Ribbons & Cartoons */
void CalculateVInten( Knot *);
void CalculateHInten( Knot *);
void DisplayRibbon( Chain __far* );

void ResetRepres( void );
void InitialiseRepres( void );

void LoadDotsFile( FILE *, int );
