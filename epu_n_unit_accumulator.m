function [rt,activation] = epu_n_unit_accumulator(nTP,v,dt,sigmaXi,SigmaXi,theta,k,affTime,effTime,pN,dMeth,iAT) %#codegen
%% N-UNIT REDUNDANT ACCUMULATOR MODEL WITHOUT LATERAL INHIBITION
% INPUTS
% nTP           - number of time points (TP) for which to log data (in ms from
%                 target onset)
% v             - vector with accumulation rates across accumulators
%                 * units:          spikes s-1 ms-1
%                 * size & class:   1xnA double, where nA is number of
%                                   accumulators
%                 * support:        v ? ?: (0,+?)
% dt            - time step size of stochastic differential equation
%                 * units:          ms
%                 * size & class:   1x1 double
%                 * support:        dt ? ?: [0,+?)
% sigmaXi       - scale parameter of the Gaussian noise distribution
%                 * units:          spikes s-1
%                 * size & class:   1x1 double
%                 * support:        sigmaXi ? ?: (0,+?)
% SigmaXi       - Cholesky-like decomposed covariance matrix
%                 * units:          ?
%                 * size & class:   nAxnA double
%                 * support:        SigmaXi
% theta         - vector with thresholds across accumulators
%                 * units:          spikes s-1
%                 * size & class:   1xnA double, where nA is number of
%                                   accumulators
%                 * support:        theta ? ?: (0,+?)
% k             - vector with leakage parameters
%                 * units:          
%                 * size & class:   1xnA double, where nA is number of
%                                   accumulators
%                 * support:        k ? ?: (0,+?)
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
% iAT           - accumulators indices for which to provide accumulation
%                 trajectories
%                 * units:          unitless
%                 * size & class:   1xN double, where N is the number of indices
%                 to get and N <= nA, where nA is number of accumulators
%                 * support:        iAT ? ?: [1,nA]
%
%
% EXAMPLE USAGE:
% nTP = 1500;
% v = 1+randn(1,10);
% sigmaXi = .2;
% rXi = .5;
% theta = 100.*ones(1,10);
% k = zeros(1,10);
% affTime = 100;
% effTime = 10;
% pN = 0;
% dMeth = 1;
% iAT = [1,3,5];
%
% [rt,activation] = ...
% epu_n_unit_accumulator(nTP,v,sigmaXi,SigmaXi,theta,k,affTime,effTime,pN,dMeth,iAT);
%
%

%
% THESE EXAMPLES NEED TO BE UPDATED AND ADJUSTED!
%
%
%% Example 1: Perfect integration of evidence, polling-based RT generation, very
%% first accumulator reaching threshold determines RT
%
% muRate = 1+randn(1,10);
% wnF = 0;
% nTP = 1500;
% k = zeros(1,10);
% theta = 100 .* ones(1,10);
% t0 = 100;
% dMeth = 1;
% q = 0;
% iAT = [1 3 4];
%
% [rt,activation] = ...
% epu_n_unit_accumulator(muRate,wnF,nTP,k,theta,t0,dMeth,q,iAT);
%
%% Example 2: Leaky integration of evidence, polling-based RT generation, median
%% accumulator reaching threshold determines RT
%
% muRate = 1+randn(1,10);
% wnF = 1;
% nTP = 1500
% theta = 100 .* ones(1,10);
% k = 0.5.*muRate./theta;
% t0 = 100;
% dMeth = 1;
% q = 0.5;
% iAT = [1 3 4];
%
% [rt,activation] = ...
% epu_n_unit_accumulator(muRate,wnF,nTP,k,theta,t0,dMeth,q,iAT);
%
%% Example 3: Leaky integration of evidence, pooling-based RT generation
%
% muRate = 1+randn(1,10);
% wnF = 1;
% nTP = 1500;
% theta = 100 .* ones(1,10);
% k = 0.5.*muRate./theta;
% t0 = 100;
% dMeth = 2;
% q = 0.5;
% iAT = 10;
%
% [rt,activation] = ...
% epu_n_unit_accumulator(muRate,wnF,nTP,k,theta,t0,dMeth,q,iAT);
%
% Bram Zandbelt, April 2012
%%

