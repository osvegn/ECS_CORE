/**
* Filename: reset_game_clock.h
* Path: include/systems
* Created Date: Thuesday, December 19th 2023, 11:37am
* Author: osvegn
*
* Copyright (c) 2023 our_rpg
 */

#ifndef RESET_GAME_CLOCK_H_
#define RESET_GAME_CLOCK_H_

#include "system.h"

int system_reset_game_clock_constructor(system_t *system);
int system_reset_game_clock(void *world);

#endif // RESET_GAME_CLOCK_H_
