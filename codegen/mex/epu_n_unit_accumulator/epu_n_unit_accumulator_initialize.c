/*
 * epu_n_unit_accumulator_initialize.c
 *
 * Code generation for function 'epu_n_unit_accumulator_initialize'
 *
 * C source code generated on: Fri Aug 31 09:23:48 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_n_unit_accumulator.h"
#include "epu_n_unit_accumulator_initialize.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void epu_n_unit_accumulator_once(epu_n_unit_accumulatorStackData *SD);

/* Function Definitions */

static void epu_n_unit_accumulator_once(epu_n_unit_accumulatorStackData *SD)
{
    int32_T i3;
    SD->pd->method = 0;
    SD->pd->v4_state = 1144108930U;
    for (i3 = 0; i3 < 2; i3++) {
        SD->pd->v5_state[i3] = 362436069U + 158852560U * (uint32_T)i3;
    }
}

void epu_n_unit_accumulator_initialize(epu_n_unit_accumulatorStackData *SD, emlrtContext *context)
{
    emlrtEnterRtStack(&emlrtContextGlobal);
    if (emlrtFirstTime(context)) {
        epu_n_unit_accumulator_once(SD);
    }
}
/* End of code generation (epu_n_unit_accumulator_initialize.c) */
