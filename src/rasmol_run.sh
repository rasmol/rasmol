#!/bin/sh
###########################################################################
#                             RasMol 2.7.5.3                              #
#                                                                         #
#                                 RasMol                                  #
#                 Molecular Graphics Visualisation Tool                   #
#                               4 May 2012                                #
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
#  Bernstein          RasMol 2.7.1     Jun 99       1998-2008             #
#                     RasMol 2.7.1.1   Jan 01                             #
#                     RasMol 2.7.2     Aug 00                             #
#                     RasMol 2.7.2.1   Apr 01                             #
#                     RasMol 2.7.2.1.1 Jan 04                             #
#                     RasMol 2.7.3     Feb 05                             #
#                     RasMol 2.7.3.1   Apr 06                             #
#                     RasMol 2.7.4     Nov 07                             #
#                     RasMol 2.7.4.2   Mar 08                             #
#                                                                         #
# RasMol 2.7.3 incorporates changes by Clarice Chigbo, Ricky Chachra,     #
# and Mamoru Yamanishi.  Work on RasMol 2.7.3 supported in part by        #
# grants DBI-0203064, DBI-0315281 and EF-0312612 from the U.S. National   #
# Science Foundation and grant DE-FG02-03ER63601 from the U.S. Department #
# of Energy.  RasMol 2.7.4 incorporates changes by G. Todorov, Nan Jia,   #
# N. Darakev, P. Kamburov, G. McQuillan, J. Jemilawon.  Work on RasMol    #
# 2.7.4 supported in part by grant 1R15GM078077-01 from the National      #
# Institute of General Medical Sciences (NIGMS). The content is solely    #
# the responsibility of the authors and does not necessarily represent    #
# the official views of the funding organizations.                        #
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
#  G. Pozhvanov                         2.7.3 menus and messages Russian  #
#  G. Todorov                           2.7.3 menus and messages Bulgarian#
#  Nan Jia, G. Todorov                  2.7.3 menus and messages Chinese  #
#  Mamoru Yamanishi, Katajima Hajime    2.7.3 menus and messages Japanese #
#                                                                         #
#                             This Release by                             #
# Herbert J. Bernstein, Bernstein + Sons, P.O. Box 177, Bellport, NY, USA #
#                       yaya@bernstein-plus-sons.com                      #
#               Copyright(C) Herbert J. Bernstein 1998-2008               #
#                                                                         #
#   This version is based in directly on RasMol version 2.7.4, on RasMol  #
#   version 2.7.3.1, on RasMol version 2.7.3, on RasMol version 2.7.2.1.1,#
#   on RasMol version 2.7.2, on RasMol version 2.7.1, on RasMol version   #
#   2.6_CIF.2, on RasMol version 2.6x1, on RasMol version 2.6.4, and      #
#   RasMol 2.5-ucb and 2.6-ucb.                                           #
#                                                                         #
#   Please read the file NOTICE for important notices which apply to this # 
#   package and for license terms (GPL  or RASLIC).                       #
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
#  Rev, 15 March 2008 for Rasmol 2.7.4.2
#

# Process command line options
#


VERSION=${RASMOL_VERSION-"RasMol_2_7_5_3"};

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
      echo "   RASMOL_LIBXiPATH    path to Xi library directory
      echo "   RASMOL_LIBXextPATH  path to Xext library directory
      echo "   RASMOL_LANTIN1FDIR  path to X11 ISO 8859-1 font directory"
      echo "   RASMOL_CP1251FDIR   path to X11 ISO CP 1251 font directory"
      echo "   RASMOL_CHINESEFDIR  path to X11 Intlfonts-1.2.1/Chinese directory"
      echo "   RASMOL_JAPANESEFDIR  path to X11 Intlfonts-1.2.1/Japanese.X directory"
      echo "   RASMOL_DEBUG        if non-empty, report settings"
      echo "   RASMOL_NOSPAWN      if non-empty, do not spawn an intermediary xterm"
      echo "   RASMOL_SYSTEM_XFORMS if non-empty search for system libxforms"
      echo "   RASMOL_SYSTEM_LIBXI  if non-empty search for system libXi"
      echo "   RASMOL_SYSTEM_LIBXEXT  if non-empty search for system libXext"
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


