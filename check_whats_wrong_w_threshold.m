function [statsApr13,statsMay01] = check_whats_wrong_w_threshold

cd /Users/bram/Documents/EPU/Simulation_2012May01/m-files;
warning off
job.nS = 500;
job.nA = 10;
job.mR = .75;
job.sR = 1;
job.wnF = 0;
job.mT = 100;
job.sT = 0;
job.t0 = 100;
job.r = .7;
job.q = .7;
job.nTP = 1500;
job.nAT = 1;
job.aLim = 1e6;
job.dMeth = 1;

nS = 500;
nA = 10;
mR = .75;
sR = 1;
wnF = 0;
mT = 100;
sT = 0;
t0 = 100;
r = .7;
q = .7;
nTP = 1500;
nAT = 1;
aLim = 1e6;
dMeth = 1;

settings.tBallistic = 10;
settings.bbBinSize = 50;
settings.outputTimeFrameBnds = [-200 10];
settings.nVincentilesAct = 10;
settings.iSortColumn = 1;

s = rng('shuffle');
rng(s);

[rt,activation,rate,iAT] = epu_sim(nS,nA,mR,sR,wnF,mT,sT,t0,r,q,nTP,nAT,aLim,dMeth);

statsApr13 = doApr13(rt,activation,rate,iAT,job,settings);
statsMay01 = doMay01(rt,activation,rate,iAT,job,settings);

cd /Users/bram/Documents/EPU/Simulation_2012May01/m-files;

% APR 13 CODE
function stats = doApr13(rt,activation,rate,iAT,job,settings);

rmpath(genpath('/Users/bram/Documents/EPU/Simulation_2012May01'));
addpath(genpath('/Users/bram/Documents/EPU/Simulation_2012Apr13'));
cd /Users/bram/Documents/EPU/Simulation_2012Apr13/m-files;

% Only trials in which activation around RT was recorded can be used
% iRecorded = int32(rt)-settings.tBallistic < job.nTP;
iRecorded = ~isnan(rt);
stats.nRecorded = numel(find(iRecorded));

stats.selectedAccums = iAT; % N.B. This is not in the original code!

if stats.nRecorded > 1

   for iAccum = 1:job.nAT 
      
      activation = mat2cell(activation,ones(500,1),1500);

      % Compute threshold (activation 10 ms before RT) per simulation
      threshold = cellfun(@(x,y) x(y),activation(iRecorded,iAccum),num2cell(double(int32(rt(iRecorded))-settings.tBallistic)));

      % Vincentize threshold and rate, based on RT
      V = vincentile([rt(iRecorded),threshold,rate(iRecorded,iAccum)],settings.nVincentilesAct,settings.iSortColumn);
      
      stats.rtBinned = V(:,1);
      stats.thresholdBinned = V(:,2);
      stats.rateBinned = V(:,3);

      % Compute sample trajectory for each simulation
      eventTimes = double(rt(iRecorded));
      allSessTrajectories = cellfun(@(w,x,y,z) align_to_event(w,x,y,z), ...
                              num2cell(eventTimes),...                            % RT
                              repmat({settings.outputTimeFrameBnds},stats.nRecorded,1),...       % Output time frame bounds
                              num2cell(zeros(stats.nRecorded,1)),...                    % time fo first data point in array (in this case t = 0)
                              activation(iRecorded,iAccum),'UniformOutput',0);    % Activation

      % Average trajections across simulations
      stats.rtAlignedTrajectories = nanmean(cell2mat(allSessTrajectories),1);
      
   end
end

% MAY 01 CODE
function stats = doMay01(rt,activation,rate,iAT,job,settings)

rmpath(genpath('/Users/bram/Documents/EPU/Simulation_2012Apr13'));
addpath(genpath('/Users/bram/Documents/EPU/Simulation_2012May01'));
cd /Users/bram/Documents/EPU/Simulation_2012May01/m-files;

iRecorded = int32(rt)-settings.tBallistic < job.nTP & int32(rt)-settings.tBallistic > 0;
stats.nRecorded = numel(find(iRecorded));
stats.selectedAccums = iAT;

if numel(size(activation)) == 2
   activation = mat2cell(activation,ones(job.nS,1),size(activation,2));
elseif numel(size(activation)) > 2
   activation = mat2cell(activation,ones(job.nS,1),ones(job.nAT,1),size(activation,3));
   activation = cellfun(@(x) squeeze(x)',activation,'UniformOutput',0);
end

if stats.nRecorded > 1

   for iAccum = 1:job.nAT 

      % Compute threshold discharge rate (activation settings.tBallistic ms before RT) per simulation
      tAroundThreshold = mat2cell([floor(rt(iRecorded)-settings.tBallistic),ceil(rt(iRecorded)-settings.tBallistic + 0.0001)],ones(numel(find(iRecorded)),1),2); % N.B. 0.0001 is added for the case of exactly rounded RTs
      actAroundThreshold = cellfun(@(x,y) x(y),activation(iRecorded,iAccum,:),tAroundThreshold,'UniformOutput',0);
      tCrossing = num2cell(rt(iRecorded)-settings.tBallistic);
      
      threshold = cellfun(@(x,y,z) interp1(x,y,z),tAroundThreshold,actAroundThreshold,tCrossing);
      
      % Binning of threshold and rate, based on RT
      binStats = bin_statistics('minBinSize',rt(iRecorded),[rt(iRecorded),threshold,rate(iRecorded,iAccum)],settings.bbBinSize,'mean');

      stats.rtBinned(1,1:size(binStats),iAccum) = binStats(:,1);
      stats.thresholdBinned(1,1:size(binStats),iAccum) = binStats(:,2);
      stats.rateBinned(1,1:size(binStats),iAccum) = binStats(:,3);
      
      % Compute sample trajectory for each simulation
      eventTimes = round(double(rt(iRecorded)));
      allSessTrajectories = cellfun(@(w,x,y,z) align_to_event(w,x,y,z), ...
                              num2cell(eventTimes),...                                  % RT
                              repmat({settings.outputTimeFrameBnds},stats.nRecorded,1),...       % Output time frame bounds
                              num2cell(zeros(stats.nRecorded,1)),...                    % time fo first data point in array (in this case t = 0)
                              activation(iRecorded,iAccum),'UniformOutput',0);          % Activation

      % Average trajections across simulations
      stats.rtAlignedTrajectories(1,:,iAccum) = nanmean(cell2mat(allSessTrajectories),1);
   end
end
