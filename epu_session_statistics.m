function [stats,varargout] = epu_session_statistics(varargin)
% 
%
%
% EXAMPLE USAGE
% Pre-allocate stats structure based on job structure
% stats = epu_session_statistics('pre-allocate',job,settings);
% 
% Compute descriptive statistics and curve fits
% stats(iSes) = epu_session_statistics(rt,activation,iAT,job,settings);
%
% Compute descriptive statistics and curve fits + get computed thresholds and
% rates
% [stats,trajectories,thresholds,rates,onsetTimes] = epu_session_statistics('alldata',rt,activation,iAT,job,settings);

warning off

%% 1. Inputs
if ischar(varargin{1})
   switch lower(varargin{1})
      case 'pre-allocate'
         job = varargin{2};
         settings = varargin{3};
         structSize = job.nSes;
      case 'alldata'
         rt = varargin{2};
         activation = varargin{3};
         iAT = varargin{4};
         job = varargin{5};
         settings = varargin{6};
         structSize = 1;
   end
else
   rt = varargin{1};
   activation = varargin{2};
   iAT = varargin{3};
   job = varargin{4};
   settings = varargin{5};
   structSize = 1;
end

%% 2. Initiate stats structure
nQntls = numel(settings.statistics.qntls);
nDensityBinsRt = (job.nTP-job.affTime)/settings.statistics.densityBinSizeRt;
nDensityBinsAct = settings.statistics.nDensityBinsAct;

nTrajectoryWindow = numel(colon(settings.statistics.outputTimeFrameBnds(1),settings.statistics.outputTimeFrameBnds(2)));
nBrainBehaviorBins = settings.statistics.nBrainBehaviorBins;
minTrialsWoodmanBin = settings.statistics.minTrialsWoodmanBin;

rtStruct(1,1) = struct( 'mean',nan(1,1),...
                        'median',nan(1,1),...
                        'std',nan(1,1),...
                        'cov',nan(1,1),...
                        'iqr',nan(1,1),...
                        'range',nan(1,1),...
                        'skewness',nan(1,1),...
                        'kurtosis',nan(1,1),...
                        'edfX',nan(1,job.nSim),...
                        'edfY',nan(1,job.nSim),...
                        'quantileX',nan(1,nQntls),...
                        'quantileY',nan(1,nQntls),...
                        'histX',nan(1,nDensityBinsRt),...
                        'histY',nan(1,nDensityBinsRt),...
                        'kernelX',nan(1,nDensityBinsRt),...
                        'kernelY',nan(1,nDensityBinsRt));

actStruct = repmat(struct(  'mean',nan(1,1),...
                            'median',nan(1,1),...
                            'std',nan(1,1),...
                            'cov',nan(1,1),...
                            'iqr',nan(1,1),...
                            'range',nan(1,1),...
                            'skewness',nan(1,1),...
                            'kurtosis',nan(1,1),...
                            'edfX',nan(1,job.nSim),...
                            'edfY',nan(1,job.nSim),...
                            'quantileX',nan(1,nQntls),...
                            'quantileY',nan(1,nQntls),...
                            'histX',nan(1,nDensityBinsAct),...
                            'histY',nan(1,nDensityBinsAct),...
                            'kernelX',nan(1,nDensityBinsAct),...
                            'kernelY',nan(1,nDensityBinsAct)),1,job.nAT);
                     
% actStruct(1,job.nAT) = repmat(struct(  'mean',nan(1,1),...
%                                        'median',nan(1,1),...
%                                        'std',nan(1,1),...
%                                        'cov',nan(1,1),...
%                                        'iqr',nan(1,1),...
%                                        'range',nan(1,1),...
%                                        'skewness',nan(1,1),...
%                                        'kurtosis',nan(1,1),...
%                                        'edfX',nan(1,job.nSim),...
%                                        'edfY',nan(1,job.nSim),...
%                                        'quantileX',nan(1,nQntls),...
%                                        'quantileY',nan(1,nQntls),...
%                                        'histX',nan(1,nDensityBinsAct),...
%                                        'histY',nan(1,nDensityBinsAct),...
%                                        'kernelX',nan(1,nDensityBinsAct),...
%                                        'kernelY',nan(1,nDensityBinsAct)),1,job.nAT);

