
%% Settings

settings.subplotType = 'subplot'; % 'panel' or 'subplot'
settings.doMask = 0; % yes (1) or no (0)
settings.maskType = 'hatch'; % 'hatch', 'contour', 'nanonly'

settings.colorBar = 1; % on (1) or off (0)
settings.title = 0; % on (1) or off (0)
settings.tickLabel = 0; % on (1) or off (0)

settings.saveFigure = 0; % yes (1) or no (0)

settings.plotType = 'heat';
settings.outcomeMeasure = 'thresVsRtPoly1';        % medianRt, dtActPeakRt, thresVsRtPoly1,rateVsRtPower1,rateVsRtRat01 raw_threshold
settings.outcomeMeasureAspect = 'meanParams';        % meanParams, signParamsFraction, meanRMSE, CoVRMSE, meanRSquare

settings.linePlotInteractive = 1; % yes (1) or no (0)

h = 1; % aLim index

dataDir = '/Users/bram/Documents/EPU/Simulation_2012May03/output/PerfectDeterministic/';
noALim = 1;
% dataDir = '/Users/bram/Documents/EPU/Simulation_2012May03/output/LeakyDeterministic/';
% noALim = 0;
% dataDir = '/Users/bram/Documents/EPU/Simulation_2012May03/output/PerfectStochastic/';
% noALim = 1;
% dataDir = '/Users/bram/Documents/EPU/Simulation_2012May03/output/LeakyStochastic/';
% noALim = 1;
figureDir = '/Users/bram/Documents/EPU/Simulation_2012May03/figures/';

switch settings.plotType
   case 'line'
      
      mT = {'40','60','80','100','120'};
      mR = {'025','050','075','100','125'};
      nA = {'10'};
%       nA = {'10','100','1000'};
      if ~noALim
         aLimit = {'100000'};
      end
      
      for i = 4%:5 % mT
            for j = 3%:5 % mR
               
               % Set up figure, whole screen
               screenSize = get(0,'ScreenSize');
               figureWidth = 30;
               figureHeight = 22.5;
               hFig = figure('Color',[1 1 1],...
                             'PaperPosition',[0 0 figureWidth figureHeight],...
                             'PaperUnits','centimeters',...
                             'PaperSize',[figureWidth figureHeight]);
                 
               % Set up panels
               switch settings.subplotType
                  case 'panel'
                     p = panel('defer');
                     p.pack(2,numel(nA)); % for each nA: first row heat plot, second row line plot
                  case 'subplot'
                     counter = 0;
               end
               
               for k = 1:numel(nA);
                  
                  % Load data
                  clear simDataMulti
                  if ~noALim
                     n = char(regexpdir(dataDir,['sim_nA',nA{k},'_mR',mR{j},'_mT',mT{i},'_aLim',aLimit{h},'.*MultiData.mat$'],0));
                  else
                     n = char(regexpdir(dataDir,['sim_nA',nA{k},'_mR',mR{j},'_mT',mT{i},'.*MultiData.mat$'],0));
                  end
                  load(n)
                  
                  % Somehow, there is a problem with identification of the value .3 in datasets
%                   simDataMulti.q(find(simDataMulti.q > .29 & simDataMulti.q < .31)) = 3/10;
%                   simDataMulti.r(find(simDataMulti.r > .29 & simDataMulti.r < .31)) = 3/10;
                  
                  switch settings.subplotType
                     case 'panel'
                        thisPanel = p(1,k).select();
                     case 'subplot'
                        thisPanel = subplot(2,numel(nA),k);
                  end
                  
                  % Make heat plot
                  x = simDataMulti.q; % Fraction
                  y = simDataMulti.r; % Correlation

                  switch settings.outcomeMeasure
                     case 'medianRt'
                        z = cellfun(@(x) x.mean,simDataMulti.medianRt); % The median response time
                        mnZ = 100;
                        mxZ = 1000;
                        colorMap = colormap('jet');
                        colorMap = flipud(colorMap);
                     case 'dtActPeakRt'
                        % Find empty cells
                        emptyCell = cellfun(@(x) isempty(x), simDataMulti.dtActPeakRt);
                        emptyCell = find(emptyCell);

                        % Fill empty cells with nans
                        for iEmpty = 1:numel(emptyCell)
                           simDataMulti.dtActPeakRt{emptyCell(iEmpty)} = ...
                           struct('mean',nan(1,1),...
                                  'ci95',nan(1,2),...
                                  'sign',nan(1,1));
                        end
                        
                        z = cellfun(@(x) x.mean,simDataMulti.dtActPeakRt); % Time between peak activation and RT
                        mnZ = -200;
                        mxZ = 0;
                        colorMap = 'bluewhitered';
                     case 'thresVsRtPoly1'
                        switch settings.outcomeMeasureAspect
                           case 'meanParams'
                              % Find empty cells
                              emptyCell = cellfun(@(x) isempty(x), simDataMulti.thresVsRtPoly1);
                              emptyCell = find(emptyCell);

                              % Fill empty cells with nans
                              for iEmpty = 1:numel(emptyCell)
                                 simDataMulti.thresVsRtPoly1{emptyCell(iEmpty)} = ...
                                 struct('meanParams',nan(1,2),...
                                        'medianParams',nan(1,2),...
                                        'ciParams',nan(2,2),...
                                        'signParamsOverall',nan(1,2),...
                                        'signParamsFraction',nan(3,3),...
                                        'meanRMSE',nan(1,1),...
                                        'medianRMSE',nan(1,1),...
                                        'ciRMSE',nan(1,2),...
                                        'meanRSquare',nan(1,1),...
                                        'medianRSquare',nan(1,1),...
                                        'ciRSquare',nan(1,2),...
                                        'exitFlagFraction',nan(19,2));
                              end
                              
                              z = cellfun(@(x) x.meanParams(1),simDataMulti.thresVsRtPoly1); % Slope of linear regression line
                              mnZ = -.2;
                              mxZ = .2;
                              colorMap = 'bluewhitered';
                           case 'signParamsFraction'
                              z = cellfun(@(x) x.signParamsFraction(2,2),simDataMulti.thresVsRtPoly1); % Fraction of sessions with a non-significant slope of linear regression line
                              mnZ = 0;
                              mxZ = 1;
                              colorMap = flipud(cbrewer('seq','RdPu',21));
                           case 'meanRMSE'
                              z = cellfun(@(x) x.meanRMSE,simDataMulti.thresVsRtPoly1); % Root mean square error
                              % RMSE in Hanes & Schall 1996 is estimated at 8
                              mnZ = 0;
                              mxZ = 16;
                              colorMap = cbrewer('div','PiYG',17);
