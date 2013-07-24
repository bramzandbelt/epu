function analyze_epu_plot_performance

% screen size
screenSize = get(0, 'ScreenSize');
   
%    %% LBA
%    load /Users/bram/Documents/EPU/Simulation_2012Aug28/output/MultiData_nA1_to_nA1000_sigmaXi000_epu_simulation_2012Aug28.mat   

%    %% Diffusion
%    load /Users/bram/Documents/EPU/Simulation_2012Aug28/output/MultiData_nA1_to_nA1000_sigmaXi050_epu_simulation_2012Aug28.mat
   
%    %% Variable theta accross accumulators
%    load /Users/bram/Documents/EPU/Simulation_2012Aug28/output_variable_theta/MultiData_nA1_to_nA1000_sigmaXi000_sdTheta20_epu_simulation_2012Aug28.mat

   %% Variability in eta
%    load /Users/bram/Documents/EPU/Simulation_2012Aug28/output_variable_eta/MultiData_nA1_to_nA1000_sigmaXi000_variable_eta_010_epu_simulation_2012Aug28.mat
   % ADD DATA FROM eta = 1.00
   
   %% Variability in noise correlations
%    load /Users/bram/Documents/EPU/Simulation_2012Aug28/output_variable_eta/MultiData_nA1_to_nA1000_sigmaXi000_variable_eta_010_epu_simulation_2012Aug28.mat
   
   %% Leakage (BA with asymptote at activation level of 200)
   load /Users/bram/Documents/EPU/Simulation_2012Aug28/output_leakage/MultiData_nA1_to_nA1000_sigmaXi000_maxActivation20000_epu_simulation_2012Aug28.mat
   sigmaXi = 0;
   rXi = .1;
   maxActivation = 200;
%    nA = [1 10 20 50 100 200 500 1000];
   nA = 1000;%[10 100 1000];
   
%% Within trial noise levels

%    load /Users/bram/Documents/EPU/Simulation_2012Aug28/output_NoiseCorrelation/MultiData_nA100_sigmaXi050_rXi100_epu_simulation_2012Aug28.mat
%    load /Users/bram/Documents/EPU/Simulation_2012Aug28/output_NoiseCorrelation/MultiData_nA100_sigmaXi050_rXi100_epu_simulation_2012Aug28
%    load /Users/bram/Documents/EPU/Simulation_2012Aug28/output_variable_theta/MultiData_nA1_to_nA1000_sigmaXi000_sdTheta20_epu_simulation_2012Aug28.mat
%    load /Users/bram/Documents/EPU/Simulation_2012Aug28/output_NoiseCorrelation/MultiData_nA10_sigmaXi050_rXi000_epu_simulation_2012Aug28.mat   

%    load /Users/bram/Documents/EPU/Simulation_2012Aug28/output/MultiData_nA1_to_1000_sigmaXi050_rXi010_epu_simulation_2012Aug28.mat

