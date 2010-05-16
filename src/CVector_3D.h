/*
 *  CVector_3D.h
 *  CVector_3D
 *
 *  C-version of vector_3d based on LCA vector_3d.cpp and vector_3d.h
 *  Which in turn is based on VECTOR.FOR
 *  Copyright 1990, 2005 Lawrence C. Andrews
 *  C version, Created by Herbert J. Bernstein on 3/18/10.
 *  Copyright 2010 Herbert J. Bernstein. All rights reserved.
 *
 */

/**********************************************************************
 *                                                                    *
 * YOU MAY REDISTRIBUTE THE CVector_3D API UNDER THE TERMS OF THE LGPL   *
 *                                                                    *
 **********************************************************************/

/************************* LGPL NOTICES *******************************
 *                                                                    *
 * This library is free software; you can redistribute it and/or      *
 * modify it under the terms of the GNU Lesser General Public         *
 * License as published by the Free Software Foundation; either       *
 * version 2.1 of the License, or (at your option) any later version. *
 *                                                                    *
 * This library is distributed in the hope that it will be useful,    *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of     *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  *
 * Lesser General Public License for more details.                    *
 *                                                                    *
 * You should have received a copy of the GNU Lesser General Public   *
 * License along with this library; if not, write to the Free         *
 * Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,    *
 * MA  02110-1301  USA                                                *
 *                                                                    *
 **********************************************************************/

#ifndef CVECTOR_3D_H_INCLUDED
#define CVECTOR_3D_H_INCLUDED

#ifdef __cplusplus

extern "C" {
    
#endif

#ifdef CV3_USE_FAR
#include <malloc.h>
#define CV3_FAR __far
#define CV3_MALLOC _fmalloc
#define CV3_FREE _ffree
#define CV3_MEMSET _fmemset
#define CV3_MEMMOVE _fmemmove
#else
#include <stdlib.h>
#define CV3_FAR
#define CV3_MALLOC malloc
#define CV3_FREE free
#define CV3_MEMSET memset
#define CV3_MEMMOVE memmove
#endif

#ifdef CV3_DEBUG
#include <stdio.h>
#define CV3M_printvector(stream,v) { \
    fprintf((stream),"vector " #v ": [%g %g %g]\n",\
    (v).vec[0],(v).vec[1],(v).vec[2]); \
  }
#define CV3M_printmatrix(stream,m) { \
    fprintf((stream),"matrix " #m ": {[%g %g %g],[%g %g %g],[%g %g %g]}\n",\
    (m).mat[0],(m).mat[1],(m).mat[2], \
    (m).mat[3],(m).mat[4],(m).mat[5], \
    (m).mat[6],(m).mat[7],(m).mat[8]);\
  }
#define CV3M_debugstatement(s) { (s); }
#else
#define CV3M_printvector(stream,v)
#define CV3M_printmatrix(stream,m)
#define CV3M_debugstatement(s)
#endif
    
#define CVECTOR_3D_BAD_ARGUMENT  1
#define CVECTOR_3D_MALLOC        2

    
    typedef struct { double vec[3]; } CV3Vector;
    typedef CV3Vector CV3_FAR * CV3VectorHandle;
    typedef struct { double mat[9]; } CV3Matrix;
    typedef CV3Matrix CV3_FAR * CV3MatrixHandle;
    typedef struct { double d; unsigned int a1; unsigned int a2; } CV3MatchObject;
    typedef CV3MatchObject CV3_FAR * CV3MatchObjectHandle;
    typedef struct { CV3Vector m_lineAxis; CV3Vector m_basePoint; CV3Vector m_centerOfMass; } CV3Line;
    typedef CV3Line CV3_FAR * CV3LineHandle;
    typedef struct { CV3Vector m_planeNormal; CV3Vector m_basePoint; CV3Vector m_centerOfMass; } CV3Plane;
    typedef CV3Plane CV3_FAR * CV3PlaneHandle;
    
#define CV3MINNORM  1.e-12
#ifdef CV3_DATA_DEFS
    CV3Vector CV3XAxis = {{1.0,0.0,0.0}};
    CV3Vector CV3YAxis = {{0.0,1.0,0.0}};
    CV3Vector CV3ZAxis = {{0.0,0.0,1.0}};
    CV3Vector CV3ZeroVector = {{0.0,0.0,0.0}};
    CV3Matrix CV3ZeroMatrix = {{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0}};
    CV3Matrix CV3UnitMatrix = {{1.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,1.0}};
    long int CV3_MemoryUsed = 0;
#else
    extern CV3Vector CV3XAxis;
    extern CV3Vector CV3YAxis;
    extern CV3Vector CV3ZAxis;
    extern CV3Vector CV3ZeroVector;
    extern CV3Matrix CV3ZeroMatrix;
    extern CV3Matrix CV3UnitMatrix;
    extern long int CV3_MemoryUsed;
#endif
    

#ifdef __cplusplus
#include <cfloat>
#include <cmath>
#else
#include <float.h>
#include <math.h>
#endif
    
#ifndef USE_LOCAL_HEADERS
#include <cqrlib.h>
#include <CVector.h>
#else
#include "cqrlib.h" 
#include "CVector.h"
#endif    
    
/*  Macro naming convention:
 
    CV3M_<object><arg1><arg2>...<argn><action>
 
    <object> - the object being operated on,
    <argk> -   the kth argument:
               v - vector
               m - matrix
               q - quaternion
               l - line
               p - plane
               o - match object
               s - scalar
               b - Boolean
               a - CV3Vector of vectors
               cv - C vector of dimension 3
               cm - C matrix 3x3
 */

#define CV3M_ooCopy(moresult,mo)       (moresult).d = (mo).d; (moresult).a1 = (mo).a1; (moresult).a2 = (mo).a2;
#define CV3M_booCompare(bresult,mo1,mo2) \
                                       (bresult) = ((mo1).d < (mo2).d);
#define CV3M_cvvSet(cvresult,v)        (cvresult)[0]=(v).vec[0];(cvresult)[1]=(v).vec[1];(cvresult)[2]=(v).vec[2];
#define CV3M_vcvSet(vresult,cv)        (vresult).vec[0]=(cv)[0];(vresult).vec[1]=(cv)[1];(vresult).vec[2]=(cv)[2];

#define CV3M_cmmSet(cmresult,m)        (cmresult)[0][0]=(m).mat[0];(cmresult)[0][1]=(m).mat[1];(cmresult)[0][2]=(m).mat[2]; \
                                       (cmresult)[1][0]=(m).mat[3];(cmresult)[1][1]=(m).mat[4];(cmresult)[1][2]=(m).mat[5]; \
                                       (cmresult)[2][0]=(m).mat[6];(cmresult)[2][1]=(m).mat[7];(cmresult)[2][2]=(m).mat[8]; 
#define CV3M_mcmSet(mresult,cm)        (mresult).mat[0]=(cm)[0][0];(mresult).mat[1]=(cm)[0][1];(mresult).mat[2]=(cm)[0][2]; \
                                       (mresult).mat[3]=(cm)[1][0];(mresult).mat[4]=(cm)[1][1];(mresult).mat[5]=(cm)[1][2]; \
                                       (mresult).mat[6]=(cm)[2][0];(mresult).mat[7]=(cm)[2][1];(mresult).mat[8]=(cm)[2][2];     
