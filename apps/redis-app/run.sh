#!/bin/bash

# J.Nider 2020-01-20

kernel_path=./build/redis_kvm-x86_64
qemu_ifup_path=../../qemu-ifup
root_path="rootfs"

# create the rootfs if it doesn't yet exist
if [ ! -d $root_path ]; then
	mkdir -p $root_path
fi

qemu-system-x86_64 \
-enable-kvm \
-kernel $kernel_path -device virtio-net,netdev=net0 \
-netdev tap,id=net0,script=$qemu_ifup_path \
-fsdev local,id=myid,path=$root_path,security_model=none \
-device virtio-9p-pci,fsdev=myid,mount_tag=test,disable-modern=on,disable-legacy=off \
-append "vfs.rootfs=9pfs vfs.rootdev=test --" \
-serial file:output.txt
