function epu_examine_trajectories

% Settings
nSim = 500;
nA = 10;
nTP = 1500;
nAT = 10;
mV = 1;
sdV = 1;
rV = 0.1;
dt = 10;
sigmaXi = 0.5;
rXi = 0.1;
mTheta = 100;
sdTheta = 0;
maxActivation = Inf;
affTime = 100;
effTime = 10;
pN = 0.5;
dMeth = 1;

% Define job
job.nSes = 1000;
job.nSim = 500;
job.nA = 10;
job.nTP = 1500; 
job.nAT = 10; 
job.mV = 1;   
job.sdV = 1;
job.rV = 0.1;
job.dt = 10;
job.sigmaXi = 0.5;
job.rXi = 0.1;
job.mTheta = 100;   
job.sdTheta = 0;
job.maxActivation = Inf;
job.affTime = 100;    
job.effTime = 10;    
job.pN = 0.5;
job.dMeth = 1;
job.tag = 'schematic';
job.rngID = rng('shuffle');

% Define settings
% 1. General
switch matlabroot % Determine on which system we are running
   case '/Applications/MATLAB_R2011b.app' % local
      settings.general.datetime     = datestr(now);
      settings.general.environment  = 'local';
      
      bzenv('all')
      settings.general.outputPath                    = '/Users/bram/Documents/EPU/Simulation_2012May27/output';
      
      
   otherwise   % ACCRE
      settings.general.datetime     = datestr(now);
      settings.general.environment  = 'ACCRE';
            
      addpath('/home/zandbeb/m-files/epu_sim_20120719/');
      addpath(genpath('/home/zandbeb/m-files/general/'));
      settings.general.outputPath = '/scratch/zandbeb/epu_sim_20120719/output/';
      
end
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


%% Get data
[rt,activation,v,theta,iAT] = epu_sim(nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation,affTime,effTime,pN,dMeth);

%% Get statistics
stats = epu_session_statistics(rt,activation,iAT,job,settings);















% Compute RT aligned trajectories
iRecorded = rt < nTP;
nRecorded = numel(find(iRecorded));
actCell = mat2cell(activation,ones(nSim,1),ones(1,nAT),nTP);
actCell = cellfun(@(x) squeeze(x),actCell,'UniformOutput',0);
trajectories = cellfun(@(w,x,y,z) align_to_event(w,x,y,z), ...
                              num2cell(repmat(round(rt(iRecorded)),1,nAT)),...                                  % RT
                              repmat({[-200 0]},nRecorded,nAT),...       % Output time frame bounds
                              num2cell(zeros(nRecorded,nAT)),...                    % time fo first data point in array (in this case t = 0)
                              actCell(iRecorded,1:nAT),'UniformOutput',0);

figure;
subplot(2,2,1); hold on
% Data from first trial
T1 = squeeze(activation(1,:,:));
% First accumulator in red
plot(T1(1,:)','Color',[1 0 0]);
% Other accumulators in grey
plot(T1(2:end,:)','Color',[0.5 0.5 0.5]);
% Draw line for RT
line([rt(1),rt(1)],[0 1000],'Color','k');
% Draw line for threshold
line([0 1000],[mTheta,mTheta],'Color','k');

subplot(2,2,2);hold on

for j = 1:nAT
   if j == 1
      plot([-200:1:0],nanmean(cell2mat(trajectories(:,j))),'Color',[1 0 0]);
   else
      plot([-200:1:0],nanmean(cell2mat(trajectories(:,j))),'Color',[0.5 0.5 0.5]);
   end
end



%% Repeat, but now with dMeth == 2
dMeth = 2;
nAT = 1;

%% Get data
[rt,activation,v,theta,iAT] = epu_sim(nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation,affTime,effTime,pN,dMeth);

% Compute RT aligned trajectories
iRecorded = rt < nTP;
nRecorded = numel(find(iRecorded));
actCell = mat2cell(activation,ones(nSim,1),nTP);
actCell = cellfun(@(x) squeeze(x),actCell,'UniformOutput',0);
trajectories = cellfun(@(w,x,y,z) align_to_event(w,x,y,z), ...
                              num2cell(repmat(round(rt(iRecorded)),1,nAT)),...                                  % RT
                              repmat({[-200 0]},nRecorded,nAT),...       % Output time frame bounds
                              num2cell(zeros(nRecorded,nAT)),...                    % time fo first data point in array (in this case t = 0)
                              actCell(iRecorded,1:nAT),'UniformOutput',0);
subplot(2,2,1); hold on
% Data from first trial
T1 = squeeze(activation(1,:,:));
% First accumulator in red
plot(T1(1,:)','Color',[0 0 1]);
% Other accumulators in grey
plot(T1(2:end,:)','Color',[0.5 1 0.5]);

subplot(2,2,2);hold on
for j = 1:nAT
   if j == 1
      plot([-200:1:0],nanmean(cell2mat(trajectories(:,j))),'Color',[0 0 1],'LineWidth',3);
   else
      plot([-200:1:0],nanmean(cell2mat(trajectories(:,j))),'Color',[0.5 0.5 0.5]);
   end
end


                           
                           
                           
                           
                           
                           
% trajectories = cellfun(@(w,x,y,z) align_to_event(w,x,y,z), ...
%                               num2cell(round(rt(iRecorded))),...                                  % RT
%                               repmat({[-200 0]},nRecorded,1),...       % Output time frame bounds
%                               num2cell(zeros(nRecorded,1)),...                    % time fo first data point in array (in this case t = 0)
%                               actCell(iRecorded,1),'UniformOutput',0);

[binStats,whichBin] = bin_statistics('edges',rt,rt,quantile(rt,[0:.1:1]),'mean');

% Color map
CT=cbrewer('seq', 'RdPu', 11);
CT = flipud(CT);

figure; hold on;
subplot(1,2,1); hold on

for iBin = 1:10
   % Plot individual trajetcories
   cellfun(@(x) plot([-200:1:0],x,'Color',CT(iBin,:)),trajectories(whichBin(iRecorded) == iBin))
end

for iBin = 1:10
   subplot(1,2,1); hold on;
   % On top, plot average trajectories in same colors but with thicker line
   meanTrajectory = nanmean(cell2mat(trajectories(whichBin(iRecorded) == iBin)),1); 
   plot([-200:1:0],meanTrajectory,'Color',CT(iBin,:),'LineWidth',2);
   axis square;
      
   subplot(1,2,2); hold on
   scatter(binStats(iBin),meanTrajectory(end-10),'Marker','o','MarkerFaceColor',CT(iBin,:),'MarkerEdgeColor','none');
   axis square;
end