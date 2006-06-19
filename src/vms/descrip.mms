!###########################################################################
!#                              RasMol 2.7.1                               # 
!#                                                                         #
!#                                 RasMol                                  #
!#                 Molecular Graphics Visualisation Tool                   #
!#                              22 June 1999                               #
!#                                                                         #
!#                   Based on RasMol 2.6 by Roger Sayle                    #
!# Biomolecular Structures Group, Glaxo Wellcome Research & Development,   #
!#                      Stevenage, Hertfordshire, UK                       #
!#         Version 2.6, August 1995, Version 2.6.4, December 1998          #
!#                   Copyright (C) Roger Sayle 1992-1999                   #
!#                                                                         #
!#                  and Based on Mods by Arne Mueller                      #
!#                      Version 2.6x1, May 1998                            #
!#                   Copyright (C) Arne Mueller 1998                       #
!#                                                                         #
!#           Version 2.7.0, 2.7.1 Mods by Herbert J. Bernstein             #
!#           Bernstein + Sons, P.O. Box 177, Bellport, NY, USA             #
!#                      yaya@bernstein-plus-sons.com                       #
!#                    2.7.0 March 1999, 2.7.1 June 1999                    #
!#              Copyright (C) Herbert J. Bernstein 1998-1999               #
!#                                                                         #
!# Please read the file NOTICE for important notices which apply to this   #
!# package. If you are not going to make changes to RasMol, you are not    # 
!# only permitted to freely make copies and distribute them, you are       # 
!# encouraged to do so, provided you do the following:                     #
!#   * 1. Either include the complete documentation, especially the file   #
!#     NOTICE, with what you distribute or provide a clear indication      #
!#     where people can get a copy of the documentation; and               #
!#   * 2. Please give credit where credit is due citing the version and    # 
!#     original authors properly; and                                      # 
!#   * 3. Please do not give anyone the impression that the original       # 
!#     authors are providing a warranty of any kind.                       #
!#                                                                         #
!# If you would like to use major pieces of RasMol in some other program,  #
!# make modifications to RasMol, or in some other way make what a lawyer   #
!# would call a "derived work", you are not only permitted to do so, you   #
!# are encouraged to do so. In addition to the things we discussed above,  #
!# please do the following:                                                #
!#   * 4. Please explain in your documentation how what you did differs    #
!#     from this version of RasMol; and                                    #
!#   * 5. Please make your modified source code available.                 #
!#                                                                         #
!# This version of RasMol is not in the public domain, but it is given     #
!# freely to the community in the hopes of advancing science. If you make  #
!# changes, please make them in a responsible manner, and please offer us  #
!# the opportunity to include those changes in future versions of RasMol.  #
!###########################################################################
!#
CC = CC
LINK = LINK

!LIBS = sys$share:decw$xlibshr/share
LIBS = 

!CFLAGS = /standard=vaxc/debug/noopt
CFLAGS= /optimize/standard=vaxc
LFLAGS = 
       
 
rasmol : rasmol.obj, molecule.obj, infile.obj, transfor.obj, command.obj, -
         abstree.obj, render.obj, repres.obj, x11win.obj, pixutils.obj, -
         outfile.obj, script.obj, cif.obj, cmndline.obj, tokens.obj -
         cif_ctonum.obj, cif_stx.obj, string_case.c
         $(LINK) /exec=rasmol $(LFLAGS) rasmol.obj, molecule.obj, -
                infile.obj, transfor.obj, cmndline.obj, command.obj, abstree.obj, -
                render.obj, repres.obj, x11win.obj, pixutils.obj, -
                outfile.obj, script.obj, tokens.obj, cif_fract.obj, cif.obj, -
                cif_ctonum.obj, cif_stx.obj, string_case.c, rasmol/opt

rasmol.obj :   rasmol.c, rasmol.h, molecule.h, transfor.h, command.h, -
               infile.h, abstree.h, render.h, graphics.h, pixutils.h, -
               outfile.h, repres.h
               $(CC) $(CFLAGS) rasmol.c

molecule.obj : molecule.c, molecule.h, rasmol.h, abstree.h, transfor.h, -
               render.h, command.h string_case.h
               $(CC) $(CFLAGS) molecule.c

infile.obj :   infile.c, infile.h, rasmol.h, molecule.h, abstree.h, -
               command.h, transfor.h, cif.h, cif_fract.h
               $(CC) $(CFLAGS) infile.c

transfor.obj : transfor.c, transfor.h, rasmol.h, molecule.h, command.h, -
               abstree.h, render.h, graphics.h, repres.h
               $(CC) $(CFLAGS) transfor.c

cmndline.obj : cmndline.c, cmndline.h, rasmol.h, molecule.h, command.h, -
               render.h, graphics.h
               $(CC) $(CFLAGS) cmndline.c

command.obj :  command.c, command.h, rasmol.h, tokens.h, abstree.h, -
               molecule.h, transfor.h, render.h, graphics.h, pixutils.h, -
               outfile.h, infile.h, script.h string_case.h
               $(CC) $(CFLAGS) command.c

abstree.obj :  abstree.c, abstree.h, rasmol.h, molecule.h
               $(CC) $(CFLAGS) abstree.c

render.obj :   render.c, render.h, rasmol.h, molecule.h, transfor.h, -
               command.h, abstree.h, graphics.h, pixutils.h
               $(CC) $(CFLAGS) render.c

repres.obj:    repres.c, repres.h, rasmol.h
               $(CC) $(CFLAGS) repres.c

x11win.obj :   x11win.c, graphics.h, rasmol.h, bitmaps.h, command.h
               $(CC) $(CFLAGS) x11win.c

pixutils.obj : pixutils.c, pixutils.h, rasmol.h, font.h, molecule.h, -
               transfor,h,  render.h, graphics.h, abstree.h
               $(CC) $(CFLAGS) pixutils.c

outfile.obj :  outfile.c, outfile.h, rasmol.h, molecule.h, command.h, -
               abstree.h, transfor.h, render.h, graphics.h, pixutils.h, -
               script.h, repres.h
               $(CC) $(CFLAGS) outfile.c

script.obj :   script.c, script.h, rasmol.h, molecule.h, command.h, -
               abstree.h, transfor.h, render.h, graphics.h, pixutils.h, -
               repres.h
               $(CC) $(CFLAGS) script.c

tokens.obj :   tokens.c, tokens.h
               $(CC) $(CFLAGS) tokens.c

cif_fract.obj : cif_fract.c, rasmol.h
               $(CC) $(CFLAGS) cif_fract.c

cif.obj :       cif.c, cif.h, rasmol.h, molecule.h string_case.h
               $(CC) $(CFLAGS) cif.c

cif_ctonum.obj : cif_ctonum.c, cif_ctonum.h, rasmol.h string_case.h
               $(CC) $(CFLAGS) cif_ctonum.c

cif_stx.obj:   cif_stx.c, cif.h
               $(CC) $(CFLAGS) cif_stx.c

string_case.obj: string_case.c
               $(CC) $(CFLAGS) string_case.c
