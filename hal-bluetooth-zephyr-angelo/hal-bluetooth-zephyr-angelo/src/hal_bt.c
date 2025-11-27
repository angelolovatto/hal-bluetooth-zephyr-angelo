/*
 * hal_bt.c - Implementação da camada de Bluetooth (esqueleto)
 */

#include "hal_bt.h"

#include <zephyr/sys/printk.h>
#include <errno.h>

#if defined(CONFIG_BT)

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/sys/util.h>

static const struct bt_data ad[] = {
    BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
    BT_DATA(BT_DATA_NAME_COMPLETE,
            CONFIG_BT_DEVICE_NAME,
            sizeof(CONFIG_BT_DEVICE_NAME) - 1),
};

static void bt_ready(int err)
{
    if (err) {
        printk("HAL BT: bt_enable falhou (err %d)\n", err);
        return;
    }
    printk("HAL BT: stack Bluetooth pronta.\n");
}

int hal_bt_init(void)
{
    int err = bt_enable(bt_ready);
    if (err) {
        printk("HAL BT: bt_enable retornou erro %d\n", err);
        return err;
    }
    return 0;
}

int hal_bt_start_advertising(void)
{
    int err = bt_le_adv_start(BT_LE_ADV_CONN_NAME, ad, ARRAY_SIZE(ad), NULL, 0);
    if (err) {
        printk("HAL BT: falha ao iniciar advertising (err %d)\n", err);
        return err;
    }

    printk("HAL BT: advertising iniciado com sucesso.\n");
    return 0;
}

#else /* CONFIG_BT não definido */

int hal_bt_init(void)
{
    printk("HAL BT: CONFIG_BT desabilitado, ignorando inicializacao.\n");
    return -ENOTSUP;
}

int hal_bt_start_advertising(void)
{
    printk("HAL BT: CONFIG_BT desabilitado, nao e possivel anunciar.\n");
    return -ENOTSUP;
}

#endif
