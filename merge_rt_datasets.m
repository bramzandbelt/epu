function merge_rt_datasets
dataDir = '/Users/bram/Documents/EPU/Simulation_2012May03/output/LeakyStochastic/';
mT = {'100'};
mR = {'075'};
nA = {'1','10','20','50','100','200','500','1000'};
aLim = {'1000'};

nCombinations = prod([numel(mT),numel(mR),10,10]);

progressbar;

counter = 0;

linRegLowerLimit = 0; % Indicates the minimum nA level to include in the linear regression analysis 

for i = 1 % mT
   for j = 1 % mR
      
      simDataMultiRt = [];
      
      for k = 1:numel(nA) % nA
         
         
         
         % Load data
         clear simDataMulti
         n = char(regexpdir(dataDir,['sim_nA',nA{k},'_mR',mR{j},'_mT',mT{i},'_aLim',aLim{1},'.*MultiData.mat$'],0));
         load(n)
         
         % Append simDataMulti to simDataMultiRt
         simDataMultiRt = vertcat(simDataMultiRt,simDataMulti);
         
      end
      
      % 
      for q = [0:10]./10
         for r = [0:10]./10
            
            switch mR{j}
               case '025'
                  mr = .25;
               case '050'
                  mr = .50;
               case '075'
                  mr = .75;
               case '100'
                  mr = 1.00;
               case '125'
                  mr = 1.25;
            end
            
            iSim = find(simDataMultiRt.q == q & ...
                        simDataMultiRt.r == r & ...
                        simDataMultiRt.mT == str2num(mT{i}) & ...
                        simDataMultiRt.mR == mr);
            
            nAVec = simDataMultiRt.nA(iSim);
            
            iLinear = find(nAVec >= linRegLowerLimit);
            
            % Find empty cells
            emptyCell = cellfun(@(x) isempty(x), simDataMultiRt.rtQuantile);
            emptyCell = find(emptyCell);

            % Fill empty cells with nans
            for iEmpty = 1:numel(emptyCell)
               simDataMultiRt.rtQuantile{emptyCell(iEmpty)} = ...
               struct('mean',nan(1,5),...
                      'data',nan(1000,5),...
                      'sign',nan(1,1));
            end
            y = cell2mat(cellfun(@(x) x.mean,simDataMultiRt.rtQuantile(iSim),'UniformOutput',0));

            %% Quantile RTs
            
            % Get QuantileRTs for all trials and nA
            rtQuantile = cellfun(@(x) x.mean,simDataMultiRt.rtQuantile(iSim),'UniformOutput',0);

            nSess = 1000;
            rtQuantileNa = nan(nSess,nVincentiles,numel(nAVec));
            for iNa = 1:numel(nAVec)
               rtQuantileNa(:,:,iNa) = rtQuantile{iNa};
            end
            rtVsNaCell = mat2cell(rtQuantileNa,[ones(nSess,1)],[ones(nVincentiles,1)],[numel(nAVec)]);
            rtVsNaCell = cellfun(@(x) squeeze(x),rtVsNaCell,'UniformOutput',0);
            % Linear regression of RT on nA
            rtOnNaBetas = cellfun(@(y) robustfit(nAVec(iLinear),double(y(iLinear)),'ols'),rtVsNaCell,'UniformOutput',0);
            % Pick slope
            rtOnNaSlope = cellfun(@(t) t(2),rtOnNaBetas);
            % Average over vincentiles
            rtOnNaSlope = nanmean(rtOnNaSlope,2);
            % 95% confidence bounds
            rtOnNaSlopeCI = prctile(rtOnNaSlope,[2.5 97.5]);
            % Sign
            if all(rtOnNaSlopeCI > 0)
               for l = 1:length(iSim)
                  simDataMultiRt.rtQuantile{iSim(l)}.sign = 1;
               end
            elseif all(rtOnNaSlopeCI < 0)
               for l = 1:length(iSim)
                  simDataMultiRt.rtQuantile{iSim(l)}.sign = -1;
               end
            else
               for l = 1:length(iSim)
                  simDataMultiRt.rtQuantile{iSim(l)}.sign = 0;
               end
            end
            
            %% Coefficient of variation
            % Find empty cells
            emptyCell = cellfun(@(x) isempty(x), simDataMultiRt.covRt);
            emptyCell = find(emptyCell);

            % Fill empty cells with nans
            for iEmpty = 1:numel(emptyCell)
               simDataMultiRt.covRt{emptyCell(iEmpty)} = ...
               struct('mean',nan(1,1),...
                      'data',nan(1000,1),...
                      'sign',nan(1,1));
            end
            y = cell2mat(cellfun(@(x) x.mean,simDataMultiRt.covRt(iSim),'UniformOutput',0));
                        
            covRt = cellfun(@(x) x.data,simDataMultiRt.covRt(iSim),'UniformOutput',0);
            
            nSess = 1000;
            rtCoVNa = nan(nSess,numel(nAVec));
            for iNa = 1:numel(nAVec)
               rtCoVNa(:,iNa) = covRt{iNa};
            end
            rtCoVNaCell = mat2cell(rtCoVNa,[ones(nSess,1)],[numel(nAVec)]);
            rtCoVNaCell = cellfun(@(x) squeeze(x),rtCoVNaCell,'UniformOutput',0);
            % Linear regression of CoV RT on nA
            CoVOnNaBetas = cellfun(@(y) robustfit(nAVec(iLinear),double(y(iLinear)),'ols'),rtCoVNaCell,'UniformOutput',0);
            % Pick slope
            CoVOnNaSlope = cellfun(@(t) t(2),CoVOnNaBetas);
            % 95% confidence bounds
            CoVOnNaSlopeCI = prctile(CoVOnNaSlope,[2.5 97.5]);
            % Sign
            if all(CoVOnNaSlopeCI > 0)
               for l = 1:length(iSim)
                  simDataMultiRt.covRt{iSim(l)}.sign = 1;
               end
            elseif all(CoVOnNaSlopeCI < 0)
               for l = 1:length(iSim)
                  simDataMultiRt.covRt{iSim(l)}.sign = -1;
               end
            else
               for l = 1:length(iSim)
                  simDataMultiRt.covRt{iSim(l)}.sign = 0;
               end
            end
            
            % Display progress
            counter = counter + 1;
            progressbar(counter/nCombinations);
            
         end
      end
      
      % Save it
      outname = ['simDataMultiRt_nA1_to_nA10000_wo_nA2_nA5_mR',mR{j},'_mT',mT{i},'_aLim',aLim{1},'_linRegLowerLimit',num2str(linRegLowerLimit),'.mat']
      save(fullfile(dataDir,outname),'simDataMultiRt','-v7.3');
   end
end