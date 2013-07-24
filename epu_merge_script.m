% Script to merge all files from EPU simulation
outputDir = '/Users/bram/Documents/EPU/Simulation_2012Aug28/output_leakage/';
inputDir = '/Users/bram/Documents/EPU/Simulation_2012Aug28/output_leakage/raw_sigmaXi000/';
datasetName = 'simData';
GUImode = 0;

for iNA = [1 10 20 50 100 200 500 1000] % [1 10 20 30 40 50 60 70 80 90 100 200 300 400 500 600 700 800 900 1000]
   
   % Update inputs
   fileFilter = sprintf('sim_nA%d_.*sigmaXi000.*maxActivation20000.*MultiData.mat',iNA);
   outputName = sprintf('MultiData_nA%d_sigmaXi000_maxActivation20000_epu_simulation_2012Aug28',iNA);
   
   % Merge data
   epu_merge_simdata(fileFilter,datasetName,outputDir,outputName,GUImode,inputDir);
   
end

bla = '[';

for iNA = [1 10 20 50 100 200 500 1000] % [1 10 20 30 40 50 60 70 80 90 100 200 300 400 500 600 700 800 900 1000]
   
   % Load files into workspace
   load(fullfile(outputDir,sprintf('MultiData_nA%d_sigmaXi000_maxActivation20000_epu_simulation_2012Aug28',iNA)));
   
   % Rename files
   eval(['s',num2str(iNA),' = simData; clear simData']);
   
   bla = [bla,';s',num2str(iNA)];
end

bla = [bla,']'];

% Merge into one file
eval(['simData = ',bla]);

% Save this file
save MultiData_nA1_to_nA1000_sigmaXi000_maxActivation20000_epu_simulation_2012Aug28.mat simData