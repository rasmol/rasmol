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
 *Bernstein          RasMol 2.7.1   Jun 99         1998-2001               *
 *                   RasMol 2.7.1.1 Jan 01                                 *
 *                   RasMol 2.7.2   Aug 00                                 *
 *                   RasMol 2.7.2.1 Apr 01                                 *
 *                   RasMol 2.7.2.1.1 Jan 04                               *
 *                   RasMol 2.7.3   Feb 05                                 *
 *                   RasMol 2.7.3.1 Apr 06                                 *
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
 *  G. Pozhvanov                         2.7.3 menus and message   Russian *
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
/* maps.h
 */


#ifndef MAPS_H
#define MAPS_H

/* A map structure

   The map is a three dimensional array
      mapdata[xlow:xhigh,ylow:yhigh,zlow:zhigh]
   The origin of the map, mapdata[0,0,0] in RasMol units
     is at [xorig,yorig,zorig]
   The spacing in each direction in RasMol units
     is given by xint, yint, zint

   If map is a pointer to a MapStruct, the location of an element
   mapdata[ix,iy,iz]  at index ix, iy, iz in *map
   is map->mapdata[ix-(map->xlow)+
                   (map->xhigh-map->xlow+1)*(iy-(map->ylow))+
                   (map->xhigh-xlow+1)*(map->yhigh-map->ylow+1)*(iz-((map->zlow))]

   The transform mapm2r, mapxlate is organized so that mapm2r[ii+jj*3] holds
   the (ii,jj) element of the matrix.

   The transform mapr2m is the inverse of mapm2r and is needed for conversion
   of the gradient of non-orthogonal map to a normal of the orthogonal map

 */
typedef struct {
  double * mapdata;          /* mapdata[xlow:xhigh,ylow:yhigh,zlow:zhigh] */
  Long xint, yint, zint;     /* The interval between map segments         */
  Long xorig, yorig, zorig;  /* The origin for the map                    */
  Long xlow, ylow, zlow;     /* The low indices                           */
  Long xhigh, yhigh, zhigh;  /* The high indices                          */
  double mapdatamin;         /* The minimum value in the map              */
  double mapdatamax;         /* The maximum value in the map              */
  double mapdatamean;        /* The average value in the map              */
  double mapm2r[9];          /* The scale matrix from map units to rasmol units  */
  double mapr2m[9];          /* The inverse of the scale matrix           */
  double mapxlate[3];        /* post translation after scale              */
} MapStruct;

#define MapM2R(map,ii,jj) (map)->mapm2r[(ii)+(jj*3)]
#define MapR2M(map,ii,jj) (map)->mapr2m[(ii)+(jj*3)]

typedef struct {
        size_t next;       /* index of the next MapPoint */
        short col;         /* color of the dot           */
        short flag;        /* Database flags             */
        Long xpos;         /* real world x-coordinate    */
        Long ypos;         /* real world y-coordinate    */
        Long zpos;         /* real world z-coordinate    */
        Long Un[3];        /* outward normal*4096        */
        int coordnum;
} MapPoint;
    
