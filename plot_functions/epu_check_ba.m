clear all;close all;

v = [0.1 0.2 0.5 1 2 5];
theta = 100*ones(1,6);
maxActivation = 125;
k = v./maxActivation;
affTime = 100;
effTime = 15;
pN = 1;
dMeth = 1;
iAT = 1:length(v);

[rt,activation] = epu_n_unit_ba_mex(v,theta,k,affTime,effTime,pN,dMeth,iAT);

figure; hold on;
plot(activation);
if dMeth == 2
   plot(mean(activation,2),'k-','LineWidth',2);
end
line([0 rt],[mean(theta) mean(theta)],'Color','k','LineStyle','--');
line([rt-effTime rt-effTime],[0 maxActivation],'Color',[.8 .8 .8],'LineStyle',':');
line([rt rt],[0 maxActivation],'Color','k','LineStyle','--');