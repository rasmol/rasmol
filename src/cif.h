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
/**********************************************************************
 *                                                                    *
 * cif.h                                                              *
 *                                                                    *
 * Simplified CIF definitions derived from CBFlib by P. Ellis         *
 * Mods by H. J. Bernstein, Bernstein + Sons, August 1998             *
 * yaya@bernstein-plus-sons.com                                       *
 *                                                                    *
 * Rev 21 February 1999
 **********************************************************************/

/**********************************************************************
 *                                 NOTICE                             *
 * Creative endeavors depend on the lively exchange of ideas. There   *
 * are laws and customs which establish rights and responsibilities   *
 * for authors and the users of what authors create.  This notice     *
 * is not intended to prevent you from using the software and         *
 * documents in this package, but to ensure that there are no         *
 * misunderstandings about terms and conditions of such use.          *
 *                                                                    *
 * Please read the following notice carefully.  If you do not         *
 * understand any portion of this notice, please seek appropriate     *
 * professional legal advice before making use of the software and    *
 * documents included in this software package.  In addition to       *
 * whatever other steps you may be obliged to take to respect the     *
 * intellectual property rights of the various parties involved, if   *
 * you do make use of the software and documents in this package,     *
 * please give credit where credit is due by citing this package,     *
 * its authors and the URL or other source from which you obtained    *
 * it, or equivalent primary references in the literature with the    *
 * same authors.                                                      *
 *                                                                    *
 * Some of the software and documents included within this software   *
 * package are the intellectual property of various parties, and      *
 * placement in this package does not in any way imply that any       *
 * such rights have in any way been waived or diminished.             *
 *                                                                    *
 * With respect to any software or documents for which a copyright    *
 * exists, ALL RIGHTS ARE RESERVED TO THE OWNERS OF SUCH COPYRIGHT.   *
 *                                                                    *
 * Even though the authors of the various documents and software      *
 * found here have made a good faith effort to ensure that the        *
 * documents are correct and that the software performs according     *
 * to its documentation, and we would greatly appreciate hearing of   *
 * any problems you may encounter, the programs and documents any     *
 * files created by the programs are provided **AS IS** without any   *
 * warranty as to correctness, merchantability or fitness for any     *
 * particular or general use.                                         *
 *                                                                    *
 * THE RESPONSIBILITY FOR ANY ADVERSE CONSEQUENCES FROM THE USE OF    *
 * PROGRAMS OR DOCUMENTS OR ANY FILE OR FILES CREATED BY USE OF THE   *
 * PROGRAMS OR DOCUMENTS LIES SOLELY WITH THE USERS OF THE PROGRAMS   *
 * OR DOCUMENTS OR FILE OR FILES AND NOT WITH AUTHORS OF THE          *
 * PROGRAMS OR DOCUMENTS.                                             *
 **********************************************************************/

