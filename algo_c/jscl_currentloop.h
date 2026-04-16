#ifndef JSCL_CURRENTLOOP_H
#define JSCL_CURRENTLOOP_H
#include "jscl_transform.h"
// PI 参数结构体
typedef struct {
    double Kp;       
    double Ki;       
    double UpperLim;   // 输出上限
    double LowerLim;   // 输出下限
} PI_Params;

// 函数声明
void CurrentLoopDQ(double IRefD,
				   double ISensD,
                   double IRefQ,
                   double ISensQ,
				   double d_kp_param,
                   double d_ki_param,
				   double q_kp_param,
                   double q_ki_param,				   
                   VectorDQ_T *dq_out);

#endif