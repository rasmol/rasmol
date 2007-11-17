
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

/* tokens.h
 $Log: not supported by cvs2svn $
 Revision 1.1.1.1  2007/03/01 01:16:32  todorovg
 Chinese working versio from rasmol_ru initial import

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
#define BackboneTok    261
#define CartoonTok     262
#define CentreTok      263
#define ClipboardTok   264
#define ColourTok      265
#define ConnectTok     266
#define DashTok        267
#define DefineTok      268
#define DelayTok       269
#define DepthTok       270
#define DisplayTok     271
#define EchoTok        272
#define ExitTok        273
#define HelpTok        274
#define LabelTok       275
#define LoadTok        276
#define LoopTok        277
#define MoleculeTok    278
#define MolSurfTok     255     // pzh: this may have to be changed 
#define MonitorTok     279
#define MoveTok        280
#define PrintTok       281
#define QuitTok        282
#define RefreshTok     283
#define RenumTok       284
#define ResetTok       285
#define ResizeTok      286
#define RestoreTok     287
#define RestrictTok    288
#define RotateTok      289
#define SaveTok        290
#define ScriptTok      291
#define SelectTok      292
#define SetTok         293
#define ShowTok        294
#define SlabTok        295
#define SourceTok      296
#define SpacefillTok   297
#define StarTok        298
#define StructureTok   299
#define SymmetryTok    300
#define TitleTok       301
#define TraceTok       302
#define TranslateTok   303
#define ViewTok        304
#define WaitTok        305
#define WireframeTok   306
#define WriteTok       307
#define ZapTok         308
#define ZoomTok        309

/* Predicate Tokens */
#define IsPredTok(x)   (((x)>=310) && ((x)<=349))
#define PredTokOrd(x)  ((x)-310)
#define PredTokChr(x)  ((x)+310)

#define AlphaTok       310
#define AminoTok       311
#define ATTok          312
#define BondedTok      313
#define CGTok          314
#define CystineTok     315
#define DNATok         316
#define HelixTok       317
#define HeteroTok      318
#define HydrogenTok    319
#define IonTok         320
#define LigandTok      321
#define MainChainTok   322
#define NucleicTok     323
#define ProteinTok     324
#define PurineTok      325
#define PyrimidineTok  326
#define RNATok         327
#define SelectedTok    328
#define SheetTok       329
#define SidechainTok   330
#define SolventTok     331
#define TurnTok        332
#define WaterTok       333

#define AcidicTok      334
#define AcyclicTok     335
#define AliphaticTok   336
#define AromaticTok    337
#define BasicTok       338
#define BuriedTok      339
#define ChargedTok     340
#define CisBondedTok   341
#define CyclicTok      342
#define HydrophobicTok 343
#define LargeTok       344
#define MediumTok      345
#define NeutralTok     346
#define PolarTok       347
#define SmallTok       348
#define SurfaceTok     349


/* Property Tokens */
#define IsPropTok(x)   (((x)>=350) && ((x)<=356))
#define TemperatureTok 350
#define RadiusTok      351
#define AtomNoTok      352
#define ElemNoTok      353
#define ModelTok       354
#define ResNoTok       355
#define AltlTok        356

/* File Format Tokens */
/* Warning! Tokens are related to Format values */
#define IsMoleculeToken(x)  (((x)>=360) && ((x)<=375))

#define PDBTok         360
#define MacroModelTok  361
#define GaussianTok    362
#define AlchemyTok     363
#define NMRPDBTok      364
#define CharmmTok      365
#define BiosymTok      366
#define MOPACTok       367
#define SHELXTok       368
#define Mol2Tok        369
#define FDATTok        370
#define MMDBTok        371
#define MDLTok         372
#define XYZTok         373
#define CIFTok         374
#define CEXTok         375

