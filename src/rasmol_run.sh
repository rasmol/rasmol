#!/bin/sh
###########################################################################
#                             RasMol 2.7.3.1                              #
#                                                                         #
#                                 RasMol                                  #
#                 Molecular Graphics Visualisation Tool                   #
#                             14 April 2006                               #
#                                                                         #
#                   Based on RasMol 2.6 by Roger Sayle                    #
# Biomolecular Structures Group, Glaxo Wellcome Research & Development,   #
#                      Stevenage, Hertfordshire, UK                       #
#         Version 2.6, August 1995, Version 2.6.4, December 1998          #
#                   Copyright (C) Roger Sayle 1992-1999                   #
#                                                                         #
#                          and Based on Mods by                           #
#  Author             Version, Date             Copyright                 #
#                                                                         #
#  Arne Mueller       RasMol 2.6x1     May 98   (C) Arne Mueller 1998     #
#                                                                         #
#  Gary Grossman and  RasMol 2.5-ucb   Nov 95   (C) UC Regents/ModularCHEM#
#  Marco Molinaro     RasMol 2.5-ucb   Nov 96       Consortium 1995, 1996 #
#                                                                         #
#  Philippe Valadon   RasTop 1.3       Aug 00   (C) Philippe Valadon 2000 #
#                                                                         #
#  Herbert J.         RasMol 2.7.0     Mar 99   (C) Herbert J. Bernstein  #
#  Bernstein          RasMol 2.7.1     Jun 99       1998-2005             #
#                     RasMol 2.7.1.1   Jan 01                             #
#                     RasMol 2.7.2     Aug 00                             #
#                     RasMol 2.7.2.1   Apr 01                             #
#                     RasMol 2.7.2.1.1 Jan 04                             #
#                     RasMol 2.7.3     Feb 05                             #
#                     RasMol 2.7.3.1   Apr 06                             #
#                                                                         #
#  with RasMol 2.7.3 incorporating changes by Clarice Chigbo, Ricky       #
#  Chachra, and Mamoru Yamanishi.  Work on RasMol 2.7.3 supported in part #
#  by grants DBI-0203064, DBI-0315281 and EF-0312612 from the U.S.        #
#  National Science Foundation and grant DE-FG02-03ER63601 from the       #
#  U.S. Department of Energy.                                             #
#                                                                         #
#                     and Incorporating Translations by                   #
#  Author                               Item                     Language #
#  Isabel Servan Martinez,                                                #
#  Jose Miguel Fernandez Fernandez      2.6   Manual              Spanish #
#  Jose Miguel Fernandez Fernandez      2.7.1 Manual              Spanish #
#  Fernando Gabriel Ranea               2.7.1 menus and messages  Spanish #
#  Jean-Pierre Demailly                 2.7.1 menus and messages  French  #
#  Giuseppe Martini, Giovanni Paolella, 2.7.1 menus and messages          #
#  A. Davassi, M. Masullo, C. Liotto    2.7.1 help file           Italian #
#  G. Pozhvanov                         2.7.3 menus and messages  Russian #
#                                                                         #
#                             This Release by                             #
# Herbert J. Bernstein, Bernstein + Sons, P.O. Box 177, Bellport, NY, USA #
#                       yaya@bernstein-plus-sons.com                      #
#               Copyright(C) Herbert J. Bernstein 1998-2006               #
#                                                                         #
#                READ THE FILE NOTICE FOR RASMOL LICENSES                 #
# Please read the file NOTICE for important notices which apply to this   #
# package and for license terms (GPL or RASLIC).                          #
###########################################################################
#
#
#  rasmol_run.sh
#
#  a script to run rasmol, setting up
#  fonts, and using xterm to set up an
#  appropriate terminal window.
#
#  This is a version for use with version
#  of RasMol that supports windows-style
#  code pages
#
#  H. J. Bernstein, 23 December 2006
#


# Process command line options
#


VERSION=${RASMOL_VERSION-"RasMol_2_7_3_1"};

