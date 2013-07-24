/*
 * epu_n_unit_accumulator.h
 *
 * Code generation for function 'epu_n_unit_accumulator'
 *
 * C source code generated on: Fri Aug 31 09:23:48 2012
 *
 */

#ifndef __EPU_N_UNIT_ACCUMULATOR_H__
#define __EPU_N_UNIT_ACCUMULATOR_H__
/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"

#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blascompat32.h"
#include "rtwtypes.h"
#include "epu_n_unit_accumulator_types.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern void epu_n_unit_accumulator(epu_n_unit_accumulatorStackData *SD, real_T nTP, const emxArray_real_T *v, real_T dt, real_T sigmaXi, const emxArray_real_T *SigmaXi, const emxArray_real_T *theta, const emxArray_real_T *k, real_T affTime, real_T effTime, emxArray_real_T *pN, real_T dMeth, const emxArray_real_T *iAT, real_T *rt, emxArray_real_T *activation);
#endif
/* End of code generation (epu_n_unit_accumulator.h) */
