#!/bin/csh
#
#
# build_HPUX_PARISC.csh -- script to build HPUX_PARISC variants of RasMol
#
#  HJB, Apr 2002
#
cp Imakefile Imakefile_save_hp
rm Imakefile
echo "#define HPUX_PARISC_32"|cat - Imakefile_save_hp > Imakefile
./build_all.csh $1
if ($1 != "-nobuild") then
mv rasmol_8BIT rasmol_8BIT_HPUX_PARISC_32
mv rasmol_16BIT rasmol_16BIT_HPUX_PARISC_32
mv rasmol_32BIT rasmol_32BIT_HPUX_PARISC_32
endif
mv Makefile_8BIT Makefile_8BIT_HPUX_PARISC_32
mv Makefile_16BIT Makefile_16BIT_HPUX_PARISC_32
mv Makefile_32BIT Makefile_32BIT_HPUX_PARISC_32
rm Imakefile
echo "#define HPUX_PARISC_64"|cat - Imakefile_save_hp > Imakefile
./build_all.csh $1
if ($1 != "-nobuild") then
mv rasmol_8BIT rasmol_8BIT_HPUX_PARISC_64
mv rasmol_16BIT rasmol_16BIT_HPUX_PARISC_64
mv rasmol_32BIT rasmol_32BIT_HPUX_PARISC_64
endif
mv Imakefile_save_hp Imakefile
mv Makefile_8BIT Makefile_8BIT_HPUX_PARISC_64
mv Makefile_16BIT Makefile_16BIT_HPUX_PARISC_64
mv Makefile_32BIT Makefile_32BIT_HPUX_PARISC_64
