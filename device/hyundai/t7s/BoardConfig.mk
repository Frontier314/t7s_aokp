# Inherit common SMDK4x12 board configuration
-include device/hyundai/smdk4x12/BoardConfig.mk

# Kernel
BOARD_KERNEL_CMDLINE := console=ttySAC2,115200 ddr=55 tmu=yes macID= dock= tp=ft54 umsvor= umspct= battery=W885 plug= bltype=n amp=4745 motor_value= utmodel=s702 lcd=hs101h came=500W_D_V01 codec=wm8978 bt=mt6x wifi=mt6x gps=mt6x eth=dongle fm=no gsmd=dongle nfc= ls= motor=yes lcdRGB=0d840100 serialno=ExynosMID macw= macb=

# RIL
BOARD_PROVIDES_LIBRIL := false

# Kernel source
# TARGET_KERNEL_SOURCE := kernel/samsung/smdk4412
# TARGET_KERNEL_CONFIG := urbetter_s702_defconfig

# Prebuilt kernel
TARGET_PREBUILT_KERNEL := device/hyundai/t7s/kernel/kernel

# Suspend in Charge mode
BOARD_ALLOW_SUSPEND_IN_CHARGER := true

# assert
TARGET_OTA_ASSERT_DEVICE := s702,hyundai_t7s

# Recovery
BOARD_CUSTOM_RECOVERY_KEYMAPPING := ../../device/hyundai/t7s/recovery/recovery_keys.c
BOARD_HAS_NO_SELECT_BUTTON := false
TARGET_RECOVERY_INITRC := device/hyundai/smdk4x12/conf/recovery.rc

# Target Device name
TARGET_DEVICE := t7s
