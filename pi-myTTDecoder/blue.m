clear
 fid = fopen('blue','r'); im3 = fread(fid, [256,inf], 'int8'); fclose(fid);

 
figure;
imagesc(im3);
colorbar;
colormap 'gray'
title "myTTDecoder blue 05/25/26"