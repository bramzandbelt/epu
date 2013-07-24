function [rt,activation,v,theta,iAT,elapsedTime] = ...
epu_sim(nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation, ...
affTime,effTime,pN,dMeth)
%EPU_SIM Simulation function of E Pluribus Unum modeling project
% µ
% INPUTS
% nSim          - number of simulations
% nA            - number of redundant accumulators
% nTP           - number of time points (TP) for which to log data (in ms from
%                 target onset)
% nAT           - number of activation trajectories (AT) to provide (i.e. the
%                 number of accumulators for which ATs are outputted)
% mV            - mean of the lognormal accumulation rate distribution
%                 * units:          spikes s-1 ms-1
%                 * size & class:   1x1 double
%                 * support:        mV ? ?: (0,+?)
% sdV           - s.d. of the lognormal accumulation rate distribution
%                 * units:          spikes s-1 ms-1
%                 * size & class:   1x1 double
%                 * support:        sdV ? ?: (0,+?)
% rV            - correlation of accumulation rates between accumulators
%                 * units:          unitless
%                 * size & class:   1x1 double
%                 * support:        rV ? ?: [0,1]
% dt            - time step size of stochastic differential equation
%                 * units:          ms
%                 * size & class:   1x1 double
%                 * support:        dt ? ?: [0,+?)
% sigmaXi       - scale parameter of the Gaussian noise distribution
%                 * units:          spikes s-1
%                 * size & class:   1x1 double
%                 * support:        sigmaXi ? ?: (0,+?)
% rXi           - correlation of the Gaussian noise
%                 * units:          unitless
%                 * size & class:   1x1 double
%                 * support:        rXi ? ?: [0,1]
% mTheta        - mean of the Gaussian threshold distribution
%                 * units:          spikes s-1
%                 * size & class:   1x1 double
%                 * support:        mTheta ? ?: (-?,+?)
% sdTheta       - s.d. of the Gaussian threshold distribution
%                 * units:          spikes s-1
%                 * size & class:   1x1 double
%                 * support:        sdTheta ? ?: (0,+?)
% maxActivation - maximum activation level an accumulator can reach
%                 * units:          unitless or spikes s-1
%                 * size & class:   1x1 double
%                 * support:        maxActivation ? ?: (0,+?)
%                                   * (0,1]  considered fraction of mTheta
%                                   * [1,+?) considered absolute activ. level
% affTime       - afferent (encoding) time
%                 * units:          ms
%                 * size & class:   1x1 double
%                 * support:        affTime ? ?: [0,+?)
% effTime       - efferent (response execution) time
%                 * units:          ms
%                 * size & class:   1x1 double
%                 * support:        effTime ? ?: [0,+?)
% pN            - proportion of accumulators necessary to produce an RT ('RT
%                 rule').
%                 * units:          unitless
%                 * size & class:   1x1 double
%                 * support:        pN ? ?: [0,1], where 0 means that the very
%                 first accumulator reaching threshold produces RT
% dMeth         - decision method, polling or pooling
%                 * units:          unitless
%                 * size & class:   1x1 double
%                 * support:        * 1   polling
%                                   * 2   pooling
%
% EXAMPLE USAGE
% [rt,activation,v,theta,iAT,elapsedTime] = ...
% epu_sim(nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation,...
% affTime,effTime,pN,dMeth)
% __________________________________________    
% May 2012, bram.zandbelt@vanderbilt.edu

%% 1. PARAMETERS
tStartFunction = tic;

%% 2. ARRAYS FOR LOGGING DATA
rt = single(nan(nSim,1)); % Response time

%% 3. SIMULATION

% accumulation rates are sampled from a multivariate lognormal distribution. A
% log normal distribution is chosen, because the Linear Ballistic
% Accumulator model assumes positive accumulation rates. The accumulation rates are
% correlated between accumulators. Then, for each trial the activation
% trajectory for all accumulators and response time is computed.

%%
% *3.1 Sample trigger threshols from a truncated Gaussian distribution*
%
% A vector |theta| is generated, containing a trigger threshold for each
% accumulator. Trigger thresholds are sampled from a normal distribution with
% mean |mTheta| and standard deviation |sdTheta|.

a = 0;
b = Inf;

phiL = normcdf((a-mTheta)/sdTheta);
phiR = normcdf((b-mTheta)/sdTheta);

theta = mTheta + sdTheta*(sqrt(2)*erfinv(2*(phiL+(phiR-phiL)*rand(1,nA))-1));

% theta = (randn(1,nA)*sdTheta) + mTheta; % Non-truncated Gaussian distribution

%% 
% *3.2 Set up correlation matrix |rhoV| of accumulation rates between accumulators*
rhoV = rV.*ones(nA);
rhoV(linspace(1,numel(rhoV),length(rhoV))) = 1;

%% 
% *3.3 Calculate location parameter |muV| and scale parameter |sigmaV| of lognormal accumulation rate distribution from |mV| and |sdV|*
muV = log(mV^2 / sqrt(sdV^2+mV^2));
sigmaV = sqrt(log(sdV^2/mV^2 + 1));     
muVvec = kron(ones(nA,1),muV);
sigmaVvec = kron(ones(nA,1),sigmaV);

% *3.4 Sample accumulation rates with correlation from multivariant lognormal random distribution*
% Sample rates for all accumulators and all trials at once
% TO CONSIDER: Truncated multivariate normal distribution
v = MvLogNRand(muVvec,sigmaVvec,nSim,rhoV);

% Randomly select |nAT| accumulator from the set of |nA| accumulators
iAT = randperm(nA,nAT);
iAT = sort(iAT);

% Compute the maximum activation level that each accumulator can reach
if maxActivation <= 1
   maxActivationVec = theta./maxActivation;
else
   maxActivationVec = maxActivation.*ones(1,nA);
end
   
% Simulate RTs and activation trajectories

% Deteremine deterministic vs. stochastic
if sigmaXi == 0 && isinf(maxActivation) % Deterministic & Perfect - LBA
   
   activationCell = cell(nSim,nAT);
   
   parfor iSim = 1:nSim
      
      % *3.4 Sample accumulation rates with correlation from multivariant lognormal random distribution*
      % Sample rates for all accumulators and one trial
      % TO CONSIDER: Truncated multivariate normal distribution
      
      [thisRt,thisActivation] = epu_n_unit_lba_mex(v(iSim,:),theta,affTime,effTime,pN,dMeth,iAT);
      
      if isnan(thisRt)
         disp('bla');
      end
      
      rt(iSim) = thisRt;
      activationCell{iSim} = thisActivation';
      
   end
   
   maxLength = max(cellfun(@numel,activationCell(:)));
   activationTmp = cellfun(@(x) [x,nan(nAT,maxLength-size(x,2))],activationCell,'UniformOutput',0);
   if numel(iAT) == 1
      activation = single(cat(1,activationTmp{:}));
   else
      activation = nan(nSim,nAT,maxLength);
      parfor iSim = 1:nSim
         activation(iSim,:,:) = activationTmp{iSim};
      end
   end

elseif sigmaXi == 0 && ~isinf(maxActivation)
   
   activationCell = cell(nSim,nAT);
   
   parfor iSim = 1:nSim
      k = v(iSim,:)./maxActivationVec; % Leakage proprotional to rate, so activationLimit is fixed
      
      [thisRt,thisActivation] = epu_n_unit_ba_mex(v(iSim,:),theta,k,affTime,effTime,pN,dMeth,iAT);
      
      rt(iSim) = thisRt;
      activationCell{iSim} = thisActivation';

   end
   
   maxLength = max(cellfun(@numel,activationCell(:)));
   activationTmp = cellfun(@(x) [x,nan(nAT,maxLength-size(x,2))],activationCell,'UniformOutput',0);
   if numel(iAT) == 1
      activation = single(cat(1,activationTmp{:}));
   else
      activation = nan(nSim,nAT,maxLength);
      parfor iSim = 1:nSim
         activation(iSim,:,:) = activationTmp{iSim};
      end
   end
   
else % Stochastic and/or Leaky
   
   activation = single(nan(nSim,nAT,nTP)); % Activation
   
   % Cholesky-like decomposition for covariance matrix
   rhoXi = rXi.*ones(nA);
   rhoXi(linspace(1,numel(rhoXi),length(rhoXi))) = 1;
   SigmaXi = rhoXi.*sigmaXi; % Covariance matrix
   [SigmaXi,err] = cholcov(SigmaXi); % Cholesky-like decomposition
   if err ~= 0
      error(message('BadCovariance2DSymPos'));
   end
   
   parfor iSim = 1:nSim
   
      k = v(iSim,:)./maxActivationVec; % Leakage proprotional to rate, so activationLimit is fixed


      [thisRt,thisActivation] = ...
      epu_n_unit_accumulator_mex(nTP,v(iSim,:),dt,sigmaXi,SigmaXi,theta,k,affTime,effTime,pN,dMeth,iAT);

      rt(iSim) = thisRt;
      activation(iSim,:,:) = thisActivation';
   
   end
end

% Remove singleton dimensions, if any
activation = squeeze(activation);

% Discard rates of non-selected accumulators
v = v(:,iAT);

% Compute simulation time
elapsedTime = toc(tStartFunction);