/**********************************************************************
 *                             The IUCr Policy                        *
 *                                    on                              *
 *     the Use of the Crystallographic Information File (CIF)         *
 *                                                                    *
 * The Crystallographic Information File (Hall, Allen & Brown,        *
 * 1991) is, as of January 1992, the recommended method for           *
 * submitting publications to Acta Crystallographica Section C. The   *
 * International Union of Crystallography holds the Copyright on      *
 * the CIF, and has applied for Patents on the STAR File syntax       *
 * which is the basis for the CIF format.                             *
 *                                                                    *
 * It is a principal objective of the IUCr to promote the use of      *
 * CIF for the exchange and storage of scientific data. The IUCr's    *
 * sponsorship of the CIF development was motivated by its            *
 * responsibility to its scientific journals, which set the           *
 * standards in crystallographic publishing. The IUCr intends that    *
 * CIFs will be used increasingly for electronic submission of        *
 * manuscripts to these journals in future. The IUCr recognises       *
 * that, if the CIF and the STAR File are to be adopted as a means    *
 * for universal data exchange, the syntax of these files must be     *
 * strictly and uniformly adhered to. Even small deviations from      *
 * the syntax would ultimately cause the demise of the universal      *
 * file concept. Through its Copyrights and Patents the IUCr has      *
 * taken the steps needed to ensure strict conformance with this      *
 * syntax.                                                            *
 *                                                                    *
 * The IUCr policy on the use of the CIF and STAR File processes is   *
 * as follows:                                                        *
 * _________________________________________________________________  *
 *                                                                    *
 *  * 1 CIFs and STAR Files may be generated, stored or transmitted,  *
 *    without permission or charge, provided their purpose is not     *
 *    specifically for profit or commercial gain, and provided that   *
 *    the published syntax is strictly adhered to.                    *
 *  * 2 Computer software may be developed for use with CIFs or STAR  *
 *    files, without permission or charge, provided it is distributed *
 *    in the public domain. This condition also applies to software   *
 *    for which a charge is made, provided that its primary function  *
 *    is for use with files that satisfy condition 1 and that it is   *
 *    distributed as a minor component of a larger package of         *
 *    software.                                                       *
 *  * 3 Permission will be granted for the use of CIFs and STAR Files *
 *    for specific commercial purposes (such as databases or network  *
 *    exchange processes), and for the distribution of commercial     *
 *    CIF/STAR software, on written application to the IUCr Executive *
 *    Secretary, 2 Abbey Square, Chester CH1 2HU, England. The        *
 *    nature, terms and duration of the licences granted will be      *
 *    determined by the IUCr Executive and Finance Committees.        *
 *                                                                    *
 * _________________________________________________________________  *
 *                                                                    *
 * In summary, the IUCr wishes to promote the use of the STAR File    *
 * concepts as a standard universal data file. It will insist on      *
 * strict compliance with the published syntax for all                *
 * applications. To assist with this compliance, the IUCr provides    *
 * public domain software for checking the logical integrity of a     *
 * CIF, and for validating the data name definitions contained        *
 * within a CIF. Detailed information on this software, and the       *
 * associated dictionaries, may be obtained from the IUCr Office at   *
 * 5 Abbey Square, Chester CH1 2HU, England.                          *
 **********************************************************************/

#ifndef _CIF_
#define _CIF_

#ifdef __cplusplus

extern "C" {

#endif

#ifdef USE_CBFLIB

#include <cbf.h>


  /* Read a file */
int cif_read_file (cbf_handle handle, FILE *stream);
 
#define cif_column_number(handle,column_number) cbf_column_number((handle),(column_number) )
#define cif_count_rows(handle,rows) cbf_count_rows((handle),(rows) )
#define cif_datablock_name(handle,dbname) cbf_datablock_name((handle),(const char **)(dbname))
#define cif_findtag(handle,tag) cbf_find_tag((handle), (const char *)(tag) )
#define cif_find_column(handle,column) cbf_find_column((handle), (column))
#define cif_free_handle(handle) cbf_free_handle((handle) )
#define cif_make_handle(handle) cbf_make_handle((handle))
#define cif_rewind_datablock(handle) cbf_rewind_datablock((handle))
#define cif_select_column(handle,column) cbf_select_column((handle), (column))
#define cif_select_row(handle,rownum) cbf_select_row((handle), (rownum))
#define cif_get_value(handle,value) cbf_get_value((handle), (const char **)(value))
#define CIF_TOKEN_NULL CBF_TOKEN_NULL
#define CIF_PRFX "_"
typedef cbf_handle cif_handle;

#else

#define CIF_PRFX "_"
#if !defined(IBMPC) || defined(_WIN32)
#ifndef __far
#define __far
#endif
#endif

#define CIF_FORMAT           0x00000001  /*     1 */
#define CIF_ALLOC            0x00000002  /*     2 */
#define CIF_ARGUMENT         0x00000004  /*     4 */
#define CIF_IDENTICAL        0x00002000  /*  8192 */
#define CIF_NOTFOUND         0x00004000  /* 16384 */

#define cif_failnez(f) { int err; err = (f); if (err) return err; }

#define cif_onfailnez(f,c) { int err; err = (f); \
         if (err) {\
           { c; } \
           return err; }}
  /* Node types */

typedef enum
{
  CIF_UNDEFINED,        /* Undefined */
  CIF_LINK,             /* Link      */
  CIF_ROOT,             /* Root      */
  CIF_DATABLOCK,        /* Datablock */
  CIF_CATEGORY,         /* Category  */
  CIF_COLUMN            /* Column    */
}
CIF_NODETYPE;

  /* Token Type Strings */
  
