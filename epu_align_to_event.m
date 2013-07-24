function alignedArray = epu_align_to_event(rt,outputTimeFrame,minTrialTime,trajectories) %#codegen
%
% Usage alignedArray = align_to_rt(rt,outputTimeFrame,minTrialTime,trajectories)
% rt                 - scalar, response time
% outputTimeFrame    - 1x2 vector containing the time frame for which to plot
%                    data
% minTrialTime       - scalar, the time (in ms) for the first data point in input array
% trajectories       - 1xN vector containing activation trajectory for this trial
%
% Based on Mathew Nelson's ADAlignTrials
%
% Bram Zandbelt, November 2011

% Handling input arguments
if nargin<4 
   error(['Current number of input arguments is ' num2str(nargin) '. At least 4 arguments are needed.']);
end

% Round data
rt=round(rt);     
outputTimeFrame=round(outputTimeFrame);   
minTrialTime=round(minTrialTime);

inputTimeFrame = [minTrialTime,minTrialTime+size(trajectories,2)-1];
timeFrameInterest = rt+outputTimeFrame;
absTimeFrame = [min([inputTimeFrame,timeFrameInterest]),max([inputTimeFrame,timeFrameInterest])];
absNSamples = diff(absTimeFrame)+1;

t=repmat(absTimeFrame(1):1:absTimeFrame(2),1,1)-repmat(rt,1,absNSamples);

currentArray = trajectories;
if min(absTimeFrame) < min(inputTimeFrame)
   currentArray = [nan(1,min(inputTimeFrame)-min(absTimeFrame)),currentArray];
end

if max(absTimeFrame) > max(inputTimeFrame)
   currentArray = [currentArray,nan(1,max(absTimeFrame)-max(inputTimeFrame))];
end

currentArray = currentArray';
t = t';

alignedArray = reshape(currentArray( t>=outputTimeFrame(1) & t<=outputTimeFrame(2) ),diff(outputTimeFrame)+1,1)';

 
 