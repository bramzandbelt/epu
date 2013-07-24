/*
 * log.c
 *
 * Code generation for function 'log'
 *
 * C source code generated on: Tue Oct 30 14:49:26 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_n_unit_ba.h"
#include "log.h"
#include "repmat.h"
#include "epu_n_unit_ba_mexutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo y_emlrtRSI = { 14, "log", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elfun/log.m" };
static emlrtRSInfo ab_emlrtRSI = { 20, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtMCInfo emlrtMCI = { 20, 19, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtMCInfo b_emlrtMCI = { 20, 5, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtBCInfo pd_emlrtBCI = { 0, MAX_int32_T, 12, 15, "", "log", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elfun/log.m", 0 };
static emlrtBCInfo qd_emlrtBCI = { 0, MAX_int32_T, 18, 11, "", "log", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elfun/log.m", 0 };
static emlrtBCInfo rd_emlrtBCI = { -1, -1, 19, 27, "", "log", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elfun/log.m", 0 };
static emlrtBCInfo sd_emlrtBCI = { -1, -1, 19, 5, "", "log", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elfun/log.m", 0 };
static emlrtBCInfo td_emlrtBCI = { -1, -1, 13, 12, "", "log", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elfun/log.m", 0 };

/* Function Declarations */
static void eml_error(void);

/* Function Definitions */

/*
 * 
 */
static void eml_error(void)
{
    const mxArray *y;
    static const int32_T iv9[2] = { 1, 29 };
    const mxArray *m1;
    static const char_T cv6[29] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'l', 'o', 'g', '_', 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };
    EMLRTPUSHRTSTACK(&ab_emlrtRSI);
    y = NULL;
    m1 = mxCreateCharArray(2, iv9);
    emlrtInitCharArray(29, m1, cv6);
    emlrtAssign(&y, m1);
    error(message(y, &emlrtMCI), &b_emlrtMCI);
    EMLRTPOPRTSTACK(&ab_emlrtRSI);
}

/*
 * 
 */
void b_log(emxArray_real_T *x)
{
    int32_T k;
    int32_T i5;
    emlrtBoundsCheck(x->size[1], &pd_emlrtBCI);
    for (k = 0; k <= x->size[1] - 1; k++) {
        if (x->data[emlrtDynamicBoundsCheck((int32_T)(1.0 + (real_T)k), 1, x->size[1], &td_emlrtBCI) - 1] < 0.0) {
            EMLRTPUSHRTSTACK(&y_emlrtRSI);
            eml_error();
            EMLRTPOPRTSTACK(&y_emlrtRSI);
        }
    }
    emlrtBoundsCheck(x->size[1], &qd_emlrtBCI);
    i5 = x->size[1];
    for (k = 0; k <= i5 - 1; k++) {
        emlrtDynamicBoundsCheck((int32_T)(1.0 + (real_T)k), 1, x->size[1], &rd_emlrtBCI);
        x->data[emlrtDynamicBoundsCheck((int32_T)(1.0 + (real_T)k), 1, x->size[1], &sd_emlrtBCI) - 1] = muDoubleScalarLog(x->data[(int32_T)(1.0 + (real_T)k) - 1]);
    }
}
/* End of code generation (log.c) */
