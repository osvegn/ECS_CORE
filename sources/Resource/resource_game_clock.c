/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/Resource/resource_scene_filename.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/Resource
 * Created Date: Tuesday, March 21st 2023, 9:45:13 am
 * Author: Thomas
 * 
 * Copyright (c) 2023 our_rpg
 */

#include "resources.h"
#include <stdlib.h>
#include <string.h>
#include "world_logger.h"
#ifdef __linux__
    #include <sys/time.h>
#endif

static int resource_is_game_clock(const resource_t *resource)
{
    if (resource->type == R_GAME_CLOCK)
        return 1;
    log_error("Resource is not game clock.");
    return 0;
}

int resource_game_clock_constructor(resource_t *resource, void *data)
{
    int rvalue = 0;
    resource->type = R_GAME_CLOCK;
    #ifdef __linux__
        struct timeval start;

        gettimeofday(&start, NULL);
        resource->data = malloc(sizeof(struct timeval));
        if (!resource->data) {
            return -1;
        }
        if (!data) {
            data = &start;
        }
    #endif
    resource->destructor = &resource_game_clock_destructor;
    rvalue = resource_game_clock_set(resource, data);
    log_info("game_clock resource created.");
    return rvalue;
}

int resource_game_clock_constructor_from_json(resource_t *resource, void *data)
{
    void *new_data = 0;

    return resource_game_clock_constructor(resource, new_data);
}

int resource_game_clock_destructor(resource_t *resource)
{
    if (resource->data)
        free(resource->data);
    log_info("game_clock resource destroyed.");
    return 0;
}

int resource_game_clock_set(resource_t *resource, void *data)
{
    if (!resource_is_game_clock(resource))
        return -1;
    #ifdef __linux__
        memcpy(resource->data, data, sizeof(struct timeval));
    #endif
    return 0;
}

void *resource_game_clock_get(const resource_t *resource)
{
    if (!resource_is_game_clock(resource))
        return 0;
    return resource->data;
}
