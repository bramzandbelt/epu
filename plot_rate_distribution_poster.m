function plot_rate_distirbution_poster
figure;

p = panel();
p.pack(3,1);



% Settings
nSim = 10;
nA = 5;
nTP = 1500;
nAT = 5;
mV = 1;
sdV = 1;
rV = 0.5;
dt = 10;
sigmaXi = 0.5;
rXi = 0.1;
mTheta = 1000;
sdTheta = 0;
maxActivation = Inf;
affTime = 100;
effTime = 10;
pN = 0.5;
dMeth = 1;


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



rs = [.1 .5 .9];

p(1,1).pack('h',4);

for i = 1:3

   % *3.2 Set up correlation matrix |rhoV| of accumulation rates between accumulators*
   rhoV = rs(i).*ones(nA);
   rhoV(linspace(1,numel(rhoV),length(rhoV))) = 1;

   % *3.3 Calculate location parameter |muV| and scale parameter |sigmaV| of lognormal accumulation rate distribution from |mV| and |sdV|*
   muV = log(mV^2 / sqrt(sdV^2+mV^2));
   sigmaV = sqrt(log(sdV^2/mV^2 + 1));     
   muVvec = kron(ones(nA,1),muV);
   sigmaVvec = kron(ones(nA,1),sigmaV);

   % *3.4 Sample accumulation rates with correlation from multivariant lognormal random distribution*
   % Sample rates for all accumulators and all trials at once
   % TO CONSIDER: Truncated multivariate normal distribution
   v = MvLogNRand(muVvec,sigmaVvec,nSim,rhoV);

   %% TOP ROW
   
   p(1,1,i).select();
   imagesc(v,[0 3]);colormap(othercolor('Msolarcolors',64));
   axis('tight','ij');
   set(gca,'DataAspectRatio',[1 1 1]);
   axis off
   
end
p(1,1,4).select();
imagesc(v,[0 3]);colormap(othercolor('Msolarcolors',64));
colorbar('peer',gca);
axis off


% *3.2 Set up correlation matrix |rhoV| of accumulation rates between accumulators*
rhoV = rV.*ones(nA);
rhoV(linspace(1,numel(rhoV),length(rhoV))) = 1;

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

%% Plot accumulators
p(2,1).pack('h',4);
clr = [.8 .8 .8];

% Perfect deterministic
sigmaXi = 0;
maxActivation = Inf;
[rt,activation] = sim_accumulation(nSim,nA,nTP,nAT,v,dt,sigmaXi,theta,maxActivation,affTime,effTime,pN,dMeth,iAT);

p(2,1,1).select();
for i = 1:5
   plot(1:1500, activation(i,:),'Color',clr);hold on;
   plot(find(activation(i,:) > 100,1,'first'),100,'k.','Color',clr,'MarkerSize',20);
end

% Leaky deterministic
sigmaXi = 0;
maxActivation = 250;
[rt,activation] = sim_accumulation(nSim,nA,nTP,nAT,v,dt,sigmaXi,theta,maxActivation,affTime,effTime,pN,dMeth,iAT);

p(2,1,2).select();
for i = 1:5
   plot(1:1500, activation(i,:),'Color',clr);hold on;
   plot(find(activation(i,:) > 100,1,'first'),100,'k.','Color',clr,'MarkerSize',20);
end

% Perfect stochastic
sigmaXi = 0.5;
maxActivation = Inf;
[rt,activation] = sim_accumulation(nSim,nA,nTP,nAT,v,dt,sigmaXi,theta,maxActivation,affTime,effTime,pN,dMeth,iAT);

p(2,1,3).select();
for i = 1:5
   plot(1:1500, activation(i,:),'Color',clr);hold on;
   plot(find(activation(i,:) > 100,1,'first'),100,'k.','Color',clr,'MarkerSize',20);
end

% Leaky stochastic
sigmaXi = 0.5;
maxActivation = 250;
[rt,activation] = sim_accumulation(nSim,nA,nTP,nAT,v,dt,sigmaXi,theta,maxActivation,affTime,effTime,pN,dMeth,iAT);

