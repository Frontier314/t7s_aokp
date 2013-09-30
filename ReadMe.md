Initial work on AOKP port to Hyundai T7s (and the rest of the series)

These files produce a working but not bootable AOKP ROM for T7s.

Sync with the AOKP jb-mr1 repo and make sure you remove all files (move them to another folder) from

/hardware
/vendor (all folders except aokp)

Copy the /device folder into /device on the AOKP tree and use the supplied (fixed) files inside frameworks and packages.

Provided that AOKP prerequisites are installed on your system, cd to the root folder of AOKP source tree and invoke:

. build/envsetup.sh && lunch (select the aokp_t7s build you want) && mka

Use the original ramdisk from 20130318 ICS ROM.
