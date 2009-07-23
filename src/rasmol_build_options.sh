#! /bin/sh
#
#  rasmol_build_options.sh
#  script to combine options with Imakefile_base
#  and produce Imakefile
#
#  H. J. Bernstein, 9 July 2009
#
###########################################################################
#                               RasMol 2.7.5                              #
#                                                                         #
#                                  RasMol                                 #
#                  Molecular Graphics Visualisation Tool                  #
#                               13 June 2009                              #
#                                                                         #
#                   Based on RasMol 2.6 by Roger Sayle                    #
# Biomolecular Structures Group, Glaxo Wellcome Research & Development,   #
#                      Stevenage, Hertfordshire, UK                       #
#         Version 2.6, August 1995, Version 2.6.4, December 1998          #
#                   Copyright (C) Roger Sayle 1992-1999                   #
#                                                                         #
#                          and Based on Mods by                           #
#Author             Version, Date             Copyright                   #
#Arne Mueller       RasMol 2.6x1   May 98     (C) Arne Mueller 1998       #
#Gary Grossman and  RasMol 2.5-ucb Nov 95     (C) UC Regents/ModularCHEM  #
#Marco Molinaro     RasMol 2.6-ucb Nov 96         Consortium 1995, 1996   #
#                                                                         #
#Philippe Valadon   RasTop 1.3     Aug 00     (C) Philippe Valadon 2000   #
#                                                                         #
#Herbert J.         RasMol 2.7.0   Mar 99     (C) Herbert J. Bernstein    # 
#Bernstein          RasMol 2.7.1   Jun 99         1998-2008               #
#                   RasMol 2.7.1.1 Jan 01                                 #
#                   RasMol 2.7.2   Aug 00                                 #
#                   RasMol 2.7.2.1 Apr 01                                 #
#                   RasMol 2.7.2.1.1 Jan 04                               #
#                   RasMol 2.7.3   Feb 05                                 #
#                   RasMol 2.7.3.1 Apr 06                                 #
#                   RasMol 2.7.4   Nov 07                                 #
#                   RasMol 2.7.4.1 Jan 08                                 #
#                   RasMol 2.7.5   May 09                                 #
#                                                                         #
# RasMol 2.7.5 incorporates changes by T. Ikonen, G. McQuillan, N. Darakev#
# and L. Andrews (via the neartree package).  Work on RasMol 2.7.5        #
# supported in part by grant 1R15GM078077-01 from the National Institute  #
# of General Medical Sciences (NIGMS), U.S. National Institutes of Health #
# and by grant ER63601-1021466-0009501 from the Office of Biological &    #
# Environmental Research (BER), Office of Science, U. S. Department of    #
# Energy.  RasMol 2.7.4 incorporated  changes by G. Todorov, Nan Jia,     #
# N. Darakev, P. Kamburov, G. McQuillan, and J. Jemilawon. Work on RasMol #
# 2.7.4 supported in part by grant 1R15GM078077-01 from the NIGMS/NIH and #
# grant ER63601-1021466-0009501 from BER/DOE.  RasMol 2.7.3 incorporates  #
# changes by Clarice Chigbo, Ricky Chachra, and Mamoru Yamanishi.  Work   #
# on RasMol 2.7.3 supported in part by grants DBI-0203064, DBI-0315281    #
# and EF-0312612 from the U.S. National Science Foundation and grant      #
# DE-FG02-03ER63601 from BER/DOE. The content is solely the responsibility#
# of the authors and does not necessarily represent the official views of #
# the funding organizations.                                              #
#                                                                         #
# The code for use of RasMol under GTK in RasMol 2.7.4.2 and 2.7.5 was    #
# written by Teemu Ikonen.                                                #
#                                                                         #
#                    and Incorporating Translations by                    #
#  Author                               Item                     Language #
#  Isabel Servan Martinez,                                                #
#  Jose Miguel Fernandez Fernandez      2.6   Manual             Spanish  #
#  Jose Miguel Fernandez Fernandez      2.7.1 Manual             Spanish  #
#  Fernando Gabriel Ranea               2.7.1 menus and messages Spanish  #
#  Jean-Pierre Demailly                 2.7.1 menus and messages French   #
#  Giuseppe Martini, Giovanni Paolella, 2.7.1 menus and messages          #
#  A. Davassi, M. Masullo, C. Liotto    2.7.1 help file          Italian  #
#  G. Pozhvanov                         2.7.3 menus and messages Russian  #
#  G. Todorov                           2.7.3 menus and messages Bulgarian#
#  Nan Jia, G. Todorov                  2.7.3 menus and messages Chinese  #
#  Mamoru Yamanishi, Katajima Hajime    2.7.3 menus and messages Japanese #
#                                                                         #
#                             This Release by                             #
# Herbert J. Bernstein, Bernstein + Sons, 5 Brewster Ln, Bellport, NY, USA#
#                       yaya@bernstein-plus-sons.com                      #
#               Copyright(C) Herbert J. Bernstein 1998-2008               #
#                                                                         #
#                READ THE FILE NOTICE FOR RASMOL LICENSES                 #
#Please read the file NOTICE for important notices which apply to this    #
#package and for license terms (GPL or RASLIC).                           #
###########################################################################



#  Script to prepend options to Imakefile_base to produce Imakefile

rm -f Imakefile_$$
touch Imakefile_$$

for optcur
do

  case "$optcur" in
  --help | -h)
    echo 'usage'
    echo '  ./rasmol_build_options.sh"'
    echo '    {--help|-h}'
    echo '    {--cbflib_local}'
    echo '    {--cqrlib_local}'
    echo '    {--cvector_local}'
    echo '    {--neartree_local}'
    echo '    {--xformslib_local}'
    echo '    {--use_xformslib}'
    echo '    {--use_gtk}'
    echo '    {--pixeldepth=32}'
    echo '    {--pixeldepth=16}'
    echo '    {--pixeldepth=8}'
    echo '    {--macosx_fink}'
    ;;

  --cbflib_local)
    echo '#define CBFLIB_LOCAL' >> Imakefile_$$
    ;;

  --cqrlib_local)
    echo '#define CQRLIB_LOCAL' >> Imakefile_$$
    ;;

  --cvector_local)
    echo '#define CVECTOR_LOCAL' >> Imakefile_$$
    ;;

  --neartree_local)
    echo '#define NEARTREE_LOCAL' >> Imakefile_$$
    ;;

  --xformslib_local)
    echo '#define XFORMSLIB_LOCAL' >> Imakefile_$$
    ;;

  --use_xformslib)
    echo '#define USE_XFORMSLIB' >> Imakefile_$$
    ;;

  --use_gtk)
    echo '#define GTKWIN' >> Imakefile_$$
    ;;

  --pixeldepth=32)
    echo '#define PIXELDEPTH 32' >> Imakefile_$$
    ;;

  --pixeldepth=16)
    echo '#define PIXELDEPTH 16' >> Imakefile_$$
    ;;

  --pixeldepth=8)
    echo '#define PIXELDEPTH 8' >> Imakefile_$$
    ;;

  --macosx_fink)
    echo '#define MACOSX_FINK True' >> Imakefile_$$
    ;;

  esac

done

cat Imakefile_$$ Imakefile_base > Imakefile_new
rm Imakefile_$$
mv Imakefile Imakefile_old
mv Imakefile_new Imakefile
