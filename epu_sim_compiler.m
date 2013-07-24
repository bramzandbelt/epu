function epu_sim_compiler
% This function compiles the epu_sim.m file to a MEX file

cfg = coder.config('mex');
cfg.DynamicMemoryAllocation = 'AllVariableSizeArrays';
cfg.MATLABSourceComments = true;

cNS = coder.typeof(0, [1,1], [0 0]);
cNA = coder.typeof(0, [1,1], [0 0]);
cMR = coder.typeof(0, [1,1], [0 0]);
cSR = coder.typeof(0, [1,1], [0 0]);
cMT = coder.typeof(0, [1,1], [0 0]);
cST = coder.typeof(0, [1,1], [0 0]);
cT0 = coder.typeof(0, [1,1], [0 0]);
cR = coder.typeof(0, [1,1], [0 0]);
cQ = coder.typeof(0, [1,1], [0 0]);
cNTP = coder.typeof(0, [1,1], [0 0]);
cNAT = coder.typeof(0, [1,1], [0 0]);
cALim = coder.typeof(0, [1,1], [0 0]);
cDMeth = coder.typeof(0, [1,1], [0 0]);
codegen -config cfg epu_sim -args {cNS,cNA,cMR,cSR,cMT,cST,cT0,cR,cQ,cNTP,cNAT,cALim,cDMeth}