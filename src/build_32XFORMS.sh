#!/bin/sh
#
#
# build_all.sh -- script to build all pixel depth variants of RasMol
#
#  HJB, Apr 2002, Rev Apr 2005
#
cp Imakefile Imakefile_save
rm Imakefile
echo "#define PIXELDEPTH 32" > Imakefile
echo "#define XFORMSLIB xx"|cat - Imakefile_save >> Imakefile
xmkmf
mv Makefile Makefile_32BIT
if [ "$1" != "-nobuild" ]; then
  make -f Makefile_32BIT clean
  make -f Makefile_32BIT rasmol
  mv rasmol rasmol_XFORMS_32BIT
fi;
mv Imakefile_save Imakefile
