function check_epu_sim_old_vs_new
%% CHECK_EPU_OLD_VS_NEW
% This function checks whether the old (deterministic) and new (stochastic)
% versions of the EPU model produce identical rates and similar RT
% distributions. Note that RT distributions of old and new versions cannot be
% identical, because of differences in threshold crossing determination: in the
% old model, threshold crossing time can be computed exactly (as threshold./rate
% + t0), whereas in the new model has a lower temporal resolution, checking
% whether threshold has been crossed every 1 ms.
%%

% Settings
nS = 500;      % number of simulatios
nA = 10;       % number of accumulators
mR = 1;        % mean accumulation rate
sR = .75;      % s.d. accumulation rate
mT = 100;
sT = 0;
t0 = 100;      % non-decision time
r = .8;        % accumulation rate correlation
q = .2;        % mean accumulation rate
nTP = 1500;    % Number of data (time) points to record
nAT = 10;      % Number of accumulation trajectories to record
aLim = 1e4;    % Absolute maximum firing rate

wnF = 0;
dMeth = 1;     % Method of determining RT: polling

s = rng('shuffle'); % Random number generator

rng(s);
[rtO,activationO,rateO,iATO] = ... 
epu_sim_old('activation',nS,nA,mR,sR,mT,sT,t0,r,q,nTP,nAT,aLim);

rtO = sort(rtO);
FO = mtb_edf(rtO,rtO);

rng(s)
[rtN,activationN,rateN,iATN] = ... 
epu_sim(nS,nA,mR,sR,wnF,mT,sT,t0,r,q,nTP,nAT,aLim,dMeth);

rtN = sort(rtN);
FN = mtb_edf(rtN,rtN);

% Check
figure;
plot(rtO,FO,'r-'); hold on;
plot(rtN,FN,'b-');

quantile(rtO,[.1 .3 .5 .7 .9])
quantile(rtN,[.1 .3 .5 .7 .9])

% Identical rates:
if isequal(rateO,rateN)
   disp('Rates of epu_sim_old.m and epu_sim.m are identical');
else
   error('Rates of epu_sim_old.m and epu_sim.m are NOT identical');
end