#define CV3M_vsssSet(vresult,v0,v1,v2)    (vresult).vec[0] = (v0); (vresult).vec[1] = (v1); (vresult).vec[2] = (v2);
#define CV3M_vsSet(vresult,s)          (vresult).vec[0] = (s);  (vresult).vec[1] = (s);  (vresult).vec[2] = (s);
#define CV3M_vvCopy(vresult,u)          (vresult).vec[0] = (u).vec[0]; (vresult).vec[1] = (u).vec[1]; (vresult).vec[2] = (u).vec[2];
#define CV3M_vvsMultiply(vresult,u,s)   (vresult).vec[0] = (u).vec[0]*(s); (vresult).vec[1] = (u).vec[1]*(s); (vresult).vec[2] = (u).vec[2]*(s);
#define CV3M_vvsDivide(vresult,u,s)     (vresult).vec[0] = (u).vec[0]/(s); (vresult).vec[1] = (u).vec[1]/(s); (vresult).vec[2] = (u).vec[2]/(s);
#define CV3M_svvDot(dresult,u,v)        dresult=((u).vec[0]*(v).vec[0] + (u).vec[1]*(v).vec[1] + (u).vec[2]*(v).vec[2]);
#define CV3M_vvvCross(vresult,u,v)      (vresult).vec[0] = (u).vec[1]*(v).vec[2]-(v).vec[1]*(u).vec[2]; \
                                       (vresult).vec[1] =-(u).vec[0]*(v).vec[2]+(v).vec[0]*(u).vec[2]; \
                                       (vresult).vec[2] = (u).vec[0]*(v).vec[1]-(v).vec[0]*(u).vec[1];
#define CV3M_vvvDyadProduct(vresult,u,v) {\
                                       (vresult).vec[0] = (u).vec[0]*(v).vec[0]; \
                                       (vresult).vec[1] = (u).vec[1]*(v).vec[1]; \
                                       (vresult).vec[2] = (u).vec[2]*(v).vec[2]; }
#define CV3M_mmmMultiply(mresult,m1,m2) { \
                                         CV3M_msssssssssSet(mresult, \
                                         (m1).mat[0]*(m2).mat[0] + (m1).mat[1]*(m2).mat[3] + (m1).mat[2]*(m2).mat[6], \
                                         (m1).mat[0]*(m2).mat[1] + (m1).mat[1]*(m2).mat[4] + (m1).mat[2]*(m2).mat[7], \
                                         (m1).mat[0]*(m2).mat[2] + (m1).mat[1]*(m2).mat[5] + (m1).mat[2]*(m2).mat[8], \
                                         (m1).mat[3]*(m2).mat[0] + (m1).mat[4]*(m2).mat[3] + (m1).mat[5]*(m2).mat[6], \
                                         (m1).mat[3]*(m2).mat[1] + (m1).mat[4]*(m2).mat[4] + (m1).mat[5]*(m2).mat[7], \
                                         (m1).mat[3]*(m2).mat[2] + (m1).mat[4]*(m2).mat[5] + (m1).mat[5]*(m2).mat[8], \
                                         (m1).mat[6]*(m2).mat[0] + (m1).mat[7]*(m2).mat[3] + (m1).mat[8]*(m2).mat[6], \
                                         (m1).mat[6]*(m2).mat[1] + (m1).mat[7]*(m2).mat[4] + (m1).mat[8]*(m2).mat[7], \
                                         (m1).mat[6]*(m2).mat[2] + (m1).mat[7]*(m2).mat[5] + (m1).mat[8]*(m2).mat[8]);}
#define CV3M_vvvAdd(vresult,u,v)        (vresult).vec[0] = (u).vec[0]+(v).vec[0]; \
                                       (vresult).vec[1] = (u).vec[1]+(v).vec[1]; \
                                       (vresult).vec[2] = (u).vec[2]+(v).vec[2];
#define CV3M_vvvSubtract(vresult,u,v)   (vresult).vec[0] = (u).vec[0]-(v).vec[0]; \
                                       (vresult).vec[1] = (u).vec[1]-(v).vec[1]; \
                                       (vresult).vec[2] = (u).vec[2]-(v).vec[2];
#define CV3M_vvNegate(vresult,u)        (vresult).vec[0] = -(u).vec[0]; (vresult).vec[1] = -(u).vec[1]; (vresult).vec[2] = -(u).vec[2]; 
#define CV3M_svNormsq(dresult,u)         dresult=((u).vec[0]*(u).vec[0] + (u).vec[1]*(u).vec[1] + (u).vec[2]*(u).vec[2]);
#define CV3M_svNorm(dresult,u)           dresult=sqrt(((u).vec[0]*(u).vec[0] + (u).vec[1]*(u).vec[1] + (u).vec[2]*(u).vec[2]));
#define CV3M_vvUnitV(vresult,u)        { double norm; \
                                         CV3M_svNorm(norm,u); \
                                         if (norm < 10.*DBL_MIN) { (vresult).vec[0] = (vresult).vec[1] = (vresult).vec[2] = 0.;} \
                                         else { CV3M_vvsDivide(vresult,u,norm);} \
                                        }
#define CV3M_svvvAngle(dresult,v1,v2,v3) { \
                                          CV3Vector x; \
                                          CV3Vector y; \
                                          CV3Vector z; \
                                          double dotProduct, xNorm, yNorm, zNorm; \
                                          CV3M_vvvSubtract((x),(v1),(v2)); \
                                          CV3M_vvvSubtract((y),(v3),(v2)); \
                                          CV3M_vvvCross((z),(x),(y)); \
                                          CV3M_svNorm(xNorm,x); CV3M_svNorm(yNorm,y); CV3M_svNorm(zNorm,z); \
                                          CV3M_svvDot(dotProduct,(x),(y)); \
                                          if (xNorm > CV3MINNORM && yNorm > CV3MINNORM ) { \
                                            double cosAngle, sinAngle; \
                                            cosAngle = dotProduct/(xNorm*yNorm); \
                                            sinAngle = zNorm/(xNorm*yNorm); \
                                            dresult = atan2( sinAngle, cosAngle) ;\
                                          } else { \
                                            dresult = 0; \
                                          } \
                                       }
#define CV3M_svvAngle(dresult,x,y) { \
                                          CV3Vector z; \
                                          double dotProduct, xNorm, yNorm, zNorm; \
                                          CV3M_svNorm(xNorm,(x)); CV3M_svNorm(yNorm,(y)); \
                                          CV3M_vvvCross((z),(x),(y)); \
                                          CV3M_svNorm(zNorm,(z)); \
                                          CV3M_svvDot(dotProduct,(x),(y)); \
                                          if (xNorm > CV3MINNORM && yNorm > CV3MINNORM ) { \
                                            double cosAngle, sinAngle; \
                                            cosAngle = dotProduct/(xNorm*yNorm); \
                                            sinAngle = zNorm/(xNorm*yNorm); \
                                            dresult = atan2( sinAngle, cosAngle) ;\
                                          } else { \
                                            dresult = 0; \
                                          } \
                                       }
#define CV3M_svvvvTorsion(dresult,a,b,c,d) { \
                                          double pdq; \
                                          CV3Vector p, q, x, y; \
                                          CV3M_vvvSubtract(p,(a),(b)); \
                                          CV3M_vvvSubtract(q,(c),(b)); \
                                          CV3M_vvvCross(x,(p),(q)); \
                                          CV3M_vvvSubtract(p,(b),(c)); \
                                          CV3M_vvvSubtract(q,(d),(c)); \
                                          CV3M_vvvCross(y,(p),(q)); \
                                          CV3M_svvAngle(dresult,(x),(y)); \
                                          CV3M_vvvCross(q,(x),(y)) ; \
                                          CV3M_svvDot(pdq,(p),(q)) ; \
                                          if (pdq > 0.0) dresult = - dresult; \
                                       }

#define CV3M_msssssssssSet(mresult,m00,m01,m02,m10,m11,m12,m20,m21,m22) { \
                                       (mresult).mat[0] = (m00); (mresult).mat[1] = (m01); (mresult).mat[2] = (m02);  \
                                       (mresult).mat[3] = (m10); (mresult).mat[4] = (m11); (mresult).mat[5] = (m12);  \
                                       (mresult).mat[6] = (m20); (mresult).mat[7] = (m21); (mresult).mat[8] = (m22);}
