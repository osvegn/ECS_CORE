/*
 * Filename: system_reset_game_clock.c
 * Path: sources/System
 * Created Date: Saturday, September 16th 2023, 4:09:34 am
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#include "systems.h"
#include "vector.h"
#include "world.h"
#include "world_resource.h"
#ifdef __linux__
    #include <sys/time.h>
#endif
#include "resources.h"

int system_reset_game_clock_constructor(system_t *system)
{
    system->type = S_RESET_GAME_CLOCK;
    system->run = &system_reset_game_clock;
    system->active = true;
    return 0;
}

int system_reset_game_clock(void *world)
{
    #ifdef __linux__
        struct timeval new;
        resource_t *game_clock = world_get_resource_by_type(world, R_GAME_CLOCK);

        gettimeofday(&new, NULL);
        resource_game_clock_set(game_clock, &new);
    #endif
    return 0;
}