p(2,1,4).select();
for i = 1:5
   plot(1:1500, activation(i,:),'Color',clr);hold on;
   plot(find(activation(i,:) > 100,1,'first'),100,'k.','Color',clr,'MarkerSize',20);
end








% 
% 
% x = .01:.01:5;
% 
% p = panel();
% p.pack(2,2)
% 
% % Plot a lognormal distribution (this should becom a multivariate lognormal
% % distribution!)
% p(1,1).select();
% plot(x,lognpdf(x,muV,sigmaV));
% axis square
% 
% hP = p(1,2).select();
% 
% % Color map
% nCmapSteps = 50;
% cmap = othercolor('Mbluegreenyellow',nCmapSteps);
% cmap = cmap;
% 
% for i = 1%1:2
%    
%    if i == 1
%       rV = 0;
%    elseif i == 2
%       rV = .9;
%    end
% %    clr = cmap(round(rV.*size(cmap,1)),:);
%    clr = [.8 .8 .8];
% 
%    % Set up correlation matrix |rhoV| of accumulation rates between accumulators*
%    rhoV = rV.*ones(nA);
%    rhoV(linspace(1,numel(rhoV),length(rhoV))) = 1;
%    
%    % Sample accumulation rates with correlation from multivariant lognormal random distribution*
%    v = MvLogNRand(muVvec,sigmaVvec,nSim,rhoV);
%    v = num2cell(v);
% 
%    cellfun(@(x) line([0,1],[x,x],'Color',clr),v);hold on
% 
% end
% set(gca,'YLim',[0 5]);
% axis square
% 
% % Plot accumulation trajectories
% hP = p(2,1).select();
% [rt,activation,v,theta,iAT] = epu_sim(nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation,affTime,effTime,pN,dMeth);
% 
% 
% for i = 1:5
%    plot(1:1500, activation(i,:),'Color',clr);hold on;
%    plot(find(activation(i,:) > 100,1,'first'),100,'k.','Color',clr,'MarkerSize',20);
% end
% xLim = [0 750];
% yLim = [0 120];
% set(gca,'XLim',xLim,'YLim',yLim);
% meanActivation = nanmean(activation,1);
% plot(1:1500, meanActivation,'Color',clr,'LineWidth',2);hold on;
% line([xLim(1),xLim(2)],[100,100],'Color','k','LineStyle','--');
% 
% 
% 
% 
% 
% 
% 
% % colormap(cmap);
% % colorbar('peer', hP,'Location','EastOutside');


function [rt,activation] = sim_accumulation(nSim,nA,nTP,nAT,v,dt,sigmaXi,theta,maxActivation,affTime,effTime,pN,dMeth,iAT)

% Compute the maximum activation level that each accumulator can reach
if maxActivation <= 1
   maxActivationVec = theta./maxActivation;
else
   maxActivationVec = maxActivation.*ones(1,nA);
end

% Simulate RTs and activation trajectories

% Deteremine deterministic vs. stochastic
if sigmaXi == 0 && isinf(maxActivation) % Deterministic & Perfect - LBA
   
   activationCell = cell(nSim,1);
   
   parfor iSim = 1:nSim
      
      % *3.4 Sample accumulation rates with correlation from multivariant lognormal random distribution*
      % Sample rates for all accumulators and one trial
      % TO CONSIDER: Truncated multivariate normal distribution
      
      [thisRt,thisActivation] = epu_n_unit_lba_mex(v(iSim,:),theta,affTime,effTime,pN,dMeth,iAT);
      
      rt(iSim) = thisRt;
%       activation(iSim,:,:) = thisActivation';
      activationCell{iSim} = thisActivation';
      
   end
   
   maxLength = max(cellfun(@numel,activationCell));
   activation = cellfun(@(x) [x,nan(nAT,maxLength-numel(x))],activationCell,'UniformOutput',0);
   activation = single(cat(1,activation{:}));
   
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