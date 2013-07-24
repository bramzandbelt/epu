function varargout = epu_sim_master(varargin)
%
%% Syntax
% epu_sim_master(job);
%
% job  - struct with fields
% .nSes           - number of sessions
%                   * default:        500
% .nSim           - number of simulations
%                   * default:        1000
% .nA             - number of redundant accumulators
%                   * default:        10
% .nTP            - number of time points (TP) for which to log data (in ms from
%                   target onset)
%                   * default:        1500
% .nAT            - number of activation trajectories (AT) to provide (i.e. the
%                   number of accumulators for which ATs are outputted)
%                   * default:        1
%                   N.B. CURRENT CODE ASSUMES nAT = 1
% .mV             - mean of the lognormal accumulation rate distribution
%                   * units:          spikes s-1 ms-1
%                   * size & class:   1x1 double
%                   * support:        mV ? ?: (0,+?)
%                   * default:        1
% .sdV            - s.d. of the lognormal accumulation rate distribution
%                   * units:          spikes s-1 ms-1
%                   * size & class:   1x1 double
%                   * support:        sdV ? ?: (0,+?)
%                   * default:        1
% .rV             - correlation of accumulation rates between accumulators
%                   * units:          unitless
%                   * size & class:   1xN double, where N is the number of
%                                     correlation coefficients
%                   * support:        rV ? ?: [0,1]
%                   * default:        [0:.1:1]
% .dt             - time step size of stochastic differential equations
%                   * units:          ms
%                   * size & class:   1x1 double
%                   * support:        dt ? ?: [0,+?)
% .sigmaXi        - scale parameter of the Gaussian noise distribution
%                   * units:          spikes s-1
%                   * size & class:   1x1 double
%                   * support:        sigmaXi ? ?: (0,+?)
%                   * default:        0
% .rXi            - correlation of the Gaussian noise
%                   * units:          unitless
%                   * size & class:   1x1 double
%                   * support:        rXi ? ?: [0,1]
%                   * default:        1
% .mTheta         - mean of the Gaussian threshold distribution
%                   * units:          spikes s-1
%                   * size & class:   1x1 double
%                   * default:        100
% .sdTheta        - s.d. of the Gaussian threshold distribution
%                   * units:          spikes s-1
%                   * size & class:   1x1 double
%                   * support:        sdTheta ? ?: (0,+?)
%                   * default:        0
% .maxActivation  - maximum activation level an accumulator can reach
%                   * units:          unitless or spikes s-1
%                   * size & class:   1x1 double
%                   * support:        maxActivation ? ?: (0,+?)
%                                     * (0,1]  considered fraction of mTheta
%                                     * [1,+?) considered absolute activ. level
%                   * default:        1000
% .affTime        - afferent (encoding) time
%                   * units:          ms
%                   * size & class:   1x1 double
%                   * support:        affTime ? ?: [0,+?)
%                   * default:        100
% .effTime        - efferent (response execution) time
%                   * units:          ms
%                   * size & class:   1x1 double
%                   * support:        effTime ? ?: [0,+?)
%                   * default:        10
% .pN             - proportion of accumulators necessary to produce an RT ('RT
%                   rule').
%                   * units:          unitless
%                   * size & class:   1x1 double
%                   * support:        pN ? ?: [0,1], where 0 means that the very
%                     first accumulator reaching threshold produces RT
%                   * default:        0
% .dMeth          - decision method, polling or pooling
%                   * units:          unitless
%                   * size & class:   1x1 double
%                   * support:        * 1   polling
%                                     * 2   pooling
%                   * default:        1
% .tag            - optional string that will serve as a suffix in the filename
%                   * default:        ''
% .rngID          - ID of random number generator seed
%                   * default:        rng('shuffle')
%


%% Check input arguments of epu_sim_master

if ischar(varargin{1}) && strncmpi(varargin{1},'get_defaults',12)
   varargout{1} = epu_check_inputs(varargin{1});
   return
else
   job = varargin{1};
   [nSes,nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation,affTime,effTime,pN,dMeth,tag,rngID] = epu_check_inputs(job);
   job.tag = tag;
end

%==========%
% Settings %
%==========%

% 1. General
switch matlabroot % Determine on which system we are running
   case '/Applications/MATLAB_R2011b.app' % local
      settings.general.datetime     = datestr(now);
      settings.general.environment  = 'local';
      
      bzenv('all')
      settings.general.outputPath                    = '/Users/bram/Documents/EPU/Simulation_2012Aug28/output';
      
      
   otherwise   % ACCRE
      settings.general.datetime     = datestr(now);
      settings.general.environment  = 'ACCRE';
            
      addpath('/home/zandbeb/m-files/epu_sim_20120828/');
      addpath(genpath('/home/zandbeb/m-files/general/'));
      settings.general.outputPath = '/scratch/zandbeb/epu_sim_20120828/output/';
      
end
settings.general.fileTimestamp                 = datestr(settings.general.datetime,'yyyymmddTHHMMSS');
settings.general.fractSesToSave               = 0.01; % Fraction of sessions to save individually

% 2. Statistics

settings.statistics.ciType                      = 95; % Percentage of confidence interval
   
settings.statistics.qntls                     = [.1 .3 .5 .7 .9]; % Quantiles for rt, threshold, rate
settings.statistics.densityBinSizeRt          = 50;
settings.statistics.densityBinSizeThreshold   = 10;
settings.statistics.densityBinSizeRate        = 0.1;
settings.statistics.nDensityBinsAct            = 101; % For both threshold and rate
settings.statistics.nBrainBehaviorBins        = 10; % Bin size for brain-behavior relationships
settings.statistics.minTrialsWoodmanBin       = 10; % Minimum number of trials per bin
settings.statistics.outputTimeFrameBnds         = [-200 10];
settings.statistics.rtBinLimit                 = 2000; % Bins with an average RT above this value will not be used to compute relationship between threshold/rate and RT


% Fit type objects
settings.statistics.fitTypePoly1                = fittype('poly1'); % First-order polynomial
settings.statistics.fitTypePower1               = fittype('power1'); % One-term power series
settings.statistics.fitTypeRat01                = fittype('rat01'); % Rational function with 0-degree numerator and 1st-degree denominator
% Fit options objects
settings.statistics.fitOptionsPoly1             = fitoptions('poly1'); % First-order polynomial
settings.statistics.fitOptionsPower1            = fitoptions('power1'); % One-term power series
settings.statistics.fitOptionsRat01             = fitoptions('rat01'); % Rational function with 0-degree numerator and 1st-degree denominator
settings.statistics.fitOptionsRat01.StartPoint  = [1 1]; % Just a guess for starting value

%============%
% Simulation %
%============%

% InitselectedAccumse dataset variables for storage of simulation data
nCombinations = prod([numel(rV),numel(pN)]);
simDataSingle = initiate_dataset('single',nCombinations,job,settings);
simDataMulti = initiate_dataset('multi',nCombinations,job,settings);

% Save dataset variables
save(fullfile(settings.general.outputPath,['sim_',tag,'_',settings.general.fileTimestamp,'_SingleData.mat']),'simDataSingle','-v7.3');
save(fullfile(settings.general.outputPath,['sim_',tag,'_',settings.general.fileTimestamp,'_MultiData.mat']),'simDataMulti','-v7.3');

counter = 0;

for iRV = rV
   for iPN = pN
      
      counter = counter + 1;
      
      % Clear mex function epu_n_unit_accumulator_mex from memory (i.e. reset
      % rng) and seed rng. Note that reseeding does not affect the
      % epu_n_unit_accumulator_mex; clearing only resets it. This needs to be
      % changed!
      clear epu_n_unit_accumulator_mex
      rng(rngID);
      
      % Pre-allocate stats structure
      stats = epu_session_statistics('pre-allocate',job,settings);
            
      % Initiate progressbar, depending on the system we are running on
      switch matlabroot % Determine on which system we are running
         case '/Applications/MATLAB_R2011b.app' % local
            progressbar;
      end
      
      tStart = tic;
      
      for iSes = 1:nSes
                  
         %% Generate rt distribution and activation trajectories
         [rt,activation,v,theta,iAT] = ...
         epu_sim(nSim,nA,nTP,nAT,mV,sdV,iRV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation, ...
         affTime,effTime,iPN,dMeth);
         
         %% Get session statistics of behavior and brain-behavior relationships
         stats(iSes) = epu_session_statistics(rt,activation,iAT,job,settings);
         
         disp(['This is session ',num2str(iSes),', the time is ',datestr(now,'HH:MM:SS')]);
         
      end
      
      %% Save single session data
      simDataSingle = save_dataset('single',job,settings,simDataSingle,iPN,iRV,counter,tStart,stats);
      
      %% Save multi session data
      simDataMulti = save_dataset('multi',job,settings,simDataMulti,iPN,iRV,counter,tStart,stats);
      
   end
end
end

%% NESTED FUNCTIONS
% 



function simData = initiate_dataset(type,nCombinations,job,settings)
      
      nSes = job.nSes;
      nBrainBehaviorBins = settings.statistics.nBrainBehaviorBins;

      part1 = dataset({(1:nCombinations)','simulationId'}, ...        % GENERAL
                        {nan(nCombinations,1),'nSes'}, ...
                        {nan(nCombinations,1),'nSim'}, ...
                        {nan(nCombinations,1),'nA'}, ...
                        {nan(nCombinations,1),'nTP'}, ...
                        {nan(nCombinations,1),'nAT'}, ...
                        {nan(nCombinations,1),'mV'}, ...
                        {nan(nCombinations,1),'sdV'}, ...
                        {nan(nCombinations,1),'rV'}, ...          
                        {nan(nCombinations,1),'dt'}, ...   
                        {nan(nCombinations,1),'sigmaXi'}, ...   
                        {nan(nCombinations,1),'rXi'}, ...   
                        {nan(nCombinations,1),'mTheta'}, ...
                        {nan(nCombinations,1),'sdTheta'}, ...
                        {nan(nCombinations,1),'maxActivation'}, ...
                        {nan(nCombinations,1),'affTime'}, ...
                        {nan(nCombinations,1),'effTime'}, ...
                        {nan(nCombinations,1),'pN'}, ...
                        {nan(nCombinations,1),'dMeth'}, ...
                        {cell(nCombinations,1),'tag'}, ...
                        {cell(nCombinations,1),'rngID'}, ...
                        {nan(nCombinations,1),'elapsedTime'});
                  
      part2 = dataset(  {cell(nCombinations,1),'iAT'}, ...
                        {cell(nCombinations,1),'iSes'});

      part3 = dataset(  {cell(nCombinations,1),'nRecorded'}, ...
                        {cell(nCombinations,1),'rt'}, ...
                        {cell(nCombinations,1),'trajectory'}, ...
                        {cell(nCombinations,1),'binnedTrajectories'}, ...
                        {cell(nCombinations,1),'threshold'}, ...
                        {cell(nCombinations,1),'rate'}, ...
                        {cell(nCombinations,1),'thresVsRtPoly1_H'}, ...
                        {cell(nCombinations,1),'rateVsRtPoly1_H'}, ...
                        {cell(nCombinations,1),'rateVsRtPower1_H'}, ...
                        {cell(nCombinations,1),'rateVsRtRat01_H'},...
                        {cell(nCombinations,1),'thresVsRtPoly1_W'}, ...
                        {cell(nCombinations,1),'rateVsRtPoly1_W'}, ...
                        {cell(nCombinations,1),'rateVsRtPower1_W'}, ...
                        {cell(nCombinations,1),'rateVsRtRat01_W'});
      
      switch type
         case 'single'
            simData = horzcat(part1,part2,part3);
         case 'multi'
            
            % Fill in the dataset stucture with NaNs
            for iCombi = 1:nCombinations
               part3.nRecorded{iCombi}.mean = nan(1,1);
               part3.nRecorded{iCombi}.ci = nan(1,2);

               part3.nRecorded{iCombi}.rt.mean.mean = nan(1,1);
               part3.nRecorded{iCombi}.rt.mean.ci = nan(1,2);

               part3.rt{iCombi}.mean.mean = nan(1,1);
               part3.rt{iCombi}.mean.ci = nan(1,2);
               part3.rt{iCombi}.mean.data = nan(1,nSes);
               part3.rt{iCombi}.median.mean = nan(1,1);
               part3.rt{iCombi}.median.ci = nan(1,2);
               part3.rt{iCombi}.median.data = nan(1,nSes);
               part3.rt{iCombi}.std.mean = nan(1,1);
               part3.rt{iCombi}.std.ci = nan(1,2);
               part3.rt{iCombi}.cov.mean = nan(1,1);
               part3.rt{iCombi}.cov.ci = nan(1,2);
               part3.rt{iCombi}.cov.data = nan(1,nSes);
               part3.rt{iCombi}.iqr.mean = nan(1,1);
               part3.rt{iCombi}.iqr.ci = nan(1,2);
               part3.rt{iCombi}.iqr.data = nan(1,nSes);
               part3.rt{iCombi}.range.mean = nan(1,1);
               part3.rt{iCombi}.range.ci = nan(1,2);
               part3.rt{iCombi}.skewness.mean = nan(1,1);
               part3.rt{iCombi}.skewness.ci = nan(1,2);
               part3.rt{iCombi}.kurtosis.mean = nan(1,1);
               part3.rt{iCombi}.kurtosis.ci = nan(1,2);
               part3.rt{iCombi}.edfX.mean = nan(1,1);
               part3.rt{iCombi}.edfX.ci = nan(1,2);
               part3.rt{iCombi}.edfY.mean = nan(1,1);
               part3.rt{iCombi}.edfY.ci = nan(1,2);
               part3.rt{iCombi}.quantileX.mean = nan(1,1);
               part3.rt{iCombi}.quantileX.ci = nan(1,2);
               part3.rt{iCombi}.quantileY.mean = nan(1,1);
               part3.rt{iCombi}.quantileY.ci = nan(1,2);
               part3.rt{iCombi}.histX.mean = nan(1,1);
               part3.rt{iCombi}.histX.ci = nan(1,2);
               part3.rt{iCombi}.histY.mean = nan(1,1);
               part3.rt{iCombi}.histY.ci = nan(1,2);
               part3.rt{iCombi}.kernelX.mean = nan(1,1);
               part3.rt{iCombi}.kernelX.ci = nan(1,2);
               part3.rt{iCombi}.kernelY.mean = nan(1,1);
               part3.rt{iCombi}.kernelY.ci = nan(1,2);

               part3.threshold{iCombi} = part3.rt{iCombi};
               part3.rate{iCombi} = part3.rt{iCombi};

               part3.thresVsRtPoly1_H{iCombi}.dataX.mean = nan(1,nBrainBehaviorBins);
               part3.thresVsRtPoly1_H{iCombi}.dataX.ci = nan(2,nBrainBehaviorBins);
               part3.thresVsRtPoly1_H{iCombi}.dataY.mean = nan(1,nBrainBehaviorBins);
               part3.thresVsRtPoly1_H{iCombi}.dataY.ci = nan(2,nBrainBehaviorBins);
               part3.thresVsRtPoly1_H{iCombi}.params.mean = nan(1,2);
               part3.thresVsRtPoly1_H{iCombi}.params.ci = nan(2,2);
               part3.thresVsRtPoly1_H{iCombi}.params.sign = nan(1,2);
               part3.thresVsRtPoly1_H{iCombi}.params.data = nan(nSes,2);
               part3.thresVsRtPoly1_H{iCombi}.paramsSign.data = nan(nSes,2);
               part3.thresVsRtPoly1_H{iCombi}.rmse.mean = nan(1,1);
               part3.thresVsRtPoly1_H{iCombi}.rmse.ci = nan(1,2);
               part3.thresVsRtPoly1_H{iCombi}.rmseCoV.mean = nan(1,1);
               part3.thresVsRtPoly1_H{iCombi}.rmseCoV.ci = nan(1,2);
               part3.thresVsRtPoly1_H{iCombi}.rSquare.mean = nan(1,1);
               part3.thresVsRtPoly1_H{iCombi}.rSquare.ci = nan(1,2);
               part3.thresVsRtPoly1_H{iCombi}.fitSuccess.mean = nan(1,1);

               part3.rateVsRtPoly1_H{iCombi} = part3.thresVsRtPoly1_H{iCombi};
               part3.rateVsRtPower1_H{iCombi} = part3.thresVsRtPoly1_H{iCombi};
               part3.rateVsRtRat01_H{iCombi} = part3.thresVsRtPoly1_H{iCombi};
               part3.thresVsRtPoly1_W{iCombi} = part3.thresVsRtPoly1_H{iCombi};
               part3.rateVsRtPoly1_W{iCombi} = part3.thresVsRtPoly1_H{iCombi};
               part3.rateVsRtPower1_W{iCombi} = part3.thresVsRtPoly1_H{iCombi};
               part3.rateVsRtRat01_W{iCombi} = part3.thresVsRtPoly1_H{iCombi};

            end
            
            simData = horzcat(part1,part3);
      end
      
end

function simData = save_dataset(type,job,settings,simData,iPN,iRV,counter,tStart,stats)


switch lower(type)
   case 'single'
      
      %% Save single session data
      nSesToSave = ceil(settings.general.fractSesToSave*job.nSes); % Number of indivdiual sessions for which to save data
      iSes = sort(randperm(job.nSes,nSesToSave));
      
      simData.nSes(counter) = job.nSes;
      simData.nSim(counter) = job.nSim;
      simData.nA(counter) = job.nA;
      simData.nTP(counter) = job.nTP;
      simData.nAT(counter) = job.nAT;
      simData.mV(counter) = job.mV;
      simData.sdV(counter) = job.sdV;
      simData.rV(counter) = iRV;
      simData.dt(counter) = job.dt;
      simData.sigmaXi(counter) = job.sigmaXi;
      simData.rXi(counter) = job.rXi;
      simData.mTheta(counter) = job.mTheta;
      simData.sdTheta(counter) = job.sdTheta;
      simData.maxActivation(counter) = job.maxActivation;
      simData.affTime(counter) = job.affTime;
      simData.effTime(counter) = job.effTime;
      simData.pN(counter) = iPN;
      simData.dMeth(counter) = job.dMeth;
      simData.tag{counter} = job.tag;
      simData.rngID{counter} = job.rngID;
      simData.elapsedTime(counter) = toc(tStart);

      simData.iAT{counter} = vertcat(stats.iAT);
      simData.iSes{counter} = iSes;
      
      simData.nRecorded{counter} = vertcat(stats(iSes).nRecorded);
      
      rt = vertcat(stats.rt);

      simData.rt{counter}.mean = vertcat(rt(iSes).mean);
      simData.rt{counter}.median = vertcat(rt(iSes).median);
      simData.rt{counter}.std = vertcat(rt(iSes).std);
      simData.rt{counter}.cov = vertcat(rt(iSes).cov);
      simData.rt{counter}.iqr = vertcat(rt(iSes).iqr);
      simData.rt{counter}.range = vertcat(rt(iSes).range);
      simData.rt{counter}.skewness = vertcat(rt(iSes).skewness);
      simData.rt{counter}.kurtosis = vertcat(rt(iSes).kurtosis);
      simData.rt{counter}.edfX = vertcat(rt(iSes).edfX);
      simData.rt{counter}.edfY = vertcat(rt(iSes).edfY);
      simData.rt{counter}.quantileX = vertcat(rt(iSes).quantileX);
      simData.rt{counter}.quantileY = vertcat(rt(iSes).quantileY);
      simData.rt{counter}.histX = vertcat(rt(iSes).histX);
      simData.rt{counter}.histY = vertcat(rt(iSes).histY);
      simData.rt{counter}.kernelX = vertcat(rt(iSes).kernelX);
      simData.rt{counter}.kernelY = vertcat(rt(iSes).kernelY);
      
      trajectory = vertcat(stats.trajectory);
      
      simData.trajectory{counter}.mean = vertcat(trajectory(iSes,:));
      
      
      binnedTrajectories = nan(nSesToSave,size(stats(1).binnedTrajectories,1),size(stats(1).binnedTrajectories,2));
      for j = 1:nSesToSave
         binnedTrajectories(j,:,:) = stats(iSes(j)).binnedTrajectories;
      end
      
      simData.binnedTrajectories{counter}.mean = squeeze(nanmean(binnedTrajectories,1));
      
      
      threshold = vertcat(stats.threshold);

      simData.threshold{counter}.mean = vertcat(threshold(iSes).mean);
      simData.threshold{counter}.median = vertcat(threshold(iSes).median);
      simData.threshold{counter}.std = vertcat(threshold(iSes).std);
      simData.threshold{counter}.cov = vertcat(threshold(iSes).cov);
      simData.threshold{counter}.iqr = vertcat(threshold(iSes).iqr);
      simData.threshold{counter}.range = vertcat(threshold(iSes).range);
      simData.threshold{counter}.skewness = vertcat(threshold(iSes).skewness);
      simData.threshold{counter}.kurtosis = vertcat(threshold(iSes).kurtosis);
      simData.threshold{counter}.edfX = vertcat(threshold(iSes).edfX);
      simData.threshold{counter}.edfY = vertcat(threshold(iSes).edfY);
      simData.threshold{counter}.quantileX = vertcat(threshold(iSes).quantileX);
      simData.threshold{counter}.quantileY = vertcat(threshold(iSes).quantileY);
      simData.threshold{counter}.histX = vertcat(threshold(iSes).histX);
      simData.threshold{counter}.histY = vertcat(threshold(iSes).histY);
      simData.threshold{counter}.kernelX = vertcat(threshold(iSes).kernelX);
      simData.threshold{counter}.kernelY = vertcat(threshold(iSes).kernelY);
      
      rate = vertcat(stats.rate);

      simData.rate{counter}.mean = vertcat(rate(iSes).mean);
      simData.rate{counter}.median = vertcat(rate(iSes).median);
      simData.rate{counter}.std = vertcat(rate(iSes).std);
      simData.rate{counter}.cov = vertcat(rate(iSes).cov);
      simData.rate{counter}.iqr = vertcat(rate(iSes).iqr);
      simData.rate{counter}.range = vertcat(rate(iSes).range);
      simData.rate{counter}.skewness = vertcat(rate(iSes).skewness);
      simData.rate{counter}.kurtosis = vertcat(rate(iSes).kurtosis);
      simData.rate{counter}.edfX = vertcat(rate(iSes).edfX);
      simData.rate{counter}.edfY = vertcat(rate(iSes).edfY);
      simData.rate{counter}.quantileX = vertcat(rate(iSes).quantileX);
      simData.rate{counter}.quantileY = vertcat(rate(iSes).quantileY);
      simData.rate{counter}.histX = vertcat(rate(iSes).histX);
      simData.rate{counter}.histY = vertcat(rate(iSes).histY);
      simData.rate{counter}.kernelX = vertcat(rate(iSes).kernelX);
      simData.rate{counter}.kernelY = vertcat(rate(iSes).kernelY);

      % Hanes & Schall (1996) binning
      simData.thresVsRtPoly1_H{counter} = vertcat(stats(iSes).thresVsRtPoly1_H);
      simData.rateVsRtPoly1_H{counter} = vertcat(stats(iSes).rateVsRtPoly1_H);
      simData.rateVsRtPower1_H{counter} = vertcat(stats(iSes).rateVsRtPower1_H);
      simData.rateVsRtRat01_H{counter} = vertcat(stats(iSes).rateVsRtRat01_H);
      
      % Woodman et al. (2008) binning
      simData.thresVsRtPoly1_W{counter} = vertcat(stats(iSes).thresVsRtPoly1_W);
      simData.rateVsRtPoly1_W{counter} = vertcat(stats(iSes).rateVsRtPoly1_W);
      simData.rateVsRtPower1_W{counter} = vertcat(stats(iSes).rateVsRtPower1_W);
      simData.rateVsRtRat01_W{counter} = vertcat(stats(iSes).rateVsRtRat01_W);
      
      simDataSingle = simData;

      % save it
      save(fullfile(settings.general.outputPath,['sim_',job.tag,'_',settings.general.fileTimestamp,'_SingleData.mat']),'simDataSingle','-v7.3');
            
   case 'multi'
      
      ciPercentiles = [(100-settings.statistics.ciType)/2 100-(100-settings.statistics.ciType)/2];
      
      %% Save multi session data
      simData.nSes(counter) = job.nSes;
      simData.nSim(counter) = job.nSim;
      simData.nA(counter) = job.nA;
      simData.nTP(counter) = job.nTP;
      simData.nAT(counter) = job.nAT;
      simData.mV(counter) = job.mV;
      simData.sdV(counter) = job.sdV;
      simData.rV(counter) = iRV;
      simData.dt(counter) = job.dt;
      simData.sigmaXi(counter) = job.sigmaXi;
      simData.rXi(counter) = job.rXi;
      simData.mTheta(counter) = job.mTheta;
      simData.sdTheta(counter) = job.sdTheta;
      simData.maxActivation(counter) = job.maxActivation;
      simData.affTime(counter) = job.affTime;
      simData.effTime(counter) = job.effTime;
      simData.pN(counter) = iPN;
      simData.dMeth(counter) = job.dMeth;
      simData.tag{counter} = job.tag;
      simData.rngID{counter} = job.rngID;
      simData.elapsedTime(counter) = toc(tStart);
      
      simData.nRecorded{counter}.mean = nanmean(vertcat(stats.nRecorded),1);
      simData.nRecorded{counter}.ci = prctile(vertcat(stats.nRecorded),ciPercentiles);
      
      % RT
      rt = vertcat(stats.rt);
      
      simData.rt{counter}.mean.mean = nanmean(vertcat(rt.mean),1);
      simData.rt{counter}.mean.ci = prctile(vertcat(rt.mean),ciPercentiles);
      simData.rt{counter}.mean.data = single(horzcat(rt.mean));
      simData.rt{counter}.median.mean = nanmean(vertcat(rt.median),1);
      simData.rt{counter}.median.ci = prctile(vertcat(rt.median),ciPercentiles);
      simData.rt{counter}.median.data = single(horzcat(rt.median));
      simData.rt{counter}.std.mean = nanmean(vertcat(rt.std),1);
      simData.rt{counter}.std.ci = prctile(vertcat(rt.std),ciPercentiles);
      simData.rt{counter}.cov.mean = nanmean(vertcat(rt.cov),1);
      simData.rt{counter}.cov.ci = prctile(vertcat(rt.cov),ciPercentiles);
      simData.rt{counter}.cov.data = single(horzcat(rt.cov));
      simData.rt{counter}.iqr.mean = nanmean(vertcat(rt.iqr),1);
      simData.rt{counter}.iqr.ci = prctile(vertcat(rt.iqr),ciPercentiles);
      simData.rt{counter}.iqr.data = single(horzcat(rt.iqr));
      simData.rt{counter}.range.mean = nanmean(vertcat(rt.range),1);
      simData.rt{counter}.range.ci = prctile(vertcat(rt.range),ciPercentiles);
      simData.rt{counter}.skewness.mean = nanmean(vertcat(rt.skewness),1);
      simData.rt{counter}.skewness.ci = prctile(vertcat(rt.skewness),ciPercentiles);
      simData.rt{counter}.kurtosis.mean = nanmean(vertcat(rt.kurtosis),1);
      simData.rt{counter}.kurtosis.ci = prctile(vertcat(rt.kurtosis),ciPercentiles);
      simData.rt{counter}.edfX.mean = nanmean(vertcat(rt.edfX),1);
      simData.rt{counter}.edfX.ci = prctile(vertcat(rt.edfX),ciPercentiles);
      simData.rt{counter}.edfY.mean = nanmean(vertcat(rt.edfY),1);
      simData.rt{counter}.edfY.ci = prctile(vertcat(rt.edfY),ciPercentiles);
      simData.rt{counter}.quantileX.mean = nanmean(vertcat(rt.quantileX),1);
      simData.rt{counter}.quantileX.ci = prctile(vertcat(rt.quantileX),ciPercentiles);
      simData.rt{counter}.quantileY.mean = nanmean(vertcat(rt.quantileY),1);
      simData.rt{counter}.quantileY.ci = prctile(vertcat(rt.quantileY),ciPercentiles);
      simData.rt{counter}.histX.mean = nanmean(vertcat(rt.histX),1);
      simData.rt{counter}.histX.ci = prctile(vertcat(rt.histX),ciPercentiles);
      simData.rt{counter}.histY.mean = nanmean(vertcat(rt.histY),1);
      simData.rt{counter}.histY.ci = prctile(vertcat(rt.histY),ciPercentiles);
      simData.rt{counter}.kernelX.mean = nanmean(vertcat(rt.kernelX),1);
      simData.rt{counter}.kernelX.ci = prctile(vertcat(rt.kernelX),ciPercentiles);
      simData.rt{counter}.kernelY.mean = nanmean(vertcat(rt.kernelY),1);
      simData.rt{counter}.kernelY.ci = prctile(vertcat(rt.kernelY),ciPercentiles);
      
      trajectory = vertcat(stats.trajectory);

      simData.trajectory{counter}.mean = nanmean(vertcat(trajectory),1);

            
      binnedTrajectories = nan(job.nSes,size(stats(1).binnedTrajectories,1),size(stats(1).binnedTrajectories,2));
      for j = 1:job.nSes
         binnedTrajectories(j,:,:) = stats(j).binnedTrajectories;
      end
      simData.binnedTrajectories{counter}.mean = squeeze(nanmean(binnedTrajectories,1));
      
      
      threshold = vertcat(stats.threshold);

      simData.threshold{counter}.mean.mean = nanmean(vertcat(threshold.mean),1);
      simData.threshold{counter}.mean.ci = prctile(vertcat(threshold.mean),ciPercentiles);
      simData.threshold{counter}.mean.data = single(horzcat(threshold.mean));
      simData.threshold{counter}.median.mean = nanmean(vertcat(threshold.median),1);
      simData.threshold{counter}.median.ci = prctile(vertcat(threshold.median),ciPercentiles);
      simData.threshold{counter}.median.data = single(horzcat(threshold.median));
      simData.threshold{counter}.std.mean = nanmean(vertcat(threshold.std),1);
      simData.threshold{counter}.std.ci = prctile(vertcat(threshold.std),ciPercentiles);
      simData.threshold{counter}.cov.mean = nanmean(vertcat(threshold.cov),1);
      simData.threshold{counter}.cov.ci = prctile(vertcat(threshold.cov),ciPercentiles);
      simData.threshold{counter}.cov.data = single(horzcat(threshold.cov));
      simData.threshold{counter}.iqr.mean = nanmean(vertcat(threshold.iqr),1);
      simData.threshold{counter}.iqr.ci = prctile(vertcat(threshold.iqr),ciPercentiles);
      simData.threshold{counter}.iqr.data = single(horzcat(threshold.iqr));
      simData.threshold{counter}.range.mean = nanmean(vertcat(threshold.range),1);
      simData.threshold{counter}.range.ci = prctile(vertcat(threshold.range),ciPercentiles);
      simData.threshold{counter}.skewness.mean = nanmean(vertcat(threshold.skewness),1);
      simData.threshold{counter}.skewness.ci = prctile(vertcat(threshold.skewness),ciPercentiles);
      simData.threshold{counter}.kurtosis.mean = nanmean(vertcat(threshold.kurtosis),1);
      simData.threshold{counter}.kurtosis.ci = prctile(vertcat(threshold.kurtosis),ciPercentiles);
      simData.threshold{counter}.edfX.mean = nanmean(vertcat(threshold.edfX),1);
      simData.threshold{counter}.edfX.ci = prctile(vertcat(threshold.edfX),ciPercentiles);
      simData.threshold{counter}.edfY.mean = nanmean(vertcat(threshold.edfY),1);
      simData.threshold{counter}.edfY.ci = prctile(vertcat(threshold.edfY),ciPercentiles);
      simData.threshold{counter}.quantileX.mean = nanmean(vertcat(threshold.quantileX),1);
      simData.threshold{counter}.quantileX.ci = prctile(vertcat(threshold.quantileX),ciPercentiles);
      simData.threshold{counter}.quantileY.mean = nanmean(vertcat(threshold.quantileY),1);
      simData.threshold{counter}.quantileY.ci = prctile(vertcat(threshold.quantileY),ciPercentiles);
      simData.threshold{counter}.histX.mean = nanmean(vertcat(threshold.histX),1);
      simData.threshold{counter}.histX.ci = prctile(vertcat(threshold.histX),ciPercentiles);
      simData.threshold{counter}.histY.mean = nanmean(vertcat(threshold.histY),1);
      simData.threshold{counter}.histY.ci = prctile(vertcat(threshold.histY),ciPercentiles);
      simData.threshold{counter}.kernelX.mean = nanmean(vertcat(threshold.kernelX),1);
      simData.threshold{counter}.kernelX.ci = prctile(vertcat(threshold.kernelX),ciPercentiles);
      simData.threshold{counter}.kernelY.mean = nanmean(vertcat(threshold.kernelY),1);
      simData.threshold{counter}.kernelY.ci = prctile(vertcat(threshold.kernelY),ciPercentiles);

      rate = vertcat(stats.rate);

      simData.rate{counter}.mean.mean = nanmean(vertcat(rate.mean),1);
      simData.rate{counter}.mean.ci = prctile(vertcat(rate.mean),ciPercentiles);
      simData.rate{counter}.mean.data = single(horzcat(rate.mean));
      simData.rate{counter}.median.mean = nanmean(vertcat(rate.median),1);
      simData.rate{counter}.median.ci = prctile(vertcat(rate.median),ciPercentiles);
      simData.rate{counter}.median.data = single(horzcat(rate.median));
      simData.rate{counter}.std.mean = nanmean(vertcat(rate.std),1);
      simData.rate{counter}.std.ci = prctile(vertcat(rate.std),ciPercentiles);
      simData.rate{counter}.cov.mean = nanmean(vertcat(rate.cov),1);
      simData.rate{counter}.cov.ci = prctile(vertcat(rate.cov),ciPercentiles);
      simData.rate{counter}.cov.data = single(horzcat(rate.cov));
      simData.rate{counter}.iqr.mean = nanmean(vertcat(rate.iqr),1);
      simData.rate{counter}.iqr.ci = prctile(vertcat(rate.iqr),ciPercentiles);
      simData.rate{counter}.iqr.data = single(horzcat(rate.iqr));
      simData.rate{counter}.range.mean = nanmean(vertcat(rate.range),1);
      simData.rate{counter}.range.ci = prctile(vertcat(rate.range),ciPercentiles);
      simData.rate{counter}.skewness.mean = nanmean(vertcat(rate.skewness),1);
      simData.rate{counter}.skewness.ci = prctile(vertcat(rate.skewness),ciPercentiles);
      simData.rate{counter}.kurtosis.mean = nanmean(vertcat(rate.kurtosis),1);
      simData.rate{counter}.kurtosis.ci = prctile(vertcat(rate.kurtosis),ciPercentiles);
      simData.rate{counter}.edfX.mean = nanmean(vertcat(rate.edfX),1);
      simData.rate{counter}.edfX.ci = prctile(vertcat(rate.edfX),ciPercentiles);
      simData.rate{counter}.edfY.mean = nanmean(vertcat(rate.edfY),1);
      simData.rate{counter}.edfY.ci = prctile(vertcat(rate.edfY),ciPercentiles);
      simData.rate{counter}.quantileX.mean = nanmean(vertcat(rate.quantileX),1);
      simData.rate{counter}.quantileX.ci = prctile(vertcat(rate.quantileX),ciPercentiles);
      simData.rate{counter}.quantileY.mean = nanmean(vertcat(rate.quantileY),1);
      simData.rate{counter}.quantileY.ci = prctile(vertcat(rate.quantileY),ciPercentiles);
      simData.rate{counter}.histX.mean = nanmean(vertcat(rate.histX),1);
      simData.rate{counter}.histX.ci = prctile(vertcat(rate.histX),ciPercentiles);
      simData.rate{counter}.histY.mean = nanmean(vertcat(rate.histY),1);
      simData.rate{counter}.histY.ci = prctile(vertcat(rate.histY),ciPercentiles);
      simData.rate{counter}.kernelX.mean = nanmean(vertcat(rate.kernelX),1);
      simData.rate{counter}.kernelX.ci = prctile(vertcat(rate.kernelX),ciPercentiles);
      simData.rate{counter}.kernelY.mean = nanmean(vertcat(rate.kernelY),1);
      simData.rate{counter}.kernelY.ci = prctile(vertcat(rate.kernelY),ciPercentiles);
      
      thresVsRtPoly1 = vertcat(stats.thresVsRtPoly1_H);
      
      simData.thresVsRtPoly1_H{counter}.dataX.mean = nanmean(vertcat(thresVsRtPoly1.dataX),1);
      simData.thresVsRtPoly1_H{counter}.dataX.ci = prctile(vertcat(thresVsRtPoly1.dataX),ciPercentiles);
      simData.thresVsRtPoly1_H{counter}.dataY.mean = nanmean(vertcat(thresVsRtPoly1.dataY),1);
      simData.thresVsRtPoly1_H{counter}.dataY.ci = prctile(vertcat(thresVsRtPoly1.dataY),ciPercentiles);
      simData.thresVsRtPoly1_H{counter}.params.mean = nanmean(vertcat(thresVsRtPoly1.params),1);
      simData.thresVsRtPoly1_H{counter}.params.ci = prctile(vertcat(thresVsRtPoly1.params),ciPercentiles);
      simData.thresVsRtPoly1_H{counter}.params.sign = ci_sign(prctile(vertcat(thresVsRtPoly1.params),ciPercentiles));
      simData.thresVsRtPoly1_H{counter}.params.data = vertcat(thresVsRtPoly1.params);
      simData.thresVsRtPoly1_H{counter}.paramsSign.data = vertcat(thresVsRtPoly1.paramsSign);
      simData.thresVsRtPoly1_H{counter}.rmse.mean = nanmean(vertcat(thresVsRtPoly1.rmse),1);
      simData.thresVsRtPoly1_H{counter}.rmse.ci = prctile(vertcat(thresVsRtPoly1.rmse),ciPercentiles);
      simData.thresVsRtPoly1_H{counter}.rmseCoV.mean = nanmean(vertcat(thresVsRtPoly1.rmseCoV),1);
      simData.thresVsRtPoly1_H{counter}.rmseCoV.ci = prctile(vertcat(thresVsRtPoly1.rmseCoV),ciPercentiles);
      simData.thresVsRtPoly1_H{counter}.rSquare.mean = tanh(nanmean(atanh(vertcat(thresVsRtPoly1.rSquare)),1)); % N.B. Note Fisher z-transformation before averaging
      simData.thresVsRtPoly1_H{counter}.rSquare.ci = tanh(prctile(atanh(vertcat(thresVsRtPoly1.rSquare)),ciPercentiles));
      simData.thresVsRtPoly1_H{counter}.fitSuccess.mean = nanmean(vertcat(thresVsRtPoly1.fitSuccess),1);
      
      clear thresVsRtPoly1
      
      
      thresVsRtPoly1 = vertcat(stats.thresVsRtPoly1_W);
      
      simData.thresVsRtPoly1_W{counter}.dataX.mean = nanmean(vertcat(thresVsRtPoly1.dataX),1);
      simData.thresVsRtPoly1_W{counter}.dataX.ci = prctile(vertcat(thresVsRtPoly1.dataX),ciPercentiles);
      simData.thresVsRtPoly1_W{counter}.dataY.mean = nanmean(vertcat(thresVsRtPoly1.dataY),1);
      simData.thresVsRtPoly1_W{counter}.dataY.ci = prctile(vertcat(thresVsRtPoly1.dataY),ciPercentiles);
      simData.thresVsRtPoly1_W{counter}.params.mean = nanmean(vertcat(thresVsRtPoly1.params),1);
      simData.thresVsRtPoly1_W{counter}.params.ci = prctile(vertcat(thresVsRtPoly1.params),ciPercentiles);
      simData.thresVsRtPoly1_W{counter}.params.sign = ci_sign(prctile(vertcat(thresVsRtPoly1.params),ciPercentiles));
      simData.thresVsRtPoly1_W{counter}.params.data = vertcat(thresVsRtPoly1.params);
      simData.thresVsRtPoly1_W{counter}.paramsSign.data = vertcat(thresVsRtPoly1.paramsSign);
      simData.thresVsRtPoly1_W{counter}.rmse.mean = nanmean(vertcat(thresVsRtPoly1.rmse),1);
      simData.thresVsRtPoly1_W{counter}.rmse.ci = prctile(vertcat(thresVsRtPoly1.rmse),ciPercentiles);
      simData.thresVsRtPoly1_W{counter}.rmseCoV.mean = nanmean(vertcat(thresVsRtPoly1.rmseCoV),1);
      simData.thresVsRtPoly1_W{counter}.rmseCoV.ci = prctile(vertcat(thresVsRtPoly1.rmseCoV),ciPercentiles);
      simData.thresVsRtPoly1_W{counter}.rSquare.mean = tanh(nanmean(atanh(vertcat(thresVsRtPoly1.rSquare)),1)); % N.B. Note Fisher z-transformation before averaging
      simData.thresVsRtPoly1_W{counter}.rSquare.ci = tanh(prctile(atanh(vertcat(thresVsRtPoly1.rSquare)),ciPercentiles));
      simData.thresVsRtPoly1_W{counter}.fitSuccess.mean = nanmean(vertcat(thresVsRtPoly1.fitSuccess),1);
      
      clear thresVsRtPoly1
      
      
      rateVsRtPoly1 = vertcat(stats.rateVsRtPoly1_H);
      
      simData.rateVsRtPoly1_H{counter}.dataX.mean = nanmean(vertcat(rateVsRtPoly1.dataX),1);
      simData.rateVsRtPoly1_H{counter}.dataX.ci = prctile(vertcat(rateVsRtPoly1.dataX),ciPercentiles);
      simData.rateVsRtPoly1_H{counter}.dataY.mean = nanmean(vertcat(rateVsRtPoly1.dataY),1);
      simData.rateVsRtPoly1_H{counter}.dataY.ci = prctile(vertcat(rateVsRtPoly1.dataY),ciPercentiles);
      simData.rateVsRtPoly1_H{counter}.params.mean = nanmean(vertcat(rateVsRtPoly1.params),1);
      simData.rateVsRtPoly1_H{counter}.params.ci = prctile(vertcat(rateVsRtPoly1.params),ciPercentiles);
      simData.rateVsRtPoly1_H{counter}.params.sign = ci_sign(prctile(vertcat(rateVsRtPoly1.params),ciPercentiles));
      simData.rateVsRtPoly1_H{counter}.params.data = vertcat(rateVsRtPoly1.params);
      simData.rateVsRtPoly1_H{counter}.paramsSign.data = vertcat(rateVsRtPoly1.paramsSign);
      simData.rateVsRtPoly1_H{counter}.rmse.mean = nanmean(vertcat(rateVsRtPoly1.rmse),1);
      simData.rateVsRtPoly1_H{counter}.rmse.ci = prctile(vertcat(rateVsRtPoly1.rmse),ciPercentiles);
      simData.rateVsRtPoly1_H{counter}.rmseCoV.mean = nanmean(vertcat(rateVsRtPoly1.rmseCoV),1);
      simData.rateVsRtPoly1_H{counter}.rmseCoV.ci = prctile(vertcat(rateVsRtPoly1.rmseCoV),ciPercentiles);
      simData.rateVsRtPoly1_H{counter}.rSquare.mean = tanh(nanmean(atanh(vertcat(rateVsRtPoly1.rSquare)),1)); % N.B. Note Fisher z-transformation before averaging
      simData.rateVsRtPoly1_H{counter}.rSquare.ci = tanh(prctile(atanh(vertcat(rateVsRtPoly1.rSquare)),ciPercentiles));
      simData.rateVsRtPoly1_H{counter}.fitSuccess.mean = nanmean(vertcat(rateVsRtPoly1.fitSuccess),1);
      
      clear rateVsRtPoly1
      
      rateVsRtPoly1 = vertcat(stats.rateVsRtPoly1_W);
      
      simData.rateVsRtPoly1_W{counter}.dataX.mean = nanmean(vertcat(rateVsRtPoly1.dataX),1);
      simData.rateVsRtPoly1_W{counter}.dataX.ci = prctile(vertcat(rateVsRtPoly1.dataX),ciPercentiles);
      simData.rateVsRtPoly1_W{counter}.dataY.mean = nanmean(vertcat(rateVsRtPoly1.dataY),1);
      simData.rateVsRtPoly1_W{counter}.dataY.ci = prctile(vertcat(rateVsRtPoly1.dataY),ciPercentiles);
      simData.rateVsRtPoly1_W{counter}.params.mean = nanmean(vertcat(rateVsRtPoly1.params),1);
      simData.rateVsRtPoly1_W{counter}.params.ci = prctile(vertcat(rateVsRtPoly1.params),ciPercentiles);
      simData.rateVsRtPoly1_W{counter}.params.sign = ci_sign(prctile(vertcat(rateVsRtPoly1.params),ciPercentiles));
      simData.rateVsRtPoly1_W{counter}.params.data = vertcat(rateVsRtPoly1.params);
      simData.rateVsRtPoly1_W{counter}.paramsSign.data = vertcat(rateVsRtPoly1.paramsSign);
      simData.rateVsRtPoly1_W{counter}.rmse.mean = nanmean(vertcat(rateVsRtPoly1.rmse),1);
      simData.rateVsRtPoly1_W{counter}.rmse.ci = prctile(vertcat(rateVsRtPoly1.rmse),ciPercentiles);
      simData.rateVsRtPoly1_W{counter}.rmseCoV.mean = nanmean(vertcat(rateVsRtPoly1.rmseCoV),1);
      simData.rateVsRtPoly1_W{counter}.rmseCoV.ci = prctile(vertcat(rateVsRtPoly1.rmseCoV),ciPercentiles);
      simData.rateVsRtPoly1_W{counter}.rSquare.mean = tanh(nanmean(atanh(vertcat(rateVsRtPoly1.rSquare)),1)); % N.B. Note Fisher z-transformation before averaging
      simData.rateVsRtPoly1_W{counter}.rSquare.ci = tanh(prctile(atanh(vertcat(rateVsRtPoly1.rSquare)),ciPercentiles));
      simData.rateVsRtPoly1_W{counter}.fitSuccess.mean = nanmean(vertcat(rateVsRtPoly1.fitSuccess),1);
      
      clear rateVsRtPoly1
      
      rateVsRtPower1 = vertcat(stats.rateVsRtPower1_H);
      
      simData.rateVsRtPower1_H{counter}.dataX.mean = nanmean(vertcat(rateVsRtPower1.dataX),1);
      simData.rateVsRtPower1_H{counter}.dataX.ci = prctile(vertcat(rateVsRtPower1.dataX),ciPercentiles);
      simData.rateVsRtPower1_H{counter}.dataY.mean = nanmean(vertcat(rateVsRtPower1.dataY),1);
      simData.rateVsRtPower1_H{counter}.dataY.ci = prctile(vertcat(rateVsRtPower1.dataY),ciPercentiles);
      simData.rateVsRtPower1_H{counter}.params.mean = nanmean(vertcat(rateVsRtPower1.params),1);
      simData.rateVsRtPower1_H{counter}.params.ci = prctile(vertcat(rateVsRtPower1.params),ciPercentiles);
      simData.rateVsRtPower1_H{counter}.params.sign = ci_sign(prctile(vertcat(rateVsRtPower1.params),ciPercentiles));
      simData.rateVsRtPower1_H{counter}.params.data = vertcat(rateVsRtPower1.params);
      simData.rateVsRtPower1_H{counter}.paramsSign.data = vertcat(rateVsRtPower1.paramsSign);
      simData.rateVsRtPower1_H{counter}.rmse.mean = nanmean(vertcat(rateVsRtPower1.rmse),1);
      simData.rateVsRtPower1_H{counter}.rmse.ci = prctile(vertcat(rateVsRtPower1.rmse),ciPercentiles);
      simData.rateVsRtPower1_H{counter}.rmseCoV.mean = nanmean(vertcat(rateVsRtPower1.rmseCoV),1);
      simData.rateVsRtPower1_H{counter}.rmseCoV.ci = prctile(vertcat(rateVsRtPower1.rmseCoV),ciPercentiles);
      simData.rateVsRtPower1_H{counter}.rSquare.mean = tanh(nanmean(atanh(vertcat(rateVsRtPower1.rSquare)),1)); % N.B. Note Fisher z-transformation before averaging
      simData.rateVsRtPower1_H{counter}.rSquare.ci = tanh(prctile(atanh(vertcat(rateVsRtPower1.rSquare)),ciPercentiles));
      simData.rateVsRtPower1_H{counter}.fitSuccess.mean = nanmean(vertcat(rateVsRtPower1.fitSuccess),1);
      
      clear rateVsRtPower1
      
      
      rateVsRtPower1 = vertcat(stats.rateVsRtPower1_W);
      
      simData.rateVsRtPower1_W{counter}.dataX.mean = nanmean(vertcat(rateVsRtPower1.dataX),1);
      simData.rateVsRtPower1_W{counter}.dataX.ci = prctile(vertcat(rateVsRtPower1.dataX),ciPercentiles);
      simData.rateVsRtPower1_W{counter}.dataY.mean = nanmean(vertcat(rateVsRtPower1.dataY),1);
      simData.rateVsRtPower1_W{counter}.dataY.ci = prctile(vertcat(rateVsRtPower1.dataY),ciPercentiles);
      simData.rateVsRtPower1_W{counter}.params.mean = nanmean(vertcat(rateVsRtPower1.params),1);
      simData.rateVsRtPower1_W{counter}.params.ci = prctile(vertcat(rateVsRtPower1.params),ciPercentiles);
      simData.rateVsRtPower1_W{counter}.params.sign = ci_sign(prctile(vertcat(rateVsRtPower1.params),ciPercentiles));
      simData.rateVsRtPower1_W{counter}.params.data = vertcat(rateVsRtPower1.params);
      simData.rateVsRtPower1_W{counter}.paramsSign.data = vertcat(rateVsRtPower1.paramsSign);
      simData.rateVsRtPower1_W{counter}.rmse.mean = nanmean(vertcat(rateVsRtPower1.rmse),1);
      simData.rateVsRtPower1_W{counter}.rmse.ci = prctile(vertcat(rateVsRtPower1.rmse),ciPercentiles);
      simData.rateVsRtPower1_W{counter}.rmseCoV.mean = nanmean(vertcat(rateVsRtPower1.rmseCoV),1);
      simData.rateVsRtPower1_W{counter}.rmseCoV.ci = prctile(vertcat(rateVsRtPower1.rmseCoV),ciPercentiles);
      simData.rateVsRtPower1_W{counter}.rSquare.mean = tanh(nanmean(atanh(vertcat(rateVsRtPower1.rSquare)),1)); % N.B. Note Fisher z-transformation before averaging
      simData.rateVsRtPower1_W{counter}.rSquare.ci = tanh(prctile(atanh(vertcat(rateVsRtPower1.rSquare)),ciPercentiles));
      simData.rateVsRtPower1_W{counter}.fitSuccess.mean = nanmean(vertcat(rateVsRtPower1.fitSuccess),1);
      
      clear rateVsRtPower1
      
      
      rateVsRtRat01 = vertcat(stats.rateVsRtRat01_H);
      
      simData.rateVsRtRat01_H{counter}.dataX.mean = nanmean(vertcat(rateVsRtRat01.dataX),1);
      simData.rateVsRtRat01_H{counter}.dataX.ci = prctile(vertcat(rateVsRtRat01.dataX),ciPercentiles);
      simData.rateVsRtRat01_H{counter}.dataY.mean = nanmean(vertcat(rateVsRtRat01.dataY),1);
      simData.rateVsRtRat01_H{counter}.dataY.ci = prctile(vertcat(rateVsRtRat01.dataY),ciPercentiles);
      simData.rateVsRtRat01_H{counter}.params.mean = nanmean(vertcat(rateVsRtRat01.params),1);
      simData.rateVsRtRat01_H{counter}.params.ci = prctile(vertcat(rateVsRtRat01.params),ciPercentiles);
      simData.rateVsRtRat01_H{counter}.params.sign = ci_sign(prctile(vertcat(rateVsRtRat01.params),ciPercentiles));
      simData.rateVsRtRat01_H{counter}.params.data = vertcat(rateVsRtRat01.params);
      simData.rateVsRtRat01_H{counter}.paramsSign.data = vertcat(rateVsRtRat01.paramsSign);
      simData.rateVsRtRat01_H{counter}.rmse.mean = nanmean(vertcat(rateVsRtRat01.rmse),1);
      simData.rateVsRtRat01_H{counter}.rmse.ci = prctile(vertcat(rateVsRtRat01.rmse),ciPercentiles);
      simData.rateVsRtRat01_H{counter}.rmseCoV.mean = nanmean(vertcat(rateVsRtRat01.rmseCoV),1);
      simData.rateVsRtRat01_H{counter}.rmseCoV.ci = prctile(vertcat(rateVsRtRat01.rmseCoV),ciPercentiles);
      simData.rateVsRtRat01_H{counter}.rSquare.mean = tanh(nanmean(atanh(vertcat(rateVsRtRat01.rSquare)),1)); % N.B. Note Fisher z-transformation before averaging
      simData.rateVsRtRat01_H{counter}.rSquare.ci = tanh(prctile(atanh(vertcat(rateVsRtRat01.rSquare)),ciPercentiles));
      simData.rateVsRtRat01_H{counter}.fitSuccess.mean = nanmean(vertcat(rateVsRtRat01.fitSuccess),1);
      
      clear rateVsRtRat01
      
      
      rateVsRtRat01 = vertcat(stats.rateVsRtRat01_W);
      
      simData.rateVsRtRat01_W{counter}.dataX.mean = nanmean(vertcat(rateVsRtRat01.dataX),1);
      simData.rateVsRtRat01_W{counter}.dataX.ci = prctile(vertcat(rateVsRtRat01.dataX),ciPercentiles);
      simData.rateVsRtRat01_W{counter}.dataY.mean = nanmean(vertcat(rateVsRtRat01.dataY),1);
      simData.rateVsRtRat01_W{counter}.dataY.ci = prctile(vertcat(rateVsRtRat01.dataY),ciPercentiles);
      simData.rateVsRtRat01_W{counter}.params.mean = nanmean(vertcat(rateVsRtRat01.params),1);
      simData.rateVsRtRat01_W{counter}.params.ci = prctile(vertcat(rateVsRtRat01.params),ciPercentiles);
      simData.rateVsRtRat01_W{counter}.params.sign = ci_sign(prctile(vertcat(rateVsRtRat01.params),ciPercentiles));
      simData.rateVsRtRat01_W{counter}.params.data = vertcat(rateVsRtRat01.params);
      simData.rateVsRtRat01_W{counter}.paramsSign.data = vertcat(rateVsRtRat01.paramsSign);
      simData.rateVsRtRat01_W{counter}.rmse.mean = nanmean(vertcat(rateVsRtRat01.rmse),1);
      simData.rateVsRtRat01_W{counter}.rmse.ci = prctile(vertcat(rateVsRtRat01.rmse),ciPercentiles);
      simData.rateVsRtRat01_W{counter}.rmseCoV.mean = nanmean(vertcat(rateVsRtRat01.rmseCoV),1);
      simData.rateVsRtRat01_W{counter}.rmseCoV.ci = prctile(vertcat(rateVsRtRat01.rmseCoV),ciPercentiles);
      simData.rateVsRtRat01_W{counter}.rSquare.mean = tanh(nanmean(atanh(vertcat(rateVsRtRat01.rSquare)),1)); % N.B. Note Fisher z-transformation before averaging
      simData.rateVsRtRat01_W{counter}.rSquare.ci = tanh(prctile(atanh(vertcat(rateVsRtRat01.rSquare)),ciPercentiles));
      simData.rateVsRtRat01_W{counter}.fitSuccess.mean = nanmean(vertcat(rateVsRtRat01.fitSuccess),1);
      
      clear rateVsRtRat01
      
      simDataMulti = simData;
      
      % save it
      save(fullfile(settings.general.outputPath,['sim_',job.tag,'_',settings.general.fileTimestamp,'_MultiData.mat']),'simDataMulti','-v7.3');
end

end


      
