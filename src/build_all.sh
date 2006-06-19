#!/bin/sh
#
#
# build_all.sh -- script to build all pixel depth variants of RasMol
#
#  HJB, Apr 2002, Rev Apr 2005
#
cp Imakefile Imakefile_save
rm Imakefile
echo "#define PIXELDEPTH 8"|cat - Imakefile_save > Imakefile
xmkmf
mv Makefile Makefile_8BIT
if [ "$1"  != "-nobuild" ]; then
  make -f Makefile_8BIT clean
  make -f Makefile_8BIT rasmol
  mv rasmol rasmol_8BIT
fi;
rm Imakefile
echo "#define PIXELDEPTH 16"|cat - Imakefile_save > Imakefile
xmkmf
mv Makefile Makefile_16BIT
if [ "$1" != "-nobuild" ]; then
  make -f Makefile_16BIT clean
  make -f Makefile_16BIT rasmol
  mv rasmol rasmol_16BIT
fi;
rm Imakefile
echo "#define PIXELDEPTH 32"|cat - Imakefile_save > Imakefile
xmkmf
mv Makefile Makefile_32BIT
if [ "$1" != "-nobuild" ]; then
  make -f Makefile_32BIT clean
  make -f Makefile_32BIT rasmol
  mv rasmol rasmol_32BIT
fi;
rm Imakefile
echo "#define PIXELDEPTH 8" > Imakefile
echo "#define XFORMSLIB xx"|cat - Imakefile_save >> Imakefile
xmkmf
mv Makefile Makefile_8BIT
if [ "$1"  != "-nobuild" ]; then
  make -f Makefile_8BIT clean
  make -f Makefile_8BIT rasmol
  mv rasmol rasmol_XFORMS_8BIT
fi;
rm Imakefile
echo "#define PIXELDEPTH 16" > Imakefile
echo "#define XFORMSLIB xx"|cat - Imakefile_save >> Imakefile
xmkmf
mv Makefile Makefile_16BIT
if [ "$1" != "-nobuild" ]; then
  make -f Makefile_16BIT clean
  make -f Makefile_16BIT rasmol
  mv rasmol rasmol_XFORMS_16BIT
fi;
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
