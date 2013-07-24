function epu_explain_exclusion_perfectcorrelation_stochastic_model
%% Make sure that in epu_session_statistics stats.allTrajectories is not
%% commented out

% General settings
job = epu_sim_master('get_defaults');
job.nSes = 1;
job.nAT = 10;
job.rngID = rng(1000);

aoi = 3;
ani = 1:job.nA;ani(aoi) = [];
settings.general.datetime     = datestr(now);
settings.general.environment  = 'local';
      
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

figure;
p = panel;
p.pack(4,4);

%% 1. Stochastic model, rV = 1, pN = 0;
job.rV = 1;
job.pN = 0;

[nSes,nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation,affTime,effTime,pN,dMeth,tag,rngID] = epu_check_inputs(job);

[rt,activation,v,theta,iAT] = ...
epu_sim(nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation, ...
affTime,effTime,pN,dMeth);
         
%% Get session statistics of behavior and brain-behavior relationships
stats = epu_session_statistics(rt,activation,iAT,job,settings);

% Settings
iTrial = int32(linspace(0,nSim,11));
iBins1 = [2,10];
iBins2 = [5:5:45];
iTrial = iTrial(iBins1);
reds = [linspace(1,1,length(iBins2)+1)',linspace(0,1,length(iBins2)+1)',linspace(0,1,length(iBins2)+1)'];

% Sort RTs
sortedRT = sortrows([[1:nSim]',rt],2);


p(1,1).select(); hold on;

% Get trajectories
aniTraj = squeeze(activation(sortedRT(iTrial(1),1),ani,1:1500));
aoiTraj = squeeze(activation(sortedRT(iTrial(1),1),aoi,1:1500));

% Plottrajectories
plot(aniTraj','Color',[.8 .8 .8],'LineStyle','-','LineWidth',1);
plot(aoiTraj','Color',[1 0 0],'LineStyle','-','LineWidth',1);
line([0,1500],[mTheta,mTheta],'Color',[0 0 0],'LineStyle','-','LineWidth',2);
line([sortedRT(iTrial(1),2),sortedRT(iTrial(1),2)],[0,mTheta + 50],'Color',[0 0 0],'LineStyle','--','LineWidth',1);

% Set axis
set(gca,'XLim',[0 1500],...
        'XTick',[0],...
        'YLim',[0 mTheta + 50],...
        'YTick',[0 mTheta]);


% Slow trial     
p(1,2).select(); hold on;
     

% Get trajectories
aniTraj = squeeze(activation(sortedRT(iTrial(2),1),ani,1:1500));
aoiTraj = squeeze(activation(sortedRT(iTrial(2),1),aoi,1:1500));

% Plottrajectories
plot(aniTraj','Color',[.8 .8 .8],'LineStyle','-','LineWidth',1);
plot(aoiTraj','Color',[1 0 0],'LineStyle','-','LineWidth',1);
line([0,1500],[mTheta,mTheta],'Color',[0 0 0],'LineStyle','-','LineWidth',2);
line([sortedRT(iTrial(2),2),sortedRT(iTrial(2),2)],[0,mTheta + 50],'Color',[0 0 0],'LineStyle','--','LineWidth',1);

% Set axis
set(gca,'XLim',[0 1500],...
        'XTick',[0],...
        'YLim',[0 mTheta + 50],...
        'YTick',[0 mTheta]);
     
% RT-aligned trajectories     
p(2,1).select(); hold on;



hP = patch([-20 -10 -10 -20],[0,0,mTheta + 50,mTheta + 50],'k');
set(hP,'FaceColor',[.8 .8 .8],'EdgeColor','none');
for i = 1:length(iBins2)
   plot(-200:1:10,squeeze(stats.binnedTrajectories(iBins2(i),:,aoi)),'Color',reds(i,:));
end
line([-200,10],[mTheta,mTheta],'Color',[0 0 0],'LineStyle','-','LineWidth',2);
line([0,0],[0,mTheta + 50],'Color',[0 0 0],'LineStyle','--','LineWidth',1);

% Set axis
set(gca,'XLim',[-50 10],...
        'XTick',[0],...
        'YLim',[0 mTheta + 50],...
        'YTick',[0 mTheta]);


% Measured threshold vs RT
p(2,2).select();hold on

for i = 1:length(iBins2)
   hP = plot(stats.thresVsRtPoly1_W(aoi).dataX(iBins2(i)),stats.thresVsRtPoly1_W(aoi).dataY(iBins2(i)),'ro');%'MarkerFaceColor',reds(i,:),'MarkerEdgeColor','none','LineStyle','none');
   set(hP,'MarkerFaceColor',reds(i,:),'MarkerEdgeColor','none','LineStyle','none');
end
line([0,1500],[mTheta,mTheta],'Color',[0 0 0],'LineStyle','-','LineWidth',2);

% Set axis
set(gca,'XLim',[0 500],...
        'XTick',[0],...
        'YLim',[0 mTheta + 50],...
        'YTick',[0 mTheta]);

     

%% 2. Stochastic model, rV = 1, pN = 1;
job.rV = 1;
job.pN = 1;

[nSes,nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation,affTime,effTime,pN,dMeth,tag,rngID] = epu_check_inputs(job);

[rt,activation,v,theta,iAT] = ...
epu_sim(nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation, ...
affTime,effTime,pN,dMeth);
         
%% Get session statistics of behavior and brain-behavior relationships
stats = epu_session_statistics(rt,activation,iAT,job,settings);

% Settings
iTrial = int32(linspace(0,nSim,11));
iBins1 = [2,10];
iBins2 = [5:5:45];
iTrial = iTrial(iBins1);
reds = [linspace(1,1,length(iBins2)+1)',linspace(0,1,length(iBins2)+1)',linspace(0,1,length(iBins2)+1)'];

% Sort RTs
sortedRT = sortrows([[1:nSim]',rt],2);


p(1,3).select(); hold on;

% Get trajectories
aniTraj = squeeze(activation(sortedRT(iTrial(1),1),ani,1:1500));
aoiTraj = squeeze(activation(sortedRT(iTrial(1),1),aoi,1:1500));

% Plottrajectories
plot(aniTraj','Color',[.8 .8 .8],'LineStyle','-','LineWidth',1);
plot(aoiTraj','Color',[1 0 0],'LineStyle','-','LineWidth',1);
line([0,1500],[mTheta,mTheta],'Color',[0 0 0],'LineStyle','-','LineWidth',2);
line([sortedRT(iTrial(1),2),sortedRT(iTrial(1),2)],[0,mTheta + 50],'Color',[0 0 0],'LineStyle','--','LineWidth',1);

% Set axis
set(gca,'XLim',[0 1500],...
        'XTick',[0],...
        'YLim',[0 mTheta + 50],...
        'YTick',[0 mTheta]);


% Slow trial     
p(1,4).select(); hold on;
     

% Get trajectories
aniTraj = squeeze(activation(sortedRT(iTrial(2),1),ani,1:1500));
aoiTraj = squeeze(activation(sortedRT(iTrial(2),1),aoi,1:1500));

% Plottrajectories
plot(aniTraj','Color',[.8 .8 .8],'LineStyle','-','LineWidth',1);
plot(aoiTraj','Color',[1 0 0],'LineStyle','-','LineWidth',1);
line([0,1500],[mTheta,mTheta],'Color',[0 0 0],'LineStyle','-','LineWidth',2);
line([sortedRT(iTrial(2),2),sortedRT(iTrial(2),2)],[0,mTheta + 50],'Color',[0 0 0],'LineStyle','--','LineWidth',1);

% Set axis
set(gca,'XLim',[0 1500],...
        'XTick',[0],...
        'YLim',[0 mTheta + 50],...
        'YTick',[0 mTheta]);
     
% RT-aligned trajectories     
p(2,3).select(); hold on;

hP = patch([-20 -10 -10 -20],[0,0,mTheta + 50,mTheta + 50],'k');
set(hP,'FaceColor',[.8 .8 .8],'EdgeColor','none');
for i = 1:length(iBins2)
   plot(-200:1:10,squeeze(stats.binnedTrajectories(iBins2(i),:,aoi)),'Color',reds(i,:));
end
line([-200,10],[mTheta,mTheta],'Color',[0 0 0],'LineStyle','-','LineWidth',2);
line([0,0],[0,mTheta + 50],'Color',[0 0 0],'LineStyle','--','LineWidth',1);

% Set axis
set(gca,'XLim',[-50 10],...
        'XTick',[0],...
        'YLim',[0 mTheta + 50],...
        'YTick',[0 mTheta]);


% Measured threshold vs RT
p(2,4).select();hold on

for i = 1:length(iBins2)
   hP = plot(stats.thresVsRtPoly1_W(aoi).dataX(iBins2(i)),stats.thresVsRtPoly1_W(aoi).dataY(iBins2(i)),'ro');%'MarkerFaceColor',reds(i,:),'MarkerEdgeColor','none','LineStyle','none');
   set(hP,'MarkerFaceColor',reds(i,:),'MarkerEdgeColor','none','LineStyle','none');
end
line([0,1500],[mTheta,mTheta],'Color',[0 0 0],'LineStyle','-','LineWidth',2);

% Set axis
set(gca,'XLim',[0 500],...
        'XTick',[0],...
        'YLim',[0 mTheta + 50],...
        'YTick',[0 mTheta]);
     

%% 3. Deterministic model, rV = 1, pN = 0;
job.sigmaXi = 0;
job.rV = 1;
job.pN = 0;
job.nAT = 10;

[nSes,nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation,affTime,effTime,pN,dMeth,tag,rngID] = epu_check_inputs(job);

clear rt activation v theta iAT

[rt,activation,v,theta,iAT] = ...
epu_sim(nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation, ...
affTime,effTime,pN,dMeth);
         
%% Get session statistics of behavior and brain-behavior relationships
stats = epu_session_statistics(rt,activation,iAT,job,settings);

% Settings
iTrial = int32(linspace(0,nSim,11));
iBins1 = [2,10];
iBins2 = [5:5:45];
iTrial = iTrial(iBins1);
reds = [linspace(1,1,length(iBins2)+1)',linspace(0,1,length(iBins2)+1)',linspace(0,1,length(iBins2)+1)'];

% Sort RTs
sortedRT = sortrows([[1:nSim]',rt],2);


p(3,1).select(); hold on;

% Get trajectories
aniTraj = squeeze(activation(sortedRT(iTrial(1),1),ani,1:1500));
aoiTraj = squeeze(activation(sortedRT(iTrial(1),1),aoi,1:1500));

% Plottrajectories
plot(aniTraj','Color',[.8 .8 .8],'LineStyle','-','LineWidth',1);
plot(aoiTraj','Color',[1 0 0],'LineStyle','-','LineWidth',1);
line([0,1500],[mTheta,mTheta],'Color',[0 0 0],'LineStyle','-','LineWidth',2);
line([sortedRT(iTrial(1),2),sortedRT(iTrial(1),2)],[0,mTheta + 50],'Color',[0 0 0],'LineStyle','--','LineWidth',1);

% Set axis
set(gca,'XLim',[0 1500],...
        'XTick',[0],...
        'YLim',[0 mTheta + 50],...
        'YTick',[0 mTheta]);


% Slow trial     
p(3,2).select(); hold on;
     

% Get trajectories
aniTraj = squeeze(activation(sortedRT(iTrial(2),1),ani,1:1500));
aoiTraj = squeeze(activation(sortedRT(iTrial(2),1),aoi,1:1500));

% Plottrajectories
plot(aniTraj','Color',[.8 .8 .8],'LineStyle','-','LineWidth',1);
plot(aoiTraj','Color',[1 0 0],'LineStyle','-','LineWidth',1);
line([0,1500],[mTheta,mTheta],'Color',[0 0 0],'LineStyle','-','LineWidth',2);
line([sortedRT(iTrial(2),2),sortedRT(iTrial(2),2)],[0,mTheta + 50],'Color',[0 0 0],'LineStyle','--','LineWidth',1);

% Set axis
set(gca,'XLim',[0 1500],...
        'XTick',[0],...
        'YLim',[0 mTheta + 50],...
        'YTick',[0 mTheta]);
     
% RT-aligned trajectories     
p(4,1).select(); hold on;



hP = patch([-20 -10 -10 -20],[0,0,mTheta + 50,mTheta + 50],'k');
set(hP,'FaceColor',[.8 .8 .8],'EdgeColor','none');
for i = 1:length(iBins2)
   plot(-200:1:10,squeeze(stats.binnedTrajectories(iBins2(i),:,aoi)),'Color',reds(i,:));
end
line([-200,10],[mTheta,mTheta],'Color',[0 0 0],'LineStyle','-','LineWidth',2);
line([0,0],[0,mTheta + 50],'Color',[0 0 0],'LineStyle','--','LineWidth',1);

% Set axis
set(gca,'XLim',[-50 10],...
        'XTick',[0],...
        'YLim',[0 mTheta + 50],...
        'YTick',[0 mTheta]);


% Measured threshold vs RT
p(4,2).select();hold on

for i = 1:length(iBins2)
   hP = plot(stats.thresVsRtPoly1_W(aoi).dataX(iBins2(i)),stats.thresVsRtPoly1_W(aoi).dataY(iBins2(i)),'ro');%'MarkerFaceColor',reds(i,:),'MarkerEdgeColor','none','LineStyle','none');
   set(hP,'MarkerFaceColor',reds(i,:),'MarkerEdgeColor','none','LineStyle','none');
end
line([0,1500],[mTheta,mTheta],'Color',[0 0 0],'LineStyle','-','LineWidth',2);

% Set axis
set(gca,'XLim',[0 500],...
        'XTick',[0],...
        'YLim',[0 mTheta + 50],...
        'YTick',[0 mTheta]);

     

%% 2. Stochastic model, rV = 1, pN = 1;
job.sigmaXi = 0;
job.rV = 1;
job.pN = 1;

[nSes,nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation,affTime,effTime,pN,dMeth,tag,rngID] = epu_check_inputs(job);

[rt,activation,v,theta,iAT] = ...
epu_sim(nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation, ...
affTime,effTime,pN,dMeth);
         
%% Get session statistics of behavior and brain-behavior relationships
stats = epu_session_statistics(rt,activation,iAT,job,settings);

% Settings
iTrial = int32(linspace(0,nSim,11));
iBins1 = [2,10];
iBins2 = [5:5:45];
iTrial = iTrial(iBins1);
reds = [linspace(1,1,length(iBins2)+1)',linspace(0,1,length(iBins2)+1)',linspace(0,1,length(iBins2)+1)'];

% Sort RTs
sortedRT = sortrows([[1:nSim]',rt],2);


p(3,3).select(); hold on;

% Get trajectories
aniTraj = squeeze(activation(sortedRT(iTrial(1),1),ani,1:1500));
aoiTraj = squeeze(activation(sortedRT(iTrial(1),1),aoi,1:1500));

% Plottrajectories
plot(aniTraj','Color',[.8 .8 .8],'LineStyle','-','LineWidth',1);
plot(aoiTraj','Color',[1 0 0],'LineStyle','-','LineWidth',1);
line([0,1500],[mTheta,mTheta],'Color',[0 0 0],'LineStyle','-','LineWidth',2);
line([sortedRT(iTrial(1),2),sortedRT(iTrial(1),2)],[0,mTheta + 50],'Color',[0 0 0],'LineStyle','--','LineWidth',1);

% Set axis
set(gca,'XLim',[0 1500],...
        'XTick',[0],...
        'YLim',[0 mTheta + 50],...
        'YTick',[0 mTheta]);


% Slow trial     
p(3,4).select(); hold on;
     

% Get trajectories
aniTraj = squeeze(activation(sortedRT(iTrial(2),1),ani,1:1500));
aoiTraj = squeeze(activation(sortedRT(iTrial(2),1),aoi,1:1500));

% Plottrajectories
plot(aniTraj','Color',[.8 .8 .8],'LineStyle','-','LineWidth',1);
plot(aoiTraj','Color',[1 0 0],'LineStyle','-','LineWidth',1);
line([0,1500],[mTheta,mTheta],'Color',[0 0 0],'LineStyle','-','LineWidth',2);
line([sortedRT(iTrial(2),2),sortedRT(iTrial(2),2)],[0,mTheta + 50],'Color',[0 0 0],'LineStyle','--','LineWidth',1);

% Set axis
set(gca,'XLim',[0 1500],...
        'XTick',[0],...
        'YLim',[0 mTheta + 50],...
        'YTick',[0 mTheta]);
     
% RT-aligned trajectories     
p(4,3).select(); hold on;

hP = patch([-20 -10 -10 -20],[0,0,mTheta + 50,mTheta + 50],'k');
set(hP,'FaceColor',[.8 .8 .8],'EdgeColor','none');
for i = 1:length(iBins2)
   plot(-200:1:10,squeeze(stats.binnedTrajectories(iBins2(i),:,aoi)),'Color',reds(i,:));
end
line([-200,10],[mTheta,mTheta],'Color',[0 0 0],'LineStyle','-','LineWidth',2);
line([0,0],[0,mTheta + 50],'Color',[0 0 0],'LineStyle','--','LineWidth',1);

% Set axis
set(gca,'XLim',[-50 10],...
        'XTick',[0],...
        'YLim',[0 mTheta + 50],...
        'YTick',[0 mTheta]);


% Measured threshold vs RT
p(4,4).select();hold on

for i = 1:length(iBins2)
   hP = plot(stats.thresVsRtPoly1_W(aoi).dataX(iBins2(i)),stats.thresVsRtPoly1_W(aoi).dataY(iBins2(i)),'ro');%'MarkerFaceColor',reds(i,:),'MarkerEdgeColor','none','LineStyle','none');
   set(hP,'MarkerFaceColor',reds(i,:),'MarkerEdgeColor','none','LineStyle','none');
end
line([0,1500],[mTheta,mTheta],'Color',[0 0 0],'LineStyle','-','LineWidth',2);

% Set axis
set(gca,'XLim',[0 500],...
        'XTick',[0],...
        'YLim',[0 mTheta + 50],...
        'YTick',[0 mTheta]);
         
    