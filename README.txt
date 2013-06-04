                                     README
                                 RasMol 2.7.5.2

  * RasMol Latest Windows                            * RasMol 2.7.5.2 Windows    
    Installer                                          Installer                 
                                                                                 
  * RasMol Latest Source                             * RasMol 2.7.5.2 Source     
    Tarball                          RasMol            Tarball                   
                                                                                 
  * RasMol Latest Manual                             * RasMol 2.7.5 Manual       
                                                                                 
  * Donate to Support RasMol                         * Donate to Support RasMol  
  * Register your RasMol                             * Register your RasMol      

                     Molecular Graphics Visualisation Tool
                         3 June 2009 (rev. 13 May 2011)

                       Based on RasMol 2.6 by Roger Sayle
Biomolecular Structures Group, Glaxo Wellcome Research & Development, Stevenage,
                               Hertfordshire, UK
             Version 2.6, August 1995, Version 2.6.4, December 1998
                      Copyright (c) Roger Sayle 1992-1999

                              and Based on Mods by

+------------------------------------------------------------------------------+
| Author            | Version, Date        | Copyright                         |
|-------------------+----------------------+-----------------------------------|
| Arne Mueller      | RasMol 2.6x1 May     | (c) Arne Mueller 1998             |
|                   | 1998                 |                                   |
|-------------------+----------------------+-----------------------------------|
| Gary Grossman and | RasMol 2.5-ucb       | (c) UC Regents/ModularCHEM        |
| Marco Molinaro    | November 1995        | Consortium 1995, 1996             |
|                   | RasMol 2.6-ucb       |                                   |
|                   | November 1996        |                                   |
|-------------------+----------------------+-----------------------------------|
| Philippe Valadon  | RasTop 1.3 August    | (c) Philippe Valadon 2000         |
|                   | 2000                 |                                   |
|-------------------+----------------------+-----------------------------------|
| Herbert J.        | RasMol 2.7.0 March   | (c) Herbert J. Bernstein          |
| Bernstein         | 1999                 | 1998-2009                         |
|                   | RasMol 2.7.1 June    |                                   |
|                   | 1999                 |                                   |
|                   | RasMol 2.7.1.1       |                                   |
|                   | January 2001         |                                   |
|                   | RasMol 2.7.2 August  |                                   |
|                   | 2000                 |                                   |
|                   | RasMol 2.7.2.1 April |                                   |
|                   | 2001                 |                                   |
|                   | RasMol 2.7.2.1.1     |                                   |
|                   | January 2004         |                                   |
|                   | RasMol 2.7.3         |                                   |
|                   | February 2005        |                                   |
|                   | RasMol 2.7.3.1 Apr   |                                   |
|                   | 06                   |                                   |
|                   | RasMol 2.7.4 Nov 07  |                                   |
|                   | RasMol 2.7.4.1 Jan   |                                   |
|                   | 08                   |                                   |
|                   | RasMol 2.7.4.2 Mar   |                                   |
|                   | 08                   |                                   |
|                   | RasMol 2.7.5 June    |                                   |
|                   | 2009                 |                                   |
|                   | RasMol 2.7.5.1 July  |                                   |
|                   | 2009                 |                                   |
|                   | RasMol 2.7.5.2 May   |                                   |
|                   | 2011                 |                                   |
+------------------------------------------------------------------------------+

   RasMol 2.7.5 incorporates changes by T. Ikonen, G. McQuillan, N. Darakev
   and L. Andrews (via the neartree package). Work on RasMol 2.7.5 supported
   in part by grant 1R15GM078077-01 from the National Institute of General
   Medical Sciences (NIGMS), U.S. National Institutes of Health and by grant
   ER63601-1021466-0009501 from the Office of Biological & Environmental
   Research (BER), Office of Science, U. S. Department of Energy. RasMol
   2.7.4 incorporated changes by G. Todorov, Nan Jia, N. Darakev, P.
   Kamburov, G. McQuillan, and J. Jemilawon. Work on RasMol 2.7.4 supported
   in part by grant 1R15GM078077-01 from the NIGMS/NIH and grant
   ER63601-1021466-0009501 from BER/DOE. RasMol 2.7.3 incorporates changes by
   Clarice Chigbo, Ricky Chachra, and Mamoru Yamanishi. Work on RasMol 2.7.3
   supported in part by grants DBI-0203064, DBI-0315281 and EF-0312612 from
   the U.S. National Science Foundation and grant DE-FG02-03ER63601 from
   BER/DOE. The content is solely the responsibility of the authors and does
   not necessarily represent the official views of the funding organizations.

   The code for use of RasMol under GTK in RasMol 2.7.4.2 was written by
   Teemu Ikonen.
                       and Incorporating Translations by

