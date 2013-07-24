/*
 * epu_n_unit_accumulator_api.c
 *
 * Code generation for function 'epu_n_unit_accumulator_api'
 *
 * C source code generated on: Fri Aug 31 09:23:48 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "epu_n_unit_accumulator.h"
#include "epu_n_unit_accumulator_api.h"
#include "epu_n_unit_accumulator_emxutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRTEInfo m_emlrtRTEI = { 1, 1, "epu_n_unit_accumulator_api", "" };

/* Function Declarations */
static real_T b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId);
static const mxArray *b_emlrt_marshallOut(emxArray_real_T *u);
static void c_emlrt_marshallIn(const mxArray *v, const char_T *identifier, emxArray_real_T *y);
static void d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void e_emlrt_marshallIn(const mxArray *SigmaXi, const char_T *identifier, emxArray_real_T *y);
static real_T emlrt_marshallIn(const mxArray *nTP, const char_T *identifier);
static const mxArray *emlrt_marshallOut(real_T u);
static void f_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static real_T g_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId);
static void h_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void i_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, emxArray_real_T *ret);

/* Function Definitions */

static real_T b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId)
{
    real_T y;
    y = g_emlrt_marshallIn(emlrtAlias(u), parentId);
    emlrtDestroyArray(&u);
    return y;
}

static const mxArray *b_emlrt_marshallOut(emxArray_real_T *u)
{
    const mxArray *y;
    const mxArray *m10;
    real_T (*pData)[];
    int32_T i5;
    int32_T i;
    int32_T b_i;
    y = NULL;
    m10 = mxCreateNumericArray(2, u->size, mxDOUBLE_CLASS, mxREAL);
    pData = (real_T (*)[])mxGetPr(m10);
    i5 = 0;
    for (i = 0; i < u->size[1]; i++) {
        for (b_i = 0; b_i < u->size[0]; b_i++) {
            (*pData)[i5] = u->data[b_i + u->size[0] * i];
            i5++;
        }
    }
    emlrtAssign(&y, m10);
    return y;
}

static void c_emlrt_marshallIn(const mxArray *v, const char_T *identifier, emxArray_real_T *y)
{
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = identifier;
    thisId.fParent = NULL;
    d_emlrt_marshallIn(emlrtAlias(v), &thisId, y);
    emlrtDestroyArray(&v);
}

static void d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
    h_emlrt_marshallIn(emlrtAlias(u), parentId, y);
    emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const mxArray *SigmaXi, const char_T *identifier, emxArray_real_T *y)
{
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = identifier;
    thisId.fParent = NULL;
    f_emlrt_marshallIn(emlrtAlias(SigmaXi), &thisId, y);
    emlrtDestroyArray(&SigmaXi);
}

static real_T emlrt_marshallIn(const mxArray *nTP, const char_T *identifier)
{
    real_T y;
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = identifier;
    thisId.fParent = NULL;
    y = b_emlrt_marshallIn(emlrtAlias(nTP), &thisId);
    emlrtDestroyArray(&nTP);
    return y;
}

static const mxArray *emlrt_marshallOut(real_T u)
{
    const mxArray *y;
    const mxArray *m9;
    y = NULL;
    m9 = mxCreateDoubleScalar(u);
    emlrtAssign(&y, m9);
    return y;
}

static void f_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
    i_emlrt_marshallIn(emlrtAlias(u), parentId, y);
    emlrtDestroyArray(&u);
}

static real_T g_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId)
{
    real_T ret;
    emlrtCheckBuiltInCtxR2011b(&emlrtContextGlobal, msgId, src, "double", FALSE, 0U, 0);
    ret = *(real_T *)mxGetData(src);
    emlrtDestroyArray(&src);
    return ret;
}

static void h_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
    int32_T iv23[2];
    boolean_T bv0[2];
    int32_T i6;
    static const boolean_T bv1[2] = { FALSE, TRUE };
    for (i6 = 0; i6 < 2; i6++) {
        iv23[i6] = 1 + 999999 * i6;
        bv0[i6] = bv1[i6];
    }
    emlrtCheckVsBuiltInCtxR2011b(&emlrtContextGlobal, msgId, src, "double", FALSE, 2U, iv23, bv0, ret->size);
    i6 = ret->size[0] * ret->size[1];
    ret->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)ret, i6, (int32_T)sizeof(real_T), (emlrtRTEInfo *)NULL);
    emlrtImportArrayR2011b(src, ret->data, 8, FALSE);
    emlrtDestroyArray(&src);
}

