#!/bin/sh
###########################################################################
#                             RasMol 2.7.4.2                              #
#                                                                         #
#                                 RasMol                                  #
#                 Molecular Graphics Visualisation Tool                   #
#                            19 November 2007                             #
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
#  rasmol_install.sh
#
#  a script to install rasmol
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


VERSION=${RASMOL_VERSION-"RasMol_2_7_4"};

prefix= ;
system="no" ;
compilefonts="no";
shell="/bin/sh" ;


for rasmolarg in "$@" ;
do
  case $rasmolarg in
     --prefix=* )
     prefix=`echo $rasmolarg|sed "s/--prefix=//"`;
     echo $prefix;
    ;;
     --shell=* )
     shell=`echo $rasmolarg|sed "s/--shell=//"`;
    ;;
     --system )
     system="yes" ;
    ;; 
     --local )
     system="no" ;
    ;;
     --compilefonts )
     compilefonts="yes";
    ;;
    --help | * )
      echo "rasmol_install.sh usage:"
      echo "  rasmol_run.sh [--help] | "
      echo "    [--prefix=installdir] |"
      echo "    [--compilefonts] |"
      echo "    [--system] | [--local] "
      echo "  installs rasmol binaries, help files and fonts"
      echo ""
      echo "optional variables:"
      echo "   RASMOLPATH          path to rasmol directory"
      echo "   RASMOL_LANTIN1FDIR  path to X11 ISO 8859-1 font directory"
      echo "   RASMOL_CP1251FDIR   path to X11 ISO CP 1251 font directory"
      echo "   RASMOL_CHINESEFDIR  path to X11 Intlfonts-1.2.1/Chinese directory"
      echo "   RASMOL_JAPANESEFDIR  path to X11 Intlfonts-1.2.1/Japanese.X directory"
      echo "   RASMOL_DEBUG        if non-empty, report settings"
      exit 1;
     
  esac;
done


if [ "$system" = "yes" ] ; then
  if ! [ `whoami` = "root" ] ; then
    echo "you must be root to do a system install"
    echo "rasmsol_install.sh exiting"
    exit 1;
  fi
fi

#  Find rasmol target directory
#

if [ "$prefix" ] ; then
  RASMOLPATH=$prefix/lib/$VERSION
elif [ "$system" = "no" ] ; then

if [ "$RASMOLPATH" ] && ! [ -f "$RASMOLPATH" ]; then
  if ! [ -d "$RASMOLPATH" ] ; then
    echo -n " Directory \"$RASMOLPATH\" does not exist; create it? [y/N] ";
    read ok
    if  [ "$ok" = "y" ] || [ "$ok" != "Y" ]   ; then
      mkdir -p "$RASMOLPATH";
    fi
  fi
fi

for rasmolpath in \
    $RASMOLPATH \
    $HOME/lib/$VERSION \
; 
do
  if [ -d "$rasmolpath" ]; then
    savecurdir=`pwd`;
    cd $rasmolpath;
    RASMOLPATH=`pwd`; export RASMOLPATH;
    cd $savecurdir;
    break 1;
  fi
done

else
for rasmolpath in \
    $RASMOLPATH \
    /usr/local/lib/$VERSION \
    /usr/lib/$VERSION \
    /sw/lib/$VERSION \
; 
do
  echo $rasmolpath
  if [ -d "$rasmolpath" ]; then
      savecurdir=`pwd`;
      cd $rasmolpath;
      RASMOLPATH=`pwd`; export RASMOLPATH;
      cd $savecurdir;
      break 1;
  fi
done
fi

if ! [ "$RASMOLPATH" ] ; then
  if [ "$system" = "no" ] ; then
    RASMOLPATH=$HOME/lib/$VERSION
  else
    RASMOLPATH=/usr/lib/$VERSION
  fi
fi

if ! [ -d $RASMOLPATH ] ; then
  if ( ! (mkdir -p $RASMOLPATH ) ) ; then
    echo "Failed to create $RASMOLPATH";
    exit 1;
  fi
fi

echo -n "Install rasmol into \"$RASMOLPATH\"? [y/N] ";
read ok
if  [ "$ok" != "y" ] && [ "$ok" != "Y" ]   ; then exit 1 ;
fi

savecurdir=`pwd` ;
cd $RASMOLPATH ;
rasmolpath=`pwd` ;
cd $savecurdir ;
libname=`dirname $rasmolpath`

if [ "`basename $libname`" = "lib" ] ; then
  prefix=`dirname $libname` ;
  bindest=$prefix/bin ;
else
  bindest=$libname ;
  
fi

echo -n "Install rasmol program wrapper in \"$bindest/rasmol\"? [y/N] ";
read ok
if  [ "$ok" != "y" ] && [ "$ok" != "Y" ]; then unset bindest ;
fi


if ! [ -d $bindest ] ; then
  mkdir -p $bindest ;
fi