#define CV3M_mmCopy(mresult,m) {       (mresult).mat[0] = (m).mat[0]; (mresult).mat[1] = (m).mat[1]; (mresult).mat[2] = (m).mat[2]; \
                                       (mresult).mat[3] = (m).mat[3]; (mresult).mat[4] = (m).mat[4]; (mresult).mat[5] = (m).mat[5]; \
                                       (mresult).mat[6] = (m).mat[6]; (mresult).mat[7] = (m).mat[7]; (mresult).mat[8] = (m).mat[8];}
#define CV3M_mvsRotmat(mresult,u,angle) { \
                                         double d; \
                                         double ux2, uy2, uz2, uxy, uxz, uyz, s, c; \
                                         CV3Vector v; \
                                         CV3Vector xaxis=CV3XAxis; \
                                         CV3M_svNormsq(d,(u)); \
                                         if ( d != 1.0 && d != 0.0 ) { \
                                             CV3M_vvsDivide(v,(u),sqrt(d)); \
                                         } else if (d == 1.0) { \
                                             CV3M_vvCopy((v),(u)); \
                                         } else { \
                                             CV3M_vvCopy((v),(xaxis)); \
                                         } \
                                         ux2 = v.vec[0]*v.vec[0]; \
                                         uy2 = v.vec[1]*v.vec[1]; \
                                         uz2 = v.vec[2]*v.vec[2]; \
                                         uxy = v.vec[0]*v.vec[1]; \
                                         uxz = v.vec[0]*v.vec[2]; \
                                         uyz = v.vec[1]*v.vec[2]; \
                                         s = sin(angle); c = cos(angle); \
                                         CV3M_msssssssssSet(mresult, \
                                           ux2+(1.0-ux2)*c,        uxy*(1.0-c)-v.vec[2]*s, uxz*(1.0-c)+v.vec[1]*s, \
                                           uxy*(1.0-c)+v.vec[2]*s, uy2+(1-uy2)*c,          uyz*(1.0-c)-v.vec[0]*s, \
                                           uxz*(1.0-c)-v.vec[1]*s, uyz*(1.0-c)+v.vec[0]*s, uz2+(1.0-uz2)*c); \
                                       }
#define CV3M_mvvvvPair(mresult,x1,x2,z1,z2) { \
                                        CV3Matrix mTemp = {{ 1.0,0.0,0.0, 0.0,1.0,0.0, 0.0,0.0,1.0}}; \
                                        CV3Vector x1Unit; \
                                        CV3Vector z1Unit; \
                                        double x1Norm, z1Norm; \
                                        CV3M_svNorm(x1Norm,(x1));\
                                        CV3M_svNorm(z1Norm,(z1));\
                                        if( x1Norm < CV3MINNORM || z1Norm < CV3MINNORM ) { \
                                          CV3M_mmCopy((mresult),mTemp) \
                                        } else { \
                                            CV3Matrix bMat, cMat; \
                                            double angleTest,angle2; \
                                            CV3Vector vx1; \
                                            CV3Vector vx2; \
                                            CV3M_vvUnitV(x1Unit,(x1)); \
                                            CV3M_vvUnitV(z1Unit,(z1)); \
                                            CV3M_vvvCross(vx1,(x1),(z1)); \
                                            CV3M_svvAngle(angleTest,(x1),(z1)); \
                                            CV3M_debugstatement(fprintf(stderr,"angleTest %g\n",angleTest));\
                                            CV3M_mvsRotmat(bMat,vx1,angleTest); \
                                            CV3M_printmatrix(stderr,bMat); \
                                            CV3M_vmvMultiply(vx2,bMat,(x2)); \
                                            CV3M_svvvvTorsion(angle2,vx2,(z1),CV3ZeroVector,(z2)); \
                                            angle2 = -angle2; \
                                            CV3M_debugstatement(fprintf(stderr,"angle2 %g\n",angle2));\
                                            CV3M_mvsRotmat(cMat,(z1),angle2); \
                                            CV3M_printmatrix(stderr,cMat); \
                                            CV3M_mmmMultiply(mresult,cMat,bMat); \
                                        } \
                                      }
#define CV3M_bvvEquals(bresult,u,v) {  (bresult)=((u).vec[0]==(v).vec[0]&&(u).vec[1]==(v).vec[1]&&(u).vec[2]==(v).vec[2]);}
#define CV3M_qvvQuaternionFromPair(qresult,u,v) { \
                                       CV3Vector axis,uaxis; \
                                       double angle; \
                                       CV3M_vvvCross(axis,u,v); \
                                       CV3M_vvUnitV(uaxis,axis); \
                                       CV3M_svvvvTorsion(angle,uaxis,u,v,CV3ZeroVector); \
                                       CQRMSet((qresult),(cos(angle/2)),(sin(angle/2)*uaxis.vec[0]),(sin(angle/2)*uaxis.vec[1]),(sin(angle/2)*uaxis.vec[2])); \
                                       }
#define CV3M_vaGetCenterOfMass(vresult,vv) { \
                                       size_t it, vvsize; \
                                       CV3M_vvCopy(vresult,CV3ZeroVector); \
                                       vvsize = CVectorSize(vv); \
                                       for (it=0; it < vvsize; it++) { \
                                         CV3M_vvvAdd(vresult,vresult,*((CV3Vector *)(CVectorElementAt(vv,it)))); \
                                       } \
                                       if (vvsize > 1) { CV3M_vvsDivide(vresult,vresult,(double)vvsize); } \
                                       }
#define CV3M_mvsInertiaTensorForPoint(mresult,v,weight) { \
                                         double am; \
                                         CV3M_svNormsq(am,v); \
                                         am *=(weight); \
                                         CV3M_mmCopy((mresult),CV3ZeroMatrix);\
                                         (mresult).mat[0] += am - (v).vec[0] * (v).vec[0]; \
                                         (mresult).mat[4] += am - (v).vec[1] * (v).vec[1]; \
                                         (mresult).mat[8] += am - (v).vec[2] * (v).vec[2]; \
                                         (mresult).mat[1] -= (v).vec[0] * (v).vec[1]; \
                                         (mresult).mat[3]  = (mresult).mat[1]; \
                                         (mresult).mat[2] -= (v).vec[0] * (v).vec[2]; \
                                         (mresult).mat[6]  = (mresult).mat[2]; \
                                         (mresult).mat[5] -= (v).vec[1] * (v).vec[2]; \
                                         (mresult).mat[7]  = (mresult).mat[5]; \
                                       }
#define CV3M_mmUNX(mresult,m)           {\
                                          double denominator, numerator, angle; \
                                          denominator = fabs((m).mat[4]+(m).mat[8]); \
                                          numerator = (m).mat[7]-(m).mat[5]; \
                                          if ( fabs(numerator/denominator) < CV3MINNORM ) numerator = 0.0; \
                                          angle = atan2( numerator, denominator ); \
                                          CV3M_mvsRotmat(mresult,CV3XAxis,-angle); \
                                       }
#define CV3M_mmUNY(mresult,m)           {\
                                          double denominator, numerator, angle; \
                                          denominator = fabs((m).mat[4]+(m).mat[8]); \
                                          numerator = (m).mat[7]-(m).mat[5]; \
                                          if ( fabs(numerator/denominator) < CV3MINNORM ) numerator = 0.0; \
                                          angle = atan2( numerator, denominator ); \
                                          CV3M_mvsRotmat(mresult,CV3YAxis,angle); \
                                       }
#define CV3M_mmUNZ(mresult,m)           {\
                                          double denominator, numerator, angle; \
                                          denominator = fabs((m).mat[4]+(m).mat[8]); \
                                          numerator = (m).mat[7]-(m).mat[5]; \
                                          if ( fabs(numerator/denominator) < CV3MINNORM ) numerator = 0.0; \
                                          angle = atan2( numerator, denominator ); \
                                          CV3M_mvsRotmat(mresult,CV3ZAxis,-angle); \
                                       }
