/*
 * sum.h
 *
 * Code generation for function 'sum'
 *
 * C source code generated on: Fri Aug 31 09:23:48 2012
 *
 */

#ifndef __SUM_H__
#define __SUM_H__
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
extern real_T sum(const emxArray_boolean_T *x);
#ifdef __WATCOMC__
#pragma aux sum value [8087];
#endif
#endif
/* End of code generation (sum.h) */