+-----------------------------------------------------------------------------+
| Author                               | Item                     | Language  |
|--------------------------------------+--------------------------+-----------|
| Isabel Servan Martinez,              | 2.6 Manual               | Spanish   |
| Jose Miguel Fernandez Fernandez      |                          |           |
|--------------------------------------+--------------------------+-----------|
| Jose Miguel Fernandez Fernandez      | 2.7.1 Manual             | Spanish   |
|--------------------------------------+--------------------------+-----------|
| Fernando Gabriel Ranea               | 2.7.1 menus and messages | Spanish   |
|--------------------------------------+--------------------------+-----------|
| Jean-Pierre Demailly                 | 2.7.1 menus and messages | French    |
|--------------------------------------+--------------------------+-----------|
| Giuseppe Martini, Giovanni Paolella, | 2.7.1 menus and messages | Italian   |
| A. Davassi, M. Masullo, C. Liotto    | 2.7.1 help file          |           |
|--------------------------------------+--------------------------+-----------|
| G. Pozhvanov                         | 2.7.3 menus and messages | Russian   |
|--------------------------------------+--------------------------+-----------|
| G. Todorov                           | 2.7.3 menus and messages | Bulgarian |
|--------------------------------------+--------------------------+-----------|
| Nan Jia, G. Todorov                  | 2.7.3 menus and messages | Chinese   |
|--------------------------------------+--------------------------+-----------|
| Mamoru Yamanishi, Katajima Hajime    | 2.7.3 menus and messages | Japanese  |
+-----------------------------------------------------------------------------+

                                This Release by
   Herbert J. Bernstein, Bernstein + Sons, 5 Brewster Lane, Bellport, NY, USA
                          yaya@bernstein-plus-sons.com
                  Copyright (c) Herbert J. Bernstein 1998-2009

   The original RasMol manual was created by Roger Sayle. In July 1996, Dr.
   Margaret Wong of the Chemistry Department, Swinburne University of
   Technology, Australia, made extensive revisions to the RasMol 2.5 manual
   to accurately reflect the operation of RasMol 2.6. Eric Martz of the
   University of Massachusetts made further revisions. In May 1997, William
   McClure of Carnegie Mellon University reorganized the HTML version of the
   manual into multiple sections which could be downloaded quickly and added
   use of frames. Portions of the 2.7.1 version of the RasMol manual were
   derived with permission from William McClure's version using Roger Sayle's
   rasmol.doc for version 2.6.4 as the primary source. Changes were made in
   August 2000 for RasMol version 2.7.2, January 2001 for RasMol version
   2.7.1.1 and April 2001 for RasMol version 2.7.2.1 and February 2005 for
   RasMol version 2.7.3.

                     Documentation Last Updated 14 May 2011
            Edited by Herbert J. Bernstein and Frances C. Bernstein

                                  Translations

   Thanks to the efforts of Jose Miguel Fernandez Fernandez (Departamento de
   Bioquimica y Biologia Molecular. Universidad de Granada. Espana
   (jmfernan@ugr.es)) a translation of the Manual for Rasmol version 2.7.1
   into Spanish is now available. La traduccion espanola del manual de la
   version de la Dra. Wong revisada por Eric Martz fue realizada por Isabel
   Servan Martinez y Jose Miguel Fernandez Fernandez. La actual traduccion
   del Manual de RasMol 2.7.1 ha sido realizada usando como base la anterior
   de RasMol 2.6 por  Jose Miguel Fernandez Fernandez.

   Thanks to translations by Fernando Gabriel Ranea <davinci@dinamica.com.ar>
   in late 2000 and early 2001, RasMol is now capable of rendering most menu
   items and messages in Spanish. Jean-Pierre Demailly
   <Jean-Pierre.Demailly@ujf-grenoble.fr> provided French translations of
   menus and messages in January 2001. Giuseppe Martini
   <martini@iigb.na.cnr.it> and Giovanni Paolella <paolella@dbbm.unina.it>
   with contributions by A. Davassi, M. Masullo and C. Liotto provided
   Italian translations of menus and messages in March 2001.

     ----------------------------------------------------------------------

                      IMPORTANT - Copying and Distribution

   This version is based directly on RasMol version 2.7.5.1, on RasMol
   version 2.7.4.2, on RasMol version 2.7.4.1, on RasMol version 2.7.4, on
   RasMol version 2.7.3.1, on RasMol version 2.7.3, on RasMol version
   2.7.2.1.1, on RasMol version 2.7.2, on RasMol version 2.7.1, on RasMol
   version 2.6_CIF.2, on RasMol version 2.6x1, on RasMol version 2.6.4, and
   RasMol 2.5-ucb and 2.6-ucb.

   Please read the file NOTICE for important notices which apply to this
   package and for license terms (GPL or RASLIC).

     ----------------------------------------------------------------------

  Contents

     * IMPORTANT - Copying and Distribution
     * Installation Instructions
     * Changes
     * Things To Do
     * Introduction
     * Source Code and Binaries
     * Directories
          * ChangeLog -- Full ChangeLog directory
          * src -- source code
               * mac -- Macintosh build directory
               * mswin -- Windows build directory
          * doc -- documentation
          * data -- sample data files

     ----------------------------------------------------------------------

                                  Introduction

   This posting is made to announce the release of RasMol version 2.7.5.2
   This release is based on RasMol 2.7.5.1.

   This is a final update to the 2.7.5 series before release of the 2.7.6
   release candidates, correcting some minor bugs and speeding up surface
   renderings by use of NearTree 3.1. The version of CBFlib used has also
   been updated. The changes made between the 2.7.5.1 release of 23 July 2009
   and the 2.7.5.2 release were:

     * Faster surface rendering by use of NearTree 3.1
     * Updates to GTK version from T. Ikonen
     * Use of CBFlib 0.9.2
     * Use of CQRlib 1.1.2
     * Minor bug fixes

   The changes made between the 2.7.5 release candidate release of 17 July
   2009 and the formal release on 23 July 2009 were:
     * Correction to the support for core CIF data file loads that was
       disabled in the move to CBFlib in place of the internal CIF support.
     * Correction to the CCP4 map read logic in the case of symmetry lines.
       Thanks to Marian Szebenyi for finding this bug.
     * Clarification to the install instructions for 64-bit unix systems.
       Thanks to Marian Szebenyi and Mark Diekhans for pointing out the lack
       of clarity.

   The major changes from the 2.7.4.2 release to the 2.7.5 release include:
     * Support for SBEVSL movie commands.
     * Support for Lee-Richards surface approximation by contouring
       pseudo-Gaussian electron densities.
     * Selection of atoms by proximity to map contours
     * Coloring of maps by the colors of neighboring atoms
     * Significant improvements to the GTK version by Teemu Ikonen
   The 2.7.4.2 release was based on RasMol 2.7.4 and RasMol 2.7.4.1 and
   RasMol 2.7.3.1, the final reference release for the 2.7.3 series. The
   changes from the 2.7.3.1 release to the 2.7.4.1 release included:
     * Support for maps.
     * Message and menu translations for Russian, Bulgarian, Japanese and
       Chinese. Our thanks to G. Pozhvanov, G. Todorov, Nan Jia, Mamoru
       Yamanishi and Katajima Hajime.
     * Fix torsion angle calculation as per bug report and patch by Swati
       Jain.
     * Corrections by Ladislav Michnovic to port to more platforms.
     * Code to read remediated PDB entries as suggested by Huanwang Yang
     * Updated icons.
     * Extended export menus.
   For more detail on these and earlier changes, consult the openrasmol svn
   repository on sourceforge.

   This version is available for MS Windows and various unix-systems. As
   binaries become available, they will be released on
   http://blondie.dowling.edu/projects/rasmol and
   http:/www.sourceforge.net/projects/openrasmol.

   For installation instructions see "INSTALL".

   For a list of open issues in this version, see "TODO".

   RasMol is a molecular graphics program intended for the visualisation of
   proteins, nucleic acids and small molecules. The program is aimed at
   display, teaching and generation of publication quality images. The
   original program was been developed at the University of Edinburgh's
   Biocomputing Research Unit and the Biomolecular Structures Group at Glaxo
   Research and Development, Greenford, UK.

   RasMol reads in molecular co-ordinate files in a number of formats and
   interactively displays the molecule on the screen in a variety of colour
   schemes and representations. Currently supported input file formats
   include Brookhaven Protein Databank (PDB), Tripos' Alchemy and Sybyl Mol2
   formats, Molecular Design Limited's (MDL) Mol file format, Minnesota
   Supercomputer Center's (MSC) XMol XYZ format, CHARMm format, MOPAC format,
   CIF format and mmCIF format files. If connectivity information and/or
   secondary structure information is not contained in the file this is
   calculated automatically. The loaded molecule may be shown as wireframe,
   cylinder (drieding) stick bonds, alpha-carbon trace, spacefilling (CPK)
   spheres, macromolecular ribbons (either smooth shaded solid ribbons or
   parallel strands), hydrogen bonding and dot surface. Atoms may also be
   labelled with arbitrary text strings. Alternate conformers and multiple
   NMR models may be specially coloured and identified in atom labels.
   Different parts of the molecule may be displayed and coloured
   independently of the rest of the molecule or shown in different
   representations simultaneously. The space filling spheres can even be
   shadowed. The displayed molecule may be rotated, translated, zoomed,
   z-clipped (slabbed) interactively using either the mouse, the scroll bars,
   the command line or an attached dials box. RasMol can read a prepared list
   of commands from a `script' file (or via interprocess communication) to
   allow a given image or viewpoint to be restored quickly. RasMol can also
   create a script file containing the commands required to regenerate the
   current image. Finally the rendered image may be written out in a variety
   of formats including both raster and vector PostScript, GIF, PPM, BMP,
   PICT, Sun rasterfile or as a MolScript input script or Kinemage.

   Versions of RasMol have run on a wide range of architectures and systems
   including SGI, sun4, sun3, sun386i, SGI, DEC, HP and E&S workstations, IBM
   RS/6000, Cray, Sequent, DEC Alpha (OSF/1, OpenVMS and Windows NT), IBM PC
   (under Microsoft Windows, Windows NT, OS/2, Linux, BSD386 and *BSD), Apple
   Macintosh (System 7.0 or later), PowerMac and VAX VMS (under DEC Windows).
   UNIX and VMS versions require an 8bit, 24bit or 32bit X Windows frame
   buffer (X11R4 or later). The X Windows version of RasMol provides optional
   support for a hardware dials box and accelerated shared memory rendering
   (via the XInput and MIT-SHM extensions) if available.

   Reports of builds and/or problems on various platforms appreciated.

     ----------------------------------------------------------------------

                            Source Code and Binaries

   The complete source code and user documentation of RasMol 2.7.5.2 may be
   obtained http://www.sourceforge.net/projects/rasmol. and by anonymous FTP
   at:

   ftp://ftp.bernstein-plus-sons.com/software/RasMol_2.7.5.2.tar.gz

   or on the web at:

   http://www.bernstein-plus-sons.com/software/RasMol_2.7.5.2.tar.gz

   http://www.sourceforge.net/projects/rasmol.

     Any comments, suggestions or questions about this modified version of
          RasMol should be directed to rasmol@bernstein-plus-sons.com.

| OpenRasMol | Copying and Distribution | Contents | Installation Instructions |
      | Changes | Things To Do | Introduction | Source Code and Binaries |
| RasMol Manual | Spanish Translation of RasMol Manual | Italian Translation of
                            RasMol 2.7.1 Help File |
      | Donate to Support RasMol | Release README | Register your RasMol |

     ----------------------------------------------------------------------

                              Updated 14 May 2011.
                              Herbert J. Bernstein
        Bernstein + Sons, 5 Brewster Lane, Bellport, NY 11713-2803, USA
                          yaya@bernstein-plus-sons.com
