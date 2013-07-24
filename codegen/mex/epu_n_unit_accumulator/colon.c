/*
 * colon.c
 *
 * Code generation for function 'colon'
 *
 * C source code generated on: Fri Aug 31 09:23:48 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_n_unit_accumulator.h"
#include "colon.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

/*
 * 
 */
void float_colon_length(real_T a, real_T d, real_T b, int32_T *n, real_T *anew, real_T *bnew, boolean_T *n_too_large)
{
    boolean_T b2;
    real_T ndbl;
    real_T cdiff;
    real_T absa;
    real_T absb;
    if (muDoubleScalarIsNaN(a) || muDoubleScalarIsNaN(d) || muDoubleScalarIsNaN(b)) {
        *n = 1;
        *anew = rtNaN;
        *bnew = b;
        *n_too_large = FALSE;
    } else if ((d == 0.0) || ((a < b) && (d < 0.0)) || ((b < a) && (d > 0.0))) {
        *n = 0;
        *anew = a;
        *bnew = b;
        *n_too_large = FALSE;
    } else if (muDoubleScalarIsInf(a) || muDoubleScalarIsInf(d) || muDoubleScalarIsInf(b)) {
        *n = 1;
        *anew = rtNaN;
        *bnew = b;
        if (muDoubleScalarIsInf(d) || (a == b)) {
            b2 = TRUE;
        } else {
            b2 = FALSE;
        }
        *n_too_large = !b2;
    } else {
        *anew = a;
        ndbl = muDoubleScalarFloor((b - a) / d + 0.5);
        *bnew = a + ndbl * d;
        if (d > 0.0) {
            cdiff = *bnew - b;
        } else {
            cdiff = b - *bnew;
        }
        absa = muDoubleScalarAbs(a);
        absb = muDoubleScalarAbs(b);
        if (absa > absb) {
            absb = absa;
        }
        if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * absb) {
            ndbl++;
            *bnew = b;
        } else if (cdiff > 0.0) {
            *bnew = a + (ndbl - 1.0) * d;
        } else {
            ndbl++;
        }
        *n_too_large = (ndbl > 2.147483647E+9);
        if (ndbl >= 0.0) {
            *n = (int32_T)ndbl;
        } else {
            *n = 0;
        }
    }
}
/* End of code generation (colon.c) */
