/***************************************************************************
 *                              RasMol 2.7.5                               *
 *                                                                         *
 *                                 RasMol                                  *
 *                 Molecular Graphics Visualisation Tool                   *
 *                              13 June 2009                                *
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
  void * mapdata;            /* mapdata[xlow:xhigh,ylow:yhigh,zlow:zhigh] */
  int elsize;                /* size of element in chars                  */
  int eltype;                /* CBF_INTEGER or CBF_FLOAT                  */
  int maptype;               /* MAP_ORTHOGONAL or MAP_FRACTIONAL          */
  int adiv, bdiv, cdiv;      /* number of a,b,c grid divisions            */
  long xint, yint, zint;     /* The interval between map segments         */
  long xorig, yorig, zorig;  /* The origin for the map                    */
  long xlow, ylow, zlow;     /* The low indices                           */
  long xhigh, yhigh, zhigh;  /* The high indices                          */
  double mapdatamin;         /* The minimum value in the map              */
  double mapdatamax;         /* The maximum value in the map              */
  double mapdatamean;        /* The average value in the map              */
  double mapdataesd;         /* The average value esd in the map          */
  double mapm2r[9];          /* The xform matrix from map units to rasmol units  */
  double mapr2m[9];          /* The inverse of the mapm2r                 */
  double mapxlate[3];        /* post translation after mapm2r             */
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

                     
#define MapEldouble(map,ix,iy,iz)  ((double*)((map)->mapdata))[(ix)-((map)->xlow) +               \
                   ((map)->xhigh-(map)->xlow+1)*((iy)-((map)->ylow)) +         \
                   ((map)->xhigh-(map)->xlow+1)*((map)->yhigh-(map)->ylow+1)*((iz)-((map)->zlow))]
#define MapElfloat(map,ix,iy,iz)  ((float*)((map)->mapdata))[(ix)-((map)->xlow) +               \
                   ((map)->xhigh-(map)->xlow+1)*((iy)-((map)->ylow)) +         \
                   ((map)->xhigh-(map)->xlow+1)*((map)->yhigh-(map)->ylow+1)*((iz)-((map)->zlow))]
#define MapElint(map,ix,iy,iz)  ((int*)((map)->mapdata))[(ix)-((map)->xlow) +               \
                   ((map)->xhigh-(map)->xlow+1)*((iy)-((map)->ylow)) +         \
                   ((map)->xhigh-(map)->xlow+1)*((map)->yhigh-(map)->ylow+1)*((iz)-((map)->zlow))]
#define MapEllong(map,ix,iy,iz)  ((long*)((map)->mapdata))[(ix)-((map)->xlow) +               \
                   ((map)->xhigh-(map)->xlow+1)*((iy)-((map)->ylow)) +         \
                   ((map)->xhigh-(map)->xlow+1)*((map)->yhigh-(map)->ylow+1)*((iz)-((map)->zlow))]
#define MapElshort(map,ix,iy,iz)  ((short*)((map)->mapdata))[(ix)-((map)->xlow) +               \
                   ((map)->xhigh-(map)->xlow+1)*((iy)-((map)->ylow)) +         \
                   ((map)->xhigh-(map)->xlow+1)*((map)->yhigh-(map)->ylow+1)*((iz)-((map)->zlow))]
#define MapElchar(map,ix,iy,iz)  ((char*)((map)->mapdata))[(ix)-((map)->xlow) +               \
                   ((map)->xhigh-(map)->xlow+1)*((iy)-((map)->ylow)) +         \
                   ((map)->xhigh-(map)->xlow+1)*((map)->yhigh-(map)->ylow+1)*((iz)-((map)->zlow))]

#define Mapm2o(map,mxpos,mypos,mzpos,oxpos,oypos,ozpos) \
     oxpos = (map)->mapxlate[0] + MapM2R(map,0,0)*(double)mxpos  \
                                + MapM2R(map,0,1)*(double)mypos  \
                                + MapM2R(map,0,2)*(double)mzpos; \
     oypos = (map)->mapxlate[1] + MapM2R(map,1,0)*(double)mxpos  \
                                + MapM2R(map,1,1)*(double)mypos  \
                                + MapM2R(map,1,2)*(double)mzpos; \
     ozpos = (map)->mapxlate[2] + MapM2R(map,2,0)*(double)mxpos  \
                                + MapM2R(map,2,1)*(double)mypos  \
                                + MapM2R(map,2,2)*(double)mzpos;

    
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
     (mp).Un[0] = (mp).Un[1] = (mp).Un[2] = 0; \
     if (gradient)      { \
     dxpos =  MapR2M(map,0,0)*(gradient)[0] + MapR2M(map,0,1)*(gradient)[1] + MapR2M(map,0,2)*(gradient)[2]; \
     dypos =  MapR2M(map,1,0)*(gradient)[0] + MapR2M(map,1,1)*(gradient)[1] + MapR2M(map,1,2)*(gradient)[2]; \
     dzpos =  MapR2M(map,2,0)*(gradient)[0] + MapR2M(map,2,1)*(gradient)[1] + MapR2M(map,2,2)*(gradient)[2]; \
     glen = sqrt(dxpos*dxpos+dypos*dypos+dzpos*dzpos); \
     if (glen > 0.) {                                  \
       (mp).Un[0] = -(Long)(4095.*(dxpos/glen)); \
       (mp).Un[1] = -(Long)(4095.*(dypos/glen)); \
       (mp).Un[2] = -(Long)(4095.*(dzpos/glen)); \
     } \
     } \
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


