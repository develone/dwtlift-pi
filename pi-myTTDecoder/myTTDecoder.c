#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

repo	https://github.com/develone/dwtlift-pi.git

cd dwtlift-pi/pi-myTTDecoder/src/ or cd dwtlift-pi/pi-myTTEncoder/src/

make clean

make all

make openjp2

if dwtlift-pi/pi-myTTDecoder/src/ cp libopenjp2.a ../ and cp libopenjp2.a ../../pi-myTTEncoder/

if dwtlift-pi/pi-myTTEncoder/src/ cp libopenjp2.a ../ and cp libopenjp2.a ../../pi-myTTDecoder/

devel@pi4-50:~/dwtlift-pi/pi-myTTDecoder $ gcc -Wall -g myTTEncoder.c -L. -lopenjp2 -lm -o myTTEncoder 

devel@pi4-50:~/dwtlift-pi/pi-myTTEncoder $ gcc -g myTTEncoder.c -L. -ldwtlift -lm -o myTTEncoder

*/

int dec, enc, TCP_DISTORATIO, FILTER, CR, flg, bp;
int da_x0, da_y0, da_x1, da_y1, ENCODE;
char *ff;

long imgsz,him,wim, *bufferptr;
int COMPRESSION_RATIO;
void decom_test(int da_x0, int da_y0, int da_x1, int da_y1, char *ff_in);

int main(int argc, char *argv[]) {

/*TCP_DISTORATIO=60;

COMPRESSION_RATIO=1;
CR = 25; 
ENCODE = 1;
argv[1];
argv[2];
 



printf("TCP_DISTORATIO = %d \n", TCP_DISTORATIO);
printf("CR = %d COMPRESSION_RATIO = %d ENCODE = %d\n",CR,COMPRESSION_RATIO,ENCODE);
printf("input %s output %s\n",argv[1],argv[2]);
 //FILTER 0 5/3 DWT
 //FILTER 1 9/7 DWT
dec = 0;
enc = 1;
//printf("calling lift_config\n");
printf("back from decom_test\n");


printf("dec = %d enc = %d TCP_DISTORATIO = %d FILTER = %d \n",dec, enc, TCP_DISTORATIO, FILTER);
printf("CR = %d flg = %d bp = %d imgsz  = %d \n",CR, flg, bp, imgsz);
//lift_config(dec, enc, TCP_DISTORATIO, FILTER, CR, flg, bp, imgsz, him, wim,  *bufferptr);
//printf("back from lift_config\n");


*/
da_x0 = 0;
da_y0 = 0;
da_x1 = 256;
da_y1= 256;
char ff[20];
  if(argc > 0) {
    da_x1 = atoi(argv[1]);
    da_y1 = atoi(argv[2]);
    printf("da_x1 %d da_y1 %d \n",da_x1,da_y1);
    
    printf("fname %s \n",argv[3]);
    printf("address of argv[3] 0x%x \n", &argv[3]);
    strncpy(ff, argv[3], sizeof(ff) - 1);
    //return 0;
  }  
printf("da_x0 = %d da_y0 = %d da_x1 = %d da_y1 = %d\n",da_x0, da_y0, da_x1, da_y1);

printf("*ff = 0x%x ff_in= %s\n",*ff,ff);

printf("calling decom_test\n");
//decom_test(int da_x0, int da_y0, int da_x1, int da_y1, char *argv[3]);
decom_test(da_x0,da_y0,da_x1,da_y1,ff);
return 0;
}
