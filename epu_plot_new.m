function epu_plot_new(fileSpecs,dependent,figureSpecs,panelSpecs);
%
% INPUTS
% 
% fileSpecs       - struct with fields
%                   * source, path or dataset variable
%                   * outputDir
%                   * outputFileName
% dependent       - struct with fields
%                   * class, cell array with two elements:
%                     - class (*, see below) 
%                     - subclass (-, see below), N.B. Leave empty if no subclass
%                     - statistic (+, see below)
%                     - sigmaXi (for deterministic vs. stochastic)
%                     - rXi (noise correlation)
%                     - maxActivation (for perfect vs. leaky accumulation)
%                   * plotType, cell array with two elements
%                     - plotType: 'heat', 'line'
%                     - nALevels: double array; for 'heat' this is the levels of
%                   nA for which to show panels, for 'line' this is the level
%                   for which to calculate the linear slope
%                   * colorMap, cell array with two elements:
%                     - map, char or N-by-3 matrix
%                     - limits, 1-by-2 double
%                   * error, cell array with two elements:
%                     - type: 'none','hatch','contour'
%                     - dependent:
%                     - limits: 1-by-2 double
% error           - struct with fields
%                   * class, cell array with two elements:
%                     - class (*, see below) 
%                     - subclass (-, see below)
%                   * criterion, can be char or double, e.g.
%                     - '~= 0'         exclusion criterion
%                     - {'in',90,100}  inclusion interval
%                     - {'out',-2,2}}  exclusion interval
%                   * plotType, cell array with two elements
%                     - plotType: 'hatch', 'contour'
%                     - nALevels: double array; for 'heat' this is the levels of
%
%
%
%
%
% 
%
% EXAMPLE 1
%
% fileSpecs.source = simData;
% fileSpecs.outputDir = pwd;
% fileSpecs.outputFileName = 'test';
%
% dependent.class = {'thresVsRtPoly1','params','mean',0.5,0.1,Inf};
% dependent.plotType = {'heat',10};
% dependent.colorMap = {'bluewhitered',[-.2 .2]};
% dependent.error.class = {'thresVsRtPoly1','signParamsOverall(1)'};
% dependent.error.criterion = {'not',0};
% dependent.error.plotType = {'hatch',0};
%
% figureSpecs.figSpecs = {18,18,'centimeters'};
% figureSpecs.paperSpecs = {'USLetter','portrait'};
% figureSpecs.otherSpecs = {'Helvetica',10};
%
% panelSpecs.title = {'none'};
% panelSpecs.xLabel = {'none'};
% panelSpecs.yLabel = {'none'};
% panelSpecs.colorBar = {'none'};
%
%
% EXAMPLE 2
%
% fileSpecs.source = simData;
% fileSpecs.outputDir = pwd;
% fileSpecs.outputFileName = 'test';
%
% dependent.class = {'rt','median','mean',0.5,0.1,Inf};
% dependent.plotType = {'heat',10};
% dependent.colorMap = {'jet',[100 1000]};
% dependent.error = [];
%
% figureSpecs.figSpecs = {18,18,'centimeters'};
% figureSpecs.paperSpecs = {'USLetter','portrait'};
% figureSpecs.otherSpecs = {'Helvetica',10};
%
% panelSpecs.title = {'none'};
% panelSpecs.xLabel = {'none'};
% panelSpecs.yLabel = {'none'};
% panelSpecs.colorBar = {'none'};
%
% EXAMPLE 3
%
% fileSpecs.source = simData;
% fileSpecs.outputDir = pwd;
% fileSpecs.outputFileName = 'test';
%
% dependent.class = {'rt','quantileX','mean',0.5,0.1,Inf};
% dependent.plotType = {'line',[1,10,20,50,100,200]};
% dependent.colorMap = {'jet',[100 1000]};
% dependent.error = [];
%
% figureSpecs.figSpecs = {18,18,'centimeters'};
% figureSpecs.paperSpecs = {'USLetter','portrait'};
% figureSpecs.otherSpecs = {'Helvetica',10};
%
% panelSpecs.title = {'none'};
% panelSpecs.xLabel = {'none'};
% panelSpecs.yLabel = {'none'};
% panelSpecs.colorBar = {'none'};
%
% epu_plot(fileSpecs,dependent,figureSpecs,panelSpecs);

% figureSpecs     - struct with fields
%                   * figSpecs, cell array with three elements:
%                     - width           
%                     - height
%                     - units: 'centimeters','inches','points','pixels':
%                   * paperSpecs
%                     - type: 'USLetter','A4','A5',etc.
%                     - orientation: 'landscape','portrait'
%                   * otherSpecs
%                     - fontName
%                     - fontSize
%
% panelSpecs      - struct with fields
%                   * title, cell array with [...] elements: 
%                     - forWhichPanel: 'first','all','none','last'
%                     - titleString
%                   * xLabel: 'first','all','none','last'
%                   * yLabel: 'first','all','none','last'
%                   * colorbar: 'first','all','none','last'
%                   * legend?

%%
% DEPENDENT - CLASSES (*) AND SUBCLASSES (-)
%                   * nRecorded
%                       + mean      [1x1 double]
%                       + ci        [1x2 double]
%                   * rt
%                     - mean
%                       + mean      [1x1 double]
%                       + ci        [1x2 double]
%                       + data
%                     - median
%                       + mean      [1x1 double]
%                       + ci        [1x2 double]
%                       + data
%                     - std
%                       + mean      [1x1 double]
%                       + ci        [1x2 double]
%                     - cov
%                       + mean      [1x1 double]
%                       + ci        [1x2 double]
%                       + data
%                     - iqr
%                       + mean      [1x1 double]
%                       + ci        [1x2 double]
%                       + data
%                     - range
%                       + mean      [1x1 double]
%                       + ci        [1x2 double]
%                     - skewness
%                       + mean      [1x1 double]
%                       + ci        [1x2 double]
%                     - kurtosis
%                       + mean      [1x1 double]
%                       + ci        [1x2 double]
%                     - edfX
%                       + mean      [1xnSim double]
%                       + ci        [2xnSim double]
%                     - edfY
%                       + mean      [1xnSim double]
%                       + ci        [2xnSim double]
%                     - quantileX
%                       + mean      [1x5 double]
%                       + ci        [2x5 double]
%                     - quantileY
%                       + mean      [1x5 double]
%                       + ci        [2x5 double]
%                     - histX
%                       + mean      [1xN double]
%                       + ci        [2xN double]
%                     - histY
%                       + mean      [1xN double]
%                       + ci        [2xN double]
%                     - kernelX
%                       + mean      [1xN double]
%                       + ci        [2xN double]
%                     - kernelY
%                       + mean      [1xN double]
%                       + ci        [2xN double]
%                   * trajectory
%                       + mean      [1x211 double]
%                   * threshold
%                     => see RT
%                   * rate
%                     => see RT
%                   * thresVsRtPoly1
%                     - dataX
%                       + mean      [1xnBin double]
%                       + ci        [2xnBin double]
%                     - dataY
%                       + mean      [1xnBin double]
%                       + ci        [2xnBin double]   
%                     - params
%                       + mean      [1x2 double]
%                       + ci        [2x2 double]
%                       + sign      [1x2 double]
%                     - rmse
%                       + mean      [1x1 double]
%                       + ci        [1x2 double]
%                     - rmseCoV
%                       + mean      [1x1 double]
%                       + ci        [1x2 double]
%                     - rSquare
%                       + mean      [1x1 double]
%                       + ci        [1x2 double]
%                     - fitSuccess
%                       + mean      [1x1 double]
%                   * rateVsRtPoly1
%                     => see thresVsRtPoly1
%                   * rateVsRtPower1
%                     => see thresVsRtPoly1
%                   * rateVsRtRat01
%                     => see thresVsRtPoly1

warning off

%% Load data, if needed

if strncmp(class(fileSpecs.source),'data',4)
   simData = fileSpecs.source;
elseif strncmp(class(fileSpecs.source),'char',4)
   load(fileName);
end


% Get (unique) levels of rV, pN, and nA
rVLevels = unique(simData.rV(~isnan(simData.rV)));
pNLevels = unique(simData.pN(~isnan(simData.pN)));
nALevels = dependent.plotType{2};
sigmaXi = dependent.class{4};
rXi = dependent.class{5};
maxActivation = dependent.class{6};