#define CIF_TOKEN_NULL       '\377'
#define CIF_TOKEN_WORD       '\300'
#define CIF_TOKEN_SQSTRING   '\301'
#define CIF_TOKEN_DQSTRING   '\302'
#define CIF_TOKEN_SCSTRING   '\303'
#define CIF_TOKEN_BIN        '\304'
#define CIF_TOKEN_BIN_TMP    '\305'



  /* Node structure */

typedef struct cif_node_struct
{
  CIF_NODETYPE type;
  char *name;
  struct cif_node_struct *parent;
  struct cif_node_struct *link;
  unsigned int children;
  size_t child_size;
  struct cif_node_struct **child;
}
cif_node;


  /* cif handle */
typedef struct
{
  cif_node __far *node;
  int row, search_row;
}
cif_handle_struct;
typedef cif_handle_struct __far *cif_handle;

  /* File structure */

typedef struct
{
  FILE *stream;                 /* File pointer */

  unsigned int connections;     /* Number of pointers to this structure */
  int          bits [2];        /* Buffer for bitwise reads and writes  */
  int          last_read;       /* The last character read              */
  unsigned int line;            /* Current line                         */
  unsigned int column;          /* Current column                       */
  size_t       text_size;       /* Size of the text buffer              */
  size_t       text_used;       /* Number in use                        */
 long          fpos;            /* File position                        */
 long          fend;            /* File end                             */
 
  char *text;                   /* Text buffer */
}
cif_file;

typedef union
{
  int          errorcode;
  char        __far *text;
  cif_node    __far *node;
} YYSTYPE;

#define	DATA	258
#define	LOOP	259
#define	ITEM	260
#define	CATEGORY	261
#define	COLUMN	262
#define	STRING	263
#define	CIFWORD	264
#define	BINARY	265
#define	UNKNOWN	266
#define	COMMENT	267
#ifdef  ERROR
#undef  ERROR
#endif
#define	ERROR	268


#include <stdlib.h>

  /* Prototypes for memory */

  /* Allocate a block of memory */
int cbf_alloc (void __far * __far *new_block, size_t __far *new_nelem, 
  size_t elsize, size_t nelem);
  /* Reallocate a block of memory (never lose the old block on failure) */
int cbf_realloc (void __far * __far *old_block, size_t __far *old_nelem, 
  size_t elsize, size_t nelem);
  /* Free a block of memory */
int cbf_free (void __far * __far *old_block, size_t __far *old_nelem);


  /* Prototypes for tree routines */


  /* Reallocate a block of memory (never lose the old block on failure) */
int cif_realloc (void __far * __far *old_block, size_t __far *old_nelem, 
  size_t elsize, size_t nelem);
  /* Allocate a block of memory */
int cif_alloc (void __far * __far *new_block, size_t __far *new_nelem, 
  size_t elsize, size_t nelem);
  /* free a block of memory */
int cif_free (void __far * __far *old_block, size_t __far *old_nelem);
  /* These function will not trace a link */
  /* Free a node */
int cif_free_node (cif_node __far *node);
  /* Set the number of children */
int cif_set_children (cif_node __far *node, unsigned int children);
  /* Change a link */
int cif_set_link (cif_node __far *link, cif_node __far *node);
  /* Add a child link */
int cif_add_link (cif_node __far *link, cif_node __far *child);
  /* Set a link successively to each child link */
int cif_shift_link (cif_node __far *link);
  /* These function will trace a link */
  /* Trace a link */
cif_node __far *cif_get_link (const cif_node __far *node);
  /* Find a child node */
int cif_find_child (cif_node __far * __far *child, const cif_node __far *node, 
  const char __far *name);
  /* Find a child node, accepting the last match  */
int cif_find_last_child (cif_node __far * __far *child, 
  const cif_node __far *node,  const char __far *name);
  /* Find a parent node */
int cif_find_parent (cif_node __far * __far *parent, 
  const cif_node __far *node, 
  CIF_NODETYPE type);
  /* Count the number of children */
