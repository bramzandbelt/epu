/*
 * interp1q.h
 *
 * Code generation for function 'interp1q'
 *
 * C source code generated on: Fri Aug 31 09:23:48 2012
 *
 */

#ifndef __INTERP1Q_H__
#define __INTERP1Q_H__
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
extern real_T interp1q(const real_T x[2], const real_T y[2], real_T xi);
#ifdef __WATCOMC__
#pragma aux interp1q value [8087];
#endif
#endif
/* End of code generation (interp1q.h) */
