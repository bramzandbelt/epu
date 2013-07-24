/*
 * filter.h
 *
 * Code generation for function 'filter'
 *
 * C source code generated on: Fri Aug 31 09:24:08 2012
 *
 */

#ifndef __FILTER_H__
#define __FILTER_H__
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
#include "epu_compute_trajectory_onset_types.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern void filter(const emxArray_real_T *b, const emxArray_real_T *x, emxArray_real_T *y);
#endif
/* End of code generation (filter.h) */
