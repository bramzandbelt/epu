function varargout = ...
epu_sim_old(simDataType,nS,nA,mR,sR,mT,sT,t0,r,q,varargin)
%EPU_SIM Simulation function of E Pluribus Unum modeling project
% COMMON INPUTS
% simDataType   - data type to simulate
%                 - 'rt'
%                 - 'activation'
% nS            - number of simulations
% nA            - number of accumulators
% mR            - mean growth rate of accumulator (in Hz ms-1)
% sR            - standard deviation of growth rate of accumulator (in Hz
%                 ms-1)
% mT            - mean trigger threshold among accumulators (in Hz ms-1)
% sT            - standard deviation of trigger threshold among
%                 accumulators (in Hz ms-1)
% t0            - accumulation onset asynchrony (in ms), interval between
%                 trial onset and accumulaton onset
% r             - correlation of growth rate between accumulators
% q             - response time rule (proportion of accumulators that should
%                 reach threshold, [0 1]). This can be an array of proportions,
%                 e.g. [0 .1 .3 .5 .7 .9]. The value 0 is special, indicating
%                 that the very first accumulator reaching threshold determines
%                 response time.
%
% ADDITIONAL INPUTS FOR SIMDATATYPE 'ACTIVATION'
% nTP           - number of time points (TP) for logging data (ms from target onset) 
% nAT           - number of accumulators for which to provide activation
%                 trajectories (AT)
% aLim          - the maximum activation level an accumulator can reach.If
%                 this value is smaller than 1, it is considered a fraction 
%                 (e.g. 60 Hz RT threshold /120 Hz limit = 0.5). If it is 
%                 greater than 1, it is considered an absolute activation level.
%
% EXAMPLE USAGE
% [rt,rate,elapsedTime] = ... 
% epu_sim('rt',nS,nA,mR,sR,mT,sT,t0,r,q);
%
% [rt,activation,rate,selectedAccums,elapsedTime] = ... 
% epu_sim('activation',nS,nA,mR,sR,mT,sT,t0,r,q,nTP,nAT,aLim);
% __________________________________________    
% October 2011, bram.zandbelt@vanderbilt.edu

elapsedTime = zeros(1,8);

%% 1. PARAMETERS
t1 = tic;

%%
% *1.1 User-defined parameters*
%
% User-defined inputs depend on |simDataType|, the data that are simulated: 
%%
% 
% * in case of |'rt'|, only response times are simulated
% * in case of |'activation'|, rt and activation profiles are simulated

switch lower(simDataType)
   case 'activation'
      nTP = varargin{1};
      nAT = varargin{2};
      aLim = varargin{3};
end
nQ = length(q);

%%
% *1.2 Constants*
%
% The simulations use a number of constants:
% * |DT_BALLISTIC| is the ballistic period in ms, the interval between an
% accumulator reaching threshold and the moment a response is made.  This number
% is based on *INCLUDE REFERENCES*
% * |HALF_LIFE| is the time it take for accumulators to return to half their
% activation level at threshold. This number was estimated based on Hanes &
% Schall (1996) Science 274:427, Fig. 3 and Churchland, Kiani & Shadlen (2008)
% Nat Neurosci 11:693, Fig. 2.
% * |TAU| is the lifetime of the exponential decay function
% * |LAMBDA| is the decay rate of the exponential decay function
% * |DECAY_TYPE| determines when decay of activity in an accumulator begins:
%     * |'thresholdonly'| only after reaching threshold
%     * |'thresholdorrt'| after reaching threshold OR after RT, whatever comes
%     first
%     * |'rtonly'| only after RT

DT_BALLISTIC = 10;
HALF_LIFE = 25;
TAU = HALF_LIFE/log(2);
LAMBDA = 1/TAU;
DECAY_TYPE = 'thresholdorrt';

elapsedTime(1) = toc(t1);

