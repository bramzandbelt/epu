function epu_align_to_event_compiler
% This function compiles the epu_accumulator.m file to a MEX file

cfg = coder.config('mex');
cfg.DynamicMemoryAllocation = 'AllVariableSizeArrays';
cfg.MATLABSourceComments = true;

c_eventTimes = coder.typeof(0, [1,1], [0 0]);
c_outputTimeFrame = coder.typeof(0, [1,2], [0 0]);
c_minTrialTime = coder.typeof(0, [1,1], [0 0]);
c_trajectories = coder.typeof(0, [1,1e6], [0 1]);

codegen -config cfg epu_align_to_event -args {c_eventTimes,c_outputTimeFrame,c_minTrialTime,c_trajectories}