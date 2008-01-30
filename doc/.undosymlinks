#!/bin/csh
foreach file ( index.html esrasmol27.html itrasmol.hlp GPL.txt NOTICE.txt RASLIC.txt )
  rm -rf $file
end
foreach file (*)
  if ( -d $file ) then
    if ( -e $file/.undosymlinks ) then
      (cd $file; source .undosymlinks)
    endif
  endif
end

