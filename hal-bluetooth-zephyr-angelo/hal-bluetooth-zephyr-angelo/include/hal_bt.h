/*
 * hal_bt.h - Interface da camada de abstração de Bluetooth
 */

#ifndef HAL_BT_H_
#define HAL_BT_H_

/* Inicializa a stack Bluetooth (quando CONFIG_BT=y).
 * Retorna 0 em caso de sucesso ou um código de erro negativo.
 */
int hal_bt_init(void);

/* Inicia advertising BLE usando o nome definido em CONFIG_BT_DEVICE_NAME.
 * Retorna 0 em caso de sucesso ou um código de erro negativo.
 */
int hal_bt_start_advertising(void);

#endif /* HAL_BT_H_ */
