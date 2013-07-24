function epu_merge_simdata(fileFilter,datasetName,outputDir,outputName, varargin);
%
% INPUTS
% fileFilter       - regexp filter e.g. '^sim_nA10_.*MultiData.mat$'
% datasetName      - dataset variable name
% outputDir        - path to directory where output will be saved
% outputName       - output file name
% GUImode          - optional, whether (1) or not (0) GUI, default = 1
% inputDir         - optional, for GUImode = 0, path to directory where files
%                    are located; default is pwd
%
% USAGE
% epu_merge_simdata(fileFilter,datasetName,outputDir,outputName);
% epu_merge_simdata(fileFilter,datasetName,outputDir,outputName,GUImode);
% epu_merge_simdata(fileFilter,datasetName,outputDir,outputName,GUImode,inputDir);

if nargin == 4
   GUImode = 1;
elseif nargin == 5
   GUImode = varargin{1};
   inputDir = pwd;
elseif nargin == 6
   GUImode = varargin{1};
   inputDir = varargin{2};
else
   error('epu_merge_simdata should have 4 or 5 inputs');
end

if GUImode == 1
   % Open dialog box for file selection, using uipickfiles
   % see: http://www.mathworks.com/matlabcentral/fileexchange/10867-uipickfiles-uigetfile-on-steroids
   fileList = uipickfiles('REFilter',fileFilter);
else
   bzenv('spm8');
   fileList = cellstr(spm_select('FPList',inputDir,fileFilter));
end

% Create an empty dataset structure
simData = dataset;

% Initiate progress bar
progressbar;

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
         simData = [simData;eval(['varStruct.',varNames{iVar}])];
      end
   end
   clear varStruct
   
   % Monitor progress
   progressbar(iFile./length(fileList));
end

% Rename dataset
eval([datasetName,' = simData;']);

% Save file
[p n e] = fileparts(outputName);
if isempty(e)
   outputName = [outputName,'.mat'];
end

save(fullfile(outputDir,outputName),datasetName);