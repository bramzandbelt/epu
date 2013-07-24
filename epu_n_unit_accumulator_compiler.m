function epu_n_unit_accumulator_compiler
% This function compiles the epu_accumulator.m file to a MEX file

cfg = coder.config('mex');
cfg.DynamicMemoryAllocation = 'AllVariableSizeArrays';
cfg.MATLABSourceComments = true;

c_nTP = coder.typeof(0, [1,1], [0 0]);
c_v = coder.typeof(0, [1,1e6], [0 1]);
c_dt = coder.typeof(0, [1,1], [0 0]);
c_sigmaXi = coder.typeof(0, [1,1], [0 0]);
c_SigmaXi = coder.typeof(0, [1e6,1e6], [1 1]);
c_theta = coder.typeof(0, [1,1e6], [0 1]);
c_k = coder.typeof(0, [1,1e6], [0 1]);
c_affTime = coder.typeof(0, [1,1], [0 0]);
c_effTime = coder.typeof(0, [1,1], [0 0]);
c_pN = coder.typeof(0, [1,1e6], [0 1]);
c_dMeth = coder.typeof(2, [1,1], [0 0]);
c_iAT = coder.typeof(0, [1,1e6], [0 1]);
% T = coder.typeof(0, [1e6,1e6], [1 1]);
% err = coder.typeof(0, [1,1], [0 0]);

codegen -config cfg epu_n_unit_accumulator -args {c_nTP,c_v,c_dt,c_sigmaXi,c_SigmaXi,c_theta,c_k,c_affTime,c_effTime,c_pN,c_dMeth,c_iAT}

% cMuRate = coder.typeof(0, [1,1e6], [0 1]);
% cWNF = coder.typeof(0, [1,1], [0 0]);
% cNTP = coder.typeof(0, [1,1], [0 0]);
% cK = coder.typeof(0, [1,1e6], [0 1]);
% cTheta = coder.typeof(0, [1,1e6], [0 1]);
% cT0 = coder.typeof(0, [1,1], [0 0]);
% cDecisionMethod = coder.typeof(2, [1,1], [0 0]);
% cQ = coder.typeof(0, [1,1e6], [0 1]);
% cNAT = coder.typeof(0, [1,1e6], [0 1]);
% codegen -config cfg epu_n_unit_accumulator -args {cMuRate,cWNF,cNTP,cK,cTheta,cT0,cDecisionMethod,cQ,cNAT}