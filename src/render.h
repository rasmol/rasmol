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
/* render.h
 $Log$
 Revision 1.6  2008/03/22 18:42:55  yaya
 Post release cleanup and credit to Ikonen in file headers. -- HJB

 Revision 1.5  2008/03/17 03:01:31  yaya
 Update to agree with 2.7.4.2 release and T. Ikonen GTK mods -- HJB

 Revision 1.3  2008/03/17 01:32:41  yaya
 Add gtk mods by tpikonen, and intergate with 2.7.4.2 mods -- HJB

 Revision 1.4  2008/03/16 22:25:22  yaya
 Align comments with production version; Update rasmol_install and
 rasmol_run shell scripts for Japanese and Chinese; Align logic for
 positioning and sizing initial window with windows version -- HJB

 Revision 1.2  2008/01/28 03:29:38  yaya
 Update CVS to RasMol_2.7.4.1 -- HJB

 Revision 1.3  2008/01/05 20:56:29  yaya
 Update handling of stereo interaction with slab
 Enable save of CBF-style maps. -- HJB

 Revision 1.2  2007/11/19 03:28:40  yaya
 Update to credits for 2.7.4 in manual and headers
 Mask code added -- HJB

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

 Revision 1.1.1.1  2006/06/19 22:05:14  todorovg
 Initial Rasmol 2.7.3 Import

 Revision 1.1  2004/05/07 19:46:16  yaya
 Initial revision

 Revision 1.2  2004/02/15 00:24:00  yaya
 *** empty log message ***

 Revision 1.1  2003/12/12 21:10:38  yaya
 Initial revision

 Revision 1.1  2001/01/31 02:13:45  yaya
 Initial revision

 Revision 1.4  2000/08/26 18:12:59  yaya
 Updates to header comments in all files

 Revision 1.3  2000/08/13 20:56:43  yaya
 Conversion from toolbar to menus

 Revision 1.2  2000/08/09 01:18:37  yaya
 Rough cut with ucb

*/

/* These values set the sizes of the sphere rendering
 * tables. The first value, maxrad, is the maximum
 * sphere radius and the second value is the table
 * size = (maxrad*(maxrad+1))/2 + 1
 */
/* #define MAXRAD    120   256   */
/* #define MAXTABLE  7261  32897 */
#define MAXRAD    255
#define MAXTABLE  32641


#define SlabReject       0x00
#define SlabHalf         0x01
#define SlabHollow       0x02
#define SlabClose        0x04
#define SlabSection      0x05

#define PickNone         0x00
#define PickIdent        0x01
#define PickDist         0x02
#define PickAngle        0x03
#define PickTorsn        0x04
#define PickLabel        0x05
#define PickMonit        0x06
#define PickCentr        0x07
#define PickOrign        0x08
#define PickCoord        0x09
#define PickAtom         0x0A
#define PickGroup        0x0B
#define PickChain        0x0C
#define PickBond         0x0D

#define RotBond          0x01
#define RotMol           0x02
#define RotAll           0x04

#define ViewLeft         0
#define ViewRight        1

#define ColBits          24

/* To handle larger molecules efficiently
   use VOXORDER 32 or larger.  To save space
   use VOXORDER 21 or smaller */
#define VOXORDER       32
#define VOXORDER2      (VOXORDER*VOXORDER)
#define VOXSIZE        (VOXORDER2*VOXORDER)

typedef struct _Item {
        struct _Item __far *list;
        RAtom  __far *data;
    } Item;
 


#ifdef RENDER
int UseDepthCue;
int UseStereo,StereoView;
int UseShadow,DisplayMode;
int UseClipping,UseSlabPlane;
int UseAutoDepthCue,UseDepthPlane;
int SlabMode,SlabValue,DepthValue;
int SlabInten,SliceValue;
int ImageRadius,ImageSize;
int SSBondMode,HBondMode;
int PickCount;
int LabelOptFlag;

double StereoAngle;
int PickMode;
int RotMode;
int DrawArea;
int AreaX1, AreaX2, AreaY1, AreaY2;

int DrawBoundBox,DrawAxes;
int DrawDoubleBonds;
int DrawUnitCell;

Real IVoxRatio;
int VoxelsClean;
int BucketFlag;
int FBClear;




Card __far *ColConst;
#if defined(IBMPC) || defined(APPLEMAC)
void __far * __far *HashTable;
Byte __far * __far *LookUp;
Byte __far *Array;

#else /* UNIX or VMS */
void *HashTable[VOXSIZE];
Byte *LookUp[MAXRAD];
Byte Array[MAXTABLE];
#endif


#else
extern int UseDepthCue;
extern int UseStereo,StereoView;
extern int UseShadow, DisplayMode;
extern int UseClipping,UseSlabPlane;
extern int UseAutoDepthCue,UseDepthPlane;
extern int SlabMode,SlabValue,DepthValue;
extern int SlabInten,SliceValue;
extern int ImageRadius,ImageSize;
extern int SSBondMode, HBondMode;
extern int PickCount;
extern int LabelOptFlag;

extern double StereoAngle;
extern int PickMode;
extern int RotMode;
extern int DrawArea;
extern int AreaX1, AreaX2, AreaY1, AreaY2;

extern int DrawBoundBox,DrawAxes;
extern int DrawDoubleBonds;
extern int DrawUnitCell;

extern Real IVoxRatio;
extern int VoxelsClean;
extern int BucketFlag;
extern int FBClear;




extern Card __far *ColConst;
#if defined(IBMPC) || defined(APPLEMAC)
extern void __far * __far *HashTable;
extern Byte __far * __far *LookUp;
extern Byte __far *Array;

#else /* UNIX or VMS */
extern void *HashTable[VOXSIZE];
extern Byte *LookUp[MAXRAD];
extern Byte Array[MAXTABLE];
#endif


#endif

#define pythag(h,x) \
           ((h)<MAXRAD? \
             (int)LookUp[(h)][(x)]: \
             (int)(.5+(sqrt((double)((h)*(h)-(x)*(x))))))
#define apythag(h,x) \
           ((h)<MAXRAD/2? \
             (int)LookUp[(h)][(x)]: \
             (int)(.5+(sqrt((double)((h)*(h)-(x)*(x))))))
#define colconst(r) \
     ((r)<MAXRAD? \
       ColConst[(r)] : \
       (Card)(((Card)ColourDepth<<ColBits)/((int)(LightLength*(r)+4))))

void ClearBuffers( void );
void ReSizeScreen( void );
void ReAllocBuffers( void );
void ShadowTransform( void );

void ResetVoxelData( void );
void CreateVoxelData( int );

void DrawFrame( void );
void ResetRenderer( void );
void InitialiseRenderer( void );
void SetStereoMode( int );
void SetPickMode( int );
int PickAtoms( int, int, int );
unsigned int isqrt( Card );

