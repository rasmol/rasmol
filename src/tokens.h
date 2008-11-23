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
#define AnimateTok     260
#define BackboneTok    262
#define CartoonTok     263
#define CentreTok      264
#define ClipboardTok   265
#define ColourTok      266
#define ColourModeTok  267
#define ConnectTok     268
#define DashTok        269
#define DefineTok      270
#define DelayTok       271
#define DepthTok       272
#define DisplayTok     273
#define EchoTok        274
#define ExitTok        275
#define GenerateTok    276
#define HelpTok        277
#define LabelTok       278
#define LoadTok        279
#define LoopTok        280
#define MapTok         281
#define MaskTok        282
#define MoleculeTok    283
#define MolSurfTok     284 
#define MonitorTok     285
#define MoveTok        286
#define MoveToTok      287
#define NoToggleTok    288
#define PrintTok       289
#define QuitTok        290
#define RefreshTok     291
#define RenumTok       292
#define ResetTok       293
#define ResizeTok      294
#define RestoreTok     295
#define RestrictTok    296
#define RotateTok      297
#define SaveTok        298
#define ScriptTok      299
#define SelectTok      300
#define SetTok         301
#define ShowTok        302
#define SlabTok        303
#define SourceTok      304
#define SpacefillTok   305
#define StarTok        306
#define StructureTok   307
#define SurfaceTok     308
#define SymmetryTok    309
#define TitleTok       310
#define TraceTok       311
#define TranslateTok   312
#define ViewTok        313
#define WaitTok        314
#define WireframeTok   315
#define WriteTok       316
#define ZapTok         317
#define ZoomTok        318

/* Predicate Tokens */
#define IsPredTok(x)   (((x)>=320) && ((x)<=358))
#define PredTokOrd(x)  ((x)-320)
#define PredTokChr(x)  ((x)+320)

#define AlphaTok       320
#define AminoTok       321
#define ATTok          322
#define BondedTok      323
#define CGTok          324
#define CystineTok     325
#define DNATok         326
#define HelixTok       327
#define HeteroTok      328
#define HydrogenTok    329
#define IonTok         330
#define LigandTok      331
#define MainChainTok   332
#define NucleicTok     333
#define ProteinTok     334
#define PurineTok      335
#define PyrimidineTok  336
#define RNATok         337
#define SelectedTok    338
#define SheetTok       339
#define SidechainTok   340
#define SolventTok     341
#define TurnTok        342
#define WaterTok       343

#define AcidicTok      344
#define AcyclicTok     345
#define AliphaticTok   346
#define AromaticTok    347
#define BasicTok       348
#define BuriedTok      349
#define ChargedTok     350
#define CisBondedTok   351
#define CyclicTok      352
#define HydrophobicTok 353
#define LargeTok       354
#define MediumTok      355
#define NeutralTok     356
#define PolarTok       357
#define SmallTok       358



/* Property Tokens */
#define IsPropTok(x)   (((x)>=360) && ((x)<=366))
#define TemperatureTok 360
#define RadiusTok      361
#define AtomNoTok      362
#define ElemNoTok      363
#define ModelTok       364
#define ResNoTok       365
#define AltlTok        366

/* File Format Tokens */
/* Warning! Tokens are related to Format values */
#define IsMoleculeToken(x)  (((x)>=370) && ((x)<=386))

#define PDBTok         370
#define MacroModelTok  371
#define GaussianTok    372
#define AlchemyTok     373
#define NMRPDBTok      374
#define CharmmTok      375
#define BiosymTok      376
#define MOPACTok       377
#define SHELXTok       378
#define Mol2Tok        379
#define FDATTok        380
#define MMDBTok        381
#define MDLTok         382
#define XYZTok         383
#define CIFTok         384
#define CEXTok         385
#define WPDBTok        386

/* Raster Tokens */
#define IsImageToken(x) (((((x)>=390) && ((x)<=409)) || ((x) == PhiPsiTok)))
#define GIFTok         390
#define PPMTok         391
#define SUNTok         392
#define SUNRLETok      393
#define EPSFTok        394
#define PICTTok        395
#define IRISTok        396
#define BMPTok         397
#define MonoPSTok      398
#define JPEGTok        399
#define PNGTok         400
#define VectPSTok      401
#define KinemageTok    402
#define MolScriptTok   403
#define POVRayTok      404
#define POVRay2Tok     404
#define POVRay3Tok     405
#define VRMLTok        406
#define Raster3DTok    407
#define RamachanTok    408  /* ok, this isn't a real image format ... */
#define RamPrintTok    409
#define MirrorTok      410

