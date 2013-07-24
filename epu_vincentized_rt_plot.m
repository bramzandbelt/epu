%% Various settings

%% Settings
settings.subplotType = 'panel'; % 'panel' or 'subplot'
settings.doMask = 1; % yes (1) or no (0)
settings.maskType = 'hatch';

settings.colorBar = 0; % on (1) or off (0)
settings.title = 0; % on (1) or off (0)
settings.tickLabel = 0; % on (1) or off (0)

settings.plotType = 'heat'; % 'line' or 'heat'
settings.outcomeMeasureAspect = 'meanFittedParams';

settings.saveFigure = 0; % yes (1) or no (0)

figureDir = '/Users/bram/Documents/EPU/Simulation_2012May03/figures/';
dataDir = '/Users/bram/Documents/EPU/Simulation_2012May03/output/LeakyStochastic/'

% Specify parameter levels
q = [0:10]./10;
r = [0:10]./10;
mT = 100; % Threshold
mR = 0.75; % Mean rate
nA = [1 10 20 50 100 200 500 1000 2000 5000]; % Number of accumulators
aLim = [10000]; 
h = 1; % index for aLim
nCombinations = prod([numel(q),numel(r)]);
counter = 0;

% progressbar;

% Line colors
% lineColors = [198 219 239;
%               158 202 225;
%               107 174 214;
%               66 146 198;
%               33 113 181;
%               8 69 148];

% Effect of nA: none on vincent RT, increase in Coefficient of Variation
lineColors{1} = [255 0 0;
                 255 0 0;
                 255 0 0;
                 255 0 0;
                 255 0 0];                 
% Effect of nA: increase in vincent RT, increase in Coefficient of Variation
lineColors{2} = [255 191 0;
                 255 191 0;
                 255 191 0;
                 255 191 0;
                 255 191 0];
% Effect of nA: increase in vincent RT, none on Coefficient of Variation
lineColors{3} = [128 255 0;
                 128 255 0;
                 128 255 0;
                 128 255 0;
                 128 255 0];
% Effect of nA: increase in vincent RT, decrease in Coefficient of Variation
lineColors{4} = [0 255 111;
                 0 255 111;
                 0 255 111;
                 0 255 111;
                 0 255 111];              
% Effect of nA: none on vincent RT, decrease in Coefficient of Variation
lineColors{5} = [0 255 255;
                 0 255 255;
                 0 255 255;
                 0 255 255;
                 0 255 255];                 
% Effect of nA: decrease in vincent RT, decrease in Coefficient of Variation
lineColors{6} = [0 88 255;
                 0 88 255;
                 0 88 255;
                 0 88 255;
                 0 88 255];
% Effect of nA: decrease in vincent RT, none on Coefficient of Variation
lineColors{7} = [104 0 255;
                 104 0 255;
                 104 0 255;
                 104 0 255;
                 104 0 255];
% Effect of nA: decrease in vincent RT, increase in Coefficient of Variation
lineColors{8} = [255 0 215;
                 255 0 215;
                 255 0 215;
                 255 0 215;
                 255 0 215;];             
% Effect of nA: none on vincent RT, none on Coefficient of Variation              
lineColors{9} = [0 0 0;
                 0 0 0;
                 0 0 0;
                 0 0 0;
                 0 0 0];             
              
for i = 1:9
   lineColors{i} = lineColors{i}./255; 
end
nVincentiles = 5;


switch settings.plotType
   case 'line'
      %% Part 1. Line plots
      
      for i = 4%1:5 % mT
         for j = 3%1:5 % mR
      
            % Set up figure
            screenSize = get(0,'ScreenSize');
            figureWidth = 30;
            figureHeight = 22.5;
            hFig = figure('Color',[1 1 1],...
                          'PaperPosition',[0 0 figureWidth figureHeight],...
                          'PaperUnits','centimeters',...
                          'PaperSize',[figureWidth figureHeight]);
            set(hFig,'Position',screenSize);
           
%             orient landscape;

            % Set up panels
            switch settings.subplotType
               case 'panel'
                  p = panel('defer');
                  p.pack(numel(r),numel(q));
            end
            
            rFlip = 11:-1:1;
            counter = 0;

            % Load data
            clear simDataMultiRt
            n = char(regexpdir(dataDir,['simDataMultiRt_nA1_to_nA10000_wo_nA2_nA5_mR075_mT100_aLim10000_linRegLowerLimit0.mat'],0));
            load(n)

            for iQ = 1:11
               for iR = 1:11
                  
                  iSim = find(simDataMultiRt.q == q(iQ) & ...
                              simDataMultiRt.r == r(iR) & ...
                              simDataMultiRt.mT == mT(i) & ...
                              simDataMultiRt.mR == mR(j));

                  nAVec = simDataMultiRt.nA(iSim);
                  y = cell2mat(cellfun(@(x) x.mean,simDataMultiRt.rtVincent(iSim),'UniformOutput',0));
                  signRt = cell2mat(cellfun(@(x) x.sign,simDataMultiRt.rtVincent(iSim),'UniformOutput',0));
                  signCov = cell2mat(cellfun(@(x) x.sign,simDataMultiRt.covRt(iSim),'UniformOutput',0));

                  if signRt(1) == 0 & signCov(1) == 1
                     iClr = 1;
                  elseif signRt(1) == 1 & signCov(1) == 1
                     iClr = 2;
                  elseif signRt(1) == 1 & signCov(1) == 0
                     iClr = 3;
                  elseif signRt(1) == 1 & signCov(1) == -1
                     iClr = 4;
                  elseif signRt(1) == 0 & signCov(1) == -1
                     iClr = 5;
                  elseif signRt(1) == -1 & signCov(1) == -1
                     iClr = 6;
                  elseif signRt(1) == -1 & signCov(1) == 0
                     iClr = 7;
                  elseif signRt(1) == -1 & signCov(1) == 1
                     iClr = 8;
                  elseif signRt(1) == 0 & signCov(1) == 0
                     iClr = 9;
                  end
                  
                  switch settings.subplotType
                     case 'panel'
                        p(rFlip(iR),iQ).select();
                     case 'subplot'
                        subplot(numel(r),numel(q),(rFlip(iR)-1)*numel(q)+iQ);
                  end
                  
                  hold on
                  for iV = 1:nVincentiles % Vincentile index
                     hP = plot(nAVec,y(:,iV),...
                          'Color',lineColors{iClr}(iV,:), ...
                          'Marker','o', ...
                          'MarkerFaceColor',lineColors{iClr}(iV,:), ...
                          'MarkerEdgeColor','none',...
                          'MarkerSize',5);
                  end

                  set(gca,'TickLength',[.04 .04],...
                          'TickDir','out',...
                          'XLim',[0 2e4],...
                          'XScale','log',...
                          'XTick',[1e1 1e2 1e3 1e4],...
                          'YLim',[1e2 2e3],...
                          'YTick',[1e2 2e2 3e2 4e2 5e2 6e2 7e2 8e2 9e2 1e3],...
                          'YScale','log');
                 
                  if ~settings.tickLabel
                     set(gca,'XTickLabel','',...
                             'YTickLabel','');
                  else
