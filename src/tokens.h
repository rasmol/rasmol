/***************************************************************************
 *                             RasMol 2.7.4.2                              *
 *                                                                         *
 *                                 RasMol                                  *
 *                 Molecular Graphics Visualisation Tool                   *
 *                            19 November 2007                             *
 *                          (rev. 21 March 2008)                           *
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
 *                                                                         *
 * RasMol 2.7.3 incorporates changes by Clarice Chigbo, Ricky Chachra,     *
 * and Mamoru Yamanishi.  Work on RasMol 2.7.3 supported in part by        *
 * grants DBI-0203064, DBI-0315281 and EF-0312612 from the U.S. National   *
 * Science Foundation and grant DE-FG02-03ER63601 from the U.S. Department *
 * of Energy.  RasMol 2.7.4 incorporates changes by G. Todorov, Nan Jia,   *
 * N. Darakev, P. Kamburov, G. McQuillan, J. Jemilawon.  Work on RasMol    *
 * 2.7.4 supported in part by grant 1R15GM078077-01 from the National      *
 * Institute of General Medical Sciences (NIGMS). The content is solely    *
 * the responsibility of the authors and does not necessarily represent    * 
 * the official views of the funding organizations.                        *
 *                                                                         *
 * The code for use of RasMol under GTK in RasMol 2.7.4.2 was written by   *
 * Teemu  Ikonen.                                                          *
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

/* tokens.h
 $Log$
 Revision 1.14  2008/06/19 19:13:37  yaya
 Insert WPDBTok -- HJB

 Revision 1.13  2008/06/18 20:04:53  yaya
 Start in infrastructure for animation
 Start on WPDB code -- HJB

 Revision 1.12  2008/03/22 18:42:55  yaya
 Post release cleanup and credit to Ikonen in file headers. -- HJB

 Revision 1.11  2008/03/17 03:01:31  yaya
 Update to agree with 2.7.4.2 release and T. Ikonen GTK mods -- HJB

 Revision 1.3  2008/03/17 01:32:41  yaya
 Add gtk mods by tpikonen, and intergate with 2.7.4.2 mods -- HJB

 Revision 1.10  2008/03/16 22:25:22  yaya
 Align comments with production version; Update rasmol_install and
 rasmol_run shell scripts for Japanese and Chinese; Align logic for
 positioning and sizing initial window with windows version -- HJB

 Revision 1.2  2008/01/28 03:29:38  yaya
 Update CVS to RasMol_2.7.4.1 -- HJB

 Revision 1.9  2007/12/06 18:47:10  hk0i
 added NoToggle and ColourMode commands + messages (translations needed), README for lang files, script to generate all langsel files (uses previous scripts).

 Revision 1.8  2007/11/19 03:28:40  yaya
 Update to credits for 2.7.4 in manual and headers
 Mask code added -- HJB

 Revision 1.7  2007/11/13 03:22:17  yaya
 Changes to support map selectors.  Needs more work. -- HJB

 Revision 1.6  2007/09/06 12:11:26  yaya
 Changes for map resolution -- HJB

 Revision 1.5  2007/08/03 02:02:34  yaya
 Add MEAN to map level command, and move the various map settings
 under the map command, and set the defaults to make a nice map
 on a default generate (spread .1667, level mean, spacing .5) -- HJB

 Revision 1.4  2007/07/09 13:57:06  yaya
 Add spacing and spread commands -- HJB

 Revision 1.3  2007/07/07 21:54:31  yaya
 Next round of preliminary updates for maps, allowing multiple maps,
 code to set the contour level and some fixes to the languages files -- HJB

 Revision 1.2  2007/07/02 12:44:39  yaya
 Partial preliminary map code -- HJB

 Revision 1.1.1.1  2007/03/01 01:16:33  todorovg
 Chinese working versio from rasmol_ru initial import

 Revision 1.4  2006/11/28 03:12:48  yaya
 Changes for Russian and About dialog in unix
 This is a variant tried under Mac OS X.  Changes
 for Linux still needed.  note that more work is
 needed on font selection. -- HJB

 Revision 1.3  2006/11/01 03:23:51  yaya
 Update NSIS windows installer for more script types and to fix
 misplaced script instructions for data files; add document and
 script icons directly in raswin.exe; add credit line to
 G. A. Pozhvanov in comments for Russian translations. -- HJB

 Revision 1.2  2006/09/17 10:53:56  yaya
 Clean up headers and start on code for X11 -- HJB

 Revision 1.1.1.1  2006/09/16 18:46:01  yaya
 Start of RasMol Russian Translation Project based on translations
 by Gregory A. Pozhvanov of Saint Petersburg State University -- HJB

 Revision 1.1.1.1  2006/06/19 22:05:14  todorovg
 Initial Rasmol 2.7.3 Import

 Revision 1.2  2004/09/29 22:39:14  chigboc
 *** empty log message ***

 Revision 1.1  2004/05/07 19:46:16  yaya
 Initial revision

 Revision 1.3  2004/02/15 00:24:00  yaya
 *** empty log message ***

 Revision 1.2  2003/12/13 19:26:11  yaya
 *** empty log message ***

 Revision 1.1  2003/12/12 21:10:38  yaya
 Initial revision

 Revision 1.2  2001/02/06 21:58:18  yaya
 *** empty log message ***

 Revision 1.1  2001/01/31 02:13:45  yaya
 Initial revision

 Revision 1.4  2000/08/26 18:13:01  yaya
 Updates to header comments in all files

 Revision 1.3  2000/08/21 21:08:08  yaya
 semi-final ucb mods

 Revision 1.2  2000/08/09 01:18:39  yaya
 Rough cut with ucb

 */

