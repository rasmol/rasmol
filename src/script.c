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
/* script.c
 $Log$
 Revision 1.8  2008/03/22 18:42:55  yaya
 Post release cleanup and credit to Ikonen in file headers. -- HJB

 Revision 1.7  2008/03/17 03:01:31  yaya
 Update to agree with 2.7.4.2 release and T. Ikonen GTK mods -- HJB

 Revision 1.6  2008/03/17 01:32:41  yaya
 Add gtk mods by tpikonen, and intergate with 2.7.4.2 mods -- HJB

 Revision 1.6  2008/03/16 22:25:22  yaya
 Align comments with production version; Update rasmol_install and
 rasmol_run shell scripts for Japanese and Chinese; Align logic for
 positioning and sizing initial window with windows version -- HJB

 Revision 1.5  2008/01/30 03:15:55  yaya
 More post 2.7.4.1 release cleanup -- HJB

 Revision 1.5  2008/01/29 04:12:11  yaya
 Post release cleanup of problems discovered. -- HJB

 Revision 1.4  2008/01/29 04:35:26  yaya
 Postrelease update to fix problems discovered -- HJB

 Revision 1.3  2008/01/28 03:29:38  yaya
 Update CVS to RasMol_2.7.4.1 -- HJB

 Revision 1.4  2007/11/19 03:28:40  yaya
 Update to credits for 2.7.4 in manual and headers
 Mask code added -- HJB

 Revision 1.3  2007/11/18 03:22:57  yaya
 Update map scripting to keep track of selections for map generate
 -- HJB

 Revision 1.1.1.1  2007/03/01 01:16:33  todorovg
 Chinese working versio from rasmol_ru initial import

 Revision 1.3  2006/11/01 03:23:51  yaya
 Update NSIS windows installer for more script types and to fix
 misplaced script instructions for data files; add document and
 script icons directly in raswin.exe; add credit line to
 G. A. Pozhvanov in comments for Russian translations. -- HJB

 Revision 1.2  2006/09/17 10:53:56  yaya
 Clean up headers and start on code for X11 -- HJB

 Revision 1.1.1.1  2006/09/16 18:46:00  yaya
 Start of RasMol Russian Translation Project based on translations
 by Gregory A. Pozhvanov of Saint Petersburg State University -- HJB

 Revision 1.2  2006/06/19 22:06:41  todorovg
 Rasmol 2.7.3.1

 Revision 1.1.1.1  2006/06/19 22:05:14  todorovg
 Initial Rasmol 2.7.3 Import

 Revision 1.1  2004/05/07 19:46:16  yaya
 Initial revision

 Revision 1.3  2004/02/15 00:24:00  yaya
 *** empty log message ***

 Revision 1.2  2003/12/13 19:26:11  yaya
 *** empty log message ***

 Revision 1.1  2003/12/12 21:10:38  yaya
 Initial revision

 Revision 1.1  2001/01/31 02:13:45  yaya
 Initial revision

 Revision 1.5  2000/08/27 00:54:48  yaya
 create rotation bond database

 Revision 1.4  2000/08/26 18:12:44  yaya
 Updates to header comments in all files

 Revision 1.3  2000/08/21 21:07:48  yaya
 semi-final ucb mods

 Revision 1.2  2000/08/09 01:18:16  yaya
 Rough cut with ucb

 */
#include "rasmol.h"

#ifdef IBMPC
#include <windows.h>
#include <malloc.h>
#endif
#ifdef APPLEMAC
#include <Types.h>
#include <Errors.h>
#ifdef __CONDITIONALMACROS__
#include <Printing.h>
#else
#include <PrintTraps.h>
#endif
#endif
#ifndef sun386
#include <stdlib.h>
#endif
 

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define SCRIPTS
#include "script.h"
#include "molecule.h"
#include "command.h"
#include "cmndline.h"
#include "abstree.h"
#include "transfor.h"
#include "render.h"
#include "repres.h"
#include "graphics.h"
#include "pixutils.h"
#include "vector.h"
#include "wbrotate.h"
#include "tokens.h"
#include "maps.h"

#ifdef INVERT
#define InvertY(y) (y)
#else
#define InvertY(y) (-(y))
#endif

#ifdef INVERT
#define RestoreY(y) (-(y))
#else
#define RestoreY(y) (y)
#endif

#define Round(x)       ((int)rint(x))

/* Macros for commonly used loops */
#define ForEachAtom  for(chain=Database->clist;chain;chain=chain->cnext) \
                     for(group=chain->glist;group;group=group->gnext)    \
                     for(aptr=group->alist;aptr;aptr=aptr->anext)
#define ForEachBond  for(bptr=Database->blist;bptr;bptr=bptr->bnext)
#define ForEachBack  for(chain=Database->clist;chain;chain=chain->cnext) \
                     for(bptr=chain->blist;bptr;bptr=bptr->bnext)


/* Special thanks to Profs Jane and David Richardson
 * for the following Kinemage colour lookup table */

#define MAXMAGECOL 20
static struct {
        int r, g, b;
        char *name;
        } KinemageCol[MAXMAGECOL] = {
    { 255,   0,   0, "red"        },  /*  1 */
    {  23, 255,   0, "green"      },  /*  2 */
    {  62,  62, 255, "blue"       },  /*  3 */
    {   0, 242, 226, "cyan"       },  /*  4 */
    { 255, 246,   0, "yellow"     },  /*  5 */
    { 255,   0, 234, "magenta"    },  /*  6 */
    { 255, 255, 255, "white"      },  /*  7 */
    { 255, 101, 117, "pink"       },  /*  8 */
    { 255,  93,   0, "orange"     },  /*  9 */
    { 140,  54, 255, "purple"     },  /* 10 */
    {  58, 144, 255, "skyblue"    },  /* 11 */
    { 175, 117,  89, "brown"      },  /* 12 */
    { 125, 125, 125, "gray"       },  /* 13 */
    { 255, 156,   0, "gold"       },  /* 15 */
    { 246, 246, 117, "yellowtint" },  /* 16 */
    {   0, 250, 109, "seagreen"   },  /* 17 */
    { 255, 171, 187, "pinktint"   },  /* 18 */
    { 175, 214, 255, "bluetint"   },  /* 19 */
    { 152, 255, 179, "greentint"  },  /* 20 */
    { 255,   0, 101, "hotpink"    }   /* 21 */
        };


#define DatWirFlag  (Long)0x10000
#define DatDasFlag  (Long)0x20000
#define DatCylFlag  (Long)0x40000

typedef struct {
        Long datum;
        Long count;
    } FreqEntry;

#define FREQSIZE  8
static FreqEntry Freq[FREQSIZE];

static RAtom __far *MagePrev;
static char *MageCol;
static FILE *OutFile;
static int SelectAll;

static int vrml_mirror;
static int vrml_rotate;



/*=======================*/
/*  Function Prototypes  */
/*=======================*/

static void IncFreqTable( Long );
static Long GetBondDatum( Bond __far* );
static Long GetHBondDatum( HBond __far* );
static int FetchBondInfo( RAtom __far*, RAtom __far* );

static void WriteMolScriptAtomSel( Chain __far*, Group __far*, RAtom __far* );

static void WriteScriptDatum( char*, Long );
static void WriteScriptSelectBond( RAtom __far*, RAtom __far* );
static void WriteScriptHBonds( char*, HBond __far* );

static int CheckKinemageChain( RAtom __far*, RAtom __far*, Chain __far* );
static void OutputKinemageVector( RAtom __far*, RAtom __far*, int );
static void WriteKinemageBonds( Chain __far* );
static void WriteKinemageSpheres( Chain __far* );
static void WriteKinemageLabels( Chain __far* );



static void FatalScriptError( char *ptr )
{
    InvalidateCmndLine();
    WriteString("Script Error: Unable to create file `");
    WriteString( ptr );  WriteString("'!\n");
}


static void ResetFreqTable( void )
{
    register int i;

    for( i=0; i<FREQSIZE; i++ )
        Freq[i].count = 0;
}


static void IncFreqTable( Long datum )
{
    register Long count;
    register int i;

    for( i=0; i<FREQSIZE; i++ )
        if( !Freq[i].count )
        {   Freq[i].datum = datum;
            Freq[i].count = 1;
            return;
        } else if( Freq[i].datum == datum )
        {   count = Freq[i].count+1;
            while( i && (Freq[i-1].count<=count) )
            {   Freq[i] = Freq[i-1];  
                i--;
            }
            Freq[i].datum = datum;
            Freq[i].count = count;
            return;
        }

    /* Replace Singletons! */
    if( Freq[FREQSIZE-1].count == 1 )
        Freq[FREQSIZE-1].datum = datum;
}


static Long GetBondDatum( Bond __far *bptr )
{
    if( bptr->flag & CylinderFlag )
    {   return( DatCylFlag | bptr->radius );
    } else if( bptr->flag & WireFlag )
    {   return DatWirFlag;
    } else if( bptr->flag & DashFlag )
    {   return DatDasFlag;
    } else return (Long)0;
}

static Long GetHBondDatum( HBond __far *bptr )
{
    if( bptr->flag & CylinderFlag )
    {   return( DatCylFlag | bptr->radius );
    } else if( bptr->flag & WireFlag )
    {   return DatWirFlag;
    } else return (Long)0;
}


/* Used by FetchBondInfo! */
static Chain __far *schn;
static Chain __far *dchn;
static Group __far *sgrp;
static Group __far *dgrp;

static int FetchBondInfo( RAtom __far *src, RAtom __far *dst )
{
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *aptr;

    /* Determine Chain and Groups */
    schn = dchn = (Chain __far*)0;
    sgrp = dgrp = (Group __far*)0;

    for( chain=Database->clist; chain; chain=chain->cnext )
    {   for( group=chain->glist; group; group=group->gnext )
        {   for( aptr=group->alist; aptr; aptr=aptr->anext )
            {   if( aptr == src )
                {   schn = chain;
                    sgrp = group;
                }
                if( aptr == dst ) 
                {   dchn = chain;
                    dgrp = group;
                }
            }
            if( sgrp && dgrp ) 
                return True;
        }
    }
    return False;
}



/*==============================*/
/*  Molscript Input Generation  */
/*==============================*/

#ifdef UNUSED
static void WriteMolScriptColour( int r, int g, int b )
{
    fprintf(OutFile," rgb %#g %#g %#g",r/255.0,g/255.0,b/255.0);
}
#endif


static void WriteMolScriptAtomSel( Chain __far *chain,
                                   Group __far *group,
                                   RAtom __far *aptr )
{
    register char *ptr;
    register int i;

    fputs("require atom ",OutFile);
    ptr = ElemDesc[aptr->refno];
    for( i=0; ptr[i]&& i<4; i++ )
        if( ptr[i]=='*' )
        {   fputc('\'',OutFile);
        } else if( ptr[i]!=' ' )
            fputc(ptr[i],OutFile);

    fputs(" and in residue ",OutFile);
    if( chain->ident!=' ' && !isdigit(chain->ident) )
        fputc(chain->ident,OutFile);
    fprintf(OutFile,"%d",group->serno);
}


static void WriteMolScriptAtoms( void )
{

    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *aptr;
    register int count,vdw;
    register long total;

#ifdef UNUSED
    register ShadeDesc *shade;

    ForEachAtom
        if( aptr->flag &SphereFlag )
        {   fputs("set atomcolour ",OutFile);
            WriteMolScriptAtomSel(chain,group,aptr);
            shade = Shade + Colour2Shade(aptr->col);
            WriteMolScriptColour(shade->r,shade->g,shade->b);
            fputs(";\n",OutFile);

            fputs("set atomradius ",OutFile);
            WriteMolScriptAtomSel(chain,group,aptr);
            fprintf(OutFile," %#g",aptr->radius/250.0);
            fputs(";\n",OutFile);
        }
#endif

    vdw = True;
    total = 0;
    count = 0;
    ForEachAtom
        if( aptr->flag & SphereFlag )
        {   if( vdw ) vdw = IsVDWRadius(aptr);
            total += aptr->radius;
            count++;
        }

    if( !count )
        return;

    if( !vdw )
    {   /* Average sphere radius! */
        fprintf(OutFile,"set atomradius atom * %#g;\n",
                (double)total/(250.0*count));
    }

    ForEachAtom
        if( aptr->flag & SphereFlag )
        {   fputs("cpk ",OutFile);
            WriteMolScriptAtomSel(chain,group,aptr);
            fputs(";\n",OutFile);
        }
}


static void WriteMolScriptBonds( void )
{
    register Bond __far *bptr;

    ForEachBond
    {    if( bptr->flag & WireFlag )
         {   FetchBondInfo(bptr->srcatom,bptr->dstatom);
             fputs("bonds ",OutFile);
             WriteMolScriptAtomSel(schn,sgrp,bptr->srcatom);
             fputs("\n      ",OutFile);
             WriteMolScriptAtomSel(dchn,dgrp,bptr->dstatom);
             fputs(";\n",OutFile);
         } else if( bptr->flag & CylinderFlag )
         {   FetchBondInfo(bptr->srcatom,bptr->dstatom);
             fputs("ball-and-stick ",OutFile);
             WriteMolScriptAtomSel(schn,sgrp,bptr->srcatom);
             fputs("\n               ",OutFile);
             WriteMolScriptAtomSel(dchn,dgrp,bptr->dstatom);
             fputs(";\n",OutFile);
         }
    }
}


