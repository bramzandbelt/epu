/*
 * epu_n_unit_ba.h
 *
 * Code generation for function 'epu_n_unit_ba'
 *
 * C source code generated on: Tue Oct 30 14:49:26 2012
 *
 */

#ifndef __EPU_N_UNIT_BA_H__
#define __EPU_N_UNIT_BA_H__
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
#include "epu_n_unit_ba_types.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern void epu_n_unit_ba(const emxArray_real_T *v, const emxArray_real_T *theta, const emxArray_real_T *k, real_T affTime, real_T effTime, emxArray_real_T *pN, real_T dMeth, const emxArray_real_T *iAT, real_T *rt, emxArray_real_T *activation);
#endif
/* End of code generation (epu_n_unit_ba.h) */
