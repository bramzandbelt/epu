/*
 * error.c
 *
 * Code generation for function 'error'
 *
 * C source code generated on: Fri Aug 31 09:24:08 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_compute_trajectory_onset.h"
#include "error.h"
#include "epu_compute_trajectory_onset_mexutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo d_emlrtRSI = { 12, "error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/lang/error.m" };
static emlrtRSInfo e_emlrtRSI = { 12, "error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/lang/error.m" };
static emlrtMCInfo emlrtMCI = { 12, 7, "error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/lang/error.m" };
static emlrtMCInfo b_emlrtMCI = { 12, 7, "error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/lang/error.m" };

/* Function Declarations */

/* Function Definitions */

/*
 * 
 */
void b_error(void)
{
    const mxArray *y;
    static const int32_T iv3[2] = { 1, 83 };
    const mxArray *m2;
    static const char_T cv2[83] = { 'm', 'o', 'd', 'e', 'l', 'o', 'r', 'd', 'e', 'r', ' ', 'm', 'u', 's', 't', ' ', 'b', 'e', ' ', 'a', ' ', 's', 'c', 'a', 'l', 'a', 'r', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ',', ' ', '>', '=', ' ', '1', ',', ' ', 'a', 'n', 'd', ' ', 'n', 'o', ' ', 'm', 'o', 'r', 'e', ' ', 't', 'h', 'a', 'n', ' ', 'm', 'i', 'n', '(', '1', '0', ',', 's', 'u', 'p', 'p', 'o', 'r', 't', 'l', 'e', 'n', 'g', 't', 'h', '-', '1', ')' };
    EMLRTPUSHRTSTACK(&e_emlrtRSI);
    y = NULL;
    m2 = mxCreateCharArray(2, iv3);
    emlrtInitCharArray(83, m2, cv2);
    emlrtAssign(&y, m2);
    c_error(y, &b_emlrtMCI);
    EMLRTPOPRTSTACK(&e_emlrtRSI);
}

/*
 * 
 */
void error(void)
{
    const mxArray *y;
    static const int32_T iv2[2] = { 1, 74 };
    const mxArray *m1;
    static const char_T cv1[74] = { 's', 'u', 'p', 'p', 'o', 'r', 't', 'l', 'e', 'n', 'g', 't', 'h', ' ', 'm', 'u', 's', 't', ' ', 'b', 'e', ' ', 'a', ' ', 's', 'c', 'a', 'l', 'a', 'r', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', ',', ' ', '>', '=', ' ', '2', ',', ' ', 'a', 'n', 'd', ' ', 'n', 'o', ' ', 'm', 'o', 'r', 'e', ' ', 't', 'h', 'a', 'n', ' ', 'l', 'e', 'n', 'g', 't', 'h', '(', 'v', 'e', 'c', ')' };
    EMLRTPUSHRTSTACK(&d_emlrtRSI);
    y = NULL;
    m1 = mxCreateCharArray(2, iv2);
    emlrtInitCharArray(74, m1, cv1);
    emlrtAssign(&y, m1);
    c_error(y, &emlrtMCI);
    EMLRTPOPRTSTACK(&d_emlrtRSI);
}
/* End of code generation (error.c) */