static void WriteMolScriptLabels( void )
{
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *aptr;
    register Label *label;
    register unsigned char *ptr;
    unsigned char buffer[80];

    ForEachAtom
    {   if( aptr->label )
        {   /* Atom Label */
            label = (Label*)aptr->label;
            FormatLabel(chain,group,aptr,label->label,buffer);

            fputs("label ",OutFile);
            WriteMolScriptAtomSel(chain,group,aptr);
            fputs(" \"",OutFile);
            for( ptr=buffer; *ptr; ptr++ )
                if( *ptr!='%' ) fputc(*ptr,OutFile);
            fputs("\";\n",OutFile);
        }
    }
}


static void MolScriptSegment( char *ptr, int src, int dst, int chain )
{   
    if( (chain!=' ') && !isdigit(chain) ) 
    {   fprintf(OutFile,"  %s from %c%d to %c%d;\n",ptr,chain,src,chain,dst);
    } else fprintf(OutFile,"  %s from %d to %d;\n",ptr,src,dst);
}


int WriteMolScriptFile( char *name )
{
    register Real temp;
    Real psi, phi, theta;
    register Chain __far *chain;
    register Group __far *group;
    register Group __far *next;
    register Group __far *prev;
    register int flag,len;
    register char *ptr;

    if( !Database )
        return(False);

    OutFile = fopen(name,"w");
    if( !OutFile )
    {   FatalScriptError(name);
        return(False);
    }
    fprintf(OutFile,"! File: %s\n",name);
    fprintf(OutFile,"! Creator: RasMol Version %s\n", VERSION);
    fputs("! Version: MolScript v1.3\n\n",OutFile);

    fputs("plot\n",OutFile);
    if( BackR || BackG || BackB )
    {   fputs("  background rgb ",OutFile);
        fprintf(OutFile,"%#g ",  BackR/255.0);
        fprintf(OutFile,"%#g ",  BackG/255.0);
        fprintf(OutFile,"%#g;\n",BackB/255.0);
    }
    temp = 0.004/Scale;
    fprintf(OutFile,"  window %g;\n",temp*Range);
    if( UseSlabPlane )
        fprintf(OutFile,"  slab %g;\n",SideLen/250.0);
    fputc('\n',OutFile);

    fprintf(OutFile,"  read mol \"%s\";\n",Info.filename);
    fputs("  transform atom *\n",OutFile);
    fputs("    by centre position atom *\n",OutFile);
    fputs("    by rotation x 180.0",OutFile);

    /*
    phi = Rad2Deg*asin(RotX[2]);
    if( (int)phi == 90 )
    {   theta = -Rad2Deg*atan2(RotY[0],RotY[1]);
        psi = 0;
    } else if( (int)phi == -90 )
    {   theta = Rad2Deg*atan2(RotY[0],RotY[1]);
        psi = 0;
    } else 
    {   theta = Rad2Deg*atan2(RotY[2],RotZ[2]);
        psi =  -Rad2Deg*atan2(RotX[1],RotX[0]);
    }
    */
    
    phi = psi = theta = 0.0;
    RMat2RV(&theta, &phi, &psi, RotX, RotY, RotZ);
    theta *= 180.;
    phi *= 180.;
    psi *= 180.;
    

    if( (int)theta ) fprintf(OutFile,"\n    by rotation x %#g",InvertY(-theta));
    if( (int)phi )   fprintf(OutFile,"\n    by rotation y %#g",phi);
    if( (int)psi )   fprintf(OutFile,"\n    by rotation z %#g",InvertY(psi));

    if( UseSlabPlane || (XOffset!=WRange) || (YOffset!=HRange) )
    {   fputs("\n    by translation ",OutFile);
        fprintf(OutFile,"%#g ",(XOffset-WRange)*temp);
        fprintf(OutFile,"%#g ",-(YOffset-HRange)*temp);
        if( UseSlabPlane )
        {   temp = (1.0-DialValue[DialSlab])/500.0;
            fprintf(OutFile,"%#g",SideLen*temp);
        } else fputs("0.0",OutFile);
    }
    fputs(";\n\n",OutFile);

    /* fputs("  trace amino-acids;\n",OutFile); */

    if( Database->clist )
    {   if( Info.helixcount < 0 )
            DetermineStructure( False );

        for( chain=Database->clist; chain; chain=chain->cnext )
        {   prev = (Group __far*)0;
            for( group=chain->glist; group && group->gnext; group=next )
            {   next = group->gnext;
                if( next->serno < group->serno )
                {   if( prev && prev!=group )
                        MolScriptSegment("coil",prev->serno,group->serno,
                                                chain->ident);
                    prev = (Group __far*)0;
                    continue;
                }
                flag = group->struc & next->struc;

                if( flag&HelixFlag )
                {   flag = HelixFlag;
                    ptr = "helix";
                } else if( flag&SheetFlag )
                {   flag = SheetFlag;
                    ptr = "strand";
                } else 
                {   if( flag&TurnFlag )
                    {   fputs("  turn residue ",OutFile);
                        if( chain->ident != ' ' )
                            fputc(chain->ident,OutFile);
                        fprintf(OutFile,"%d;\n",group->serno);
                    }
                    if( !prev ) prev = group;
                    continue;
                }

                len = 2;  /* Determine Structure Length */
                while( next->gnext && (next->gnext->struc&flag)
                           && (next->serno<=next->gnext->serno) )
                {   next = next->gnext;
                    len++;
                }

                if( len>2 )
                {   if( prev && prev!=group ) /* MolScript coil or turn? */
                       MolScriptSegment("coil",prev->serno,group->serno,
                                              chain->ident);
                    MolScriptSegment(ptr,group->serno,next->serno,
                                         chain->ident);
                    prev = next;
                } 
            }

            if( prev && prev!=group )  /* C-terminal coil/turn */
                MolScriptSegment("coil",prev->serno,group->serno,chain->ident);
        }
    }


    WriteMolScriptAtoms();
    WriteMolScriptBonds();
    WriteMolScriptLabels();

    fputs("end_plot\n",OutFile);
    fclose(OutFile);
#ifdef APPLEMAC
    SetFileInfo(name,'ttxt','TEXT',133);
#endif
    return True;
}

/*============================*/
/* Map Generation Scripts     */
/*============================*/


/* Load the vector MapAtmSelVec with the information to select
   the atoms used for the current map generation */

void WriteMapAtoms( MapAtmSelVec __far * MapGenSel )
{
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *aptr;
    register Long first=0,last=0;
    register int currad, newrad;
    register int init,selectall;
    MapAtmSel mas;
    
    init = False;
    selectall = True;
    mas.loserno= -1;
    mas.hiserno=-2;
    mas.radius=ProbeRadius;
    vector_add_element((GenericVec __far *)MapGenSel,(void __far *)&mas);
    currad = 0;
    
    ForEachAtom {
      if (aptr->flag&SelectFlag) {
        if (!init) {
          currad = aptr->radius;
          if (currad < 10 || currad == ElemVDWRadius( aptr->elemno )) currad = 0;
          init = True;
          first = last = aptr->serno;
        }
        newrad = aptr->radius;
        if (newrad < 10 || newrad == ElemVDWRadius( aptr->elemno )) newrad = 0;
        if (currad == newrad) {
          last = aptr->serno;
        } else {
          mas.loserno=first;
          mas.hiserno=last;
          mas.radius=currad;
          currad=newrad;
          first=last=aptr->serno;
          selectall = False;
        }
      } else {
        selectall = False;
      }	
    }
    if (init) {
      if (selectall) {
        mas.loserno = mas.hiserno = 0;
      } else {
      	mas.loserno = first;
      	mas.hiserno = last;
      }
      mas.radius = currad;
      vector_add_element((GenericVec __far *)MapGenSel,(void __far *)&mas);
    }
    return;
}



/*============================*/
/*  RasMol Script Generation  */
/*============================*/
  
static void WriteScriptAll( void )
{
    if( !SelectAll )
    {   fputs("select all\n",OutFile);
        SelectAll = True;
    }
}

static void WriteScriptColour( char *ptr, int col )
{
    register ShadeDesc *shade;
    
    if( col )
    {   shade = Shade + Colour2Shade(col);
        fprintf(OutFile,"colour %s [%d,%d,%d]\n",ptr,
                shade->r,shade->g,shade->b);
    } else fprintf(OutFile,"colour %s none\n",ptr);
}


static void WriteScriptBetween( int lo, int hi )
{
    if( lo != hi )
    {   fprintf(OutFile,"select (atomno>=%d) and (atomno<=%d)\n",lo,hi);
    } else fprintf(OutFile,"select atomno=%d\n",lo);
    SelectAll = False;
}


static void WriteScriptSelectBond( RAtom __far *src, RAtom __far *dst )
{
    fprintf(OutFile,"select (atomno=%ld) or (atomno==%ld)\n",
                    src->serno, dst->serno);
    SelectAll = False;
}


static void WriteScriptAtoms( void )
{
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *aptr;
    register Long first=0,last=0;
    register int same,init;
    register int cpk=0,cpknew=0,vdw=0;
    register int col=0,rad=0;
    register int prevflag,staron,sphereon;

    fputs("\n# Atoms\n",OutFile);

    same = True;
    init = False;

    ForEachAtom
        if( !init )
        {   first = last = aptr->serno;
            cpk = IsCPKColour( aptr );
	        cpknew = IsCpkNewColour( aptr );
            col = aptr->col;
            if (cpk || cpknew ) col = 0;
            init = True;
        } else if( (cpk && IsCPKColour(aptr)) || 
                   (cpknew && IsCpkNewColour(aptr)))
        {   last = aptr->serno;
            if( aptr->col != col )
                col = 0;
        } else if( aptr->col == col )
        {   last = aptr->serno;
            cpk = False;
            cpknew = False;
        } else if( aptr->col != col )
        {   WriteScriptBetween( first, last );
            if( !col )
            {   if (cpk) {
                   fputs("colour atoms cpk\n",OutFile);
                } else {
                   fputs("colour atoms cpknew\n",OutFile);
                }
            } else WriteScriptColour("atoms",col);
                
            first = last = aptr->serno;
            cpk = IsCPKColour( aptr );
            cpknew = IsCpkNewColour( aptr );
            col = aptr->col;
            if (cpk || cpknew ) col = 0;
            same = False;
        } else last = aptr->serno; 
        
    if( init )
    {   if( !same )
        {   WriteScriptBetween(first,last);
        } else WriteScriptAll();

        if( !col )
        {   if (cpk) {
              fputs("colour atoms cpk\n",OutFile);
            } else {
               fputs("colour atoms cpknew\n",OutFile);
            }
        } else WriteScriptColour("atoms",col);
    }

    
	    

    staron = False;
    sphereon = False;
    if( DrawAtoms || DrawStars )
    {   same = True;
        init = False;
        prevflag = 0;
        ForEachAtom
	    {
            if( !init )
            {   rad = (aptr->flag&(SphereFlag | StarFlag)) ? aptr->radius : 0;
                first = last = aptr->serno;
                vdw = IsVDWRadius( aptr );
                if (vdw) rad = -1;
                init = True;
                prevflag = aptr->flag&(SphereFlag | StarFlag);
            } else 
            { if( (prevflag == (aptr->flag&(SphereFlag | StarFlag))) &&
                ((vdw && IsVDWRadius(aptr)) ||
                (rad == (prevflag ? aptr->radius : 0))))
              { last = aptr->serno;
              } else
              { if( prevflag )
                { WriteScriptBetween(first,last);
                  if( rad == -1 )
                  { if( prevflag&SphereFlag ) 
                    { sphereon = True; 
                      fputs("spacefill on\n",OutFile);
                    }
                    if( prevflag&StarFlag ) 
		            { staron = True;
                      fputs("star on\n",OutFile);
                    }
                  } else 
                  { if( rad )
                    { if( prevflag&SphereFlag )
                      { sphereon = True; 
                        fprintf(OutFile,"spacefill %d\n",rad);
                      }
                      if( prevflag&StarFlag)
		              { staron = True;
                        fprintf(OutFile,"star %d\n",rad);
                      }
                    } else 
                    { if( sphereon )
                      { sphereon = False;
                        fputs("spacefill off\n",OutFile); 
                      }
                      if( staron )
		              { staron = False;
                        fputs("star off\n",OutFile);
                      }
                    }
                  }
	            }
                prevflag = aptr->flag&(SphereFlag | StarFlag);
                rad = prevflag? aptr->radius : 0;
                first = last = aptr->serno;
                vdw = IsVDWRadius( aptr );
                if( vdw ) rad = -1;
                same = False;
              }
            }
        }

        if( !same )
        {   WriteScriptBetween(first,last);
        } else WriteScriptAll();

        if( rad == -1 )
        {   if( prevflag&SphereFlag )
              fputs("spacefill on\n",OutFile);
            if( prevflag&StarFlag )
              fputs("star on\n",OutFile);
        } else if( rad )
        {   if( prevflag&SphereFlag )
              fprintf(OutFile,"spacefill %d\n",rad);
            if( prevflag&StarFlag )
              fprintf(OutFile,"star %d\n",rad);
        } else {
          if (sphereon) fputs("spacefill off\n",OutFile); 
          if (staron) fputs("star off\n",OutFile);
        }

        if( UseShadow )
        {   fputs("set shadow on\n",OutFile);
        } else fputs("set shadow off\n",OutFile);

    } else
    {   WriteScriptAll();
        fputs("spacefill off\n",OutFile);
    }
        
}


static void WriteScriptDatum( char *ptr, Long datum )
{
    if( datum & DatCylFlag )
    {   fprintf(OutFile,"%s %d\n",ptr,(int)(datum-DatCylFlag));
    } else if( datum & DatWirFlag )
    {   fprintf(OutFile,"%s on\n",ptr);
    } else if( datum & DatDasFlag )
    {   fprintf(OutFile,"%s dash\n",ptr);
    } else fprintf(OutFile,"%s off\n",ptr);
}