/* Lexeme Tokens */
#define IdentTok       256
#define NumberTok      257
#define FloatTok       258
#define StringTok      259

/* Command Tokens */
#define AdviseTok      260
#define AnimateTok     261
#define APSTok         262
#define BackboneTok    263
#define CartoonTok     264
#define CentreTok      265
#define ClipboardTok   266
#define ColourTok      267
#define ColourModeTok  268
#define ConnectTok     269
#define DashTok        270

#define DeferTok       271
#define DefineTok      272
#define DelayTok       273
#define DepthTok       274
#define DisplayTok     275
#define DwellTok       276
#define EchoTok        277
#define EjectTok       278
#define ExitTok        279
#define ExecuteTok     280

#define FPSTok         281
#define GenerateTok    282
#define HelpTok        283
#define LabelTok       284
#define LoadTok        285
#define LoopTok        286
#define MapTok         287
#define MaskTok        288
#define MoleculeTok    289
#define MolSurfTok     290 

#define MonitorTok     291
#define MoveTok        292
#define MoveToTok      293
#define NoToggleTok    294
#define PlayTok        295
#define PrintTok       296
#define QuitTok        297
#define RecordTok      298
#define RefreshTok     299
#define RenumTok       300

#define ResetTok       301
#define ResizeTok      302
#define RestoreTok     303
#define RestrictTok    304
#define RotateTok      305
#define SaveTok        306
#define ScriptTok      307
#define SelectTok      308
#define SetTok         309
#define ShowTok        310

#define SlabTok        311
#define SourceTok      312
#define SpacefillTok   313
#define StarTok        314
#define StructureTok   315
#define SurfaceTok     316
#define SymmetryTok    317
#define TitleTok       318
#define TraceTok       319
#define TranslateTok   320

#define ViewTok        321
#define WaitTok        322
#define WireframeTok   323
#define WriteTok       324
#define ZapTok         325
#define ZoomTok        326

/* Predicate Tokens */
#define IsPredTok(x)   (((x)>=AlphaTok) && ((x)<=SmallTok))
#define PredTokOrd(x)  ((x)-AlphaTok)
#define PredTokChr(x)  ((x)+AlphaTok)

#define AlphaTok       400
#define AminoTok       401
#define ATTok          402
#define BondedTok      403
#define CGTok          404
#define CystineTok     405
#define DNATok         406
#define HelixTok       407
#define HeteroTok      408
#define HydrogenTok    409
#define IonTok         410
#define LigandTok      411
#define MainChainTok   412
#define NucleicTok     413
#define ProteinTok     414
#define PurineTok      415
#define PyrimidineTok  416
#define RNATok         417
#define SelectedTok    418
#define SheetTok       419
#define SidechainTok   420
#define SolventTok     421
#define TurnTok        422
#define WaterTok       423

#define AcidicTok      424
#define AcyclicTok     425
#define AliphaticTok   426
#define AromaticTok    427
#define BasicTok       428
#define BuriedTok      429
#define ChargedTok     430
#define CisBondedTok   431
#define CyclicTok      432
#define HydrophobicTok 433
#define LargeTok       434
#define MediumTok      435
#define NeutralTok     436
#define PolarTok       437
#define SmallTok       438



/* Property Tokens */
#define IsPropTok(x)   (((x)>=TemperatureTok) && ((x)<=AltlTok))
#define TemperatureTok 460
#define RadiusTok      461
#define AtomNoTok      462
#define ElemNoTok      463
#define ModelTok       464
#define ResNoTok       465
#define AltlTok        466

/* File Format Tokens */
/* Warning! Tokens are related to Format values */
#define IsMoleculeToken(x)  (((x)>=PDBTok) && ((x)<=WPDBTok))

#define PDBTok         470
#define MacroModelTok  471
#define GaussianTok    472
#define AlchemyTok     473
#define NMRPDBTok      474
#define CharmmTok      475
#define BiosymTok      476
#define MOPACTok       477
#define SHELXTok       478
#define Mol2Tok        479
#define FDATTok        480
#define MMDBTok        481
#define MDLTok         482
#define XYZTok         483
#define CIFTok         484
#define CEXTok         485
#define WPDBTok        486

