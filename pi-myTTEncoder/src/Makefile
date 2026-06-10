obj_files = bio.o cio.o dwt.o event.o function_list.o image.o invert.o  j2k.o jp2.o mct.o mqc.o opj_clock.o opj_malloc.o openjpeg.o pi.o t1.o rd-wr-ops.o t2.o tcd.o  tgt.o thread.o  openjpeg.o sparse_array.o dwtlift.o

src_files = bio.c cio.c dwt.c event.c function_list.c image.c invert.c  j2k.c jp2.c mct.c mqc.c opj_clock.c opj_malloc.c openjpeg.c pi.c t1.c rd-wr-ops.c t2.c tcd.c  tgt.c thread.c  openjpeg.c sparse_array.c dwtlift.c

CC = gcc

CFLAGS = -c -g -I. -Wall

all: $(obj_files)



clean:
	rm -f *.o libopenjp2.a libopenjp2_obj.txt libopenjp2.a.dis

openjp2:
	ar rcs libopenjp2.a $(obj_files)
	ar t libopenjp2.a > libopenjp2_obj.txt
	objdump -d libopenjp2.a > libopenjp2.a.dis