%% 2. ARRAYS FOR LOGGING DATA
t2 = tic;
% In these arrays, growth rate, response time and activation are logged.
switch lower(simDataType)
   case 'rt'
      rate = single(nan(nS,nA));
      rt = single(nan(nS,nQ));
   case 'activation'
      rate = single(nan(nS,nA));
      activation = single(nan(nS,nAT,nTP));
end

elapsedTime(2) = toc(t2);

%% 3. SIMULATION
t3 = tic;
% Growth rates are sampled from a multivariate lognormal distribution. A
% log normal distribution is chosen, because the Linear Ballistic
% Accumulator model assumes positive growth rates. The growth rates are
% correlated between accumulators. Then, for each trial the activation
% trajectory for all accumulators and response time is computed.

%%
% *3.1 Sample trigger threshols*
%
% A vector |theta| is generated, containing a trigger threshold for each
% accumulator. Trigger thresholds are sampled from a normal distribution with
% mean |mT| and standard deviation |sT|.
theta = (randn(1,nA)*sT) + mT;
elapsedTime(4) = toc(t3);

%% 
% *3.2 Set up correlation matrix*
%
% A matrix |rX| is generated, specifying the correlation of growth rates
% between accumulators.
t4 = tic;
rX = r.*ones(nA);
% rX(linspace(1,numel(nA),length(nA))) = 1;
rX(linspace(1,numel(rX),length(rX))) = 1;

% rX = eye(nA);                                               
% for i=2:nA
%     for j=1:i-1
%         rX(i,j)=r;
%         rX(j,i)=r;
%     end
% end
elapsedTime(4) = toc(t4);
%% 
% *3.3 Compute scale and location parameters for a lognormal distribution*
%
% A lognormal distribution with mean |mR| and standard deviation
% |sR| has a location parameter |muLognrnd| and scale parameter
% |sigmaLognrnd|. See also <matlab:help('lognrnd') lognrnd>. For now, we assume
% identical location and scale parameters across accumulators.
%
t5 = tic;
muLognrnd = log(mR^2 / sqrt(sR^2+mR^2));
sigmaLognrnd = sqrt(log(sR^2/mR^2 + 1));     
muvecLognrnd = kron(ones(nA,1),muLognrnd);
sigmavecLognrnd = kron(ones(nA,1),sigmaLognrnd);
elapsedTime(5) = toc(t5);
%%
% *3.4 Sample multivariant lognormal random growth rates with correlation*
%
% Growth rates are sample for each accumulator and each trial. Growth rates
% are correlated between accumulators, as specified in the correlation
% matrix |rX|.
%
t6 = tic;
rate = MvLogNRand(muvecLognrnd,sigmavecLognrnd,nS,rX);

elapsedTime(6) = toc(t6);
%%
% *3.5 Compute responses times *
%
% Response time |rt| is calculated as the sum of:
%%
% * |t0|, the accumulation onset asynchrony, or the time between trial
% onset and accumulation onset.
% * |dtAccumulation|, the time it takes for the accumulator to reach
% threshold
% * |DT_BALLISTIC|, the ballistic period
%
t7 = tic;
% Compute the growth time for each accumulator
dtAccumulation = kron(ones(nS,1),theta)./rate;

