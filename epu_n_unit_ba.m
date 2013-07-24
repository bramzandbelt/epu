function [rt,activation] = epu_n_unit_ba(v,theta,k,affTime,effTime,pN,dMeth,iAT)  %#codegen
% EPU redundant ballistic accumulator model
% INPUTS
% v             - vector with accumulation rates across accumulators
%                 * units:          spikes s-1 ms-1
%                 * size & class:   1xnA double, where nA is number of
%                                   accumulators
%                 * support:        v ? ?: (0,+?)
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
% USAGE
% [rt,activation] = epu_n_unit_ba(v,theta,k,affTime,effTime,pN,dMeth,iAT);
%
%
% Bram Zandbelt, October 2012

rt = Inf;
accumulationTime = Inf;


% Number of accumulator units
nA = size(v,2);
nAT = numel(iAT);
x0 = 0;              % Starting value of activation

activation = [zeros(floor(affTime),nAT);nan(1,nAT)]; % Activation

% Time to reach theta for each accumulator
dtAccumulation = log((theta - v./k)./(x0 - v./k))./-k;
% dtAccumulation = arrayfun(@log,(theta - v./k)./(x0 - v./k))./-k;

if dMeth == 1 % Polling

   if nA > 1
      % Per simulation, sort growth times in ascending order
      dtAccumulation = sort(dtAccumulation')';
   end

   if all(pN == 0)
      pN = realmin; % This ensures that very first accumulator determines RT
   end

   % Compute rt as the sum of afferent time, time for pN fraction of accumulators
   % to reach threshold and efferent time
   accumulationTime = dtAccumulation(:,ceil(pN*nA));
   accumulationTime = accumulationTime(1);
   
   % Compute RT
   rt(1) = affTime + accumulationTime + effTime;
   
   % Maximum time for trajectories
   tMax = ceil(rt);

   % Time vector
   t = 0:1:tMax;
   
   % Compute activation trajectories for all accumulators
   activation = [zeros(floor(affTime),nAT);repmat(v(iAT),tMax+1,1)./repmat(k(iAT),tMax+1,1) + (repmat(x0,tMax+1,nAT) - repmat(v(iAT),tMax+1,1)./repmat(k(iAT),tMax+1,1)).*exp(repmat(-k(iAT),tMax+1,1).*repmat(t',1,nAT))];
   
elseif dMeth == 2 % Pooling
   
   % Maximum time to reach theta across the population
   tMax = ceil(max(dtAccumulation));

   % Time vector
   t = 0:1:tMax+effTime;

   % Compute activation trajectories for all accumulators
   activation = repmat(v,tMax+effTime+1,1)./repmat(k,tMax+effTime+1,1) + (repmat(x0,tMax+effTime+1,nA) - repmat(v,tMax+effTime+1,1)./repmat(k,tMax+effTime+1,1)).*exp(repmat(-k,tMax+effTime+1,1).*repmat(t',1,nA));
   
   % Compute average activation trajectory across accumulators
   meanActivation = mean(activation,2);
   accumulationTime = interp1(meanActivation,t,mean(theta));
   
   % Compute RT 
   rt(1) = affTime + accumulationTime + effTime;
   
   % Compute activation trajectories for all accumulators, including affTime
   % time points
   activation = [zeros(floor(affTime),nA);activation];
   
   % Maximum time for trajectories
   tMax = ceil(rt);

   % Only use activation trajectories of iAT
   activation = activation(1:tMax,iAT);
   
end

