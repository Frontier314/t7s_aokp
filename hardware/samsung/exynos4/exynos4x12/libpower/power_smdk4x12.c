/*
 * Copyright (C) 2012 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
//#define LOG_NDEBUG 0

#define LOG_TAG "SMDK4412PowerHAL"
#include <utils/Log.h>

#include <hardware/hardware.h>
#include <hardware/power.h>

#define BOOSTPULSE_PATH "/sys/devices/system/cpu/cpufreq/interactive/boostpulse"

struct smdk4x12_power_module {
    struct power_module base;
    pthread_mutex_t lock;
    int boostpulse_fd;
    int boostpulse_warned;
    const char *touchscreen_power_path;
};

static void sysfs_write(const char *path, char *s)
{
    char buf[80];
    int len;
    int fd = open(path, O_WRONLY);

    if (fd < 0) {
        strerror_r(errno, buf, sizeof(buf));
        ALOGE("Error opening %s: %s\n", path, buf);
        return;
    }

    len = write(fd, s, strlen(s));
    if (len < 0) {
        strerror_r(errno, buf, sizeof(buf));
        ALOGE("Error writing to %s: %s\n", path, buf);
    }

    close(fd);
}

static void power_init(struct power_module *module)
{
    struct smdk4x12_power_module *smdk4x12 = (struct smdk4x12_power_module *) module;
    struct dirent **namelist;
    int n;
    /*
     * cpufreq interactive governor: timer 20ms, min sample 40ms,
     * hispeed 1G at load 90%, 140ms load burst needed to move above hispeed.
     */

    sysfs_write("/sys/devices/system/cpu/cpufreq/interactive/timer_rate",
                "20000");
    sysfs_write("/sys/devices/system/cpu/cpufreq/interactive/min_sample_time",
                "40000");
    sysfs_write("/sys/devices/system/cpu/cpufreq/interactive/hispeed_freq",
                "1000000");
    sysfs_write("/sys/devices/system/cpu/cpufreq/interactive/go_hispeed_load",
                "90");
    sysfs_write("/sys/devices/system/cpu/cpufreq/interactive/above_hispeed_delay",
                "140000");
}

static void power_set_interactive(struct power_module *module, int on)
{
    struct smdk4x12_power_module *smdk4x12 = (struct smdk4x12_power_module *) module;
    char buf[80];
    int ret;

    ALOGV("power_set_interactive: %d\n", on);

    /*
     * Lower maximum frequency when screen is off.  All CPUs share a
     * cpufreq policy.
     */
    sysfs_write("/sys/devices/system/cpu/cpu0/cpufreq/scaling_max_freq",
                on ? "1600000" : "800000");

    ALOGV("power_set_interactive: %d done\n", on);
}

static int boostpulse_open(struct smdk4x12_power_module *smdk4x12)
{
    char buf[80];

    pthread_mutex_lock(&smdk4x12->lock);

    if (smdk4x12->boostpulse_fd < 0) {
        smdk4x12->boostpulse_fd = open(BOOSTPULSE_PATH, O_WRONLY);

        if (smdk4x12->boostpulse_fd < 0) {
            if (!smdk4x12->boostpulse_warned) {
                strerror_r(errno, buf, sizeof(buf));
                ALOGE("Error opening %s: %s\n", BOOSTPULSE_PATH, buf);
                smdk4x12->boostpulse_warned = 1;
            }
        }
    }

    pthread_mutex_unlock(&smdk4x12->lock);
    return smdk4x12->boostpulse_fd;
}

static void smdk4x12_power_hint(struct power_module *module, power_hint_t hint,
                             void *data)
{
    struct smdk4x12_power_module *smdk4x12 = (struct smdk4x12_power_module *) module;
    char buf[80];
    int len;

    switch (hint) {
     case POWER_HINT_INTERACTION:
        if (boostpulse_open(smdk4x12) >= 0) {
            len = write(smdk4x12->boostpulse_fd, "1", 1);

            if (len < 0) {
                strerror_r(errno, buf, sizeof(buf));
                ALOGE("Error writing to %s: %s\n", BOOSTPULSE_PATH, buf);
            }
        }
    ALOGV("power_set_interactive: POWER_HINT_INTERACTION done\n");

        break;

   case POWER_HINT_VSYNC:
        break;

    default:
            break;
    }
}

static struct hw_module_methods_t power_module_methods = {
    .open = NULL,
};

struct smdk4x12_power_module HAL_MODULE_INFO_SYM = {
    base: {
        common: {
            tag: HARDWARE_MODULE_TAG,
            module_api_version: POWER_MODULE_API_VERSION_0_2,
            hal_api_version: HARDWARE_HAL_API_VERSION,
            id: POWER_HARDWARE_MODULE_ID,
            name: "SMDK4412 Power HAL",
            author: "The Android Open Source Project",
            methods: &power_module_methods,
        },

        init: power_init,
        setInteractive: power_set_interactive,
        powerHint: smdk4x12_power_hint,
    },

    lock: PTHREAD_MUTEX_INITIALIZER,
    boostpulse_fd: -1,
    boostpulse_warned: 0,
};