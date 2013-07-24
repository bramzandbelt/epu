


nAs = [1 10 20 50 100 200 500 1000];

% Simulation settings
nSim = 500;
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
pN = 0.5;
dMeth = 1;

t = 0:2000;
qntls = [.1 .3 .5 .7 .9];
% Arrays for logging data

simData(length(nAs)) = struct('nA',nan(1,1), ...
                              'rt',nan(nSim,1), ...
                              'params',nan(1,3), ...
                              'f',nan(length(t),1), ...
                              'F',nan(length(t),1), ...
                              'q',nan(1,5));

for iNa = 1:length(nAs)
   
   % Simulate RT distribution
   nA = nAs(iNa); 
   rt = epu_sim(nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,maxActivation,affTime,effTime,pN,dMeth)
   rt = double(rt);
   simData(iNa).rt = rt;
   
   % Fit Ex-Gaussian to RT distribution
   [params,sse,FZr,fitSucess] = fit_fun_to_data('exgaussian',[nanmedian(rt),nanstd(rt),5],sort(rt),affTime);
   simData(iNa).params = params;
   
   % Get Ex-Gaussian PDF & CDF
   simData(iNa).f = mtb_exgaussian_pdf(t,params);
   simData(iNa).F = mtb_exgaussian_cdf(t,params);
   
   % Compute quantiles
   for iQ = 1:length(qntls)
      if qntls(iQ) <= max(simData(iNa).F(:))
         simData(iNa).q(iQ) = t(find(simData(iNa).F >- qntls(iQ),1,'first'));
      else
         simData(iNa).q(iQ) = NaN;
      end
   end
   
end