if [ "$DISPLAY" ] &&  ( xdpyinfo > /dev/null 2>&1 ) ; then 

#
#  Find libforms
#


if [ "$RASMOL_SYSTEM_XFORMS" ] ; then
  havelibforms=

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
      if [ "$RASMOL_DEBUG" ] ; then echo "trying $RASMOL_LIBFORMSPATH" ;
      fi
  if [ -d "$RASMOL_LIBFORMSPATH" ]; then
    if [ -f "$RASMOL_LIBFORMSPATH/libforms.a" ] || \
       [ -f "$RASMOL_LIBFORMSPATH/libforms.so" ] || \
       [ -f "$RASMOL_LIBFORMSPATH/libforms.dylib" ] ; then
       savecurdir=`pwd`;
       cd $RASMOL_LIBFORMSPATH;
       RASMOL_LIBFORMSPATH=`pwd`;
       cd $savecurdir;
        havelibforms=1;
       break 1;
    fi
  fi
done

  if [ "$havelibforms" ]; then 
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
    # OSX
    if [ "$DYLD_LIBARY_PATH" ]; then
      DYLD_LIBARY_PATH=$DYLD_LIBARY_PATH:$RASMOL_LIBFORMSPATH; export DYLD_LIBARY_PATH;
    else
      DYLD_LIBARY_PATH=$RASMOL_LIBFORMSPATH; export DYLD_LIBARY_PATH;
fi
  fi

else
  havelibforms=1
fi


#
#  Find libXi
#
if [ "$RASMOL_SYSTEM_LIBXI" ] ; then
havelibXi=
for RASMOL_LIBXIPATH in \
  $RASMOL_LIBXiPATH \
  $HOME/lib \
  /lib \
  /usr/lib \
  /opt/X11/lib \
  /opt/local/lib \
  /usr/X11/lib \
  /usr/local/lib \
  /sw/lib \
  /usr/openwin/lib \
  . \
  ;
  do
    if [ "$RASMOL_DEBUG" ] ; then echo "trying $RASMOL_LIBXIPATH" ;
    fi
    if [ -d "$RASMOL_LIBXIPATH" ]; then
    if [ -f "$RASMOL_LIBXIPATH/libXi.a" ] || \
    [ -f "$RASMOL_LIBXIPATH/libXi.so" ] || \
    [ -f "$RASMOL_LIBXIPATH/libXi.dylib" ] ; then
    savecurdir=`pwd`;
    cd $RASMOL_LIBXIPATH;
    RASMOL_LIBXIPATH=`pwd`;
    cd $savecurdir;
    havelibXi=1;
    if [ "$RASMOL_DEBUG" ] ; then echo "using Xi library in $RASMOL_LIBXIPATH" ;
    fi
    # LINUX
    if [ "$LD_LIBRARY_PATH" ]; then
      LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$RASMOL_LIBXIPATH; export LD_LIBRARY_PATH;
    else
      LD_LIBRARY_PATH=$RASMOL_LIBXIPATH; export LD_LIBRARY_PATH;
    fi
    if [ "$RASMOL_DEBUG" ] ; then echo "using library path $LD_LIBRARY_PATH" ;
    fi
    # HPUX
    if [ "$SHLIB_PATH" ]; then
      SHLIB_PATH=$SHLIB_PATH:$RASMOL_LIBXIPATH; export SHLIB_PATH;
    else
      SHLIB_PATH=$RASMOL_LIBXIPATH; export SHLIB_PATH;
    fi
    # AIX
    if [ "$LIBPATH" ]; then
      LIBPATH=$LIBPATH:$RASMOL_LIBXIPATH; export LIBPATH;
    else
      LIBPATH=$RASMOL_LIBXIPATH; export LIBPATH;
    fi
    # OSX
    if [ "$DYLD_LIBARY_PATH" ]; then
      DYLD_LIBARY_PATH=$DYLD_LIBARY_PATH:$RASMOL_LIBXIPATH; export DYLD_LIBARY_PATH;
    else
      DYLD_LIBARY_PATH=$RASMOL_LIBXIPATH; export DYLD_LIBARY_PATH;
    fi
    break 1;
  fi
  fi
  done
