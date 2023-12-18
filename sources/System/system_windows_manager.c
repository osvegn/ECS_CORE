/*
 * Filename: windows_manager.c
 * Path: sources/System
 * Created Date: Friday, March 10th 2023, 6:57:13 pm
 * Author: Thomas
 *
 * Copyright (c) 2023 our_rpg
 */

#include "systems.h"

int system_windows_manager_constructor(system_t *system)
{
    system->type = S_WINDOW_MANAGER;
    system->run = &system_windows_manager;
    system->active = true;
    return 0;
}

int system_windows_manager(void *ptr)
{
    return 0;
}
