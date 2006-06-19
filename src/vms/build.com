$!###########################################################################
$!#                              RasMol 2.7.1                               # 
$!#                                                                         #
$!#                                 RasMol                                  #
$!#                 Molecular Graphics Visualisation Tool                   #
$!#                              22 June 1999                               #
$!#                                                                         #
$!#                   Based on RasMol 2.6 by Roger Sayle                    #
$!# Biomolecular Structures Group, Glaxo Wellcome Research & Development,   #
$!#                      Stevenage, Hertfordshire, UK                       #
$!#         Version 2.6, August 1995, Version 2.6.4, December 1998          #
$!#                   Copyright (C) Roger Sayle 1992-1999                   #
$!#                                                                         #
$!#                  and Based on Mods by Arne Mueller                      #
$!#                      Version 2.6x1, May 1998                            #
$!#                   Copyright (C) Arne Mueller 1998                       #
$!#                                                                         #
$!#           Version 2.7.0, 2.7.1 Mods by Herbert J. Bernstein             #
$!#           Bernstein + Sons, P.O. Box 177, Bellport, NY, USA             #
$!#                      yaya@bernstein-plus-sons.com                       #
$!#                    2.7.0 March 1999, 2.7.1 June 1999                    #
$!#              Copyright (C) Herbert J. Bernstein 1998-1999               #
$!#                                                                         #
$!# Please read the file NOTICE for important notices which apply to this   #
$!# package. If you are not going to make changes to RasMol, you are not    # 
$!# only permitted to freely make copies and distribute them, you are       # 
$!# encouraged to do so, provided you do the following:                     #
$!#   * 1. Either include the complete documentation, especially the file   #
$!#     NOTICE, with what you distribute or provide a clear indication      #
$!#     where people can get a copy of the documentation; and               #
$!#   * 2. Please give credit where credit is due citing the version and    # 
$!#     original authors properly; and                                      # 
$!#   * 3. Please do not give anyone the impression that the original       # 
$!#     authors are providing a warranty of any kind.                       #
$!#                                                                         #
$!# If you would like to use major pieces of RasMol in some other program,  #
$!# make modifications to RasMol, or in some other way make what a lawyer   #
$!# would call a "derived work", you are not only permitted to do so, you   #
$!# are encouraged to do so. In addition to the things we discussed above,  #
$!# please do the following:                                                #
$!#   * 4. Please explain in your documentation how what you did differs    #
$!#     from this version of RasMol; and                                    #
$!#   * 5. Please make your modified source code available.                 #
$!#                                                                         #
$!# This version of RasMol is not in the public domain, but it is given     #
$!# freely to the community in the hopes of advancing science. If you make  #
$!# changes, please make them in a responsible manner, and please offer us  #
$!# the opportunity to include those changes in future versions of RasMol.  #
$!###########################################################################
$!
$! BUILD.COM
$! VMS Compilation Script
$! RasMol v2.7.0
$!
$ If F$Trnlnm ("X11") .eqs. "" Then Define X11 DECW$Include
$ If F$Trnlnm ("SYS") .eqs. "" Then Define Sys Sys$Share
$!
$ cc/optimize rasmol.c
$ cc/optimize molecule.c
$ cc/optimize infile.c
$ cc/optimize transfor.c
$ cc/optimize cmndline.c
$ cc/optimize command.c
$ cc/optimize abstree.c
$ cc/optimize render.c
$ cc/optimize repres.c
$ cc/optimize x11win.c
$ cc/optimize pixutils.c
$ cc/optimize outfile.c
$ cc/optimize script.c
$ cc/optimize tokens.c
$ cc/optimize cif_fract.c
$ cc/optimize cif.c
$ cc/optimize cif_ctonum.c
$ cc/optimize cif_stx.c
$ cc/optimize string_case.c
$ cc/optimize langsel.c
$ cc/optimize multiple.c
$ cc/optimize wbrotate.c
$ cc/optimize vector.c
$!
$ link /exec=rasmol rasmol.obj, molecule.obj, infile.obj, transfor.obj, -
    cmndline.obj, command.obj, abstree.obj, render.obj, repres.obj, x11win.obj, -
    pixutils.obj, outfile.obj, script.obj, tokens.obj, cif_fract.obj, cif.obj, -
    cif_ctonum.obj, cif_stx.obj, string_case.obj, langsel.obj, multiple.obj, - 
    wbrotate.obj, vector.obj, rasmol/opt
$!
$ set prot=w:re rasmol.exe
$ set prot=w:r rasmol.hlp