for program in \
  rasmol_run.sh \
  rasmol_install.sh \
  rasmol_32BIT \
  rasmol_XFORMS_32BIT \
  rasmol_16BIT \
  rasmol_XFORMS_16BIT \
  rasmol_8BIT \
  rasmol_XFORMS_8BIT \
;
do
  if [ -f $program ] ; then
    cp $program $RASMOLPATH ;
    chmod 755 $RASMOLPATH/$program ;
  elif [ -f ${program}.gz ] ; then
    gunzip < ${program}.gz > $RASMOLPATH/$program ;
    chmod 755 $RASMOLPATH/$program ;
  else
    echo "Unable to find $program" ;
  fi
  if [ "$program" = "rasmol_run.sh" ] && [ -f "$RASMOLPATH/$program" ]; then
    if [ "$shell" != "/bin/sh" ]; then
      ed "$RASMOLPATH/$program" <<-EOF_EOF_EOF
		1,1s:/bin/sh:$shell:
		w
		q
		EOF_EOF_EOF
    fi
  fi
done

for document in \
  rasmol.hlp \
  NOTICE \
  RASLIC \
  GPL \
  Licenses.txt \
  INSTALL \
  README.txt \
;
do
if [ -f $document ] ; then
  cp $document $RASMOLPATH ;
  chmod 644 $RASMOLPATH/$document ;
elif [ -f ${document}.gz ] ; then
  gunzip < ${document}.gz > $RASMOLPATH/$document ;
  chmod 644 $RASMOLPATH/$document ;
elif [ -f ../$document ] ; then
  cp ../$document $RASMOLPATH ;
  chmod 644 $RASMOLPATH/$document ;
elif [ -f ../$document.gz ] ; then
  gunzip < ../$document.gz > $RASMOLPATH/$document ;
  chmod 644 $RASMOLPATH/$document ;
elif [ -d ../doc ] ; then
  if [ -f ../doc/$document ] ; then
    cp ../doc/$document $RASMOLPATH/$document ;
    chmod 644 $RASMOLPATH/$document ;
  elif [ -f ../doc/${document}.gz ] ; then
    gunzip < ../doc/${document}.gz > $RASMOLPATH/$document ;
    chmod 644 $RASMOLPATH/$document ;
  else
    echo "Unable to find $document" ;
  fi
else
  echo "Unable to find $document" ;
fi
done


# Check on availability of ISO 8859-1 fonts for
# English, French, German, Italian and Spanish
#
if ( (xlsfonts -fn "-*-*-bold-o-normal-*-14-*-iso8859-1" | grep "iso8859-1") > /dev/null  2>&1 );
then
  echo Latin1 \(ISO 8859-1\) fonts available
elif [ -d $RASMOLPATH/jmk ] ; then
  echo Latin1 fonts in $RASMOLPATH/jmk
else
  for latin1fdir in \
    $RASMOL_LANTIN1FDIR \
    ./jmk-x11-fonts-3.0 \
    ./jmk-x11-fonts\
    ./jmk \
    ../external_packages/jmk-x11-fonts-3.0 \
    ../external_packages/jmk-x11-fonts \
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
    rm -r -f $RASMOLPATH/jmk ;
    cp -r -p $RASMOL_LATIN1FDIR $RASMOLPATH/jmk ;
    echo Installed Latin1 fonts in $RASMOLPATH/jmk
    if [ "$compilefonts" = "yes" ] ; then
      savecurdir=`pwd`;
      cd $RASMOLPATH/jmk;
      rm -f *.pcf;
      rm -f *.pcf.gz;
      rm -f *.pcf.Z;
      for file in `ls *.bdf`; do bdftopcf $file > `basename $file .bdf`.pcf; done
      mkfontdir `pwd`;
      cd $savecurdir;
    fi
  else
    echo Latin1 fonts not found
  fi
fi


# Check on availability of Intlfonts-1.2.1 fonts for
# Chinese
#

if ( (xlsfonts -fn "*-16-*-gb2312.1980-0" | grep "gb2312.1980") > /dev/null  2>&1 );
then
  echo Chinese \(gb2312.1980\) fonts available
elif [ -d $RASMOLPATH/Chinese.X ] ; then
  echo Chinese fonts in $RASMOLPATH/Chinese.X
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
    rm -r -f $RASMOLPATH/Chinese.X ;
    cp -r -p $RASMOL_CHINESEFDIR $RASMOLPATH/Chinese.X ;
    echo Installed Latin1 fonts in $RASMOLPATH/jmk
    if [ "$compilefonts" = "yes" ] ; then
      savecurdir=`pwd`;
      cd $RASMOLPATH/Chinese.X;
      rm -f *.pcf;
      rm -f *.pcf.gz;
      rm -f *.pcf.Z;
      for file in `ls *.bdf`; do bdftopcf $file > `basename $file .bdf`.pcf; done
      mkfontdir `pwd`;
      cd $savecurdir;
    fi
  else
    echo Chinese fonts not found
  fi
fi

# Check on availability of Intlfonts-1.2.1 fonts for
# Japanese
#

