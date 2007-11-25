/***************************************************************************
 *                              RasMol 2.7.4                               *
 *                                                                         *
 *                                 RasMol                                  *
 *                 Molecular Graphics Visualisation Tool                   *
 *                              18 May 2007                                *
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
 *Bernstein          RasMol 2.7.1   Jun 99         1998-2007               *
 *                   RasMol 2.7.1.1 Jan 01                                 *
 *                   RasMol 2.7.2   Aug 00                                 *
 *                   RasMol 2.7.2.1 Apr 01                                 *
 *                   RasMol 2.7.2.1.1 Jan 04                               *
 *                   RasMol 2.7.3   Feb 05                                 *
 *                   RasMol 2.7.3.1 Apr 06                                 *
 *                   RasMol 2.7.4   Nov 07                                 *
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
 *               Copyright(C) Herbert J. Bernstein 1998-2007               *
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

int LoadMapFile( FILE *fp, int info, int mapno )
{

    MapInfo mapinfo;
    MapStruct * map;
          

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

    double * mapdata;
    double datasq;
    unsigned char * bytemapdata;
    MapStruct __far *mapmaskptr;
    MapAtmSelVec __far *mapmaskgensel;
    register Long xel, yel, zel;

    
    cbf_file *mapfile;
    int i,ii;
    char buffer[80];

    if (!MapInfoPtr) InitialiseMaps();
    if (MapSpacing <= 0) MapSpacing = 125L;
  
    /* Initialize a mapinfo struct */
  
    mapinfo.MapLevel = MapLevel;
    mapinfo.MapLabel = NULL;          /* clear the map label */
    mapinfo.MapSpacing = MapSpacing;
    if (MapSpread < 0.1) MapSpread = 2.*((double)MapSpacing)/750.;
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
    
    cbf_failnez(cbf_get_integer(mapfile,&NCRS[0],0,32))       /*   1 */
    cbf_failnez(cbf_get_integer(mapfile,&NCRS[1],0,32))       /*   2 */
    cbf_failnez(cbf_get_integer(mapfile,&NCRS[2],0,32))       /*   3 */
    cbf_failnez(cbf_get_integer(mapfile,&MODE,0,32))          /*   4 */
    cbf_failnez(cbf_get_integer(mapfile,&NCRSSTART[0],0,32))  /*   5 */
    cbf_failnez(cbf_get_integer(mapfile,&NCRSSTART[1],0,32))  /*   6 */
    cbf_failnez(cbf_get_integer(mapfile,&NCRSSTART[2],0,32))  /*   7 */
    cbf_failnez(cbf_get_integer(mapfile,&NXYZ[0],0,32))       /*   8 */
    cbf_failnez(cbf_get_integer(mapfile,&NXYZ[1],0,32))       /*   9 */
    cbf_failnez(cbf_get_integer(mapfile,&NXYZ[2],0,32))       /*  10 */
    cbf_failnez(cbf_get_integer(mapfile,(int *)&(XYZ[0]),0,32))/*  11 */
    cbf_failnez(cbf_get_integer(mapfile,(int *)&(XYZ[1]),0,32))/*  12 */
    cbf_failnez(cbf_get_integer(mapfile,(int *)&(XYZ[2]),0,32))/*  13 */
    cbf_failnez(cbf_get_integer(mapfile,(int *)&alpha,0,32))  /*  14 */
    cbf_failnez(cbf_get_integer(mapfile,(int *)&beta,0,32))   /*  15 */
    cbf_failnez(cbf_get_integer(mapfile,(int *)&gamma,0,32))  /*  16 */
    cbf_failnez(cbf_get_integer(mapfile,&MAP_CRS[0],0,32))    /*  17 */
    cbf_failnez(cbf_get_integer(mapfile,&MAP_CRS[1],0,32))    /*  18 */
    cbf_failnez(cbf_get_integer(mapfile,&MAP_CRS[2],0,32))    /*  19 */
    cbf_failnez(cbf_get_integer(mapfile,(int *)&AMIN,0,32))   /*  20 */
    cbf_failnez(cbf_get_integer(mapfile,(int *)&AMAX,0,32))   /*  21 */
    cbf_failnez(cbf_get_integer(mapfile,(int *)&AMEAN,0,32))  /*  22 */
    cbf_failnez(cbf_get_integer(mapfile,&ISPG,0,32))          /*  23 */
    cbf_failnez(cbf_get_integer(mapfile,&NSYMBT,0,32))        /*  24 */
    cbf_failnez(cbf_get_integer(mapfile,&LSKFLG,0,32))        /*  25 */
    
    for (ii=0; ii<9; ii++) {                                  /*  26 -- 34 */
      cbf_failnez(cbf_get_integer(mapfile,(int *)(SKWMAT+ii),0,32)) 	
    }

    for (ii=0; ii<3; ii++) {                                  /*  35 -- 37 */
      cbf_failnez(cbf_get_integer(mapfile,(int *)(SKWTRAN+ii),0,32)) 	
    }
    
    for (ii=38; ii<53; ii++) {                                /*  38 -- 52 */
      cbf_failnez(cbf_get_integer(mapfile,&DUMMY,0,32)) 	
    }
    
    for (ii=0; ii<4; ii++) {                                  /*  53 */
      cbf_failnez(cbf_get_integer(mapfile,(int *)(MAP+ii),0,8)) 
    }

    for (ii=0; ii<4; ii++) {                                  /*  54 */
      cbf_failnez(cbf_get_integer(mapfile,(int *)(MACHST+ii),0,8)) 
    }
    
    cbf_failnez(cbf_get_integer(mapfile,(int *)&ARMS,0,32))   /*  55 */
    cbf_failnez(cbf_get_integer(mapfile,&NLABL,0,32))         /*  56 */

    for (ii=0; ii<800; ii++) {                                /*  57 -- 256 */                          
      cbf_failnez(cbf_get_integer(mapfile,(int *)(LABEL+ii),0,8)) 
    }
    
    NSYMBT = (NSYMBT+79)/80;

    for (ii=0; ii<NSYMBT; ii++) {                     /* 257 -- 256+(NSYMBT/4) */
      cbf_failnez(cbf_get_integer(mapfile,&DUMMY,0,8)) 
    }
   
    map = (MapStruct*)_fmalloc(sizeof(MapStruct));
    
    if (!map) return 1;
    
    AXIS_XYZ[MAP_CRS[0]-1] = 0;
    AXIS_XYZ[MAP_CRS[1]-1] = 1;
    AXIS_XYZ[MAP_CRS[2]-1] = 2;
    
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
    (map)->mapxlate[1] = -(250.*Info.vecf2o[0])-OrigCY;
