# BoardConfig.mk - SMDK4x12 board configuration
#
# Product-specific compile-time definitions.
#

# 2013-09-05:	mpappas		Initial version

HAVE_SELINUX := false

# init debugging options
INIT_BOOTCHART := false
TARGET_NO_INITLOGO := true

# init boot animation
TARGET_BOOTANIMATION_PRELOAD := true

# CPU options
TARGET_CPU_ABI := armeabi-v7a
TARGET_CPU_ABI2 := armeabi
TARGET_CPU_SMP := true
TARGET_ARCH := arm
TARGET_ARCH_VARIANT := armv7-a-neon
TARGET_ARCH_VARIANT_CPU := cortex-a9
TARGET_CPU_VARIANT := cortex-a9
ARCH_ARM_HAVE_TLS_REGISTER := true
ARCH_ARM_HAVE_NEON := true
ARCH_ARM_HAVE_TLS_REGISTER := true
TARGET_GLOBAL_CFLAGS += -mtune=cortex-a9 -mfpu=neon -mfloat-abi=softfp
TARGET_GLOBAL_CPPFLAGS += -mtune=cortex-a9 -mfpu=neon -mfloat-abi=softfp

# Board Platform options
TARGET_BOARD_PLATFORM := exynos4
TARGET_SOC := exynos4x12

EXYNOS4X12_ENHANCEMENTS := true
EXYNOS4_ENHANCEMENTS := true

ifdef EXYNOS4X12_ENHANCEMENTS
COMMON_GLOBAL_CFLAGS += -DEXYNOS4_ENHANCEMENTS
COMMON_GLOBAL_CFLAGS += -DEXYNOS4X12_ENHANCEMENTS
COMMON_GLOBAL_CFLAGS += -DDISABLE_HW_ID_MATCH_CHECK
#COMMON_GLOBAL_CFLAGS += -DSAMSUNG_SYSLSI_SEC_COMMON_H
endif

# Bootloader options
TARGET_NO_BOOTLOADER := true
TARGET_NO_RADIOIMAGE := true
TARGET_BOOTLOADER_BOARD_NAME := smdk4x12
TARGET_BOARD_NAME := smdk4x12

# Machine options
#TARGET_NO_KERNEL := true
TARGET_PROVIDES_INIT_RC := true
TARGET_PROVIDES_INIT_TARGET_RC := true

# Kernel options
BOARD_KERNEL_CMDLINE := console=ttySAC2,115200
BOARD_KERNEL_BASE := 0x40000000
BOARD_KERNEL_PAGESIZE := 2048

# Audio options
BOARD_USES_GENERIC_AUDIO := false
BOARD_USES_I2S_AUDIO := true
BOARD_USES_PCM_AUDIO := false
BOARD_USES_SPDIF_AUDIO := false
#USE_ULP_AUDIO := true
BOARD_USE_ALP_AUDIO := true

# SEC Camera
BOARD_USES_PROPRIETARY_LIBCAMERA := true
USE_SEC_CAMERA := true
CAMERA_USE_DIGITALZOOM := true
BOARD_USE_S5K3H7:= true

# Enable JIT
WITH_JIT := true

# Filesystem
BOARD_NAND_PAGE_SIZE := 4096
BOARD_NAND_SPARE_SIZE := 128
BOARD_BOOTIMAGE_PARTITION_SIZE := 8388608
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 8388608
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 1610612736
BOARD_USERDATAIMAGE_PARTITION_SIZE := 12381585408
BOARD_FLASH_BLOCK_SIZE := 4096
TARGET_USERIMAGES_USE_EXT4 := true
TARGET_USERIMAGES_SPARSE_EXT_DISABLED := true
BOARD_HAS_TWOSTORAGES := true

# OpenGL
BOARD_USES_HGL := true
BOARD_NO_32BPP := true
BOARD_EGL_CFG := device/hyundai/smdk4x12/conf/egl.cfg
USE_OPENGL_RENDERER := true