static void WriteScriptBonds( void )
{
    register Bond __far *bptr;
    register Long defdat;
    register Long datum;
    register int col;

    fputs("\n# Bonds\n",OutFile);

    ResetFreqTable();
    ForEachBond
        IncFreqTable(GetBondDatum(bptr));

    WriteScriptAll();
    defdat = Freq[0].datum;
    WriteScriptDatum("wireframe",defdat);

    if( Freq[1].count )
    {   ForEachBond
        {   datum = GetBondDatum(bptr);
            if( datum != defdat )
            {    WriteScriptSelectBond(bptr->srcatom,bptr->dstatom);
                 WriteScriptDatum("wireframe",datum);
            }
        }
    } else if( !defdat )
        return;

    ResetFreqTable();
    ForEachBond
        IncFreqTable(bptr->col);

    col = (int)Freq[0].datum;
    if( col )
    {   WriteScriptAll();
        WriteScriptColour("bonds",col);
    }

    if( Freq[1].count )
        ForEachBond
            if( bptr->col != col )
            {   WriteScriptSelectBond(bptr->srcatom,bptr->dstatom);
                WriteScriptColour("bonds",bptr->col);
            }
}


static void WriteScriptBackbone( void )
{
    register Chain __far *chain;
    register Bond __far *bptr;

    register Long defdat;
    register Long datum;
    register int col;

    fputs("\n# Backbone\n",OutFile);

    ResetFreqTable();
    ForEachBack
        IncFreqTable(GetBondDatum(bptr));

    WriteScriptAll();
    defdat = Freq[0].datum;
    WriteScriptDatum("backbone",defdat);

    if( Freq[1].count )
    {   ForEachBack
        {   datum = GetBondDatum(bptr);
            if( datum != defdat )
            {    WriteScriptSelectBond(bptr->srcatom,bptr->dstatom);
                 WriteScriptDatum("backbone",datum);
            }
        }
    } else if( !defdat )
        return;

    ResetFreqTable();
    ForEachBack
        IncFreqTable(bptr->col);

    col = (int)Freq[0].datum;
    if( col )
    {   WriteScriptAll();
        WriteScriptColour("backbone",col);
    }

    if( Freq[1].count )
        ForEachBack
            if( bptr->col != col )
            {   WriteScriptSelectBond(bptr->srcatom,bptr->dstatom);
                WriteScriptColour("backbone",bptr->col);
            }
}


static void WriteScriptRibbons( void )
{
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *aptr;

    fputs("\n# Ribbons\n",OutFile);

    if( DrawRibbon )
    {   if( Info.structsource == SourceCalc )
            fputs("structure\n",OutFile);
        fprintf(OutFile,"set strands %d\n",SplineCount);
        fprintf(OutFile,"set cartoon %s\n",DrawBetaArrows?"on":"off");
        fprintf(OutFile,"set cartoon %d\n",CartoonHeight);

        for( chain=Database->clist; chain; chain=chain->cnext )
            for( group=chain->glist; group; group=group->gnext )
            {    if( IsAmino(group->refno) )
                 {   aptr = FindGroupAtom(group,1);
                 } else aptr = FindGroupAtom(group,7);
                 if( !aptr ) continue;

                 fprintf(OutFile,"select atomno=%ld\n",aptr->serno);
                 SelectAll = False;

                 if( group->flag & RibbonFlag )
                 {   fprintf(OutFile,"ribbons %d\n",group->width);
                 } else if( group->flag & CartoonFlag )
                 {   fprintf(OutFile,"cartoon %d\n",group->width);
                 } else if( group->flag & StrandFlag )
                 {   fprintf(OutFile,"strands %d\n",group->width);
                 } else if( group->flag & DashStrandFlag )
                 {   fprintf(OutFile,"strands dash %d\n",group->width);
                 } else if( group->flag & TraceFlag )
                 {   fprintf(OutFile,"trace %d\n",group->width);
                 } else fputs("ribbons off\n",OutFile);

                 if( group->col1 != group->col2 )
                 {   if( group->col1 )
                         WriteScriptColour("ribbon1",group->col1);
                     if( group->col2 )
                         WriteScriptColour("ribbon2",group->col2);
                 } else if( group->col1 )
                     WriteScriptColour("ribbons",group->col1);
            }
    } else
    {   WriteScriptAll();
        fputs("ribbons off\n",OutFile);
    }
}


static void WriteScriptHBonds( char *obj, HBond __far *list )
{
    register HBond __far *ptr;
    register Long defdat;
    register Long datum;
    register int col;

    ResetFreqTable();
    for( ptr=list; ptr; ptr=ptr->hnext )
        IncFreqTable(GetHBondDatum(ptr));

    WriteScriptAll();
    defdat = Freq[0].datum;
    WriteScriptDatum(obj,defdat);

    if( Freq[1].count )
    {   for( ptr=list; ptr; ptr=ptr->hnext )
        {   datum = GetHBondDatum(ptr);
            if( datum != defdat )
            {    WriteScriptSelectBond(ptr->src,ptr->dst);
                 WriteScriptDatum(obj,datum);
            }
        }
    } else if( !defdat )
        return;

    ResetFreqTable();
    for( ptr=list; ptr; ptr=ptr->hnext )
        IncFreqTable(ptr->col);

    col = (int)Freq[0].datum;
    if( col )
    {   WriteScriptAll();
        WriteScriptColour(obj,col);
    }

    if( Freq[1].count )
        for( ptr=list; ptr; ptr=ptr->hnext )
            if( ptr->col != col )
            {   WriteScriptSelectBond(ptr->src,ptr->dst);
                WriteScriptColour(obj,ptr->col);
            }
}


static void WriteScriptLabels( void )
{
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *aptr;
    register Long first = 0,last = 0;
    register Label *label;

    fputs("\n# Labels\n",OutFile);
    WriteScriptAll();
    fputs("labels off\n",OutFile);
    if( !LabelList ) return;

    if( UseLabelCol )
    {   fprintf(OutFile,"colour labels [%d,%d,%d]\n",LabR,LabG,LabB);
    } else fputs("colour labels none\n",OutFile);

    if ( FontPS )
    { fprintf(OutFile,"set fontsize %d PS\n",FontSize);
    } else fprintf(OutFile,"set fontsize %d\n",FontSize);

    if ( FontStroke )
      fprintf(OutFile,"set fontstroke %d\n",FontStroke);

    label = (Label*)0;
    ForEachAtom
        if( aptr->label != label )
        {   if( label )
            {   WriteScriptBetween(first,last);
                fprintf(OutFile,"label \"%s\"\n",label->label);
            }
            label = (Label*)aptr->label;
            first = last = aptr->serno;
        } else last = aptr->serno;

    if( label )
    {   WriteScriptBetween(first,last);
        fprintf(OutFile,"label \"%s\"",label->label);
    }
}


static void WriteScriptMonitors( void )
{
    register Monitor *ptr;
    register int col;

    fputs("\n# Monitors\n",OutFile);
    if( !MonitList )
    {   fputs("monitors off\n",OutFile);
        return;
    }

    fprintf(OutFile,"set monitors %s\n",DrawMonitDistance?"on":"off");

    ResetFreqTable();
    for( ptr=MonitList; ptr; ptr=ptr->next )
    {   fprintf(OutFile,"monitor %ld %ld\n",ptr->src->serno,ptr->dst->serno);
        IncFreqTable(ptr->col);
    }

    col = (int)Freq[0].datum;
    if( col )
    {   WriteScriptAll();
        WriteScriptColour("monitors",col);
    }

    if( Freq[1].count )
        for( ptr=MonitList; ptr; ptr=ptr->next )
            if( ptr->col != col )
            {   WriteScriptSelectBond(ptr->src,ptr->dst);
                WriteScriptColour("monitor",ptr->col);
            }
}

static void WriteScriptMaps()
{   int j;
    MapInfo *mapinfo;
    MapAtmSel *mas;
    
    if (MapInfoPtr) {
      for (j=0; j < MapInfoPtr->size; j++) {
        vector_get_elementptr((GenericVec __far *)MapInfoPtr,(void __far * __far *)&mapinfo,j );
        if (mapinfo->MapPtr) {
          if (!MapPointRad)  {
            if (mapinfo->flag&MapPointFlag)fprintf(OutFile,"map new dots\n");          	
          } else  {
            if (mapinfo->flag&MapPointFlag)fprintf(OutFile,"map new dots %-.2lf\n",
              ((double)mapinfo->MapPointRad/250.) );
          }
          if (mapinfo->flag&MapMeshFlag){
            if ((mapinfo->flag&MapMeshDashFlag) != MapMeshDashFlag) {
              fprintf(OutFile,"map new dash \n");
            } else {
              if (!MapMeshRad) {
                fprintf(OutFile,"map new mesh\n" );
              } else {
                fprintf(OutFile,"map new mesh %-.2lf\n",((double)mapinfo->MapMeshRad/250.) );
              }
            }
          }
          if (mapinfo->flag&MapSurfFlag)fprintf(OutFile,"map new surface\n");
          if (mapinfo->flag&MapColourPot) fprintf(OutFile,"map new colour potential\n" );
          else fprintf(OutFile,"map new colour [%d,%d,%d]\n",
            mapinfo->MapRGBCol[0],mapinfo->MapRGBCol[1],mapinfo->MapRGBCol[2]);
          if (mapinfo->flag&MapMeanFlag) fprintf(OutFile,"map new level MEAN %g\n",mapinfo->MapLevel );
          else fprintf(OutFile,"map new level %g\n",mapinfo->MapLevel );
          if (fabs(((double)mapinfo->MapSpacing/250.)*.6667-mapinfo->MapSpread) < .01) {
            fprintf(OutFile,"map new resolution %-.2lf\n",((double)mapinfo->MapSpacing/250.) );          	
          } else  {
            fprintf(OutFile,"map new spacing %-.2lf\n",((double)mapinfo->MapSpacing/250.) );
            fprintf(OutFile,"map new spread %-.2lf\n",mapinfo->MapSpread);	
          }
          if (mapinfo->flag&MapScaleFlag) {
            fprintf(OutFile,"map new scale Z\n" );
          } else {
            fprintf(OutFile,"map new scale none\n" );          	          	
          }
          if (mapinfo->MapFile) {
            fprintf(OutFile,"map new load \"%s\"\n",mapinfo->MapFile);
          } else {
            if (mapinfo->MapGenSel) {
              int selectall;
              int selcount;
              selectall=True;
              selcount = 0;
              for (j=0;j< mapinfo->MapGenSel->size; j++) {
              	vector_get_elementptr((GenericVec __far *)mapinfo->MapGenSel,
              	  (void __far **)&mas,j);
              	if (mas->loserno==-1 && mas->hiserno==-2) {
              	  fprintf(OutFile,"set radius %#lg\n",((double)ProbeRadius)/250.);
              	} else {
              	  if (mas->loserno==0 && mas->hiserno==0) {
              	    fprintf(OutFile,"select all\n");
              	  } else {
              	    selectall=False;
              	    selcount++;
              	    if (mas->loserno==mas->hiserno) {
              	      fprintf(OutFile,"select atomno=%ld\n",mas->loserno);
              	    } else {
              	      fprintf(OutFile,"select atomno>=%ld and atomno>=%ld \n",
              	        mas->loserno,mas->hiserno);
              	    }
              	  }
              	  if (mas->radius) {
              	    fprintf(OutFile,"spacefill %#lg\n",((double)mas->radius)/250.);
              	  } else {
              	  	fprintf(OutFile,"spacefill true\n" );
              	  }
              		
              	}
              }
              if (selcount||selectall) fprintf(OutFile,"spacefill off\n" );
              if (selcount>1) {
              	fprintf(OutFile,"select none\n" );
                for (j=0;j< mapinfo->MapGenSel->size; j++) {
              	  vector_get_elementptr((GenericVec __far *)mapinfo->MapGenSel,
              	    (void __far **)&mas,j);
              	  if (mas->loserno>0 && mas->hiserno>0) {
              	    if (mas->loserno==mas->hiserno) {
              	      fprintf(OutFile,"select selected or atomno=%ld\n",mas->loserno);
              	    } else {
              	      fprintf(OutFile,"select selected or (atomno>=%ld and atomno>=%ld) \n",
              	        mas->loserno,mas->hiserno);
              	    }              	  	
              	  }
                }
              }
            }
          	fprintf(OutFile,"map new generate\n");
          }
        }
      }
    }
}