curveFitStruct_H = repmat(struct( 'dataX',nan(1,nBrainBehaviorBins),...
                                           'dataY',nan(1,nBrainBehaviorBins),...
                                           'params',nan(1,2),...
                                           'paramsCI',nan(2,2),...
                                           'paramsSign',nan(1,2),...
                                           'rmse',nan(1,1),...
                                           'rmseCoV',nan(1,1),...
                                           'rSquare',nan(1,1),...
                                           'fitSuccess',nan(1,1),...
                                           'fitObject',struct),1,job.nAT);

% curveFitStruct_H(1,job.nAT) = repmat(struct( 'dataX',nan(1,job.nSim./nBrainBehaviorBins),...
%                                            'dataY',nan(1,job.nSim./nBrainBehaviorBins),...
%                                            'params',nan(1,2),...
%                                            'paramsCI',nan(2,2),...
%                                            'paramsSign',nan(1,2),...
%                                            'rmse',nan(1,1),...
%                                            'rmseCoV',nan(1,1),...
%                                            'rSquare',nan(1,1),...
%                                            'fitSuccess',nan(1,1),...
%                                            'fitObject',struct),1,job.nAT);
                                        

curveFitStruct_W = repmat(struct( 'dataX',nan(1,job.nSim./minTrialsWoodmanBin),...
                                           'dataY',nan(1,job.nSim./minTrialsWoodmanBin),...
                                           'params',nan(1,2),...
                                           'paramsCI',nan(2,2),...
                                           'paramsSign',nan(1,2),...
                                           'rmse',nan(1,1),...
                                           'rmseCoV',nan(1,1),...
                                           'rSquare',nan(1,1),...
                                           'fitSuccess',nan(1,1),...
                                           'fitObject',struct),1,job.nAT);                                        

% curveFitStruct_W(1,job.nAT) = repmat(struct( 'dataX',nan(1,job.nSim./minTrialsWoodmanBin),...
%                                            'dataY',nan(1,job.nSim./minTrialsWoodmanBin),...
%                                            'params',nan(1,2),...
%                                            'paramsCI',nan(2,2),...
%                                            'paramsSign',nan(1,2),...
%                                            'rmse',nan(1,1),...
%                                            'rmseCoV',nan(1,1),...
%                                            'rSquare',nan(1,1),...
%                                            'fitSuccess',nan(1,1),...
%                                            'fitObject',struct),1,job.nAT);

stats = repmat(struct( 'nRecorded',nan(1,1),...
                        'iAT',nan(1,job.nAT),...
                        'rt',rtStruct,...
                        'threshold',actStruct,...
                        'rate',actStruct,...
                        'trajectory',nan(1,nTrajectoryWindow,job.nAT),...
                        'binnedTrajectories',nan(job.nSim./minTrialsWoodmanBin,nTrajectoryWindow,job.nAT),...
                        'thresVsRtPoly1_H',curveFitStruct_H,...
                        'rateVsRtPoly1_H',curveFitStruct_H,...
                        'rateVsRtPower1_H',curveFitStruct_H,...
                        'rateVsRtRat01_H',curveFitStruct_H,...
                        'thresVsRtPoly1_W',curveFitStruct_W,...
                        'rateVsRtPoly1_W',curveFitStruct_W,...
                        'rateVsRtPower1_W',curveFitStruct_W,...
                        'rateVsRtRat01_W',curveFitStruct_W,...
                        'allTrajectories',cell(1,1)),structSize,1);

