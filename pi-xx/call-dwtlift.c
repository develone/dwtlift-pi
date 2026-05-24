#include <stdio.h>
#include <stdlib.h>

/*
devel@pi4-50:~/dwtlift-pi/src $ ./compile_pi.sh
The word count here should be 22
the word count in /home/devel/jpeg-2000-test/bare-metal/openjp
when ./libbuild.sh is executed should be 22
 22  22 182 libopenjp2_obj.txt

devel@pi4-50:~/dwtlift-pi/pi $ ./libbuild.sh 
dwtlift.c: In function ‘decompress’:
dwtlift.c:658:17: warning: implicit declaration of function ‘octave_write_byte’ [-Wimplicit-function-declaration]
  658 |                 octave_write_byte(r_decompress_fn,r_decompress,da_x1*da_y1);
      |                 ^~~~~~~~~~~~~~~~~
dwtlift.c: In function ‘lift_config’:
dwtlift.c:822:23: warning: cast to pointer from integer of different size [-Wint-to-pointer-cast]
  822 |         char *lclip = (char *)*bufferptr;
      |                       ^
dwtlift.c:1023:17: warning: cast to pointer from integer of different size [-Wint-to-pointer-cast]
 1023 |         lclip = (char *)*bufferptr;
      |                 ^
when ./libbuild.sh is executed should be 23
 23  23 192 libdwtlift_obj.txt

DWT_LIFT_RPi2 reads
Filename:='C:\testfile';
devel@pi4-50:~/dwtlift-pi/pi-xx $ od -x ~/Ultibo_Projects/jpeg2000/RPi2/64com 
0000000 0019 0000 0001 0000 0000 0000 0000 0000
0000020 0004 0000 0004 0000
CR 25 ENCODE 64 64
devel@pi4-50:~/dwtlift-pi/pi-xx $ od -x ~/Ultibo_Projects/jpeg2000/RPi2/64decom 
0000000 0019 0000 0000 0000 0000 0000 0000 0000
0000020 0004 0000 0004 0000
CR 25 DECODE 64 64
64com or 64decom -> testfile
decom_test(da_x0,da_y0,da_x1,da_y1,ff);
DrawBitmap(Window,'C:\MyBitmap.bmp',0,0,DECOMP,ENCODE,TCP_DISTORATIO,FILTER, COMPRESSION_RATIO,DIS_CR_FLG);
devel@pi4-50:~/dwtlift-pi/pi-xx $ gcc -g  call-dwtlift.c -L. -ldwtlift -o call-dwtlift
devel@pi4-50:~/dwtlift-pi/pi-xx $ ./call-dwtlift "lena_rgb_256.bmp" "test.j2k"
input lena_rgb_256.bmp output test.j2k
devel@pi4-50:~/dwtlift-pi/pi-xx $ ./call-dwtlift "lena_rgb_64.bmp" "test.j2k"
input lena_rgb_64.bmp output test.j2k
*/

int dec, enc, TCP_DISTORATIO, FILTER, CR, flg, bp;
int da_x0, da_y0, da_x1, da_y1, ENCODE;
//char *ff;
char ff[]="test.j2k";
long imgsz,him,wim, *bufferptr;
int COMPRESSION_RATIO;
void decom_test(int da_x0, int da_y0, int da_x1, int da_y1, char *ff_in);

int main(int argc, char *argv[]) {

TCP_DISTORATIO=60;

COMPRESSION_RATIO=1;
CR = 25; 
ENCODE = 1; 
da_x0 = 0;
da_y0 = 0;
da_x1 = 256;
da_y1= 256;
argv[1];
argv[2];

printf("TCP_DISTORATIO = %d \n", TCP_DISTORATIO);
printf("CR = %d COMPRESSION_RATIO = %d ENCODE = %d\n",CR,COMPRESSION_RATIO,ENCODE);
printf("da_x0 = %d da_y0 = %d da_x1 = %d da_y1 = %d\n",da_x0, da_y0, da_x1, da_y1);
printf("input %s output %s\n",argv[1],argv[2]);
printf("*ff = 0x%x ff_in= %s\n",*ff,ff);
printf("calling decom_test\n");
//decom_test(int da_x0, int da_y0, int da_x1, int da_y1, char *ff);
decom_test(da_x0,da_y0,da_x1,da_y1,ff);
printf("back from decom_test\n");
return 0;
}