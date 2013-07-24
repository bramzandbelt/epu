function plot_single_trial_examples_SfN

% Settings
nSim = 500;
nA = 1;
nTP = 1500;
nAT = 1;
mV = 1;
sdV = 1;
rV = 0.5;
dt = 1;
sigmaXi = 0.5;
rXi = 0.1;
mTheta = 100;
sdTheta = 0;
maxActivation = Inf;
affTime = 100;
effTime = 10;
pN = 0.5;

% Trial index for plotting
i = 13;


nAVec = [10];
rVVec = [.1 .9];
pNVec = [1];


for iNa = 1:length(nAVec)
   
   figure;
   p = panel;
   p.pack(length(rVVec),length(pNVec))
   
   nA = nAVec(iNa);
   nAT = nA;
      
   for iR = 1:length(rVVec)
      
      rV = rVVec(iR);
      
      rts = nan(1,length(pNVec));
      
      for iP = 1:length(pNVec)
         
         pN = pNVec(iP);

         p(iR,iP).select(); hold on;
         p(iR,iP).margin = [5 0 5 0];

         % Seed random number generator
         clear epu_n_unit_accumulator_mex
         rng(10);
         dMeth = 1;

         % Simulate activation trajectories and RT
         [rt,activation] = epu_sim(nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation,affTime,effTime,pN,dMeth);
         
         line([0 1000],[100 100],'Color','k','LineStyle','--')
         
         % Plot individual trajectories
         
         if numel(size(activation)) == 2 % if nA = 1
            plot(activation(i,:)','Color',[.8 .8 .8],'LineWidth',.5);set(gca,'YLim',[0 125]);
         elseif numel(size(activation)) == 3
            plot(squeeze(activation(i,:,:))','Color',[.8 .8 .8],'LineWidth',.5);set(gca,'YLim',[0 125]);
         end
         
         
         rts(iP) = rt(i);
         
         if iP == 1
            line([rt(i) rt(i)],[0 125],'Color','r','LineStyle','--');
         elseif iP == 2
            line([rt(i) rt(i)],[0 125],'Color','y','LineStyle','--');
         elseif iP == 3
            line([rts(1) rts(1)],[0 125],'Color','r','LineStyle','--');
            line([rts(2) rts(2)],[0 125],'Color','y','LineStyle','--');
            line([rts(3) rts(3)],[0 125],'Color','b','LineStyle','--');
         end
         
         
         
         % Seed random number generator
         clear epu_n_unit_accumulator_mex
         rng(10);
         dMeth = 2;
         
         % Simulate activation trajectories and RT
         [rt,activation] = epu_sim(nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation,affTime,effTime,pN,dMeth);
                  
         % Compute pooled trajectory and RT
         if numel(size(activation)) == 2 % if nA = 1
            poolTrajectory = activation(i,:)';
         elseif numel(size(activation)) == 3
            poolTrajectory = nanmean(squeeze(activation(i,:,:)),1);
         end
         iTP = find(poolTrajectory > 100,1,'first');
         actAroundThres = poolTrajectory(iTP-1:iTP);
         tAroundThres = dt.*[iTP-1,iTP]';
         poolRt = interp1q(actAroundThres,tAroundThres,100) + effTime;
                  
         plot(poolTrajectory','Color',[0 0 0],'LineWidth',0.5);set(gca,'YLim',[0 125]);
         line([poolRt poolRt],[0 125],'Color','g','LineStyle','--');
         
         % Set axes
         axis square
         set(gca,'XLim',[0 600]);
         
      end
      
   end
   p.refresh();   
   
end



































































% 
% %% 2. ARRAYS FOR LOGGING DATA
% rt = single(nan(nSim,1)); % Response time
% 
% %% 3. SIMULATION
% 
% % accumulation rates are sampled from a multivariate lognormal distribution. A
% % log normal distribution is chosen, because the Linear Ballistic
% % Accumulator model assumes positive accumulation rates. The accumulation rates are
% % correlated between accumulators. Then, for each trial the activation
% % trajectory for all accumulators and response time is computed.
% 
% %%
% % *3.1 Sample trigger threshols from a truncated Gaussian distribution*
% %
% % A vector |theta| is generated, containing a trigger threshold for each
% % accumulator. Trigger thresholds are sampled from a normal distribution with
% % mean |mTheta| and standard deviation |sdTheta|.
% 
% a = 0;
% b = Inf;
% 
% phiL = normcdf((a-mTheta)/sdTheta);
% phiR = normcdf((b-mTheta)/sdTheta);
% 
% theta = mTheta + sdTheta*(sqrt(2)*erfinv(2*(phiL+(phiR-phiL)*rand(1,nA))-1));
% 
% 
% 
% nAVec = [1 10 100];
% rVVec = [.9 .5 .1];
% pNVec = [0 .5 1];
% 
% for iNa = 1:length(nAVec)
%    
%    figure;
%    p = panel;
%    p.pack(3,3)
%    
%    nA = nAVec(iNa);
%    nAT = nA;
%       
%    for iR = 1:length(rVVec)
%       
%       rV = rVVec(iR);
%       
%       % Set up correlation matrix |rhoV| of accumulation rates between accumulators
%       rhoV = rV.*ones(nA);
%       rhoV(linspace(1,numel(rhoV),length(rhoV))) = 1;
% 
%       % Calculate location parameter |muV| and scale parameter |sigmaV| of lognormal accumulation rate distribution from |mV| and |sdV|
%       muV = log(mV^2 / sqrt(sdV^2+mV^2));
%       sigmaV = sqrt(log(sdV^2/mV^2 + 1));     
%       muVvec = kron(ones(nA,1),muV);
%       sigmaVvec = kron(ones(nA,1),sigmaV);
% 
%       % Sample accumulation rates with correlation from multivariant lognormal random distribution
%       % Sample rates for all accumulators and all trials at once
%       v = MvLogNRand(muVvec,sigmaVvec,nSim,rhoV);
% 
%       % Randomly select |nAT| accumulator from the set of |nA| accumulators
%       iAT = randperm(nA,nAT);
%       iAT = sort(iAT);
%       
%       for iP = 1:length(pNVec)
%          
%          pN = pNVec(iP);
%    
%          % Perfect stochastic
%          sigmaXi = 0.5;
%          maxActivation = Inf;
%          
%          % Seed random number generator
%          rng(10);
%          
%          % Simulate activation trajectories and RT
%          [rt,activation] = sim_accumulation(nSim,nA,nTP,nAT,v,dt,sigmaXi,rXi,theta,maxActivation,affTime,effTime,pN,dMeth,iAT);
%                   
%          % Plot accumulators
%          p(iR,iP).select();
%          
%          
%          
%       end
%    end
% 
% end
% 
% 
% 
% 
% 
% 
% function [rt,activation] = sim_accumulation(nSim,nA,nTP,nAT,v,dt,sigmaXi,rXi,theta,maxActivation,affTime,effTime,pN,dMeth,iAT)
% 
% % Compute the maximum activation level that each accumulator can reach
% if maxActivation <= 1
%    maxActivationVec = theta./maxActivation;
% else
%    maxActivationVec = maxActivation.*ones(1,nA);
% end
%    
% % Simulate RTs and activation trajectories
% 
% % Deteremine deterministic vs. stochastic
% if sigmaXi == 0 && isinf(maxActivation) % Deterministic & Perfect - LBA
%    
%    activationCell = cell(nSim,1);
%    
%    parfor iSim = 1:nSim
%       
%       % *3.4 Sample accumulation rates with correlation from multivariant lognormal random distribution*
%       % Sample rates for all accumulators and one trial
%       % TO CONSIDER: Truncated multivariate normal distribution
%       
%       [thisRt,thisActivation] = epu_n_unit_lba_mex(v(iSim,:),theta,affTime,effTime,pN,dMeth,iAT);
%       
%       rt(iSim) = thisRt;
%       activationCell{iSim} = thisActivation';
%       
%    end
%    
%    maxLength = max(cellfun(@numel,activationCell));
%    activation = cellfun(@(x) [x,nan(1,maxLength-numel(x))],activationCell,'UniformOutput',0);
%    activation = single(cat(1,activation{:}));
%    
% else % Stochastic and/or Leaky
%    
%    activation = single(nan(nSim,nAT,nTP)); % Activation
%    
%    % Cholesky-like decomposition for covariance matrix
%    rhoXi = rXi.*ones(nA);
%    rhoXi(linspace(1,numel(rhoXi),length(rhoXi))) = 1;
%    SigmaXi = rhoXi.*sigmaXi; % Covariance matrix
%    [SigmaXi,err] = cholcov(SigmaXi); % Cholesky-like decomposition
%    if err ~= 0
%       error(message('BadCovariance2DSymPos'));
%    end
%    
%    parfor iSim = 1:nSim
%    
%       k = v(iSim,:)./maxActivationVec; % Leakage proprotional to rate, so activationLimit is fixed
% 
% 
%       [thisRt,thisActivation] = ...
%       epu_n_unit_accumulator_mex(nTP,v(iSim,:),dt,sigmaXi,SigmaXi,theta,k,affTime,effTime,pN,dMeth,iAT);
% 
%       rt(iSim) = thisRt;
%       activation(iSim,:,:) = thisActivation';
%    
%    end
% end
% 
% % Remove singleton dimensions, if any
% activation = squeeze(activation);
% 
% % Discard rates of non-selected accumulators
% v = v(:,iAT);
% 
% % Compute simulation time