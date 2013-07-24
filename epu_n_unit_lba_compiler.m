function epu_n_unit_lba_compiler
% This function compiles the epu_n_unit_lba.m file to a MEX file

cfg = coder.config('mex');
cfg.DynamicMemoryAllocation = 'AllVariableSizeArrays';
cfg.MATLABSourceComments = true;

c_v = coder.typeof(0, [1,1e6], [0 1]);
c_theta = coder.typeof(0, [1,1e6], [0 1]);
c_affTime = coder.typeof(0, [1,1], [0 0]);
c_effTime = coder.typeof(0, [1,1], [0 0]);
c_pN = coder.typeof(0, [1,1e6], [0 1]);
c_dMeth = coder.typeof(2, [1,1], [0 0]);
c_iAT = coder.typeof(0, [1,1e6], [0 1]);

codegen -config cfg epu_n_unit_lba -args {c_v,c_theta,c_affTime,c_effTime,c_pN,c_dMeth,c_iAT}