int WriteScriptFile( char *name )
{
    Real theta,phi,psi;
    register char *ptr;
    register int temp;

    OutFile = fopen(name,"w");
    if( !OutFile )
    {   FatalScriptError(name);
        return(False);
    }

    fprintf(OutFile,"#!rasmol -script\n# File: %s\n",name);
    fprintf(OutFile,"# Creator: RasMol Version %s\n\n", VERSION);
    fputs("zap\n",OutFile);

    if( !Database )
    {   /* No Molecule! */
        fclose(OutFile);
#ifdef APPLEMAC
        SetFileInfo(name,'RSML','RSML',133);
#endif
        return True;
    }

    /* Molecule File Name */
    switch( DataFileFormat )
    {   default:
        case(FormatPDB):      ptr = "pdb";      break;
        case(FormatAlchemy):  ptr = "alchemy";  break;
        case(FormatCharmm):   ptr = "charmm";   break;
        case(FormatMol2):     ptr = "mol2";     break;
        case(FormatMDL):      ptr = "mdl";      break;
        case(FormatXYZ):      ptr = "xyz";      break;
        case(FormatCIF):      ptr = "cif";      break;
    }
    if ( !strcmp(Info.filename,"inline") ) 
    { fprintf(OutFile,
       "\n#*** WARNING Data loaded inline not included in this script\n");
        fprintf(OutFile,"load %s %s\n",ptr,Info.filename);
    } else {
      fprintf(OutFile,"load %s \"%s\"\n",ptr,Info.filename);
    }

    /* Maps */
    WriteScriptMaps();


    /* Colour Details */
    fprintf(OutFile,"background [%d,%d,%d]\n",BackR,BackG,BackB);
    fprintf(OutFile,"set ambient %d\n", (int)(100*Ambient) );
    fputs("set specular ",OutFile);
    if( FakeSpecular )
    {   fprintf(OutFile,"on\nset specpower %d\n",SpecPower);
    } else fputs("off\n",OutFile);
    if( ShadePower )
    {  fprintf(OutFile,"set shadepower %d\n",(int)(((ShadePower+20)*100)/40));
    }
    putc('\n',OutFile);

    /* Transformation */
    fputs("reset\n",OutFile);
    if( UseSlabPlane )
    {   temp = (int)(50.0*DialValue[DialSlab]);
        if( temp )
        {   fprintf(OutFile,"slab %d\n",temp+50);
        } else fputs("slab on\n",OutFile);

        fputs("set slabmode ",OutFile);
        switch( SlabMode )
        {   default:            
            case(SlabClose):    ptr = "solid";    break;
            case(SlabReject):   ptr = "reject";   break;
            case(SlabHalf):     ptr = "half";     break;
            case(SlabHollow):   ptr = "hollow";   break;
            case(SlabSection):  ptr = "section";
        }
        fputs(ptr,OutFile);
        putc('\n',OutFile);
    } else fputs("slab off\n",OutFile);

/*
    phi = Round(Rad2Deg*asin(RotX[2]));
    if( phi == 90 )
    {   theta = -Round(Rad2Deg*atan2(RotY[0],RotY[1]));
        psi = 0;
    } else if( phi == -90 )
    {   theta = Round(Rad2Deg*atan2(RotY[0],RotY[1]));
        psi = 0;
    } else
    {   theta = Round(Rad2Deg*atan2(RotY[2],RotZ[2]));
        psi =  Round(-Rad2Deg*atan2(RotX[1],RotX[0]));
    }
 */
    phi = psi = theta = 0.0;
    RMat2RV(&theta, &phi, &psi, RotX, RotY, RotZ);
    theta *= 180.;
    phi *= 180.;
    psi *= 180.;
    

    if( Round(theta) ) fprintf(OutFile,"rotate x %d\n",Round(InvertY(-theta)));
    if( Round(phi) )   fprintf(OutFile,"rotate y %d\n",Round(phi));
    if( Round(psi) )   fprintf(OutFile,"rotate z %d\n",Round(InvertY(-psi)));
    if( BondsSelected ) {
      BondRot __far *brptr;

      brptr = BondsSelected;
      while (brptr) {
        fprintf(OutFile,"bond %ld %ld pick\n", 
          brptr->BSrcAtom->serno, brptr->BDstAtom->serno);
        fprintf(OutFile,"rotate bond %d\n", Round(brptr->BRotValue*180.));
        brptr = brptr->brnext;
      }
    }

    /* temp = (int)(10000.0*DialValue[DialTX]); */
    temp = (int)(10000.0*(XOffset-WRange)/(XRange*Zoom));
    if( temp ) fprintf(OutFile,"translate x %.2f\n",(Real)(temp/100.0));
    /* temp = (int)(10000.0*DialValue[DialTY]); */
    temp = (int)(10000.0*(YOffset-HRange)/(YRange*Zoom));
    if( temp ) fprintf(OutFile,"translate y %.2f\n",
      (Real)(InvertY(-temp)/100.0));
    /* temp = (int)(10000.0*DialValue[DialTZ]); */
    temp = (int)(10000.0*(ZOffset-10000)/(ZRange*Zoom));
    if( temp ) fprintf(OutFile,"translate z %.2f\n",(Real)(temp/100.0));

    if( DialValue[DialZoom] != 0.0 )
    {   if( DialValue[DialZoom]<0.0 )
        {   temp = (int)(100*DialValue[DialZoom]);
        } else temp = (int)(100*MaxZoom*DialValue[DialZoom]);
        fprintf(OutFile,"zoom %d\n",temp+100);
    }
    putc('\n',OutFile);

    if ( CenX || CenY || CenZ ) {
#ifdef INVERT
       fprintf(OutFile,"centre [%ld,%ld,%ld]\n", CenX, -CenY, -CenZ);
#else
       fprintf(OutFile,"centre [%ld,%ld,%ld]\n", CenX, CenY, -CenZ);
#endif
    }

    /* Rendering */
    if( DrawAxes || DrawBoundBox || DrawUnitCell )
        fprintf(OutFile,"colour axes [%d,%d,%d]\n",BoxR,BoxG,BoxB);
    if( DrawBonds )
        fprintf(OutFile,"set bonds %s\n", DrawDoubleBonds? "on":"off" );

    fprintf(OutFile,"set axes %s\n", DrawAxes? "on":"off" );
    fprintf(OutFile,"set boundingbox %s\n", DrawBoundBox? "on":"off" );
    fprintf(OutFile,"set unitcell %s\n", DrawUnitCell? "on":"off" );

    if( Database->hlist )
    {   fputs("set hbond ",OutFile);
        fputs(HBondMode?"backbone":"sidechain",OutFile);
        fputc('\n',OutFile);
    }

    if( Database->slist )
    {   fputs("set ssbond ",OutFile);
        fputs(SSBondMode?"backbone":"sidechain",OutFile);
        fputc('\n',OutFile);
    }

    fputs("set bondmode and\ndots off\n\n",OutFile); 
    fputs("\n# Avoid Colour Problems!\nselect all\n",OutFile);
    fputs("colour bonds none\ncolour backbone none\n",OutFile);
    fputs("colour hbonds none\ncolour ssbonds none\n",OutFile);
    fputs("colour ribbons none\ncolour white\n",OutFile);
    SelectAll = True;

    WriteScriptAtoms();
    if( UseSlabPlane && (SlabMode==SlabSection) )
    {   /* Section Mode Slabbing! */
        fclose(OutFile);
#ifdef APPLEMAC
        SetFileInfo(name,'RSML','RSML',133);
#endif
        return True;
    }

    WriteScriptBonds();
    WriteScriptRibbons();
    WriteScriptBackbone();
    WriteScriptLabels();
    WriteScriptMonitors();
    fputc('\n',OutFile);
    
    WriteScriptHBonds("ssbonds",Database->slist);
    WriteScriptHBonds("hbonds",Database->hlist);
    WriteScriptAll();

    fclose(OutFile);
#ifdef APPLEMAC
    SetFileInfo(name,'RSML','RSML',133);
#endif
    return True;
}



/*=======================*/
/*  Kinemage Generation  */
/*=======================*/

static char *FindKinemageCol( int r, int g, int b )
{
    register Long dist,best;
    register int dr,dg,db;
    register int i,res;

    res = 0;
    dr = KinemageCol[0].r - r;
    dg = KinemageCol[0].g - g;
    db = KinemageCol[0].b - b;
    best = (Long)dr*dr + (Long)dg*dg + (Long)db*db;

    for( i=1; i<MAXMAGECOL; i++ )
    {   dr = KinemageCol[i].r - r;
        dg = KinemageCol[i].g - g;
        db = KinemageCol[i].b - b;
        dist = (Long)dr*dr + (Long)dg*dg + (Long)db*db;  

        if( dist < best ) 
        {   best = dist;
            res = i;
        }
    }
    return( KinemageCol[res].name );
}


static char *GetKinemageCol( int col )
{
    register ShadeDesc *ptr;

    ptr = Shade + Colour2Shade(col);
    return( FindKinemageCol(ptr->r,ptr->g,ptr->b) );
}


static int CheckKinemageChain( RAtom __far *src,  RAtom __far *dst, 
                               Chain __far *chain )
{
    register Group __far *group;
    register RAtom __far *aptr;

    /* Determine Chain and Groups */
    schn = dchn = (Chain __far*)0;
    sgrp = dgrp = (Group __far*)0;

    if( chain )
    {   for( group=chain->glist; group; group=group->gnext )
        {   for( aptr=group->alist; aptr; aptr=aptr->anext )
            {   if( aptr == src ) sgrp = group;
                if( aptr == dst ) dgrp = group;
            }
            if( sgrp && dgrp ) 
                return True;
        }
    }
    return False;
}


static void OutputKinemageVector( RAtom __far *src,  RAtom __far *dst, int col )
{
    register RAtom __far *aptr;
    register Real x, y, z;
    register char *col1;
    register char *col2;

    if( !col )
    {   col1 = GetKinemageCol(src->col);
        col2 = GetKinemageCol(dst->col);
    } else col1 = col2 = GetKinemageCol(col);

    if( (col1!=MageCol) && (col2==MageCol) )
    {   aptr = src;  src = dst;  dst = aptr;
        col2 = col1;  col1 = MageCol;
    }

    if( col1 != MageCol )
    {   fprintf(OutFile,"@vectorlist {} color= %s\n",col1);
        MagePrev = (RAtom __far*)0;
    }

    if( src != MagePrev )
    {   if( MainGroupCount>1 )
        {   fprintf(OutFile,"{%.4s %.3s %d}", ElemDesc[src->refno], 
                    Residue[sgrp->refno], sgrp->serno );
        } else fprintf(OutFile,"{%.4s %ld}",ElemDesc[src->refno],src->serno);
        fprintf(OutFile," P %g %g %g\n", 
          (src->xorg + src->fxorg + src->xtrl/40. + OrigCX)/250.0, 
          RestoreY((src->yorg + src->fyorg + src->ytrl/40. + OrigCY))/250.0,
          -(src->zorg + src->fzorg + src->ztrl/40. + OrigCZ)/250.0 );
    }

    if( col1 != col2 )
    {   x = (src->xorg + dst->xorg + src->fxorg + dst->fxorg + 
          (src->xtrl + dst->xtrl)/40. + OrigCX + OrigCX)/500.0;
        y = (src->yorg + dst->yorg + src->fyorg + dst->fyorg +
          (src->ytrl + dst->ytrl)/40. + OrigCY + OrigCY)/500.0;
        z = (src->zorg + dst->zorg + src->fzorg + dst->fzorg +
          (src->ztrl + dst->ztrl)/40. + OrigCZ + OrigCZ)/500.0;

        fprintf(OutFile,"{} L %g %g %g\n", x, RestoreY(y), -z );
        fprintf(OutFile,"@vectorlist {} color= %s\n",col2);
        fprintf(OutFile,"{} P %g %g %g\n", x, RestoreY(y), -z );
    }

    if( MainGroupCount>1 )
    {   fprintf(OutFile,"{%.4s %.3s %d}", ElemDesc[dst->refno],
                Residue[dgrp->refno], dgrp->serno );
    } else fprintf(OutFile,"{%.4s %ld}",ElemDesc[dst->refno],dst->serno);
    fprintf(OutFile," L %g %g %g\n", 
      (dst->xorg + dst->fxorg + dst->xtrl/40. + OrigCX)/250.0,
      RestoreY((dst->yorg + dst->fyorg + dst->ytrl/40. + OrigCY))/250.0,
       -(dst->zorg + dst->fzorg + dst->ztrl/40. + OrigCZ)/250.0 );

    MagePrev = dst;
    MageCol = col2;
}


static void WriteKinemageBonds( Chain __far *chain )
{
    register Bond __far *bptr;
    register Bond __far *flag;

    MagePrev = (RAtom __far*)0;  
    MageCol = (char*)0;

    ForEachBond
        if( KinemageFlag || (bptr->flag&DrawBondFlag) )
        {   if( CheckKinemageChain(bptr->srcatom,bptr->dstatom,chain) )
            {   if( !MagePrev ) 
                    fputs("@subgroup {wireframe} dominant\n",OutFile);
                OutputKinemageVector(bptr->srcatom,bptr->dstatom,bptr->col);
            }
        }

    if( !chain->blist ) 
        return;

    /* Test for displayed backbone */
    for( flag=chain->blist; flag; flag=flag->bnext )
        if( flag->flag & DrawBondFlag ) break;
    if( !KinemageFlag && !flag ) return;

    MagePrev = (RAtom __far*)0;  
    MageCol = (char*)0;

    for( bptr=chain->blist; bptr; bptr=bptr->bnext )
        if( KinemageFlag || (bptr->flag&DrawBondFlag) )
        {   if( CheckKinemageChain(bptr->srcatom,bptr->dstatom,chain) )
            {   if( !MagePrev )
                {   fputs("@subgroup {alpha trace} dominant",OutFile);
                    fputs( (KinemageFlag && !flag)? " off\n":"\n",OutFile);
                }
                OutputKinemageVector(bptr->srcatom,bptr->dstatom,bptr->col);
            }
        }
}


static void WriteKinemageSpheres( Chain __far *chain )
{
    register Group __far *group;
    register RAtom __far *aptr;
    register char *col;
    register int radius = 0;

    MageCol = (char*)0;
    for( group=chain->glist; group; group=group->gnext )
        for( aptr=group->alist; aptr; aptr=aptr->anext )
            if( aptr->flag & SphereFlag )
            {   if( !MageCol )
                    fputs("@subgroup {CPK spheres} dominant\n",OutFile);

                col = GetKinemageCol(aptr->col);
                if( (col!=MageCol) || (aptr->radius!=radius) )
                {   fprintf(OutFile,"@balllist {} color= %s radius= %g\n",
                                    col, aptr->radius/250.0);
                    radius = aptr->radius;
                    MageCol = col;
                }

                if( MainGroupCount>1 )
                {   fprintf(OutFile,"{%.4s %.3s %d}", ElemDesc[aptr->refno],
                                    Residue[group->refno], group->serno );
                } else fprintf(OutFile,"{%.4s %ld}",ElemDesc[aptr->refno],
                                    aptr->serno);
                fprintf(OutFile," %g %g %g\n", 
                  (aptr->xorg + aptr->fxorg 
                    + (aptr->xtrl)/40. + OrigCX)/250.0,
                  RestoreY((aptr->yorg + aptr->fyorg
                    + (aptr->ytrl)/40. + OrigCY))/250.0, 
                  -(aptr->zorg + aptr->fzorg 
                    + (aptr->ztrl)/40. + OrigCZ)/250.0 );
            }
}



