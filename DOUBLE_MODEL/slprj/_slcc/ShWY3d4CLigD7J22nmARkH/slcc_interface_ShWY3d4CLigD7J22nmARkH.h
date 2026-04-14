#include "customcode_ShWY3d4CLigD7J22nmARkH.h"
#ifdef __cplusplus
extern "C" {
#endif


/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
DLL_EXPORT_CC extern const char_T *get_dll_checksum_ShWY3d4CLigD7J22nmARkH(void);
DLL_EXPORT_CC extern void ClarkeTransform_ShWY3d4CLigD7J22nmARkH(const ClarkeInput *in_vector, real_T *i_alpha, real_T *i_beta);
DLL_EXPORT_CC extern void ParkTransform_ShWY3d4CLigD7J22nmARkH(real_T i_alpha, real_T i_beta, const SinCosInput *sin_cos, real_T *i_d, real_T *i_q);
DLL_EXPORT_CC extern void InverseParkTransform_ShWY3d4CLigD7J22nmARkH(real_T u_d, real_T u_q, const SinCosInput *sin_cos, real_T *u_alpha, real_T *u_beta);
DLL_EXPORT_CC extern void CurrentLoopDQ_ShWY3d4CLigD7J22nmARkH(real_T IRefD, real_T ISensD, real_T IRefQ, real_T ISensQ, real_T d_kp_param, real_T d_ki_param, real_T q_kp_param, real_T q_ki_param, real_T *Vd, real_T *Vq);

/* Function Definitions */
DLL_EXPORT_CC const uint8_T *get_checksum_source_info(int32_T *size);
#ifdef __cplusplus
}
#endif

