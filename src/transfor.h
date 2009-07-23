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
/* transfor.h
 $Log$
 Revision 1.7  2008/03/22 18:42:55  yaya
 Post release cleanup and credit to Ikonen in file headers. -- HJB

 Revision 1.6  2008/03/17 03:01:32  yaya
 Update to agree with 2.7.4.2 release and T. Ikonen GTK mods -- HJB

 Revision 1.3  2008/03/17 01:32:41  yaya
 Add gtk mods by tpikonen, and intergate with 2.7.4.2 mods -- HJB

 Revision 1.5  2008/03/16 22:25:22  yaya
 Align comments with production version; Update rasmol_install and
 rasmol_run shell scripts for Japanese and Chinese; Align logic for
 positioning and sizing initial window with windows version -- HJB

 Revision 1.2  2008/01/28 03:29:38  yaya
 Update CVS to RasMol_2.7.4.1 -- HJB

 Revision 1.4  2007/11/19 03:28:40  yaya
 Update to credits for 2.7.4 in manual and headers
 Mask code added -- HJB

 Revision 1.3  2007/11/13 03:22:17  yaya
 Changes to support map selectors.  Needs more work. -- HJB

 Revision 1.2  2007/09/13 20:05:07  yaya
 RasWin 2.7.4 PreRelease 1 -- HJB

 Revision 1.1.1.1  2007/03/01 01:16:32  todorovg
 Chinese working versio from rasmol_ru initial import

 Revision 1.3  2006/11/01 03:23:51  yaya
 Update NSIS windows installer for more script types and to fix
 misplaced script instructions for data files; add document and
 script icons directly in raswin.exe; add credit line to
 G. A. Pozhvanov in comments for Russian translations. -- HJB

 Revision 1.2  2006/09/17 10:53:56  yaya
 Clean up headers and start on code for X11 -- HJB

 Revision 1.1.1.1  2006/09/16 18:46:02  yaya
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

 Revision 1.7  2000/08/26 18:13:02  yaya
 Updates to header comments in all files

 Revision 1.6  2000/08/26 17:31:24  yaya
 Fix for world rot, remove refs to toolbar

 Revision 1.5  2000/08/26 03:14:29  yaya
 Mods for mac compilations

 Revision 1.4  2000/08/21 21:08:09  yaya
 semi-final ucb mods

 Revision 1.3  2000/08/09 01:18:42  yaya
 Rough cut with ucb

 Revision 1.2  2000/08/03 18:32:43  yaya
 Parametrization for alt conformer bond radius

 */

#define GroupAttr       0x00
#define ChainAttr       0x01
#define TempAttr	    0x02
#define ChargeAttr      0x03
#define AltAttr         0x04
#define ModelAttr       0x05

#define MaskColourFlag  0x01
#define MaskRadiusFlag  0x02
#define MaskBothFlag    0x03

#define RibColInside    0x01
#define RibColOutside   0x02
#define RibColBoth      0x03

#ifdef EIGHTBIT
#define ColourDepth       16
#define ColourMask        15
#define AltlDepth         4
#ifdef APPLEMAC
#define LastShade         14
#else
#define LastShade         15
#endif
#else
#define ColourDepth       32
#define ColourMask        31
#define LastShade         31
#define AltlDepth         8
#endif


#ifdef __esv
/* Evans & Sutherland Gamma! */
#define DefaultAmbient    0.05
#else
#define DefaultAmbient    0.4
#endif


typedef struct { 
        Long refcount;
        unsigned char r;
        unsigned char g;
        unsigned char b;
    } ShadeDesc;

typedef struct {
        short col;
        short shade;
        unsigned char r;
        unsigned char g;
        unsigned char b;
    } ShadeRef;


#ifdef IBMPC
#define BackCol    0
#define BoxCol     1
#define LabelCol   2
#define FirstCol   3
#endif

#ifdef APPLEMAC
#define BackCol    1
#define BoxCol     2
#define LabelCol   3
#define FirstCol   4
#endif

#if !defined(IBMPC) && !defined(APPLEMAC)
#define BackCol    5
#define BoxCol     6
#define LabelCol   7
#define FirstCol   8
#endif

#define Colour2Shade(x)  ((int)((x)-FirstCol)/ColourDepth)
#define Shade2Colour(x)  ((x)*ColourDepth+FirstCol)


#ifdef TRANSFORM
ShadeDesc Shade[LastShade];
Real RotX[3],RotY[3],RotZ[3];
Real LRotX[3],LRotY[3],LRotZ[3];
Real LOffset[3];
Real MatX[3],MatY[3],MatZ[3];
Real InvX[3],InvY[3],InvZ[3];
Long OrigCX,OrigCY,OrigCZ;
Long CenX, CenY, CenZ;
Long ShiftS;
int XlateCen;

int FakeSpecular,SpecPower;
int ShadePower;
int BackR,BackG,BackB;
int DotR,DotG,DotB;
int LabR,LabG,LabB;
int BoxR,BoxG,BoxB;
int UseLabelCol;
int UseBackFade;
Real Ambient;
int UseDotColPot;

Real Scale,MaxZoom;
Long LScale;
Real DScale,IScale;
Long SideLen,Offset;
Card WorldRadius,WorldSize,LocalRadius;
int XOffset,YOffset,ZOffset;
int UseScreenClip;
int ZoomRange;