% Return if epu_session_stats was called for pre-allocation only
if ischar(varargin{1}) % Pre-allocate
   switch lower(varargin{1})
      case 'pre-allocate'
         return
   end
end

%% 3. Pre-processing of data

% Assign variables based on job and settings
nSim = job.nSim;
nAT = job.nAT;
nTP = job.nTP;
nBrainBehaviorBins = settings.statistics.nBrainBehaviorBins;
outputTimeFrameBnds = settings.statistics.outputTimeFrameBnds;
fitTypePoly1 = settings.statistics.fitTypePoly1;
fitTypePower1 = settings.statistics.fitTypePower1;
fitTypeRat01 = settings.statistics.fitTypeRat01;
fitOptionsPoly1 = settings.statistics.fitOptionsPoly1;
fitOptionsPower1 = settings.statistics.fitOptionsPower1;
fitOptionsRat01 = settings.statistics.fitOptionsRat01;

% Convert input variables to double precision
rt = double(rt);
activation = double(activation);

% Identify and count trials in which RT was recorded
iRecorded = ~isnan(rt);
nRecorded = numel(find(iRecorded));
try
   stats.nRecorded = nRecorded;
catch
   disp('bla');
end

% Replace NaN RTs (not recorded RTs because critical accumulators had not
% reached threshold yet) by maximum RT that can be recorded (i.e. nTP).
% rt(isnan(rt)) = nTP;

% Convert activation variable to cell array
if numel(size(activation)) == 2 % If activation is 2D
   activation = mat2cell(activation,ones(nSim,1),size(activation,2));
