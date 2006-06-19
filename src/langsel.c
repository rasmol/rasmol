
/***************************************************************************
 *                               RasMol 2.7.3                              *
 *                                                                         *
 *                                 RasMol                                  *
 *                 Molecular Graphics Visualisation Tool                   *
 *                             6 February 2005                             *
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
 *Bernstein          RasMol 2.7.1   Jun 99         1998-2001               *
 *                   RasMol 2.7.1.1 Jan 01                                 *
 *                   RasMol 2.7.2   Aug 00                                 *
 *                   RasMol 2.7.2.1 Apr 01                                 *
 *                   RasMol 2.7.2.1.1 Jan 04                               *
 *                   RasMol 2.7.3   Feb 05                                 *
 *                                                                         *
 *with RasMol 2.7.3 incorporating changes by Clarice Chigbo, Ricky Chachra,*
 *and Mamoru Yamanishi.  Work on RasMol 2.7.3 supported in part by         *
 *grants DBI-0203064, DBI-0315281 and EF-0312612 from the U.S. National    *
 *Science Foundation and grant DE-FG02-03ER63601 from the U.S. Department  *
 *of Energy.                                                               *
 *                                                                         *
 *                    and Incorporating Translations by                    *
 *  Author                               Item                      Language*
 *  Isabel Servan Martinez,                                                *
 *  Jose Miguel Fernandez Fernandez      2.6   Manual              Spanish *
 *  Jose Miguel Fernandez Fernandez      2.7.1 Manual              Spanish *
 *  Fernando Gabriel Ranea               2.7.1 menus and messages  Spanish *
 *  Jean-Pierre Demailly                 2.7.1 menus and messages  French  *
 *  Giuseppe Martini, Giovanni Paolella, 2.7.1 menus and messages          *
 *  A. Davassi, M. Masullo, C. Liotto    2.7.1 help file           Italian *
 *                                                                         *
 *                             This Release by                             *
 * Herbert J. Bernstein, Bernstein + Sons, P.O. Box 177, Bellport, NY, USA *
 *                       yaya@bernstein-plus-sons.com                      *
 *               Copyright(C) Herbert J. Bernstein 1998-2005               *
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
 *                                                                         *
 ***************************************************************************/

#include <string.h>

#define LANGSEL
#include "rasmol.h"
#include "graphics.h"
#include "langsel.h"

extern int Interactive;

