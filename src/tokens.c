/***************************************************************************
 *                             RasMol 2.7.4.2                              *
 *                                                                         *
 *                                 RasMol                                  *
 *                 Molecular Graphics Visualisation Tool                   *
 *                            19 November 2007                             *
 *                          (rev. 21 March 2008)                           *
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
 *                                                                         *
 * RasMol 2.7.3 incorporates changes by Clarice Chigbo, Ricky Chachra,     *
 * and Mamoru Yamanishi.  Work on RasMol 2.7.3 supported in part by        *
 * grants DBI-0203064, DBI-0315281 and EF-0312612 from the U.S. National   *
 * Science Foundation and grant DE-FG02-03ER63601 from the U.S. Department *
 * of Energy.  RasMol 2.7.4 incorporates changes by G. Todorov, Nan Jia,   *
 * N. Darakev, P. Kamburov, G. McQuillan, J. Jemilawon.  Work on RasMol    *
 * 2.7.4 supported in part by grant 1R15GM078077-01 from the National      *
 * Institute of General Medical Sciences (NIGMS). The content is solely    *
 * the responsibility of the authors and does not necessarily represent    * 
 * the official views of the funding organizations.                        *
 *                                                                         *
 * The code for use of RasMol under GTK in RasMol 2.7.4.2 was written by   *
 * Teemu  Ikonen.                                                          *
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
/* tokens.c
 $Log$
 Revision 1.17  2008/06/19 19:03:39  yaya
 Fix missing } -- HJB

 Revision 1.16  2008/06/19 18:54:26  yaya
 Fix missing } -- HJB

 Revision 1.15  2008/06/19 18:50:51  yaya
 Fix some missing ;'s -- HJB

 Revision 1.14  2008/06/18 20:04:53  yaya
 Start in infrastructure for animation
 Start on WPDB code -- HJB

 Revision 1.13  2008/03/22 18:42:55  yaya
 Post release cleanup and credit to Ikonen in file headers. -- HJB

 Revision 1.12  2008/03/17 03:01:31  yaya
 Update to agree with 2.7.4.2 release and T. Ikonen GTK mods -- HJB

 Revision 1.3  2008/03/17 01:32:41  yaya
 Add gtk mods by tpikonen, and intergate with 2.7.4.2 mods -- HJB

 Revision 1.11  2008/03/16 22:25:22  yaya
 Align comments with production version; Update rasmol_install and
 rasmol_run shell scripts for Japanese and Chinese; Align logic for
 positioning and sizing initial window with windows version -- HJB

 Revision 1.2  2008/01/28 03:29:38  yaya
 Update CVS to RasMol_2.7.4.1 -- HJB

 Revision 1.10  2007/12/06 18:47:10  hk0i
 added NoToggle and ColourMode commands + messages (translations needed), README for lang files, script to generate all langsel files (uses previous scripts).

 Revision 1.9  2007/11/19 03:28:40  yaya
 Update to credits for 2.7.4 in manual and headers
 Mask code added -- HJB

 Revision 1.8  2007/11/13 03:22:17  yaya
 Changes to support map selectors.  Needs more work. -- HJB

 Revision 1.7  2007/09/06 12:11:26  yaya
 Changes for map resolution -- HJB

 Revision 1.6  2007/09/03 14:25:10  yaya
 Upload of more of the map load and map generate commands -- HJB

 Revision 1.5  2007/08/03 02:02:34  yaya
 Add MEAN to map level command, and move the various map settings
 under the map command, and set the defaults to make a nice map
 on a default generate (spread .1667, level mean, spacing .5) -- HJB

 Revision 1.4  2007/07/09 13:57:06  yaya
 Add spacing and spread commands -- HJB

 Revision 1.3  2007/07/07 21:54:31  yaya
 Next round of preliminary updates for maps, allowing multiple maps,
 code to set the contour level and some fixes to the languages files -- HJB

 Revision 1.2  2007/07/02 12:44:39  yaya
 Partial preliminary map code -- HJB

 Revision 1.1.1.1  2007/03/01 01:16:33  todorovg
 Chinese working versio from rasmol_ru initial import

 Revision 1.4  2006/11/28 03:12:48  yaya
 Changes for Russian and About dialog in unix
 This is a variant tried under Mac OS X.  Changes
 for Linux still needed.  note that more work is
 needed on font selection. -- HJB

 Revision 1.3  2006/11/01 03:23:51  yaya
 Update NSIS windows installer for more script types and to fix
 misplaced script instructions for data files; add document and
 script icons directly in raswin.exe; add credit line to
 G. A. Pozhvanov in comments for Russian translations. -- HJB

 Revision 1.2  2006/09/17 10:53:56  yaya
 Clean up headers and start on code for X11 -- HJB

 Revision 1.1.1.1  2006/09/16 18:46:01  yaya
 Start of RasMol Russian Translation Project based on translations
 by Gregory A. Pozhvanov of Saint Petersburg State University -- HJB

 Revision 1.1.1.1  2006/06/19 22:05:14  todorovg
 Initial Rasmol 2.7.3 Import

 Revision 1.2  2004/09/29 22:39:14  chigboc
 *** empty log message ***

 Revision 1.1  2004/05/07 19:46:16  yaya
 Initial revision

 Revision 1.2  2004/02/15 00:24:00  yaya
 *** empty log message ***

 Revision 1.1  2003/12/12 21:10:38  yaya
 Initial revision

 Revision 1.2  2001/02/06 21:58:18  yaya
 *** empty log message ***

 Revision 1.1  2001/01/31 02:13:45  yaya
 Initial revision

 Revision 1.4  2000/08/26 18:12:46  yaya
 Updates to header comments in all files

 Revision 1.3  2000/08/21 21:07:50  yaya
 semi-final ucb mods

 Revision 1.2  2000/08/09 01:18:18  yaya
 Rough cut with ucb

 */
#include <string.h>
#include <ctype.h>

#include "tokens.h"