#define CV3M_lvvSet( lresult, direction, centerOfMass) {\
                                          CV3Vector lineAxis; \
                                          CV3Matrix mPrep; \
                                          double dirns; \
                                          CV3M_vvUnitV(lineAxis,(direction)); \
                                          CV3M_vvCopy((lresult).m_lineAxis,(lineAxis));\
                                          CV3M_vvCopy((lresult).m_basePoint,(centerOfMass));\
                                          CV3M_vvCopy((lresult).m_centerOfMass,(centerOfMass));\
                                          CV3M_svNormsq(dirns,direction); \
                                          if (dirns == 0.0) { \
                                            CV3M_vsSet((lresult).m_lineAxis,0.); \
                                            CV3M_vsSet((lresult).m_basePoint,0.); \
                                            CV3M_vsSet((lresult).m_centerOfMass,0.); \
                                          } else { \
                                              CV3M_mvvTensorProduct(mPrep,(lresult).m_lineAxis,(lresult).m_lineAxis);\
                                              CV3M_mmmSubtract(mPrep,CV3UnitMatrix,mPrep);\
                                              CV3M_vmvMultiply((lresult).m_basePoint,mPrep,centerOfMass); \
                                          } \
                                       }
#define CV3M_vlLineAxis( vresult, line)  { \
                                         CV3M_vvCopy(vresult,((line).m_lineAxis));\
                                       }
#define CV3M_vlBasePoint( vresult, line)  { \
                                         CV3M_vvCopy(vresult,((line).m_basePoint));\
                                          }
#define CV3M_pvvSet( presult, direction, centerOfMass) {\
                                          CV3Vector planeNormal; \
                                          CV3Vector basePoint; \
                                          double comdotpn; \
                                          CV3M_vvUnitV(planeNormal,direction); \
                                          CV3M_svvDot(comdotpn,centerOfMass,planeNormal); \
                                          CV3M_vvsMultiply(basePoint,planeNormal,comdotpn); \
                                          CV3M_vvCopy((presult).m_planeNormal,planeNormal);\
                                          CV3M_vvCopy((presult).m_basePoint,basePoint);\
                                          CV3M_vvCopy((presult).m_centerOfMass,centerOfMass);\
                                       }
#define CV3M_vpNormalVector( vresult, plane)  { \
                                         CV3M_vvCopy(vresult,(plane).m_planeNormal);\
                                       }
#define CV3M_vpBasePoint( vresult, plane)  { \
                                         CV3M_vvCopy(vresult,(plane).m_basePoint);\
                                          }
#define CV3M_mmmAdd(mresult,m1,m2) {    CV3M_msssssssssSet(mresult, \
                                       (m1).mat[0]+(m2).mat[0],(m1).mat[1]+(m2).mat[1],(m1).mat[2]+(m2).mat[2], \
                                       (m1).mat[3]+(m2).mat[3],(m1).mat[4]+(m2).mat[4],(m1).mat[5]+(m2).mat[5], \
                                       (m1).mat[6]+(m2).mat[6],(m1).mat[7]+(m2).mat[7],(m1).mat[8]+(m2).mat[8]) }
#define CV3M_mmmSubtract(mresult,m1,m2) {    CV3M_msssssssssSet(mresult, \
                                       (m1).mat[0]-(m2).mat[0],(m1).mat[1]-(m2).mat[1],(m1).mat[2]-(m2).mat[2], \
                                       (m1).mat[3]-(m2).mat[3],(m1).mat[4]-(m2).mat[4],(m1).mat[5]-(m2).mat[5], \
                                       (m1).mat[6]-(m2).mat[6],(m1).mat[7]-(m2).mat[7],(m1).mat[8]-(m2).mat[8]) }
#define CV3M_mmsMultiply(mresult,m,s)   {      CV3M_msssssssssSet(mresult, \
                                       (m).mat[0]*s,(m).mat[1]*s,(m).mat[2]*s, \
                                       (m).mat[3]*s,(m).mat[4]*s,(m).mat[5]*s, \
                                       (m).mat[6]*s,(m).mat[7]*s,(m).mat[8]*s) }
#define CV3M_mmsDivide(mresult,m,s)     {      CV3M_msssssssssSet(mresult, \
                                       (m).mat[0]/s,(m).mat[1]/s,(m).mat[2]/s, \
                                       (m).mat[3]/s,(m).mat[4]/s,(m).mat[5]/s, \
                                       (m).mat[6]/s,(m).mat[7]/s,(m).mat[8]/s) }
#define CV3M_vmvMultiply(vresult,m,v) {      CV3M_vsssSet(vresult, \
                                       (m).mat[0]*(v).vec[0] + (m).mat[1]*(v).vec[1] + (m).mat[2]*(v).vec[2], \
                                       (m).mat[3]*(v).vec[0] + (m).mat[4]*(v).vec[1] + (m).mat[5]*(v).vec[2], \
                                       (m).mat[6]*(v).vec[0] + (m).mat[7]*(v).vec[1] + (m).mat[8]*(v).vec[2]);}


#define CV3M_mvvTensorProduct(mresult,u,v) {     (mresult).mat[0] = (u).vec[0]*(v).vec[0]; \
                                       (mresult).mat[1] = (u).vec[0]*(v).vec[1]; \
                                       (mresult).mat[2] = (u).vec[0]*(v).vec[2]; \
                                       (mresult).mat[3] = (u).vec[1]*(v).vec[0]; \
                                       (mresult).mat[4] = (u).vec[1]*(v).vec[1]; \
                                       (mresult).mat[5] = (u).vec[1]*(v).vec[2]; \
                                       (mresult).mat[6] = (u).vec[2]*(v).vec[0]; \
                                       (mresult).mat[7] = (u).vec[2]*(v).vec[1]; \
                                       (mresult).mat[8] = (u).vec[2]*(v).vec[2]; }

#define CV3M_mvvMatrixProduct(mresult,u,v) CV3M_mvvTensorProduct(mresult,u,v)

#define CV3M_mmTranspose(mresult,m) { \
                                       (mresult).mat[0] = (m).mat[0]; (mresult).mat[1] = (m).mat[3]; (mresult).mat[2] = (m).mat[6]; \
                                       (mresult).mat[3] = (m).mat[1]; (mresult).mat[4] = (m).mat[4]; (mresult).mat[5] = (m).mat[7]; \
                                       (mresult).mat[6] = (m).mat[2]; (mresult).mat[7] = (m).mat[5]; (mresult).mat[8] = (m).mat[8];}
#define CV3M_smDeterminant(dresult,m) { \
                                       (dresult) =  (m).mat[0]*(m).mat[4]*(m).mat[8] + \
                                                    (m).mat[1]*(m).mat[5]*(m).mat[6] + \
                                                    (m).mat[2]*(m).mat[3]*(m).mat[7] - \
                                                    (m).mat[6]*(m).mat[4]*(m).mat[2] - \
                                                    (m).mat[7]*(m).mat[5]*(m).mat[0] - \
                                                    (m).mat[8]*(m).mat[3]*(m).mat[1];}
#define CV3M_mmInverse(mresult,m) { \
                                    double d;               \
                                    CV3Vector v0, v1, v2, vOut0, vOut1, vOut2; \
                                    CV3M_smDeterminant(d,m); \
                                    d = (d==0.0)? 1.:((d<0.0 && d > -1.e-20)?-d:d) ;\
                                    CV3M_vsssSet( v0, (m).mat[0], (m).mat[1], (m).mat[2] ); \
                                    CV3M_vsssSet( v1, (m).mat[3], (m).mat[4], (m).mat[5] ); \
                                    CV3M_vsssSet( v2, (m).mat[6], (m).mat[7], (m).mat[8] ); \
                                    CV3M_vvvCross( vOut0, v1, v2); \
                                    CV3M_vvvCross( vOut1, v2, v0); \
                                    CV3M_vvvCross( vOut2, v0, v1); \
                                    CV3M_msssssssssSet( mresult,  vOut0.vec[0]/d, vOut1.vec[0]/d, vOut2.vec[0]/d, \
                                                         vOut0.vec[1]/d, vOut1.vec[1]/d, vOut2.vec[1]/d, \
                                                         vOut0.vec[2]/d, vOut1.vec[2]/d, vOut2.vec[2]/d ); \
}
#define CV3M_slvDistanceFromLine( dresult, line, vector ) { \
                                    CV3Matrix mPrep, mMP; \
                                    CV3Vector vTemp1, vTemp2; \
                                    CV3M_mvvMatrixProduct(mMP,(line).m_lineAxis,(line).m_lineAxis);\
                                    CV3M_mmmSubtract(mPrep,CV3UnitMatrix,mMP); \
                                    CV3M_vvvSubtract(vTemp1,vector,(line).m_basePoint); \
                                    CV3M_vmvMultiply(vTemp2,mPrep,vTemp1); \
                                    CV3M_svNorm(dresult,vTemp2) \
                                  }