%                               colorMap = colormap('bluewhitered');
                           case 'meanRSquare'
                              z = cellfun(@(x) x.meanRSquare,simDataMulti.thresVsRtPoly1); % Root mean square error
                              mnZ = 0;
                              mxZ = 1;
                              colorMap = cbrewer('seq','RdPu',21);
                        end
                     case 'rateVsRtPoly1'
                        z = cellfun(@(x) x.meanParams(1),simDataMulti.rateVsRtPoly1); % Slope of linear regression line
                     case 'rateVsRtPower1'
                        z = cellfun(@(x) x.meanParams(2),simDataMulti.rateVsRtPower1);
                     case 'rateVsRtRat01'
                  
                        % Find empty cells
                        emptyCell = cellfun(@(x) isempty(x), simDataMulti.rateVsRtRat01);
                        emptyCell = find(emptyCell);

                        % Fill empty cells with nans
                        for iEmpty = 1:numel(emptyCell)
                           simDataMulti.rateVsRtRat01{emptyCell(iEmpty)} = ...
                           struct('meanParams',nan(1,2),...
                                  'medianParams',nan(1,2),...
                                  'ciParams',nan(2,2),...
                                  'signParamsOverall',nan(1,2),...
                                  'signParamsFraction',nan(3,3),...
                                  'meanRMSE',nan(1,1),...
                                  'medianRMSE',nan(1,1),...
                                  'ciRMSE',nan(1,2),...
                                  'meanRSquare',nan(1,1),...
                                  'medianRSquare',nan(1,1),...
                                  'ciRSquare',nan(1,2),...
                                  'exitFlagFraction',nan(19,2));
                        end
                        
                        z = cellfun(@(x) x.meanParams(1),simDataMulti.rateVsRtRat01); % Slope of linear regression line
                        mnZ = -500;
                        mxZ = 500;
                        colorMap = 'bluewhitered';
                        
                  end
                  ppa = sqrt(numel(x)); % Number of data points per axis
                  
                  imagesc(x,flipdim(y,1),flipdim(vec2mat(z,ppa),1),[mnZ,mxZ]);
                  colormap(colorMap);
                  
                  if settings.doMask

                  switch settings.outcomeMeasure
                     case 'medianRt'
%                         medRtBnds = [150 1000];
                        medRtBnds = [190 600]; % Based on 95% CI in visual search data set with set sizes 2, 4, 8; see: EPU/ModelFitting_Jan26/m-files
