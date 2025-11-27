/*
 * hal_gpio.c - Implementação da camada de GPIO
 */

#include "hal_gpio.h"

#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/printk.h>

/* Usa o alias 'led0' definido no device tree da placa */
#if !DT_NODE_HAS_STATUS(DT_ALIAS(led0), okay)
#error "Alias 'led0' nao definido no device tree. Verifique a placa ou crie um alias."
#endif

static const struct gpio_dt_spec led0 = GPIO_DT_SPEC_GET(DT_ALIAS(led0), gpios);
static bool led_ready;
static bool led_state;

int hal_gpio_init(void)
{
    if (!device_is_ready(led0.port)) {
        printk("HAL GPIO: dispositivo do LED nao esta pronto.\n");
        led_ready = false;
        return -ENODEV;
    }

    int ret = gpio_pin_configure_dt(&led0, GPIO_OUTPUT_INACTIVE);
    if (ret < 0) {
        printk("HAL GPIO: erro ao configurar LED (%d).\n", ret);
        led_ready = false;
        return ret;
    }

    led_ready = true;
    led_state = false;
    printk("HAL GPIO: LED inicializado com sucesso.\n");
    return 0;
}

void hal_gpio_led_on(void)
{
    if (!led_ready) {
        return;
    }
    gpio_pin_set_dt(&led0, 1);
    led_state = true;
}

void hal_gpio_led_off(void)
{
    if (!led_ready) {
        return;
    }
    gpio_pin_set_dt(&led0, 0);
    led_state = false;
}

void hal_gpio_led_toggle(void)
{
    if (!led_ready) {
        return;
    }
    led_state = !led_state;
    gpio_pin_set_dt(&led0, (int)led_state);
}
