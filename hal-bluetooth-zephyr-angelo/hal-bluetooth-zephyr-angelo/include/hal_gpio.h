/*
 * hal_gpio.h - Interface da camada de abstração de GPIO
 */

#ifndef HAL_GPIO_H_
#define HAL_GPIO_H_

#include <zephyr/kernel.h>

int hal_gpio_init(void);
void hal_gpio_led_on(void);
void hal_gpio_led_off(void);
void hal_gpio_led_toggle(void);

#endif /* HAL_GPIO_H_ */