%                          medRtBnds = [190 460]; % Based on 90% CI in visual search data set with set sizes 2, 4, 8; see: EPU/ModelFitting_Jan26/m-files
                        msk = cell2mat(cellfun(@(x) all(x.ci95 < medRtBnds(1)) | all(x.ci95 > medRtBnds(2)),simDataMulti.medianRt,'UniformOutput',0)); % Any median RT confidence bounds fully out of reasonable range
                        msk = vec2mat(msk,ppa);
                        mat = vec2mat(z,ppa);
                        
                        outline = pixel_outline(mat,msk);
                         
                        % Pixels in which parameter equals NaN
                        nanmsk = isnan(cellfun(@(x) x.mean,simDataMulti.medianRt));
                        nanmsk = vec2mat(nanmsk,ppa);
                        nanoutline = pixel_outline(mat,nanmsk);
                     case 'dtActPeakRt'
                        msk = abs(cellfun(@(x) x.mean,simDataMulti.dtActPeakRt)) > 50;
                        msk = vec2mat(msk,ppa);
                        mat = vec2mat(z,ppa);
                        
                        outline = pixel_outline(mat,msk);
                         
                        % Pixels in which fitted parameter equals NaN
                        nanmsk = isnan(cellfun(@(x) x.mean,simDataMulti.dtActPeakRt));
                        nanmsk = vec2mat(nanmsk,ppa);
                        nanoutline = pixel_outline(mat,nanmsk);
                         
                     case 'thresVsRtPoly1'
                         
                         switch settings.outcomeMeasureAspect
                               case 'meanParams'
                                  msk = cellfun(@(x) x.signParamsOverall(1),simDataMulti.thresVsRtPoly1) ~= 0;
                                  msk = vec2mat(msk,ppa);
                                  mat = vec2mat(z,ppa);

                                  outline = pixel_outline(mat,msk);

                                  % Pixels in which fitted parameter equals NaN
                                  nanmsk = isnan(cellfun(@(x) x.meanParams(1),simDataMulti.thresVsRtPoly1));
                                  nanmsk = vec2mat(nanmsk,ppa);
                                  nanoutline = pixel_outline(mat,nanmsk);
                               case 'meanRMSE'
                                  mat = vec2mat(z,ppa);
                                  
                                  % Pixels in which fitted parameter equals NaN
                                  nanmsk = isnan(cellfun(@(x) x.meanRMSE,simDataMulti.thresVsRtPoly1));
                                  nanmsk = vec2mat(nanmsk,ppa);
                                  nanoutline = pixel_outline(mat,nanmsk);
                               case 'meanRSquare'
                                  mat = vec2mat(z,ppa);
                                  
                                  % Pixels in which fitted parameter equals NaN
                                  nanmsk = isnan(cellfun(@(x) x.meanRSquare,simDataMulti.thresVsRtPoly1));
                                  nanmsk = vec2mat(nanmsk,ppa);
                                  nanoutline = pixel_outline(mat,nanmsk);
                               case 'signParamsFraction'
                                  mat = vec2mat(z,ppa);
                                  
                                  % Pixels in which fitted parameter equals NaN
                                  nanmsk = isnan(cellfun(@(x) x.signParamsFraction(1),simDataMulti.thresVsRtPoly1));
                                  nanmsk = vec2mat(nanmsk,ppa);
                                  nanoutline = pixel_outline(mat,nanmsk);
                         end
                         
                      case 'rateVsRtPoly1'
                         msk = cellfun(@(x) x.signParamsOverall(1),simDataMulti.rateVsRtPoly1) ~= -1; % A negative sign of the second parameter of the linear function indicates a decreasing trend
                         msk = vec2mat(msk,ppa);
                         mat = vec2mat(z,ppa);

                         outline = pixel_outline(mat,msk);
                         
                         % Pixels in which fitted parameter equals NaN
                         nanmsk = isnan(cellfun(@(x) x.meanParams(1),simDataMulti.rateVsRtPoly1));
                         nanmsk = vec2mat(nanmsk,ppa);
                         nanoutline = pixel_outline(mat,nanmsk);
                         
                      case 'rateVsRtRat01'
                         msk = cellfun(@(x) x.signParamsOverall(1),simDataMulti.rateVsRtRat01) ~= 1; % A positive sign of the first parameter of the rational function indicates a decreasing trend
                         msk = vec2mat(msk,ppa);
                         mat = vec2mat(z,ppa);

                         outline = pixel_outline(mat,msk);
                         
                         % Pixels in which fitted parameter equals NaN
                         nanmsk = isnan(cellfun(@(x) x.meanParams(1),simDataMulti.rateVsRtRat01));
                         nanmsk = vec2mat(nanmsk,ppa);
                         nanoutline = pixel_outline(mat,nanmsk);
                     end

                     switch lower(settings.maskType)
                      case 'hatch'
                         for l = 1:numel(outline)
                            hPatch{l} = patch(outline{l}(:,2),outline{l}(:,1),[1 1 1]);
                            hPatch{l} = hatchfill(hPatch{l},'single',45,3);
                         end
                         
                         if ~isempty(nanoutline)
                            for l = 1:numel(nanoutline)
                               hNanPatch{l} = patch(nanoutline{l}(:,2),nanoutline{l}(:,1),[0.5 0.5 0.5],'EdgeColor','none');
                            end
                         end
                         
                      case 'contour'
                         for l = 1:numel(outline)
                            plot(outline{l}(:,2), outline{l}(:,1), 'k', 'Linewidth', 2)
                         end
                         
                         if ~isempty(nanoutline)
                            for l = 1:numel(nanoutline)
                               hNanPatch{l} = patch(nanoutline{l}(:,2),nanoutline{l}(:,1),[0.5 0.5 0.5],'EdgeColor','none');
                            end
                         end
                      case 'nanonly'
                         if ~isempty(nanoutline)
                            for l = 1:numel(nanoutline)
                               hNanPatch{l} = patch(nanoutline{l}(:,2),nanoutline{l}(:,1),[0.5 0.5 0.5],'EdgeColor','none');
                            end
                         end
                     end
                  end
                  
                  % Axis properties
                  set (gca, 'XTick',[0:.2:1],...
                            'YTick',[0:.2:1]);
                  
                  if settings.colorBar == 1
                     hColorbar = colorbar('peer', thisPanel);
                  elseif settings.colorBar == 2
                     if i ==1 & j == 1
                        thisFig = gcf;
                        thisAxis = gca;
                        figure;
                        imagesc(x,flipdim(y,1),flipdim(vec2mat(z,ppa),1),[mnZ,mxZ]);
                        colormap(bluewhitered);
                        colorbar;
                        axis('xy','image');
                        figure(thisFig);
                        axes(thisAxis);
                     end
                  end


                  switch settings.subplotType
                     case 'panel'
                        p(i,j,1,2).select(h_colorbar_axis);
                  end
               
                  axis('xy','image');
                  
                  % Selection of q and r combinations for plotting lines
                  if settings.linePlotInteractive
                     disp('Click data points for which to plot lines; when finished press Enter');
                     [X,Y] = ginput;
                     X = roundn(X,-1);
                     Y = roundn(Y,-1);
                     for iPts = 1:length(X)
                        text(X(iPts),Y(iPts),num2roman(iPts),'FontWeight','bold');
                     end
                     
                     
                  else
                     X = [0 1 1 0 .3 .5 .7]';
                     Y = [0 0 1 1 .3 .5 .7]';
                     for iPts = 1:length(X)
                        text(X(iPts),Y(iPts),num2roman(iPts),'FontWeight','bold','HorizontalAlignment','center');
                     end
                  end
                  
                  %% Make line plot
                  switch settings.subplotType
                     case 'panel'
                        p(2,k).select();
                     case 'subplot'
                        subplot(2,numel(nA),numel(nA)+k);
                  end
                  
                  hold on;
                  
                  % Line color management
                  lineColors = getcmaprgbs('gray',[1 size(X,1)+1]);
                  lineColors = double(lineColors(:,[2:4]))./255;
                  
                  for iPts = 1:length(X)
                     % Select data point
                     iSim = find(simDataMulti.q == X(iPts) & ...
                                 simDataMulti.r == Y(iPts));
                     
                     switch settings.outcomeMeasure
                        case 'medianRt'
                           tline = simDataMulti.rtCdf{iSim}.mean;
                           yline = simDataMulti.FCdf{iSim}.mean;
                        case 'dtActPeakRt'
                           tline = -200:1:0;
                           yline = simDataMulti.rtAlignedTrajectories{iSim}.mean;
                        case 'thresVsRtPoly1'
                           tline = simDataMulti.rtBinned{iSim}.mean;
                           yline = simDataMulti.thresholdBinned{iSim}.mean;
                           fun = @(a,b) a*tline + b;
                           params = simDataMulti.thresVsRtPoly1{iSim}.meanParams;
                           p1 = params(1);
                           p2 = params(2);
                           fun = @(p1,q1) p1*tline + p2;
                        case 'rateVsRtRat01'
                           tline = simDataMulti.rtBinned{iSim}.mean;
                           yline = simDataMulti.rateBinned{iSim}.mean;
                           params = simDataMulti.rateVsRtRat01{iSim}.meanParams;
                           p1 = params(1);
                           q1 = params(2);
                           fun = @(p1,q1) (p1)./(tline + q1);
                     end
                              
                     % Plot data points
                     hLinePlot = plot(tline,yline, ...
                                       'Color',lineColors(iPts,:));
                                    
                     switch settings.outcomeMeasure
                        case 'medianRt'
                           thres = simDataMulti.mT(iSim);
                           limit = simDataMulti.aLim(iSim);
                           
                           set(hLinePlot,'LineStyle','-',...
                                         'Marker','none');
                           set(gca,'XLim',[0 2000]);
                                      
                                      
                        case 'dtActPeakRt'
                           thres = simDataMulti.mT(iSim);
                           limit = simDataMulti.aLim(iSim);
                           
                           set(hLinePlot,'LineStyle','-',...
                                         'Marker','none');
                  
                           set(gca,'XLim',[-200 200],...
                                   'YLim',[0 thres./limit]);
                        case 'thresVsRtPoly1'
                           set(hLinePlot,'HandleVisibility','off',...  % Handle visibility off to prevent legend to show points and line separately   
                                         'LineStyle','none',...
                                         'Marker','.',...
                                         'MarkerSize',20);
                           
                           
                           % Plot fit line
                           params = simDataMulti.thresVsRtPoly1{iSim}.meanParams;
                           plot(tline,fun(params(2),params(1)),...
                              'Color',lineColors(iPts,:));
                           
                           thres = simDataMulti.mT(iSim);
                           limit = simDataMulti.aLim(iSim);
                  
                           set(gca,'XLim',[0 1000],...
                                   'YLim',[0 thres./limit]);
                       
                        case 'rateVsRtRat01'
                           set(gca,'XLim',[0 350]);



                     end
                     
                  end
                  
                  legend(num2roman([1:size(X,1)]),'Location','Best');
                  
                  axis square
                  
               
               end
               
            end
      end
      
      if settings.saveFigure
         % Save figure
         if ~noALim
            print(hFig,'-depsc',fullfile(figureDir,[settings.outcomeMeasure,'_',settings.plotType,'_mR',mR{j},'_and_mT',mT{i},'_for_nA',nA{k},'_aLim',aLimit{h},'_cBarLim',strrep([num2str(mnZ),'to',num2str(mxZ)],'.','')]));
         else
            print(hFig,'-depsc',fullfile(figureDir,[settings.outcomeMeasure,'_',settings.plotType,'_mR',mR{j},'_and_mT',mT{i},'_for_nA',nA{k},'_cBarLim',strrep([num2str(mnZ),'to',num2str(mxZ)],'.','')]));
         end
      end

   case 'heat'
      for k = 1 % nA index

         %% Set up figure, whole screen
         screenSize = get(0,'ScreenSize');
         figureWidth = 30;
         figureHeight = 22.5;
         hFig = figure('Color',[1 1 1],...
                       'PaperPosition',[0 0 figureWidth figureHeight],...
                       'PaperUnits','centimeters',...
                       'PaperSize',[figureWidth figureHeight]);

         % Set up panels
         switch settings.subplotType
            case 'panel'
               p = panel('defer');
               p.pack(2,2);
            case 'subplot'
               counter = 0;
         end

         mT = {'40','60','80','100','120'};
         mR = {'025','050','075','100','125'};
         nA = {'10'};
