function epu_explain_sim_methods(varargin)

%% General settings
bzenv('all')
settings.general.datetime     = datestr(now);
settings.general.environment  = 'local';
settings.general.outputPath                    = '/Users/bram/Documents/EPU/Simulation_2012Aug28/output';
settings.general.fileTimestamp                 = datestr(settings.general.datetime,'yyyymmddTHHMMSS');
settings.general.fractSesToSave               = 0.01; % Fraction of sessions to save individually

% Statistics
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

%% Job structure
job = epu_check_inputs('get_defaults');

% Adjust job structure
job.nSess = 1;
job.nSim = 550;
job.nA = 10;
job.nAT = job.nA;
job.nTP = 10000;
job.dt = 1;
job.rV = .5;
job.effTime = 15;
job.pN = 1;
job.rngID = rng(1000);

% Get job struct fields in workspace
[nSes,nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,...
maxActivation,affTime,effTime,pN,dMeth,tag,rngID] = epu_check_inputs(job);

%% Run simulation
[rt_pN100,activation_pN100,v_pN100,theta_pN100,iAT_pN100,elapsedTime_pN100] = ...
  epu_sim(nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation,...
  affTime,effTime,pN,dMeth);

% Remove trials without RT (this is for plotting purposes only!)
iRec = find(~isnan(rt_pN100));
rt_pN100 = rt_pN100(iRec);
activation_pN100 = activation_pN100(iRec,:,:);
v_pN100 = v_pN100(iRec);

% Remove trailing trials (cut down to 500)
rt_pN100 = rt_pN100(1:500);
activation_pN100 = activation_pN100(1:500,:,:);
v_pN100 = v_pN100(1:500);

% Set nSim and job.nSim back to 500
job.nSim = 500;
nSim = 500;

%% Get descriptive statistics, trajectories, thresholds, and rates
[stats_pN100,trajectories_pN100,thresholds_pN100,rates_pN100,onsetTimes_pN100] = epu_session_statistics('alldata',rt_pN100,activation_pN100,iAT_pN100,job,settings);

%% "Randomly" selected accumulator-of-interest, trial-of-interest
aoi = 2; % Accumulator of interest
toi = 67; % Trial of interest
iRec = find(~isnan(rt_pN100));
nRec = numel(iRec);
sortedData_pN100 = sortrows([rt_pN100(iRec),thresholds_pN100(iRec),rates_pN100(iRec)],1);

%% RUN SIMULATION AGAIN, BUT NOW WITH rV = .9

%% Job structure
job = epu_check_inputs('get_defaults');

% Adjust job structure
job.nSess = 1;
job.nSim = 550;
job.nA = 10;
job.nAT = job.nA;
job.nTP = 10000;
job.dt = 1;
job.rV = .99;
job.effTime = 15;
job.pN = 1;
job.rngID = rng(1000);

% Get job struct fields in workspace
[nSes,nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,...
maxActivation,affTime,effTime,pN,dMeth,tag,rngID] = epu_check_inputs(job);

%% Run simulation
[rt_rV099,activation_rV099,v_rV099,theta_rV099,iAT_rV099,elapsedTime_rV099] = ...
  epu_sim(nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation,...
  affTime,effTime,pN,dMeth);

% Remove trials without RT (this is for plotting purposes only!)
iRec = find(~isnan(rt_rV099));
rt_rV099 = rt_rV099(iRec);
activation_rV099 = activation_rV099(iRec,:,:);
v_rV099 = v_rV099(iRec);

% Remove trailing trials (cut down to 500)
rt_rV099 = rt_rV099(1:500);
activation_rV099 = activation_rV099(1:500,:,:);
v_rV099 = v_rV099(1:500);

% Set nSim and job.nSim back to 500
job.nSim = 500;
nSim = 500;

%% Get descriptive statistics, trajectories, thresholds, and rates
[stats_rV099,trajectories_rV099,thresholds_rV099,rates_rV099,onsetTimes_rV099] = epu_session_statistics('alldata',rt_rV099,activation_rV099,iAT_rV099,job,settings);

%% "Randomly" selected accumulator-of-interest, trial-of-interest
aoi = 2; % Accumulator of interest
toi = 67; % Trial of interest
iRec = find(~isnan(rt_rV099));
nRec = numel(iRec);
sortedData_rV099 = sortrows([rt_rV099(iRec),thresholds_rV099(iRec),rates_rV099(iRec)],1);



%% RUN SIMULATION AGAIN, BUT NOW WITH pN = .5

%% Job structure
job = epu_check_inputs('get_defaults');

% Adjust job structure
job.nSess = 1;
job.nSim = 550;
job.nA = 10;
job.nAT = job.nA;
job.nTP = 10000;
job.dt = 1;
job.rV = .5;
job.effTime = 15;
job.pN = .5;
job.rngID = rng(1000);

% Get job struct fields in workspace
[nSes,nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,...
maxActivation,affTime,effTime,pN,dMeth,tag,rngID] = epu_check_inputs(job);

%% Run simulation
[rt,activation,v,theta,iAT,elapsedTime] = ...
  epu_sim(nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation,...
  affTime,effTime,pN,dMeth);

% Remove trials without RT (this is for plotting purposes only!)
iRec = find(~isnan(rt));
rt = rt(iRec);
activation = activation(iRec,:,:);
v = v(iRec);

% Remove trailing trials (cut down to 500)
rt = rt(1:500);
activation = activation(1:500,:,:);
v = v(1:500);

% Set nSim and job.nSim back to 500
job.nSim = 500;
nSim = 500;

%% Get descriptive statistics, trajectories, thresholds, and rates
[stats,trajectories,thresholds,rates,onsetTimes] = epu_session_statistics('alldata',rt,activation,iAT,job,settings);

%% "Randomly" selected accumulator-of-interest, trial-of-interest
aoi = 2; % Accumulator of interest
toi = 67; % Trial of interest
iRec = find(~isnan(rt));
nRec = numel(iRec);
sortedData = sortrows([rt(iRec),thresholds(iRec),rates(iRec)],1);


%% Graphics settings
IDColWidth = 33.7525;

%% Problem Figure
hFig = set_figure({IDColWidth,IDColWidth,'centimeters'},{'A4','landscape'});
   