for rasmolarg in "$@" ;
do
  case $rasmolarg in
    '--help' )
      echo "rasmol_run.sh usage:"
      echo "  rasmol_run.sh [--help] | [rasmolargs]*"
      echo "invokes a version of rasmol matching the"
      echo "available X11 visuals in a new xterm"
      echo ""
      echo "optional variables:"
      echo "   RASMOL_VERSION      RasMol_n_n_n..."
      echo "   RASMOL_LANG         startup language"
      echo "   RASMOLPATH          path to rasmol directory"
      echo "   RASMOL_LIBSFORMPATH path to xforms library directory"
      echo "   RASMOL_LANTIN1FDIR  path to X11 ISO 8859-1 font directory"
      echo "   RASMOL_CP1251FDIR   path to X11 ISO CP 1251 font directory"
      echo "   RASMOL_DEBUG        if non-empty, report settings"
      echo "   RASMOL_NOSPAWN      if non-empty, do not spawn an intermediary xterm"
      exit 0;
    ;;
    '--English'  | '--ENGLISH'  | '--english'  ) RASMOL_LANG="English"  ;; 
    '--French'   | '--FRENCH'   | '--french'   ) RASMOL_LANG="French"   ;; 
    '--German'   | '--GERMAN'   | '--german'   ) RASMOL_LANG="German"   ;; 
    '--Italian'  | '--ITALIAN'  | '--italian'  ) RASMOL_LANG="Italian"  ;; 
    '--Russian'  | '--RUSSIAN'  | '--russian'  ) RASMOL_LANG="Russian"  ;; 
    '--Spanish'  | '--SPANISH'  | '--spanish'  ) RASMOL_LANG="Spanish"  ;; 
    '--Japanese' | '--JAPANESE' | '--japanese' ) RASMOL_LANG="Japanese" ;; 
    '--Chinese'  | '--CHINESE'  | '--chinese'  ) RASMOL_LANG="Chinese"  ;; 
  esac
done

if ! [ "$RASMOL_LANG" ] ; then
  if [ -d "$HOME/.rasmol" ] ; then
    if [ -f "$HOME/.rasmol/RasMol.flg" ] ; then
      for rasmol_lang in  \
        English French German Italian Russian Spanish Japanese Chinese \
      ;
      do
        if ( grep -i "^$rasmol_lang" "$HOME/.rasmol/RasMol.flg" >/dev/null 2>&1 ) ; then
          RASMOL_LANG=$rasmol_lang; export RASMOL_LANG ;
          break 1;
        fi
      done
    fi
  fi
fi

if ! [ "$RASMOL_LANG" ] ; then
  RASMOL_LANG="English"; export RASMOL_LANG ;
fi

if [ "$RASMOL_DEBUG" ] ; then echo "startup language selected $RASMOL_LANG" ;
fi

for rasmolpath in \
    $RASMOLPATH \
    . \
    $HOME/lib/$VERSION \
    /usr/local/lib/$VERSION \
    /usr/lib/$VERSION \
    /sw/lib/$VERSION \
    /usr/openwin/lib/$VERSION \
; 
do
  if [ -d "$rasmolpath" ]; then
    if [ -x "$rasmolpath/rasmol_run.sh" ]; then
      savecurdir=`pwd`;
      cd $rasmolpath;
      RASMOLPATH=`pwd`; export RASMOLPATH;
      cd $savecurdir;
      break 1;
    fi
  fi
done

if [ "$RASMOL_DEBUG" ] ; then echo "executing rasmol from $RASMOLPATH" ;
fi



#
if [ "$DISPLAY" ] &&  ( xdpyinfo > /dev/null 2>&1 ) ; then 


#  Find libforms
#
for RASMOL_LIBFORMSPATH in \
  $RASMOL_LIBFORMSPATH \
  . \
  $HOME/lib \
  /lib \
  /usr/lib \
  /usr/local/lib \
  /sw/lib \
  /usr/openwin/lib \
;
do
  if [ -d "$RASMOL_LIBFORMSPATH" ]; then
    if [ -f "$RASMOL_LIBFORMSPATH/libforms.a" ] || \
       [ -f "$RASMOL_LIBFORMSPATH/libforms.so" ] || \
       [ -f "$RASMOL_LIBFORMSPATH/libforms.dylib" ] ; then
       savecurdir=`pwd`;
       cd $RASMOL_LIBFORMSPATH;
       RASMOL_LIBFORMSPATH=`pwd`;
       cd $savecurdir;
       break 1;
    fi
  fi
done