#define CV3M_spvDistanceFromPlane( dresult, plane, vector ) { \
                                     CV3Vector temp; \
                                     CV3M_vvvSubtract(temp,(plane).m_basePoint,(vector)); \
                                     CV3M_svvDot(dresult,temp,(plane).m_planeNormal); \
                                     if ((dresult)<0.) (dresult) = -(dresult); \
                                  }
#define CV3M_lppIntersect( lresult, p1, p2 ) { \
                                     CV3Vector vtest; \
                                     double vtn; \
                                     CV3M_vvvCross(vtest,(p1).m_planeNormal,(p2).m_planeNormal); \
                                     CV3M_svNormsq(vtn,vtest); \
                                     if (vtn < 0.005*0.005 ) { \
                                       CV3M_lvvSet(lresult,CV3ZeroVector,CV3ZeroVector); \
                                     } else { \
                                       double n11, n12, n13, n21, n22, n23; \
                                       double x1, x2, x3; \
                                       double p2dotn2, p1dotn1; \
                                       CV3Vector pointOnLine, vtestUnit, v, temp; \
                                       double dot; \
                                       CV3M_svvDot(p2dotn2,((p2).m_basePoint),((p2).m_planeNormal)); \
                                       CV3M_svvDot(p1dotn1,((p1).m_basePoint),((p1).m_planeNormal));\
                                       n11 = (p1).m_planeNormal.vec[0]; \
                                       n12 = (p1).m_planeNormal.vec[1]; \
                                       n13 = (p1).m_planeNormal.vec[2]; \
                                       n21 = (p2).m_planeNormal.vec[0]; \
                                       n22 = (p2).m_planeNormal.vec[1]; \
                                       n23 = (p2).m_planeNormal.vec[2]; \
                                       if ( fabs(n13*n21 - n11*n23) > CV3MINNORM && \
                                         fabs(n13*n21 - n11*n23) >= fabs(n13*n22 - n12*n23) && \
                                         fabs(n13*n21 - n11*n23) >= fabs(n12*n21 - n11*n22) ) { \
                                         x2 = 0.0; \
                                         x1 =    ( n13*p2dotn2 - n23*p1dotn1) /  (n13*n21 - n11*n23); \
                                         x3 =    (-n11*p2dotn2 + n21*p1dotn1) /  (n13*n21 - n11*n23); \
                                       } else if ( fabs(n13*n22 - n12*n23) > CV3MINNORM && \
                                         fabs(n13*n22 - n12*n23) >= fabs(n12*n21 - n11*n22)) { \
                                         x1 = 0.0; \
                                         x2 =    ( n13*p2dotn2 - n23*p1dotn1) /  (n13*n22 - n12*n23); \
                                         x3 =    (-n12*p2dotn2 + n22*p1dotn1) /  (n13*n22 - n12*n23); \
                                       } else if ( fabs(n12*n21 - n11*n22) > CV3MINNORM ) { \
                                         x3 = 0.0; \
                                         x1 =    ( n12*p2dotn2 - n22*p1dotn1) /  (n12*n21 - n11*n22); \
                                         x2 =    (-n11*p2dotn2 + n21*p1dotn1) /  (n12*n21 - n11*n22); \
                                       } else { \
                                         x1 = 0.0; x2 = 0.0; x3 = 0.0; \
                                       } \
                                       CV3M_vsssSet(pointOnLine,x1,x2,x3); \
                                       CV3M_vvUnitV(vtestUnit,vtest); \
                                       CV3M_svvDot(dot,vtestUnit,pointOnLine ); \
                                       CV3M_vvsMultiply(vtestUnit,vtestUnit,dot); \
                                       CV3M_vvvSubtract(v,pointOnLine,vtestUnit); \
                                       CV3M_vvUnitV(temp,vtest); \
                                       CV3M_lvvSet(lresult,temp,v); \
                                   } \
                                }
#define CV3M_vqvRotateByQuaternion(vresult,q,v) { \
                                       CQRQuaternion vquat,wquat,qconj; \
                                       CQRMSet(vquat,0.,(v).vec[0],(v).vec[1],(v).vec[2]); \
                                       CQRMMultiply(wquat,(q),vquat); \
                                       CQRMConjugate(qconj,(q));\
                                       CQRMMultiply(vquat,wquat,qconj); \
                                       CV3M_vsssSet(vresult,vquat.x,vquat.y,vquat.z); \
                                }
#define CV3M_qvsAxis2Quaternion(qresult,v,angle) { \
                                       double axis[3]; \
                                       CV3M_cvvSet(axis,v); \
                                       CQRAxis2Quaternion(qresult,axis,angle); \
                                }
#define CV3M_qmMatrix2Quaternion(qresult,m) { \
                                       double matrix[3][3]; \
                                       CV3M_cmmSet(matrix,m); \
                                       CQRMatrix2Quaternion(&qresult,matrix); \
                                }
#define CV3M_mqQuaternion2Matrix(mresult,q) { \
                                       double matrix[3][3]; \
                                       CQRQuaternion2Matrix(matrix,&q); \
                                       CV3M_mcmSet(mresult,matrix); \
                                }

#define CV3M_svmEigen1(dresult,vresult,m) { \
                                      CV3Matrix x, xx, b; \
                                      CV3Vector v0, v1, v2; \
                                      double v0Normsq, v1Normsq, v2Normsq, vrNormsq; \
                                      int i; \
                                      double trace; \
                                      CV3M_mmCopy(x,(m)); \
                                     for(i=0; i<18; ++i ) { \
                                        trace = x.mat[0] + x.mat[4] + x.mat[8]; \
                                        if( fabs(trace) < CV3MINNORM ) { \
                                          trace = 1.0; \
                                        } \
                                        CV3M_mmsDivide(x,x,trace); \
                                        CV3M_mmmMultiply(xx,x,x); \
                                        CV3M_mmCopy(x,xx); \
                                      }\
                                      /* by this point in the code, the matrix _should_ have been reduced to a matrix with \
                                      a single row (and column) that is non-zero (or at least the others are very small) */ \
                                      \
                                      /* now get the eigenvalue */ \
                                      CV3M_mmmMultiply(b,m,x); /* isolate the eigenvector */ \
                                      CV3M_vsssSet(v0,b.mat[0],b.mat[1],b.mat[2]); \
                                      CV3M_vsssSet(v1,b.mat[3],b.mat[4],b.mat[5]); \
                                      CV3M_vsssSet(v2,b.mat[6],b.mat[7],b.mat[8]); \
                                      CV3M_svNormsq(v0Normsq,v0); \
                                      CV3M_svNormsq(v1Normsq,v1); \
                                      CV3M_svNormsq(v2Normsq,v2); \
                                      CV3M_vvCopy((vresult),v0); \
                                      if( v0Normsq < v1Normsq ) { CV3M_vvCopy((vresult),v1); } \
                                      CV3M_svNormsq(vrNormsq,(vresult)); \
                                      if( vrNormsq < v2Normsq ) { CV3M_vvCopy((vresult),v2); } \
                                      CV3M_vvUnitV((vresult),(vresult)); \
                                      CV3M_vmvMultiply(v0,(m),(vresult)); \
                                      CV3M_svvDot((dresult),(vresult),v0); \
                                      if ((dresult) < 0.) { \
                                        CV3M_vvNegate((vresult),(vresult)); \
                                      } \
                            }