elseif numel(size(activation)) == 3  % If activation is 3D
   activation = mat2cell(activation,ones(nSim,1),ones(nAT,1),size(activation,3));
   activation = cellfun(@(x) squeeze(x)',activation,'UniformOutput',0);
end

% Identify accumulators for which trajectories are sampled
stats.iAT = iAT;

% Predefine variables for trajectory
rtRounded = round(rt);
trajectoryWindow = colon(outputTimeFrameBnds(1),outputTimeFrameBnds(2));
nTrajectoryWindow = numel(trajectoryWindow);
trajectoryWindowCell = mat2cell(repmat(trajectoryWindow,nSim,1),ones(nSim,1),numel(trajectoryWindow));
trajectory = cell(nSim,nAT);
if nAT > 1
   stats.trajectory = nan(1,nTrajectoryWindow,nAT);
else
   stats.trajectory = nan(1,nTrajectoryWindow);
end

% Predefine variables for threshold
thresholdWindow = find(trajectoryWindow >= -job.effTime-5 & trajectoryWindow <= -job.effTime+5);
thresholdWindowCell = mat2cell(repmat(thresholdWindow,nSim,1),ones(nSim,1),numel(thresholdWindow));
threshold = nan(nSim,nAT);

% Predefine variables for threshold computations
halfThresholdWindowSize = 5; % in milliseconds: e.g. measure between 20 and 10 ms before saccade if job.effTime = 15 (Purcell et al. 2012);
iInterp1 = cell(nSim,1);
interp1XCell = cell(nSim,1);
interp1XICell = cell(nSim,1);
interp1YCell = cell(nSim,1);

% These are the X vectors for interp 1
iInterp1(iRecorded) = cellfun(@(w,x,y,z) find(w >= floor(x-round(x)-y-1)-z & w <= ceil(x-round(x)-y-1)+z),...
                                                   trajectoryWindowCell(iRecorded),...
                                                   num2cell(rt(iRecorded)),...
                                                   num2cell(repmat(job.effTime,length(rt(iRecorded)),1)),...
                                                   num2cell(repmat(halfThresholdWindowSize,length(rt(iRecorded)),1)),...
                                                   'UniformOutput',0);

interp1XCell(iRecorded) = cellfun(@(x,y) y(x),iInterp1(iRecorded),trajectoryWindowCell(iRecorded),'UniformOutput',0);

% These are the XI vectors for interp1
interp1XICell(iRecorded) = cellfun(@(x,y) x-round(x)-y-1-halfThresholdWindowSize:1:x-round(x)-y-1+halfThresholdWindowSize,num2cell(rt(iRecorded)),num2cell(repmat(job.effTime,length(rt(iRecorded)),1)),'UniformOutput',0);

% Predefine variables for rate
slidingWindowWidth = 20;
slidingWindowWidthCell = num2cell(repmat(slidingWindowWidth,nSim,1));
onsetTimes = nan(nSim,nAT);
rate = nan(nSim,nAT);

for iA = 1:nAT 

   %% Compute RT aligned activation trajectories
   %% N.B. There may be some jitter in trajectories, due to threshold crossing
   %% between integers
   trajectory(iRecorded,iA) = cellfun(@(w,x,y,z) epu_align_to_event_mex(w,x,y,z), ...
                           num2cell(rtRounded(iRecorded)),...                                  % RT
                           repmat({outputTimeFrameBnds},nRecorded,1),...      % Output time frame bounds
                           num2cell(zeros(nRecorded,1)),...                   % Time fo first data point in array (in this case t = 0)
                           activation(iRecorded,iA),'UniformOutput',0);             % Activation
   
   % Compute mean trajectory across simulations
   stats.trajectory(1,:,iA) = nanmean(cell2mat(trajectory(iRecorded,iA)),1);
   
   % Compute mean binned trajectories across simulations
   rtForBinnedTrajectories = [rt(iRecorded);nan(nSim-nRecorded,1)];
   trajectoriesForBinnedTrajectories = [cell2mat(trajectory(iRecorded,iA));nan(nSim-nRecorded,nTrajectoryWindow)];
   
   tmp = woodman_binning([rtForBinnedTrajectories,trajectoriesForBinnedTrajectories],minTrialsWoodmanBin,1,1);
   stats.binnedTrajectories(:,:,iA) = tmp(:,2:end);
   
   %% Compute measured threshold
   
   
   % These are the Y vectors for interp1
   interp1YCell(iRecorded) = cellfun(@(x,y) y(x),iInterp1(iRecorded),trajectory(iRecorded,iA),'UniformOutput',0);
   
   % Now do the interpolation
   activationAroundThreshold(iRecorded) = cellfun(@(x,y,z) interp1(x,y,z), interp1XCell(iRecorded),interp1YCell(iRecorded),interp1XICell(iRecorded),'UniformOutput',0);
   
   threshold(iRecorded,iA) = cellfun(@nanmean,activationAroundThreshold(iRecorded));
   
%    threshold(iRecorded,iA) = cell2mat(cellfun(@(x,y) nanmean(x(y)),trajectory(iRecorded,iA),thresholdWindowCell(iRecorded),'UniformOutput',0));
   

   % Compute measure rate
   % Definition: Slope coefficient of least-squares linear regression line fit to
   % activity from onset of activation trajectory to 10 ms presaccade

   % N.B. Schall lab approach (e.g. Woodman et al. 2008; Pouget et al. 2011;
   % Purcell et al.) of using sliding window with correlation coefficient
   % does not work, because activation level at baseline is zero, resulting
   % in NaN correlations. Therefore, a sliding window algorithm is used that
   % detects changes in the slope of trajectory.

   % Identify onset of accumulation
   tOnset = cellfun(@(x,y,z) epu_compute_trajectory_onset_mex(x,double(y),z),trajectoryWindowCell(iRecorded),trajectory(iRecorded,iA),slidingWindowWidthCell(iRecorded),'UniformOutput',0);
   iEmptyOnset = cellfun(@(x) isempty(x),tOnset); % Identify empty cells
   
   if any(iEmptyOnset)
      tOnset(cellfun(@(x) isempty(x),tOnset)) = {-11};
   end
   
   tOnset = cell2mat(cellfun(@(x) x(1),tOnset,'UniformOutput',0)); % Sometimes, two onsets are returned
   tOnset(tOnset >= -10) = -11; % To calculate rate, a vector of at least two data points is needed
   onsetTimes(iRecorded,iA) = tOnset;
   tOnset = num2cell(tOnset);
   
   
   
   rateWindowCell = cell(nSim,1);
   rateWindowCell(iRecorded) = cellfun(@(x,y) find(x >= y & x <= -10),trajectoryWindowCell(iRecorded),tOnset,'UniformOutput',0);
   
   rateFit = cellfun(@(x,y,z) regress(y(z)',[ones(length(x(z)),1) x(z)']),trajectoryWindowCell(iRecorded),trajectory(iRecorded,iA),rateWindowCell(iRecorded),'UniformOutput',0);
   rate(iRecorded,iA) = cell2mat(cellfun(@(x) x(2),rateFit,'UniformOutput',0)); 
   
