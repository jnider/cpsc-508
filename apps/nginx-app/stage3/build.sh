#!/bin/bash

imgname=nginx-app_kvm-x86_64
basedir=/home/joel/projects/unikraft/unikraft

rm -f $imgname.*

# bring in the .o files from the linux build
cp $(find ../../nginx-linux/objs/ -name '*.o') .

# get the unikraft libraries
cp $(find ../build/ -name 'lib*.o') .
rm -rf *.ld.o  # get rid of the duplicates
rm -rf libnginx.o # get rid of the unikraft port of nginx

# add our own glue code
gcc -c glue.c -o glue.o

# build a list of all objects that should be used in the final image
objs=$(ls *.o)

echo "Linking $imgname.ld.o"
gcc -r -nostdinc -nostdlib -Wl,--omagic -Wl,-r -Wl,-d -Wl,--build-id=none -no-pie  -Wl,-m,elf_x86_64  \
 $objs -Wl,--start-group     -Wl,--end-group -o $imgname.ld.o

echo "Creating $imgname.o"
objcopy -w -G kvmos_* -G _libkvmplat_entry $imgname.ld.o $imgname.o

echo "Creating dbg"
#gcc  -nostdinc -nostdlib -Wl,--omagic -Wl,--build-id=none  -no-pie  \
#-Wl,-m,elf_x86_64 -Wl,-dT,link64.lds -Wl,-T,$basedir/lib/ukdebug/extra.ld \
#-Wl,-T,$basedir/lib/vfscore/extra.ld $imgname.o -o $imgname.dbg

gcc  -nostdinc -nostdlib -Wl,--omagic -Wl,--build-id=none  -no-pie  \
-Wl,-m,elf_x86_64 -Wl,-dT,link64.lds -Wl,-T,$basedir/lib/ukdebug/extra.ld \
-Wl,-T,libparam.lds -Wl,-T,$basedir/lib/vfscore/extra.ld $imgname.o -o $imgname.dbg

echo "strip"
$basedir/support/scripts/sect-strip.py --with-objcopy=objcopy $imgname.dbg -o $imgname && strip -s $imgname
