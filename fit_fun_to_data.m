function [fittedParams,SSE,fisherZr,fitSuccess] = fit_fun_to_data(funName,params,t,t0,varargin);
% Routine of the epu_sim_master function
      
if nargin == 5
   yObs = varargin{1};
end

switch funName
   case 'linear'
      stats = regstats(yObs,t);               
      fittedParams = stats.beta';
      SSE = stats.mse .* (length(t)-1-1); % SSE = MSE * df = MSE * (n-K-1), where n = number of observations and K is number of predictors = 1 in linear regression
      fisherZr = atanh(stats.rsquare);
      fitSuccess = stats.tstat.pval < .05;
%             if all(stats.tstat.pval < .05)
%                fitSuccess = 1;
%             else
%                fitSuccess = 0;
%             end
%       fitSuccess = 'NaN';
   case {'power','ratio'}
      switch funName
         case 'power'
            fun = @(params) params(2).*t.^params(1);
         case 'ratio'
            fun = @(params) params(2)./(t-t0).^params(1);
      end
      options = optimset('fminsearch');
      options.Display = 'off';
      [fittedParams,SSE,fitSuccess] = fminsearch(@(params) compute_sse(params,fun,t,yObs),params,options);
      fisherZr = atanh(corr(yObs,fun(fittedParams),'type','Pearson','tail','both')); % Fisher Z transformed r
   case 'exgaussian'
      options = optimset('fminsearch');
      options.Display = 'off';
      [fittedParams,SSE,fitSuccess] = fminsearchbnd(@(params) discrepancy_exgaussian_cdf(t,params),params,[0 0 0],[5000 5000 5000]);
      FCdfPred = mtb_exgaussian_cdf(t,fittedParams);
      fisherZr = atanh(corr(mtb_edf(t,t),FCdfPred,'type','Pearson','tail','both')); % Fisher Z transformed r
end
   