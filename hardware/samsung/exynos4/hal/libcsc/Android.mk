LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_COPY_HEADERS_TO := libsecmm
LOCAL_COPY_HEADERS := \
	csc.h

LOCAL_MODULE_TAGS := optional

LOCAL_SRC_FILES := \
	csc.c

LOCAL_C_INCLUDES := \
	hardware/samsung/exynos/multimedia/openmax/include/khronos \
	hardware/samsung/exynos/multimedia/openmax/include/sec

LOCAL_CFLAGS :=

LOCAL_MODULE := libcsc

LOCAL_PRELINK_MODULE := false

LOCAL_ARM_MODE := arm

LOCAL_STATIC_LIBRARIES := libswconverter
LOCAL_SHARED_LIBRARIES := liblog

ifeq ($(BOARD_USE_SAMSUNG_COLORFORMAT), true)
LOCAL_CFLAGS += -DUSE_SAMSUNG_COLORFORMAT
endif

ifeq ($(TARGET_BOARD_PLATFORM), exynos4)
LOCAL_SRC_FILES += hwconverter_wrapper.cpp
LOCAL_C_INCLUDES += \
	hardware/samsung/exynos4/hal/include \
	hardware/samsung/exynos4/hal/libhwconverter
LOCAL_CFLAGS += -DUSE_FIMC
LOCAL_SHARED_LIBRARIES += libfimc libhwconverter
endif

ifeq ($(BOARD_USE_V4L2_ION),true)
LOCAL_CFLAGS += -DUSE_ION
LOCAL_SHARED_LIBRARIES += libion
endif

ifeq ($(BOARD_USE_EXYNOS_OMX), true)
LOCAL_CFLAGS += -DEXYNOS_OMX
endif

include $(BUILD_SHARED_LIBRARY)
