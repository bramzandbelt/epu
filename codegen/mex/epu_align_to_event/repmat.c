/*
 * repmat.c
 *
 * Code generation for function 'repmat'
 *
 * C source code generated on: Fri Aug 31 09:30:57 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_align_to_event.h"
#include "repmat.h"
#include "epu_align_to_event_emxutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo t_emlrtRSI = { 19, "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m" };
static emlrtRTEInfo g_emlrtRTEI = { 45, 1, "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m" };
static emlrtRTEInfo h_emlrtRTEI = { 1, 14, "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m" };
static emlrtBCInfo n_emlrtBCI = { -1, -1, 64, 21, "", "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m", 0 };
static emlrtBCInfo o_emlrtBCI = { -1, -1, 64, 29, "", "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m", 0 };
static emlrtDCInfo h_emlrtDCI = { 42, 22, "repmat", "/Applications/MATLAB_R2011b.app/toolbox/eml/lib/matlab/elmat/repmat.m", 4 };

/* Function Declarations */

/* Function Definitions */

/*
 * 
 */
void b_repmat(real_T a, real_T n, emxArray_real_T *b)
{
    int32_T iv5[2];
    real_T d0;
    int32_T i1;
    int32_T outsize[2];
    int32_T loop_ub;
    EMLRTPUSHRTSTACK(&t_emlrtRSI);
    eml_assert_valid_size_arg(n);
    EMLRTPOPRTSTACK(&t_emlrtRSI);
    iv5[0] = 1;
    d0 = n;
    d0 = d0 < 0.0 ? muDoubleScalarCeil(d0 - 0.5) : muDoubleScalarFloor(d0 + 0.5);
    if (d0 < 2.147483648E+9) {
        if (d0 >= -2.147483648E+9) {
            i1 = (int32_T)d0;
        } else {
            i1 = MIN_int32_T;
        }
    } else if (d0 >= 2.147483648E+9) {
        i1 = MAX_int32_T;
    } else {
        i1 = 0;
    }
    iv5[1] = i1;
    for (i1 = 0; i1 < 2; i1++) {
        outsize[i1] = iv5[i1];
    }
    iv5[0] = 1;
    d0 = n;
    d0 = d0 < 0.0 ? muDoubleScalarCeil(d0 - 0.5) : muDoubleScalarFloor(d0 + 0.5);
    if (d0 < 2.147483648E+9) {
        if (d0 >= -2.147483648E+9) {
            i1 = (int32_T)d0;
        } else {
            i1 = MIN_int32_T;
        }
    } else if (d0 >= 2.147483648E+9) {
        i1 = MAX_int32_T;
    } else {
        i1 = 0;
    }
    iv5[1] = i1;
    for (i1 = 0; i1 < 2; i1++) {
        emlrtNonNegativeCheckR2009b((real_T)iv5[i1], &h_emlrtDCI);
    }
    i1 = b->size[0] * b->size[1];
    b->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)b, i1, (int32_T)sizeof(real_T), &h_emlrtRTEI);
    i1 = b->size[0] * b->size[1];
    b->size[1] = outsize[1];
    emxEnsureCapacity((emxArray__common *)b, i1, (int32_T)sizeof(real_T), &h_emlrtRTEI);
    loop_ub = outsize[1] - 1;
    for (i1 = 0; i1 <= loop_ub; i1++) {
        b->data[i1] = a;
    }
}

/*
 * 
 */
void repmat(const emxArray_real_T *a, emxArray_real_T *b)
{
    int32_T iv4[2];
    int32_T ib;
    int32_T iacol;
    int32_T jcol;
    for (ib = 0; ib < 2; ib++) {
        iv4[ib] = a->size[ib];
    }
    ib = b->size[0] * b->size[1];
    b->size[0] = 1;
    b->size[1] = iv4[1];
    emxEnsureCapacity((emxArray__common *)b, ib, (int32_T)sizeof(real_T), &g_emlrtRTEI);
    if (b->size[1] == 0) {
    } else {
        ib = 1;
        iacol = 1;
        for (jcol = 1; jcol <= a->size[1]; jcol++) {
            b->data[emlrtDynamicBoundsCheck(ib, 1, b->size[1], &n_emlrtBCI) - 1] = a->data[emlrtDynamicBoundsCheck(iacol, 1, a->size[1], &o_emlrtBCI) - 1];
            ib++;
            iacol++;
        }
    }
}
/* End of code generation (repmat.c) */