#define MapPointm2o(map,mp,gradient) \
  {  double dxpos, dypos, dzpos, glen; \
     dxpos = (map)->mapxlate[0] + MapM2R(map,0,0)*(double)mp.xpos  \
                                + MapM2R(map,0,1)*(double)mp.ypos  \
                                + MapM2R(map,0,2)*(double)mp.zpos; \
     dypos = (map)->mapxlate[1] + MapM2R(map,1,0)*(double)mp.xpos  \
                                + MapM2R(map,1,1)*(double)mp.ypos  \
                                + MapM2R(map,1,2)*(double)mp.zpos; \
     dzpos = (map)->mapxlate[2] + MapM2R(map,2,0)*(double)mp.xpos  \
                                + MapM2R(map,2,1)*(double)mp.ypos  \
                                + MapM2R(map,2,2)*(double)mp.zpos; \
     (mp).xpos = dxpos;   \
     (mp).ypos = dypos;   \
     (mp).zpos = dzpos;   \
     dxpos =  MapR2M(map,0,0)*(gradient)[0] + MapR2M(map,0,1)*(gradient)[1] + MapR2M(map,0,2)*(gradient)[2]; \
     dypos =  MapR2M(map,1,0)*(gradient)[0] + MapR2M(map,1,1)*(gradient)[1] + MapR2M(map,1,2)*(gradient)[2]; \
     dzpos =  MapR2M(map,2,0)*(gradient)[0] + MapR2M(map,2,1)*(gradient)[1] + MapR2M(map,2,2)*(gradient)[2]; \
     glen = sqrt(dxpos*dxpos+dypos*dypos+dzpos*dzpos); \
     if (glen > 0.) {                                  \
       (mp).Un[0] = -(Long)(4096.*(gradient)[0]/glen);   \
       (mp).Un[1] = -(Long)(4096.*(gradient)[1]/glen);   \
       (mp).Un[2] = -(Long)(4096.*(gradient)[2]/glen);   \
     } else {                                          \
       (mp).Un[0] = (mp).Un[1] = (mp).Un[2] = 0;       \
       fprintf(stderr,"zero gradient at xpos, ypos, zpos [%ld,%ld,%ld]\n",mp.xpos, mp.ypos, mp.zpos);\
       fprintf(stderr,"gradient [%lg,%lg,%lg]\n",gradient[0], gradient[1], gradient[2]);\
     }                                                 \
  }


    
typedef struct {
        size_t   src;       /* source map point index       */
        size_t   dst;       /* destination map point index  */
        short    col;       /* Bond Colour                  */
        short    flag;      /* Database flags               */
} MapBond;


typedef struct {
        size_t   points[3]; /* corners of a triangle        */
        short    col;       /* Bond Colour                  */
        short    flag;      /* Database flags               */
} MapTangle;

typedef struct {
        size_t size;             /* size of the vector      */
        size_t capacity;         /* capacity of the vector  */
        size_t elementsize;      /* size of an element      */
        void __far * array;      /* the array of elements  */
} GenericVec;

typedef struct {
        size_t size;             /* size of the vector      */
        size_t capacity;         /* capacity of the vector  */
        size_t elementsize;      /* size of an element      */
        MapPoint __far * array;  /* the array of MapPoints  */
} MapPointVec;


typedef struct {
        size_t size;             /* size of the vector        */
        size_t capacity;         /* capacity of the vector    */
        size_t elementsize;      /* size of an element        */
        MapBond __far * array;   /* the array of MapPoints    */
} MapBondVec;

typedef struct {
        size_t size;             /* size of the vector        */
        size_t capacity;         /* capacity of the vector    */
        size_t elementsize;      /* size of an element        */
        MapTangle __far * array; /* the array of MapPoints    */
} MapTangleVec;


/* Map flags */
#define MapSelectFlag   0x001    /* The indicated map is selected   */
#define MapMarkedFlag   0x002    /* The indicated map is tentatively
                                    marked for selection            */
#define MapNoSelectFlag 0x004    /* Set when no map selector was 
                                    given                           */
#define MapColourPot    0x010    /* Set for colour by potential     */
#define MapPointFlag    0x100    /* Represent map as points         */
#define MapMeshFlag     0x200    /* Represent map as mesh           */
#define MapMeshDashFlag 0x210    /* Represent map as dashed mesh    */
#define MapSurfFlag     0x400    /* Represent map as surface        */
#define MapMeanFlag     0x800    /* Map level relative to MEAN      */

typedef struct {
        Real              MapLevel;    /* map level for this map     */
        Long              MapPointRad; /* radius for map points      */
        Long              MapMeshRad;  /* radius for map mesh lines  */
        Long              MapSpacing;  /* spacing for this map       */
        Real              MapSpread;   /* spread used to generate    */
        Long              flag;        /* flags for this map         */
        int               MapRGBCol[3];/* map RGB color              */
        char*             MapLabel;    /* label for this map         */
        char*             MapFile;     /* path of map file loaded    */
        char*             MapSelection;/* map generation selection   */
        MapTangleVec __far 
                          *MapTanglePtr;/* Data for the surface rep  */
        MapPointVec __far *MapPointsPtr;/* Data for the points rep   */
        MapBondVec  __far *MapBondsPtr;	/* Data for the mesh rep     */
        MapStruct   __far *MapPtr;      /* The map itself            */
        MapStruct   __far *MapMaskPtr;  /* Map to be used as a mask  */
} MapInfo;