#else
    (map)->mapxlate[1] = 250.*Info.vecf2o[0]-OrigCY;
#endif
    (map)->mapxlate[2] = -(250.*Info.vecf2o[0])-OrigCZ;
    
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

    /* ** ALLOCATE AND MAP THE DATA ITSELF ** */
    
    if (MODE == 2)  {
      float temp;
      cbf_failnez(cbf_alloc((void **)&mapdata, NULL, 8, NCRS[0]*NCRS[1]*NCRS[2]))
      (map)->mapdata = (double *)mapdata;
      for (ID[2] = 0; ID[2] < NCRS[2]; ID[2]++)
        for (ID[1] = 0; ID[1] < NCRS[1]; ID[1]++)
          for (ID[0] = 0; ID[0] < NCRS[0]; ID[0]++) {
            cbf_failnez(cbf_get_integer(mapfile,(int *)&temp,0,32))
            /* fprintf(stderr,"mapel[%d,%d,%d] = %f\n",ID[AXIS_XYZ[0]],ID[AXIS_XYZ[1]],ID[AXIS_XYZ[2]],temp); */
            MapEl(map,ID[AXIS_XYZ[0]],ID[AXIS_XYZ[1]],ID[AXIS_XYZ[2]]) = (double)temp;
            datasq += ((double)temp)*((double)temp);
          }
      
    } else if (MODE == 0) 
    {
      int bytetemp;
      cbf_failnez(cbf_alloc((void **)&bytemapdata, NULL, 1, NCRS[0]*NCRS[1]*NCRS[2]))    
      (map)->mapdata = (double *)bytemapdata;
      for (ID[2] = 0; ID[2] < NCRS[2]; ID[2]++)
        for (ID[1] = 0; ID[1] < NCRS[1]; ID[1]++)
          for (ID[0] = 0; ID[0] < NCRS[0]; ID[0]++) {
            cbf_failnez(cbf_get_integer(mapfile,(int *)&bytetemp,0,8))
            MapEl(map,ID[AXIS_XYZ[0]],ID[AXIS_XYZ[1]],ID[AXIS_XYZ[2]]) = bytetemp;
            datasq += (double)(bytetemp*bytetemp); 
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
      mapmaskptr->mapdata = (double *)_fmalloc(sizeof(double)*
       (MapMaskPtr->xhigh-MapMaskPtr->xlow+1)*
       (MapMaskPtr->yhigh-MapMaskPtr->ylow+1)*
       (MapMaskPtr->zhigh-MapMaskPtr->zlow+1));
     if(!mapmaskptr->mapdata) {
       _ffree(mapmaskptr);
       CommandError(MsgStrs[StrMalloc]);
       return 1;
     }
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
     for (xel=(mapmaskptr)->xlow; xel<=(mapmaskptr)->xhigh; xel++ )
       for (yel=(mapmaskptr)->ylow; yel<=(mapmaskptr)->yhigh; yel++  )
         for (zel=(mapmaskptr)->zlow; zel<=(mapmaskptr)->zhigh; zel++ )
           MapEl(mapmaskptr,xel,yel,zel)=MapEl(MapMaskPtr,xel,yel,zel);
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

    map_points(mapinfo.MapPtr, 
    mapinfo.MapLevel+((mapinfo.flag&MapMeanFlag)?mapinfo.MapPtr->mapdatamean:0), 
    mapinfo.MapSpacing, mapinfo.MapPointsPtr,mapinfo.MapBondsPtr,mapinfo.MapTanglePtr,
    mapinfo.MapMaskPtr, mapinfo.MapRGBCol );

    if (mapno < 0)
    vector_add_element((GenericVec __far *)MapInfoPtr,(void __far *)&mapinfo);
    else
    vector_set_element((GenericVec __far *)MapInfoPtr,(void __far *)&mapinfo,mapno);
    
    mapinfo.MapFile = (char __far *)_fmalloc(strlen(DataFileName)+1);
    strcpy(mapinfo.MapFile,DataFileName);

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
   
   if (!(*vector)) return -1;
   
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
   return -1;
}


/*  vector_add_element -- add an element to a generic vector */

int vector_add_element(GenericVec __far * vector, void __far * element) {
   
   if (!(vector)) return -1;
   
   if (vector->size >= vector->capacity) {
   
     void __far * temparray;
     
     temparray = _fmalloc(vector->capacity*vector->elementsize*2);
     if (!temparray) return -1;
     if (vector->size)    
       memmove((char *)temparray, (char *)vector->array, vector->size*vector->elementsize);
     _ffree(vector->array);
     vector->array = temparray;
     vector->capacity *=2;
   }
   
   memmove(((char *)(vector->array))+vector->size*vector->elementsize,
     (char *)element, vector->elementsize);
   vector->size ++;
   return 0;

}

/* vector_get_element -- get a copy of an element from a generic vector */

int vector_get_element(GenericVec __far * vector, void __far * element, int index) {

  if (index >= 0 && index < vector->size) {
  
    memmove((char *)element,((char *)(vector->array))+index*vector->elementsize,
      vector->elementsize);
      
    return 0;
  	
  } else {
  	
  	return -1;
  }
	
}


/* vector_get_elementptr -- get a pointer to an element from a generic vector */

int vector_get_elementptr(GenericVec __far * vector, void __far ** elementptr, int index) {

  if (index >= 0 && index < vector->size) {
  
    *elementptr = (void __far*)(((char *)(vector->array))+index*vector->elementsize);
      
    return 0;
  	
  } else {
  	
  	return -1;
  }
	
}


/* vector_set_element -- set a copy of an element into a generic vector */

int vector_set_element(GenericVec __far * vector, void __far * element, int index) {

  if (index >= vector->capacity) {

     void __far * temparray;
     
     temparray = _fmalloc((index+vector->capacity)*vector->elementsize);
     if (!temparray) return -1;
     if (vector->size)    
       memmove((char *)temparray, (char *)vector->array, vector->size*vector->elementsize);
     _ffree(vector->array);
     vector->array = temparray;
     vector->capacity += index;
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
   at 4.5 sigma.  The Gaussian is scaled to the atomic number.
   
   */
   
int generate_map(MapStruct **map, 
                            Long xint, Long yint, Long zint,
                            Long xorig, Long yorig, Long zorig,
                            Long buffer, double sig_per_rad) {

    register Chain __far *chain;
    register Group __far *group;
    register RAtom __far *ptr;
    register Long xsellow,xselhigh,ysellow,yselhigh,zsellow,zselhigh;
    register Long xel, yel, zel;
    register int radius;
    size_t mapcount;
    double test;
    int ii, jj;
    
    double pi,sqrt2pi3;
    
    pi = 4.*atan2(1.,1.);
    
    sqrt2pi3 = 2.*pi*sqrt(2.*pi);
    
    
    /* First intialize the map */
    
    *map = (MapStruct*)_fmalloc(sizeof(MapStruct));
    
    if (!*map) return 1;
    
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

        radius = ptr->radius;
        if (radius < 10) radius = Element[ptr->elemno].vdwrad;

      
        if (ptr->xorg+ptr->fxorg-radius-ProbeRadius<xsellow)
          xsellow = ptr->xorg+ptr->fxorg-radius-ProbeRadius;
        if (ptr->yorg+ptr->fyorg-radius-ProbeRadius<ysellow)
          ysellow = ptr->yorg+ptr->fyorg-radius-ProbeRadius;
        if (ptr->zorg+ptr->fzorg-radius-ProbeRadius<zsellow)
          zsellow = ptr->zorg+ptr->fzorg-radius-ProbeRadius;
        
        if (ptr->xorg+ptr->fxorg+radius+ProbeRadius>xselhigh)
          xselhigh = ptr->xorg+ptr->fxorg+radius+ProbeRadius;
        if (ptr->yorg+ptr->fyorg+radius+ProbeRadius>yselhigh)
          yselhigh = ptr->yorg+ptr->fyorg+radius+ProbeRadius;
        if (ptr->zorg+ptr->fzorg+radius+ProbeRadius>zselhigh)
          zselhigh = ptr->zorg+ptr->fzorg+radius+ProbeRadius;    	
      }
      
      xsellow -= buffer;
      ysellow -= buffer;
      zsellow -= buffer;
      
      xselhigh += buffer;
      yselhigh += buffer;
      zselhigh += buffer;
      
      (*map)->xlow = xsellow-xorig;
      if ((*map)->xlow< 0) (*map)->xlow = ( (*map)->xlow - (xint-1) )/xint;
      else (*map)->xlow = ( (*map)->xlow + (xint-1) )/xint;

      (*map)->ylow = ysellow-yorig;
      if ((*map)->ylow< 0) (*map)->ylow = ( (*map)->ylow - (yint-1) )/yint;
      else (*map)->ylow = ( (*map)->ylow + (yint-1) )/yint;

      (*map)->zlow = zsellow-zorig;
      if ((*map)->zlow< 0) (*map)->zlow = ( (*map)->zlow - (zint-1) )/zint;
      else (*map)->zlow = ( (*map)->zlow + (zint-1) )/zint;
 
      (*map)->xhigh = xselhigh-xorig;
      (*map)->xhigh = ( (*map)->xhigh + (xint-1) )/xint;

      (*map)->yhigh = yselhigh-yorig;
      (*map)->yhigh = ( (*map)->yhigh + (yint-1) )/yint;

      (*map)->zhigh = zselhigh-zorig;
      (*map)->zhigh = ( (*map)->zhigh + (zint-1) )/zint;
      
      (*map)->mapdata = (double *)_fmalloc(sizeof(double)*
      ((*map)->xhigh-(*map)->xlow+1)*
      ((*map)->yhigh-(*map)->ylow+1)*
      ((*map)->zhigh-(*map)->zlow+1));
      
      if (!(*map)->mapdata) {
      	_ffree(*map);
        *map = NULL;
        return 1;
      }
      
      for (xel=(*map)->xlow; xel<=(*map)->xhigh; xel++ )
        for (yel=(*map)->ylow; yel<=(*map)->yhigh; yel++  )
          for (zel=(*map)->zlow; zel<=(*map)->zhigh; zel++ )
            MapEl((*map),xel,yel,zel) = 0.;
      

    /* Scan each selected atom and add its contributions to the
       points in the map */
       
    ForEachAtom 
      if (ptr->flag&SelectFlag ){
      
        Long xpos, ypos, zpos;
        
        Long rad;
        
        Long sig6;
        
        double sig, coeff;
        
        radius = ptr->radius;
        if (radius < 10) radius = Element[ptr->elemno].vdwrad;
        
        rad = radius + ProbeRadius;
        
        sig = ((double)rad)/sig_per_rad;
        
        sig6 = (Long)(6* sig);
        
        sig /= 250.;
        
        coeff = 1/(sig*sig*sig*sqrt2pi3);
        
        xpos = ptr->xorg + ptr->fxorg - xorig;
        ypos = ptr->yorg + ptr->fyorg - yorig;
        zpos = ptr->zorg + ptr->fzorg - zorig;
        
        xsellow = xpos - sig6;
        if (xsellow< 0) xsellow = ( xsellow - (xint-1) )/xint;
        else xsellow = ( xsellow + (xint-1) )/xint;
        if (xsellow < (*map)->xlow) xsellow = (*map)->xlow;
        if (xsellow > (*map)->xhigh) xsellow = (*map)->xhigh;
        ysellow = ypos - sig6;
        if (ysellow< 0) ysellow = ( ysellow - (yint-1) )/yint;
        else ysellow = ( ysellow + (yint-1) )/yint;
        if (ysellow < (*map)->ylow) ysellow = (*map)->ylow;
        if (ysellow > (*map)->yhigh) ysellow = (*map)->yhigh;
        zsellow = zpos - sig6;
        if (zsellow< 0) zsellow = ( zsellow - (zint-1) )/zint;
        else zsellow = ( zsellow + (zint-1) )/zint;
        if (zsellow < (*map)->zlow) zsellow = (*map)->zlow;
        if (zsellow > (*map)->zhigh) zsellow = (*map)->zhigh;

        xselhigh = xpos + sig6;
        if (xselhigh< 0) xselhigh = ( xselhigh - (xint-1) )/xint;
        else xselhigh = ( xselhigh + (xint-1) )/xint;
        if (xselhigh < (*map)->xlow) xselhigh = (*map)->xlow;
        if (xselhigh > (*map)->xhigh) xselhigh = (*map)->xhigh;
        yselhigh = ypos + sig6;
        if (yselhigh< 0) yselhigh = ( yselhigh - (yint-1) )/yint;
        else yselhigh = ( yselhigh + (yint-1) )/yint;
        if (yselhigh < (*map)->ylow) yselhigh = (*map)->ylow;
        if (yselhigh > (*map)->yhigh) yselhigh = (*map)->yhigh;
        zselhigh = zpos + sig6;
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
            
            	 MapEl((*map),xel,yel,zel) += ((double)(ptr->elemno)*coeff*exp(-distsq/(2.*sig*sig)));
            	 
            	 /* fprintf (stderr,"MapEl(%ld,%ld,%ld) = %g\n",xel,yel,zel,MapEl((*map),xel,yel,zel)); */
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
            test = MapEl((*map),xel,yel,zel);
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
        (*map)->mapxlate[ii] = 0;
        for (jj=0; jj< 3; jj++) {
          MapM2R(*map,ii,jj) = MapR2M(*map,ii,jj)= (ii==jj?1.:0.);
        }
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
    
  
  mapval[0] = MapEl(map,xp[0]  ,yp[0]  ,zp[0] );
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

  mapval[1] = MapEl(map,xp[0]  ,yp[0]  ,zp[7] );
  mapval[2] = MapEl(map,xp[0]  ,yp[7]  ,zp[0] );
  mapval[3] = MapEl(map,xp[0]  ,yp[7]  ,zp[7] );
  mapval[4] = MapEl(map,xp[7]  ,yp[0]  ,zp[0] );
  mapval[5] = MapEl(map,xp[7]  ,yp[0]  ,zp[7] );
  mapval[6] = MapEl(map,xp[7]  ,yp[7]  ,zp[0] );
  mapval[7] = MapEl(map,xp[7]  ,yp[7]  ,zp[7] );

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
      
      mp.next = NULL;
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
            	jj=((int *)(PointsUsed->array))[cubebase+ii]; /* pick up X,Y top corner*/
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
                if (numtangle==0){
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
            	
                }
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
 
 
