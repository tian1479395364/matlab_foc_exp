

#include "jscl_clarke.h"

void ClarkeTransform(const ClarkeInput *in_vector, double *i_alpha, double *i_beta)
{
    double f64_i_alpha = 0.6666666666666666 * in_vector->ia 
                       - 0.3333333333333333 * (in_vector->ib + in_vector->ic);
    
    double f64_i_beta  = 0.5773502691896257 * (in_vector->ib - in_vector->ic);

    *i_alpha = f64_i_alpha;
    *i_beta  = f64_i_beta;
}