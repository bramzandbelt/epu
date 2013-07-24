function [binStats,whichBin] = bztbx_binstats(type,X,Y,classifier,statistic)

% DESCRIPTION
% Provides descriptive statistics for binned data
%
% INPUTS
% type          - 'edges' or 'minBinSize'
% X             - vector based on which bins are created
% Y             - vector for which statistic should be computed. Should have
%               equal dimensions as X
% classifier    - if type is 'edges', classifier are the bin edges
%                 if type is 'minBinSize', classifier is the minimum size of the
%                 bin
% statistic     - 'mean', 'median','std'
%
% OUTPUTS
% binStats      for each bin, a descriptive is provided
%
%
% Example: 
% [binStats,whichBin] = bztbx_binstats('edges',X,Y,quantile(X,[0 1/3 2/3 1]),'mean');
% [binStats,whichBin] = bztbx_binstats('minBinSize',X,Y,10,'mean');
%
% Bram Zandbelt - July 2011

% Function for binned data

% Based on Matlab tutorial video: http://blogs.mathworks.com/videos/2009/01/07/binning-data-in-matlab/

switch lower(type)
   case 'edges'
      binEdges = classifier;
      [h,whichBin] = histc(X,binEdges);
      
      numBins = numel(binEdges) - 1;
      binStats = nan(numBins,1);

      for i = 1:numBins
          binMembers = Y(whichBin == i);
          switch statistic
              case 'mean'
                  binStats(i) = mean(binMembers);
              case 'median'
                  binStats(i) = median(binMembers);
              case 'std'
                  binStats(i) = std(binMembers);
          end
      end
      
   case 'minbinsize'
      % Sort Y based on X
      XY = sortrows([X,Y],1);
      
      % Compute block sizes
      minBinSize = classifier;
      nBlocks = floor(length(X)./minBinSize);
      blockSizes = [minBinSize.*ones(nBlocks-1,1);length(X)-(nBlocks-1).*minBinSize];
      
      % Divide into cells
      YCell = mat2cell(XY(:,2:end),blockSizes,ones(1,size(Y,2)));
      
      % Compute statistic
      switch statistic
        case 'mean'
            binStats = cellfun(@nanmean,YCell);
        case 'median'
            binStats = cellfun(@nanmedian,YCell);
        case 'std'
            binStats = cellfun(@nanstd,YCell);
    end
end