% Panel settings
p = panel('defer');
p.margin = [15 15 5 5];
p.pack('v',3);
p(1).pack('h',[1/5.8 1.6/5.8 1.6/5.8 1.6/5.8]);
p(2).pack('h',[1/5.8 2.4/5.8 2.4/5.8]);
p(3).pack('h',[1/5.8 2.4/5.8 2.4/5.8]);

% Figure specific settings
% toi = {322,270};
toi = {50,270};
nTPMax = 1500;
xLim = [0 nTPMax];
yLim = [0 102];

% Sample trial, 1 accumulator
p(1,2).select(); hold on;
xData = 1:nTPMax;
yData = squeeze(activation_pN100(toi{1},aoi,1:nTPMax));

% Compute when accumulator crosses threshold
iCross = [find(yData < 100,1,'last'),find(yData > 100,1,'first')];
tCross = interp1([yData(iCross(1)),yData(iCross(2))],[xData(iCross(1)),xData(iCross(2))],mTheta);

% Plot accumulator, RT, and threshold
plot(xData,yData,'Color','r','LineStyle','-','LineWidth',1);
line([tCross + effTime,tCross + effTime],[0, mTheta],'Color','k','LineStyle','--','LineWidth',0.5);
line([xLim(1) xLim(2)],[mTheta, mTheta],'Color','k','LineStyle','-','LineWidth',2);

% Set axis
set(gca,'PlotBoxAspectRatio',[1.6 1 1],...
        'XLim',[xLim(1) xLim(2)], ...
        'XTick',[0],...
        'YLim',[yLim(1) yLim(2)], ...
        'YTick',[]);

% text(diff(xLim)/2,diff(yLim)/2,['Trial = ',num2str(toi{1})]);

% Another sample trial, 1 accumulator
p(1,3).select(); hold on;
xData = 1:nTPMax;
yData = squeeze(activation_pN100(toi{2},aoi,1:nTPMax));

% Compute when accumulator crosses threshold
iCross = [find(yData < 100,1,'last'),find(yData > 100,1,'first')];
tCross = interp1([yData(iCross(1)),yData(iCross(2))],[xData(iCross(1)),xData(iCross(2))],mTheta);

% Plot accumulator, RT, and threshold
plot(xData,yData,'Color','r','LineStyle','-','LineWidth',1);
line([tCross + effTime,tCross + effTime],[0, mTheta],'Color','k','LineStyle','--','LineWidth',0.5);
line([xLim(1) xLim(2)],[mTheta, mTheta],'Color','k','LineStyle','-','LineWidth',2);

% Set axis
set(gca,'PlotBoxAspectRatio',[1.6 1 1],...
        'XLim',[xLim(1) xLim(2)], ...
        'XTick',[0],...
        'YLim',[yLim(1) yLim(2)], ...
        'YTick',[]);

% text(diff(xLim)/2,diff(yLim)/2,['Trial = ',num2str(toi{2})]);

% Average trajectories for fast, intermediate, and slow RTs
% N.B. Different data than for sample trial plots is used; For the sample
% trials, we need all trajectories to reach threshold, but this gives average
% trajectories that are not in line with predictions of fixed threshold
p(1,4).select(); hold on;
xData = colon(settings.statistics.outputTimeFrameBnds(1),settings.statistics.outputTimeFrameBnds(2));
yData1 = nanmean(squeeze(stats.binnedTrajectories(1:10,:,aoi)),1);
yData2 = nanmean(squeeze(stats.binnedTrajectories(10:20,:,aoi)),1);
yData3 = nanmean(squeeze(stats.binnedTrajectories(30:40,:,aoi)),1);

% Plot accumulator, RT, and threshold
plot(xData,yData1,'Color','r','LineStyle','-','LineWidth',1);
plot(xData,yData2,'Color','r','LineStyle','-','LineWidth',1);
plot(xData,yData3,'Color','r','LineStyle','-','LineWidth',1);

line([0 0 ],[0, mTheta],'Color','k','LineStyle','--','LineWidth',0.5);
line([xData(1) xData(end)],[mTheta, mTheta],'Color','k','LineStyle','-','LineWidth',2);

% Set axis
set(gca,'PlotBoxAspectRatio',[1.6 1 1],...
        'XLim',[xData(1) xData(end)], ...
        'XTick',[0],...
        'YLim',[yLim(1) yLim(2)], ...
        'YTick',[]);

% Sample trial, 1 of N accumulators
p(2,2).select(); hold on;
toi = {50,270};
xData = 1:nTPMax;
iRest = 1:nA;iRest(aoi) = [];
yDataAOI = squeeze(activation_pN100(toi{1},aoi,1:nTPMax));
yDataRest = squeeze(activation_pN100(toi{1},iRest,1:nTPMax));

