/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/System/windows_manager.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/System
 * Created Date: Friday, March 10th 2023, 6:57:13 pm
 * Author: Thomas
 * 
 * Copyright (c) 2023 Your Company
 */

#include "world.h"
#include "systems.h"
#include "components.h"
#include "raylib.h"

int windows_manager_constructor(system_t *system)
{
    system->type = WINDOW_MANAGER;
    system->run = &windows_manager;
    system->active = true;
    return 0;
}

int windows_manager(void *ptr)
{
    if (WindowShouldClose())
        return -1;
    return 0;
}