if [ "$RASMOL_LIBFORMSPATH" ]; then 
  if [ "$RASMOL_DEBUG" ] ; then echo "using xforms library in $RASMOL_LIBFORMSPATH" ;
  fi
  # LINUX
  if [ "$LD_LIBARY_PATH" ]; then
    LD_LIBARY_PATH=$LD_LIBARY_PATH:$RASMOL_LIBFORMSPATH; export LD_LIBARY_PATH;
  else
    LD_LIBARY_PATH=$RASMOL_LIBFORMSPATH; export LD_LIBARY_PATH;
  fi
  # HPUX
  if [ "$SHLIB_PATH" ]; then
    SHLIB_PATH=$SHLIB_PATH:$RASMOL_LIBFORMSPATH; export SHLIB_PATH;
  else
    SHLIB_PATH=$RASMOL_LIBFORMSPATH; export SHLIB_PATH;
  fi
  # AIX
  if [ "$LIBPATH" ]; then
    LIBPATH=$LIBPATH:$RASMOL_LIBFORMSPATH; export LIBPATH;
  else
    LIBPATH=$RASMOL_LIBFORMSPATH; export LIBPATH;
  fi
fi


# Check on the available visuals

if [ -x $RASMOLPATH/rasmol_32BIT ] && (  xdpyinfo | grep "bits_per_pixel 32" > /dev/null 2>&1 );
  then RASMOL_BIN=rasmol_32BIT;
  if [ -x $RASMOLPATH/rasmol_XFORMS_32BIT ] && [ "$RASMOL_LIBFORMSPATH" ] ; then RASMOL_BIN=rasmol_XFORMS_32BIT;
  fi
elif [ -x $RASMOLPATH/rasmol_16BIT ] && (  xdpyinfo | grep "bits_per_pixel 16" > /dev/null  2>&1 );
  then RASMOL_BIN=rasmol_16BIT;
  if [ -x $RASMOLPATH/rasmol_XFORMS_16BIT ] && [ "$RASMOL_LIBFORMSPATH" ] ; then RASMOL_BIN=rasmol_XFORMS_16BIT;
  fi
elif [ -x $RASMOLPATH/rasmol_8BIT ] && (  xdpyinfo | grep "bits_per_pixel 8"  > /dev/null 2>&1 );
  then RASMOL_BIN=rasmol_8BIT;
  if [ -x $RASMOLPATH/rasmol_XFORMS_8BIT ] && [ "$RASMOL_LIBFORMSPATH" ] ; then RASMOL_BIN=rasmol_XFORMS_8BIT;
  fi
elif [ -x $RASMOLPATH/rasmol ] ;
  then RASMOL_BIN=rasmol;
else
  echo "unable to find rasmol binary" ;
  exit 1;
fi

if [ "$RASMOL_DEBUG" ] ; then echo "selected $RASMOL_BIN" ;
fi

# Check on availability of ISO 8859-1 fonts for
# English, French, German, Italian and Spanish
#
if ( ( xlsfonts -fn "-*-*-bold-o-normal-*-14-*-iso8859-1" | grep "iso8859-1" ) > /dev/null  2>&1 ) ;
then
  if [ "$RASMOL_DEBUG" ] ; then echo "Latin1 \(ISO 8859-1\) fonts available" ;
  fi
else
  for latin1fdir in \
    $RASMOL_LANTIN1FDIR \
    $RASMOLPATH/jmk-x11-fonts-3.0 \
    $RASMOLPATH/jmk-x11-fonts \
    $RASMOLPATH/jmk \
    ./jmk-x11-fonts-3.0 \
    ./jmk-x11-fonts \
    ./jmk \
    $HOME/lib/X11/fonts/jmk-x11-fonts-3.0 \
    $HOME/lib/X11/fonts/jmk-x11-fonts \
    $HOME/lib/X11/fonts/jmk \
    /usr/lib/X11/fonts/jmk-x11-fonts-3.0 \
    /usr/lib/X11/fonts/jmk-x11-fonts \
    /usr/lib/X11/fonts/jmk \
    /sw/lib/X11/fonts/jmk-x11-fonts-3.0 \
    /sw/lib/X11/fonts/jmk-x11-fonts \
    /sw/lib/X11/fonts/jmk \
    /usr/openwin/lib/X11/fonts/jmk-x11-fonts-3.0 \
    /usr/openwin/lib/X11/fonts/jmk-x11-fonts \
    /usr/openwin/lib/X11/fonts/jmk \
    ;
  do
    if [ -d $latin1fdir ] ; then
      savecurdir=`pwd`;
      cd $latin1fdir;
      RASMOL_LATIN1FDIR=$latin1fdir;
      cd $savecurdir;
      break 1;
    fi ;
  done
  if [ "$RASMOL_LATIN1FDIR" ]; then
    if xset +fp $RASMOL_LATIN1FDIR ;
      then 
        if [ "$RASMOL_DEBUG" ] ; then echo "adding fonts from $RASMOL_LATIN1FDIR" ;
        fi
      else latin1fdir="unknown";
    fi
    if [ $latin1fdir = "unknown" ];
      then RASMOL_LATIN1FDIR= ;
           echo unable to add iso 8859-1 fonts ;
      fi
  else
    echo unable to find iso 8859-1 fonts ;
  fi