int LookUpKeyword( char *ptr )
{
    switch(*ptr++) {
      /*
        ACIDIC               AcidTok
        ACYCLIC              AcyclicTok 
        ALCHEMY              AlchemyTok
        ALIPHATIC            AliphaticTok
        ALL                  AllTok 
        ALPHA                AlphaTok
        ALT                  AltlTok
        AMBIENT              AmbientTok
        AMINO                AminoTok
        AND                  AndTok
        ANGLE                AngleTok
        ANGLES               AngleTok
        ANIM                 AnimateTok
        ANIMATE              AnimateTok
             APPEARANCE           AppearanceTok
             APS                  APSTok
        AROMATIC             AromaticTok
             ASPECT               AppearanceTok
        ASSE                 AxesTok
        ASSI                 AxesTok
        AT                   ATTok
        ATOM                 AtomTok
        ATOMNO               AtomNoTok
        ATOMNUMBER           AtomNoTok
        ATOMS                AtomTok
        AXES                 AxesTok
        AXIS                 AxesTok
        AVERAGE              MeanTok
      */
        case('A'):
            switch(*ptr++) {
                case('C'):
                    if( !strcmp(ptr,"IDIC") ) {
                        return( AcidicTok );
                    } else if( !strcmp(ptr,"YCLIC") ) {
                        return( AcyclicTok );
                    }
                    break;

                case('L'):
                    if( !strcmp(ptr,"CHEMY") ) {
                        return( AlchemyTok );
                    } else if( !strcmp(ptr,"IPHATIC") ) {
                        return( AliphaticTok );
                    } else if( (*ptr=='L') && !ptr[1] ) {
                        return( AllTok );
                    } else if( (*ptr=='T') && !ptr[1] ) {
                        return( AltlTok );
                    } else if( !strcmp(ptr,"PHA") ) {
                        return( AlphaTok );
                    }
                    break;

                case('M'):
                    if( !strcmp(ptr,"BIENT") ) {
                        return( AmbientTok );
                    } else if( !strcmp(ptr,"INO") ) {
                        return( AminoTok );
                    }
                    break;

                case('N'):
                    if( (*ptr=='D') && !ptr[1] ) {
                        return( AndTok );
                    } else if( !strcmp(ptr,"GLE") ) {
                        return( AngleTok );
                    } else if( !strcmp(ptr,"GLES") ) {
                        return( AngleTok );
                    } else if (!strcmp(ptr,"IMATE") ||  !strcmp(ptr,"IM") ) {
                        return( AnimateTok);
                    }
                    break;

                case('P'):
                    if( !strcmp(ptr,"PEARANCE") ) {
                    	return( AppearanceTok );
                    } else if( (*ptr=='S') && !ptr[1] ) {
                        return( APSTok );
                    }
                    break;
                    
                case('R'):
                    if( !strcmp(ptr,"OMATIC") ) {
                        return( AromaticTok );
                    }
                    break;

                 case('S'):
                    if( !strcmp(ptr,"SE") || !strcmp(ptr,"SI")) {
                        return( AxesTok );
                    } else if ( !strcmp(ptr,"PECT") ) {
                    	return( AppearanceTok);
                    }
                    break;

               case('T'):
                    if( !*ptr ) {
                        return( ATTok );
                    } else if( !strcmp(ptr,"OM") ) {
                        return( AtomTok );
                    } else if( !strcmp(ptr,"OMNO") ) {
                        return( AtomNoTok );
                    } else if( !strcmp(ptr,"OMNUMBER") ) {
                        return( AtomNoTok );
                    } else if( !strcmp(ptr,"OMS") ) {
                        return( AtomTok );
                    }
                    break;

                case('X'):
                    if( !strcmp(ptr,"ES") ) {
                        return( AxesTok );
                    } else if( !strcmp(ptr,"IS") ) {
                        return( AxesTok );
                    }
                    break;
                    
            	case('V'):
            	    if( !strcmp(ptr,"ERAGE") )  {
            	        return( MeanTok );
                    }
                    break;

            }
            break;

      /*
        BACKBONE             BackboneTok
        BACKFADE             BackFadeTok
        BACKGROUND           BackgroundTok
        BASIC                BasicTok
        BIOSYM               BiosymTok
        BLACK                BlackTok
        BLUE                 BlueTok
        BLUETINT             BlueTintTok
        BMP                  BMPTok
        BOND                 BondTok
        BONDED               BondedTok
        BONDMODE             BondModeTok
        BONDS                BondTok
        BOUNDBOX             BoundBoxTok
        BOUNDINGBOX          BoundBoxTok
        BROWN                BrownTok
        BURIED               BuriedTok
      */

        case('B'):
            switch(*ptr++) {
                case('A'):
                    if( !strcmp(ptr,"CKBONE") ) {
                        return( BackboneTok );
                    } else if( !strcmp(ptr,"CKFADE") ) {
                        return( BackFadeTok );
                    } else if( !strcmp(ptr,"CKGROUND") ) {
                        return( BackgroundTok );
                    } else if( !strcmp(ptr,"SIC") ) {
                        return( BasicTok );
                    }
                    break;

                case('I'):
                    if( !strcmp(ptr,"OSYM") ) {
                        return( BiosymTok );
                    }
                    break;

                case('L'):
                    if( !strcmp(ptr,"ACK") ) {
                        return( BlackTok );
                    } else if( !strcmp(ptr,"UE") ) {
                        return( BlueTok );
                    } else if( !strcmp(ptr,"UETINT") ) {
                        return( BlueTintTok );
                    }
                    break;

                case('M'):
                    if( (*ptr=='P') && !ptr[1] ) {
                        return( BMPTok );
                    }
                    break;

                case('O'):
                    if( !strcmp(ptr,"ND") ) {
                        return( BondTok );
                    } else if( !strcmp(ptr,"NDED") ) {
                        return( BondedTok );
                    } else if( !strcmp(ptr,"NDMODE") ) {
                        return( BondModeTok );
                    } else if( !strcmp(ptr,"NDS") ) {
                        return( BondTok );
                    } else if( !strcmp(ptr,"UNDBOX") ) {
                        return( BoundBoxTok );
                    } else if( !strcmp(ptr,"UNDINGBOX") ) {
                        return( BoundBoxTok );
                    }
                    break;

                case('R'):
                    if( !strcmp(ptr,"OWN") ) {
                        return( BrownTok );
                    }
                    break;

                case('U'):
                    if( !strcmp(ptr,"RIED") ) {
                        return( BuriedTok );
                    } else if ( !strcmp(ptr,"LGARIAN") ) {
			    return ( BulgarianTok );
		    }
                    break;

            }
            break;

      /*
        CADENA               ChainTok
        CADENAS              ChainTok
        CARTOON              CartoonTok
        CARTOONS             CartoonTok
        CATENA               ChainTok
        CATENE               ChainTok
        CENTER               CentreTok
        CENTRE               CentreTok
        CEX                  CEXTok
        CG                   CGTok
        CHAIN                ChainTok
        CHAINS               ChainTok
        CHARGE               ChargeTok
        CHARGED              ChargedTok
        CHARGES              ChargeTok
        CHARMM               CharmmTok
        CHINESE              ChineseTok
        CIF                  CIFTok
        CISANGLE             CisAngleTok
        CISBONDED            CisBondedTok
        CLIPBOARD            ClipboardTok
        COLOR                ColourTok
		COLORMODE            ColourModeTok
        COLORS               ColourTok
        COLOUR               ColourTok
		COLOURMODE           ColourModeTok
        COLOURS              ColourTok
        CONNECT              ConnectTok
        CONTOUR              ContourTok (LevelTok)
        COORDINATE           CoordTok
        COORDINATES          CoordTok
        COORD                CoordTok
        COORDS               CoordTok
        COPY                 CopyTok
        CPK                  CPKTok
        CPKNEW               CpkNewTok
        CYAN                 CyanTok
        CYCLIC               CyclicTok
        CYSTINE              CystineTok
      */

        case('C'):
            switch(*ptr++) {
                case('A'):
                    if( !strcmp(ptr,"DENA") || !strcmp(ptr,"DENAS")) {
                        return( ChainTok );
                    } else if( !strcmp(ptr,"RTOON") ) {
                        return( CartoonTok );
                    } else if( !strcmp(ptr,"RTOONS") ) {
                        return( CartoonTok );
                    } else if( !strcmp(ptr,"TENA") || !strcmp(ptr,"TENE")) {
                        return( ChainTok );
                    }
                    break;

                case('E'):
                    if( !strcmp(ptr,"NTER") ) {
                        return( CentreTok );
                    } else if( !strcmp(ptr,"NTRE") ) {
                        return( CentreTok );
                    } else if( (*ptr=='X') && !ptr[1] ) {
                        return( CEXTok );
                    }
                    break;

                case('G'):
                    if( !*ptr ) {
                        return( CGTok );
                    }
                    break;

                case('H'):
                    if( !strcmp(ptr,"AIN") ) {
                        return( ChainTok );
                    } else if( !strcmp(ptr,"AINS") ) {
                        return( ChainTok );
                    } else if( !strcmp(ptr,"ARGE") ) {
                        return( ChargeTok );
                    } else if( !strcmp(ptr,"ARGED") ) {
                        return( ChargedTok );
                    } else if( !strcmp(ptr,"ARGES") ) {
                        return( ChargeTok );
                    } else if( !strcmp(ptr,"ARMM") ) {
                        return( CharmmTok );
                    } else if( !strcmp(ptr,"INESE") ) {
                        return( ChineseTok );
                    }
                    break;

                case('I'):
                    if( (*ptr=='F') && !ptr[1] ) {
                        return( CIFTok );
                    } else if ( !strcmp(ptr,"SANGLE") ) {
                        return( CisAngleTok );
                    } else if ( !strcmp(ptr,"SBONDED") ) {
                        return( CisBondedTok );
                    }
                    break;

                case('L'):
                    if( !strcmp(ptr,"IPBOARD") ) {
                        return( ClipboardTok );
                    }
                    break;

                case('O'):
                    if( !strcmp(ptr,"LOR") ) {
                        return( ColourTok );
					} else if( !strcmp(ptr,"LORMODE") ) {
						return( ColourModeTok );
                    } else if( !strcmp(ptr,"LORS") ) {
                        return( ColourTok );
                    } else if( !strcmp(ptr,"LOUR") ) {
                        return( ColourTok );
					} else if( !strcmp(ptr,"LOURMODE") ) {
						return( ColourModeTok );
                    } else if( !strcmp(ptr,"LOURS") ) {
                        return( ColourTok );
                    } else if( !strcmp(ptr,"NNECT") ) {
                        return( ConnectTok );
                    } else if( !strcmp(ptr,"NTOUR") ) {
                        return( ContourTok );
                    } else if( !strcmp(ptr,"ORDINATE") ) {
                        return( CoordTok );
                    } else if( !strcmp(ptr,"ORDINATES") ) {
                        return( CoordTok );
                    } else if( !strcmp(ptr,"ORD") ) {
                        return( CoordTok );
                    } else if( !strcmp(ptr,"ORDS") ) {
                        return( CoordTok );
                    } else if( !strcmp(ptr,"PY") ) {
                        return( CopyTok );
                    }
                    break;

                case('P'):
                    if( (*ptr=='K') && !ptr[1] ) {
                        return( CPKTok );
                    } else if( !strcmp(ptr,"KNEW") ) {
                      return( CpkNewTok );
                    }
                    break;

                case('Y'):
                    if( !strcmp(ptr,"AN") ) {
                        return( CyanTok );
                    } else if( !strcmp(ptr,"CLIC") ) {
                        return( CyclicTok );
                    } else if( !strcmp(ptr,"STINE") ) {
                        return( CystineTok );
                    }
                    break;

            }
            break;


      /*
        DASH                 DashTok
        DASHES               DashTok
        DATA_...             CIFDataTok
             DEFER                DeferTok
        DEFINE               DefineTok
		DEPTH                DepthTok
        DEPTHCUE             DepthCueTok
        DIBUJO               CartoonTok
        DIBUJOS              CartoonTok
        DISPLAY              DisplayTok
        DISTANCE             DistanceTok
        DISTANCES            DistanceTok
        DNA                  DNATok
        DOTS                 DotsTok
        DOWN                 DownTok
             DWELL                DwellTok
      */

        case('D'):
            switch(*ptr++) {
                case('A'):
                    if( !strcmp(ptr,"SH") ) {
                        return( DashTok );
                    } else if( !strcmp(ptr,"SHES") ) {
                        return( DashTok );
                    } else if( !strncmp(ptr, "TA_", 3) ) {
                        return( CIFDataTok );
                    }
                    break;

                case('E'):
                    if( !strcmp(ptr,"FER") ) {
                        return( DeferTok );
                    } else if( !strcmp(ptr,"FINE") ) {
                        return( DefineTok );
                    } else if( !strcmp(ptr,"PTH") ) {
                        return( DepthTok );
                    } else if( !strcmp(ptr,"PTHCUE") ) {
                        return( DepthCueTok );
                    }
                    break;

                case('I'):
                    if( !strcmp(ptr,"BUJO") || !strcmp(ptr,"BUJOS") ) {
                        return( CartoonTok );
                    } else if( !strcmp(ptr,"SPLAY") ) {
                        return( DisplayTok );
                    } else if( !strcmp(ptr,"STANCE") ) {
                        return( DistanceTok );
                    } else if( !strcmp(ptr,"STANCES") ) {
                        return( DistanceTok );
                    }
                    break;

                case('N'):
                    if( (*ptr=='A') && !ptr[1] ) {
                        return( DNATok );
                    }
                    break;

                case('O'):
                    if( !strcmp(ptr,"TS") ) {
                        return( DotsTok );
                    } else if( !strcmp(ptr,"WN") ) {
                        return( DownTok );
                    }
                    break;
                    
                case('W'):
                    if( !strcmp(ptr,"ELL") ) {
                        return( DwellTok );
                    }
                    

            }
            break;

      /*
        E                    AndTok
        ECHO                 EchoTok
        EJE                  AxesTok
             EJECT                EjectTok
        EJES                 AxesTok
        ELANCE               BondTok
        ELANCES              BondTok
        ELEMNO               ElemNoTok
        ELEMENTNUMBER        ElemNoTok
        ELICHE               HelixTok
        ENGLISH              EnglishTok
        EPSF                 EPSFTok
        ELICHE               HelixTok
        ESQUELETO            BackboneTok
        ETIQUETA             LabelTok
        ETIQUETAS            LabelTok
        ETICHETTA            LabelTok
        ETICHETTE            LabelTok  
             EXECUTE              ExecuteTok
        EXIT                 ExitTok
      */

        case('E'):
            switch(*ptr++) {
                case('\0'):
                    return( AndTok );
                    break;

                case('C'):
                    if( !strcmp(ptr,"HO") ) {
                        return( EchoTok );
                    }
                    break;

                case('J'):
                    if( *ptr=='E' && (!ptr[1] || ptr[1]=='S')) {
                        return( AxesTok );
                    } else if ( !strcmp(ptr,"ECT") ) {
                        return( EjectTok);
                    }
                    break;
 
                case('L'):
                    if( !strcmp(ptr,"ANCE") || !strcmp(ptr,"ANCES" ) ) {
                        return( BondTok );
                    } else if( !strcmp(ptr,"EMNO") ) {
                        return( ElemNoTok );
                    } else if( !strcmp(ptr,"EMENTNUMBER") ) {
                        return( ElemNoTok );
                     } else if( !strcmp(ptr,"ICHE") ) {
                        return( HelixTok );
                   }
                    break;

                case('N'):
                    if( !strcmp(ptr,"GLISH") ) {
                        return( EnglishTok );
                    }
                    break;

                case('P'):
                    if( !strcmp(ptr,"SF") ) {
                        return( EPSFTok );
                    }
                    break;

                case('S'):
                    if( !strcmp(ptr,"QUELETO") ) {
                        return( BackboneTok );
                    } else if( !strcmp(ptr,"CI") ) {
                        return( ExitTok );
                    }
                    break;

                case('T'):
                    if( !strcmp(ptr,"IQUETA") || !strcmp(ptr,"IQUETAS") ) {
                        return( LabelTok );
                    } else if( !strcmp(ptr,"ICHETTA") || !strcmp(ptr,"ICHETTE") ) {
                        return( LabelTok );
                    }
                    break;

                case('X'):
                    if( !strcmp(ptr,"ECUTE") ) {
                        return( ExecuteTok );
                    } else if( !strcmp(ptr,"IT") ) {
                        return( ExitTok );
                    }
                    break;

            }
            break;

      /*
        FALSE                FalseTok
        FDAT                 FDATTok
        FILODIFERRO          WireframeTok
        FILDIFERRO           WireframeTok
        FILI                 StrandsTok  
        FONTSIZE             FontSizeTok
        FONTSTROKE           FontStrokeTok
             FPS                  FPSTok
        FRAMES               FramesTok
        FRENCH               FrenchTok
             FROM                 FromTok
        FS                   FSTok
      */

        case('F'):
            switch(*ptr++) {
                case('A'):
                    if( !strcmp(ptr,"LSE") ) {
                        return( FalseTok );
                    }
                    break;

                case('D'):
                    if( !strcmp(ptr,"AT") ) {
                        return( FDATTok );
                    }
                    break;

                case('I'):
                	if( !strcmp(ptr,"LODIFERRO") || !strcmp(ptr,"LDIFERRO")) {
                        return( WireframeTok );
                    } else if( !strcmp(ptr,"LI") ) {
                        return( StrandsTok );
                    }
                    break;

                case('O'):
                    if( !strcmp(ptr,"NTSIZE") ) {
                        return( FontSizeTok );
                    } else if( !strcmp(ptr,"NTSTROKE") ) {
                        return( FontStrokeTok );
                    }
                    break;
                
                case('P'):
                    if( !strcmp(ptr,"S") ) {
                        return( FPSTok );
                    }
                    break;

                
                case('R'):
                    if( !strcmp(ptr,"AMES") ) {
                        return( FramesTok );
                    } else if( !strcmp(ptr,"ENCH") ) {
                        return( FrenchTok );
                    } else if( !strcmp(ptr,"OM") ) {
                        return( FromTok );
                    }
                    break;

                case('S'):
                    if( !ptr[0] ) {
                        return( FSTok );
                    }
                    break;

            }
            break;

      /*
        GAUSSIAN             GaussianTok
        GENERATE             GenerateTok   
        GIF                  GIFTok
        GIRO                 TurnTok
        GIROS                TurnTok
        GOLD                 GoldTok
        GRAY                 GrayTok
        GREEN                GreenTok
        GREENBLUE            GreenBlueTok
        GREENTINT            GreenTintTok
        GREY                 GrayTok
        GROUP                GroupTok
        GRUPO                GroupTok
        GRUPPO               GroupTok 
      */

        case('G'):
            switch(*ptr++) {
                case('A'):
                    if( !strcmp(ptr,"USSIAN") ) {
                        return( GaussianTok );
                    }
                    break;

                case('E'):
                    if( !strcmp(ptr,"NERATE") ) {
                        return( GenerateTok );
                    }
                    break;

                case('I'):
                    if( !strcmp(ptr,"RO") || !strcmp(ptr,"ROS") ) {
                        return( TurnTok );
                    } else if( (*ptr=='F') && !ptr[1] ) {
                        return( GIFTok );
                    }
                    break;

                case('O'):
                    if( !strcmp(ptr,"LD") ) {
                        return( GoldTok );
                    }
                    break;

                case('R'):
                    if( !strcmp(ptr,"AY") ) {
                        return( GrayTok );
                    } else if( !strcmp(ptr,"EEN") ) {
                        return( GreenTok );
                    } else if( !strcmp(ptr,"EENBLUE") ) {
                        return( GreenBlueTok );
                    } else if( !strcmp(ptr,"EENTINT") ) {
                        return( GreenTintTok );
                    } else if( !strcmp(ptr,"EY") ) {
                        return( GrayTok );
                    } else if( !strcmp(ptr,"OUP") || !strcmp(ptr,"UPO") ) {
                        return( GroupTok );
                     } else if( !strcmp(ptr,"UPPO") ) {
                        return( GroupTok );
                   }
                    break;

            }
            break;

      /*
        HALF                 HalfTok
        HARDWARE             HardwareTok
        HBOND                HBondTok
        HBONDS               HBondTok
        HEADER               HeaderTok
        HEBRAS               StrandsTok
        HELICES              HelixTok
        HELIX                HelixTok
        HELP                 HelpTok
        HETERO               HeteroTok
        HOLLOW               HollowTok
        HOTPINK              HotPinkTok
        HOURGLASS            HourGlassTok
        HYDROGEN             HydrogenTok
        HYDROPHOBIC          HydrophobicTok
      */

        case('H'):
            switch(*ptr++) {
                case('A'):
                    if( !strcmp(ptr,"LF") ) {
                        return( HalfTok );
                    } else if( !strcmp(ptr,"RDWARE") ) {
                        return( HardwareTok );
                    }
                    break;

                case('B'):
                    if( !strcmp(ptr,"OND") ) {
                        return( HBondTok );
                    } else if( !strcmp(ptr,"ONDS") ) {
                        return( HBondTok );
                    }
                    break;

                case('E'):
	  	    if( !strcmp(ptr,"ADER") ) {
                        return( HeaderTok );
                    } else if( !strcmp(ptr,"BRAS") ) {
                        return( StrandsTok );
                    } else if( !strcmp(ptr,"LICES") ) {
                        return( HelixTok );
                    } else if( !strcmp(ptr,"LIX") ) {
                        return( HelixTok );
                    } else if( !strcmp(ptr,"LP") ) {
                        return( HelpTok );
                    } else if( !strcmp(ptr,"TERO") ) {
                        return( HeteroTok );
                    }
                    break;

                case('O'):
                    if( !strcmp(ptr,"LLOW") ) {
                        return( HollowTok );
                    } else if( !strcmp(ptr,"TPINK") ) {
                        return( HotPinkTok );
                    } else if( !strcmp(ptr,"URGLASS") ) {
                        return( HourGlassTok );
                    }
                    break;

                case('Y'):
                    if( !strcmp(ptr,"DROGEN") ) {
                        return( HydrogenTok );
                    } else if( !strcmp(ptr,"DROPHOBIC") ) {
                        return( HydrophobicTok );
                    }
                    break;

            }
            break;

      /*
        IDENT                IdentifyTok
        IDENTIFY             IdentifyTok
		IMAGE				 ImageTok
		IN                   InTok
        INFO                 InfoTok
        INFORMATION          InfoTok
        INLINE               InLineTok
        INSIGHT              InsightTok
        ION                  IonTok
        IONS                 IonTok
        IRIS                 IRISTok
        ITALIAN              ItalianTok
      */

        case('I'):
            switch(*ptr++) {
                case('D'):
                    if( !strcmp(ptr,"ENT") ) {
                        return( IdentifyTok );
                    } else if( !strcmp(ptr,"ENTIFY") ) {
                        return( IdentifyTok );
                    }
                    break;

                case('M'):
                    if( !strcmp(ptr,"AGE") )
                        return( ImageTok );
					break;

                case('N'):
                    if( !*ptr ) {
                    	return( InTok );
                    } else if( !strcmp(ptr,"FO") ) {
                        return( InfoTok );
                    } else if( !strcmp(ptr,"FORMATION") ) {
                        return( InfoTok );
                    } else if( !strcmp(ptr,"LINE") ) {
                        return( InLineTok );
                    } else if( !strcmp(ptr,"SIGHT") ) {
                        return( InsightTok );
                    }
                    break;

                case('O'):
                    if( (*ptr=='N') && !ptr[1] ) {
                        return( IonTok );
                    } else if( !strcmp(ptr,"NS") ) {
                        return( IonTok );
                    }
                    break;

                case('R'):
                    if( !strcmp(ptr,"IS") ) {
                        return( IRISTok );
                    }
                    break;

                case('T'):
                    if( !strcmp(ptr,"ALIAN") ) {
                        return( ItalianTok );
                    }
                    break;

            }
            break;

      /*
        JAPANESE             JAPANESETok
        JPEG                 JPEGTok
      */

        case('J'):
            if( !strcmp(ptr,"PEG") ) {
                return( JPEGTok );
            } else if( !strcmp(ptr,"APANESE") ) {
                return( JapaneseTok );
            }
            break;

      /*
        KINEMAGE             KinemageTok
      */

        case('K'):
            if( !strcmp(ptr,"INEMAGE") ) {
                return( KinemageTok );
            }
            break;

      /*
        LABEL                LabelTok
        LABELS               LabelTok
        LARGE                LargeTok
        LEFT                 LeftTok
        LEVEL                LevelTok (ContourTok)
        LEERICHARDS          MolSurfTok
        LH                   LeftTok
        LIGAND               LigandTok
        LIGANDS              LigandTok
        LOAD                 LoadTok
        LRSURF               MolSurfTok
      */

        case('L'):
            switch(*ptr++) {
                case('A'):
                    if( !strcmp(ptr,"BEL") ) {
                        return( LabelTok );
                    } else if( !strcmp(ptr,"BELS") ) {
                        return( LabelTok );
                    } else if( !strcmp(ptr,"RGE") ) {
                        return( LargeTok );
                    }
                    break;
                    
            	case('E'):
            	    if( !strcmp(ptr,"ERCHARDS") ){
            	        return( MolSurfTok);
            	    } else if( !strcmp(ptr,"VEL") ){
            	        return( LevelTok);
            	    } else if( !strcmp(ptr,"FT") ) {
                        return( LeftTok );
                    }
            	    break;

                case('H'):
                    if( !*ptr ) {
                        return( LeftTok );
            	    }
            	    break;


                case('I'):
                    if( !strcmp(ptr,"GAND") ) {
                        return( LigandTok );
                    } else if( !strcmp(ptr,"GANDS") ) {
                        return( LigandTok );
                    }
                    break;

                case('O'):
                    if( !strcmp(ptr,"AD") ) {
                        return( LoadTok );
                    }
                    break;

                case('R'):
                    if( !strcmp(ptr,"SURF") ) {
                        return( MolSurfTok );
                    }
                    break;
                    
            }
            break;

      /*
        MACROMODEL           MacroModelTok
        MAGENTA              MagentaTok
        MAINCHAIN            MainChainTok
        MAP                  MapTok
        MASK                 MaskTok
        MDL                  MDLTok
        MEAN                 MeanTok
        MEDIUM               MediumTok
        MENUS                MenusTok
        MESH                 WireframeTok
        MIRROR               MirrorTok
        MMDB                 MMDBTok
        MODEL                ModelTok
        MOL2                 Mol2Tok
        MOLECULE             MoleculeTok
        MOLSCRIPT            MolScriptTok
        MOLSURF	             MolSurfTok
        MONITOR              MonitorTok
        MONITORS             MonitorTok
        MONO                 MonoTok
        MONOCHROME           MonoTok
        MONOPS               MonoPSTok
        MOPAC                MOPACTok
        MOSTRAR              DisplayTok
             MOTION               MotionTok
        MOUSE                MouseTok
        MOUSEMODE            MouseTok
        MOVE                 MoveTok
             MOVEMENT             MotionTok
        MOVETO               MoveToTok
      */

        case('M'):
            switch(*ptr++) {
                case('A'):
                    if( !strcmp(ptr,"CROMODEL") ) {
                        return( MacroModelTok );
                    } else if( !strcmp(ptr,"GENTA") ) {
                        return( MagentaTok );
                    } else if( !strcmp(ptr,"INCHAIN") ) {
                        return( MainChainTok );
                    } else if( !strcmp(ptr,"P") ) {
                        return( MapTok );
                    } else if( !strcmp(ptr,"SK") ) {
                        return( MaskTok );
                    }
                    break;

                case('D'):
                    if( (*ptr=='L') && !ptr[1] ) {
                        return( MDLTok );
                    }
                    break;

                case('E'):
                    if( !strcmp(ptr,"AN") ) {
                        return( MeanTok );
                    } else if( !strcmp(ptr,"DIUM") ) {
                        return( MediumTok );
                    } else if( !strcmp(ptr,"NUS") ) {
                        return( MenusTok );
                    } else if( !strcmp(ptr,"SH") ) {
                    	return( WireframeTok );
                    }
                    break;

                case('I'):
                    if( !strcmp(ptr,"RROR") ) {
                        return( MirrorTok );
                    }
                    break;

                case('M'):
                    if( !strcmp(ptr,"DB") ) {
                        return( MMDBTok );
                    }
                    break;

                case('O'):
                    if( !strcmp(ptr,"DEL") ) {
                        return( ModelTok );
                    } else if( !strcmp(ptr,"L2") ) {
                        return( Mol2Tok );
                    } else if( !strcmp(ptr,"LECULE") ) {
		                return( MoleculeTok );
                    } else if( !strcmp(ptr,"LSCRIPT") ) {
                        return( MolScriptTok );
                    } else if( !strcmp(ptr,"LSURF") ) {
                        return( MolSurfTok );
                    } else if( !strcmp(ptr,"NITOR") ) {
                        return( MonitorTok );
                    } else if( !strcmp(ptr,"NITORS") ) {
                        return( MonitorTok );
                    } else if( !strcmp(ptr,"NO") ) {
                        return( MonoTok );
                    } else if( !strcmp(ptr,"NOCHROME") ) {
                        return( MonoTok );
                    } else if( !strcmp(ptr,"NOPS") ) {
                        return( MonoPSTok );
                    } else if( !strcmp(ptr,"PAC") ) {
                        return( MOPACTok );
                    } else if( !strcmp(ptr,"STRAR") ) {
                        return( DisplayTok );
                    } else if( !strcmp(ptr,"TION") ) {
                        return( MotionTok );
                    } else if( !strcmp(ptr,"USE") ) {
                        return( MouseTok );
                    } else if( !strcmp(ptr,"USEMODE") ) {
                        return( MouseTok );
                    } else if( !strcmp(ptr,"MOVE") ) {
                        return( MoveTok );
                    } else if( !strcmp(ptr,"MOVEMENT") ) {
                        return( MotionTok );
                    } else if( !strcmp(ptr,"MOVETO") ) {
                        return( MoveToTok );
                    }
                    break;

            }
            break;

      /*
        NASTRO               RibbonTok 
        NASTRI               RibbonTok 
        NEGATIVE             AcidicTok
        NEW                  NewTok
        NEUTRAL              NeutralTok
        NEXT                 NextTok
        NMRPDB               NMRPDBTok
        NONE                 NoneTok
        NORMAL               NormalTok
        NOT                  NotTok
		NOTOGGLE             NoToggleTok
        NUCLEIC              NucleicTok
      */

         case('N'):
            switch(*ptr++) {
                case('A'):
                	if( !strcmp(ptr,"STRO") || !strcmp(ptr,"STRI") ) {
                        return( RibbonTok );
                    }
                    break;
            
                case('E'):
                    if( !strcmp(ptr,"GATIVE") ) {
                        return( AcidicTok );
                    } else if( !strcmp(ptr,"W") ) {
                        return( NewTok );
                    } else if( !strcmp(ptr,"UTRAL") ) {
                        return( NeutralTok );
                    } else if( !strcmp(ptr,"XT") ) {
                        return( NextTok );
                    }
                    break;

                case('M'):
                    if( !strcmp(ptr,"RPDB") ) {
                        return( NMRPDBTok );
                    }
                    break;

                case('O'):
                    if( !strcmp(ptr,"NE") ) {
                        return( NoneTok );
                    } else if( !strcmp(ptr,"RMAL") ) {
                        return( NormalTok );
                    } else if( (*ptr=='T') && !ptr[1] ) {
                        return( NotTok );
					} else if( !strcmp(ptr,"TOGGLE") ) {
						return( NoToggleTok );
                    }
                    break;

                case('U'):
                    if( !strcmp(ptr,"CLEIC") ) {
                        return( NucleicTok );
                    }
                    break;

            }
            break;

      /*
        OFF                  FalseTok
             OLD                  OldTok
        ON                   TrueTok
        OR                   OrTok
        ORANGE               OrangeTok
        ORIGIN               OriginTok
        OUT                  OutTok
      */
        case('O'):
            switch(*ptr++) {
                case('F'):
                    if( (*ptr=='F') && !ptr[1] ) {
                        return( FalseTok );
                    }
                    break;

                case('L'):
                    if( (*ptr=='D') && !ptr[1] ) {
                        return( OldTok );
                    }
                    break;

                case('N'):
                    if( !*ptr ) {
                        return( TrueTok );
                    }
                    break;

                case('R'):
                    if( !*ptr ) {
                        return( OrTok );
                    } else if( !strcmp(ptr,"ANGE") ) {
                        return( OrangeTok );
                    } else if( !strcmp(ptr,"IGIN") ) {
                        return( OriginTok );
                    }
                    break;
                    
               case('U'):
                   if (!strcmp(ptr,"T") )  {
                   	    return ( OutTok );
                   }


            }
            break;

      /*
             PASTE				  PasteTok
        PAUSE                WaitTok
        PDB                  PDBTok
        PHIPSI               PhiPsiTok
        PICK                 PickingTok
        PICKING              PickingTok
        PICT                 PICTTok
        PINK                 PinkTok
        PINKTINT             PinkTintTok
             PLAY                 PlayTok
        PNG                  PNGTok
        POLAR                PolarTok
        POSITIVE             BasicTok
             POSITION			  PositionTok
        POTENTIAL            PotentialTok
        POVRAY               POVRayTok
        POVRAY2              POVRay2Tok
        POVRAY3              POVRay3Tok
        PPM                  PPMTok
        PRINT                PrintTok
        PROTEIN              ProteinTok
        PS                   EPSFTok
        PURINE               PurineTok
        PURINES              PurineTok
        PURPLE               PurpleTok
        PYRIMIDINE           PyrimidineTok
        PYRIMIDINES          PyrimidineTok
      */

        case('P'):
            switch(*ptr++) {
                case('A'):
                    if( !strcmp(ptr,"STE") ) {
                        return( PasteTok );
                    } else if( !strcmp(ptr,"USE") ) {
                        return( WaitTok );
                    }
                    break;

                case('D'):
                    if( (*ptr=='B') && !ptr[1] ) {
                        return( PDBTok );
                    }
                    break;

                case('H'):
                    if( !strcmp(ptr,"IPSI") ) {
                        return( PhiPsiTok );
                    } 

                case('I'):
                    if( !strcmp(ptr,"CK") ) {
                        return( PickingTok );
                    } else if( !strcmp(ptr,"CKING") ) {
                        return( PickingTok );
                    } else if( !strcmp(ptr,"CT") ) {
                        return( PICTTok );
                    } else if( !strcmp(ptr,"NK") ) {
                        return( PinkTok );
                    } else if( !strcmp(ptr,"NKTINT") ) {
                        return( PinkTintTok );
                    }
                    break;

                case('L'):
                    if (!strcmp(ptr,"AY") ) {
                        return( PlayTok );
                    }
                    break;
                    
                case('N'):
                    if( (*ptr=='G') && !ptr[1] ) {
                        return( PNGTok );
                    }
                    break;

                case('O'):
                    if( !strcmp(ptr,"LAR") ) {
                        return( PolarTok );
                    } else if( !strcmp(ptr,"SITIVE") ) {
                        return( BasicTok );
                    } else if( !strcmp(ptr,"SITION") ) {
                        return( PositionTok );
                    } else if( !strcmp(ptr,"TENTIAL") ) {
                        return( PotentialTok );
                    } else if( !strcmp(ptr,"VRAY") ) {
                        return( POVRayTok );
                    } else if( !strcmp(ptr,"VRAY2") ) {
                        return( POVRay2Tok );
                    } else if( !strcmp(ptr,"VRAY3") ) {
                        return( POVRay3Tok );
                    }
                    break;

                case('P'):
                    if( (*ptr=='M') && !ptr[1] ) {
                        return( PPMTok );
                    }
                    break;

                case('R'):
                    if( !strcmp(ptr,"INT") ) {
                        return( PrintTok );
                    } else if( !strcmp(ptr,"OTEIN") ) {
                        return( ProteinTok );
                    }
                    break;

                case('S'):
                    if( !*ptr ) {
                        return( EPSFTok );
                    }
                    break;

                case('U'):
                    if( !strcmp(ptr,"RINE") ) {
                        return( PurineTok );
                    } else if( !strcmp(ptr,"RINES") ) {
                        return( PurineTok );
                    } else if( !strcmp(ptr,"RPLE") ) {
                        return( PurpleTok );
                    }
                    break;

                case('Y'):
                    if( !strcmp(ptr,"RIMIDINE") ) {
                        return( PyrimidineTok );
                    } else if( !strcmp(ptr,"RIMIDINES") ) {
                        return( PyrimidineTok );
                    }
                    break;

            }
            break;

      /*
        QUANTA               QuantaTok
        QUIT                 QuitTok
      */

        case('Q'):
            if( *ptr++ == 'U' ) {
                if( !strcmp(ptr,"ANTA") ) {
                    return( QuantaTok );
                } else if( !strcmp(ptr,"IT") ) {
                    return( QuitTok );
                }
            }
            break;

      /*
        R3D                  Raster3DTok
        RADIUS               RadiusTok
        RAMACHAN             RamachanTok
        RAMACHANDRANDATAFILE RamachanTok
        RAMACHANDRANPRINTERPLOT RamPrintTok
        RAMDATA              RamachanTok
        RAMPRINT             RamPrintTok
        RASMAC               RasMolTok
        RASMOL               RasMolTok
        RASTER3D             Raster3DTok
        RASWIN               RasMolTok
        RDF                  RamachanTok
             RECORD               RecordTok
        RED                  RedTok
        REDORANGE            RedOrangeTok
        REFRESH              RefreshTok
        REJECT               RejectTok
        RENUM                RenumTok
        RENUMBER             RenumTok
        RESET                ResetTok
        RESIDUE              ResidueTok
        RESIDUENUMBER        ResNoTok
        RESIZE               ResizeTok
        RESNO                ResNoTok
        RESOLUTION           ResolutionTok
        RESTRICT             RestrictTok
        RGB                  IRISTok
        RH                   RightTok
        RIBBON               RibbonTok
        RIBBON1              Ribbon1Tok
        RIBBON2              Ribbon2Tok
        RIBBONS              RibbonTok
        RIBBONS1             Ribbon1Tok
        RIBBONS2             Ribbon2Tok
        RIEMPIMENTO          SpacefillTok
        RIGHT                RightTok
        RNA                  RNATok
        ROT                  RotateTok
        ROTATE               RotateTok
        ROTATION             RotateTok
        RPP                  RamPrintTok
      */

        case('R'):
            switch(*ptr++) {
            	case('3'):
            	    if( !strcmp(ptr,"D") ) {
            	    	return( Raster3DTok );
            	    }
            	    break;
            	    
                case('A'):
                    if( !strcmp(ptr,"DIUS") ) {
                        return( RadiusTok );
                    } else if( !strcmp(ptr,"MACHAN") ) {
                        return( RamachanTok );
                    } else if( !strcmp(ptr,"MACHANDRANDATAFILE") ) {
                        return( RamachanTok );
                    } else if( !strcmp(ptr,"MACHANDRANPRINTERPLOT") ) {
                        return( RamPrintTok );
                    } else if( !strcmp(ptr,"MDATA") ) {
                        return( RamachanTok );
                    } else if( !strcmp(ptr,"MPRINT") ) {
                        return( RamPrintTok );
                    } else if( !strcmp(ptr,"SMAC") ) {
                        return( RasMolTok );
                    } else if( !strcmp(ptr,"SMOL") ) {
                        return( RasMolTok );
                    } else if( !strcmp(ptr,"STER3D") )  {
                    	return( Raster3DTok);
                    } else if( !strcmp(ptr,"SWIN") ) {
                        return( RasMolTok );
                    }
                    break;

                case('D'):
                    if( !strcmp(ptr,"F") ) {
                        return( RamachanTok );
                    }
                    break;

                case('E'):
                    if( !strcmp(ptr,"CORD") ) {
                        return ( RecordTok );
                    } else if( (*ptr=='D') && !ptr[1] ) {
                        return( RedTok );
                    } else if( !strcmp(ptr,"DORANGE") ) {
                        return( RedOrangeTok );
                    } else if( !strcmp(ptr,"FRESH") ) {
                        return( RefreshTok );
                    } else if( !strcmp(ptr,"JECT") ) {
                        return( RejectTok );
                    } else if( !strcmp(ptr,"NUM") ) {
                        return( RenumTok );
                    } else if( !strcmp(ptr,"NUMBER") ) {
                        return( RenumTok );
                    } else if( !strcmp(ptr,"SET") ) {
                        return( ResetTok );
                    } else if( !strcmp(ptr,"SIDUE") ) {
                        return( ResidueTok );
                    } else if( !strcmp(ptr,"SIDUENUMBER") ) {
                        return( ResNoTok );
                    } else if( !strcmp(ptr,"SIZE") ) {
                        return( ResizeTok );
                    } else if( !strcmp(ptr,"SNO") ) {
                        return( ResNoTok );
                    } else if( !strcmp(ptr,"SOLUTION") ) {
                        return( ResolutionTok );
                    } else if( !strcmp(ptr,"STRICT") ) {
                        return( RestrictTok );
                    }
                    break;

                case('G'):
                    if( (*ptr=='B') && !ptr[1] ) {
                        return( IRISTok );
                    }
                    break;

                case('H'):
                    if( !*ptr ) {
                        return( RightTok );
                    }
                    break;

                case('I'):
                    if( !strcmp(ptr,"BBON") ) {
                        return( RibbonTok );
                    } else if( !strcmp(ptr,"BBON1") ) {
                        return( Ribbon1Tok );
                    } else if( !strcmp(ptr,"BBON2") ) {
                        return( Ribbon2Tok );
                    } else if( !strcmp(ptr,"BBONS") ) {
                        return( RibbonTok );
                    } else if( !strcmp(ptr,"BBONS1") ) {
                        return( Ribbon1Tok );
                    } else if( !strcmp(ptr,"BBONS2") ) {
                        return( Ribbon2Tok );
                    } else if( !strcmp(ptr,"EMPIMENTO") ) {
                        return( SpacefillTok );
                    } else if( !strcmp(ptr,"GHT") ) {
                        return( RightTok );
                    }
                    break;

                case('N'):
                    if( (*ptr=='A') && !ptr[1] ) {
                        return( RNATok );
                    }
                    break;

                case('O'):
                    if( !strcmp(ptr,"TATE") ) {
                        return( RotateTok );
                    } else if( !strcmp(ptr,"T") ) {
                        return( RotateTok );
                    } else if( !strcmp(ptr,"TATION") ) {
                        return( RotateTok );
                    }
                    break;

                case('P'):
                    if( !strcmp(ptr,"P") ) {
                        return( RamPrintTok );
                    }
                    break;

                case('U'):
                    if( !strcmp(ptr,"SSIAN") ) {
                        return( RussianTok );
                    }
                    break;
            }
            break;

      /*
        SALIR                ExitTok
        SAVE                 SaveTok
        SCALE                ScaleTok
        SCHELETRO            BackboneTok
        SCRIPT               ScriptTok
        SECTION              SectionTok
        SEAGREEN             SeaGreenTok
        SELECT               SelectTok
        SELECTED             SelectedTok
        SELECTION            SelectedTok
        SEQUENCE             SequenceTok
        SET                  SetTok
        SHADEPOWER           ShadePowerTok
        SHADOW               ShadowTok
        SHADOWS              ShadowTok
        SHAPELY              ShapelyTok
        SHEET                SheetTok
        SHEETS               SheetTok
        SHELX                SHELXTok
        SHOW                 ShowTok
        SIDECHAIN            SidechainTok
        SKYBLUE              SkyBlueTok
        SLAB                 SlabTok
        SLABMODE             SlabModeTok
        SMALL                SmallTok
        SOLID                SolidTok
        SOLVENT              SolventTok
        SOLVENTS             SolventTok
        SOURCE               SourceTok
        SPACEFILL            SpacefillTok
        SPACING              SpacingTok
        SPANISH              SpanishTok
        SPECPOWER            SpecPowerTok
        SPECULAR             SpecularTok
        SPREAD               SpreadTok (WidthTok)
        SSBOND               SSBondTok
        SSBONDS              SSBondTok
        STAR                 StarTok
        STARS                StarTok
        STEREO               StereoTok
        STRANDS              StrandsTok
        STRUCTURE            StructureTok
        SUN                  SUNTok
        SUNRLE               SUNRLETok
        SURFACE              SurfaceTok
        SYBYL                SybylTok
        SYMMETRY             SymmetryTok
      */

        case('S'):
            switch(*ptr++) {
                case('A'):
                    if( !strcmp(ptr,"LIR") ) {
                        return( ExitTok );
                    } else if( !strcmp(ptr,"VE") ) {
                        return( SaveTok );
                    }
                    break;

                case('C'):
                    if( !strcmp(ptr,"ALE") ) {
                        return( ScaleTok );
                    }else if( !strcmp(ptr,"RIPT") ) {
                        return( ScriptTok );
                    } else if( !strcmp(ptr,"HELETRO") ) {
                        return( BackboneTok );
                    }
                    break;

                case('E'):
                    if( !strcmp(ptr,"AGREEN") ) {
                        return( SeaGreenTok );
                    } else if( !strcmp(ptr,"CTION") ) {
                        return( SectionTok );
                    } else if( !strcmp(ptr,"LECT") ) {
                        return( SelectTok );
                    } else if( !strcmp(ptr,"LECTED") ) {
                        return( SelectedTok );
                    } else if( !strcmp(ptr,"LECTION") ) {
                        return( SelectedTok );
                     } else if( !strcmp(ptr,"QUENCE") ) {
                        return( SequenceTok );
                    } else if( (*ptr=='T') && !ptr[1] ) {
                        return( SetTok );
                    }
                    break;

                case('H'):
                     if( !strcmp(ptr,"ADEPOWER") ) {
                        return( ShadePowerTok );
                    } else if( !strcmp(ptr,"ADOW") ) {
                       return( ShadowTok );
                    } else if( !strcmp(ptr,"ADOWS") ) {
                        return( ShadowTok );
                    } else if( !strcmp(ptr,"APELY") ) {
                        return( ShapelyTok );
                    } else if( !strcmp(ptr,"EET") ) {
                        return( SheetTok );
                    } else if( !strcmp(ptr,"EETS") ) {
                        return( SheetTok );
                    } else if( !strcmp(ptr,"ELX") ) {
                        return( SHELXTok );
                    } else if( !strcmp(ptr,"OW") ) {
                        return( ShowTok );
                    }
                    break;

                case('I'):
                    if( !strcmp(ptr,"DECHAIN") ) {
                        return( SidechainTok );
                    }
                    break;

                case('K'):
                    if( !strcmp(ptr,"YBLUE") ) {
                        return( SkyBlueTok );
                    }
                    break;

                case('L'):
                    if( !strcmp(ptr,"AB") ) {
                        return( SlabTok );
                    } else if( !strcmp(ptr,"ABMODE") ) {
                        return( SlabModeTok );
                    }
                    break;

                case('M'):
                    if( !strcmp(ptr,"ALL") ) {
                        return( SmallTok );
                    }
                    break;

                case('O'):
                    if( !strcmp(ptr,"LID") ) {
                        return( SolidTok );
                    } else if( !strcmp(ptr,"LVENT") ) {
                        return( SolventTok );
                    } else if( !strcmp(ptr,"LVENTS") ) {
                        return( SolventTok );
                    } else if( !strcmp(ptr,"URCE") ) {
                        return( SourceTok );
                    }
                    break;

                case('P'):
                    if( !strcmp(ptr,"ACEFILL") ) {
                        return( SpacefillTok );
                    } else if( !strcmp(ptr,"ACING") ) {
                        return( SpacingTok );
                    } else if( !strcmp(ptr,"ANISH") ) {
                        return( SpanishTok );
                    } else if( !strcmp(ptr,"ECPOWER") ) {
                        return( SpecPowerTok );
                    } else if( !strcmp(ptr,"ECULAR") ) {
                        return( SpecularTok );
                    } else if( !strcmp(ptr,"READ") ) {
                        return( SpreadTok );
                    }
                    break;

                case('S'):
                    if( !strcmp(ptr,"BOND") ) {
                        return( SSBondTok );
                    } else if( !strcmp(ptr,"BONDS") ) {
                        return( SSBondTok );
                    }
                    break;

                case('T'):
                    if( !strcmp(ptr,"AR") || !strcmp(ptr,"ARS") ){
                        return( StarTok );
                    } else if( !strcmp(ptr,"EREO") ) {
                        return( StereoTok );
                    } else if( !strcmp(ptr,"RANDS") ) {
                        return( StrandsTok );
                    } else if( !strcmp(ptr,"RUCTURE") ) {
                        return( StructureTok );
                    }
                    break;

                case('U'):
                    if( (*ptr=='N') && !ptr[1] ) {
                        return( SUNTok );
                    } else if( !strcmp(ptr,"NRLE") ) {
                        return( SUNRLETok );
                    } else if( !strcmp(ptr,"RFACE") ) {
                        return( SurfaceTok );
                    }
                    break;

                case('Y'):
                    if( !strcmp(ptr,"BYL") ) {
                        return( SybylTok );
                    } else if( !strcmp(ptr,"MMETRY") ) {
                        return( SymmetryTok );
                    }
                    break;

            }
            break;

      /*
        TEMPERATURE          TemperatureTok
        TITLE                TitleTok
        TODO                 AllTok
        TORSION              TorsionTok
        TORSIONS             TorsionTok
        TRACE                TraceTok
        TRANSLATE            TranslateTok
        TRANSLATION          TranslateTok
        TRANSPARENT          TransparentTok
        TRUE                 TrueTok
        TURN                 TurnTok
        TURNS                TurnTok
        TUTTO                AllTok 
        TYPE                 TypeTok
      */

        case('T'):
            switch(*ptr++) {
                case('E'):
                    if( !strcmp(ptr,"MPERATURE") ) {
                        return( TemperatureTok );
                    }
                    break;

                case('I'):
                    if( !strcmp(ptr,"TLE") ) {
                        return( TitleTok );
                    }
                    break;

                case('O'):
                    if( !strcmp(ptr,"DO") ) {
                        return( AllTok );
                    } else if( !strcmp(ptr,"RSION") ) {
                        return( TorsionTok );
                    } else if( !strcmp(ptr,"RSIONS") ) {
                        return( TorsionTok );
                    }
                    break;

                case('R'):
                    if( !strcmp(ptr,"ACE") ) {
                        return( TraceTok );
                    } else if( !strcmp(ptr,"ANSLATE") ) {
                        return( TranslateTok );
                    } else if( !strcmp(ptr,"ANSLATION") ) {
                        return( TranslateTok );
                    } else if( !strcmp(ptr,"ANSPARENT") ) {
                        return( TransparentTok );
                    } else if( !strcmp(ptr,"UE") ) {
                        return( TrueTok );
                    }
                    break;

                case('U'):
                    if( !strcmp(ptr,"RN") ) {
                        return( TurnTok );
                    } else if( !strcmp(ptr,"RNS") ) {
                        return( TurnTok );
                    } else if( !strcmp(ptr,"TTO") ) {
                        return( AllTok );
                    }
                    break;

                case('Y'):
                    if( !strcmp(ptr,"PE") ) {
                        return( TypeTok );
                    }
                    break;

            }
            break;

      /*
        UNBOND               UnBondTok
        UNITCELL             UnitCellTok
             UNTIL                UntilTok
        UP                   UpTok
        USER                 UserTok
      */

        case('U'):
            switch(*ptr++) {
                case('N'):
                    if( !strcmp(ptr,"ITCELL") ) {
                        return( UnitCellTok );
                    } else if( !strcmp(ptr,"BOND") ) {
                        return( UnBondTok );
                    } else if( !strcmp(ptr,"TIL") ) {
                        return( UntilTok );
                    }
                    break;

                case('P'):
                    if( !*ptr ) {
                        return( UpTok );
                    }
                    break;


                case('S'):
                    if( !strcmp(ptr,"ER") ) {
                        return( UserTok );
                    }
                    break;

            }
            break;

      /*
        VDW                  VDWTok
        VECTPS               VectPSTok
		VIEW                 ViewTok
        VIGNETTA             CartoonTok
        VIOLET               VioletTok
        VISUALIZZA           DisplayTok 
        VRML                 VRMLTok
      */

        case('V'):
            switch(*ptr++) {
                case('D'):
                    if( (*ptr=='W') && !ptr[1] ) {
                        return( VDWTok );
                    }
                    break;

                case('E'):
                    if( !strcmp(ptr,"CTPS") ) {
                        return( VectPSTok );
                    }
                    break;

                case('I'):
                     if( !strcmp(ptr,"EW") ) {
                        return( ViewTok );
                    } else if( !strcmp(ptr,"GNETTA") ) {
                        return( CartoonTok );
                    } else if( !strcmp(ptr,"OLET") ) {
                        return( VioletTok );
                    } else if( !strcmp(ptr,"SAGE") ) {
                    	return( AppearanceTok);
                    } else if( !strcmp(ptr,"SUALIZZA") ) {
                        return( DisplayTok );
                    }
                    break;

                case('R'):
                    if( !strcmp(ptr,"ML") ) {
                        return( VRMLTok );
                    }
                    break;

            }
            break;

      /*
        WAIT                 WaitTok
        WATER                WaterTok
        WATERS               WaterTok
        WHITE                WhiteTok
        WIDTH                WidthTok (SpreadTok)
        WIREFRAME            WireframeTok
        WITHIN               WithinTok
        WPDB                 WPDBTok
        WRITE                WriteTok
      */

        case('W'):
            switch(*ptr++) {
                case('A'):
                    if( !strcmp(ptr,"IT") ) {
                        return( WaitTok );
                    } else if( !strcmp(ptr,"TER") ) {
                        return( WaterTok );
                    } else if( !strcmp(ptr,"TERS") ) {
                        return( WaterTok );
                    }
                    break;

                case('H'):
                    if( !strcmp(ptr,"ITE") ) {
                        return( WhiteTok );
                    }
                    break;

                case('I'):
                    if( !strcmp(ptr,"DTH") ) {
                        return( WidthTok );
                    } else if( !strcmp(ptr,"REFRAME") ) {
                        return( WireframeTok );
                    } else if( !strcmp(ptr,"THIN") ) {
                        return( WithinTok );
                    }
                    break;

                case('P'):
                    if( !strcmp(ptr,"DB") ) {
                        return( WPDBTok );
                    }
                    break;

                case('R'):
                    if( !strcmp(ptr,"ITE") ) {
                        return( WriteTok );
                    }
                    break;

            }
            break;

      /*
        X                    XTok
        XYZ                  XYZTok
      */

        case('X'):
            switch(*ptr++) {
                case(0):
                    return( XTok );

                case('Y'):
                    if( (*ptr=='Z') && !ptr[1] ) {
                        return( XYZTok );
                    }
                    break;

            }
            break;

      /*
        Y                    YTok
        YELLOW               YellowTok
        YELLOWTINT           YellowTintTok
      */

        case('Y'):
            switch(*ptr++) {
                case(0):
                    return( YTok );

                case('E'):
                    if( !strcmp(ptr,"LLOW") ) {
                        return( YellowTok );
                    } else if( !strcmp(ptr,"LLOWTINT") ) {
                        return( YellowTintTok );
                    }
                    break;

            }
            break;

      /*
        Z                    ZTok
        ZAP                  ZapTok
        ZOOM                 ZoomTok
      */
        case('Z'):
            switch(*ptr++) {
                case(0):
                    return( ZTok );

                case('A'):
                    if( (*ptr=='P') && !ptr[1] ) {
                        return( ZapTok );
                    }
                    break;

                case('O'):
                    if( !strcmp(ptr,"OM") ) {
                        return( ZoomTok );
                    }
                    break;

            }
            break;

    }
    return( IdentTok );
}

