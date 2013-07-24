/*
 * interp1.h
 *
 * Code generation for function 'interp1'
 *
 * C source code generated on: Fri Aug 31 09:23:48 2012
 *
 */

#ifndef __INTERP1_H__
#define __INTERP1_H__
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
extern void interp1_work(emxArray_real_T *y, const emxArray_real_T *xi, emxArray_real_T *x, emxArray_real_T *yi);
#endif
/* End of code generation (interp1.h) */