int Hydrogens,HetaGroups;
int DrawAtoms,MaxAtomRadius;
int DrawBonds,MaxBondRadius;
int DrawStars;
int DrawSurf;
int DrawRibbon;
int ZoneBoth;
int ModelInclude;

int ScaleCount;
ShadeRef ScaleRef[LastShade];
int AltlColours[AltlDepth];

Real Zoom;

double record_fps, play_fps, record_aps, record_dwell;
int record_on[2];
size_t record_frame[2], play_frame[2];



#else
extern ShadeDesc Shade[LastShade];
extern Real RotX[3],RotY[3],RotZ[3];
extern Real LRotX[3],LRotY[3],LRotZ[3];
extern Real LOffset[3];
extern Real MatX[3],MatY[3],MatZ[3];
extern Real InvX[3],InvY[3],InvZ[3];
extern Long OrigCX, OrigCY, OrigCZ;
extern Long CenX, CenY, CenZ;
extern Long ShiftS;
extern int XlateCen;


extern int FakeSpecular,SpecPower;
extern int ShadePower;
extern int BackR,BackG,BackB;
extern int DotR,DotG,DotB;
extern int LabR,LabG,LabB;
extern int BoxR,BoxG,BoxB;
extern int UseLabelCol;
extern int UseBackFade;
extern Real Ambient;
extern int UseDotColPot;

extern Real Scale,MaxZoom;
extern Long LScale;
extern Real DScale,IScale;
extern Long SideLen,Offset;
extern Card WorldRadius,WorldSize,LocalRadius;
extern int XOffset,YOffset,ZOffset;
extern int UseScreenClip;
extern int ZoomRange;

extern int Hydrogens,HetaGroups;
extern int DrawAtoms,MaxAtomRadius;
extern int DrawBonds,MaxBondRadius;
extern int DrawStars;
extern int DrawSurf;
extern int DrawRibbon;
extern int ZoneBoth;
extern int ModelInclude;

extern int ScaleCount;
extern ShadeRef ScaleRef[LastShade];
extern int AltlColours[AltlDepth];

extern ShadeDesc Shade[LastShade];
extern Real RotX[3],RotY[3],RotZ[3];

extern Real Zoom;


extern double record_fps, play_fps, record_aps, record_dwell;
extern int record_on[2];
extern size_t record_frame[2], play_frame[2];

#endif


void SetRadiusValue( int, int  );
void SetRadiusTemperature( int );
void SetVanWaalRadius( int );
void DisableSpacefill( void );
void SetHBondStatus( int, int, int, int );
void SetRibbonStatus( int, int, int );
void SetRibbonCartoons( void );
void SetTraceTemperature( void );
void EnableWireframe( int, int, int );
void EnableBackbone( int, int, int );
void DisableWireframe( void );
void DisableBackbone( void );

void DisplaySelectCount( void );
void SelectZoneExpr( Expr* );
void RestrictZoneExpr( Expr* );
void RestrictZone( int );
void SelectArea( int, int, int, int, int, int );
void SelectZone( int );
void SelectAtom( int, RAtom __far *, Group __far * );
void SelectGroup( int, Group __far * );
void SelectChain( int, Chain __far * );

int IsCPKColour( RAtom __far * );
int IsCpkNewColour( RAtom __far * );
int IsVDWRadius( RAtom __far * );

int DefineShade( int, int, int );

void DefineColourMap( void );
void ResetColourMap( void );

void ColourBackNone( void );
void ColourBondNone( void );
void ColourHBondType( void );
void ColourHBondNone( int );
void ColourRibbonNone( int );
void ColourMonitNone( void );
void ColourBackAttrib( int, int, int );
void ColourBondAttrib( int, int, int );
void ColourHBondAttrib( int, int, int, int );
void ColourRibbonAttrib( int, int, int, int );
void ColourMonitAttrib( int, int, int );
void ColourDotsAttrib( int, int, int );
void ColourDotsPotential( void );
void ColourPointAttrib( int, int, int, int );
void ColourPointPotential( int );
void ColourPointAtom( int );
void MonoColourAttrib( int, int, int );
void ScaleColourAttrib( int );
void CPKColourAttrib( void );
void CpkNewColourAttrib( void );
void AminoColourAttrib( void );
void ShapelyColourAttrib( void );
void StructColourAttrib( void );
void UserMaskAttrib( int );

void DefaultRepresentation( void );

void DetermineClipping( void );
void InitialiseTransform( void );
void InitialTransform( void );
void RMatVec( Real [3], Real [3], Real [3], Real [3], Real [3] );
void RMatRMat( Real [3][3], Real [3], Real [3], Real [3], Real [3][3] );
void RMatInv( Real [3], Real [3], Real [3], Real [3], Real [3], Real [3] );
void RMat2RV( Real *, Real *, Real *,  Real [3], Real [3], Real [3]  );
void RV2RMat( Real, Real, Real,  Real [3], Real [3], Real [3]  );
void PrepareTransform( void );
void ReviseInvMatrix( void );
void ApplyTransform( void );
void CentreTransform( int, int, int, int );
void ResetTransform( void );

void SetLutEntry( int, int, int, int );
