

/* jscl_clarke.h */
#ifndef JSCL_CLARKE_H
#define JSCL_CLARKE_H

typedef struct {
    double ia;
    double ib;
    double ic;
} ClarkeInput;   // ← 输入结构体

typedef struct {
    double i_alpha;
    double i_beta;
} ClarkeOutput;  // ← 输出结构体（可选，如果你想把两个输出也打包）

void ClarkeTransform(const ClarkeInput *in_vector,   // const 指针更好，明确是输入
                     double *i_alpha,
                     double *i_beta);

#endif