#define CV3M_aamEigen3(evalues, evectors, m) { \
                                      double MINEIGENVALUE = 1.0E-16;\
                                      CV3Matrix m1, m2, m3; \
                                      CV3Matrix mattp;\
                                      double dtemp; \
                                      CV3M_mmCopy(m1,m); \
                                      CV3M_svmEigen1(evalues[0], evectors[0], m1); \
                                      if( fabs(evalues[0]) < MINEIGENVALUE ) { \
                                         /* all three eigenvalues are zero - deal with it! */ \
                                         evalues[0] = evalues[1] = evalues[2] = 0; \
                                         CV3M_vsssSet(evectors[0],1.0,0.0,0.0); \
                                         CV3M_vsssSet(evectors[1],0.0,1.0,0.0); \
                                         CV3M_vsssSet(evectors[2],0.0,0.0,1.0); \
                                      } else { \
                                         CV3M_mvvTensorProduct(mattp,evectors[0],evectors[0]); \
                                         CV3M_mmsMultiply(mattp,mattp,evalues[0]); \
                                         CV3M_mmmSubtract(m2,m1,mattp); \
                                         CV3M_svmEigen1(evalues[1], evectors[1],m2); \
                                         CV3M_debugstatement(fprintf(stderr," evalues[1] %g evalues[1] %g %g %g\n",evalues[1],evectors[1].vec[0],evectors[1].vec[1],evectors[1].vec[2]));\
                                         if (fabs(evalues[1]) < MINEIGENVALUE) { \
                                             evalues[1] = evalues[2] = 0; \
                                             if (fabs(evectors[0].vec[0]) > 0.5) { \
                                               dtemp = sqrt(evectors[0].vec[0]*evectors[0].vec[0]+evectors[0].vec[1]*evectors[0].vec[1]); \
                                               evectors[1].vec[0] = -evectors[0].vec[1]/dtemp; \
                                               evectors[1].vec[1] = evectors[0].vec[0]/dtemp; \
                                               evectors[1].vec[2] = 0.; \
                                               CV3M_vvvCross(evectors[2],evectors[0],evectors[1]); \
                                             } else if (fabs(evectors[0].vec[1]) > 0.5) { \
                                                 dtemp = sqrt(evectors[0].vec[1]*evectors[0].vec[1]+evectors[0].vec[2]*evectors[0].vec[2]); \
                                                 evectors[1].vec[1] = -evectors[0].vec[2]/dtemp; \
                                                 evectors[1].vec[2] = evectors[0].vec[1]/dtemp; \
                                                 evectors[1].vec[0] = 0.; \
                                                 CV3M_vvvCross(evectors[2],evectors[0],evectors[1]); \
                                             } else if (fabs(evectors[0].vec[2]) > 0.5) { \
                                                 dtemp = sqrt(evectors[0].vec[0]*evectors[0].vec[0]+evectors[0].vec[2]*evectors[0].vec[2]); \
                                                 evectors[1].vec[0] = -evectors[0].vec[2]/dtemp; \
                                                 evectors[1].vec[2] = evectors[0].vec[0]/dtemp; \
                                                 evectors[1].vec[1] = 0.; \
                                                 CV3M_vvvCross(evectors[2],evectors[0],evectors[1]); \
                                             } else { \
                                                 CV3M_vsSet(evectors[1],0.0); \
                                                 CV3M_vsSet(evectors[2],0.0); \
                                             } \
                                        } else { \
                                             CV3M_mvvTensorProduct(mattp,evectors[1],evectors[1]); \
                                             CV3M_mmsMultiply(mattp,mattp,evalues[1]); \
                                             CV3M_mmmSubtract(m3,m2,mattp); \
                                             CV3M_svmEigen1(evalues[2], evectors[2],m3); \
                                             if (fabs(evalues[2]) < MINEIGENVALUE) { \
                                               evalues[2] = 0; \
                                               CV3M_vvvCross(evectors[2],evectors[0],evectors[1]); \
                                             } \
                                           } \
                                         } \
                                }
#define CV3M_paBestPlane(presult,vv) { \
                                CV3Vector CenterOfMass; \
                                CV3Vector comtemp; \
                                CV3Matrix inertiaTensor = {{0.0,0.0,0.0, 0.0,0.0,0.0, 0.0,0.0,0.0}};\
                                CV3Matrix inertiaTemp; \
                                size_t it; \
                                double eigenValue1; \
                                CV3Vector eigenVector1; \
                                CV3M_vaGetCenterOfMass(CenterOfMass,vv); \
                                \
                                for( it=0; it<CVectorSize(vv); ++it ) { \
                                  CV3M_vvvSubtract(comtemp,*((CV3VectorHandle)CVectorElementAt(vv,it)),CenterOfMass); \
                                  CV3M_mvsInertiaTensorForPoint(inertiaTemp,comtemp,1.0); \
                                  CV3M_mmmAdd(inertiaTensor,inertiaTensor,inertiaTemp); \
                                } \
                                CV3M_svmEigen1(eigenValue1, eigenVector1, inertiaTensor); \
                                CV3M_pvvSet(presult,eigenVector1, CenterOfMass); \
                                }
#define CV3M_laBestLine(lresult,vv) { \
                                CV3Vector CenterOfMass; \
                                CV3Vector comtemp; \
                                CV3Matrix inertiaTensor = {{0.0,0.0,0.0, 0.0,0.0,0.0, 0.0,0.0,0.0}};\
                                CV3Matrix inertiaTemp; \
                                size_t it; \
                                double eigenValue1; \
                                CV3Vector eigenVector1; \
                                CV3M_vaGetCenterOfMass(CenterOfMass,vv); \
                                \
                                for( it=0; it<CVectorSize(vv); ++it ) { \
                                  CV3M_vvvSubtract(comtemp,*((CV3VectorHandle)CVectorElementAt(vv,it)),CenterOfMass); \
                                  CV3M_mvsInertiaTensorForPoint(inertiaTemp,comtemp,1.0); \
                                  CV3M_mmmAdd(inertiaTensor,inertiaTensor,inertiaTemp); \
                                } \
                                CV3M_printmatrix(stderr,inertiaTensor); \
                                CV3M_mmInverse(inertiaTemp,inertiaTensor); \
                                CV3M_printmatrix(stderr,inertiaTemp); \
                                CV3M_svmEigen1(eigenValue1, eigenVector1, inertiaTemp); \
                                CV3M_printvector(stderr,eigenVector1); \
                                CV3M_lvvSet(lresult,eigenVector1, CenterOfMass); \
                                }
