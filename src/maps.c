/***************************************************************************
 *                              RasMol 2.7.5                               *
 *                                                                         *
 *                                 RasMol                                  *
 *                 Molecular Graphics Visualisation Tool                   *
 *                 19 November 2007 (rev. 17 March 2008)                   *
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
/* maps.c
 */

#include <stdio.h>
#include <math.h>
 
#include "rasmol.h"
#include "command.h"
#include "cmndline.h"
#include "langsel.h"
#include "molecule.h"
#include "graphics.h"
#include "repres.h"
#include "abstree.h"
#include "transfor.h"
#include "multiple.h"
#include "cif_fract.h"
#define MAPS
#include "maps.h"

#ifdef IBMPC
#include <malloc.h>
#endif
#ifndef sun386
#include <stdlib.h>
#endif

#include <string.h>


#ifdef USE_CBFLIB
#include "cbf.h"
#include "cbf_file.h"
#include "cbf_alloc.h"
#include "cbf_string.h"
#else
#define CBF_INTEGER     0x0010  /* Uncompressed integer               */
#define CBF_FLOAT       0x0020  /* Uncompressed IEEE floating-point   */
#endif

#ifndef PI
#define PI 3.14159265358979323846
#endif


/* Macros for commonly used loops */
#define ForEachAtom  for(chain=Database->clist;chain;chain=chain->cnext) \
                     for(group=chain->glist;group;group=group->gnext)    \
                     for(ptr=group->alist;ptr;ptr=ptr->anext)


/* #define LogMapVal(mapval)  mapval<=0.?-1.e30:log((mapval)) */

#define LogMapVal(mapval)  mapval<-1.e-9?-10.-log(-(mapval)):(mapval>1.e-9?10.+log(mapval):0.)



/* Initialise Maps */

void InitialiseMaps( void ) {

  DeleteMaps();
  
  if (vector_create((GenericVec __far * __far *)&MapInfoPtr,
    sizeof(MapInfo),10) ){
      InvalidateCmndLine();
      RasMolFatalExit(MsgStrs[StrMalloc]);      
  }
    
}

/* Delete Maps 

   Delete the maps associated with the current molecule

*/

void DeleteMaps( void ) {
    
    int ii;
    MapInfo mapinfo;
    int shade;
  shade = DefineShade(0xFA,0xFF,0xFA);
    
    if (MapInfoPtr) {
        
        for (ii = 0; ii < MapInfoPtr->size; ii++) {
            vector_get_element((GenericVec __far *)MapInfoPtr,&mapinfo,ii);
            if (mapinfo.MapPointsPtr) {
                vector_free((GenericVec __far * __far *)&mapinfo.MapPointsPtr);
                Shade[shade].refcount--;
            }
            if (mapinfo.MapBondsPtr){
                vector_free((GenericVec __far * __far *)&mapinfo.MapBondsPtr);
                Shade[shade].refcount--;
            }
            if (mapinfo.MapTanglePtr){
                vector_free((GenericVec __far * __far *)&mapinfo.MapTanglePtr);
                Shade[shade].refcount--;
            }
            
            if (mapinfo.MapPtr) {
                if (mapinfo.MapPtr->mapdata)_ffree((void __far *)mapinfo.MapPtr->mapdata);
                _ffree((void __far *)mapinfo.MapPtr);
                mapinfo.MapPtr = NULL;
            }
            
            if (mapinfo.MapMaskPtr) {
                if (mapinfo.MapMaskPtr->mapdata)_ffree((void __far *)mapinfo.MapMaskPtr->mapdata);
                _ffree((void __far *)mapinfo.MapMaskPtr);
                mapinfo.MapMaskPtr = NULL;
            }
            
            if (mapinfo.MapLabel) {
                _ffree((void __far *)mapinfo.MapLabel);
                mapinfo.MapLabel=NULL;
            }
            
            if (mapinfo.MapFile) {
                _ffree((void __far *)mapinfo.MapFile);
                mapinfo.MapFile=NULL;
            }
            
            if (mapinfo.MapGenSel) {
                vector_free((GenericVec __far * __far *)&(mapinfo.MapGenSel ) );
                mapinfo.MapGenSel=NULL;
            }
            
            if (mapinfo.MapMaskGenSel) {
                vector_free((GenericVec __far * __far *)&(mapinfo.MapMaskGenSel ) );
                mapinfo.MapMaskGenSel=NULL;
            }
            
            
        }
        vector_free((GenericVec __far * __far *)&MapInfoPtr);
        
    }
    ReDrawFlag |= RFRefresh;
    MapRadius = 0;
    ReRadius();
    return;
}

/* Delete map number map from the current molecule
   if keepmap is true, only delete the representations */

void DeleteMap( int map, int keepmap ) {

  MapInfo *mapinfo;
  int shade;

  if (MapInfoPtr) {
  
    if (map >=0 && map < MapInfoPtr->size) {

      vector_get_elementptr((GenericVec __far *)MapInfoPtr,(void __far * __far *)&mapinfo,map);
      shade = DefineShade(mapinfo->MapRGBCol[0],mapinfo->MapRGBCol[1],mapinfo->MapRGBCol[2]);
      if (mapinfo->MapPointsPtr) {
        vector_free((GenericVec __far * __far *)&(mapinfo->MapPointsPtr) );
          Shade[shade].refcount--;
          mapinfo->MapPointsPtr = NULL;
      }
      if (mapinfo->MapBondsPtr){
        vector_free((GenericVec __far * __far *)&(mapinfo->MapBondsPtr) );
          Shade[shade].refcount--;
          mapinfo->MapBondsPtr = NULL;
      }
      if (mapinfo->MapTanglePtr){
        vector_free((GenericVec __far * __far *)&(mapinfo->MapTanglePtr ) );
          Shade[shade].refcount--;
          mapinfo->MapTanglePtr = NULL;
      }

      if (!keepmap && mapinfo->MapPtr) {
        if (mapinfo->MapPtr->mapdata)_ffree((void __far *)mapinfo->MapPtr->mapdata);
        _ffree((void __far *)mapinfo->MapPtr);
        mapinfo->MapPtr = NULL;
      }
      
      if (!keepmap && mapinfo->MapMaskPtr) {
        if (mapinfo->MapMaskPtr->mapdata)_ffree((void __far *)mapinfo->MapMaskPtr->mapdata);
        _ffree((void __far *)mapinfo->MapMaskPtr);
        mapinfo->MapMaskPtr = NULL;
      }
      
      if (!keepmap && mapinfo->MapLabel) {
        _ffree((void __far *)mapinfo->MapLabel);
        mapinfo->MapLabel=NULL;
      }

      if (!keepmap && mapinfo->MapFile) {
        _ffree((void __far *)mapinfo->MapFile);
        mapinfo->MapFile=NULL;
      }

      if (!keepmap && mapinfo->MapGenSel) {
        vector_free((GenericVec __far * __far *)&(mapinfo->MapGenSel ) );
        mapinfo->MapGenSel=NULL;
      }

      if (!keepmap && mapinfo->MapMaskGenSel) {
        vector_free((GenericVec __far * __far *)&(mapinfo->MapMaskGenSel ) );
        mapinfo->MapMaskGenSel=NULL;
      }


    }
    ReDrawFlag |= RFRefresh;
  
  }
  MapReRadius();
  ReRadius();
  return;
}


/* DeleteAllMaps 

Delete all the maps associated with all molecules

*/

void DeleteAllMaps( void ) {
    
    int SaveMolecule;
    int i;
    SaveMolecule = MoleculeIndex;
    for (i = 0; i < NumMolecules; i++) {
        SwitchMolecule(i);
        DeleteMaps();      
    }
    SwitchMolecule(SaveMolecule);
};


void MapReRadius( void ) {
    
    int i, j;
    Card dist, ax, ay, az;
    MapPointVec __far *MapPointsPtr;
    MapInfo mapinfo;
    
    MapRadius = 0;
    
    if (MapInfoPtr)
        for (j=0; j<MapInfoPtr->size; j++) {
            vector_get_element((GenericVec __far *)MapInfoPtr,(void __far *)&mapinfo,j );
            MapPointsPtr = mapinfo.MapPointsPtr;
            
            if (MapPointsPtr)
                for (i=0; i<MapPointsPtr->size; i++) {
                    ax = (Card)AbsFun((MapPointsPtr->array[i]).xpos);
                    ay = (Card)AbsFun((MapPointsPtr->array[i]).ypos);
                    az = (Card)AbsFun((MapPointsPtr->array[i]).zpos);
                    dist = (double)ax*ax + 
                        (double)ay*ay + 
                        (double)az*az;
                    if (dist > (double)MapRadius*(double)MapRadius ) MapRadius = (Card)sqrt(dist); 
                }
        }
            
}

#ifdef USE_CBFLIB

