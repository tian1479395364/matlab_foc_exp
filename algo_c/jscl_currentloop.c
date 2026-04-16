#include "jscl_currentloop.h"

// ==================== 全局 PI 参数 ====================
PI_Params PI_D = {1.0, 0.3,  10.0, -10.0};   // d轴参数，饱和值 ±10
PI_Params PI_Q = {1.0, 0.3,  10.0, -10.0};   // q轴参数，饱和值 ±10

// 静态积分项
static double integral_d = 0.0;
static double integral_q = 0.0;

void CurrentLoopDQ(double IRefD,
				   double ISensD,
                   double IRefQ,
                   double ISensQ,
				   double d_kp_param,
                   double d_ki_param,
				   double q_kp_param,
                   double q_ki_param,
				   VectorDQ_T *dq_out)	   
{
    double err_d, err_q;
    double out_d, out_q;

    /* ====================== d轴 PI ====================== */
    err_d = IRefD - ISensD;
    out_d = PI_D.Kp * err_d + PI_D.Ki * integral_d;

    // 限幅 + 抗积分饱和
    if (out_d > PI_D.UpperLim) {
        out_d = PI_D.UpperLim;
    } else if (out_d < PI_D.LowerLim) {
        out_d = PI_D.LowerLim;
    } else {
        integral_d += err_d;        // 未饱和时更新积分
    }

    /* ====================== q轴 PI ====================== */
    err_q = IRefQ - ISensQ;
    out_q = PI_Q.Kp * err_q + PI_Q.Ki * integral_q;

    if (out_q > PI_Q.UpperLim) {
        out_q = PI_Q.UpperLim;
    } else if (out_q < PI_Q.LowerLim) {
        out_q = PI_Q.LowerLim;
    } else {
        integral_q += err_q;
    }

    dq_out->s64_d = out_d;
    dq_out->s64_q = out_q;
}