clear
fid = fopen('red','r'); im1 = fread(fid, [256,inf], 'int8'); fclose(fid);
fid = fopen('green','r'); im2 = fread(fid, [256,inf], 'int8'); fclose(fid);
fid = fopen('blue','r'); im3 = fread(fid, [256,inf], 'int8'); fclose(fid);

figure;
imagesc(im1);
colorbar
colormap 'gray'
title "myTTDecoder red 05/25/26"

figure;
imagesc(im2);
colorbar;
colormap 'gray'
title "myTTDecoder green 05/25/26"

figure;
imagesc(im3);
colorbar;
colormap 'gray'
title "myTTDecoder blue 05/25/26"