if nA > 1
   % Per simulation, sort growth times in ascending order
   dtAccumulation = sort(dtAccumulation')';
end

for iRtRule = 1:nQ
   prop = q(iRtRule) + realmin; % Add smallest positive floating-point number so that a proportion of 0 results in the first accumulator reaching thresold
   rt(:,iRtRule) = t0 + dtAccumulation(:,ceil(prop*nA)) + DT_BALLISTIC;
end
elapsedTime(7) = toc(t7);
%%
% *3.6 Compute accumulation trajectories (optional)*

% This computes activation trajectories for all trials of |nAT| accumulators
% randomly selected from the pool of accumulators.
% Activation is equal to zero during the non-decision time |t0|.
% After |t0|, activity grows linearly with rate |rate|, crosses threshold
% |theta| and continues growing until either enough accumulators have crossed
% threshold according to the RT rule |q| or the absolute activation limit
% |activationLimit| has been reached.
t8 = tic;
switch lower(simDataType)
   case 'activation'
      
      if aLim <= 1
         activationLimit = theta./aLim; % Double-check whether this is the best way to implement it
      else
         activationLimit = aLim.*ones(1,nA);
      end
      
      % Sample unique accumulators from set of all accumulators 
      selectedAccums = sort(randperm(nA,nAT));
      
      % Cell array of growth rates
      rateCell = num2cell(rate(:,selectedAccums));
      
      % Cell array of thresholds
      thresholdCell = num2cell(theta(:,selectedAccums));
      
      % Cell array of non-decision times (identical across trials and accumulators)
      t0Cell = num2cell(t0*ones(nS,nAT));
      
      % Cell array of RTs (identical across accumulators)
      rtCell = num2cell(kron(ones(1,nAT),rt));
      
      % Cell array of decay rates (identical across trials and accumulators)
      lambdaCell = num2cell(LAMBDA*ones(nS,nAT));
      
      switch DECAY_TYPE
         case {'thresholdonly','thresholdorrt'}
            % Cell array of thresholds (identical across trials, different 
            % between accumulators)
            thresholdCell = num2cell(kron(ones(nS,1),theta(selectedAccums)));
            
            % Cell array of the time needed to reach threshold
            timeToThreshold = num2cell(kron(ones(nS,1),theta(selectedAccums))./cell2mat(rateCell));
         case 'rtonly'
            % Cell array of absolute activation limits (identical across trials and
            % accumulators)
            activationLimitCell = num2cell(kron(ones(nS,1),activationLimit(selectedAccums)));

            % Cell array of the time needed to reach activation limit
            timeToActLimit = num2cell(kron(ones(nS,1),activationLimit(selectedAccums))./cell2mat(rateCell));
      end
      
      % Cell array of time points (identical across trials and accumulators)
      tCell = cellfun(@(N)(1:N),num2cell(nTP*ones(nS,nAT)),'UniformOutput',0);
      
      % Cell array baseline time point indices (identical across trials and accumulators)
      tBaseline = cellfun(@(x,y) find(x <= y),tCell,t0Cell,'UniformOutput',0);
      
      % Cell array of baseline activation levels
      activationBaseline = cellfun(@(x,y) x*y,num2cell(zeros(nS,nAT)),tBaseline,'UniformOutput',0);
            
      switch DECAY_TYPE
         case 'thresholdonly'
            % Cell array of pre-threshold time point indices
            tPreThreshold = cellfun(@(x,y,z) find(x > y & x - y <= z),tCell,t0Cell,timeToThreshold,'UniformOutput',0);
            
            % Cell array of decay time point indices
            tDecay = cellfun(@(x,y,z) find(x - y > z),tCell,t0Cell,timeToThreshold,'UniformOutput',0);
            
            % Cell array of pre-threshold activation levels
            activationPreThreshold = cellfun(@(x,y,z) x*(y-z),rateCell,tPreThreshold,t0Cell,'UniformOutput',0);
            
            % Cell array post-response activation levels
            activationDecay = cellfun(@(x,y,z) x*exp(-(1:numel(y))*z), ...
                                        thresholdCell,...
                                        tDecay, ...
                                        lambdaCell, ...
                                        'UniformOutput',0);
                                     
            % Cell array of whole-trial activation levels, obtained by concatenating
            % arrays
            activation = cellfun(@(x,y,z) horzcat(x,y,z),activationBaseline, ...
                                                         activationPreThreshold, ...
                                                         activationDecay,'UniformOutput',0);
                                     
         case 'thresholdorrt'
            % Cell array of pre-threshold or pre-RT time point indices
            tPreThresholdOrRt = cellfun(@(w,x,y,z) find(w > x & w <= y & w - x <= z),tCell,t0Cell,rtCell,timeToThreshold,'UniformOutput',0);
            
            % Cell array of decay time point indices
            tDecay = cellfun(@(w,x,y,z) find(w - x > y | w > z),tCell,t0Cell,timeToThreshold,rtCell,'UniformOutput',0);
            
            % Cell array of pre-threshold activation levels
            activationPreThresholdOrRt = cellfun(@(x,y,z) x*(y-z),rateCell,tPreThresholdOrRt,t0Cell,'UniformOutput',0);
            
            % Cell array activation levels at threshold or RT (needed for the decay function)
            activationAtThresholdOrRt = cellfun(@(u,v,w,x,y,z) myfun(u,v,w,x,y,z),t0Cell,timeToThreshold,rtCell,thresholdCell,rateCell,t0Cell,'UniformOutput',0);

            % Cell array post-response activation levels
            activationDecay = cellfun(@(x,y,z) x*exp(-(1:numel(y))*z), ...
                                        activationAtThresholdOrRt,...
                                        tDecay, ...
                                        lambdaCell, ...
                                        'UniformOutput',0);
                                     
            % Cell array of whole-trial activation levels, obtained by concatenating
            % arrays
            activation = cellfun(@(x,y,z) horzcat(x,y,z),activationBaseline, ...
                                                         activationPreThresholdOrRt, ...
                                                         activationDecay,'UniformOutput',0);
            
         case 'rtonly'
            % Cell array of pre-limit time point indices
            tPreLimit = cellfun(@(w,x,y,z) find(w > x & w <= y & w - x <= z),tCell,t0Cell,rtCell,timeToActLimit,'UniformOutput',0);

            % Cell array post-limit (activation equal to activation) time point indices
            tPostLimit = cellfun(@(w,x,y,z) find(w - x > y & w <= z),tCell,t0Cell,timeToActLimit,rtCell,'UniformOutput',0);

            % Cell array post-response time point indices
            tDecay = cellfun(@(x,y) find(x > y),tCell,rtCell,'UniformOutput',0);
            
            % Cell array pre-overshoot activation levels
            activationPreLimit = cellfun(@(x,y,z) x*(y-z),rateCell,tPreLimit,t0Cell,'UniformOutput',0);

            % Cell array post-overshoot  activation levels
            activationPostLimit = cellfun(@(x,y) x*ones(size(y)),activationLimitCell,tPostLimit,'UniformOutput',0);
            
            % Cell array activation levels at RT (needed for the decay function)
            activationAtRt = cellfun(@(u,v,w,x,y,z) myfun(u,v,w,x,y,z),t0Cell,timeToActLimit,rtCell,activationLimitCell,rateCell,t0Cell,'UniformOutput',0);

            % Cell array post-response activation levels
            activationDecay = cellfun(@(x,y,z) x*exp(-(1:numel(y))*z), ...
                                        activationAtRt,...
                                        tDecay, ...
                                        lambdaCell, ...
                                        'UniformOutput',0);

            % Cell array of whole-trial activation levels, obtained by concatenating
            % arrays
            activation = cellfun(@(w,x,y,z) horzcat(w,x,y,z),activationBaseline, ...
                                                           activationPreLimit, ...
                                                           activationPostLimit, ...
                                                           activationDecay,'UniformOutput',0);
      end
      
      
      
      
      
      
      
      
end
elapsedTime(8) = toc(t8);

%% 4. OUTPUT
% elapsedTime = toc(tStartFunction);

switch lower(simDataType)
   case 'rt'
      varargout{1} = rt;
      varargout{2} = rate;
      varargout{3} = elapsedTime;
   case 'activation'
      varargout{1} = rt;
      varargout{2} = activation;
      varargout{3} = rate(:,selectedAccums);
      varargout{4} = selectedAccums;
      varargout{5} = elapsedTime;
end

%% 5. NESTED FUNCTIONS
   function a = myfun(u,v,w,x,y,z)
      if u + v < w
         a = x;
      elseif u + v >= w
         a = y*(w-z);
      end
   end
end