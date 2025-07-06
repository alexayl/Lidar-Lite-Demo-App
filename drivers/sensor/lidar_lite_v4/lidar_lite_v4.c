/*
 * Copyright (c) 2025 yo mama
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define DT_DRV_COMPAT garmin_lidar_lite_v4

#include <zephyr/drivers/i2c.h>
#include <zephyr/drivers/sensor.h>

#include "lidar_lite_v4.h"

int lidar_lite_v4_init(const struct device *dev) {

    return 0;
}

static int lidar_lite_v4_sample_fetch(const struct device *dev, enum sensor_channel chan) {
    
    return 0;
}

static int lidar_lite_v4_channel_get(const struct device *dev, enum sensor_channel chan, struct sensor_value *val) {
    
    return 0;
}

static const struct sensor_driver_api lidar_lite_v4_driver_api = {
	.sample_fetch = lidar_lite_v4_sample_fetch,
	.channel_get = lidar_lite_v4_channel_get,
};


#define LIDAR_LITE_V4_DEFINE(inst) \
    static struct lidar_lite_v4_data lidar_lite_v4_data_##inst; \
    static const struct lidar_lite_v4_config lidar_lite_v4_config_##inst = { \
        .i2c = I2C_DT_SPEC_INST_GET(inst), \
    }; \
    SENSOR_DEVICE_DT_INST_DEFINE(inst, \
        lidar_lite_v4_init, \
        NULL, \
        &lidar_lite_v4_data_##inst, \
        &lidar_lite_v4_config_##inst, \
        POST_KERNEL, \
        CONFIG_SENSOR_INIT_PRIORITY, \
        &lidar_lite_v4_driver_api);

DT_INST_FOREACH_STATUS_OKAY(LIDAR_LITE_V4_DEFINE)

/*
 *
 * @param node_id The devicetree node identifier.
 *
 * @param init_fn Name of the init function of the driver.
 *
 * @param pm_device PM device resources reference (NULL if device does not use
 * PM).
 *
 * @param data_ptr Pointer to the device's private data.
 *
 * @param cfg_ptr The address to the structure containing the configuration
 * information for this instance of the driver.
 *
 * @param level The initialization level. See SYS_INIT() for details.
 *
 * @param prio Priority within the selected initialization level. See
 * SYS_INIT() for details.
 *
 * @param api_ptr Provides an initial pointer to the API function struct used
 * by the driver. Can be NULL.
 */