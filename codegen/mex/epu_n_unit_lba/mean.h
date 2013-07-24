/*
 * mean.h
 *
 * Code generation for function 'mean'
 *
 * C source code generated on: Fri Aug 31 09:31:05 2012
 *
 */

#ifndef __MEAN_H__
#define __MEAN_H__
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
extern real_T mean(const emxArray_real_T *x);
#ifdef __WATCOMC__
#pragma aux mean value [8087];
#endif
#endif
/* End of code generation (mean.h) */
