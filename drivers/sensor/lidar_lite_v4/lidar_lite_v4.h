#ifndef ZEPHYR_DRIVERS_SENSOR_LIDAR_LITE_V4
#define ZEPHYR_DRIVERS_SENSOR_LIDAR_LITE_V4

#include <zephyr/device.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/drivers/sensor.h>

struct lidar_lite_v4_config {
    struct i2c_dt_spec i2c;
};

struct lidar_lite_v4_data {
    /* Add sensor-specific runtime data here, e.g.:
       int16_t distance;
       int status;
    */
   int hello;
};

#endif // ZEPHYR_DRIVERS_SENSOR_LIDAR_LITE_V4