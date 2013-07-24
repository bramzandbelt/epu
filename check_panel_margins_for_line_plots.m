figure;
p = panel('defer');
p.pack(4,4);
p.de.margin = 0;
for i = 1:4
   for j = 1:4
      p(R(i),C(j)).select();
      scatter(randn(50,1)*100+200,randn(50,1)*100+200);
         if R(i) == 4 && C(j) == 1
            set(gca,'XLim',[1 1e3],'XTick',[1e0 1e1 1e2 1e3],'XScale','log','YLim',[1 1e3],'YTick',[1e0 1e1 1e2 1e3],'YScale','log','Box','on');
         elseif R(i) == 4
            set(gca,'XLim',[1 1e3],'XTick',[1e0 1e1 1e2 1e3],'XScale','log','YLim',[1 1e3],'YTick',[1e0 1e1 1e2 1e3],'YTickLabel',[],'YScale','log','Box','on');
         elseif C(j) == 1
            set(gca,'XLim',[1 1e3],'XTick',[1e0 1e1 1e2 1e3],'XTickLabel',[],'XScale','log','YLim',[1 1e3],'YTick',[1e0 1e1 1e2 1e3],'YScale','log','Box','on');
         else
            set(gca,'XLim',[1 1e3],'XTick',[1e0 1e1 1e2 1e3],'XTickLabel',[],'XScale','log','YLim',[1 1e3],'YTick',[1e0 1e1 1e2 1e3],'YTickLabel',[],'YScale','log','Box','on');
         end
   end
end
p.refresh();