#define CV3M_mssssssCart(mresult,a,b,c,alpha,beta,gamma) { \
                                double degreesPerRad;\
                                double sinGamma; \
                                double cosAlpha; \
                                double cosBeta; \
                                double cosGamma; \
                                double V; \
                                degreesPerRad = 45./atan2(1.0,1.0); \
                                sinGamma = sin((gamma) / degreesPerRad); \
                                cosAlpha = cos((alpha) / degreesPerRad); \
                                cosBeta  = cos((beta)  / degreesPerRad); \
                                cosGamma = cos((gamma) / degreesPerRad); \
                                V = (a)*(b)*(c)*sqrt(1.0 \
                                    -cosAlpha*cosAlpha-cosBeta*cosBeta-cosGamma*cosGamma + \
                                    2.0*cosAlpha*cosBeta*cosGamma ); \
                                CV3M_msssssssssSet((mresult), \
                                            (a),   (b)*cosGamma, (c)*cosBeta, \
                                            0.0,   (b)*sinGamma, (c)*(cosAlpha-cosBeta*cosGamma) / sinGamma, \
                                            0.0,   0.0,        V/((a)*(b)*sinGamma)); \
                                }
     
    /* Copy a Match Object */
    
    int CV3CopyMatchObject(CV3MatchObjectHandle moresult, const CV3MatchObjectHandle mo);
    
    /* Compare Match Objects */
    
    int CV3CompareMatchObject(int CV3_FAR * bresult, const CV3MatchObjectHandle mo1, const CV3MatchObjectHandle mo2);
    
    /* Create a Vector */
    
    int CV3CreateVector(CV3VectorHandle CV3_FAR  * vhandle);
    
    /* Create a Matrix */
    
    int CV3CreateMatrix(CV3MatrixHandle CV3_FAR  * mhandle);
    
    /* Free a Vector */
    
    int CV3FreeVector(CV3VectorHandle vhandle);
    
    /* Free a Matrix */
    
    int CV3FreeMatrix(CV3MatrixHandle mhandle);
    
    /* Vector to CVector */
    
    int CV3Vector2CVector(double cv[3], const CV3VectorHandle v );
    
    /* CVector to Vector */
    
    int CV3CVector2Vector(CV3VectorHandle v, const double cv[3]);
    CV3VectorHandle CV3vCVector2Vector(const double cv[3]);
    
    /* Matrix to CMatrix */
    
    int CV3Matrix2CMatrix(double cm[3][3], const CV3MatrixHandle m );
    
    /* CMatrix to Matrix */
    
    int CV3CMatrix2Matrix(CV3MatrixHandle m, const double cm[3][3]);
    CV3MatrixHandle CV3mCMatrix2Matrix(const double cm[3][3]);
    
    /* Initialize a vector from 3 scalars */
    
    int CV3VectorFrom3Scalars(CV3VectorHandle v, const double x, const double y, const double z);
    CV3VectorHandle CV3vVectorFrom3Scalars(const double x, const double y, const double z);
    
    /* Initialize a vector from 1 scalar */
    
    int CV3VectorFromScalar(CV3VectorHandle v, const double s);
    CV3VectorHandle CV3vVectorFromScalar(const double s);
    
    /* Copy a vector */
    
    int CV3CopyVector(CV3VectorHandle v, const CV3VectorHandle u);
    CV3VectorHandle CV3vCopyVector(const CV3VectorHandle u);
    
    /* Multiply a vector by a scalar*/
    
    int CV3VectorScalarMultiply(CV3VectorHandle v, const CV3VectorHandle u, const double s);
    CV3VectorHandle CV3vVectorScalarMultiply(const CV3VectorHandle u, const double s);
    
    /* Divide a vector by a scalar*/
    
    int CV3VectorScalarDivide(CV3VectorHandle v, const CV3VectorHandle u, const double s);
    CV3VectorHandle CV3vCross(const CV3VectorHandle u,  const CV3VectorHandle v );
    
    /* dot product of 2 3-vectors */
    
    int CV3Dot(double CV3_FAR * dresult,  const CV3VectorHandle u,  const CV3VectorHandle v );
    double CV3dDot(const CV3VectorHandle u,  const CV3VectorHandle v );
    
    /* cross product of 2 3-vectors */
    
    int CV3Cross(CV3VectorHandle vresult, const CV3VectorHandle u,  const CV3VectorHandle v );
    CV3VectorHandle CV3vCross(const CV3VectorHandle u,  const CV3VectorHandle v );
    
    /* dyad product of 2 3-vectors */
    
    int CV3DyadProduct(CV3VectorHandle vresult, const CV3VectorHandle u,  const CV3VectorHandle v );
    CV3VectorHandle CV3vDyadProduct(const CV3VectorHandle u,  const CV3VectorHandle v);
    
    /* vector sum of 2 3-vectors */
    
    int CV3VectorAdd(CV3VectorHandle vresult, const CV3VectorHandle u,  const CV3VectorHandle v );
    CV3VectorHandle CV3vVectorAdd(const CV3VectorHandle u,  const CV3VectorHandle v );
    
    /* vector difference of 2 3-vectors */
    
    int CV3VectorSubtract(CV3VectorHandle vresult, const CV3VectorHandle u,  const CV3VectorHandle v );
    CV3VectorHandle CV3vVectorSubtract(const CV3VectorHandle u,  const CV3VectorHandle v );
    
    /* negate a vector */
    
    int CV3VectorNegate(CV3VectorHandle vresult, const CV3VectorHandle u );
    CV3VectorHandle CV3vVectorNegate(const CV3VectorHandle u );
    
    /* L2 norm squared of a vector */
    
    int CV3Normsq(double CV3_FAR * dresult, const CV3VectorHandle u );
    double CV3dNormsq(const CV3VectorHandle u);
    
    /* L2 norm of a vector */
    
    int CV3Norm(double CV3_FAR * dresult, const CV3VectorHandle u );
    double CV3dNorm(const CV3VectorHandle u);
   
    /* Unit vector from a vector */
    
    int CV3UnitVector(CV3VectorHandle vresult, const CV3VectorHandle u);
    CV3VectorHandle CV3vUnitVector(const CV3VectorHandle u);
    
    /* angle v1-v2, v3-v2 formed by three vectors, v1, v2, v3 */
    
    
    int CV3Angle3(double CV3_FAR * angle,  const CV3VectorHandle v1, const CV3VectorHandle v2, const CV3VectorHandle v3);
    double CV3dAngle3(const CV3VectorHandle v1, const CV3VectorHandle v2, const CV3VectorHandle v3);
    
    /* angle v1, v2 */
    
    int CV3Angle2(double CV3_FAR * angle,  const CV3VectorHandle v1, const CV3VectorHandle v2);
    double CV3dAngle2(const CV3VectorHandle v1, const CV3VectorHandle v2);
    
    /* Torsion angle angle v1, v2, v3, v4 */
    
    int CV3Torsion(double CV3_FAR * angle,  const CV3VectorHandle v1, const CV3VectorHandle v2, const CV3VectorHandle v3, const CV3VectorHandle v4);
    double CV3dTorsion(const CV3VectorHandle v1, const CV3VectorHandle v2, const CV3VectorHandle v3, const CV3VectorHandle v4);
    
    /* matrix product of 2 matrices */
    
    int CV3MatrixMultiply(CV3MatrixHandle mresult, const CV3MatrixHandle m1, const CV3MatrixHandle m2);
    CV3MatrixHandle CV3mMatrixMultiply(const CV3MatrixHandle m1, const CV3MatrixHandle m2);
    
    /* Initialize a matrix from 9 scalars */
    
    int CV3MatrixFrom9Scalars(CV3MatrixHandle mresult, const double m00, const double m01, const double m02,
                                       const double m10, const double m11, const double m12,
                                       const double m20, const double m21, const double m22);
    CV3MatrixHandle CV3mMatrixFrom9Scalars(const double m00, const double m01, const double m02,
                                           const double m10, const double m11, const double m12,
                                           const double m20, const double m21, const double m22);
    /* Copy a matrix */
    
    int CV3CopyMatrix(CV3MatrixHandle mresult, const CV3MatrixHandle m);
    CV3MatrixHandle CV3mCopyMatrix(const CV3MatrixHandle m);
    
    /* Create a rotation matrix from an axis vector and an angle */
    
    int CV3Rotmat(CV3MatrixHandle mresult, const CV3VectorHandle u, const double angle);
    CV3MatrixHandle CV3mRotmat(const CV3VectorHandle u, const double angle);
    
    /* Create a rotation matrix that rotates vector x1 to conincide
     with vector z1 and puts x2 into the z1-z2 plane as close to
     vector z2 as possible
     */
    
    int CV3Pair(CV3MatrixHandle mresult, const CV3VectorHandle x1,  const CV3VectorHandle x2,  
                         const CV3VectorHandle z1,  const CV3VectorHandle z2);
    CV3MatrixHandle CV3mPair(const CV3VectorHandle x1,  const CV3VectorHandle x2,  
                             const CV3VectorHandle z1,  const CV3VectorHandle z2);
    
    /* Test if two vectors are equal */
    
    int CV3VectorsEqual(int CV3_FAR * bresult, const CV3VectorHandle u, const CV3VectorHandle v);
    int CV3bVectorsEqual(const CV3VectorHandle u, const CV3VectorHandle v);

    /* Get the quaternion to rotate one vector into another */
    
    int CV3QuaternionFromPair(CQRQuaternionHandle qresult, const CV3VectorHandle u, const CV3VectorHandle v);
    
    /* Get the center of mass from a CVector of vectors */
    
    int CV3GetCenterOfMass(CV3VectorHandle vresult, const CVectorHandle vv);
    CV3VectorHandle CV3vGetCenterOfMass(const CVectorHandle vv);
    
    /* Get the interial tensor for a single point with a weight */
    
    int CV3InertiaTensorForPoint(CV3MatrixHandle mresult, CV3VectorHandle v, double weight );
    CV3MatrixHandle CV3mInertiaTensorForPoint(CV3VectorHandle v, const double weight );
    
    /* Get the matrices for the rotated components of the X, Y and Z axes */
    
    int CV3UNX(CV3MatrixHandle mresult, const CV3MatrixHandle m);
    
    int CV3UNY(CV3MatrixHandle mresult, const CV3MatrixHandle m);
    
    int CV3UNZ(CV3MatrixHandle mresult, const CV3MatrixHandle m);
    
    CV3MatrixHandle CV3mUNX(const CV3MatrixHandle m);
    
    CV3MatrixHandle CV3mUNY(const CV3MatrixHandle m);
    
    CV3MatrixHandle CV3mUNZ(const CV3MatrixHandle m);
    
    
    /* Initialize a Line from 2 vectors */
    
    int CV3LineFrom2Vectors(CV3LineHandle lresult, const CV3VectorHandle direction, 
                                     const CV3VectorHandle centerOfMass);
    
    /* Recover the axis of a line */
    
    int CV3LineAxis(CV3VectorHandle vresult, const CV3LineHandle line);
    CV3VectorHandle CV3vLineAxis(const CV3LineHandle line);
    
    /* Recover the basepoint of a line */
    
    int CV3LineBasePoint(CV3VectorHandle vresult, const CV3LineHandle line);
    CV3VectorHandle CV3vLineBasePoint(const CV3LineHandle line);
    
    
    /* Initialize a plane from 2 vectors */
    
    int CV3PlaneFrom2Vectors(CV3PlaneHandle presult, const CV3VectorHandle direction, 
                                      const CV3VectorHandle centerOfMass);
    
    /* Recover the normal of a plane */
    
    int CV3PlaneNormal(CV3VectorHandle vresult, const CV3PlaneHandle plane);
    CV3VectorHandle CV3vPlaneNormal(const CV3PlaneHandle plane);
    
    /* Recover the basepoint of a plane */
    
    int CV3PlaneBasePoint(CV3VectorHandle vresult, const CV3PlaneHandle plane);
    CV3VectorHandle CV3vPlaneBasePoint(const CV3PlaneHandle plane);
    
    /* matrix sum of 2 matrices */
    
    int CV3MatrixAdd(CV3MatrixHandle mresult, const CV3MatrixHandle m1,  const CV3MatrixHandle m2 );
    CV3MatrixHandle CV3mMatrixAdd(const CV3MatrixHandle m1,  const CV3MatrixHandle m2 );
    
    /* matrix difference of 2 matrices */
    
    int CV3MatrixSubtract(CV3MatrixHandle mresult, const CV3MatrixHandle m1,  const CV3MatrixHandle m2 );
    CV3MatrixHandle CV3mMatrixSubtract(const CV3MatrixHandle m1,  const CV3MatrixHandle m2 );
    
    /* Multiply a matrix by a scalar*/
    
    int CV3MatrixScalarMultiply(CV3MatrixHandle mresult, const CV3MatrixHandle m, const double s);
    CV3MatrixHandle CV3mMatrixScalarMultiply(const CV3MatrixHandle m, const double s);
    
    /* Divide a matrix by a scalar*/
    
    int CV3MatrixScalarDivide(CV3MatrixHandle mresult, const CV3MatrixHandle m, const double s);
    CV3MatrixHandle CV3mMatrixScalarDivide(const CV3MatrixHandle m, const double s);
    
    /* Multiply a matrix by a vector*/
    
    int CV3MatrixVectorMultiply(CV3VectorHandle lresult, const CV3MatrixHandle m, const CV3VectorHandle v);
    CV3VectorHandle CV3vMatrixVectorMultiply(const CV3MatrixHandle m, const CV3VectorHandle v);
    
    /* Tensor product of a vector by a vector*/
    
    int CV3TensorProduct(CV3MatrixHandle mresult, const CV3VectorHandle u, const CV3VectorHandle v);
    CV3MatrixHandle CV3mTensorProduct(const CV3VectorHandle u, const CV3VectorHandle v);
    
    /* Matrix Transpose */
    
    int CV3Transpose(CV3MatrixHandle mresult, const CV3MatrixHandle m);
    CV3MatrixHandle CV3mTranspose(const CV3MatrixHandle m);
    
    /* Determinant */
    
    int CV3Determinant(double * dresult, const CV3MatrixHandle m);
    double CV3dDeterminant(const CV3MatrixHandle m);
    
    /* Matrix Inverse */
    
    int CV3Inverse(CV3MatrixHandle mresult, const CV3MatrixHandle m);
    CV3MatrixHandle CV3mInverse(const CV3MatrixHandle m);

    /* Distance from Line */
    
    int CV3DistanceFromLine(double * dresult, const CV3LineHandle line, const CV3VectorHandle vector );
    double CV3dDistanceFromLine(const CV3LineHandle line, const CV3VectorHandle vector );

    /* Distance from Plane */
    
    int CV3DistanceFromPlane(double * dresult, const CV3PlaneHandle plane, const CV3VectorHandle vector );
    double CV3dDistanceFromPlane(const CV3PlaneHandle plane, const CV3VectorHandle vector );
    
    /* Intersection line for 2 planes */
    
    int CV3Intersect(CV3LineHandle lresult, const CV3PlaneHandle p1, const CV3PlaneHandle p2);
    
    /* Rotate a vector by a quaternion */
    
    int CV3RotateByQuaternion(CV3VectorHandle vresult, const CQRQuaternionHandle q, const CV3VectorHandle v);
    CV3VectorHandle CV3vRotateByQuaternion(const CQRQuaternionHandle q, const CV3VectorHandle v);
    
    /* Convert a matrix to a quaternion */
    
    int CV3Matrix2Quaternion(CQRQuaternionHandle qresult, const CV3MatrixHandle m);
    
    /* Convert a quaternion to a matrix */
    
    int CV3Quaternion2Matrix(CV3MatrixHandle mresult, const CQRQuaternionHandle q);
    CV3MatrixHandle CV3mQuaternion2Matrix(const CQRQuaternionHandle q);
    
    /* Get the largest eigenvalue and associated eigenvector from a matrix */

    int CV3Eigen1(double CV3_FAR * eigenvalue, const CV3VectorHandle eigenvector, const CV3MatrixHandle matrix);

    /* Get the eigenvalues and associated eigenvectors from a matrix */
    
    int CV3Eigen3(double eigenvalues[3], CV3Vector eigenvectors[3], const CV3MatrixHandle matrix);
    
    /* Best Plane and Best Line */
    
    int CV3BestPlane(CV3PlaneHandle presult, CVectorHandle vv);
    
    int CV3BestLine(CV3LineHandle lresult, CVectorHandle vv);
                                                 
    /* Matrix to go from fractional to orthogonal coordinates */
    
    int CV3Cart(CV3MatrixHandle mresult, double a, double b, double c, double alpha, double beta, double gamma);
    CV3MatrixHandle CV3mCart(double a, double b, double c, double alpha, double beta, double gamma);
     
#ifdef __cplusplus
    
}

#endif
#endif