%% Specify figures, panels, and subpanels
switch dependent.plotType{1}
   case {'distline','line','hist'}
      
      % a. Specify figures
      switch dependent.plotType{1}
         case {'distline','hist'}
            for iFig = 1:numel(nALevels)
               hFig{iFig} = set_figure(figureSpecs.figSpecs, ...
                                    figureSpecs.paperSpecs, ...
                                    figureSpecs.otherSpecs);
            end
         case 'line'
            hFig{1} = set_figure(figureSpecs.figSpecs, ...
                           figureSpecs.paperSpecs, ...
                           figureSpecs.otherSpecs);
      end
      
      % b. Specify panels - dMeth
      nPanelRows = 1;
      nPanelColumns = 2;
      nPanels = nPanelRows.*nPanelColumns;
      
      % Get panel indices
      [iPanelRow,iPanelColumn] = meshgrid(1:nPanelRows,1:nPanelColumns);
      iPanelRow = iPanelRow(:);
      iPanelColumn = iPanelColumn(:);      
      
      % c. Specify subpanels - pN & rV
      nSubPanelRows{1} = numel(rVLevels);
      nSubPanelColumns{1} = numel(pNLevels);
      nSubPanelRows{2} = numel(rVLevels);
      nSubPanelColumns{2} = 1;
      
      nSubPanels{1} = nSubPanelRows{1}.*nSubPanelColumns{1};
      nSubPanels{2} = nSubPanelRows{2}.*nSubPanelColumns{2};
      
      % Get subpanel indices
      [iSubPanelRow{1},iSubPanelColumn{1}] = meshgrid(1:nSubPanelRows{1},1:nSubPanelColumns{1});
      iSubPanelRow{1} = iSubPanelRow{1}(:);
      iSubPanelColumn{1} = iSubPanelColumn{1}(:);      
      
      [iSubPanelRow{2},iSubPanelColumn{2}] = meshgrid(1:nSubPanelRows{2},1:nSubPanelColumns{2});
      iSubPanelRow{2} = iSubPanelRow{2}(:);
      iSubPanelColumn{2} = iSubPanelColumn{2}(:);      
      
      %
      
      % Get simData indices corresponding to the data that will be plotted in
      % iRow and iColumn. Note that flipped rV levels are used, so that the
      % lowest rV value appears in the bottom row
      rVLevelsFlipped = flipud(rVLevels);
      
      % Pre-allocate iSimData
      iSimData = cell(1,nALevels);
      
      
      % a. Specify figures
      switch dependent.plotType{1}
         case {'distline','hist'}
            for iFig = 1:numel(nALevels)
               for iPanel = 1:nPanels

                  if iPanel == 2
                     pNLevels = 1;
                  end
                  
                  switch dependent.class{2}
                     case {'dataX','dataY','params'}
                        iSimData{iFig}{iPanel} = cellfun(@(x,y) find(simData.rV == rVLevelsFlipped(x) & ...
                                                                     simData.pN == pNLevels(y) & ...
                                                                     simData.nA == nALevels(iFig) & ...
                                                                     simData.sigmaXi == sigmaXi & ...
                                                                     simData.rXi == rXi & ...
                                                                     simData.maxActivation == maxActivation & ...
                                                                     simData.dMeth == iPanel), ...
                                                                     num2cell(iSubPanelRow{iPanel}), ...
                                                                     num2cell(iSubPanelColumn{iPanel}), ...
                                                                     'UniformOutput',0);
                     otherwise
                        iSimData{iFig}{iPanel} = cellfun(@(x,y) find(simData.rV == rVLevelsFlipped(x) & ...
                                                                     simData.pN == pNLevels(y) & ...
                                                                     simData.nA == nALevels & ...
                                                                     simData.sigmaXi == sigmaXi & ...
                                                                     simData.rXi == rXi & ...
                                                                     simData.maxActivation == maxActivation & ...
                                                                     simData.dMeth == iPanel), ...
                                                                     num2cell(iSubPanelRow{iPanel}), ...
                                                                     num2cell(iSubPanelColumn{iPanel}), ...
                                                                     'UniformOutput',0);
                  end
               end
            end
         case 'line'
            for iPanel = 1:nPanels

                  if iPanel == 2
                     pNLevels = 1;
                  end

                  iSimData{1}{iPanel} = cellfun(@(x,y) find(simData.rV == rVLevelsFlipped(x) & ...
                                                            simData.pN == pNLevels(y) & ...
                                                            simData.sigmaXi == sigmaXi & ...
                                                            simData.rXi == rXi & ...
                                                            simData.maxActivation == maxActivation & ...
                                                            simData.dMeth == iPanel), ...
                                                            num2cell(iSubPanelRow{iPanel}), ...
                                                            num2cell(iSubPanelColumn{iPanel}), ...
                                                            'UniformOutput',0);
            end
      end
      
      
                                      
   case 'heat'
      % a. Specify figures
      iFig = 1;
      hFig{iFig} = set_figure(figureSpecs.figSpecs, ...
                           figureSpecs.paperSpecs, ...
                           figureSpecs.otherSpecs);
      
                        
      % b. Specify panels - nA
      nPanelRows = 1;
      nPanelColumns = numel(nALevels);
      nPanels = nPanelRows.*nPanelColumns;
      
      % Get panel indices
      [iPanelRow,iPanelColumn] = meshgrid(1:nPanelRows,1:nPanelColumns);
      iPanelRow = iPanelRow(:);
      iPanelColumn = iPanelColumn(:);
      
      % c. Specify subpanels - dMeth
      nSubPanelRows = num2cell(repmat(1,1,nPanels));
      nSubPanelColumns = num2cell(repmat(2,1,nPanels));
      nSubPanels = num2cell(cellfun(@(x,y) x.*y,nSubPanelRows,nSubPanelColumns));
      
      % Get subpanel indices
      for i = 1:nPanels
         [iSubPanelRow{i},iSubPanelColumn{i}] = meshgrid(1:nSubPanelRows{i},1:nSubPanelColumns{i});
         iSubPanelRow{i} = iSubPanelRow{i}(:);
         iSubPanelColumn{i} = iSubPanelColumn{i}(:);
      end
      
      % Get simData indices corresponding to the data that will be plotted in
      % iRow and iColumn. 
      
      for iPanel = 1:nPanels
         for iSubPanel = 1:nSubPanels{iPanel}
            iSimData{iFig}{iPanel}{iSubPanel} = find(simData.nA == nALevels(iPanel) & ...
                                                     simData.sigmaXi == sigmaXi & ...
                                                     simData.rXi == rXi & ...
                                                     simData.maxActivation == maxActivation & ...
                                                     simData.dMeth == iSubPanel);
         end
      end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Looping over figures, panels, and subpanels %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Loop 1: over figures
for iFig = 1:numel(hFig)
   
   % Make figure iFig current
   figure(hFig{iFig});
   
   % Initiate panels
   p = panel('defer');
   p.margin = [20,20,20,20]; % Margins of the parent panel (i.e. figure): left, bottom, right, top
   switch dependent.plotType{1}
      case {'distline','line','hist'}
         p.pack('h',[11/12 1/12]);
         p(1).margin = [5 0 5 0];
         p(2).margin = [5 0 5 0];
      case 'heat'
         p.pack(nPanelRows,nPanelColumns);
   end
   
   
   %% Loop 2: over panels (nA or dMeth)
   for iPanel = 1:nPanels
      
      % Initiate subpanels
      switch dependent.plotType{1}
         case {'distline','line','hist'}
            p(iPanelColumn(iPanel)).pack(nSubPanelRows{iPanel},nSubPanelColumns{iPanel});
         case 'heat'
            p(iPanelRow(iPanel),iPanelColumn(iPanel)).pack('h',[11/12 1/12]);
            % CHECK IF THIS WORKS
            p(iPanelRow(iPanel),iPanelColumn(iPanel),1).margin = [5 0 5 0];
            p(iPanelRow(iPanel),iPanelColumn(iPanel),2).margin = [5 0 5 0];
      end
      
      %% Loop 3: over subpanels (dMeth or rV/pN)
      for iSubPanel = 1:nSubPanels{iPanel}
                  
         switch dependent.plotType{1}
            case {'distline','hist'}
               
               % Select current subpanel
               currentSubPanel = p(iPanelColumn(iPanel),iSubPanelRow{iPanel}(iSubPanel),iSubPanelColumn{iPanel}(iSubPanel)).select();
               
               % Set margins of subpanels: left, bottom, right, top
               p(iPanelColumn(iPanel),iSubPanelRow{iPanel}(iSubPanel),iSubPanelColumn{iPanel}(iSubPanel)).margin = [0 0 0 0];
%                p(iPanelColumn(iPanel),iSubPanelRow{iPanel}(iSubPanel),iSubPanelColumn{iPanel}(iSubPanel)).margin = [2 2 2 2];
               % Select data for current subpanel
               currentSimData = simData(iSimData{iFig}{iPanel}{iSubPanel},:);
               
               % Make copy of dependent struct
               virtDependent = dependent;
         
               
            case 'line'
               
               % Select current subpanel
               currentSubPanel = p(iPanelColumn(iPanel),iSubPanelRow{iPanel}(iSubPanel),iSubPanelColumn{iPanel}(iSubPanel)).select();
               
               % Set margins of subpanels: left, bottom, right, top
               p(iPanelColumn(iPanel),iSubPanelRow{iPanel}(iSubPanel),iSubPanelColumn{iPanel}(iSubPanel)).margin = [0 0 0 0];
