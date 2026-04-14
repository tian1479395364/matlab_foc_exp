#ifndef JSCL_INVCLARKE_H
#define JSCL_INVCLARKE_H

// 输出三相电压结构体
typedef struct {
    double ua;
    double ub;
    double uc;
} UabcOutput;

// 函数声明
void InverseClarkeTransform(double u_alpha,
                            double u_beta,
                            UabcOutput *u_abc);

#endif