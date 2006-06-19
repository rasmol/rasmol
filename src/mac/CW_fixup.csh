#!/bin/csh
#  CW_fixup.csh
#  H. J. Bernstein, 15 Feb 2004
#
#  This script is intended for use under Mac OS X to fixup
#  the creator (CWIE) and the type (TEXT) of all *.c and *.h
#  files
#
#  Change the following definition to the path to SetFile
set setfile=/Developer/Tools/SetFile
foreach file (*.c *.h *.idm *.def *.rc *.r *.xml)
$setfile -c "CWIE" -t "TEXT" $file
end

