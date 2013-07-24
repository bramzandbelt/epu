
job = epu_sim_master('get_defaults');
job.nSes = 1;
job.nSim = 1;
job.nA = 10;
job.nAT = job.nA;
job.rngID = 1000;
job.sigmaXi = 1;

[nSes,nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,...
   maxActivation,affTime,effTime,pN,dMeth,tag,rngID] = epu_check_inputs(job);

%% PLOT ALL TRIALS, EACH TRAJECTORY SEPARATELY
close all

picDir = '/Users/bram/Documents/EPU/Simulation_2012Aug28/movie/pics/explainParameters/';

% Create figure
figWidth = 500*3.2/3;
figHeight= 500;
figUnit = 'pixels';
figSpecs = {figWidth, figHeight, figUnit};
paperSpecs = {'USLetter','Portrait'};
hFig = set_figure(figSpecs,paperSpecs);

tMax = 1000;

p = panel;
p.pack(3,2);

p(1).margin = [5 0 0 0];
p(2).margin = [5 0 0 0];
p(3).margin = [5 0 0 5];

% Plot background
p(1,1).select();
axis off

p(2,1).select();
hThreshold = line([0 tMax],[mTheta mTheta],'Color','k','LineWidth',2); % Threshold
set(gca,'XLim',[0 tMax],'YLim',[0 mTheta+1],'XTick',[],'YTick',[]);

