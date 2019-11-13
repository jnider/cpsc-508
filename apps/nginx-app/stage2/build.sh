#!/bin/bash

imgname=nginx-app_kvm-x86_64
basedir=/home/joel/projects/unikraft/unikraft

rm -f $imgname.*

objs="lib9pfs.o libkvmpci.o libkvmplat.o libkvmvirtio9p.o libkvmvirtionet.o libkvmvirtio.o liblwip.o libnewlibc.o libnewlibglue.o libnewlibm.o libnginx.o libposix_libdl.o libposix_process.o libposix_user.o libpthread-embedded.o libramfs.o libsyscall_shim.o libuk9p.o libukallocbbuddy.o libukalloc.o libukargparse.o libukblkdev.o libukboot_main.o libukboot.o libukbus.o libukdebug.o libuklibparam.o libuklock.o libukmmap.o libukmpi.o libuknetdev.o libukschedcoop.o libuksched.o libuksglist.o libukswrand.o libuktimeconv.o libuktime.o libvfscore.o nginxapp.o uksysinfo.o"


# copy all of the object files from the normal build directory
for f in $objs; do
	cp ${f/#/../build\/} .
done

# copy the linker scripts too
cp $(find ../build -name '*.lds') .

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
