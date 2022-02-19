/*
 * MIT License
 *
 * Copyright (c) 2022 Jayson Reis
 */

#include "sbc.h"

static int sbc_reboot = 0;
static int sbc_maskroom_mode = 0;

void sbc_init()
{
    gpio_pin_init(&device_config_get()->maskroom_relay);
    gpio_pin_init(&device_config_get()->charger_relay);
}

void sbc_handle()
{
    sbc_handle_reboot();
    sbc_handle_maskroom_mode();
}

void sbc_set_reboot()
{
    sbc_reboot = SBC_RESTART_TIME;
}

void sbc_handle_reboot()
{
    sbc_state_t state = sbc_state_on;
    if (sbc_reboot) {
        sbc_reboot--;
        state = sbc_state_off;
    }
    gpio_pin_set(&device_config_get()->charger_relay, state);
}

void sbc_set_maskroom_mode()
{
    sbc_maskroom_mode = SBC_MASKROOOM_TIME;
}

void sbc_handle_maskroom_mode()
{
    sbc_state_t state = sbc_state_off;
    if (sbc_maskroom_mode) {
        sbc_maskroom_mode--;
        state = sbc_state_on;
    }
    gpio_pin_set(&device_config_get()->maskroom_relay, state);
}