static void WriteKinemageLabels( Chain __far *chain )
{
    register Group __far *group;
    register RAtom __far *aptr;
    register Label *label;
    register char *col;

    auto unsigned char buffer[256];

    MageCol = (char*)0;
    for( group=chain->glist; group; group=group->gnext )
        for( aptr=group->alist; aptr; aptr=aptr->anext )
            if( aptr->label )
            {   if( !MageCol )
                    fputs("@subgroup {labels} dominant\n",OutFile);
                if( UseLabelCol )
                {   col = FindKinemageCol(LabR,LabG,LabB);
                } else col = GetKinemageCol(aptr->col);

                if( col != MageCol )
                    fprintf(OutFile,"@labellist {} color= %s\n",col);
                label = (Label*)aptr->label;
                FormatLabel(chain,group,aptr,label->label,buffer);
                fprintf(OutFile,"{%s} %g %g %g\n", buffer, 
                  (aptr->xorg + aptr->fxorg 
                  + (aptr->xtrl)/40. + OrigCX)/250.0, 
                  RestoreY((aptr->yorg + aptr->fyorg
                    + (aptr->ytrl)/40. + OrigCY))/250.0, 
                  -(aptr->zorg + aptr->fzorg 
                    + (aptr->ztrl)/40.  + OrigCZ)/250.0);
                MageCol = col;
            }
}


#ifdef UNUSED
static void WriteKinemageUnitCell( void )
{
}
#endif


static void WriteKinemageDots( void )
{
    auto int status[LastShade];
    register DotStruct __far *ptr;
    register ShadeDesc *shade;
    register int flag;
    register int i,j;

    fputs("@group {dot surface} dominant\n",OutFile);
    MageCol = (char*)0;

    for( i=0; i<LastShade; i++ )
        if( Shade[i].refcount )
        {      status[i] = 0;
        } else status[i] = 2;

    for( i=0; i<LastShade; i++ )
        if( status[i] == 0 )
        {   shade = &Shade[i];
            MageCol = FindKinemageCol(shade->r,shade->g,shade->b);
            shade++;

            status[i] = 1;
            for( j=i+1; j<LastShade; j++ )
            {   if( MageCol == FindKinemageCol(shade->r,shade->g,shade->b) )
                    status[j] = 1;
                shade++;
            }

            flag = False;
            for( ptr=DotPtr; ptr; ptr=ptr->next )
                for( j=0; j<ptr->count; j++ )
                    if( status[Colour2Shade(ptr->col[j])] == 1 )
                    {   if( !flag )
                        {   fprintf(OutFile,"@dotlist {} color= %s\n",MageCol);
                            flag = True;
                        }
                        fprintf(OutFile, "{} %g %g %g\n", 
                             (ptr->xpos[j] + OrigCX)/250.0,
                             RestoreY((ptr->ypos[j] + OrigCY))/250.0, 
                             -(ptr->zpos[j] + OrigCZ)/250.0 );
                    }

            for( j=i; j<LastShade; j++ )
                if( status[j] == 1 )
                    status[j] = 2;
        }
}


static void WriteKinemageData( void )
{
    register HBond __far *hptr;
    register RAtom __far *src;
    register RAtom __far *dst;
    register Real dx, dy, dz, cx, cy, cz;

    /* Hydrogen Bonds */
    for( hptr=Database->hlist; hptr; hptr=hptr->hnext )
        if( hptr->flag & DrawBondFlag ) break;

    if( KinemageFlag && Database->hlist )
    {   fputs("@group {h-bonds}",OutFile);
        fputs( hptr? "\n" : "off", OutFile );

        fputs("@subgroup {sidechain} dominant",OutFile);
        fputs( HBondMode? " off\n" : "\n", OutFile);
        for( hptr=Database->hlist; hptr; hptr=hptr->hnext )
        {   CheckKinemageChain( hptr->src, hptr->dst, (Chain __far*)0 );
            OutputKinemageVector( hptr->src, hptr->dst, hptr->col);
        }

        fputs("@subgroup {mainchain} dominant",OutFile);
        fputs( HBondMode? "\n" : " off\n", OutFile);
        for( hptr=Database->hlist; hptr; hptr=hptr->hnext )
        {   FetchBondInfo( hptr->src, hptr->dst );
            OutputKinemageVector( hptr->srcCA, hptr->dstCA, hptr->col);
        }
    } else if( hptr )
    {   fputs("@group {h-bonds} dominant\n",OutFile);
        for( hptr=Database->hlist; hptr; hptr=hptr->hnext )
            if( hptr->flag&DrawBondFlag )
            {   src = HBondMode? hptr->srcCA : hptr->src;
                dst = HBondMode? hptr->dstCA : hptr->dst;

                if( src && dst )
                {   FetchBondInfo( src, dst );
                    OutputKinemageVector( src, dst, hptr->col);
                }
            }
    }


    /* Disulphide Bridges */
    for( hptr=Database->slist; hptr; hptr=hptr->hnext )
        if( hptr->flag & DrawBondFlag ) break;

    if( KinemageFlag && Database->slist )
    {   fputs("@group {S-S bridges}",OutFile);
        fputs( hptr? "\n" : "off", OutFile );

        fputs("@subgroup {sidechain} dominant",OutFile);
        fputs( SSBondMode? " off\n" : "\n", OutFile);
        for( hptr=Database->slist; hptr; hptr=hptr->hnext )
        {   FetchBondInfo( hptr->src, hptr->dst );
            OutputKinemageVector(hptr->src,hptr->dst,hptr->col);
        }

        fputs("@subgroup {mainchain} dominant",OutFile);
        fputs( SSBondMode? "\n" : " off\n", OutFile);
        for( hptr=Database->slist; hptr; hptr=hptr->hnext )
        {   FetchBondInfo( hptr->srcCA, hptr->dstCA );
            OutputKinemageVector( hptr->srcCA, hptr->dstCA, hptr->col );
        }
    } else if( hptr )
    {   fputs("@group {S-S bridges} dominant\n",OutFile);
        for( hptr=Database->slist; hptr; hptr=hptr->hnext )
            if( hptr->flag&DrawBondFlag )
            {   FetchBondInfo( hptr->src, hptr->dst );
                OutputKinemageVector( SSBondMode?hptr->srcCA:hptr->src,
                                      SSBondMode?hptr->dstCA:hptr->dst,
                                      hptr->col );
            }
    }


    /* Dot Surfaces */
    if( DotPtr )
        WriteKinemageDots();

    /* Draw `Background' Objects */
    if( !KinemageFlag && !DrawAxes && 
        !DrawBoundBox && !DrawUnitCell )
        return;

    dx = MaxX/250.0;  dy = MaxY/250.0;  dz = MaxZ/250.0;
    cx = OrigCX/250.0; cy = OrigCY/250.0; cz = OrigCZ/250.0;
    MageCol = FindKinemageCol( BoxR, BoxG, BoxB );

    if( DrawAxes || KinemageFlag )
    {   fputs("@group {coord axes} dominant",OutFile);
        fputs( (DrawAxes?"\n":" off\n"), OutFile );
        fprintf(OutFile,"@vectorlist {} color= %s\n",MageCol);

        fprintf(OutFile,"{} P %g 0 0\n{} L %g 0 0\n",-dx+cx,dx+cx);
        fprintf(OutFile,"{} P 0 %g 0\n{} L 0 %g 0\n",-dy+cy,dy+cy);
        fprintf(OutFile,"{} P 0 0 %g\n{} L 0 0 %g\n",-dz+cz,dz+cz);
    }

    if( DrawBoundBox || KinemageFlag )
    {   fputs("@group {bound box} dominant",OutFile);
        fputs( (DrawAxes?"\n":" off\n"), OutFile );
        fprintf(OutFile,"@vectorlist {} color= %s\n",MageCol);

        fprintf(OutFile,"{} P %g %g %g\n",-dx+cx,-dy+cy,-dz+cz);
        fprintf(OutFile,"{} L %g %g %g\n", dx+cx,-dy+cy,-dz+cz);
        fprintf(OutFile,"{} L %g %g %g\n", dx+cx, dy+cy,-dz+cz);
        fprintf(OutFile,"{} L %g %g %g\n",-dx+cx, dy+cy,-dz+cz);
        fprintf(OutFile,"{} L %g %g %g\n",-dx+cx,-dy+cy,-dz+cz);
        fprintf(OutFile,"{} L %g %g %g\n",-dx+cx,-dy+cy, dz+cz);
        fprintf(OutFile,"{} L %g %g %g\n", dx+cx,-dy+cy, dz+cz);
        fprintf(OutFile,"{} L %g %g %g\n", dx+cx, dy+cy, dz+cz);
        fprintf(OutFile,"{} L %g %g %g\n",-dx+cx, dy+cy, dz+cz);
        fprintf(OutFile,"{} L %g %g %g\n",-dx+cx,-dy+cy, dz+cz);

        fprintf(OutFile,"{} P %g %g %g\n", dx+cx,-dy+cy,-dz+cz);
        fprintf(OutFile,"{} L %g %g %g\n", dx+cx,-dy+cy, dz+cz);
        fprintf(OutFile,"{} P %g %g %g\n", dx+cx, dy+cy,-dz+cz);
        fprintf(OutFile,"{} L %g %g %g\n", dx+cx, dy+cy, dz+cz);
        fprintf(OutFile,"{} P %g %g %g\n",-dx+cx, dy+cy,-dz+cz);
        fprintf(OutFile,"{} L %g %g %g\n",-dx+cx, dy+cy, dz+cz);
    }

    if( *Info.spacegroup && (DrawUnitCell || KinemageFlag) )
    {   fputs("@group {unit cell} dominant",OutFile);
        fputs( (DrawAxes?"\n":" off\n"), OutFile );
        fprintf(OutFile,"@vectorlist {} color= %s\n",MageCol);
        /* WriteKinemageUnitCell(); */
    }
}


int WriteKinemageFile( char *name )
{
    register Chain __far *chain;
    register Real zoom;

    if( !Database )
        return(True);

    OutFile = fopen(name,"w");
    if( !OutFile )
    {   FatalScriptError(name);
        return(False);
    }

    fprintf(OutFile,"@text\nRasMol v%s generated Kinemage\n \n", VERSION);
    if( *Info.moleculename )
        fprintf(OutFile,"Molecule name ....... %s\n",Info.moleculename);
    if( *Info.classification )
        fprintf(OutFile,"Classification ...... %s\n",Info.classification);
    if( *Info.identcode )
        fprintf(OutFile,"Database Code ....... %s\n",Info.identcode);

    fprintf(OutFile,
      "@kinemage 1\n@caption RasMol v%s generated Kinemage\n", VERSION);
    fputs("@onewidth\n",OutFile);

    if( DialValue[DialZoom] != 0.0 )
    {   if( DialValue[DialZoom]<0.0 )
        {   zoom = DialValue[DialZoom];
        } else zoom = MaxZoom*DialValue[DialZoom];
        fprintf(OutFile,"zoom %g\n",zoom+1.0);
    }

    if( Info.chaincount > 1 )
    {   for( chain=Database->clist; chain; chain=chain->cnext )
        {   fprintf(OutFile,"@group {chain %c}\n",chain->ident);
            WriteKinemageSpheres( chain );
            WriteKinemageBonds( chain );
            WriteKinemageLabels( chain );
        }
    } else
    {   fputs("@group {molecule}\n",OutFile);
        chain = Database->clist;
        WriteKinemageSpheres( chain );
        WriteKinemageBonds( chain );
        WriteKinemageLabels( chain );
    }

    WriteKinemageData();
    fclose(OutFile);
#ifdef APPLEMAC
    SetFileInfo(name,'MAGE','TEXT',135);
#endif
    return True;
}


/*================================*/
/*  POVRay Ray Tracer Generation  */
/*================================*/