%          nA = {'10','100','1000'};
         if ~noALim
             aLimit = {'100000'};
         end
         
         for i = 4; % mT
            for j = 3; % mR
               
                  for k = 1:numel(nA);

                  % Load data
                  clear simDataMulti
                  if ~noALim
                     n = char(regexpdir(dataDir,['sim_nA',nA{k},'_mR',mR{j},'_mT',mT{i},'_aLim',aLimit{h},'.*MultiData.mat$'],0));
                  else
                     n = char(regexpdir(dataDir,['sim_nA',nA{k},'_mR',mR{j},'_mT',mT{i},'.*MultiData.mat$'],0));
                  end
                  load(n)


                  switch settings.subplotType
                     case 'panel'
                        p(i,j).pack('h',[-1 30]);
                        thisPanel = p(i,j,1,1).select();

                     case 'subplot'
                        counter = counter + 1;
                        thisPanel = subplot(1,numel(nA),counter);
                  end

                  x = simDataMulti.q; % Fraction
                  y = simDataMulti.r; % Correlation

                  switch settings.outcomeMeasure
                     case 'medianRt'
                        % Find empty cells
                        emptyCell = cellfun(@(x) isempty(x), simDataMulti.medianRt);
                        emptyCell = find(emptyCell);
                        
                        % Fill empty cells with nans
                        for iEmpty = 1:numel(emptyCell)
                           simDataMulti.medianRt{emptyCell(iEmpty)} = ...
                              struct('mean',nan(1,1),...
                                     'ci95',nan(1,2));
                        end

                        z = cellfun(@(x) x.mean,simDataMulti.medianRt); % The median response time
                        mnZ = 100;
                        mxZ = 1000;
                        colorMap = colormap('jet');
                        colorMap = flipud(colorMap);
                     case 'exGaussian_mu'
                        % Find empty cells
                        emptyCell = cellfun(@(x) isempty(x), simDataMulti.rt_exGauss);
                        emptyCell = find(emptyCell);

                        % Fill empty cells with nans
                        for iEmpty = 1:numel(emptyCell)
                           simDataMulti.rt_exGauss{emptyCell(iEmpty)} = ...
                           struct('meanParams',nan(1,2),...
                                        'medianParams',nan(1,2),...
                                        'ciParams',nan(2,2),...
                                        'signParamsOverall',nan(1,2),...
                                        'signParamsFraction',nan(3,3),...
                                        'meanRMSE',nan(1,1),...
                                        'medianRMSE',nan(1,1),...
                                        'ciRMSE',nan(1,2),...
                                        'meanRSquare',nan(1,1),...
                                        'medianRSquare',nan(1,1),...
                                        'ciRSquare',nan(1,2),...
                                        'exitFlagFraction',nan(19,2));
                        end

                        z = cellfun(@(x) x.meanParams(1),simDataMulti.rt_exGauss); % The median response time
                        mnZ = 100;
                        mxZ = 1000;
                        colorMap = 'jet';
                     case 'exGaussian_sigma'
                        % Find empty cells
                        emptyCell = cellfun(@(x) isempty(x), simDataMulti.rt_exGauss);
                        emptyCell = find(emptyCell);

                        % Fill empty cells with nans
                        for iEmpty = 1:numel(emptyCell)
                           simDataMulti.rt_exGauss{emptyCell(iEmpty)} = ...
                           struct('meanParams',nan(1,2),...
                                        'medianParams',nan(1,2),...
                                        'ciParams',nan(2,2),...
                                        'signParamsOverall',nan(1,2),...
                                        'signParamsFraction',nan(3,3),...
                                        'meanRMSE',nan(1,1),...
                                        'medianRMSE',nan(1,1),...
                                        'ciRMSE',nan(1,2),...
                                        'meanRSquare',nan(1,1),...
                                        'medianRSquare',nan(1,1),...
                                        'ciRSquare',nan(1,2),...
                                        'exitFlagFraction',nan(19,2));
                        end

                        z = cellfun(@(x) x.meanParams(2),simDataMulti.rt_exGauss); % The median response time
                        mnZ = 0;
                        mxZ = 100;
                        colorMap = 'jet';
                     case 'exGaussian_tau'
                        % Find empty cells
                        emptyCell = cellfun(@(x) isempty(x), simDataMulti.rt_exGauss);
                        emptyCell = find(emptyCell);

                        % Fill empty cells with nans
                        for iEmpty = 1:numel(emptyCell)
                           simDataMulti.rt_exGauss{emptyCell(iEmpty)} = ...
                           struct('meanParams',nan(1,2),...
                                  'ci95FittedParams',nan(2,2),...
                                  'meanSSE',nan,...
                                  'ci95SSE',nan(1,2),...
                                  'meanRSquare',nan,...
                                  'ci95RSquare',nan(1,2),...
                                  'successRate',nan);
                        end
                        z = cellfun(@(x) x.meanParams(3),simDataMulti.rt_exGauss); % The median response time
                        mnZ = 0;
                        mxZ = 500;
                        colorMap = 'jet';
                     case 'dtActPeakRt'
                        % Find empty cells
                        emptyCell = cellfun(@(x) isempty(x), simDataMulti.dtActPeakRt);
                        emptyCell = find(emptyCell);

                        % Fill empty cells with nans
                        for iEmpty = 1:numel(emptyCell)
                           simDataMulti.dtActPeakRt{emptyCell(iEmpty)} = ...
                           struct('mean',nan(1,1),...
                                  'ci95',nan(1,2),...
                                  'sign',nan(1,1));
                        end
                        
                        z = cellfun(@(x) x.mean,simDataMulti.dtActPeakRt); % Time between peak activation and RT
                        mnZ = -200;
                        mxZ = 0;
                        colorMap = 'bluewhitered';
                     case 'raw_threshold'
                        z = cellfun(@(x) mean(x.mean),simDataMulti.thresholdBinned); % Time between peak activation and RT
                        mnZ = 0;
                        mxZ = 200;
                        C = flipud(cbrewer('div','RdBu',64))
                        colorMap = C;
                     case 'thresVsRtPoly1'
                        switch settings.outcomeMeasureAspect
                           case 'meanParams'
                              % Find empty cells
                              emptyCell = cellfun(@(x) isempty(x), simDataMulti.thresVsRtPoly1);
                              emptyCell = find(emptyCell);

                              % Fill empty cells with nans
                              for iEmpty = 1:numel(emptyCell)
                                 simDataMulti.thresVsRtPoly1{emptyCell(iEmpty)} = ...
                                 struct('meanParams',nan(1,2),...
                                        'medianParams',nan(1,2),...
                                        'ciParams',nan(2,2),...
                                        'signParamsOverall',nan(1,2),...
                                        'signParamsFraction',nan(3,3),...
                                        'meanRMSE',nan(1,1),...
                                        'medianRMSE',nan(1,1),...
                                        'ciRMSE',nan(1,2),...
                                        'meanRSquare',nan(1,1),...
                                        'medianRSquare',nan(1,1),...
                                        'ciRSquare',nan(1,2),...
                                        'exitFlagFraction',nan(19,2));
                              end
                              
                              z = cellfun(@(x) x.meanParams(1),simDataMulti.thresVsRtPoly1); % Slope of linear regression line
                              mnZ = -.2;
                              mxZ = .2;
                              colorMap = 'bluewhitered';
                           case 'signParamsFraction'
                              % Find empty cells
                              emptyCell = cellfun(@(x) isempty(x), simDataMulti.thresVsRtPoly1);
                              emptyCell = find(emptyCell);

                              % Fill empty cells with nans
                              for iEmpty = 1:numel(emptyCell)
                                 simDataMulti.thresVsRtPoly1{emptyCell(iEmpty)} = ...
                                 struct('meanParams',nan(1,2),...
                                        'medianParams',nan(1,2),...
                                        'ciParams',nan(2,2),...
                                        'signParamsOverall',nan(1,2),...
                                        'signParamsFraction',nan(3,3),...
                                        'meanRMSE',nan(1,1),...
                                        'medianRMSE',nan(1,1),...
                                        'ciRMSE',nan(1,2),...
                                        'meanRSquare',nan(1,1),...
                                        'medianRSquare',nan(1,1),...
                                        'ciRSquare',nan(1,2),...
                                        'exitFlagFraction',nan(19,2));
                              end
                              
                              z = cellfun(@(x) x.signParamsFraction(2,2),simDataMulti.thresVsRtPoly1); % Fraction of sessions with a non-significant slope of linear regression line
                              mnZ = 0;
                              mxZ = 1;
                              colorMap = flipud(cbrewer('seq','RdPu',21));
                           case 'meanRMSE'
                              % Find empty cells
                              emptyCell = cellfun(@(x) isempty(x), simDataMulti.thresVsRtPoly1);
                              emptyCell = find(emptyCell);

                              % Fill empty cells with nans
                              for iEmpty = 1:numel(emptyCell)
                                 simDataMulti.thresVsRtPoly1{emptyCell(iEmpty)} = ...
                                 struct('meanParams',nan(1,2),...
                                        'medianParams',nan(1,2),...
                                        'ciParams',nan(2,2),...
                                        'signParamsOverall',nan(1,2),...
                                        'signParamsFraction',nan(3,3),...
                                        'meanRMSE',nan(1,1),...
                                        'medianRMSE',nan(1,1),...
                                        'ciRMSE',nan(1,2),...
                                        'meanRSquare',nan(1,1),...
                                        'medianRSquare',nan(1,1),...
                                        'ciRSquare',nan(1,2),...
                                        'exitFlagFraction',nan(19,2));
                              end
                              
                              z = cellfun(@(x) x.meanRMSE,simDataMulti.thresVsRtPoly1); % Root mean square error
                              % RMSE in Hanes & Schall 1996 is estimated at 8
                              mnZ = 0;
                              mxZ = 16;
                              colorMap = cbrewer('div','PiYG',17);
