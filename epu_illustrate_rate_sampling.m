function epu_illustrate_rate_sampling

mV = 1;     % Mean of lognormal distribution
sdV = 1;    % Standard deviation of log-normal distribution
rV = 0.5;   % Correlation coefficient
nA = 10;    % Number of accumulators
nSim = 20;  % Number of simulations


rVvec = [0.1 0.5 0.9];
hFig = set_figure({10,20,'centimeters'},{'USLetter','landscape'})
p = panel;
p.pack(2,1);
p(1,1).pack(2,4);
p(2,1).pack(1,4);

% p.pack(3,4);

%% 
% *3.3 Calculate location parameter |muV| and scale parameter |sigmaV| of lognormal accumulation rate distribution from |mV| and |sdV|*
muV = log(mV^2 / sqrt(sdV^2+mV^2));
sigmaV = sqrt(log(sdV^2/mV^2 + 1));     
muVvec = kron(ones(nA,1),muV);
sigmaVvec = kron(ones(nA,1),sigmaV);

% Force column vectors
Mu     = muVvec(:);
Sigma  = sigmaVvec(:);

% Data for the covariance structure
sigma_down = repmat( Sigma' , numel(Sigma), 1            );
sigma_acrs = repmat( Sigma  , 1           , numel(Sigma) );

for iP = 1:2
   for iR = 1:3

      rV = rVvec(iR);

      % *3.2 Set up correlation matrix |rhoV| of accumulation rates between accumulators*
      rhoV = rV.*ones(nA);
      rhoV(linspace(1,numel(rhoV),length(rhoV))) = 1;

      CorrMat = rhoV;
      
      % Calculate the covariance structure
      covv = log( CorrMat .* sqrt(exp(sigma_down.^2)-1) .* ...
                             sqrt(exp(sigma_acrs.^2)-1) + 1 );

      % The Simulation
      y = exp( mvnrnd( Mu , covv , nSim ));

      if iP == 1
         p(iP,1,1,iR).select();
         imagesc(rhoV,[0 1]);
         colormap(othercolor('Msolarcolors',64));
         title(['r_V = ',num2str(rV)]);
         axis('tight','square','ij')

         if iR == 1
            xlabel('A_i');
            ylabel('A_j');
         elseif iR == 3
            p(iP,1,1,4).select();
            imagesc(rhoV,[0 1]);
            colorbar('peer',gca);
            set(gca,'Visible','off');
         end

         p(iP,1,2,iR).select();
         imagesc(covv,[0 1]);
         axis('tight','square','ij')
         if iR == 1
            xlabel('A_i');
            ylabel('A_j');
         elseif iR == 3
            p(iP,1,2,4).select();
            imagesc(covv,[0 1]);
            colorbar('peer',gca);
            set(gca,'Visible','off');
         end
      
      elseif iP == 2
         
         p(iP,1,1,iR).select();
         imagesc(y,[0 3]);
         colormap(othercolor('Msolarcolors',64));
         set(gca,'DataAspectRatio',[1,1,1]);
         axis('tight','ij')
         if iR == 1
            xlabel('A_i');
            ylabel('Simulation_i');
         elseif iR == 3
            p(iP,1,1,4).select();
            imagesc(y,[0 3]);
            colorbar('peer',gca);
            set(gca,'Visible','off');
         end
         
      end


   end
end