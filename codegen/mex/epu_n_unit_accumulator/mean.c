/*
 * mean.c
 *
 * Code generation for function 'mean'
 *
 * C source code generated on: Fri Aug 31 09:23:48 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_n_unit_accumulator.h"
#include "mean.h"
#include "interp1.h"
#include "epu_n_unit_accumulator_mexutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo gc_emlrtRSI = { 17, "mean", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/mean.m" };
static emlrtRSInfo hc_emlrtRSI = { 17, "mean", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/mean.m" };
static emlrtRSInfo ic_emlrtRSI = { 20, "mean", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/mean.m" };
static emlrtRSInfo jc_emlrtRSI = { 36, "mean", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/mean.m" };
static emlrtRSInfo kc_emlrtRSI = { 8, "isequal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/isequal.m" };
static emlrtRSInfo lc_emlrtRSI = { 30, "eml_isequal_core", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_isequal_core.m" };
static emlrtRSInfo mc_emlrtRSI = { 56, "eml_isequal_core", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_isequal_core.m" };
static emlrtMCInfo v_emlrtMCI = { 18, 9, "mean", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/mean.m" };
static emlrtMCInfo w_emlrtMCI = { 17, 19, "mean", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/mean.m" };
static emlrtMCInfo x_emlrtMCI = { 23, 9, "mean", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/mean.m" };
static emlrtMCInfo y_emlrtMCI = { 20, 19, "mean", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/mean.m" };
static emlrtBCInfo qc_emlrtBCI = { -1, -1, 56, 22, "", "sum", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/sum.m", 0 };

/* Function Declarations */

/* Function Definitions */

/*
 * 
 */
real_T mean(const emxArray_real_T *x)
{
    real_T y;
    boolean_T p;
    boolean_T b_p;
    int32_T k;
    int32_T exitg1;
    int32_T vlen;
    const mxArray *b_y;
    static const int32_T iv15[2] = { 1, 31 };
    const mxArray *m5;
    static const char_T cv10[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'm', 'e', 'a', 'n', '_', 's', 'p', 'e', 'c', 'i', 'a', 'l', 'E', 'm', 'p', 't', 'y' };
    const mxArray *c_y;
    static const int32_T iv16[2] = { 1, 36 };
    static const char_T cv11[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };
    EMLRTPUSHRTSTACK(&gc_emlrtRSI);
    EMLRTPUSHRTSTACK(&kc_emlrtRSI);
    p = FALSE;
    EMLRTPUSHRTSTACK(&lc_emlrtRSI);
    EMLRTPUSHRTSTACK(&mc_emlrtRSI);
    b_p = FALSE;
    k = 0;
    do {
        exitg1 = 0U;
        if (k < 2) {
            vlen = x->size[k];
            if (vlen != 0) {
                exitg1 = 1U;
            } else {
                k++;
            }
        } else {
            b_p = TRUE;
            exitg1 = 1U;
        }
    } while (exitg1 == 0U);
    EMLRTPOPRTSTACK(&mc_emlrtRSI);
    if (b_p) {
        b_p = TRUE;
    } else {
        b_p = FALSE;
    }
    EMLRTPOPRTSTACK(&lc_emlrtRSI);
    if (!b_p) {
    } else {
        p = TRUE;
    }
    EMLRTPOPRTSTACK(&kc_emlrtRSI);
    EMLRTPOPRTSTACK(&gc_emlrtRSI);
    if (!p) {
        b_p = TRUE;
    } else {
        b_p = FALSE;
    }
    if (b_p) {
    } else {
        EMLRTPUSHRTSTACK(&hc_emlrtRSI);
        b_y = NULL;
        m5 = mxCreateCharArray(2, iv15);
        emlrtInitCharArray(31, m5, cv10);
        emlrtAssign(&b_y, m5);
        error(message(b_y, &v_emlrtMCI), &w_emlrtMCI);
        EMLRTPOPRTSTACK(&hc_emlrtRSI);
    }
    if ((x->size[1] == 1) || (x->size[1] != 1)) {
        b_p = TRUE;
    } else {
        b_p = FALSE;
    }
    if (b_p) {
    } else {
        EMLRTPUSHRTSTACK(&ic_emlrtRSI);
        c_y = NULL;
        m5 = mxCreateCharArray(2, iv16);
        emlrtInitCharArray(36, m5, cv11);
        emlrtAssign(&c_y, m5);
        error(message(c_y, &x_emlrtMCI), &y_emlrtMCI);
        EMLRTPOPRTSTACK(&ic_emlrtRSI);
    }
    EMLRTPUSHRTSTACK(&jc_emlrtRSI);
    if (x->size[1] == 0) {
        y = 0.0;
    } else {
        vlen = x->size[1];
        y = x->data[0];
        for (k = 2; k <= vlen; k++) {
            y += x->data[emlrtDynamicBoundsCheck(k, 1, x->size[1], &qc_emlrtBCI) - 1];
        }
    }
    y /= (real_T)x->size[1];
    EMLRTPOPRTSTACK(&jc_emlrtRSI);
    return y;
}
/* End of code generation (mean.c) */
