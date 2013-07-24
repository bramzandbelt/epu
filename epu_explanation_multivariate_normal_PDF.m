function epu_explanation_multivariate_normal_PDF

screenSize = get(0,'ScreenSize');
figure; hold on;
p = panel('defer');
rVs = .1:.2:.9;
p.pack(1,length(rVs));


for i = 1:length(rVs);
   
   p(1,i).select();
   nA = 2;
   rV = rVs(i);

   meanVec = zeros(1,nA);  % Vector with means
   sdVec = ones(1,nA);     % Vector with standard deviations

   % Compute correlation matrix
   rhoV = rV.*ones(nA);
   rhoV(linspace(1,numel(rhoV),length(rhoV))) = 1;

   % Transform correlation matrix to covariance matrix
   Sigma = corr2cov(sdVec,rhoV);

   % Independent variable - N-by-D array

   [X1,X2] = meshgrid(linspace(-3,3,30)', linspace(-3,3,30)');
   X = [X1(:),X2(:)];

   % Multivariate normal PDF
   Y = mvnpdf(X,meanVec,Sigma);

   % Plot
   surf(X1,X2,reshape(Y,30,30),'EdgeColor','none');
   colormap(othercolor('Msolarcolors',64));
   axis tight
end

p.refresh();