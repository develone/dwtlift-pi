obj_files = Encoder.o  Decoder.o 
src_files = Encoder.c  Decoder.c
CC = gcc

CFLAGS = -c -g -I.  

all: $(obj_files)



clean:
	rm -f *.o  Encoder Decoder

Encoder:
	$(CC) Encoder.o -L. -lopenjp2 -lm -o Encoder

Decoder:
	$(CC)  Decoder.o -L. -lopenjp2 -lm -o Decoder