/* Raster Tokens */
#define IsImageToken(x) (((((x)>=GIFTok) && ((x)<=RamPrintTok)) || ((x) == PhiPsiTok)))
#define GIFTok         490
#define PPMTok         491
#define SUNTok         492
#define SUNRLETok      493
#define EPSFTok        494
#define PICTTok        495
#define IRISTok        496
#define BMPTok         497
#define MonoPSTok      498
#define JPEGTok        499
#define PNGTok         500
#define VectPSTok      501
#define KinemageTok    502
#define MolScriptTok   503
#define POVRayTok      504
#define POVRay2Tok     504
#define POVRay3Tok     505
#define VRMLTok        506
#define Raster3DTok    507
#define RamachanTok    508  /* ok, this isn't a real image format ... */
#define RamPrintTok    509
#define MirrorTok      510

/* Feature Tokens */
#define AtomTok        521
#define BondTok        522
#define DotsTok        523
#define HBondTok       524
#define RibbonTok      525
#define SSBondTok      526
#define Ribbon1Tok     527
#define Ribbon2Tok     528
#define UnBondTok      529

/* Expression Tokens */
#define AllTok         530
#define AndTok         531
#define FalseTok       532
#define FromTok        533
#define MeanTok        534
#define NewTok         535
#define NextTok        536
#define NoneTok        537
#define NotTok         538
#define OnTok          TrueTok
#define OffTok         FalseTok
#define OrTok          539
#define TrueTok        540
#define UntilTok       541
#define WithinTok      542
#define XorTok         543

/* Colour Tokens */
/* Warning! Tokens are related to colour values */
#define IsColourToken(x) (((x)>=BlackTok) && ((x)<=YellowTintTok))
#define Token2Colour(x)  ((x)-BlackTok)

#define BlackTok       642
#define BlueTok        643
#define BlueTintTok    644
#define BrownTok       645
#define CyanTok        646
#define GoldTok        647
#define GrayTok        648
#define GreenTok       649
#define GreenBlueTok   650
#define GreenTintTok   651
#define HotPinkTok     652
#define MagentaTok     653
#define OrangeTok      654
#define PinkTok        655
#define PinkTintTok    656
#define PurpleTok      657
#define RedTok         658
#define RedOrangeTok   659
#define SeaGreenTok    660
#define SkyBlueTok     661
#define VioletTok      662
#define WhiteTok       663
#define YellowTok      664
#define YellowTintTok  665

#define CPKTok         666
#define ShapelyTok     667
#define ResidueTok     668
#define UserTok        669
#define GroupTok       670
#define ChainTok       671
#define TypeTok        672
#define PotentialTok   673
#define ChargeTok      674
#define CpkNewTok      675

/* Variable Tokens */
#define AmbientTok     680
#define AxesTok        681
#define BackFadeTok    682
#define BackgroundTok  683
#define BondModeTok    684
#define BoundBoxTok    685
#define CisAngleTok    686
#define ContourTok     687
#define DepthCueTok    688
#define FontSizeTok    689
#define FontStrokeTok  690
#define FramesTok      691
#define HourGlassTok   692
#define LevelTok       ContourTok
#define MenusTok       693
#define MouseTok       694
#define PickingTok     695
#define ResolutionTok  696
#define ShadePowerTok  697
#define ShadowTok      698
#define SlabModeTok    699
#define SpacingTok     700
#define SpecularTok    701
#define SpecPowerTok   702
#define SpreadTok      703
#define StrandsTok     704
#define TransparentTok 705
#define UnitCellTok    706
#define WidthTok       SpreadTok

/* SlabMode Tokens */
#define RejectTok      710
#define HalfTok        711
#define HollowTok      712
#define SolidTok       713
#define SectionTok     714

/* MouseMode Tokens */
#define RasMolTok      720
#define InsightTok     721
#define QuantaTok      722
#define SybylTok       723

/* Information Tokens */
#define InfoTok        724
#define SequenceTok    725
#define VersionTok     726
#define PhiPsiTok      727

/* Display Mode Tokens */
#define NormalTok      728
#define StereoTok      729
#define MonoTok        730
#define HardwareTok    731

/* Axis Tokens */
#define XTok           741
#define YTok           742
#define ZTok           743
#define RightTok       744
#define LeftTok        745
#define UpTok          746
#define DownTok        747
#define InTok          748
#define OutTok         749

/* Picking Tokens */
#define IdentifyTok    750
#define CoordTok       751
#define DistanceTok    752
#define AngleTok       753
#define TorsionTok     754
#define OriginTok      755

/* Misc Tokens */
#define InLineTok      760
#define VDWTok         761
#define HeaderTok      762
#define CIFDataTok     763
#define FSTok          764
#define ScaleTok       765

#define PSTok          EPSFTok

/* Clipboard Tokens */
#define ImageTok       770
#define PositionTok    771
#define CopyTok        772
#define PasteTok       773

/* Language Tokens */
#define EnglishTok     800
#define FrenchTok      801
#define GermanTok      802
#define ItalianTok     803
#define SpanishTok     804
#define RussianTok     805
#define ChineseTok     806
#define JapaneseTok    807
#define BulgarianTok   808
int LookUpKeyword( char *ptr );

