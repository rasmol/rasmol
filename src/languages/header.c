/***************************************************************************
 *                              RasMol 2.7.5                               *
 *                                                                         *
 *                                 RasMol                                  *
 *                 Molecular Graphics Visualisation Tool                   *
 *                              13 June 2009                               *
 *                                                                         *
 *                   Based on RasMol 2.6 by Roger Sayle                    *
 * Biomolecular Structures Group, Glaxo Wellcome Research & Development,   *
 *                      Stevenage, Hertfordshire, UK                       *
 *         Version 2.6, August 1995, Version 2.6.4, December 1998          *
 *                   Copyright (C) Roger Sayle 1992-1999                   *
 *                                                                         *
 *                          and Based on Mods by                           *
 *Author             Version, Date             Copyright                   *
 *Arne Mueller       RasMol 2.6x1   May 98     (C) Arne Mueller 1998       *
 *Gary Grossman and  RasMol 2.5-ucb Nov 95     (C) UC Regents/ModularCHEM  *
 *Marco Molinaro     RasMol 2.6-ucb Nov 96         Consortium 1995, 1996   *
 *                                                                         *
 *Philippe Valadon   RasTop 1.3     Aug 00     (C) Philippe Valadon 2000   *
 *                                                                         *
 *Herbert J.         RasMol 2.7.0   Mar 99     (C) Herbert J. Bernstein    * 
 *Bernstein          RasMol 2.7.1   Jun 99         1998-2008               *
 *                   RasMol 2.7.1.1 Jan 01                                 *
 *                   RasMol 2.7.2   Aug 00                                 *
 *                   RasMol 2.7.2.1 Apr 01                                 *
 *                   RasMol 2.7.2.1.1 Jan 04                               *
 *                   RasMol 2.7.3   Feb 05                                 *
 *                   RasMol 2.7.3.1 Apr 06                                 *
 *                   RasMol 2.7.4   Nov 07                                 *
 *                   RasMol 2.7.4.1 Jan 08                                 *
 *                   RasMol 2.7.4.2 Mar 08                                 *
 *                   RasMol 2.7.5   May 09                                 *
 *                                                                         *
 * RasMol 2.7.5 incorporates changes by T. Ikonen, G. McQuillan, N. Darakev*
 * and L. Andrews (via the neartree package).  Work on RasMol 2.7.5        *
 * supported in part by grant 1R15GM078077-01 from the National Institute  *
 * of General Medical Sciences (NIGMS), U.S. National Institutes of Health *
 * and by grant ER63601-1021466-0009501 from the Office of Biological &    *
 * Environmental Research (BER), Office of Science, U. S. Department of    *
 * Energy.  RasMol 2.7.4 incorporated  changes by G. Todorov, Nan Jia,     *
 * N. Darakev, P. Kamburov, G. McQuillan, and J. Jemilawon. Work on RasMol *
 * 2.7.4 supported in part by grant 1R15GM078077-01 from the NIGMS/NIH and *
 * grant ER63601-1021466-0009501 from BER/DOE.  RasMol 2.7.3 incorporates  *
 * changes by Clarice Chigbo, Ricky Chachra, and Mamoru Yamanishi.  Work   *
 * on RasMol 2.7.3 supported in part by grants DBI-0203064, DBI-0315281    *
 * and EF-0312612 from the U.S. National Science Foundation and grant      *
 * DE-FG02-03ER63601 from BER/DOE. The content is solely the responsibility*
 * of the authors and does not necessarily represent the official views of *
 * the funding organizations.                                              *
 *                                                                         *
 * The code for use of RasMol under GTK in RasMol 2.7.4.2 and 2.7.5 was    *
 * written by Teemu Ikonen.                                                *
 *                                                                         *
 *                    and Incorporating Translations by                    *
 *  Author                               Item                     Language *
 *  Isabel Servan Martinez,                                                *
 *  Jose Miguel Fernandez Fernandez      2.6   Manual             Spanish  *
 *  Jose Miguel Fernandez Fernandez      2.7.1 Manual             Spanish  *
 *  Fernando Gabriel Ranea               2.7.1 menus and messages Spanish  *
 *  Jean-Pierre Demailly                 2.7.1 menus and messages French   *
 *  Giuseppe Martini, Giovanni Paolella, 2.7.1 menus and messages          *
 *  A. Davassi, M. Masullo, C. Liotto    2.7.1 help file          Italian  *
 *  G. Pozhvanov                         2.7.3 menus and messages Russian  *
 *  G. Todorov                           2.7.3 menus and messages Bulgarian*
 *  Nan Jia, G. Todorov                  2.7.3 menus and messages Chinese  *
 *  Mamoru Yamanishi, Katajima Hajime    2.7.3 menus and messages Japanese *
 *                                                                         *
 *                             This Release by                             *
 * Herbert J. Bernstein, Bernstein + Sons, 5 Brewster Ln, Bellport, NY, USA*
 *                       yaya@bernstein-plus-sons.com                      *
 *               Copyright(C) Herbert J. Bernstein 1998-2008               *
 *                                                                         *
 *                READ THE FILE NOTICE FOR RASMOL LICENSES                 *
 *Please read the file NOTICE for important notices which apply to this    *
 *package and for license terms (GPL or RASLIC).                           *
 ***************************************************************************/
 
 /* langsel.c
 */