%                               colorMap = colormap('bluewhitered');
                           case 'CoVRMSE'
                               % Find empty cells
                              emptyCell = cellfun(@(x) isempty(x), simDataMulti.thresVsRtPoly1);
                              emptyCell = find(emptyCell);

                              % Fill empty cells with nans
                              for iEmpty = 1:numel(emptyCell)
                                 simDataMulti.thresVsRtPoly1{emptyCell(iEmpty)} = ...
                                 struct('meanParams',nan(1,2),...
                                        'medianParams',nan(1,2),...
                                        'ciParams',nan(2,2),...
                                        'signParamsOverall',nan(1,2),...
                                        'signParamsFraction',nan(3,3),...
                                        'meanRMSE',nan(1,1),...
                                        'medianRMSE',nan(1,1),...
                                        'CoVRMSE',nan(1,1),...
                                        'ciRMSE',nan(1,2),...
                                        'meanRSquare',nan(1,1),...
                                        'medianRSquare',nan(1,1),...
                                        'ciRSquare',nan(1,2),...
                                        'exitFlagFraction',nan(19,2));
                              end
                              z = cellfun(@(x) x.CoVRMSE,simDataMulti.thresVsRtPoly1); % Root mean square error
                              mnZ = 0;
                              mxZ = 0.25;
                              colorMap = cbrewer('div','PiYG',21);
