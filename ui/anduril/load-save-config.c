// load-save-config.c: Load/save/eeprom functions for Anduril.
// Copyright (C) 2017-2023 Selene ToyKeeper
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "anduril/load-save-config-fsm.h"
#include "anduril/load-save-config.h"

void load_config() {
    eeprom = (uint8_t *)&cfg;

    if (! load_eeprom()) return;

    #ifdef START_AT_MEMORIZED_LEVEL
    if (load_eeprom_wl()) {
        memorized_level = eeprom_wl[0];
    }
    #endif

    #ifdef USE_POCKET_UI
    // TODO Ugly, but required for compiler optimization
    pocket_ui_active = cfg.pocket_ui_active;
    #endif
}

void save_config() {
    #ifdef USE_POCKET_UI
    // TODO Ugly, but required for compiler optimization
    cfg.pocket_ui_active = pocket_ui_active;
    #endif

    eeprom = (uint8_t *)&cfg;
    save_eeprom();
}

#ifdef START_AT_MEMORIZED_LEVEL
void save_config_wl() {
    eeprom_wl[0] = memorized_level;
    save_eeprom_wl();
}
#endif