fi



# Check on availability of CP 1251 fonts for
# Cyrillic
#
if ( (xlsfonts -fn "-*-*-bold-o-normal-*-14-*-*1251" | grep "1251") > /dev/null  2>&1 );
then
  if [ "$RASMOL_DEBUG" ] ; then echo "CP 1251 fonts available" ;
  fi
else
  for cp1251fdir in \
    $RASMOL_CP1251FDIR \
    $RASMOLPATH/cyr-rfx-windows-1251 \
    $RASMOLPATH/cyr-rfx-windows-1251-1.1 \
    ./windows-1251 \
    ./cyr-rfx-windows-1251-1.1 \
    ./cyr-rfx-windows-1251 \
    $HOME/lib/X11/fonts/windows-1251 \
    $HOME/lib/X11/fonts/cyr-rfx-windows-1251-1.1 \
    $HOME/lib/X11/fonts/cyr-rfx-windows-1251 \
    /usr/lib/X11/fonts/windows-1251 \
    /usr/lib/X11/fonts/cyr-rfx-windows-1251-1.1 \
    /usr/lib/X11/fonts/cyr-rfx-windows-1251 \
    /sw/lib/X11/fonts/windows-1251 \
    /sw/lib/X11/fonts/cyr-rfx-windows-1251-1.1 \
    /sw/lib/X11/fonts/cyr-rfx-windows-1251 \
    /usr/openwin/lib/X11/fonts/windows-1251 \
    /usr/openwin/lib/X11/fonts/cyr-rfx-windows-1251-1.1 \
    /usr/openwin/lib/X11/fonts/cyr-rfx-windows-1251 \
    ;
  do
    if [ -d $cp1251fdir ] && [ -d $cp1251fdir/misc ] && [ -d $cp1251fdir/75dpi ] ; then
      savecurdir=`pwd`;
      cd $cp1251fdir;
      RASMOL_CP1251FDIR=$cp1251fdir;
      cd $savecurdir;
      break 1;
    fi ;
  done
  if [ "$RASMOL_CP1251FDIR" ]; then
    if xset +fp $RASMOL_CP1251FDIR/misc ;
      then 
        if [ "$RASMOL_DEBUG" ] ; then echo "adding fonts from $RASMOL_CP1251FDIR/misc";
        fi
      else cp1251fdir="unknown";
    fi
    if xset +fp $RASMOL_CP1251FDIR/75dpi ;
      then 
        if [ "$RASMOL_DEBUG" ] ; then echo "adding fonts from $RASMOL_CP1251FDIR/75dpi";
        fi
      else cp1251fdir="unknown";
    fi
    if [ $cp1251fdir = "unknown" ];
      then RASMOL_CP1251FDIR= ;
           echo "unable to add codepage 1251 fonts";
      fi
  else
    echo unable to find codepage 1251 fonts ;
  fi
fi



