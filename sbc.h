/*
 * MIT License
 *
 * Copyright (c) 2022 Jayson Reis
 */

#ifndef SBC_H
#define SBC_H

#include "device_config.h"
#include "gpio.h"

typedef enum {
    sbc_state_off,
    sbc_state_on,
} __attribute__((packed)) sbc_state_t;

#define SBC_RESTART_TIME              50000
#define SBC_MASKROOOM_TIME_PERCENTAGE 20
#define SBC_MASKROOOM_TIME            (SBC_RESTART_TIME + SBC_RESTART_TIME * SBC_MASKROOOM_TIME_PERCENTAGE / 100)

void sbc_init();

void sbc_handle();

void sbc_set_reboot();
void sbc_handle_reboot();

void sbc_set_maskroom_mode();
void sbc_handle_maskroom_mode();
#endif