typedef struct {
        Long   loserno;           /* start of selected range  */
        Long   hiserno;           /* end of selected range    */
        int    radius;            /* 0 for VWD or value       */
} MapAtmSel;

typedef struct {
        size_t size;             /* size of the vector      */
        size_t capacity;         /* capacity of the vector  */
        size_t elementsize;      /* size of an element      */
        MapAtmSel __far * array; /* the array of selections */
} MapAtmSelVec;


/* Map flags */
#define MapSelectFlag   0x001    /* The indicated map is selected   */
#define MapMarkedFlag   0x002    /* The indicated map is tentatively
                                    marked for selection            */
#define MapNoSelectFlag 0x004    /* Set when no map selector was 
                                    given                           */
#define MapColourPot    0x010    /* Set for colour by potential     */
#define MapColourAtom   0x020    /* Set for colour by nearest atom  */
#define MapPointFlag    0x100    /* Represent map as points         */
#define MapMeshFlag     0x200    /* Represent map as mesh           */
#define MapMeshDashFlag 0x210    /* Represent map as dashed mesh    */
#define MapSurfFlag     0x400    /* Represent map as surface        */
#define MapMeanFlag     0x800    /* Map level relative to MEAN      */
#define MapScaleFlag    0x1000   /* Map scaled to atomic no. Z      */
#define MapLRSurfFlag   0x2000   /* Map with Lee-Richards approx    */  
#define MAP_ORTHOGONAL  0x000    /* Orthogonal map coordinates      */
#define MAP_FRACTIONAL  0x001    /* Fractional map coordinates      */

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
        MapAtmSelVec __far
                          *MapGenSel;  /* map generation selection   */
        MapTangleVec __far 
                          *MapTanglePtr;/* Data for the surface rep  */
        MapPointVec __far *MapPointsPtr;/* Data for the points rep   */
        MapBondVec  __far *MapBondsPtr;	/* Data for the mesh rep     */
        MapStruct   __far *MapPtr;      /* The map itself            */
        MapStruct   __far *MapMaskPtr;  /* Map to be used as a mask  */
        MapAtmSelVec __far
                          *MapMaskGenSel;  /* map mask generation selection   */
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
MapStruct   __far *MapMaskPtr;         /* Map to be used as a mask  */
MapAtmSelVec __far
                  *MapMaskGenSel;      /* map mask generation selection   */
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
extern MapStruct   __far *MapMaskPtr;  /* Map to be used as a mask  */
extern MapAtmSelVec __far
                      *MapMaskGenSel;  /* map mask generation selection   */
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

int vector_get_element(GenericVec __far * vector, void __far * element, size_t index);

/* vector_get_elementptr -- get a pointer to an element from a generic vector */

int vector_get_elementptr(GenericVec __far * vector, void __far ** elementptr, size_t index);

/* vector_set_element -- set a copy of an element into a generic vector */

int vector_set_element(GenericVec __far * vector, void __far * element, size_t index);

/* vector_free -- remove a generic vector */

int vector_free(GenericVec __far * __far * vector);



/* MapReRadius -- recalculate the maximum map radius */

void MapReRadius( void );


/* SaveMapFile -- save a map file */

int SaveMapFile( FILE *fp, int info, int mapno );


/* LoadCBFMapFile -- load a CBF map file */

int LoadCBFMapFile( FILE *fp, int info, int mapno );


/* LoadCCP4MapFile -- load a map file */

int LoadCCP4MapFile( FILE *fp, int info, int mapno );


                   
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
   
   sig_per_rad is the reciprocal of the spread.
   
   */
   
int generate_map(MapStruct **map, 
                            Long xint, Long yint, Long zint,
                            Long xorig, Long yorig, Long zorig,
                            Long buffer, double sig_per_rad,
                            int ScaletoAN);
                            
                            
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
                               int uselog, double * value );

                               
/*  map_points --  Find the points in a map at a given level with a given
                   spacing and adds them to the PointVec list of dots
                   
                   If MapBondsPtr is not NULL, map bonds will be added
                   to that list of bonds
 
 */
 
int map_points(MapStruct *map, double level, Long spacing, 
      MapPointVec __far *PointVec, MapBondVec __far *BondVec,
      MapTangleVec __far *TangleVec, MapStruct __far *mapmask,
      int RGBCol[3] ); 

#endif



