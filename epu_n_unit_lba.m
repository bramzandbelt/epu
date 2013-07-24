function [rt,activation] = epu_n_unit_lba(v,theta,affTime,effTime,pN,dMeth,iAT);  %#codegen
%
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
% [rt,activation] = epu_n_unit_lba(v,theta,affTime,effTime,pN,dMeth,iAT);
%
%
% Bram Zandbelt, August 2012

rt = Inf;
accumulationTime = Inf;
% Number of accumulator units
nA = size(v,2);
nAT = numel(iAT);

if dMeth == 1 % Polling

   % Compute the growth time for each accumulator
   dtAccumulation = theta./v;

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
   
elseif dMeth == 2
   
   % Compute the growth time for each accumulator
   accumulationTime(1) = mean(theta)./mean(v);
   
end

rt(1) = affTime + accumulationTime + effTime;

% Compute activation trajectories
activation = [zeros(floor(affTime),nAT);repmat(colon(1,ceil(accumulationTime + effTime))',1,nAT).*repmat(v(iAT),ceil(accumulationTime + effTime),1)]; % Activation

% activation(floor(affTime)+1:end,:) = repmat(colon(1,ceil(accumulationTime + effTime))',1,nAT).*repmat(v(iAT),ceil(accumulationTime + effTime),1);