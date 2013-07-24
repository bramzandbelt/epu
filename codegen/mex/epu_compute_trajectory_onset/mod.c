/*
 * mod.c
 *
 * Code generation for function 'mod'
 *
 * C source code generated on: Fri Aug 31 09:24:08 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_compute_trajectory_onset.h"
#include "mod.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

/*
 * 
 */
real_T b_mod(real_T x, real_T y)
{
    real_T r;
    real_T b_x;
    if (y == 0.0) {
        r = x;
    } else if (y == muDoubleScalarFloor(y)) {
        r = x - muDoubleScalarFloor(x / y) * y;
    } else {
        r = x / y;
        if (muDoubleScalarAbs(r) > 4.503599627370496E+15) {
            b_x = r;
        } else if (r >= 0.5) {
            b_x = muDoubleScalarFloor(r + 0.5);
        } else if (r > -0.5) {
            b_x = -0.0;
        } else {
            b_x = muDoubleScalarCeil(r - 0.5);
        }
        if (muDoubleScalarAbs(r - b_x) <= 2.2204460492503131E-16 * muDoubleScalarAbs(r)) {
            r = 0.0;
        } else {
            r = (r - muDoubleScalarFloor(r)) * y;
        }
    }
    return r;
}
/* End of code generation (mod.c) */
