function t = epu_compute_trajectory_onset(X,Y,Z) %#codegen
%
% INPUTS
% X      - vector of time points with 1-ms increments (e.g. [-200:1:10])
% Y      - vector of activation trajectory
% Z      - scalar if full width of moving time window
%
% OUTPUT
% t      - trajectory onset (in ms)
%
% Bram Zandbelt, July 2012
%

% OUTPUT
% time from response when trajectory starts

% coder.extrinsic('movingslope');

% Estimate local slope, using sliding window
dVec = movingslope(Y,Z,1,1);
halfWindow = round(median(1:Z));
t = X(find(dVec>0,1) + halfWindow);
