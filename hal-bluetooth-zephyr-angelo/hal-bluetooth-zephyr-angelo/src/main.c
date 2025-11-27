/*
 * main.c - Aplicação principal usando o HAL (GPIO + Bluetooth)
 */

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "hal_gpio.h"
#include "hal_bt.h"

#define MAIN_SLEEP_MS 500

void main(void)
{
    int ret;

    printk("HAL Bluetooth + Zephyr - Angelo Lovatto\n");

    /* Inicializa camada de GPIO (LED) */
    ret = hal_gpio_init();
    if (ret) {
        printk("Erro ao inicializar HAL GPIO (%d)\n", ret);
    }

#if defined(CONFIG_BT)
    /* Tenta inicializar BLE via HAL */
    ret = hal_bt_init();
    if (ret) {
        printk("Erro ao inicializar HAL Bluetooth (%d)\n", ret);
    } else {
        printk("Bluetooth inicializado, iniciando advertising...\n");
        (void)hal_bt_start_advertising();
    }
#else
    printk("Bluetooth desabilitado em tempo de compilacao (CONFIG_BT=n)\n");
#endif

    while (1) {
        hal_gpio_led_toggle();
        k_msleep(MAIN_SLEEP_MS);
    }
}
