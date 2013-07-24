function ciSign = ci_sign(ciMatrix)
% ciMatrix should be a 2-x-N matrix containing confidence intervals for N
% parameters. Returns sign, a 1-x-N vector indicating whether confidence
% interval is entirely positive (1), negative (-1), or contains zero (0).

% Make sure that size matrix is 2 x N
if size(ciMatrix,1) ~= 2
   ciMatrix = ciMatrix';
end

% Determine signs of all parameters
ciSign = zeros(1,size(ciMatrix,2));
ciSign = all(ciMatrix > 0) - all(ciMatrix < 0);

