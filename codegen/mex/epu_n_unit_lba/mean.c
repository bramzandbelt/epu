/*
 * mean.c
 *
 * Code generation for function 'mean'
 *
 * C source code generated on: Fri Aug 31 09:31:05 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_n_unit_lba.h"
#include "mean.h"
#include "epu_n_unit_lba_mexutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo cb_emlrtRSI = { 17, "mean", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/mean.m" };
static emlrtRSInfo db_emlrtRSI = { 17, "mean", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/mean.m" };
static emlrtRSInfo eb_emlrtRSI = { 20, "mean", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/mean.m" };
static emlrtRSInfo fb_emlrtRSI = { 36, "mean", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/mean.m" };
static emlrtRSInfo gb_emlrtRSI = { 8, "isequal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/isequal.m" };
static emlrtRSInfo hb_emlrtRSI = { 30, "eml_isequal_core", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_isequal_core.m" };
static emlrtRSInfo ib_emlrtRSI = { 56, "eml_isequal_core", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_isequal_core.m" };
static emlrtRSInfo jb_emlrtRSI = { 34, "sum", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/sum.m" };
static emlrtMCInfo i_emlrtMCI = { 18, 9, "mean", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/mean.m" };
static emlrtMCInfo j_emlrtMCI = { 17, 19, "mean", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/mean.m" };
static emlrtMCInfo k_emlrtMCI = { 23, 9, "mean", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/mean.m" };
static emlrtMCInfo l_emlrtMCI = { 20, 19, "mean", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/mean.m" };
static emlrtBCInfo tb_emlrtBCI = { -1, -1, 56, 22, "", "sum", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/datafun/sum.m", 0 };

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
    static const int32_T iv6[2] = { 1, 31 };
    const mxArray *m3;
    static const char_T cv6[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'm', 'e', 'a', 'n', '_', 's', 'p', 'e', 'c', 'i', 'a', 'l', 'E', 'm', 'p', 't', 'y' };
    const mxArray *c_y;
    static const int32_T iv7[2] = { 1, 36 };
    static const char_T cv7[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };
    EMLRTPUSHRTSTACK(&cb_emlrtRSI);
    EMLRTPUSHRTSTACK(&gb_emlrtRSI);
    p = FALSE;
    EMLRTPUSHRTSTACK(&hb_emlrtRSI);
    EMLRTPUSHRTSTACK(&ib_emlrtRSI);
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
    EMLRTPOPRTSTACK(&ib_emlrtRSI);
    if (b_p) {
        b_p = TRUE;
    } else {
        b_p = FALSE;
    }
    EMLRTPOPRTSTACK(&hb_emlrtRSI);
    if (!b_p) {
    } else {
        p = TRUE;
    }
    EMLRTPOPRTSTACK(&gb_emlrtRSI);
    EMLRTPOPRTSTACK(&cb_emlrtRSI);
    if (!p) {
        b_p = TRUE;
    } else {
        b_p = FALSE;
    }
    if (b_p) {
    } else {
        EMLRTPUSHRTSTACK(&db_emlrtRSI);
        b_y = NULL;
        m3 = mxCreateCharArray(2, iv6);
        emlrtInitCharArray(31, m3, cv6);
        emlrtAssign(&b_y, m3);
        error(message(b_y, &i_emlrtMCI), &j_emlrtMCI);
        EMLRTPOPRTSTACK(&db_emlrtRSI);
    }
    if ((x->size[1] == 1) || (x->size[1] != 1)) {
        b_p = TRUE;
    } else {
        b_p = FALSE;
    }
    if (b_p) {
    } else {
        EMLRTPUSHRTSTACK(&eb_emlrtRSI);
        c_y = NULL;
        m3 = mxCreateCharArray(2, iv7);
        emlrtInitCharArray(36, m3, cv7);
        emlrtAssign(&c_y, m3);
        error(message(c_y, &k_emlrtMCI), &l_emlrtMCI);
        EMLRTPOPRTSTACK(&eb_emlrtRSI);
    }
    EMLRTPUSHRTSTACK(&fb_emlrtRSI);
    EMLRTPUSHRTSTACK(&jb_emlrtRSI);
    eml_assert_valid_dim(2.0);
    EMLRTPOPRTSTACK(&jb_emlrtRSI);
    if (x->size[1] == 0) {
        y = 0.0;
    } else {
        vlen = x->size[1];
        y = x->data[0];
        for (k = 2; k <= vlen; k++) {
            y += x->data[emlrtDynamicBoundsCheck(k, 1, x->size[1], &tb_emlrtBCI) - 1];
        }
    }
    y /= (real_T)x->size[1];
    EMLRTPOPRTSTACK(&fb_emlrtRSI);
    return y;
}
/* End of code generation (mean.c) */
