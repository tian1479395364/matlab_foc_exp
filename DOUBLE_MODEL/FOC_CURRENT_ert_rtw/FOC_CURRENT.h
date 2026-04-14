#ifndef FOC_CURRENT_h_
#define FOC_CURRENT_h_
#ifndef FOC_CURRENT_COMMON_INCLUDES_
#define FOC_CURRENT_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

#include "jscl_transform.h"

#include "jscl_clarke.h"
#include "jscl_park.h"

typedef struct {
    VectorAB_T g_f_p;
    real_T g_f_b[3];
} g_ty_DW;

typedef struct {
    real_T g_f_e;
    real_T g_f_m;
    real_T g_f_j;
    real_T g_f_h;
    real_T g_f_a;
    real_T g_f_o;
    real_T g_f_hk;
} g_ty_ExtU;

typedef struct {
    real_T g_f_f;
    real_T g_f_i;
    real_T g_f_h;
} g_ty_ExtY;

extern g_ty_DW g_l5;
extern g_ty_ExtU g_m;
extern g_ty_ExtY g_ho;
extern void FOC_CURRENT_initialize(void);
extern void FOC_CURRENT_step(void);

#endif