for latin1termfont in \
  "$RASMOL_LATIN1TERMFONT" \
  "-*-*fixed-medium-r-normal-*sans-13-*-*8859-1" \
  "-*-*fixed-medium-r-normal-*-13-*-*8859-1" \
  "-*-*typewriter-medium-r-normal-*sans-13-*-*8859-1" \
  "-*-*typewriter-medium-r-normal-*-13-*-*8859-1" \
  "-*-*-medium-r-normal-*-13-*-*8859-1" \
  "-*-*fixed-medium-r-normal-*sans-14-*-*8859-1" \
  "-*-*fixed-medium-r-normal-*-14-*-*8859-1" \
  "-*-*typewriter-medium-r-normal-*sans-14-*-*8859-1" \
  "-*-*typewriter-medium-r-normal-*-14-*-*8859-1" \
  "-*-*-medium-r-normal-*-14-*-*8859-1" \
  "-*-*fixed-medium-r-normal-*sans-12-*-*8859-1" \
  "-*-*fixed-medium-r-normal-*-12-*-*8859-1" \
  "-*-*typewriter-medium-r-normal-*sans-12-*-*8859-1" \
  "-*-*typewriter-medium-r-normal-*-12-*-*8859-1" \
  "-*-*-medium-r-normal-*-12-*-*8859-1" \
;
do
  if [ "$RASMOL_DEBUG" ] ; then echo "trying font $latin1termfont" ;
  fi
  if ( (xlsfonts -fn "$latin1termfont" | grep "8859-1") > /dev/null  2>&1 ); then
  RASMOL_LATIN1TERMFONT="$latin1termfont";
  break 1;
  fi
done

if [ "$RASMOL_DEBUG" ] ; then echo "selected LATIN1 terminal font $RASMOL_LATIN1TERMFONT" ;
fi

for cp1251termfont in \
  "$RASMOL_CP1251TERMFONT" \
  "-*-*fixed-medium-r-normal-*sans-13-*-*1251" \
  "-*-*fixed-medium-r-normal-*-13-*-*1251" \
  "-*-*typewriter-medium-r-normal-*sans-13-*-*1251" \
  "-*-*typewriter-medium-r-normal-*-13-*-*1251" \
  "-*-*-medium-r-normal-*-13-*-*1251" \
  "-*-*fixed-medium-r-normal-*sans-14-*-*1251" \
  "-*-*fixed-medium-r-normal-*-14-*-*1251" \
  "-*-*typewriter-medium-r-normal-*sans-14-*-*1251" \
  "-*-*typewriter-medium-r-normal-*-14-*-*1251" \
  "-*-*-medium-r-normal-*-14-*-*1251" \
  "-*-*fixed-medium-r-normal-*sans-12-*-*1251" \
  "-*-*fixed-medium-r-normal-*-12-*-*1251" \
  "-*-*typewriter-medium-r-normal-*sans-12-*-*1251" \
  "-*-*typewriter-medium-r-normal-*-12-*-*1251" \
  "-*-*-medium-r-normal-*-12-*-*1251" \
;
do
  if [ "$RASMOL_DEBUG" ] ; then echo "trying font $cp1251termfont" ;
  fi
  if ( (xlsfonts -fn "$cp1251termfont" | grep "1251") > /dev/null  2>&1 ); then
  RASMOL_CP1251TERMFONT="$cp1251termfont";
  break 1;
  fi
done

if [ "$RASMOL_DEBUG" ] ; then echo "selected CP1251 terminal font $RASMOL_CP1251TERMFONT" ;
fi

if [ "$RASMOL_LANG" = "Russian" ] ; then
  if [ "$RASMOL_DEBUG" ] ; then echo "Starting xterm with CP 1251 font $RASMOL_CP1251TERMFONT" ;
  fi
  if [ "$RASMOL_NOSPAWN" ] ; then
    exec $RASMOLPATH/$RASMOL_BIN "$@"
  else
    xterm -font "$RASMOL_CP1251TERMFONT" -e $RASMOLPATH/$RASMOL_BIN "$@" &
  fi
else
  if [ "$RASMOL_DEBUG" ] ; then echo "Starting xterm with Latin1 font $RASMOL_LATIN1TERMFONT" ;
  fi
  if [ "$RASMOL_NOSPAWN" ] ; then
    exec $RASMOLPATH/$RASMOL_BIN "$@"
  else
    xterm -font "$RASMOL_LATIN1TERMFONT" -e $RASMOLPATH/$RASMOL_BIN "$@" &
  fi
fi

else
  # we come here if there is no display
  RASMOL_BIN="rasmol_32BIT -nodisplay";
  if [ "$RASMOL_DEBUG" ] ; then echo "selected $RASMOL_BIN" ;
  fi
  exec $RASMOLPATH/$RASMOL_BIN "$@"
fi
