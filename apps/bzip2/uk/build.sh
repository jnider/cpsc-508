#!/bin/bash

imgname=bzip2_kvm-x86_64
basedir=../..
app=.

rm -f $imgname.*

#objs="libvfscore.o main.o libuktime.o libkvmplat.o libkvmpci.o libkvmvirtio.o libuksched.o libukdebug.o libnewlibglue.o libuklock.o libukalloc.o libposix_process.o libnewlibc.o libpthread-embedded.o libukallocbbuddy.o libukboot.o libnewlibm.o libposix_user.o libukschedcoop.o libukargparse.o libuklibparam.o libuktimeconv.o"

# copy the glue functions
cp $basedir/../bink/__stack_chk_fail.o .
cp $basedir/../bink/__printf_chk.o .

echo "Partially linking $imgname.ld.o"
gcc -r -nostdinc -nostdlib -Wl,--omagic -Wl,-r -Wl,-d \
-Wl,--build-id=none -no-pie  -Wl,-m,elf_x86_64  \
$app/libkvmplat.o \
$app/libkvmpci.o \
$app/libkvmvirtio.o \
$app/libkvmvirtionet.o \
$app/libkvmvirtio9p.o   \
$app/main.o \
$app/__stack_chk_fail.o \
$app/__printf_chk.o \
$app/libukboot.o \
$app/libukboot_main.o \
$app/libukswrand.o \
$app/libposix_user.o \
$app/libukdebug.o \
$app/libukargparse.o \
$app/libuktimeconv.o \
$app/libukalloc.o \
$app/libukallocbbuddy.o \
$app/libuksched.o \
$app/libukschedcoop.o \
$app/libvfscore.o \
$app/libramfs.o \
$app/lib9pfs.o \
$app/libuklock.o \
$app/libukmpi.o \
$app/libukbus.o \
$app/libuksglist.o \
$app/libuknetdev.o \
$app/libuk9p.o \
$app/libposix_libdl.o \
$app/libuklibparam.o \
$app/libuktime.o \
$app/libukblkdev.o \
$app/libposix_process.o \
$app/libpthread-embedded.o \
$app/libnewlibc.o \
$app/libnewlibm.o \
$app/libnewlibglue.o \
$app/liblwip.o \
$app/libbzip2.o \
-Wl,--start-group     -Wl,--end-group -o $app/$imgname.ld.o

#$app/libsyscall_shim.o \
#$app/uksysinfo.o \
#$app/libukmmap.o \

echo "Creating $imgname.o"
objcopy -w -G kvmos_* -G _libkvmplat_entry $imgname.ld.o $imgname.o

echo "Linking dbg"
gcc  -nostdinc -nostdlib -Wl,--omagic -Wl,--build-id=none  -no-pie  \
-Wl,-m,elf_x86_64 -Wl,-dT,kvmplat-link64.lds \
-Wl,-T,debug-extra.ld \
-Wl,-T,libparam.lds \
-Wl,-T,vfscore-extra.ld \
$imgname.o -o $imgname.dbg

#gcc  -nostdinc -nostdlib -Wl,--omagic -Wl,--build-id=none  -no-pie  \
#-Wl,-m,elf_x86_64 -Wl,-dT,/home/joel/projects/unikraft/apps/nginx-app/build/libkvmplat/link64.lds \
#-Wl,-T,/home/joel/projects/unikraft/unikraft/lib/ukdebug/extra.ld \
#-Wl,-T,/home/joel/projects/unikraft/apps/nginx-app/build/libvfscore/libparam.lds \
#-Wl,-T,/home/joel/projects/unikraft/unikraft/lib/vfscore/extra.ld \
#/home/joel/projects/unikraft/apps/nginx-app/build/nginx-app_kvm-x86_64.o \
#-o /home/joel/projects/unikraft/apps/nginx-app/build/nginx-app_kvm-x86_64.dbg

echo "strip"
$basedir/../unikraft/support/scripts/sect-strip.py --with-objcopy=objcopy $imgname.dbg -o $imgname && strip -s $imgname
