/*
 * epu_n_unit_accumulator_types.h
 *
 * Code generation for function 'epu_n_unit_accumulator'
 *
 * C source code generated on: Fri Aug 31 09:23:48 2012
 *
 */

#ifndef __EPU_N_UNIT_ACCUMULATOR_TYPES_H__
#define __EPU_N_UNIT_ACCUMULATOR_TYPES_H__

/* Type Definitions */
#ifndef struct_emxArray__common
#define struct_emxArray__common
typedef struct emxArray__common
{
    void *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
} emxArray__common;
#endif
#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T
typedef struct emxArray_boolean_T
{
    boolean_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
} emxArray_boolean_T;
#endif
#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T
typedef struct emxArray_int32_T
{
    int32_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
} emxArray_int32_T;
#endif
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
typedef struct emxArray_real_T
{
    real_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
} emxArray_real_T;
#endif
typedef struct
{
    uint8_T method;
    uint32_T v4_state;
    uint32_T v5_state[2];
} c_epu_n_unit_accumulatorPersist;
typedef struct
{
    c_epu_n_unit_accumulatorPersist *pd;
} epu_n_unit_accumulatorStackData;

#endif
/* End of code generation (epu_n_unit_accumulator_types.h) */
