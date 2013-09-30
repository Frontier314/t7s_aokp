#!/system/bin/sh
export PATH="/system/busybox/bin:/system/busybox/sbin:/system/busybox/usr/bin:/system/busybox/usr/sbin:/sbin:/vendor/bin:/system/sbin:/system/bin:/system/xbin"

while true
do

PLUG=true

while $PLUG
do
[ -c "/dev/sg0" ] && PLUG=false
sleep 1
done

for ID in `awk -F'[ =]' '$3~/'Vendor'/ {print $4"_"$6}' /proc/bus/usb/devices`
do
    echo "$ID"
    if [ -f "/system/etc/ppp/sw/$ID" ];then
        eject -s /dev/sg0
        usb_modeswitch -c /system/etc/ppp/sw/$ID
    fi
done

while [ -c "/dev/sg0" ]
do
sleep 1
done

done
