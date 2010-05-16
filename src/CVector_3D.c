/*
 *  CVector_3D.c
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

#ifdef __cplusplus

extern "C" {
    
#endif
    
#define USE_LOCAL_HEADERS
#define CV3_DATA_DEFS
#ifdef USE_LOCAL_HEADERS
#include "CVector_3D.h"
#else
#include <CVector_3D.h>
#endif
    
    /* Copy a Match Object */
    
    int CV3CopyMatchObject(CV3MatchObjectHandle moresult, const CV3MatchObjectHandle mo) {
        if (!moresult || !mo) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_ooCopy(*moresult,*mo);
        return 0;
    }
    
    /* Compare Match Objects */
    
    int CV3CompareMatchObject(int CV3_FAR * bresult, const CV3MatchObjectHandle mo1, const CV3MatchObjectHandle mo2) {
        if (!bresult || !mo1 || !mo2) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_booCompare(*bresult,*mo1,*mo2);
        return 0;
    }
    
    /* Create a Vector */
    
    int CV3CreateVector(CV3VectorHandle CV3_FAR  * vhandle) {
        if (!vhandle) return CVECTOR_3D_BAD_ARGUMENT;
        if (!(*vhandle=(CV3VectorHandle)CV3_MALLOC(sizeof(CV3Vector)))) return CVECTOR_3D_MALLOC;
        CV3_MemoryUsed += sizeof(CV3Vector);
        CV3M_debugstatement(fprintf(stderr," CV3CreateVector on exit %ld\n", (long)CV3_MemoryUsed));
        return 0;
    }
    
    /* Create a Matrix */
    
    int CV3CreateMatrix(CV3MatrixHandle CV3_FAR  * mhandle) {
        if (!mhandle) return CVECTOR_3D_BAD_ARGUMENT;
        if (!(*mhandle=(CV3MatrixHandle)CV3_MALLOC(sizeof(CV3Matrix)))) return CVECTOR_3D_MALLOC;
        CV3_MemoryUsed += sizeof(CV3Matrix);
        CV3M_debugstatement(fprintf(stderr," CV3CreateMatrix on exit %ld\n", (long)CV3_MemoryUsed));
        return 0;
    }
    
    /* Free a Vector */
    
    int CV3FreeVector(CV3VectorHandle vhandle) {
        if (!vhandle) return CVECTOR_3D_BAD_ARGUMENT;
        CV3_FREE(vhandle);
        CV3_MemoryUsed -= sizeof(CV3Vector);
        CV3M_debugstatement(fprintf(stderr," CV3FreeVector on exit %ld\n", (long)CV3_MemoryUsed));
        return 0;
    }
    
    /* Free a Matrix */
    
    int CV3FreeMatrix(CV3MatrixHandle mhandle) {
        if (!mhandle) return CVECTOR_3D_BAD_ARGUMENT;
        CV3_FREE(mhandle);
        CV3_MemoryUsed -= sizeof(CV3Matrix);
        CV3M_debugstatement(fprintf(stderr," CV3FreeMatrix on exit %ld\n", (long)CV3_MemoryUsed));
        return 0;
    }
    
    /* Vector to CVector */
    
    int CV3Vector2CVector(double cv[3], const CV3VectorHandle v ) {
        if (!v || !cv) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_cvvSet(cv,*v);
        return 0;
    }
    

    /* CVector to Vector */
    
    int CV3CVector2Vector(CV3VectorHandle v, const double cv[3]) {
        if (!v || !cv) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_vcvSet(*v,cv);
        return 0;
    }
    
    CV3VectorHandle CV3vCVector2Vector(const double cv[3]) {
        CV3VectorHandle v;
        if (CV3CreateVector(&v) || !cv) return (CV3VectorHandle)NULL;
        CV3M_vcvSet(*v,cv);
        return v;
    }
    
    /* Matrix to CMatrix */
    
    int CV3Matrix2CMatrix(double cm[3][3], const CV3MatrixHandle m ) {
        if (!m || !cm) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_cmmSet(cm,*m);
        return 0;
    }
    
    /* CMatrix to Matrix */
    
    int CV3CMatrix2Matrix(CV3MatrixHandle m, const double cm[3][3]) {
        if (!m || !cm) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_mcmSet(*m,cm);
        return 0;
    }

    CV3MatrixHandle CV3mCMatrix2Matrix(const double cm[3][3]) {
        CV3MatrixHandle m;
        if (CV3CreateMatrix(&m) || !cm) return (CV3MatrixHandle)NULL;
        CV3M_mcmSet(*m,cm);
        return m;
    }
        
    /* Initialize a vector from 3 scalars */
    
    int CV3VectorFrom3Scalars(CV3VectorHandle v, const double x, const double y, const double z) {
        if (!v) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_vsssSet(*v,x,y,z);
        return 0;
    }
    
    CV3VectorHandle CV3vVectorFrom3Scalars(const double x, const double y, const double z) {
        CV3VectorHandle v;
        if (CV3CreateVector(&v)) return (CV3VectorHandle)NULL;
        CV3M_vsssSet(*v,x,y,z);
        return v;
    }

    /* Initialize a vector from 1 scalar */
    
    int CV3VectorFromScalar(CV3VectorHandle v, const double s) {
        if (!v) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_vsSet(*v,s);
        return 0;
    }
    
    CV3VectorHandle CV3vVectorFromScalar(const double s) {
        CV3VectorHandle v;
        if (CV3CreateVector(&v)) return (CV3VectorHandle)NULL;
        CV3M_vsSet(*v,s);
        return v;
    }
    
    
    /* Copy a vector */
    
    int CV3CopyVector(CV3VectorHandle v, const CV3VectorHandle u) {
        if (!u || !v) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_vvCopy(*v, *u);
        return 0;
    }

    CV3VectorHandle CV3vCopyVector(const CV3VectorHandle u) {
        CV3VectorHandle v;
        if (CV3CreateVector(&v)) return (CV3VectorHandle)NULL;
        CV3M_vvCopy(*v, *u);
        return v;
    }
    
    /* Multiply a vector by a scalar*/
    
    int CV3VectorScalarMultiply(CV3VectorHandle v, const CV3VectorHandle u, const double s) {
        if (!u || !v) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_vvsMultiply(*v, *u, s);
        return 0;
    }

    CV3VectorHandle CV3vVectorScalarMultiply(const CV3VectorHandle u, const double s) {
        CV3VectorHandle v;
        if (CV3CreateVector(&v) || !u) return (CV3VectorHandle)NULL;
        CV3M_vvsMultiply(*v, *u, s);
        return v;
    }
    
    /* Divide a vector by a scalar*/
    
    int CV3VectorScalarDivide(CV3VectorHandle v, const CV3VectorHandle u, const double s) {
        if (!u || !v || s == 0.) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_vvsDivide(*v, *u, s);
        return 0;
    }

    CV3VectorHandle CV3vVectorScalarDivide(const CV3VectorHandle u, const double s) {
        CV3VectorHandle v;
        if (CV3CreateVector(&v) || !u || s == 0.) return (CV3VectorHandle)NULL;
        CV3M_vvsDivide(*v, *u, s);
        return v;
    }
    
    /* dot product of 2 3-vectors */
    
    int CV3Dot(double CV3_FAR * dresult,  const CV3VectorHandle u,  const CV3VectorHandle v ) {
        if (!dresult || !u || !v) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_svvDot(*dresult,*u,*v);
        return 0;
    }

    double CV3dDot(const CV3VectorHandle u,  const CV3VectorHandle v ) {
        double dresult;
        if (!u || !v) return 0;
        CV3M_svvDot(dresult,*u,*v);
        return dresult;
    }
    
    /* cross product of 2 3-vectors */
    
    int CV3Cross(CV3VectorHandle vresult, const CV3VectorHandle u,  const CV3VectorHandle v ) {
        if (!vresult || !u || !v) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_vvvCross(*vresult,*u,*v);
        return 0;
    }
    
    CV3VectorHandle CV3vCross(const CV3VectorHandle u,  const CV3VectorHandle v ) {
        CV3VectorHandle vresult;
        if (CV3CreateVector(&vresult) || !u || !v) return (CV3VectorHandle)NULL;
        CV3M_vvvCross(*vresult,*u,*v);
        return vresult;
    }
    
    /* dyad product of 2 3-vectors */
    
    int CV3DyadProduct(CV3VectorHandle vresult, const CV3VectorHandle u,  const CV3VectorHandle v ) {
        if (!vresult || !u || !v) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_vvvDyadProduct(*vresult,*u,*v);
        return 0;
    }
    
    CV3VectorHandle CV3vDyadProduct(const CV3VectorHandle u,  const CV3VectorHandle v) {
        CV3VectorHandle vresult;
        if (CV3CreateVector(&vresult) || !u || !v) return (CV3VectorHandle)NULL;
        CV3M_vvvDyadProduct(*vresult,*u,*v);
        return vresult;
    }
    
    /* vector sum of 2 3-vectors */
    
    int CV3VectorAdd(CV3VectorHandle vresult, const CV3VectorHandle u,  const CV3VectorHandle v ) {
        if (!vresult || !u || !v) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_vvvAdd(*vresult,*u,*v);
        return 0;
    }
    
    CV3VectorHandle CV3vVectorAdd(const CV3VectorHandle u,  const CV3VectorHandle v ) {
        CV3VectorHandle vresult;
        if (CV3CreateVector(&vresult) || !u || !v) return (CV3VectorHandle)NULL;
        CV3M_vvvAdd(*vresult,*u,*v);
        return vresult;
    }

    /* vector difference of 2 3-vectors */
    
    int CV3VectorSubtract(CV3VectorHandle vresult, const CV3VectorHandle u,  const CV3VectorHandle v ) {
        if (!vresult || !u || !v) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_vvvSubtract(*vresult,*u,*v);
        return 0;
    }

    CV3VectorHandle CV3vVectorSubtract(const CV3VectorHandle u,  const CV3VectorHandle v ) {
        CV3VectorHandle vresult;
        if (CV3CreateVector(&vresult) || !u || !v) return (CV3VectorHandle)NULL;
        CV3M_vvvSubtract(*vresult,*u,*v);
        return vresult;
    }
    
    /* negate a vector */
    
    int CV3VectorNegate(CV3VectorHandle vresult, const CV3VectorHandle u ) {
        if (!vresult || !u ) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_vvNegate(*vresult,*u);
        return 0;
    }

    CV3VectorHandle CV3vVectorNegate(const CV3VectorHandle u ) {
        CV3VectorHandle vresult;
        if (CV3CreateVector(&vresult) || !u) return (CV3VectorHandle)NULL;
        CV3M_vvNegate(*vresult,*u);
        return vresult;
    }
    
    /* L2 norm squared of a vector */
    
    int CV3Normsq(double CV3_FAR * dresult, const CV3VectorHandle u ) {
        if (!dresult || !u ) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_svNormsq(*dresult,*u);
        return 0;
    }

    double CV3dNormsq(const CV3VectorHandle u ) {
        double dresult;
        if (!u ) return 0.;
        CV3M_svNormsq(dresult,*u);
        return dresult;
    }
    
    /* L2 norm of a vector */
    
    int CV3Norm(double CV3_FAR * dresult, const CV3VectorHandle u ) {
        if (!dresult || !u ) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_svNorm(*dresult,*u);
        return 0;
    }
    
    double CV3dNorm(const CV3VectorHandle u ) {
        double dresult;
        if (!u ) return 0.;
        CV3M_svNorm(dresult,*u);
        return dresult;
    }
    
    /* Unit vector from a vector */
    
    int CV3UnitVector(CV3VectorHandle vresult, const CV3VectorHandle u) {
        if (!vresult || !u ) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_vvUnitV(*vresult,*u);
        return 0;
    }

     CV3VectorHandle CV3vUnitVector(const CV3VectorHandle u) {
        CV3VectorHandle vresult;
        if (CV3CreateVector(&vresult) || !u) return (CV3VectorHandle)NULL;
        CV3M_vvUnitV(*vresult,*u);
        return vresult;
    }
    
    /* angle v1-v2, v3-v2 formed by three vectors, v1, v2, v3 */
    
    
    int CV3Angle3(double CV3_FAR * angle,  const CV3VectorHandle v1, const CV3VectorHandle v2, const CV3VectorHandle v3) {
        if (!angle || !v1 || !v2 || !v3) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_svvvAngle(*angle,*v1,*v2,*v3);
        return 0;
    }
    
    double CV3dAngle3(const CV3VectorHandle v1, const CV3VectorHandle v2, const CV3VectorHandle v3) {
        double angle;
        if( !v1 || !v2 || !v3) return 0.;
        CV3M_svvvAngle(angle,*v1,*v2,*v3);
        return angle;
    }

    /* angle v1, v2 */
    
    int CV3Angle2(double CV3_FAR * angle,  const CV3VectorHandle v1, const CV3VectorHandle v2) {
        if (!angle || !v1 || !v2 ) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_svvAngle(*angle,*v1,*v2);
        return 0;
    }
    
    double CV3dAngle(const CV3VectorHandle v1, const CV3VectorHandle v2) {
        double angle;
        if( !v1 || !v2) return 0.;
        CV3M_svvAngle(angle,*v1,*v2);
        return angle;
    }

    /* Torsion angle angle v1, v2, v3, v4 */
    
    int CV3Torsion(double CV3_FAR * angle,  const CV3VectorHandle v1, const CV3VectorHandle v2, const CV3VectorHandle v3, const CV3VectorHandle v4) {
        if (!angle || !v1 || !v2 || !v3 || !v4 ) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_svvvvTorsion(*angle,*v1,*v2,*v3,*v4);
        return 0;
    }
    
    double CV3dTorsion(const CV3VectorHandle v1, const CV3VectorHandle v2, const CV3VectorHandle v3, const CV3VectorHandle v4) {
        double angle;
        if( !v1 || !v2 || !v3 || !v4 ) return 0.;
        CV3M_svvvvTorsion(angle,*v1,*v2,*v3,*v4);
        return angle;
    }

    /* matrix product of 2 matrices */
    
    int CV3MatrixMultiply(CV3MatrixHandle mresult, const CV3MatrixHandle m1, const CV3MatrixHandle m2) {
        if (!mresult || !m1 || !m2) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_mmmMultiply(*mresult,*m1,*m2);
        return 0;
    }
    
    CV3MatrixHandle CV3mMatrixMultiply(const CV3MatrixHandle m1, const CV3MatrixHandle m2) {
        CV3MatrixHandle mresult;
        if (CV3CreateMatrix(&mresult) || !m1 || !m2) return (CV3MatrixHandle)NULL;
        CV3M_mmmMultiply(*mresult,*m1,*m2);
        return mresult;
    }

    /* Initialize a matrix from 9 scalars */
    
    int CV3MatrixFrom9Scalars(CV3MatrixHandle mresult, const double m00, const double m01, const double m02,
                                       const double m10, const double m11, const double m12,
                                       const double m20, const double m21, const double m22) {
        if (!mresult) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_msssssssssSet(*mresult,m00,m01,m02,m10,m11,m12,m20,m21,m22)
        return 0;
    }
    
    CV3MatrixHandle CV3mMatrixFrom9Scalars(const double m00, const double m01, const double m02,
                              const double m10, const double m11, const double m12,
                              const double m20, const double m21, const double m22) {
        CV3MatrixHandle mresult;
        if (CV3CreateMatrix(&mresult)) return (CV3MatrixHandle)NULL;
        CV3M_msssssssssSet(*mresult,m00,m01,m02,m10,m11,m12,m20,m21,m22)
        return mresult;
    }

    /* Copy a matrix */
    
    int CV3CopyMatrix(CV3MatrixHandle mresult, const CV3MatrixHandle m) {
        if (!mresult || !m) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_mmCopy(*mresult, *m);
        return 0;
    }

    CV3MatrixHandle CV3mCopyMatrix(const CV3MatrixHandle m) {
        CV3MatrixHandle mresult;
        if (CV3CreateMatrix(&mresult) || !m) return (CV3MatrixHandle)NULL;
        CV3M_mmCopy(*mresult, *m);
        return mresult;
    }
    
    /* Create a rotation matrix from an axis vector and an angle */
    
    int CV3Rotmat(CV3MatrixHandle mresult, const CV3VectorHandle u, const double angle) {
        if (!mresult || !u) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_mvsRotmat(*mresult,*u,angle);
        return 0;
    }

    CV3MatrixHandle CV3mRotmat(const CV3VectorHandle u, const double angle) {
        CV3MatrixHandle mresult;
        if (CV3CreateMatrix(&mresult) || !u) return (CV3MatrixHandle)NULL;
        CV3M_mvsRotmat(*mresult,*u,angle);
        return mresult;
    }
    
    /* Create a rotation matrix that rotates vector x1 to conincide
     with vector z1 and puts x2 into the z1-z2 plane as close to
     vector z2 as possible
     */
    
    int CV3Pair(CV3MatrixHandle mresult, const CV3VectorHandle x1,  const CV3VectorHandle x2,  
                         const CV3VectorHandle z1,  const CV3VectorHandle z2) {
        if (!mresult || !x1 || !x2 || !z1 || !z2) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_mvvvvPair(*mresult,*x1,*x2,*z1,*z2);
        return 0;
    }

    CV3MatrixHandle CV3mPair(const CV3VectorHandle x1,  const CV3VectorHandle x2,  
                const CV3VectorHandle z1,  const CV3VectorHandle z2) {
        CV3MatrixHandle mresult;
        if (CV3CreateMatrix(&mresult) || !x1 || !x2 || !z1 || !z2) return (CV3MatrixHandle)NULL;
        CV3M_mvvvvPair(*mresult,*x1,*x2,*z1,*z2);
        return mresult;
    }
    
    /* Test if two vectors are equal */
    
    int CV3VectorsEqual(int CV3_FAR * bresult, const CV3VectorHandle u, const CV3VectorHandle v) {
        if (!bresult || !u || !v) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_bvvEquals(*bresult,*u,*v);
        return 0;
    }
    
    int CV3bVectorsEqual(const CV3VectorHandle u, const CV3VectorHandle v) {
        int bresult;
        if (!u || !v) return 0;
        CV3M_bvvEquals(bresult,*u,*v);
        return bresult;
    }
    
    /* Get the quaternion to rotate one vector into another */
    
    int CV3QuaternionFromPair(CQRQuaternionHandle qresult, const CV3VectorHandle u, const CV3VectorHandle v) {
        if (!qresult || !u || !v) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_qvvQuaternionFromPair(*qresult,*u,*v);
        return 0;
    }
    
    /* Get the center of mass from a CVector of vectors */
    
    int CV3GetCenterOfMass(CV3VectorHandle vresult, const CVectorHandle vv) {
        if (!vresult || !vv) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_vaGetCenterOfMass(*vresult,vv);
        return 0;
    }

    CV3VectorHandle CV3vGetCenterOfMass(const CVectorHandle vv) {
        CV3VectorHandle vresult;
        if (CV3CreateVector(&vresult) || !vv) return (CV3VectorHandle)NULL;
        CV3M_vaGetCenterOfMass(*vresult,vv);
        return vresult;
    }
    
    /* Get the interial tensor for a single point with a weight */
    
    int CV3InertiaTensorForPoint(CV3MatrixHandle mresult, CV3VectorHandle v, const double weight ) {
        if (!mresult || !v) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_mvsInertiaTensorForPoint(*mresult,*v,weight);
        return 0;
    }
    
    CV3MatrixHandle CV3mInertiaTensorForPoint(CV3VectorHandle v, const double weight ) {
        CV3MatrixHandle mresult;
        if (CV3CreateMatrix(&mresult) || !v) return (CV3MatrixHandle)NULL;
        CV3M_mvsInertiaTensorForPoint(*mresult,*v,weight);
        return mresult;
    }

    /* Get the matrices for the rotated components of the X, Y and Z axes */
    
    int CV3UNX(CV3MatrixHandle mresult, const CV3MatrixHandle m) {
        if (!mresult || !m) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_mmUNX(*mresult,*m);
        return 0;
    }
    
    int CV3UNY(CV3MatrixHandle mresult, const CV3MatrixHandle m) {
        if (!mresult || !m) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_mmUNY(*mresult,*m);
        return 0;
    }
    
    int CV3UNZ(CV3MatrixHandle mresult, const CV3MatrixHandle m) {
        if (!mresult || !m) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_mmUNZ(*mresult,*m);
        return 0;
    }

    CV3MatrixHandle CV3mUNX(const CV3MatrixHandle m) {
        CV3MatrixHandle mresult;
        if (CV3CreateMatrix(&mresult) || !m) return (CV3MatrixHandle)NULL;
        CV3M_mmUNX(*mresult,*m);
        return mresult;
    }
    
    CV3MatrixHandle CV3mUNY(const CV3MatrixHandle m) {
        CV3MatrixHandle mresult;
        if (CV3CreateMatrix(&mresult) || !m) return (CV3MatrixHandle)NULL;
        CV3M_mmUNY(*mresult,*m);
        return mresult;
    }
    
    CV3MatrixHandle CV3mUNZ(const CV3MatrixHandle m) {
        CV3MatrixHandle mresult;
        if (CV3CreateMatrix(&mresult) || !m) return (CV3MatrixHandle)NULL;
        CV3M_mmUNZ(*mresult,*m);
        return mresult;
    }
    
    
    /* Initialize a Line from 2 vectors */
    
    int CV3LineFrom2Vectors(CV3LineHandle lresult, const CV3VectorHandle direction, 
                                     const CV3VectorHandle centerOfMass) {
        if (!lresult || !direction || !centerOfMass)  return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_lvvSet( *lresult, *direction, *centerOfMass);
        return 0;
    }
    
    /* Recover the axis of a line */
    
    int CV3LineAxis(CV3VectorHandle vresult, const CV3LineHandle line) {
        if (!vresult || !line)  return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_vlLineAxis( *vresult, *line);
        return 0;
    }

    CV3VectorHandle CV3vLineAxis(const CV3LineHandle line) {
        CV3VectorHandle vresult;
        if (CV3CreateVector(&vresult) || !line)  return (CV3VectorHandle)NULL;
        CV3M_vlLineAxis( *vresult, *line);
        return vresult;
    }
    
    /* Recover the basepoint of a line */
    
    int CV3LineBasePoint(CV3VectorHandle vresult, const CV3LineHandle line) {
        if (!vresult || !line)  return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_vlBasePoint( *vresult, *line);
        return 0;
    }

    CV3VectorHandle CV3vLineBasePoint(const CV3LineHandle line) {
        CV3VectorHandle vresult;
        if (CV3CreateVector(&vresult) || !line)  return (CV3VectorHandle)NULL;
        CV3M_vlBasePoint( *vresult, *line);
        return vresult;
    }
    
    
    /* Initialize a plane from 2 vectors */
    
    int CV3PlaneFrom2Vectors(CV3PlaneHandle presult, const CV3VectorHandle direction, 
                                      const CV3VectorHandle centerOfMass) {
        if (!presult || !direction || !centerOfMass)  return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_pvvSet( *presult, *direction, *centerOfMass);
        return 0;
    }
    
    /* Recover the normal of a plane */
    
    int CV3PlaneNormal(CV3VectorHandle vresult, const CV3PlaneHandle plane) {
        if (!vresult || !plane)  return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_vpNormalVector( *vresult, *plane);
        return 0;
    }
 
    CV3VectorHandle CV3vPlaneNormal(const CV3PlaneHandle plane) {
        CV3VectorHandle vresult;
        if (CV3CreateVector(&vresult) || !plane)  return (CV3VectorHandle)NULL;
        CV3M_vpNormalVector( *vresult, *plane);
        return vresult;
    }
    
    /* Recover the basepoint of a plane */
    
    int CV3PlaneBasePoint(CV3VectorHandle vresult, const CV3PlaneHandle plane) {
        if (!vresult || !plane)  return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_vlBasePoint( *vresult, *plane);
        return 0;
    }

    CV3VectorHandle CV3vPlaneBasePoint(const CV3PlaneHandle plane) {
        CV3VectorHandle vresult;
        if (CV3CreateVector(&vresult) || !plane)  return (CV3VectorHandle)NULL;
        CV3M_vlBasePoint( *vresult, *plane);
        return vresult;
    }
    
    /* matrix sum of 2 matrices */
    
    int CV3MatrixAdd(CV3MatrixHandle mresult, const CV3MatrixHandle m1,  const CV3MatrixHandle m2 ) {
        if (!mresult || !m1 || !m2) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_mmmAdd(*mresult,*m1,*m2);
        return 0;
    }
    
    CV3MatrixHandle CV3mMatrixAdd(const CV3MatrixHandle m1,  const CV3MatrixHandle m2 ) {
        CV3MatrixHandle mresult;
        if (CV3CreateMatrix(&mresult) || !m1 || !m2) return (CV3MatrixHandle)NULL;
        CV3M_mmmAdd(*mresult,*m1,*m2);
        return mresult;
    }

    /* matrix difference of 2 matrices */
    
    int CV3MatrixSubtract(CV3MatrixHandle mresult, const CV3MatrixHandle m1,  const CV3MatrixHandle m2 ) {
        if (!mresult || !m1 || !m2) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_mmmSubtract(*mresult,*m1,*m2);
        return 0;
    }

    CV3MatrixHandle CV3mMatrixSubtract(const CV3MatrixHandle m1,  const CV3MatrixHandle m2 ) {
        CV3MatrixHandle mresult;
        if (CV3CreateMatrix(&mresult) || !m1 || !m2) return (CV3MatrixHandle)NULL;
        CV3M_mmmSubtract(*mresult,*m1,*m2);
        return mresult;
    }
    
    /* Multiply a matrix by a scalar*/
    
    int CV3MatrixScalarMultiply(CV3MatrixHandle mresult, const CV3MatrixHandle m, const double s) {
        if (!mresult || !m) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_mmsMultiply(*mresult, *m, s);
        return 0;
    }

    CV3MatrixHandle CV3mMatrixScalarMultiply(const CV3MatrixHandle m, const double s) {
        CV3MatrixHandle mresult;
        if (CV3CreateMatrix(&mresult) || !m) return (CV3MatrixHandle)NULL;
        CV3M_mmsMultiply(*mresult, *m, s);
        return mresult;
    }
    
    /* Divide a matrix by a scalar*/
    
    int CV3MatrixScalarDivide(CV3MatrixHandle mresult, const CV3MatrixHandle m, const double s) {
        if (!mresult || !m || s==0.) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_mmsDivide(*mresult, *m, s);
        return 0;
    }
    
    CV3MatrixHandle CV3mMatrixScalarDivide(const CV3MatrixHandle m, const double s) {
        CV3MatrixHandle mresult;
        if (CV3CreateMatrix(&mresult) || !m || s==0.) return (CV3MatrixHandle)NULL;
        CV3M_mmsDivide(*mresult, *m, s);
        return mresult;
    }
    
    /* Multiply a matrix by a vector*/
    
    int CV3MatrixVectorMultiply(CV3VectorHandle vresult, const CV3MatrixHandle m, const CV3VectorHandle v) {
        if (!vresult || !m || !v) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_vmvMultiply(*vresult, *m, *v);
        return 0;
    }

    CV3VectorHandle CV3vMatrixVectorMultiply(const CV3MatrixHandle m, const CV3VectorHandle v) {
        CV3VectorHandle vresult;
        if(CV3CreateVector(&vresult) || !m || !v) return (CV3VectorHandle)NULL;
        CV3M_vmvMultiply(*vresult, *m, *v);
        return vresult;
    }
    
    /* Tensor product of a vector by a vector*/
    
    int CV3TensorProduct(CV3MatrixHandle mresult, const CV3VectorHandle u, const CV3VectorHandle v) {
        if (!mresult || !u || !v) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_mvvTensorProduct(*mresult, *u, *v);
        return 0;
    }

    CV3MatrixHandle CV3mTensorProduct(const CV3VectorHandle u, const CV3VectorHandle v) {
        CV3MatrixHandle mresult;
        if (CV3CreateMatrix(&mresult) || !u || !v) return (CV3MatrixHandle)NULL;
        CV3M_mvvTensorProduct(*mresult, *u, *v);
        return mresult;
    }
        
    /* Matrix Transpose */
    
    int CV3Transpose(CV3MatrixHandle mresult, const CV3MatrixHandle m) {
        if (!mresult || !m) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_mmTranspose(*mresult,*m);
        return 0;
    }

    CV3MatrixHandle CV3mTranspose(const CV3MatrixHandle m) {
        CV3MatrixHandle mresult;
        if (CV3CreateMatrix(&mresult) || !m) return (CV3MatrixHandle)NULL;
        CV3M_mmTranspose(*mresult,*m);
        return mresult;
    }
    
    /* Determinant */
    
    int CV3Determinant(double CV3_FAR * dresult, const CV3MatrixHandle m) {
        if (!dresult || !m) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_smDeterminant(*dresult,*m);
        return 0;
    }

    double CV3dDeterminant(const CV3MatrixHandle m) {
        double dresult;
        if (!m) return 0.;
        CV3M_smDeterminant(dresult,*m);
        return dresult;
    }
    
    /* Matrix Inverse */
    
    int CV3Inverse(CV3MatrixHandle mresult, const CV3MatrixHandle m) {
        if (!mresult || !m) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_mmInverse(*mresult,*m);
        return 0;
    }

    CV3MatrixHandle CV3mInverse(const CV3MatrixHandle m) {
        CV3MatrixHandle mresult;
        if (CV3CreateMatrix(&mresult) || !m) return (CV3MatrixHandle)NULL;
        CV3M_mmInverse(*mresult,*m);
        return mresult;
    }
    
    /* Distance from Line */
    
    int CV3DistanceFromLine(double CV3_FAR * dresult, const CV3LineHandle line, const CV3VectorHandle vector ) {
        if (!dresult || !line || !vector ) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_slvDistanceFromLine( *dresult, *line, *vector );
        return 0;
    }
    
    double CV3dDistanceFromLine(const CV3LineHandle line, const CV3VectorHandle vector ) {
        double dresult;
        if (!line || !vector ) return 0.;
        CV3M_slvDistanceFromLine( dresult, *line, *vector );
        return dresult;
    }
    
    /* Distance from Plane */
    
    int CV3DistanceFromPlane(double CV3_FAR * dresult, const CV3PlaneHandle plane, const CV3VectorHandle vector ) {
        if (!dresult || !plane || !vector ) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_spvDistanceFromPlane( *dresult, *plane, *vector );
        return 0;
    }
    
    double CV3dDistanceFromPlane(const CV3PlaneHandle plane, const CV3VectorHandle vector ) {
        double dresult;
        if (!plane || !vector ) return 0.;
        CV3M_spvDistanceFromPlane( dresult, *plane, *vector );
        return dresult;
    }

    /* Intersection line for 2 planes */
    
    int CV3Intersect(const CV3LineHandle lresult, const CV3PlaneHandle p1, const CV3PlaneHandle p2) {
        if (!lresult || !p1 || !p2) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_lppIntersect( *lresult, *p1, *p2 );
        return 0;
    }
    
    /* Rotate a vector by a quaternion */
    
    int CV3RotateByQuaternion(CV3VectorHandle vresult, const CQRQuaternionHandle q, const CV3VectorHandle v) {
        if (!vresult || !q || !v) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_vqvRotateByQuaternion(*vresult,*q,*v);
        return 0;
    }
    
    CV3VectorHandle CV3vRotateByQuaternion(const CQRQuaternionHandle q, const CV3VectorHandle v) {
        CV3VectorHandle vresult;
        if (CV3CreateVector(&vresult) || !q || !v) return (CV3VectorHandle)NULL;
        CV3M_vqvRotateByQuaternion(*vresult,*q,*v);
        return vresult;
    }

    /* Convert a matrix to a quaternion */
    
    int CV3Matrix2Quaternion(CQRQuaternionHandle qresult, const CV3MatrixHandle m){
        if (!qresult || !m) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_qmMatrix2Quaternion(*qresult,*m);
        return 0;
    }
    
    /* Convert a quaternion to a matrix */
    
    int CV3Quaternion2Matrix(CV3MatrixHandle mresult, const CQRQuaternionHandle q){
        if (!mresult || !q) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_mqQuaternion2Matrix(*mresult,*q);
        return 0;
    }
    
    CV3MatrixHandle CV3mQuaternion2Matrix(const CQRQuaternionHandle q){
        CV3MatrixHandle mresult;
        if (CV3CreateMatrix(&mresult) || !q) return (CV3MatrixHandle)NULL;
        CV3M_mqQuaternion2Matrix(*mresult,*q);
        return mresult;
    }
    
    /* Get the largest eigenvalue and associated eigenvector from a matrix */
    
    int CV3Eigen1(double CV3_FAR * eigenvalue, CV3VectorHandle eigenvector, const CV3MatrixHandle matrix) {
        if (!eigenvalue || !eigenvector || !matrix ) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_svmEigen1(*eigenvalue,*eigenvector,*matrix);
        return 0;
    }
    
    int CV3Eigen3(double eigenvalues[3], CV3Vector eigenvectors[3], const CV3MatrixHandle matrix) {
        if (!eigenvalues || !eigenvectors || !matrix ) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_aamEigen3(eigenvalues,eigenvectors,*matrix);
        return 0;
    }
    
    /* Best Plane and Best Line */
    
    int CV3BestPlane(CV3PlaneHandle presult, CVectorHandle vv) {
        if (!presult || !vv) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_paBestPlane(*presult,vv);
        return 0;
    }

    int CV3BestLine(CV3LineHandle lresult, CVectorHandle vv) {
        if (!lresult || !vv) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_laBestLine(*lresult,vv);
        return 0;
    }
    
    int CV3Cart(CV3MatrixHandle mresult, double a, double b, double c, double alpha, double beta, double gamma) {
        if (!mresult) return CVECTOR_3D_BAD_ARGUMENT;
        CV3M_mssssssCart(*mresult,a,b,c,alpha,beta,gamma);
        return 0;
    }
    
    CV3MatrixHandle CV3mCart(double a, double b, double c, double alpha, double beta, double gamma) {
        CV3MatrixHandle mresult;
        if (CV3CreateMatrix(&mresult)) return (CV3MatrixHandle)NULL;
        CV3M_mssssssCart(*mresult,a,b,c,alpha,beta,gamma);
        return mresult;
    }

    
#ifdef __cplusplus
    
}
        
#endif
        
