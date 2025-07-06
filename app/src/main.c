#include <zephyr/kernel.h>
#include <stdlib.h>
#include <zephyr/device.h>
#include <zephyr/drivers/sensor.h>

int main(void)
{
    const struct device *lidar = DEVICE_DT_GET(DT_ALIAS(lidarlite));
    
    while (1) {
        if (sensor_sample_fetch(lidar)) {
            printk("sad\n");
        } else {
            printk("happy\n");
        }
        k_msleep(500);
    }
    // if (!device_is_ready(lidar)) {
    //     printk("LIDAR not ready\n");
    //     return EXIT_FAILURE;
    // }

    // while (1) {
    //     sensor_sample_fetch(lidar);
    //     struct sensor_value val;
    //     sensor_channel_get(lidar, SENSOR_CHAN_DISTANCE, &val);
    //     printk("Distance: %d cm\n", val.val1);
    //     k_msleep(500);
    // }

    return EXIT_SUCCESS;
}