end

stats.allTrajectories = trajectory;

%% Compute descriptive statistics for RT, threshold, and rate

% RT
stats.rt = compute_descriptive_statistics('rt',rt,job,settings);

for iA = 1:nAT
   % Threshold
   stats.threshold(iA) = compute_descriptive_statistics('threshold',threshold(:,iA),job,settings);

   % Rate
   stats.rate(iA) = compute_descriptive_statistics('rate',rate(:,iA),job,settings);
end

%% Compute threshold-RT and rate-RT relationships according to Hanes & Schall (1996) and Woodman et al. (2008) methods

% Hanes & Schall (1996) method
for iA = 1:nAT
   
   % Vincentize RT, threshold, and rate, based on RT
   binStats_H = vincentile([rt,threshold(:,iA),rate(:,iA)],nBrainBehaviorBins,1);
   binStats_W = woodman_binning([rt,threshold(:,iA),rate(:,iA)],minTrialsWoodmanBin,1);
   
   % Threshold vs. RT - first-order polynomial (fitObject(x) = p1*x + p2)
   stats.thresVsRtPoly1_H(iA) = compute_curve_fit(binStats_H(:,1),binStats_H(:,2),fitTypePoly1,fitOptionsPoly1,settings);
   stats.thresVsRtPoly1_W(iA) = compute_curve_fit(binStats_W(:,1),binStats_W(:,2),fitTypePoly1,fitOptionsPoly1,settings);
   
   % Rate vs. RT - first-order polynomial (fitObject(x) = p1*x + p2)
   stats.rateVsRtPoly1_H(iA) = compute_curve_fit(binStats_H(:,1),binStats_H(:,3),fitTypePoly1,fitOptionsPoly1,settings);
   stats.rateVsRtPoly1_W(iA) = compute_curve_fit(binStats_W(:,1),binStats_W(:,3),fitTypePoly1,fitOptionsPoly1,settings);
   
   % Rate vs. RT - one-term power series (fitObject(x) = a*x^b)
   stats.rateVsRtPower1_H(iA) = compute_curve_fit(binStats_H(:,1),binStats_H(:,3),fitTypePower1,fitOptionsPower1,settings);
   stats.rateVsRtPower1_W(iA) = compute_curve_fit(binStats_W(:,1),binStats_W(:,3),fitTypePower1,fitOptionsPower1,settings);
   
   % Rate vs. RT - rational function with 0-degree numerator and 1st-degree 
   % denominator (fitObject(x) = (p1) / (x + q1))
   stats.rateVsRtRat01_H(iA) = compute_curve_fit(binStats_H(:,1),binStats_H(:,3),fitTypeRat01,fitOptionsRat01,settings);
   stats.rateVsRtRat01_W(iA) = compute_curve_fit(binStats_W(:,1),binStats_W(:,3),fitTypeRat01,fitOptionsRat01,settings);
end


