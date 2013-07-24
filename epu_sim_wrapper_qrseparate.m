% Path settings
switch matlabroot
   case '/Applications/MATLAB_R2011b.app' % local
      bzenv('all')
      outputDir = '/Users/bram/Documents/EPU/Simulation_2012Aug28/output/';
   otherwise   % ACCRE
      addpath('/home/zandbeb/m-files/epu_sim_20120828/');
      addpath(genpath('/home/zandbeb/m-files/general/'));
      outputDir = '/scratch/zandbeb/epu_sim_20120828/output/';
end

% Get variables from underlyings OS's environment
nA = str2double(getenv('nA'));
dMeth = str2double(getenv('dMeth'));
sigmaXi = str2double(getenv('sigmaXi'));
maxActivation = str2double(getenv('maxActivation'));
rXi = str2double(getenv('rXi'));
rV = str2double(getenv('rV'));
pN = str2double(getenv('pN'));

% Generate tag
tag = sprintf('nA%.0f_dMeth%.0f_sigmaXi%.2f_maxActivation%.2f_rXi%.2f_rV%.2f_pN%.2f',nA,dMeth,sigmaXi,maxActivation,rXi,rV,pN);
tag = strrep(tag,'.','');

% Generate job struct
job.nSes = 1000;
job.nSim = 500;
job.nA = nA;
job.nTP = 100000; 
job.nAT = 1; 
job.mV = 1;   
job.sdV = 1;
job.rV = rV;
job.dt = 10;
job.sigmaXi = sigmaXi;
job.rXi = rXi;
job.mTheta = 100;   
job.sdTheta = 0;
job.maxActivation = maxActivation;
job.affTime = 100;    
job.effTime = 10;    
job.pN = pN;
job.dMeth = dMeth;
job.tag = tag;
job.rngID = rng('shuffle');

% Run the program
epu_sim_master(job);