#ifndef JSCL_TRANSFORM_H
#define JSCL_TRANSFORM_H

/**
 * \brief 2D-vector for alpha/beta domain
 */
typedef struct VectorAB_S {
    double s64_alpha;   /**< alpha */
    double s64_beta;    /**< beta  */
} VectorAB_T;

/**
 * \brief 2D-vector for d/q domain
 */
typedef struct VectorDQ_S {
    double s64_d;       /**< d */
    double s64_q;       /**< q */
} VectorDQ_T;

/**
 * \brief 3D-vector in ABC domain
 */
typedef struct VectorUVW_S {
    double s64_u;       /**< phase U/A */
    double s64_v;       /**< phase V/B */
    double s64_w;       /**< phase W/C */
} VectorUVW_T;

/* ====================== 函数声明 ====================== */

/* Clarke Transform: ABC → αβ */
void ClarkeTransform(const VectorUVW_T *ABC_in, VectorAB_T *AB_out);

/* Park Transform: αβ → dq */
void ParkTransform(const VectorAB_T *AB_in, const double sin_cos[2], VectorDQ_T *DQ_out);

/* Inverse Park Transform: dq → αβ */
void InverseParkTransform(const VectorDQ_T *in, const double sin_cos[2], VectorAB_T *out);

/* Inverse Clarke Transform: αβ → ABC */
void InverseClarkeTransform(const VectorAB_T *AB_in, VectorUVW_T *ABC_out);

void CalcZeroSequenceVoltage(const VectorUVW_T *u_abc, 
                             double *u_zero);						 

#endif