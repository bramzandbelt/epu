/*
 * round.c
 *
 * Code generation for function 'round'
 *
 * C source code generated on: Fri Aug 31 09:30:57 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_align_to_event.h"
#include "round.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

/*
 * 
 */
void b_round(real_T *x)
{
    if (muDoubleScalarAbs(*x) > 4.503599627370496E+15) {
    } else if (*x >= 0.5) {
        *x = muDoubleScalarFloor(*x + 0.5);
    } else if (*x > -0.5) {
        *x *= 0.0;
    } else {
        *x = muDoubleScalarCeil(*x - 0.5);
    }
}

/*
 * 
 */
void c_round(real_T x[2])
{
    int32_T k;
    real_T b_x;
    for (k = 0; k < 2; k++) {
        if (muDoubleScalarAbs(x[k]) > 4.503599627370496E+15) {
            b_x = x[k];
        } else if (x[k] >= 0.5) {
            b_x = muDoubleScalarFloor(x[k] + 0.5);
        } else if (x[k] > -0.5) {
            b_x = x[k] * 0.0;
        } else {
            b_x = muDoubleScalarCeil(x[k] - 0.5);
        }
        x[k] = b_x;
    }
}
/* End of code generation (round.c) */