int SaveMapFile( FILE *fp, int info, int mapno ) {
    
    cbf_handle cbf;
    MapStruct *map, *mapmask;
    char map_id[81], map_structure_id[81], mask_structure_id[81];
    int ii,jj;
    double ocmap_axismat[3][3], ocmap_axisvec[3];
    double fcmap_axismat[3][3], fcmap_axisvec[3];
    double ocmapmask_axismat[3][3], ocmapmask_axisvec[3];
    double fcmapmask_axismat[3][3], fcmapmask_axisvec[3];
    double rc2oc[3];
    
    MapInfo *mapinfo;
    
    if (mapno < 0 ) return CBF_ARGUMENT;
    if (!MapInfoPtr) return CBF_ARGUMENT;
    if (mapno > MapInfoPtr->size) return CBF_ARGUMENT;
    
    vector_get_elementptr((GenericVec __far *)MapInfoPtr,
                          (void __far * __far *)&mapinfo,mapno );
    
    if (!mapinfo) return 0;
    
    cbf_failnez (cbf_make_handle (&cbf))
        
        sprintf(map_id, "map_%-d", mapno+1);
    
    strcpy (map_structure_id,map_id);
    
    strcat (map_structure_id,"_structure");
    
    strcpy (mask_structure_id,map_id);
    strcat (mask_structure_id,"_mask_structure");
    
    cbf_failnez (cbf_force_new_datablock(cbf,map_id))
        
        cbf_failnez (cbf_new_category(cbf,"map"))
        
        cbf_failnez (cbf_new_column(cbf,"id"))
        cbf_failnez (cbf_set_integervalue(cbf,mapno+1))
        
        if ( mapinfo->MapLabel && *mapinfo->MapLabel)  {
            
            cbf_failnez (cbf_new_column(cbf,"details"))
            cbf_failnez (cbf_set_value(cbf,mapinfo->MapLabel))
            cbf_failnez (cbf_set_typeofvalue(cbf,"dblq"))
            
        } else  if ( mapinfo->MapFile && *mapinfo->MapFile) {
            
            cbf_failnez (cbf_new_column(cbf,"details"))
            cbf_failnez (cbf_set_value(cbf,mapinfo->MapFile))
            cbf_failnez (cbf_set_typeofvalue(cbf,"dblq"))
            
        }
    
    cbf_failnez (cbf_new_column(cbf,"entry_id"))
        
        if (Info.identcode && *Info.identcode) {
            
            cbf_failnez (cbf_set_value(cbf,Info.identcode))
            cbf_failnez (cbf_set_typeofvalue(cbf,"dblq"))
        }
    
    
    map = mapmask = NULL;
    
    if (mapinfo->MapPtr) {
        
        map = mapinfo->MapPtr;
        
    }
    
    if (mapinfo->MapMaskPtr) {
        
        mapmask = mapinfo->MapMaskPtr;
        
    }
    
    if ( map || mapmask )  {
        
        Long map_xbase=0, map_ybase=0, map_zbase=0;
        Long mapmask_xbase=0, mapmask_ybase=0, mapmask_zbase=0;
        double ocmap_xbase=0., ocmap_ybase=0., ocmap_zbase=0.;
        double ocmapmask_xbase=0., ocmapmask_ybase=0, ocmapmask_zbase=0.;
        double fcmap_xbase=0., fcmap_ybase=0., fcmap_zbase=0.;
        double fcmapmask_xbase=0., fcmapmask_ybase=0, fcmapmask_zbase=0.;
        double templen[3];
        double OrigC[3];
        
        rc2oc[0] = 1./250.;
#ifdef INVERT
        rc2oc[1] = -1./250.;
#else
        rc2oc[1] = 1./250.;
#endif
        rc2oc[2] = -1/250.;
        
        OrigC[0] = OrigCX;
        OrigC[1] = OrigCY;
        OrigC[2] = OrigCZ;
        
        if (map) {
            
            map_xbase = map->xorig;
            map_ybase = map->yorig;
            map_zbase = map->zorig;

            Mapm2o(map, map_xbase,map_ybase,map_zbase, 
              ocmap_xbase,ocmap_ybase,ocmap_zbase);
            fcmap_xbase = Info.mato2f[0][0]*ocmap_xbase*rc2oc[0]
                          + Info.mato2f[0][1]*ocmap_ybase*rc2oc[1]
                          + Info.mato2f[0][2]*ocmap_zbase*rc2oc[2]
                          + Info.veco2f[0];
            fcmap_ybase = Info.mato2f[1][0]*ocmap_xbase*rc2oc[0]
                          + Info.mato2f[1][1]*ocmap_ybase*rc2oc[1]
                          + Info.mato2f[1][2]*ocmap_zbase*rc2oc[2]
                          + Info.veco2f[1];
            fcmap_zbase = Info.mato2f[2][0]*ocmap_xbase*rc2oc[0]
                          + Info.mato2f[2][1]*ocmap_ybase*rc2oc[1]
                          + Info.mato2f[2][2]*ocmap_zbase*rc2oc[2]
                          + Info.veco2f[2];
            ocmap_xbase *= 4.*1.e-10;
#ifdef INVERT
            ocmap_ybase *= -4.*1.e-10;
#else
            ocmap_ybase *= 4.*1.e-10;
#endif
            ocmap_zbase *= -4.*1.e-10;
            
            for (jj = 0; jj < 3; jj++) templen[jj] = 0;
            for (ii = 0; ii < 3; ii++) {
              ocmap_axisvec[ii] = (map->mapxlate[ii]+OrigC[ii])*rc2oc[ii];
              for (jj=0; jj<3; jj++) {
                ocmap_axismat[ii][jj] = MapM2R(map,ii,jj)*rc2oc[ii];
                templen[jj] +=  ocmap_axismat[ii][jj]*ocmap_axismat[ii][jj];                  
              }    
            }
            for (jj = 0; jj < 3; jj++) templen[jj] = sqrt(templen[jj]);
            for (ii=0 ; ii<3; ii++) {
              for (jj=0; jj<3; jj++) {
                ocmap_axismat[ii][jj] /= templen[jj];
              }    
            }
            
            matmul(Info.mato2f, ocmap_axismat, fcmap_axismat);
            matvec(Info.mato2f, ocmap_axisvec, fcmap_axisvec);

            for (jj = 0; jj < 3; jj++) templen[jj] = 0;
            for (ii = 0; ii < 3; ii++) {
              for (jj=0; jj<3; jj++) {
                templen[jj] +=  fcmap_axismat[ii][jj]*fcmap_axismat[ii][jj];                  
              }    
            }
            for (jj = 0; jj < 3; jj++) templen[jj] = sqrt(templen[jj]);
            for (ii=0 ; ii<3; ii++) {
              for (jj=0; jj<3; jj++) {
                fcmap_axismat[ii][jj] /= templen[jj];
              }    
            }


                
         }
        
        if (mapmask) {
            
            mapmask_xbase = mapmask->xorig;
            mapmask_ybase = mapmask->yorig;
            mapmask_zbase = mapmask->zorig;

            Mapm2o(map, mapmask_xbase,mapmask_ybase,mapmask_zbase, 
              ocmapmask_xbase,ocmapmask_ybase,ocmapmask_zbase);
              
            ocmapmask_xbase += OrigCX;
            ocmapmask_ybase += OrigCY;
            ocmapmask_zbase += OrigCZ;

            fcmapmask_xbase = Info.mato2f[0][0]*ocmapmask_xbase*rc2oc[0]
                          + Info.mato2f[0][1]*ocmapmask_ybase*rc2oc[1]
                          + Info.mato2f[0][2]*ocmapmask_zbase*rc2oc[2]
                          + Info.veco2f[0];
            fcmapmask_ybase = Info.mato2f[1][0]*ocmapmask_xbase*rc2oc[0]
                          + Info.mato2f[1][1]*ocmapmask_ybase*rc2oc[1]
                          + Info.mato2f[1][2]*ocmapmask_zbase*rc2oc[2]
                          + Info.veco2f[1];
            fcmapmask_zbase = Info.mato2f[2][0]*ocmapmask_xbase*rc2oc[0]
                          + Info.mato2f[2][1]*ocmapmask_ybase*rc2oc[1]
                          + Info.mato2f[2][2]*ocmapmask_zbase*rc2oc[2]
                          + Info.veco2f[2];
            ocmapmask_xbase *= 4.*1.e-10;
#ifdef INVERT
            ocmapmask_ybase *= -4.*1.e-10;
#else
            ocmapmask_ybase *= 4.*1.e-10;
#endif
            ocmapmask_zbase *= -4.*1.e-10;

            for (jj = 0; jj < 3; jj++) templen[jj] = 0;
            for (ii = 0; ii < 3; ii++) {
              ocmapmask_axisvec[ii] = (mapmask->mapxlate[ii]+OrigC[ii])*rc2oc[ii];
              for (jj=0; jj<3; jj++) {
                ocmapmask_axismat[ii][jj] = MapM2R(mapmask,ii,jj)*rc2oc[ii];
                templen[jj] +=  ocmapmask_axismat[ii][jj]*ocmapmask_axismat[ii][jj];                  
              }    
            }
            for (jj = 0; jj < 3; jj++) templen[jj] = sqrt(templen[jj]);
            for (ii=0 ; ii<3; ii++) {
              for (jj=0; jj<3; jj++) {
                ocmapmask_axismat[ii][jj] /= templen[jj];
              }    
            }
            
            matmul(Info.mato2f, ocmapmask_axismat, fcmapmask_axismat);
            matvec(Info.mato2f, ocmapmask_axisvec, fcmapmask_axisvec);

            for (jj = 0; jj < 3; jj++) templen[jj] = 0;
            for (ii = 0; ii < 3; ii++) {
              for (jj=0; jj<3; jj++) {
                templen[jj] +=  fcmapmask_axismat[ii][jj]*fcmapmask_axismat[ii][jj];                  
              }    
            }
            for (jj = 0; jj < 3; jj++) templen[jj] = sqrt(templen[jj]);
            for (ii=0 ; ii<3; ii++) {
              for (jj=0; jj<3; jj++) {
                fcmapmask_axismat[ii][jj] /= templen[jj];
              }    
            }


        }
        
        cbf_failnez (cbf_new_category(cbf,"map_segment"))
            
            cbf_failnez (cbf_new_column(cbf,"map_id"))
            cbf_failnez (cbf_set_value(cbf,map_id))
            
            cbf_failnez (cbf_new_column(cbf,"id"))
            cbf_failnez (cbf_set_value(cbf,map_id))
            
            cbf_failnez (cbf_new_column(cbf,"array_id"))
            
            if (map)  {
                
                cbf_failnez (cbf_set_value(cbf,map_structure_id))
                
            }
        
        cbf_failnez (cbf_new_column(cbf,"binary_id"))
            
            if (map)  {
                
                cbf_failnez (cbf_set_integervalue(cbf,1))
                
            }
        
        cbf_failnez (cbf_new_column(cbf,"mask_array_id"))
            
            if (mapmask)  {
                
                cbf_failnez (cbf_set_value(cbf,mask_structure_id))
                
            }
        
        cbf_failnez (cbf_new_column(cbf,"mask_binary_id"))
            
            if (mapmask)  {
                
                cbf_failnez (cbf_set_integervalue(cbf,2))
                
            }
        
        cbf_failnez (cbf_new_category(cbf,"array_structure"))
            
            if (map)  {
                
                cbf_failnez (cbf_new_column(cbf,"id"))
                cbf_failnez (cbf_set_value(cbf,map_structure_id))
                
                cbf_failnez (cbf_new_column(cbf,"byte_order"))
                cbf_failnez (cbf_set_value(cbf,"little_endian"))
                
                cbf_failnez (cbf_new_column(cbf,"compression_type"))
                cbf_failnez (cbf_set_value(cbf,"packed_v2"))
                
                cbf_failnez (cbf_new_column(cbf,"encoding_type"))
                
                switch (map->eltype) {
                    
                    case CBF_INTEGER:
                        
                        switch (map->elsize) {
                            
                            case 1: cbf_failnez (cbf_set_value(cbf, "signed 8-bit integer")); break;
                            case 2: cbf_failnez (cbf_set_value(cbf, "signed 16-bit integer")); break;
                            case 4: cbf_failnez (cbf_set_value(cbf, "signed 32-bit integer")); break;
                            case 8: cbf_failnez (cbf_set_value(cbf, "signed 64-bit integer")); break;
                            default: return CBF_FORMAT;
                                
                        }
                        
                        break;
                        
                    case CBF_FLOAT:
                        
                        switch (map->elsize) {
                            
                            case 4: cbf_failnez (cbf_set_value(cbf, "signed 32-bit real IEEE")); break;
                            case 8: cbf_failnez (cbf_set_value(cbf, "signed 64-bit real IEEE")); break;
                            default: return CBF_FORMAT;
                                
                        }
                        
                        break;
                        
                    default:  return CBF_FORMAT;
                        
                }
                
            }
        
        if (mapmask)  {
            
            cbf_failnez (cbf_new_row(cbf))
            
            cbf_failnez (cbf_require_column(cbf,"id"))
            cbf_failnez (cbf_set_value(cbf,mask_structure_id))
            
            cbf_failnez (cbf_require_column(cbf,"byte_order"))
            cbf_failnez (cbf_set_value(cbf,"little_endian"))
            
            cbf_failnez (cbf_require_column(cbf,"compression_type"))
            
            cbf_failnez (cbf_set_value(cbf,"packed_v2"))
            
            cbf_failnez (cbf_require_column(cbf,"encoding_type"))
            
            switch (mapmask->eltype) {
                
                case CBF_INTEGER:
                    
                    switch (mapmask->elsize) {
                        
                        case 1: cbf_failnez (cbf_set_value(cbf, "signed 8-bit integer")); break;
                        case 2: cbf_failnez (cbf_set_value(cbf, "signed 16-bit integer")); break;
                        case 4: cbf_failnez (cbf_set_value(cbf, "signed 32-bit integer")); break;
                        case 8: cbf_failnez (cbf_set_value(cbf, "signed 64-bit integer")); break;
                        default: return CBF_FORMAT;
                            
                    }
                    
                    break;
                    
                case CBF_FLOAT:
                    
                    switch (mapmask->elsize) {
                        
                        case 4: cbf_failnez (cbf_set_value(cbf, "signed 32-bit real IEEE")); break;
                        case 8: cbf_failnez (cbf_set_value(cbf, "signed 64-bit real IEEE")); break;
                        default: return CBF_FORMAT;
                            
                    }
                    
                    break;
                    
                default:  return CBF_FORMAT;
                    
            }
              
        }
        
        cbf_failnez (cbf_new_category(cbf,"array_structure_list"))
            
            if (map) {
                
                cbf_failnez (cbf_new_column(cbf,"array_id"))
                cbf_failnez (cbf_set_value(cbf,map_structure_id))
                
                cbf_failnez (cbf_new_column(cbf,"index"))
                cbf_failnez (cbf_set_integervalue(cbf,1))
                
                cbf_failnez (cbf_new_column(cbf,"dimension"))
                cbf_failnez (cbf_set_integervalue(cbf,map->xhigh-map->xlow+1))
                
                cbf_failnez (cbf_new_column(cbf,"precedence"))
                cbf_failnez (cbf_set_integervalue(cbf,1))
                
                cbf_failnez (cbf_new_column(cbf,"direction"))
                cbf_failnez (cbf_set_value(cbf,"increasing"))
                
                cbf_failnez (cbf_new_column(cbf,"axis_set_id"))
                if (map->maptype==MAP_FRACTIONAL) {
                    cbf_failnez (cbf_set_value(cbf,"MAP_CELL_X"))          
                } else {
                    cbf_failnez (cbf_set_value(cbf,"MAP_ORTHOGONAL_X"))          
                }
                
                cbf_failnez (cbf_new_row(cbf))
                
                cbf_failnez (cbf_find_column(cbf,"array_id"))
                cbf_failnez (cbf_set_value(cbf,map_structure_id))
                
                cbf_failnez (cbf_find_column(cbf,"index"))
                cbf_failnez (cbf_set_integervalue(cbf,2))
                
                cbf_failnez (cbf_find_column(cbf,"dimension"))
                cbf_failnez (cbf_set_integervalue(cbf,map->yhigh-map->ylow+1))
                
                cbf_failnez (cbf_find_column(cbf,"precedence"))
                cbf_failnez (cbf_set_integervalue(cbf,2))
                
                cbf_failnez (cbf_find_column(cbf,"direction"))
                cbf_failnez (cbf_set_value(cbf,"increasing"))
                
                cbf_failnez (cbf_find_column(cbf,"axis_set_id")) 
                if (map->maptype==MAP_FRACTIONAL) {
                    cbf_failnez (cbf_set_value(cbf,"MAP_CELL_Y"))          
                } else {
                    cbf_failnez (cbf_set_value(cbf,"MAP_ORTHOGONAL_Y"))          
                }
                
                cbf_failnez (cbf_new_row(cbf))
                
                cbf_failnez (cbf_find_column(cbf,"array_id"))
                cbf_failnez (cbf_set_value(cbf,map_structure_id))
                
                cbf_failnez (cbf_find_column(cbf,"index"))
                cbf_failnez (cbf_set_integervalue(cbf,3))
                
                cbf_failnez (cbf_find_column(cbf,"dimension"))
                cbf_failnez (cbf_set_integervalue(cbf,map->zhigh-map->zlow+1))
                
                cbf_failnez (cbf_find_column(cbf,"precedence"))
                cbf_failnez (cbf_set_integervalue(cbf,3))
                
                cbf_failnez (cbf_find_column(cbf,"direction"))
                cbf_failnez (cbf_set_value(cbf,"increasing"))
                
                cbf_failnez (cbf_find_column(cbf,"axis_set_id"))
                if (map->maptype==MAP_FRACTIONAL) {
                    cbf_failnez (cbf_set_value(cbf,"MAP_CELL_Z"))          
                } else {
                    cbf_failnez (cbf_set_value(cbf,"MAP_ORTHOGONAL_Z"))          
                }
                
            }
        
        if (mapmask) {
            
            cbf_failnez (cbf_new_row(cbf))
            
            cbf_failnez (cbf_require_column(cbf,"array_id"))
            cbf_failnez (cbf_set_value(cbf,mask_structure_id))
            
            cbf_failnez (cbf_require_column(cbf,"index"))
            cbf_failnez (cbf_set_integervalue(cbf,1))
            
            cbf_failnez (cbf_require_column(cbf,"dimension"))
            cbf_failnez (cbf_set_integervalue(cbf,mapmask->xhigh-mapmask->xlow+1))
            
            cbf_failnez (cbf_require_column(cbf,"precedence"))
            cbf_failnez (cbf_set_integervalue(cbf,1))
            
            cbf_failnez (cbf_require_column(cbf,"direction"))
            cbf_failnez (cbf_set_value(cbf,"increasing"))
            
            cbf_failnez (cbf_require_column(cbf,"axis_set_id"))
            if (mapmask->maptype==MAP_FRACTIONAL) {
                cbf_failnez (cbf_set_value(cbf,"MASK_CELL_X"))          
            } else {
                cbf_failnez (cbf_set_value(cbf,"MASK_ORTHOGONAL_X"))          
            }
            
            cbf_failnez (cbf_new_row(cbf))
            
            cbf_failnez (cbf_find_column(cbf,"array_id"))
            cbf_failnez (cbf_set_value(cbf,mask_structure_id))
            
            cbf_failnez (cbf_find_column(cbf,"index"))
            cbf_failnez (cbf_set_integervalue(cbf,2))
            
            cbf_failnez (cbf_find_column(cbf,"dimension"))
            cbf_failnez (cbf_set_integervalue(cbf,mapmask->yhigh-mapmask->ylow+1))
            
            cbf_failnez (cbf_find_column(cbf,"precedence"))
            cbf_failnez (cbf_set_integervalue(cbf,2))
            
            cbf_failnez (cbf_find_column(cbf,"direction"))
            cbf_failnez (cbf_set_value(cbf,"increasing"))
            
            cbf_failnez (cbf_find_column(cbf,"axis_set_id"))
            if (mapmask->maptype==MAP_FRACTIONAL) {
                cbf_failnez (cbf_set_value(cbf,"MASK_CELL_Y"))          
            } else {
                cbf_failnez (cbf_set_value(cbf,"MASK_ORTHOGONAL_Y"))          
            }
            
            cbf_failnez (cbf_new_row(cbf))
            
            cbf_failnez (cbf_find_column(cbf,"array_id"))
            cbf_failnez (cbf_set_value(cbf,mask_structure_id))
            
            cbf_failnez (cbf_find_column(cbf,"index"))
            cbf_failnez (cbf_set_integervalue(cbf,3))
            
            cbf_failnez (cbf_find_column(cbf,"dimension"))
            cbf_failnez (cbf_set_integervalue(cbf,mapmask->zhigh-mapmask->zlow+1))
            
            cbf_failnez (cbf_find_column(cbf,"precedence"))
            cbf_failnez (cbf_set_integervalue(cbf,3))
            
            cbf_failnez (cbf_find_column(cbf,"direction"))
            cbf_failnez (cbf_set_value(cbf,"increasing"))
            
            cbf_failnez (cbf_find_column(cbf,"axis_set_id"))
            if (mapmask->maptype==MAP_FRACTIONAL) {
                cbf_failnez (cbf_set_value(cbf,"MASK_CELL_Z"))          
            } else {
                cbf_failnez (cbf_set_value(cbf,"MASK_ORTHOGONAL_Z"))          
            }
            
        }
        
        cbf_failnez (cbf_new_category(cbf,"array_structure_list_axis"))
            
            if (map) {
                
                cbf_failnez (cbf_new_column(cbf,"axis_id"))
                if (map->maptype==MAP_FRACTIONAL) {
                    cbf_failnez (cbf_set_value(cbf,"MAP_CELL_X"))          
                } else {
                    cbf_failnez (cbf_set_value(cbf,"MAP_ORTHOGONAL_X"))          
                }
                
                cbf_failnez (cbf_new_column(cbf,"axis_set_id"))
                if (map->maptype==MAP_FRACTIONAL) {
                    cbf_failnez (cbf_set_value(cbf,"MAP_CELL_X"))          
                } else {
                    cbf_failnez (cbf_set_value(cbf,"MAP_ORTHOGONAL_X"))          
                }
                
                if (map->maptype == MAP_ORTHOGONAL) {
                    
                    cbf_failnez (cbf_new_column(cbf,"displacement"))
                    cbf_failnez (cbf_set_doublevalue(cbf,"%-g",
                      ((double)map->xlow*map->xint)*4.e-10))
                    
                    cbf_failnez (cbf_new_column(cbf,"displacement_increment"))
                    cbf_failnez (cbf_set_doublevalue(cbf,"%-g",((double)map->xint)*4.e-10))
                    
                } else if (map->maptype == MAP_FRACTIONAL) {
                    
                    cbf_failnez (cbf_new_column(cbf,"fract_displacement"))
                    cbf_failnez (cbf_set_doublevalue(cbf,"%-g",
                      (double)map->xlow/(double)map->adiv ))
                    
                    cbf_failnez (cbf_new_column(cbf,"fract_displacement_increment"))
                    cbf_failnez (cbf_set_doublevalue(cbf,"%-g",1./(double)(map->adiv)))
                    
                }
                
                cbf_failnez (cbf_new_row(cbf))
                cbf_failnez (cbf_find_column(cbf,"axis_id"))
                if (map->maptype==MAP_FRACTIONAL) {
                    cbf_failnez (cbf_set_value(cbf,"MAP_CELL_Y"))          
                } else {
                    cbf_failnez (cbf_set_value(cbf,"MAP_ORTHOGONAL_Y"))          
                }
                
                cbf_failnez (cbf_find_column(cbf,"axis_set_id"))
                if (map->maptype==MAP_FRACTIONAL) {
                    cbf_failnez (cbf_set_value(cbf,"MAP_CELL_Y"))          
                } else {
                    cbf_failnez (cbf_set_value(cbf,"MAP_ORTHOGONAL_Y"))          
                }
                
                if (map->maptype == MAP_ORTHOGONAL) {
                    
                    cbf_failnez (cbf_find_column(cbf,"displacement"))
                    cbf_failnez (cbf_set_doublevalue(cbf,"%-g",
                      ((double)map->xlow*map->yint)*4.e-10))
                    
                    cbf_failnez (cbf_find_column(cbf,"displacement_increment"))
                    cbf_failnez (cbf_set_doublevalue(cbf,"%-g",((double)map->yint)*4.e-10))
                    
                } else if (map->maptype == MAP_FRACTIONAL) {
                    
                    cbf_failnez (cbf_find_column(cbf,"fract_displacement"))
                    cbf_failnez (cbf_set_doublevalue(cbf,"%-g",
                      (double)map->ylow/(double)map->bdiv ))
                    
                    cbf_failnez (cbf_find_column(cbf,"fract_displacement_increment"))
                    cbf_failnez (cbf_set_doublevalue(cbf,"%-g",1./(double)(map->bdiv)))
                    
                }
                
                cbf_failnez (cbf_new_row(cbf))
                cbf_failnez (cbf_find_column(cbf,"axis_id"))
                if (map->maptype==MAP_FRACTIONAL) {
                    cbf_failnez (cbf_set_value(cbf,"MAP_CELL_Z"))          
                } else {
                    cbf_failnez (cbf_set_value(cbf,"MAP_ORTHOGONAL_Z"))          
                }
                
                cbf_failnez (cbf_find_column(cbf,"axis_set_id"))
                if (map->maptype==MAP_FRACTIONAL) {
                    cbf_failnez (cbf_set_value(cbf,"MAP_CELL_Z"))          
                } else {
                    cbf_failnez (cbf_set_value(cbf,"MAP_ORTHOGONAL_Z"))          
                }
                
                if (map->maptype == MAP_ORTHOGONAL) {
                    
                    cbf_failnez (cbf_find_column(cbf,"displacement"))
                    cbf_failnez (cbf_set_doublevalue(cbf,"%-g",
                      ((double)map->zlow*map->zint)*4.e-10))
                    
                    cbf_failnez (cbf_find_column(cbf,"displacement_increment"))
                    cbf_failnez (cbf_set_doublevalue(cbf,"%-g",((double)map->zint)*4.e-10))
                    
                } else if (map->maptype == MAP_FRACTIONAL) {
                    
                    cbf_failnez (cbf_find_column(cbf,"fract_displacement"))
                    cbf_failnez (cbf_set_doublevalue(cbf,"%-g",
                      (double)map->zlow/(double)map->cdiv ))
                    
                    cbf_failnez (cbf_find_column(cbf,"fract_displacement_increment"))
                    cbf_failnez (cbf_set_doublevalue(cbf,"%-g",1./(double)(map->cdiv)))
                    
                }
                
                
            }
        
        if (mapmask) {
            
            cbf_failnez (cbf_new_row(cbf))
            cbf_failnez (cbf_require_column(cbf,"axis_id"))
            if (mapmask->maptype==MAP_FRACTIONAL) {
                cbf_failnez (cbf_set_value(cbf,"MASK_CELL_X"))          
            } else {
                cbf_failnez (cbf_set_value(cbf,"MASK_ORTHOGONAL_X"))          
            }
            
            cbf_failnez (cbf_require_column(cbf,"axis_set_id"))
            if (mapmask->maptype==MAP_FRACTIONAL) {
                cbf_failnez (cbf_set_value(cbf,"MASK_CELL_X"))          
            } else {
                cbf_failnez (cbf_set_value(cbf,"MASK_ORTHOGONAL_X"))          
            }
            
            if (mapmask->maptype == MAP_ORTHOGONAL) {
                
                cbf_failnez (cbf_require_column(cbf,"displacement"))
                cbf_failnez (cbf_set_doublevalue(cbf,"%-g",
                  ((double)mapmask->xlow*mapmask->xint)*4.e-10))
                
                cbf_failnez (cbf_require_column(cbf,"displacement_increment"))
                cbf_failnez (cbf_set_doublevalue(cbf,"%-g",((double)mapmask->xint)*4.e-10))
                
            } else if (mapmask->maptype == MAP_FRACTIONAL) {
                
                cbf_failnez (cbf_require_column(cbf,"fract_displacement"))
                cbf_failnez (cbf_set_doublevalue(cbf,"%-g",
                  (double)mapmask->xlow/(double)mapmask->adiv ))
                
                cbf_failnez (cbf_require_column(cbf,"fract_displacement_increment"))
                cbf_failnez (cbf_set_doublevalue(cbf,"%-g",1./(double)(mapmask->adiv)))
                
            }
            
            cbf_failnez (cbf_new_row(cbf))
            cbf_failnez (cbf_find_column(cbf,"axis_id"))
            if (mapmask->maptype==MAP_FRACTIONAL) {
                cbf_failnez (cbf_set_value(cbf,"MASK_CELL_Y"))          
            } else {
                cbf_failnez (cbf_set_value(cbf,"MASK_ORTHOGONAL_Y"))          
            }
            
            cbf_failnez (cbf_find_column(cbf,"axis_set_id"))
            if (mapmask->maptype==MAP_FRACTIONAL) {
                cbf_failnez (cbf_set_value(cbf,"MASK_CELL_Y"))          
            } else {
                cbf_failnez (cbf_set_value(cbf,"MASK_ORTHOGONAL_Y"))          
            }
            
            if (mapmask->maptype == MAP_ORTHOGONAL) {
                
                cbf_failnez (cbf_find_column(cbf,"displacement"))
                cbf_failnez (cbf_set_doublevalue(cbf,"%-g",
                  ((double)mapmask->ylow*mapmask->yint)*4.e-10))
                
                cbf_failnez (cbf_find_column(cbf,"displacement_increment"))
                cbf_failnez (cbf_set_doublevalue(cbf,"%-g",((double)mapmask->yint)*4.e-10))
                
            } else if (mapmask->maptype == MAP_FRACTIONAL) {
                
                cbf_failnez (cbf_find_column(cbf,"fract_displacement"))
                cbf_failnez (cbf_set_doublevalue(cbf,"%-g",
                  (double)mapmask->ylow/(double)mapmask->bdiv ))
                
                cbf_failnez (cbf_find_column(cbf,"fract_displacement_increment"))
                cbf_failnez (cbf_set_doublevalue(cbf,"%-g",1./(double)(mapmask->bdiv)))
                
            }
            
            cbf_failnez (cbf_new_row(cbf))
            cbf_failnez (cbf_find_column(cbf,"axis_id"))
            if (mapmask->maptype==MAP_FRACTIONAL) {
                cbf_failnez (cbf_set_value(cbf,"MASK_CELL_Z"))          
            } else {
                cbf_failnez (cbf_set_value(cbf,"MASK_ORTHOGONAL_Z"))          
            }
            
            cbf_failnez (cbf_find_column(cbf,"axis_set_id"))
            if (mapmask->maptype==MAP_FRACTIONAL) {
                cbf_failnez (cbf_set_value(cbf,"MASK_CELL_Z"))          
            } else {
                cbf_failnez (cbf_set_value(cbf,"MASK_ORTHOGONAL_Z"))          
            }
            
            if (mapmask->maptype == MAP_ORTHOGONAL) {
                
                cbf_failnez (cbf_find_column(cbf,"displacement"))
                cbf_failnez (cbf_set_doublevalue(cbf,"%-g",
                  ((double)mapmask->zlow*mapmask->zint)*4.e-10))
                
                cbf_failnez (cbf_find_column(cbf,"displacement_increment"))
                cbf_failnez (cbf_set_doublevalue(cbf,"%-g",((double)mapmask->zint)*4.e-10))
                
            } else if (mapmask->maptype == MAP_FRACTIONAL) {
                
                cbf_failnez (cbf_find_column(cbf,"fract_displacement"))
                cbf_failnez (cbf_set_doublevalue(cbf,"%-g",
                  (double)mapmask->zlow/(double)mapmask->cdiv ))
                
                cbf_failnez (cbf_find_column(cbf,"fract_displacement_increment"))
                cbf_failnez (cbf_set_doublevalue(cbf,"%-g",1./(double)(mapmask->cdiv)))
                
            }
            
            
        }
        
        cbf_failnez (cbf_new_category(cbf,"axis"))
            
            if ((map && map->maptype == MAP_FRACTIONAL) ||
                (mapmask && mapmask->maptype == MAP_FRACTIONAL)) {
                
                cbf_failnez (cbf_new_column(cbf,"id"))
                cbf_failnez (cbf_set_value(cbf,"CELL_A")) 
                
                cbf_failnez (cbf_new_column(cbf,"system"))
                cbf_failnez (cbf_set_value(cbf,"fractional")) 
                
                cbf_failnez (cbf_new_column(cbf,"vector[1]"))
                cbf_failnez (cbf_set_value(cbf,"1")) 
                
                cbf_failnez (cbf_new_column(cbf,"vector[2]"))
                cbf_failnez (cbf_set_value(cbf,"0"))
                
                cbf_failnez (cbf_new_column(cbf,"vector[3]"))
                cbf_failnez (cbf_set_value(cbf,"0"))    
            
                cbf_failnez (cbf_new_column(cbf,"offset[1]"))
                cbf_failnez (cbf_set_value(cbf,"0")) 
            
                cbf_failnez (cbf_new_column(cbf,"offset[2]"))
                cbf_failnez (cbf_set_value(cbf,"0")) 
            
                cbf_failnez (cbf_new_column(cbf,"offset[3]"))
                cbf_failnez (cbf_set_value(cbf,"0")) 

                cbf_failnez (cbf_new_row(cbf))
                
                cbf_failnez (cbf_find_column(cbf,"id"))
                cbf_failnez (cbf_set_value(cbf,"CELL_B")) 
                
                cbf_failnez (cbf_find_column(cbf,"system"))
                cbf_failnez (cbf_set_value(cbf,"fractional")) 
                
                cbf_failnez (cbf_find_column(cbf,"vector[1]"))
                cbf_failnez (cbf_set_value(cbf,"0")) 
                
                cbf_failnez (cbf_find_column(cbf,"vector[2]"))
                cbf_failnez (cbf_set_value(cbf,"1"))
                
                cbf_failnez (cbf_find_column(cbf,"vector[3]"))
                cbf_failnez (cbf_set_value(cbf,"0")) 
                
                cbf_failnez (cbf_find_column(cbf,"offset[1]"))
                cbf_failnez (cbf_set_value(cbf,"0")) 
            
                cbf_failnez (cbf_find_column(cbf,"offset[2]"))
                cbf_failnez (cbf_set_value(cbf,"0")) 
            
                cbf_failnez (cbf_find_column(cbf,"offset[3]"))
                cbf_failnez (cbf_set_value(cbf,"0")) 

                cbf_failnez (cbf_new_row(cbf))
                
                cbf_failnez (cbf_find_column(cbf,"id"))
                cbf_failnez (cbf_set_value(cbf,"CELL_C")) 
                
                cbf_failnez (cbf_find_column(cbf,"system"))
                cbf_failnez (cbf_set_value(cbf,"fractional")) 
                
                cbf_failnez (cbf_find_column(cbf,"vector[1]"))
                cbf_failnez (cbf_set_value(cbf,"0")) 
                
                cbf_failnez (cbf_find_column(cbf,"vector[2]"))
                cbf_failnez (cbf_set_value(cbf,"0"))
                
                cbf_failnez (cbf_find_column(cbf,"vector[3]"))
                cbf_failnez (cbf_set_value(cbf,"1")) 
                
                cbf_failnez (cbf_find_column(cbf,"offset[1]"))
                cbf_failnez (cbf_set_value(cbf,"0")) 
            
                cbf_failnez (cbf_find_column(cbf,"offset[2]"))
                cbf_failnez (cbf_set_value(cbf,"0")) 
            
                cbf_failnez (cbf_find_column(cbf,"offset[3]"))
                cbf_failnez (cbf_set_value(cbf,"0")) 
                
            }
        
        if ((map && map->maptype == MAP_ORTHOGONAL) ||
            (mapmask && mapmask->maptype == MAP_ORTHOGONAL)) {
            
            cbf_failnez (cbf_new_row(cbf))
            
            cbf_failnez (cbf_require_column(cbf,"id"))
            cbf_failnez (cbf_set_value(cbf,"ORTHOGONAL_X")) 
            
            cbf_failnez (cbf_require_column(cbf,"system"))
            cbf_failnez (cbf_set_value(cbf,"orthogonal")) 
            
            cbf_failnez (cbf_require_column(cbf,"vector[1]"))
            cbf_failnez (cbf_set_value(cbf,"1")) 
            
            cbf_failnez (cbf_require_column(cbf,"vector[2]"))
            cbf_failnez (cbf_set_value(cbf,"0"))
            
            cbf_failnez (cbf_require_column(cbf,"vector[3]"))
            cbf_failnez (cbf_set_value(cbf,"0")) 
            
            cbf_failnez (cbf_require_column(cbf,"offset[1]"))
            cbf_failnez (cbf_set_value(cbf,"0")) 
            
            cbf_failnez (cbf_require_column(cbf,"offset[2]"))
            cbf_failnez (cbf_set_value(cbf,"0")) 
            
            cbf_failnez (cbf_require_column(cbf,"offset[3]"))
            cbf_failnez (cbf_set_value(cbf,"0")) 

            cbf_failnez (cbf_new_row(cbf))
            
            cbf_failnez (cbf_find_column(cbf,"id"))
            cbf_failnez (cbf_set_value(cbf,"ORTHOGONAL_Y")) 
            
            cbf_failnez (cbf_find_column(cbf,"system"))
            cbf_failnez (cbf_set_value(cbf,"orthogonal")) 
            
            cbf_failnez (cbf_find_column(cbf,"vector[1]"))
            cbf_failnez (cbf_set_value(cbf,"0")) 
            
            cbf_failnez (cbf_find_column(cbf,"vector[2]"))
            cbf_failnez (cbf_set_value(cbf,"1"))
            
            cbf_failnez (cbf_find_column(cbf,"vector[3]"))
            cbf_failnez (cbf_set_value(cbf,"0")) 
            
            cbf_failnez (cbf_find_column(cbf,"offset[1]"))
            cbf_failnez (cbf_set_value(cbf,"0")) 
            
            cbf_failnez (cbf_find_column(cbf,"offset[2]"))
            cbf_failnez (cbf_set_value(cbf,"0")) 
            
            cbf_failnez (cbf_find_column(cbf,"offset[3]"))
            cbf_failnez (cbf_set_value(cbf,"0")) 
            
            cbf_failnez (cbf_new_row(cbf))
            
            cbf_failnez (cbf_find_column(cbf,"id"))
            cbf_failnez (cbf_set_value(cbf,"ORTHOGONAL_Z")) 
            
            cbf_failnez (cbf_find_column(cbf,"system"))
            cbf_failnez (cbf_set_value(cbf,"orthogonal")) 
            
            cbf_failnez (cbf_find_column(cbf,"vector[1]"))
            cbf_failnez (cbf_set_value(cbf,"0")) 
            
            cbf_failnez (cbf_find_column(cbf,"vector[2]"))
            cbf_failnez (cbf_set_value(cbf,"0"))
            
            cbf_failnez (cbf_find_column(cbf,"vector[3]"))
            cbf_failnez (cbf_set_value(cbf,"1")) 
            
            cbf_failnez (cbf_find_column(cbf,"offset[1]"))
            cbf_failnez (cbf_set_value(cbf,"0")) 
            
            cbf_failnez (cbf_find_column(cbf,"offset[2]"))
            cbf_failnez (cbf_set_value(cbf,"0")) 
            
            cbf_failnez (cbf_find_column(cbf,"offset[3]"))
            cbf_failnez (cbf_set_value(cbf,"0")) 
           
             
        }
        
        if (map && map->maptype == MAP_ORTHOGONAL)  {
            
            cbf_failnez (cbf_new_row(cbf))
            
            cbf_failnez (cbf_require_column(cbf,"id"))
            cbf_failnez (cbf_set_value(cbf,"MAP_ORTHOGONAL_X")) 
            
            cbf_failnez (cbf_require_column(cbf,"system"))
            cbf_failnez (cbf_set_value(cbf,"orthogonal")) 
            
            cbf_failnez (cbf_find_column(cbf,"vector[1]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",ocmap_axismat[0][0])) 
            
            cbf_failnez (cbf_find_column(cbf,"vector[2]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",ocmap_axismat[1][0]))
            
            cbf_failnez (cbf_find_column(cbf,"vector[3]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",ocmap_axismat[2][0])) 
            
            cbf_failnez (cbf_find_column(cbf,"offset[1]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",ocmap_axisvec[0])) 
            
            cbf_failnez (cbf_find_column(cbf,"offset[2]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",ocmap_axisvec[1]))
            
            cbf_failnez (cbf_find_column(cbf,"offset[3]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",ocmap_axisvec[2])) 
            
            cbf_failnez (cbf_new_row(cbf))
            
            cbf_failnez (cbf_find_column(cbf,"id"))
            cbf_failnez (cbf_set_value(cbf,"MAP_ORTHOGONAL_Y")) 
            
            cbf_failnez (cbf_find_column(cbf,"system"))
            cbf_failnez (cbf_set_value(cbf,"orthogonal")) 
            
            cbf_failnez (cbf_find_column(cbf,"vector[1]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",ocmap_axismat[0][1])) 
            
            cbf_failnez (cbf_find_column(cbf,"vector[2]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",ocmap_axismat[1][1]))
            
            cbf_failnez (cbf_find_column(cbf,"vector[3]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",ocmap_axismat[2][1])) 
            
            cbf_failnez (cbf_find_column(cbf,"offset[1]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",ocmap_axisvec[0])) 
            
            cbf_failnez (cbf_find_column(cbf,"offset[2]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",ocmap_axisvec[1]))
            
            cbf_failnez (cbf_find_column(cbf,"offset[3]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",ocmap_axisvec[2])) 
            
            cbf_failnez (cbf_new_row(cbf))
            
            cbf_failnez (cbf_find_column(cbf,"id"))
            cbf_failnez (cbf_set_value(cbf,"MAP_ORTHOGONAL_Z")) 
            
            cbf_failnez (cbf_find_column(cbf,"system"))
            cbf_failnez (cbf_set_value(cbf,"orthogonal")) 
            
            cbf_failnez (cbf_find_column(cbf,"vector[1]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",ocmap_axismat[0][2])) 
            
            cbf_failnez (cbf_find_column(cbf,"vector[2]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",ocmap_axismat[1][2]))
            
            cbf_failnez (cbf_find_column(cbf,"vector[3]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",ocmap_axismat[2][2])) 
            
            cbf_failnez (cbf_find_column(cbf,"offset[1]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",ocmap_axisvec[0])) 
            
            cbf_failnez (cbf_find_column(cbf,"offset[2]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",ocmap_axisvec[1]))
            
            cbf_failnez (cbf_find_column(cbf,"offset[3]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",ocmap_axisvec[2])) 
             
        }
        
        if (map && map->maptype == MAP_FRACTIONAL)  {
            
            cbf_failnez (cbf_new_row(cbf))
            
            cbf_failnez (cbf_require_column(cbf,"id"))
            cbf_failnez (cbf_set_value(cbf,"MAP_CELL_X")) 
            
            cbf_failnez (cbf_require_column(cbf,"system"))
            cbf_failnez (cbf_set_value(cbf,"fractional")) 
            
            cbf_failnez (cbf_find_column(cbf,"vector[1]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",fcmap_axismat[0][0])) 
            
            cbf_failnez (cbf_find_column(cbf,"vector[2]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",fcmap_axismat[1][0]))
            
            cbf_failnez (cbf_find_column(cbf,"vector[3]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",fcmap_axismat[2][0])) 
            
            cbf_failnez (cbf_find_column(cbf,"offset[1]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",fcmap_axisvec[0])) 
            
            cbf_failnez (cbf_find_column(cbf,"offset[2]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",fcmap_axisvec[1]))
            
            cbf_failnez (cbf_find_column(cbf,"offset[3]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",fcmap_axisvec[2])) 
            
            cbf_failnez (cbf_new_row(cbf))
            
            cbf_failnez (cbf_find_column(cbf,"id"))
            cbf_failnez (cbf_set_value(cbf,"MAP_CELL_Y")) 
            
            cbf_failnez (cbf_find_column(cbf,"system"))
            cbf_failnez (cbf_set_value(cbf,"fractional")) 
            
            cbf_failnez (cbf_find_column(cbf,"vector[1]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",fcmap_axismat[0][1])) 
            
            cbf_failnez (cbf_find_column(cbf,"vector[2]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",fcmap_axismat[1][1]))
            
            cbf_failnez (cbf_find_column(cbf,"vector[3]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",fcmap_axismat[2][1])) 
            
            cbf_failnez (cbf_find_column(cbf,"offset[1]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",fcmap_axisvec[0])) 
            
            cbf_failnez (cbf_find_column(cbf,"offset[2]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",fcmap_axisvec[1]))
            
            cbf_failnez (cbf_find_column(cbf,"offset[3]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",fcmap_axisvec[2])) 
            
            cbf_failnez (cbf_new_row(cbf))
            
            cbf_failnez (cbf_find_column(cbf,"id"))
            cbf_failnez (cbf_set_value(cbf,"MAP_CELL_Z")) 
            
            cbf_failnez (cbf_find_column(cbf,"system"))
            cbf_failnez (cbf_set_value(cbf,"fractional")) 
            
            cbf_failnez (cbf_find_column(cbf,"vector[1]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",fcmap_axismat[0][2])) 
            
            cbf_failnez (cbf_find_column(cbf,"vector[2]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",fcmap_axismat[1][2]))
            
            cbf_failnez (cbf_find_column(cbf,"vector[3]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",fcmap_axismat[2][2])) 
            
            cbf_failnez (cbf_find_column(cbf,"offset[1]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",fcmap_axisvec[0])) 
            
            cbf_failnez (cbf_find_column(cbf,"offset[2]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",fcmap_axisvec[1]))
            
            cbf_failnez (cbf_find_column(cbf,"offset[3]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",fcmap_axisvec[2])) 
             
        }

        if (mapmask && mapmask->maptype == MAP_ORTHOGONAL)  {
            
            cbf_failnez (cbf_new_row(cbf))
            
            cbf_failnez (cbf_require_column(cbf,"id"))
            cbf_failnez (cbf_set_value(cbf,"MASK_ORTHOGONAL_X")) 
            
            cbf_failnez (cbf_require_column(cbf,"system"))
            cbf_failnez (cbf_set_value(cbf,"orthogonal")) 
            
            cbf_failnez (cbf_find_column(cbf,"vector[1]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",ocmapmask_axismat[0][0])) 
            
            cbf_failnez (cbf_find_column(cbf,"vector[2]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",ocmapmask_axismat[1][0]))
            
            cbf_failnez (cbf_find_column(cbf,"vector[3]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",ocmapmask_axismat[2][0])) 
            
            cbf_failnez (cbf_find_column(cbf,"offset[1]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",ocmapmask_axisvec[0])) 
            
            cbf_failnez (cbf_find_column(cbf,"offset[2]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",ocmapmask_axisvec[1]))
            
            cbf_failnez (cbf_find_column(cbf,"offset[3]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",ocmapmask_axisvec[2])) 
            
            cbf_failnez (cbf_new_row(cbf))
            
            cbf_failnez (cbf_find_column(cbf,"id"))
            cbf_failnez (cbf_set_value(cbf,"MASK_ORTHOGONAL_Y")) 
            
            cbf_failnez (cbf_find_column(cbf,"system"))
            cbf_failnez (cbf_set_value(cbf,"orthogonal")) 
            
            cbf_failnez (cbf_find_column(cbf,"vector[1]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",ocmapmask_axismat[0][1])) 
            
            cbf_failnez (cbf_find_column(cbf,"vector[2]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",ocmapmask_axismat[1][1]))
            
            cbf_failnez (cbf_find_column(cbf,"vector[3]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",ocmapmask_axismat[2][1])) 
            
            cbf_failnez (cbf_find_column(cbf,"offset[1]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",ocmapmask_axisvec[0])) 
            
            cbf_failnez (cbf_find_column(cbf,"offset[2]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",ocmapmask_axisvec[1]))
            
            cbf_failnez (cbf_find_column(cbf,"offset[3]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",ocmapmask_axisvec[2])) 
            
            cbf_failnez (cbf_new_row(cbf))
            
            cbf_failnez (cbf_find_column(cbf,"id"))
            cbf_failnez (cbf_set_value(cbf,"MASK_ORTHOGONAL_Z")) 
            
            cbf_failnez (cbf_find_column(cbf,"system"))
            cbf_failnez (cbf_set_value(cbf,"orthogonal")) 
            
            cbf_failnez (cbf_find_column(cbf,"vector[1]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",ocmapmask_axismat[0][2])) 
            
            cbf_failnez (cbf_find_column(cbf,"vector[2]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",ocmapmask_axismat[1][2]))
            
            cbf_failnez (cbf_find_column(cbf,"vector[3]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",ocmapmask_axismat[2][2])) 
            
            cbf_failnez (cbf_find_column(cbf,"offset[1]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",ocmapmask_axisvec[0])) 
            
            cbf_failnez (cbf_find_column(cbf,"offset[2]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",ocmapmask_axisvec[1]))
            
            cbf_failnez (cbf_find_column(cbf,"offset[3]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",ocmapmask_axisvec[2])) 
             
        }
        
        if (mapmask && mapmask->maptype == MAP_FRACTIONAL)  {
            
            cbf_failnez (cbf_new_row(cbf))
            
            cbf_failnez (cbf_require_column(cbf,"id"))
            cbf_failnez (cbf_set_value(cbf,"MASK_CELL_X")) 
            
            cbf_failnez (cbf_require_column(cbf,"system"))
            cbf_failnez (cbf_set_value(cbf,"fractional")) 
            
            cbf_failnez (cbf_find_column(cbf,"vector[1]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",fcmapmask_axismat[0][0])) 
            
            cbf_failnez (cbf_find_column(cbf,"vector[2]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",fcmapmask_axismat[1][0]))
            
            cbf_failnez (cbf_find_column(cbf,"vector[3]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",fcmapmask_axismat[2][0])) 
            
            cbf_failnez (cbf_find_column(cbf,"offset[1]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",fcmapmask_axisvec[0])) 
            
            cbf_failnez (cbf_find_column(cbf,"offset[2]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",fcmapmask_axisvec[1]))
            
            cbf_failnez (cbf_find_column(cbf,"offset[3]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",fcmapmask_axisvec[2])) 
            
            cbf_failnez (cbf_new_row(cbf))
            
            cbf_failnez (cbf_find_column(cbf,"id"))
            cbf_failnez (cbf_set_value(cbf,"MASK_CELL_Y")) 
            
            cbf_failnez (cbf_find_column(cbf,"system"))
            cbf_failnez (cbf_set_value(cbf,"fractional")) 
            
            cbf_failnez (cbf_find_column(cbf,"vector[1]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",fcmapmask_axismat[0][1])) 
            
            cbf_failnez (cbf_find_column(cbf,"vector[2]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",fcmapmask_axismat[1][1]))
            
            cbf_failnez (cbf_find_column(cbf,"vector[3]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",fcmapmask_axismat[2][1])) 
            
            cbf_failnez (cbf_find_column(cbf,"offset[1]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",fcmapmask_axisvec[0])) 
            
            cbf_failnez (cbf_find_column(cbf,"offset[2]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",fcmapmask_axisvec[1]))
            
            cbf_failnez (cbf_find_column(cbf,"offset[3]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",fcmapmask_axisvec[2])) 
            
            cbf_failnez (cbf_new_row(cbf))
            
            cbf_failnez (cbf_find_column(cbf,"id"))
            cbf_failnez (cbf_set_value(cbf,"MASK_CELL_Z")) 
            
            cbf_failnez (cbf_find_column(cbf,"system"))
            cbf_failnez (cbf_set_value(cbf,"fractional")) 
            
            cbf_failnez (cbf_find_column(cbf,"vector[1]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",fcmapmask_axismat[0][2])) 
            
            cbf_failnez (cbf_find_column(cbf,"vector[2]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",fcmapmask_axismat[1][2]))
            
            cbf_failnez (cbf_find_column(cbf,"vector[3]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-f",fcmapmask_axismat[2][2])) 
            
            cbf_failnez (cbf_find_column(cbf,"offset[1]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",fcmapmask_axisvec[0])) 
            
            cbf_failnez (cbf_find_column(cbf,"offset[2]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",fcmapmask_axisvec[1]))
            
            cbf_failnez (cbf_find_column(cbf,"offset[3]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",fcmapmask_axisvec[2])) 
             
        }


        
        if ((map && map->maptype == MAP_FRACTIONAL) ||
            (mapmask && mapmask->maptype == MAP_FRACTIONAL)) {
            
            cbf_failnez (cbf_new_category(cbf,"cell"))
            
            cbf_failnez (cbf_new_column(cbf,"length_a"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",Info.cella))
            cbf_failnez (cbf_new_column(cbf,"length_b"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",Info.cellb))
            cbf_failnez (cbf_new_column(cbf,"length_c"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",Info.cellc))
            
            cbf_failnez (cbf_new_column(cbf,"angle_alpha"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",Info.cellalpha*180./PI))
            cbf_failnez (cbf_new_column(cbf,"angle_beta"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",Info.cellbeta*180./PI))
            cbf_failnez (cbf_new_column(cbf,"angle_gamma"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",Info.cellgamma*180./PI))
            
            
            cbf_failnez (cbf_new_category(cbf,"atom_sites"))
            
            cbf_failnez (cbf_new_column(cbf,"Cartn_transf_matrix[1][1]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",Info.matf2o[0][0]))
            cbf_failnez (cbf_new_column(cbf,"Cartn_transf_matrix[1][2]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",Info.matf2o[0][1]))
            cbf_failnez (cbf_new_column(cbf,"Cartn_transf_matrix[1][3]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",Info.matf2o[0][2]))
            cbf_failnez (cbf_new_column(cbf,"Cartn_transf_matrix[2][1]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",Info.matf2o[1][0]))
            cbf_failnez (cbf_new_column(cbf,"Cartn_transf_matrix[2][2]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",Info.matf2o[1][1]))
            cbf_failnez (cbf_new_column(cbf,"Cartn_transf_matrix[2][3]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",Info.matf2o[1][2]))
            cbf_failnez (cbf_new_column(cbf,"Cartn_transf_matrix[3][1]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",Info.matf2o[2][0]))
            cbf_failnez (cbf_new_column(cbf,"Cartn_transf_matrix[3][2]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",Info.matf2o[2][1]))
            cbf_failnez (cbf_new_column(cbf,"Cartn_transf_matrix[3][3]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",Info.matf2o[2][2]))

            cbf_failnez (cbf_new_column(cbf,"Cartn_transf_vector[1]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",Info.vecf2o[0]))
            cbf_failnez (cbf_new_column(cbf,"Cartn_transf_vector[2]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",Info.vecf2o[1]))
            cbf_failnez (cbf_new_column(cbf,"Cartn_transf_vector[3]"))
            cbf_failnez (cbf_set_doublevalue(cbf,"%-g",Info.vecf2o[2]))
            
        }
        
        
            
        
        
        cbf_failnez (cbf_new_category(cbf,"array_data"))
            
            if (map)  {
                
                cbf_failnez (cbf_new_column(cbf,"array_id"))
                cbf_failnez (cbf_set_value(cbf,map_structure_id))
                
                cbf_failnez (cbf_new_column(cbf,"binary_id"))
                cbf_failnez (cbf_set_integervalue(cbf,1))
                
                cbf_failnez (cbf_new_column(cbf,"data"))
                
                if (map->eltype == CBF_FLOAT) {
                
                    int compression;
                    compression = CBF_NONE;
                    
                    cbf_failnez(cbf_set_realarray_wdims (cbf,compression, 1, 
                                                         (void *)(map->mapdata), 
                                                         map->elsize,
                                                         ((map->xhigh)-(map->xlow)+1)
                                                         *((map->yhigh)-(map->ylow)+1)
                                                         *((map->zhigh)-(map->zlow)+1),
                                                         "little_endian", ((map->xhigh)-(map->xlow)+1), 
                                                         ((map->yhigh)-(map->ylow)+1), ((map->zhigh)-(map->zlow)+1), 0))
                    
                } else  {
                    
                    cbf_failnez(cbf_set_integerarray_wdims (cbf,CBF_PACKED_V2, 1, 
                                                            (void *)(map->mapdata), 
                                                            map->elsize, 1,
                                                            ((map->xhigh)-(map->xlow)+1)
                                                            *((map->yhigh)-(map->ylow)+1)
                                                            *((map->zhigh)-(map->zlow)+1),
                                                            "little_endian", ((map->xhigh)-(map->xlow)+1), 
                                                            ((map->yhigh)-(map->ylow)+1), ((map->zhigh)-(map->zlow)+1), 0))
                    
                }
                
            }
        
        if (mapmask)  {
            
            cbf_failnez (cbf_new_row(cbf))
            
            cbf_failnez (cbf_require_column(cbf,"array_id"))
            cbf_failnez (cbf_set_value(cbf,mask_structure_id))
            
            cbf_failnez (cbf_require_column(cbf,"binary_id"))
            cbf_failnez (cbf_set_integervalue(cbf,2))
            
            cbf_failnez (cbf_require_column(cbf,"data"))
            
            if (map->eltype == CBF_FLOAT) {
            
               int compression;
               compression = CBF_NONE;

                
               cbf_failnez(cbf_set_realarray_wdims (cbf,compression, 1, 
                                                     (void *)(mapmask->mapdata), 
                                                     mapmask->elsize,
                                                     ((mapmask->xhigh)-(mapmask->xlow)+1)
                                                     *((mapmask->yhigh)-(mapmask->ylow)+1)
                                                     *((mapmask->zhigh)-(mapmask->zlow)+1),
                                                     "little_endian", ((mapmask->xhigh)-(mapmask->xlow)+1), 
                                                     ((mapmask->yhigh)-(mapmask->ylow)+1), ((mapmask->zhigh)-(mapmask->zlow)+1), 0))
                
            } else  {
                
                cbf_failnez(cbf_set_integerarray_wdims (cbf,CBF_PACKED_V2, 1, 
                                                        (void *)(map->mapdata), 
                                                        map->elsize, 1,
                                                        ((mapmask->xhigh)-(mapmask->xlow)+1)
                                                        *((mapmask->yhigh)-(mapmask->ylow)+1)
                                                        *((mapmask->zhigh)-(mapmask->zlow)+1),
                                                        "little_endian", ((mapmask->xhigh)-(mapmask->xlow)+1), 
                                                        ((mapmask->yhigh)-(mapmask->ylow)+1), ((mapmask->zhigh)-(mapmask->zlow)+1), 0))
                
            }
            
        }
        
        
    }
    
    
    cbf_failnez (cbf_write_file (cbf, fp, 0, CBF,
                                 MSG_DIGEST | MIME_HEADERS, 0))
        
        /* Free the cbf */
        
        cbf_failnez (cbf_free_handle (cbf))
        
        return 0;
    
    
}


int LoadCBFMapFile( FILE *fp, int info, int mapno ) {

    cbf_handle cbf;

    MapInfo mapinfo;
    MapStruct * map;
    MapStruct * mask;
    char * map_structure_id;
    char * mask_structure_id;
    int map_bin_id, mask_bin_id;
    char * enc_type;

    void * mapdata;
    void * maskdata;
    
    Long   map_xbase,       map_ybase,       map_zbase;
    Long   mapmask_xbase,   mapmask_ybase,   mapmask_zbase;
    double ocmap_xbase,     ocmap_ybase,     ocmap_zbase;
    double ocmapmask_xbase, ocmapmask_ybase, ocmapmask_zbase;
    double fcmap_xbase,     fcmap_ybase,     fcmap_zbase;
    double fcmapmask_xbase, fcmapmask_ybase, fcmapmask_zbase;
    int    map_dimension[3],           mask_dimension[3];
    int    map_index[3],               mask_index[3];
    double map_displacement[3],        map_displacement_increment[3];
    double mask_displacement[3],       mask_displacement_increment[3];
    double map_fract_displacement[3],  map_fract_displacement_increment[3];
    double mask_fract_displacement[3], mask_fract_displacement_increment[3];
    double map_axis_vector[3][3],      map_axis_offset[3][3];
    double mask_axis_vector[3][3],     mask_axis_offset[3][3];
    double map_axis_length[3],         mask_axis_length[3];
    double cell_a, cell_b, cell_c, cell_alpha, cell_beta, cell_gamma;
    double matf2o[3][3], vecf2o[3];
    double tempmatin[3][3], tempmatout[3][3], tempvecin[3], tempvecout[3];
    
    char * map_axis_set_id[3];
    char * mask_axis_set_id[3];
    char * map_axis_system[3];
    char * map_system;
    char * mask_axis_system[3];
    char * mask_system;
    char * valtype;
    int    map_dir[3], mask_dir[3]; /* +1 for incr, -1 for decr */
    unsigned int  row, rows;

    
    int ii, jj;
    int cell_found;
    
    if (!MapInfoPtr) InitialiseMaps();
    if (MapSpacing <= 0) MapSpacing = 250L;
    
    cbf_failnez (cbf_make_handle (&cbf))
    cbf_failnez (cbf_read_widefile(cbf, fp, MSG_DIGEST))
    cbf_failnez (cbf_rewind_datablock(cbf))
    
    /* we have the first datablock, loop through until there are no more */
    
    do {
      map_xbase       = map_ybase       = map_zbase       = 0;
      mapmask_xbase   = mapmask_ybase   = mapmask_zbase   = 0;
      cell_found = 0;
      ocmap_xbase     = ocmap_ybase     = ocmap_zbase     = 0.;
      ocmapmask_xbase = ocmapmask_ybase = ocmapmask_zbase = 0.;
      fcmap_xbase     = fcmap_ybase     = fcmap_zbase     = 0.;
      fcmapmask_xbase = fcmapmask_ybase = fcmapmask_zbase = 0.;
      cell_a = cell_b = cell_c = cell_alpha = cell_beta = cell_gamma = 0.;
      for (ii=0; ii<3; ii++) { 
        map_dimension[ii]           = mask_dimension[ii]                    = 0;
        map_index[ii]               = mask_index[ii]                        = 0;
        map_axis_set_id[ii]         = mask_axis_set_id[ii]                  = NULL;
        map_axis_system[ii]         = mask_axis_system[ii]                  = NULL;
        map_dir[ii]                 = mask_dir[ii]                          = 0;
        map_displacement[ii]        = map_displacement_increment[ii]        = 0.;
        mask_displacement[ii]       = mask_displacement_increment[ii]       = 0.;
        map_fract_displacement[ii]  = map_fract_displacement_increment[ii]  = 0.;
        mask_fract_displacement[ii] = mask_fract_displacement_increment[ii] = 0.;
        matf2o[ii][0] = matf2o[ii][1] = matf2o[ii][2] = vecf2o[ii] = 0.;
        map_axis_vector[ii][0]  =  map_axis_vector[ii][1]  =  map_axis_vector[ii][2]   = 0;
        map_axis_offset[ii][0]  =  map_axis_offset[ii][1]  =  map_axis_offset[ii][2]   = 0;
        mask_axis_vector[ii][0] =  mask_axis_vector[ii][1] =  mask_axis_vector[ii][2]  = 0;
        mask_axis_offset[ii][0] =  mask_axis_offset[ii][1] =  mask_axis_offset[ii][2]  = 0;
        map_axis_length[ii]     =  mask_axis_length[ii]    =  1.;
      }
      matf2o[0][0] = matf2o[1][1] = matf2o[2][2] = 1.;
      
      map  = NULL;
      mask = NULL;
      map_system = NULL;
      mask_system = NULL;

      map_structure_id = mask_structure_id = NULL;
      map_bin_id = mask_bin_id = -1;
    
      /* only recognize datablocks with map and map_segment categories */
      if (cbf_find_category(cbf,"map")) continue;
      if (cbf_find_column(cbf,"id")) continue;
      if (cbf_find_category(cbf,"map_segment")) continue;
      
      if (!cbf_find_column(cbf,"array_id")) 
        if (cbf_get_value(cbf,(const char **)&map_structure_id)
        || (!cbf_get_typeofvalue(cbf,(const char **)&valtype) 
           && !cbf_cistrcmp(valtype,"null"))) map_structure_id = NULL;
      if (!cbf_find_column(cbf,"mask_array_id")) 
        if (cbf_get_value(cbf,(const char **)&mask_structure_id)
        || (!cbf_get_typeofvalue(cbf,(const char **)&valtype) 
           && !cbf_cistrcmp(valtype,"null"))
        || MapMaskPtr) mask_structure_id = NULL;
      if (!cbf_find_column(cbf,"binary_id")) 
        cbf_get_integervalue(cbf,&map_bin_id);
      if (!cbf_find_column(cbf,"mask_binary_id")) 
        cbf_get_integervalue(cbf,&mask_bin_id);
      
      if (map_structure_id && map_structure_id[0]) {
          map = _fmalloc(sizeof(MapStruct));
          if (!map) RasMolFatalExit(MsgStrs[StrMalloc]);
      }
 
      if (mask_structure_id && mask_structure_id[0]) {
          mask = _fmalloc(sizeof(MapStruct));
          if (!mask) RasMolFatalExit(MsgStrs[StrMalloc]);
      }
     
      if (cbf_find_category(cbf,"array_structure")) continue;
      cbf_failnez(cbf_rewind_row(cbf))
      if (map 
        && !cbf_find_column(cbf,"id")
        && !cbf_find_row(cbf,map_structure_id))  {
        if (!cbf_find_column(cbf,"encoding_type") 
          && !cbf_get_value(cbf,(const char **)&enc_type)
          && enc_type ) {
          if (!cbf_cistrcmp(enc_type,"signed 8-bit integer")) {
            map->elsize = 1;
            map->eltype = CBF_INTEGER;
          } else if (!cbf_cistrcmp(enc_type,"signed 16-bit integer")) {
            map->elsize = 2;
            map->eltype = CBF_INTEGER;
          } else if (!cbf_cistrcmp(enc_type,"signed 32-bit integer")) {
            map->elsize = 4;
            map->eltype = CBF_INTEGER;
          } else if (!cbf_cistrcmp(enc_type,"signed 64-bit integer")) {
            map->elsize = 8;
            map->eltype = CBF_INTEGER;
          } else if (!cbf_cistrcmp(enc_type,"signed 32-bit real IEEE")) {
            map->elsize = 4;
            map->eltype = CBF_FLOAT;
          } else if (!cbf_cistrcmp(enc_type,"signed 64-bit real IEEE")) {
            map->elsize = 8;
            map->eltype = CBF_FLOAT;
          } else return CBF_FORMAT;
        }
      }
      cbf_failnez(cbf_rewind_row(cbf))
      if (mask 
        && !cbf_find_column(cbf,"id")
        && !cbf_find_row(cbf,mask_structure_id))  {
        if (!cbf_find_column(cbf,"encoding_type") 
          && !cbf_get_value(cbf,(const char **)&enc_type)
          && enc_type ) {
          if (!cbf_cistrcmp(enc_type,"signed 8-bit integer")) {
            mask->elsize = 1;
            mask->eltype = CBF_INTEGER;
          } else if (!cbf_cistrcmp(enc_type,"signed 16-bit integer")) {
            mask->elsize = 2;
            mask->eltype = CBF_INTEGER;
          } else if (!cbf_cistrcmp(enc_type,"signed 32-bit integer")) {
            mask->elsize = 4;
            mask->eltype = CBF_INTEGER;
          } else if (!cbf_cistrcmp(enc_type,"signed 64-bit integer")) {
            mask->elsize = 8;
            mask->eltype = CBF_INTEGER;
          } else if (!cbf_cistrcmp(enc_type,"signed 32-bit real IEEE")) {
            mask->elsize = 4;
            mask->eltype = CBF_FLOAT;
          } else if (!cbf_cistrcmp(enc_type,"signed 64-bit real IEEE")) {
            mask->elsize = 8;
            mask->eltype = CBF_FLOAT;
          } else return CBF_FORMAT;
        }
      }
      
      cbf_onfailnez(cbf_find_category(cbf,"array_structure_list"),
        {if (map) _ffree(map); if (mask) _ffree(mask);})
      cbf_onfailnez(cbf_rewind_row(cbf),
        {if (map) _ffree(map); if (mask) _ffree(mask);})
      cbf_onfailnez(cbf_count_rows(cbf, &rows),
        {if (map) _ffree(map); if (mask) _ffree(mask);})
      
      for (row=0; row < rows; row++) {
        char * tempval;
        int precedence;
      

        cbf_onfailnez(cbf_find_column(cbf,"array_id"),
        {if (map) _ffree(map); if (mask) _ffree(mask);})
        cbf_onfailnez(cbf_select_row(cbf, row),
        {if (map) _ffree(map); if (mask) _ffree(mask);})
        cbf_onfailnez(cbf_get_value(cbf,(const char**)&tempval),
        {if (map) _ffree(map); if (mask) _ffree(mask);})
        if (map && !cbf_cistrcmp(tempval,map_structure_id)) {
          if (!cbf_find_column(cbf,"precedence") 
            && !cbf_get_integervalue(cbf,&precedence)) {
            if (precedence < 1 || precedence > 3) { if (map) _ffree(map); 
              if (mask) _ffree(mask); return CBF_FORMAT;
            }
            if (cbf_find_column(cbf,"index") 
              || cbf_get_integervalue(cbf,&(map_index[precedence-1]))) {
              if (map) _ffree(map); 
              if (mask) _ffree(mask); return CBF_FORMAT;
            }
            if (cbf_find_column(cbf,"dimension") 
              || cbf_get_integervalue(cbf,&(map_dimension[precedence-1]))) {
              if (map) _ffree(map); 
              if (mask) _ffree(mask); return CBF_FORMAT;
            }
            if (cbf_find_column(cbf,"direction") 
              || cbf_get_value(cbf,(const char **)&tempval)) {
              if (map) _ffree(map); 
              if (mask) _ffree(mask); return CBF_FORMAT;
            }
            map_dir[precedence-1] = 0;
            if (!cbf_cistrcmp("increasing",tempval)) map_dir[precedence-1] = 1;
            if (!cbf_cistrcmp("decreasing",tempval)) map_dir[precedence-1] = -1;

              if (cbf_find_column(cbf,"axis_set_id") 
              || cbf_get_value(cbf,(const char **)&map_axis_set_id[precedence-1])
              || !map_axis_set_id[precedence-1] 
              || !map_axis_set_id[precedence-1][0]) {
              if (map) _ffree(map); 
              if (mask) _ffree(mask); return CBF_FORMAT;
            }

          }
            
        }
        if (mask && !cbf_cistrcmp(tempval,mask_structure_id)) {
          if (!cbf_find_column(cbf,"precedence") 
            && !cbf_get_integervalue(cbf,&precedence)) {
            if (precedence < 1 || precedence > 3) { if (map) _ffree(map); 
              if (mask) _ffree(mask); return CBF_FORMAT;
            }
            if (cbf_find_column(cbf,"index") 
              || cbf_get_integervalue(cbf,&(mask_index[precedence-1]))) {
              if (map) _ffree(map); 
              if (mask) _ffree(mask); return CBF_FORMAT;
            }
            if (cbf_find_column(cbf,"dimension") 
              || cbf_get_integervalue(cbf,&(mask_dimension[precedence-1]))) {
              if (map) _ffree(map); 
              if (mask) _ffree(mask); return CBF_FORMAT;
            }
            if (cbf_find_column(cbf,"direction") 
              || cbf_get_value(cbf,(const char **)&tempval)) {
              if (map) _ffree(map); 
              if (mask) _ffree(mask); return CBF_FORMAT;
            }
            mask_dir[precedence-1] = 0;
            if (!cbf_cistrcmp("increasing",tempval)) mask_dir[precedence-1] = 1;
            if (!cbf_cistrcmp("decreasing",tempval)) mask_dir[precedence-1] = -1;
              if (cbf_find_column(cbf,"axis_set_id") 
              || cbf_get_value(cbf,(const char **)&map_axis_set_id[precedence-1])
              || !mask_axis_set_id[precedence-1] 
              || !mask_axis_set_id[precedence-1][0]) {
              if (map) _ffree(map); 
              if (mask) _ffree(mask); return CBF_FORMAT;
            }
              
          }
            
        }
        
          
      }
      
      cbf_onfailnez(cbf_find_category(cbf,"array_structure_list_axis"),
        {if (map) _ffree(map); if (mask) _ffree(mask);})
      cbf_onfailnez(cbf_rewind_row(cbf),
        {if (map) _ffree(map); if (mask) _ffree(mask);})
      cbf_onfailnez(cbf_count_rows(cbf, &rows),
        {if (map) _ffree(map); if (mask) _ffree(mask);})
      
      for (row=0; row < rows; row++) {
        char * tempval;
        int precedence;

        if (cbf_find_column(cbf,"axis_id")) {
          if (map) _ffree(map); if (mask) _ffree(mask); return CBF_FORMAT;
        }
        cbf_onfailnez(cbf_select_row(cbf, row),
        {if (map) _ffree(map); if (mask) _ffree(mask);})
        
        if (!cbf_get_value(cbf,(const char**)&tempval) && tempval && tempval[0]) {
          if (map) for (precedence=1; precedence<4; precedence++) {
            if (map_axis_set_id[precedence-1]
              &&!cbf_cistrcmp(tempval,map_axis_set_id[precedence-1])) {
              if (!cbf_find_column(cbf,"displacement") ) {
                cbf_onfailnez(cbf_get_doublevalue(cbf,&map_displacement[precedence-1]),
                  {if (map) _ffree(map); if (mask) _ffree(mask);})
              }
              if (!cbf_find_column(cbf,"displacement_increment") ) {
                cbf_onfailnez(cbf_get_doublevalue(cbf,&map_displacement_increment[precedence-1]),
                  {if (map) _ffree(map); if (mask) _ffree(mask);})
              }
              if (!cbf_find_column(cbf,"fract_displacement") ) {
                cbf_onfailnez(cbf_get_doublevalue(cbf,&map_fract_displacement[precedence-1]),
                  {if (map) _ffree(map); if (mask) _ffree(mask);})
              }
              if (!cbf_find_column(cbf,"fract_displacement_increment") ) {
                cbf_onfailnez(cbf_get_doublevalue(cbf,&map_fract_displacement_increment[precedence-1]),
                  {if (map) _ffree(map); if (mask) _ffree(mask);})
              }
              break;    
            }
              
          }
          if (mask) for (precedence=1; precedence<4; precedence++) {
            if (mask_axis_set_id[precedence-1]
              &&!cbf_cistrcmp(tempval,mask_axis_set_id[precedence-1])) {
              if (!cbf_find_column(cbf,"displacement") ) {
                cbf_onfailnez(cbf_get_doublevalue(cbf,&mask_displacement[precedence-1]),
                  {if (map) _ffree(map); if (mask) _ffree(mask);})
              }
              if (!cbf_find_column(cbf,"displacement_increment") ) {
                cbf_onfailnez(cbf_get_doublevalue(cbf,&mask_displacement_increment[precedence-1]),
                  {if (map) _ffree(map); if (mask) _ffree(mask);})
              }
              if (!cbf_find_column(cbf,"fract_displacement") ) {
                cbf_onfailnez(cbf_get_doublevalue(cbf,&mask_fract_displacement[precedence-1]),
                  {if (map) _ffree(map); if (mask) _ffree(mask);})
              }
              if (!cbf_find_column(cbf,"fract_displacement_increment") ) {
                cbf_onfailnez(cbf_get_doublevalue(cbf,&mask_fract_displacement_increment[precedence-1]),
                  {if (map) _ffree(map); if (mask) _ffree(mask);})
              }
              break;    
            }
              
          }
            
        }
          
      }
      
      cbf_onfailnez(cbf_find_category(cbf,"axis"),
        {if (map) _ffree(map); if (mask) _ffree(mask);})
      cbf_onfailnez(cbf_rewind_row(cbf),
        {if (map) _ffree(map); if (mask) _ffree(mask);})
      cbf_onfailnez(cbf_count_rows(cbf, &rows),
        {if (map) _ffree(map); if (mask) _ffree(mask);})
      
      for (row=0; row < rows; row++) {
        char * tempval;
        int precedence;

        
        if (cbf_find_column(cbf,"id")) {
          if (map) _ffree(map); if (mask) _ffree(mask); return CBF_FORMAT;
        }
        cbf_onfailnez(cbf_select_row(cbf, row),
        {if (map) _ffree(map); if (mask) _ffree(mask);})

        if (!cbf_get_value(cbf,(const char**)&tempval) && tempval && tempval[0]) {
          if (map) for (precedence=1; precedence<4; precedence++) {
            if (map_axis_set_id[precedence-1]
              &&!cbf_cistrcmp(tempval,map_axis_set_id[precedence-1])) {
              map_axis_system[precedence-1] = NULL;
              if (!cbf_find_column(cbf,"system") ) {
                cbf_onfailnez(cbf_get_value(cbf,(const char **)&map_axis_system[precedence-1]),
                  {if (map) _ffree(map); if (mask) _ffree(mask);})
                if (!map_system) map_system = map_axis_system[precedence-1];
                else {
                  if (cbf_cistrcmp(map_system,map_axis_system[precedence-1]))
                    {if (map) _ffree(map); if (mask) _ffree(mask); return CBF_FORMAT;}
                }
              }
              if (!cbf_find_column(cbf,"vector[1]") ) {
                cbf_onfailnez(cbf_get_doublevalue(cbf,&map_axis_vector[precedence-1][0]),
                  {if (map) _ffree(map); if (mask) _ffree(mask);})
              }
              if (!cbf_find_column(cbf,"vector[2]") ) {
                cbf_onfailnez(cbf_get_doublevalue(cbf,&map_axis_vector[precedence-1][1]),
                  {if (map) _ffree(map); if (mask) _ffree(mask);})
              }
              if (!cbf_find_column(cbf,"vector[3]") ) {
                cbf_onfailnez(cbf_get_doublevalue(cbf,&map_axis_vector[precedence-1][2]),
                  {if (map) _ffree(map); if (mask) _ffree(mask);})
              }
              if (!cbf_find_column(cbf,"offset[1]") ) {
                cbf_onfailnez(cbf_get_doublevalue(cbf,&map_axis_offset[precedence-1][0]),
                  {if (map) _ffree(map); if (mask) _ffree(mask);})
              }
              if (!cbf_find_column(cbf,"offset[2]") ) {
                cbf_onfailnez(cbf_get_doublevalue(cbf,&map_axis_offset[precedence-1][1]),
                  {if (map) _ffree(map); if (mask) _ffree(mask);})
              }
              if (!cbf_find_column(cbf,"offset[3]") ) {
                cbf_onfailnez(cbf_get_doublevalue(cbf,&map_axis_offset[precedence-1][2]),
                  {if (map) _ffree(map); if (mask) _ffree(mask);})
              }
              break;
            }
          }
          if (mask) for (precedence=1; precedence<4; precedence++) {
            if (mask_axis_set_id[precedence-1]
              &&!cbf_cistrcmp(tempval,mask_axis_set_id[precedence-1])) {
              mask_axis_system[precedence-1] = NULL;
              if (!cbf_find_column(cbf,"system") ) {
                cbf_onfailnez(cbf_get_value(cbf,(const char **)&mask_axis_system[precedence-1]),
                  {if (map) _ffree(map); if (mask) _ffree(mask);})
                if (!mask_system) mask_system = mask_axis_system[precedence-1];
                else {
                  if (cbf_cistrcmp(mask_system,mask_axis_system[precedence-1]))
                    {if (map) _ffree(map); if (mask) _ffree(mask); return CBF_FORMAT;}
                }

              }
              if (!cbf_find_column(cbf,"vector[1]") ) {
                cbf_onfailnez(cbf_get_doublevalue(cbf,&mask_axis_vector[precedence-1][0]),
                  {if (map) _ffree(map); if (mask) _ffree(mask);})
              }
              if (!cbf_find_column(cbf,"vector[2]") ) {
                cbf_onfailnez(cbf_get_doublevalue(cbf,&mask_axis_vector[precedence-1][1]),
                  {if (map) _ffree(map); if (mask) _ffree(mask);})
              }
              if (!cbf_find_column(cbf,"vector[3]") ) {
                cbf_onfailnez(cbf_get_doublevalue(cbf,&mask_axis_vector[precedence-1][2]),
                  {if (map) _ffree(map); if (mask) _ffree(mask);})
              }
              if (!cbf_find_column(cbf,"offset[1]") ) {
                cbf_onfailnez(cbf_get_doublevalue(cbf,&mask_axis_offset[precedence-1][0]),
                  {if (map) _ffree(map); if (mask) _ffree(mask);})
              }
              if (!cbf_find_column(cbf,"offset[2]") ) {
                cbf_onfailnez(cbf_get_doublevalue(cbf,&mask_axis_offset[precedence-1][1]),
                  {if (map) _ffree(map); if (mask) _ffree(mask);})
              }
              if (!cbf_find_column(cbf,"offset[3]") ) {
                cbf_onfailnez(cbf_get_doublevalue(cbf,&mask_axis_offset[precedence-1][2]),
                  {if (map) _ffree(map); if (mask) _ffree(mask);})
              }
              break;
            }
          }
        }
      }

      if (map) {
        if (!map_system) {if (map) _ffree(map); if (mask) _ffree(mask); return CBF_FORMAT;}
        if (!cbf_cistrcmp(map_system,"fractional")) {
          map->maptype = MAP_FRACTIONAL;
          if (map_fract_displacement_increment[0] != 0.) 
            map->adiv = rint(1./fabs(map_fract_displacement_increment[0]));
          if (map_fract_displacement_increment[1] != 0.) 
            map->bdiv = rint(1./fabs(map_fract_displacement_increment[1]));
          if (map_fract_displacement_increment[2] != 0.) 
            map->cdiv = rint(1./fabs(map_fract_displacement_increment[2]));
        } else if (!cbf_cistrcmp(map_system,"orthogonal")) {
          map->adiv = map->bdiv = map->cdiv = 1;
          map->maptype = MAP_ORTHOGONAL;            
        }       
      }
      
      if (mask) {
        if (!mask_system) {if (map) _ffree(map); if (mask) _ffree(mask); return CBF_FORMAT;}
        if (!cbf_cistrcmp(mask_system,"fractional")) {
          mask->maptype = MAP_FRACTIONAL;
          if (map_fract_displacement_increment[0] != 0.) 
            mask->adiv = rint(1./fabs(map_fract_displacement_increment[0]));
          if (map_fract_displacement_increment[1] != 0.) 
            mask->bdiv = rint(1./fabs(map_fract_displacement_increment[1]));
          if (map_fract_displacement_increment[2] != 0.) 
            mask->cdiv = rint(1./fabs(map_fract_displacement_increment[2]));
        } else if (!cbf_cistrcmp(mask_system,"orthogonal"))
        {
          mask->adiv = mask->bdiv = mask->cdiv = 1;
          mask->maptype = MAP_ORTHOGONAL;            
        }          
      }
      
      
      
      if (!cbf_find_category(cbf,"cell")) {
        cell_found = 1;
        cbf_onfailnez(cbf_find_column(cbf,"length_a"),
          {if (map) _ffree(map); if (mask) _ffree(mask);})
        cbf_onfailnez(cbf_get_doublevalue(cbf,&cell_a),
          {if (map) _ffree(map); if (mask) _ffree(mask);})
        cbf_onfailnez(cbf_find_column(cbf,"length_b"),
          {if (map) _ffree(map); if (mask) _ffree(mask);})
        cbf_onfailnez(cbf_get_doublevalue(cbf,&cell_b),
          {if (map) _ffree(map); if (mask) _ffree(mask);})
        cbf_onfailnez(cbf_find_column(cbf,"length_c"),
          {if (map) _ffree(map); if (mask) _ffree(mask);})
        cbf_onfailnez(cbf_get_doublevalue(cbf,&cell_c),
          {if (map) _ffree(map); if (mask) _ffree(mask);})
        cbf_onfailnez(cbf_find_column(cbf,"angle_alpha"),
          {if (map) _ffree(map); if (mask) _ffree(mask);})
        cbf_onfailnez(cbf_get_doublevalue(cbf,&cell_alpha),
          {if (map) _ffree(map); if (mask) _ffree(mask);})
        cbf_onfailnez(cbf_find_column(cbf,"angle_beta"),
          {if (map) _ffree(map); if (mask) _ffree(mask);})
        cbf_onfailnez(cbf_get_doublevalue(cbf,&cell_beta),
          {if (map) _ffree(map); if (mask) _ffree(mask);})
        cbf_onfailnez(cbf_find_column(cbf,"angle_gamma"),
          {if (map) _ffree(map); if (mask) _ffree(mask);})
        cbf_onfailnez(cbf_get_doublevalue(cbf,&cell_gamma),
          {if (map) _ffree(map); if (mask) _ffree(mask);})
      }
           
      if (!cbf_find_category(cbf,"atom_sites")) {
        if (!cbf_find_column(cbf,"Cartn_transf_matrix[1][1]")) {
          cbf_get_doublevalue(cbf,&matf2o[0][0]);
        }
        if (!cbf_find_column(cbf,"Cartn_transf_matrix[1][2]")) {
          cbf_get_doublevalue(cbf,&matf2o[0][1]);
        }
        if (!cbf_find_column(cbf,"Cartn_transf_matrix[1][3]")) {
          cbf_get_doublevalue(cbf,&matf2o[0][2]);
        }
        if (!cbf_find_column(cbf,"Cartn_transf_matrix[2][1]")) {
          cbf_get_doublevalue(cbf,&matf2o[0][0]);
        }
        if (!cbf_find_column(cbf,"Cartn_transf_matrix[2][2]")) {
          cbf_get_doublevalue(cbf,&matf2o[1][1]);
        }
        if (!cbf_find_column(cbf,"Cartn_transf_matrix[2][3]")) {
          cbf_get_doublevalue(cbf,&matf2o[1][2]);
        }
        if (!cbf_find_column(cbf,"Cartn_transf_matrix[3][1]")) {
          cbf_get_doublevalue(cbf,&matf2o[2][0]);
        }
        if (!cbf_find_column(cbf,"Cartn_transf_matrix[3][2]")) {
          cbf_get_doublevalue(cbf,&matf2o[2][1]);
        }
        if (!cbf_find_column(cbf,"Cartn_transf_matrix[3][3]")) {
          cbf_get_doublevalue(cbf,&matf2o[2][2]);
        }
        if (!cbf_find_column(cbf,"Cartn_transf_vector[1]")) {
          cbf_get_doublevalue(cbf,&vecf2o[0]);
        }
        if (!cbf_find_column(cbf,"Cartn_transf_vector[2]")) {
          cbf_get_doublevalue(cbf,&vecf2o[1]);
        }
        if (!cbf_find_column(cbf,"Cartn_transf_vector[3]")) {
          cbf_get_doublevalue(cbf,&vecf2o[2]);
        }
      } else if (cell_found) {
      
        static double pi = PI;
        double d1, d2, d3, d4;
        double torad;
        
        torad = pi / 180.;
        
        d1 = cos(torad*cell_alpha);
        d2 = cos(torad*cell_beta);
        d3 = cos(torad*cell_gamma);
        if ( fabs (d4 = sin(torad * cell_gamma)) <  1.e-6)
          {if (map) _ffree(map); if (mask) _ffree(mask); return CBF_FORMAT;}
        matf2o[0][0] = cell_a;
        matf2o[0][1] = cell_b*d3;
        matf2o[1][1] = cell_b*d4;
        matf2o[0][2] = cell_c*d2;
        matf2o[1][2] = cell_c*((d1 - d2*d3)/d4);
        d1 = cell_c;
        d2 = matf2o[0][2];
        d3 = matf2o[1][2];
        matf2o[2][2] = sqrt(fabs(d1*d1 - d2*d2 - d3*d3));
        if ( fabs(det(matf2o)) < 
          (fabs(cell_a*cell_b*cell_c) + 1.)*1.e-9 )
          {if (map) _ffree(map); if (mask) _ffree(mask); return CBF_FORMAT;}         
      } else {
          for (ii=0; ii < 3; ii++) {
            vecf2o[ii] = Info.vecf2o[ii];
            for (jj=0; jj < 3; jj++)
              matf2o[ii][jj] = Info.matf2o[ii][jj];
          }
      }
      
      /* Now we have the coordinate system for the map and the mask organized
         byt axis precedence.  Before we use them we apply, we flip any
         axes that are presented as decreasing, and then we flip any axes
         for which the increment is negative */
         
      if (map) {
        for (ii=0; ii<3; ii++) {
          if (map_dir[ii] < 0) {
            map_displacement[ii] += (map_dimension[ii]-1)*map_displacement_increment[ii];
            map_fract_displacement[ii] += (map_dimension[ii]-1)*map_fract_displacement_increment[ii];
            map_dir[ii] = -map_dir[ii];
            map_displacement_increment[ii] = -map_displacement_increment[ii];
            map_fract_displacement_increment[ii] = -map_fract_displacement_increment[ii];
          }
          if (map_displacement_increment[ii] < 0.||map_fract_displacement_increment[ii] < 0.) {
            for (jj=0; jj<3; ii++) {
              map_axis_vector[ii][jj] = -map_axis_vector[ii][jj];
            }
              map_displacement_increment[ii] = -map_displacement_increment[ii];
              map_fract_displacement_increment[ii] = -map_fract_displacement_increment[ii];
          }
        }
      }
      if (mask) {
        for (ii=0; ii<3; ii++) {
          if (mask_dir[ii] < 0) {
            mask_displacement[ii] += (mask_dimension[ii]-1)*mask_displacement_increment[ii];
            mask_fract_displacement[ii] += (mask_dimension[ii]-1)*mask_fract_displacement_increment[ii];
            mask_dir[ii] = -mask_dir[ii];
            mask_displacement_increment[ii] = -mask_displacement_increment[ii];
            mask_fract_displacement_increment[ii] = -mask_fract_displacement_increment[ii];
          }
          if (mask_displacement_increment[ii] < 0.||mask_fract_displacement_increment[ii] < 0.) {
            for (jj=0; jj<3; ii++) {
              mask_axis_vector[ii][jj] = -mask_axis_vector[ii][jj];
            }
              mask_displacement_increment[ii] = -mask_displacement_increment[ii];
              mask_fract_displacement_increment[ii] = -mask_fract_displacement_increment[ii];
          }
        }
      }
      
      
      /* Get the intervals along each axis *
          For orthogonal coordinates it is just the displacement along the axis
          For fractional coordinates we have to scale by the axis length
          */
      
      if (map) {
        if (map->maptype == MAP_ORTHOGONAL) {
          map->xint = (long)rint(fabs(.25e10*map_displacement_increment[0]));
          map->yint = (long)rint(fabs(.25e10*map_displacement_increment[1]));
          map->zint = (long)rint(fabs(.25e10*map_displacement_increment[2]));
          map->xlow = (long)rint(map_displacement[0]/map_displacement_increment[0]);
          map->ylow = (long)rint(map_displacement[1]/map_displacement_increment[1]);
          map->zlow = (long)rint(map_displacement[2]/map_displacement_increment[2]);
        } else {
          double tempvec[3];
          for (ii=0; ii< 3; ii++) {
            for (jj=0; jj<3; jj++) {
              tempvec[jj]=matf2o[jj][0]*map_axis_vector[ii][0]
                + matf2o[jj][1]*map_axis_vector[ii][1]
                + matf2o[jj][2]*map_axis_vector[ii][2];
            }
            map_axis_length[ii]=sqrt(tempvec[0]*tempvec[0]+tempvec[1]*tempvec[1]+tempvec[2]*tempvec[2]);
          }
          map->xint = (long)rint(fabs(250.*map_axis_length[0]*map_fract_displacement_increment[0]));
          map->yint = (long)rint(fabs(250.*map_axis_length[1]*map_fract_displacement_increment[1]));
          map->zint = (long)rint(fabs(250.*map_axis_length[2]*map_fract_displacement_increment[2]));
          map->xlow = (long)rint(map_fract_displacement[0]/map_fract_displacement_increment[0]);
          map->ylow = (long)rint(map_fract_displacement[1]/map_fract_displacement_increment[1]);
          map->zlow = (long)rint(map_fract_displacement[2]/map_fract_displacement_increment[2]);
        }
        map->xhigh = map->xlow + map_dimension[0]-1;
        map->yhigh = map->ylow + map_dimension[1]-1;
        map->zhigh = map->zlow + map_dimension[2]-1;
      }
      if (mask) {
        if (mask->maptype == MAP_ORTHOGONAL) {
          mask->xint = (long)rint(fabs(.25e10*mask_displacement_increment[0]));
          mask->yint = (long)rint(fabs(.25e10*mask_displacement_increment[1]));
          mask->zint = (long)rint(fabs(.25e10*mask_displacement_increment[2]));
          mask->xlow = (long)rint(mask_displacement[0]/mask_displacement_increment[0]);
          mask->ylow = (long)rint(mask_displacement[1]/mask_displacement_increment[1]);
          mask->zlow = (long)rint(mask_displacement[2]/mask_displacement_increment[2]);
        } else {
          double tempvec[3];
          for (ii=0; ii< 3; ii++) {
            for (jj=0; jj<3; jj++) {
              tempvec[jj]=matf2o[jj][0]*mask_axis_vector[ii][0]
                + matf2o[jj][1]*mask_axis_vector[ii][1]
                + matf2o[jj][2]*mask_axis_vector[ii][2];
            }
            mask_axis_length[ii]=sqrt(tempvec[0]*tempvec[0]+tempvec[1]*tempvec[1]+tempvec[2]*tempvec[2]);
          }
          mask->xint = (long)rint(fabs(250.*mask_axis_length[0]*mask_fract_displacement_increment[0]));
          mask->yint = (long)rint(fabs(250.*mask_axis_length[1]*mask_fract_displacement_increment[1]));
          mask->zint = (long)rint(fabs(250.*mask_axis_length[2]*mask_fract_displacement_increment[2]));
          mask->xlow = (long)rint(mask_fract_displacement[0]/mask_fract_displacement_increment[0]);
          mask->ylow = (long)rint(mask_fract_displacement[1]/mask_fract_displacement_increment[1]);
          mask->zlow = (long)rint(mask_fract_displacement[2]/mask_fract_displacement_increment[2]);
        }
        mask->xhigh = mask->xlow + mask_dimension[0]-1;
        mask->yhigh = mask->ylow + mask_dimension[1]-1;
        mask->zhigh = mask->zlow + mask_dimension[2]-1;
      }
      
      /* Convert the map grid vectors to orthogonal vectors to make a transform matrix
      
         For orthogonal coordinates, the matrix columns are just the axes.
         
         For fractional coordinates, the matrix columns are the transformed axes.
         
         In both cases, we need to do a post-transform for the negation of Z
         and the possible negation of Y.
         
      
      
       */
      

      if (map) {
        if (map->maptype == MAP_ORTHOGONAL) {
          for (ii=0; ii < 3; ii++)  {
            map->mapxlate[ii] = 0.;
              for (jj=0; jj < 3; jj++) {
                MapM2R(map,ii,jj) = map_axis_vector[jj][ii];
                map->mapxlate[jj] += map_axis_offset[ii][jj];
              }
          }
            
        } else  if (map->maptype == MAP_FRACTIONAL) {
          for (ii=0; ii < 3; ii++)  {
            map->mapxlate[ii] = 0.;
              for (jj=0; jj < 3; jj++) {
                MapM2R(map,ii,jj) = (matf2o[jj][0]*map_axis_vector[ii][0]
                                  + matf2o[jj][1]*map_axis_vector[ii][1]
                                  + matf2o[jj][2]*map_axis_vector[ii][2])/
                                  map_axis_length[ii];
                                 
                map->mapxlate[jj] += matf2o[jj][0]*map_axis_offset[ii][0]
                                  + matf2o[jj][1]*map_axis_offset[ii][1]
                                  + matf2o[jj][2]*map_axis_offset[ii][2];
              }
          }
          
            
        } else {if (map) _ffree(map); if (mask) _ffree(mask); return CBF_FORMAT;}
          map->mapxlate[0] = 250.*(map->mapxlate[0])-OrigCX;
#ifdef INVERT
        map->mapxlate[1] = -(250.*map->mapxlate[1])-OrigCY;
#else
        map->mapxlate[1] = 250.*map->mapxlate[1]-OrigCY;
#endif
        map->mapxlate[2] = -(250.*map->mapxlate[2])-OrigCZ;
        
        for (jj=0; jj < 3; jj++) {
#ifdef INVERT
          MapM2R(map,1,jj) = -MapM2R(map,1,jj);
#endif
          MapM2R(map,2,jj) = -MapM2R(map,2,jj);
        }
        
        for (ii=0; ii < 3; ii++) {
          tempvecin[ii] = map->mapxlate[ii];
          for (jj=0; jj < 3; jj++) {
            tempmatin[ii][jj] = MapM2R(map,ii,jj);
          }
        }
        invxfrm (tempmatin,tempvecin, tempmatout, tempvecout);
        for (ii=0; ii < 3; ii++) {
          for (jj=0; jj < 3; jj++) {
            MapR2M(map,ii,jj) = tempmatout[ii][jj];
          }
        }
        
        
      }


      if (mask) {
        if (mask->maptype == MAP_ORTHOGONAL) {
          for (ii=0; ii < 3; ii++)  {
            mask->mapxlate[ii] = 0.;
              for (jj=0; jj < 3; jj++) {
                MapM2R(mask,ii,jj) = mask_axis_vector[jj][ii];
                mask->mapxlate[jj] += mask_axis_offset[ii][jj];
              }
              
          }
            
        } else  if (mask->maptype == MAP_FRACTIONAL) {
          for (ii=0; ii < 3; ii++)  {
            map->mapxlate[ii] = 0.;
              for (jj=0; jj < 3; jj++) {
                MapM2R(mask,ii,jj) = (matf2o[jj][0]*mask_axis_vector[ii][0]
                                  + matf2o[jj][1]*mask_axis_vector[ii][1]
                                  + matf2o[jj][2]*mask_axis_vector[ii][2])/
                                  mask_axis_length[ii];
                mask->mapxlate[jj] += matf2o[jj][0]*mask_axis_offset[ii][0]
                                  + matf2o[jj][1]*mask_axis_offset[ii][1]
                                  + matf2o[jj][2]*mask_axis_offset[ii][2];
              }
              
          }
          
            
        } else {if (map) _ffree(map); if (mask) _ffree(mask); return CBF_FORMAT;}

          mask->mapxlate[0] = 250.*(mask->mapxlate[0])-OrigCX;
#ifdef INVERT
        mask->mapxlate[1] = -(250.*mask->mapxlate[1])-OrigCY;
#else
        mask->mapxlate[1] = 250.*mask->mapxlate[1]-OrigCY;
#endif
        mask->mapxlate[2] = -(250.*mask->mapxlate[2])-OrigCZ;
        
        for (jj=0; jj < 3; jj++) {
#ifdef INVERT
          MapM2R(mask,1,jj) = -MapM2R(mask,1,jj);
#endif
          MapM2R(mask,2,jj) = -MapM2R(mask,2,jj);
        }
        for (ii=0; ii < 3; ii++) {
          tempvecin[ii] = mask->mapxlate[ii];
          for (jj=0; jj < 3; jj++) {
            tempmatin[ii][jj] = MapM2R(mask,ii,jj);
          }
        }
        invxfrm (tempmatin,tempvecin, tempmatout, tempvecout);
        for (ii=0; ii < 3; ii++) {
          for (jj=0; jj < 3; jj++) {
            MapR2M(mask,ii,jj) = tempmatout[ii][jj];
          }
        }
          
      }

      cbf_onfailnez(cbf_find_category(cbf,"array_data"),
        {if (map) _ffree(map); if (mask) _ffree(mask);})

    
      if (map) {
        int binary_id, elsigned, elunsigned;
        size_t elements,elements_read, elsize;
        int minelement, maxelement;
        unsigned int cifcompression;
        int realarray;
        const char *byteorder;
        size_t dim1, dim2, dim3, padding;

      
        cbf_onfailnez(cbf_find_column(cbf,"array_id"),
        {if (map) _ffree(map); if (mask) _ffree(mask);}) 
        cbf_onfailnez(cbf_rewind_row(cbf),
        {if (map) _ffree(map); if (mask) _ffree(mask);}) 
        while (!cbf_find_nextrow(cbf,map_structure_id)) {
          cbf_onfailnez(cbf_find_column(cbf,"binary_id"),
          {if (map) _ffree(map); if (mask) _ffree(mask);}) 
          if (!cbf_get_integervalue(cbf,&ii)&&ii==map_bin_id) {
            cbf_onfailnez(cbf_find_column(cbf,"data"),
            {if (map) _ffree(map); if (mask) _ffree(mask);})
            cbf_onfailnez(cbf_get_arrayparameters_wdims(
              cbf, &cifcompression,
              &binary_id, &elsize, &elsigned, &elunsigned,
              &elements, &minelement, &maxelement, &realarray,
              &byteorder, &dim1, &dim2, &dim3, &padding),
              {if (map) _ffree(map); if (mask) _ffree(mask);})
            if (elsize != map->elsize
              || dim1 != map_dimension[0]
              || dim2 != map_dimension[1]
              || dim3 != map_dimension[2]
              || (realarray&&map->eltype!=CBF_FLOAT)
              || dim1*dim2*dim3 <= 0 
              || dim1*dim2*dim3 != elements
              || binary_id != map_bin_id)
              {if (map) _ffree(map); if (mask) _ffree(mask);}
            cbf_onfailnez(cbf_alloc((void **)&mapdata, NULL, (map)->elsize, 
            map_dimension[0]*map_dimension[1]*map_dimension[2]),
            {if (map) _ffree(map); if (mask) _ffree(mask);})
            (map)->mapdata = (void *)mapdata;
            if (!realarray)  {
              cbf_onfailnez (cbf_get_integerarray(
                cbf, &binary_id, (map)->mapdata, elsize, elsigned,
                elements, &elements_read),
                {if (map) { _ffree(map->mapdata); _ffree(map);} if (mask) _ffree(mask);})
              if (elsize==sizeof(signed char)) {
                double datamin, datamax, datasum, datasqsum;
                register double data;
                datamax = datamin = datasum = (double)((signed char *)(map->mapdata))[0];
                datasqsum = datasum*datasum;
                for (ii=1; ii< elements; ii++) {
                  data = (double) (((signed char *)(map->mapdata))[ii]);
                  datasum += data;
                  datasqsum += data*data;
                  if (data > datamax) datamax = data;
                  if (data < datamin) datamin = data;
                }
                datasqsum /= (double)elements;
                map->mapdatamin = datamin;
                map->mapdatamax = datamax;
                map->mapdatamean = datasum/(double)elements;
                map->mapdataesd= sqrt(datasqsum/(double)elements-
                  map->mapdatamean*map->mapdatamean);
              } else if (elsize==sizeof(short)) {
                double datamin, datamax, datasum, datasqsum;
                register double data;
                datamax = datamin = datasum = (double)((short *)(map->mapdata))[0];
                datasqsum = datasum*datasum;
                for (ii=1; ii< elements; ii++) {
                  data = (double)(((short *)(map->mapdata))[ii]);
                  datasum += data;
                  datasqsum += data*data;
                  if (data > datamax) datamax = data;
                  if (data < datamin) datamin = data;
                }
                datasqsum /= (double)elements;
                map->mapdatamin = datamin;
                map->mapdatamax = datamax;
                map->mapdatamean = datasum/(double)elements;
                map->mapdataesd= sqrt(datasqsum/(double)elements-
                  map->mapdatamean*map->mapdatamean);
                  
              } else if (elsize==sizeof(int)) {
                double datamin, datamax, datasum, datasqsum;
                register double data;
                datamax = datamin = datasum = (double)((int *)(map->mapdata))[0];
                datasqsum = datasum*datasum;
                for (ii=1; ii< elements; ii++) {
                  data = (double)(((int *)(map->mapdata))[ii]);
                  datasum += data;
                  datasqsum += data*data;
                  if (data > datamax) datamax = data;
                  if (data < datamin) datamin = data;
                }
                datasqsum /= (double)elements;
                map->mapdatamin = datamin;
                map->mapdatamax = datamax;
                map->mapdatamean = datasum/(double)elements;
                map->mapdataesd= sqrt(datasqsum/(double)elements-
                  map->mapdatamean*map->mapdatamean);
                  
              }
              else {if (map) { _ffree(map->mapdata); _ffree(map);} if (mask) _ffree(mask); return CBF_FORMAT;}
            } else {
              cbf_onfailnez (cbf_get_realarray(
                cbf, &binary_id, (map)->mapdata, elsize,
                elements, &elements_read),
                {if (map) { _ffree(map->mapdata); _ffree(map);} if (mask) _ffree(mask);})
              if (elsize==sizeof(float)) {
                double datamin, datamax, datasum, datasqsum;
                register double data;
                datamax = datamin = datasum = (double)((float *)(map->mapdata))[0];
                datasqsum = datasum*datasum;
                for (ii=1; ii< elements; ii++) {
                  data = (double) (((float *)(map->mapdata))[ii]);
                  datasum += data;
                  datasqsum += data*data;
                  if (data > datamax) datamax = data;
                  if (data < datamin) datamin = data;
                }
                datasqsum /= (double)elements;
                map->mapdatamin = datamin;
                map->mapdatamax = datamax;
                map->mapdatamean = datasum/(double)elements;
                map->mapdataesd= sqrt(datasqsum/(double)elements-
                  map->mapdatamean*map->mapdatamean);
              } else if (elsize==sizeof(double)) {
                double datamin, datamax, datasum, datasqsum;
                register double data;
                datamax = datamin = datasum = ((double *)(map->mapdata))[0];
                datasqsum = datasum*datasum;
                for (ii=1; ii< elements; ii++) {
                  data = (((double *)(map->mapdata))[ii]);
                  datasum += data;
                  datasqsum += data*data;
                  if (data > datamax) datamax = data;
                  if (data < datamin) datamin = data;
                }
                datasqsum /= (double)elements;
                map->mapdatamin = datamin;
                map->mapdatamax = datamax;
                map->mapdatamean = datasum/(double)elements;
                map->mapdataesd= sqrt(datasqsum/(double)elements-
                  map->mapdatamean*map->mapdatamean);
                  
              }
              else {if (map) { _ffree(map->mapdata); _ffree(map);} if (mask) _ffree(mask); return CBF_FORMAT;}
            }
          }
        }
      }
      if (mask) {
        int binary_id, elsigned, elunsigned;
        size_t elements,elements_read, elsize;
        int minelement, maxelement;
        unsigned int cifcompression;
        int realarray;
        const char *byteorder;
        size_t dim1, dim2, dim3, padding;

      
        cbf_onfailnez(cbf_find_column(cbf,"array_id"),
        { _ffree(map->mapdata); _ffree(map); if (mask) _ffree(mask);}) 
        cbf_onfailnez(cbf_rewind_row(cbf),
        { _ffree(map->mapdata); _ffree(map); if (mask) _ffree(mask);}) 
        while (!cbf_find_nextrow(cbf,mask_structure_id)) {
          cbf_onfailnez(cbf_find_column(cbf,"binary_id"),
          { _ffree(map->mapdata); _ffree(map); if (mask) _ffree(mask);}) 
          if (!cbf_get_integervalue(cbf,&ii)&&ii==mask_bin_id) {
            cbf_onfailnez(cbf_find_column(cbf,"data"),
            { _ffree(map->mapdata); _ffree(map); if (mask) _ffree(mask);})
            cbf_onfailnez(cbf_get_arrayparameters_wdims(
              cbf, &cifcompression,
              &binary_id, &elsize, &elsigned, &elunsigned,
              &elements, &minelement, &maxelement, &realarray,
              &byteorder, &dim1, &dim2, &dim3, &padding),
              { _ffree(map->mapdata); _ffree(map); if (mask) _ffree(mask);})
            if (elsize != mask->elsize
              || dim1 != mask_dimension[0]
              || dim2 != mask_dimension[1]
              || dim3 != mask_dimension[2]
              || (realarray&&mask->eltype!=CBF_FLOAT)
              || dim1*dim2*dim3 <= 0 
              || dim1*dim2*dim3 != elements
              || binary_id != mask_bin_id)
              { _ffree(map->mapdata); _ffree(map); if (mask) _ffree(mask);}
            cbf_onfailnez(cbf_alloc((void **)&maskdata, NULL, (mask)->elsize, 
            mask_dimension[0]*mask_dimension[1]*mask_dimension[2]),
            { _ffree(map->mapdata); _ffree(map); if (mask) _ffree(mask);})
            (mask)->mapdata = (void *)maskdata;
            if (!realarray)  {
              cbf_onfailnez (cbf_get_integerarray(
                cbf, &binary_id, (mask)->mapdata, elsize, elsigned,
                elements, &elements_read),
                {if (map) { _ffree(map->mapdata); _ffree(map);} if (mask) {_ffree(mask->mapdata);_ffree(mask);}})
              if (elsize==sizeof(signed char)) {
                double datamin, datamax, datasum, datasqsum;
                register double data;
                datamax = datamin = datasum = (double)((signed char *)(mask->mapdata))[0];
                datasqsum = datasum*datasum;
                for (ii=1; ii< elements; ii++) {
                  data = (double) (((signed char *)(mask->mapdata))[ii]);
                  datasum += data;
                  datasqsum += data*data;
                  if (data > datamax) datamax = data;
                  if (data < datamin) datamin = data;
                }
                datasqsum /= (double)elements;
                mask->mapdatamin = datamin;
                mask->mapdatamax = datamax;
                mask->mapdatamean = datasum/(double)elements;
                mask->mapdataesd= sqrt(datasqsum/(double)elements-
                  mask->mapdatamean*mask->mapdatamean);
              } else if (elsize==sizeof(short)) {
                double datamin, datamax, datasum, datasqsum;
                register double data;
                datamax = datamin = datasum = (double)((short *)(mask->mapdata))[0];
                datasqsum = datasum*datasum;
                for (ii=1; ii< elements; ii++) {
                  data = (double)(((short *)(mask->mapdata))[ii]);
                  datasum += data;
                  datasqsum += data*data;
                  if (data > datamax) datamax = data;
                  if (data < datamin) datamin = data;
                }
                datasqsum /= (double)elements;
                mask->mapdatamin = datamin;
                mask->mapdatamax = datamax;
                mask->mapdatamean = datasum/(double)elements;
                mask->mapdataesd= sqrt(datasqsum/(double)elements-
                  mask->mapdatamean*mask->mapdatamean);
                  
              } else if (elsize==sizeof(int)) {
                double datamin, datamax, datasum, datasqsum;
                register double data;
                datamax = datamin = datasum = (double)((int *)(mask->mapdata))[0];
                datasqsum = datasum*datasum;
                for (ii=1; ii< elements; ii++) {
                  data = (double)(((int *)(mask->mapdata))[ii]);
                  datasum += data;
                  datasqsum += data*data;
                  if (data > datamax) datamax = data;
                  if (data < datamin) datamin = data;
                }
                datasqsum /= (double)elements;
                mask->mapdatamin = datamin;
                mask->mapdatamax = datamax;
                mask->mapdatamean = datasum/(double)elements;
                mask->mapdataesd= sqrt(datasqsum/(double)elements-
                  mask->mapdatamean*mask->mapdatamean);
                  
              }
              else {if (map) { _ffree(map->mapdata); _ffree(map);} if (mask) _ffree(mask); return CBF_FORMAT;}
            } else {
              cbf_onfailnez (cbf_get_realarray(
                cbf, &binary_id, (mask)->mapdata, elsize,
                elements, &elements_read),
                {if (map) { _ffree(map->mapdata); _ffree(map);} if (mask) {_ffree(mask->mapdata);_ffree(mask);}})
              if (elsize==sizeof(float)) {
                double datamin, datamax, datasum, datasqsum;
                register double data;
                datamax = datamin = datasum = (double)((float *)(mask->mapdata))[0];
                datasqsum = datasum*datasum;
                for (ii=1; ii< elements; ii++) {
                  data = (double) (((float *)(mask->mapdata))[ii]);
                  datasum += data;
                  datasqsum += data*data;
                  if (data > datamax) datamax = data;
                  if (data < datamin) datamin = data;
                }
                datasqsum /= (double)elements;
                mask->mapdatamin = datamin;
                mask->mapdatamax = datamax;
                mask->mapdatamean = datasum/(double)elements;
                mask->mapdataesd= sqrt(datasqsum/(double)elements-
                  mask->mapdatamean*mask->mapdatamean);
              } else if (elsize==sizeof(double)) {
                double datamin, datamax, datasum, datasqsum;
                register double data;
                datamax = datamin = datasum = ((double *)(mask->mapdata))[0];
                datasqsum = datasum*datasum;
                for (ii=1; ii< elements; ii++) {
                  data = (((double *)(mask->mapdata))[ii]);
                  datasum += data;
                  datasqsum += data*data;
                  if (data > datamax) datamax = data;
                  if (data < datamin) datamin = data;
                }
                datasqsum /= (double)elements;
                mask->mapdatamin = datamin;
                mask->mapdatamax = datamax;
                mask->mapdatamean = datasum/(double)elements;
                mask->mapdataesd= sqrt(datasqsum/(double)elements-
                  mask->mapdatamean*mask->mapdatamean);
                  
              }
              else {if (map) { _ffree(map->mapdata); _ffree(map);} if (mask) _ffree(mask); return CBF_FORMAT;}
            }
          }
        }
      }
      
          /* If no mask in the file try for one in MapMaskPtr */
          
      if (!mask && MapMaskPtr) {
      
        mask = _fmalloc(sizeof(MapStruct));
        if(!mask) {
          CommandError(MsgStrs[StrMalloc]);
          if (map) { _ffree(map->mapdata); _ffree(map);}
          return -1;    
        }
        mask->mapdata = _fmalloc(MapMaskPtr->elsize*
         (MapMaskPtr->xhigh-MapMaskPtr->xlow+1)*
         (MapMaskPtr->yhigh-MapMaskPtr->ylow+1)*
         (MapMaskPtr->zhigh-MapMaskPtr->zlow+1));
       if(!mask->mapdata) {
         _ffree(mask);
         CommandError(MsgStrs[StrMalloc]);
         if (map) { _ffree(map->mapdata); _ffree(map);}
         return -1;
       }
       mask->elsize=MapMaskPtr->elsize;
       mask->eltype=MapMaskPtr->eltype;
       mask->maptype=MapMaskPtr->maptype;
       mask->adiv=MapMaskPtr->adiv;
       mask->bdiv=MapMaskPtr->bdiv;
       mask->cdiv=MapMaskPtr->cdiv;
       mask->xint=MapMaskPtr->xint;
       mask->yint=MapMaskPtr->yint;
       mask->zint=MapMaskPtr->zint;
       mask->xorig=MapMaskPtr->xorig;
       mask->yorig=MapMaskPtr->yorig;
       mask->zorig=MapMaskPtr->zorig;
       mask->xlow=MapMaskPtr->xlow;
       mask->ylow=MapMaskPtr->ylow;
       mask->zlow=MapMaskPtr->zlow;
       mask->xhigh=MapMaskPtr->xhigh;
       mask->yhigh=MapMaskPtr->yhigh;
       mask->zhigh=MapMaskPtr->zhigh;
       mask->mapdatamin=MapMaskPtr->mapdatamin;
       mask->mapdatamax=MapMaskPtr->mapdatamax;
       mask->mapdatamean=MapMaskPtr->mapdatamean;
       mask->mapdataesd=MapMaskPtr->mapdataesd;
       for (ii=0; ii<9; ii++) {
         mask->mapm2r[ii]=MapMaskPtr->mapm2r[ii];
         mask->mapr2m[ii]=MapMaskPtr->mapr2m[ii];
       }
       for (ii=0; ii<3; ii++) {
         mask->mapxlate[ii]=MapMaskPtr->mapxlate[ii];
       }
       memmove(mask->mapdata,MapMaskPtr->mapdata,
         ((mask)->xhigh-(mask)->xlow+1)
         *((mask)->yhigh-(mask)->ylow+1)
         *((mask)->zhigh-(mask)->zlow+1)
         *((mask)->elsize));

          
      }
          
          /* Initialize a mapinfo struct */
  
      mapinfo.MapLevel = MapLevel;
      mapinfo.MapLabel = NULL;          /* clear the map label */
      mapinfo.MapSpacing = MapSpacing;
      if (MapSpread < 0.) MapSpread = 2.*((double)MapSpacing)/750.;
      mapinfo.MapSpread = MapSpread;
      if (!(MapFlag & (MapPointFlag|MapMeshFlag|MapSurfFlag)) ) MapFlag |= MapPointFlag;
      mapinfo.flag = SelectFlag|MapFlag;
      mapinfo.MapPointsPtr = NULL;
      mapinfo.MapBondsPtr = NULL;
      mapinfo.MapTanglePtr = NULL;
      mapinfo.MapMaskPtr = mask;
      mapinfo.MapFile = NULL;
      mapinfo.MapGenSel = NULL;
      mapinfo.MapMaskGenSel = NULL;
      mapinfo.MapPtr =map;
      mapinfo.MapRGBCol[0] = MapRGBCol[0];
      mapinfo.MapRGBCol[1] = MapRGBCol[1];
      mapinfo.MapRGBCol[2] = MapRGBCol[2];
      mapinfo.MapMeshRad = MapMeshRad;
      mapinfo.MapPointRad = MapPointRad;
      mapinfo.MapLabel = MapLabel;


      vector_create((GenericVec __far **)&mapinfo.MapPointsPtr,sizeof(MapPoint),1000);
      if (mapinfo.flag&(MapMeshFlag))
        vector_create((GenericVec __far **)&mapinfo.MapBondsPtr,sizeof(MapBond),1000);
      if (mapinfo.flag&(MapSurfFlag))
        vector_create((GenericVec __far **)&mapinfo.MapTanglePtr,sizeof(MapTangle),1000);

      cbf_failnez(map_points(mapinfo.MapPtr, 
      mapinfo.MapLevel+((mapinfo.flag&MapMeanFlag)?mapinfo.MapPtr->mapdatamean:0.), 
      mapinfo.MapSpacing, mapinfo.MapPointsPtr,mapinfo.MapBondsPtr,mapinfo.MapTanglePtr,
      mapinfo.MapMaskPtr, mapinfo.MapRGBCol ))

      mapinfo.MapFile = (char __far *)_fmalloc(strlen(DataFileName)+1);
      if (!mapinfo.MapFile) RasMolFatalExit(MsgStrs[StrMalloc]);
      strcpy(mapinfo.MapFile,DataFileName);

      if (mapno < 0)
        vector_add_element((GenericVec __far *)MapInfoPtr,(void __far *)&mapinfo);
      else
        vector_set_element((GenericVec __far *)MapInfoPtr,(void __far *)&mapinfo,mapno);
    
       
    } while (!cbf_next_datablock(cbf));
    
    
    cbf_free_handle(cbf);
    
    MapReRadius();
    ReRadius();

    ReDrawFlag |= RFRefresh;

    if( info )
    {   InvalidateCmndLine();

    }
    return 0;
}


int LoadCCP4MapFile( FILE *fp, int info, int mapno ) {

    MapInfo mapinfo;
    MapStruct * map;
          
    /* size of raw little-endian elements */
    
    int rawelsize;

    /* CCP4 map header variables */
    int NCRS[3], MODE, 
        NCRSSTART[3],
        NXYZ[3],ID[3];
    float XYZ[3], alpha, beta, gamma;
    int MAP_CRS[3], AXIS_XYZ[3];
    float AMIN, AMAX, AMEAN;
    int ISPG, NSYMBT, LSKFLG;
    float SKWMAT[9];
    float SKWTRAN[3];
    int DUMMY;
    char MAP[4];
    char MACHST[4];
    float ARMS;
    int NLABL;
    char LABEL[800];

    void * mapdata;
    double datasq;
    MapStruct __far *mapmaskptr;
    MapAtmSelVec __far *mapmaskgensel;
    
    cbf_file *mapfile;
    int i,ii;
    char buffer[80];
    
    long int fpos;
    int errorcnt;
    
    if (!MapInfoPtr) InitialiseMaps();
    if (MapSpacing <= 0) MapSpacing = 250L;
  
    /* Initialize a mapinfo struct */
  
    mapinfo.MapLevel = MapLevel;
    mapinfo.MapLabel = NULL;          /* clear the map label */
    mapinfo.MapSpacing = MapSpacing;
    if (MapSpread < 0.) MapSpread = 2.*((double)MapSpacing)/750.;
    mapinfo.MapSpread = MapSpread;
    if (!(MapFlag & (MapPointFlag|MapMeshFlag|MapSurfFlag)) ) MapFlag |= MapPointFlag;
    mapinfo.flag = SelectFlag|MapFlag;
    mapinfo.MapPointsPtr = NULL;
    mapinfo.MapBondsPtr = NULL;
    mapinfo.MapTanglePtr = NULL;
    mapinfo.MapMaskPtr = NULL;
    mapinfo.MapFile = NULL;
    mapinfo.MapGenSel = NULL;
    mapinfo.MapMaskGenSel = NULL;
    mapinfo.MapPtr =NULL;
    mapinfo.MapRGBCol[0] = MapRGBCol[0];
    mapinfo.MapRGBCol[1] = MapRGBCol[1];
    mapinfo.MapRGBCol[2] = MapRGBCol[2];
    mapinfo.MapMeshRad = MapMeshRad;
    mapinfo.MapPointRad = MapPointRad;
    mapinfo.MapLabel = MapLabel;
    MapLabel=NULL;
 
    cbf_failnez(cbf_make_file(&mapfile, fp))
    cbf_onfailnez(cbf_get_fileposition(mapfile, &fpos)
      ,cbf_free_file(&mapfile))
      
    cbf_onfailnez(cbf_set_fileposition(mapfile, 208L, SEEK_SET)
      ,cbf_free_file(&mapfile))    

    errorcnt = 0 ;
    for (ii=0; ii<4; ii++) {                                  /*  53 */
      unsigned int tmp;
      if (cbf_get_integer(mapfile,(int *)(&tmp),0,8) ) errorcnt++;
      ((unsigned char *)MAP)[ii]=tmp&0xFF;
    }
    
    if (cbf_cistrncmp(MAP,"MAP ",4)) errorcnt++;

    cbf_onfailnez(cbf_set_fileposition(mapfile, fpos, SEEK_SET)
      ,cbf_free_file(&mapfile))    

    if (errorcnt) {
      
      cbf_failnez(cbf_free_file(&mapfile));
      
      return CBF_FORMAT;
        
    }

    
    cbf_onfailnez(cbf_get_integer(mapfile,&NCRS[0],0,32)
      ,cbf_free_file(&mapfile))                                /*   1 */
    cbf_onfailnez(cbf_get_integer(mapfile,&NCRS[1],0,32)
      ,cbf_free_file(&mapfile))                                /*   2 */
    cbf_onfailnez(cbf_get_integer(mapfile,&NCRS[2],0,32)
      ,cbf_free_file(&mapfile))                                /*   3 */
    cbf_onfailnez(cbf_get_integer(mapfile,&MODE,0,32)
      ,cbf_free_file(&mapfile))                                /*   4 */
    cbf_onfailnez(cbf_get_integer(mapfile,&NCRSSTART[0],0,32)
      ,cbf_free_file(&mapfile))                                /*   5 */
    cbf_onfailnez(cbf_get_integer(mapfile,&NCRSSTART[1],0,32)
      ,cbf_free_file(&mapfile))                                /*   6 */
    cbf_onfailnez(cbf_get_integer(mapfile,&NCRSSTART[2],0,32)
      ,cbf_free_file(&mapfile))                                /*   7 */
    cbf_onfailnez(cbf_get_integer(mapfile,&NXYZ[0],0,32)
      ,cbf_free_file(&mapfile))                                /*   8 */
    cbf_onfailnez(cbf_get_integer(mapfile,&NXYZ[1],0,32)
      ,cbf_free_file(&mapfile))                                /*   9 */
    cbf_onfailnez(cbf_get_integer(mapfile,&NXYZ[2],0,32)
      ,cbf_free_file(&mapfile))                                /*  10 */
    cbf_onfailnez(cbf_get_integer(mapfile,(int *)&(XYZ[0]),0,32)
      ,cbf_free_file(&mapfile))                                /*  11 */
    cbf_onfailnez(cbf_get_integer(mapfile,(int *)&(XYZ[1]),0,32)
      ,cbf_free_file(&mapfile))                                /*  12 */
    cbf_onfailnez(cbf_get_integer(mapfile,(int *)&(XYZ[2]),0,32)
      ,cbf_free_file(&mapfile))                                /*  13 */
    cbf_onfailnez(cbf_get_integer(mapfile,(int *)&alpha,0,32)
      ,cbf_free_file(&mapfile))                                /*  14 */
    cbf_onfailnez(cbf_get_integer(mapfile,(int *)&beta,0,32)
      ,cbf_free_file(&mapfile))                                /*  15 */
    cbf_onfailnez(cbf_get_integer(mapfile,(int *)&gamma,0,32)
      ,cbf_free_file(&mapfile))                                /*  16 */
    cbf_onfailnez(cbf_get_integer(mapfile,&MAP_CRS[0],0,32)
      ,cbf_free_file(&mapfile))                                /*  17 */
    cbf_onfailnez(cbf_get_integer(mapfile,&MAP_CRS[1],0,32)
      ,cbf_free_file(&mapfile))                                /*  18 */
    cbf_onfailnez(cbf_get_integer(mapfile,&MAP_CRS[2],0,32)
      ,cbf_free_file(&mapfile))                                /*  19 */
    cbf_onfailnez(cbf_get_integer(mapfile,(int *)&AMIN,0,32)
      ,cbf_free_file(&mapfile))                                /*  20 */
    cbf_onfailnez(cbf_get_integer(mapfile,(int *)&AMAX,0,32)
      ,cbf_free_file(&mapfile))                                /*  21 */
    cbf_onfailnez(cbf_get_integer(mapfile,(int *)&AMEAN,0,32)
      ,cbf_free_file(&mapfile))                                /*  22 */
    cbf_onfailnez(cbf_get_integer(mapfile,&ISPG,0,32)
      ,cbf_free_file(&mapfile))                                /*  23 */
    cbf_onfailnez(cbf_get_integer(mapfile,&NSYMBT,0,32)
      ,cbf_free_file(&mapfile))                                /*  24 */
    cbf_onfailnez(cbf_get_integer(mapfile,&LSKFLG,0,32)
      ,cbf_free_file(&mapfile))                                /*  25 */
    
    for (ii=0; ii<9; ii++) {                                  /*  26 -- 34 */
      cbf_onfailnez(cbf_get_integer(mapfile,(int *)(SKWMAT+ii),0,32)
      ,cbf_free_file(&mapfile))    
    }

    for (ii=0; ii<3; ii++) {                                  /*  35 -- 37 */
      cbf_onfailnez(cbf_get_integer(mapfile,(int *)(SKWTRAN+ii),0,32)
      ,cbf_free_file(&mapfile))         
    }
    
    for (ii=38; ii<53; ii++) {                                /*  38 -- 52 */
      cbf_onfailnez(cbf_get_integer(mapfile,&DUMMY,0,32)
      ,cbf_free_file(&mapfile))         
    }
    
    for (ii=0; ii<4; ii++) {                                  /*  53 */
      unsigned int tmp;
      cbf_onfailnez(cbf_get_integer(mapfile,(int *)(&tmp),0,8)
      ,cbf_free_file(&mapfile))
      ((unsigned char *)MAP)[ii]=tmp&0xFF;
    }

    if (cbf_cistrncmp(MAP,"MAP ",4)) {
    

      cbf_failnez (cbf_free_file(&mapfile))    
      
      return CBF_FORMAT;
        
    }

    for (ii=0; ii<4; ii++) {                                  /*  54 */
      cbf_onfailnez(cbf_get_integer(mapfile,(int *)(MACHST+ii),0,8)
      ,cbf_free_file(&mapfile))     
    }
    
    cbf_onfailnez(cbf_get_integer(mapfile,(int *)&ARMS,0,32)
      ,cbf_free_file(&mapfile))                                  /*  55 */
    cbf_onfailnez(cbf_get_integer(mapfile,&NLABL,0,32)
      ,cbf_free_file(&mapfile))                                  /*  56 */

    for (ii=0; ii<800; ii++) {                                /*  57 -- 256 */                          
      cbf_onfailnez(cbf_get_integer(mapfile,(int *)(LABEL+ii),0,8)
      ,cbf_free_file(&mapfile))
    }
    
    NSYMBT = (NSYMBT+79)/80;
    NSYMBT *= 80;                                     /*THNX TO Marian Szebenyi*/
    
    for (ii=0; ii<NSYMBT; ii++) {                     /* 257 -- 256+(NSYMBT/4) */
      cbf_onfailnez(cbf_get_integer(mapfile,&DUMMY,0,8)
      ,cbf_free_file(&mapfile))
    }
   
    map = (MapStruct*)_fmalloc(sizeof(MapStruct));
    
    if (!map) return 1;
    
    AXIS_XYZ[MAP_CRS[0]-1] = 0;
    AXIS_XYZ[MAP_CRS[1]-1] = 1;
    AXIS_XYZ[MAP_CRS[2]-1] = 2;

    switch (MODE) {
    
        case 0:
        case 5:           /* signed bytes */
          rawelsize = 1;
          (map)->elsize = sizeof(signed char);
          (map)->eltype = CBF_INTEGER;
          break;
        case 1:              /* integer *2   */
          rawelsize = 2;
          (map)->elsize = sizeof(short);
          (map)->eltype = CBF_INTEGER;
          break;
        case 2:           /* real *2      */
          rawelsize = 2;
          (map)->elsize = sizeof(float);
          (map)->eltype = CBF_FLOAT;
          break;
        case 3:           /* complex integer *2 */
          return CBF_FORMAT;
        case 4:           /* complex real *2 */
          return CBF_FORMAT;
        default:
          return CBF_FORMAT;
    }
    
    (map)->maptype = MAP_FRACTIONAL;
    
    (map)->adiv = NXYZ[AXIS_XYZ[0]];
    (map)->bdiv = NXYZ[AXIS_XYZ[1]];
    (map)->cdiv = NXYZ[AXIS_XYZ[2]];
    
    (map)->xint = rint(250.*XYZ[AXIS_XYZ[0]]/NXYZ[AXIS_XYZ[0]]);
    (map)->yint = rint(250.*XYZ[AXIS_XYZ[1]]/NXYZ[AXIS_XYZ[1]]);
    (map)->zint = rint(250.*XYZ[AXIS_XYZ[2]]/NXYZ[AXIS_XYZ[2]]);
    
    
    (map)->xorig = NCRSSTART[AXIS_XYZ[0]]*(map)->xint;
    (map)->yorig = NCRSSTART[AXIS_XYZ[1]]*(map)->yint;
    (map)->zorig = NCRSSTART[AXIS_XYZ[2]]*(map)->zint;
    (map)->xlow = 0;
    (map)->ylow = 0;
    (map)->zlow = 0;
    (map)->xhigh = NCRS[AXIS_XYZ[0]]-1;
    (map)->yhigh = NCRS[AXIS_XYZ[1]]-1;
    (map)->zhigh = NCRS[AXIS_XYZ[2]]-1;
    (map)->mapdatamin = AMIN;
    (map)->mapdatamax = AMAX;
    (map)->mapdatamean = AMEAN;
    (map)->mapdataesd = 0.;
   
    (map)->mapxlate[0] = 250.*Info.vecf2o[0]-OrigCX;
#ifdef INVERT
    (map)->mapxlate[1] = -(250.*Info.vecf2o[1])-OrigCY;
#else
    (map)->mapxlate[1] = 250.*Info.vecf2o[1]-OrigCY;
#endif
    (map)->mapxlate[2] = -(250.*Info.vecf2o[2])-OrigCZ;
    
/* M2R[0,0] */
    (map)->mapm2r[0] = 250.*Info.matf2o[0][0]/((map)->xint*(double)NXYZ[0]);
/* M2R[0,1] */
    (map)->mapm2r[0+3] = 250.*Info.matf2o[0][1]/((map)->yint*(double)NXYZ[1]);
/* M2R[0,2] */
    (map)->mapm2r[0+6] = 250.*Info.matf2o[0][2]/((map)->zint*(double)NXYZ[2]);

#ifdef INVERT
/* M2R[1,0] */
    (map)->mapm2r[1] = -(250.*Info.matf2o[1][0]/((map)->xint*(double)NXYZ[0]));
/* M2R[1,1] */
    (map)->mapm2r[1+3] = -(250.*Info.matf2o[1][1]/((map)->yint*(double)NXYZ[1]));
/* M2R[1,2] */
    (map)->mapm2r[1+6] = -(250.*Info.matf2o[1][2]/((map)->zint*(double)NXYZ[2]));
#else
/* M2R[1,0] */
    (map)->mapm2r[1] = 250.*Info.matf2o[1][0]/((map)->xint*(double)NXYZ[0]);
/* M2R[1,1] */
    (map)->mapm2r[1+3] = 250.*Info.matf2o[1][1]/((map)->yint*(double)NXYZ[1]);
/* M2R[1,2] */
    (map)->mapm2r[1+6] = 250.*Info.matf2o[1][2]/((map)->zint*(double)NXYZ[2]);
#endif

/* M2R[2,0] */
    (map)->mapm2r[2] = -(250.*Info.matf2o[2][0]/((map)->xint*(double)NXYZ[0]));
/* M2R[2,1] */
    (map)->mapm2r[2+3] = -(250.*Info.matf2o[2][1]/((map)->yint*(double)NXYZ[1]));
/* M2R[2,2] */
    (map)->mapm2r[2+6] = -(250.*Info.matf2o[2][2]/((map)->zint*(double)NXYZ[2]));

/* R2M[0,0] */
    (map)->mapr2m[0] = (map)->xint*(double)NXYZ[0]*Info.mato2f[0][0]/250.;
/* R2M[1,0] */
    (map)->mapr2m[1] = (map)->yint*(double)NXYZ[1]*Info.mato2f[1][0]/250.;
/* R2M[2,0] */
    (map)->mapr2m[2] = (map)->zint*(double)NXYZ[2]*Info.mato2f[2][0]/250.;

#ifdef INVERT
/* R2M[0,1] */
    (map)->mapr2m[0+3] = -(map)->xint*(double)NXYZ[0]*Info.mato2f[0][1]/250.;
/* R2M[1,1] */
    (map)->mapr2m[1+3] = -(map)->yint*(double)NXYZ[1]*Info.mato2f[1][1]/250.;
/* R2M[2,1] */
    (map)->mapr2m[2+3] = -(map)->zint*(double)NXYZ[2]*Info.mato2f[2][1]/250.;
#else
/* R2M[0,1] */
    (map)->mapr2m[0+3] = (map)->xint*(double)NXYZ[0]*Info.mato2f[0][1]/250.;
/* R2M[1,1] */
    (map)->mapr2m[1+3] = (map)->yint*(double)NXYZ[1]*Info.mato2f[1][1]/250.;
/* R2M[2,1] */
    (map)->mapr2m[2+3] = (map)->zint*(double)NXYZ[2]*Info.mato2f[2][1]/250.;
#endif

/* R2M[0,2] */
    (map)->mapr2m[0+6] = -(map)->xint*(double)NXYZ[0]*Info.mato2f[0][2]/250.;
/* R2M[1,2] */
    (map)->mapr2m[2+6] = -(map)->yint*(double)NXYZ[1]*Info.mato2f[2][1]/250.;
/* R2M[2,2] */
    (map)->mapr2m[2+6] = -(map)->zint*(double)NXYZ[2]*Info.mato2f[2][2]/250.;


    datasq = 0;
    
    cbf_failnez(cbf_alloc((void **)&mapdata, NULL, (map)->elsize, NCRS[0]*NCRS[1]*NCRS[2]))
    (map)->mapdata = (void *)mapdata;
    
    /* ** ALLOCATE AND MAP THE DATA ITSELF ** */
    
    if ((map)->eltype == CBF_FLOAT)  {
      float temp;
      for (ID[2] = 0; ID[2] < NCRS[2]; ID[2]++)
        for (ID[1] = 0; ID[1] < NCRS[1]; ID[1]++)
          for (ID[0] = 0; ID[0] < NCRS[0]; ID[0]++) {
            cbf_onfailnez(cbf_get_integer(mapfile,(int *)&temp,0,32)
              ,cbf_free_file(&mapfile))
            /* fprintf(stderr,"mapel[%d,%d,%d] = %f\n",ID[AXIS_XYZ[0]],ID[AXIS_XYZ[1]],ID[AXIS_XYZ[2]],temp); */
            MapElfloat(map,ID[AXIS_XYZ[0]],ID[AXIS_XYZ[1]],ID[AXIS_XYZ[2]]) = (float)temp;
            datasq += ((double)temp)*((double)temp);
          }
      
    } else if (map->elsize == sizeof(char)) /* byte */
    {
      int bytetemp;
      for (ID[2] = 0; ID[2] < NCRS[2]; ID[2]++)
        for (ID[1] = 0; ID[1] < NCRS[1]; ID[1]++)
          for (ID[0] = 0; ID[0] < NCRS[0]; ID[0]++) {
            cbf_onfailnez(cbf_get_integer(mapfile,(int *)&bytetemp,0,8)
              ,cbf_free_file(&mapfile))                                  
            MapElchar(map,ID[AXIS_XYZ[0]],ID[AXIS_XYZ[1]],ID[AXIS_XYZ[2]]) = bytetemp;
            datasq += (double)(bytetemp*bytetemp); 
          }
    } else if (map->elsize == sizeof(short)) /* integer*2  */
    {
      int shorttemp;
      for (ID[2] = 0; ID[2] < NCRS[2]; ID[2]++)
        for (ID[1] = 0; ID[1] < NCRS[1]; ID[1]++)
          for (ID[0] = 0; ID[0] < NCRS[0]; ID[0]++) {
            cbf_onfailnez(cbf_get_integer(mapfile,(int *)&shorttemp,0,16)
              ,cbf_free_file(&mapfile))
            MapElshort(map,ID[AXIS_XYZ[0]],ID[AXIS_XYZ[1]],ID[AXIS_XYZ[2]]) = shorttemp;
            datasq += (double)(shorttemp*shorttemp); 
          }
    }
    
    datasq = datasq/((double)NCRS[0]*NCRS[1]*NCRS[2]);

    (map)->mapdataesd= sqrt(datasq-AMEAN*AMEAN);
    
    cbf_failnez(cbf_free_file(&mapfile))
    
    mapinfo.MapPtr = map;
    
    vector_create((GenericVec __far **)&mapinfo.MapPointsPtr,sizeof(MapPoint),1000);
    if (mapinfo.flag&(MapMeshFlag))
      vector_create((GenericVec __far **)&mapinfo.MapBondsPtr,sizeof(MapBond),1000);
    if (mapinfo.flag&(MapSurfFlag))
      vector_create((GenericVec __far **)&mapinfo.MapTanglePtr,sizeof(MapTangle),1000);
    
    if (MapMaskPtr) {
      mapmaskptr = _fmalloc(sizeof(MapStruct));
      if(!mapmaskptr) {
        CommandError(MsgStrs[StrMalloc]);
        return 1;    
      }
      mapmaskptr->mapdata = _fmalloc(MapMaskPtr->elsize*
       (MapMaskPtr->xhigh-MapMaskPtr->xlow+1)*
       (MapMaskPtr->yhigh-MapMaskPtr->ylow+1)*
       (MapMaskPtr->zhigh-MapMaskPtr->zlow+1));
     if(!mapmaskptr->mapdata) {
       _ffree(mapmaskptr);
       CommandError(MsgStrs[StrMalloc]);
       return 1;
     }
     mapmaskptr->elsize=MapMaskPtr->elsize;
     mapmaskptr->eltype=MapMaskPtr->eltype;
     mapmaskptr->maptype=MapMaskPtr->maptype;
     mapmaskptr->adiv=MapMaskPtr->adiv;
     mapmaskptr->bdiv=MapMaskPtr->bdiv;
     mapmaskptr->cdiv=MapMaskPtr->cdiv;
     mapmaskptr->xint=MapMaskPtr->xint;
     mapmaskptr->yint=MapMaskPtr->yint;
     mapmaskptr->zint=MapMaskPtr->zint;
     mapmaskptr->xorig=MapMaskPtr->xorig;
     mapmaskptr->yorig=MapMaskPtr->yorig;
     mapmaskptr->zorig=MapMaskPtr->zorig;
     mapmaskptr->xlow=MapMaskPtr->xlow;
     mapmaskptr->ylow=MapMaskPtr->ylow;
     mapmaskptr->zlow=MapMaskPtr->zlow;
     mapmaskptr->xhigh=MapMaskPtr->xhigh;
     mapmaskptr->yhigh=MapMaskPtr->yhigh;
     mapmaskptr->zhigh=MapMaskPtr->zhigh;
     mapmaskptr->mapdatamin=MapMaskPtr->mapdatamin;
     mapmaskptr->mapdatamax=MapMaskPtr->mapdatamax;
     mapmaskptr->mapdatamean=MapMaskPtr->mapdatamean;
     mapmaskptr->mapdataesd=MapMaskPtr->mapdataesd;
     for (i=0; i<9; i++) {
       mapmaskptr->mapm2r[i]=MapMaskPtr->mapm2r[i];
       mapmaskptr->mapr2m[i]=MapMaskPtr->mapr2m[i];
     }
     for (i=0; i<3; i++) {
       mapmaskptr->mapxlate[i]=MapMaskPtr->mapxlate[i];
     }
     memmove(mapmaskptr->mapdata,MapMaskPtr->mapdata,
      ((mapmaskptr)->xhigh-(mapmaskptr)->xlow+1)
      *((mapmaskptr)->yhigh-(mapmaskptr)->ylow+1)
      *((mapmaskptr)->zhigh-(mapmaskptr)->zlow+1)
      *((mapmaskptr)->elsize));
     mapinfo.MapMaskPtr=mapmaskptr;
     if (MapMaskGenSel) {
       MapAtmSel *mapatmsel;
       vector_create((GenericVec __far **)&mapmaskgensel,sizeof(MapAtmSel),10);
       for (i = 0; i < MapMaskGenSel->size; i++) {
         vector_get_elementptr((GenericVec __far *)MapMaskGenSel,(void __far * __far *)&mapatmsel,i );
         vector_set_element((GenericVec __far *)mapmaskgensel,mapatmsel,i);
       }
       mapinfo.MapGenSel=mapmaskgensel;
     }    
    }

    cbf_failnez(map_points(mapinfo.MapPtr, 
    mapinfo.MapLevel+((mapinfo.flag&MapMeanFlag)?mapinfo.MapPtr->mapdatamean:0.), 
    mapinfo.MapSpacing, mapinfo.MapPointsPtr,mapinfo.MapBondsPtr,mapinfo.MapTanglePtr,
    mapinfo.MapMaskPtr, mapinfo.MapRGBCol ))

    mapinfo.MapFile = (char __far *)_fmalloc(strlen(DataFileName)+1);
    if (!mapinfo.MapFile) {
      CommandError(MsgStrs[StrMalloc]);
      return -1;
    }
    strcpy(mapinfo.MapFile,DataFileName);

    if (mapno < 0)
      vector_add_element((GenericVec __far *)MapInfoPtr,(void __far *)&mapinfo);
    else
      vector_set_element((GenericVec __far *)MapInfoPtr,(void __far *)&mapinfo,mapno);
    

    MapReRadius();
    ReRadius();

    ReDrawFlag |= RFRefresh;

    if( info )
    {   InvalidateCmndLine();

        sprintf(buffer,"%d map values read from file\n",NCRS[0]*NCRS[1]*NCRS[2]);
        WriteString(buffer);
    }
    return 0;
}

#endif

/* vector_create -- create a generic vector */

int vector_create(GenericVec __far * __far * vector, size_t elementsize, size_t capacity) {

   *vector = (GenericVec __far *)_fmalloc(sizeof(GenericVec));
   
   if (!(*vector)) {
      CommandError(MsgStrs[StrMalloc]);
      return -1;
   }
   
   (*vector)->size = 0;
   (*vector)->capacity = 0;
   (*vector)->elementsize = elementsize;
   if (!capacity) capacity = 10;
   (*vector)->array = (void __far *)_fmalloc(capacity*elementsize);
   if ((*vector)->array) {
     (*vector)->capacity = capacity;
     return 0;
   }
   _ffree(*vector);
   *vector = NULL;
   CommandError(MsgStrs[StrMalloc]);
   return -1;
}


/*  vector_add_element -- add an element to a generic vector */

int vector_add_element(GenericVec __far * vector, void __far * element) {

   size_t newcap;
   
   if (!(vector)) return -1;
   
   if (vector->size >= vector->capacity) {
   
     void __far * temparray;
     
     newcap = vector->capacity*2;
     
     temparray = _fmalloc(newcap*vector->elementsize);
     if (!temparray)  {
       newcap = vector->capacity*1.2;
       if (newcap < vector->capacity+512) newcap = vector->capacity+512;
       temparray = _fmalloc(newcap*vector->elementsize);
       if (!temparray) {
            CommandError(MsgStrs[StrMalloc]);
         return -1;
       }
     }
     if (vector->size)    
       memmove((char *)temparray, (char *)vector->array, vector->size*vector->elementsize);
     _ffree(vector->array);
     vector->array = temparray;
     vector->capacity = newcap;
   }
   
   memmove(((char *)(vector->array))+vector->size*vector->elementsize,
     (char *)element, vector->elementsize);
   vector->size ++;
   return 0;

}

/* vector_get_element -- get a copy of an element from a generic vector */

int vector_get_element(GenericVec __far * vector, void __far * element, size_t index) {

  if (index >= 0 && index < vector->size) {
  
    memmove((char *)element,((char *)(vector->array))+index*vector->elementsize,
      vector->elementsize);
      
    return 0;
      
  } else {
      
      return -1;
  }
    
}


/* vector_get_elementptr -- get a pointer to an element from a generic vector */

int vector_get_elementptr(GenericVec __far * vector, void __far ** elementptr, size_t index) {

  if (index >= 0 && index < vector->size) {
  
    *elementptr = (void __far*)(((char *)(vector->array))+index*vector->elementsize);

    return 0;
      
  } else {
      
      return -1;
  }
    
}


/* vector_set_element -- set a copy of an element into a generic vector */

int vector_set_element(GenericVec __far * vector, void __far * element, size_t index) {

  size_t newcap;

  if (index >= vector->capacity) {

     void __far * temparray;
     
     newcap = (index+vector->capacity);
     
     temparray = _fmalloc(newcap*vector->elementsize);
     if (!temparray)  {
       newcap = index*1.2;
       if (newcap < index+128) newcap = index+128;
       temparray = _fmalloc(newcap*vector->elementsize);
       if (!temparray) {
            CommandError(MsgStrs[StrMalloc]);
         return -1;
       }
     }
     if (vector->size)    
       memmove((char *)temparray, (char *)vector->array, vector->size*vector->elementsize);
     _ffree(vector->array);
     vector->array = temparray;
     vector->capacity = newcap;
     _fmemset((void __far *)((char *)vector->array+vector->elementsize*vector->size),
     0,(vector->capacity-vector->size)*vector->elementsize);
  }


  if (index >= 0 && index < vector->capacity) {
  
    memmove(((char *)(vector->array))+index*vector->elementsize,(char *)element,
      vector->elementsize);
      
    if (index >= vector->size) vector->size = index+1;
    return 0;
      
  } else {
      
      return -1;
  }
    
}


/* vector_free -- remove a generic vector */

int vector_free(GenericVec __far * __far * vector) {

  if (*vector) {
    
    if ((*vector)->array) {
          
      _ffree((*vector)->array);
        
    }
      
    _ffree(*vector);
        
  }
    
  *vector = 0;
    
  return 0;
    
}


/* generate_map -- generate a map from the currently selected
   atoms in the database 
   
   Returns a pointer to the newly generated map in map
   The map uses x, y, z spacings of xint, yint, zint,
   based on an origin at xorig, yorig, zorig. 
   
   The values of array indices xlow, ylow, zlow, 
   xhigh, yhigh, zhigh are set to allow a buffer of size 
   buffer. 
   
   The values of xint, yint, zint, xorig, yorig, zorig
   are in the rasmol world coordinate system in units
   of 1/250 of an Angstrom.
   
   The location of an element at index ix, iy, iz in *map
   is *map->mapdata[ix-(*map->xlow)+
                   (*map->xhigh-*map->xlow+1)*(iy-(*map->ylow))+
                   (*map->xhigh-xlow+1)*(*map->yhigh-*map->ylow+1)*(iz-((*map->zlow))]
                   
   The physical location of that element in the atomic world
   coordinate system is
   
     {*map->xorig+ix*(*map->xint),
      *map->yorig+iy*(*map->yint),
      *map->zorig+iz*(*map->zint)}
      
   Each atom is mapped to a 3D Gaussian based on sig_per_rad
   sigmas per radius, with the Gaussian treated as zero
   at 4.5 sigma.  If ScaletoAN is set, the Gaussian is scaled to the 
   atomic number, otherwise it is scaled to 1.
   
   */
   
int generate_map(MapStruct **map, 
                            Long xint, Long yint, Long zint,
                            Long xorig, Long yorig, Long zorig,
                            Long buffer, double sig_per_rad,
                            int ScaletoAN) {

    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *ptr;
    register long xsellow,xselhigh,ysellow,yselhigh,zsellow,zselhigh;
    register long xpos, ypos, zpos;
    register long xel, yel, zel;
    register int radius;
    size_t mapcount;
    double test, pr;
    int ii, jj;
    
    double pi,sqrt2pi3;
    
    pi = PI;
    
    sqrt2pi3 = 2.*pi*sqrt(2.*pi);
    
    pr = 350.;
        
    if (ProbeRadius > 100) pr = (double)ProbeRadius;


    /* First intialize the map */
    
    *map = (MapStruct*)_fmalloc(sizeof(MapStruct));
    
    if (!*map) {
      CommandError(MsgStrs[StrMalloc]);
      return -1;
    }

    
    (*map)->elsize = sizeof(double);
    (*map)->eltype = CBF_FLOAT;    
    (*map)->maptype = MAP_ORTHOGONAL;    
    (*map)->adiv = 1;    
    (*map)->bdiv = 1;    
    (*map)->cdiv = 1;    
    (*map)->xint = xint;
    (*map)->yint = yint;
    (*map)->zint = zint;
    (*map)->xorig = xorig;
    (*map)->yorig = yorig;
    (*map)->zorig = zorig;

    (*map)->xlow = (*map)->xhigh = 0;
    (*map)->ylow = (*map)->yhigh = 0;
    (*map)->ylow = (*map)->zhigh = 0;
   

    /* Scan each selected atom and to determine the
       range to be covered */
       
    xsellow = xselhigh = xorig;
    ysellow = yselhigh = yorig;
    zsellow = zselhigh = zorig;
       
    ForEachAtom 
      if (ptr->flag&SelectFlag) {
      
        
        Long rad;
          
        Long sigcut;
                
        double sig;
        
        radius = ptr->radius;
        if (radius < 100) radius = Element[ptr->elemno].vdwrad;
        
        rad = radius;
        
        if (sig_per_rad > 0.) {
            
          sig = ((double)rad)/sig_per_rad;
          
        } else  {
             
          sig = sqrt((2.*pr*pr + 2.*rad*pr - pr*sqrt(4.*(rad+pr)*(rad+pr) - 4.*rad*rad))/(2.*log(2.)));

        }
        
#ifdef HIPREC
        sigcut = (Long)(6* sig);
#else
#ifdef LOPREC
        sigcut = (Long)(3* sig);
#else
        sigcut = (Long)(4.5*sig);
#endif
#endif

        xpos = ptr->xorg+ptr->fxorg+OrigCX;
#ifdef INVERT
        ypos = -(ptr->yorg+ptr->fyorg+OrigCY);
#else
        ypos = ptr->yorg+ptr->fyorg+OrigCY;
#endif
        zpos = -(ptr->zorg+ptr->fzorg+OrigCZ);

        if (xpos-sigcut < xsellow) xsellow = xpos-sigcut;
        if (ypos-sigcut < ysellow) ysellow = ypos-sigcut;
        if (zpos-sigcut < zsellow) zsellow = zpos-sigcut;
        if (xpos+sigcut > xselhigh) xselhigh = xpos+sigcut;
        if (ypos+sigcut > yselhigh) yselhigh = ypos+sigcut;
        if (zpos+sigcut > zselhigh) zselhigh = zpos+sigcut;
      }
      
      xsellow -= buffer;
      ysellow -= buffer;
      zsellow -= buffer;
      
      xselhigh += buffer;
      yselhigh += buffer;
      zselhigh += buffer;
      
  
      (*map)->xlow = (long)rint((double)(xsellow-xorig)/(double)(xint));
      (*map)->xhigh = (long)rint((double)(xselhigh-yorig)/(double)(xint));
      (*map)->ylow = (long)rint((double)(ysellow-zorig)/(double)(yint));
      (*map)->yhigh = (long)rint((double)(yselhigh-xorig)/(double)(yint));
      (*map)->zlow = (long)rint((double)(zsellow-yorig)/(double)(zint));
      (*map)->zhigh = (long)rint((double)(zselhigh-zorig)/(double)(zint));
    
      /*  I know this check seems extreme, but this actually
          happens */
    
      if (
          ((double)((*map)->xhigh-(*map)->xlow+1))*
          ((double)((*map)->yhigh-(*map)->ylow+1))*
          ((double)((*map)->zhigh-(*map)->zlow+1)) > ((double)LONG_MAX)/((double)sizeof(double)) - 1) {
          
          _ffree(*map);
          *map = NULL;
          CommandError(MsgStrs[StrMalloc]);
          return -1;
          
      }
      
      (*map)->mapdata = _fmalloc(sizeof(double)*
      ((*map)->xhigh-(*map)->xlow+1)*
      ((*map)->yhigh-(*map)->ylow+1)*
      ((*map)->zhigh-(*map)->zlow+1));
      
      if (!(*map)->mapdata) {
          _ffree(*map);
        *map = NULL;
        CommandError(MsgStrs[StrMalloc]);
        return -1;
      }
      
      for (xel=(*map)->xlow; xel<=(*map)->xhigh; xel++ )
        for (yel=(*map)->ylow; yel<=(*map)->yhigh; yel++  )
          for (zel=(*map)->zlow; zel<=(*map)->zhigh; zel++ )
            MapEldouble((*map),xel,yel,zel) = 0.;
      

    /* Scan each selected atom and add its contributions to the
       points in the map */
       
    ForEachAtom 
      if (ptr->flag&SelectFlag ){
      
        Long xpos, ypos, zpos;
        
        Long rad;
          
        Long sigcut;
        
        double sig, coeff;
        
        double scaleg;
        
        radius = ptr->radius;
        if (radius < 100) radius = Element[ptr->elemno].vdwrad;
        
        rad = radius;
        
        if (sig_per_rad > 0.) {
            
          sig = ((double)rad)/sig_per_rad;
          
        } else  {
                    
          sig = sqrt((2.*pr*pr + 2.*rad*pr - pr*sqrt(4.*(rad+pr)*(rad+pr) - 4.*rad*rad))/(2.*log(2.)));
         /*  sig = sqrt((pr*rad)/log(2.)); */

        }

#ifdef HIPREC
        sigcut = (Long)(6* sig);
#else
#ifdef LOPREC
        sigcut = (Long)(3 *sig);
#else
        sigcut = (Long)(4.5 *sig);
#endif
#endif
        
        sig /= 250.;
        
        coeff = 1/(sig*sig*sig*sqrt2pi3);
        
        if (ScaletoAN) {
            
          scaleg = (double)(ptr->elemno)*coeff;
        
        } else {
        
          scaleg = exp(rad*rad/(62500.*2.*sig*sig));
  
        }
        
        xpos = ptr->xorg + ptr->fxorg +OrigCX -xorig;
#ifdef INVERT
        ypos = -(ptr->yorg + ptr->fyorg +OrigCY) -yorig;
#else
        ypos = ptr->yorg + ptr->fyorg +OrigCY -yorig;
#endif
        zpos = -(ptr->zorg + ptr->fzorg +OrigCZ) -zorig;
        
        xsellow = xpos - sigcut;
        if (xsellow< 0) xsellow = ( xsellow - (xint-1) )/xint;
        else xsellow = ( xsellow + (xint-1) )/xint;
        if (xsellow < (*map)->xlow) xsellow = (*map)->xlow;
        if (xsellow > (*map)->xhigh) xsellow = (*map)->xhigh;

        ysellow = ypos - sigcut;
        if (ysellow< 0) ysellow = ( ysellow - (yint-1) )/yint;
        else ysellow = ( ysellow + (yint-1) )/yint;
        if (ysellow < (*map)->ylow) ysellow = (*map)->ylow;
        if (ysellow > (*map)->yhigh) ysellow = (*map)->yhigh;

        zsellow = zpos - sigcut;
        if (zsellow< 0) zsellow = ( zsellow - (zint-1) )/zint;
        else zsellow = ( zsellow + (zint-1) )/zint;
        if (zsellow < (*map)->zlow) zsellow = (*map)->zlow;
        if (zsellow > (*map)->zhigh) zsellow = (*map)->zhigh;

        xselhigh = xpos + sigcut;
        if (xselhigh< 0) xselhigh = ( xselhigh - (xint-1) )/xint;
        else xselhigh = ( xselhigh + (xint-1) )/xint;
        if (xselhigh < (*map)->xlow) xselhigh = (*map)->xlow;
        if (xselhigh > (*map)->xhigh) xselhigh = (*map)->xhigh;

        yselhigh = ypos + sigcut;
        if (yselhigh< 0) yselhigh = ( yselhigh - (yint-1) )/yint;
        else yselhigh = ( yselhigh + (yint-1) )/yint;
        if (yselhigh < (*map)->ylow) yselhigh = (*map)->ylow;
        if (yselhigh > (*map)->yhigh) yselhigh = (*map)->yhigh;

        zselhigh = zpos + sigcut;
        if (zselhigh< 0) zselhigh = ( zselhigh - (zint-1) )/zint;
        else zselhigh = ( zselhigh + (zint-1) )/zint;
        if (zselhigh < (*map)->zlow) zselhigh = (*map)->zlow;
        if (zselhigh > (*map)->zhigh) zselhigh = (*map)->zhigh;
        
        
        
        for (xel = xsellow; xel <= xselhigh; xel++)
          for (yel = ysellow; yel <= yselhigh; yel++)
            for (zel = zsellow; zel <= zselhigh; zel++) {
                 double distsq;
                 
                 distsq = ((double)(xel*xint-xpos))*((double)(xel*xint-xpos))
                   + ((double)(yel*yint-ypos))*((double)(yel*yint-ypos))
                   + ((double)(zel*zint-zpos))*((double)(zel*zint-zpos));
                   
                 distsq /= 62500.;
#ifdef LRSUMPROD
                if (ScaletoAN) {
#endif
                   MapEldouble((*map),xel,yel,zel) += scaleg*exp(-distsq/(2.*sig*sig));
#ifdef LRSUMPROD
                } else {
                   MapEldouble((*map),xel,yel,zel) = MapEldouble((*map),xel,yel,zel)+scaleg*exp(-distsq/(2.*sig*sig))
                     + MapEldouble((*map),xel,yel,zel)*scaleg*exp(-distsq/(2.*sig*sig));
                }
#endif

                 
                 /* fprintf (stderr,"MapEl(%ld,%ld,%ld) = %g\n",xel,yel,zel,MapEldouble((*map),xel,yel,zel)); */
            }
    
        
      }
      
      
      (*map)->mapdatamin = 1.e30;
      (*map)->mapdatamax = -1.e30;
      (*map)->mapdatamean = 0.;
      (*map)->mapdataesd = 0.;
      mapcount = 0;
      
      for (xel=(*map)->xlow; xel<=(*map)->xhigh; xel++ )
        for (yel=(*map)->ylow; yel<=(*map)->yhigh; yel++  )
          for (zel=(*map)->zlow; zel<=(*map)->zhigh; zel++ ) {
            test = MapEldouble((*map),xel,yel,zel);
            if (test) {
              mapcount++;
              if ((*map)->mapdatamin > test) (*map)->mapdatamin = test;
              if ((*map)->mapdatamax < test) (*map)->mapdatamax = test;
              (*map)->mapdatamean += test;
              (*map)->mapdataesd += test*test;
            }
          }
      if (mapcount) {    
        (*map)->mapdatamean /= (double)mapcount;
        (*map)->mapdataesd /= (double)mapcount;
        (*map)->mapdataesd = (*map)->mapdataesd-((*map)->mapdatamean)*((*map)->mapdatamean);
        (*map)->mapdataesd = sqrt((*map)->mapdataesd);
      } else {
        (*map)->mapdatamin = (*map)->mapdatamax = 0;
      }
      
      
      for (ii=0; ii< 3; ii++) {
        for (jj=0; jj< 3; jj++) {
          MapM2R(*map,ii,jj) = MapR2M(*map,ii,jj) = 0.;
        }
      }
      
      MapM2R(*map,0,0) = MapR2M(*map,0,0) = 1.;
      (*map)->mapxlate[0] = -OrigCX;
#ifdef INVERT
      MapM2R(*map,1,1) = MapR2M(*map,1,1) = -1.;
      (*map)->mapxlate[1] = -OrigCY;
#else
      MapM2R(*map,1,1) = MapR2M(*map,1,1) = 1.;
      (*map)->mapxlate[1] = -OrigCY;
#endif
      MapM2R(*map,2,2) = MapR2M(*map,2,2) = -1.;
      (*map)->mapxlate[2] = -OrigCZ;
      
      {char buffer[132];
          
      sprintf(buffer,"\nmap generate normal completion \n X:[%ld,%ld], Y:[%ld,%ld], Z:[%ld,%ld]\n",
        (*map)->xlow,(*map)->xhigh,(*map)->ylow,(*map)->yhigh,(*map)->zlow,(*map)->zhigh);
        
      WriteString(buffer);
      }
      
      
      
      return 0;
    
}

/*  map_point_distance_sq -- find the square of the
                             distance between two map points */

Long map_point_distance_sq(MapPointVec * PointVec,
                             int srcindex, int dstindex) {
                             
  MapPoint src;
  MapPoint dst;
  register Long dx, dy, dz;
  
  vector_get_element((GenericVec __far *)PointVec, (void __far *)(&src), srcindex);
  vector_get_element((GenericVec __far *)PointVec, (void __far *)(&dst), dstindex);
  
  dx = dst.xpos-src.xpos;
  dy = dst.ypos-src.ypos;
  dz = dst.zpos-src.zpos;

  return dx*dx+dy*dy+dz*dz;
    
}



/* Interpolate a map value from map at position [xpos,ypos,zpos]
   in map coordinates.
   
   If uselog is nonzero, the interpolation is done against the
   logarithms of the map values and the value returned is the
   logarithm of the interpolated value.
   
   The value is returned in value.  The function returns 0
   for success, -1 if the point is outside of the map.
   
   if gradient is not NULL, an estimate of the gradient is returned
   in {gradient[0], gradient[1], gradient[2]}
                                                              */

#define xabs(x) ((x)<0?-(x):(x))

int interpolate_map_value(MapStruct __far *map, 
                               Long xpos, Long ypos, Long zpos, 
                               int uselog, double * value, double * gradient) {
                               
  Long xp[8], yp[8], zp[8];
  Long xbase, ybase, zbase, xtop, ytop, ztop;
  Long xppos[8], yppos[8], zppos[8];
  double mapval[8], logmapval[8], mapest, logmapest;
  double d[8];
  int ii, ki;
  double otherx,othery,otherz;
  double lowval,highval;
  Long delta;
  
  xbase = map->xorig+(map->xlow)*(map->xint);
  ybase = map->yorig+(map->ylow)*(map->yint);
  zbase = map->zorig+(map->zlow)*(map->zint);
  xtop = map->xorig+(map->xhigh)*(map->xint);
  ytop = map->yorig+(map->yhigh)*(map->yint);
  ztop = map->zorig+(map->zhigh)*(map->zint);
  
  /* compute the indices of the [0,0,0] corner of a map box
     containing the point */
  
  xp[0] = (xpos-xbase)/(map->xint) + map->xlow;
  yp[0] = (ypos-ybase)/(map->yint) + map->ylow;
  zp[0] = (zpos-zbase)/(map->zint) + map->zlow;
  
  if ( xp[0] < map->xlow || xp[0] > map->xhigh
    || yp[0] < map->ylow || yp[0] > map->yhigh
    || zp[0] < map->zlow || zp[0] > map->zhigh ) return -1;
    
  switch(map->eltype) {
  
      case CBF_INTEGER:
        if (map->elsize == sizeof(char) ) {
            mapval[0] = (double)(MapElchar(map,xp[0]  ,yp[0]  ,zp[0] ) );
        } else if (map->elsize == sizeof(short) ) {
            mapval[0] = (double)(MapElshort(map,xp[0]  ,yp[0]  ,zp[0] ) );
        } else if (map->elsize == sizeof(int) ) {
          mapval[0] = (double)(MapElint(map,xp[0]  ,yp[0]  ,zp[0] ) );
        } else if (map->elsize == sizeof(long) ) {
            mapval[0] = (double)(MapEllong(map,xp[0]  ,yp[0]  ,zp[0] )  );
        } else { 
          return -1;
        }
        break;
      
      case CBF_FLOAT:
        if(map->elsize ==  sizeof(float)) {
        mapval[0] = (double)(MapElfloat(map,xp[0]  ,yp[0]  ,zp[0] ) );
      } else if (map->elsize ==  sizeof(double)) {
           mapval[0] = (double)(MapEldouble(map,xp[0]  ,yp[0]  ,zp[0] ) );
        } else { 
          return -1;
        }
        break;
  }
  
  
  xppos[0] = map->xorig + xp[0]*(map->xint);
  yppos[0] = map->yorig + yp[0]*(map->yint);
  zppos[0] = map->zorig + zp[0]*(map->zint);
  

  d[0] = sqrt((double)((xppos[0]-xpos)*(xppos[0]-xpos)+(yppos[0]-ypos)*(yppos[0]-ypos)+(zppos[0]-zpos)*(zppos[0]-zpos)));
  
  if (d[0] < 3 && !gradient)  {
    
    if (uselog){
        *value = LogMapVal(mapval[0]);
    } else {
        *value = mapval[0];
    }
      
      /* if (mapval[0]) fprintf (stderr, "using map point %ld %ld %ld %g\n", xp[0], yp[0], zp[0], *value);*/
      
      return 0;
  }
      
  xp[7] = (xp[0] < map->xhigh)?xp[0]+1:xp[0]-1;
  yp[7] = (yp[0] < map->yhigh)?yp[0]+1:yp[0]-1;
  zp[7] = (zp[0] < map->zhigh)?zp[0]+1:zp[0]-1;

  switch(map->eltype) {
  
      case CBF_INTEGER:
        if(map->elsize == sizeof(char) ){
        mapval[1] = (double)MapElchar(map,xp[0]  ,yp[0]  ,zp[7] );
        mapval[2] = (double)MapElchar(map,xp[0]  ,yp[7]  ,zp[0] );
        mapval[3] = (double)MapElchar(map,xp[0]  ,yp[7]  ,zp[7] );
        mapval[4] = (double)MapElchar(map,xp[7]  ,yp[0]  ,zp[0] );
        mapval[5] = (double)MapElchar(map,xp[7]  ,yp[0]  ,zp[7] );
        mapval[6] = (double)MapElchar(map,xp[7]  ,yp[7]  ,zp[0] );
        mapval[7] = (double)MapElchar(map,xp[7]  ,yp[7]  ,zp[7] );
        } else if (map->elsize == sizeof(short) ) {
          mapval[1] = (double)MapElshort(map,xp[0]  ,yp[0]  ,zp[7] );
        mapval[2] = (double)MapElshort(map,xp[0]  ,yp[7]  ,zp[0] );
        mapval[3] = (double)MapElshort(map,xp[0]  ,yp[7]  ,zp[7] );
        mapval[4] = (double)MapElshort(map,xp[7]  ,yp[0]  ,zp[0] );
        mapval[5] = (double)MapElshort(map,xp[7]  ,yp[0]  ,zp[7] );
        mapval[6] = (double)MapElshort(map,xp[7]  ,yp[7]  ,zp[0] );
        mapval[7] = (double)MapElshort(map,xp[7]  ,yp[7]  ,zp[7] );
        } else if (map->elsize == sizeof(int) ) {
        mapval[1] = (double)MapElint(map,xp[0]  ,yp[0]  ,zp[7] );
        mapval[2] = (double)MapElint(map,xp[0]  ,yp[7]  ,zp[0] );
        mapval[3] = (double)MapElint(map,xp[0]  ,yp[7]  ,zp[7] );
        mapval[4] = (double)MapElint(map,xp[7]  ,yp[0]  ,zp[0] );
        mapval[5] = (double)MapElint(map,xp[7]  ,yp[0]  ,zp[7] );
        mapval[6] = (double)MapElint(map,xp[7]  ,yp[7]  ,zp[0] );
        mapval[7] = (double)MapElint(map,xp[7]  ,yp[7]  ,zp[7] );
        } else if (map->elsize == sizeof(long) ) {
        mapval[1] = (double)MapEllong(map,xp[0]  ,yp[0]  ,zp[7] );
        mapval[2] = (double)MapEllong(map,xp[0]  ,yp[7]  ,zp[0] );
        mapval[3] = (double)MapEllong(map,xp[0]  ,yp[7]  ,zp[7] );
        mapval[4] = (double)MapEllong(map,xp[7]  ,yp[0]  ,zp[0] );
        mapval[5] = (double)MapEllong(map,xp[7]  ,yp[0]  ,zp[7] );
        mapval[6] = (double)MapEllong(map,xp[7]  ,yp[7]  ,zp[0] );
        mapval[7] = (double)MapEllong(map,xp[7]  ,yp[7]  ,zp[7] );
        } else {
        return -1;
        }
        break;
      
      case CBF_FLOAT:
         if (map->elsize== sizeof(float) ) {
           mapval[1] = (double)MapElfloat(map,xp[0]  ,yp[0]  ,zp[7] );
         mapval[2] = (double)MapElfloat(map,xp[0]  ,yp[7]  ,zp[0] );
         mapval[3] = (double)MapElfloat(map,xp[0]  ,yp[7]  ,zp[7] );
         mapval[4] = (double)MapElfloat(map,xp[7]  ,yp[0]  ,zp[0] );
         mapval[5] = (double)MapElfloat(map,xp[7]  ,yp[0]  ,zp[7] );
         mapval[6] = (double)MapElfloat(map,xp[7]  ,yp[7]  ,zp[0] );
         mapval[7] = (double)MapElfloat(map,xp[7]  ,yp[7]  ,zp[7] );
         } else if (map->elsize== sizeof(double) ) {
         mapval[1] = (double)MapEldouble(map,xp[0]  ,yp[0]  ,zp[7] );
         mapval[2] = (double)MapEldouble(map,xp[0]  ,yp[7]  ,zp[0] );
         mapval[3] = (double)MapEldouble(map,xp[0]  ,yp[7]  ,zp[7] );
         mapval[4] = (double)MapEldouble(map,xp[7]  ,yp[0]  ,zp[0] );
         mapval[5] = (double)MapEldouble(map,xp[7]  ,yp[0]  ,zp[7] );
         mapval[6] = (double)MapEldouble(map,xp[7]  ,yp[7]  ,zp[0] );
         mapval[7] = (double)MapEldouble(map,xp[7]  ,yp[7]  ,zp[7] );
         } else  {
          return -1;
         }
         break;
      
      default: return -1;
      
  }
  
  xp[1] = xp[2] = xp[3] = xp[0];
  xp[4] = xp[5] = xp[6] = xp[7];
  yp[1] = yp[4] = yp[5] = yp[0];
  yp[2] = yp[3] = yp[6] = yp[7];
  zp[2] = zp[4] = zp[6] = zp[0];
  zp[1] = zp[3] = zp[5] = zp[7];
  
  /* Compute the positions of the 7 other corners */

  for (ii = 1; ii < 8; ii++ ) {
     xppos[ii] = map->xorig + xp[ii]*(map->xint);
     yppos[ii] = map->yorig + yp[ii]*(map->yint);
     zppos[ii] = map->zorig + zp[ii]*(map->zint);
  }
              
              
  d[1] = sqrt((double)((xppos[1]-xpos)*(xppos[1]-xpos)+(yppos[1]-ypos)*(yppos[1]-ypos)+(zppos[1]-zpos)*(zppos[1]-zpos)));
  d[2] = sqrt((double)((xppos[2]-xpos)*(xppos[2]-xpos)+(yppos[2]-ypos)*(yppos[2]-ypos)+(zppos[2]-zpos)*(zppos[2]-zpos)));
  d[3] = sqrt((double)((xppos[3]-xpos)*(xppos[3]-xpos)+(yppos[3]-ypos)*(yppos[3]-ypos)+(zppos[3]-zpos)*(zppos[3]-zpos)));
  d[4] = sqrt((double)((xppos[4]-xpos)*(xppos[4]-xpos)+(yppos[4]-ypos)*(yppos[4]-ypos)+(zppos[4]-zpos)*(zppos[4]-zpos)));
  d[5] = sqrt((double)((xppos[5]-xpos)*(xppos[5]-xpos)+(yppos[5]-ypos)*(yppos[5]-ypos)+(zppos[5]-zpos)*(zppos[5]-zpos)));
  d[6] = sqrt((double)((xppos[6]-xpos)*(xppos[6]-xpos)+(yppos[6]-ypos)*(yppos[6]-ypos)+(zppos[6]-zpos)*(zppos[6]-zpos)));
  d[7] = sqrt((double)((xppos[7]-xpos)*(xppos[7]-xpos)+(yppos[7]-ypos)*(yppos[7]-ypos)+(zppos[7]-zpos)*(zppos[7]-zpos)));


  /* Estimate the value at the probe point as the reciprocal distance
     weighed average of the map box selected */
              
  if (uselog){
      
    for (ii = 0; ii < 8; ii++) {
      logmapval[ii] = LogMapVal(mapval[ii]);
    }

              
    ki = -1;
    for (ii = 0; ii < 8; ii++) {
      if (d[ii] < 3.) { ki = ii; break; }      
    }
    if (ki == -1)  {
      logmapest = logmapval[0]/d[0];
      for (ii = 1; ii < 8; ii++) logmapest += logmapval[ii]/d[ii];
      logmapest /= (1./d[0]+1./d[1]+1./d[2]+1./d[3]+1./d[4]+1./d[5]+1./d[6]+1./d[7]);
    } else {
      logmapest = logmapval[ki];
    }
    
    mapest = logmapest;
    *value = logmapest;
    if(!gradient) return 0;
    
  } else {

    ki = -1;
    for (ii = 0; ii < 8; ii++) {
      if (d[ii] < 3.) { ki = ii; break; }      
    }
    if (ki == -1)  {
      mapest = mapval[0]/d[0];
      for (ii = 1; ii < 8; ii++) mapest += mapval[ii]/d[ii];
      mapest /= (1./d[0]+1./d[1]+1./d[2]+1./d[3]+1./d[4]+1./d[5]+1./d[6]+1./d[7]);
    } else {
      mapest = mapval[ki];
    }
    
    *value = mapest;
    if (!gradient) return 0;
      
  }
  
  /* A gradient has been requested */
  
  delta=40;
  if (xpos-delta >= xbase && xpos+delta <= xtop)  {
    interpolate_map_value(map,xpos-delta,ypos,zpos,uselog,&lowval,NULL);
    interpolate_map_value(map,xpos+delta,ypos,zpos,uselog,&highval,NULL);
    gradient[0] = (highval-lowval)/(double)(2*delta);    
  } else {
    if (xabs(xppos[0]-xpos) > xabs(xppos[7]-xpos) ) {
      interpolate_map_value(map,xppos[0],ypos,zpos,uselog,&otherx,NULL);
      gradient[0] = (otherx-mapest)/(double)(xppos[0]-xpos);
    } else {
      interpolate_map_value(map,xppos[7],ypos,zpos,uselog,&otherx,NULL);
      gradient[0] = (otherx-mapest)/(double)(xppos[7]-xpos);        
    }
  }
  if (ypos-delta >= ybase && ypos+delta <= ytop)  {
    interpolate_map_value(map,xpos,ypos-delta,zpos,uselog,&lowval,NULL);
    interpolate_map_value(map,xpos,ypos+delta,zpos,uselog,&highval,NULL);
    gradient[1] = (highval-lowval)/(double)(2*delta);    
  } else {
    if (xabs(yppos[0]-ypos) > xabs(yppos[7]-ypos) ) {
      interpolate_map_value(map,xpos,yppos[0],zpos,uselog,&othery,NULL);
      gradient[1] = (othery-mapest)/(double)(yppos[0]-ypos);
    } else {
      interpolate_map_value(map,xpos,yppos[7],zpos,uselog,&othery,NULL);
      gradient[1] = (othery-mapest)/(double)(yppos[7]-ypos);
    }
  }
  if (zpos-delta >= zbase && zpos+delta <= ztop)  {
    interpolate_map_value(map,xpos,ypos,zpos-delta,uselog,&lowval,NULL);
    interpolate_map_value(map,xpos,ypos,zpos+delta,uselog,&highval,NULL);
    gradient[2] = (highval-lowval)/(double)(2*delta);    
  } else {
    if (xabs(zppos[0]-zpos) > xabs(zppos[7]-zpos) ) {
      interpolate_map_value(map,xpos,ypos,zppos[0],uselog,&otherz,NULL);
      gradient[2] = (otherz-mapest)/(double)(zppos[0]-zpos);
    } else {
      interpolate_map_value(map,xpos,ypos,zppos[7],uselog,&otherz,NULL);
      gradient[2] = (otherz-mapest)/(double)(zppos[7]-zpos);
    }
  }
    
  return 0;
  

}

/* Interpolate a map value from map at position [xpos,ypos,zpos]
   in orthogonal coordinates.
   
   If uselog is nonzero, the interpolation is done against the
   logarithms of the map values and the value returned is the
   logarithm of the interpolated value.
   
   The value is returned in value.  The function returns 0
   for success, -1 if the point is outside of the map.
                                                              */

int interpolate_oc_map_value(MapStruct __far *map, 
                               Long xpos, Long ypos, Long zpos, 
                               int uselog, double * value ) {
    double pos[3],mpos[3];
    int i;
    
    pos[0] = (double)(xpos-map->mapxlate[0]);
    pos[1] = (double)(ypos-map->mapxlate[1]);
    pos[2] = (double)(zpos-map->mapxlate[2]);
    
    for (i = 0; i < 3; i++) {
      mpos[i] = rint(MapR2M(map,i,0)*pos[0]+MapR2M(map,i,1)*pos[1]+MapR2M(map,i,2)*pos[2]);
    }
    
    return interpolate_map_value(map,(Long)mpos[0],(Long)mpos[1],(Long)mpos[2],
      uselog, value, NULL);
    
}


/*  map_points --  Find the points in a map at a given level with a given
                   spacing and adds them to the PointVec list of points
                   
                   If MapBondVec is not NULL, map bonds will be added
                   to that list of bonds
                   
                   If MapTangleVec is not NULL triples of points will
                   be added to the list of triangles
 
 */
 
 #define vec_diff(z,x,y) { (z)[0] = (x)[0]-(y)[0]; (z)[1] = (x)[2]-(y)[2]; (z)[2] = (x)[2]-(y)[2];}
 #define vec_dot(d,x,y) {(d)=(x)[0]*(y)[0]+(x)[1]*(y)[1]+(x)[2]*(y)[2];}
 #define vec_cross(c,x,y) { c[0] = x[1]*y[2]-x[2]*y[1]; c[1] = x[2]*y[0]-x[0]*y[2]; c[2] = x[0]*y[1]-x[1]*y[0];}
 #define vec_scale(a,x) { (x)[0]*=(a);(x)[1]*=(a);(x)[2]*=(a);}
 #define vec_copy(out,in) {out[0]=in[0];out[1]=in[1];out[2]=in[2];}
 
int map_points(MapStruct __far *map, double level, Long spacing,
      MapPointVec __far *PointVec, MapBondVec __far *BondVec,
      MapTangleVec __far *TangleVec, MapStruct __far *mapmask,
      int RGBCol[3] ) {
      
      Long xwid, ywid, zwid;
      Long xpts, ypts, zpts;
      Long xbase, ybase, zbase;
      Long ix, iy, iz, zalt;
      Long xp[8], yp[8], zp[8];
      double mapval[8], loglevel;
      int havemapval[8]; 
      double valdist[8];
      double marked[8];
      double gradient[3];
      double masklevel,maskmin;
      double testlevel;
      double dummy;
      int ii, jj, kk;
      int zero = 0;
      int haveedges[3], havefaces[3], havebody;
      int edges[3][2] = { {0,1}, {0,2}, {0,4} };               /* X, Y, Z  */
      int odirs[3][2];                                         /* {Y,Z}, {Z,X}, {X,Y} */
      Long koffsets[3][2];  /* The offsets back to the prior cells */
      MapPoint mp;
      MapBond mb;
      MapTangle mt;
      
      /* PointsUsed is a vector of level points for 2 layers of cubes, with
         points on edges in the order X, Y, Z.  The layers alternate
         as iz increments, starting at 0  */
      
      GenericVec __far *PointsUsed;
      int shade;
      
      mp.next = 0;
      shade = DefineShade(RGBCol[0],RGBCol[1],RGBCol[2]);
      mp.col = Shade2Colour(shade);
      mp.coordnum = 0;
      mp.flag = SelectFlag;
      mb.col = mp.col;
      mb.flag = SelectFlag;
      mt.col = mp.col;
      mt.flag = SelectFlag;
      if (BondVec) Shade[shade].refcount++;
      if (TangleVec) Shade[shade].refcount++;
      
      /* Will do the calculations in terms of logs */
      
      loglevel = LogMapVal(level);
      masklevel = 0.;
      maskmin = 0.;
      if (mapmask) {          
        masklevel = LogMapVal(mapmask->mapdatamean);
        maskmin   = LogMapVal(map->mapdatamin);
      }
      
      /* Get the dimensions of the map */
      
      xwid = (map->xhigh - map->xlow + 1)*map->xint;
      ywid = (map->yhigh - map->ylow + 1)*map->yint;
      zwid = (map->zhigh - map->zlow + 1)*map->zint;
      
      /* We need to determine the number of points in each
         direction using spacing */
         
      xpts = (xwid+spacing-1)/spacing;
      ypts = (ywid+spacing-1)/spacing;
      zpts = (zwid+spacing-1)/spacing;
      
      
      
      /* offsets to go back to prior X-edge */
      
      koffsets[0][0] = -xpts;         /* back in Y */
      koffsets[0][1] = -xpts*ypts;    /* back in Z */
      odirs[0][0] = 1;
      odirs[0][1] = 2;
      

      /* offsets to go back to prior Y-edge */
      
      koffsets[1][0] = -xpts*ypts;           /* back in Z */
      koffsets[1][1] = -1;                   /* back in X */
      odirs[1][0] = 2;
      odirs[1][1] = 0;
      
      /* offsets to go back to prior Z-edge */
      
      koffsets[2][0] = -1;            /* back in X */
      koffsets[2][1] = -xpts;         /* back in Y */
      odirs[2][0] = 0;
      odirs[2][1] = 1;
      
      if (BondVec || TangleVec) vector_create(&PointsUsed,sizeof(int),xpts*ypts*6);
      
      /* Get an adjusted base, perhaps slightly outside the map */
      
      xbase = -(xpts*spacing-xwid)/2+map->xorig+map->xlow*map->xint;
      ybase = -(ypts*spacing-ywid)/2+map->yorig+map->ylow*map->yint;
      zbase = -(zpts*spacing-zwid)/2+map->zorig+map->zlow*map->zint;
      
      /* Now look for point in each box, taking a level point on
         each edge, each face and the body of the box, clipping
         at the edge of the map
      
      */
      
      
      zp[0] = zbase;
      zp[7] = zbase+spacing;
      zalt = 0;
      for (iz = 0; iz < zpts; iz ++) {
        yp[0] = ybase;
        yp[7] = ybase+spacing;
        for (iy = 0; iy < ypts; iy ++) {
          xp[0] = xbase;
          xp[7] = xbase+spacing;
          for (ix = 0; ix < xpts; ix ++) {

            if (BondVec||TangleVec) {
                
              vector_set_element(PointsUsed,&zero,3*(ix+iy*xpts+zalt*xpts*ypts));
              vector_set_element(PointsUsed,&zero,1+3*(ix+iy*xpts+zalt*xpts*ypts));
              vector_set_element(PointsUsed,&zero,2+3*(ix+iy*xpts+zalt*xpts*ypts));
             
            }

            havemapval[0]=!interpolate_map_value(map,xp[0],yp[0],zp[0],1,&(mapval[0]),NULL);

            if ( havemapval[0] ) {
                
            havemapval[1]=!interpolate_map_value(map,xp[7],yp[0],zp[0],1,&(mapval[1]),NULL);
            havemapval[2]=!interpolate_map_value(map,xp[0],yp[7],zp[0],1,&(mapval[2]),NULL);
            havemapval[3]=!interpolate_map_value(map,xp[7],yp[7],zp[0],1,&(mapval[3]),NULL);
            havemapval[4]=!interpolate_map_value(map,xp[0],yp[0],zp[7],1,&(mapval[4]),NULL);
            havemapval[5]=!interpolate_map_value(map,xp[7],yp[0],zp[7],1,&(mapval[5]),NULL);
            havemapval[6]=!interpolate_map_value(map,xp[0],yp[7],zp[7],1,&(mapval[6]),NULL);
            havemapval[7]=!interpolate_map_value(map,xp[7],yp[7],zp[7],1,&(mapval[7]),NULL);
            
               
            xp[2] = xp[4] = xp[6] = xp[0];
            xp[1] = xp[3] = xp[5] = xp[7];
            yp[1] = yp[4] = yp[5] = yp[0];
            yp[2] = yp[3] = yp[6] = yp[7];
            zp[1] = zp[2] = zp[3] = zp[0];
            zp[4] = zp[5] = zp[6] = zp[7];
              
            if (mapmask) {
              double oxpos[8],oypos[8],ozpos[8];
              Mapm2o(map,xp[0],yp[0],zp[0],oxpos[0],oypos[0],ozpos[0]);
              Mapm2o(map,xp[7],yp[7],zp[7],oxpos[7],oypos[7],ozpos[7]);
              oxpos[2] = oxpos[4] = oxpos[6] = oxpos[0];
              oxpos[1] = oxpos[3] = oxpos[5] = oxpos[7];
              oypos[1] = oypos[4] = oypos[5] = oypos[0];
              oypos[2] = oypos[3] = oypos[6] = oypos[7];
              ozpos[1] = ozpos[2] = ozpos[3] = ozpos[0];
              ozpos[4] = ozpos[5] = ozpos[6] = ozpos[7];
           
              for(ii=0; ii < 8; ii++) {
                if (havemapval[ii]) {
                  if(!interpolate_oc_map_value(mapmask,oxpos[ii],oypos[ii],ozpos[ii],1,&testlevel)){
                    if (testlevel < masklevel) {
                      mapval[ii] = maskmin;
                    }
                  } else {
                      havemapval[ii] = 0;
                  }
                }
              }
            }
            
            
            for (ii=0; ii < 8; ii ++) if (havemapval[ii]) valdist[ii] = fabs(mapval[ii]-loglevel);
            for (ii=0; ii < 8; ii ++) marked[ii] = 0;
            for (ii=0; ii < 3; ii ++) haveedges[ii] = havefaces[ii] = 0;
            havebody = 0;
              
            /* Now estimate the distance to the level line along each
                 edge and face of the cube, excluding the edges and faces
                 that will be picked up in a following cube */
                 
              
            for ( ii= 0; ii < 3; ii ++ ) {
                /* Do an edge */
                jj = edges[ii][0];
                kk = edges[ii][1];
                if (havemapval[jj]&&havemapval[kk]) {
                  if (!((mapval[jj]>loglevel && mapval[kk]>loglevel)
                    ||(mapval[jj]<loglevel && mapval[kk]<loglevel))){
                    if (valdist[kk] < valdist[jj]) {
                      kk = jj;
                      jj = edges[ii][1];
                    }
                    if (valdist[kk] < 1./250.) {
                      mp.xpos = (xp[jj]+xp[kk])/2;
                      mp.ypos = (yp[jj]+yp[kk])/2;
                      mp.zpos = (zp[jj]+zp[kk])/2;
                      interpolate_map_value(map,mp.xpos,mp.ypos,mp.zpos,1,&dummy,gradient);
                      MapPointm2o(map,mp,gradient);
                      if (mapmask) {
                        if(!interpolate_oc_map_value(mapmask,mp.xpos,mp.ypos,mp.zpos,1,&testlevel)){
                          if (testlevel < masklevel) continue;    
                        }
                        else continue;
                      }
                      mp.col = Shade2Colour(shade);
                      Shade[shade].refcount++;
                      vector_add_element((GenericVec __far *) PointVec,(void __far *)&mp);
                      haveedges[ii] = PointVec->size;
                      if (BondVec  || TangleVec) {
                          int kloc;
                          kloc = PointVec->size;
                          vector_set_element(PointsUsed,&kloc,ii+3*(ix+iy*xpts+zalt*xpts*ypts));
                      }
                    } else {
                      if (!((marked[jj] && valdist[jj]+valdist[kk] > 250*valdist[jj]) ||
                          (marked[kk] && valdist[jj]+valdist[kk] > 250*valdist[kk])) )  {
                          mp.xpos = (xp[jj]*valdist[kk]+xp[kk]*valdist[jj])/(valdist[jj]+valdist[kk]);
                        mp.ypos = (yp[jj]*valdist[kk]+yp[kk]*valdist[jj])/(valdist[jj]+valdist[kk]);
                        mp.zpos = (zp[jj]*valdist[kk]+zp[kk]*valdist[jj])/(valdist[jj]+valdist[kk]);
                        interpolate_map_value(map,mp.xpos,mp.ypos,mp.zpos,1,&dummy,gradient);
                        MapPointm2o(map,mp,gradient);
                        if (mapmask) {
                          if(!interpolate_oc_map_value(mapmask,mp.xpos,mp.ypos,mp.zpos,1,&testlevel)){
                            if (testlevel < masklevel) continue;    
                          }
                          else continue;
                        }
                        mp.col = Shade2Colour(shade);
                        Shade[shade].refcount++;
                        vector_add_element((GenericVec __far *) PointVec,(void __far *)&mp);
                        if ( valdist[jj]+valdist[kk] > 250*valdist[kk]) marked[kk] = PointVec->size;
                        if ( valdist[jj]+valdist[kk] > 250*valdist[jj]) marked[jj] = PointVec->size;
                        haveedges[ii] = PointVec->size;
                        if (BondVec || TangleVec) {
                            int kloc;
                            kloc = PointVec->size;
                            vector_set_element(PointsUsed,&kloc,ii+3*(ix+iy*xpts+zalt*xpts*ypts));
                        }
                      } else {
                        if ((marked[jj] && valdist[jj]+valdist[kk] > 250*valdist[jj]) ) {
                          haveedges[ii] = marked[jj];
                          if (BondVec  || TangleVec) {
                            int kloc;
                            kloc =  haveedges[ii];
                            vector_set_element(PointsUsed,&kloc,ii+3*(ix+iy*xpts+zalt*xpts*ypts));
                          }
                        } else {
                          if ((marked[kk] && valdist[jj]+valdist[kk] > 250*valdist[jj]) ) {
                              haveedges[ii] = marked[kk];
                            if (BondVec || TangleVec) {
                              int kloc;
                              kloc =  haveedges[ii];
                              vector_set_element(PointsUsed,&kloc,ii+3*(ix+iy*xpts+zalt*xpts*ypts));
                            }
                          }
                        }
                      } 
                    }
                  }
                }
              }
            
             
           /* Time to do the bonding 
             
              If we have edges at each end, we just connect each edge in its
              two othogonal directions, or back along a diagonal.
              
              We also connect any pair of edges that have level lines hits.
              
              If we do not have a particular edge, we try for a face,
              containing the direction of travel.
              
                  |              |              |              | 
                  |              |              |              |        
                  y010           y110           y210           y310
                  |              |              |              | 
                  |              |              |              |        
                  *----x010------*----x110------*----x210------*----x310---- 
                 /|             /|             /|             /| 
                / |            / |            / |            / |        
             z010 y000      z110 y100      z210 y200      z310 y300
              /   |          /   |          /   |          /   | 
             /----x011------/----x111------/----x211------/----x311------
                  *----x000------*----x100------*----x200------*----x300---- 
                 /              /              /              / 
                /              /              /              /
               z000           z100           z200           z300
              /              /              /              / 
             /              /              /              / 

        Edges:

          We do three sets of contours:  in the XY plane, in the XZ plane and in the YZ
        plane.  Let use the XZ plane as an example. If x111 is present we could connect it
        to x110 if it is present, or z110 and z210 if x110 is not present and they are.
        Similarly, if z210 is present we can connect it to z110 is it is present, or
        to x111 and x110 if z110 is not present and they are.  Not that this could create
        a duplicate of the z210 -- x111 bond.
  

              
           */
             
            }
            xp[0]=xp[7];
            xp[7]+=spacing;
          }
          yp[0]=yp[7];
          yp[7]+=spacing;
        }

        /* We have completed a Z layer.  If we are doing Bonds and Tangles,
           once we have 2 layers, we can examine cubes and extract contours
           and surfaces */
        
        if (iz >= 1 && BondVec) {
          int square[4];
          int squarebase;
          
          square[0] = square[1] = square[2] = square[3] = squarebase = 0;
            
          for (iy = 0; iy < ypts-1; iy ++) {
            for (ix = 0; ix < xpts-1; ix ++) {
              for (ii=0; ii<3; ii++) {
              
                switch (ii) {
                
                  case (0):  /* Extact the contours in the base layer X-Y plane */
            
                  squarebase= 3*(ix+iy*xpts+(1-zalt)*xpts*ypts);

                  square[0] = ((int *)(PointsUsed->array))[squarebase];       /* bottom X edge in base layer */ 
                  square[1] = ((int *)(PointsUsed->array))[squarebase+1];     /* left Y edge in base layer */ 
                  square[2] = ((int *)(PointsUsed->array))[squarebase+xpts*3];/* top X edge in base layer */ 
                  square[3] = ((int *)(PointsUsed->array))[squarebase+3+1];   /* right Y edge in base layer */ 
            
                  break;

                  case (1):  /* Extact the contours in the X-Z plane */
            
                  squarebase= 3*(ix+iy*xpts+(1-zalt)*xpts*ypts);
                  square[1] = ((int *)(PointsUsed->array))[squarebase+2];     /* left Z edge in base layer */ 
                  square[3] = ((int *)(PointsUsed->array))[squarebase+3+2];   /* right Z edge in top layer */ 
              
                  squarebase= 3*(ix+iy*xpts+zalt*xpts*ypts);
              
                  square[2] = ((int *)(PointsUsed->array))[squarebase];       /* X edge in top layer */ 

                  break;

                  case (2): /* Extact the contours in the Y-Z plane */
              
                  square[2] = ((int *)(PointsUsed->array))[squarebase+1];     /* Y edge in top layer */

                  squarebase= 3*(ix+iy*xpts+(1-zalt)*xpts*ypts);
            
                  square[0] = ((int *)(PointsUsed->array))[squarebase+1];     /* Y edge in base layer */ 
                  square[3] = ((int *)(PointsUsed->array))[squarebase+xpts*3+2];/* top Z edge in base layer */ 
            
                  break;
                }
            
                if (square[0]) {
                  if (square[2]) {
                    mb.src = square[0]-1;
                    mb.dst = square[2]-1;
                    vector_add_element((GenericVec __far *) BondVec,(void __far *)&mb);
                } else {
                  if (square[1]) {
                    mb.src = square[0]-1;
                    mb.dst = square[1]-1;                    
                    vector_add_element((GenericVec __far *) BondVec,(void __far *)&mb);
                  }
                  if (square[3]) {
                      mb.src = square[0]-1;
                    mb.dst = square[3]-1;                    
                    vector_add_element((GenericVec __far *) BondVec,(void __far *)&mb);
                  }
                }    
              } else  {
                if (square[2]) {
                  if (square[1]) {
                      mb.src = square[2]-1;
                    mb.dst = square[1]-1;                    
                    vector_add_element((GenericVec __far *) BondVec,(void __far *)&mb);
                  }
                  if (square[3]) {
                      mb.src = square[2]-1;
                    mb.dst = square[3]-1;                    
                    vector_add_element((GenericVec __far *) BondVec,(void __far *)&mb);
                  }                  
                }
              }
            
              if (square[1]) {
                if (square[3]) {
                    mb.src = square[1]-1;
                  mb.dst = square[3]-1;
                  vector_add_element((GenericVec __far *) BondVec,(void __far *)&mb);
                } else  {
                    if (square[0] && square[2]) {
                      mb.src = square[0]-1;
                    mb.dst = square[1]-1;                    
                    vector_add_element((GenericVec __far *) BondVec,(void __far *)&mb);
                      mb.src = square[2]-1;
                    mb.dst = square[1]-1;                    
                    vector_add_element((GenericVec __far *) BondVec,(void __far *)&mb);                      
                  }
                }    
              } else {
                if (square[3] && square[0] && square[2]) {
                    mb.src = square[0]-1;
                  mb.dst = square[3]-1;                    
                  vector_add_element((GenericVec __far *) BondVec,(void __far *)&mb);
                    mb.src = square[2]-1;
                  mb.dst = square[3]-1;                    
                  vector_add_element((GenericVec __far *) BondVec,(void __far *)&mb);                      
                }
              }
            }
          }
        }    
        }
        
        /* Now for the surfaces.  Our approach is to build lists of points from
           cubes and then to form triangle from triples of edges that are
           at a significant angle from the normals at the vertices and for
           which the vertex normals are not inconsistent.
           
           */
           
          if (iz >= 1 && TangleVec) {
          int cube[12];
          int cubebase;
          int numpoints;
          Real x1[3],x2[3],x3[3],e1[3],e2[3],e3[3];
          Real d1,d2,d3, nd1,nd2,nd3;
          
          for (iy = 0; iy < ypts-1; iy ++) {
            for (ix = 0; ix < xpts-1; ix ++) {
            
              cubebase= 3*(ix+iy*xpts+(1-zalt)*xpts*ypts); /* base layer */
              numpoints = 0;
            
              for (ii=0; ii< 3; ii++) {
                jj=((int *)(PointsUsed->array))[cubebase+ii]; /* pick up X,Y,Z base corner*/
                if (jj) {
                  cube[numpoints]=jj; numpoints++;
                }
              }
              
              cubebase += 3;                                    /* base layer, up in X, pick up Y and Z */
 
              for (ii=1; ii< 3; ii++) {
                jj=((int *)(PointsUsed->array))[cubebase+ii]; 
                if (jj)  {
                  cube[numpoints]=jj; numpoints++;
                }
              }

              cubebase += (-3+xpts*3); /* base layer, up in Y, pick up X and Z */
 
              for (ii=0; ii< 3; ii+=2) {
                jj=((int *)(PointsUsed->array))[cubebase+ii];
                if (jj) {
                  cube[numpoints]=jj; numpoints++;
                }
              }
             
              cubebase += 3;           /* base layer, up in X and Y, pick up Z */
              jj = ((int *)(PointsUsed->array))[cubebase+2];
              if (jj) {
                cube[numpoints]=jj; numpoints++;
              }
              
              cubebase = 3*(ix+iy*xpts+zalt*xpts*ypts);         /* top layer, pick up  X and Y */
              
              for (ii=0; ii< 2; ii++) {
                jj=((int *)(PointsUsed->array))[cubebase+ii];   /* pick up X,Y top corner*/
                if (jj) {
                  cube[numpoints]=jj; numpoints++;
                }
              }

              cubebase += 3;                                    /* top layer, up in X, pick up Y */
              jj = ((int *)(PointsUsed->array))[cubebase+1];
              if (jj) {
                cube[numpoints]=jj; numpoints++;
              }
              
              cubebase += (-3+xpts*3);                          /* top layer, up in Y, pick up X */
              jj = ((int *)(PointsUsed->array))[cubebase];
              if (jj) {
                cube[numpoints]=jj; numpoints++;
              }
          
              if (numpoints > 2) {
                int numtangle;
                numtangle=0;
                for (ii = 0; ii < numpoints-2; ii++) {
                  mt.points[0] = cube[ii]-1;
                  for (jj = ii+1; jj < numpoints-1; jj++) {
                    mt.points[1] = cube[jj]-1;
                    for (kk = jj+1; kk < numpoints; kk++)  {
                      mt.points[2] = cube[kk]-1;
                      if (numpoints > 3)  {
                      x1[0] = (Real)(PointVec->array[mt.points[0]]).xpos;
                      x1[1] = (Real)(PointVec->array[mt.points[0]]).ypos;
                      x1[2] = (Real)(PointVec->array[mt.points[0]]).zpos;
                      x2[0] = (Real)(PointVec->array[mt.points[1]]).xpos;
                      x2[1] = (Real)(PointVec->array[mt.points[1]]).ypos;
                      x2[2] = (Real)(PointVec->array[mt.points[1]]).zpos;
                      x3[0] = (Real)(PointVec->array[mt.points[2]]).xpos;
                      x3[1] = (Real)(PointVec->array[mt.points[2]]).ypos;
                      x3[2] = (Real)(PointVec->array[mt.points[2]]).zpos;
                      vec_diff(e1,x2,x1); vec_diff(e2,x3,x2); vec_diff(e3,x1,x3);
                      vec_dot(d1,e1,e1); vec_dot(d2,e2,e2); vec_dot(d3,e3,e3);
                      d1=sqrt(d1); d2=sqrt(d2); d3=sqrt(d3);
                      /* if (d1 == 0. || d2 == 0. || d3 == 0. ) continue; */
                      vec_dot(nd1,(PointVec->array[mt.points[0]]).Un,(PointVec->array[mt.points[1]]).Un);                  
                      vec_dot(nd2,(PointVec->array[mt.points[1]]).Un,(PointVec->array[mt.points[2]]).Un);                  
                      vec_dot(nd3,(PointVec->array[mt.points[2]]).Un,(PointVec->array[mt.points[0]]).Un);    
                      if (nd1 < -15000000. || nd2 < -15000000. || nd3 < -15000000. ) continue;
                      }
                      vector_add_element((GenericVec __far *) TangleVec,(void __far *)&mt);
                      numtangle++;
                    }
                  }
                }
                /* if (numtangle==0){
                   fprintf(stderr,"failed to use valid cube, numpoints=%d, numtangle=%d\n",numpoints,numtangle);
                  fprintf(stderr,"points: x1={%lg,%lg,%lg}, x1={%lg,%lg,%lg}, x1={%lg,%lg,%lg}\n",
                    x1[0],x1[1],x1[2],x2[0],x2[1],x2[2],x3[0],x3[1],x3[2]);
                  fprintf(stderr,"normals: n1={%ld,%ld,%ld}, n1={%ld,%ld,%ld}, n1={%ld,%ld,%ld}\n",
                    (PointVec->array[mt.points[0]]).Un[0],
                    (PointVec->array[mt.points[0]]).Un[1],
                    (PointVec->array[mt.points[0]]).Un[2],
                    (PointVec->array[mt.points[1]]).Un[0],
                    (PointVec->array[mt.points[1]]).Un[1],
                    (PointVec->array[mt.points[1]]).Un[2],
                    (PointVec->array[mt.points[2]]).Un[0],
                    (PointVec->array[mt.points[2]]).Un[1],
                    (PointVec->array[mt.points[2]]).Un[2]);
                  
                }*/
              }
            }
              
          }
          }

        
        zalt = 1-zalt;
        zp[0]=zp[7];
        zp[7]+=spacing;
      }

   if (BondVec || TangleVec) vector_free(&PointsUsed);
         
   return 0;
    
}
 
 
