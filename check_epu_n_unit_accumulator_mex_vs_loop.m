function check_epu_n_unit_accumulator_mex_vs_loop
%% CHECK_EPU_OLD_VS_NEW
% This function checks whether epu_n_unit_accumulator_mex produces identical
% activation trajectories as epu_n_unit_accumulator.
%%

% Settings
s = rng('shuffle');

nS = 500;                     % number of simulations
nA = 10;                      % number of accumulators
mR = 1;                       % mean accumulation rate
sR = .75;                     % s.d. accumulation rate
wnF = 3;                      % white noise factor
mT = 100;                     % mean threshold
sT = 0;                       % s.d. threshold
t0 = 100;                     % non-decision time
r = .8;                       % accumulation rate correlation
q = .2;                       % fraction of accumulators needed to reach threshold
nAT = 1;
iAT = randperm(nA,nAT);
activationLimit = 1000;
nTP = 1500;
dMeth = 1;                    % decision method: 1, polling; 2, pooling

Theta= (randn(1,nA)*sT) + mT; % threshold

rX = r.*ones(nA);             % accumulation rate correlation matrix
rX(linspace(1,numel(rX),length(rX))) = 1;
muLognrnd = log(mR^2 / sqrt(sR^2+mR^2));
sigmaLognrnd = sqrt(log(sR^2/mR^2 + 1));     
muvecLognrnd = kron(ones(nA,1),muLognrnd);
sigmavecLognrnd = kron(ones(nA,1),sigmaLognrnd);
rate = MvLogNRand(muvecLognrnd,sigmavecLognrnd,nS,rX); % rate matrix

% epu_n_unit_accumulator
% Pre-allocate arrays
rt_standard = nan(nS,1);
activation_standard = nan(nS,nTP,nAT);

rng(s);
tic;
for iS = 1:nS
   whiteNoise = kron(ones(nTP,1),wnF.*rate(iS,:)).*randn(nTP,nA); % This is Gaussian noise, with s.d. equal wnF times rate (i.e. noise scales with rate, with factor wnF)
   k = rate(iS,:)./activationLimit; % Leakage is proprotional to rate, so that activationLimit is fixed
   [rt_standard(iS),activation_standard(iS,:,:)] = epu_n_unit_accumulator(rate(iS,:),whiteNoise,k,Theta,t0,dMeth,q,iAT);
end
standard_loop_time = toc

% Mex, standard loop
% Pre-allocate arrays
rt_mex = nan(nS,1);
activation_mex = nan(nS,nTP,nAT);

rng(s);
tic;
for iS = 1:nS
   whiteNoise = kron(ones(nTP,1),wnF.*rate(iS,:)).*randn(nTP,nA); % This is Gaussian noise, with s.d. equal wnF times rate (i.e. noise scales with rate, with factor wnF)
   k = rate(iS,:)./activationLimit; % Leakage is proprotional to rate, so that activationLimit is fixed
   [rt_mex(iS),activation_mex(iS,:,:)] = epu_n_unit_accumulator_mex(rate(iS,:),whiteNoise,k,Theta,t0,dMeth,q,iAT);
   
end
mex_standard_loop_time = toc


% Check

% Identical trajectories?
if isequal(activation_standard,activation_mex)
   disp('Trajectories ofepu_n_unit_accumulator and epu_n_unit_accumulator_mex are identical');
else
   disp('Trajectories ofepu_n_unit_accumulator and epu_n_unit_accumulator_mex are NOT identical. This can be due to NaNs');
end

rt_standard = sort(rt_standard);
F_standard = mtb_edf(rt_standard,rt_standard);
rt_mex = sort(rt_mex);
F_mex = mtb_edf(rt_mex,rt_mex);


% Inspect trajectories trial-by-trial
figure;
subplot(1,2,1)
plot(rt_standard,F_standard,'r-'); hold on;
plot(rt_mex,F_mex,'b-');
title('Response time CDFs')
legend('standard','mex')

quantile(F_standard,[.1 .3 .5 .7 .9])
quantile(F_mex,[.1 .3 .5 .7 .9])

for iS = 1:nS
   subplot(1,2,2)
   cla
   plot(squeeze(activation_standard(iS,:,1)),'r-'); hold on;
   plot(squeeze(activation_mex(iS,:,1)),'b-'); hold on;
   set(gca,'XLim',[0 500],'YLim',[0 120]);
   title(['accumulation trajectories of simulation ',num2str(iS)])
   legend('standard','mex')
   pause;
end
