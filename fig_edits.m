% For RT 100 - 10000
hCh = get(gcf,'Children');
set(hCh,'XTick',[],'YTick',[]);
set(hCh,'XTickLabel',[],'YTickLabel',[]);
delete(findobj(gcf,'Type','text'));
set(hCh,'XTick',[1,10,100,1000],'YTick',[10:10:90,100:100:900,1000:1000:10000]);
set(hCh,'YLim',[100,10000]);

% For RT 100 - 1000
hCh = get(gcf,'Children');
set(hCh,'XTick',[],'YTick',[]);
set(hCh,'XTickLabel',[],'YTickLabel',[]);
delete(findobj(gcf,'Type','text'));
set(hCh,'XTick',[1,10,100,1000],'YTick',[100:100:1000]);
set(hCh,'YLim',[100,1000]);

% For TAV 10 - 1000
hCh = get(gcf,'Children');
set(hCh,'Color',[1,1,1]);
set(hCh,'XTick',[],'YTick',[]);
set(hCh,'XTickLabel',[],'YTickLabel',[]);
delete(findobj(gcf,'Type','text'));
set(hCh,'XTick',[1,10,100,1000],'YTick',[10:10:90,100:100:1000]);
set(hCh,'YLim',[10,1000]);