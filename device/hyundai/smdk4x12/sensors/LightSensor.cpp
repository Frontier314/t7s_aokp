/*
 * Copyright (C) 2008 The Android Open Source Project
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

#include <fcntl.h>
#include <errno.h>
#include <math.h>
#include <poll.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/select.h>
#include <cutils/log.h>

#include "LightSensor.h"

//#define SENSOR_DEBUG

#ifdef SENSOR_DEBUG
#define DEBUG(format, ...) LOGD((format), ## __VA_ARGS__)
#else
#define DEBUG(format, ...)
#endif

/*****************************************************************************/
#define FIRST_GOOD_EVENT    1

LightSensor::LightSensor()
    : SensorBase(NULL, "light_sensor"),
      mEnabled(0),
      mEventsSinceEnable(0),
      mInputReader(4),
      mHasPendingEvent(false)
{
    mPendingEvent.version = sizeof(sensors_event_t);
    mPendingEvent.sensor = ID_L;
    mPendingEvent.type = SENSOR_TYPE_LIGHT;
    memset(mPendingEvent.data, 0, sizeof(mPendingEvent.data));
}

LightSensor::~LightSensor() {
}

int LightSensor::setDelay(int32_t handle, int64_t ns)
{
    return 0;
}

int LightSensor::enable(int32_t handle, int en)
{
    int flags = en ? 1 : 0;
    mEventsSinceEnable = 0;
    mPreviousLight = -1;
    if (flags != mEnabled) {
        mEnabled = flags;
    }
    return 0;
}

bool LightSensor::hasPendingEvents() const {
    return mHasPendingEvent;
}

int LightSensor::readEvents(sensors_event_t* data, int count)
{
    if (count < 1)
        return -EINVAL;

    if (mHasPendingEvent) {
        mHasPendingEvent = false;
        mPendingEvent.timestamp = getTimestamp();
        *data = mPendingEvent;
        return mEnabled ? 1 : 0;
    }

    ssize_t n = mInputReader.fill(data_fd);
    if (n < 0)
        return n;

    int numEventReceived = 0;
    input_event const* event;

    while (count && mInputReader.readEvent(&event)) {
        int type = event->type;
        if (type == EV_ABS) {
            if (event->code == ABS_X) {
                mPendingEvent.light = indexToValue(event->value);
                if (mEventsSinceEnable < FIRST_GOOD_EVENT)
                    mEventsSinceEnable++;
            }
        } else if (type == EV_SYN) {
            mPendingEvent.timestamp = timevalToNano(event->time);
            if (mEnabled && (mPendingEvent.light != mPreviousLight) &&
                    mEventsSinceEnable >= FIRST_GOOD_EVENT) {
                *data++ = mPendingEvent;
                count--;
                numEventReceived++;
                mPreviousLight = mPendingEvent.light;
            }
        } else {
            ALOGE("LightSensor: unknown event (type=%d, code=%d)",
                    type, event->code);
        }
        mInputReader.next();
    }
    return numEventReceived;
}

float LightSensor::indexToValue(size_t index) const
{
    /* GL3526 driver converts from adc value and returns an index [0,4].  Now convert it to lux levels. */
    static float lux_value[] = {
        3500.0,
        1500.0,
        800.0,
        500.0,
        100.0,
    };
    if (index > ARRAY_SIZE(lux_value))
        index = 0;
    return lux_value[index];
}