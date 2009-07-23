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
 * cif.c                                                              *
 *                                                                    *
 * Simplified CIF library for support of CIF in RasMol derived in     *
 * part from CBFlib by P. Ellis                                       *
 * Mods by H. J. Bernstein, Bernstein + Sons, August 1998             *
 * yaya@bernstein-plus-sons.com                                       *
 *                                                                    *
 **********************************************************************/

/**********************************************************************
 *                                CREDITS                             *
 *                                                                    *
 *  This software is a Crystallographic Information File (CIF)        *
 *  application.  Please see the IUCR Policy below.   See the IUCR    *
 *  web page (http://www.iucr.org) or its mirrors for background      *
 *  and references on CIF.                                            *
 *                                                                    *
 *  This code was creating making use of coding conventions from      * 
 *  "RasMol 2.6 Molecular Graphics Visualisation tool" by             * 
 *  Roger Sayle,  Biomolecular Structures Group, Glaxo Wellcome       *
 *  Research & Development, Stevenage, Hertfordshire, UK,             *
 *  September 1995.  These coding conventions greatly enhance the     *
 *  portability of any C program, and are gratefully acknowledged.    *
 *                                                                    *
 *  This code is derived in part from CBFlib.  See "CBFLIB, An ANSI-C *
 *  API for Crystallographic Binary Files", Version 0.1, April 1998   *
 *  by Paul J. Ellis, Stanford Synchrotron Radiation Laboratory,      *
 *  ellis@ssrl.slac.stanford.edu                                      *
 *                                                                    *
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

                                      
/**************************************************************************
 *                                                                        *
 *                              CBFlib V0.1 Notice                        *
 *                                                                        *
 * The following Diclaimer Notice applies to CBFlib V0.1, from which this *
 * code is in part derived.                                               *
 *                                                                        *
 *   * The items furnished herewith were developed under the sponsorship  *
 *     of the U.S. Government. Neither the U.S., nor the U.S. D.O.E., nor *
 *     the Leland Stanford Junior University, nor their employees, makes  *
 *     any warranty, express or implied, or assumes any liability or      *
 *     responsibility for accuracy, completeness or usefulness of any     *
 *     information, apparatus, product or process disclosed, or           *
 *     represents that its use will not infringe privately-owned rights.  *
 *     Mention of any product, its manufacturer, or suppliers shall not,  *
 *     nor is it intended to, imply approval, disapproval, or fitness for *
 *     any particular use. The U.S. and the University at all times       *
 *     retain the right to use and disseminate the furnished items for    *
 *     any purpose whatsoever.                                            *
 *                                                                        *
 *      * Notice 91 02 01                                                 *
 *                                                                        *
 **************************************************************************/
       
/**************************************************************************
 *                              CIFPARSE notice                           *
 *                                                                        *
 *  Portions of this software are loosely based on the CIFPARSE software  *
 *  package from the NDB at Rutgers university (see                       *
 *  http://ndbserver.rutgers.edu/NDB/mmcif/software). CIFPARSE is part of *
 *  the NDBQUERY application, a program component of the Nucleic Acid     *
 *  Database Project [ H. M. Berman, W. K. Olson, D. L. Beveridge, J. K.  *
 *  Westbrook, A. Gelbin, T. Demeny, S. H. Shieh, A. R. Srinivasan, and   *
 *  B. Schneider. (1992). The Nucleic Acid Database: A Comprehensive      *
 *  Relational Database of Three-Dimensional Structures of Nucleic Acids. *
 *  Biophys J., 63, 751-759.], whose cooperation is gratefully            *
 *  acknowledged, especially in the form of design concepts created by    *
 *  J. Westbrook.                                                         *
 *                                                                        * 
 *  Please be aware of the following notice in the CIFPARSE API:          *
 *    * This software is provided WITHOUT WARRANTY OF MERCHANTABILITY OR  *
 *      FITNESS FOR A PARTICULAR PURPOSE OR ANY OTHER WARRANTY, EXPRESS   *
 *      OR IMPLIED. RUTGERS MAKE NO REPRESENTATION OR WARRANTY THAT THE   *
 *      SOFTWARE WILL NOT INFRINGE ANY PATENT, COPYRIGHT OR OTHER         *
 *      PROPRIETARY RIGHT.                                                *
 *                                                                        *
 **************************************************************************/


#ifdef __cplusplus