%                               colorMap = colormap('jet');
                           case 'meanRSquare'
                              % Find empty cells
                              emptyCell = cellfun(@(x) isempty(x), simDataMulti.thresVsRtPoly1);
                              emptyCell = find(emptyCell);

                              % Fill empty cells with nans
                              for iEmpty = 1:numel(emptyCell)
                                 simDataMulti.thresVsRtPoly1{emptyCell(iEmpty)} = ...
                                 struct('meanParams',nan(1,2),...
                                        'medianParams',nan(1,2),...
                                        'ciParams',nan(2,2),...
                                        'signParamsOverall',nan(1,2),...
                                        'signParamsFraction',nan(3,3),...
                                        'meanRMSE',nan(1,1),...
                                        'medianRMSE',nan(1,1),...
                                        'CoVRMSE',nan(1,1),...
                                        'ciRMSE',nan(1,2),...
                                        'meanRSquare',nan(1,1),...
                                        'medianRSquare',nan(1,1),...
                                        'ciRSquare',nan(1,2),...
                                        'exitFlagFraction',nan(19,2));
                              end
                              
                              z = cellfun(@(x) x.meanRSquare,simDataMulti.thresVsRtPoly1); % Root mean square error
                              mnZ = 0;
                              mxZ = 1;
                              colorMap = cbrewer('seq','RdPu',21);
                        end
                     case 'rateVsRtPoly1'
                        switch settings.outcomeMeasureAspect
                           case 'meanRSquare'
                              % Find empty cells
                              emptyCell = cellfun(@(x) isempty(x), simDataMulti.rateVsRtPoly1);
                              emptyCell = find(emptyCell);

                              % Fill empty cells with nans
                              for iEmpty = 1:numel(emptyCell)
                                 simDataMulti.rateVsRtPoly1{emptyCell(iEmpty)} = ...
                                 struct('meanParams',nan(1,2),...
                                              'medianParams',nan(1,2),...
                                              'ciParams',nan(2,2),...
                                              'signParamsOverall',nan(1,2),...
                                              'signParamsFraction',nan(3,3),...
                                              'meanRMSE',nan(1,1),...
                                              'medianRMSE',nan(1,1),...
                                              'ciRMSE',nan(1,2),...
                                              'meanRSquare',nan(1,1),...
                                              'medianRSquare',nan(1,1),...
                                              'ciRSquare',nan(1,2),...
                                              'exitFlagFraction',nan(19,2));
                              end


                              z = cellfun(@(x) x.meanRSquare,simDataMulti.rateVsRtPoly1); % Slope of linear regression line

                              mnZ = 0;
                              mxZ = 1;
                              colorMap = cbrewer('seq','RdPu',21);
                        end
                        
                     case 'rateVsRtPower1'
                        switch settings.outcomeMeasureAspect
                           case 'meanRSquare'
                              % Find empty cells
                              emptyCell = cellfun(@(x) isempty(x), simDataMulti.rateVsRtPower1);
                              emptyCell = find(emptyCell);

                              % Fill empty cells with nans
                              for iEmpty = 1:numel(emptyCell)
                                 simDataMulti.rateVsRtPower1{emptyCell(iEmpty)} = ...
                                 struct('meanParams',nan(1,2),...
                                              'medianParams',nan(1,2),...
                                              'ciParams',nan(2,2),...
                                              'signParamsOverall',nan(1,2),...
                                              'signParamsFraction',nan(3,3),...
                                              'meanRMSE',nan(1,1),...
                                              'medianRMSE',nan(1,1),...
                                              'ciRMSE',nan(1,2),...
                                              'meanRSquare',nan(1,1),...
                                              'medianRSquare',nan(1,1),...
                                              'ciRSquare',nan(1,2),...
                                              'exitFlagFraction',nan(19,2));
                              end

                              z = cellfun(@(x) x.meanRSquare,simDataMulti.rateVsRtPower1); % Slope of linear regression line

                              mnZ = 0;
                              mxZ = 1;
                              colorMap = cbrewer('seq','RdPu',21);
                        
                        end
                        
                     case 'rateVsRtRat01'
                        
                        % Find empty cells
                        emptyCell = cellfun(@(x) isempty(x), simDataMulti.rateVsRtRat01);
                        emptyCell = find(emptyCell);

                        % Fill empty cells with nans
                        for iEmpty = 1:numel(emptyCell)
                           simDataMulti.rateVsRtRat01{emptyCell(iEmpty)} = ...
                           struct('meanParams',nan(1,2),...
                                        'medianParams',nan(1,2),...
                                        'ciParams',nan(2,2),...
                                        'signParamsOverall',nan(1,2),...
                                        'signParamsFraction',nan(3,3),...
                                        'meanRMSE',nan(1,1),...
                                        'medianRMSE',nan(1,1),...
                                        'ciRMSE',nan(1,2),...
                                        'meanRSquare',nan(1,1),...
                                        'medianRSquare',nan(1,1),...
                                        'ciRSquare',nan(1,2),...
                                        'exitFlagFraction',nan(19,2));
                        end
                        
                        z = cellfun(@(x) x.meanParams(1),simDataMulti.rateVsRtRat01); % Slope of linear regression line
                        
                        mnZ = -500;
                        mxZ = 500;
                        colorMap = 'bluewhitered';
                        
                        switch settings.outcomeMeasureAspect
                           case 'medianParams'
                              % The first parameter seems to control the y-level of
                              % the curve, the second parameter controls the curvature
                              % and seems of most interest
                              
                              z = cellfun(@(x) x.medianParams(2),simDataMulti.rateVsRtRat01); % Slope of linear regression line
                              mnZ = -1000;
                              mxZ = 1000;
                              colorMap = 'bluewhitered';
                           case 'signParamsFraction'
                              % Find empty cells
                              emptyCell = cellfun(@(x) isempty(x), simDataMulti.rateVsRtRat01);
                              emptyCell = find(emptyCell);

                              % Fill empty cells with nans
                              for iEmpty = 1:numel(emptyCell)
                                 simDataMulti.rateVsRtRat01{emptyCell(iEmpty)} = ...
                                 struct('meanParams',nan(1,2),...
                                        'medianParams',nan(1,2),...
                                        'ciParams',nan(2,2),...
                                        'signParamsOverall',nan(1,2),...
                                        'signParamsFraction',nan(3,3),...
                                        'meanRMSE',nan(1,1),...
                                        'medianRMSE',nan(1,1),...
                                        'ciRMSE',nan(1,2),...
                                        'meanRSquare',nan(1,1),...
                                        'medianRSquare',nan(1,1),...
                                        'ciRSquare',nan(1,2),...
                                        'exitFlagFraction',nan(19,2));
                              end
                              
                              z = cellfun(@(x) x.signParamsFraction(2,2),simDataMulti.rateVsRtRat01); % Fraction of sessions with a non-significant slope of linear regression line
                              mnZ = 0;
                              mxZ = 1;
                              colorMap = flipud(cbrewer('seq','RdPu',21));
                           case 'meanRMSE'
                              % Find empty cells
                              emptyCell = cellfun(@(x) isempty(x), simDataMulti.rateVsRtRat01);
                              emptyCell = find(emptyCell);

                              % Fill empty cells with nans
                              for iEmpty = 1:numel(emptyCell)
                                 simDataMulti.rateVsRtRat01{emptyCell(iEmpty)} = ...
                                 struct('meanParams',nan(1,2),...
                                        'medianParams',nan(1,2),...
                                        'ciParams',nan(2,2),...
                                        'signParamsOverall',nan(1,2),...
                                        'signParamsFraction',nan(3,3),...
                                        'meanRMSE',nan(1,1),...
                                        'medianRMSE',nan(1,1),...
                                        'ciRMSE',nan(1,2),...
                                        'meanRSquare',nan(1,1),...
                                        'medianRSquare',nan(1,1),...
                                        'ciRSquare',nan(1,2),...
                                        'exitFlagFraction',nan(19,2));
                              end
                              
                              z = cellfun(@(x) x.meanRMSE,simDataMulti.rateVsRtRat01); % Root mean square error
                              % RMSE in Hanes & Schall 1996 is estimated at 8
                              mnZ = 0;
                              mxZ = 16;
                              colorMap = cbrewer('div','PiYG',17);
