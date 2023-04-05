/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/System/system_reload_config.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/System
 * Created Date: Tuesday, March 21st 2023, 5:09:16 pm
 * Author: Thomas
 * 
 * Copyright (c) 2023 Your Company
 */

#include "world.h"
#include "world_system.h"
#include "system.h"
#include "systems.h"
#include "raylib.h"

int system_reload_config_constructor(system_t *system)
{
    system->run = system_reload_config_run;
    system->type = S_RELOAD_CONFIG;
    system->active = true;
    return 0;
}

int system_reload_config_run(void *ptr)
{
    world_t *world = ptr;
    system_t system = {0};

    if (IsKeyPressed(KEY_R)) {
        system_load_scene_constructor(&system);
        world_add_system(world, &system);
    }
    return 0;
}