% Check out rate distributions
nA = 10;
mV = 1;
sdV = 1;
allrV = [0:.1:1];
nSim = 10000;

rates = nan(nSim,length(allrV));

for i = 1:length(allrV)

   rV = allrV(i);
   rhoV = rV.*ones(nA);
   rhoV(linspace(1,numel(rhoV),length(rhoV))) = 1;

   muV = log(mV^2 / sqrt(sdV^2+mV^2));
   sigmaV = sqrt(log(sdV^2/mV^2 + 1));     
   muVvec = kron(ones(nA,1),muV);
   sigmaVvec = kron(ones(nA,1),sigmaV);

   v = MvLogNRand(muVvec,sigmaVvec,nSim,rhoV);

   rates(:,i) = v(:,1);
   clear rhoV muV sigmaV muVvec sigmaVvec
end