#!/bin/bash

# J.Nider 2019-21-10

kernel_path=./build/nginx-app_kvm-x86_64
qemu_ifup_path=~joel/projects/unikraft/apps/qemu-ifup.sh
root_path="/home/joel/projects/unikraft/apps/nginx-app/rootfs"

qemu-system-x86_64 \
-enable-kvm \
-kernel $kernel_path -device virtio-net,netdev=net0 \
-netdev tap,id=net0,script=$qemu_ifup_path \
-fsdev local,id=myid,path=$root_path,security_model=none \
-device virtio-9p-pci,fsdev=myid,mount_tag=test,disable-modern=on,disable-legacy=off \
-append "vfs.rootfs=9pfs vfs.rootdev=test --" \
-serial file:output.txt