%                      ylm = get(gca,'YLim');
%                      ylm(1) = 100;
%                      set(gca,'YLim',ylm);
%                      set(gca,'YTick',power(10,[2:.1:3]),...
%                               'YScale','log');
%                      
%                      set(gca,'XTickLabel','',...
%                              'FontSize',6,...
%                              'YTickLabel',get(gca,'YTickLabel')); % Labels reflect power coefficient (e.g. 2 means 10^2)
                  end
                     
%                   axis square;

                  if settings.title
                     switch settings.subplotType
                        case 'panel'
                           p(rFlip(iR),iQ).title(sprintf('q=%.1f r=%.1f',q(iQ),r(iR)));
                     end
                  end

                  counter = counter + 1;
%                   progressbar(counter/nCombinations);

               end
            end
            
            if settings.saveFigure
               % Save figure
               print(hFig,'-depsc',fullfile(figureDir,['rtVsNa_lines_mR',strrep(sprintf('%.2f',mR(j)),'.',''),'_mT',strrep(sprintf('%2.f',mT(i)),'.',''),'_aLim',strrep(sprintf('%.2f',aLim(h)),'.','')]));
            end
               
         end
      end
      
      switch settings.subplotType
         case 'panel'
            p.refresh();
      end
      
   case 'heat'
      
      % Set up figure
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
            p.pack(1,1);
      end
      
      counter = 0;
      
      flipMt = 5:-1:1;
                 
      for i = 4 % mT
         for j = 3 % mR
            
            try
               switch settings.subplotType
                  case 'panel'
                     thisPanel = p(1,1).select();
                  case 'subplot'
                     counter = counter + 1;
                     thisPanel = subplot(5,5,(flipMt(i)-1)*5+j);
               end

               % Load data
               clear simDataMultiRt
               n = char(regexpdir(dataDir,['simDataMultiRt_nA1_to_nA10000_wo_nA2_nA5_mR075_mT100_aLim10000_linRegLowerLimit100.mat'],0));
               load(n);

               % Make heat plot
               iSim = find(simDataMultiRt.nA == 10);

               x = simDataMultiRt.q(iSim); % Fraction
               y = simDataMultiRt.r(iSim); % Correlation
               signRt = cell2mat(cellfun(@(x) x.sign,simDataMultiRt.rtVincent(iSim),'UniformOutput',0));
               signCov = cell2mat(cellfun(@(x) x.sign,simDataMultiRt.covRt(iSim),'UniformOutput',0));
               z = nan(size(x));

               z(signRt == 0 & signCov == 1) = 1;
               z(signRt == 1 & signCov == 1) = 2;
               z(signRt == 1 & signCov == 0) = 3;
               z(signRt == 1 & signCov == -1) = 4;
               z(signRt == 0 & signCov == -1) = 5;
               z(signRt == -1 & signCov == -1) = 6;
               z(signRt == -1 & signCov == 0) = 7;
               z(signRt == -1 & signCov == 1) = 8;
               z(signRt == 0 & signCov == 0) = 9;

               mnZ = 1;
               mxZ = 9;
               colorMap = colormap('hsv');
               colorMap(end,:) = [1 1 1]; % White

               ppa = sqrt(numel(x)); % Number of data points per axis

               imagesc(x,flipdim(y,1),flipdim(vec2mat(z,ppa),1),[mnZ,mxZ]);
               colormap(colorMap);

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

               if settings.title
                  switch settings.subplotType
                     case 'panel'
                        p(i,j).title(sprintf('mT=%2.f mR=%.2f',mT(i),mR(j)));
                     case 'subplot'
                        title(['mT = ',num2str(mT(i)),' mR = ',num2str(mR(j))]);
                  end

               end


               axis('xy','image');
            catch
            end
            
         end % mR
      end %mT
      
      switch settings.subplotType
         case 'panel'
            p.refresh();
      end
      
      if settings.saveFigure
         % Save figure
         print(hFig,'-depsc',fullfile(figureDir,['rtVsNa_heat_across_mR_and_mT__aLim',strrep(sprintf('%.2f',aLim(h)),'.','')]));
      end
      
end