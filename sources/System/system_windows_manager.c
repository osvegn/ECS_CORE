/*
 * Filename:
 * /home/thomas/Documents/Perso/our_rpg/sources/System/windows_manager.c Path:
 * /home/thomas/Documents/Perso/our_rpg/sources/System Created Date: Friday,
 * March 10th 2023, 6:57:13 pm Author: Thomas
 *
 * Copyright (c) 2023 Your Company
 */

#include "components.h"
#include "raylib.h"
#include "systems.h"
#include "world.h"

int system_windows_manager_constructor(system_t *system)
{
    system->type = S_WINDOW_MANAGER;
    system->run = &system_windows_manager;
    system->active = true;
    return 0;
}

int system_windows_manager(void *ptr)
{
    if (WindowShouldClose())
        return -1;
    return 0;
}
