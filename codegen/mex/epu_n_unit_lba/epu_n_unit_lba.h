/*
 * epu_n_unit_lba.h
 *
 * Code generation for function 'epu_n_unit_lba'
 *
 * C source code generated on: Fri Aug 31 09:31:05 2012
 *
 */

#ifndef __EPU_N_UNIT_LBA_H__
#define __EPU_N_UNIT_LBA_H__
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
#include "epu_n_unit_lba_types.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern void eml_assert_valid_dim(real_T dim);
extern void epu_n_unit_lba(const emxArray_real_T *v, const emxArray_real_T *theta, real_T affTime, real_T effTime, emxArray_real_T *pN, real_T dMeth, const emxArray_real_T *iAT, real_T *rt, emxArray_real_T *activation);
#endif
/* End of code generation (epu_n_unit_lba.h) */
