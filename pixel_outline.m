% function [f v] = pixel_outline(mat,msk,matSize,axSize)
function [x2 y2] = pixel_outline(mat,msk,matSize,axSize)
%
%% Syntax
% outline = pixel_outline(matrix,mask);
%
%
%

C = 100;
OFFSET = 0.5;

% Scale matrix and mask by C
% sMat = imresize(flipud(mat),C,'nearest');
% sMsk = imresize(flipud(msk),C,'nearest');

sMat = imresize(mat,C,'nearest');
sMsk = imresize(msk,C,'nearest');


% Compute (scaled) oulines
sOutline = bwboundaries(sMsk);

% Rescale boundaries to original dimensions
% outline = cellfun(@(x,y) x./y + OFFSET,sOutline,num2cell(kron(ones(size(sOutline)),C)),'UniformOutput',0);
outline = cellfun(@(x,y) x./y,sOutline,num2cell(repmat(C,size(sOutline))),'UniformOutput',0);

scaleFactor = matSize./fliplr(axSize);
shiftFactor = 0.5*1./scaleFactor;
% shiftFactor = axSize./matSize;

% outline = cellfun(@(x) x./10-.1,outline,'UniformOutput',0);

% scaleFactor = mat2cell(repmat(scaleFactor,size(outline)),ones(size(outline,1),1),2);
% shiftFactor = mat2cell(repmat(shiftFactor,size(outline)),ones(size(outline,1),1),2);

% X data in outline{#}(:,2) needs to be scaled and shifted

X = cell(1,numel(outline));
Y = cell(1,numel(outline));

for iCell = 1:numel(outline)
   for iDim = 1:2
      scaleMat = repmat(scaleFactor(iDim),length(outline{iCell}(:,iDim)),1);
      shiftMat = repmat(shiftFactor(iDim),length(outline{iCell}(:,iDim)),1);
      if iDim == 1 % Y data in outline{#}(:,1) needs to be scaled, shifted, and flipped
         Y{iCell} = -(outline{iCell}(:,iDim)./scaleMat-0.5*axSize(iDim)) + 0.5*axSize(iDim) - shiftMat;
      elseif iDim == 2
         X{iCell} = outline{iCell}(:,iDim)./scaleMat-shiftMat;
      end
   end
end

% X = cell(1,numel(outline));
% Y = cell(1,numel(outline));
% 
% for iCell = 1:numel(outline)
%    outline{iCell} = outline{iCell}./repmat(scaleFactor,size(outline{iCell},1),1) - ...
%                     repmat(shiftFactor,size(outline{iCell},1),1);
%    X{iCell} = outline{iCell}(:,1);
%    Y{iCell} = outline{iCell}(:,2);
% end

% Compute face and vertex matrices
% [f v] = poly2fv(X,Y);
[x2 y2] = poly2cw(X,Y);