/* Raster Tokens */
#define IsImageToken(x) (((((x)>=380) && ((x)<=398)) || ((x) == PhiPsiTok)))
#define GIFTok         380
#define PPMTok         381
#define SUNTok         382
#define SUNRLETok      383
#define EPSFTok        384
#define PICTTok        385
#define IRISTok        386
#define BMPTok         387
#define MonoPSTok      388
#define JPEGTok        389
#define PNGTok         390
#define VectPSTok      391
#define KinemageTok    392
#define MolScriptTok   393
#define POVRayTok      394
#define POVRay2Tok     394
#define POVRay3Tok     395
#define VRMLTok        396
#define RamachanTok    397  /* ok, this isn't a real image format ... */
#define RamPrintTok    398

/* Feature Tokens */
#define AtomTok        400
#define BondTok        401
#define DotsTok        402
#define HBondTok       403
#define RibbonTok      404
#define SSBondTok      405
#define Ribbon1Tok     406
#define Ribbon2Tok     407
#define UnBondTok      408

/* Expression Tokens */
#define TrueTok        410
#define FalseTok       411
#define AllTok         412
#define NoneTok        413
#define AndTok         414
#define OrTok          415
#define NotTok         416
#define WithinTok      417
#define XorTok         418

/* Colour Tokens */
/* Warning! Tokens are related to colour values */
#define IsColourToken(x) (((x)>=420) && ((x)<=443))
#define Token2Colour(x)  ((x)-420)

#define BlackTok       420
#define BlueTok        421
#define BlueTintTok    422
#define BrownTok       423
#define CyanTok        424
#define GoldTok        425
#define GrayTok        426
#define GreenTok       427
#define GreenBlueTok   428
#define GreenTintTok   429
#define HotPinkTok     430
#define MagentaTok     431
#define OrangeTok      432
#define PinkTok        433
#define PinkTintTok    434
#define PurpleTok      435
#define RedTok         436
#define RedOrangeTok   437
#define SeaGreenTok    438
#define SkyBlueTok     439
#define VioletTok      440
#define WhiteTok       441
#define YellowTok      442
#define YellowTintTok  443

#define CPKTok         444
#define ShapelyTok     445
#define ResidueTok     446
#define UserTok        447
#define GroupTok       448
#define ChainTok       449
#define TypeTok        450
#define PotentialTok   451
#define ChargeTok      452
#define CpkNewTok      453

/* Variable Tokens */
#define ShadePowerTok  459
#define AmbientTok     460
#define AxesTok        461
#define BackFadeTok    462
#define BackgroundTok  463
#define BondModeTok    464
#define BoundBoxTok    465
#define CisAngleTok    466
#define DepthCueTok    467
#define FontSizeTok    468
#define FontStrokeTok  469
#define HourGlassTok   470
#define MenusTok       471
#define MouseTok       472
#define PickingTok     473
#define ShadowTok      474
#define SlabModeTok    475
#define SpecularTok    476
#define SpecPowerTok   477
#define StrandsTok     478
#define TransparentTok 479
#define UnitCellTok    480

/* SlabMode Tokens */
#define RejectTok      481
#define HalfTok        482
#define HollowTok      483
#define SolidTok       484
#define SectionTok     485

/* MouseMode Tokens */
#define RasMolTok      486
#define InsightTok     487
#define QuantaTok      488
#define SybylTok       489

/* Information Tokens */
#define InfoTok        490
#define SequenceTok    491
#define VersionTok     492
#define PhiPsiTok      493

/* Display Mode Tokens */
#define NormalTok      495
#define StereoTok      496
#define MonoTok        497
#define HardwareTok    498

/* Axis Tokens */
#define XTok           500
#define YTok           501
#define ZTok           502

/* Picking Tokens */
#define IdentifyTok    505
#define CoordTok       506
#define DistanceTok    507
#define AngleTok       508
#define TorsionTok     509
#define OriginTok      510

/* Misc Tokens */
#define InLineTok      511
#define VDWTok         512
#define HeaderTok      513
#define CIFDataTok     514
#define FSTok          515
#define PSTok          EPSFTok

/* Clipboard Tokens */
#define ImageTok       516
#define PositionTok    517
#define CopyTok        518
#define PasteTok       519

/* Language Tokens */
#define EnglishTok     600
#define FrenchTok      601
#define GermanTok      602
#define ItalianTok     603
#define SpanishTok     604

int LookUpKeyword( char *ptr );