else
  havelibXi=1
fi


#
#  Find libXext
#
if [ "$RASMOL_SYSTEM_LIBXEXT" ] ; then
havelibXext=
for RASMOL_LIBXEXTPATH in \
  $RASMOL_LIBXextPATH \
  $HOME/lib \
  /lib \
  /usr/lib \
  /opt/X11/lib \
  /opt/local/lib \
  /usr/X11/lib \
  /usr/local/lib \
  /sw/lib \
  /usr/openwin/lib \
  . \
  ;
  do
    if [ "$RASMOL_DEBUG" ] ; then echo "trying $RASMOL_LIBXEXTPATH" ;
    fi
    if [ -d "$RASMOL_LIBXEXTPATH" ]; then
    if [ -f "$RASMOL_LIBXEXTPATH/libXext.a" ] || \
    [ -f "$RASMOL_LIBXEXTPATH/libXext.so" ] || \
    [ -f "$RASMOL_LIBXEXTPATH/libXext.dylib" ] ; then
    savecurdir=`pwd`;
    cd $RASMOL_LIBXEXTPATH;
    RASMOL_LIBXEXTPATH=`pwd`;
    cd $savecurdir;
    havelibXext=1;
    if [ "$RASMOL_DEBUG" ] ; then echo "using Xext library in $RASMOL_LIBXEXTPATH" ;
    fi
    # LINUX
    if [ "$LD_LIBRARY_PATH" ]; then
      LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$RASMOL_LIBXEXTPATH; export LD_LIBRARY_PATH;
    else
      LD_LIBRARY_PATH=$RASMOL_LIBXEXTPATH; export LD_LIBRARY_PATH;
    fi
    if [ "$RASMOL_DEBUG" ] ; then echo "using library path $LD_LIBRARY_PATH" ;
    fi
    # HPUX
    if [ "$SHLIB_PATH" ]; then
      SHLIB_PATH=$SHLIB_PATH:$RASMOL_LIBXEXTPATH; export SHLIB_PATH;
    else
      SHLIB_PATH=$RASMOL_LIBXEXTPATH; export SHLIB_PATH;
    fi
    # AIX
    if [ "$LIBPATH" ]; then
      LIBPATH=$LIBPATH:$RASMOL_LIBXEXTPATH; export LIBPATH;
    else
      LIBPATH=$RASMOL_LIBXEXTPATH; export LIBPATH;
    fi
    # OSX
    if [ "$DYLD_LIBRARY_PATH" ]; then
      DYLD_LIBRARY_PATH=$DYLD_LIBRARY_PATH:$RASMOL_LIBXEXTPATH; export DYLD_LIBRARY_PATH;
    else
      DYLD_LIBRARY_PATH=$RASMOL_LIBXEXTPATH; export DYLD_LIBRARY_PATH;
    fi
    break 1;
  fi
  fi
  done
else
  havelibXext=1
fi



# Check on the available visuals

if [ -x $RASMOLPATH/rasmol_32BIT ] && (  xdpyinfo | grep "bits_per_pixel 32" > /dev/null 2>&1 );
  then RASMOL_BIN=rasmol_32BIT;
  if [ -x $RASMOLPATH/rasmol_XFORMS_32BIT ] && [ "$havelibforms" ] && [ "$havelibXi" ] && [ "$havelibXext" ] ; then RASMOL_BIN=rasmol_XFORMS_32BIT;
  fi
elif [ -x $RASMOLPATH/rasmol_16BIT ] && (  xdpyinfo | grep "bits_per_pixel 16" > /dev/null  2>&1 );
  then RASMOL_BIN=rasmol_16BIT;
  if [ -x $RASMOLPATH/rasmol_XFORMS_16BIT ] && [ "$havelibforms" ] && [ "$havelibXi" ]  && [ "$havelibXext" ] ; then RASMOL_BIN=rasmol_XFORMS_16BIT;
  fi
