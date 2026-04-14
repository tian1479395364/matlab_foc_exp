#ifndef FOC_CURRENTLOOP_DOUBLE_h_
#define FOC_CURRENTLOOP_DOUBLE_h_
#ifndef FOC_CURRENTLOOP_DOUBLE_COMMON_INCLUDES_
#define FOC_CURRENTLOOP_DOUBLE_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

#include "jscl_transform.h"
#include <math.h>

typedef struct g_ty_tag_RTM g_ty_RT_MODEL;

#include "jscl_clarke.h"
#include "jscl_park.h"

typedef struct {
    VectorAB_T g_f_j;
    real_T g_f_bz[3];
    real_T g_f_i;
    real_T g_f_b;
    real_T g_f_bl;
    real_T g_f_k;
    real_T g_f_p;
    real_T g_f_c;
    real_T g_f_l;
    real_T g_f_i_m;
    real_T g_f_h;
    real_T g_f_cb;
    real_T g_f_k_c;
    struct {
        int_T PrevIndex;
    } g_f_em;

    struct {
        void *TimePtr;
        void *DataPtr;
        void *RSimInfoPtr;
    } g_f_e2;

    uint8_T g_f_lw;
    uint8_T g_f_o;
} g_ty_DW;

struct g_ty_tag_RTM {
    struct {
        uint32_T clockTick1;
        struct {
            uint8_T TID[2];
        } TaskCounters;
    } Timing;
};

extern g_ty_DW g_l5;
extern void FOC_CURRENTLOOP_DOUBLE_initialize(void);
extern void FOC_CURRENTLOOP_DOUBLE_step(void);
extern g_ty_RT_MODEL *const g_j;

#endif

