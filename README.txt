                              R E A D M E
                        R a s M o l   v 2 . 7 . 3
                        =========================
                    Molecular Graphics Visualisation Tool
                             6 February 2005

                     Based on RasMol 2.6 by Roger Sayle
    Biomolecular Structures Group, Glaxo Wellcome Research & Development,
                        Stevenage, Hertfordshire, UK
           Version 2.6, August 1995, Version 2.6.4, December 1998
                    Copyright (C) Roger Sayle 1992-1999

                            and Based on Mods by

   Author             Version, Date             Copyright

   Arne Mueller       RasMol 2.6x1     May 98   (C) Arne Mueller 1998

   Gary Grossman and  RasMol 2.5-ucb   Nov 95   (C) UC Regents/ModularCHEM
   Marco Molinaro     RasMol 2.5-ucb   Nov 96       Consortium 1995, 1996

   Philippe Valadon   RasTop 1.3       Aug 00   (C) Philippe Valadon 2000

   Herbert J.         RasMol 2.7.0     Mar 99   (C) Herbert J. Bernstein
   Bernstein          RasMol 2.7.1     Jun 99       1998-2005
                      RasMol 2.7.1.1   Jan 01
                      RasMol 2.7.2     Aug 00
                      RasMol 2.7.2.1   Apr 01
                      RasMol 2.7.2.1.1 Jan 04
                      RasMol 2.7.3     Feb 05

   with RasMol 2.7.3 incorporating changes by Clarice Chigbo, Ricky Chachra,
   and Mamoru Yamanishi

                     and Incorporating Translations by

   Author                               Item                     Language

   Isabel Servan Martinez,              2.6 Manual               Spanish
   Jose Miguel Fernandez Fernandez
   Jose Miguel Fernandez Fernandez      2.7.1 Manual             Spanish
   Fernando Gabriel Ranea               2.7.1 menus and messages Spanish

   Jean-Pierre Demailly                 2.7.1 menus and messages French

   Giuseppe Martini, Giovanni Paolella, 2.7.1 menus and messages Italian
   A. Davassi, M. Masullo, C. Liotto    2.7.1 help file

                              This Release by
   Herbert J. Bernstein, Bernstein + Sons, P.O. Box 177, Bellport, NY, USA
                        yaya@bernstein-plus-sons.com
                Copyright (C) Herbert J. Bernstein 1998-2005

   The original RasMol manual was created by Roger Sayle.  In July 1996,
   Dr. Margaret Wong of the Chemistry Department, Swinburne University
   of Technology, Australia, made extensive revisions to the RasMol 2.5
   manual to accurately reflect the operation of RasMol 2.6.  Eric Martz
   of the University of Massachusetts made further revisions.  In May
   1997, William McClure of Carnegie Mellon University reorganized the
   HTML version of the manual into multiple sections which could be
   downloaded quickly and added use of frames.   Portions of the 2.7.1
   version of the RasMol manual were derived with permission from
   William McClure's version using Roger Sayle's rasmol.doc for
   version 2.6.4 as the primary source. Changes were made in August 2000 for
   RasMol version 2.7.2, January 2001 for RasMol version 2.7.1.1, April 2001
   for RasMol version 2.7.2.1 and February 2005 for RasMol version 2.7.3.

                  Documentation Last Updated 19 April 2005
            Edited by Herbert J. Bernstein and Frances C. Bernstein

                                Translations

   Thanks to the efforts of Jose Miguel Fernandez Fernandez (Departamento
   de Bioquimica y Biologia Molecular. Universidad de Granada. Espana
   (jmfernan@ugr.es)) a translation of the Manual for Rasmol version
   2.7.1 into Spanish is now available. La traduccion espanola del manual
   de la version de la Dra. Wong revisada por Eric Martz fue realizada
   por Isabel Servan Martinez y Jose Miguel Fernandez Fernandez. La
   actual traduccion del Manual de RasMol 2.7.1 ha sido realizada usando
   como base la anterior de RasMol 2.6 por  Jose Miguel Fernandez
   Fernandez.

   Thanks to translations by Fernando Gabriel Ranea in late 2000 and
   early 2001, RasMol is now capable of rendering most menu items and
   messages in Spanish. Jean-Pierre Demailly provided French translations
   of menus and messages in January 2001. Giuseppe Martini and Giovanni
   Paolella with contributions by A. Davassi, M. Masullo and C. Liotto
   provided Italian translation of menus and messages in March 2001.

     _______________________________________________________________________________________

                 THIS IS A PRELIMINARY RELEASE INVOLVING EXTENSIVE MODIFICATIONS
                                  ***** USE WITH CAUTION ******
     _______________________________________________________________________________________

                                            IMPORTANT

   This version is based in directly on RasMol version 2.7.2.1.1, on RasMol version 2.7.2, on
   RasMol version 2.7.1, on RasMol version 2.6_CIF.2, on RasMol version 2.6x1, on RasMol
   version 2.6.4, and RasMol 2.5-ucb and 2.6-ucb.

   Please read the file NOTICE for important notices which apply to this package and for
   license terms (GPL  or RASLIC).
     _________________________________________________________________

                                  Contents

     * IMPORTANT - Copying and Distribution
     * Installation Instructions
     * Changes
     * Things To Do
     * Introduction
     * Source Code and Binaries
     * Directories
          + ChangeLog -- Full ChangeLog directory
          + src -- source code
               o mac -- Macintosh build directory
               o mswin -- Windows build directory
          + doc -- documentation
          + data -- sample data files
     _________________________________________________________________

                                Introduction

   This posting is made to announce the releases of RasMol version 2.7.3.
   This release is based on RasMol 2.7.2.1.1, the final reference release
   for the 2.7.2 series. The changes for the 2.7.3 release include:
     * Adjustment to the mouse handling for a better, more natural feel.
       Our thanks to C. Chigbo for the suggestion.
     * Correction to cif.c for blanks after an initial quote mark.
       cif.c.patch
     * Correction to mswin31.c to restore lost initializations of ZRange
       and DialValue[8..9]. mswin31.c.patch
     * Correction to vector.c for nested bond rotations. vector.c.patch
     * Modifications by Mamoru Yamanishi to Imakefile and rasmol.c to use
       xforms for GUI file open. xforms.patch. This patch needs the opens
       source xforms 1.0.90 library by Steve Lamont (see the source at
       http://savannah.nongnu.org/download/xforms/xforms-1.0.90.tar.gz).
       The cummulative patch is given in the link above. The individual
       patches are available at xforms/
     * Correction to molecule.c to correct input of xyz files. Thanks to
       Stuart Prescott. molecule.c2.patch. (Revised 20 Jan 2005).
     * Revision to CPK colors by C. Chigbo. cpknew.patch. The new colors
       are called CPKNEW. The current CPK colors remain available as CPK.
       (Revised 16 Jan 2005 by HJB).
     * Correction to negative torsion angle monitors and to imprecise
       distance and angle monitors by C. Chigbo. datconsis.patch.
       (Revised 16 Jan 2005). This patch corrects the display of negative
       torsion angles caused by use of the unsigned short type, and
       correctys imprecise distance and angle displays. This extends the
       original patch which was just for torsion angles (torsion.patch).
       A side effect of this change is to limit the available range for
       distance monitors to approximately 327 Ångstroms.
     * Initial code for display of solid Lee-Richards molecular surfaces.
       surface3.patch. (Rev 20 Jan 05). This patch adds the basic code
       for display of Lee-Richards surfaces with a new Molecular Surface
       menu item, and surface molecule <probe radius> and surface solvent
       <probe radius> commands. Two other, related, major patches are
       pending that depend upon this one: code by P. Zhivkov to simulate
       surfaces efficiently by blurring and code to display surfaces
       using OpenGL.
     * Corrections of ribbons 0, etc. commands by R. Chachra.
       comb3.patch. (Revised 18 Jan 05). With this patch, the wireframe
       0, ribbon 0, cartoon 0, backbone 0, strands 0 and trace 0 commands
       work the same as these command with off instead of 0.

   The 2.7.2.1.1 release was the final reference release for the 2.7.2
   series prior to the creation of version 2.7.3. For most users there
   should be no operational changes from version 2.7.2.1, except for the
   correction to the loading of PDB exchange dictionary CIFS.

   Post release patches to command.c were included to fix the handling of
   load inline in the UCB multiple molecule environment. In addition
   conditional code controlled by STRICT was disabled to restore
   operation of load inline under windows. Thanks to Jan Reichert
   <jr@imb-jena.de> for pointing out these problems. Thanks to E. Martz
   <emartz@microbio.umass.edu> for pointing out an error in the Spanish
   translation credits which has been corrected. Thanks to a report by
   Julien Hering, the omission of a prior fix to the MS Windows version
   was found and corrected on 7 May 2004.

   The April 2001 posting was made to announce the release of RasMol
   version 2.7.2.1, which made the following changes to RasMol 2.7.2,
   incorporating changes from RasMol 2.7.1.1 and some changes from RasTop
   1.3:
     * Adaption of the multilingual mods from RasMol 2.7.1.1 into Rasmol
       2.7.2.1.
     * Rewrite of the mouse handling and rotation logic to correct the
       problems in 2.7.2 and make the feel of 2.7.2.1 closer to that of
       RasMol 2.7.1.
     * Addition of French menus and messages
     * Addition of Italian menus and messages
     * Adoption of picking for selection of atoms, groups or chains from
       RasTop 1.3.
     * Adoption of backclipping from RasTop 1.3
     * Adoption of shadepower command for glassy surfaces from RasTop 1.3
     * Change of the menu stereo option to rotate cross-wall-none
     * Allow longer atom names (12 characters) in CIFs.

   The release of RasMol version 2.7.1.1 made the following changes to
   RasMol 2.7.1:
     * Introduction of a multilingual structure for RasMol.
     * Population of messages and menu lists for English and Spanish.
     * Upgrade of some of the Windows printer logic
     * Correction of coordinate handling for Mol2 and XYZ coordinates
     * Fix to the parsing of D2O.

   That was an interim release to facillitate testing of the new
   multilingual capabilities. Our thanks to Fernando Gabriel Ranea for
   doing the hard work of creating an initial Spanish translation of
   RasMol 2.7.1. We have created this new version to allow on-the-fly
   switching among langauges. Use the command "Spanish" to request
   Spanish messages and menus, and "English" to return to the original
   English format. Corrections and translations for additional languages
   greatly appreciated.

   The release of RasMol version 2.7.2, made the following changes to
   RasMol 2.7.1:
     * Incorporation of some of the code from the UCB RasMol variants.
       Out thanks to Eileen Lewis and Marco Molinaro for their
       cooperation in contributing the UCB Enhanced RasMol code for
       incorporation into the RasMol 2.7 series.
     * Code to represent bonds in and to alternate conformers with a
       narrowed portion in the middle of each bond.
     * An attempt to fix some of the chirality reversals in some of the
       output modes.
     * Fixes for some of the problems reported since the last release.

   This release does not include the toolbar from the UCB mods. In order
   to resolve some cross-platform issues we have started incorporation of
   the UCB code for multiple molecules and bond rotation by adding to the
   command interface and to the menus. We expect to be able to add a
   toolbar in a future release.

   This release is not fully debugged and has some serious problems. This
   release is intended for testing and experimentation and not for
   production use. Comments and suggestions would be appreciated. We are
   aware fo the following deficiencies:
     * RasMol may have difficulty in allocating colors for molecules
       after the first. The fix for this interacts with some other
       pending changes, and should be ready for the next release.
     * As has been true for all recent versions, the stereo mode defaults
       to cross-eyed, which is inconvenient for many users. The next
       release will allow cross-eyed and wall-eyed stereo to be selected
       from the menus.
     * Printing under windows is not working for many modern systems. We
       hope to have a fix for the next release.
     * The fixes for several of the bugs reported against RasMol 2.7.1
       have not been incorporated into RasMol 2.7.2 yet. Our apologies.
       If you previously reported a bug in RasMol 2.7.1 which still
       exists in 2.7.2, you may resubmit your report, but there is no
       need to do so.

   The release of RasMol version 2.7.1 made the following changes to
   RasMol 2.7.0:
     * The ability to automatically mark non bonded atoms in wireframe
       and stick displays. Our thanks to R. Curtis Haltiwanger for
       suggesting this change.
     * The ability to use a proportionally spaced font and to draw labels
       with heavier strokes. Our thanks to Eric Martz for suggesting this
       change.
     * The ability to auto-recognize PDB vs. CIF and mmCIF datasets.
     * Extensive updating to the manual. Our thanks to William McClure,
       Margaret Wong, Eric Martz and Frances Bernstein.
     * Updating the canvas title with the PDB ID code and EXPDTA
       information, so models will be clearly distinguished from
       experimental data. Our thanks to Helen Berman for suggesting this
       change.
     * The ability to report coordinates.
     * Additions to the list of pre-defined colours.
     * Improved accuracy of coordinates in pseudo-PDB output.
     * Fixes to the centering logic.

   RasMol version 2.7.0.1 was a technically minor, but operationally
   critical upgrade to version 2.7.0, correcting a serious error in the
   selection logic introduced in the process of merging versions to
   create version 2.7.0.

   RasMol version 2.7.0 combined Roger Sayle's version 2.6.4 with Herbert
   Bernstein's CIF modified version 2.6_CIF(Rev 2) and with Arne
   Mueller's version 2.6x1. This combined version allows selection by
   alternate conformers as well as by models, production of Ramachandran
   printer plots (as in F. Bernstein's fisipl), and access to A.
   Mueller's POVray output as POVray3 in addition to the existing POVray
   version 2 output. (POVray3 should not be used in the PC or Mac
   version, yet).

   RasMol version 2.6x1 was an upgrade to RasMol by Arne Mueller to add
   code to allow listing of information about the chains, groups or atoms
   in a selection, listing of phi-psi, allow selection by cis angle
   cutoff, and to provide a POV-Ray version 3 output.

   RasMol version 2.6.4 was a major code cleanup and reorganization by
   Roger Sayle, dropping obsolete non-ANSI C options and providing speed
   improvments.

   RasMol version 2.6_CIF(Rev 2) added pre-compiled binaries for OpenVMS
   7.1 (DEC Alpha) and OpenVMS 6.2 (DEC VAX) and replaced the binary for
   68K Apple MacIntoshes in RasMol version 2.6_CIF(Rev 1).

   Rasmol version 2.6_CIF(Rev 1) was a minor update to RasMol version
   2.6_CIF, which added support for alternate conformer coloring of small
   molecule CIFs, using _atom_site_disorder_group, recognizes requests
   for bonds which have neither atom names nor atom numbers, ensures
   zapping of existing bonds when connect command is used.

   RasMol version 2.6_CIF added several new features to RasMol:

     * Support for reading IUCr CIF and mmCIF format;
     * Coloring for alternate conformers and multiple NMR models;
     * Display of all NMR models in a data set.

   This version is available for the Apple Macintosh and PowerMac in
   addition to UNIX, VMS and Microsoft Windows versions. However, because
   of limitations in the memory management under MacOS, very large
   multiple NMR model datasets are not supported on the Mac or PowerMac
   at this time.

   For a complete list of changes from RasMol 2.6 refer to the
   distribution's "ChangeLog".

   For installation instructions see "INSTALL".

   For a list of open issues in this version, see "TODO". Roger Sayle's
   prior list of pending projects is in "PROJECTS".

   RasMol is a molecular graphics program intended for the visualisation
   of proteins, nucleic acids and small molecules. The program is aimed
   at display, teaching and generation of publication quality images. The
   program has been developed at the University of Edinburgh's
   Biocomputing Research Unit and the Biomolecular Structures Group at
   Glaxo Research and Development, Greenford, UK.

   RasMol reads in molecular co-ordinate files in a number of formats and
   interactively displays the molecule on the screen in a variety of
   colour schemes and representations. Currently supported input file
   formats include Brookhaven Protein Databank (PDB), Tripos' Alchemy and
   Sybyl Mol2 formats, Molecular Design Limited's (MDL) Mol file format,
   Minnesota Supercomputer Center's (MSC) XMol XYZ format, CHARMm format,
   MOPAC format, CIF format and mmCIF format files. If connectivity
   information and/or secondary structure information is not contained in
   the file this is calculated automatically. The loaded molecule may be
   shown as wireframe, cylinder (drieding) stick bonds, alpha-carbon
   trace, spacefilling (CPK) spheres, macromolecular ribbons (either
   smooth shaded solid ribbons or parallel strands), hydrogen bonding and
   dot surface. Atoms may also be labelled with arbitrary text strings.
   Alternate conformers and multiple NMR models may be specially coloured
   and identified in atom labels. Different parts of the molecule may be
   displayed and coloured independently of the rest of the molecule or
   shown in different representations simultaneously. The space filling
   spheres can even be shadowed. The displayed molecule may be rotated,
   translated, zoomed, z-clipped (slabbed) interactively using either the
   mouse, the scroll bars, the command line or an attached dials box.
   RasMol can read a prepared list of commands from a `script' file (or
   via interprocess communication) to allow a given image or viewpoint to
   be restored quickly. RasMol can also create a script file containing
   the commands required to regenerate the current image. Finally the
   rendered image may be written out in a variety of formats including
   both raster and vector PostScript, GIF, PPM, BMP, PICT, Sun rasterfile
   or as a MolScript input script or Kinemage.

   RasMol will run on a wide range of architectures and systems including
   SGI, sun4, sun3, sun386i, SGI, DEC, HP and E&S workstations, IBM
   RS/6000, Cray, Sequent, DEC Alpha (OSF/1, OpenVMS and Windows NT), IBM
   PC (under Microsoft Windows, Windows NT, OS/2, Linux, BSD386 and
   *BSD), Apple Macintosh (System 7.0 or later), PowerMac and VAX VMS
   (under DEC Windows). UNIX and VMS versions require an 8bit, 24bit or
   32bit X Windows frame buffer (X11R4 or later). The X Windows version
   of RasMol provides optional support for a hardware dials box and
   accelerated shared memory rendering (via the XInput and MIT-SHM
   extensions) if available.

   Reports of builds and/or problems on various platforms appreciated.
     _________________________________________________________________

                          Source Code and Binaries

   The complete source code and user documentation of RasMol 2.7.3 may be
   obtained by anonymous FTP at:

   ftp://ftp.bernstein-plus-sons.com/software/RasMol_2.7.3.tar.gz

   or on the web at:

   http://www.bernstein-plus-sons.com/software/RasMol_2.7.3.tar.gz

   The source code and documentation are stored in several files
   appropriate for the receiving operating system. Please read the
   "README" file in the distribution directory. See the table below for
   appropriate binaries. Mac and Windows binaries are no longer included
   on the tar. Unix and VMS users should retrieve the same file for
   source code and documentation, and one or more of the following
   pre-compiled binaries: WARNING: ALL binaries are gzipped!!!.
   Uncompressed binaries are also available in the second section of each
   page.

                    DEC/Compaq/HP:          RasMol.DEC
                    HP:                     RasMol.HP
                    Linux (RedHat 7, i386): RasMol.LINUX
                    Mac:                    RasMol.MAC
                    MS Windows:             RasMol.MSWIN
                    RS/6000:                RasMol.RS6K
                    SGI:                    RasMol.SGI

   You will need both an appropriate binary and a copy of rasmol.hlp for
   each system, and, under Windows, a copy of raswin.hlp for the WinHelp
   sub-system.

   Please remember to use "binary" mode when transferring these files
   between systems. Check that the file size is the same before and after
   transfer.

   Any comments, suggestions or questions about this modified version of
   RasMol should be directed to rasmol@bernstein-plus-sons.com.

     _________________________________________________________________

   Updated 29 April 2005.
   Herbert J. Bernstein
   Bernstein + Sons, 5 Brewster Lane, Bellport, NY 11713-2803, USA
   yaya@bernstein-plus-sons.com
