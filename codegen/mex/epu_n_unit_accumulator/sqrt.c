/*
 * sqrt.c
 *
 * Code generation for function 'sqrt'
 *
 * C source code generated on: Fri Aug 31 09:23:48 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_n_unit_accumulator.h"
#include "sqrt.h"
#include "interp1.h"
#include "epu_n_unit_accumulator_mexutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo ob_emlrtRSI = { 14, "sqrt", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elfun/sqrt.m" };
static emlrtRSInfo pb_emlrtRSI = { 20, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtMCInfo i_emlrtMCI = { 20, 19, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtMCInfo j_emlrtMCI = { 20, 5, "eml_error", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };

/* Function Declarations */
static void eml_error(void);

/* Function Definitions */

/*
 * 
 */
static void eml_error(void)
{
    const mxArray *y;
    static const int32_T iv12[2] = { 1, 30 };
    const mxArray *m2;
    static const char_T cv7[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 's', 'q', 'r', 't', '_', 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };
    EMLRTPUSHRTSTACK(&pb_emlrtRSI);
    y = NULL;
    m2 = mxCreateCharArray(2, iv12);
    emlrtInitCharArray(30, m2, cv7);
    emlrtAssign(&y, m2);
    error(message(y, &i_emlrtMCI), &j_emlrtMCI);
    EMLRTPOPRTSTACK(&pb_emlrtRSI);
}

/*
 * 
 */
void b_sqrt(real_T *x)
{
    if (*x < 0.0) {
        EMLRTPUSHRTSTACK(&ob_emlrtRSI);
        eml_error();
        EMLRTPOPRTSTACK(&ob_emlrtRSI);
    }
    *x = muDoubleScalarSqrt(*x);
}
/* End of code generation (sqrt.c) */