hYL21 = ylabel('A_1');
set(hYL21,'Units','normalized','Position',[0 .5 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',16,'HorizontalAlignment','right','VerticalAlignment','bottom','Rotation',0);
hThetaLabel = text(0,mTheta,sprintf('\\theta'),'FontSize',18,'Color','k','HorizontalAlignment','right');

p(3,1).select();

hXL31 = xlabel('time from target');
set(hXL31,'Units','normalized','Position',[1 0 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',16,'HorizontalAlignment','right','VerticalAlignment','cap');
hYL31 = ylabel('I_1');
set(hYL31,'Units','normalized','Position',[0 .5 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',16,'HorizontalAlignment','right','VerticalAlignment','bottom','Rotation',0);

warning off

% Plot trials, save figure
for iRV = 0:.1:1
   
   clear epu_n_unit_accumulator_mex
   rng(rngID);
   
   iPN = 0;
   [rt_first,activation,v,theta,iAT] = ...
            epu_sim(nSim,nA,nTP,nAT,mV,sdV,iRV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation, ...
            affTime,effTime,iPN,dMeth);
         
   clear epu_n_unit_accumulator_mex
   rng(rngID);
   
   iPN = 1;
   [rt_last,activation,v,theta,iAT] = ...
            epu_sim(nSim,nA,nTP,nAT,mV,sdV,iRV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation, ...
            affTime,effTime,iPN,dMeth);
   
   % Plot input
   p(3,1).select(); cla; hold on
   for i = 1:nA
      stairs([zeros(1,affTime),v(i).*ones(1,rt_last-affTime),zeros(1,tMax-rt_last-affTime)],'Color',[.5 .5 .5],'LineWidth',1);
   end
   set(gca,'Box','off','XLim',[0 tMax],'YLim',[0 1.2*max(v)],'XTick',[0],'YTick',[]);

   % Plot trajectory
   p(2,1).select(); cla;hold on
   plot(activation(1:9,:)','Color',[.8 .8 .8]);
   plot(activation(10,:)','Color',[1 0 0]);
   plot(mean(activation,1),'Color',[0 0 0]);
   line([0 1000],[100 100],'Color','k','LineWidth',2);
%    line([rt_first rt_first],[0 102],'Color','k','LineStyle','--','LineWidth',1);
%    line([rt_last rt_last],[0 102],'Color','k','LineStyle','--','LineWidth',1);
   line([affTime rt_first],[0 100],'Color',[247 148 30]./255,'LineWidth',2);
   line([affTime rt_last],[0 100],'Color',[247 148 30]./255,'LineWidth',2);
   set(gca,'Box','off','YLim',[0 102],'XLim',[0 1000],'XTick',[],'YTick',[]);
   hYL21 = ylabel('A_1');
set(hYL21,'Units','normalized','Position',[0 .5 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',16,'HorizontalAlignment','right','VerticalAlignment','bottom','Rotation',0);
%    plot([rt_first,rt_last],[100 100],'Marker','v','MarkerSize',10,'LineStyle','none','MarkerFaceColor',[0 174 239]./255,'MarkerEdgeColor','none')
   
   text(1000,50,sprintf('\\rho_v = %.2f',iRV),'FontSize',16,'FontWeight','bold','Color',[247 148 30]./255,'HorizontalAlignment','right');
%    text(double(rt_first),102,'first','FontSize',18,'Color',[0 174 239]./255,'Rotation',45);
%    text(double(rt_last),102,'last','FontSize',18,'Color',[0 174 239]./255,'Rotation',45);
   
   % Plot RT histogram
   p(1,1).select(); hold off
%    N = histc(rt(nSim+1-iSim:nSim),rtEdges);
%    bar(rtEdges,N,'histc');
% 
%    hBar = findobj(gca,'Type','patch');
%    set(hBar,'FaceColor',[0 0 0],'EdgeColor',[0 0 0]);
%    set(gca,'XLim',[0 tMax],'YLim',[0 35],'XTick',[],'YTick',[]);
%    text(1/2*tMax,0.5*NMax,'RT','FontSize',12,'Color',[0 0 0]);
   axis off

   p.export(fullfile(picDir,sprintf('redundantAccumulatorTrial_rV%.3d.png',100*iRV)),'-pA5','-a0.8');
      
end

%% PLOT ALL TRIALS, EACH TRAJECTORY SEPARATELY - TERMINATION RULE
close all

picDir = '/Users/bram/Documents/EPU/Simulation_2012Aug28/movie/pics/explainParameters/';

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
p(2).pack('h',2);

% Plot background
p(1,1).select();
hThreshold = line([0 tMax],[mTheta mTheta],'Color','k','LineWidth',2); % Threshold
set(gca,'XLim',[0 tMax],'YLim',[0 2*mTheta],'XTick',[],'YTick',[]);

hYL21 = ylabel('A_1');
set(hYL21,'Units','normalized','Position',[0 .75 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',16,'HorizontalAlignment','right','VerticalAlignment','bottom','Rotation',0);
hThetaLabel = text(0,mTheta,sprintf('\\theta'),'FontSize',18,'Color','k','HorizontalAlignment','right');

p(2,1).select();

hXL31 = xlabel('time from target');
set(hXL31,'Units','normalized','Position',[1 0 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',16,'HorizontalAlignment','right','VerticalAlignment','cap');
hYL31 = ylabel('I_1');
set(hYL31,'Units','normalized','Position',[0 .5 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',16,'HorizontalAlignment','right','VerticalAlignment','bottom','Rotation',0);

warning off

iRV = 0;

% Plot trials, save figure
for iPN = [0:1:10]/10
   
   clear epu_n_unit_accumulator_mex
   rng(rngID);
   
   [rt,activation,v,theta,iAT] = ...
            epu_sim(nSim,nA,nTP,nAT,mV,sdV,iRV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation, ...
            affTime,effTime,iPN,dMeth);
   
   % Plot input
   p(2,1).select(); cla; hold on
   for i = 1:nA
      stairs([zeros(1,affTime),v(i).*ones(1,rt-affTime),zeros(1,tMax-rt-affTime)],'Color',[.5 .5 .5],'LineWidth',1);
   end
   set(gca,'Box','off','XLim',[0 tMax],'YLim',[0 1.2*max(v)],'XTick',[0],'YTick',[]);

   % Plot trajectory
   p(1,1).select(); cla;hold on
   plot(activation(1:9,:)','Color',[.8 .8 .8]);
   plot(activation(10,:)','Color',[1 0 0]);
   plot(rt-effTime,activation(10,int32(rt-effTime)),'r.','MarkerSize',20);
   plot(mean(activation,1),'Color',[0 0 0]);
   line([0 1000],[100 100],'Color','k','LineWidth',2);
   line([rt rt],[0 102],'Color','k','LineStyle','--','LineWidth',1);
   set(gca,'Box','off','YLim',[0 200],'XLim',[0 1000],'XTick',[],'YTick',[]);
   hYL21 = ylabel('A_1');
   set(hYL21,'Units','normalized','Position',[0 .75 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',16,'HorizontalAlignment','right','VerticalAlignment','bottom','Rotation',0);
   plot([rt],[100],'Marker','v','MarkerSize',10,'LineStyle','none','MarkerFaceColor',[0 174 239]./255,'MarkerEdgeColor','none')
   hThetaLabel = text(0,mTheta,sprintf('\\theta'),'FontSize',18,'Color','k','HorizontalAlignment','right');
   
   if iPN == 0
      text(1000,50,sprintf('p_N = first'),'FontSize',16,'FontWeight','bold','Color',[0 174 239]./255,'HorizontalAlignment','right');
   elseif iPN == 1
      text(1000,50,sprintf('p_N = last'),'FontSize',16,'FontWeight','bold','Color',[0 174 239]./255,'HorizontalAlignment','right');
   else
      text(1000,50,sprintf('p_N = %.d%%',100*iPN),'FontSize',16,'FontWeight','bold','Color',[0 174 239]./255,'HorizontalAlignment','right');
   end
   picName = sprintf('redundantAccumulatorTrial_pN%.3d_measureThreshold.png',100*iPN);
%    text(double(rt_first),102,'first','FontSize',18,'Color',[0 174 239]./255,'Rotation',45);
%    text(double(rt_last),102,'last','FontSize',18,'Color',[0 174 239]./255,'Rotation',45);
   
   p.export(fullfile(picDir,picName),'-pA5','-a0.8');
   
   if iPN == 0.5
      
      dMeth = 2;
      clear epu_n_unit_accumulator_mex
      rng(rngID);

      [rt,activation,v,theta,iAT] = ...
               epu_sim(nSim,nA,nTP,nAT,mV,sdV,iRV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation, ...
               affTime,effTime,iPN,dMeth);

      % Plot input
      p(2,1).select(); cla; hold on
      for i = 1:nA
         stairs([zeros(1,affTime),v(i).*ones(1,rt-affTime),zeros(1,tMax-rt-affTime)],'Color',[.5 .5 .5],'LineWidth',1);
      end
      set(gca,'Box','off','XLim',[0 tMax],'YLim',[0 1.2*max(v)],'XTick',[0],'YTick',[]);

      % Plot trajectory
      p(1,1).select(); cla; hold on
      plot(activation(1:9,:)','Color',[.8 .8 .8]);
      plot(activation(10,:)','Color',[1 0 0]);
      plot(rt-effTime,activation(10,int32(rt-effTime)),'r.','MarkerSize',20);
      plot(mean(activation,1),'Color',[0 0 0]);
      line([0 1000],[100 100],'Color','k','LineWidth',2);
      line([rt rt],[0 102],'Color','k','LineStyle','--','LineWidth',1);
      set(gca,'Box','off','YLim',[0 200],'XLim',[0 1000],'XTick',[],'YTick',[]);
      hYL21 = ylabel('A_1');
      set(hYL21,'Units','normalized','Position',[0 .75 0],'FontName','Helvetica','FontAngle','normal','FontWeight','normal','FontSize',16,'HorizontalAlignment','right','VerticalAlignment','bottom','Rotation',0);
      plot([rt],[100],'Marker','v','MarkerSize',10,'LineStyle','none','MarkerFaceColor',[0 174 239]./255,'MarkerEdgeColor','none')
      hThetaLabel = text(0,mTheta,sprintf('\\theta'),'FontSize',18,'Color','k','HorizontalAlignment','right');
      text(1000,50,sprintf('p_N = mean'),'FontSize',16,'FontWeight','bold','Color',[0 174 239]./255,'HorizontalAlignment','right');
      picName = sprintf('redundantAccumulatorTrial_pN050_mean_measureThreshold');
   %    text(double(rt_first),102,'first','FontSize',18,'Color',[0 174 239]./255,'Rotation',45);
   %    text(double(rt_last),102,'last','FontSize',18,'Color',[0 174 239]./255,'Rotation',45);

    	p.export(fullfile(picDir,picName),'-pA5','-a0.8');
      
      dMeth = 1;
   
   end
   
end