#!/bin/bash
rm -f *.o
rm -f libopenjp2.a

gcc   -c -g -g bio.c -o bio.o
gcc   -c -g cio.c -o cio.o
gcc   -c -g dwt.c -o dwt.o
gcc   -c -g event.c -o event.o
gcc   -c -g function_list.c -o function_list.o
gcc   -c -g image.c -o image.o
gcc   -c -g invert.c -o invert.o
gcc   -c -g j2k.c -o j2k.o
gcc   -c -g jp2.c -o jp2.o
gcc   -c -g mct.c -o mct.o
gcc   -c -g mqc.c -o mqc.o
gcc   -c -g opj_clock.c -o opj_clock.o
gcc   -c -g opj_malloc.c -o opj_malloc.o
gcc   -c -g pi.c -o pi.o
gcc   -c -g t1.c -o t1.o
gcc   -c -g rd-wr-ops.c -o rd-wr-ops.o
 
gcc   -c -g t2.c -o t2.o 
gcc   -c -g tcd.c -o tcd.o
gcc   -c -g tgt.c -o tgt.o
gcc   -c -g thread.c -o thread.o
gcc   -c -g openjpeg.c -o openjpeg.o

gcc   -c -g sparse_array.c -o sparse_array.o
ar rcs libopenjp2.a *.o
ar t libopenjp2.a > libopenjp2_obj.txt
echo "The word count here should be 22"
echo "the word count in /home/devel/jpeg-2000-test/bare-metal/openjp"
echo "when ./libbuild.sh is executed should be 22"
wc libopenjp2_obj.txt 