/* Feature Tokens */
#define AtomTok        421
#define BondTok        422
#define DotsTok        423
#define HBondTok       424
#define RibbonTok      425
#define SSBondTok      426
#define Ribbon1Tok     427
#define Ribbon2Tok     428
#define UnBondTok      429

/* Expression Tokens */
#define TrueTok        430
#define FalseTok       431
#define AllTok         432
#define NoneTok        433
#define AndTok         434
#define OrTok          435
#define NotTok         436
#define WithinTok      437
#define XorTok         438
#define MeanTok        439
#define NextTok        440
#define NewTok         441

/* Colour Tokens */
/* Warning! Tokens are related to colour values */
#define IsColourToken(x) (((x)>=442) && ((x)<=465))
#define Token2Colour(x)  ((x)-442)

#define BlackTok       442
#define BlueTok        443
#define BlueTintTok    444
#define BrownTok       445
#define CyanTok        446
#define GoldTok        447
#define GrayTok        448
#define GreenTok       449
#define GreenBlueTok   450
#define GreenTintTok   451
#define HotPinkTok     452
#define MagentaTok     453
#define OrangeTok      454
#define PinkTok        455
#define PinkTintTok    456
#define PurpleTok      457
#define RedTok         458
#define RedOrangeTok   459
#define SeaGreenTok    460
#define SkyBlueTok     461
#define VioletTok      462
#define WhiteTok       463
#define YellowTok      464
#define YellowTintTok  465

#define CPKTok         466
#define ShapelyTok     467
#define ResidueTok     468
#define UserTok        469
#define GroupTok       470
#define ChainTok       471
#define TypeTok        472
#define PotentialTok   473
#define ChargeTok      474
#define CpkNewTok      475

/* Variable Tokens */
#define AmbientTok     480
#define AxesTok        481
#define BackFadeTok    482
#define BackgroundTok  483
#define BondModeTok    484
#define BoundBoxTok    485
#define CisAngleTok    486
#define ContourTok     487
#define DepthCueTok    488
#define FontSizeTok    489
#define FontStrokeTok  490
#define FramesTok      491
#define HourGlassTok   492
#define LevelTok       ContourTok
#define MenusTok       493
#define MouseTok       494
#define PickingTok     495
#define ResolutionTok  496
#define ShadePowerTok  497
#define ShadowTok      498
#define SlabModeTok    499
#define SpacingTok     500
#define SpecularTok    501
#define SpecPowerTok   502
#define SpreadTok      503
#define StrandsTok     504
#define TransparentTok 505
#define UnitCellTok    506
#define WidthTok       SpreadTok

/* SlabMode Tokens */
#define RejectTok      510
#define HalfTok        511
#define HollowTok      512
#define SolidTok       513
#define SectionTok     514

/* MouseMode Tokens */
#define RasMolTok      520
#define InsightTok     521
#define QuantaTok      522
#define SybylTok       523

/* Information Tokens */
#define InfoTok        524
#define SequenceTok    525
#define VersionTok     526
#define PhiPsiTok      527

/* Display Mode Tokens */
#define NormalTok      528
#define StereoTok      529
#define MonoTok        530
#define HardwareTok    531

/* Axis Tokens */
#define XTok           541
#define YTok           542
#define ZTok           543
#define RightTok       544
#define LeftTok        545
#define UpTok          546
#define DownTok        547
#define InTok          548
#define OutTok         549

/* Picking Tokens */
#define IdentifyTok    550
#define CoordTok       551
#define DistanceTok    552
#define AngleTok       553
#define TorsionTok     554
#define OriginTok      555

/* Misc Tokens */
#define InLineTok      560
#define VDWTok         561
#define HeaderTok      562
#define CIFDataTok     563
#define FSTok          564
#define ScaleTok       565

#define PSTok          EPSFTok

/* Clipboard Tokens */
#define ImageTok       570
#define PositionTok    571
#define CopyTok        572
#define PasteTok       573

/* Language Tokens */
#define EnglishTok     600
#define FrenchTok      601
#define GermanTok      602
#define ItalianTok     603
#define SpanishTok     604
#define RussianTok     605
#define ChineseTok     606
#define JapaneseTok    607
#define BulgarianTok   608
int LookUpKeyword( char *ptr );

