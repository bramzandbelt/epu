function varargout = epu_check_inputs(varargin)
%
% USAGE
% [nSes,nSim,nA,nTP,nAT,mV,sdV,rV,dt,sigmaXi,rXi,mTheta,sdTheta,...
%  maxActivation,affTime,effTime,pN,dMeth,tag,rngID] = epu_check_inputs(job);
%
   if ischar(varargin{1})
      switch lower(varargin{1})
         case 'get_defaults'
            job.nSes = 1000;
            job.nSim = 500;
            job.nA = 10;
            job.nTP = 10000; 
            job.nAT = 1; 
            job.mV = 1;   
            job.sdV = 1;
            job.rV = 0:.1:1;
            job.dt = 1;
            job.sigmaXi = 0.5;
            job.rXi = .1;
            job.mTheta = 100;   
            job.sdTheta = 0;
            job.maxActivation = Inf;
            job.affTime = 100;    
            job.effTime = 15;    
            job.pN = 0;
            job.dMeth = 1;
            job.tag = '';
            job.rngID = rng('shuffle');
      end

      varargout{1} = job;

   else
   
      job = varargin{1};

       % 1. Number of sessions
      if isfield(job,'nSes');
         nSes = job.nSes;
      else
         nSes = 1000; % Default
      end
      
      % 2. Number of simulations
      if isfield(job,'nSim');
         nSim = job.nSim;
      else
         nSim = 500; % Default
      end

      % 3. Number of accumulators
      if isfield(job,'nA');
         nA = job.nA;
      else
         nA = 10; % Default
      end

      % 4. Number of time points (1-ms increments from 0 ms) for which to compute activation trajectories 
      if isfield(job,'nTP');
         nTP = job.nTP;
      else
         nTP = 1500; % Default
      end

      % 5. Number of accumulators for which to record activation trajectories
      if isfield(job,'nAT');
%          if job.nAT ~= 1
%             warning('Current epu_sim_master cannot handle nAT > 1. nAT is now set to 1.');
%             nAT = 1;
%          else
            nAT = job.nAT;
%          end
      else
         nAT = 1; % Default
      end
      
      % 6. Mean of the lognormal accumulation rate distribution
      if isfield(job,'mV');
         mV = job.mV;
      else
         mV = 1; % Default
      end

      % 7. S.d.  of the lognormal accumulation rate distribution
      if isfield(job,'sdV');
         sdV = job.sdV;
      else
         sdV = 1; % Default
      end
      
      % 8. Correlation of accumulation rates between accumulators
      if isfield(job,'rV');
         rV = job.rV;
      else
         rV = 0:.1:1; % Default
      end
      
      % 9. Time step of the stochastic differential equation
      if isfield(job,'dt');
         dt = job.dt;
      else
         dt = 1; % Default
      end
      
      % 10. Scale parameter of the Gaussian noise distribution
      if isfield(job,'sigmaXi');
         sigmaXi = job.sigmaXi;
      else
         sigmaXi = 0; % Default
      end
      
      % 11. Correlation of the Gaussian noise
      if isfield(job,'rXi');
         rXi = job.rXi;
      else
         rXi = 1; % Default
      end
      
      % 12. Mean of the Gaussian threshold distribution
      if isfield(job,'mTheta');
         mTheta = job.mTheta;
      else
         mTheta = 100; % Default
      end
      
      % 13. S.d. of the Gaussian threshold distribution
      if isfield(job,'sdTheta');
         sdTheta = job.sdTheta;
      else
         sdTheta = 0; % Default
      end
      
      % 14. Maximum activation level an accumulator can reach
      if isfield(job,'maxActivation');
         maxActivation = job.maxActivation;
      else
         maxActivation = 1000; % Default
      end
      
      % 15. Afferent (encoding) time
      if isfield(job,'affTime');
         affTime = job.affTime;
      else
         affTime = 100; % Default
      end
      
      % 16. Efferent (response execution) time
      if isfield(job,'effTime');
         effTime = job.effTime;
      else
         effTime = 10; % Default
      end
      
      % 17. Proportion of accumulators necessary to produce an RT ('RT rule').
      if isfield(job,'pN');
         pN = job.pN;
      else
         pN = 0; % Default
      end
      
      % 18. Decision method: polling (1) or pooling (2)
      if isfield(job,'dMeth');
         dMeth = job.dMeth;
      else
         dMeth = 1; % Default
      end

      % 19. Tag
      if isfield(job,'tag');
         tag = job.tag;
      else
         tag = ''; % Default
      end
      
      if dMeth == 1
         tag = [tag,'_polled'];
      elseif dMeth == 2
         tag = [tag,'_pooled'];
      end
      
      % 19. ID of random number generator seed
      if isfield(job,'rngID');
         rngID = job.rngID;
      else
         rngID = rng('shuffle');
      end

      if nargout == 0
         assignin('caller','nSes',nSes);
         assignin('caller','nSim',nSim);
         assignin('caller','nA',nA);
         assignin('caller','nTP',nTP);
         assignin('caller','nAT',nAT);
         assignin('caller','mV',mV);
         assignin('caller','sdV',sdV);
         assignin('caller','rV',rV);
         assignin('caller','dt',dt);
         assignin('caller','sigmaXi',sigmaXi);
         assignin('caller','rXi',rXi);
         assignin('caller','mTheta',mTheta);
         assignin('caller','sdTheta',sdTheta);
         assignin('caller','maxActivation',maxActivation);
         assignin('caller','affTime',affTime);
         assignin('caller','effTime',effTime);
         assignin('caller','pN',pN);
         assignin('caller','dMeth',dMeth);
         assignin('caller','tag',tag);
         assignin('caller','rngID',rngID);
      else
         % Outputs
         varargout{1} = nSes;
         varargout{2} = nSim;
         varargout{3} = nA;
         varargout{4} = nTP;
         varargout{5} = nAT;
         varargout{6} = mV;
         varargout{7} = sdV;
         varargout{8} = rV;
         varargout{9} = dt;
         varargout{10} = sigmaXi;
         varargout{11} = rXi;
         varargout{12} = mTheta;
         varargout{13} = sdTheta;
         varargout{14} = maxActivation;
         varargout{15} = affTime;
         varargout{16} = effTime;
         varargout{17} = pN;
         varargout{18} = dMeth;
         varargout{19} = tag;
         varargout{20} = rngID;
      end
   end
      
end