% Plot accumulator, RT, and threshold
plot(yDataRest','Color',[.8 .8 .8],'LineStyle','-','LineWidth',1);
plot(xData,yDataAOI,'Color','r','LineStyle','-','LineWidth',1);
line([xLim(1) xLim(2)],[mTheta, mTheta],'Color','k','LineStyle','-','LineWidth',2);

% Set axis
set(gca,'PlotBoxAspectRatio',[1.6 1 1],...
        'XLim',[xLim(1) xLim(2)], ...
        'XTick',[0],...
        'YLim',[yLim(1) yLim(2)], ...
        'YTick',[]);

% Sample trial, 1 of N accumulators
p(2,3).select(); hold on;
xData = 1:nTPMax;
iRest = 1:nA;iRest(aoi) = [];
yDataAOI = squeeze(activation_pN100(toi{2},aoi,1:nTPMax));
yDataRest = squeeze(activation_pN100(toi{2},iRest,1:nTPMax));

% Plot accumulator, RT, and threshold
plot(yDataRest','Color',[.8 .8 .8],'LineStyle','-','LineWidth',1);
plot(xData,yDataAOI,'Color','r','LineStyle','-','LineWidth',1);
line([xLim(1) xLim(2)],[mTheta, mTheta],'Color','k','LineStyle','-','LineWidth',2);

% Set axis
set(gca,'PlotBoxAspectRatio',[1.6 1 1],...
        'XLim',[xLim(1) xLim(2)], ...
        'XTick',[0],...
        'YLim',[yLim(1) yLim(2)], ...
        'YTick',[]);

     
% Sample trial, 1 of N accumulators

% for v = 1:250
%    toi = {v*2-1,v*2};

% toi = {126,138};
toi = {50,138};
p(3,2).select(); cla; hold on;
xData = 1:nTPMax;
iRest = 1:nA;iRest(aoi) = [];
% yDataAOI = squeeze(activation_rV099(toi{1},aoi,1:nTPMax));
% yDataRest = squeeze(activation_rV099(toi{1},iRest,1:nTPMax));
yDataAOI = squeeze(activation_pN100(toi{1},aoi,1:nTPMax));
yDataRest = squeeze(activation_pN100(toi{1},iRest,1:nTPMax));

% Plot accumulator, RT, and threshold
plot(yDataRest','Color',[.8 .8 .8],'LineStyle','-','LineWidth',1);
plot(xData,yDataAOI,'Color','r','LineStyle','-','LineWidth',1);
line([xLim(1) xLim(2)],[mTheta, mTheta],'Color','k','LineStyle','-','LineWidth',2);

% Set axis
set(gca,'PlotBoxAspectRatio',[1.6 1 1],...
        'XLim',[xLim(1) xLim(2)], ...
        'XTick',[0],...
        'YLim',[yLim(1) yLim(2)], ...
        'YTick',[]);

%      text(diff(xLim)/2,diff(yLim)/2,['Trial = ',num2str(toi{1})]);
     
% Sample trial, 1 of N accumulators
p(3,3).select(); cla; hold on;
xData = 1:nTPMax;
iRest = 1:nA;iRest(aoi) = [];
yDataAOI = squeeze(activation_rV099(toi{2},aoi,1:nTPMax));
yDataRest = squeeze(activation_rV099(toi{2},iRest,1:nTPMax));

% Plot accumulator, RT, and threshold
plot(yDataRest','Color',[.8 .8 .8],'LineStyle','-','LineWidth',1);
plot(xData,yDataAOI,'Color','r','LineStyle','-','LineWidth',1);
line([xLim(1) xLim(2)],[mTheta, mTheta],'Color','k','LineStyle','-','LineWidth',2);

% Set axis
set(gca,'PlotBoxAspectRatio',[1.6 1 1],...
        'XLim',[xLim(1) xLim(2)], ...
        'XTick',[0],...
        'YLim',[yLim(1) yLim(2)], ...
        'YTick',[]);
   
%      text(diff(xLim)/2,diff(yLim)/2,['Trial = ',num2str(toi{2})]);
     
%    p.refresh();
%    pause;
%      
% end
     
% % Average trajectories for fast, intermediate, and slow RTs
% % N.B. Different data than for sample trial plots is used; For the sample
% % trials, we need all trajectories to reach threshold, but this gives average
% % trajectories that are not in line with predictions of fixed threshold
% % N.B.2: this plot is identical to the plot in p(1,4).
% 
% p(2,4).select(); hold on;
% xData = colon(settings.statistics.outputTimeFrameBnds(1),settings.statistics.outputTimeFrameBnds(2));
% yData1 = nanmean(squeeze(stats.binnedTrajectories(1:10,:,aoi)),1);
% yData2 = nanmean(squeeze(stats.binnedTrajectories(10:20,:,aoi)),1);
% yData3 = nanmean(squeeze(stats.binnedTrajectories(30:40,:,aoi)),1);
% 
% % Plot accumulator, RT, and threshold
% plot(xData,yData1,'Color','r','LineStyle','-','LineWidth',1);
% plot(xData,yData2,'Color','r','LineStyle','-','LineWidth',1);
% plot(xData,yData3,'Color','r','LineStyle','-','LineWidth',1);
% line([0 0 ],[0, mTheta],'Color','k','LineStyle','--','LineWidth',0.5);
% line([xData(1) xData(end)],[mTheta, mTheta],'Color','k','LineStyle','-','LineWidth',2);
% 
% % Set axis
% set(gca,'PlotBoxAspectRatio',[1.6 1 1],...
%         'XLim',[xData(1) xData(end)], ...
%         'XTick',[0],...
%         'YLim',[yLim(1) yLim(2)], ...
%         'YTick',[]);


p.refresh();

close all
%% Background Figure - Explaining role of termination rule and rate correlation
hFig = set_figure({IDColWidth,(IDColWidth/1.6),'centimeters'},{'A4','landscape'});
   
% Panel settings
p = panel('defer');
p.margin = [15 15 5 5];
p.pack('v',2);
p(1).pack('h',2);
p(2).pack('h',2);

% Figure specific settings
% toi = {321,221};
toi = {321,204};
nTPMax = 1200;
xLim = [0 nTPMax];
yLim = [0 300];

% Sample trial, 1 of N accumulators
p(1,1).select(); hold on;
xData = 1:nTPMax;
iRest = 1:nA;iRest(aoi) = [];
yDataAOI = squeeze(activation_pN100(toi{1},aoi,1:nTPMax));
yDataRest = squeeze(activation_pN100(toi{1},iRest,1:nTPMax));

% Plot accumulator, RT, and threshold
plot(yDataRest','Color',[.8 .8 .8],'LineStyle','-','LineWidth',1);
plot(xData,yDataAOI,'Color','r','LineStyle','-','LineWidth',1);
line([xLim(1) xLim(2)],[mTheta, mTheta],'Color','k','LineStyle','-','LineWidth',2);



% bli = mat2cell(squeeze(activation(toi{1},:,1:nTPMax)),ones(nA,1),nTPMax);
% bla = cellfun(@(x) find(x > 100,1,'first'),bli,'UniformOutput',0);
% ble = cellfun(@(x) find(x < 100,1,'last'),bli,'UniformOutput',0);


% Set axis
set(gca,'PlotBoxAspectRatio',[1.6 1 1],...
        'XLim',[xLim(1) xLim(2)], ...
        'XTick',[0],...
        'YLim',[yLim(1) yLim(2)], ...
        'YTick',[]);

% Sample trial, 1 of N accumulators
p(1,2).select(); hold on;
xData = 1:nTPMax;
iRest = 1:nA;iRest(aoi) = [];
yDataAOI = squeeze(activation_pN100(toi{2},aoi,1:nTPMax));
yDataRest = squeeze(activation_pN100(toi{2},iRest,1:nTPMax));

% Plot accumulator, RT, and threshold
plot(yDataRest','Color',[.8 .8 .8],'LineStyle','-','LineWidth',1);
plot(xData,yDataAOI,'Color','r','LineStyle','-','LineWidth',1);
line([xLim(1) xLim(2)],[mTheta, mTheta],'Color','k','LineStyle','-','LineWidth',2);

% Set axis
set(gca,'PlotBoxAspectRatio',[1.6 1 1],...
        'XLim',[xLim(1) xLim(2)], ...
        'XTick',[0],...
        'YLim',[yLim(1) yLim(2)], ...
        'YTick',[]);

p.refresh();







%% EPU model parameter cartoon
hFig = set_figure({IDColWidth,(IDColWidth/1.6),'centimeters'},{'A4','landscape'});
   
% Panel settings
p = panel('defer');
p.margin = [0 0 0 0];
p.pack(1);

% Figure specific settings
toi = {50,270};
nTPMax = 1000;
xLim = [0 nTPMax];
yLim = [0 105];

xData = 1:nTPMax;
yData = squeeze(activation_pN100(toi{1},:,1:nTPMax));

% Plot accumulator, RT, and threshold
p(1).select(); hold on;
p(1).margin = [15 15 0 0];
plot(yData','Color',[.8 .8 .8],'LineStyle','-','LineWidth',1);
plot(nanmean(yData,1),'Color',[0 0 0],'LineStyle','-','LineWidth',1);

line([xLim(1) xLim(2)],[mTheta, mTheta],'Color','k','LineStyle','-','LineWidth',2);

% Set axis
set(gca,'PlotBoxAspectRatio',[1.6 1 1],...
        'XLim',[xLim(1) xLim(2)], ...
        'XTick',[0],...
        'YLim',[yLim(1) yLim(2)], ...
        'YTick',[]);
















%% Methods Figure - Sample trial and computation of RT, threshold, and rate
hFig = set_figure({IDColWidth,(IDColWidth/3.2),'centimeters'},{'A4','landscape'});

% Panel settings
p = panel('defer');
p.margin = [15 15 0 0];
p.pack('h',2);
%    p(1).margin = [0 0 0 0];
%    p(2).margin = [0 0 0 0];

% Figure specific settings
toi = 67
xLim = [0 250];
yLim = [0 125];
cmap = othercolor('Mdeepseacolors',64);
cLim = [0 500];

% Sample trial
p(1).select(); hold on
iOtherAccum = 1:size(activation,2);
iOtherAccum(aoi) = [];
plot(squeeze(activation(toi,iOtherAccum,1:xLim(2)))','Color',[.5 .5 .5]);
plot(squeeze(activation(toi,aoi,1:xLim(2)))','Color',[1 0 0]);
plot(nanmean(squeeze(activation(toi,:,1:xLim(2)))),'Color',[0 0 0]);

% Threshold
line([xLim(1),xLim(2)],[100 100],'Color','k','LineWidth',2);

% RT
line([rt(toi),rt(toi)],[yLim(1),yLim(2)],'Color','k','LineStyle','--');

% Mark accumulation onset
tStart = round(rt(toi) + onsetTimes(toi,aoi));
tEnd = round(rt(toi)-15);
yStart = activation(toi,aoi,tStart);
yEnd = activation(toi,aoi,tEnd);
plot([tStart,tEnd],[yStart yEnd],'Color','g','LineStyle','--','Marker','x');

% Box for computation of measured threshold
hP = patch([floor(rt(toi)-20) floor(rt(toi)-10) floor(rt(toi)-10) floor(rt(toi)-20)],[yLim(1) yLim(1) yLim(2) yLim(2)],'g');
set(hP,'FaceColor','none','EdgeColor','m');

% Set legend
hGreen = findobj('Color','g','Type','line');
hGreen = hGreen(1);
hMagenta = findobj('EdgeColor','m','Type','patch');
hMagenta = hMagenta(1);
legend([hGreen,hMagenta],'activation = p1*time + p2','box for computing measured threshold','Location','NorthWest')


% hLeg = findobj(gcf,'Tag','legend');
% set(hLeg(1),'String',{'Threshold = p1*RT + p2','95% CI'});
% set(hLeg(2),'String',{'Rate = q1/(RT + q2)','95% CI'});

% Set axis
set(gca,'PlotBoxAspectRatio',[1.6 1 1],...
        'XLim',[xLim(1) xLim(2)], ...
        'XTick',[0],...
        'YLim',[yLim(1) yLim(2)], ...
        'YTick',[]);


%    text(250,50,['Trial = ',num2str(toi)]);     

% Computation of threshold and rate
p(2).select(); hold on;

% Panel-specific settings
xLim = [-180 0];
yLim = [1 500];

trajMat = cell2mat(trajectories(:,aoi));
imagesc([-200:10],[1:500],trajMat,cLim);
iOtherTrial = 1:500;
iOtherTrial(toi) = [];
plot(onsetTimes(iOtherTrial,aoi),iOtherTrial,'gx');
plot(onsetTimes(toi,aoi),toi,'gx');
colormap(cmap);

% Box for computation of measured threshold
hP = patch([-20 -10 -10 -20],[1 1 500 500],'m');
set(hP,'FaceColor','none','EdgeColor','m');

% Box for current trial
hP = patch([xLim(1) xLim(2) xLim(2) xLim(1)],[toi+2 toi+2 toi-2 toi-2],'c');
set(hP,'FaceColor','none','EdgeColor','c');

% Set axis
set(gca,'PlotBoxAspectRatio',[1.6 1 1],...
        'XLim',[xLim(1) xLim(2)], ...
        'XTick',[-150 -100 -50 -15 0],...
        'XTickLabel','-150|-100|-50|T_r|0',...
        'YLim',[yLim(1) yLim(2)], ...
        'YTick',[]);

axis('ij')


p.refresh();
   


%% Methods Figure - Descriptive statistics for RT-N relationship
% hFig = set_figure({IDColWidth/3,(IDColWidth/2),'centimeters'},{'A4','landscape'});
hFig = set_figure({IDColWidth/2,(IDColWidth/2),'centimeters'},{'A4','landscape'});

% Panel settings
p = panel('defer');
p.margin = [5 0 5 0];
p.pack('v',[.05 .05 -1]);

% Figure specific settings

% Boxplot
p(1).select();
hB = boxplot(rt(iRec),'Color',[0 0 0],'Jitter',0,'Orientation','horizontal','PlotStyle','compact');
delete(findobj('String',{'1'},'Type','text')); % Delete boxplot label on y-axis
set(gca,'XLim',[0 1000],...
        'XTick',[]);
axis off

% Quantiles
p(2).select();
plot(stats.rt.quantileX,zeros(1,length(stats.rt.quantileX)),'k.');
set(gca,'XLim',[0 1000],...
        'XTick',[]);
axis off

% Histogram
p(3).select(); hold on
barRes = 10;
cLim = [0 1000];
% cmap = flipud(othercolor('YlOrRd9',64));
cmap = zeros(64,3);
edges = 0:barRes:1000;
nEdges = numel(edges);
N = histc(rt(iRec),edges);     
hPlot(1) = bar(N);
colormap(cmap);
% hCB = colorbar('Peer',p(3).axis,'Location','SouthOutside');
set(hPlot(1),'XData',edges);
ch = get(hPlot(1),'Children');
fvd = get(ch,'Faces');
fvcd = get(ch,'FaceVertexCData');
% Traverse the Faces array and assign colors to the face-vertex color data as you go:
for j = 1:nEdges
   fvcd(fvd(j,:)) = j;
end
set(ch,'EdgeColor','none','FaceVertexCData',fvcd);
set(gca,'XLim',[0 1000]);

% Set axis
set(gca,'PlotBoxAspectRatio',[1.6 1 1],...
        'XLim',[cLim], ...
        'XTick',unique([cLim(1),cLim(2)]),...     
        'YLim',[0 50], ...
        'YTick',[]);
%         'XTick',unique([cLim(1),0,100,cLim(2)]),...     
     
% Set color bar
% set(hCB,'Box','off',...
%         'Color','none',...
%         'XColor','w',...
%         'XTick',[],...
%         'YColor','w');

p.refresh();

%% Methods Figure - Descriptive statistics for threshold-N relationship
% hFig = set_figure({IDColWidth/3,(IDColWidth/2),'centimeters'},{'A4','landscape'});
hFig = set_figure({IDColWidth/3.2,(IDColWidth/3.2),'centimeters'},{'A4','landscape'});

% Panel settings
p = panel('defer');
p.margin = [5 0 5 0];
p.pack('v',[.05 .05 -1]);

% Figure specific settings

% Boxplot
p(1).select();
hB = boxplot(thresholds(iRec),'Color',[0 0 0],'Jitter',0,'Orientation','horizontal','PlotStyle','compact');
delete(findobj('String',{'1'},'Type','text')); % Delete boxplot label on y-axis
set(gca,'XLim',[0 200],...
        'XTick',[]);
axis off

% Quantiles
p(2).select();
plot(stats.threshold(aoi).quantileX,zeros(1,length(stats.threshold(aoi).quantileX)),'k.');
set(gca,'XLim',[0 200],...
        'XTick',[]);
axis off

% Histogram
p(3).select(); hold on
barRes = 2;
cLim = [0 200];
% cmap = othercolor('Mdeepseacolors',64);
cmap = zeros(64,3);
edges = 0:barRes:500;
nEdges = numel(edges);
N = histc(thresholds(iRec,aoi),edges);     
hPlot(1) = bar(N);
colormap(cmap);
% hCB = colorbar('Peer',p(3).axis,'Location','SouthOutside');
set(hPlot(1),'XData',edges);
ch = get(hPlot(1),'Children');
fvd = get(ch,'Faces');
fvcd = get(ch,'FaceVertexCData');
% Traverse the Faces array and assign colors to the face-vertex color data as you go:
for j = 1:nEdges
   fvcd(fvd(j,:)) = j;
end
set(ch,'EdgeColor','none','FaceVertexCData',fvcd);
set(gca,'XLim',[0 500]);

% Set axis
set(gca,'PlotBoxAspectRatio',[1.6 1 1],...
        'XLim',[cLim], ...
        'XTick',unique([cLim(1),cLim(2)]),...
        'YLim',[0 50], ...
        'YTick',[]);
% 'XTick',unique([cLim(1),0,100,cLim(2)]),...

% % Set color bar
% set(hCB,'Box','off',...
%         'Color','none',...
%         'XColor','w',...
%         'XTick',[],...
%         'YColor','w');

p.refresh();

%% Methods Figure - Descriptive statistics for rate-N relationship
% hFig = set_figure({IDColWidth/3,(IDColWidth/2),'centimeters'},{'A4','landscape'});
hFig = set_figure({IDColWidth/3.2,(IDColWidth/3.2),'centimeters'},{'A4','landscape'});

% Panel settings
p = panel('defer');
p.margin = [5 0 5 0];
p.pack('v',[.05 .05 -1]);

% Figure specific settings

% Boxplot
p(1).select();
hB = boxplot(rates(iRec,aoi),'Color',[0 0 0],'Jitter',0,'Orientation','horizontal','PlotStyle','compact');
delete(findobj('String',{'1'},'Type','text')); % Delete boxplot label on y-axis
set(gca,'XLim',[0 5],...
        'XTick',[]);
axis off

% Quantiles
p(2).select();
plot(stats.rate(aoi).quantileX,zeros(1,length(stats.rate(aoi).quantileX)),'k.');
set(gca,'XLim',[0 5],...
        'XTick',[]);
axis off

% Histogram
p(3).select(); hold on
barRes = .05;
cLim = [0 5];
% cmap = othercolor('Mavocadocolors',64);
cmap = zeros(64,3);
edges = 0:barRes:5;
nEdges = numel(edges);
N = histc(rates(iRec,aoi),edges);     
hPlot(1) = bar(N);
colormap(cmap);
% hCB = colorbar('Peer',p(3).axis,'Location','SouthOutside');
set(hPlot(1),'XData',edges);
ch = get(hPlot(1),'Children');
fvd = get(ch,'Faces');
fvcd = get(ch,'FaceVertexCData');
% Traverse the Faces array and assign colors to the face-vertex color data as you go:
for j = 1:nEdges
   fvcd(fvd(j,:)) = j;
end
set(ch,'EdgeColor','none','FaceVertexCData',fvcd);
set(gca,'XLim',[0 500]);

% Set axis
set(gca,'PlotBoxAspectRatio',[1.6 1 1],...
        'XLim',[cLim], ...
        'XTick',unique([cLim(1),cLim(2)]),...
        'YLim',[0 50], ...
        'YTick',[]);
% 'XTick',unique([cLim(1),0,1,cLim(2)]),...     
     
% % Set color bar
% set(hCB,'Box','off',...
%         'Color','none',...
%         'XColor','w',...
%         'XTick',[],...
%         'YColor','w');

p.refresh();

%% Methods Figure - Descriptive statistics for threshold-RT and rate-RT relationships - sorting dependents by RT
hFig = set_figure({IDColWidth/2,(IDColWidth/2),'centimeters'},{'A4','landscape'});

% Panel settings
p = panel('defer');
p.margin = [5 0 0 0];
p.pack('h',2);
p(1).pack('h',3);
p(1,1).margin = [0 0 0 0];
p(1,2).margin = [0 0 0 0];
p(1,3).margin = [0 0 0 0];
p(2).pack('h',3);
p(2,1).margin = [0 0 0 0];
p(2,2).margin = [0 0 0 0];
p(2,3).margin = [0 0 0 0];

% Figure specific settings
nTrialsBin = settings.statistics.minTrialsWoodmanBin;

% 1. RT
cmap = flipud(othercolor('YlOrRd9',64));
cLim = [0 1000];
% 1.1 Heatmap of unsorted data
p(1,1).select();
imagesc(rt(iRec),cLim);
colormap(cmap);
freezeColors;cbfreeze;
delete(findobj(gcf,'Tag','Colorbar'))
axis off
% 1.2 Heatmap of sorted data
p(2,1).select();
imagesc(sortedData(:,1),cLim);
colormap(cmap);
freezeColors;cbfreeze;
delete(findobj(gcf,'Tag','Colorbar'))
axis off
% Bin edges
xLm = get(gca,'XLim');
x = num2cell(repmat(xLm(1),floor(numel(rt(iRec))./nTrialsBin),1));
y = num2cell(repmat(xLm(2),floor(numel(rt(iRec))./nTrialsBin),1));
z = num2cell([nTrialsBin:nTrialsBin:floor(numel(rt(iRec)))]');
cellfun(@(x,y,z) line([x,y],[z,z],'Color','w','LineStyle',':'),x,y,z,'UniformOutput',0);

% 2. Threshold
cmap = othercolor('Mdeepseacolors',64);
cLim = [0 500];
% 2.1 Heatmap of unsorted data
p(1,2).select();
imagesc(thresholds(iRec,aoi),cLim);
colormap(cmap);
freezeColors;cbfreeze;
delete(findobj(gcf,'Tag','Colorbar'))
axis off
% 2.2 Heatmap of sorted data
p(2,2).select();
imagesc(sortedData(:,2),cLim);
colormap(cmap);
freezeColors;cbfreeze;
delete(findobj(gcf,'Tag','Colorbar'))
axis off
% Bin edges
xLm = get(gca,'XLim');
x = num2cell(repmat(xLm(1),floor(numel(rt(iRec))./nTrialsBin),1));
y = num2cell(repmat(xLm(2),floor(numel(rt(iRec))./nTrialsBin),1));
z = num2cell([nTrialsBin:nTrialsBin:floor(numel(rt(iRec)))]');
cellfun(@(x,y,z) line([x,y],[z,z],'Color','w','LineStyle',':'),x,y,z,'UniformOutput',0);

% 3. Rate
cmap = othercolor('Mavocadocolors',64);
cLim = [0 5];
% 3.1 Heatmap of unsorted data
p(1,3).select();
imagesc(rates(iRec,aoi),cLim);
colormap(cmap);
freezeColors;cbfreeze;
delete(findobj(gcf,'Tag','Colorbar'))
axis off
% 2.3 Heatmap of sorted data
p(2,3).select();
imagesc(sortedData(:,3),cLim);
colormap(cmap);
freezeColors;cbfreeze;
delete(findobj(gcf,'Tag','Colorbar'))
axis off
% Bin edges
xLm = get(gca,'XLim');
x = num2cell(repmat(xLm(1),floor(numel(rt(iRec))./nTrialsBin),1));
y = num2cell(repmat(xLm(2),floor(numel(rt(iRec))./nTrialsBin),1));
z = num2cell([nTrialsBin:nTrialsBin:floor(numel(rt(iRec)))]');
cellfun(@(x,y,z) line([x,y],[z,z],'Color','w','LineStyle',':'),x,y,z,'UniformOutput',0);

% Refresh panel
p.refresh();

%% Methods Figure - Descriptive statistics for threshold-RT and rate-RT relationships - example threshold-RT and rate-RT relationship
hFig = set_figure({IDColWidth,(IDColWidth/1.6),'centimeters'},{'A4','landscape'});

% Panel settings
p = panel('defer');
p.margin = [15 0 50 0];
p.pack('h',2);

% Figure-specific settings
alphaLevel = .95;

% 1. Threshold-RT relationship
p(1).select(); hold on;
dataX = stats.thresVsRtPoly1_W(aoi).dataX;
dataY = stats.thresVsRtPoly1_W(aoi).dataY;
plot(dataX,dataY,'k.');
% plot(stats.thresVsRtPoly1_W(aoi).fitObject,'k-','predobs',alphaLevel);
plot(stats.thresVsRtPoly1_W(aoi).fitObject,'k-','predfunc',alphaLevel);
set(gca,'PlotBoxAspectRatio',[1.6 1 1],...
        'XLim',[0 1000],...
        'YLim',[0 200],...
        'YTick',[0,100,200]);

xlabel('RT (ms)');
ylabel('Threshold (sp s-1)');
          
% 2. Rate-RT relationship
p(2).select(); hold on;
dataX = stats.rateVsRtRat01_W(aoi).dataX;
dataY = stats.rateVsRtRat01_W(aoi).dataY;
plot(dataX,dataY,'k.');
% plot(stats.rateVsRtRat01_W(aoi).fitObject,'k-','predobs',alphaLevel);
plot(stats.rateVsRtRat01_W(aoi).fitObject,'k-','predfunc',alphaLevel);
set(gca,'PlotBoxAspectRatio',[1.6 1 1],...
        'XLim',[0 1000],...
        'YLim',[0 5],...
        'YTick',[0 5]);

% Adjust legends
hLeg = findobj(gcf,'Tag','legend');
set(hLeg(1),'String',{'Rate = q1/(RT + q2)','95% CI'});
set(hLeg(2),'String',{'Threshold = p1*RT + p2','95% CI'});


xlabel('RT (ms)');
ylabel('Rate (sp s-1 ms-1)');

% Refresh panel
p.refresh();

%% Methods Figure - Inferential statistics 
load /Users/bram/Documents/EPU/Simulation_2012Aug28/output/MultiData_nA1_to_1000_sigmaXi050_rXi010_epu_simulation_2012Aug28.mat

%% Methods Figure - Inferential statistics for RT-N relationship
hFig = set_figure({IDColWidth,(IDColWidth/4),'centimeters'},{'A4','landscape'});

% Panel settings
p = panel('defer');
p.margin = [10 10 0 0];
p.pack('h',[1/4 1/4 1/2]);
% p(1).margin = [0 0 0 0];
% p(2).margin = [0 0 0 0];
% p(3).margin = [0 0 0 0];
p(1).pack('v',8);
p(1,1).margin = [0 0 0 0];
p(1,2).margin = [0 0 0 0];
p(1,3).margin = [0 0 0 0];
p(1,4).margin = [0 0 0 0];
p(1,5).margin = [0 0 0 0];
p(1,6).margin = [0 0 0 0];
p(1,7).margin = [0 0 0 0];
p(1,8).margin = [0 0 0 0];
p(3).pack('h',[1/3 2/3]);
p(3,1).pack('v',[1/3 2/3]);
p(3,2).pack('v',[1/3 2/3]);
% p(3,1,1).margin = [0 0 0 0];
% p(3,1,2).margin = [0 0 0 0];
% p(3,2,1).margin = [0 0 0 0];
% p(3,2,2).margin = [0 0 0 0];

% Figure specific settings
iSim = find(simData.rV == .5 & simData.pN == .5);
NLevels = [1 10 20 50 100 200 500 1000];
iRegression = find(NLevels >= 10);

qPlotData = nan(8,5);
medianDistData = nan(1000,8);
iqrDistData = nan(1000,8);

for iPlot = 1:8

   p(1,iPlot).select(); hold on;

   dataX = simData.rt{iSim(iPlot)}.kernelX.mean;
   dataY = simData.rt{iSim(iPlot)}.kernelY.mean;
   ciX = simData.rt{iSim(iPlot)}.kernelX.ci;
   ciY = simData.rt{iSim(iPlot)}.kernelY.ci;
   ciX = [ciX(1,:),fliplr(ciX(2,:))];
   ciY = [ciY(1,:),fliplr(ciY(2,:))];
   qX = simData.rt{iSim(1)}.quantileX.mean;
   qY = interp1(dataX,dataY,qX);

   qPlotData(iPlot,:) = qX;
   medianDistData(:,iPlot) = simData.rt{iSim(iPlot)}.median.data;
   iqrDistData(:,iPlot) = simData.rt{iSim(iPlot)}.iqr.data;
   
   patch(ciX,ciY,[.8 .8 .8],'EdgeColor','none');
   plot(dataX,dataY,'k-');
   plot(qX,zeros(1,length(qX)),'k.','MarkerSize',10);
%    cellfun(@(x,y) line([x x],[0 y],'Color','k','LineStyle','--'),num2cell(qX),num2cell(qY),'UniformOutput',0);


   % Set axis data
   if iPlot <= 7
      set(gca,'Color','none', ...
           'XLim',[100 10000],...
           'XTick',[100 1000 10000],...
           'XTickLabel','',...        
           'XScale','log',...
           'YLim',[0 .01],...
           'YTick',[]);
   else
      set(gca,'Color','none', ...
           'XLim',[100 10000],...
           'XTick',[100 1000 10000],...
           'XScale','log',...
           'YLim',[0 .01],...
           'YTick',[]);
   end
end

p(2).select();hold on
qPlotData = qPlotData';
for iQ = 1:5;
   plot([1 10 20 50 100 200 500 1000],qPlotData(iQ,:),'k.-');
end

% Set axis data
set(gca,'XScale','log',...
        'XLim',[1 1000],...
        'YScale','log',...
        'YLim',[100 10000],...
        'YTick',[100 1000 10000]);



% Matrix to cell transformation
xCell = mat2cell(repmat(NLevels(iRegression),nSes,1),ones(nSes,1),numel(NLevels(iRegression)));
medianDistData = mat2cell(medianDistData(:,iRegression),ones(1000,1),numel(NLevels(iRegression)));
iqrDistData = mat2cell(iqrDistData(:,iRegression),ones(1000,1),numel(NLevels(iRegression)));

% Linear regression location parameter
locRegParams = cellfun(@(a,b) regress(b',[ones(numel(NLevels(iRegression)),1),a']),xCell,medianDistData,'UniformOutput',0);
locRegSlope = cell2mat(cellfun(@(a) a(2),locRegParams,'UniformOutput',0)); % Get slopes

% Linear regression spread parameter
spreadRegParams = cellfun(@(a,b) regress(b',[ones(numel(NLevels(iRegression)),1),a']),xCell,iqrDistData,'UniformOutput',0);
spreadRegSlope = cell2mat(cellfun(@(a) a(2),spreadRegParams,'UniformOutput',0)); % Get slopes

% Plot distribution of regression parameters for location parameter
p(3,1,2).select(); hold on

% Histogram
barRes = .001;
cLim = [-0.05 0.05];
cmap = 0.5*ones(64,3);
edges = -0.05:barRes:0.05;
nEdges = numel(edges);
N = histc(locRegSlope,edges);     
hPlot(1) = bar(N);
colormap(cmap);
set(hPlot(1),'XData',edges);
ch = get(hPlot(1),'Children');
fvd = get(ch,'Faces');
fvcd = get(ch,'FaceVertexCData');
% Traverse the Faces array and assign colors to the face-vertex color data as you go:
for j = 1:nEdges
   fvcd(fvd(j,:)) = j;
end
set(ch,'EdgeColor','none','FaceVertexCData',fvcd);
set(gca,'XLim',[-0.05 0.05]);

% Draw Monte Carlo mean and 95% confidence interval lines
hPlot(2) = line([nanmean(locRegSlope),nanmean(locRegSlope)],[0 80],'Color','k','LineStyle','-');
hPlot(3) = line([prctile(locRegSlope,2.5),prctile(locRegSlope,2.5)],[0 80],'Color','k','LineStyle','--');
hPlot(4) = line([prctile(locRegSlope,97.5),prctile(locRegSlope,97.5)],[0 80],'Color','k','LineStyle','--');

% Set axis data
set(gca,'XLim',[-0.05 0.05],...
        'YLim',[0 80],...
        'YTick',[]);

% Plot distribution of regression parameters for location parameter
p(3,2,1).select(); hold on

% Histogram
barRes = .001;
cLim = [-0.05 0.05];
cmap = 0.5*ones(64,3);
edges = -0.05:barRes:0.05;
nEdges = numel(edges);
N = histc(spreadRegSlope,edges);     
hPlot(1) = bar(N);
colormap(cmap);
set(hPlot(1),'XData',edges);
ch = get(hPlot(1),'Children');
fvd = get(ch,'Faces');
fvcd = get(ch,'FaceVertexCData');
% Traverse the Faces array and assign colors to the face-vertex color data as you go:
for j = 1:nEdges
   fvcd(fvd(j,:)) = j;
end
set(ch,'EdgeColor','none','FaceVertexCData',fvcd);

% Draw Monte Carlo mean and 95% confidence interval lines
hPlot(2) = line([nanmean(spreadRegSlope),nanmean(spreadRegSlope)],[0 80],'Color','k','LineStyle','-');
hPlot(3) = line([prctile(spreadRegSlope,2.5),prctile(spreadRegSlope,2.5)],[0 80],'Color','k','LineStyle','--');
hPlot(4) = line([prctile(spreadRegSlope,97.5),prctile(spreadRegSlope,97.5)],[0 80],'Color','k','LineStyle','--');

% Set axis data
set(gca,'XLim',[-0.05 0.05],...
        'YLim',[0 80],...
        'YTick',[]);

p.refresh();

%% Methods Figure - Inferential statistics for threshold-RT and rate-RT relationships
hFig = set_figure({IDColWidth,(IDColWidth*(2.6/1.6)),'centimeters'},{'A4','landscape'});

% Panel settings
p = panel('defer');
p.margin = [10 0 10 0];
p.pack('v',[.38462 -1]);
p(1).pack('h',2);
p(2).pack('h',2);

% Figure-specific settings
cmap = flipud(othercolor('Mredbluetones',64));
iSes = iSim(2); %(N = 10);

% Histogram
p(1,1).select();
p1ThresVsRt = simData.thresVsRtPoly1_W{iSes}.params.data(:,1);

barRes = .004;
cLim = [-.2 .2];
edges = -.25:barRes:.25;
nEdges = numel(edges);
N = histc(p1ThresVsRt,edges);     
hPlot(1) = bar(N);
colormap(cmap);
hCB = colorbar('Peer',p(1,1).axis,'Location','SouthOutside');
set(hPlot(1),'XData',edges);
ch2 = get(hPlot(1),'Children');
fvd = get(ch2,'Faces');
fvcd = get(ch2,'FaceVertexCData');
% Traverse the Faces array and assign colors to the face-vertex color data as you go:
for j = 1:nEdges
   fvcd(fvd(j,:)) = j;
end
set(ch2,'EdgeColor','none','FaceVertexCData',fvcd);

% Draw Monte Carlo mean and 95% confidence interval lines
hPlot(2) = line([nanmean(p1ThresVsRt),nanmean(p1ThresVsRt)],[0 100],'Color','k','LineStyle','-');
hPlot(3) = line([prctile(p1ThresVsRt,2.5),prctile(p1ThresVsRt,2.5)],[0 100],'Color','k','LineStyle','--');
hPlot(4) = line([prctile(p1ThresVsRt,97.5),prctile(p1ThresVsRt,97.5)],[0 100],'Color','k','LineStyle','--');

% Set legend
legend(hPlot([2,3]),'Monte Carlo mean','Monte Carlo CI','Location','NorthWest');

% Set axis
set(gca,'PlotBoxAspectRatio',[1.6 1 1], ... % Golden ratio
        'XLim',[cLim], ...
        'XTick',[cLim(1),0,cLim(2)],...
        'YLim',[0 100], ...
        'YTick',[]);

% Set color bar
set(hCB,'Box','off',...
        'Color','none',...
        'XColor','w',...
        'XTick',[],...
        'YColor','w');

% Set ylabel
ylabel('Frequency');


p(1,2).select();
p1RateVsRt = simData.rateVsRtRat01_W{iSes}.params.data(:,1);

barRes = 10;
cLim = [-500 500];
edges = -500:barRes:500;
nEdges = numel(edges);
N = histc(p1RateVsRt,edges);     
hPlot(1) = bar(N);
colormap(cmap);
hCB = colorbar('Peer',p(1,2).axis,'Location','SouthOutside');
set(hPlot(1),'XData',edges);
ch2 = get(hPlot(1),'Children');
fvd = get(ch2,'Faces');
fvcd = get(ch2,'FaceVertexCData');
% Traverse the Faces array and assign colors to the face-vertex color data as you go:
for j = 1:nEdges
   fvcd(fvd(j,:)) = j;
end
set(ch2,'EdgeColor','none','FaceVertexCData',fvcd);

% Draw Monte Carlo mean and 95% confidence interval lines
hPlot(2) = line([nanmean(p1RateVsRt),nanmean(p1RateVsRt)],[0 100],'Color','k','LineStyle','-');
hPlot(3) = line([prctile(p1RateVsRt,2.5),prctile(p1RateVsRt,2.5)],[0 100],'Color','k','LineStyle','--');
hPlot(4) = line([prctile(p1RateVsRt,97.5),prctile(p1RateVsRt,97.5)],[0 100],'Color','k','LineStyle','--');

% Set legend
legend(hPlot([2,3]),'Monte Carlo mean','Monte Carlo CI','Location','NorthWest');

% Set axis
set(gca,'PlotBoxAspectRatio',[1.6 1 1], ... % Golden ratio
        'XLim',[cLim], ...
        'XTick',[cLim(1),0,cLim(2)],...
        'YLim',[0 100], ...
        'YTick',[]);

% Set color bar
set(hCB,'Box','off',...
        'Color','none',...
        'XColor','w',...
        'XTick',[],...
        'YColor','w');

% Set ylabel
ylabel('Frequency');

p.refresh();


p(2,1).select();






















% %% Check out Indexed colors from Mathematica
% 
% hFig = set_figure({33.7525,33.7525,'centimeters'},{'A3','landscape'});
% p = panel;
% p.pack(8,8);
% 
% cnt = 0;
% for i = 1:8
%    for j = 1:8
%       cnt = cnt + 1;
%       if cnt == 63
%          break
%       end
%       p(i,j).select();
%       mapName = sprintf('MIndexed%d',cnt)
%       cmap = othercolor(mapName,64);
%       imagesc(1:64);
%       colormap(cmap);
%       axis tight
%       freezeColors;
%       xl = get(gca,'XLim');
%       yl = get(gca,'YLim');
%       text(xl(1)+0.5.*diff(xl),yl(1)+0.5.*diff(yl),num2str(cnt));
%    end
% end



