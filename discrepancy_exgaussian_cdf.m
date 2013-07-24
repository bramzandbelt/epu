function discrepancy = discrepancy_exgaussian_cdf(y,params)
% y = observed RT vector
% params = parameters for exGaussian distribution

t = quantile(y,[.1 .3 .5 .7 .9]);
eObs = mtb_compute_estimator(y,t,'cdf')';
ePred = mtb_exgaussian_cdf(t,params);
discrepancy = mtb_sse(eObs,ePred);
