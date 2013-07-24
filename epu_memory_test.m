function memory_test_epu_sim
% JUST RUN THIS WITH PROFILER

job = epu_sim_master('get_defaults');

job.nSim = 500;
job.nSes = 1;
job.sdV = 1;
job.rV = 0;
job.pN = 1;
job.sigmaXi = 0;
job.maxActivation = 200;

epu_sim_master(job);