%                               colorMap = colormap('bluewhitered');
                           case 'meanRSquare'
                              % Find empty cells
                              emptyCell = cellfun(@(x) isempty(x), simDataMulti.rateVsRtRat01);
                              emptyCell = find(emptyCell);

                              % Fill empty cells with nans
                              for iEmpty = 1:numel(emptyCell)
                                 simDataMulti.rateVsRtRat01{emptyCell(iEmpty)} = ...
                                 struct('meanParams',nan(1,2),...
                                        'medianParams',nan(1,2),...
                                        'ciParams',nan(2,2),...
                                        'signParamsOverall',nan(1,2),...
                                        'signParamsFraction',nan(3,3),...
                                        'meanRMSE',nan(1,1),...
                                        'medianRMSE',nan(1,1),...
                                        'ciRMSE',nan(1,2),...
                                        'meanRSquare',nan(1,1),...
                                        'medianRSquare',nan(1,1),...
                                        'ciRSquare',nan(1,2),...
                                        'exitFlagFraction',nan(19,2));
                              end
                              
                              z = cellfun(@(x) x.meanRSquare,simDataMulti.rateVsRtRat01); % Root mean square error
                              mnZ = 0;
                              mxZ = 1;
                              colorMap = cbrewer('seq','RdPu',21);
                        end
                  end
                  ppa = sqrt(numel(x)); % Number of data points per axis

                  imagesc(x,flipdim(y,1),flipdim(vec2mat(z,ppa),1),[mnZ,mxZ]);
                  colormap(colorMap);

                  if settings.title
                     title(['mT = ',mT{i},' mR = ',mR{j}]);
                  end

                   if settings.doMask

                      switch settings.outcomeMeasure
                         case 'medianRt'
                            medRtBnds = [190 600]; % Based on 95% CI in visual search data set with set sizes 2, 4, 8; see: EPU/ModelFitting_Jan26/m-files
                            msk = cell2mat(cellfun(@(x) all(x.ci95 < medRtBnds(1)) | all(x.ci95 > medRtBnds(2)),simDataMulti.medianRt,'UniformOutput',0)); % Any median RT confidence bounds fully out of reasonable range
                            msk = vec2mat(msk,ppa);
                            mat = vec2mat(z,ppa);

                            outline = pixel_outline(mat,msk);

                            % Pixels in which parameter equals NaN
                            nanmsk = isnan(cellfun(@(x) x.mean,simDataMulti.medianRt));
                            nanmsk = vec2mat(nanmsk,ppa);
                            nanoutline = pixel_outline(mat,nanmsk);

                         case 'exGaussian_mu'
                            muBnds = [150 307]; % Based on 95% CI in visual search data set with set sizes 2, 4, 8; see: EPU/ModelFitting_Jan26/m-files
   %                          muBnds = [160 290]; % Based on 90% CI in visual search data set with set sizes 2, 4, 8; see: EPU/ModelFitting_Jan26/m-files
                            msk = cell2mat(cellfun(@(x) all(x.ci95FittedParams(:,1) < muBnds(1)) | all(x.ci95FittedParams(:,1) > muBnds(2)),simDataMulti.rt_exGauss,'UniformOutput',0)); % Any median RT confidence bounds fully out of reasonable range
                            msk = vec2mat(msk,ppa);
                            mat = vec2mat(z,ppa);

                            outline = pixel_outline(mat,msk);

                            % Pixels in which parameter equals NaN
                            nanmsk = isnan(cell2mat(cellfun(@(x) x.meanParams(1),simDataMulti.rt_exGauss,'UniformOutput',0)));
                            nanmsk = vec2mat(nanmsk,ppa);
                            nanoutline = pixel_outline(mat,nanmsk);

                         case 'exGaussian_sigma'
                            sigmaBnds = [1.8 57.6]; % Based on 95% CI in visual search data set with set sizes 2, 4, 8; see: EPU/ModelFitting_Jan26/m-files
   %                          sigmaBnds = [1.8 48.9]; % Based on 90% CI in visual search data set with set sizes 2, 4, 8; see: EPU/ModelFitting_Jan26/m-files
                            msk = cell2mat(cellfun(@(x) all(x.ci95FittedParams(:,2) < sigmaBnds(1)) | all(x.ci95FittedParams(:,2) > sigmaBnds(2)),simDataMulti.rt_exGauss,'UniformOutput',0)); % Any median RT confidence bounds fully out of reasonable range
                            msk = vec2mat(msk,ppa);
                            mat = vec2mat(z,ppa);

                            outline = pixel_outline(mat,msk);

                            % Pixels in which parameter equals NaN
                            nanmsk = isnan(cell2mat(cellfun(@(x) x.meanParams(2),simDataMulti.rt_exGauss,'UniformOutput',0)));
                            nanmsk = vec2mat(nanmsk,ppa);
                            nanoutline = pixel_outline(mat,nanmsk);

                         case 'exGaussian_tau'
                            tauBnds = [16 511]; % Based on 95% CI in visual search data set with set sizes 2, 4, 8; see: EPU/ModelFitting_Jan26/m-files
   %                          tauBnds = [17 307]; % Based on 90% CI in visual search data set with set sizes 2, 4, 8; see: EPU/ModelFitting_Jan26/m-files
                            msk = cell2mat(cellfun(@(x) all(x.ci95FittedParams(:,3) < tauBnds(1)) | all(x.ci95FittedParams(:,3) > tauBnds(2)),simDataMulti.rt_exGauss,'UniformOutput',0)); % Any median RT confidence bounds fully out of reasonable range
                            msk = vec2mat(msk,ppa);
                            mat = vec2mat(z,ppa);

                            outline = pixel_outline(mat,msk);

                            % Pixels in which parameter equals NaN
                            nanmsk = isnan(cell2mat(cellfun(@(x) x.meanParams(3),simDataMulti.rt_exGauss,'UniformOutput',0)));
                            nanmsk = vec2mat(nanmsk,ppa);
                            nanoutline = pixel_outline(mat,nanmsk);

                         case 'dtActPeakRt'
                           msk = abs(cellfun(@(x) x.mean,simDataMulti.dtActPeakRt)) > 50; % Activation peak more than 50 ms before or after RT
                           msk = vec2mat(msk,ppa);
                           mat = vec2mat(z,ppa);

                           outline = pixel_outline(mat,msk);

                           % Pixels in which fitted parameter equals NaN
                           nanmsk = isnan(cellfun(@(x) x.mean,simDataMulti.dtActPeakRt));
                           nanmsk = vec2mat(nanmsk,ppa);
                           nanoutline = pixel_outline(mat,nanmsk);

                         case 'thresVsRtPoly1'
                            
                            switch settings.outcomeMeasureAspect
                               case 'meanParams'
                                  msk = cellfun(@(x) x.signParamsOverall(1),simDataMulti.thresVsRtPoly1) ~= 0;
                                  msk = vec2mat(msk,ppa);
                                  mat = vec2mat(z,ppa);

                                  outline = pixel_outline(mat,msk);

                                  % Pixels in which fitted parameter equals NaN
                                  nanmsk = isnan(cellfun(@(x) x.meanParams(1),simDataMulti.thresVsRtPoly1));
                                  nanmsk = vec2mat(nanmsk,ppa);
                                  nanoutline = pixel_outline(mat,nanmsk);
                               case 'meanRMSE'
                                  mat = vec2mat(z,ppa);
                                  
                                  % Pixels in which fitted parameter equals NaN
                                  nanmsk = isnan(cellfun(@(x) x.meanRMSE,simDataMulti.thresVsRtPoly1));
                                  nanmsk = vec2mat(nanmsk,ppa);
                                  nanoutline = pixel_outline(mat,nanmsk);
                               case 'CoVRMSE'
                                  mat = vec2mat(z,ppa);
                                  
                                  % Pixels in which fitted parameter equals NaN
                                  nanmsk = isnan(cellfun(@(x) x.CoVRMSE,simDataMulti.thresVsRtPoly1));
                                  nanmsk = vec2mat(nanmsk,ppa);
                                  nanoutline = pixel_outline(mat,nanmsk);
                               case 'meanRSquare'
                                  mat = vec2mat(z,ppa);
                                  
                                  % Pixels in which fitted parameter equals NaN
                                  nanmsk = isnan(cellfun(@(x) x.meanRSquare,simDataMulti.thresVsRtPoly1));
                                  nanmsk = vec2mat(nanmsk,ppa);
                                  nanoutline = pixel_outline(mat,nanmsk);
                               case 'signParamsFraction'
                                  mat = vec2mat(z,ppa);
                                  
                                  % Pixels in which fitted parameter equals NaN
                                  nanmsk = isnan(cellfun(@(x) x.signParamsFraction(1),simDataMulti.thresVsRtPoly1));
                                  nanmsk = vec2mat(nanmsk,ppa);
                                  nanoutline = pixel_outline(mat,nanmsk);
                            end

                         case 'rateVsRtPoly1'
                            switch settings.outcomeMeasureAspect
                               case 'meanParams'
                                  msk = cellfun(@(x) x.signParamsOverall(1),simDataMulti.rateVsRtPoly1) ~= -1; % A negative sign of the second parameter of the linear function indicates a decreasing trend
                                  msk = vec2mat(msk,ppa);
                                  mat = vec2mat(z,ppa);

                                  outline = pixel_outline(mat,msk);

                                  % Pixels in which fitted parameter equals NaN
                                  nanmsk = isnan(cellfun(@(x) x.meanParams(1),simDataMulti.rateVsRtPoly1));
                                  nanmsk = vec2mat(nanmsk,ppa);
                                  nanoutline = pixel_outline(mat,nanmsk);
                               case 'meanRMSE'
                            end
                            
                         case 'rateVsRtRat01'
                            
                            switch settings.outcomeMeasureAspect
                               case 'meanParams'
                                  msk = cellfun(@(x) x.signParamsOverall(1),simDataMulti.rateVsRtRat01) ~= 1; % A positive sign of the first parameter of the rational function indicates a decreasing trend
                                  msk = vec2mat(msk,ppa);
                                  mat = vec2mat(z,ppa);

                                  outline = pixel_outline(mat,msk);

                                  % Pixels in which fitted parameter equals NaN
                                  nanmsk = isnan(cellfun(@(x) x.medianParams(1),simDataMulti.rateVsRtRat01));
                                  nanmsk = vec2mat(nanmsk,ppa);
                                  nanoutline = pixel_outline(mat,nanmsk);
                               case 'meanRMSE'
                               case 'signParamsFraction'
                                  mat = vec2mat(z,ppa);
                                  
                                  % Pixels in which fitted parameter equals NaN
                                  nanmsk = isnan(cellfun(@(x) x.signParamsFraction(1),simDataMulti.rateVsRtRat01));
                                  nanmsk = vec2mat(nanmsk,ppa);
                                  nanoutline = pixel_outline(mat,nanmsk);
                            end
                      end

                      switch lower(settings.maskType)
                         case 'hatch'
                            for l = 1:numel(outline)
                               hPatch{l} = patch(outline{l}(:,2),outline{l}(:,1),[1 1 1]);
                               hPatch{l} = hatchfill(hPatch{l},'single',45,3);
                            end

                            if ~isempty(nanoutline)
                               for l = 1:numel(nanoutline)
                                  hNanPatch{l} = patch(nanoutline{l}(:,2),nanoutline{l}(:,1),[0.5 0.5 0.5],'EdgeColor','none');
                               end
                            end

                         case 'contour'
                            for l = 1:numel(outline)
                               plot(outline{l}(:,2), outline{l}(:,1), 'k', 'Linewidth', 2)
                            end

                            if ~isempty(nanoutline)
                               for l = 1:numel(nanoutline)
                                  hNanPatch{l} = patch(nanoutline{l}(:,2),nanoutline{l}(:,1),[0.5 0.5 0.5],'EdgeColor','none');
                               end
                            end
                            
                         case 'nanonly'
                            if ~isempty(nanoutline)
                               for l = 1:numel(nanoutline)
                                  hNanPatch{l} = patch(nanoutline{l}(:,2),nanoutline{l}(:,1),[0.5 0.5 0.5],'EdgeColor','none');
                               end
                            end
                      end
                   end

                  set(gca,'XLim',[0 1],...
                           'YLim',[0 1]);

                  if ~settings.tickLabel
                     set(gca,'XTickLabel','',...
                             'YTickLabel','');
                  end

                  if settings.colorBar == 1
                     hColorbar = colorbar('peer', thisPanel);
                  elseif settings.colorBar == 2
                     if i ==1 & j == 1
                        thisFig = gcf;
                        thisAxis = gca;
                        figure;
                        imagesc(x,flipdim(y,1),flipdim(vec2mat(z,ppa),1),[mnZ,mxZ]);
                        colormap(bluewhitered);
                        colorbar;
                        axis('xy','image');
                        figure(thisFig);
                        axes(thisAxis);
                     end
                  end


                  switch settings.subplotType
                     case 'panel'
                        p(i,j,1,2).select(h_colorbar_axis);
                  end

                  axis('xy','image');

               end
            end
         end

         switch settings.subplotType
         case 'panel'
            p.refresh();
         end

         if settings.saveFigure
            % Save figure
            if ~noALim
               print(hFig,'-depsc',fullfile(figureDir,[settings.outcomeMeasure,'_',settings.plotType,'_mR',mR{j},'_and_mT',mT{i},'_for_nA',nA{k},'_aLim',aLimit{h},'_cBarLim',strrep([num2str(mnZ),'to',num2str(mxZ)],'.','')]));
            else
               print(hFig,'-depsc',fullfile(figureDir,[settings.outcomeMeasure,'_',settings.plotType,'_mR',mR{j},'_and_mT',mT{i},'_for_nA',nA{k},'_cBarLim',strrep([num2str(mnZ),'to',num2str(mxZ)],'.','')]));
            end
         end

      end
end

