#
# Copyright (C) 2012 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

$(call inherit-product, device/hyundai/smdk4x12/full_smdk4x12.mk)

LOCAL_PATH := device/hyundai/t7s

DEVICE_PACKAGE_OVERLAYS += $(LOCAL_PATH)/overlay

PRODUCT_AAPT_CONFIG := mdpi hdpi
PRODUCT_AAPT_PREF_CONFIG := hdpi

TARGET_SCREEN_HEIGHT := 800
TARGET_SCREEN_WIDTH := 1280

# These are the hardware-specific features
PRODUCT_COPY_FILES += \
    frameworks/native/data/etc/handheld_core_hardware.xml:system/etc/permissions/handheld_core_hardware.xml

# Gps
PRODUCT_COPY_FILES += \
     $(LOCAL_PATH)/conf/gps.conf:system/etc/gps.conf 

# Kernel modules
PRODUCT_COPY_FILES += \
     $(LOCAL_PATH)/modules/battery.ko:system/utmodules/battery.ko \
     $(LOCAL_PATH)/modules/ft5x0x_ts_5406.ko:system/utmodules/ft5x0x_ts_5406.ko \
     $(LOCAL_PATH)/modules/mma7660.ko:system/utmodules/mma7660.ko \
     $(LOCAL_PATH)/modules/hci_stp.ko:system/lib/modules/hci_stp.ko \
     $(LOCAL_PATH)/modules/hci_uart.ko:system/lib/modules/hci_uark.ko \
     $(LOCAL_PATH)/modules/mtk_hif_sdio.ko:system/lib/modules/mtk_hif_sdio.ko \
     $(LOCAL_PATH)/modules/mtk_stp_bt.ko:system/lib/modules/mtk_stp_bt.ko \
     $(LOCAL_PATH)/modules/mtk_stp_gps.ko:system/lib/modules/mtk_stp_gps.ko \
     $(LOCAL_PATH)/modules/mtk_stp_uart.ko:system/lib/modules/mtk_stp_uart.ko \
     $(LOCAL_PATH)/modules/mtk_stp_wmt.ko:system/lib/modules/mtk_stp_wmt.ko \
     $(LOCAL_PATH)/modules/mtk_wmt_wifi.ko:system/lib/modules/mtk_wmt_wifi.ko \
     $(LOCAL_PATH)/modules/p2p.ko:system/lib/modules/p2p.ko \
     $(LOCAL_PATH)/modules/wlan.ko:system/lib/modules/wlan.ko
     
# WIFI Firmware
PRODUCT_COPY_FILES += \
     $(LOCAL_PATH)/firmware/WMT.cfg:system/etc/firmware/WMT.cfg \
     $(LOCAL_PATH)/firmware/WIFI_RAM_CODE:system/etc/firmware/WIFI_RAM_CODE \
     $(LOCAL_PATH)/firmware/WIFI_RAM_CODE_E6:system/etc/firmware/WIFI_RAM_CODE_E6 \
     $(LOCAL_PATH)/firmware/mt6620_patch_e3_0_hdr.bin:system/etc/firmware/mt6620_patch_e3_0_hdr.bin \
     $(LOCAL_PATH)/firmware/mt6620_patch_e3_1_hdr.bin:system/etc/firmware/mt6620_patch_e3_1_hdr.bin \
     $(LOCAL_PATH)/firmware/mt6620_patch_e3_2_hdr.bin:system/etc/firmware/mt6620_patch_e3_2_hdr.bin \
     $(LOCAL_PATH)/firmware/mt6620_patch_e3_3_hdr.bin:system/etc/firmware/mt6620_patch_e3_3_hdr.bin
     
# T7s specific files
PRODUCT_COPY_FILES += \
     $(LOCAL_PATH)/conf/gps.conf:system/etc/gps.conf \
     $(LOCAL_PATH)/conf/modems-conf.xml:system/etc/modems-conf.xml \
     $(LOCAL_PATH)/conf/usb-modem-dialer:system/etc/usb-modem-dialer \
     $(LOCAL_PATH)/ppp/chap-secrets:system/etc/ppp/chap-secrets \
     $(LOCAL_PATH)/ppp/chat.conf:system/etc/ppp/chat.conf \
     $(LOCAL_PATH)/ppp/chat_serial_0.conf:system/etc/ppp/chat_serial_0 \
     $(LOCAL_PATH)/ppp/chat_serial_1.conf:system/etc/ppp/chat_serial_1 \
     $(LOCAL_PATH)/ppp/chat_serial_2.conf:system/etc/ppp/chat_serial_2 \
     $(LOCAL_PATH)/ppp/chat_serial_3.conf:system/etc/ppp/chat_serial_3 \
     $(LOCAL_PATH)/ppp/chat_serial_4.conf:system/etc/ppp/chat_serial_4 \
     $(LOCAL_PATH)/ppp/chat_serial_5.conf:system/etc/ppp/chat_serial_5 \
     $(LOCAL_PATH)/ppp/chat_tmp:system/etc/ppp/chat_tmp \
     $(LOCAL_PATH)/ppp/connect-errors:system/etc/ppp/connect-errors \
     $(LOCAL_PATH)/ppp/connect3g:system/etc/ppp/connect3g \
     $(LOCAL_PATH)/ppp/cpydialnum:system/etc/ppp/cpydialnum \
     $(LOCAL_PATH)/ppp/dialer:system/etc/ppp/dialer \
     $(LOCAL_PATH)/ppp/dialer_tmp:system/etc/ppp/dialer_tmp \
     $(LOCAL_PATH)/ppp/gprs-connect-chat:system/etc/ppp/gprs-connect-chat \
     $(LOCAL_PATH)/ppp/ip-down:system/etc/ppp/ip-down \
     $(LOCAL_PATH)/ppp/ip-up:system/etc/ppp/ip-up \
     $(LOCAL_PATH)/ppp/ip-up-vpn:system/etc/ppp/ip-up-vpn \
     $(LOCAL_PATH)/ppp/pap-secrets:system/etc/ppp/pap-secrets \
     $(LOCAL_PATH)/ppp/serial_0.dia:system/etc/ppp/serial_0.dia \
     $(LOCAL_PATH)/ppp/serial_1.dia:system/etc/ppp/serial_1.dia \
     $(LOCAL_PATH)/ppp/serial_2.dia:system/etc/ppp/serial_2.dia \
     $(LOCAL_PATH)/ppp/serial_3.dia:system/etc/ppp/serial_3.dia \
     $(LOCAL_PATH)/ppp/serial_4.dia:system/etc/ppp/serial_4.dia \
     $(LOCAL_PATH)/ppp/serial_5.dia:system/etc/ppp/serial_5.dia \
     $(LOCAL_PATH)/ppp/switch3g.sh:system/etc/ppp/switch3g.sh
     