y0 = 0;
A = 1;
x = 0:10000;
w = 20;
t0 = 100;
xc = 240;




% xcVec = logspace(log10(240),log10(240),10);
xcVec = logspace(log10(160),log10(320),10);
xcVec = [xcVec(1),xcVec(4:end)]; % Get rid of data for N = 2 and N = 5

% t0Vec = logspace(log10(11),log10(200),10);
% t0Vec = [t0Vec(1),t0Vec(4:end)]; % Get rid of data for N = 2 and N = 5

% wVec = logspace(log10(120),log10(1),10);
wVec = linspace(120,1,10);
wVec = [wVec(1),wVec(4:end)]; % Get rid of data for N = 2 and N = 5

nAs = [1 10 20 50 100 200 500 1000];


figure;
p = panel;
p.pack('v',8);

for iP = 1:8
   
   % Compute density function
   xc = xcVec(iP);
%    t0 = t0Vec(iP);
   w = wVec(iP);
   f = mtb_exgaussian_pdf_alternative(x,y0,A,xc,w,t0);
   
   % Compute distirbution function
   F = cumsum(f);
   
   % Find median and first quartile
   Q50 = find(F >= .5,1,'first') - 1;
   Q25 = find(F >= .25,1,'first') - 1;
   
   % Compute IQR
   IQR = find(F >= .75,1,'first') - find(F >= .25,1,'first');
   
   % Select panel
   p(iP).select();
   p(iP).margin = [0 2 0 2];
   
   % Plot data
   plot(x,f); hold on;
   line([Q25,Q25+IQR],[0 0]);
   hM = plot(Q50,0,'k.');
   set(hM,'MarkerSize',10);
   
   % Set axis data
   set(gca,'Color','none', ...
            'XLim',[100 10000],...
            'XTick',[],...
            'XScale','log',...
            'YLim',[0 .01],...
            'YTick',[]);
   
end
   