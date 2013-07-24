function epu_plot_quantile_plot_logic


simData = load('/Users/bram/Documents/EPU/Simulation_2012Aug28/output/MultiData_nA1_to_1000_sigmaXi000_rXi010_epu_simulation_2012Aug28.mat');
simData = simData(1).simData;

nAs = [1 10 20 50 100 200 500 1000];

% Simulation settings
nSim = 500;
nSes = 5;
nTP = 10000;
nAT = 1;
mV = 1;
sdV = 1;
rV = .5;
dt = 10;
sigmaXi = 0;
rXi = .1;
mTheta = 100;
sdTheta = 0;
maxActivation = Inf;
affTime = 100;
effTime = 15;
pN = 0;
dMeth = 1;

t = 0:1:1500;
qntls = [.1 .3 .5 .7 .9];
% Arrays for logging data

plotData(length(nAs)) = struct('nA',nan(1,1), ...
                              'rt',nan(nSim,1), ...
                              'f',nan(length(t),1), ...
                              'xi',nan(length(t),1), ...
                              'iqr',nan(1,1), ...
                              'q1',nan(1,1),...
                              'q',nan(1,5));
                           
for iNa = 1:length(nAs)
   
   
   
   % Simulate RT distribution
   nA = nAs(iNa); 
   plotData(iNa).nA = nA;
   
   rtMat = nan(nSim,nSes);
   for iSes = 1:nSes
      rtVec = epu_sim(nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation,affTime,effTime,pN,dMeth);
      rtMat(:,iSes) = sort(rtVec);
   end
   rt = nanmean(rtMat,2);
   rt = double(rt);
   plotData(iNa).rt = rt;
   
   plotData(iNa).q1 = quantile(rt,.25);
   
   iRow = find(simData.nA == nA & simData.rV == rV & simData.pN == pN & simData.dMeth == dMeth);
   bli = simData.rt(iRow);
   
   plotData(iNa).q = bli{1}.quantileX.mean;
   plotData(iNa).iqr = bli{1}.iqr.mean;
   
   [f,xi] = ksdensity(rt,t);
   
   plotData(iNa).f = f;
   plotData(iNa).xi = xi;
   
   
   % Fit Ex-Gaussian to RT distribution
%    a = bli{1}.median.mean;
%    b = bli{1}.std.mean;
%    c = 50;
%    initParams = [a,b,c];
%    edfX = bli{1}.edfX.mean;
%    edfY = bli{1}.edfY.mean;
%    
%    params = fit_ex_gaussian(edfX,edfY,initParams)
%    
%    
% %    [params,sse,FZr,fitSucess] = fit_fun_to_data('exgaussian',[nanmedian(rt),nanstd(rt),5],sort(rt),affTime);
% %    plotData(iNa).params = params;
%    
%    % Get Ex-Gaussian PDF & CDF
%    plotData(iNa).f = mtb_exgaussian_pdf(t,params);
%    plotData(iNa).F = mtb_exgaussian_cdf(t,params);
   
%    % Compute quantiles
%    for iQ = 1:length(qntls)
%       if qntls(iQ) <= max(plotData(iNa).F(:))
%          plotData(iNa).q(iQ) = t(find(plotData(iNa).F >= qntls(iQ),1,'first'));
%       else
%          plotData(iNa).q(iQ) = NaN;
%       end
%    end
end


figure;
p = panel;
p.pack('v',length(nAs));

for iNa = 1:length(nAs)
   p(iNa).margin = [0 2 0 2];
   p(iNa).select();
   plot(plotData(iNa).xi,plotData(iNa).f,'k-'); hold on;
%    for iQ = 1:length(qntls)
%       line([plotData(iNa).q(iQ),plotData(iNa).q(iQ)],[0,plotData(iNa).f(round(plotData(iNa).q(iQ)))],'LineStyle',':');
%    end
%    hMarkers = plot(plotData(iNa).q,0,'k.');
%    set(hMarkers,'MarkerSize',10);
   
   for iQ = 3
      line([plotData(iNa).q(iQ),plotData(iNa).q(iQ)],[0,plotData(iNa).f(round(plotData(iNa).q(iQ)))],'LineStyle',':');
   end
   hMarkers = plot(plotData(iNa).q(3),0,'k.');
   set(hMarkers,'MarkerSize',10);
   
   line([plotData(iNa).q1,plotData(iNa).q1+plotData(iNa).iqr],[.005,.005]);
   
end



function finalParams = fit_ex_gaussian(edfX,edfY,initParams)
   [finalParams,SSE,fitSuccess] = fminsearchbnd(@(params) mtb_sse(edfY,mtb_exgaussian_cdf(edfX,initParams)),initParams,[0 0 0],[5000 5000 5000]);
end

end