typedef struct {
        size_t size;             /* size of the vector        */
        size_t capacity;         /* capacity of the vector    */
        size_t elementsize;      /* size of an element        */
        MapInfo __far * array;   /* the array of MapPoints    */
} MapInfoVec;


#ifdef MAPS
Real               MapLevel;           /* global map level     */
Long               MapMeshRad;         /* global radius for 
                                               map mesh lines  */
Long               MapPointRad;        /* global radius for 
                                               map points      */
Long               MapSpacing;         /* global map spacing   */
Real               MapSpread;          /* global map spread    */
Long               MapFlag;            /* global map flags     */
int                MapRGBCol[3];       /* global map color     */
Card               MapRadius;          /* global map radius    */
char*              MapLabel;           /* global map label     */
MapInfoVec  __far *MapInfoPtr;         /* vector of maps       */
#else
extern Real               MapLevel;    /* global map level     */
extern Long               MapMeshRad;  /* global radius for 
                                               map mesh lines  */
extern Long               MapPointRad; /* global radius for 
                                               map points      */
extern Long               MapSpacing;  /* global map spacing   */
extern Real               MapSpread;   /* global map spread    */
extern Long               MapFlag;     /* global map flags     */
extern int                MapRGBCol[3];/* global map color     */
extern Card               MapRadius;   /* global map radius    */
extern char*              MapLabel;    /* global map label     */
extern MapInfoVec  __far *MapInfoPtr;  /* vector of maps       */
#endif

/* Initialise Maps */

void InitialiseMaps( void);

/* Delete Maps */

void DeleteMaps( void );

/* Delete Map */

void DeleteMap( int, int );

/* DeleteAllMaps */

void DeleteAllMaps( void );



/* vector_create -- create a generic vector */

int vector_create(GenericVec __far * __far * vector, size_t elementsize, size_t capacity);

/*  vector_add_element -- add an element to a generic vector */

int vector_add_element(GenericVec __far * vector, void __far * element);

/* vector_get_element -- get a copy of an element from a generic vector */

int vector_get_element(GenericVec __far * vector, void __far * element, int index);

/* vector_get_elementptr -- get a pointer to an element from a generic vector */

int vector_get_elementptr(GenericVec __far * vector, void __far ** elementptr, int index);

/* vector_set_element -- set a copy of an element into a generic vector */

int vector_set_element(GenericVec __far * vector, void __far * element, int index);

/* vector_free -- remove a generic vector */

int vector_free(GenericVec __far * __far * vector);



/* MapReRadius -- recalculate the maximum map radius */

void MapReRadius( void );

/* LoadMapFile -- load a map file */

int LoadMapFile( FILE *fp, int info, int mapno );


                   
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
                            Long buffer, double sig_per_rad);
                            
                            
/* Interpolate a map value from map at position [xpos,ypos,zpos]
   If uselog is nonzero, the interpolation is done against the
   logarithms of the map values and the value returned is the
   logoarithm of the interpolated value.
   
   If gradient is not null, {gradient[0], gradient[1], gradient[2]}
   is set to the gradient (uphill vector)
   
   The value is returned in value.  The function returns 0
   for success, -1 if the point is outside of the map.
                                                              */

int interpolate_map_value(MapStruct __far *map, 
                               Long xpos, Long ypos, Long zpos, 
                               int uselog, double * value, double * gradient);
                               
/*  map_points --  Find the points in a map at a given level with a given
                   spacing and adds them to the PointVec list of dots
                   
                   If MapBondsPtr is not NULL, map bonds will be added
                   to that list of bonds
 
 */
 
int map_points(MapStruct *map, double level, Long spacing, 
      MapPointVec __far *PointVec, MapBondVec __far *BondVec,
      MapTangleVec __far *TangleVec,
      int RGBCol[3] ); 

#endif



