clear
fid = fopen('green','r'); im2 = fread(fid, [256,inf], 'int8'); fclose(fid);
 
 
figure;
imagesc(im2);
colorbar;
colormap 'gray'
title "myTTDecoder green 05/25/26"

 