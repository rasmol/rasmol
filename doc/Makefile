CC = cc
CFLAGS = -O2

prepdoc:	prepdoc.c
		$(CC) $(CFLAGS) -o prepdoc prepdoc.c

rasmol.txt:	prepdoc rasmol.doc
		rm -f rasmol.txt
		prepdoc -text rasmol.doc > rasmol.txt
		gzip --best < rasmol.txt > rasmol.txt.gz

rasmol.html:	prepdoc rasmol.doc
		rm -f rasmol.html
		prepdoc -html rasmol.doc > rasmol.html
		gzip --best < rasmol.html > rasmol.html.gz

rasmol.hlp:	prepdoc rasmol.doc
		rm -f rasmol.hlp
		prepdoc -help rasmol.doc > rasmol.hlp
		gzip --best < rasmol.hlp > rasmol.hlp.gz

rasmol.tex:	prepdoc rasmol.doc
		rm -f rasmol.tex
		prepdoc -latex rasmol.doc > rasmol.tex
		gzip --best < rasmol.tex > rasmol.tex.gz

raswin.rtf:	prepdoc rasmol.doc
		rm -f raswin.rtf
		prepdoc -rtf rasmol.doc > raswin.rtf
		gzip --best < raswin.rtf > raswin.rtf.gz

rasmol.man:	prepdoc rasmol.doc
		rm -f rasmol.man
		prepdoc -troff rasmol.doc > rasmol.man
		cp rasmol.man rasmol.1
		gzip --best < rasmol.1 > rasmol.1.gz

rasmol.vms:	prepdoc rasmol.doc
		rm -f rasmol.vms
		prepdoc -vms rasmol.doc > rasmol.vms
		gzip --best < rasmol.vms > rasmol.vms.gz

all:		rasmol.txt rasmol.hlp rasmol.html raswin.rtf rasmol.vms rasmol.tex rasmol.man
