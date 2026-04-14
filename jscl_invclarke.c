#include "jscl_invclarke.h"

void InverseClarkeTransform(double u_alpha,
                            double u_beta,
                            UabcOutput *u_abc)
{
    /* Inverse Clarke Transform */
    u_abc->ua = u_alpha;

    u_abc->ub = -0.5 * u_alpha + 0.8660254037844386 * u_beta;   // √3/2

    u_abc->uc = -0.5 * u_alpha - 0.8660254037844386 * u_beta;
}