#!/bin/csh
#  RSML_fixup.csh
#  H. J. Bernstein, 15 Feb 2004
#
#  This script is intended for use under Mac OS X to fixup
#  the creator (RSML) and the type (TEXT) of all *.pdb,
#  *.cif  and *.ent  files
#
#  Change the following definition to the path to SetFile
set setfile=/Developer/Tools/SetFile
foreach file (*.pdb *.cif *.ent *.PDB *.CIF *.ENT)
$setfile -c "RSML" -t "TEXT" $file
end

