#!/system/bin/sh

for UT_KO in `find /system/utmodules/ -name "*.ko"`
do
    insmod $UT_KO
done


if [ -e /etc/.sdcard_label_ok ]
then
        echo "skip sdcard label formatting!"
else
        echo "sdcard label formatting..."
        newfs_msdos -F 32 -O android -c 8 -L "HYUNDAI T7S" /dev/block/mmcblk0p1
        echo "ok" > /etc/.sdcard_label_ok
fi
