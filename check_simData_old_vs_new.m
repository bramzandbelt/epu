function check_simData_old_vs_new

% Load original data set
% load('/Users/bram/Documents/EPU/Simulation_2012Apr13/output/sim_activation_nA10_mR075_mT100_aLim100000_20120412T181028_MultiData.mat')
load('/Users/bram/Documents/EPU/Simulation_2012Apr13/output/decay_rt_only/temp/sim_activation_nA10_mR075_mT100_aLim100000_20120503T075939_MultiData.mat')
simDataMultiOrig = simDataMulti;
clear simDataMulti

j = find(simDataMultiOrig.q == .70 & simDataMultiOrig.r == .70);

% Load new data set
% load('/Users/bram/Documents/EPU/Simulation_2012May01/replication_test/sim_replication_test_q070_r070_polled_20120502T114648_MultiData.mat');
% load('/Users/bram/Documents/EPU/Simulation_2012May01/replication_test/sim_q070_r070_removeNaNDiscarded_polled_20120502T145327_MultiData.mat');
% load('/Users/bram/Documents/EPU/Simulation_2012May01/replication_test/sim_get_activation_up_to_rt_polled_20120503T123555_MultiData.mat');
load('/Users/bram/Documents/EPU/Simulation_2012May03/output/PerfectDeterministic/sim_nA10_mR075_mT10020120504T145826_MultiData.mat');



%% Figure with behavioral data
figure;

% RT CDF
subplot(3,3,1)
plot(simDataMulti.rtCdf{j}.mean,simDataMulti.FCdf{j}.mean,'b-');hold on;
plot(simDataMultiOrig.rtCdf{j}.mean,simDataMultiOrig.FCdf{j}.mean,'r-')
title('RT CDF');

% RT Gaussian Kernel
subplot(3,3,2)
plot(simDataMulti.rtGaussKernel{j}.mean,simDataMulti.fGaussKernel{j}.mean,'b-');hold on;
plot(simDataMultiOrig.rtGaussKernel{j}.mean,simDataMultiOrig.fGaussKernel{j}.mean,'r-');
title('RT Gaussian kernel histograms');

% Median RT
subplot(3,3,3)
bar([simDataMulti.medianRt{j}.mean,simDataMultiOrig.medianRt{j}.mean;nan nan]);
set(gca,'XLim',[0.5 1.5]);
title('Median RT');

% SD RT
subplot(3,3,4)
bar([simDataMulti.sdRt{j}.mean,simDataMultiOrig.sdRt{j}.mean;nan nan]);
set(gca,'XLim',[0.5 1.5]);
title('S.D. RT');

% CoV RT
subplot(3,3,5)
bar([simDataMulti.covRt{j}.mean,simDataMultiOrig.covRt{j}.mean;nan nan]);
set(gca,'XLim',[0.5 1.5]);
title('Coefficient of variation RT');

% IQR RT
subplot(3,3,6)
bar([simDataMulti.iqrRt{j}.mean,simDataMultiOrig.iqrRt{j}.mean;nan nan]);
set(gca,'XLim',[0.5 1.5]);
title('IQR RT');

% Skewness RT
subplot(3,3,7)
bar([simDataMulti.skewnessRt{j}.mean,simDataMultiOrig.skewnessRt{j}.mean;nan nan]);
set(gca,'XLim',[0.5 1.5]);
title('Skewness RT distribution');

% Kurtosis RT
subplot(3,3,8)
bar([simDataMulti.kurtosisRt{j}.mean,simDataMultiOrig.kurtosisRt{j}.mean;nan nan]);
set(gca,'XLim',[0.5 1.5]);
title('Kurtosis RT distribution');

%% Figure with brain data & brain-behavior relationships
figure;

% N Recorded
subplot(3,2,1)
bar([simDataMulti.nRecorded{j}.mean,simDataMultiOrig.nRecorded{j}.mean;nan nan]);
set(gca,'XLim',[0.5 1.5]);
title('N Recorded');

% Activation trajectories
subplot(3,2,2)
plot([-200:1:10],simDataMulti.rtAlignedTrajectories{j}.mean,'b-');hold on
plot([-200:1:200],simDataMultiOrig.rtAlignedTrajectories{j}.mean,'r-');

% Threshold vs RT: first-order polynomial
subplot(3,2,3)
plot(simDataMulti.rtBinned{j}.mean,simDataMulti.thresholdBinned{j}.mean,'b-');hold on;
plot(simDataMultiOrig.rtVincent{j}.mean,simDataMultiOrig.thresholdVincent{j}.mean,'r-');hold on;
title('Threshold vs RT: binned data');

subplot(3,2,4)
bar([simDataMulti.thresVsRtPoly1{j}.meanParams',simDataMultiOrig.thresVsRtPoly1{j}.meanParams']);
set(gca,'YScale','log');
title('Threshold vs RT: best fit params');

% Rate vs RT: rational
subplot(3,2,5)
plot(simDataMulti.rtBinned{j}.mean,simDataMulti.rateBinned{j}.mean,'b-');hold on;
plot(simDataMultiOrig.rtVincent{j}.mean,simDataMultiOrig.rateVincent{j}.mean,'r-');hold on;
title('Rate vs RT: binned data');

subplot(3,2,6)
bar([simDataMulti.rateVsRtRat01{j}.meanParams',simDataMultiOrig.rateVsRtRat01{j}.meanParams']);
title('Rate vs RT: best fit params');

