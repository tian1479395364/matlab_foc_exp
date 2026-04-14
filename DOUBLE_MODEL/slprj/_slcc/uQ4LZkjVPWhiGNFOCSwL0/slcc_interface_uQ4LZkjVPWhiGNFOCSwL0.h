#include "customcode_uQ4LZkjVPWhiGNFOCSwL0.h"
#ifdef __cplusplus
extern "C" {
#endif


/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
DLL_EXPORT_CC extern const char_T *get_dll_checksum_uQ4LZkjVPWhiGNFOCSwL0(void);
DLL_EXPORT_CC extern void ClarkeTransform_uQ4LZkjVPWhiGNFOCSwL0(const VectorUVW_T *ABC_in, VectorAB_T *AB_out);
DLL_EXPORT_CC extern void ParkTransform_uQ4LZkjVPWhiGNFOCSwL0(const VectorAB_T *AB_in, const real_T sin_cos[2], VectorDQ_T *DQ_out);
DLL_EXPORT_CC extern void InverseParkTransform_uQ4LZkjVPWhiGNFOCSwL0(const VectorDQ_T *in, const real_T sin_cos[2], VectorAB_T *out);
DLL_EXPORT_CC extern void InverseClarkeTransform_uQ4LZkjVPWhiGNFOCSwL0(const VectorAB_T *AB_in, VectorUVW_T *ABC_out);
DLL_EXPORT_CC extern void CalcZeroSequenceVoltage_uQ4LZkjVPWhiGNFOCSwL0(const VectorUVW_T *u_abc, real_T *u_zero);
DLL_EXPORT_CC extern void CurrentLoopDQ_uQ4LZkjVPWhiGNFOCSwL0(real_T IRefD, real_T ISensD, real_T IRefQ, real_T ISensQ, real_T d_kp_param, real_T d_ki_param, real_T q_kp_param, real_T q_ki_param, VectorDQ_T *dq_out);

/* Function Definitions */
DLL_EXPORT_CC const uint8_T *get_checksum_source_info(int32_T *size);
#ifdef __cplusplus
}
#endif

