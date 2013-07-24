/*
 * median.h
 *
 * Code generation for function 'median'
 *
 * C source code generated on: Fri Aug 31 09:24:09 2012
 *
 */

#ifndef __MEDIAN_H__
#define __MEDIAN_H__
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
extern real_T median(const emxArray_real_T *x);
#ifdef __WATCOMC__
#pragma aux median value [8087];
#endif
#endif
/* End of code generation (median.h) */
