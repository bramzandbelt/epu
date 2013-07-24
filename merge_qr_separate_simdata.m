function epu_merge_simdata(fileFilter,datasetName,outputDir,outputName);
%
%
%
% INPUTS
% fileFilter
% outputDir
% outputName
% datasetName      dataset variable name
% 

% Open dialog box for file selection, using uipickfiles
% see: http://www.mathworks.com/matlabcentral/fileexchange/10867-uipickfiles-uigetfile-on-steroids
fileList = uipickfiles('REFilter',fileFilter);

% Create an empty dataset structure
simData = dataset;

% Loop over files, open them, and add them to the dataset
for iFile = 1:length(fileList)
   
   % Load variables into a structure
   varStruct = load(fileList{iFile});
   
   % Get variable name
   varNames = fieldnames(varStruct);
   
   % Warn if file contains more than one variable
   if prod(size(varNames)) ~= 1
      warning(['File ',fileList(iFile,:),' contains more than one variable. First dataset variable is used.']);
   end
   
   % Add the very first dataset variable to workspace dataset
   for iVar = 1:prod(size(varNames))
      
      % If this is a dataset, append it to simData
      if strncmp(class(eval(['varStruct.',varNames{iVar}])),'dataset',7)
         simData = [simData;['varStruct.',varNames{iVar}]];
      end
   end
   clear fileStruct
   
end

% Rename dataset
eval([datasetName,' = simData;']);

% Save file
[p n e] = fileparts(outputName);
if isempty(e)
   outputName = [outputName,'.mat'];
end

save(fullfile(outputdir,outputName),eval(datasetName));

% % Script for assembling activation and rt multidata for q-r separate simulations
% 
% nA = [1];
% mR = 0.75;
% mT = 100;
% q = 0:.1:1;
% r = 0:.1:1;
% aLimit = 1000;
% tag = 'leaky_stochastic';
% 
% dataDir = '/Users/bram/Documents/EPU/Simulation_2012May03/output/LeakyStochastic/raw/';
% outputDir = '/Users/bram/Documents/EPU/Simulation_2012May03/output/LeakyStochastic/';
% 
% if exist(outputDir) ~= 7
%    mkdir(outputDir);
% end
% 
% for iNA = 1:length(nA)
%    
%    % Initiate dataset variables
%    simDataSingleAll = dataset;
%    simDataMultiAll = dataset;
%    
%    %% Single
%    for iR = 1:length(r)
%       for iQ = 1:length(q)      
%          % Load file name
%          
%          if exist('aLimit') == 1
%             n = char(regexpdir(dataDir,['sim_',tag,...
%                                strrep(sprintf('_nA%.d',nA(iNA)),'.',''),...
%                                strrep(sprintf('_mR%.2f',mR),'.',''),...
%                                strrep(sprintf('_mT%.0f',mT),'.',''),...
%                                strrep(sprintf('_q%.2f',q(iQ)),'.',''),...
%                                strrep(sprintf('_r%.2f',r(iR)),'.',''),...
%                                strrep(sprintf('_aLim%.2f',aLimit),'.',''),...
%                                '.*SingleData.mat$'],0));
%          else
%             n = char(regexpdir(dataDir,['sim_',tag,...
%                             strrep(sprintf('_nA%.d',nA(iNA)),'.',''),...
%                             strrep(sprintf('_mR%.2f',mR),'.',''),...
%                             strrep(sprintf('_mT%.0f',mT),'.',''),...
%                             strrep(sprintf('_q%.2f',q(iQ)),'.',''),...
%                             strrep(sprintf('_r%.2f',r(iR)),'.',''),...
%                             '.*SingleData.mat$'],0));
%          end
%          
%          for iFile = 1:size(n,1)
%             % Load file
%             load(n(iFile,:))
%             simDataSingleAll = [simDataSingleAll;simDataSingle];
%             clear simDataSingle
%          end
%                          
%             
%          
%       end
%    end
%    
%    % Save Activation data
%    simDataSingle = simDataSingleAll;
%    if exist('aLimit') == 1
%       save(fullfile(outputDir,['sim_nA',num2str(nA(iNA)),...
%                      strrep(sprintf('_mR%.2f',mR),'.',''),...
%                      strrep(sprintf('_mT%.0f',mT),'.',''),...
%                      strrep(sprintf('_aLim%.2f',aLimit),'.',''),...
%                      datestr(now,'yyyymmddTHHMMSS'),...
%                      '_SingleData.mat']),'simDataSingle');
%    else
%       save(fullfile(outputDir,['sim_nA',num2str(nA(iNA)),...
%                      strrep(sprintf('_mR%.2f',mR),'.',''),...
%                      strrep(sprintf('_mT%.0f',mT),'.',''),...
%                      datestr(now,'yyyymmddTHHMMSS'),...
%                      '_SingleData.mat']),'simDataSingle');
%    end
%    
%    %% Multi
%    for iR = 1:length(r)
%       for iQ = 1:length(q)      
%          % Load file name
%          if exist('aLimit') == 1
%             n = char(regexpdir(dataDir,['sim_',tag,...
%                                strrep(sprintf('_nA%.d',nA(iNA)),'.',''),...
%                                strrep(sprintf('_mR%.2f',mR),'.',''),...
%                                strrep(sprintf('_mT%.0f',mT),'.',''),...
%                                strrep(sprintf('_q%.2f',q(iQ)),'.',''),...
%                                strrep(sprintf('_r%.2f',r(iR)),'.',''),...
%                                strrep(sprintf('_aLim%.2f',aLimit),'.',''),...
%                                '.*MultiData.mat$'],0));
%          else
%             n = char(regexpdir(dataDir,['sim_',tag,...
%                             strrep(sprintf('_nA%.d',nA(iNA)),'.',''),...
%                             strrep(sprintf('_mR%.2f',mR),'.',''),...
%                             strrep(sprintf('_mT%.0f',mT),'.',''),...
%                             strrep(sprintf('_q%.2f',q(iQ)),'.',''),...
%                             strrep(sprintf('_r%.2f',r(iR)),'.',''),...
%                             '.*MultiData.mat$'],0));
%          end
%          
%          for iFile = 1:size(n,1)
%             % Load file
%             load(n(iFile,:))
%             simDataMultiAll = [simDataMultiAll;simDataMulti];
%             clear simDataMulti
%          end
%                          
%             
%          
%       end
%    end
%    
%    if exist('aLimit') == 1
%       simDataMulti = simDataMultiAll;
%       save(fullfile(outputDir,['sim_nA',num2str(nA(iNA)),...
%                      strrep(sprintf('_mR%.2f',mR),'.',''),...
%                      strrep(sprintf('_mT%.0f',mT),'.',''),...
%                      strrep(sprintf('_aLim%.2f',aLimit),'.',''),...
%                      datestr(now,'yyyymmddTHHMMSS'),...
%                      '_MultiData.mat']),'simDataMulti');
%    else
%       simDataMulti = simDataMultiAll;
%       save(fullfile(outputDir,['sim_nA',num2str(nA(iNA)),...
%                      strrep(sprintf('_mR%.2f',mR),'.',''),...
%                      strrep(sprintf('_mT%.0f',mT),'.',''),...
%                      datestr(now,'yyyymmddTHHMMSS'),...
%                      '_MultiData.mat']),'simDataMulti');
%    end
%                
%                
% 
% end