if ischar(varargin{1})
   switch lower(varargin{1})
      case 'alldata'
         varargout{1} = trajectory;
         varargout{2} = threshold;
         varargout{3} = rate;
         varargout{4} = onsetTimes;
   end
end

function S = compute_descriptive_statistics(varType,V,job,settings)
% V         - variable for which to compute descriptives
% job       - job structure containing info about simulation
% settings  - settings structure, containing info about simulation settings

%%
% One way of characterizing a random variable is by estimating point estimators
% (describing parameters of the distribution it was sampled from) and function
% estimators (specificying the functional form of the distribution). 

qntls = settings.statistics.qntls;

switch lower(varType)
   case 'rt'
      binSize = settings.statistics.densityBinSizeRt;
      binCenters = job.affTime+0.5*binSize:binSize:job.nTP;
   case 'threshold'
      binSize = settings.statistics.densityBinSizeThreshold;
      binCenters = 0:binSize:settings.statistics.nDensityBinsAct*binSize-1;
   case 'rate'
      binSize = settings.statistics.densityBinSizeRate;
      binCenters = 0:binSize:settings.statistics.nDensityBinsAct*binSize-0.1;
end

% Point estimators of central tendency
   S.mean = nanmean(V);                % Mean
   S.median = nanmedian(V);            % Median
% Point estimators of spread
   S.std = nanstd(V);                  % Standard deviation
   S.cov = nanstd(V)./nanmean(V);      % Coefficient of variation
   S.iqr = iqr(V);                     % Interquartile range
   S.range = range(V);                 % Range
% Point estimators of shape
   S.skewness = skewness(V);           % Skewness
   S.kurtosis = kurtosis(V);           % Kurtosis
% Function estimators - distribution (CDF)
   S.edfX = sort(V)';                  % Empirical distribution function
   S.edfY = mtb_edf(sort(V),sort(V))';
   for iQ = 1:length(qntls)         % Quantiles, looked up in EDF
      if qntls(iQ) <= max(S.edfY(:))
         S.quantileX(iQ) = S.edfX(find(S.edfY >= qntls(iQ),1,'first'));
      else
         S.quantileX(iQ) = NaN;
      end
   end
   S.quantileY = qntls;
% Function estimators - density (PDF)
   S.histX = binCenters;               % Histogram
   S.histY = hist(V,binCenters);
   S.kernelX = binCenters;             % Gaussian kernel
   S.kernelY = mtb_gaussian_kernel(binCenters,sort(V))';
% Function estimators - survival (to be implemented)
% Function estimators - hazard (to be implemented)

%% Distribution fitting (to be implemented)
% Another way of characterizing a random variable is to use explicit theoretical 
% distribution functions to describe location, spread, and shape of empirical
% data.

% Stats of interest for fitting
   % Sum of squared errors
   % Fisher z-transformed explained variance (R^2)
   % Root mean squared error
   % Coefficient of variation of root mean squared error
   % Log-likelihood
   % Akaike information criterion
   % Bayes information criterion

end

function S = compute_curve_fit(X,Y,fitTyp,fitOpt,settings)
   
   rtBinLimit = settings.statistics.rtBinLimit;
   iSelectedBin = X <= rtBinLimit;
   ciType = settings.statistics.ciType;
   
   [fitObject,GoF,output] = fit(X(iSelectedBin),Y(iSelectedBin),fitTyp,fitOpt); % fitTypePoly1 = fittype('poly1'); fitOptionsPoly1= fitoptions('poly1');
   
   S.dataX = X';
   S.dataY = Y';
   S.params = coeffvalues(fitObject);
   S.paramsCI = confint(fitObject,ciType/100);
   S.paramsSign = ci_sign(confint(fitObject,ciType/100));
   S.rmse = GoF.rmse;
   S.rmseCoV = GoF.rmse./nanmean(Y(iSelectedBin));
   S.rSquare = GoF.rsquare;
   S.fitSuccess = output.exitflag;
   S.fitObject = fitObject;
   
end

end
