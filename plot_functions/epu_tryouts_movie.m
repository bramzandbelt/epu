%% 
%%% ONE ACCUMULATOR
%%%
%%%
%%%
%%%
close all;clear all

job = epu_sim_master('get_defaults');
job.nSes = 1;
job.nSim = 500;
job.nA = 1;
job.nAT = job.nA;
job.rV = .5;
job.rngID = 1000;
job.sigmaXi = 1;

% Get variables
[nSes,nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,...
   maxActivation,affTime,effTime,pN,dMeth,tag,rngID] = epu_check_inputs(job);

% Get data
[rt,activation,v,theta,iAT] = ...
            epu_sim(nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation, ...
            affTime,effTime,pN,dMeth);

rt = round(double(rt));
         
% Compute and define some variables
tMax = quantile(rt,.975);
vMax = max(v);
rtEdges = [0:10:tMax];
vEdges = linspace(0,vMax,100);
NMax = max(histc(rt,rtEdges));
NVMax = max(histc(v,vEdges));

         
picDir = '/Users/bram/Documents/EPU/Simulation_2012Aug28/movie/pics/singleAccumulatorOneTrial/';

%% PLOT 1 TRIAL, EACH DATA POINT SEPARATELY

% Create figure
figWidth = 500*3.2/3;
figHeight= 500;
figUnit = 'pixels';
figSpecs = {figWidth, figHeight, figUnit};
paperSpecs = {'USLetter','Portrait'};
hFig = set_figure(figSpecs,paperSpecs);

p = panel;
p.pack(3,2);

p(1).margin = [5 0 0 0];
p(2).margin = [5 0 0 0];
p(3).margin = [5 0 0 5];

% Plot background
p(1,1).select();
set(gca,'XLim',[0 tMax],'YLim',[0 NMax],'XTick',[],'YTick',[]);

p(2,1).select();
hThreshold = line([0 tMax],[mTheta mTheta],'Color','k','LineWidth',2); % Threshold
set(gca,'XLim',[0 tMax],'YLim',[0 mTheta+1],'XTick',[],'YTick',[]);

