#include <stdio.h>
#include <stdlib.h>
#include "format_defs.h"
#include "openjpeg.h"
#include "opj_config.h"

/*

repo	https://github.com/develone/dwtlift-pi.git

devel@pi4-50:~/dwtlift-pi/src $ ./compile_pi.sh

devel@pi4-50:~/dwtlift-pi/pi-xx $ ./libbuild.sh

devel@pi5-90:~/dwtlift-pi/pi-myTTDecoder $ 
gcc -Wall -Werror -g myTTEncoder.c -L. -ldwtlift -lm -o myTTEncoder 
gcc -g myTTEncoder.c -L. -ldwtlift -lm -o myTTEncoder

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
//void lift_config(int dec, int enc, int TCP_DISTORATIO, int FILTER, int CR, int flg, int bp, long imgsz,long him,long wim, char bufferptr);



DrawBitmap(Window,'C:\MyBitmap.bmp',0,0,DECOMP,ENCODE,TCP_DISTORATIO,FILTER, COMPRESSION_RATIO,DIS_CR_FLG);
devel@pi4-50:~/dwtlift-pi/pi-xx $ gcc -g  call-dwtlift.c -L. -ldwtlift -o call-dwtlift
devel@pi4-50:~/dwtlift-pi/pi-xx $ ./call-dwtlift "lena_rgb_256.bmp" "test.j2k"
input lena_rgb_256.bmp output test.j2k
devel@pi4-50:~/dwtlift-pi/pi-xx $ ./call-dwtlift "lena_rgb_64.bmp" "test.j2k"
input lena_rgb_64.bmp output test.j2k
*/

struct CompressImage {
int dec; 
int enc; 
int TCP_DISTORATIO;
int FILTER;  
int CR; 
int flg;
int bpp;
int imgsz;
int him;
int wim;
char *bufferptr;
};

//setting intial values in struct CompressImage
struct CompressImage s1 = {6,1,60,0,25,1,24,196608,256,256,0};
int dec, enc, TCP_DISTORATIO, FILTER, CR, flg, bpp;
//int da_x0, da_y0, da_x1, da_y1;
//char *ff;
char ff[]="test.j2k";
long imgsz,him,wim;
int TCP_DISTORATIO=60; 
int COMPRESSION_RATIO=1,CR = 25,ENCODE = 1;

typedef struct
    {
        unsigned char RGB[3];
    }RGB; 

//void lift_config(void lift_config(int dec, int enc, int TCP_DISTORATIO, int FILTER,  int CR, int flg, int bpp, long imgsz,long him,long wim, char bufferptr);
void lift_config(struct CompressImage *s);
RGB** createMatrix();

int main(int argc, char *argv[]) {
#pragma pack(push,1)
/* Windows 3.x bitmap file header */
typedef struct {
    char         filetype[2];   /* magic - always 'B' 'M' */
    unsigned int filesize;
    short        reserved1;
    short        reserved2;
    unsigned int dataoffset;    /* offset in bytes to actual bitmap data */
} file_header;

typedef struct {
    file_header  fileheader;
    unsigned int headersize;
    int          width;
    int          height;
    short        planes;
    short        bitsperpixel;  /* we only support the value 24 here */
    unsigned int compression;   /* we do not support compression */
    unsigned int bitmapsize;
    int          horizontalres;
    int          verticalres;
    unsigned int numcolors;
    unsigned int importantcolors;
} bitmap_header;
#pragma pack(pop)

	char  *bufferptr;
	//printf("bufferptr 0x%x *bufferptr 0x%x \n",bufferptr,*bufferptr);
        int n,loop;
	char fname[] = "lena_rgb_256.bmp";
	//*bufferptr = buffer;
	//printf("0x%x *bufferptr\n",bufferptr);
	//printf("fname = %s  \n",fname);

 
        
         
        bitmap_header* hp;
        
        FILE *in;
        
        //open the input file
        in = fopen(fname, "rb");
        if(in == NULL){
           //cleanup
           printf("Unable to open file for reading!");
        }
        else printf("opening fname = %s  in 0x%x \n", fname, in);
        
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
        bufferptr = (char*)malloc(s1.imgsz);
        s1.bufferptr = bufferptr;
	printf("s1.bufferptr 0x%x    \n",s1.bufferptr);

    	fseek(in,sizeof(char)*hp->fileheader.dataoffset,SEEK_SET);
    	n=fread(bufferptr,sizeof(char),hp->bitmapsize, in);
    	printf("number of data points %d \n",n);
	for(loop=0;loop<8;loop++) {
    		printf("loop %d data %x data %d \n",loop,*bufferptr, *bufferptr);
                printf("bufferptr 0x%x *bufferptr 0x%x \n",bufferptr, *bufferptr);
		bufferptr++;
    	}
    	//printf("before loop data %s \n",data);
        bufferptr = bufferptr - loop;
        printf("bufferptr 0x%x *bufferptr 0x%x \n",bufferptr, *bufferptr);
        
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
	//lift_config(dec, enc, TCP_DISTORATIO, FILTER, CR, flg, bpp, imgsz, him, wim,   bufferptr);
	printf("back from lift_config\n");
        free(in);
        free(hp);
        free(bufferptr);


 
 

return 0;
}
