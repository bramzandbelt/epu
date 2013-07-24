function varargout = align_to_event(eventTimes,outputTimeFrame,minTrialTime,varargin)
%
% Usage alignedArray = align_to_event(eventTimes,outputTimeFrame,minTrialTime,inArray)
% eventTimes         - column vector containing RT data
% outputTimeFrame    - 1x2 vector containing the time frame for which to plot
%                    data
% minTrialTime       - the time (in ms) for the first data point in input array
% varargin           - cell array containing any number of nTrial x nDataPoint
%                    arrays
%
% Based on Mathew Nelson's ADAlignTrials
%
% Bram Zandbelt, November 2011

% Handling input arguments
if nargin<4 
   error(['Current number of input arguments is ' num2str(nargin) '. At least 4 arguments are needed.']);
end

% Round data
eventTimes=round(eventTimes);     
outputTimeFrame=round(outputTimeFrame);   
minTrialTime=round(minTrialTime);

% Transform eventTimes to column vector, if necessary
if size(eventTimes,2)>size(eventTimes,1)
   eventTimes=eventTimes';
end

% Compute some figures
nTrials=length(eventTimes);

% Transform varargin matrix if necessary, so that size is nTrial x nDataPoint
for iArray = 1:numel(varargin)
   if size(varargin{iArray},2) == nTrials
      varargin{iArray} = varargin{iArray}';
   end
end

inputTimeFrame = [minTrialTime,minTrialTime+size(varargin{1},2)-1];
timeFrameInterest = minmax(eventTimes')+outputTimeFrame;
absTimeFrame = minmax([inputTimeFrame,timeFrameInterest]);
absNSamples = diff(absTimeFrame)+1;

t = kron(ones(nTrials,1),[absTimeFrame(1):1:absTimeFrame(2)]) - ...
    kron(ones(1,absNSamples),eventTimes);

% t=repmat([FrontPad:EndPad]',1,nTrials)-repmat(eventTimes,tmpnsamps,1);
% t=repmat([absTimeFrame(1):1:absTimeFrame(2)],nTrials,1)-repmat(eventTimes,1,absNSamples);
 
for iArray = 1:numel(varargin)
   currentArray = varargin{iArray};
   if min(absTimeFrame) < min(inputTimeFrame)
      currentArray = [nan(nTrials,min(inputTimeFrame)-min(absTimeFrame)),currentArray];
   end
   
   if max(absTimeFrame) > max(inputTimeFrame)
      currentArray = [currentArray,nan(nTrials,max(absTimeFrame)-max(inputTimeFrame))];
   end
   
   currentArray = currentArray';
   t = t';
   
   varargout{iArray} = reshape(currentArray( t>=outputTimeFrame(1) & t<=outputTimeFrame(2) ),diff(outputTimeFrame)+1,nTrials)';
end
 
 