%                p(iPanelColumn(iPanel),iSubPanelRow{iPanel}(iSubPanel),iSubPanelColumn{iPanel}(iSubPanel)).margin = [2 2 2 2];

               
               % Select data for current subpanel
               currentSimData = simData(iSimData{iFig}{iPanel}{iSubPanel},:);
               
               % Make copy of dependent struct
               virtDependent = dependent;
               
            case 'heat'
               currentSubPanel = p(iPanelRow(iPanel),iPanelColumn(iPanel),iSubPanelColumn{iPanel}(iSubPanel)).select();
               
               % Set margins of subpanels: left, bottom, right, top
               p(iPanelRow(iPanel),iPanelColumn(iPanel),iSubPanelColumn{iPanel}(iSubPanel)).margin = [5 0 5 0];
               
               % Select data for current subpanel
               currentSimData = simData(iSimData{iFig}{iPanel}{iSubPanel},:);
         end
         
         % Do the plotting
         switch dependent.plotType{1}
            case 'distline'
               
               % Get x and y data for mean and CI plots
               switch dependent.class{2}
                  case {'edfX','edfY'}
                     % Get x data for mean plot
                     virtDependent.class{2} = 'edfX';
                     virtDependent.class{3} = 'mean';
                     xMean = get_dependents(currentSimData,virtDependent);

                     % Get y data for mean plot
                     yMean = 1/length(xMean):1/length(xMean):1;

                     % Get x data for ci plot
                     virtDependent.class{2} = 'edfX';
                     virtDependent.class{3} = 'ci';
                     xCI = get_dependents(currentSimData,virtDependent);

                     % Get y data for ci plot
                     yCI = repmat(1/length(xMean):1/length(xMean):1,2,1);

                     % Use only non-NaN data
                     iNoNan = find(~isnan(xMean) & ~isnan(yMean) & ~isnan(xCI(1,:)) & ~isnan(yCI(1,:)));
                     xMean = xMean(iNoNan);
                     yMean = yMean(iNoNan);
                     xCI = xCI(:,iNoNan);
                     yCI = yCI(:,iNoNan);

                     xCI = [xCI(1,:),fliplr(xCI(2,:))];
                     yCI = [yCI(1,:),fliplr(yCI(2,:))];

                  case {'quantileX','quantileY'}
                     % Get x data for mean plot
                     virtDependent.class{2} = 'quantileX';
                     virtDependent.class{3} = 'mean';
                     xMean = get_dependents(currentSimData,virtDependent);

                     % Get y data for mean plot
                     virtDependent.class{2} = 'quantileY';
                     virtDependent.class{3} = 'mean';
                     yMean = get_dependents(currentSimData,virtDependent);

                     % Get x data for ci plot
                     virtDependent.class{2} = 'quantileX';
                     virtDependent.class{3} = 'ci';
                     xCI = get_dependents(currentSimData,virtDependent);
                     xCI = [xCI(1,:),fliplr(xCI(2,:))];

                     % Get y data for ci plot
                     virtDependent.class{2} = 'quantileY';
                     virtDependent.class{3} = 'ci';
                     yCI = get_dependents(currentSimData,virtDependent);
                     yCI = [yCI(1,:),fliplr(yCI(2,:))];

                     % Plot ci band
                     hCI = patch(xCI,yCI,[.8 .8 .8],'EdgeColor','none');
                     hold on;

                     % Plot mean data
                     hMean = plot(xMean,yMean,'k-');

                  case {'histX','histY'}
                     % Get x data for mean plot
                     virtDependent.class{2} = 'histX';
                     virtDependent.class{3} = 'mean';
                     xMean = get_dependents(currentSimData,virtDependent);

                     % Get y data for mean plot
                     virtDependent.class{2} = 'histY';
                     virtDependent.class{3} = 'mean';
                     yMean = get_dependents(currentSimData,virtDependent);

                     % Get x data for ci plot
                     virtDependent.class{2} = 'histX';
                     virtDependent.class{3} = 'ci';
                     xCI = get_dependents(currentSimData,virtDependent);
                     xCI = [xCI(1,:),fliplr(xCI(2,:))];

                     % Get y data for ci plot
                     virtDependent.class{2} = 'histY';
                     virtDependent.class{3} = 'ci';
                     yCI = get_dependents(currentSimData,virtDependent);
                     yCI = [yCI(1,:),fliplr(yCI(2,:))];

                  case {'kernelX','kernelY'}
                     % Get x data for mean plot
                     virtDependent.class{2} = 'kernelX';
                     virtDependent.class{3} = 'mean';
                     xMean = get_dependents(currentSimData,virtDependent);

                     % Get y data for mean plot
                     virtDependent.class{2} = 'kernelY';
                     virtDependent.class{3} = 'mean';
                     yMean = get_dependents(currentSimData,virtDependent);

                     % Get x data for ci plot
                     virtDependent.class{2} = 'kernelX';
                     virtDependent.class{3} = 'ci';
                     xCI = get_dependents(currentSimData,virtDependent);

                     % Get y data for ci plot
                     virtDependent.class{2} = 'kernelY';
                     virtDependent.class{3} = 'ci';
                     yCI = get_dependents(currentSimData,virtDependent);

                     % Use only non-NaN data
                     iNoNan = find(~isnan(xMean) & ~isnan(yMean) & ~isnan(xCI(1,:)) & ~isnan(yCI(1,:)));
                     xMean = xMean(iNoNan);
                     yMean = yMean(iNoNan);
                     xCI = xCI(:,iNoNan);
                     yCI = yCI(:,iNoNan);

                     xCI = [xCI(1,:),fliplr(xCI(2,:))];
                     yCI = [yCI(1,:),fliplr(yCI(2,:))];

                  case {'dataX','dataY'}
                     % Get x data for mean plot
                     virtDependent.class{2} = 'dataX';
                     virtDependent.class{3} = 'mean';
                     xMean = get_dependents(currentSimData,virtDependent);

                     % Get y data for mean plot
                     virtDependent.class{2} = 'dataY';
                     virtDependent.class{3} = 'mean';
                     yMean = get_dependents(currentSimData,virtDependent);

                     % Get the best fitting parameters
                     virtDependent.class{2} = 'params';
                     virtDependent.class{3} = 'mean';
                     bestFitParams = get_dependents(currentSimData,virtDependent);

                     % Get the best fitting parameters
                     virtDependent.class{2} = 'params';
                     virtDependent.class{3} = 'sign';
                     signFitParams = get_dependents(currentSimData,virtDependent);

                     % Regression line
                     xSpan = [100,10000];
                     xDataReg = colon(xSpan(1),1,xSpan(2));
                     yDataReg = xDataReg.*bestFitParams(1) + bestFitParams(2);

                     % Confidence band of regression line
                     % To be implemented ...

               end

               % Plot data
               switch dependent.class{2}
                  case {'dataX','dataY'}
                     % Plot ci band
                     if signFitParams(1) == -1
                        lineColor = [0.1657    0.2823    0.9362];
                     elseif signFitParams(1) == 0
                        lineColor = [0 0 0];
                     elseif signFitParams(1) == 1
                        lineColor = [0.8453    0.3695    0.1911];
                     end
                     hold on;
                     hRegMean = plot(xDataReg,yDataReg,'Color',lineColor,'LineWidth',1);

                     hMean = plot(xMean,yMean,'k.','Color',lineColor,'MarkerSize',20);
                  otherwise
                     % Plot ci band
                     hCI = patch(xCI,yCI,[.8 .8 .8],'EdgeColor','none');
                     hold on;

                     hMean = plot(xMean,yMean,'k-');
               end

               % Set axis

               % Proportional scaling of X axis
               switch dependent.class{1}
                  case 'rt'
                     xTicks = [100,500,1000,5000 10000];
                     yTicks = [];
                     xScale = 'log';
                     yScale = 'linear';
                  case 'threshold'
                     xTicks = [10,100,1000];
                     yTicks = [];
                     lineX = currentSimData.mTheta(1);
                     xScale = 'log';
                     yScale = 'linear';
                  case 'rate'
                     xTicks = [0:1:5];
                     yTicks = [];
                     lineX = currentSimData.mV(1);
                     xScale = 'linear';
                     yScale = 'linear';
                  case {'thresVsRtPoly1_H','thresVsRtPoly1_W'}

                     if currentSimData.pN == 0
                        xTicks = [100,500];
                     elseif currentSimData.pN == 1
                        xTicks = [100,500,1000,2000];
                     else
                        xTicks = [100,500,1000];
                     end
                     yTicks = [10 100 1000];
                     xScale = 'log';
                     yScale = 'log';
                  case {'rateVsRtRat01_H','rateVsRtRat01_W'}
                     if currentSimData.pN == 0
                        xTicks = [100,500];
                     elseif currentSimData.pN == 1
                        xTicks = [100,500,1000,2000];
                     else
                        xTicks = [100,500,1000];
                     end
                     yTicks = [0 5];
                     xScale = 'log';
                     yScale = 'linear';
               end

               set(gca,'Box','on',...
                       'TickLength',[.04 .04],...
                       'TickDir','in',...
                       'XLim',[xTicks(1),xTicks(end)],...
                       'XScale',xScale,...
                       'XTick',xTicks,...
                       'XTickLabel','',...
                       'YTick',yTicks,...
                       'YTickLabel','',...
                       'YScale',yScale);

               xLim = get(gca,'XLim');

               switch dependent.class{1}
                  case {'thresVsRtPoly1_H','thresVsRtPoly1_W'}
                     set(gca,'YLim',[10 1000]);
                     yLim = get(gca,'YLim');
                  otherwise
                     yLim = get(gca,'YLim');
               end


               if iSubPanelRow{iPanel}(iSubPanel) == nSubPanelRows{iPanel} && iSubPanelColumn{iPanel}(iSubPanel) == 1
                  set(gca,'XTickLabel',xTicks);
                  text(xLim(1)+0.9*diff(xLim), ...
                       yLim(1)+0.8*diff(yLim), ...
                       {['p_N = ',num2str(currentSimData.pN)], ...
                        ['r_V = ',num2str(currentSimData.rV)]}, ...
                       'horizontalAlignment','right', ...
                       'verticalAlignment','top');
               elseif iSubPanelRow{iPanel}(iSubPanel) == nSubPanelRows{iPanel}
                  set(gca,'XTickLabel',xTicks);
                  text(xLim(1)+0.9*diff(xLim), ...
                       yLim(1)+0.8*diff(yLim), ...
                       ['p_N = ',num2str(currentSimData.pN)], ...
                       'horizontalAlignment','right', ...
                       'verticalAlignment','top');
               elseif iSubPanelColumn{iPanel}(iSubPanel) == 1
                  text(xLim(1)+0.9*diff(xLim), ...
                       yLim(1)+0.8*diff(yLim), ...
                       ['r_V = ',num2str(currentSimData.rV)], ...
                       'horizontalAlignment','right', ...
                       'verticalAlignment','top');
                 switch dependent.class{1}
                    case {'thresVsRtPoly1_H','thresVsRtPoly1_W'}
                       set(gca,'YTickLabel',yTicks);
                 end
               end

               % In case
               switch dependent.class{1}
                  case {'threshold','rate'}
                     axYLim = get(gca,'YLim');
                     hRefLineDist{iPanel}{iSubPanel} = line([lineX,lineX],[axYLim(1),axYLim(2)],'Color','k','LineStyle',':');
               end
               
            case 'hist'
               
               % Get x and y data for mean and CI plots
               switch dependent.class{2}
                  case {'params'}
                                          
                     params = get_dependents(currentSimData,dependent);
                                          
                     switch dependent.class{1}
                        case {'thresVsRtPoly1_W','thresVsRtPoly1_H'}
                           hold on;
                           
                           line([0 0],[0 1000],'Color','r');
                           hPatch = patch([prctile(params,2.5), prctile(params,97.5),prctile(params,97.5),prctile(params,2.5)],[0 0 1000 1000],'b');
                           
                           