# JPEG hw accel
BOARD_USES_SKIAHWJPEG := true
COMMON_GLOBAL_CFLAGS += -DSEC_HWJPEG_G2D

# HDMI & TVout options
BOARD_USES_HDMI_SUBTITLES := false
BOARD_USES_HDMI := true
BOARD_HDMI_STD := STD_1080P
BOARD_HDMI_DDC_CH := DDC_CH_I2C_2
BOARD_USES_FIMGAPI := true
BOARD_USE_SECTVOUT := true
BOARD_USES_SKTEXTBOX := true

# Colourspace options
BOARD_USE_SAMSUNG_COLORFORMAT := true
BOARD_NONBLOCK_MODE_PROCESS := true
BOARD_USE_STOREMETADATA := true
BOARD_USE_METADATABUFFERTYPE := true
BOARD_USES_MFC_FPS := true
BOARD_USE_S3D_SUPPORT := true
BOARD_USE_CSC_FIMC := false
BOARD_USES_PROPRIETARY_LIBFIMC := false

# FIMG Acceleration
BOARD_USES_FIMGAPI := true
BOARD_USES_SKIA_FIMGAPI := true

# Enable WEBGL in WebKit
ENABLE_WEBGL := true

# HWComposer
BOARD_USES_HWCOMPOSER := true
BOARD_USE_SYSFS_VSYNC_NOTIFICATION := true

# RIL
#BOARD_MOBILEDATA_INTERFACE_NAME := "pdp0"

# Enable V4L2 & ION
BOARD_USE_V4L2 := true
BOARD_USE_V4L2_ION := false
BOARD_NO_OVERLAY := false

# WiFi
BOARD_HAVE_WIFI := true
BOARD_WLAN_DEVICE                := mt6620
WPA_SUPPLICANT_VERSION 		 := MTK_VER_1_0
BOARD_WPA_SUPPLICANT_DRIVER	 := WEXT
#BOARD_P2P_SUPPLICANT_DRIVER	 := NL80211
BOARD_WPA_SUPPLICANT_PRIVATE_LIB := "/system/lib/libwpa_client.so"
WIFI_DRIVER_MODULE_PATH          := "/system/lib/modules/wlan.ko"
WIFI_DRIVER_MODULE_NAME          := "wlan"
WIFI_BAND                        := 802_11_BGN
BOARD_HAVE_SAMSUNG_WIFI          := false

# Bluetooth options
BOARD_HAVE_BLUETOOTH := true
BOARD_HAVE_BLUETOOTH_CSR := false
BOARD_HAVE_BLUETOOTH_BCM := false
BOARD_HAVE_SAMSUNG_BLUETOOTH := false
BOARD_BLUEDROID_VENDOR_CONF := device/hyundai/smdk4x12/bluetooth/vnd_smdk4x12.txt

# GPS
BOARD_HAVE_GPS := true
BOARD_GPS_LIBRARIES := false

# FM
#BOARD_HAVE_FM := false

# Vold
TARGET_USE_CUSTOM_LUN_FILE_PATH := "/sys/devices/platform/s3c-usbgadget/gadget/lun%d/file"

# Charging mode
BOARD_CHARGING_MODE_BOOTING_LPM := /sys/class/power_supply/battery/batt_lp_charging
BOARD_BATTERY_DEVICE_NAME := "battery"

# Common Recovery options
BOARD_CUSTOM_GRAPHICS := ../../../device/hyundai/smdk4x12/recovery/graphics.c
BOARD_USE_CUSTOM_RECOVERY_FONT := \"roboto_15x24.h\"
BOARD_UMS_LUNFILE := "/sys/class/android_usb/android0/f_mass_storage/lun0/file"
BOARD_USES_MMCUTILS := true
BOARD_HAS_LARGE_FILESYSTEM := true
BOARD_HAS_NO_MISC_PARTITION := false

# LCD Options
BOARD_USES_HIGH_RESOLUTION_LCD := true

# Sensors Options
BOARD_USES_G_SENSOR_MMA7660 : true
