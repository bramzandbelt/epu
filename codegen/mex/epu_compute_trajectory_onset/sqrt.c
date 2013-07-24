/*
 * sqrt.c
 *
 * Code generation for function 'sqrt'
 *
 * C source code generated on: Fri Aug 31 09:24:08 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_compute_trajectory_onset.h"
#include "sqrt.h"
#include "median.h"
#include "epu_compute_trajectory_onset_mexutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo te_emlrtRSI = { 14, "sqrt", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elfun/sqrt.m" };
static emlrtRSInfo ue_emlrtRSI = { 20, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtMCInfo r_emlrtMCI = { 20, 19, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtMCInfo s_emlrtMCI = { 20, 5, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };

/* Function Declarations */
static void d_eml_error(void);

/* Function Definitions */

/*
 * 
 */
static void d_eml_error(void)
{
    const mxArray *y;
    static const int32_T iv22[2] = { 1, 30 };
    const mxArray *m8;
    static const char_T cv12[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 's', 'q', 'r', 't', '_', 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };
    EMLRTPUSHRTSTACK(&ue_emlrtRSI);
    y = NULL;
    m8 = mxCreateCharArray(2, iv22);
    emlrtInitCharArray(30, m8, cv12);
    emlrtAssign(&y, m8);
    c_error(message(y, &r_emlrtMCI), &s_emlrtMCI);
    EMLRTPOPRTSTACK(&ue_emlrtRSI);
}

/*
 * 
 */
void b_sqrt(real_T *x)
{
    if (*x < 0.0) {
        EMLRTPUSHRTSTACK(&te_emlrtRSI);
        d_eml_error();
        EMLRTPOPRTSTACK(&te_emlrtRSI);
    }
    *x = muDoubleScalarSqrt(*x);
}
/* End of code generation (sqrt.c) */
