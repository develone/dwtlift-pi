clear
fid = fopen('red','r'); im1 = fread(fid, [256,inf], 'int8'); fclose(fid);
 
figure;
imagesc(im1);
colorbar
colormap 'gray'
title "myTTDecoder red 05/25/26"

 