static void i_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
    int32_T iv24[2];
    boolean_T bv2[2];
    int32_T i;
    for (i = 0; i < 2; i++) {
        iv24[i] = -1;
        bv2[i] = TRUE;
    }
    emlrtCheckVsBuiltInCtxR2011b(&emlrtContextGlobal, msgId, src, "double", FALSE, 2U, iv24, bv2, ret->size);
    i = ret->size[0] * ret->size[1];
    emxEnsureCapacity((emxArray__common *)ret, i, (int32_T)sizeof(real_T), (emlrtRTEInfo *)NULL);
    emlrtImportArrayR2011b(src, ret->data, 8, FALSE);
    emlrtDestroyArray(&src);
}

void epu_n_unit_accumulator_api(epu_n_unit_accumulatorStackData *SD, const mxArray * const prhs[12], const mxArray *plhs[2])
{
    emxArray_real_T *v;
    emxArray_real_T *SigmaXi;
    emxArray_real_T *theta;
    emxArray_real_T *k;
    emxArray_real_T *pN;
    emxArray_real_T *iAT;
    emxArray_real_T *b_SigmaXi;
    real_T nTP;
    real_T dt;
    real_T sigmaXi;
    real_T affTime;
    real_T effTime;
    real_T dMeth;
    int32_T i4;
    int32_T loop_ub;
    real_T rt;
    emlrtHeapReferenceStackEnterFcn();
    emxInit_real_T(&v, 2, &m_emlrtRTEI, TRUE);
    emxInit_real_T(&SigmaXi, 2, &m_emlrtRTEI, TRUE);
    emxInit_real_T(&theta, 2, &m_emlrtRTEI, TRUE);
    emxInit_real_T(&k, 2, &m_emlrtRTEI, TRUE);
    emxInit_real_T(&pN, 2, &m_emlrtRTEI, TRUE);
    emxInit_real_T(&iAT, 2, &m_emlrtRTEI, TRUE);
    emxInit_real_T(&b_SigmaXi, 2, &m_emlrtRTEI, TRUE);
    /* Marshall function inputs */
    nTP = emlrt_marshallIn(emlrtAliasP(prhs[0]), "nTP");
    c_emlrt_marshallIn(emlrtAliasP(prhs[1]), "v", v);
    dt = emlrt_marshallIn(emlrtAliasP(prhs[2]), "dt");
    sigmaXi = emlrt_marshallIn(emlrtAliasP(prhs[3]), "sigmaXi");
    e_emlrt_marshallIn(emlrtAliasP(prhs[4]), "SigmaXi", SigmaXi);
    c_emlrt_marshallIn(emlrtAliasP(prhs[5]), "theta", theta);
    c_emlrt_marshallIn(emlrtAliasP(prhs[6]), "k", k);
    affTime = emlrt_marshallIn(emlrtAliasP(prhs[7]), "affTime");
    effTime = emlrt_marshallIn(emlrtAliasP(prhs[8]), "effTime");
    c_emlrt_marshallIn(emlrtAliasP(prhs[9]), "pN", pN);
    dMeth = emlrt_marshallIn(emlrtAliasP(prhs[10]), "dMeth");
    c_emlrt_marshallIn(emlrtAliasP(prhs[11]), "iAT", iAT);
    /* Invoke the target function */
    i4 = b_SigmaXi->size[0] * b_SigmaXi->size[1];
    b_SigmaXi->size[0] = SigmaXi->size[0];
    b_SigmaXi->size[1] = SigmaXi->size[1];
    emxEnsureCapacity((emxArray__common *)b_SigmaXi, i4, (int32_T)sizeof(real_T), &m_emlrtRTEI);
    loop_ub = SigmaXi->size[0] * SigmaXi->size[1] - 1;
    for (i4 = 0; i4 <= loop_ub; i4++) {
        b_SigmaXi->data[i4] = SigmaXi->data[i4];
    }
    epu_n_unit_accumulator(SD, nTP, v, dt, sigmaXi, b_SigmaXi, theta, k, affTime, effTime, pN, dMeth, iAT, &rt, SigmaXi);
    /* Marshall function outputs */
    plhs[0] = emlrt_marshallOut(rt);
    plhs[1] = b_emlrt_marshallOut(SigmaXi);
    emxFree_real_T(&b_SigmaXi);
    emxFree_real_T(&iAT);
    emxFree_real_T(&pN);
    emxFree_real_T(&k);
    emxFree_real_T(&theta);
    emxFree_real_T(&SigmaXi);
    emxFree_real_T(&v);
    emlrtHeapReferenceStackLeaveFcn();
}
/* End of code generation (epu_n_unit_accumulator_api.c) */