int cif_count_children (unsigned int *children, const cif_node __far *node);
  /* Get the index of a child */
int cif_child_index (unsigned int *index, const cif_node __far *node);
  /* Get the specified child */
int cif_get_child (cif_node __far * __far *child, const cif_node __far *node, 
  unsigned int index);
  /* Add a child to a node */
int cif_add_child (cif_node __far *node, cif_node __far *child);
  /* Add a child to a node with duplicates allowed */
int cif_add_new_child (cif_node __far *node, cif_node __far *child);
  /* Get the name of a node */
int cif_get_name (char __far * __far *name, cif_node __far *node);
  /* All of the following functions assume that the string arguments
     have been created using cif_copy_string and that no pointers to
     the strings are retained by the calling functions */
  /* Name a node */
int cif_name_node (cif_node __far *node, const char __far *name);
  /* Name a node allowing for duplicates  */
int cif_name_new_node (cif_node __far *node, const char __far *name);
  /* Make a new node */
int cif_make_node (cif_node __far * __far *node, CIF_NODETYPE type, 
  const char __far *name);
  /* Make a new node allowing for duplicates */
int cif_make_new_node (cif_node __far * __far *node, CIF_NODETYPE type, 
  const char __far *name);
  /* Make a new child node */
int cif_make_child (cif_node __far * __far *child, cif_node __far *node, 
     CIF_NODETYPE type, char __far *name);
  /* Make a new child node, with duplicates allowed */
int cif_make_new_child (cif_node __far * __far *child, cif_node __far *node,
     CIF_NODETYPE type, const char __far *name);
  /* Get the value of a row */
int cif_get_columnrow (char __far * __far *value, 
  const cif_node __far *column, 
  unsigned int row);
  /* Set the value of a row */
int cif_set_columnrow (cif_node __far *column, unsigned int row, 
  const char __far *value);
  /* Insert a value in a column */
int cif_insert_columnrow (cif_node __far *column, unsigned int row, 
  const char __far *value);
  /* Delete a value from a column */
int cif_delete_columnrow (cif_node __far *column, unsigned int row);
  /* Add a value to a column */
int cif_add_columnrow (cif_node __far *column, const char __far *value);
  /* Free a value */
int cif_free_value (char __far * __far *value);
  /* Copy a string */
char __far *cbf_copy_string (char __far *string, char type);
  /* Free a string */
void cif_free_string (char __far *string);
  /* Create a handle */
int cif_make_handle (cif_handle *handle);
  /* Free a handle */
int cif_free_handle (cif_handle handle);
  /* Read a file */
int cif_read_file (cif_handle handle, FILE *stream);
  /* Create and initialise a file */
int cif_make_file (cif_file __far * __far *file, FILE *stream);
  /* Add a character to the text buffer */
int cif_save_character (cif_file __far *file, int c);
  /* Get the ascii value of the current (row, column) entry */
int cif_get_value (cif_handle handle, char **value);
  /* Make the specified column the current column */
int cif_select_column (cif_handle handle, unsigned int column);
  /* Find the requested tag anywhere in the cif, make it the current column */
int cif_findtag (cif_handle handle, char __far *tag);
int cif_srch_tag (cif_handle handle, cif_node __far *node,  
  char __far *catname, char __far *colname);
  /* Make the named column in the current category the current column */
int cif_find_column (cif_handle handle, char __far  *columnname);
  /* Get the number of the current column */
int cif_column_number (cif_handle handle, unsigned int __far *column);
  /* Make the specified row the current row */
int cif_select_row (cif_handle handle, unsigned int row);
  /* Count the rows in the current category */
int cif_count_rows (cif_handle handle, unsigned int __far *rows);
  /* Delete a row from the current category */
int cif_delete_row (cif_handle handle, const int rownumber);
  /* Count the columns in the current category */
int cif_count_columns (cif_handle handle, unsigned int __far *columns);
  /* Get the name of the current data block */
int cif_datablock_name (cif_handle handle, char __far * __far *datablockname);
  /* Make the first data block the current data block */
int cif_rewind_datablock (cif_handle handle);


int cif_parse (void *context);

#endif

#ifdef __cplusplus

}

#endif

#endif /* _CIF_ */




