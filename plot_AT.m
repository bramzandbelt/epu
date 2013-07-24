figure;
for iSim = 1:size(activation,1)
   cla; hold on;
   plot(squeeze(activation(iSim,:,:))');
   line([0 rt(iSim)],[mTheta mTheta],'Color','k');
   line([rt(iSim) rt(iSim)],[0 mTheta],'Color','k');
   pause;
end