/***************************************************************************
 *                                                                         *
 * The Spanish translations in langsel.c were provided in late 2000 and    *
 * early 2001 by Fernando Gabriel Ranea <davinci@dinamica.com.ar>, who     *
 * created a version of RasMol with Spanish messages.  Those translations  *
 * were adapted by Herbert J. Bernstein to create a general multilingual   *
 * structure for RasMol.  In order to add another languages, define that   *
 * language in langsel.h, define a token for that language in tokens.h,    *
 * add code to recognize that token to tokens.c and command.c, and add     *
 * parallel lines with translations to the new language to langsel.c.      *
 * When entering menu items, you must identify a character in the item     *
 * to be underlined as a menu bar accelerator character.  The position of  *
 * that character (starting from 0 for the left-most character) should be  *
 * the last field of the line.  In addition, all menu items need to be     *
 * repeated for the Windows version with an ampersand ("&") before the     *
 * menu bar accelerator character.                                         *
 *                                                                         *
 * To date the following translations have been provided:                  *
 *                                                                         *
 * Spanish  Fernando Gabriel Ranea <davinci@dinamica.com.ar>               *
 *          January 2001                                                   *
 * French   Jean-Pierre Demailly <Jean-Pierre.Demailly@ujf-grenoble.fr>    *
 *          February 2001                                                  *
 * Italian  Giuseppe Martini <martini@iigb.na.cnr.it> and                  *
 *          Giovanni Paolella <paolella@dbbm.unina.it>                     *
 *          with contributions by: A. Davassi, M. Masullo, C. Liotto,      *
 *          G. Paolella, G. Martini of the joint bioinformatics            *
 *          groups of DBBM-UNINA and IIGB-CNR in Naples, Italy.            *
 *          March 2001                                                     *
 * Russian  Gregory A. Pozhvanov <pozhvanov@gmail.com>                     *    
 *          February 2006                                                  *
 ***************************************************************************/

#include <stdio.h>
#include <string.h>

#define LANGSEL
#include "rasmol.h"
#include "graphics.h"
#include "langsel.h"
#include "command.h"
#include "cmndline.h"


extern int Interactive;

static char * langnames[NUMLANGS] = {
  "English",
  "French",
  "German",
  "Italian",
  "Spanish",
  "Russian",
  "Chinese",
  "Japanese",
  "Bulgarian"
};