%                            line([prctile(params,2.5) prctile(params,2.5)],[0 1000],'Color','k','LineStyle','--');
%                            line([prctile(params,97.5) prctile(params,97.5)],[0 1000],'Color','k','LineStyle','--');
                           xTicks = [-1 0 1];
                           hist(params,-1:0.02:1);
                        case {'rateVsRtPoly1_H','rateVsRtPower1_H','rateVsRtRat01_H','rateVsRtPoly1_W','rateVsRtPower1_W','rateVsRtRat01_W'}
                           hold on;
                           line([0 0],[0 1000],'Color','r');
                           hPatch = patch([prctile(params,2.5), prctile(params,97.5),prctile(params,97.5),prctile(params,2.5)],[0 0 1000 1000]);
%                            line([prctile(params,2.5) prctile(params,2.5)],[0 1000],'Color','k','LineStyle','--');
%                            line([prctile(params,97.5) prctile(params,97.5)],[0 1000],'Color','k','LineStyle','--');
                           hist(params,-500:1:500);
                     end
                     
               end
               
               hHist = findobj(gca,'Type','patch');
               set(hHist,'FaceColor','k','EdgeColor','none');
               set(hPatch,'FaceColor',[.2 .2 .2],'EdgeColor','none');
               
               % Set axis
               set(gca,'Box','on',...
                       'TickLength',[.04 .04],...
                       'TickDir','in',...
                       'XLim',[xTicks(1),xTicks(end)],...
                       'XScale','linear',...
                       'XTick',[],...
                       'XTickLabel','',...
                       'YTick',[]);
               
            case 'line'
                              
               % Line color indicates effect of nA on location and spread of dependent variable
               lineColors = [255   0   0;    % Location same, spread increases      (Color name: Maraschino)
                             255 191   0;    % Location increases, spread increases (Color name: Tangerine)
                             128 255   0;    % Location increases, spread same      (Color name: Lime)
                               0 255 111;    % Location increases, spread decreases (Color name: Sea foam)
                               0 255 255;    % Loaction same, spread decreases      (Color name: Turquoise)
                               0  88 255;    % Loaction decreases, spread decreases (Color name: ?)
                             104   0 255;    % Location decreases, spread same      (Color name: ?)
                             255   0 215;    % Location decreases, spread increases (Color name: ?)
                             255 255 255];   % Location same, spread same           (Color name: White)
               
               % Scale colors to [0 1] range
               lineColors = lineColors./255;

               % nA Levels
               x = unique(simData.nA(~isnan(simData.nA)));
               if size(x,1) == numel(x)
                  x = x';
               end

               % Get dependents across nA
               y = get_dependents(currentSimData,dependent);
 
               switch dependent.class{1}
                  case {'rt','threshold','rate'}
                     
                     % Measure of location
                     switch dependent.class{1}
                        case 'rt'
                           virtDependent.class{2} = 'median';
%                            virtDependent.class{2} = 'mean';
                           virtDependent.class{3} = 'data';
                        case 'threshold'
                           virtDependent.class{2} = 'mean';
%                            virtDependent.class{2} = 'median';
                           virtDependent.class{3} = 'data';
                        case 'rate'
                           virtDependent.class{2} = 'mean';
