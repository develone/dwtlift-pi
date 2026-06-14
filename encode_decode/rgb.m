clear
fid = fopen('red','r'); im1 = fread(fid, [2048,inf], 'int8'); fclose(fid);
fid = fopen('green','r'); im2 = fread(fid, [2048,inf], 'int8'); fclose(fid);
fid = fopen('blue','r'); im3 = fread(fid, [2048,inf], 'int8'); fclose(fid);

figure;
imagesc(im1);
colorbar
colormap 'gray'
title "Decoder red 06/14/26"

figure;
imagesc(im2);
colorbar;
colormap 'gray'
title "Decoder green 06/14/26"

figure;
imagesc(im3);
colorbar;
colormap 'gray'
title "Decoder blue 06/14/26"