%% 1. Parameter settings & array pre-allocation

% warning off

% Constants
TAU = 1; % Time scale (in ms), see Usher & McClelland 2001, p. 558

% User-defined parameters
nA = size(v,2); % Number of accumulator units

% Arrays for logging data
activation = [zeros(floor(affTime./dt),nA);nan(ceil((nTP-affTime)./dt),nA)]; % Activation
rt = Inf;

%% 2. Accumulator trajectories
% iTP = affTime+1; % Before affTime, activation is zero
iTP = floor(affTime./dt)+1; % Before affTime, activation is zero

if all(pN == 0)
   pN = realmin; % This ensures that very first accumulator determines RT
end

if dMeth == 1 % Polling

   while iTP < Inf
      
      % Generate correlated Gaussian noise
      Xi = randn(1,size(SigmaXi,1)) * SigmaXi + zeros(1,nA);
         
      % Compute activation level
      activation(iTP,:) = activation(iTP-1,:) + dt./TAU.*(v-k.*activation(iTP-1,:)) + sqrt(dt./TAU).*Xi;
      
      % Reset activation level if it goes below zero
      activation(iTP,(activation(iTP,:) < 0)) = 0;
      
      % Proportion of accumulators above threshold
      prop = sum(activation(iTP,:) > theta)/nA;
      
      if isinf(rt) && all(prop >= pN) % Determine RT if sufficient number of accumulators have reached threshold
         
         % Identify critical accumulator (i.e. crossed threshold most recently) and determine RT
         iCrossed = activation(iTP,:) - theta > 0;
         iCritical = find(activation(iTP,:) - theta == min(activation(iTP,iCrossed)-theta(iCrossed)));
         iCritical = iCritical(1); % This is because when r equals 1, all accumulators cross at the same time

         actAroundThres = activation(iTP-1:iTP,iCritical);
         tAroundThres = dt.*[iTP-1,iTP]';
         critThres = theta(iCritical);

         rt = interp1q(actAroundThres,tAroundThres,critThres) + effTime;
         
         rt = rt(1); % If interp1q returns vector rather than scalar
      end

      if iTP*dt > rt
            % Keep data from selected accumulators
            activation = activation(:,iAT);
            break
      end
         
      if iTP > floor(nTP./dt)-1 % If trial end (i.e. maximum number of time points) has been reached
         % Keep data from selected accumulators
         rt = nan;
         activation = activation(:,iAT);
         break
      end
      
      iTP = iTP + 1;
      
   end
elseif dMeth == 2 % Pooling
   mActivation = zeros(nTP,1);
   mThreshold = mean(theta);
   while iTP < Inf
      
      % Generate correlated Gaussian noise
      Xi = randn(1,size(SigmaXi,1)) * SigmaXi + zeros(1,nA);
         
      % Compute activation level
      activation(iTP,:) = activation(iTP-1,:) + dt./TAU.*(v-k.*activation(iTP-1,:)) + sqrt(dt./TAU).*Xi;
      
      % Reset activation level if it goes below zero
      activation(iTP,(activation(iTP,:) < 0)) = 0;
      
      % Compute mean activation level across all accumulators
      mActivation(iTP) = mean(activation(iTP,:)); 
      
      if isinf(rt) && all(mActivation(iTP) > mThreshold)
         
         actAroundThres = mActivation(iTP-1:iTP);
         tAroundThres = dt.*[iTP-1,iTP]';
         
         rt = interp1q(actAroundThres,tAroundThres,mThreshold) + effTime;
         
         rt = rt(1); % In case inetrp1q returns vector rather than scalar
      end
      
      if iTP*dt > rt
         activation = activation(:,iAT);
         break
%          activation = mActivation;
%          activation(iTP+1:end) = nan;
%          break
      end
         
      if iTP > floor(nTP./dt)-1
         % Keep data from selected accumulators
         rt = nan;
         activation = activation(:,iAT);
         break
%          rt = nan;
%          activation = mActivation;
%          break
      end
      
      iTP = iTP + 1;
      
   end
end

% Transform to 1-ms steps
t = dt:dt:nTP;
activation = interp1(t,activation,colon(1,nTP));





