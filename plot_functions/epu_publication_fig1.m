% Figures for publication


%% Figure 1. Explanation of the problem

% Set parameters of EPU simulation
job = epu_sim_master('get_defaults');
job.nSes = 1;
job.nSim = 500;
job.nA = 1;
job.nAT = job.nA;
job.rV = 1;
job.pN = 0.5;
job.rngID = 1000;
job.sigmaXi = 1;

[nSes,nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,...
   maxActivation,affTime,effTime,pN,dMeth,tag,rngID] = epu_check_inputs(job);

%% PLOT ALL TRIALS, EACH TRAJECTORY SEPARATELY
close all

% Create figure
figWidth = 18;
figHeight= 12;
figUnit = 'centimeters';
figSpecs = {figWidth, figHeight, figUnit};
paperSpecs = {'USLetter','Portrait'};
hFig = set_figure(figSpecs,paperSpecs);

% Initiate panels
p = panel;
p.pack(2,3);
p(1,2).pack('v',[1/3,2/3]);
p(1,2,1).margin = [15 0 5 5];    % No margin at bottom
p(1,2,2).margin = [15 15 5 0];   % No margin at top

p(1,3).pack('v',[1/3,2/3]);
p(1,3,1).margin = [15 0 5 5];    % No margin at bottom
p(1,3,2).margin = [15 15 5 0];   % No margin at top


% Panel 1,2: standard stochastic accumulator

clear epu_n_unit_accumulator_mex
rng(rngID);

% Simulate RTs, trajectories
[rt,activation,v,theta,iAT] = ...
epu_sim(nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation, ...
affTime,effTime,pN,dMeth);

% Compute and define some variables
tMax = quantile(rt,.975); % Maximum time point to plot
vMax = max(v);
rtEdges = [0:10:tMax];
vEdges = linspace(0,vMax,100);
NMax = max(histc(rt,rtEdges));
NVMax = max(histc(v,vEdges));

% Plot data stochastic accumulator
p(1,2,1).select(); cla; hold on

N = histc(rt(rt <= tMax),rtEdges);

bar(rtEdges,N,'histc');

hBar = findobj(gca,'Type','patch');
set(hBar,'FaceColor',[0 0 0],'EdgeColor',[0 0 0]);
set(gca,'Color','none','XLim',[0 tMax],'YLim',[1 NMax],'XTick',[],'YTick',[]);
% text(1/2*tMax,0.5*NMax,'RT','FontSize',12,'Color',[0 0 0]);
axis off