elif [ -x $RASMOLPATH/rasmol_8BIT ] && (  xdpyinfo | grep "bits_per_pixel 8"  > /dev/null 2>&1 );
  then RASMOL_BIN=rasmol_8BIT;
  if [ -x $RASMOLPATH/rasmol_XFORMS_8BIT ] && [ "$havelibforms" ] && [ "$havelibXi" ]  && [ "$havelibXext" ] ; then RASMOL_BIN=rasmol_XFORMS_8BIT;
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

# Check on availability of Chinese GB2312 fonts 
#
if ( (xlsfonts -fn "*-16-*-gb2312.1980-0" | grep "gb2312.1980") > /dev/null  2>&1 );
then
  if [ "$RASMOL_DEBUG" ] ; then echo "Chinese \(gb2312.1980\) fonts available" ;
  fi
else
  for chinesefdir in \
    $RASMOL_CHINESEFDIR \
    ./intlfonts-1.2.1/Chinese.X \
    ./Chinese.X \
    ../external_packages/intlfonts-1.2.1/Chinese.X \
    ../external_packages/Chinese.X \
    $HOME/lib/X11/fonts/intlfonts-1.2.1/Chinese.X \
    $HOME/lib/X11/fonts/Chinese.X \
    /usr/lib/X11/fonts/intlfonts-1.2.1/Chinese.X \
    /usr/lib/X11/fonts/Chinese.X \
    /sw/lib/X11/fonts/intlfonts-1.2.1/Chinese.X \
    /sw/lib/X11/fonts/Chinese.X \
    /usr/openwin/lib/X11/fonts/intlfonts-1.2.1/Chinese.X \
    /usr/openwin/lib/X11/fonts/Chinese.X \
    ;
  do
    if [ -d $chinesefdir ] ; then
      savecurdir=`pwd`;
      cd $chinesefdir;
      RASMOL_CHINESEFDIR=$chinesefdir;
      cd $savecurdir;
      break 1;
    fi ;
  done
  if [ "$RASMOL_CHINESEFDIR" ]; then
    if xset +fp $RASMOL_CHINESEFDIR ;
      then 
        if [ "$RASMOL_DEBUG" ] ; then echo "adding fonts from $RASMOL_CHINESEFDIR" ;
        fi
      else chinesefdir="unknown";
    fi
    if [ $chinesefdir = "unknown" ];
      then RASMOL_CHINESEFDIR= ;
           echo unable to add Chinese GB2312 fonts ;
      fi
  else
    echo unable to find Chinese GB2312 fonts ;
  fi
fi

# Check on availability of Japanese jisx0208 fonts 
#
if ( (xlsfonts -fn "*-r-*-14-*-jisx0208.1983-0" | grep "jisx0208.1983") > /dev/null  2>&1 );
then
  if [ "$RASMOL_DEBUG" ] ; then echo "Japanese \(jisx208\) fonts available" ;
  fi
else
  for japanesefdir in \
    $RASMOL_JAPANESEFDIR \
    ./intlfonts-1.2.1/Japanese.X \
    ./Japanese.X \
    ../external_packages/intlfonts-1.2.1/Japanese.X \
    ../external_packages/Japanese.X \
    $HOME/lib/X11/fonts/intlfonts-1.2.1/Japanese.X \
    $HOME/lib/X11/fonts/Japanese.X \
    /usr/lib/X11/fonts/intlfonts-1.2.1/Japanese.X \
    /usr/lib/X11/fonts/Japanese.X \
    /sw/lib/X11/fonts/intlfonts-1.2.1/Japanese.X \
    /sw/lib/X11/fonts/Japanese.X \
    /usr/openwin/lib/X11/fonts/intlfonts-1.2.1/Japanese.X \
    /usr/openwin/lib/X11/fonts/Japanese.X \
    ;
  do
    if [ -d $japanesefdir ] ; then
      savecurdir=`pwd`;
      cd $japanesefdir;
      RASMOL_JAPANESEFDIR=$japanesefdir;
      cd $savecurdir;
      break 1;
    fi ;
  done
  if [ "$RASMOL_JAPANESEFDIR" ]; then
    if xset +fp $RASMOL_JAPANESEFDIR ;
      then 
        if [ "$RASMOL_DEBUG" ] ; then echo "adding fonts from $RASMOL_JAPANESEFDIR" ;
        fi
      else japanesefdir="unknown";
    fi
    if [ $japanesefdir = "unknown" ];
      then RASMOL_JAPANESEFDIR= ;
           echo unable to add Japanese jisx208 fonts ;
      fi
  else
    echo unable to find Japanese jisx208 fonts ;
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