hYL21 = ylabel('A_1');
set(hYL21,'Units','normalized','Position',[0 .5 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',16,'HorizontalAlignment','right','VerticalAlignment','bottom','Rotation',0);
hThetaLabel = text(0,mTheta,sprintf('\\theta'),'FontSize',18,'Color','k','HorizontalAlignment','right');

p(3,1).select();
set(gca,'XLim',[0 tMax],'YLim',[0 vMax],'XTick',[],'YTick',[]);

hXL31 = xlabel('time from target');
set(hXL31,'Units','normalized','Position',[1 0 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',16,'HorizontalAlignment','right','VerticalAlignment','cap');
hYL31 = ylabel('I_1');
set(hYL31,'Units','normalized','Position',[0 .5 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',16,'HorizontalAlignment','right','VerticalAlignment','bottom','Rotation',0);

warning off

iTrial = nSim;  % Turns out that last trial has good noise

inputData = [zeros(1,affTime),v(iTrial).*ones(1,rt(iTrial)-affTime),zeros(1,tMax-rt(iTrial)-affTime)]

% Plot one trial
for iTP = [affTime:2:rt(iTrial),rt(iTrial)]
   
   % Plot input
   p(3,1).select(); hold on
   hInput = stairs(inputData(1:iTP),'Color',[.5 .5 .5],'LineWidth',1);
   set(gca,'Box','off','XLim',[0 tMax],'YLim',[0 vMax],'XTick',[0],'YTick',[]);
   set(hXL31,'FontSize',16);
   set(hYL31,'FontSize',16);
   
   % Plot trajectory
   p(2,1).select(); hold on
   set(gca,'Children',sort(get(gca,'Children'))); % Make sure that threshold is always in front
   hPgrey = plot(activation(iTrial,1:iTP),'Color',[.5 .5 .5],'LineWidth',1);
   set(gca,'Box','off','XLim',[0 tMax],'YLim',[0 mTheta+1],'XTick',[],'YTick',[]);
   set(hYL21,'FontSize',16);
   
   p(1,1).select();
   axis off
   
   if iTP == rt(iTrial)
      
      % Mark RT
      p(2,1).select();
      line([rt(iTrial) rt(iTrial)],[0 mTheta],'Color','k','LineStyle','--','LineWidth',1);
      
      % Plot RT histogram
      p(1,1).select(); hold off
      N = histc(rt(iTrial),rtEdges);
      bar(rtEdges,N,'histc');

      hBar = findobj(gca,'Type','patch');
      set(hBar,'FaceColor',[0 0 0],'EdgeColor',[0 0 0]);
      set(gca,'XLim',[0 tMax],'YLim',[0 35],'XTick',[],'YTick',[]);
      axis off
   end
   
   p.export(fullfile(picDir,sprintf('singleAccumulatorOneTrial_%.4d.png',iTP)),'-pA5','-a0.8');
   
end

%% PLOT ALL TRIALS, EACH TRAJECTORY SEPARATELY
close all

picDir = '/Users/bram/Documents/EPU/Simulation_2012Aug28/movie/pics/singleAccumulatorAllTrials/';

% Create figure
figWidth = 500*3.2/3;
figHeight= 500;
figUnit = 'pixels';
figSpecs = {figWidth, figHeight, figUnit};
paperSpecs = {'USLetter','Portrait'};
hFig = set_figure(figSpecs,paperSpecs);

p = panel;
p.pack(3,2);

p(1).margin = [5 0 0 0];
p(2).margin = [5 0 0 0];
p(3).margin = [5 0 0 5];

% Plot background
p(1,1).select();
set(gca,'XLim',[0 tMax],'YLim',[0 NMax],'XTick',[],'YTick',[]);

p(2,1).select();
hThreshold = line([0 tMax],[mTheta mTheta],'Color','k','LineWidth',2); % Threshold
set(gca,'XLim',[0 tMax],'YLim',[0 mTheta+1],'XTick',[],'YTick',[]);

hTrialLabel = text(tMax,0.5*mTheta,sprintf('trial %.3d',0),'FontSize',12,'Color','k','HorizontalAlignment','right');

hYL21 = ylabel('A_1');
set(hYL21,'Units','normalized','Position',[0 .5 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',16,'HorizontalAlignment','right','VerticalAlignment','bottom','Rotation',0);
hThetaLabel = text(0,mTheta,sprintf('\\theta'),'FontSize',18,'Color','k','HorizontalAlignment','right');

p(3,1).select();
set(gca,'XLim',[0 tMax],'YLim',[0 vMax],'XTick',[],'YTick',[]);

hXL31 = xlabel('time from target');
set(hXL31,'Units','normalized','Position',[1 0 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',16,'HorizontalAlignment','right','VerticalAlignment','cap');
hYL31 = ylabel('I_1');
set(hYL31,'Units','normalized','Position',[0 .5 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',16,'HorizontalAlignment','right','VerticalAlignment','bottom','Rotation',0);

warning off

% Plot trials, save figure
for iSim = 1:nSim
   
   if rt(nSim+1-iSim) < tMax
      
      % Plot input
      p(3,1).select(); hold on
      hInput = stairs([zeros(1,affTime),v(nSim+1-iSim).*ones(1,rt(nSim+1-iSim:nSim)-affTime),zeros(1,tMax-rt(nSim+1-iSim:nSim)-affTime)],'Color',[.5 .5 .5],'LineWidth',1);
      set(gca,'Box','off','XLim',[0 tMax],'YLim',[0 vMax],'XTick',[0],'YTick',[]);
      
%       % Plot input histogram
%       p(3,2).select(); hold off
%       NV = histc(v(nSim+1-iSim:nSim),vEdges);
%       hBarV = bar(vEdges,NV,'histc');
%             
%       hVBar = findobj(gca,'Type','patch');
%       set(hVBar,'FaceColor',[0 0 0],'EdgeColor',[0 0 0]);
%       set(gca,'XLim',[0 vMax],'YLim',[0 35],'XTick',[],'YTick',[]);
%       text(vMax,0.5*NVMax,'Rate distribution','FontSize',12,'Color',[0 0 0],'Rotation',-90,'HorizontalAlignment','left');
%       view(90,-90); % Rotate x and y axes
%       axis off
      
      % Plot trajectory
      p(2,1).select(); hold on
      set(gca,'Children',sort(get(gca,'Children'))); % Make sure that threshold is always in front
      hPgrey = plot(activation(nSim+1-iSim,1:tMax),'Color',[.5 .5 .5],'LineWidth',1); % Turns out that last trial has good noise
      set(gca,'Box','off','XLim',[0 tMax],'YLim',[0 mTheta+1],'XTick',[],'YTick',[]);
      set(hTrialLabel,'String',sprintf('trial %.3d',iSim))
      
      % Plot RT histogram
      p(1,1).select(); hold off
      N = histc(rt(nSim+1-iSim:nSim),rtEdges);
      bar(rtEdges,N,'histc');

      hBar = findobj(gca,'Type','patch');
      set(hBar,'FaceColor',[0 0 0],'EdgeColor',[0 0 0]);
      set(gca,'XLim',[0 tMax],'YLim',[0 35],'XTick',[],'YTick',[]);
      text(1/2*tMax,0.5*NMax,'RT','FontSize',12,'Color',[0 0 0]);
      axis off

      p.export(fullfile(picDir,sprintf('singleAccumulatorTrial_%.4d.png',iSim)),'-pA5','-a0.8');
      set(hPgrey,'Color',[.8 .8 .8]);
      set(hInput,'Color',[.8 .8 .8]);
   end
end





%% 
%%% TWO ACCUMULATORS
%%%
%%%
%%%
%%%
clear all;close all;


job = epu_sim_master('get_defaults');
job.nSes = 1;
job.nSim = 500;
job.nA = 1;
job.nAT = job.nA;
job.rV = .5;
job.rngID = 1000;
job.sigmaXi = 1;

% Get variables
[nSes,nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,...
   maxActivation,affTime,effTime,pN,dMeth,tag,rngID] = epu_check_inputs(job);

% Get data
[rt1,activation1,v1,theta1,iAT1] = ...
            epu_sim(nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation, ...
            affTime,effTime,pN,dMeth);
         
[rt2,activation2,v2,theta2,iAT2] = ...
            epu_sim(nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation, ...
            affTime,effTime,pN,dMeth);

rt1 = round(double(rt1));
rt2 = round(double(rt2));

rt = sort([rt1,rt2],2); % Fastest rt wins
rt1(rt1 > rt2) = NaN;
rt2(rt2 > rt1) = NaN;

v = sort([v1,v2],2,'descend'); % Fastest rt wins

% Compute and define some variables
tMax = quantile(rt(:,1),.975);
vMax = max(v(:,1));
rtEdges = [0:10:tMax];
vEdges = linspace(0,vMax,100);
NMax = max(histc(rt(:,1),rtEdges));
NVMax = max(histc(v(:,1),vEdges));

picDir = '/Users/bram/Documents/EPU/Simulation_2012Aug28/movie/pics/TwoAccumulatorsAllTrials/';
   
% Create figure

%% PLOT ONE TRIAL, EACH TIME POINT SEPARATELY
close all

picDir = '/Users/bram/Documents/EPU/Simulation_2012Aug28/movie/pics/twoAccumulatorsOneTrial/';

% Create figure
figWidth = 500*3.2/3;
figHeight= 500;
figUnit = 'pixels';
figSpecs = {figWidth, figHeight, figUnit};
paperSpecs = {'USLetter','Portrait'};
hFig = set_figure(figSpecs,paperSpecs);

p = panel;
p.pack(3,2);

p(1).margin = [5 0 0 0];
p(2).margin = [5 0 0 0];
p(3).margin = [5 0 0 5];

% Plot background
p(1,1).select();
set(gca,'XLim',[0 tMax],'YLim',[0 NMax],'XTick',[],'YTick',[]);
p(1,2).select();
set(gca,'XLim',[0 tMax],'YLim',[0 NMax],'XTick',[],'YTick',[]);

p(2,1).select();
hThreshold = line([0 tMax],[mTheta mTheta],'Color','k','LineWidth',2); % Threshold
set(gca,'XLim',[0 tMax],'YLim',[0 mTheta+1],'XTick',[],'YTick',[]);

hYL21 = ylabel('A_1');
set(hYL21,'Units','normalized','Position',[0 .5 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',16,'HorizontalAlignment','right','VerticalAlignment','bottom','Rotation',0);
hThetaLabel = text(0,mTheta,sprintf('\\theta'),'FontSize',18,'Color','k','HorizontalAlignment','right');

p(2,2).select();
hYL22 = ylabel('A_2');
set(hYL22,'Units','normalized','Position',[0 .5 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',16,'HorizontalAlignment','right','VerticalAlignment','bottom','Rotation',0);

hThreshold = line([0 tMax],[mTheta mTheta],'Color','k','LineWidth',2); % Threshold
set(gca,'XLim',[0 tMax],'YLim',[0 mTheta+1],'XTick',[],'YTick',[]);

p(3,1).select();
set(gca,'XLim',[0 tMax],'YLim',[0 vMax],'XTick',[],'YTick',[]);

hXL31 = xlabel('time from target');
set(hXL31,'Units','normalized','Position',[1 0 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',16,'HorizontalAlignment','right','VerticalAlignment','cap');
hYL31 = ylabel('I_1');
set(hYL31,'Units','normalized','Position',[0 .5 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',16,'HorizontalAlignment','right','VerticalAlignment','bottom','Rotation',0);

p(3,2).select();
set(gca,'XLim',[0 tMax],'YLim',[0 vMax],'XTick',[],'YTick',[]);

hXL32 = xlabel('time from target');
set(hXL32,'Units','normalized','Position',[1 0 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',16,'HorizontalAlignment','right','VerticalAlignment','cap');

hYL32 = ylabel('I_2');
set(hYL32,'Units','normalized','Position',[0 .5 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',16,'HorizontalAlignment','right','VerticalAlignment','bottom','Rotation',0);

warning off

iTrial = nSim;  % Turns out that last trial has good noise

inputData1 = [zeros(1,affTime),v1(iTrial).*ones(1,rt(iTrial)-affTime),zeros(1,tMax-rt(iTrial)-affTime)];
inputData2 = [zeros(1,affTime),v2(iTrial).*ones(1,rt(iTrial)-affTime),zeros(1,tMax-rt(iTrial)-affTime)];

% Plot one trial
for iTP = [affTime:2:rt(iTrial),rt(iTrial)]
   
   % Plot input Accumulator 1
   p(3,1).select(); hold on
   hInput1 = stairs(inputData1(1:iTP),'Color',[.5 .5 .5],'LineWidth',1);
   set(gca,'Box','off','XLim',[0 tMax],'YLim',[0 vMax],'XTick',[0],'YTick',[]);
   set(hXL31,'FontSize',16);
   set(hYL31,'FontSize',16);
   
   % Plot input Accumulator 2
   p(3,2).select(); hold on
   hInput2 = stairs(inputData2(1:iTP),'Color',[.5 .5 .5],'LineWidth',1);
   set(gca,'Box','off','XLim',[0 tMax],'YLim',[0 vMax],'XTick',[0],'YTick',[]);
   set(hXL32,'FontSize',16);
    
   % Plot trajectory Accumulator 1
   p(2,1).select(); hold on
   set(gca,'Children',sort(get(gca,'Children'))); % Make sure that threshold is always in front
   hP1 = plot(activation1(iTrial,1:iTP),'Color',[.5 .5 .5],'LineWidth',1);
   set(gca,'Box','off','XLim',[0 tMax],'YLim',[0 mTheta+1],'XTick',[],'YTick',[]);
   set(hYL21,'FontSize',16);

   % Plot trajectory Accumulator 2
   p(2,2).select(); hold on
   set(gca,'Children',sort(get(gca,'Children'))); % Make sure that threshold is always in front
   hP2 = plot(activation2(iTrial,1:iTP),'Color',[.5 .5 .5],'LineWidth',1);
   set(gca,'Box','off','XLim',[0 tMax],'YLim',[0 mTheta+1],'XTick',[],'YTick',[]);
   
   p(1,1).select();
   axis off
   
   p(1,2).select();
   axis off
   
   if iTP == rt(iTrial)
      
      % Mark RT
      if isnan(rt1(iTrial))
         p(2,2).select();
      else
         p(2,1).select();
      end
      line([rt(iTrial) rt(iTrial)],[0 mTheta],'Color','k','LineStyle','--','LineWidth',1);
      
      % Plot RT histogram
      if isnan(rt1(iTrial))
         p(1,2).select(); hold off
      else
         p(1,1).select(); hold off
      end
      N = histc(rt(iTrial),rtEdges);
      bar(rtEdges,N,'histc');

      hBar = findobj(gca,'Type','patch');
      set(hBar,'FaceColor',[0 0 0],'EdgeColor',[0 0 0]);
      set(gca,'XLim',[0 tMax],'YLim',[0 35],'XTick',[],'YTick',[]);
      axis off
   end
   
   p.export(fullfile(picDir,sprintf('twoAccumulatorsOneTrial_%.4d.png',iTP)),'-pA5','-a0.8');
   
end





%% PLOT ALL TRIALS, EACH TRAJECTORY SEPARATELY
close all

picDir = '/Users/bram/Documents/EPU/Simulation_2012Aug28/movie/pics/singleAccumulatorAllTrials/';

% Create figure
figWidth = 500*3.2/3;
figHeight= 500;
figUnit = 'pixels';
figSpecs = {figWidth, figHeight, figUnit};
paperSpecs = {'USLetter','Portrait'};
hFig = set_figure(figSpecs,paperSpecs);

p = panel;
p.pack(3,2);

p(1).margin = [5 0 0 0];
p(2).margin = [5 0 0 0];
p(3).margin = [5 0 0 5];

% Plot background
p(1,1).select();
set(gca,'XLim',[0 tMax],'YLim',[0 NMax],'XTick',[],'YTick',[]);
p(1,2).select();
set(gca,'XLim',[0 tMax],'YLim',[0 NMax],'XTick',[],'YTick',[]);

p(2,1).select();
hThreshold = line([0 tMax],[mTheta mTheta],'Color','k','LineWidth',2); % Threshold
set(gca,'XLim',[0 tMax],'YLim',[0 mTheta+1],'XTick',[],'YTick',[]);

hTrialLabel1 = text(tMax,0.5*mTheta,sprintf('trial %.3d',0),'FontSize',12,'Color','k','HorizontalAlignment','right');

hYL21 = ylabel('A_1');
set(hYL21,'Units','normalized','Position',[0 .5 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',16,'HorizontalAlignment','right','VerticalAlignment','bottom','Rotation',0);
hThetaLabel = text(0,mTheta,sprintf('\\theta'),'FontSize',18,'Color','k','HorizontalAlignment','right');

p(2,2).select();
hThreshold = line([0 tMax],[mTheta mTheta],'Color','k','LineWidth',2); % Threshold
set(gca,'XLim',[0 tMax],'YLim',[0 mTheta+1],'XTick',[],'YTick',[]);
hTrialLabel2 = text(tMax,0.5*mTheta,sprintf('trial %.3d',0),'FontSize',12,'Color','k','HorizontalAlignment','right');

p(3,1).select();
set(gca,'XLim',[0 tMax],'YLim',[0 vMax],'XTick',[],'YTick',[]);

hXL31 = xlabel('time from target');
set(hXL31,'Units','normalized','Position',[1 0 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',16,'HorizontalAlignment','right','VerticalAlignment','cap');
hYL31 = ylabel('I_1');
set(hYL31,'Units','normalized','Position',[0 .5 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',16,'HorizontalAlignment','right','VerticalAlignment','bottom','Rotation',0);

p(3,2).select();
set(gca,'XLim',[0 tMax],'YLim',[0 vMax],'XTick',[],'YTick',[]);

hXL32 = xlabel('time from target');
set(hXL32,'Units','normalized','Position',[1 0 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',16,'HorizontalAlignment','right','VerticalAlignment','cap');

warning off

% Plot trials, save figure
for iSim = 1:nSim
   
   if rt(nSim+1-iSim) < tMax
      
      % Plot input Accumulator 1
      p(3,1).select(); hold on
      hInput1 = stairs([zeros(1,affTime),v1(nSim+1-iSim).*ones(1,rt(nSim+1-iSim:nSim,1)-affTime),zeros(1,tMax-rt(nSim+1-iSim:nSim,1)-affTime)],'Color',[.5 .5 .5],'LineWidth',1);
      set(gca,'Box','off','XLim',[0 tMax],'YLim',[0 vMax],'XTick',[0],'YTick',[]);
      
      % Plot input Accumulator 2
      p(3,2).select(); hold on
      hInput2 = stairs([zeros(1,affTime),v2(nSim+1-iSim).*ones(1,rt(nSim+1-iSim:nSim,1)-affTime),zeros(1,tMax-rt(nSim+1-iSim:nSim,1)-affTime)],'Color',[.5 .5 .5],'LineWidth',1);
      set(gca,'Box','off','XLim',[0 tMax],'YLim',[0 vMax],'XTick',[0],'YTick',[]);
      
      % Plot trajectory Accumulator 1
      p(2,1).select(); hold on
      set(gca,'Children',sort(get(gca,'Children'))); % Make sure that threshold is always in front
      hP1 = plot(activation1(nSim+1-iSim,1:rt(nSim+1-iSim:nSim,1)),'Color',[.5 .5 .5],'LineWidth',1); % Turns out that last trial has good noise
      set(gca,'Box','off','XLim',[0 tMax],'YLim',[0 mTheta+1],'XTick',[],'YTick',[]);
      set(hTrialLabel1,'String',sprintf('trial %.3d',iSim))
      
      % Plot trajectory Accumulator 2
      p(2,2).select(); hold on
      set(gca,'Children',sort(get(gca,'Children'))); % Make sure that threshold is always in front
      hP2 = plot(activation2(nSim+1-iSim,1:rt(nSim+1-iSim:nSim,1)),'Color',[.5 .5 .5],'LineWidth',1); % Turns out that last trial has good noise
      set(gca,'Box','off','XLim',[0 tMax],'YLim',[0 mTheta+1],'XTick',[],'YTick',[]);
      set(hTrialLabel2,'String',sprintf('trial %.3d',iSim))
      
      % Plot RT histogram Accumulator 1
      p(1,1).select(); hold off
      NRT1 = histc(rt1(nSim+1-iSim:nSim),rtEdges);
      bar(rtEdges,NRT1,'histc');
      
      hBar1 = findobj(gca,'Type','patch');
      set(hBar1,'FaceColor',[0 0 0],'EdgeColor',[0 0 0]);
      set(gca,'XLim',[0 tMax],'YLim',[0 NMax],'XTick',[],'YTick',[]);
      text(1/2*tMax,0.5*NMax,'RT_1','FontSize',12,'Color',[0 0 0]);
      axis off
      
      % Plot RT histogram Accumulator 2
      p(1,2).select(); hold off
      NRT2 = histc(rt2(nSim+1-iSim:nSim),rtEdges);
      bar(rtEdges,NRT2,'histc');
      
      hBar2 = findobj(gca,'Type','patch');
      set(hBar2,'FaceColor',[0 0 0],'EdgeColor',[0 0 0]);
      set(gca,'XLim',[0 tMax],'YLim',[0 NMax],'XTick',[],'YTick',[]);
      text(1/2*tMax,0.5*NMax,'RT_2','FontSize',12,'Color',[0 0 0]);
      axis off
      
      p.export(fullfile(picDir,sprintf('singleAccumulatorTrial_%.4d.png',iSim)),'-pA5','-a0.8');
      set(hP1,'Color',[.8 .8 .8]);
      set(hP2,'Color',[.8 .8 .8]);
      set(hInput1,'Color',[.8 .8 .8]);
      set(hInput2,'Color',[.8 .8 .8]);
   end
end


%% 
%%% 10 REDUNANT ACCUMULATORS - EXPLAIN THRESHOLD VARIATION
%%%
%%%
%%%
%%%
close all;clear all

job = epu_sim_master('get_defaults');
job.nSes = 1;
job.nSim = 500;
job.nA = 10;
job.nAT = job.nA;
job.rV = .5;
job.pN = .5;
job.rngID = 1000;
job.sigmaXi = 1;

settings.general.datetime     = datestr(now);
settings.general.environment  = 'local';
settings.general.outputPath = '/Users/bram/Documents/EPU/Simulation_2012Aug28/movie/pics/explainThresholdVariation/';
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

% Get variables
[nSes,nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,...
   maxActivation,affTime,effTime,pN,dMeth,tag,rngID] = epu_check_inputs(job);

% Get data
[rt,activation,v,theta,iAT] = ...
            epu_sim(nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation, ...
            affTime,effTime,pN,dMeth);

% Get statistics (for measure threshold) for 10th accumulator
[stats,trajectories,thresholds,rates,onsetTimes] = epu_session_statistics('alldata',rt,activation,10,job,settings);
         
rt = round(double(rt));
         
% Compute and define some variables
tMax = quantile(rt,.975);
vMax = max(v(:));
rtEdges = [0:10:tMax];
vEdges = linspace(0,vMax,100);
NMax = max(histc(rt,rtEdges));
NVMax = max(histc(v,vEdges));

measThetaVec = thresholds(:,10);
measThetaMax = round(quantile(measThetaVec,.975)/10)*10;
measThetaEdges = linspace(0,measThetaMax,100);
NmeasThetaMax = max(histc(measThetaVec,measThetaEdges));

%% PLOT ALL TRIALS, EACH TRAJECTORY SEPARATELY
close all

picDir = '/Users/bram/Documents/EPU/Simulation_2012Aug28/movie/pics/explainThresholdVariation/';

% Create figure
figWidth = 500*3.2/3;
figHeight= 500;
figUnit = 'pixels';
figSpecs = {figWidth, figHeight, figUnit};
paperSpecs = {'USLetter','Portrait'};
hFig = set_figure(figSpecs,paperSpecs);

tMax = 1000;

p = panel;
p.pack('v',[2/3 1/3])

p(1).margin = [5 0 0 0];
p(2).margin = [5 0 0 5];

p(1).pack('h',2);
p(1,2).margin = [0 0 0 0];
p(2).pack('h',2);

% Plot background
p(1,1).select();
hThreshold = line([0 tMax],[mTheta mTheta],'Color','k','LineWidth',2); % Threshold
hTrialLabel = text(tMax,0.5*mTheta,sprintf('trial %.3d',0),'FontSize',12,'Color','k','HorizontalAlignment','right');
set(gca,'XLim',[0 tMax],'YLim',[0 2*mTheta],'XTick',[],'YTick',[]);


hYL21 = ylabel('A_1');
set(hYL21,'Units','normalized','Position',[0 .75 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',16,'HorizontalAlignment','right','VerticalAlignment','bottom','Rotation',0);
hThetaLabel = text(0,mTheta,sprintf('\\theta'),'FontSize',18,'Color','k','HorizontalAlignment','right');

p(2,1).select();

hXL31 = xlabel('time from target');
set(hXL31,'Units','normalized','Position',[1 0 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',16,'HorizontalAlignment','right','VerticalAlignment','cap');
hYL31 = ylabel('I_1');
set(hYL31,'Units','normalized','Position',[0 .5 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',16,'HorizontalAlignment','right','VerticalAlignment','bottom','Rotation',0);

p(1,2).select();

warning off

% Plot trials, save figure
for iSim = 1:nSim
   
   if rt(nSim+1-iSim) < tMax
      
      % Plot input
      p(2,1).select(); hold on
      
      for iNA = 1:nA
         hInput = stairs([zeros(1,affTime),v(nSim+1-iSim,iNA).*ones(1,rt(nSim+1-iSim:nSim)-affTime),zeros(1,tMax-rt(nSim+1-iSim:nSim)-affTime)],'Color',[.5 .5 .5],'LineWidth',1);
      end
      set(gca,'Box','off','XLim',[0 tMax],'YLim',[0 vMax],'XTick',[0],'YTick',[]);
      
%       % Plot input histogram
%       p(3,2).select(); hold off
%       NV = histc(v(nSim+1-iSim:nSim),vEdges);
%       hBarV = bar(vEdges,NV,'histc');
%             
%       hVBar = findobj(gca,'Type','patch');
%       set(hVBar,'FaceColor',[0 0 0],'EdgeColor',[0 0 0]);
%       set(gca,'XLim',[0 vMax],'YLim',[0 35],'XTick',[],'YTick',[]);
%       text(vMax,0.5*NVMax,'Rate distribution','FontSize',12,'Color',[0 0 0],'Rotation',-90,'HorizontalAlignment','left');
%       view(90,-90); % Rotate x and y axes
%       axis off
      
      % Plot trajectory
      p(1,1).select(); hold on
      set(gca,'Children',sort(get(gca,'Children'))); % Make sure that threshold is always in front
      hPgrey = plot(squeeze(activation(nSim+1-iSim,1:nA-1,1:tMax))','Color',[.5 .5 .5],'LineWidth',1); % Turns out that last trial has good noise
      hPred = plot(squeeze(activation(nSim+1-iSim,nA,1:tMax))','Color',[1 0 0],'LineWidth',1); % Turns out that last trial has good noise
      hThresRed = plot(rt(nSim+1-iSim)-effTime,activation(nSim+1-iSim,10,int32(rt(nSim+1-iSim)-effTime)),'r.','MarkerSize',20);
      set(gca,'Box','off','XLim',[0 tMax],'YLim',[0 measThetaMax],'XTick',[],'YTick',[]);
      set(hTrialLabel,'String',sprintf('trial %.3d',iSim))
      
      % Plot measured threshold histogram
      p(1,2).select(); hold off
      NmeasTheta = histc(measThetaVec(nSim+1-iSim:nSim),measThetaEdges);
      hBarMeasTheta = bar(measThetaEdges,NmeasTheta,'histc');
      hMeasThetaBar = findobj(gca,'Type','patch');
      set(hMeasThetaBar,'FaceColor',[1 0 0],'EdgeColor',[1 0 0]);
      set(gca,'XLim',[0 measThetaMax],'YLim',[0 NmeasThetaMax],'XTick',[],'YTick',[]);
      text(measThetaMax,0.25*NmeasThetaMax,'Threshold distribution','FontSize',12,'Color',[0 0 0],'Rotation',-90,'HorizontalAlignment','left');
      view(90,-90); % Rotate x and y axes
      axis off
      
%       % Plot RT histogram
%       p(1,1).select(); hold off
%       N = histc(rt(nSim+1-iSim:nSim),rtEdges);
%       bar(rtEdges,N,'histc');
% 
%       hBar = findobj(gca,'Type','patch');
%       set(hBar,'FaceColor',[0 0 0],'EdgeColor',[0 0 0]);
%       set(gca,'XLim',[0 tMax],'YLim',[0 35],'XTick',[],'YTick',[]);
%       text(1/2*tMax,0.5*NMax,'RT','FontSize',12,'Color',[0 0 0]);
%       axis off
      
      p.export(fullfile(picDir,sprintf('singleAccumulatorTrial_%.4d.png',iSim)),'-pA5','-a0.8');
      set(hPgrey,'Color',[.8 .8 .8]);
      set(hPred,'Color',[1 .8 .8]);
      set(hThresRed,'Color',[1 .8 .8]);
      set(hInput,'Color',[.8 .8 .8]);

      

   end
end
