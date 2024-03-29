/*
 * epu_align_to_event_emxutil.c
 *
 * Code generation for function 'epu_align_to_event_emxutil'
 *
 * C source code generated on: Fri Aug 31 09:30:57 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_align_to_event.h"
#include "epu_align_to_event_emxutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

void b_emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush)
{
    emxArray_real_T *emxArray;
    int32_T loop_ub;
    int32_T i;
    *pEmxArray = (emxArray_real_T *)malloc(sizeof(emxArray_real_T));
    if ((void *)*pEmxArray == NULL) {
        emlrtHeapAllocationError(srcLocation);
    }
    if (doPush) {
        emlrtPushHeapReferenceStack((void *)pEmxArray, (void (*)(void *, boolean_T))emxFree_real_T);
    }
    emxArray = *pEmxArray;
    emxArray->data = (real_T *)NULL;
    emxArray->numDimensions = numDimensions;
    emxArray->size = (int32_T *)malloc((uint32_T)(sizeof(int32_T) * numDimensions));
    if ((void *)emxArray->size == NULL) {
        emlrtHeapAllocationError(srcLocation);
    }
    emxArray->allocatedSize = 0;
    emxArray->canFreeData = TRUE;
    loop_ub = numDimensions - 1;
    for (i = 0; i <= loop_ub; i++) {
        emxArray->size[i] = 0;
    }
}

void emxEnsureCapacity(emxArray__common *emxArray, int32_T oldNumel, int32_T elementSize, const emlrtRTEInfo *srcLocation)
{
    int32_T newNumel;
    int32_T loop_ub;
    int32_T i;
    void *newData;
    newNumel = 1;
    loop_ub = emxArray->numDimensions - 1;
    for (i = 0; i <= loop_ub; i++) {
        newNumel = (int32_T)emlrtSizeMul((uint32_T)newNumel, (uint32_T)emxArray->size[i], srcLocation);
    }
    if (newNumel > emxArray->allocatedSize) {
        loop_ub = emxArray->allocatedSize;
        if (loop_ub < 16) {
            loop_ub = 16;
        }
        while (loop_ub < newNumel) {
            loop_ub = (int32_T)emlrtSizeMul((uint32_T)loop_ub, 2U, srcLocation);
        }
        newData = calloc((uint32_T)loop_ub, (uint32_T)elementSize);
        if (newData == NULL) {
            emlrtHeapAllocationError(srcLocation);
        }
        if (emxArray->data != NULL) {
            memcpy(newData, emxArray->data, (uint32_T)(elementSize * oldNumel));
            if (emxArray->canFreeData) {
                free(emxArray->data);
            }
        }
        emxArray->data = newData;
        emxArray->allocatedSize = loop_ub;
        emxArray->canFreeData = TRUE;
    }
}

void emxFree_boolean_T(emxArray_boolean_T **pEmxArray)
{
    if (*pEmxArray != (emxArray_boolean_T *)NULL) {
        if ((*pEmxArray)->canFreeData) {
            free((void *)(*pEmxArray)->data);
        }
        free((void *)(*pEmxArray)->size);
        free((void *)*pEmxArray);
        *pEmxArray = (emxArray_boolean_T *)NULL;
    }
}

void emxFree_int32_T(emxArray_int32_T **pEmxArray)
{
    if (*pEmxArray != (emxArray_int32_T *)NULL) {
        if ((*pEmxArray)->canFreeData) {
            free((void *)(*pEmxArray)->data);
        }
        free((void *)(*pEmxArray)->size);
        free((void *)*pEmxArray);
        *pEmxArray = (emxArray_int32_T *)NULL;
    }
}

void emxFree_real_T(emxArray_real_T **pEmxArray)
{
    if (*pEmxArray != (emxArray_real_T *)NULL) {
        if ((*pEmxArray)->canFreeData) {
            free((void *)(*pEmxArray)->data);
        }
        free((void *)(*pEmxArray)->size);
        free((void *)*pEmxArray);
        *pEmxArray = (emxArray_real_T *)NULL;
    }
}

void emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush)
{
    emxArray_boolean_T *emxArray;
    int32_T loop_ub;
    int32_T i;
    *pEmxArray = (emxArray_boolean_T *)malloc(sizeof(emxArray_boolean_T));
    if ((void *)*pEmxArray == NULL) {
        emlrtHeapAllocationError(srcLocation);
    }
    if (doPush) {
        emlrtPushHeapReferenceStack((void *)pEmxArray, (void (*)(void *, boolean_T))emxFree_boolean_T);
    }
    emxArray = *pEmxArray;
    emxArray->data = (boolean_T *)NULL;
    emxArray->numDimensions = numDimensions;
    emxArray->size = (int32_T *)malloc((uint32_T)(sizeof(int32_T) * numDimensions));
    if ((void *)emxArray->size == NULL) {
        emlrtHeapAllocationError(srcLocation);
    }
    emxArray->allocatedSize = 0;
    emxArray->canFreeData = TRUE;
    loop_ub = numDimensions - 1;
    for (i = 0; i <= loop_ub; i++) {
        emxArray->size[i] = 0;
    }
}

void emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush)
{
    emxArray_int32_T *emxArray;
    int32_T loop_ub;
    int32_T i;
    *pEmxArray = (emxArray_int32_T *)malloc(sizeof(emxArray_int32_T));
    if ((void *)*pEmxArray == NULL) {
        emlrtHeapAllocationError(srcLocation);
    }
    if (doPush) {
        emlrtPushHeapReferenceStack((void *)pEmxArray, (void (*)(void *, boolean_T))emxFree_int32_T);
    }
    emxArray = *pEmxArray;
    emxArray->data = (int32_T *)NULL;
    emxArray->numDimensions = numDimensions;
    emxArray->size = (int32_T *)malloc((uint32_T)(sizeof(int32_T) * numDimensions));
    if ((void *)emxArray->size == NULL) {
        emlrtHeapAllocationError(srcLocation);
    }
    emxArray->allocatedSize = 0;
    emxArray->canFreeData = TRUE;
    loop_ub = numDimensions - 1;
    for (i = 0; i <= loop_ub; i++) {
        emxArray->size[i] = 0;
    }
}

void emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush)
{
    emxArray_real_T *emxArray;
    int32_T loop_ub;
    int32_T i;
    *pEmxArray = (emxArray_real_T *)malloc(sizeof(emxArray_real_T));
    if ((void *)*pEmxArray == NULL) {
        emlrtHeapAllocationError(srcLocation);
    }
    if (doPush) {
        emlrtPushHeapReferenceStack((void *)pEmxArray, (void (*)(void *, boolean_T))emxFree_real_T);
    }
    emxArray = *pEmxArray;
    emxArray->data = (real_T *)NULL;
    emxArray->numDimensions = numDimensions;
    emxArray->size = (int32_T *)malloc((uint32_T)(sizeof(int32_T) * numDimensions));
    if ((void *)emxArray->size == NULL) {
        emlrtHeapAllocationError(srcLocation);
    }
    emxArray->allocatedSize = 0;
    emxArray->canFreeData = TRUE;
    loop_ub = numDimensions - 1;
    for (i = 0; i <= loop_ub; i++) {
        emxArray->size[i] = 0;
    }
}
/* End of code generation (epu_align_to_event_emxutil.c) */
