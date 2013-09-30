LOCAL_PATH := $(call my-dir)

########################
include $(CLEAR_VARS)
LOCAL_MODULE := wpa_passphrase
LOCAL_MODULE_PATH := $(TARGET_OUT)/bin
LOCAL_MODULE_TAGS := eng
LOCAL_SRC_FILES := $(LOCAL_MODULE)
LOCAL_MODULE_CLASS := ETC
include $(BUILD_PREBUILT)
########################

########################
include $(CLEAR_VARS)
LOCAL_MODULE := wpa_supplicant
LOCAL_MODULE_PATH := $(TARGET_OUT)/bin
LOCAL_MODULE_TAGS := eng
LOCAL_SRC_FILES := $(LOCAL_MODULE)
LOCAL_MODULE_CLASS := ETC
include $(BUILD_PREBUILT)
########################

########################
include $(CLEAR_VARS)
LOCAL_MODULE := p2p_cli
LOCAL_MODULE_PATH := $(TARGET_OUT)/bin
LOCAL_MODULE_TAGS := eng
LOCAL_MODULE_CLASS := ETC
LOCAL_SRC_FILES := $(LOCAL_MODULE)
include $(BUILD_PREBUILT)
########################

########################
include $(CLEAR_VARS)
LOCAL_MODULE := p2p_supplicant
LOCAL_MODULE_PATH := $(TARGET_OUT)/bin
LOCAL_MODULE_TAGS := eng
LOCAL_MODULE_CLASS := ETC
LOCAL_SRC_FILES := $(LOCAL_MODULE)
include $(BUILD_PREBUILT)
########################

########################
include $(CLEAR_VARS)
LOCAL_MODULE := libwpa_client
LOCAL_SRC_FILES := $(LOCAL_MODULE).so
LOCAL_MODULE_PATH := $(TARGET_OUT_SHARED_LIBRARIES)
LOCAL_MODULE_SUFFIX := .so
LOCAL_MODULE_TAGS := eng
LOCAL_PRELINK_MODULE := false
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
WPA_CLIENT_HEADER_PATH := $(TARGET_OUT_HEADERS)/libwpa_client
$(shell test ! -d $(TARGET_OUT_HEADERS) && mkdir $(TARGET_OUT_HEADERS) )
$(shell test ! -d $(WPA_CLIENT_HEADER_PATH) && mkdir $(WPA_CLIENT_HEADER_PATH) )
$(shell test ! -f $(WPA_CLIENT_HEADER_PATH)/wpa_ctrl.h && cp $(LOCAL_PATH)/wpa_ctrl.h $(WPA_CLIENT_HEADER_PATH))
include $(BUILD_PREBUILT)
########################
