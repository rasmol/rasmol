"COMPILING" LANGSEL

1. COMPILING
2. EDITING
2.1 ENCODING LIST

1. COMPILING

languages/ - herein lie the files that make up langsel.c
They are separated for the ease of maintenance, each file has its own text
encoding.

TO "COMPILE" THE langsel.c FILE:

(Unix)
On any Unix machine (linux/unix/mac os x)
From a terminal window cd to the languages/ directory and type

./genlangsel_all

to execute all the following scripts

./genlangsel_unix

to compile langsel_unix.c for unix systems with EUC-CN, EUC-JP and CP1251 fonts.

./genlangsel_mswin

to compile langsel_mswin.c for MS Windows systems with EUC-CN, SJIS and CP1251 fonts.

./genlangsel_mac

to compile langsel_mac.c for mac os classic (if using X11 emulation, use
langsel_unix.c)

or

./genlangsel_master

to generate a utf-8 version where all character sets will be visible (the
"master" file)


Keep in mind it may be necessary to give executable permissions to these scripts
if they don't already have them! If the scripts do not run, try:

chmod +x filename

where filename is the name of the script, i.e.:

chmod +x genlangsel


2. EDITING

Each one of this files is in a separate encoding, please be kind and keep the
encodings consistent by opening the files in their appropriate encodings. You
should work with the UTF-8 files and convert them with an encoding utility,
such as "iconv" for unix. Type "iconv --help" at a terminal window for more
details.

2.1 ENCODING LIST

Below is a list of all of the files included in this folder and what encodings
they are using.

The .utf.c files are all UTF8.
The .utf16.c files are all UTF16 (or UCS2).

langsel.Bulgarian.c			CP1251
langsel.Bulgarian.mac.c		
langsel.Chinese.c			GB 18030 (EUC-CN)
langsel.Chinese.mac.c
langsel.English.c			ISO-8859-1
langsel.English.mac.c
langsel.French.c			ISO-8859-1
langsel.French.mac.c
langsel.Italian.c			ISO-8859-1
langsel.Italian.mac.c
langsel.Japanese.c			shift_jis
langsel.Japanese.EUC.c		EUC-JP
langsel.Japanese.mac.c		japanese (mac)
langsel.Russian.c			CP1251
langsel.Russian.mac.c
langsel.Spanish.c			ISO-8859-1
langsel.Spanish.mac.c