extern "C" {

#endif


#include "rasmol.h"

#ifdef USE_CBFLIB
#include "cmndline.h"
#include "cif.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#define C2CBUFSIZ 4096

#if defined(IBMPC) || defined(VMS) || defined(APPLEMAC)
#define NOMKSTEMP
#endif
    
    int cif_read_file (cbf_handle handle, FILE *stream) {
        char *ciftmp=NULL;
        int nbytes;
        FILE *file;
#ifndef NOMKSTEMP
        int ciftmpfd;
#endif
        char buffer [4096];
        
        ciftmp = (char *)_fmalloc(strlen("/tmp/rsml275XXXXXX")+1);
        strcpy(ciftmp, "/tmp/rsml275XXXXXX");
#ifdef NOMKSTEMP
        if ((file = tmpfile()) == NULL )
        {       WriteString("Can't create temporary file \n");
                sprintf(buffer,"%s\n",strerror(errno));
                WriteString(buffer);
                RasMolExit();
        }
        _ffree(ciftmp);
#else
        if ((ciftmpfd = mkstemp(ciftmp)) == -1 || (file = fdopen(ciftmpfd, "wb+")) == NULL) {
            strcpy(ciftmp, "rsml275XXXXXX");
            if ((ciftmpfd = mkstemp(ciftmp)) == -1 || (file = fdopen(ciftmpfd, "wb+")) == NULL) {        
                sprintf(buffer,"\n rasmol: Can't create temporary file %s.\n", ciftmp);
                WriteString(buffer);
                sprintf(buffer,"%s\n",strerror(errno));
                WriteString(buffer);
                RasMolExit();
            }
        }
        unlink(ciftmp);
        _ffree(ciftmp);
#endif
        if (Recycle) {
            nbytes = strlen(Recycle);
            if(nbytes != fwrite(Recycle, 1, nbytes, file)) {
                sprintf(buffer,"Failed to write %s.\n", ciftmp);
                WriteString(buffer);
                RasMolExit();
            }
            nbytes=1;
            if(nbytes != fwrite("\n", 1, nbytes, file)) {
                sprintf(buffer,"Failed to write %s.\n", ciftmp);
                WriteString(buffer);
                RasMolExit();
            }
        }
        if (stream)
        while ((nbytes = fread(buffer, 1, C2CBUFSIZ, stream))) {
            if(nbytes != fwrite(buffer, 1, nbytes, file)) {
                sprintf(buffer,"Failed to write %s.\n", ciftmp);
                WriteString(buffer);
                RasMolExit();
            }
        }
        
        rewind(file);
        cbf_failnez(cbf_read_widefile(handle,file, MSG_DIGEST));
        
        return 0;
    }



#else


#ifdef IBMPC
#include <windows.h>
#include <malloc.h>
#endif
#ifdef APPLEMAC
#include <Types.h>
#endif
#ifndef sun386
#include <stdlib.h>
#endif

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>
#if defined(IBMPC) || defined(VMS) || defined(APPLEMAC)
#include "string_case.h"
#else
#include <strings.h>
#endif

#include "molecule.h"
#include "cmndline.h"
#include "cif.h"

  /* Reallocate a block of memory (never lose the old block on failure) */

int cif_realloc (void __far * __far *old_block, size_t __far *old_nelem, 
  size_t elsize, size_t nelem)
{
  void __far *new_block;

    /* Are the arguments valid? */
  if (!old_block || elsize == (size_t)0) return CIF_ARGUMENT;

    /* Is the size alread correct? */

  if (old_nelem)
    if (*old_nelem == nelem)
      return 0;

    /* Allocate the memory */

  if (nelem > (size_t)0) {
    new_block = _fmalloc (nelem * elsize);
    if (!new_block)
      return CIF_ALLOC;
    RegisterAlloc( new_block );
  }
  else
    new_block = NULL;

    /* Copy the old data */
  if (old_nelem)
      if (*old_block && *old_nelem > (size_t)0 && nelem > (size_t)0)
    {
      if (*old_nelem > nelem)
            *old_nelem = nelem;
      memcpy (new_block, *old_block, *old_nelem * elsize);
    }

    /* free the old memory */

  if (*old_block)
    FreeAlloc (*old_block);


    /* Clear the new data */
  if (!old_nelem)
    memset (new_block, 0, nelem * elsize);
  else
    if (nelem > (size_t)0 && nelem > *old_nelem)
      memset (((char __far *) new_block) + *old_nelem * elsize, 0,
                                     (nelem - *old_nelem) * elsize);

    /* Replace the old data */
  *old_block = new_block;
  if (old_nelem)
    *old_nelem = nelem;
  
    /* Success */
  return 0;
}


  /* Allocate a block of memory */

int cif_alloc (void __far * __far *new_block, size_t __far *new_nelem, 
  size_t elsize, size_t nelem)
{
    /* Are the arguments valid? */
    
  if (!new_block)
    return CIF_ARGUMENT;

    /* Initialise */
  *new_block = NULL;

  if (new_nelem)
    *new_nelem = 0;

    /* Allocate the memory */
  return cif_realloc (new_block, new_nelem, elsize, nelem);
}

  /* free a block of memory */

int cif_free (void __far * __far *old_block, size_t __far *old_nelem)
{
    /* Are the arguments valid? */
    
  if (!old_block)
    return CIF_ARGUMENT;

    /* free the memory */

  if (*old_block)
    FreeAlloc (*old_block);
  *old_block = NULL;
  if (old_nelem)  *old_nelem = 0;

    /* Success */
  return 0;
}

  /* Make a new node */

int cif_make_node (cif_node __far * __far *node, CIF_NODETYPE type, 
  const char __far *name)
{
  int errorcode;
  if (!node)   return CIF_ARGUMENT;

    /* Create the new node */
  cif_failnez (cif_alloc ((void __far * __far *) node, NULL, 
    sizeof (cif_node), 1))

    
    /* Initialise the node */

  (*node)->type = type;
  (*node)->name = NULL;
  (*node)->link = NULL;
  (*node)->parent = NULL;
  (*node)->children = 0;
  (*node)->child_size = 0;
  (*node)->child = NULL;

    /* Name the node */
  errorcode = cif_name_node (*node, name);
  if (errorcode)  {
    return errorcode | cif_free_node (*node);
  }
    /* Success */
  return 0;
}

  /* Make a new node allowing for duplicates */

int cif_make_new_node (cif_node __far * __far *node, CIF_NODETYPE type, 
  const char __far *name)
{
  int errorcode;
  if (!node) return CIF_ARGUMENT;

    /* Create the new node */
  cif_failnez (cif_alloc ((void __far * __far *) node, NULL, 
    sizeof (cif_node), 1))

    /* Initialise the node */
  (*node)->type = type;
  (*node)->name = NULL;
  (*node)->link = NULL;
  (*node)->parent = NULL;
  (*node)->children = 0;
  (*node)->child_size = 0;
  (*node)->child = NULL;

     /* Name the node */
  errorcode = cif_name_new_node (*node, name);
  if (errorcode)
    return errorcode | cif_free_node (*node);

  /* Success */
  return 0;
}


  /* free a node */

int cif_free_node (cif_node __far *node)
{
  unsigned int count;

    /* Check the arguments */
  if (!node)
    return CIF_ARGUMENT;

    /* Disconnect the node from its parent? */
  if (node->parent)
    for (count = 0; count < node->parent->children; count++)
      if (node->parent->child [count] == node)
      {
        node->parent->children--;
        if (node->parent->children == 0)
          cif_failnez (cif_free ((void __far * __far *) &node->parent->child,
                                       &node->parent->child_size))
        else
          if (node->parent->children > count)
             memmove (node->parent->child + count, 
               node->parent->child + count + 1,
               (node->parent->children - count) * sizeof (cif_node __far *));
        break;
      }

    /* free the children */
  cif_failnez (cif_set_children (node, 0))

    /* free the name */
  cif_free_string (node->name);

    /* free the node */
  return cif_free ((void __far * __far *) &node, NULL);
}


  /* Set the number of children */
int cif_set_children (cif_node __far *node, unsigned int children)
{
  unsigned int count, new_size, kblock;
  int errorcode;

    /* Check the arguments */
  if (!node)
    return CIF_ARGUMENT;

    /* Is the current size correct? */
  if (children == node->children)
    return 0;

  kblock = 16;
  if (children > 128*2) kblock = 128;
  if (children > 512*2) kblock = 512;
  new_size = (((int)((children -1)/kblock)))*kblock+kblock;
  if (new_size < children) new_size = children;

    /* Decrease the number of children? */
  if (children < node->children)
  {
    errorcode = 0;
    for (count = children; count < node->children; count++)

        /* free the child */
      if (node->type == CIF_COLUMN)
        errorcode |= cif_set_columnrow (node, count, NULL);
      else
        if (node->type != CIF_LINK)
          if (node->child [count])
          {
            node->child [count]->parent = NULL;
            errorcode |= cif_free_node (node->child [count]);
            node->child [count] = NULL;
          }
    if (children == 0)
      errorcode = cif_free ((void __far * __far *) &node->child, 
        &node->child_size);
    node->children = children;
    if (new_size < node->child_size )
      cif_failnez (cif_realloc ((void __far * __far *) &node->child, 
      &node->child_size,  sizeof (cif_node __far *), new_size))
    return errorcode;
  }

    /* Increase the number of children */
  if (new_size > node->child_size)
    cif_failnez (cif_realloc ((void __far * __far *) &node->child, 
    &node->child_size,  sizeof (cif_node __far *), new_size))
  node->children = children;

    /* Success */
  return 0;
}
  

  /* Trace a link */
cif_node __far *cif_get_link (const cif_node __far *node)
{
  while (node)
    if (node->type == CIF_LINK && node->link)
      node = node->link;
    else
      return (cif_node __far *) node;

    /* Fail */
  return NULL;
}


  /* Find a child node */

int cif_find_child (cif_node __far * __far *child, const cif_node __far *node, const char __far *name)
{
  unsigned int count;
  const char __far *namec, *nodenamec;

    /* Follow any links */
  node = cif_get_link (node);

    /* Check the arguments */
  if (!node)
    return CIF_ARGUMENT;

    /* Is it a normal node? */
  if (node->type == CIF_COLUMN)
    return CIF_ARGUMENT;

    /* Search the children */

  for (count = 0; count < node->children; count++)
    if (name)
    {
      if (node->child [count]->name)
      {
        for (namec = name, nodenamec = node->child [count]->name;
            *namec && toupper (*nodenamec) == toupper (*namec);
             namec++, nodenamec++);
        if (!*namec && !*nodenamec)
        {
          if (child)          
            *child = node->child [count];
          return 0;
        }
      }
    }
    else
      if (name == node->child [count]->name)
      {
        if (child) *child = node->child [count];
        return 0;
      }

    /* Fail */
  return CIF_NOTFOUND;
}

  /* Find a child node, accepting the last match  */

int cif_find_last_child (cif_node __far * __far *child, 
  const cif_node __far *node, const char __far *name)
{
  unsigned int count;
  const char __far *namec, *nodenamec;

    /* Follow any links */
  node = cif_get_link (node);
  
    /* Check the arguments */
  if (!node)  return CIF_ARGUMENT;

    /* Is it a normal node? */
  if (node->type == CIF_COLUMN)
    return CIF_ARGUMENT;

    /* Search the children */
  for ( count = node->children; count > 0;  ) {
    count--;
    if (name)
    {
      if (node->child [count]->name)
      {
        for (namec = name, nodenamec = node->child [count]->name;
            *namec && toupper (*nodenamec) == toupper (*namec);
             namec++, nodenamec++);
        if (!*namec && !*nodenamec)
        {
          if (child) *child = node->child [count];
          return 0;
        }
      }
    }
    else
      if (name == node->child [count]->name)
      {
        if (child)  *child = node->child [count];
        return 0;
      }
  }
    /* Fail */

  return CIF_NOTFOUND;
}


  /* Find a parent node */
int cif_find_parent (cif_node __far * __far *parent, 
  const cif_node __far *node, CIF_NODETYPE type)
{
    /* Follow any links */
  node = cif_get_link (node);

    /* Check the arguments */
  if (!node)
    return CIF_ARGUMENT;

    /* Find the parent */
  while (node)
  {
    if (node->type == type)
    {
      if (parent) *parent = (cif_node __far *) node;
      return 0;
    }
    node = node->parent;
  }

    /* Fail */
  return CIF_NOTFOUND;
}

  /* Count the number of children */
int cif_count_children (unsigned int *children, const cif_node __far *node)
{
    /* Follow any links */
  node = cif_get_link (node);

    /* Check the arguments */
  if (!children || !node)
    return CIF_ARGUMENT;

    /* Success */
  *children = node->children;
  return 0;
}

  /* Get the index of a child */
int cif_child_index (unsigned int *index, const cif_node __far *node)
{
  cif_node __far *parent;
  unsigned int child;

    /* Follow any links */
  node = cif_get_link (node);

    /* Check the arguments */
  if (!node)
    return CIF_ARGUMENT;

    /* Get the parent */
  parent = node->parent;
  if (!parent)
    return CIF_NOTFOUND;

    /* Find the child */

  for (child = 0; child < parent->children; child++)
    if (parent->child [child] == node)
    {
      if (index)
        *index = child;
      return 0;
    }

    /* Fail */
  return CIF_NOTFOUND;
}

  /* Get the specified child */

int cif_get_child (cif_node __far * __far *child, const cif_node __far *node, unsigned int index)
{
    /* Follow any links */
  node = cif_get_link (node);
  
    /* Check the arguments */
  if (!node)
    return CIF_ARGUMENT;

    /* Is it a normal node? */
  if (node->type == CIF_COLUMN)
    return CIF_ARGUMENT;

    /* Does the child exists? */
  if (index < node->children)
  {
    if (child) *child = node->child [index];
    return 0;
  }

    /* Fail */
  return CIF_NOTFOUND;
}


  /* Get the name of a node */
int cif_get_name (char __far * __far *name, cif_node __far *node)
{
    /* Follow any links */
  node = cif_get_link (node);

    /* Check the arguments */
  if (!node)
    return CIF_ARGUMENT;

    /* Set the name */
  if (name) *name = node->name;

    /* Success */
  return 0;
}


  /* All of the following functions assume that all of the strings have
     been created using cif_copy_string and that no pointers to the
     strings are retained by the calling functions */

  /* Name a node */

int cif_name_node (cif_node __far *node, const char __far *name)
{
    /* Follow any links */
  node = cif_get_link (node);

    /* Check the arguments */
  if (!node)
    return CIF_ARGUMENT;
    
    /* Is there a sibling with this name? */
  if (node->parent)
    if (cif_find_child (NULL, node->parent, name) == 0)
      return CIF_IDENTICAL;
      
    /* Replace the old name */
  cif_free_string (node->name);
  node->name = (char __far *) name;

    /* Success */      
  return 0;
}
  /* Name a node allowing for duplicates  */
int cif_name_new_node (cif_node __far *node, const char __far *name)
{
    /* Follow any links */
  node = cif_get_link (node);

    /* Check the arguments */
  if (!node)
    return CIF_ARGUMENT;

    /* Replace the old name */
  cif_free_string (node->name);
  node->name = (char __far *) name;

    /* Success */      

  return 0;
}

  /* Add a child to a node */

int cif_add_child (cif_node __far *node, cif_node __far *child)
{
    /* Follow any links */
  node = cif_get_link (node);

    /* Check the first argument */
  if (!node)

    return CIF_ARGUMENT;

    /* Follow any links */
  child = cif_get_link (child);

    /* Check the second argument */
  if (!child)
    return CIF_ARGUMENT;

    /* Is there already a child with this name? */
    
  if (cif_find_child (NULL, node, child->name) == 0)
    return CIF_IDENTICAL;

    /* Add the child */

  cif_failnez (cif_set_children (node, node->children + 1))
  child->parent = node;
  node->child [node->children - 1] = child;

    /* Success */
  return 0;
}

  /* Add a child to a node with duplicates allowed */

int cif_add_new_child (cif_node __far *node, cif_node __far *child)
{
    /* Follow any links */
  node = cif_get_link (node);


    /* Check the first argument */
  if (!node)
    return CIF_ARGUMENT;


    /* Follow any links */
  child = cif_get_link (child);

    /* Check the second argument */
    
  if (!child)
    return CIF_ARGUMENT;

    /* Add the child */
  cif_failnez (cif_set_children (node, node->children + 1))
  child->parent = node;
  node->child [node->children - 1] = child;

    /* Success */

  return 0;
}


  /* Make a new child node */

int cif_make_child (cif_node __far * __far *child, cif_node __far *node, 
  CIF_NODETYPE type, char __far *name)
{
  cif_node __far *newchild;

  int errorcode;

  
    /* Check the type */

  if (type == CIF_LINK)

    return CIF_ARGUMENT;
    

    /* Follow any links */

  node = cif_get_link (node);


    /* Does the child already exist? */

  errorcode = cif_find_last_child (child, node, name);

  if (errorcode == 0)
  {
    cif_free_string (name);
   
    return 0;
  }

  if (errorcode != CIF_NOTFOUND)

    return errorcode;


    /* Make a new node */

  cif_failnez (cif_make_node (&newchild, type, name))

  errorcode = cif_add_child (node, newchild);

  if (errorcode)
  {
    newchild->name = NULL;

    cif_free_node (newchild);
    
    return errorcode;
  }


    /* Success */

  if (child)

    *child = newchild;

  return 0;
}

  /* Make a new child node, with duplicates allowed */

int cif_make_new_child (cif_node __far * __far *child, cif_node __far *node,
    CIF_NODETYPE type, const char __far *name)
{
  cif_node __far *newchild;

  int errorcode;

  
    /* Check the type */

  if (type == CIF_LINK)

    return CIF_ARGUMENT;
    

    /* Follow any links */

  node = cif_get_link (node);



    /* Make a new node */

  cif_failnez (cif_make_new_node (&newchild, type, name))

  errorcode = cif_add_new_child (node, newchild);

  if (errorcode)
  {
    newchild->name = NULL;

    cif_free_node (newchild);
    
    return errorcode;
  }


    /* Success */

  if (child)

    *child = newchild;

  return 0;
}


  /* Change a link */

int cif_set_link (cif_node __far *link, cif_node __far *node)
{
    /* Check the arguments */
    
  if (!link)

    return CIF_ARGUMENT;


    /* Check the type */

  if (link->type != CIF_LINK)

    return CIF_ARGUMENT;


    /* Change the link */

  link->link = node;


    /* Success */

  return 0;
}


  /* Add a child link */

int cif_add_link (cif_node __far *link, cif_node __far *child)
{
    /* Check the arguments */
    
  if (!link)

    return CIF_ARGUMENT;


    /* Check the type */

  if (link->type != CIF_LINK)

    return CIF_ARGUMENT;


    /* Add the child */

  cif_failnez (cif_set_children (link, link->children + 1))

  link->child [link->children - 1] = child;
  

    /* Success */

  return 0;
}
                                                  

  /* Set a link successively to each child link */

int cif_shift_link (cif_node __far *link)
{
    /* Check the arguments */
    
  if (!link)

    return CIF_ARGUMENT;


    /* Check the type */

  if (link->type != CIF_LINK)

    return CIF_ARGUMENT;


    /* Do the children exist? */

  if (link->children == 0)

    return CIF_ARGUMENT;


    /* Change the link */

  link->link = link->child [0];


    /* Shift the children */

  memmove (link->child, link->child + 1, 
    (link->children - 1) * sizeof (cif_node __far *));

  link->child [link->children - 1] = link->link;


    /* Success */

  return 0;
}


  /* Set the value of a row */

int cif_set_columnrow (cif_node __far *column, unsigned int row, 
  const char __far *value)
{
    /* Follow any links */

  column = cif_get_link (column);


    /* Check the arguments */
    
  if (!column)

    return CIF_ARGUMENT;


    /* Check the node type */

  if (column->type != CIF_COLUMN)

    return CIF_ARGUMENT;


    /* Increase the column size? */

  if (row + 1 > column->children)

    cif_failnez (cif_set_children (column, row + 1))


    /* Set the value */

  cif_failnez (cif_free_value ((char __far **) &(column->child [row])))

  column->child [row] = (cif_node __far *) value;


    /* Success */

  return 0;
}


  /* Get the value of a row */

int cif_get_columnrow (char __far **value, const cif_node __far *column, unsigned int row)
{
    /* Follow any links */

  column = cif_get_link (column);


    /* Check the arguments */
    
  if (!column)

    return CIF_ARGUMENT;


    /* Check the node type */

  if (column->type != CIF_COLUMN)

    return CIF_ARGUMENT;


    /* Is the value in the column? */

  if (row + 1 > column->children)

    return CIF_NOTFOUND;


    /* Success */

  if (value)

    *value = (char __far *) column->child [row];

  return 0;
}


  /* Inset a value into a column */

int cif_insert_columnrow (cif_node __far *column, unsigned int row, const char __far *value)
{
    /* Follow any links */

  column = cif_get_link (column);


    /* Check the arguments */

  if (!column)

    return CIF_ARGUMENT;

  if (row > column->children)

    return CIF_NOTFOUND;


    /* Increase the column size */

  cif_failnez (cif_set_children (column, column->children + 1))


    /* Move any values further down the column */

  if (row < column->children - 1)

    memmove (column->child + row + 1, column->child + row,
               sizeof (cif_node __far *) * (column->children - row - 1));
  

    /* Set the value */

  column->child [row] = (cif_node __far *) value;


    /* Success */

  return 0;
}


  /* Delete a row from a column */

int cif_delete_columnrow (cif_node __far *column, unsigned int row)
{
    /* Follow any links */

  column = cif_get_link (column);


    /* Check the arguments */

  if (!column)

    return CIF_ARGUMENT;

  if (row >= column->children)

    return CIF_NOTFOUND;


    /* free the value */

  cif_failnez (cif_set_columnrow (column, row, NULL))


    /* Move any values further down the column */

  if (row < column->children - 1)

    memmove (column->child + row, column->child + row + 1,
               sizeof (cif_node __far *) * (column->children - row - 1));

  column->child [column->children - 1] = NULL;


    /* Decrease the column size */

  return cif_set_children (column, column->children - 1);
}


  /* Add a value to a column */

int cif_add_columnrow (cif_node __far *column, const char __far *value)
{
    /* Follow any links */

  column = cif_get_link (column);


    /* Check the arguments */

  if (!column)

    return CIF_ARGUMENT;


    /* Add the value */

  return cif_set_columnrow (column, column->children, value);
}

  /* Free a value */

int cif_free_value (char __far * __far *value)
{
  const char *text;

    /* Check the argument */

  if (!value)
    return CIF_ARGUMENT;

  text = *value;
  if (!text)  return 0;

    /* Free the value */
  cif_free_string (*value);
  *value = NULL;
  return 0;

}


  /* Copy a string */
char __far *cif_copy_string (char __far *string, char type)
{
  char __far *new_string;
  if (string)
    {
    if (type)
    {
      if (cif_alloc ((void __far * __far *) &new_string, NULL, 
        sizeof (char), strlen (string) + 2) == 0)
      {
        *new_string = type;
         strcpy (new_string + 1, string);
        return new_string;
      }
    }
    else {
      if (cif_alloc ((void __far * __far *) &new_string, NULL, 
        sizeof (char), strlen (string) + 1) == 0)
      {
        strcpy (new_string, string);
        return new_string;
      }
    }
    }

  /* Fail */
  return NULL;
}


  /* Free a string */
void cif_free_string (char __far *string)
{
  cif_free ((void __far *__far*) &string, NULL);
}

  /* Create a handle */

int cif_make_handle (cif_handle *handle)
{
  int errorcode;
  cif_failnez (cif_alloc ((void **) handle, NULL, sizeof (cif_handle_struct), 1))

  errorcode = cif_make_node (&(*handle)->node, CIF_ROOT, NULL);
  if (errorcode)
    return errorcode | cif_free ((void **) handle, NULL);
  (*handle)->row = 0;
  (*handle)->search_row = 0;

  return 0;
}


  /* Free a handle */

int cif_free_handle (cif_handle handle)
{
  int errorcode;
    if (handle)
  {
    errorcode = cif_free_node (handle->node);
    return errorcode | cif_free ((void **) &handle, NULL);
  }
  return 0;
}


  /* Read a file */

int cif_read_file (cif_handle handle, FILE *stream)
{
  cif_file __far *file;
  cif_node __far *node;
  void __far *parse [2];
  int errorcode;
  unsigned int children;
  char *name;

  if (!handle) return CIF_ARGUMENT;

  
    /* Delete the old datablocks */
  cif_failnez (cif_find_parent (&node, handle->node, CIF_ROOT))
  cif_failnez (cif_set_children (node, 0))
  handle->node = node;

      /* Create the input file */
  cif_failnez (cif_make_file (&file, stream))


    /* Parse the file */
    
  parse [0] = file;
  parse [1] = handle->node;
  errorcode = cif_parse (parse);


    /* Delete the first datablock if it's empty */
  if (!errorcode)
  {
    errorcode = cif_get_child (&node, node, 0);
    if (!errorcode)
    {
      errorcode = cif_get_name (&name, node);
      if (!errorcode && !name)
      {
        errorcode = cif_count_children (&children, node);
        if (!errorcode && !children)
          errorcode = cif_free_node (node);
      }
    }
    else
      if (errorcode == CIF_NOTFOUND)
        errorcode = 0;
  }

    
  return errorcode;
}



  /* Create and initialise a file */

int cif_make_file (cif_file __far * __far *file, FILE *stream)
{
    /* Allocate the memory */

  cif_failnez (cif_alloc ((void __far * __far *) file, NULL, 
    sizeof (cif_file), 1))


    /* Initialise */

  (*file)->stream = stream;
  (*file)->connections = 1;
  (*file)->bits [0]    = 0;
  (*file)->bits [1]    = 0;
  (*file)->last_read   = 0;
  (*file)->line        = 0;
  (*file)->column      = 0;
  (*file)->text_size   = 0;
  (*file)->text_used   = 0;
  (*file)->fpos        = 0;
  (*file)->fend        = 0;
  (*file)->text = NULL;


    /* Success */
  return 0;
}



  /* Get the next character */
int cif_get_character (cif_file __far *file)
{
  if (file->stream) {
    if ( feof(file->stream) ) {
      file->last_read = EOF;
    } else {
      if (Recycle) {
        if (*Recycle) {
          file->last_read = *Recycle++;
        } else {
          file->last_read = '\n';
        }
      } else {
        file->last_read = fgetc (file->stream);
        ++(file->fpos);
        if (file->fpos > file->fend) file->fend = file->fpos;
      }
    }
  }
  else
    file->last_read = EOF;
  return file->last_read;
}


  /* Read the next character (convert end-of-line and update line and column) */
int cif_read_character (cif_file __far *file)
{
  int last, current;

    /* Does the file exist? */
  if (!file) return EOF;

    /* Read the next character */
  last = file->last_read;
  current = cif_get_character (file);
  if ((current == '\n' && last == '\r') ||
      (current == '\r' && last == '\n'))
    current = cif_get_character (file);

    /* Convert the end-of-line character and update line and column */
  if (current == '\n' || current == '\r')
  {
    current = '\n';
    file->column = 0;
    file->line++;
    if (Recycle && !(*Recycle)) Recycle = (char *)0;
  }
  else
    if (current == '\t')
      file->column = (file->column & ~0x07) + 8;
    else
      file->column++;
  return current;
}

  /* Return a copy of the text */
int cif_return_text (int code, YYSTYPE __far *val, int offset, 
                   cif_file __far *file, char type)
{
  val->text = cif_copy_string (file->text + offset, type);
  if (!val->text)
  {
    val->errorcode = CIF_ALLOC;
    return ERROR;
  }
  return code;
}


  /* Get the name of the current data block */
int cif_datablock_name (cif_handle handle, char __far * __far * datablockname)
{
  cif_node *node;

  if (!handle)

    return CIF_ARGUMENT;


    /* Find the data block node */

  cif_failnez (cif_find_parent (&node, handle->node, CIF_DATABLOCK))


    /* Get the name */

  return cif_get_name (datablockname, node);
}





  /* Make the first data block the current data block */

int cif_rewind_datablock (cif_handle handle)
{
  cif_node *node;

  if (!handle)
    return CIF_ARGUMENT;


    /* Find the root node */

  cif_failnez (cif_find_parent (&node, handle->node, CIF_ROOT))


    /* Find the first child */

  cif_failnez (cif_get_child (&node, node, 0))
  handle->node = node;


    /* Success */

  return 0;
}



  /* Get the next token */

int cif_lex (YYSTYPE __far *val, cif_file __far *file)
{
  int data, loop, item, column, comment, word, string, length, 
      c, cprev, count, reprocess, errorcode;
  

  file->text_used = 0;
  c = file->last_read;
  cprev = '\0';
  column = c == '.';
  comment = c == '#';
  reprocess = (column || comment);
  data = loop = item = string = !reprocess;
  comment = !column;

  do
  {
    length = (int)(file->text_used);
    if (reprocess) {
      reprocess = 0;
    } else {
      cprev = c;
      c = cif_read_character (file);
    }    

      /* Discard spaces ([[:space:]]+) */

    if (length == 0)
      if (isspace (c))
         continue;
            
        
       /* DATA ([Dd][Aa][Tt][Aa][_][^[:space:]]*) */
    
    if (data)
    {
      if (length < 5)
         data = (ToUpper (c) == "DATA_" [length]);
      else
      {
        data = !isspace (c) && c != EOF;
          if (!data)
          return cif_return_text (DATA, val, 5, file, 0);
      }
    }
   
   
       /* LOOP ([Ll][Oo][Oo][Pp][_]) */
     
    if (loop)
    {
      loop = (ToUpper (c) == "LOOP_" [length]);
      if (loop && length == 4)
        return LOOP;
    }

   
       /* ITEM ([_][^[:space:]\.]+) */
     
    if (item)
    {
      if (length == 0)
        item = c == '_';
      else
      {
        item = !isspace (c) && c != '.' && c != EOF;
        if (length >= 2 && !item)
        {
          if (c == '.')
            return cif_return_text (CATEGORY, val, 1, file, 0);
          return cif_return_text (ITEM, val, 1, file, 0);
        }
      }
    }

   
      /* COLUMN (\.[^[:space:]]+) */
     
    if (column)
    {
      column = !isspace (c) && c != EOF;
      if (!column)
        return cif_return_text (COLUMN, val, 1, file, 0);
    }

      /* STRING ([\'][^'\n]*[\'\n])|(([\"][^"\n]*[\"\n])) */
     
    if (string)
    {
      if (length == 0)
        string = c == '\'' || c == '"';
      else
      {
        string = (cprev != file->text [0] || file->text_used<2 || 
                  !isspace(c)) 
                     && ( c != '\n'  && c != EOF);
        /* string = c != file->text [0] && c != '\n' && c != EOF; */
        if (!string)
        {
          if ( cprev == file->text[0] && file->text_used > 0 ) {
            file->text_used--;
            file->text [file->text_used] = '\0';
          }
          if (file->text [0] == '\'')
            return cif_return_text (STRING, val, 1, file, CIF_TOKEN_SQSTRING);
          return cif_return_text (STRING, val, 1, file, CIF_TOKEN_DQSTRING);
        }
      }
    }


       /* COMMENT ([#][^\n]*) */
     
    if (comment)
    {
      if (length == 0)
        comment = c == '#';
      else
      {
        comment = c != '\n' && c != EOF;
        if (!comment)
          return cif_return_text (COMMENT, val, 1, file, 0);
      }
    }


      /* semicolon-delimited STRING (^;[^\n]*[\n])([^;][^\n]*[\n])+)(;) */
      
    if (file->column == 1)
      {
      if (c == ';')
      {
        
        
        do
        {
          errorcode = cif_save_character (file, c);
          if (errorcode)
          {
            val->errorcode = errorcode;
            return ERROR;
          }
          cprev = c;
          c = cif_read_character (file);
        }
        while ((c != ';' || file->column != 1) );

        file->text [file->text_used - 1] = '\0';

          /* Convert "\n\\;" -> "\n;" */
        for (count = 0; file->text [count]; count++)
          if (strncmp (file->text + count, "\n\\;", 3) == 0)
            memmove (file->text + count + 1, file->text + count + 2,
                                               file->text_used - count - 2);
        return cif_return_text (STRING, val, 1, file, CIF_TOKEN_SCSTRING);

      }
      }

       /* CIFWORD ([^[:space:]]+) */
     
    if (!data && !loop && !item && !comment && !string && !column)
    {
      word = !isspace (c) && c != EOF;
      if (length && !word)
      {
          /* Missing value? */
        if (length == 1 && 
          (file->text [0] == '?' || file->text [0] == '.')){
          memmove (file->text + 1, file->text, length + 1);
          return cif_return_text (CIFWORD, val, 1, file, CIF_TOKEN_NULL);
        }
        memmove (file->text + 1, file->text, length + 1);
        return cif_return_text (CIFWORD, val, 1, file, CIF_TOKEN_WORD);
      }
    }


      /* Add the character to the text */
    errorcode = cif_save_character (file, c);

    if (errorcode)
    {
      val->errorcode = errorcode;
      return ERROR;
    }
  }
  while (c != EOF);
  
  return 0;
}

  /* Get the ascii value of the current (row, column) entry */
  
int cif_get_value (cif_handle handle, char **value)
{
  char *text;

  
    /* Check the arguments */

  if (!handle)

    return CIF_ARGUMENT;

    
    /* Get the value */

  cif_failnez (cif_get_columnrow (&text, handle->node, handle->row))



  if (value)

    *value = text + 1;


    /* Success */

  return 0;
}

  /* Make the specified column the current column */

int cif_select_column (cif_handle handle, unsigned int column)
{
  cif_node *node;

  if (!handle)

    return CIF_ARGUMENT;


    /* Find the category node */

  cif_failnez (cif_find_parent (&node, handle->node, CIF_CATEGORY))


    /* Select the column */

  cif_failnez (cif_get_child (&node, node, column))

  handle->node = node;


    /* Success */

  return 0;
}

  /* Find the requested tag anywhere in the cif, make it the current column */

int cif_findtag (cif_handle handle, char __far *tag)
{
  cif_node __far *node;
  size_t catlen, collen;
  char __far catname[80];
  char __far colname[80];
  char __far *colstart;

  if (!handle || !tag) return CIF_ARGUMENT;
  cif_failnez (cif_find_parent (&node, handle->node, CIF_ROOT))
  
  if (tag[0] == '_') tag++;
  if (!(colstart = strchr(tag,'.'))) {
    colstart=tag-1;
    catlen = 0;
  } else {
    catlen = colstart-tag;
  }
  if (catlen) strncpy(catname,tag,catlen);
  catname[catlen] = '\0';
  collen = (tag+strlen(tag))-colstart;
  if (collen) strncpy(colname,colstart+1,collen);
  colname[collen] = '\0';
  cif_failnez(cif_srch_tag(handle, node, catname, colname))
  return 0;
  
}

int cif_srch_tag (cif_handle handle, cif_node __far *node, 
  char __far *catname, char __far *colname)
{
  unsigned int children, child;

  if (!node) return CIF_NOTFOUND;
  node = cif_get_link(node);
  
  if (node->type == CIF_CATEGORY) {
    if ((!(node->name)&&(catname[0]=='\0'))||
        ((node->name)&&!strcasecmp(node->name,catname))) {
      cif_failnez (cif_find_child(&node,node,colname))
      handle->node = node;
      return 0;
    } else {
      return CIF_NOTFOUND;
    }
  }
  children = node->children;
  for (child = 0; child < children; child++) {
    if(! cif_srch_tag(handle, (node->child)[child], 
      catname, colname)) return 0;
  }
  return CIF_NOTFOUND;
}

  /* Set the size of the text buffer */

int cif_set_textsize (cif_file __far *file, size_t size)
{
    /* Does the file exist? */

  if (!file)

    return CIF_ARGUMENT;


    /* Is the size already close enough? */

  if (file->text_size > size && file->text_size <= size + 256 && size > (size_t)0)

    return 0;


    /* Reallocate the buffer */

  return cif_realloc ((void **) &file->text, &file->text_size, sizeof (char), size);
}


  /* Add a character to the text buffer */

int cif_save_character (cif_file __far *file, int c)
{
  unsigned int new_size, kblock;

    /* Does the file exist? */

  if (!file)

    return CIF_ARGUMENT;


    /* Expand the buffer? */

  kblock = 16;
  if (file->text_used+2 > (size_t)(128*2)) kblock = 128;
  if (file->text_used+2 > (size_t)(512*2)) kblock = 512;
  new_size = (((int)((file->text_used+2)/kblock)))*kblock+kblock;
  if (new_size < file->text_used+3) new_size = (int)file->text_used+3;

  if (new_size >= file->text_size)

    cif_failnez (cif_set_textsize (file, new_size))


    /* Add the character */

  file->text [file->text_used] = (char) c;

  file->text_used++;

  file->text [file->text_used] = '\0';


    /* Success */
  
  return 0;
}

  /* Make the named column in the current category the current column */

int cif_find_column (cif_handle handle, char __far  *columnname)
{
  cif_node *node;

  if (!handle)

    return CIF_ARGUMENT;


    /* Find the category node */

  cif_failnez (cif_find_parent (&node, handle->node, CIF_CATEGORY))


    /* Find the column */

  cif_failnez (cif_find_child (&node, node, columnname))

  handle->node = node;


    /* Success */

  return 0;
}
  /* Get the number of the current column */
  
int cif_column_number (cif_handle handle, unsigned int __far *column)
{
  unsigned int children, child;
  cif_node *node;

  if (!handle)

    return CIF_ARGUMENT;


    /* Find the category node */

  cif_failnez (cif_find_parent (&node, handle->node, CIF_CATEGORY))


    /* Find the column */

  children = node->children;
  for (child = 0; child < children; child++) {
    if( handle->node ==  node->child[child] )  {
      *column =  child;
      return 0;
    }
  }

    /* Failure */

  return CIF_NOTFOUND;

}

  /* Make the specified row the current row */

int cif_select_row (cif_handle handle, unsigned int row)
{
  cif_node __far *node;

  unsigned int rows;
  
  if (!handle)

    return CIF_ARGUMENT;


    /* Find the column node */

  cif_failnez (cif_find_parent (&node, handle->node, CIF_COLUMN))

  cif_failnez (cif_count_children (&rows, node))


    /* Is the row valid? */

  if (row >= rows)

    return CIF_NOTFOUND;

  handle->row = row;

  handle->search_row = row;


    /* Success */

  return 0;
}

  /* Count the rows in the current category */

int cif_count_rows (cif_handle handle, unsigned int __far *rows)
{
  cif_node __far *node;
  cif_node __far *parent;

  unsigned int columns, column, columnrows, categoryrows;

  if (!handle)

    return CIF_ARGUMENT;


    /* Find the category node */

  cif_failnez (cif_find_parent (&parent, handle->node, CIF_CATEGORY))


    /* Count the columns */

  cif_failnez (cif_count_children (&columns, parent))


    /* Get the size of each column */

  categoryrows = 0;

  for (column = 0; column < columns; column++)
  {
      /* Get the column */

    cif_failnez (cif_get_child (&node, parent, column))


      /* Count the number of rows */

    cif_failnez (cif_count_children (&columnrows, node))


      /* Is it the same size as the other columns? */

    if (column == 0)

      categoryrows = columnrows;

    else

      if (categoryrows != columnrows)

        return CIF_FORMAT;
  }

  if (rows)

    *rows = categoryrows;


    /* Success */

  return 0;
}
  /* Delete a row from the current category */

int cif_delete_row (cif_handle handle, const int rownumber)
{
  cif_node __far *node, __far *columnnode;

  int errorcode [2];

  unsigned int rows, columns, column;

  if (!handle)

    return CIF_ARGUMENT;

  
    /* Find the category node */

  cif_failnez (cif_find_parent (&node, handle->node, CIF_CATEGORY))


    /* How many rows and columns does this category have? */

  cif_failnez (cif_count_rows (handle, &rows))
  
  cif_failnez (cif_count_columns (handle, &columns))
  

    /* Delete a row from each column */

  errorcode [0] = 0;
  
  for (column = 0; column < columns; column++)
  {
    errorcode [1] = cif_get_child (&columnnode, node, column);

    if (!errorcode [1])

      errorcode [1] = cif_delete_columnrow (columnnode, rownumber);

    errorcode [0] |= errorcode [1];
  }

  rows--;

  if (handle->row > rownumber)

    handle->row--;

  if (handle->search_row > rownumber)

    handle->search_row--;

  return errorcode [0];
}

  /* Count the columns in the current category */

int cif_count_columns (cif_handle handle, unsigned int __far *columns)
{
  cif_node __far *node;

  if (!handle)

    return CIF_ARGUMENT;


    /* Find the category node */

  cif_failnez (cif_find_parent (&node, handle->node, CIF_CATEGORY))


    /* Count the columns */

  return cif_count_children (columns, node);
}
#endif


#ifdef __cplusplus

}

#endif

