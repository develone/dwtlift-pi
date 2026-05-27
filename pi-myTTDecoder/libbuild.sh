#!/bin/bash 

rm -f dwtlift.o
rm -f libdwtlift.a
rm -f libopenjp2.a
#cp  libopenjp2_816f53.a libopenjp2.a 
cp  ../src/libopenjp2.a libopenjp2.a 

gcc -L. -llibopenjp2  -c dwtlift.c

ar rcs libopenjp2.a dwtlift.o 

cp libopenjp2.a libdwtlift.a
ar t libdwtlift.a > libdwtlift_obj.txt
echo "when ./libbuild.sh is executed should be 23"
objdump -d  libdwtlift.a > libdwtlift.dis
cat libdwtlift_obj.txt
wc libdwtlift_obj.txt