%                            virtDependent.class{2} = 'median';
                           virtDependent.class{3} = 'data';
                     end
                  
               
                     location = get_dependents(currentSimData,virtDependent);

                     % Transpose matrix if necessary
                     if size(location,1) == numel(x)
                        location = location';
                     end
                     
                     try
                     if size(location{1},1) == 1
                        location = cellfun(@(x) x',location,'UniformOutput',0);
                     end
                     catch
                        disp('bla');
                     end

                     % Identify the nA levels to use for regression analysis
                     iRegression = unique(currentSimData.nA(~isnan(currentSimData.nA))) >= dependent.colorMap{2}(1) & unique(currentSimData.nA(~isnan(currentSimData.nA))) <= dependent.colorMap{2}(2);

                     % nSes-x-nALevels cell containing nALevels used for regression
                     xCell = mat2cell(repmat(x(iRegression),currentSimData.nSes(1),1),ones(currentSimData.nSes(1),1),numel(x(iRegression)));
                     
                     % If cells contain matrices of different sizes (e.g. if
                     % nSes = 100 in for nA = 1000 and nSes = 1000 for nA = 100
                     cellSize = unique(cellfun(@(x) size(x,1),location));
                     if numel(cellSize) > 1
                        location = cellfun(@(x) x(1:min(cellSize)),location,'UniformOutput',0);
                        xCell = xCell(1:min(cellSize));
                     end
                     
                     % Location data used for regression
                     if iscolumn(location)
                        location = location';
                     end
                     location = cell2mat(location(:,iRegression));
                     
                     % Matrix to cell transformation
                     location = mat2cell(location,ones(min(cellSize),1),numel(x(iRegression)));
                     
                     % Linear regression to identify any effect of nA on dependent.class{1}
                     locationRegParams = cellfun(@(a,b) regress(b',[ones(numel(x(iRegression)),1),a']),xCell,location,'UniformOutput',0);
                     locationRegSlope = cell2mat(cellfun(@(a) a(2),locationRegParams,'UniformOutput',0)); % Get slopes
                     locationSign = ci_sign(prctile(locationRegSlope,[2.5 97.5])');

                     % Measure of spread
                     switch dependent.class{1}
                        case 'rt'
                           virtDependent.class{2} = 'iqr';
%                            virtDependent.class{2} = 'cov';
                           virtDependent.class{3} = 'data';
                        case 'threshold'
                           virtDependent.class{2} = 'cov';
%                            virtDependent.class{2} = 'iqr';
                           virtDependent.class{3} = 'data';
                        case 'rate'
                           virtDependent.class{2} = 'cov';
%                            virtDependent.class{2} = 'iqr';
                           virtDependent.class{3} = 'data';
                     end
                     spread = get_dependents(currentSimData,virtDependent);

                     % Transpose matrix if necessary
                     if size(spread,1) == numel(x)
                        spread = spread';
                     end
                     
                     if size(spread{1},1) == 1
                        spread = cellfun(@(x) x',spread,'UniformOutput',0);
                     end
                     
                     % If cells contain matrices of different sizes (e.g. if
                     % nSes = 100 in for nA = 1000 and nSes = 1000 for nA = 100
                     cellSize = unique(cellfun(@(x) size(x,1),spread));
                     if numel(cellSize) > 1
                        spread = cellfun(@(x) x(1:min(cellSize)),spread,'UniformOutput',0);
                     end

                     % Location data used for regression
                     if iscolumn(spread)
                        spread = spread';
                     end
                     spread = cell2mat(spread(:,iRegression));

                     % Matrix to cell transformation
                     spread = mat2cell(spread,ones(min(cellSize),1),numel(x(iRegression)));

                     % Linear regression
                     spreadRegParams = cellfun(@(a,b) regress(b',[ones(numel(x(iRegression)),1),a']),xCell,spread,'UniformOutput',0);
                     spreadRegSlope = cell2mat(cellfun(@(a) a(2),spreadRegParams,'UniformOutput',0)); % Get slopes
                     spreadSign = ci_sign(prctile(spreadRegSlope,[2.5 97.5])');

                     switch dependent.class{1}
                        case 'rt'
                           % Spread-location ratio
                           spreadLocRatio = cellfun(@(a,b) a./b,spread,location,'UniformOutput',0);

                           % Linear regression of spread-location ratio
                           spreadLocRatioRegParams = cellfun(@(a,b) regress(b',[ones(numel(x(iRegression)),1),a']),xCell,spreadLocRatio,'UniformOutput',0);
                           spreadLocRatioRegSlope = cell2mat(cellfun(@(a) a(2),spreadLocRatioRegParams,'UniformOutput',0)); % Get slopes
                           spreadLocRatioRegSign = ci_sign(prctile(spreadLocRatioRegSlope,[2.5 97.5])');

                           % Determine line color based on sign of location and spread
                           iClr(locationSign ==  0 & spreadLocRatioRegSign ==  1) = 1; % Location same, spread increases
                           iClr(locationSign ==  1 & spreadLocRatioRegSign ==  1) = 2; % Location increases, spread increases
                           iClr(locationSign ==  1 & spreadLocRatioRegSign ==  0) = 3; % Location increases, spread same
                           iClr(locationSign ==  1 & spreadLocRatioRegSign == -1) = 4; % Location increases, spread decreases
                           iClr(locationSign ==  0 & spreadLocRatioRegSign == -1) = 5; % Loaction same, spread decreases
                           iClr(locationSign == -1 & spreadLocRatioRegSign == -1) = 6; % Loaction decreases, spread decreases
                           iClr(locationSign == -1 & spreadLocRatioRegSign ==  0) = 7; % Location decreases, spread same
                           iClr(locationSign == -1 & spreadLocRatioRegSign ==  1) = 8; % Location decreases, spread increases
                           iClr(locationSign ==  0 & spreadLocRatioRegSign ==  0) = 9; % Location same, spread same             

                        case {'threshold','rate'}

                           % Determine line color based on sign of location and spread
                           iClr(locationSign ==  0 & spreadSign ==  1) = 1; % Location same, spread increases
                           iClr(locationSign ==  1 & spreadSign ==  1) = 2; % Location increases, spread increases
                           iClr(locationSign ==  1 & spreadSign ==  0) = 3; % Location increases, spread same
                           iClr(locationSign ==  1 & spreadSign == -1) = 4; % Location increases, spread decreases
                           iClr(locationSign ==  0 & spreadSign == -1) = 5; % Loaction same, spread decreases
                           iClr(locationSign == -1 & spreadSign == -1) = 6; % Loaction decreases, spread decreases
                           iClr(locationSign == -1 & spreadSign ==  0) = 7; % Location decreases, spread same
                           iClr(locationSign == -1 & spreadSign ==  1) = 8; % Location decreases, spread increases
                           iClr(locationSign ==  0 & spreadSign ==  0) = 9; % Location same, spread same          
                     end
                  case {'thresVsRtPoly1_H','thresVsRtPoly1_W'}
                     iClr = 9;

               end

               % Plot it
               hold on

               for iBin = 1:size(y,2)
                  try
                  hP = plot(x,y(:,iBin),...
                     'Color',[0 0 0], ...
                     'Marker','o', ...
                     'MarkerFaceColor',[0 0 0], ...
                     'MarkerEdgeColor','none',...
                     'MarkerSize',5);
                  hL = line([1 1000],[100 100],'Color','r');
                  
%                   hP = plot(x,y(:,iBin),...
%                      'Color',lineColors(iClr,:), ...
%                      'Marker','o', ...
%                      'MarkerFaceColor',lineColors(iClr,:), ...
%                      'MarkerEdgeColor','none',...
%                      'MarkerSize',5);
                  catch
                  end
               end
               
               set(gca,'Color',lineColors(iClr,:));

               switch dependent.class{1}
                  case 'rt'
                     yTicks = [100 500 1000 5000 10000];
                     yScale = 'log';
                     axXLim = get(gca,'XLim');
                     axYLim = get(gca,'XLim');
                  case 'threshold'
                     yTicks = [10,100,1000];
                     lineY = currentSimData.mTheta(1);
                     yScale = 'log';
                     axXLim = get(gca,'XLim');
                     axYLim = get(gca,'XLim');
                     hRefLineDist{iPanel}{iSubPanel} = line([axXLim(1),axXLim(2)],[lineY,lineY],'Color','k','LineStyle',':');
                  case 'rate'
                     yTicks = [0:1:5];
                     lineY = currentSimData.mV(1);
                     yScale = 'linear';
                     axXLim = get(gca,'XLim');
                     axYLim = get(gca,'XLim');
                     hRefLineDist{iPanel}{iSubPanel} = line([axXLim(1),axXLim(2)],[lineY,lineY],'Color','k','LineStyle',':');
                  case {'thresVsRtPoly1_H','thresVsRtPoly1_W'}
                     yTicks = [-.2:.1:.2];
                     yScale = 'linear';
                     axXLim = get(gca,'XLim');
                     axYLim = get(gca,'XLim');
               end

               
               
               set(gca,'Box','on',...
                       'TickLength',[.04 .04],...
                       'TickDir','in',...
                       'XLim',[1 1e3],...
                       'XScale','log',...
                       'XTick',[1e0 2e0 5e0 1e1 2e1 5e1 1e2 2e2 5e2 1e3],...
                       'XTickLabel','',...
                       'YLim',[dependent.colorMap{2}(1),dependent.colorMap{2}(2)],...
                       'YTick',yTicks,...
                       'YTickLabel','',...
                       'YScale',yScale);

               if iSubPanelRow{iPanel}(iSubPanel) == nSubPanelRows{iPanel} && iSubPanelColumn{iPanel}(iSubPanel) == 1
                  set(gca,'XTickLabel',[1e0 2e0 5e0 1e1 2e1 5e1 1e2 2e2 5e2 1e3],...
                          'YTickLabel',yTicks);
                  text(axXLim(1)+0.9*diff(axXLim), ...
                       axYLim(1)+0.8*diff(axYLim), ...
                       {['p_N = ',num2str(currentSimData.pN(1))], ...
                        ['r_V = ',num2str(currentSimData.rV(1))]}, ...
                       'horizontalAlignment','right', ...
                       'verticalAlignment','top');
               elseif iSubPanelRow{iPanel}(iSubPanel) == nSubPanelRows{iPanel}
                  set(gca,'XTickLabel',[1e0 2e0 5e0 1e1 2e1 5e1 1e2 2e2 5e2 1e3]);
                  text(axXLim(1)+0.9*diff(axXLim), ...
                       axYLim(1)+0.8*diff(axYLim), ...
                       ['p_N = ',num2str(currentSimData.pN(1))], ...
                       'horizontalAlignment','right', ...
                       'verticalAlignment','top');
               elseif iSubPanelColumn{iPanel}(iSubPanel) == 1
                  set(gca,'YTickLabel',yTicks);
                  text(axXLim(1)+0.9*diff(axXLim), ...
                       axYLim(1)+0.8*diff(axYLim), ...
                       ['r_V = ',num2str(currentSimData.rV(1))], ...
                       'horizontalAlignment','right', ...
                       'verticalAlignment','top');
               end
               
            case 'heat'
               
               if iSubPanel == 1 % Polling
               
                  ppa = numel(rVLevels);

                  % Define axes variables (specific for heat plots of thresVsRt etc.)
                  x = currentSimData.pN;
                  y = currentSimData.rV;
                  y = flipdim(y,1);

                  % N.B. if dependents are matrices, they will be averaged to make vectors!
                  z = get_dependents(currentSimData,dependent);
                  z = flipdim(vec2mat(z,ppa),1);

                  % Complex numbers were found in rSquare data of rateVsRtRat01
                  z = real(z);

                  % EDIT THIS:
                  imagesc(x,y,z,dependent.colorMap{2}); hold on;
                  colormap(dependent.colorMap{1});

                  axis tight

   %                %% Quiver
   %                freezeColors;
   %                colormap('gray');
   %                
   %                [dx,dy] = gradient(z,.1);
   %                vecLength = sqrt(dx.^2 + dy.^2);
   %                [X,Y] = meshgrid(0:.1:1,0:.1:1);
   %                Y = flipud(Y);
   %                
   %                cont = logspace(log10(min(vecLength(:))),log10(max(vecLength(:))),64);
   %                ncquiverref(X,Y,dx,dy,'sp s-1','max',1,'col',cont);


                  % Plot error
                  if isfield(dependent,'error')
                     plot_error(currentSimData,dependent,z,ppa);
                  end

                  posPoll =  get(gca,'Position');
                  posPoll(4) = posPoll(3); % Height equals width

                  set(gca,'DataAspectRatioMode','manual', ...
                          'DataAspectRatio',[1 1 1]);
               
                  % Add colorbar below pooling heat map
                  if ~strcmpi(panelSpecs.colorBar,'none')
                     hColorbar = colorbar('peer', currentSubPanel,'Location','SouthOutside');
                  end
                       
               elseif iSubPanel == 2 % Pooling
                  ppa = 1;
               
                  % Define axes variables (specific for heat plots of thresVsRt etc.)
                  x = currentSimData.pN;
                  y = currentSimData.rV;
                  y = flipdim(y,1);

                  % N.B. if dependents are matrices, they will be averaged to make vectors!
                  z = get_dependents(currentSimData,dependent);
                  z = flipdim(vec2mat(z,1),1);

                  imagesc(x,y,z,dependent.colorMap{2});
                  colormap(dependent.colorMap{1});

                  axis tight
                  

                  if isfield(dependent,'error')
                     plot_error(currentSimData,dependent,z(:),ppa);
                  end

                  posPool = get(gca,'Position');
                  posPool(2) = posPoll(2);
                  posPool(3) = posPoll(3)/11;
                  posPool(4) = posPoll(4);
                  set(gca,'Position',posPool);

                  set(gca,'DataAspectRatioMode','manual', ...
                          'DataAspectRatio',[1 1/10 1]);
                  
                  axis off
        
                  % Add colorbar below pooling heat map
                  % N.B. Although this colorbar is identical to that of subpanel
                  % 1, and is hardly legible, it ensures equal height of the
                  % subpanels
                  if ~strcmpi(panelSpecs.colorBar,'none')
                     hColorbar = colorbar('peer', currentSubPanel,'Location','SouthOutside');
                  end
            end
         end
      end
   end
   
   % Proportional scaling of Y axis and reference line (in distribution plots)
   hFigAxes = get(hFig{iFig},'Children');

   if ~isempty(dependent.class{2})
      switch dependent.class{2}
         case {'edfX','edfY'}
            set(hFigAxes,'YLim',[0 1]);
            switch dependent.class{1}
               case {'threshold','rate'}
                  set(cell2mat([hRefLineDist{:}]),'YData',[0 1]);
            end
         case {'quantileX','quantileY'}
            set(hFigAxes,'YLim',[0 1]);
            switch dependent.class{1}
               case 'rt'
                  set(hFigAxes,'YLim',[100 10000]);
               case {'threshold','rate'}
                  set(cell2mat([hRefLineDist{:}]),'YData',[0 1]);
            end
         case {'histX','histY'}
            ylm = cell2mat(get(hFigAxes,'YLim'));
            set(hFigAxes,'YLim',[0 max(ylm(:))]);
            switch dependent.class{1}
               case {'threshold','rate'}
                  set(cell2mat([hRefLineDist{:}]),'YData',[0 max(ylm(:))]);
            end
         case {'kernelX','kernelY'}
            ylm = cell2mat(get(hFigAxes,'YLim'));
            set(hFigAxes,'YLim',[0 max(ylm(:))]);

            switch dependent.class{1}
               case {'threshold','rate'}
                  set(cell2mat([hRefLineDist{:}]),'YData',[0 max(ylm(:))]);
            end
      end
   end
   
   % Refresh panel
   p.refresh();
end

%% NESTED FUNCTIONS



function plot_error(currentSimData,dependent,z,ppa)
% error           - struct with fields
%
%
%

% Replace any empty cells with NaN structs
currentSimData = find_empty_cells(currentSimData,dependent);

% Get size of axes (for scaling of masks from Cartesian to matrix mode)
axSize = [diff(get(gca,'XLim')),diff(get(gca,'YLim'))];

% Compute error mask
if isempty(dependent.error.class{2}) % nRecorded, trajectory
   errorData = eval(['cell2mat(cellfun(@(x) x.',dependent.error.class{3},',currentSimData.',dependent.error.class{1},',''UniformOutput'',0));']);
   switch dependent.error.class{1}
      case 'nRecorded'
         errorData = (errorData./500)*100; % nSim to %Sim
      case 'trajectory'
   end
elseif strncmpi(dependent.error.class{3},'data',4)
   tempCell = eval(['vertcat(currentSimData.',dependent.error.class{1},');']);
   errorData = eval(['cellfun(@(x) x.',dependent.error.class{2},'.',dependent.error.class{3},', tempCell,''UniformOutput'',0);']);   
   switch dependent.class{1}
      case {'thresVsRtPoly1_H','thresVsRtPoly1_W'}
         
         switch dependent.error.class{2}
            case 'params'
               error('Don''t know what to display')
            case 'paramsSign'
               errorData = cell2mat(cellfun(@(x) numel(find(x ~= 0)),errorData,'UniformOutput',0));
         end
      case {'rateVsRtPoly1_H','rateVsRtPower1_H','rateVsRtRat01_H','rateVsRtPoly1_W','rateVsRtPower1_W','rateVsRtRat01_W'}
         
         switch dependent.class{2}
            case 'params'
               error('Don''t know what to display')
            case 'paramsSign'
               errorData = cell2mat(cellfun(@(x) numel(find(x <= 0)),errorData,'UniformOutput',0));
         end
   end
else
   tempCell = eval(['vertcat(currentSimData.',dependent.error.class{1},');']);
   errorData = eval(['cell2mat(cellfun(@(x) x.',dependent.error.class{2},'.',dependent.error.class{3},', tempCell,''UniformOutput'',0));']);
end

% eval(['errorData = cell2mat(cellfun(@(x) x.',dependent.error.class{2},',currentSimData.',dependent.error.class{1},',''UniformOutput'',0));']);
switch lower(dependent.error.criterion{1})
   case 'in' % Inclusive mask, masks values in between lower bound and upper bound
      lb = dependent.error.criterion{2};
      ub = dependent.error.criterion{3};
      compute_error_mask = @(x,y,z) x>y & x<z;
      errorMask = compute_error_mask(errorData,lb,ub);
   case 'out' % Exclusive mask, masks values outside lower bound and upper bound
      lb = dependent.error.criterion{2};
      ub = dependent.error.criterion{3};
      compute_error_mask = @(x,y,z) x<y | x>z;
      errorMask = compute_error_mask(errorData,lb,ub);
   case 'not'
      crit = str2num(dependent.error.criterion{2});
      compute_error_mask = @(x,y) x~=y;
      errorMask = compute_error_mask(errorData,crit);
end
errorMask = flipdim(vec2mat(errorMask,ppa),1);
% [maskF,maskV] = pixel_outline(z,errorMask,size(errorMask),axSize);
[maskX,maskY] = pixel_outline(z,errorMask,size(errorMask),axSize);

% Pixels in which parameter equals NaN
if isempty(dependent.error.class{2}) % nRecorded, trajectory
   nanMask = eval(['isnan(cell2mat(cellfun(@(x) x.',dependent.class{3},',currentSimData.',dependent.class{1},',''UniformOutput'',0)));']);
else
   tempCell = eval(['vertcat(currentSimData.',dependent.error.class{1},');']);
   nanMask = eval(['isnan(cell2mat(cellfun(@(x) x.',dependent.error.class{2},'.',dependent.error.class{3},', tempCell,''UniformOutput'',0)));']);
end
 
% eval(['nanMask = isnan(cell2mat(cellfun(@(x) x.',dependent.error.class{2},'.',dependent.error.class{3},',tempCell,''UniformOutput'',0)));']);
nanMask = flipdim(vec2mat(nanMask,ppa),1);
% nanOutline = pixel_outline(z,nanMask,size(nanMask),axSize);
if any(nanMask(:)>0)
   [nanX,nanY] = pixel_outline(z,nanMask,size(nanMask),axSize);
end

% Plot error bar / variability
switch dependent.error.plotType{1}
   case 'hatch'
      % Create hatched mask patch
      hatchAngle = 45;
      hatchSpacing = 20;
      
      for j = 1:length(maskX)
         hHatch{j} = patch(maskX{j},maskY{j},[1 1 1]);
         hHatch{j} = hatchfill(hHatch{j},'single',hatchAngle,hatchSpacing);
      end
      
      % Nan patch
      if any(nanMask(:)>0)
         for j = 1:length(nanX)
            hNanHatch{j} = patch(nanX{j},nanY{j},[0.5 0.5 0.5],'EdgeColor','none');
%             hNanHatch{j} = hatchfill(hNanHatch{j},'single',hatchAngle,hatchSpacing);
%             hNanHatch{j} = patch(nanX{j},nanY{j},[1 1 1]);
%             hNanHatch{j} = hatchfill(hNanHatch{j},'single',hatchAngle,hatchSpacing);            
%             patch(nanOutline{ino}(:,2),nanoutline{ino}(:,1),[0.5 0.5 0.5],'EdgeColor','none')
         end
      end
      
      
%       hPatch = patch('Faces',maskF,'Vertices',maskV,'FaceColor','k','FaceAlpha',0.8,'EdgeColor','k','EdgeAlpha',0);
%       hPatch = patch('Faces',maskF,'FaceColor','w','FaceAlpha',0.5);
%       hPatch = hatchfill(hPatch,'single',45,5);
      
      
%       for imo = 1:numel(maskOutline)
% %          hPatch{imo} = patch(maskOutline{imo}(:,2),maskOutline{imo}(:,1),[1 1 1]);
%          hPatch{imo} = patch('Faces',maskF,'Vertices',maskV,'FaceColor','k','FaceAlpha',0,'EdgeColor','k');
%          
%          hPatch = patch('Faces',maskF,'FaceColor','w','FaceAlpha',0.5);
%          hPatch = hatchfill(hPatch,'single',45,5);
% %          hPatch{imo} = hatchfill(hPatch{imo},'single',45,5);
%       end
      
      % Create grey NaN patch
%       for j = 1:length(nanX)
%          hPatch{j} = patch(maskX{j},maskY{j},[1 1 1]);
%          hPatch{j} = hatchfill(hPatch{j},'single',45,10);
%       end      
      
      
      
%       hNanPatch = patch('Faces',nanF,'Vertices',nanV,'FaceColor',[.5 .5 .5],'FaceAlpha',0,'EdgeColor','none','EdgeAlpha',0);
      
%       if ~isempty(nanOutline)
%          for ino = 1:numel(nanOutline)
%             hNanPatch{ino} = patch(nanOutline{ino}(:,2),nanoutline{ino}(:,1),[0.5 0.5 0.5],'EdgeColor','none');
%          end
%       end
   case 'contour'
      for imo = 1:numel(maskOutline)
         plot(maskOutline{imo}(:,2), maskOutline{imo}(:,1), 'k', 'Linewidth', 2);
      end
                         
      if ~isempty(nanOutline)
         for ino = 1:numel(nanOutline)
            hNanPatch{ino} = patch(nanOutline{ino}(:,2),nanOutline{ino}(:,1),[0.5 0.5 0.5],'EdgeColor','none');
         end
      end
   case 'nanonly'
      if ~isempty(nanOutline)
         for ino = 1:numel(nanOutline)
            hNanPatch{ino} = patch(nanOutline{ino}(:,2),nanOutline{ino}(:,1),[0.5 0.5 0.5],'EdgeColor','none');
         end
      end
end

function dataToPlot = get_dependents(simData,dependent)

% Find empty cells and replace with NaN structs
simData = find_empty_cells(simData,dependent);

% Get dependents
if isempty(dependent.class{2}) % nRecorded, trajectory, elapsedTime
   
   switch dependent.class{1}
      case 'nRecorded'
         dataToPlot = eval(['cell2mat(cellfun(@(x) x.',dependent.class{3},',simData.',dependent.class{1},',''UniformOutput'',0));']);
         dataToPlot = (dataToPlot./500)*100;
      case 'elapsedTime'
         dataToPlot = simData.elapsedTime/3600; % In hours
   end
elseif strncmpi(dependent.class{2},'iqr',3) % Normalize IQR
   tempCell = eval(['vertcat(simData.',dependent.class{1},');']);
   dataToPlot = eval(['cellfun(@(x) x.',dependent.class{2},'.',dependent.class{3},', tempCell,''UniformOutput'',0);']);
   dataToPlot = eval(['cellfun(@(x) 0.7413.*x, dataToPlot,''UniformOutput'',0);']); % 0.7413 is Normalization Constant for IQR, see p. 4 of http://publications.lib.chalmers.se/records/fulltext/11447.pdf   
   
elseif strncmpi(dependent.class{3},'data',4)
   tempCell = eval(['vertcat(simData.',dependent.class{1},');']);
   dataToPlot = eval(['cellfun(@(x) x.',dependent.class{2},'.',dependent.class{3},', tempCell,''UniformOutput'',0);']);
else
   tempCell = eval(['vertcat(simData.',dependent.class{1},');']);
   try
      dataToPlot = eval(['cell2mat(cellfun(@(x) x.',dependent.class{2},'.',dependent.class{3},', tempCell,''UniformOutput'',0));']);
   catch
      disp('bla');
   end
end

switch dependent.plotType{1}
   
   case 'distline'
      switch dependent.class{1}
         case {'rt','threshold','rate'}
            switch dependent.class{2}
               case {'mean','median','std','cov','iqr','range','skewness','kurtosis'}
                  error(['It is not clear what to plot for ',dataToPlot.class{1},' - ',dataToPlot.class{2},' - ',dataToPlot.class{3}]);
               case {'edfX','edfY','quantileX','quantileY','histX','histY','kernelX','kernelY'}
                  % Do nothing
            end     
         case {'thresVsRtPoly1_H','rateVsRtPoly1_H','rateVsRtPower1_H','rateVsRtRat01_H','thresVsRtPoly1_W','rateVsRtPoly1_W','rateVsRtPower1_W','rateVsRtRat01_W'}
            switch dependent.class{2}
               case {'dataX','dataY','params'}
                  % Do nothing
               case {'rmse','rmseCoV','rSquare','fitSuccess'}
                  error(['It is not clear what to plot for ',dataToPlot.class{1},' - ',dataToPlot.class{2},' - ',dataToPlot.class{3}]);
            end
      end
   case 'hist'   
      switch dependent.class{1}
         case {'rt','threshold','rate'}
               switch dependent.class{2}
                  case {'mean','median','std','cov','iqr','range','skewness','kurtosis'}
                     error(['It is not clear what to plot for ',dataToPlot.class{1},' - ',dataToPlot.class{2},' - ',dataToPlot.class{3}]);
                  case {'edfX','edfY','quantileX','quantileY','histX','histY','kernelX','kernelY'}
                     % Do nothing
               end     
         case {'thresVsRtPoly1_H','rateVsRtPoly1_H','rateVsRtPower1_H','rateVsRtRat01_H','thresVsRtPoly1_W','rateVsRtPoly1_W','rateVsRtPower1_W','rateVsRtRat01_W'}
               switch dependent.class{2}
                  case {'dataX','dataY'}
                     % Do nothing
                  case {'params'}
                     dataToPlot = cell2mat(dataToPlot);
                  case {'rmse','rmseCoV','rSquare','fitSuccess'}
                     error(['It is not clear what to plot for ',dataToPlot.class{1},' - ',dataToPlot.class{2},' - ',dataToPlot.class{3}]);
               end
      end
   case 'line'
   case 'heat'
      
      switch dependent.class{1}
         case {'rt','threshold','rate'}
            switch dependent.class{2}
               case {'mean','median','std','cov','iqr','range','skewness','kurtosis'}
                  switch dependent.class{3}
                     case 'mean'
                        % Do nothing
                     case 'ci'
                        % Take the difference between the upper and lower bound
                        dataToPlot = dataToPlot(:,2)-dataToPlot(:,1);
                     case 'data'
                        error(['It is not clear what to plot for ',dataToPlot.class{1},' - ',dataToPlot.class{2},' - ',dataToPlot.class{3}]);
                  end
               case {'edfX','edfY','quantileX','quantileY','histX','histY','kernelX','kernelY'}
                  error(['It is not clear what to plot for ',dataToPlot.class{1},' - ',dataToPlot.class{2},' - ',dataToPlot.class{3}]);
            end     
         case {'thresVsRtPoly1_H','rateVsRtPoly1_H','rateVsRtPower1_H','rateVsRtRat01_H','thresVsRtPoly1_W','rateVsRtPoly1_W','rateVsRtPower1_W','rateVsRtRat01_W'}
            switch dependent.class{2}
               case {'dataX','dataY'}
                  error(['It is not clear what to plot for ',dataToPlot.class{1},' - ',dataToPlot.class{2},' - ',dataToPlot.class{3}]);
               case 'params'
                  % The first parameter is of interest for Poly1 and Rat01 functions
                  dataToPlot = dataToPlot(:,1);
               case 'paramsSign'
                  switch dependent.class{1}
                     case {'thresVsRtPoly1_H','thresVsRtPoly1_W'}
                        dataToPlot = cell2mat(cellfun(@(x) numel(find(x ~= 0)),dataToPlot,'UniformOutput',0));
                     case {'rateVsRtPoly1_H','rateVsRtPower1_H','rateVsRtRat01_H','rateVsRtPoly1_W','rateVsRtPower1_W','rateVsRtRat01_W'}
                        dataToPlot = cell2mat(cellfun(@(x) numel(find(x <= 0)),dataToPlot,'UniformOutput',0));
                  end
               case {'rmse','rmseCoV','rSquare','fitSuccess'}
                  switch dependent.class{3}
                     case 'mean'
                        % Do nothing
                     case 'ci'
                        % Take the difference between the upper and lower bound
                        dataToPlot = dataToPlot(:,2)-dataToPlot(:,1);
                  end
            end
      end

end

function simData = find_empty_cells(simData,dependent);

noCell = eval(['~iscell(simData.',dependent.class{1},');']);
if noCell
   simData = simData;
else   
   % Find empty cells and replace with NaN structs
   emptyCell = eval(['cellfun(@(x) isempty(x), simData.',dependent.class{1},');']);
   emptyCell = find(emptyCell);

   % Fill empty cells with NaNs
   switch dependent.class{1}
      case 'rtCdf'
         for iEmpty = 1:numel(emptyCell)
            simData.rtCdf{emptyCell(iEmpty)} = ...
               struct('mean',nan(1,simData.nSim));
         end
      case 'FCdf'
         for iEmpty = 1:numel(emptyCell)
            simData.FCdf{emptyCell(iEmpty)} = ...
               struct('mean',nan(1,simData.nSim));
         end
      case 'rtQuantile'
         for iEmpty = 1:numel(emptyCell)
            simData.rtQuantile{emptyCell(iEmpty)} = ...
               struct('mean',nan(1,5));
         end
      case 'FQuantile'
         for iEmpty = 1:numel(emptyCell)
            simData.FQuantile{emptyCell(iEmpty)} = ...
               struct('mean',nan(1,5));
         end
      case 'rtGaussKernel'
         for iEmpty = 1:numel(emptyCell)
            simData.rtGaussKernel{emptyCell(iEmpty)} = ...
               struct('mean',nan(1,60));
         end
      case 'fGaussKernel'
         for iEmpty = 1:numel(emptyCell)
            simData.fGaussKernel{emptyCell(iEmpty)} = ...
               struct('mean',nan(1,60));
         end
      case 'medianRt'
         for iEmpty = 1:numel(emptyCell)
            simData.medianRt{emptyCell(iEmpty)} = ...
               struct('mean',nan(1,1), ...
                      'ci95',nan(1,2));
         end
      case 'sdRt'
         for iEmpty = 1:numel(emptyCell)
            simData.sdRt{emptyCell(iEmpty)} = ...
               struct('mean',nan(1,1), ...
                      'ci95',nan(1,2));
         end
      case 'covRt'
         for iEmpty = 1:numel(emptyCell)
            simData.covRt{emptyCell(iEmpty)} = ...
               struct('mean',nan(1,1), ...
                      'data',nan(simData.nSes,1));
         end
      case 'iqrRt'
         for iEmpty = 1:numel(emptyCell)
            simData.iqrRt{emptyCell(iEmpty)} = ...
               struct('mean',nan(1,1), ...
                      'ci95',nan(1,2));
         end
      case 'skewnessRt'
         for iEmpty = 1:numel(emptyCell)
            simData.skewnessRt{emptyCell(iEmpty)} = ...
               struct('mean',nan(1,1), ...
                      'ci95',nan(1,2));
         end
      case 'kurtosisRt'
         for iEmpty = 1:numel(emptyCell)
            simData.kurtosisRt{emptyCell(iEmpty)} = ...
               struct('mean',nan(1,1), ...
                      'ci95',nan(1,2));
         end
      case 'rt_exGauss'
         for iEmpty = 1:numel(emptyCell)
            simData.rt_exGauss{emptyCell(iEmpty)} = ...
               struct('meanFittedParams',nan(1,3), ...
                      'ci95FittedParams',nan(2,3), ...
                      'meanSSE',nan(1,1), ...
                      'ci95SSE',nan(1,2), ...
                      'meanRSquare',nan(1,1), ...
                      'ci95RSquare',nan(1,2), ...
                      'successRate',nan(1,1));
         end
      case 'nRecorded'
         for iEmpty = 1:numel(emptyCell)
            simData.nRecorded{emptyCell(iEmpty)} = ...
               struct('mean',nan(1,1), ...
                      'ci95',nan(1,2));
         end
      case 'dtActPeakRt'
         for iEmpty = 1:numel(emptyCell)
            simData.nRecorded{emptyCell(iEmpty)} = ...
               struct('mean',nan(1,1), ...
                      'ci95',nan(1,2), ...
                      'sign',nan(1,1));
         end
      case 'rtAlignedTrajectories'
         for iEmpty = 1:numel(emptyCell)
            simData.nRecorded{emptyCell(iEmpty)} = ...
               struct('mean',nan(1,211), ...
                      'ci95',nan(2,211));
         end
      case 'rtBinned'
         for iEmpty = 1:numel(emptyCell)
            simData.rtBinned{emptyCell(iEmpty)} = ...
               struct('mean',nan(1,10), ...
                      'ci95',nan(2,10));
         end
      case 'thresholdBinned'
         for iEmpty = 1:numel(emptyCell)
            simData.thresholdBinned{emptyCell(iEmpty)} = ...
               struct('mean',nan(1,10), ...
                      'ci95',nan(2,10));
         end
      case 'rateBinned'
         for iEmpty = 1:numel(emptyCell)
            simData.rateBinned{emptyCell(iEmpty)} = ...
               struct('mean',nan(1,10), ...
                      'ci95',nan(2,10));
         end
      case 'thresVsRtPoly1_H'
         for iEmpty = 1:numel(emptyCell)
            simData.thresVsRtPoly1_H{emptyCell(iEmpty)} = ...
               struct('dataX',struct('mean',nan(1,50),'ci',nan(2,50)), ...
                      'dataY',struct('mean',nan(1,50),'ci',nan(2,50)), ...
                      'params',struct('mean',nan(1,2),'ci',nan(2,2),'sign',nan(1,2),'data',nan(1000,2)), ...
                      'paramsSign',struct('data',nan(1000,2)), ...
                      'rmse',struct('mean',nan(1,1),'ci',nan(1,2)), ...
                      'rmseCoV',struct('mean',nan(1,1),'ci',nan(1,2)), ...
                      'rSquare',struct('mean',nan(1,1),'ci',nan(1,2)), ...
                      'fitSuccess',struct('mean',nan(1,1)));
         end
      case 'thresVsRtPoly1_W'
         for iEmpty = 1:numel(emptyCell)
            simData.thresVsRtPoly1_W{emptyCell(iEmpty)} = ...
               struct('dataX',struct('mean',nan(1,50),'ci',nan(2,50)), ...
                      'dataY',struct('mean',nan(1,50),'ci',nan(2,50)), ...
                      'params',struct('mean',nan(1,2),'ci',nan(2,2),'sign',nan(1,2),'data',nan(1000,2)), ...
                      'paramsSign',struct('data',nan(1000,2)), ...
                      'rmse',struct('mean',nan(1,1),'ci',nan(1,2)), ...
                      'rmseCoV',struct('mean',nan(1,1),'ci',nan(1,2)), ...
                      'rSquare',struct('mean',nan(1,1),'ci',nan(1,2)), ...
                      'fitSuccess',struct('mean',nan(1,1)));
         end
      case 'rateVsRtPoly1_H'
         for iEmpty = 1:numel(emptyCell)
            simData.rateVsRtPoly1_H{emptyCell(iEmpty)} = ...
               struct('dataX',struct('mean',nan(1,50),'ci',nan(2,50)), ...
                      'dataY',struct('mean',nan(1,50),'ci',nan(2,50)), ...
                      'params',struct('mean',nan(1,2),'ci',nan(2,2),'sign',nan(1,2),'data',nan(1000,2)), ...
                      'paramsSign',struct('data',nan(1000,2)), ...
                      'rmse',struct('mean',nan(1,1),'ci',nan(1,2)), ...
                      'rmseCoV',struct('mean',nan(1,1),'ci',nan(1,2)), ...
                      'rSquare',struct('mean',nan(1,1),'ci',nan(1,2)), ...
                      'fitSuccess',struct('mean',nan(1,1)));
         end
      case 'rateVsRtPoly1_W'
         for iEmpty = 1:numel(emptyCell)
            simData.rateVsRtPoly1_W{emptyCell(iEmpty)} = ...
               struct('dataX',struct('mean',nan(1,50),'ci',nan(2,50)), ...
                      'dataY',struct('mean',nan(1,50),'ci',nan(2,50)), ...
                      'params',struct('mean',nan(1,2),'ci',nan(2,2),'sign',nan(1,2),'data',nan(1000,2)), ...
                      'paramsSign',struct('data',nan(1000,2)), ...
                      'rmse',struct('mean',nan(1,1),'ci',nan(1,2)), ...
                      'rmseCoV',struct('mean',nan(1,1),'ci',nan(1,2)), ...
                      'rSquare',struct('mean',nan(1,1),'ci',nan(1,2)), ...
                      'fitSuccess',struct('mean',nan(1,1)));
         end
      case 'rateVsRtPower1_H'
         for iEmpty = 1:numel(emptyCell)
            simData.rateVsRtPower1_H{emptyCell(iEmpty)} = ...
               struct('dataX',struct('mean',nan(1,50),'ci',nan(2,50)), ...
                      'dataY',struct('mean',nan(1,50),'ci',nan(2,50)), ...
                      'params',struct('mean',nan(1,2),'ci',nan(2,2),'sign',nan(1,2),'data',nan(1000,2)), ...
                      'paramsSign',struct('data',nan(1000,2)), ...
                      'rmse',struct('mean',nan(1,1),'ci',nan(1,2)), ...
                      'rmseCoV',struct('mean',nan(1,1),'ci',nan(1,2)), ...
                      'rSquare',struct('mean',nan(1,1),'ci',nan(1,2)), ...
                      'fitSuccess',struct('mean',nan(1,1)));
         end
      case 'rateVsRtPower1_W'
         for iEmpty = 1:numel(emptyCell)
            simData.rateVsRtPower1_W{emptyCell(iEmpty)} = ...
               struct('dataX',struct('mean',nan(1,50),'ci',nan(2,50)), ...
                      'dataY',struct('mean',nan(1,50),'ci',nan(2,50)), ...
                      'params',struct('mean',nan(1,2),'ci',nan(2,2),'sign',nan(1,2),'data',nan(1000,2)), ...
                      'paramsSign',struct('data',nan(1000,2)), ...
                      'rmse',struct('mean',nan(1,1),'ci',nan(1,2)), ...
                      'rmseCoV',struct('mean',nan(1,1),'ci',nan(1,2)), ...
                      'rSquare',struct('mean',nan(1,1),'ci',nan(1,2)), ...
                      'fitSuccess',struct('mean',nan(1,1)));
         end
      case 'rateVsRtRat01_H'
         for iEmpty = 1:numel(emptyCell)
            simData.rateVsRtRat01_H{emptyCell(iEmpty)} = ...
               struct('dataX',struct('mean',nan(1,50),'ci',nan(2,50)), ...
                      'dataY',struct('mean',nan(1,50),'ci',nan(2,50)), ...
                      'params',struct('mean',nan(1,2),'ci',nan(2,2),'sign',nan(1,2),'data',nan(1000,2)), ...
                      'paramsSign',struct('data',nan(1000,2)), ...
                      'rmse',struct('mean',nan(1,1),'ci',nan(1,2)), ...
                      'rmseCoV',struct('mean',nan(1,1),'ci',nan(1,2)), ...
                      'rSquare',struct('mean',nan(1,1),'ci',nan(1,2)), ...
                      'fitSuccess',struct('mean',nan(1,1)));
         end
      case 'rateVsRtRat01_W'
         for iEmpty = 1:numel(emptyCell)
            simData.rateVsRtRat01_W{emptyCell(iEmpty)} = ...
               struct('dataX',struct('mean',nan(1,50),'ci',nan(2,50)), ...
                      'dataY',struct('mean',nan(1,50),'ci',nan(2,50)), ...
                      'params',struct('mean',nan(1,2),'ci',nan(2,2),'sign',nan(1,2),'data',nan(1000,2)), ...
                      'paramsSign',struct('data',nan(1000,2)), ...
                      'rmse',struct('mean',nan(1,1),'ci',nan(1,2)), ...
                      'rmseCoV',struct('mean',nan(1,1),'ci',nan(1,2)), ...
                      'rSquare',struct('mean',nan(1,1),'ci',nan(1,2)), ...
                      'fitSuccess',struct('mean',nan(1,1)));
         end
   end
end