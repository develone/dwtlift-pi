#!/bin/bash
rm -f *.o
rm -f libopenjp2.a

gcc   -c bio.c -o bio.o
gcc   -c cio.c -o cio.o
gcc   -c dwt.c -o dwt.o
gcc   -c event.c -o event.o
gcc   -c function_list.c -o function_list.o
gcc   -c image.c -o image.o
gcc   -c invert.c -o invert.o
gcc   -c j2k.c -o j2k.o
gcc   -c jp2.c -o jp2.o
gcc   -c mct.c -o mct.o
gcc   -c mqc.c -o mqc.o
gcc   -c opj_clock.c -o opj_clock.o
gcc   -c opj_malloc.c -o opj_malloc.o
gcc   -c pi.c -o pi.o
gcc   -c t1.c -o t1.o
gcc   -c rd-wr-ops.c -o rd-wr-ops.o
 
gcc   -c t2.c -o t2.o 
gcc   -c tcd.c -o tcd.o
gcc   -c tgt.c -o tgt.o
gcc   -c thread.c -o thread.o
gcc   -c openjpeg.c -o openjpeg.o

gcc   -c sparse_array.c -o sparse_array.o
ar rcs libopenjp2.a *.o
ar t libopenjp2.a > libopenjp2_obj.txt
echo "The word count here should be 22"
echo "the word count in /home/devel/jpeg-2000-test/bare-metal/openjp"
echo "when ./libbuild.sh is executed should be 22"
wc libopenjp2_obj.txt 
