/*
 * all.c
 *
 * Code generation for function 'all'
 *
 * C source code generated on: Fri Aug 31 09:31:05 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_n_unit_lba.h"
#include "all.h"
#include "epu_n_unit_lba_mexutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo u_emlrtRSI = { 12, "all", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/ops/all.m" };
static emlrtRSInfo v_emlrtRSI = { 24, "eml_all_or_any", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_all_or_any.m" };
static emlrtRSInfo w_emlrtRSI = { 24, "eml_all_or_any", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_all_or_any.m" };
static emlrtRSInfo x_emlrtRSI = { 27, "eml_all_or_any", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_all_or_any.m" };
static emlrtRSInfo y_emlrtRSI = { 8, "isequal", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/isequal.m" };
static emlrtRSInfo ab_emlrtRSI = { 30, "eml_isequal_core", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_isequal_core.m" };
static emlrtRSInfo bb_emlrtRSI = { 56, "eml_isequal_core", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_isequal_core.m" };
static emlrtMCInfo e_emlrtMCI = { 25, 9, "eml_all_or_any", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_all_or_any.m" };
static emlrtMCInfo f_emlrtMCI = { 24, 19, "eml_all_or_any", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_all_or_any.m" };
static emlrtMCInfo g_emlrtMCI = { 30, 9, "eml_all_or_any", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_all_or_any.m" };
static emlrtMCInfo h_emlrtMCI = { 27, 19, "eml_all_or_any", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_all_or_any.m" };
static emlrtBCInfo sb_emlrtBCI = { -1, -1, 111, 24, "", "eml_all_or_any", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_all_or_any.m", 0 };

/* Function Declarations */

/* Function Definitions */

/*
 * 
 */
boolean_T all(const emxArray_boolean_T *x)
{
    boolean_T y;
    boolean_T p;
    boolean_T b_p;
    int32_T i2;
    int32_T exitg2;
    int32_T ix;
    const mxArray *b_y;
    static const int32_T iv4[2] = { 1, 41 };
    const mxArray *m2;
    static const char_T cv4[41] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r', '_', 'a', 'n', 'y', '_', 's', 'p', 'e', 'c', 'i', 'a', 'l', 'E', 'm', 'p', 't', 'y' };
    const mxArray *c_y;
    static const int32_T iv5[2] = { 1, 51 };
    static const char_T cv5[51] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r', '_', 'a', 'n', 'y', '_', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };
    boolean_T exitg1;
    EMLRTPUSHRTSTACK(&u_emlrtRSI);
    EMLRTPUSHRTSTACK(&v_emlrtRSI);
    EMLRTPUSHRTSTACK(&y_emlrtRSI);
    p = FALSE;
    EMLRTPUSHRTSTACK(&ab_emlrtRSI);
    EMLRTPUSHRTSTACK(&bb_emlrtRSI);
    b_p = FALSE;
    i2 = 0;
    do {
        exitg2 = 0U;
        if (i2 < 2) {
            ix = x->size[i2];
            if (ix != 0) {
                exitg2 = 1U;
            } else {
                i2++;
            }
        } else {
            b_p = TRUE;
            exitg2 = 1U;
        }
    } while (exitg2 == 0U);
    EMLRTPOPRTSTACK(&bb_emlrtRSI);
    if (b_p) {
        b_p = TRUE;
    } else {
        b_p = FALSE;
    }
    EMLRTPOPRTSTACK(&ab_emlrtRSI);
    if (!b_p) {
    } else {
        p = TRUE;
    }
    EMLRTPOPRTSTACK(&y_emlrtRSI);
    EMLRTPOPRTSTACK(&v_emlrtRSI);
    if (!p) {
        b_p = TRUE;
    } else {
        b_p = FALSE;
    }
    if (b_p) {
    } else {
        EMLRTPUSHRTSTACK(&w_emlrtRSI);
        b_y = NULL;
        m2 = mxCreateCharArray(2, iv4);
        emlrtInitCharArray(41, m2, cv4);
        emlrtAssign(&b_y, m2);
        error(message(b_y, &e_emlrtMCI), &f_emlrtMCI);
        EMLRTPOPRTSTACK(&w_emlrtRSI);
    }
    if ((x->size[1] == 1) || (x->size[1] != 1)) {
        b_p = TRUE;
    } else {
        b_p = FALSE;
    }
    if (b_p) {
    } else {
        EMLRTPUSHRTSTACK(&x_emlrtRSI);
        c_y = NULL;
        m2 = mxCreateCharArray(2, iv5);
        emlrtInitCharArray(51, m2, cv5);
        emlrtAssign(&c_y, m2);
        error(message(c_y, &g_emlrtMCI), &h_emlrtMCI);
        EMLRTPOPRTSTACK(&x_emlrtRSI);
    }
    y = TRUE;
    i2 = x->size[1];
    ix = 1;
    exitg1 = 0U;
    while ((exitg1 == 0U) && (ix <= i2)) {
        if (x->data[emlrtDynamicBoundsCheck(ix, 1, x->size[1], &sb_emlrtBCI) - 1] == 0) {
            y = FALSE;
            exitg1 = 1U;
        } else {
            ix++;
        }
    }
    EMLRTPOPRTSTACK(&u_emlrtRSI);
    return y;
}
/* End of code generation (all.c) */
