/*
 * mean.c
 *
 * Code generation for function 'mean'
 *
 * C source code generated on: Tue Oct 30 14:49:26 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_n_unit_ba.h"
#include "mean.h"
#include "epu_n_unit_ba_emxutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo mc_emlrtRSI = { 28, "mean", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/mean.m" };
static emlrtRSInfo nc_emlrtRSI = { 36, "mean", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/mean.m" };
static emlrtRSInfo oc_emlrtRSI = { 34, "sum", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/sum.m" };
static emlrtRTEInfo u_emlrtRTEI = { 49, 1, "sum", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/sum.m" };
static emlrtRTEInfo v_emlrtRTEI = { 1, 14, "mean", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/mean.m" };
static emlrtBCInfo md_emlrtBCI = { -1, -1, 69, 22, "", "sum", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/sum.m", 0 };
static emlrtBCInfo nd_emlrtBCI = { -1, -1, 75, 13, "", "sum", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/sum.m", 0 };
static emlrtBCInfo od_emlrtBCI = { -1, -1, 72, 30, "", "sum", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/sum.m", 0 };

/* Function Declarations */

/* Function Definitions */

/*
 * 
 */
void mean(const emxArray_real_T *x, emxArray_real_T *y)
{
    uint32_T sz[2];
    int32_T iy;
    int32_T vlen;
    int32_T vstride;
    int32_T ixstart;
    int32_T j;
    int32_T ix;
    real_T s;
    int32_T k;
    EMLRTPUSHRTSTACK(&mc_emlrtRSI);
    EMLRTPOPRTSTACK(&mc_emlrtRSI);
    EMLRTPUSHRTSTACK(&nc_emlrtRSI);
    EMLRTPUSHRTSTACK(&oc_emlrtRSI);
    EMLRTPOPRTSTACK(&oc_emlrtRSI);
    for (iy = 0; iy < 2; iy++) {
        sz[iy] = (uint32_T)x->size[iy];
    }
    sz[1] = 1U;
    iy = y->size[0];
    y->size[0] = (int32_T)sz[0];
    emxEnsureCapacity((emxArray__common *)y, iy, (int32_T)sizeof(real_T), &u_emlrtRTEI);
    if ((x->size[0] == 0) || (x->size[1] == 0)) {
        vlen = y->size[0];
        iy = y->size[0];
        y->size[0] = vlen;
        emxEnsureCapacity((emxArray__common *)y, iy, (int32_T)sizeof(real_T), &v_emlrtRTEI);
        vlen--;
        for (iy = 0; iy <= vlen; iy++) {
            y->data[iy] = 0.0;
        }
    } else {
        vlen = x->size[1];
        vstride = x->size[0];
        iy = 0;
        ixstart = 0;
        for (j = 1; j <= vstride; j++) {
            ixstart++;
            ix = ixstart;
            s = x->data[emlrtDynamicBoundsCheck(ixstart, 1, x->size[0] * x->size[1], &md_emlrtBCI) - 1];
            for (k = 2; k <= vlen; k++) {
                ix += vstride;
                s += x->data[emlrtDynamicBoundsCheck(ix, 1, x->size[0] * x->size[1], &od_emlrtBCI) - 1];
            }
            iy++;
            y->data[emlrtDynamicBoundsCheck(iy, 1, y->size[0], &nd_emlrtBCI) - 1] = s;
        }
    }
    vstride = x->size[1];
    iy = y->size[0];
    emxEnsureCapacity((emxArray__common *)y, iy, (int32_T)sizeof(real_T), &v_emlrtRTEI);
    vlen = y->size[0] - 1;
    for (iy = 0; iy <= vlen; iy++) {
        y->data[iy] /= (real_T)vstride;
    }
    EMLRTPOPRTSTACK(&nc_emlrtRSI);
}
/* End of code generation (mean.c) */
