##########################################################################
#                              RasMol 2.7.2                              #
#                                                                        #
#                                 RasMol                                 #
#                 Molecular Graphics Visualisation Tool                  #
#                             21 August 2000                             #
#                                                                        #
#                   Based on RasMol 2.6 by Roger Sayle                   #
# Biomolecular Structures Group, Glaxo Wellcome Research & Development,  #
#                      Stevenage, Hertfordshire, UK                      #
#         Version 2.6, August 1995, Version 2.6.4, December 1998         #
#                   Copyright (C) Roger Sayle 1992-1999                  #
#                                                                        #
#                  and Based on Mods by Arne Mueller                     #
#                      Version 2.6x1, May 1998                           #
#                   Copyright (C) Arne Mueller 1998                      #
#                                                                        #
#          and Based on Mods by Gary Grossman and Marco Molinaro         #
#                   Version 2.5-ucb, November 1995                       #
#                   Version 2.6-ucb, November 1996                       #
#       Copyright (C) UC Regents/ModularCHEM Consortium 1995, 1996       #
#                                                                        #
#        Version 2.7.0, 2.7.1, 2.7.2 Mods by Herbert J. Bernstein        #
#           Bernstein + Sons, P.O. Box 177, Bellport, NY, USA            #
#                      yaya@bernstein-plus-sons.com                      #
#          2.7.0 March 1999, 2.7.1 June 1999, 2.7.2 August 2000          #
#              Copyright (C) Herbert J. Bernstein 1998-2000              #
#                                                                        #
# Please read the file NOTICE for important notices which apply to this  #
# package. If you are not going to make changes to RasMol, you are not   # 
# only permitted to freely make copies and distribute them, you are      # 
# encouraged to do so, provided you do the following:                    #
#   * 1. Either include the complete documentation, especially the file  #
#     NOTICE, with what you distribute or provide a clear indication     #
#     where people can get a copy of the documentation; and              #
#   * 2. Please give credit where credit is due citing the version and   # 
#     original authors properly; and                                     #  
#   * 3. Please do not give anyone the impression that the original      #   
#     authors are providing a warranty of any kind.                      #
#                                                                        #
# If you would like to use major pieces of RasMol in some other program, #
# make modifications to RasMol, or in some other way make what a lawyer  #
# would call a "derived work", you are not only permitted to do so, you  #
# are encouraged to do so. In addition to the things we discussed above, #
# please do the following:                                               #
#   * 4. Please explain in your documentation how what you did differs   #
#     from this version of RasMol; and                                   #
#   * 5. Please make your modified source code available.                #
#                                                                        #
# This version of RasMol is not in the public domain, but it is given    #
# freely to the community in the hopes of advancing science. If you make #
# changes, please make them in a responsible manner, and please offer us #
# the opportunity to include those changes in future versions of RasMol. #
##########################################################################
#   File:       RasMol.symantec.make
#   Target:     RasMol.symantec
#   Sources:
#      abstree.c cmndline.c command.c infile.c molecule.c outfile.c
#      pixutils.c render.c repres.c script.c transfor.c tokens.c
#      cif_fract.c cif.c cif_ctonum.c cif_stx.c
#      multiple.c toolbar.c vector.c wbrotate.c
#   Created:    Tuesday August 29, 2000


PPC_C = SMrC
PPC_OPTIONS = 
OPTIONS = -ansi relaxed -align power -opt all
C_OPTIONS = {OPTIONS} 



COBJECTS = abstree.c.o applemac.c.o cmndline.c.o command.c.o infile.c.o [partial]
           molecule.c.o outfile.c.o pixutils.c.o rasmac.c.o [partial]
		   render.c.o repres.c.o script.c.o transfor.c.o tokens.c.o [partial]
		   cif_fract.c.o cif.c.o cif_ctonum.c.o cif_stx.c.o [partial]
		   multiple.c.o toolbar.c.o vector.c.o wbrotate.c.o

RasMol.symantec [f] RasMol.symantec.make RasMac.rsrc {COBJECTS} 
	PPCLink   -warn  {COBJECTS} [partial]
		"{SharedLibraries}"InterfaceLib [partial]
		"{SharedLibraries}"MathLib  [partial]
		"{SharedLibraries}"StdCLib  [partial]
		"{PPCLibraries}"StdCRuntime.o  [partial]
		"{PPCLibraries}"PPCCRuntime.o [partial]
		-o RasMol.symantec
	Echo "include [partial]"RasMac.rsrc[partial]" ;" [partial]
		| Rez -a  -o RasMol.symantec
	SetFile -c RSML RasMol.symantec


abstree.c.o [f] abstree.c
	{PPC_C} abstree.c {PPC_OPTIONS} {C_OPTIONS}

applemac.c.o [f] applemac.c
	{PPC_C} applemac.c {PPC_OPTIONS} {C_OPTIONS}

cmndline.c.o [f] cmndline.c
	{PPC_C} cmndline.c {PPC_OPTIONS} {C_OPTIONS}

command.c.o [f] command.c
	{PPC_C} command.c {PPC_OPTIONS} {C_OPTIONS}

infile.c.o [f] infile.c
	{PPC_C} infile.c {PPC_OPTIONS} {C_OPTIONS}

molecule.c.o [f] molecule.c
	{PPC_C} molecule.c {PPC_OPTIONS} {C_OPTIONS}

outfile.c.o [f]  outfile.c
	{PPC_C} outfile.c {PPC_OPTIONS} {C_OPTIONS}

pixutils.c.o [f]  pixutils.c
	{PPC_C} pixutils.c {PPC_OPTIONS} {C_OPTIONS}

rasmac.c.o [f]  rasmac.c
	{PPC_C} rasmac.c {PPC_OPTIONS} {C_OPTIONS}

render.c.o [f]  render.c
	{PPC_C} render.c {PPC_OPTIONS} {C_OPTIONS}

repres.c.o [f]  repres.c
	{PPC_C} repres.c {PPC_OPTIONS} {C_OPTIONS}

script.c.o [f]  script.c
	{PPC_C} script.c {PPC_OPTIONS} {C_OPTIONS}

transfor.c.o [f]  transfor.c
	{PPC_C} transfor.c {PPC_OPTIONS} {C_OPTIONS}

trokens.c.o [f]  tokens.c
	{PPC_C} tokens.c {PPC_OPTIONS} {C_OPTIONS}

cif_fract.c.o [f]  cif_fract.c
	{PPC_C} cif_fract.c {PPC_OPTIONS} {C_OPTIONS}

cif.c.o [f]  cif.c
	{PPC_C} cif.c {PPC_OPTIONS} {C_OPTIONS}

cif_ctonum.c.o [f]  cif_ctonum.c
	{PPC_C} cif_ctonum.c {PPC_OPTIONS} {C_OPTIONS}

cif_stx.c.o [f]  cif_stx.c
	{PPC_C} cif_stx.c {PPC_OPTIONS} {C_OPTIONS}

multiple.c.o [f]  multiple.c
	{PPC_C} multiple.c {PPC_OPTIONS} {C_OPTIONS}

vector.c.o [f]  vector.c
	{PPC_C} vector.c {PPC_OPTIONS} {C_OPTIONS}

wbrotate.c.o [f]  wbrotate.c
	{PPC_C} wbrotate.c {PPC_OPTIONS} {C_OPTIONS}


