# Release name
PRODUCT_RELEASE_NAME := aokp_t7s

# Inherit some common AOKP stuff.
$(call inherit-product, vendor/aokp/configs/common_tablet.mk)

# Inherit device configuration
$(call inherit-product, device/hyundai/t7s/full_t7s.mk)

# Device identifier. This must come after all inclusions
PRODUCT_DEVICE := smdk4x12
PRODUCT_NAME := aokp_t7s
PRODUCT_BRAND := hyundai
PRODUCT_MODEL := Hyundai T7s

# Set build fingerprint / ID / Product Name ect.
PRODUCT_BUILD_PROP_OVERRIDES += PRODUCT_NAME=smdk4x12 TARGET_DEVICE=smdk4x12 BUILD_FINGERPRINT="samsung/p4noterfxx/p4noterf:4.0.4/IMM76D/N8000XWALG9:user/release-keys" PRIVATE_BUILD_DESC="samsung/p4notewifiue/p4notewifi:4.0.4/IMM76D/N8013UEALH2:user/release-keys"
