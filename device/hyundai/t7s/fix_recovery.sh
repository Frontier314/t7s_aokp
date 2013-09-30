#!/bin/bash

echo "Fixing recovery.fstab"
cp recovery/fixed_recovery.fstab ${OUT}/recovery/root/etc/recovery.fstab
echo "Creating final recovery"
cd ${OUT}
rm ramdisk-recovery.img ramdisk-recovery.cpio
cd ${OUT}/recovery/root
find . | cpio --create --format='newc' | gzip > ../../ramdisk-recovery.img
cd ${OUT}
echo "Creating final recovery (uboot)"
mkimage -A arm -O linux -T ramdisk -C none -a 0x30800000 -n "hyundai" -d ramdisk-recovery.img ramdisk-recovery-uboot.img
echo "All done. Copy ramdisk-recovery-uboot.img to SD and reboot"