static langstr langstrs[] = {
  { "Invalid command syntax!\n",                       ErrSyntax,   English,0},
  { "¡Sintaxis de comando inválida!\n",                ErrSyntax,   Spanish,0},
  { "Syntaxe de commande incorrecte!\n",               ErrSyntax,   French,0},
  { "Sintassi del comando errata!\n",                  ErrSyntax,   Italian,0},

  { "Parameter value too large!\n",                    ErrBigNum,   English,0},
  { "¡Valor de parámetro demasiado larga!\n",          ErrBigNum,   Spanish,0},
  { "Valeur du paramètre trop grande!\n",              ErrBigNum,   French,0},
  { "Valore del parametro troppo grande!\n",           ErrBigNum,   Italian,0},

  { "Invalid parameter setting!\n",                    ErrBadOpt,   English,0},
  { "¡Valor de parámetro inválido!\n",                 ErrBadOpt,   Spanish,0},
  { "Valeur du paramètre incorrecte!\n",               ErrBadOpt,   French,0},
  { "Parametro di impostazione non valido!\n",         ErrBadOpt,   Italian,0},

  { "Invalid parameter name!\n",                       ErrParam,    English,0},
  { "¡Nombre de parámetro inválido!\n",                ErrParam,    Spanish,0},
  { "Nom du paramètre incorrect!\n",                   ErrParam,    French,0},
  { "Nome del parametro non valido!\n",                ErrParam,    Italian,0},

  { "Filename string expected!\n",                     ErrFilNam,   English,0},
  { "¡Se esperaba un nombre de archivo!\n",            ErrFilNam,   Spanish,0},
  { "Un nom de fichier est attendu!\n",                ErrFilNam,   French,0},
  { "Stringa col nome del documento richiesta!\n",     ErrFilNam,   Italian,0},

  { "Molecule database loaded!\n",                     ErrBadLoad,  English,0},
  { "¡Base de datos de moléculas cargada!\n",          ErrBadLoad,  Spanish,0},
  { "Base de données de molécules chargée!\n",         ErrBadLoad,  French,0},
  { "Archivio della molecola caricato!\n",             ErrBadLoad,  Italian,0},

  { "Integer value expected!\n",                       ErrNotNum,   English,0},
  { "¡Se esperaba un valor entero!\n",                 ErrNotNum,   Spanish,0},
  { "Une valeur entière est attendue!\n",              ErrNotNum,   French,0},
  { "Valore intero richiesto!\n",                      ErrNotNum,   Italian,0},

  { "Comma separator missing!\n",                      ErrNotSep,   English,0},
  { "¡Separador coma perdido!\n",                      ErrNotSep,   Spanish,0},
  { "Manque une virgule de séparation!\n",             ErrNotSep,   French,0},
  { "Virgola di separazione richiesta!\n",             ErrNotSep,   Italian,0},

  { "Close bracket ']' expected!\n",                   ErrNotBrac,  English,0},
  { "¡Se esperaba cerrar corchete ']'!\n",             ErrNotBrac,  Spanish,0},
  { "Manque un crochet fermant ']'!\n",                ErrNotBrac,  French,0},
  { "Parentesi chiusa ']' richiesta!\n",               ErrNotBrac,  Italian,0},

  { "No colour specified!\n",                          ErrNoCol,    English,0},
  { "¡No se ha especificado un color!\n",              ErrNoCol,    Spanish,0},
  { "Aucune couleur n'a été spécifiée!\n",             ErrNoCol,    French,0},
  { "Colore non specificato!\n",                       ErrNoCol,    Italian,0},

  { "Unknown or incorrect colour!\n",                  ErrColour,   English,0},
  { "¡Color incorrecto o desconocido!\n",              ErrColour,   Spanish,0},
  { "Couleur incorrecte ou inconnue!\n",               ErrColour,   French,0},
  { "Colore non corretto o non specificato!\n",        ErrColour,   Italian,0},

  { "Invalid command argument!\n",                     ErrBadArg,   English,0},
  { "¡Argumento de comando inválido!\n",               ErrBadArg,   Spanish,0},
  { "Argument de commande invalide!\n",                ErrBadArg,   French,0},
  { "Argomento del comando non corretto!\n",           ErrBadArg,   Italian,0},

  { "Syntax error in expression!\n",                   ErrBadExpr,  English,0},
  { "¡Error de sintaxis en la expresión!\n",           ErrBadExpr,  Spanish,0},
  { "Erreur de syntaxe dans l'expression!\n",          ErrBadExpr,  French,0},
  { "Errore di sintassi nell'espressione!\n",          ErrBadExpr,  Italian,0},

  { "Close parenthesis ')' expected!\n",               ErrParen,    English,0},
  { "¡Se esperaba cerrar paréntesis ')'!\n",           ErrParen,    Spanish,0},
  { "Une parenthèse fermante ')' est attendue!\n",     ErrParen,    French,0},
  { "Parentesi chiusa ')' richiesta!\n",               ErrParen,    Italian,0},

  { "Script command stack too deep!\n",                ErrScript,   English,0},
  { "¡Pila del comando de script demasiado grande!\n", ErrScript,   Spanish,0},
  { "La pile de commande est trop profonde!\n",        ErrScript,   French,0},
  { "La pila dei comandi è troppo profonda!\n",        ErrScript,   Italian,0},

  { "Open parenthesis '(' expected!\n",                ErrFunc,     English,0}, 
  { "¡Se esperaba abrir parentesis '('!\n",            ErrFunc,     Spanish,0},
  { "Une parenthèse ouvrante '(' est attendue!\n",     ErrFunc,     French,0},
  { "Parentesi aperta '(' richiesta!\n",               ErrFunc,     Italian,0},

  { "Invalid or missing atom set name!\n",             ErrSetName,  English,0},
  { "¡Nombre de átomo inválido o erróneo!\n",          ErrSetName,  Spanish,0},
  { "Nom d'atome invalide ou erroné!\n",               ErrSetName,  French,0},
  { "Nome set atomo non valido o assente!\n",          ErrSetName,  Italian,0},

  { "Not enough memory to define set!\n",              ErrBadSet,   English,0},
  { "¡No hay suficiente memoria para definir!\n",      ErrBadSet,   Spanish,0},
  { "Mémoire insuffisante pour définir l'ensemble!\n", ErrBadSet,   French,0},
  { "Memoria insufficiente per definire set!\n",       ErrBadSet,   Italian,0},

  { "Command disabled in script file!\n",              ErrInScrpt,  English,0},
  { "¡Comando deshabilitado en el archivo de script!\n",
                                                       ErrInScrpt,  Spanish,0},
  { "Commande désactivée dans le fichier de script!\n",ErrInScrpt,  French,0},
  { "Comando disabilitato nel documento di script!\n", ErrInScrpt,  Italian,0},

  { "Command invalid (valid only within a script)!\n", ErrOutScrpt, English,0},
  { "¡Comando inválido (comando válido sólo dentro un script)!\n", 
                                                       ErrOutScrpt, Spanish,0},
  { "Commande invalide (le serait seulement dans un script)!\n", 
                                                       ErrOutScrpt, French,0},
  { "Comando non valido (valido solo dentro uno script)!\n", 
                                                       ErrOutScrpt, Italian,0},

  { "Molecule database not loaded!\n",                 ErrBadMolDB, English,0},
  { "¡Base de datos de moléculas no cargada!\n",       ErrBadMolDB, Spanish,0},
  { "Base de données de molécules non chargée!\n",     ErrBadMolDB, French,0},
  { "Archivio della molecola non caricato!\n",         ErrBadMolDB, Italian,0},

  { "Bond for rotation not picked!\n",                 ErrNoBond,   English,0},
  { "¡Enlace para el giro no elegido!\n",              ErrNoBond,   Spanish,0},
  { "Liaison de tourner non choisi!\n",                ErrNoBond,   French,0},
  { "Legame per rotazione non selezionato\n",          ErrNoBond,   Italian,0},

  { "Error: File '",                                   StrErrFile,  English,0},
  { "¡Error: Archivo '",                               StrErrFile,  Spanish,0},
  { "Erreur: Fichier '",                               StrErrFile,  French,0},
  { "Errore: Documento '",                             StrErrFile,  Italian,0},

  { "' not found!\n\n",                                StrNotFnd,   English,0},
  { "' no encontrado!\n\n",                            StrNotFnd,   Spanish,0},
  { "' non trouvé!\n\n",                               StrNotFnd,   French,0},
  { "' non trovato!\n\n",                              StrNotFnd,   Italian,0},

  { "Error: Unrecognised compression format!\n\n",     StrCFmt,     English,0},
  { "¡Error: Formato de compresión no reconocido!\n\n",
                                                       StrCFmt,     Spanish,0},
  { "Erreur: Format de compression non reconnu!\n\n",  StrCFmt,     French,0},
  { "Errore: Formato di compressione non riconosciuto!\n\n",
                                                       StrCFmt,     Italian,0},

  { "Error: Unable to decompress file!\n\n",           StrDcmp,     English,0},
  { "¡Error: Incapaz de descomprimir el archivo!\n\n", StrDcmp,     Spanish,0},
  { "Erreur: Impossible de décompresser le fichier!\n\n", 
                                                       StrDcmp,     French,0},
  { "Errore: Incapace di decomprimere il documento!\n\n",
                                                       StrDcmp,     Italian,0},

  { "Script command line too long!\n",                 StrSLong,    English,0},
  { "¡Script de línea de comando demasiado largo!\n",  StrSLong,    Spanish,0},
  { "Ligne de command de script trop longue!\n",       StrSLong,    French,0},
  { "Script di linea di comando troppo lungo!\n",      StrSLong,    Italian,0},

  { "Command Error: Insufficient memory!\n",           StrSMem,     English,0},
  { "¡Error de comando: Memoria insuficiente!",        StrSMem,     Spanish,0},
  { "Erreur de commande: Mémoire inuffisante!\n",      StrSMem,     French,0},
  { "Errore di comando: Memoria insufficiente!",       StrSMem,     Italian,0},

  { "Unable to find RasMol help file!\n",              StrHFil,     English,0},
  { "¡Incapaz de encontrar el archivo de ayuda del RasMol!\n",
                                                       StrHFil,     Spanish,0},
  { "Impossible de trouver le fichier d'aide sur RasMol!\n",              
                                                        StrHFil,     French,0},
  { "Incapace di trovare il documento dell'aiuto di RasMol!\n",
                                                       StrHFil,     Italian,0},

  { "Ambiguous help topic requested!\n",               StrHTop,     English,0},
  { "¡Tópico de ayuda requerido ambiguo!\n",           StrHTop,     Spanish,0},
  { "Requête d'aide thématique ambigüe!\n",            StrHTop,     French,0},
  { "Richiesta di argomento di aiuto ambiguo!\n",      StrHTop,     Italian,0},

  { "No available help on requested topic!\n",         StrHNone,    English,0},
  { "¡No hay ayuda disponible para el tópico requerido!\n",
                                                       StrHNone,    Spanish,0},
  { "Pas d'aide disponible sur le thème requis!\n",    StrHNone,    French,0},
  { "Argomento di aiuto non disponibile!\n",           StrHNone,    Italian,0},

  { "Command Error: Unable to reopen help file!\n",    StrHROpn,    English,0},
  { "¡Error de comando: Incapaz de reabrir el archivo de ayuda!\n",
                                                       StrHROpn,    Spanish,0},
  { "Erreur de commande: Impossible de réouvrir le fichier d'aide!\n",    
                                                       StrHROpn,    French,0},
  { "Errore di comando: Incapace di riaprire documento di aiuto!\n",
                                                       StrHROpn,    Italian,0},

  { "String constant unterminated!\n",                 StrCTerm,    English,0},
  { "¡Constante de cadena indeterminada!\n",           StrCTerm,    Spanish,0},
  { "Chaîne de caractères non terminée!\n",            StrCTerm,    French,0},
  { "Costante di stringa non terminata!\n",            StrCTerm,    Italian,0},

  { "String constant too long!\n",                     StrCLong,    English,0},
  { "¡Constante de cadena muy larga !\n",              StrCLong,    Spanish,0},
  { "Chaîne de caractères trop longue!\n",             StrCLong,    French,0},
  { "Costante di stringa troppo lunga!\n",             StrCLong,    Italian,0},

  { "Invalid floating point number!\n",                StrFNum,     English,0},
  { "¡Número de punto flotante inválido!\n",           StrFNum,     Spanish,0},
  { "Nombre à virgule flottante invalide!\n",          StrFNum,     French,0},
  { "Numero in virgola mobile non valido!\n",          StrFNum,     Italian,0},

  { "No Atoms to Centre!\n",                           StrCent,     English,0},
  { "¡No hay átomos para centrar!\n",                  StrCent,     Spanish,0},
  { "Aucun atome à recentrer!\n",                      StrCent,     French,0},
  { "Non ci sono atomi da centrare!\n",                StrCent,     Italian,0},

  { "Unable to copy to clipboard!\n",                  StrCClip,    English,0},
  { "¡Incapaz de copiar al portapapeles!\n",           StrCClip,    Spanish,0},
  { "Impossible de copier le porte-papiers!\n",        StrCClip,    French,0},
  { "Incapace di copiare nel blocco appunti!\n",       StrCClip,    Italian,0},

  { "Cannot open dots file '",                         StrDFile,    English,0},
  { "¡No se puede abrir el archivo de puntos '",       StrDFile,    Spanish,0},
  { "Impossible d'ouvrir le fichier de points '",      StrDFile,    French,0},
  { "Non si può aprire un file di punti '",            StrDFile,    Italian,0},

  { "Warning: No suitable printer!\n",                 StrNPrint,   English,0},
  { "¡Cuidado: No hay impresora disponible!\n",        StrNPrint,   Spanish,0},
  { "Avertissement: Aucune imprimante disponible!\n",  StrNPrint,   French,0},
  { "Attenzione: Stampante non disponibile!\n",        StrNPrint,   Italian,0},

  { "Unit Cell",                                       StrUCell,    English,0},
  { "Célula Unidad",                                   StrUCell,    Spanish,0},
  { "Cellule Unité",                                   StrUCell,    French,0},
  { "Cella Unitaria",                                  StrUCell,    Italian,0},

  { "Space Group",                                     StrSGroup,   English,0},
  { "Grupo Espacial",                                  StrSGroup,   Spanish,0},
  { "Groupe Spatial",                                  StrSGroup,   French,0},
  { "Gruppo Spaziale",                                 StrSGroup,  Italian,0},

  { "No crystal symmetry data!\n",                     StrSymm,     English,0},
  { "¡No hay datos de simetría del cristal\n",         StrSymm,     Spanish,0},
  { "Pas de données de symétrie du cristal!\n",        StrSymm,     French,0},
  { "Assenza dati simmetria del cristallo\n",          StrSymm,     Italian,0},

  { "Unrecognised command!\n",                         StrUnrec,    English,0},
  { "¡Comando no reconocido!\n",                       StrUnrec,    Spanish,0},
  { "Commande non reconnue!\n",                        StrUnrec,    French,0},
  { "Comando non riconosciuto!\n",                     StrUnrec,    Italian,0},

  { "Warning: Ignoring rest of command!\n",            StrIgnore,   English,0},
  { "¡Cuidado: se ignora el resto del comando!\n",     StrIgnore,   Spanish,0},
  { "Avertissement: Reste de la commande ignorée!\n",  StrIgnore,   French,0},
  { "Attenzione: si ignora la restante parte del comando!\n",
                                                       StrIgnore,   Italian,0},

  { "Warning: Remote command too long!\n",             StrRCLong,   English,0},
  { "¡Cuidado: comando remoto demasiado largo!\n",     StrRCLong,   Spanish,0},
  { "Avertissement: Command indirecte trop longue!\n", StrRCLong,   French,0},
  { "Attenzione: comando remoto troppo lungo!\n",      StrRCLong,   Italian,0},

  { "Cannot open script file '",                       StrSFile,    English,0},
  { "¡No se puede abrir el archivo de script '",       StrSFile,    Spanish,0},
  { "Impossible d'ouvrir le fichier de script file '", StrSFile,    French,0},
  { "Impossibile aprire documento di script '",        StrSFile,    Italian,0},

  { "Identifier too long!\n",                          StrILong,    English,0},
  { "¡Identificador demasiado largo!\n",               StrILong,    Spanish,0},
  { "Identificateur trop long!\n",                     StrILong,    French,0},
  { "Identificatore troppo lungo!\n",                  StrILong,    Italian,0},

  { "Molecule name ......... ",                        StrMolNam,   English,0},
  { "Nombre de la Molécula . ",                        StrMolNam,   Spanish,0},
  { "Nom de la molécule .... ",                        StrMolNam,   French,0},
  { "Nome della Molecola ... ",                        StrMolNam,   Italian,0},

  { "Classification ........ ",                        StrClass,    English,0},
  { "Clasificación ......... ",                        StrClass,    Spanish,0},
  { "Classification ........ ",                        StrClass,    French,0},
  { "Classificazione ....... ",                        StrClass,    Italian,0},

  { "Secondary Structure ... ",                        StrSecSt,    English,0},
  { "Estructura Secundaria . ",                        StrSecSt,    Spanish,0},
  { "Structure Secondaire... ",                        StrSecSt,    French,0},
  { "Struttura Secondaria .. ",                        StrSecSt,    Italian,0},

  { "No Assignment\n",                                 StrNoAsmt,   English,0},
  { "No Asignada\n",                                   StrNoAsmt,   Spanish,0},
  { "Non assigné\n",                                   StrNoAsmt,   French,0},
  { "Nessuna assegnazione\n",                          StrNoAsmt,   Italian,0},

  { "PDB Data Records\n",                              StrPDBRec,   English,0},
  { "Registro PDB\n",                                  StrPDBRec,   Spanish,0},
  { "Registre PDB\n",                                  StrPDBRec,   French,0},
  { "Registro PDB\n",                                  StrPDBRec,   Italian,0},

  { "Calculated\n",                                    StrCalc,     English,0},
  { "Calculado\n",                                     StrCalc,     Spanish,0},
  { "Calculé\n",                                       StrCalc,     French,0},
  { "Calcolato\n",                                     StrCalc,     Italian,0},

  { "Database Code ......... ",                        StrDBCode,   English,0},
  { "Código de Base de Datos ",                        StrDBCode,   Spanish,0},
  { "Code de Base de Données ",                        StrDBCode,   French,0},
  { "Codice di database .... ",                        StrDBCode,   Italian,0},

  { "Experiment Technique .. ",                        StrExpTec,   English,0},
  { "Técnica de Experimento  ",                        StrExpTec,   Spanish,0},
  { "Technique expérim.  ... ",                        StrExpTec,   French,0},
  { "Tecnica sperimentale .. ",                        StrExpTec,   Italian,0},

  { "Number of Chains ...... ",                        StrNumChn,   English,0},
  { "Número de Cadenas ..... ",                        StrNumChn,   Spanish,0},
  { "Nombre de Chaînes ..... ",                        StrNumChn,   French,0},
  { "Numero di Catene ...... ",                        StrNumChn,   Italian,0},

  { "Number of Groups ...... ",                        StrNumGrp,   English,0},
  { "Número de Grupos ...... ",                        StrNumGrp,   Spanish,0},
  { "Nombre de Groupes ..... ",                        StrNumGrp,   French,0},
  { "Numero di Gruppi ...... ",                        StrNumGrp,   Italian,0},

  { "Number of Atoms ....... ",                        StrNumAtm,   English,0},
  { "Número de Atomos ...... ",                        StrNumAtm,   Spanish,0},
  { "Nombre d'Atomes ....... ",                        StrNumAtm,   French,0},
  { "Numero di Atomi ....... ",                        StrNumAtm,   Italian,0},

  { "Number of Bonds ....... ",                        StrNumBnd,   English,0},
  { "Número de Enlaces ..... ",                        StrNumBnd,   Spanish,0},
  { "Nombre de Liaisons .... ",                        StrNumBnd,   French,0},
  { "Numero di Legami ...... ",                        StrNumBnd,   Italian,0},

  { "Number of Bridges ..... ",                        StrNumBrg,   English,0},
  { "Número de Puentes ..... ",                        StrNumBrg,   Spanish,0},
  { "Nombre de Ponts ....... ",                        StrNumBrg,   French,0},
  { "Numero di Ponti S-S ... ",                        StrNumBrg,   Italian,0},

  { "Number of H-Bonds ..... ",                        StrNumHbd,   English,0},
  { "Número de Uniones-H ... ",                        StrNumHbd,   Spanish,0},
  { "Nombre de Liaisons-H .. ",                        StrNumHbd,   French,0},
  { "Numero di Legami-H .... ",                        StrNumHbd,   Italian,0},

  { "Number of Helices ..... ",                        StrNumHel,   English,0},
  { "Número de Hélices ..... ",                        StrNumHel,   Spanish,0},
  { "Nombre d'Hélices ...... ",                        StrNumHel,   French,0},
  { "Numero di Eliche ...... ",                        StrNumHel,   Italian,0},

  { "Number of Strands ..... ",                        StrNumStrnd, English,0},
  { "Número de Hebras ...... ",                        StrNumStrnd, Spanish,0},
  { "Nombre de Tresses ..... ",                        StrNumStrnd, French,0},
  { "Numero di Foglietti ... ",                        StrNumStrnd, Italian,0},

  { "Number of Turns ....... ",                        StrNumTrn,   English,0},
  { "Número de Giros ....... ",                        StrNumTrn,   Spanish,0},
  { "Nombre de Tours ....... ",                        StrNumTrn,   French,0},
  { "Numero di Turns ....... ",                        StrNumTrn,   Italian,0},

  { "Memory allocation failed",                        StrMalloc,   English,0},
  { "Falla en la asignación de memoria",               StrMalloc,   Spanish,0},
  { "Allocation mémoire défaillante",                  StrMalloc,   French,0},
  { "Assegnazione di memoria fallita",                 StrMalloc,   Italian,0},

  { "Too many new residues",                           StrXSRes,    English,0},
  { "Demasiados residuos nuevos",                      StrXSRes,    Spanish,0},
  { "Nouveaux résidus trop nombreux",                  StrXSRes,    French,0},
  { "Troppi residui nuovi",                            StrXSRes,    Italian,0},

  { "Too many new atom types",                         StrXSAtyp,   English,0},
  { "Demasiados tipos de átomos nuevos",               StrXSAtyp,   Spanish,0},
  { "Nouveaux type d'atomes trop nombreux",            StrXSAtyp,   French,0},
  { "Troppi tipi di atomi nuovi",                      StrXSAtyp,   Italian,0},

#ifndef MSWIN

  { "Open...",                                         StrMOpen,    English,0},
  { "Save As...",                                      StrMSaveAs,  English,0},
  { "Close",                                           StrMClose,   English,0},
  { "",                                                StrMEmpty,   English,0},
#ifdef APPLEMAC
  { "Page Setup",                                      StrMPSetup,  English,0},
  { "Print",                                           StrMPrint,   English,0},
  { "Quit",                                            StrMExit,    English,0},
#else
  { "Exit",                                            StrMExit,    English,0},
#endif

  { "Abrir...",                                        StrMOpen,    Spanish,0},
  { "Guardar como...",                                 StrMSaveAs,  Spanish,0},
  { "Cerrar",                                          StrMClose,   Spanish,0},
  { "",                                                StrMEmpty,   Spanish,0},
#ifdef APPLEMAC
  { "Configurar página",                               StrMPSetup,  Spanish,3},
  { "Imprimir",                                        StrMPrint,   Spanish,0},
  { "Quitar",                                          StrMExit,    Spanish,0},
#else
  { "Salir",                                           StrMExit,    Spanish,0},
#endif


  { "Ouvrir...",                                       StrMOpen,    French,0},
  { "Sauver sous...",                                  StrMSaveAs,  French,0},
  { "Fermer",                                          StrMClose,   French,0},
  { "",                                                StrMEmpty,   French,0},

#ifdef APPLEMAC
  { "Configuration des Pages",                         StrMPSetup,  French,0},
  { "Imprimer",                                        StrMPrint,   French,0},
  { "Quitter",                                         StrMExit,    French,0},
#else
  { "Terminer",                                        StrMExit,    French,0},
#endif

  { "Apri...",                                         StrMOpen,    Italian,0},
  { "Salva col nome...",                               StrMSaveAs,  Italian,0},
  { "Chiudi",                                          StrMClose,   Italian,0},
  { "",                                                StrMEmpty,   Italian,0},
#ifdef APPLEMAC
  { "Imposta pagina",                                  StrMPSetup,  Italian,0},
  { "Stampa",                                          StrMPrint,   Italian,0},
  { "Esci",                                            StrMExit,    Italian,0},
#else
  { "Esci",                                            StrMExit,    Italian,0},
#endif


  { "Wireframe",                                       StrMWirefr,  English,0},
  { "Backbone",                                        StrMBackbn,  English,0},
  { "Sticks",                                          StrMSticks,  English,1},
  { "Spacefill",                                       StrMSpacefl, English,0},
  { "Ball & Stick",                                    StrMBallStk, English,0},
  { "Ribbons",                                         StrMRibbons, English,0},
  { "Strands",                                         StrMStrands, English,3},
  { "Cartoons",                                        StrMCartoon, English,0},
  { "Molecular Surface",                               StrMMolSurf, English,0},

  { "Alambre",                                         StrMWirefr,  Spanish,0},
  { "Esqueleto",                                       StrMBackbn,  Spanish,0},
  { "Bastones",                                        StrMSticks,  Spanish,3},
  { "Espacio Completo",                                StrMSpacefl, Spanish,2},
  { "Bolas & Bastones",                                StrMBallStk, Spanish,0},
  { "Cintas",                                          StrMRibbons, Spanish,0},
  { "Hebras",                                          StrMStrands, Spanish,0},
  { "Dibujo",                                          StrMCartoon, Spanish,0},
  { "Superficie Molecular",                            StrMMolSurf, Spanish,11},

  { "Fil",                                             StrMWirefr,  French,0},
  { "Squelette",                                       StrMBackbn,  French,0},
  { "Bâtons",                                          StrMSticks,  French,0},
  { "Espace réél occupé",                              StrMSpacefl, French,0},
  { "Boules et Bâtons",                                StrMBallStk, French,1},
  { "Rubans",                                          StrMRibbons, French,0},
  { "Tresses",                                         StrMStrands, French,0},
  { "Ebauches",                                        StrMCartoon, French,5},
  { "Surface Molécular",                              StrMMolSurf, French,8},

  { "Fildiferro",                                      StrMWirefr,  Italian,0},
  { "Scheletro",                                       StrMBackbn,  Italian,0},
  { "Bastoncini",                                      StrMSticks,  Italian,3},
  { "Riempimento spaziale",                            StrMSpacefl, Italian,2},
  { "Palle e Bastoncini",                              StrMBallStk, Italian,0},
  { "Nastri",                                          StrMRibbons, Italian,0},
  { "Fili",                                            StrMStrands, Italian,0},
  { "Vignetta",                                        StrMCartoon, Italian,0},
  { "Superficie Molecolare",                           StrMMolSurf, Italian,11},

  { "Monochrome",                                      StrMMonochr, English,0},
  { "CPK",                                             StrMCPK,     English,0},
  { "Shapely",                                         StrMShapely, English,0},
  { "Group",                                           StrMGroup,   English,0},
  { "Chain",                                           StrMChain,   English,1},
  { "Temperature",                                     StrMTemp,    English,0},
  { "Structure",                                       StrMStruct,  English,2},
  { "User",                                            StrMUser,    English,0},
  { "Model",                                           StrMModel,   English,2},
  { "Alt",                                             StrMAlt,     English,0},

  { "Monocromo",                                       StrMMonochr, Spanish,0},
  { "CPK",                                             StrMCPK,     Spanish,0},
  { "Forma",                                           StrMShapely, Spanish,0},
  { "Grupo",                                           StrMGroup,   Spanish,0},
  { "Cadena",                                          StrMChain,   Spanish,2},
  { "Temperatura",                                     StrMTemp,    Spanish,0},
  { "Estructura",                                      StrMStruct,  Spanish,3},
  { "Usuario",                                         StrMUser,    Spanish,0},
  { "Modelo",                                          StrMModel,   Spanish,2},
  { "Alt",                                             StrMAlt,     Spanish,0},
  
  { "Monochrome",                                      StrMMonochr, French,0},
  { "CPK",                                             StrMCPK,     French,0},
  { "Forme",                                           StrMShapely, French,0},
  { "Groupe",                                          StrMGroup,   French,0},
  { "Chaîne",                                          StrMChain,   French,1},
  { "Température",                                     StrMTemp,    French,0},
  { "Structure",                                       StrMStruct,  French,0},
  { "Utilisateur",                                     StrMUser,    French,0},
  { "Modèle",                                          StrMModel,   French,2},
  { "Alt",                                             StrMAlt,     French,0},

  { "Monocromatico",                                   StrMMonochr, Italian,0},
  { "CPK",                                             StrMCPK,     Italian,0},
  { "Forma",                                           StrMShapely, Italian,0},
  { "Gruppo",                                          StrMGroup,   Italian,0},
  { "Catena",                                          StrMChain,   Italian,2},
  { "Temperatura",                                     StrMTemp,    Italian,0},
  { "Struttura",                                       StrMStruct,  Italian,3},
  { "Utente",                                          StrMUser,    Italian,0},
  { "Modello",                                         StrMModel,   Italian,2},
  { "Alt",                                             StrMAlt,     Italian,0},

  { "Slab Mode",                                       StrMSlab,    English,0},
  { "Hydrogens",                                       StrMHydr,    English,1},
  { "Hetero Atoms",                                    StrMHet,     English,2},
  { "Specular",                                        StrMSpec,    English,1},
  { "Shadows",                                         StrMShad,    English,1},
  { "Stereo",                                          StrMStereo,  English,5},
  { "Labels",                                          StrMLabel,   English,0},
  
  { "Modo Aserrado",                                   StrMSlab,    Spanish,6},
  { "Hidrógenos",                                      StrMHydr,    Spanish,1},
  { "Heteroátomos",                                    StrMHet,     Spanish,2},
  { "Especular",                                       StrMSpec,    Spanish,2},
  { "Sombras",                                         StrMShad,    Spanish,2},
  { "Estereo",                                         StrMStereo,  Spanish,6},
  { "Etiquetas",                                       StrMLabel,   Spanish,3},
  
  { "Vision en Coupe",                                 StrMSlab,    French,10},
  { "Hydrogènes",                                      StrMHydr,    French,1},
  { "Hétéroatomes",                                    StrMHet,     French,0},
  { "Reflets",                                         StrMSpec,    French,0},
  { "Ombres",                                          StrMShad,    French,0},
  { "Stéréo",                                          StrMStereo,  French,0},
  { "Labels",                                          StrMLabel,   French,0},
  
  { "Appiattito",                                      StrMSlab,    Italian,6},
  { "Idrogeni",                                        StrMHydr,    Italian,1},
  { "Eteroatomi",                                      StrMHet,     Italian,2},
  { "Speculare",                                       StrMSpec,    Italian,2},
  { "Ombre",                                           StrMShad,    Italian,2},
  { "Stereo",                                          StrMStereo,  Italian,5},
  { "Etichette",                                       StrMLabel,   Italian,3},
  
  { "Pick Off",                                        StrMPOff,    English,5},
  { "Pick Ident",                                      StrMPIdent,  English,5},
  { "Pick Distance",                                   StrMPDist,   English,5},
  { "Pick Monitor",                                    StrMPMon,    English,0},
  { "Pick Angle",                                      StrMPAng,    English,5},
  { "Pick Torsion",                                    StrMPTrsn,   English,5},
  { "Pick Label",                                      StrMPLabl,   English,5}, 
  { "Pick Centre",                                     StrMPCent,   English,5},
  { "Pick Coord",                                      StrMPCoord,  English,6},
  { "Pick Bond",                                       StrMPBond,   English,5},
  { "Rotate Bond",                                     StrMRBond,   English,0},
  { "Rotate Mol",                                      StrMRMol,    English,7},
  { "Rotate All",                                      StrMRAll,    English,7},
 
  { "Desactivar elección",                             StrMPOff,    Spanish,0},
  { "Elegir identificación",                           StrMPIdent,  Spanish,7},
  { "Elegir distancia",                                StrMPDist,   Spanish,9},
  { "Elegir monitor",                                  StrMPMon,    Spanish,13},
  { "Elegir ángulo",                                   StrMPAng,    Spanish,8},
  { "Elegir torsiones",                                StrMPTrsn,   Spanish,7},
  { "Elegir etiqueta",                                 StrMPLabl,   Spanish,10}, 
  { "Elegir centro",                                   StrMPCent,   Spanish,7},
  { "Elegir coordenadas",                              StrMPCoord,  Spanish,8},
  { "Elegir enlace",                                   StrMPBond,   Spanish,7},
  { "Girar enlace",                                    StrMRBond,   Spanish,0},
  { "Girar molécula",                                  StrMRMol,    Spanish,6},
  { "Girar todo",                                      StrMRAll,    Spanish,6},

  { "Désactiver Choix",                                StrMPOff,    French,0},
  { "Activer Identification",                          StrMPIdent,  French,8},
  { "Activer Distance",                                StrMPDist,   French,8},
  { "Activer Moniteur",                                StrMPMon,    French,8},
  { "Activer Angle",                                   StrMPAng,    French,8},
  { "Activer Torsion",                                 StrMPTrsn,   French,8},
  { "Activer Label",                                   StrMPLabl,   French,8}, 
  { "Activer Centre",                                  StrMPCent,   French,8},
  { "Activer Coord",                                   StrMPCoord,  French,8},
  { "Activer Liaison",                                 StrMPBond,   French,9},
  { "Tourner Liaison",                                 StrMRBond,   French,10},
  { "Tourner Molécule",                                StrMRMol,    French,9},
  { "Tourner Globalement",                             StrMRAll,    French,8},
 
  { "Elimina selezione",                               StrMPOff,    Italian,14},
  { "Identifica",                                      StrMPIdent,  Italian,0},
  { "Seleziona distanza",                              StrMPDist,   Italian,10},
  { "Seleziona monitor",                               StrMPMon,    Italian,0},
  { "Seleziona angolo",                                StrMPAng,    Italian,11},
  { "Seleziona torsione",                              StrMPTrsn,   Italian,10},
  { "Seleziona etichetta",                             StrMPLabl,   Italian,14}, 
  { "Seleziona centro",                                StrMPCent,   Italian,10},
  { "Seleziona coordinate",                            StrMPCoord,  Italian,11},
  { "Seleziona legame",                                StrMPBond,   Italian,10},
  { "Ruota legame",                                    StrMRBond,   Italian,0},
  { "Ruota molecola",                                  StrMRMol,    Italian,6},
  { "Ruota tutto",                                     StrMRAll,    Italian,6},
 
  { "GIF...",                                          StrMGIF,     English,0},
  { "PostScript...",                                   StrMPostscr, English,0},
  { "PPM...",                                          StrMPPM,     English,0},
  { "IRIS RGB...",                                     StrMIRGB,    English,5},
  { "Sun Raster...",                                   StrMSRast,   English,0},
  { "BMP...",                                          StrMBMP,     English,0},
  { "PICT...",                                         StrMPICT,    English,1},
  
  { "GIF...",                                          StrMGIF,     Spanish,0},
  { "PostScript...",                                   StrMPostscr, Spanish,0},
  { "PPM...",                                          StrMPPM,     Spanish,2},
  { "IRIS RGB...",                                     StrMIRGB,    Spanish,5},
  { "Sun Raster...",                                   StrMSRast,   Spanish,0},
  { "BMP...",                                          StrMBMP,     Spanish,0},
  { "PICT...",                                         StrMPICT,    Spanish,1},
  
  { "GIF...",                                          StrMGIF,     French,0},
  { "PostScript...",                                   StrMPostscr, French,0},
  { "PPM...",                                          StrMPPM,     French,0},
  { "IRIS RGB...",                                     StrMIRGB,    French,5},
  { "Sun Raster...",                                   StrMSRast,   French,0},
  { "BMP...",                                          StrMBMP,     French,0},
  { "PICT...",                                         StrMPICT,    French,1},
  
  { "GIF...",                                          StrMGIF,     Italian,0},
  { "PostScript...",                                   StrMPostscr, Italian,0},
  { "PPM...",                                          StrMPPM,     Italian,2},
  { "IRIS RGB...",                                     StrMIRGB,    Italian,5},
  { "Sun Raster...",                                   StrMSRast,   Italian,0},
  { "BMP...",                                          StrMBMP,     Italian,0},
  { "PICT...",                                         StrMPICT,    Italian,1},
  
  { "About RasMol...",                                 StrMAbout,   English,0},
  { "User Manual...",                                  StrMUserM,   English,0},
  
  { "Acerca del RasMol...",                            StrMAbout,   Spanish,0},
  { "Manual del Usuario...",                           StrMUserM,   Spanish,0},
  
  { "A propos de RasMol...",                           StrMAbout,   French,0},
  { "Manual utilisateur...",                           StrMUserM,   French,0},
  
  { "Informazioni su RasMol...",                       StrMAbout,   Italian,0},
  { "Manuale utente...",                               StrMUserM,   Italian,0},

  { "Undo",                                            StrMUndo,    English,0},
  { "Cut",                                             StrMCut,     English,1},
  { "Copy",                                            StrMCopy,    English,1},
  { "Paste",                                           StrMPaste,   English,0},
#ifdef APPLEMAC
  { "Clear",                                           StrMClear,   English,1},
#else
  { "Delete",                                          StrMDelete,  English,0},
#endif
  { "Select all",                                      StrMSelAll,  English,0},
 

  { "Deshacer",                                        StrMUndo,    Spanish,0},
  { "Cortar",                                          StrMCut,     Spanish,2},
  { "Copiar",                                          StrMCopy,    Spanish,1},
  { "Pegar",                                           StrMPaste,   Spanish,0},
#ifdef APPLEMAC
  { "Borrar",                                          StrMClear,   Spanish,0},
#else
  { "Borrar",                                          StrMDelete,  Spanish,0},
#endif
  { "Seleccionar todo",                                StrMSelAll,  Spanish,0},


  { "Annuler",                                         StrMUndo,    French,0},
  { "Couper",                                          StrMCut,     French,0},
  { "Copier",                                          StrMCopy,    French,1},
  { "Coller",                                          StrMPaste,   French,2},
#ifdef APPLEMAC
  { "Effacer",                                         StrMClear,   French,0},
#else
  { "Détruire",                                        StrMDelete,  French,0},
#endif
  { "Sélectionner tout",                               StrMSelAll,  French,0},

  { "Annulla",                                         StrMUndo,    Italian,0},
  { "Taglia",                                          StrMCut,     Italian,2},
  { "Copia",                                           StrMCopy,    Italian,1},
  { "Incolla",                                         StrMPaste,   Italian,0},
#ifdef APPLEMAC
  { "Cancella",                                        StrMClear,   Italian,0},
#else
  { "Elimina",                                         StrMDelete,  Italian,0},
#endif
  { "Seleziona tutto",                                 StrMSelAll,  Italian,0},
  
  { "File",                                            StrMFile,    English,0},
  { "Edit",                                            StrMEdit,    English,0},
  { "Display",                                         StrMDisplay, English,0},
  { "Colours",                                         StrMColour,  English,0},
  { "Options",                                         StrMOpt,     English,0},
  { "Settings",                                        StrMSettings,English,0},
  { "Export",                                          StrMExport,  English,1},
#ifdef APPLEMAC
  { "Window",                                          StrMWindow,  English,0},
#endif
  { "Help",                                            StrMHelp,    English,0},

  { "Archivo",                                         StrMFile,    Spanish,0},
  { "Editar",                                          StrMEdit,    Spanish,0},
  { "Mostrar",                                         StrMDisplay ,Spanish,0},
  { "Colores",                                         StrMColour,  Spanish,0},
  { "Opciones",                                        StrMOpt,     Spanish,0},
  { "Configuraciones",                                 StrMSettings,Spanish,3},
  { "Exportar",                                        StrMExport,  Spanish,1},
#ifdef APPLEMAC
  { "Ventana",                                         StrMWindow,  Spanish,0},
#endif
  { "Ayuda",                                           StrMHelp,    Spanish,1},


  { "Fichier",                                         StrMFile,    French,0},
  { "Editer",                                          StrMEdit,    French,0},
  { "Montrer",                                         StrMDisplay, French,0},
  { "Couleurs",                                        StrMColour,  French,0},
  { "Options",                                         StrMOpt,     French,0},
  { "Configuration",                                   StrMSettings,French,3},
  { "Exporter",                                        StrMExport,  French,1},
#ifdef APPLEMAC
  { "Fenêtre",                                         StrMWindow,  French,0},
#endif
  { "Aide",                                            StrMHelp,    French,0},

  { "Archivio",                                        StrMFile,    Italian,0},
  { "Modifica",                                        StrMEdit,    Italian,0},
  { "Mostra",                                          StrMDisplay ,Italian,0},
  { "Colori",                                          StrMColour,  Italian,0},
  { "Opzioni",                                         StrMOpt,     Italian,0},
  { "Impostazioni",                                    StrMSettings,Italian,3},
  { "Esporta",                                         StrMExport,  Italian,1},
#ifdef APPLEMAC
  { "Finestra",                                        StrMWindow,  Italian,0},
#endif
  { "Aiuto",                                           StrMHelp,    Italian,1},

#ifdef APPLEMAC
  { "Main Window",                                     StrMMainWin,  English,0},
  { "Command Line",                                    StrMCmndLin,  English,0},

  { "Ventana principal",                               StrMMainWin,  Spanish,0},
  { "Línea de comando",                                StrMCmndLin,  Spanish,0},

  { "Fenêtre Principale",                              StrMMainWin,  French,0},
  { "Ligne de Commande",                               StrMCmndLin,  French,0},

  { "Finestra Principale",                             StrMMainWin,  Italian,0},
  { "Linea di Comando",                                StrMCmndLin,  Italian,0},
#endif


#else

  { "&Open ...",                                       StrMOpen,    English,0},
  { "&Information",                                    StrMInfo,    English,0},
  { "&Close",                                          StrMClose,   English,0},
  { "&Print",                                          StrMPrint,   English,0},
  { "P&rint Setup",                                    StrMPSetup,  English,0},
  { "&Exit",                                           StrMExit,    English,0},

  { "&Abrir ...",                                      StrMOpen,    Spanish,0},
  { "&Información",                                    StrMInfo,    Spanish,0},
  { "&Cerrar",                                         StrMClose,   Spanish,0},
  { "Im&primir",                                       StrMPrint,   Spanish,0},
  { "Con&figurar impresora",                           StrMPSetup,  Spanish,3},
  { "&Salir",                                          StrMExit,    Spanish,0},

  { "&Ouvrir ...",                                     StrMOpen,    French,0},
  { "&Information",                                    StrMInfo,    French,0},
  { "&Fermer",                                         StrMClose,   French,0},
  { "Im&primer",                                       StrMPrint,   French,2},
  { "&Configuration des Pages",                        StrMPSetup,  French,0},
  { "&Terminer",                                       StrMExit,    French,0},

  { "&Apri ...",                                       StrMOpen,    Italian,0},
  { "&Informazione",                                   StrMInfo,    Italian,0},
  { "&Chiudi",                                         StrMClose,   Italian,0},
  { "St&ampa",                                         StrMPrint,   Italian,0},
  { "Imp&osta pagina",                                 StrMPSetup,  Italian,3},
  { "&Esci",                                           StrMExit,    Italian,0},

  { "&Wireframe",                                      StrMWirefr,  English,0},
  { "&Backbone",                                       StrMBackbn,  English,0},
  { "S&ticks",                                         StrMSticks,  English,1},
  { "&Spacefill",                                      StrMSpacefl, English,0},
  { "&Ball && Stick",                                  StrMBallStk, English,0},
  { "&Ribbons",                                        StrMRibbons, English,0},
  { "Str&ands",                                        StrMStrands, English,3},
  { "&Cartoons",                                       StrMCartoon, English,0},
  { "&Molecular Surface",                              StrMMolSurf, English,0},

  { "&Alambre",                                        StrMWirefr,  Spanish,0},
  { "&Esqueleto",                                      StrMBackbn,  Spanish,0},
  { "Bas&tones",                                       StrMSticks,  Spanish,3},
  { "Es&pacio Completo",                               StrMSpacefl, Spanish,2},
  { "&Bolas && Bastones",                              StrMBallStk, Spanish,0},
  { "&Cintas",                                         StrMRibbons, Spanish,0},
  { "&Hebras",                                         StrMStrands, Spanish,0},
  { "&Dibujo",                                         StrMCartoon, Spanish,0},
  { "Superficie &Molecular",                           StrMMolSurf, Spanish,11},

  { "&Fil",                                            StrMWirefr,  French,0},
  { "&Squelette",                                      StrMBackbn,  French,0},
  { "&Bâtons",                                         StrMSticks,  French,0},
  { "&Espace réel occupé",                             StrMSpacefl, French,0},
  { "B&oules et Bâtons",                               StrMBallStk, French,1},
  { "&Ribbons",                                        StrMRibbons, French,0},
  { "&Tresses",                                        StrMStrands, French,0},
  { "Ebauc&hes",                                       StrMCartoon, French,5},
  { "Surface &Molécular",                              StrMMolSurf, French,8},

  { "&Fildiferro",                                     StrMWirefr,  Italian,0},
  { "&Scheletro",                                      StrMBackbn,  Italian,0},
  { "Bas&toncini",                                     StrMSticks,  Italian,3},
  { "Ri&empimento spaziale",                           StrMSpacefl, Italian,2},
  { "&Palle e Bastoncini",                             StrMBallStk, Italian,0},
  { "&Nastri",                                         StrMRibbons, Italian,0},
  { "&Fili",                                           StrMStrands, Italian,0},
  { "&Vignetta",                                       StrMCartoon, Italian,0},
  { "Superficie &Molecolare",                          StrMMolSurf, Italian,11},

  { "&Monochrome",                                     StrMMonochr, English,0},
  { "&CPK",                                            StrMCPK,     English,0},
  { "&Shapely",                                        StrMShapely, English,0},
  { "&Group",                                          StrMGroup,   English,0},
  { "C&hain",                                          StrMChain,   English,1},
  { "&Temperature",                                    StrMTemp,    English,0},
  { "St&ructure",                                      StrMStruct,  English,2},
  { "&User",                                           StrMUser,    English,0},
  { "Mo&del",                                          StrMModel,   English,2},
  { "&Alt",                                            StrMAlt,     English,0},

  { "&Monocromo",                                      StrMMonochr, Spanish,0},
  { "&CPK",                                            StrMCPK,     Spanish,0},
  { "&Forma",                                          StrMShapely, Spanish,0},
  { "&Grupo",                                          StrMGroup,   Spanish,0},
  { "Ca&dena",                                         StrMChain,   Spanish,2},
  { "&Temperatura",                                    StrMTemp,    Spanish,0},
  { "Est&ructura",                                     StrMStruct,  Spanish,3},
  { "&Usuario",                                        StrMUser,    Spanish,0},
  { "Mo&delo",                                         StrMModel,   Spanish,2},
  { "&Alt",                                            StrMAlt,     Spanish,0},
  
  { "&Monochrome",                                     StrMMonochr, French,0},
  { "&CPK",                                            StrMCPK,     French,0},
  { "&Forme",                                          StrMShapely, French,0},
  { "&Groupe",                                         StrMGroup,   French,0},
  { "C&haîne",                                         StrMChain,   French,1},
  { "&Température",                                    StrMTemp,    French,0},
  { "&Structure",                                      StrMStruct,  French,0},
  { "&Utilisateur",                                    StrMUser,    French,0},
  { "Mo&dèle",                                         StrMModel,   French,2},
  { "&Alt",                                            StrMAlt,     French,0},

  { "&Monocromatico",                                  StrMMonochr, Italian,0},
  { "&CPK",                                            StrMCPK,     Italian,0},
  { "&Forma",                                          StrMShapely, Italian,0},
  { "&Gruppo",                                         StrMGroup,   Italian,0},
  { "Ca&tena",                                         StrMChain,   Italian,2},
  { "&Temperatura",                                    StrMTemp,    Italian,0},
  { "Str&uttura",                                      StrMStruct,  Italian,3},
  { "&Utente",                                         StrMUser,    Italian,0},
  { "Mo&dello",                                        StrMModel,   Italian,2},
  { "&Alt",                                            StrMAlt,     Italian,0},

  { "&Slab Mode",                                      StrMSlab,    English,0},
  { "H&ydrogens",                                      StrMHydr,    English,1},
  { "He&tero Atoms",                                   StrMHet,     English,2},
  { "S&pecular",                                       StrMSpec,    English,1},
  { "S&hadows",                                        StrMShad,    English,1},
  { "Stere&o",                                         StrMStereo,  English,5},
  { "&Labels",                                         StrMLabel,   English,0},
  
  { "Modo A&serrado",                                  StrMSlab,    Spanish,6},
  { "H&idrógenos",                                     StrMHydr,    Spanish,1},
  { "He&teroátomos",                                   StrMHet,     Spanish,2},
  { "Es&pecular",                                      StrMSpec,    Spanish,2},
  { "So&mbras",                                        StrMShad,    Spanish,2},
  { "Estere&o",                                        StrMStereo,  Spanish,6},
  { "Eti&quetas",                                      StrMLabel,   Spanish,3},
  
  { "Vision en &Coupe",                                StrMSlab,    French,10},
  { "H&ydrogènes",                                     StrMHydr,    French,1},
  { "&Hétéroatomes",                                   StrMHet,     French,0},
  { "&Reflets",                                        StrMSpec,    French,0},
  { "&Ombres",                                         StrMShad,    French,0},
  { "&Stéréo",                                         StrMStereo,  French,0},
  { "&Labels",                                         StrMLabel,   French,0},
  
  { "Appiat&tito",                                     StrMSlab,    Italian,6},
  { "I&drogeni",                                       StrMHydr,    Italian,1},
  { "Et&eroatomi",                                     StrMHet,     Italian,2},
  { "&Speculare",                                      StrMSpec,    Italian,0},
  { "Om&bre",                                          StrMShad,    Italian,2},
  { "Stere&o",                                         StrMStereo,  Italian,5},
  { "Eti&chette",                                      StrMLabel,   Italian,3},
  
  { "Pick &Off",                                       StrMPOff,    English,5},
  { "Pick &Ident",                                     StrMPIdent,  English,5},
  { "Pick &Distance",                                  StrMPDist,   English,5},
  { "&Pick Monitor",                                   StrMPMon,    English,0},
  { "Pick &Angle",                                     StrMPAng,    English,5},
  { "Pick &Torsion",                                   StrMPTrsn,   English,5},
  { "Pick &Label",                                     StrMPLabl,   English,5}, 
  { "Pick &Centre",                                    StrMPCent,   English,5},
  { "Pick C&oord",                                     StrMPCoord,  English,6},
  { "Pick &Bond",                                      StrMPBond,   English,5},
  { "&Rotate Bond",                                    StrMRBond,   English,0},
  { "Rotate &Mol",                                     StrMRMol,    English,7},
  { "Rotate &All",                                     StrMRAll,    English,7},
 
  { "&Desactivar elección",                            StrMPOff,    Spanish,0},
  { "Elegir &identificación",                          StrMPIdent,  Spanish,7},
  { "Elegir di&stancia",                               StrMPDist,   Spanish,9},
  { "Elegir monito&r",                                 StrMPMon,    Spanish,13},
  { "Elegir á&ngulo",                                  StrMPAng,    Spanish,8},
  { "Elegir &torsiones",                               StrMPTrsn,   Spanish,7},
  { "Elegir eti&queta",                                StrMPLabl,   Spanish,10}, 
  { "Elegir &centro",                                  StrMPCent,   Spanish,7},
  { "Elegir c&oordenadas",                             StrMPCoord,  Spanish,8},
  { "Elegir &enlace",                                 StrMPBond,   Spanish,7},
  { "&Girar enlace",                                  StrMRBond,   Spanish,0},
  { "Girar &molécula",                                 StrMRMol,    Spanish,6},
  { "Girar &todo",                                     StrMRAll,    Spanish,6},

  { "&Désactiver Choix",                               StrMPOff,    French,0},
  { "Activer &Identification",                         StrMPIdent,  French,8},
  { "Activer &Distance",                               StrMPDist,   French,8},
  { "Activer &Moniteur",                               StrMPMon,    French,8},
  { "Activer &Angle",                                  StrMPAng,    French,8},
  { "Activer &Torsion",                                StrMPTrsn,   French,8},
  { "Activer &Label",                                  StrMPLabl,   French,8}, 
  { "Activer &Centre",                                 StrMPCent,   French,8},
  { "Activer &Coord",                                  StrMPCoord,  French,8},
  { "Activer L&iaison",                                StrMPBond,   French,9},
  { "Tourner Li&aison",                                StrMRBond,   French,10},
  { "Tourner M&olécule",                               StrMRMol,    French,9},
  { "Tourner &Globalement",                            StrMRAll,    French,8},
 
  { "Disattiva sele&zione",                            StrMPOff,    Italian,14},
  { "&Identifica",                                     StrMPIdent,  Italian,0},
  { "Seleziona &distanza",                             StrMPDist,   Italian,10},
  { "&Seleziona monitor",                              StrMPMon,    Italian,0},
  { "Seleziona a&ngolo",                               StrMPAng,    Italian,11},
  { "Seleziona &torsione",                             StrMPTrsn,   Italian,10},
  { "Seleziona etic&hetta",                            StrMPLabl,   Italian,14}, 
  { "Seleziona &centro",                               StrMPCent,   Italian,10},
  { "Seleziona c&oordinate",                           StrMPCoord,  Italian,11},
  { "Seleziona &legame",                               StrMPBond,   Italian,10},
  { "&Ruota legame",                                   StrMRBond,   Italian,0},
  { "Ruota &molecola",                                 StrMRMol,    Italian,6},
  { "Ruota &tutto",                                    StrMRAll,    Italian,6},
 
  { "&GIF",                                            StrMGIF,     English,0},
  { "&EPSF",                                           StrMPostscr, English,0},
  { "&PPM",                                            StrMPPM,     English,0},
  { "&RAST",                                           StrMSRast,   English,0},
  { "&BMP",                                            StrMBMP,     English,0},
  
  { "&GIF",                                            StrMGIF,     Spanish,0},
  { "&EPSF",                                           StrMPostscr, Spanish,0},
  { "&PPM",                                            StrMPPM,     Spanish,0},
  { "&RAST",                                           StrMSRast,   Spanish,0},
  { "&BMP",                                            StrMBMP,     Spanish,0},
  
  { "&GIF",                                            StrMGIF,     French,0},
  { "&EPSF",                                           StrMPostscr, French,0},
  { "&PPM",                                            StrMPPM,     French,0},
  { "&RAST",                                           StrMSRast,   French,0},
  { "&BMP",                                            StrMBMP,     French,0},
  
  { "&GIF",                                            StrMGIF,     Italian,0},
  { "&EPSF",                                           StrMPostscr, Italian,0},
  { "&PPM",                                            StrMPPM,     Italian,0},
  { "&RAST",                                           StrMSRast,   Italian,0},
  { "&BMP",                                            StrMBMP,     Italian,0},
  
  { "&About RasMol...",                                StrMAbout,   English,0},
  { "&User Manual...",                                 StrMUserM,   English,0},
  
  { "&Acerca del RasMol...",                           StrMAbout,   Spanish,0},
  { "&Manual del Usuario...",                          StrMUserM,   Spanish,0},

  { "&A propos de RasMol...",                          StrMAbout,   French,0},
  { "&Manual utilisateur...",                          StrMUserM,   French,0},
  
  { "&Informazioni su RasMol...",                      StrMAbout,   Italian,0},
  { "&Manuale utente...",                              StrMUserM,   Italian,0},

  { "&Undo",                                           StrMUndo,    English,0},
  { "C&ut",                                            StrMCut,     English,1},
  { "C&opy",                                           StrMCopy,    English,1},
  { "&Paste",                                          StrMPaste,   English,0},
  { "&Delete",                                         StrMDelete,  English,0},
  { "&Select all",                                     StrMSelAll,  English,0},
 
  { "&Deshacer",                                       StrMUndo,    Spanish,0},
  { "Co&rtar",                                         StrMCut,     Spanish,2},
  { "C&opiar",                                         StrMCopy,    Spanish,1},
  { "&Pegar",                                          StrMPaste,   Spanish,0},
  { "&Borrar",                                         StrMDelete,  Spanish,0},
  { "&Seleccionar todo",                               StrMSelAll,  Spanish,0},
   
  { "&Annuler",                                        StrMUndo,    French,0},
  { "&Couper",                                         StrMCut,     French,0},
  { "C&opier",                                         StrMCopy,    French,1},
  { "Co&ller",                                         StrMPaste,   French,2},
  { "&Détruire",                                       StrMDelete,  French,0},
  { "&Sélectionner tout",                              StrMSelAll,  French,0},

  { "&Annulla",                                        StrMUndo,    Italian,0},
  { "Ta&glia",                                         StrMCut,     Italian,2},
  { "C&opia",                                          StrMCopy,    Italian,1},
  { "&Incolla",                                        StrMPaste,   Italian,0},
  { "&Cancella",                                       StrMDelete,  Italian,0},
  { "&Seleziona tutto",                                StrMSelAll,  Italian,0},
  
  { "&File",                                           StrMFile,    English,0},
  { "&Edit",                                           StrMEdit,    English,0},
  { "&Display",                                        StrMDisplay, English,0},
  { "&Colours",                                        StrMColour,  English,0},
  { "&Options",                                        StrMOpt,     English,0},
  { "&Settings",                                       StrMSettings,English,0},
  { "E&xport",                                         StrMExport,  English,1},
  { "&Help",                                           StrMHelp,    English,0},

  { "&Archivo",                                        StrMFile,    Spanish,0},
  { "&Editar",                                         StrMEdit,    Spanish,0},
  { "&Mostrar",                                        StrMDisplay ,Spanish,0},
  { "&Colores",                                        StrMColour,  Spanish,0},
  { "&Opciones",                                       StrMOpt,     Spanish,0},
  { "Con&figuraciones",                                StrMSettings,Spanish,3},
  { "E&xportar",                                       StrMExport,  Spanish,1},
  { "A&yuda",                                          StrMHelp,    Spanish,1},

  { "&Fichier",                                        StrMFile,    French,0},
  { "&Editer",                                         StrMEdit,    French,0},
  { "&Montrer",                                        StrMDisplay, French,0},
  { "&Couleurs",                                       StrMColour,  French,0},
  { "&Options",                                        StrMOpt,     French,0},
  { "Con&figuration",                                  StrMSettings,French,3},
  { "E&xporter",                                       StrMExport,  French,1},
  { "&Aide",                                           StrMHelp,    French,0},

  { "&Archivio",                                       StrMFile,    Italian,0},
  { "&Modifica",                                       StrMEdit,    Italian,0},
  { "&Mostra",                                         StrMDisplay ,Italian,0},
  { "&Colori",                                         StrMColour,  Italian,0},
  { "&Opzioni",                                        StrMOpt,     Italian,0},
  { "Con&figurazione",                                 StrMSettings,Italian,3},
  { "E&sporta",                                        StrMExport,  Italian,1},
  { "A&iuto",                                          StrMHelp,    Italian,1},

#endif

  { "PDB file name:",                                  StrPrmtPDB,  English,0},
  { "Image file name:",                                StrPrmtImg,  English,0},
  { "Molecule file name:",                             StrPrmtMol,  English,0},

  { "Nombre del archivo PDB:",                         StrPrmtPDB,  Spanish,0},
  { "Nombre del archivo de imagen:",                   StrPrmtImg,  Spanish,0},
  { "Nombre del archivo de molécula:",                 StrPrmtMol,  Spanish,0},

  { "Nom du fichier PDB:",                             StrPrmtPDB,  French,0},
  { "Nom du fichier Image:",                           StrPrmtImg,  French,0},
  { "Nom du fichier de Molécule:",                     StrPrmtMol,  French,0},

  { "Nome documento PDB:",                             StrPrmtPDB,  Italian,0},
  { "Nome documento immagine:",                        StrPrmtImg,  Italian,0},
  { "Nome documento molecola:",                        StrPrmtMol,  Italian,0},

  { "Warning: ",                                       StrWarn,     English,0},
  { "Cuidado: ",                                       StrWarn,     Spanish,0},
  { "Avertissement: ",                                 StrWarn,     French,0},
  { "Attenzione: ",                                    StrWarn,     Italian,0},

  { "Chain",                                           StrChain,    English,0},
  { "Cadena",                                          StrChain,    Spanish,0},
  { "Chaîne",                                          StrChain,    French,0},
  { "Catena",                                          StrChain,    Italian,0}
  
};
 
 
void SwitchLang( language lang ) {

  int ii;
  int kmsg;

  kmsg = sizeof(langstrs)/sizeof(langstr);
  for (ii = 0; ii < MaxStrFlag; ii++) {
     MsgStrs[ii] = (char *)0;
     MsgLens[ii] = 0;
     MsgAuxl[ii] = 0;
  }
  for (ii = 0; ii < kmsg; ii++) {
    if (langstrs[ii].lang == lang) {
      MsgStrs[langstrs[ii].msgno] = langstrs[ii].msg;
      MsgLens[langstrs[ii].msgno] = strlen(langstrs[ii].msg);
      MsgAuxl[langstrs[ii].msgno] = langstrs[ii].aux;
    }
  }
  for (ii = 0; ii < kmsg; ii++) {
    if (langstrs[ii].lang == English && !(MsgStrs[langstrs[ii].msgno])) {
      WriteString("\nError: Translation missing for ...\n");
      WriteString(langstrs[ii].msg);
      MsgStrs[langstrs[ii].msgno] = langstrs[ii].msg;
      MsgLens[langstrs[ii].msgno] = strlen(langstrs[ii].msg);
      MsgAuxl[langstrs[ii].msgno] = langstrs[ii].aux;
    }
  }
  if (Interactive)
    ReDrawWindow();
}