int WritePOVRayFile( char *name )
{
    register ShadeDesc *shade;
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *aptr;
    register double x,y,z;

    if( !Database )
        return(True);

    OutFile = fopen(name,"w");
    if( !OutFile )
    {   FatalScriptError(name);
        return(False);
    }

    fprintf(OutFile,"// File: %s\n",name);
    fprintf(OutFile,"// Creator: RasMol Version %s\n", VERSION);
    fputs("// Version: POV-Ray Version 2.2\n\n",OutFile);

    fputs("#include \"shapes.inc\"\n",OutFile);
    fputs("#include \"colors.inc\"\n",OutFile);
    fputs("#include \"textures.inc\"\n\n",OutFile);

    fputs("// Camera\ncamera {",OutFile);
#ifdef __STDC__
    fprintf(OutFile,"    location <0, 0, %g>\n",-Offset/250.0);
#else
    fprintf(OutFile,"    location <0, 0, %lg>\n",(double)(-Offset/250.0));
#endif
    fputs("    look_at <0, 0, 0>\n}\n\n",OutFile);

    fputs("// Light\nlight_source {<0, 20, -100>",OutFile);
    fputs(" color rgb <1, 1, 1>}\n\n",OutFile);

    fputs("// Objects\n",OutFile);

    ForEachAtom
        if( aptr->flag & SphereFlag )
        {   x = (double)(aptr->xorg + aptr->fxorg)/250.0 
                + (double)(aptr->xtrl)/10000.;
            y = (double)(aptr->yorg + aptr->fyorg)/250.0 
                + (double)(aptr->ytrl)/10000.;
            z = (double)(aptr->zorg + aptr->fzorg)/250.0 
                + (double)(aptr->ztrl)/10000.;
#ifdef __STDC__
            fprintf(OutFile,"object {sphere {<%g, %g, %g> %g}\n",
#else
            fprintf(OutFile,"object {sphere {<%lg, %lg, %lg> %lg}\n",
#endif
#ifdef INVERT
                             x, -y, -z, (double)aptr->radius/250.0 );
#else
                             x,  y, -z, (double)aptr->radius/250.0 );
#endif

            fputs("  texture {\n",OutFile);
            shade = Shade+Colour2Shade(aptr->col);
#ifdef __STDC__
            fprintf(OutFile,"    pigment {color rgb <%g, %g, %g>}\n",
#else
            fprintf(OutFile,"    pigment {color rgb <%lg, %lg, %lg>}\n",
#endif
                    (double)shade->r/255.0, 
                    (double)shade->g/255.0, 
                    (double)shade->b/255.0 );
            if( FakeSpecular )
                fputs("    finish {phong 1}\n",OutFile);
            fputs("  }\n}\n",OutFile);
        }

    fclose(OutFile);
#ifdef APPLEMAC
    SetFileInfo(name,'ttxt','TEXT',133);
#endif
    return True;
}



/*===========================================*/
/*  VRML Virtual Reality Modelling Language  */
/*===========================================*/

static void WriteVRMLTriple( double x, double y, double z )
{
#ifdef __STDC__
    fprintf(OutFile,"%.3f %.3f %.3f",x,y,z);
#else
    fprintf(OutFile,"%.3lf %.3lf %.3lf",x,y,z);
#endif
}


static void WriteVRMLColour( int indent, int shade )
{
    register int i;

    for( i=0; i<indent; i++ )
        fputc(' ',OutFile);
    fputs("Material { diffuseColor ",OutFile);
    WriteVRMLTriple(Shade[shade].r/255.0,
                    Shade[shade].g/255.0,
                    Shade[shade].b/255.0);
    fputs(" }\n",OutFile);
}

                
                    
static void WriteVRMLCylinder(double src[3], double dst[3], double radius, int indent, int shade ) {
                    
    register int i;
    double raxis[3], baxis[3];
    double nsqr, nsqb, dotp, sangle, cangle, angle, height;
                    
    /*  baxis = dst-src
        raxis = baxis x [0,1,0]
        nsqr = (raxis,raxis)
        nsqb = (baxis,baxis)
        dotp = (baxis,[0,1,0])
        
        angle = angle between baxis and [0,1,0]
        cos(angle) = dotp/sqrt(nsqb)
        sin(angle) = sqrt(nsqr)/sqrt(nsqb)
             
    */
                    
    for( i=0; i < 3; i++) baxis[i] = dst[i]-src[i];
    raxis[0] = -baxis[2];
    raxis[1] = 0;
    raxis[2] = baxis[0];
    nsqr = nsqb = 0.;
    for( i=0; i < 3; i++) nsqr += raxis[i]*raxis[i];
    for( i=0; i < 3; i++) nsqb += baxis[i]*baxis[i];            
    dotp = baxis[1];
    cangle = 1.;
    sangle = 0;
    angle = 0.;
    height = 0.;
    if (nsqb > 1.e-15) {
        height = sqrt(nsqb);
        sangle = sqrt(nsqr)/height;
        cangle = dotp/height;
        angle = atan2(sangle,cangle);
    }
    if (nsqr > 1.e-15) {
      raxis[0] = raxis[0]/sqrt(nsqr);
      raxis[2] = raxis[2]/sqrt(nsqr);
    } else {
      raxis[0] = raxis[2] = 0.;
      raxis[1] = 1.;
    }
                    
    for( i=0; i<indent; i++ ) fputc(' ',OutFile);
    fputs("Separator {\n",OutFile);
    WriteVRMLColour(indent+2, shade);
    for( i=0; i<indent+2; i++ ) fputc(' ',OutFile);
    fputs("Translation { translation ", OutFile);
    WriteVRMLTriple(src[0],src[1],src[2]);
    fputs("}\n", OutFile);
    for( i=0; i<indent+2; i++ ) fputc(' ',OutFile);
    fputs("Sphere {", OutFile);
    fprintf(OutFile," radius %g }\n",radius);

    for( i=0; i<indent+2; i++ ) fputc(' ',OutFile);
    fputs("Translation { translation ", OutFile);
    WriteVRMLTriple(dst[0]-src[0],dst[1]-src[1],dst[2]-src[2]);
    fputs("}\n", OutFile);
    for( i=0; i<indent+2; i++ ) fputc(' ',OutFile);
    fputs("Sphere {", OutFile);
    fprintf(OutFile," radius %g }\n",radius);

    for( i=0; i<indent+2; i++ ) fputc(' ',OutFile);
    fputs("Translation { translation ", OutFile);
    WriteVRMLTriple((src[0]-dst[0])/2.,(src[1]-dst[1])/2.,(src[2]-dst[2])/2.);
    fputs("}\n", OutFile);
                    
    for( i=0; i<indent; i++ ) fputc(' ',OutFile);
    fputs("Rotation { rotation ", OutFile);
    fprintf(OutFile, "%g %g %g %g ", raxis[0], raxis[1], raxis[2], -angle);
    fputs("}\n", OutFile);
                    
    for( i=0; i<indent+2; i++ ) fputc(' ',OutFile);
    fputs("Cylinder {\n", OutFile);
    for( i=0; i<indent+4; i++ ) fputc(' ',OutFile);
    fprintf(OutFile," radius %g height %g\n",radius,height);
    for( i=0; i<indent+4; i++ ) fputc(' ',OutFile);
    fputs("}\n", OutFile);
    for( i=0; i<indent; i++ ) fputc(' ',OutFile);
    fputs("}\n", OutFile);
}

static void WriteVRMLBondCylinder(RAtom __far * asrc, RAtom __far * adst, short radius, short col) {
    double src[3], dst[3], mid[3];
                    
    src[0] = (double)(asrc->xorg + asrc->fxorg)/250.0
                    + (double)(asrc->xtrl)/10000.;
    src[1] = (double)(asrc->yorg + asrc->fyorg)/250.0
                    + (double)(asrc->ytrl)/10000.;
    src[2]= -(double)(asrc->zorg + asrc->fzorg)/250.0
                    - (double)(asrc->ztrl)/10000.;

    dst[0] = (double)(adst->xorg + adst->fxorg)/250.0
                    + (double)(adst->xtrl)/10000.;
    dst[1] = (double)(adst->yorg + adst->fyorg)/250.0
                    + (double)(adst->ytrl)/10000.;
    dst[2]= -(double)(adst->zorg + adst->fzorg)/250.0
                    - (double)(adst->ztrl)/10000.;

    if ( vrml_mirror ) {
        src[0] = -src[0];
        src[1] = -(RestoreY(src[1]));
        src[2] = -src[2];
        dst[0] = -dst[0];
        dst[1] = -(RestoreY(dst[1]));
        dst[2] = -dst[2];
    } else {
      if (vrml_rotate) {
        src[1] = -(RestoreY(src[1]));
        src[2] = -src[2];
        dst[1] = -(RestoreY(dst[1]));
        dst[2] = -dst[2];
      } else {
        src[1] = (RestoreY(src[1]));
        dst[1] = (RestoreY(dst[1]));
      }
    }
    
    if (radius < 10) radius=10;
                    
    if (col) { 
        WriteVRMLCylinder(src, dst, ((double)radius)/250., 2, Colour2Shade(col));
    } else {
        mid[0] = (src[0]+dst[0])/2;
        mid[1] = (src[1]+dst[1])/2;
        mid[2] = (src[2]+dst[2])/2;
        WriteVRMLCylinder(src, mid, ((double)radius)/250., 2, Colour2Shade(asrc->col));
        WriteVRMLCylinder(mid, dst, ((double)radius)/250., 2, Colour2Shade(adst->col));
    }
            
}
                    
static void WriteVRMLAtoms( void )
{
    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *aptr;
    register double ox,oy,oz;
    register double x,y,z;
    register int i,flag;

    for( i=0; i<LastShade; i++ )
        if( Shade[i].refcount )
        {   flag = False;
            ox = 0.0;  oy = 0.0;  oz = 0.0;
            ForEachAtom
                if( (aptr->flag&SphereFlag)&&(i==Colour2Shade(aptr->col)) )
                {   if( !flag )
                    {   WriteVRMLColour(2,i);
                        fputs("  Separator {\n",OutFile);
                        flag = True;
                    }

                    x = (double)(aptr->xorg + aptr->fxorg)/250.0
                      + (double)(aptr->xtrl)/10000.;
                    y = (double)(aptr->yorg + aptr->fyorg)/250.0
                      + (double)(aptr->ytrl)/10000.;
                    z = -(double)(aptr->zorg + aptr->fzorg)/250.0
                      - (double)(aptr->ztrl)/10000.;

                    fputs("    Transform { translation ",OutFile);

                    if ( vrml_mirror ) {
                      WriteVRMLTriple(-(x-ox),-(RestoreY(y-oy)),-(z-oz));
                    } else {
                      if (vrml_rotate) {
                        WriteVRMLTriple(x-ox,-(RestoreY(y-oy)),-(z-oz));
                      } else {
                        WriteVRMLTriple(x-ox,RestoreY(y-oy),z-oz);
                      }
                    }
                    ox = x;  oy = y;  oz = z;
                    fputs(" }\n",OutFile);

                    fputs("    Sphere { radius ",OutFile);
#ifdef __STDC__
                    fprintf(OutFile,"%.3f }\n",(double)aptr->radius/250.0);
#else
                    fprintf(OutFile,"%.3f }\n",(double)aptr->radius/250.0);
#endif
                }

            if( flag )
                fputs("  }\n",OutFile);
        }
}
                            

static void WriteVRMLLine( int src, int dst, int shade, int *flag )
{
    if( !*flag )
    {   WriteVRMLColour(4,shade);
        fputs("    IndexedLineSet {\n",OutFile);
        fputs("      coordIndex [\n",OutFile);
        *flag = True;
    }
    fprintf(OutFile,"        %5d, %5d, -1,\n",src-1,dst-1);
}


static void WriteVRMLWireframe( void )
{
    register Bond __far *bptr;
    register RAtom __far *src;
    register RAtom __far *dst;

    ForEachBond
        if (bptr->flag & DrawBondFlag)
        {   src = bptr->srcatom;
            dst = bptr->dstatom;
            WriteVRMLBondCylinder(src, dst, bptr->radius, bptr->col);
        }

}

static void WriteVRMLBackbone( void )
{
    register Chain __far *chain;
    register Bond __far *bptr;
    register RAtom __far *src;
    register RAtom __far *dst;

    ForEachBack
        if (bptr->flag & DrawBondFlag)
        {   src = bptr->srcatom;
            dst = bptr->dstatom;
            WriteVRMLBondCylinder(src, dst, bptr->radius, bptr->col);
        }

}

static void WriteVRMLHbonds( void )
{
    register HBond __far *hptr;
    register RAtom __far *src;
    register RAtom __far *dst;

    for( hptr=Database->slist; hptr; hptr=hptr->hnext )
        if( hptr->flag & DrawBondFlag ) {
            if (SSBondMode) {
              src = hptr->srcCA;
              dst = hptr->dstCA;
            } else {
              src = hptr->src;
              dst = hptr->dst;
            }
            src = hptr->src;
            dst = hptr->dst;
            WriteVRMLBondCylinder(src, dst, hptr->radius, hptr->col);
        }

}


static void WriteVRMLDots( void )
{
    auto int hist[LastShade];
    register DotStruct __far *ptr;
    register double x,y,z;
    register int count;
    register int flag;
    register int i,j;

    flag = False;
    for( i=0; i<LastShade; i++ )
        if( Shade[i].refcount )
        {   count = 0;

            for( ptr=DotPtr; ptr; ptr=ptr->next )
                for( j=0; j<ptr->count; j++ )
                    if( Colour2Shade(ptr->col[j]) == i )
                    {   if( !flag )
                        {   fputs("  Separator {\n",OutFile);
                            fputs("    Coordinate3 {\n",OutFile);
                            fputs("      point [\n",OutFile);
                            flag = True;
                        }

                        x = (double)ptr->xpos[j]/250.0;
                        y = (double)ptr->ypos[j]/250.0;
                        z = -(double)ptr->zpos[j]/250.0;

                        fputs("        ",OutFile);
                        if (vrml_mirror) {
                          WriteVRMLTriple(-x,-(RestoreY(y)),-z);
                        } else {
                          if (vrml_rotate) {
                          	WriteVRMLTriple(x,-(RestoreY(y)),-z);
                          } else {
                        WriteVRMLTriple(x,RestoreY(y),z);
                          }
                        }
                        fputs(",\n",OutFile);
                        count++;
                    }

            hist[i] = count;
        } else hist[i] = 0;

    if( flag )
    {   fputs("      ]\n",OutFile);
        fputs("    }\n",OutFile);

        count = 0;
        for( i=0; i<LastShade; i++ )
            if( hist[i] )
            {   WriteVRMLColour(4,i);
                fputs("    PointSet {\n      ",OutFile);
                fprintf(OutFile,"startIndex %d numPoints %d\n",count,hist[i]);
                fputs("    }\n",OutFile);
                count += hist[i];
            }

        fputs("  }\n",OutFile);
    }
}


int WriteVRMLFile( char *name, int subtype )
{
    if( !Database )
        return True;

    OutFile = fopen(name,"w");
    if( !OutFile )
    {   FatalScriptError(name);
        return False;
    }
    
    vrml_mirror = False;
    vrml_rotate = False;
    if ( subtype == MirrorTok ) vrml_mirror = True;
    if ( subtype == RotateTok ) vrml_rotate = True;

    fputs("#VRML V1.0 ascii\n",OutFile);
    fprintf(OutFile,"#Created by RasMol v%s\n\n",VERSION);

    fputs("DEF Viewer Info { string \"examiner\" }\n",OutFile);
    fprintf(OutFile,"DEF Title Info { string \"%s\" }\n",Info.moleculename);
    fprintf(OutFile,
      "DEF Creator Info { string \"Created by RasMol v%s\" }\n",VERSION);
    fputs("DEF BackgroundColor Info { string \"",OutFile);
    WriteVRMLTriple(BackR/255.0,BackG/255.0,BackB/255.0);
    fputs("\" }\n\n",OutFile);
    
    fputs("Separator {\n",OutFile);

#ifdef ORIG
    fputs("  DirectionalLight {\n",OutFile);
    fputs("    direction -1 -1 -2\n",OutFile);
    fputs("  }\n\n",OutFile);
#endif

    WriteVRMLAtoms();
    WriteVRMLWireframe();
    WriteVRMLBackbone();
    WriteVRMLHbonds();
    /*if (DrawRibbon )
        WriteVRMLRibbon(); */
    if( DotPtr )
        WriteVRMLDots();

    fputs("}\n",OutFile);
    fclose(OutFile);
#ifdef APPLEMAC
    SetFileInfo(name,'ttxt','TEXT',133);
#endif
    return True;
}

static void WriteBuffer ( char* buffer )
{
   if ( OutFile ) {
     fputs(buffer, OutFile);
   } else {
     WriteString ( buffer );
   }
 }

int WritePhiPsiAngles ( char *name, int ramachan )
{

  register Chain __far *chain;
  register Group __far *group;
  register RAtom __far *aptr;
  register Group __far *prev;
  register char c;
  char pplot[73][73];
  char buffer[130];
  AtomRef current;
  double phi, psi, omega;
  int i,j,iphi,jphi,ipsi,jpsi,model;

  if (ramachan < 0 )
    for (i = 0; i<73; i++)
      for (j = 0; j < 73; j++)
        pplot[i][j] = ' ';

  model = -1;

  if( !Database )
    return(True);

  if (name && !(name[0] == '-' && name[1] == '\0')) {
    OutFile = fopen(name,"w");
    if( !OutFile ){
      FatalScriptError(name);
      return(False);
    }
  } else {
    OutFile = (FILE *)0;
  }   
  /* Note: '#' is comment-sign in gnuplot */ 
  if (OutFile) {
    sprintf(buffer,"# File: %s\n",name);  
    WriteBuffer(buffer);
    sprintf(buffer,"# Creator: RasMol Version %s\n", VERSION);
    WriteBuffer(buffer);
    sprintf(buffer, "# from Molecule: %s\n", 
      Info.moleculename);
    WriteBuffer(buffer);
    sprintf(buffer, "# Database Code: %s\n", 
      Info.identcode);
    WriteBuffer(buffer);
  }
  if(ramachan > 0 ){
    WriteBuffer("# phi/psi-angles for Ramachandran-Plot\n");
    WriteBuffer("#\n#\t\tPhi \t Psi\n");
  } else {
    if (ramachan < 0 ) {
    WriteBuffer("# Ramachandran Printer Plot\n");
    } else {
      WriteBuffer("# Combinations of backbone-angles\n");
    }
  }

  for(chain=Database->clist;chain;chain=chain->cnext){ 
    prev = (Group __far *)0;
    for(group=chain->glist;group;group=group->gnext){
      for(aptr=group->alist;aptr;aptr=aptr->anext){
	if( !(aptr->flag&SelectFlag) || !IsAmino(group->refno)){
	  prev = group;
	  break;	  
	} 
	if(!aptr->anext){ 
	  /* save reference to current group for later information */
	  current.chn = chain;
	  current.grp = group;
	  current.atm = aptr;

	  /* calculation of angles (-180.0 <= angle >= 180.0) */
	  if(prev && IsAmino(prev->refno)){
	     phi   = CalcPhiAngle(prev, group);
 	     omega =  CalcOmegaAngle(prev, group);
	  } else {
	    phi   = 360.0;
	    omega = 360.0;
	  }
	 
	  if(group->gnext && IsAmino(group->gnext->refno))
	    psi   = CalcPsiAngle(group, group->gnext);
	  else
	    psi   = 360.0;

      if ( !(group->model == model) ) {
        if (model > 0 || group->model > 0 ) {
          sprintf(buffer, "Model: %d\n", group->model);
          WriteBuffer(buffer);
          if ( ( ramachan < 0)  && (model > 0) ) {
            WriteBuffer(
              "    ...........................................................................\n");
            for ( i = 0; i < 73 ; i++ ) {
              sprintf(buffer,"%5d.",180-5*i);
              for ( j = 0; j < 73; j++ ) buffer[5+j] = pplot[i][j];
              buffer[5+73] = '.'; buffer[5+74] = '\n'; buffer[5+75] = '\0';
              WriteBuffer(buffer);
            }
            WriteBuffer(
              "    ...........................................................................\n\n");
            WriteBuffer(
              "P    - - - - - - - - -                                       + + + + + + + + +\n");
            WriteBuffer(
              "s    1 1 1 1 1 1 1 1 1 - - - - - - - - -   + + + + + + + + + 1 1 1 1 1 1 1 1 1\n");
            WriteBuffer(
              "i    8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1   1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8\n");
            WriteBuffer(
              "Phi   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n");
          }
          for (i = 0; i<73; i++)
            for (j = 0; j < 73; j++)
              pplot[i][j] = ' ';
          model = group->model;
        }
      }

	  /* writing (current group and) angles */
	  if(ramachan){     /* data for Ramachandran-plot */
	    if(fabs(phi) <= 180.0 && 180.0 >= fabs(psi)) {
          if (ramachan > 0) {
	        sprintf(buffer, "%3s\t%c%d\t%#.1f\t%#.1f\n", 
		      Residue[group->refno], 
		      chain->ident, 
		      group->serno, 
		      phi, psi);
		    WriteBuffer(buffer);
          }
          iphi = (phi+182.5)/5.;
          ipsi = (psi+182.5)/5.;
          ipsi = 72-ipsi;
          if (iphi < 0 ) iphi = 0;
          if (iphi > 72) iphi = 72;
          if (ipsi < 0 ) ipsi = 0;
          if (ipsi > 72) ipsi = 72;
          jphi = iphi;
          jpsi = ipsi;
          if (iphi == 0 || iphi == 72) {
            iphi = 0;
            jphi = 72;
          }
          if (ipsi == 0 || ipsi == 72) {
            ipsi = 0;
            jpsi = 72;
          }
          for ( i = iphi; i <= jphi; i+= 72 ) {
            for ( j = ipsi; j <= jpsi; j+=72 ) {
              c = pplot[j][i];
              if ( c == ' ' ) {
                c = '1';
              } else if ( c == '9' || c == '+' ) {
                c = '+';
              } else c++;
              pplot[j][i] = c;
            }
          }
        }  
	  }
	  else{ 
	    WriteBuffer( DescribeObj(&current, GRP) ); 
	    if(phi != 360.0) {
	      sprintf(buffer, "\tPhi = %#.1f", phi);
	      WriteBuffer(buffer);
	    }
	    if(psi != 360.0) {
	      sprintf(buffer, "\tPsi = %#.1f", psi);
	      WriteBuffer(buffer);
	    }
	    /*  only omega-angles of cis-peptidbonds are listed, */
	    /*  see 'molecule.h' for definition of 'CIS'          */
	    if(fabs(omega) < CisBondCutOff)  {
	      sprintf(buffer, "\tOmega = %#.1f", omega);
	      WriteBuffer(buffer);
	    }
	    WriteBuffer("\n");
	  }
	  prev = group;
	}
      } /* for atom ... */
    } /* for group ... */ 
  } /* for chain ... */
 
  if (ramachan < 0) {
    WriteBuffer(
      "    ...........................................................................\n");
    for ( i = 0; i < 73 ; i++ ) {
      sprintf(buffer,"%4d.",180-5*i);
      for ( j = 0; j < 73; j++ ) buffer[5+j] = pplot[i][j];
        buffer[5+73] = '.'; buffer[5+74] = '\n'; buffer[5+75] = '\0';
      WriteBuffer(buffer);
    }
    WriteBuffer(
      "    ...........................................................................\n\n");
    WriteBuffer(
      "P    - - - - - - - - -                                       + + + + + + + + +\n");
    WriteBuffer(
      "s    1 1 1 1 1 1 1 1 1 - - - - - - - - -   + + + + + + + + + 1 1 1 1 1 1 1 1 1\n");
    WriteBuffer(
      "i    8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1   1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8\n");
    WriteBuffer(
      "Phi  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n");
  }

  if(OutFile) {
    fclose(OutFile);
#ifdef APPLEMAC
    SetFileInfo(name,'ttxt','TEXT',133);
#endif
  }
  return True;
}


/****************************************************************************\
 * POV-Ray version 3:
 * ==================
 *
 * Below you find all you need for the transformation of a RasMol-Image to a 
 * POV-script. Note, you need POV-Ray 3 or higher to render the created
 * POV-scriptfile.
 *
 * 'WritePOVRay3File' is the main function that writes the scriptfile, it's
 * an external function, all other functions used by WritePOVRay3File' are
 * internal (static).
\****************************************************************************/


/*==========================================================================*\
 * datatypes, variables and definitions for POV-work
\*==========================================================================*/

typedef struct _Coord {
  double x;
  double y;
  double z;
} Coord;


/* storing RGB-values */
typedef struct _Color{
  double r;
  double g;
  double b;
} Color;


/*==========================================================================*\
 * Prototypes of internal functions
\*==========================================================================*/
static Coord POVGetMidCoord(RAtom __far *src, RAtom __far *dst);
static Color POVGetColor(int col);
static void  POVWriteTexture(Color color);
static void  POVWriteHeader(void);
static void  POVWriteAtoms(void);
static void  POVWriteLine(RAtom __far *src,RAtom __far *dst,int rad,Byte flag);
static void  POVWriteBonds(void);
static void  POVWriteBackBone(void);
static void  POVWriteHSBonds(void);
static void  POVWriteDots(void);

/*=========================================================================*\
 * Definitions for the finish of the POV-scene, may me changed by user
 *
 * SPECPOWER: a high value makes a shiny surface, value from 0..1
 * ROUGHNESS: 1..0.005, low values for a small highlight (= very smooth),
 *            bigger values for a rough surface
 * DIFFUSE  : high value causes sharp shadows, objects in a shadow are
 *            very dark, LOW value means that less light comes directly
 *            from the lightsource, most light comes from everywhere. 
 *            Values from 0..1.
 * AMBIENT  : "ambient" together with "diffuse" controlls the scattered 
 *            light, higher values for ambient means that there are many
 *            lightsources everywhere in space. Values from 0..1
 * TRANSMIT : determines the transparence of a surface, values from 0..1,
 *            1.0 is completely transparent
 * DOTFACTOR: bigger values for bigger dots (spheres) of dots surfaces
 * MINWIRE  : because a cylinder in POVRay is not allowed to have radius 0
 *            you have to define a minimal value for this, default is 10,
 *            this creates a very thin cylinder
 * MINDASH  : the same as above only for a dashed wireframe
\*=========================================================================*/
#define SPECPOWER 0.4  
#define ROUGHNESS 0.005
#define DIFFUSE   0.8 
#define AMBIENT   0.2 
#define TRANSMIT  0.0

#define MAXNAME 80  /* maximal length of a filename */

/* to convert the world coordinates into original pdb coordinates */
#define Trans 250.0
#define INVTrans 0.004
#define TransO(o) ((double)(o)*INVTrans)
#define TransX(x) ((double)((x)+OrigCX)*INVTrans)
#define TransY(y) ((double)(RestoreY((y)+OrigCY)*INVTrans))
#define TransZ(z) (-((double)((z)+OrigCZ)*INVTrans))

#define DOTFACTOR (500.0) 
#define MINWIRE   (15)
#define MINDASH   (MINWIRE)

#define NOSHADEDOTS /* define this to avoid shade each dot of dottes surfaces */


/*==========================================================================*\
 * Internal macro "POVWriteSphere" writes a sphere with in the atom colour
 * but with an explicit given radius, so you can also use it for rounded
 * cylinder caps. 
\*==========================================================================*/
#define POVWriteSphere(atom, rad)  \
        fprintf(OutFile_inc, "object {\n"\
		"   sphere { < %g , %g , %g > %g }\n",\
		TransX(atom->xorg+atom->fxorg),\
		TransY(atom->yorg+atom->fyorg),\
		TransZ(atom->zorg+atom->fzorg),\
		TransO(rad)),\
                POVWriteTexture(POVGetColor((int)(atom)->col)), \
        Slab(), \
        fputs("}\n", OutFile_inc)

/*==========================================================================*\
 * These internal but global variables are shared by internal POV-functions.
 * Because no function should change the values for file handling expect
 * the main function 'WritePOVRay3File' there's no need to use function 
 * parameters instead.
\*==========================================================================*/

static FILE *OutFile_inc = NULL; 
static char INCname[MAXNAME]   ; 
static char POVname[MAXNAME]   ; 


/*==========================================================================*\
 * Below you find all function definitions ...
\*==========================================================================*/
/****************************************************************************/

/*==========================================================================*\
 * returns the coordinate that is exact between two given coordinates
\*==========================================================================*/
static Coord POVGetMidCoord( RAtom __far *src, RAtom __far *dst )
{
  
  Coord d;

  d.x = (double)(labs(src->xorg - dst->xorg + src->fxorg - dst->fxorg));
  d.y = (double)(labs(src->yorg - dst->yorg + src->fyorg - dst->fyorg));
  d.z = (double)(labs(src->zorg - dst->zorg + src->fzorg - dst->fzorg));
  if ( src->xorg + src->fxorg > dst->xorg + dst->fxorg )
    d.x*= -1;
  if ( src->yorg + src->fyorg > dst->yorg + dst->fyorg )
    d.y*= -1;
  if ( src->zorg + src->fzorg > dst->zorg + dst->fzorg )
    d.z*= -1;
     
  d.x = TransX(d.x * 0.5 + src->xorg + src->fxorg);
  d.y = TransY(d.y * 0.5 + src->yorg + src->fyorg);
  d.z = TransZ(d.z * 0.5 + src->zorg + src->fzorg); 

  return d;
}


/*===========================================================================*\
 * returns a POVRAY-Color
\*===========================================================================*/
static Color POVGetColor( int col )
{

  ShadeDesc *shade;
  Color POVcol;

  shade = Shade+Colour2Shade(col);
  POVcol.r = (double)shade->r/255.0;
  POVcol.g = (double)shade->g/255.0;
  POVcol.b = (double)shade->b/255.0;
  
  return POVcol;
}


/*===========================================================================*\
 * writes the color of an object including finish
\*===========================================================================*/
static void POVWriteTexture( Color color )
{
        fputs("    texture {\n",OutFile_inc);
        fprintf(OutFile_inc,"      pigment {color rgbt <%g, %g, %g, T>}\n",
	  (color).r, (color).g, (color).b),
        fputs("      finish {F}\n", OutFile_inc);
	fputs("    }\n", OutFile_inc);
}


/*===========================================================================*\
 * internal function "POVWriteHeader"
\*===========================================================================*/
static void POVWriteHeader( void )
{

  double  dx, dy, dz;

  fprintf(OutFile,"// Original image size: H = %d, W = %d\n\n", 
	  YRange, XRange);   
  
  fprintf(OutFile,"// OrigCX = %ld, OrigCY = %ld, OrigCZ = %ld, Scale = %g\n\n", 
	  OrigCX, OrigCY, OrigCZ, Scale);   


  dx =   MatX[0]*TransX(0)+MatX[1]*TransY(0)-MatX[2]*TransZ(0);
  dy =   MatY[0]*TransX(0)+MatY[1]*TransY(0)-MatY[2]*TransZ(0);
  dz =  -MatZ[0]*TransX(0)-MatZ[1]*TransY(0)+MatZ[2]*TransZ(0);

  fputs("// Camera\ncamera {\n    orthographic\n", OutFile);
  fprintf(OutFile,"    location <%g, %g, %g>\n", 
	  dx-TransO((XOffset-XRange*0.5)), 
	  dy-TransO((YOffset-YRange*0.5)), 
	  TransO(-ZOffset));
  fprintf(OutFile,"    look_at <%g, %g, %g>\n", 
	  dx-TransO((XOffset-XRange*0.5)), 
	  dy-TransO((YOffset-YRange*0.5)), 
	  /*dz-TransO(-ZOffset));*/
          dz);

  fprintf(OutFile,"    up <0, %g, 0>\n",    TransO(-YRange));
  fprintf(OutFile,"    right <%g, 0, 0>\n", TransO(XRange));
  fputs("}\n\n",OutFile);

  /*-------------------------------------------------------------------------*\
   * The light source is 2 units on the right and two untis above the origin.
   * The Y-value is negative because Y-axis is inverted. The camera is 
   * between light and object (see above)!
  \*-------------------------------------------------------------------------*/
  fprintf(OutFile, "// Light\nlight_source {<%g, %g, %g>", 
	  2.0*ZOffset, -2.0*ZOffset, -4.0*ZOffset);       
  fputs(" color rgb <1.0, 1.0, 1.0>}\n\n",OutFile);           
  fprintf(OutFile,"background { color rgb <%g, %g, %g> }\n\n", 
          (double)BackR/255.0, (double)BackG/255.0, (double)BackB/255.0);
 
  fputs("union {   \n// Objects\n",OutFile);
  fprintf(OutFile,"   // union finish\n"
	  "   // change \"T\" to a higher value (up to 1.0, e.g. 0.8) and\n"
	  "   // uncomment \"hollow\" to make your object transparent\n"
	  "   #declare F = finish { specular %g roughness %g\n"
	  "                         diffuse %g\n"
	  "                         ambient %g }\n"
	  "   #declare T = %g\n",
	  SPECPOWER, ROUGHNESS, DIFFUSE, AMBIENT, TRANSMIT);  
  
#ifdef SLABING
  /* supports hollow slabbing only at the moment! */
  if( UseSlabPlane ) {    
     /*fprintf(stderr,"SlabValue: %d\n", SlabValue);
     fprintf(stderr,"ZOffset: %d\n", ZOffset);
     fprintf(stderr,"MinZ: %d, MaxZ: %d\n", MinZ, MaxZ);
     fprintf(stderr,"DialValue[DialSlab]: %f\n", DialValue[DialSlab]);*/
     fprintf(stderr,"Scale: %f\n", Scale);
     fprintf(stderr,"%f, %f, %f\n"
                    "%f, %f, %f\n"
	            "%f, %f, %f\n", 
	     MatX[0], MatY[0], MatZ[0],
	     MatX[1], MatY[1], MatZ[1],
	     MatX[2], MatY[2], MatZ[2]);
     /* MaxZ+OrigCZ       = absolute outer z-coordinate (most far one)
      * DialValue[DialSlab]*MaxZ = where to put the slab plane (relative to)
      * DialValue[DialSlab] is 0 for slab 50, -0.5 for slab 25 and 0.5 for 
      * slab 75 
      */
     fprintf(OutFile,"   #declare C = difference{\n"
	     "      plane{ z, %d }\n"
	     "      plane{ z, %f }\n"
	     "   }\n",
	     ZOffset+ZOffset, 
	     INVTrans * ( (MaxZ+OrigCZ) - (DialValue[DialSlab]*MaxZ) ) );
  }
#endif

  fprintf(OutFile,"   #include \"%s\"\n",INCname);   

  /*if( !UseShadow )*/
  fputs("   // no_shadow\n",OutFile);
  fputs("   // hollow\n",OutFile);  

  fprintf(OutFile,"   matrix \n"
                  "        < %g,\t%g,\t%g,\n"
                  "          %g,\t%g,\t%g,\n"
                  "          %g,\t%g,\t%g,\n"
	          "          %g,\t%g,\t%g >\n",
          MatX[0],MatY[0],-MatZ[0],
          MatX[1],MatY[1],-MatZ[1],
          -MatX[2],-MatY[2],MatZ[2],
          0.0, 0.0, 0.0);   

  fputs("}\n", OutFile);
		  
}

static void Slab( void )
{   
   if( UseSlabPlane ) 
      fputs("   clipped_by{C}\n", OutFile_inc);
}

static void POVWriteAtoms( void )
{
  
  register Chain __far *chain;
  register Group __far *group;
  register RAtom  __far *aptr;
  
  ForEachAtom {
    if( !(aptr->flag&SphereFlag) )
      continue;
    POVWriteSphere(aptr, aptr->radius);
    /*fputs("sphere\n", stderr);*/
  }

}

static void POVWriteLine( RAtom __far *src, RAtom __far *dst,
                           int rad, Byte flag )
{

  Coord middle;

  if( !(flag&(CylinderFlag|WireFlag|DashFlag) ) ) 
      return;

  middle = POVGetMidCoord(src, dst);
  if( flag&WireFlag)
    rad = MINWIRE;
  else if( flag&DashFlag)
    rad = MINDASH;
  
  fprintf(OutFile_inc,"object {\n"
	  "   cylinder {<%g, %g, %g> <%g, %g, %g> %g}\n",
	  TransX(src->xorg + src->fxorg), 
	  TransY(src->yorg + src->fyorg),
	  TransZ(src->zorg + src->fzorg),
	  middle.x,
	  middle.y,
	  middle.z,
	  TransO(rad));
  POVWriteTexture(POVGetColor((int)src->col));
  Slab();
  fputs("}\n", OutFile_inc);
  
  fprintf(OutFile_inc,"object {\n"
	  "   cylinder {<%g, %g, %g> <%g, %g, %g> %g}\n",
	  middle.x,
	  middle.y,
	  middle.z,
	  TransX(dst->xorg + dst->fxorg), 
	  TransY(dst->yorg + dst->fyorg),
	  TransZ(dst->zorg + dst->fzorg),	    
	  TransO(rad));
  POVWriteTexture(POVGetColor((int)dst->col));
  Slab();
  fputs("}\n", OutFile_inc);
  
  /* add cylinder caps */
  if( !(src->flag&SphereFlag) || (src->flag&SphereFlag && rad > src->radius) )
    POVWriteSphere(src, rad);
  if( !(dst->flag&SphereFlag) || (dst->flag&SphereFlag && rad > dst->radius) )
    POVWriteSphere(dst, rad); 

}
	    

static void POVWriteBonds( void )
{

  register Bond __far *bptr;

  ForEachBond {   
    if( (bptr->flag&DrawBondFlag) )
      POVWriteLine(bptr->srcatom, bptr->dstatom, bptr->radius, bptr->flag);
    /* fprintf(stderr,"zorg: %d\n", bptr->srcatom->zorg); */
  }  
}


static void POVWriteBackBone( void )
{
  register Bond  __far *bptr;
  register Chain __far *chain;

  ForEachBack {
    if( (bptr->flag&DrawBondFlag) )
      POVWriteLine(bptr->srcatom, bptr->dstatom, bptr->radius, bptr->flag);
  }  
 
}
  

static void POVWriteHSBonds( void )
{

  register HBond __far *bptr;

  for( bptr=CurMolecule->hlist; bptr; bptr=bptr->hnext ) {
    if( (bptr->flag&DrawBondFlag) )
      POVWriteLine(bptr->src, bptr->dst, bptr->radius, bptr->flag);
  }

  for( bptr=CurMolecule->slist; bptr; bptr=bptr->hnext ) {
    if( (bptr->flag&DrawBondFlag) )
      POVWriteLine(bptr->src, bptr->dst, bptr->radius, bptr->flag);
  }

}


static void POVWriteDots( void )
{

  register DotStruct __far *ptr;
  register int i;
  RAtom tmp;
  RAtom *atom = &tmp;

  ptr = DotPtr;

#ifdef NOSHADEDOTS
  if( UseShadow && ptr )
    fputs("union {\n",OutFile_inc);  
#endif   
  for( ptr=DotPtr; ptr; ptr=ptr->next ) {
    for( i=0; i<ptr->count; i++ ){ 
      tmp.xorg = ptr->xpos[i] ;
      tmp.yorg = ptr->ypos[i] ;
      tmp.zorg = ptr->zpos[i] ;
      tmp.col  = ptr->col[i]  ;
      tmp.fxorg = 0;
      tmp.fyorg = 0;
      tmp.fzorg = 0;
      atom     = &tmp         ;
      POVWriteSphere(atom, DOTFACTOR/(double)DotPtr->count);    
    }
  }
#ifdef NOSHADEDOTS
  if( UseShadow && ptr ) {
    fputs("no_shadow\n",OutFile_inc);
    fputs("}\n",OutFile_inc);
  }
#endif  

}


int WritePOVRay3File( char *name )
{

  if( strlen(name) > (MAXNAME-5) ) {
     FatalScriptError(name);
     return(False);
  }
  
  strcpy(POVname, name);
  strcpy(INCname, name);
  strcat(POVname, ".pov");
  strcat(INCname, ".inc");
  
  if( !Database )
    return True;
  
  OutFile = fopen(POVname,"w");
  if( !OutFile ){
    FatalScriptError(POVname);
    return False;
  }

  OutFile_inc = fopen(INCname,"w");
  if( !OutFile ){
    FatalScriptError(INCname);
    return False;
  }
  
  fprintf(OutFile,"// File: %s\n",POVname);
  fprintf(OutFile,"// Creator: RasMol Version %s\n", VERSION);
  fputs("// Version: POV-Ray Version 3\n",OutFile);
  fprintf(OutFile,"// Needs objectfile \"%s\"\n\n",INCname);
  
  fprintf(OutFile_inc,"// File: %s\n",INCname);
  fprintf(OutFile_inc,"// Creator: RasMol Version %s\n", VERSION);
  fputs("// Version: POV-Ray Version 3\n",OutFile_inc);
  fputs("// Objects for POV-Ray Version 3\n\n",OutFile_inc);
              
  POVWriteHeader();
  POVWriteAtoms();
  POVWriteBonds();
  POVWriteBackBone();
  POVWriteHSBonds();
  POVWriteDots();

  /*
  printf("XOffset = %g\t WRange = %g\t YOffset = %g\t HRange = %g\n"
	 "XRange  = %g\t YRange = %g\t\n",
	 (double)XOffset, (double)WRange, (double)YOffset, (double)HRange,
	 (double)XRange, (double)YRange);
    */

  fclose(OutFile);
  fclose(OutFile_inc);
#ifdef APPLEMAC
  SetFileInfo(name,'ttxt','TEXT',133);
#endif
  return True;
}

