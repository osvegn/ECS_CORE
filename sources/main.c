/*
 * Filename: /workspaces/our_rpg/sources/main.c
 * Path: /workspaces/our_rpg/sources
 * Created Date: Saturday, January 21st 2023, 2:35:06 am
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#include "world.h"
#include "world_system.h"
#include "systems.h"
#include "world_logger.h"

int main(void)
{
    world_t world;
    system_t system;
    int rvalue = 0;

    set_world_log_level(WORLD_LOG_LEVEL_DEBUG);
    world_constructor(&world, 0);
    system_world_initializer_constructor(&system);
    world_add_system(&world, &system);
    while (!rvalue && world.system_list.size(&world.system_list)) {
        rvalue = world_run_systems(&world);
    }
    world_destructor(&world);
    return 0;
}