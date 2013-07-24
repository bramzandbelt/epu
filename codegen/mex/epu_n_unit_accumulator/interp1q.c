/*
 * interp1q.c
 *
 * Code generation for function 'interp1q'
 *
 * C source code generated on: Fri Aug 31 09:23:48 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_n_unit_accumulator.h"
#include "interp1q.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo ec_emlrtRSI = { 51, "interp1q", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/polyfun/interp1q.m" };

/* Function Declarations */

/* Function Definitions */

/*
 * 
 */
real_T interp1q(const real_T x[2], const real_T y[2], real_T xi)
{
    real_T yi;
    yi = rtNaN;
    if ((xi >= x[0]) && (xi <= x[1])) {
        EMLRTPUSHRTSTACK(&ec_emlrtRSI);
        EMLRTPOPRTSTACK(&ec_emlrtRSI);
        yi = y[0] + (xi - x[0]) / (x[1] - x[0]) * (y[1] - y[0]);
    }
    return yi;
}
/* End of code generation (interp1q.c) */