if ( (xlsfonts -fn "*-r-*-14-*-jisx0208.1983-0" | grep "jisx0208.1983") > /dev/null  2>&1 );
then
  echo Japanese \(jisx0208.1983\) fonts available
elif [ -d $RASMOLPATH/Japanese ] ; then
  echo Japanese fonts in $RASMOLPATH/Japanese.X
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
      cd $jpapnesefdir;
      RASMOL_JAPANESEFDIR=$japanesefdir;
      cd $savecurdir;
      break 1;
    fi ;
  done
  if [ "$RASMOL_JAPANESEFDIR" ]; then
    rm -r -f $RASMOLPATH/Japanese.X ;
    cp -r -p $RASMOL_JAPANESEFDIR $RASMOLPATH/Japanese.X ;
    echo Installed Latin1 fonts in $RASMOLPATH/jmk
    if [ "$compilefonts" = "yes" ] ; then
      savecurdir=`pwd`;
      cd $RASMOLPATH/Japanese.X;
      rm -f *.pcf;
      rm -f *.pcf.gz;
      rm -f *.pcf.Z;
      for file in `ls *.bdf`; do bdftopcf $file > `basename $file .bdf`.pcf; done
      mkfontdir `pwd`;
      cd $savecurdir;
    fi
  else
    echo Japanese fonts not found
  fi
fi



# Check on availability of CP 1251 fonts for
# Cyrillic
#
if ( (xlsfonts -fn "-*-*-bold-o-normal-*-14-*-*1251" | grep "1251") > /dev/null  2>&1 );
then
  echo CP 1251 fonts available
elif [ -d $RASMOLPATH/cyr-rfx-windows-1251 ] ; then
  echo CP 1251 fonts in $RASMOLPATH/cyr-rfx-windows-1251
else
  for cp1251fdir in \
    $RASMOL_CP1251FDIR \
    ./windows-1251 \
    ./cyr-rfx-windows-1251-1.1 \
    ./cyr-rfx-windows-1251 \
    ../external_packages/cyr-rfx-windows-1251-1.1 \
    ../external_packages/cyr-rfx-windows-1251 \
    $HOME/lib/X11/fonts/windows-1251 \
    $HOME/lib/X11/fonts/cyr-rfx-windows-1251-1.1 \
    $HOME/lib/X11/fonts/cyr-rfx-windows-1251 \
    /usr/lib/X11/fonts/windows-1251 \
    /usr/lib/X11/fonts/cyr-rfx-windows-1251-1.1 \
    /usr/lib/X11/fonts/cyr-rfx-windows-1251 \
    /sw/lib/X11/fonts/windows-1251 \
    /sw/lib/X11/fonts/cyr-rfx-windows-1251-1.1 \
    /sw/lib/X11/fonts/cyr-rfx-windows-1251 \
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
    rm -r -f $RASMOLPATH/cyr-rfx-windows-1251 ;
    cp -r -p $RASMOL_CP1251FDIR $RASMOLPATH/cyr-rfx-windows-1251 ;
    echo installed CP 1251 fonts in $RASMOLPATH/cyr-rfx-windows-1251
    if [ "$compilefonts" = "yes" ] ; then
      savecurdir=`pwd`;
      cd $RASMOLPATH/cyr-rfx-windows-1251;
      for fonts in 75dpi misc; do
        cd $fonts;
        rm -f *.pcf;
        rm -f *.pcf.gz;
        rm -f *.pcf.Z;
        for file in `ls *.bdf`; do bdftopcf $file > `basename $file .bdf`.pcf; done
        mkfontdir `pwd`;
        cd ..;
      done
      cd $savecurdir;
    fi
  else
    echo CP 1251 fonts not found
  fi
fi


if [ "$bindest" ] ; then 
  if [ -e "$bindest/rasmol" ];  then
    if [ -e "$bindest/rasmol_save" ]; then
      echo "There is an existing \"$bindest/rasmol_save\"" ;
      echo -n "Replace this file with the prior \"$bindest/rasmol\"? [y/N] " ;
      read ok ;
      if [ $ok = "y" ]  ||  [ "$ok" = "Y" ] ; then
        rm -rf $bindest/rasmol_save ;
        mv $bindest/rasmol $bindest/rasmol_save ;
      else
        echo "There is an existing \"$bindest/rasmol\""
        echo -n "Replace this with the new  \"$bindest/rasmol\"? [y/N] "
        read ok ;
        if [ $ok != "y" ] && [ "$ok" != "Y" ] ; then
          echo "rasmol_nstall exiting without installing new rasmol wrapper"
          exit 1;
        fi
      fi
    else
      mv $bindest/rasmol $bindest/rasmol_old ;
    fi
  fi
  
  rm -f $bindest/rasmol ;
  echo "#!$shell" > $bindest/rasmol ;
  echo "RASMOLPATH=$RASMOLPATH ; export RASMOLPATH" >> $bindest/rasmol;
  echo "$RASMOLPATH/rasmol_run.sh \"\$@\"" >> $bindest/rasmol;
  chmod 755 $bindest/rasmol;

fi
