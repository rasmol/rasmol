"COMPILING" LANGSEL

1. COMPILING
2. EDITING
2.1 ENCODING LIST

1. COMPILING

TO "COMPILE" THE langsel.c FILE:

	Execute the genlangsel script by typing:
		./genlangsel
	
	Don't forget to chmod +x genlangsel if it does not have execute permissions.
	For more info on genlangsel type:
		./genlangsel --help

2. EDITING

	Edit the appropriate language file in its .utf.c file.

2.1 ENCODING LIST

	Below is a list of all of the files included in this folder and what
	encodings they are using.

	The .utf.c files are all UTF8.

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
	langsel.Japanese.mac.c		CP932
	langsel.Russian.c			CP1251
	langsel.Russian.mac.c
	langsel.Spanish.c			ISO-8859-1
	langsel.Spanish.mac.c