%    nA = [1 10 20 30 40 50 60 70 80 90 100 200 300 400 500 600 700 800 900 1000];
%    nA = [1 10 20 50 100 200 500 1000];
%    nA = [10 100 1000];

   steps = 100;
   Ctop = flipud([linspace(1,1,steps)',linspace(0,1,steps)',linspace(0,1,steps)']);
   Cbot = flipud([linspace(1,0,steps)',linspace(1,0,steps)',linspace(1,1,steps)']);
   C = [Cbot;Ctop];

   fileSpecs.source = simData;
   fileSpecs.outputDir = '/Users/bram/Documents/EPU/Simulation_2012Aug28/figures/raw';
   fileSpecs.outputFileName = ['rt_median_nA_',num2str(nA)];

%% Sanity checks

%    %% Heat maps of nRecorded
%    nCmapSteps = 99;
%    cmap = othercolor('Mlighttemperaturemap',nCmapSteps);
%    cmap = flipud(cmap(median(1:nCmapSteps):end,:));
%    dependent.class = {'nRecorded',[],'mean',sigmaXi,rXi,maxActivation};
%    dependent.plotType = {'heat',nA};
%    dependent.colorMap = {cmap,[80 100]};
%    dependent.error.class = {'nRecorded',[],'ci(1)'};
%    dependent.error.criterion = {'in',0,90};
%    dependent.error.plotType = {'hatch',10};

%    %% Heat maps of threshold-by-RT relationship
%    cmap = othercolor('Mlighttemperaturemap',99);
%    dependent.class = {'thresVsRtPoly1_H','paramsSign','data(:,1)',sigmaXi,rXi,maxActivation};
%    dependent.plotType = {'heat',10};
%    dependent.colorMap = {cmap,[0 1000]};

%% Effect of rV, pN, and N on distribution of response time

%    %% Heat maps of RT location parameter
%    nCmapSteps = 99;
%    cmap = othercolor('Mlighttemperaturemap',nCmapSteps);
%    cmap = flipud(cmap(median(1:nCmapSteps):end,:));
%    dependent.class = {'rt','median','mean',sigmaXi,rXi,maxActivation};
%    dependent.plotType = {'heat',nA};
%    dependent.colorMap = {cmap,[0 800]};

%    %% Heat maps of RT spread parameter
%    nCmapSteps = 99;
%    cmap = othercolor('Mlighttemperaturemap',nCmapSteps);
%    cmap = flipud(cmap(median(1:nCmapSteps):end,:));
%    dependent.class = {'rt','iqr','mean',sigmaXi,rXi,maxActivation};
%    dependent.plotType = {'heat',nA};
%    dependent.colorMap = {cmap,[0 800]};

%    %% Quantile line plots against nA
%    dependent.class = {'rt','quantileX','mean',sigmaXi,rXi,maxActivation};
%    dependent.plotType = {'line',nA};
%    dependent.colorMap = {'hsv',[1 1000]}; % This determines the nA range for which regression is done

%    %% Line plots of distributions - for RT, the EDF is most interesting
%    dependent.class = {'rt','kernelX','mean',sigmaXi,rXi,maxActivation};
%    dependent.plotType = {'distline',1};
   
%% Effect of rV, pN, and N on distribution of threshold

   %% Heat maps of threshold location parameter
%    nCmapSteps = 99;
%    cmap = othercolor('Mlighttemperaturemap',nCmapSteps);
%    cmap = flipud(cmap(median(1:nCmapSteps):end,:));
%    dependent.class = {'threshold','mean','mean',sigmaXi,rXi,maxActivation};
%    dependent.plotType = {'heat',nA};
%    dependent.colorMap = {cmap,[0 500]};

%    %% Heat maps of threshold spread parameter
%    nCmapSteps = 99;
%    cmap = othercolor('Mlighttemperaturemap',nCmapSteps);
%    cmap = flipud(cmap(median(1:nCmapSteps):end,:));
%    dependent.class = {'threshold','std','mean',sigmaXi,rXi,maxActivation};
%    dependent.plotType = {'heat',nA};
%    dependent.colorMap = {cmap,[0 500]};

%    %% Quantile line plots against nA
%    dependent.class = {'threshold','quantileX','mean',sigmaXi,rXi,maxActivation};
%    dependent.plotType = {'line',[10 20 50 100 200 500 1000]};
%    dependent.colorMap = {'hsv',[1 1000]}; % This determines the nA range for which regression is done

%    %% Line plots of distributions - for threshold, the kernel estimator is most interesting
%    dependent.class = {'threshold','kernelX','mean',sigmaXi,rXi,maxActivation};
%    dependent.plotType = {'distline',10};


%% Effect of rV, pN, and N on distribution of rate

%    %% Heat maps of rate location parameter
%    nCmapSteps = 99;
%    cmap = othercolor('Mlighttemperaturemap',nCmapSteps);
%    cmap = flipud(cmap(median(1:nCmapSteps):end,:));
%    dependent.class = {'rate','mean','mean',sigmaXi,rXi,maxActivation};
%    dependent.plotType = {'heat',nA};
%    dependent.colorMap = {cmap,[0 5]};

%    %% Heat maps of threshold spread parameter
%    nCmapSteps = 99;
%    cmap = othercolor('Mlighttemperaturemap',nCmapSteps);
%    cmap = flipud(cmap(median(1:nCmapSteps):end,:));
%    dependent.class = {'rate','std','mean',sigmaXi,rXi,maxActivation};
%    dependent.plotType = {'heat',nA};
%    dependent.colorMap = {cmap,[0 5]};

%    %% Quantile line plots against nA
%    dependent.class = {'rate','quantileX','mean',sigmaXi,rXi,maxActivation};
%    dependent.plotType = {'line',[10 20 50 100 200 500 1000]};
%    dependent.colorMap = {'hsv',[10 maxActivation]}; % This determines the nA range for which regression is done
   
%    %% Line plots of distributions - for threshold, the kernel estimator is most interesting
%    dependent.class = {'rate','kernelX','mean',sigmaXi,rXi,maxActivation};
%    dependent.plotType = {'distline',10};


%% Relation between threshold and RT

   %% Heat maps of threshold-by-RT relationship
%    cmap = othercolor('Mlighttemperaturemap',99);
%    dependent.class = {'thresVsRtPoly1_H','params','mean',sigmaXi,rXi,maxActivation};
%    dependent.plotType = {'heat',10};
%    dependent.colorMap = {cmap,[-.2 .2]};
%    dependent.error.class = {'thresVsRtPoly1_H','paramsSign','data(:,1)'};
%    dependent.error.criterion = {'not','0'};
%    dependent.error.plotType = {'hatch',10};

%    % Heat maps of threshold-by-RT relationship
%    cmap = flipud(othercolor('Mredbluetones',99));
%    dependent.class = {'thresVsRtPoly1_W','params','mean',sigmaXi,rXi,maxActivation};
%    dependent.plotType = {'heat',nA};
%    dependent.colorMap = {cmap,[-0.2 0.2]};
%    dependent.error.class = {'thresVsRtPoly1_W','params','sign(1)'};
%    dependent.error.criterion = {'not','0'};
%    dependent.error.plotType = {'hatch',nA};

     %% Line plots of distributions
     dependent.class = {'thresVsRtPoly1_W','dataX','mean',sigmaXi,rXi,maxActivation};
     dependent.plotType = {'distline',10};
   
%      %% Line plots of distributions
%      dependent.class = {'thresVsRtPoly1','params','mean(1)',sigmaXi,rXi,maxActivation};
%      dependent.plotType = {'line',[1 10 20 50 100 200 500]};
%      dependent.colorMap = {'hsv',[10 maxActivation]}; % This determines the nA range for which regression is done

% % Histograms of slope distributions
% dependent.class = {'thresVsRtPoly1_W','params','data(:,1)',sigmaXi,rXi,maxActivation};
% dependent.plotType = {'hist',nA};

%% Relation between rate and RT

%    %% Heat maps of rate-by-RT relationship
%    cmap = othercolor('Mlighttemperaturemap',99);
%    dependent.class = {'rateVsRtRat01_H','params','mean',sigmaXi,rXi,maxActivation};
%    dependent.plotType = {'heat',1000};
%    dependent.colorMap = {cmap,[-500 500]};
%    dependent.error.class = {'rateVsRtRat01_H','params','sign(1)'};
%    dependent.error.criterion = {'in',-maxActivation,0};
%    dependent.error.plotType = {'hatch',1000};

%    %% Heat maps of rate-by-RT relationship
%    cmap = othercolor('Mredbluetones',99);
%    dependent.class = {'rateVsRtRat01_W','params','mean',sigmaXi,rXi,maxActivation};
%    dependent.plotType = {'heat',nA};
%    dependent.colorMap = {cmap,[-500 500]};
%    dependent.error.class = {'rateVsRtRat01_W','params','sign(1)'};
%    dependent.error.criterion = {'in',-maxActivation,0};
%    dependent.error.plotType = {'hatch',nA};

%    %% Line plots of distributions
%    dependent.class = {'rateVsRtRat01_W','dataX','mean',sigmaXi,rXi,maxActivation};
%    dependent.plotType = {'distline',10};




















%    %% Heat maps of threshold location parameter
%    nCmapSteps = 199;
%    cmap1 = othercolor('Mlighttemperaturemap',nCmapSteps);
%    cmap1 = cmap1(1:median(1:nCmapSteps),:);
%    nCmapSteps = 1799;
%    cmap2 = othercolor('Mlighttemperaturemap',nCmapSteps);
%    cmap2 = cmap2(median(1:nCmapSteps):end,:);
%    cmap = [cmap1;cmap2];
%    
%    dependent.class = {'threshold','mean','mean',0.5,0.1,maxActivation};
%    dependent.plotType = {'heat',nA};
%    dependent.colorMap = {cmap,[0 1000]};

%    % %% Heat maps of R-square of curve fits
%    nCmapSteps = 99;
%    cmap = othercolor('Mlighttemperaturemap',nCmapSteps);
%    cmap = cmap(median(1:nCmapSteps):end,:);
%    % dependent.class = {'thresVsRtPoly1','rSquare','mean',0.5,0.1,maxActivation};
%    dependent.class = {'rateVsRtPower1','rSquare','mean',0.5,0.1,maxActivation};
%    dependent.plotType = {'heat',nA};
%    dependent.colorMap = {cmap,[0 1]};

%    %% Heat maps of CV(RMSE) of curve fits
%    dependent.class = {'thresVsRtPoly1','rmseCoV','mean',0.5,0.1,maxActivation};
%    dependent.plotType = {'heat',nA};
%    dependent.colorMap = {Ctop,[0 .2]};

%    %% Heat maps of simulation times
%    dependent.class = {'elapsedTime',[],[],0.5,0.1,maxActivation};
%    dependent.plotType = {'heat',nA};
%    dependent.colorMap = {'jet',[0 100]};






     


   figureSpecs.figSpecs = {24,24,'centimeters'};
   figureSpecs.paperSpecs = {'USLetter','portrait'};
   figureSpecs.otherSpecs = {'Helvetica',10};

   panelSpecs.title = '';
   panelSpecs.xLabel = 'none';
   panelSpecs.yLabel = 'none';
   panelSpecs.colorBar = 'yes!';

   epu_plot_new(fileSpecs,dependent,figureSpecs,panelSpecs);
   
   % Save it
%    outputName = fullfile(fileSpecs.outputDir,fileSpecs.outputFileName);
%    saveas(gcf, outputName, 'epsc')
   
   % Close window
%    close;
   