p(1,2,2).select(); hold on
plot(activation(rt <= tMax,:)','Color',[1 0 0]); % Trajectories of all trials
line([0 tMax],[mTheta,mTheta],'Color','k','LineWidth',2); % Threshold (theta)
set(gca,'Box','off','Color','none','XLim',[0 tMax],'YLim',[0 mTheta+1],'XTick',[],'YTick',[]);

hThetaLabel = text(-5,mTheta,sprintf('\\theta'),'FontSize',12,'Color','k','HorizontalAlignment','right');

hXL122 = xlabel('time from target');
set(hXL122,'Units','normalized','Position',[1 0 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',10,'HorizontalAlignment','right','VerticalAlignment','cap');
hYL122 = ylabel('evidence');
set(hYL122,'Units','normalized','Position',[0 0.5 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',10,'HorizontalAlignment','center','VerticalAlignment','bottom','Rotation',90);

% Plot data individual 'neuron'
job.nA = 100;
job.nAT = 1;
[nSes,nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,...
   maxActivation,affTime,effTime,pN,dMeth,tag,rngID] = epu_check_inputs(job);

% Simulate RTs, trajectories
clear epu_n_unit_accumulator_mex
rng(rngID);

[rt,activation,v,theta,iAT] = ...
epu_sim(nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation, ...
affTime,effTime,pN,dMeth);

settings.general.datetime     = datestr(now);
settings.general.environment  = 'local';
settings.general.outputPath = '/Users/bram/Documents/EPU/Simulation_2012Aug28/movie/pics/explainThresholdVariation/';
settings.general.fileTimestamp                 = datestr(settings.general.datetime,'yyyymmddTHHMMSS');
settings.general.fractSesToSave               = 0.01; % Fraction of sessions to save individually
% 2. Statistics
settings.statistics.ciType                      = 95; % Percentage of confidence interval
settings.statistics.qntls                     = [.1 .3 .5 .7 .9]; % Quantiles for rt, threshold, rate
settings.statistics.densityBinSizeRt          = 3;
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

[stats,trajectories,thresholds,rates,onsetTimes] = epu_session_statistics('alldata',rt,activation,10,job,settings);


% Load Purcell et al. (2012) data
load /Users/bram/Documents/EPU/Simulation_2012Aug28/PurcellEtAl2012Data/Binned_mov_cell_SDFs_RTs_SS4_correct.mat

p(1,3,1).select(); cla; hold on

rt = GroupRTs(:);
tMax = quantile(rt,.975); % Maximum time point to plot
rtEdges = [0:10:tMax];
NMax = max(histc(rt,rtEdges));


N = histc(rt(rt <= tMax),rtEdges);
bar(rtEdges,N,'histc');

hBar = findobj(gca,'Type','patch');
set(hBar,'FaceColor',[0 0 0],'EdgeColor',[0 0 0]);
set(gca,'Color','none','XLim',[0 tMax],'YLim',[1 NMax],'XTick',[],'YTick',[]);
axis off

p(1,3,2).select(); cla; hold on

effTime = 10; % Gives the best results
tThres = nan(1,5);
meanActivation = nan(1,5);
semActivation = nan(1,5);

for i = 1:5
   % Estimate threshold crossing time
   tThres(i) = round(nanmean(nanmean(GroupRTs(:,:,i))))-effTime;

   % Estimate standard error of mean of activation level
   meanActivation(i) = nanmean(GroupSDFs.aot(:,500+tThres(i),i));
   semActivation(i) = meanActivation(i)./size(GroupSDFs.aot,1);

   % Plot trajectories
   plot([0:tThres(i)],nanmean(GroupSDFs.aot(:,500:500+tThres(i),i)),'Color',[1 0 0]);

   % Plot errorbars
   errorbar(tThres(i),meanActivation(i),semActivation(i),'Color',[1 0 0]);
end

B = nanmean(meanActivation);
linRegFun = @(x) B + 0.*x;    
x = 0:1.1*tThres(5);
plot(x,linRegFun(x),'Color','k','LineStyle','-','LineWidth',2);

baselineEstimate = nanmean(nanmean(nanmean(GroupSDFs.aot(:,500:550,:))));

set(gca,'Box','off','Color','none','XLim',[0 tMax],'YLim',[baselineEstimate-2 B+5],'XTick',[],'YTick',[]);

hThetaLabel = text(-5,mTheta,sprintf('\\theta'),'FontSize',12,'Color','k','HorizontalAlignment','right');

hXL132 = xlabel('time from target');
set(hXL132,'Units','normalized','Position',[1 0 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',10,'HorizontalAlignment','right','VerticalAlignment','cap');
hYL132 = ylabel('Activation');
set(hYL132,'Units','normalized','Position',[0 0.5 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',10,'HorizontalAlignment','center','VerticalAlignment','bottom','Rotation',90);


% rtBinEdges = quantile(rt(rt<=tMax),[0:.01:1]);
% % rtBinEdges = quantile(rt(rt<=tMax),[0,1/2,2/3,1]);
% [~,iBin] = histc(rt,rtBinEdges);
% 
% plot(nanmean(activation(iBin == 20,1:ceil(mean(rt(iBin == 20))))),'Color',[1 0 0]); % Trajectories of all trials
% plot(nanmean(activation(iBin == 45,1:ceil(mean(rt(iBin == 45))))),'Color',[1 0 0]); % Trajectories of all trials
% plot(nanmean(activation(iBin == 60,1:ceil(mean(rt(iBin == 60))))),'Color',[1 0 0]); % Trajectories of all trials
% plot(nanmean(activation(iBin == 72,1:ceil(mean(rt(iBin == 72))))),'Color',[1 0 0]); % Trajectories of all trials
% plot(nanmean(activation(iBin == 85,1:ceil(mean(rt(iBin == 85))))),'Color',[1 0 0]); % Trajectories of all trials
% plot(nanmean(activation(iBin == 95,1:ceil(mean(rt(iBin == 95))))),'Color',[1 0 0]); % Trajectories of all trials
% 
% line([0 tMax],[mTheta,mTheta],'Color','k','LineWidth',2,'LineStyle','--'); % Threshold (theta)
% 
% set(gca,'Box','off','Color','none','XLim',[0 tMax],'YLim',[0 mTheta+1],'XTick',[],'YTick',[]);
% 
% hThetaLabel = text(-5,mTheta,sprintf('\\theta'),'FontSize',12,'Color','k','HorizontalAlignment','right');
% 
% hXL132 = xlabel('time from target');
% set(hXL132,'Units','normalized','Position',[1 0 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',10,'HorizontalAlignment','right','VerticalAlignment','cap');
% hYL132 = ylabel('Activation');
% set(hYL132,'Units','normalized','Position',[0 0.5 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',10,'HorizontalAlignment','center','VerticalAlignment','bottom','Rotation',90);

%% Plot data from EPU model
job.nSim = 1;
job.rV = 1;
job.rXi = 1;
job.nA = 10;
job.nAT = 10;
[nSes,nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation,affTime,effTime,pN,dMeth,tag,rngID] = epu_check_inputs(job);

% Simulate RTs, trajectories for termination rule 'last' with high rate correlation
job.dMeth = 1;
job.pN = [0 0.5 1];
[nSes,nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation,affTime,effTime,pN,dMeth,tag,rngID] = epu_check_inputs(job);
clear epu_n_unit_accumulator_mex
rng(rngID);
[rtLastHigh,activationLastHigh,vLastHigh,thetaLastHigh] = epu_sim(nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation,affTime,effTime,pN,dMeth);
rtLastHigh = double(rtLastHigh);
[~,~,thresholdsLastHigh] = epu_session_statistics('alldata',rtLastHigh,activationLastHigh,10,job,settings);

% Simulate RTs, trajectories for termination rule 'first' with high rate correlation
job.dMeth = 1;
job.pN = 0;
[nSes,nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation,affTime,effTime,pN,dMeth,tag,rngID] = epu_check_inputs(job);
clear epu_n_unit_accumulator_mex
rng(rngID);
[rtFirstHigh,activationFirstHigh,vFirstHigh,thetaFirstHigh] = epu_sim(nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation,affTime,effTime,pN,dMeth);
rtFirstHigh = double(rtFirstHigh);
[~,~,thresholdsFirstHigh] = epu_session_statistics('alldata',rtFirstHigh,activationLastHigh,10,job,settings);

% Simulate RTs, trajectories for termination rule 'mean' with high rate correlation
job.dMeth = 2;
[nSes,nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation,affTime,effTime,pN,dMeth,tag,rngID] = epu_check_inputs(job);
clear epu_n_unit_accumulator_mex
rng(rngID);
[rtMeanHigh,activationMeanHigh,vMeanHigh,thetaMeanHigh] = epu_sim(nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation,affTime,effTime,pN,dMeth);
rtMeanHigh = double(rtMeanHigh);
[~,~,thresholdsMeanHigh] = epu_session_statistics('alldata',rtMeanHigh,activationLastHigh,10,job,settings);

job.rV = .2;
job.rXi = 0.1;
job.nA = 10;
job.nAT = 10;
[nSes,nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation,affTime,effTime,pN,dMeth,tag,rngID] = epu_check_inputs(job);

% Simulate RTs, trajectories for termination rule 'last' with low rate correlation
job.dMeth = 1;
job.pN = 1;
[nSes,nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation,affTime,effTime,pN,dMeth,tag,rngID] = epu_check_inputs(job);
clear epu_n_unit_accumulator_mex
rng(rngID);
[rtLastLow,activationLastLow,vLastLow,thetaLastLow] = epu_sim(nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation,affTime,effTime,pN,dMeth);
rtLastLow = double(rtLastLow);
[~,~,thresholdsLastLow] = epu_session_statistics('alldata',rtLastLow,activationLastLow,10,job,settings);

% Simulate RTs, trajectories for termination rule 'first' with low rate correlation
job.dMeth = 1;
job.pN = 0;
[nSes,nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation,affTime,effTime,pN,dMeth,tag,rngID] = epu_check_inputs(job);
clear epu_n_unit_accumulator_mex
rng(rngID);
[rtFirstLow,activationFirstLow,vFirstLow,thetaFirstLow] = epu_sim(nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation,affTime,effTime,pN,dMeth);
rtFirstLow = double(rtFirstLow);
[~,~,thresholdsFirstLow] = epu_session_statistics('alldata',rtFirstLow,activationLastLow,10,job,settings);

% Simulate RTs, trajectories for termination rule 'mean' with low rate correlation
job.dMeth = 2;
[nSes,nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation,affTime,effTime,pN,dMeth,tag,rngID] = epu_check_inputs(job);
clear epu_n_unit_accumulator_mex
rng(rngID);
[rtMeanLow,activationMeanLow,vMeanLow,thetaMeanLow] = epu_sim(nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation,affTime,effTime,pN,dMeth);
rtMeanLow = double(rtMeanLow);
[~,~,thresholdsMeanLow] = epu_session_statistics('alldata',rtMeanLow,activationLastLow,10,job,settings);

aoi = 10; % Accumulator of interest

hTrialLabel = text(double(tMax),0.5*mTheta,sprintf('trial %.3d',0),'FontSize',10,'Color','k','HorizontalAlignment','right');


for iSim = 63%1:500
   
   if rtLastHigh(iSim) <= tMax & rtLastLow(iSim) <= tMax
      
      maxActivation = double(max([max(activationLastLow(iSim,:));max(activationLastHigh(iSim,:))]));
      maxRT = max([rtLastLow(iSim);rtLastHigh(iSim)]);
      
      p(2,2).select(); cla; hold on;
      hPgrey = plot(squeeze(activationLastLow(iSim,1:nA-1,1:tMax))','Color',[.5 .5 .5],'LineWidth',1); % Redundant accumulators
      hPblack = plot(nanmean(squeeze(activationLastLow(iSim,1:nA,1:tMax))),'Color',[0 0 0],'LineWidth',1); % Mean
      hPred = plot(squeeze(activationLastLow(iSim,aoi,1:tMax))','Color',[1 0 0],'LineWidth',1); % Measured accumulator
      hTrialLabel = text(double(maxRT),0.5*mTheta,sprintf('trial %.3d',iSim),'FontSize',10,'Color','k','HorizontalAlignment','right');

      line([rtFirstLow(iSim)-effTime,rtFirstLow(iSim)-effTime],[0,thresholdsFirstLow(iSim,aoi)],'Color','k','LineWidth',1,'LineStyle','--');
      line([rtMeanLow(iSim)-effTime,rtMeanLow(iSim)-effTime],[0,thresholdsMeanLow(iSim,aoi)],'Color','k','LineWidth',1,'LineStyle','--');
      line([rtLastLow(iSim)-effTime,rtLastLow(iSim)-effTime],[0,thresholdsLastLow(iSim,aoi)],'Color','k','LineWidth',1,'LineStyle','--');

      set(gca,'Box','off','Color','none','XLim',[0 maxRT],'YLim',[0 maxActivation],'XTick',[],'YTick',[]);

      line([0,rtFirstLow(iSim)-effTime],[thresholdsFirstLow(iSim,aoi),thresholdsFirstLow(iSim,aoi)],'Color','k','LineWidth',1,'LineStyle','--');
      line([0,rtMeanLow(iSim)-effTime],[thresholdsMeanLow(iSim,aoi),thresholdsMeanLow(iSim,aoi)],'Color','k','LineWidth',1,'LineStyle','--');
      line([0,rtLastLow(iSim)-effTime],[thresholdsLastLow(iSim,aoi),thresholdsLastLow(iSim,aoi)],'Color','k','LineWidth',1,'LineStyle','--');

      line([0 tMax],[mTheta,mTheta],'Color','k','LineWidth',1,'LineStyle','-'); % Threshold (theta)
      
      
      plot([rtFirstLow(iSim)-effTime,rtMeanLow(iSim)-effTime,rtLastLow(iSim)-effTime],[mTheta,mTheta,mTheta],'Marker','v','MarkerSize',6,'LineStyle','none','MarkerFaceColor',[0 174 239]./255,'MarkerEdgeColor','none')
      plot([rtFirstLow(iSim)-effTime,rtMeanLow(iSim)-effTime,rtLastLow(iSim)-effTime],[thresholdsFirstLow(iSim,aoi),thresholdsMeanLow(iSim,aoi),thresholdsLastLow(iSim,aoi)],'Marker','o','MarkerSize',4,'LineStyle','none','MarkerFaceColor',[1 0 0],'MarkerEdgeColor','none')

      hThetaLabel = text(-5,mTheta,sprintf('\\theta'),'FontSize',12,'Color','k','HorizontalAlignment','right');

      hMThetaFirstLabel = text(rtFirstLow(iSim)-effTime,thresholdsFirstLow(iSim,aoi),sprintf('\\theta_m'),'FontSize',12,'Color','k','HorizontalAlignment','right','VerticalAlignment','bottom');
      hMThetaMeanLabel = text(rtMeanLow(iSim)-effTime,thresholdsMeanLow(iSim,aoi),sprintf('\\theta_m'),'FontSize',12,'Color','k','HorizontalAlignment','right','VerticalAlignment','bottom');
      hMThetaLastLabel = text(rtLastLow(iSim)-effTime,thresholdsLastLow(iSim,aoi),sprintf('\\theta_m'),'FontSize',12,'Color','k','HorizontalAlignment','right','VerticalAlignment','bottom');

      rtFirstLabel = text(rtFirstLow(iSim)-effTime,-10,'RT','FontSize',12,'Color','k','HorizontalAlignment','right','VerticalAlignment','top','Rotation',45);
      rtMeanLabel = text(rtMeanLow(iSim)-effTime,-10,'RT','FontSize',12,'Color','k','HorizontalAlignment','right','VerticalAlignment','top','Rotation',45);
      rtLastLabel = text(rtLastLow(iSim)-effTime,-10,'RT','FontSize',12,'Color','k','HorizontalAlignment','right','VerticalAlignment','top','Rotation',45);

      NALabel = text(0.05*maxRT,0.90*maxActivation,sprintf('N_A = %d',10),'FontSize',10,'Color','k','HorizontalAlignment','left','VerticalAlignment','middle');
      NTrLabel = text(0.05*maxRT,0.80*maxActivation,sprintf('N_t_r = %d',1),'FontSize',10,'Color','k','HorizontalAlignment','left','VerticalAlignment','middle');
      rhoVLabel = text(0.05*maxRT,0.70*maxActivation,sprintf('\\rho_v = %.2f',0.2),'FontSize',10,'Color',[247 148 30]./255,'HorizontalAlignment','left','VerticalAlignment','middle');
      
      p(2,3).select(); cla; hold on;
      hPgrey = plot(squeeze(activationLastHigh(iSim,1:nA-1,1:tMax))','Color',[.5 .5 .5],'LineWidth',1); % Redundant accumulators
      hPblack = plot(nanmean(squeeze(activationLastHigh(iSim,1:nA,1:tMax))),'Color',[0 0 0],'LineWidth',1); % Mean
      hPred = plot(squeeze(activationLastHigh(iSim,aoi,1:tMax))','Color',[1 0 0],'LineWidth',1); % Measured accumulator
%       hTrialLabel = text(double(maxRT),0.5*mTheta,sprintf('trial %.3d',iSim),'FontSize',10,'Color','k','HorizontalAlignment','right');

      line([rtFirstHigh(iSim)-effTime,rtFirstHigh(iSim)-effTime],[0,thresholdsFirstHigh(iSim,aoi)],'Color','k','LineWidth',1,'LineStyle','--');
      line([rtMeanHigh(iSim)-effTime,rtMeanHigh(iSim)-effTime],[0,thresholdsMeanHigh(iSim,aoi)],'Color','k','LineWidth',1,'LineStyle','--');
      line([rtLastHigh(iSim)-effTime,rtLastHigh(iSim)-effTime],[0,thresholdsLastHigh(iSim,aoi)],'Color','k','LineWidth',1,'LineStyle','--');

      set(gca,'Box','off','Color','none','XLim',[0 maxRT],'YLim',[0 maxActivation],'XTick',[],'YTick',[]);

      line([0,rtFirstHigh(iSim)-effTime],[thresholdsFirstHigh(iSim,aoi),thresholdsFirstHigh(iSim,aoi)],'Color','k','LineWidth',1,'LineStyle','--');
      line([0,rtMeanHigh(iSim)-effTime],[thresholdsMeanHigh(iSim,aoi),thresholdsMeanHigh(iSim,aoi)],'Color','k','LineWidth',1,'LineStyle','--');
      line([0,rtLastHigh(iSim)-effTime],[thresholdsLastHigh(iSim,aoi),thresholdsLastHigh(iSim,aoi)],'Color','k','LineWidth',1,'LineStyle','--');

      line([0 tMax],[mTheta,mTheta],'Color','k','LineWidth',1,'LineStyle','-'); % Threshold (theta)
      
      plot([rtFirstHigh(iSim)-effTime,rtMeanHigh(iSim)-effTime,rtLastHigh(iSim)-effTime],[mTheta,mTheta,mTheta],'Marker','v','MarkerSize',6,'LineStyle','none','MarkerFaceColor',[0 174 239]./255,'MarkerEdgeColor','none')
      plot([rtFirstHigh(iSim)-effTime,rtMeanHigh(iSim)-effTime,rtLastHigh(iSim)-effTime],[thresholdsFirstHigh(iSim,aoi),thresholdsMeanHigh(iSim,aoi),thresholdsLastHigh(iSim,aoi)],'Marker','o','MarkerSize',4,'LineStyle','none','MarkerFaceColor',[1 0 0],'MarkerEdgeColor','none')
      
      hThetaLabel = text(-5,mTheta,sprintf('\\theta'),'FontSize',12,'Color','k','HorizontalAlignment','right');

      hMThetaFirstLabel = text(rtFirstHigh(iSim)-effTime,thresholdsFirstHigh(iSim,aoi),sprintf('\\theta_m'),'FontSize',12,'Color','k','HorizontalAlignment','right','VerticalAlignment','bottom');
      hMThetaMeanLabel = text(rtMeanHigh(iSim)-effTime,thresholdsMeanHigh(iSim,aoi),sprintf('\\theta_m'),'FontSize',12,'Color','k','HorizontalAlignment','right','VerticalAlignment','bottom');
      hMThetaLastLabel = text(rtLastHigh(iSim)-effTime,thresholdsLastHigh(iSim,aoi),sprintf('\\theta_m'),'FontSize',12,'Color','k','HorizontalAlignment','right','VerticalAlignment','bottom');

      rtFirstLabel = text(rtFirstHigh(iSim)-effTime,-10,'RT','FontSize',12,'Color','k','HorizontalAlignment','right','VerticalAlignment','top','Rotation',45);
      rtMeanLabel = text(rtMeanHigh(iSim)-effTime,-10,'RT','FontSize',12,'Color','k','HorizontalAlignment','right','VerticalAlignment','top','Rotation',45);
      rtLastLabel = text(rtLastHigh(iSim)-effTime,-10,'RT','FontSize',12,'Color','k','HorizontalAlignment','right','VerticalAlignment','top','Rotation',45);

      NALabel = text(0.05*maxRT,0.90*maxActivation,sprintf('N_A = %d',10),'FontSize',10,'Color','k','HorizontalAlignment','left','VerticalAlignment','middle');
      NTrLabel = text(0.05*maxRT,0.80*maxActivation,sprintf('N_t_r = %d',1),'FontSize',10,'Color','k','HorizontalAlignment','left','VerticalAlignment','middle');
      rhoVLabel = text(0.05*maxRT,0.70*maxActivation,sprintf('\\rho_v = %.2f',1),'FontSize',10,'Color',[247 148 30]./255,'HorizontalAlignment','left','VerticalAlignment','middle');
      
      pause;
   end
end




%% Plot data from EPU model: 1 trial, low rate correlation



aoi = 10; % Accumulator of interest

hTrialLabel = text(double(tMax),0.5*mTheta,sprintf('trial %.3d',0),'FontSize',10,'Color','k','HorizontalAlignment','right');



for iSim = 1:500
   
   if rtLastLow(iSim) <= tMax
      p(2,3).select(); cla; hold on;
      hPgrey = plot(squeeze(activationLastLow(iSim,1:nA-1,1:tMax))','Color',[.5 .5 .5],'LineWidth',1); % Turns out that last trial has good noise
      hPred = plot(squeeze(activationLastLow(iSim,aoi,1:tMax))','Color',[1 0 0],'LineWidth',1); % Turns out that last trial has good noise
      hTrialLabel = text(double(tMax),0.5*mTheta,sprintf('trial %.3d',iSim),'FontSize',10,'Color','k','HorizontalAlignment','right');

      line([rtFirstLow(iSim),rtFirstLow(iSim)],[0,thresholdsFirstLow(iSim,aoi)],'Color','k','LineWidth',1,'LineStyle','--');
      line([rtMeanLow(iSim),rtMeanLow(iSim)],[0,thresholdsMeanLow(iSim,aoi)],'Color','k','LineWidth',1,'LineStyle','--');
      line([rtLastLow(iSim),rtLastLow(iSim)],[0,thresholdsLastLow(iSim,aoi)],'Color','k','LineWidth',1,'LineStyle','--');

      set(gca,'Box','off','Color','none','XLim',[0 tMax],'YLim',[0 max(activationLastLow(iSim,:))],'XTick',[],'YTick',[]);

      line([0,rtFirstLow(iSim)],[thresholdsFirstLow(iSim,aoi),thresholdsFirstLow(iSim,aoi)],'Color','k','LineWidth',1,'LineStyle','--');
      line([0,rtMeanLow(iSim)],[thresholdsMeanLow(iSim,aoi),thresholdsMeanLow(iSim,aoi)],'Color','k','LineWidth',1,'LineStyle','--');
      line([0,rtLastLow(iSim)],[thresholdsLastLow(iSim,aoi),thresholdsLastLow(iSim,aoi)],'Color','k','LineWidth',1,'LineStyle','--');

      line([0 tMax],[mTheta,mTheta],'Color','k','LineWidth',1,'LineStyle','-'); % Threshold (theta)


      hThetaLabel = text(-5,mTheta,sprintf('\\theta'),'FontSize',12,'Color','k','HorizontalAlignment','right');

      hMThetaFirstLabel = text(rtFirstLow(iSim),thresholdsFirstLow(iSim,aoi),sprintf('\\theta_m'),'FontSize',12,'Color','k','HorizontalAlignment','right','VerticalAlignment','bottom');
      hMThetaMeanLabel = text(rtMeanLow(iSim),thresholdsMeanLow(iSim,aoi),sprintf('\\theta_m'),'FontSize',12,'Color','k','HorizontalAlignment','right','VerticalAlignment','bottom');
      hMThetaLastLabel = text(rtLastLow(iSim),thresholdsLastLow(iSim,aoi),sprintf('\\theta_m'),'FontSize',12,'Color','k','HorizontalAlignment','right','VerticalAlignment','bottom');

      rtFirstLabel = text(rtFirstLow(iSim),-10,'RT','FontSize',12,'Color','k','HorizontalAlignment','right','VerticalAlignment','top','Rotation',45);
      rtMeanLabel = text(rtMeanLow(iSim),-10,'RT','FontSize',12,'Color','k','HorizontalAlignment','right','VerticalAlignment','top','Rotation',45);
      rtLastLabel = text(rtLastLow(iSim),-10,'RT','FontSize',12,'Color','k','HorizontalAlignment','right','VerticalAlignment','top','Rotation',45);

      pause;
   end
end

