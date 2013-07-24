function epu_compute_trajectory_onset_compiler
% This function compiles the epu_accumulator.m file to a MEX file

cfg = coder.config('mex');
cfg.DynamicMemoryAllocation = 'AllVariableSizeArrays';
cfg.MATLABSourceComments = true;

c_X = coder.typeof(0, [1,1e6], [0 1]);
c_Y = coder.typeof(0, [1,1e6], [0 1]);
c_Z = coder.typeof(0, [1,1], [0 0]);

codegen -config cfg epu_compute_trajectory_onset -args {c_X,c_Y,c_Z}