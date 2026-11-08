


/*
 * Copyright (c) 2016 Intel Corporation
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/devicetree.h>

// /* Get node identifiers for all three LEDs using aliases or node labels */
// #define LED0_NODE DT_ALIAS(led0)                  /* Board's default user LED */
// #define BLUE_LED_NODE DT_NODELABEL(blue_led)      /* Custom blue LED from overlay */
// #define RED_LED_NODE DT_NODELABEL(red_led)        /* Custom red LED from overlay */

#define APP_LED_NODE DT_ALIAS(app_led)

/* Initialize GPIO specifications for each LED */
// static const struct gpio_dt_spec led0 = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
// static const struct gpio_dt_spec blue_led = GPIO_DT_SPEC_GET(BLUE_LED_NODE, gpios);
// static const struct gpio_dt_spec red_led = GPIO_DT_SPEC_GET(RED_LED_NODE, gpios);

static const struct gpio_dt_spec led=GPIO_DT_SPEC_GET(APP_LED_NODE, gpios);

int main(void)
{

int ret;

    if (!gpio_is_ready_dt(&led)) {
        printf("Error: LED device not ready!\n");
        return 0;
    }
    
    ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
    if (ret < 0) {
        return 0;
    }

    printf("Heartbeat LED started with period: %d ms\n", CONFIG_APP_HEARTBEAT_PERIOD_MS);

    while (1) {
        ret = gpio_pin_toggle_dt(&led);
        if (ret < 0) {
            return 0;
        }

        /* Use the Kconfig macro for sleep duration */
        k_msleep(CONFIG_APP_HEARTBEAT_PERIOD_MS);
    }


    #if 0
    // int ret;

    // /* Verify that all LED devices are ready */
    // if (!gpio_is_ready_dt(&led0) || !gpio_is_ready_dt(&blue_led) || !gpio_is_ready_dt(&red_led)) {
    //     printf("Error: One or more LED GPIO controllers are not ready!\n");
    //     return 0;
    // }
    
    // /* Configure all LED pins as outputs */
    // ret = gpio_pin_configure_dt(&led0, GPIO_OUTPUT_ACTIVE);
    // if (ret < 0) return 0;

    // ret = gpio_pin_configure_dt(&blue_led, GPIO_OUTPUT_INACTIVE);
    // if (ret < 0) return 0;

    // ret = gpio_pin_configure_dt(&red_led, GPIO_OUTPUT_INACTIVE);
    // if (ret < 0) return 0;

    // printf("Starting multi-LED toggle sequence...\n");

    // while (1) {
    //     /* Toggle all three LEDs */
    //     gpio_pin_toggle_dt(&led0);
    //     gpio_pin_toggle_dt(&blue_led);
    //     gpio_pin_toggle_dt(&red_led);

    //     printf("Toggled LEDs state.\n");
    //     k_msleep(CONFIG_BLINK_SLEEP_TIME_MS); /* Wait 1 second */
    // }
    #endif
    return 0;
}