#ifdef MSWIN
langfont langfonts[NUMLANGS] = {
  { "RASMOL_ENGLISH_MENU_FONT", 
    ANSI_CHARSET,
    "ANSI_CHARSET",
    English },
  { "RASMOL_FRENCH_MENU_FONT", 
    ANSI_CHARSET,
    "ANSI_CHARSET", 
    French },
  { "RASMOL_GERMAN_MENU_FONT", 
    ANSI_CHARSET,
    "ANSI_CHARSET", 
    German },
  { "RASMOL_ITALIAN_MENU_FONT", 
    ANSI_CHARSET,
    "ANSI_CHARSET", 
    Italian },
  { "RASMOL_SPANISH_MENU_FONT", 
    ANSI_CHARSET,
    "ANSI_CHARSET", 
    Spanish },
  { "RASMOL_RUSSIAN_MENU_FONT", 
    RUSSIAN_CHARSET,
    "RUSSIAN_CHARSET", 
    Russian },
  { "RASMOL_CHINESE_MENU_FONT", 
    GB2312_CHARSET,
    "GB2312_CHARSET", 
    Chinese },
  { "RASMOL_JAPANESE_MENU_FONT", 
    SHIFTJIS_CHARSET,
    "SHIFTJIS_CHARSET", 
    Japanese },
  { "RASMOL_BULGARIAN_MENU_FONT", 
    RUSSIAN_CHARSET,
    "RUSSIAN_CHARSET", 
    Bulgarian }
};
#else
#ifdef APPLEMAC
langfont langfonts[NUMLANGS] = {
  { "RASMOL_ENGLISH_MENU_FONT", 
    "Monaco", 
    English },
  { "RASMOL_FRENCH_MENU_FONT", 
    "Monaco", 
    French },
  { "RASMOL_GERMAN_MENU_FONT", 
    "Monaco", 
    German },
  { "RASMOL_ITALIAN_MENU_FONT", 
    "Monaco", 
    Italian },
  { "RASMOL_SPANISH_MENU_FONT", 
    "Monaco", 
    Spanish },
  { "RASMOL_RUSSIAN_MENU_FONT", 
    "ER Kurier Macintosh", 
    Russian },
  { "RASMOL_CHINESE_MENU_FONT", 
    "Beijing", 
    Chinese },
  { "RASMOL_JAPANESE_MENU_FONT", 
    "Osaka", 
    Japanese },
  { "RASMOL_BULGARIAN_MENU_FONT", 
    "ER Kurier Macintosh", 
    Bulgarian }
};
#else
langfont langfonts[NUMLANGS] = {
  { "RASMOL_ENGLISH_MENU_FONT", 
    "-*-helvetica-bold-o-normal-*-14-*-iso8859-1" ":"
    "-*-serf-bold-o-normal-*-14-*-iso8859-1" ":"
    "-*-*-bold-o-normal-*-14-*-iso8859-1" ":", 
    English },
  { "RASMOL_FRENCH_MENU_FONT", 
    "-*-helvetica-bold-o-normal-*-14-*-iso8859-1" ":"
    "-*-serf-bold-o-normal-*-14-*-iso8859-1"  ":"
    "-*-*-bold-o-normal-*-14-*-iso8859-1" ":", 
    French },
  { "RASMOL_GERMAN_MENU_FONT", 
    "-*-helvetica-bold-o-normal-*-14-*-iso8859-1" ":"
    "-*-serf-bold-o-normal-*-14-*-iso8859-1" ":"
    "-*-*-bold-o-normal-*-14-*-iso8859-1" ":", 
    German },
  { "RASMOL_ITALIAN_MENU_FONT", 
    "-*-helvetica-bold-o-normal-*-14-*-iso8859-1" ":"
    "-*-serf-bold-o-normal-*-14-*-iso8859-1" ":"
    "-*-*-bold-o-normal-*-14-*-iso8859-1" ":", 
    Italian },
  { "RASMOL_SPANISH_MENU_FONT", 
    "-*-helvetica-bold-o-normal-*-14-*-iso8859-1" ":"
    "-*-serf-bold-o-normal-*-14-*-iso8859-1" ":"
    "-*-*-bold-o-normal-*-14-*-iso8859-1" ":", 
    Spanish },
  { "RASMOL_RUSSIAN_MENU_FONT", 
    "-*-helvetica-bold-o-normal-*-14-*1251" ":"
    "-*-serf-bold-o-normal-*-14-*-*1251" ":"
    "-*-*-bold-o-normal-*-14-*-*1251" ":", 
    Russian },
  { "RASMOL_CHINESE_MENU_FONT", 
    "*-16-*-gb2312.1980-0" ":", 
    Chinese },
  { "RASMOL_JAPANESE_MENU_FONT", 
    "*-r-*-14-*-jisx0208.1983-0" ":", 
    Japanese },
  { "RASMOL_BULGARIAN_MENU_FONT", 
    "-*-helvetica-bold-o-normal-*-14-*1251" ":"
    "-*-serf-bold-o-normal-*-14-*-*1251" ":"
    "-*-*-bold-o-normal-*-14-*-*1251" ":", 
    Bulgarian }
};
#endif
#endif
	

static langstr langstrs[] = {
