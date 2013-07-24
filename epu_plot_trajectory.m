function epu_trajectory_plot

%Parameter settings
nSim = 50;
nA = 10;
nTP = 1500;
nAT = nA;
mV = 1;
sdV = 1;
rV = 0.8;
dt = 1;
sigmaXi = 0.5;
rXi = 0.1;
mTheta = 100;
sdTheta = 0;
maxActivation = 250;
affTime = 100;
effTime = 10;
pN = 0.1;
dMeth = 1;

% Seed random number generator
s = rng('shuffle');
rng(s);

% Simulate trajectories and RT
[rt,activation,v,theta,iAT,] = epu_sim(nSim,nA,nTP,nAT,mV,sdV,rV, ...
                                       dt,sigmaXi,rXi,mTheta,sdTheta, ...
                                       maxActivation,affTime,effTime,pN,dMeth);
                                    


% Set up figure
hFig = set_figure({18,10,'centimeters'},{'USLetter','portrait'})

% Set up panels
p = panel('defer');
p.pack(1,2);

% Plot 'polling' data
thisPanel = p(1,1).select();
plot_data(rt,activation,theta,thisPanel);
title('Polling');
p.refresh();

% Simulate trajectories and RT for pooling
dMeth = 2;

% Seed random number generator
rng(s);
% Simulate trajectories and RT

[rt,activation,v,theta,iAT,] = epu_sim(nSim,nA,nTP,nAT,mV,sdV,rV, ...
                                       dt,sigmaXi,rXi,mTheta,sdTheta, ...
                                       maxActivation,affTime,effTime,pN,dMeth);

% Plot 'pooling' data
thisPanel = p(1,2).select();                                    
plot_data(rt,activation,theta,thisPanel);
title('Pooling');
p.refresh();

function plot_data(rt,activation,theta,thisPanel)

action = 'n';
iSim = 0;
   
while ~strncmp(action,'s',1)
   % Clear axes
   cla(thisPanel); hold on
   
   % Determine the trial for which to plot data
   if strncmp(action,'n',1)
      iSim = iSim + 1;
   elseif strncmp(action,'p',1)
      iSim = iSim - 1;
   end

   if iSim < 1
      iSim = 1;
   elseif iSim > size(activation,1)
      iSim = size(activation,1);
   end
   
   % Patch showing how threshold is defined: 10-20 ms before saccade
   hPatch = patch([rt(iSim)-20 rt(iSim)-10 rt(iSim)-10 rt(iSim)-20],[0 0 150 150],[.8 .8 .8]);
   set(hPatch,'EdgeColor','none')
   
   % Detect onset and draw regression line
   tOnset = epu_compute_trajectory_onset(1:round(floor(rt(iSim))),squeeze(activation(iSim,1,:)),20);
   x = tOnset:floor(rt(iSim))-10;
   x = x(:);
   b = regress(squeeze(activation(iSim,1,x)),[x,ones(size(x,1),1)]);
   plot(x,b(1).*x+b(2),'b-','LineWidth',2);
   
   % Plot activation trajectories of current trial
   hA = plot(squeeze(activation(iSim,:,:))');
   set(hA,'Color',[0 0 0]);
   set(hA(1),'Color','r','LineWidth',2);
   
   if dMeth == 2
      hM = plot(nanmean(squeeze(activation(iSim,:,:))),'Color','k','LineWidth',2); 
   end
   
   % Set plot layout
   set(gca,'XLim',[0 500],'XTick',[0:100:500],...
           'YLim',[0 150],'YTick',[0:50:150]);
   line([0 500],[100,100],'Color',[0 0 0],'LineStyle','--');
   line([rt(iSim),rt(iSim)],[0,150],'Color',[0 0 0],'LineStyle','--');
   
   xlabel('time (ms)');
   ylabel('activation level (sp s-1)');
   
   axis square
            
   % Wait for user input
   action = lower(input('Next trial (N), previous trial (P), or stop (S)?','s'));
   
end

end

end