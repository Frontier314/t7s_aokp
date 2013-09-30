# Inherit AOSP device configuration for grouper
$(call inherit-product, device/hyundai/t7s/full_t7s.mk)

# Inherit AOKP common_tablet bits
$(call inherit-product, vendor/aokp/configs/common_tablet.mk)

# Grouper Overlay
PRODUCT_PACKAGE_OVERLAYS += vendor/aokp/overlay/t7s

# Setup device specific product configuration.
PRODUCT_NAME := aokp_t7s
PRODUCT_BRAND := hyundai
PRODUCT_DEVICE := t7s
PRODUCT_MODEL := Hyundai T7s
PRODUCT_MANUFACTURER := hyundai

PRODUCT_BUILD_PROP_OVERRIDES := PRODUCT_NAME=nakasi BUILD_FINGERPRINT=google/nakasi/grouper:4.2.2/JDQ39/573038:user/release-keys PRIVATE_BUILD_DESC="nakasi-user 4.2.2 JDQ39 573038 release-keys" BUILD_NUMBER=573038

PRODUCT_COPY_FILES += \
    vendor/aokp/prebuilt/bootanimation/bootanimation.zip:system/media/bootanimation.zip