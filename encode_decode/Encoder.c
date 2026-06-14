#include <stdio.h>
#include <stdlib.h>
#include "format_defs.h"
#include "openjpeg.h"
#include "opj_config.h"
#include "encode_decode.h"

/*

repo	https://github.com/develone/dwtlift-pi.git

cd dwtlift-pi/pi-myTTDecoder/src/ or cd dwtlift-pi/pi-myTTEncoder/src/

make clean

make all

make openjp2

if dwtlift-pi/pi-myTTDecoder/src/ cp libopenjp2.a ../ and cp libopenjp2.a ../../pi-myTTEncoder/

if dwtlift-pi/pi-myTTEncoder/src/ cp libopenjp2.a ../ and cp libopenjp2.a ../../pi-myTTDecoder/

devel@pi4-50:~/dwtlift-pi/pi-myTTDecoder $ gcc -Wall -g myTTDecoder.c -L. -lopenjp2 -lm -o myTTDecoder 

devel@pi4-50:~/dwtlift-pi/pi-myTTEncoder $ gcc -g myTTEncoder.c -L. -lopenjp2 -lm -o myTTEncoder

*/

 

 
int dec, enc, TCP_DISTORATIO, FILTER, CR, flg, bpp;

 
long imgsz,him,wim;
  
//int COMPRESSION_RATIO=1,CR = 25,ENCODE = 1;

  

 
void lift_config(struct CompressImage *s);
 

int main(int argc, char *argv[]) {

 
        int n,loop;

 
        
         
        bitmap_header* hp;
        
        FILE *in;
        
        //open the input file
        in = fopen(argv[1], "rb");
        if(in == NULL){
           //cleanup
           printf("Unable to open file for reading!");
        }
        else printf("opening fname = %s  in 0x%x \n", argv[1], in);
        
        //malloc for INFOHEADER
         
        hp=(bitmap_header*)malloc(sizeof(sizeof(bitmap_header)));
        
 
        printf("hp 0x%x *hp 0x%x \n",hp,*hp);
 
        n=fread(hp, sizeof(bitmap_header), 1, in);
        printf("number of header points %d \n",n);
        printf("n %d \n",n);

 


 	//FILTER 0 5/3 DWT
 	//FILTER 1 9/7 DWT

        s1.wim = hp->width;
	s1.him = hp->height;
        printf("s1.wim %d s1.him %d \n",s1.wim, s1.him);

        s1.bpp = hp->bitsperpixel;
        printf("s1.bpp %d \n", s1.bpp);

        s1.imgsz = hp->bitmapsize;
        printf("s1.imgsz %d \n",s1.imgsz);

        printf("Allocating memory for data\n");
        s1.bufferptr = (char*)malloc(s1.imgsz);
         
	printf("s1.bufferptr 0x%x    \n",s1.bufferptr);

    	fseek(in,sizeof(char)*hp->fileheader.dataoffset,SEEK_SET);
    	n=fread(s1.bufferptr,sizeof(char),hp->bitmapsize, in);
    	printf("number of data points %d \n",n);
	for(loop=0;loop<8;loop++) {
    		printf("loop %d data %x data %d \n",loop,*s1.bufferptr, *s1.bufferptr);
                printf("s1.bufferptr 0x%x *s1.bufferptr 0x%x \n",s1.bufferptr, *s1.bufferptr);
		s1.bufferptr++;
    	}
    	 
        s1.bufferptr = s1.bufferptr - loop;
        printf("s1,bufferptr 0x%x *s1.bufferptr 0x%x \n",s1.bufferptr, *s1.bufferptr);
        
        printf("s1 0x%x \n",&s1);
        printf("s1.dec %d \n",s1.dec);
        printf("s1.enc %d \n",s1.enc);
        printf("s1.TCP_DISTORATIO %d \n",s1.TCP_DISTORATIO);
        printf("s1.CR %d \n",s1.CR);
        printf("s1.flg %d \n",s1.flg); 
        printf("s1.bpp %d \n",s1.bpp);
        printf("s1.imgsz %d \n",s1.imgsz);
        printf("s1.him %d \n",s1.him);
        printf("s1.wim %d \n",s1.wim);
        printf("s1.*bufferptr  0x%x \n",s1.bufferptr);
	//updatecompressimage(&s1);

        printf("calling lift_config\n"); 
        lift_config(&s1);
 
	printf("back from lift_config\n");
        free(in);
        free(hp);
        free(s1.bufferptr);


 
 

return 0;
}