if [ "$RASMOL_DEBUG" ] ; then echo "selected CP 1251 Cyrillic terminal font $RASMOL_CP1251TERMFONT" ;
fi

for chinesetermfont in \
  "$RASMOL_CHINESETERMFONT" \
  "*-*-r-normal--16-*-gb2312.1980-0" \
;
do
  if [ "$RASMOL_DEBUG" ] ; then echo "trying font $chinesetermfont" ;
  fi
  if ( (xlsfonts -fn "$chinesetermfont" | grep -i "gb2312") > /dev/null  2>&1 ); then
  RASMOL_CHINESETERMFONT="$chinesetermfont";
  break 1;
  fi
done


if [ "$RASMOL_DEBUG" ] ; then echo "selected Chinese terminal font $RASMOL_CHINESETERMFONT" ;
fi

for japanesetermfont in \
  "$RASMOL_JAPANESETERMFONT" \
  "*-r-*-14-*-jisx0208.1983-0" \
;
do
  if [ "$RASMOL_DEBUG" ] ; then echo "trying font $japanesetermfont" ;
  fi
  if ( (xlsfonts -fn "$japanesetermfont" | grep -i "jisx0208") > /dev/null  2>&1 ); then
  RASMOL_JAPANESETERMFONT="$japanesetermfont";
  break 1;
  fi
done


if [ "$RASMOL_DEBUG" ] ; then echo "selected Japanese terminal font $RASMOL_JAPANESETERMFONT" ;
fi


if [ "$RASMOL_LANG" = "Chinese" ] ; then
  if [ "$RASMOL_DEBUG" ] ; then echo "Starting xterm with Chinese font $RASMOL_CHINESETERMFONT" ;
  fi
  export LC_ALL=zh_CN.GB2312;
  if [ "$RASMOL_NOSPAWN" ] ; then
    exec $RASMOLPATH/$RASMOL_BIN "$@"
  else
    cxterm -fh "$RASMOL_CHINESETERMFONT" -hz GB -e $RASMOLPATH/$RASMOL_BIN "$@" &
  fi
else
if [ "$RASMOL_LANG" = "Japanese" ] ; then
  if [ "$RASMOL_DEBUG" ] ; then echo "Starting xterm with Japanese font $RASMOL_JAPANESETERMFONT" ;
  fi
  export LC_ALL=ja_JP.eucjp;
  if [ "$RASMOL_NOSPAWN" ] ; then
    exec $RASMOLPATH/$RASMOL_BIN "$@"
  else
    cxterm -fh "$RASMOL_JAPANESETERMFONT" -hz EUC -e $RASMOLPATH/$RASMOL_BIN "$@" &
  fi
else
if [ "$RASMOL_LANG" = "Russian" ] ; then
  if [ "$RASMOL_DEBUG" ] ; then echo "Starting xterm with CP 1251 font $RASMOL_CP1251TERMFONT" ;
  fi
  if [ "$RASMOL_NOSPAWN" ] ; then
    exec $RASMOLPATH/$RASMOL_BIN "$@"
  else
    xterm -font "$RASMOL_CP1251TERMFONT" -e $RASMOLPATH/$RASMOL_BIN "$@" &
  fi
else
if [ "$RASMOL_LANG" = "Bulgarian" ] ; then
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
fi
fi
fi

else
  # we come here if there is no display
  RASMOL_BIN="rasmol_32BIT -nodisplay";
  if [ "$RASMOL_DEBUG" ] ; then echo "selected $RASMOL_BIN" ;
  fi
  exec $RASMOLPATH/$RASMOL_BIN "$@"
fi
