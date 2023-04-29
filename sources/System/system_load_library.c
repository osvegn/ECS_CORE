/*
 * Filename:
 * /home/osvegn/Documents/Repositories/ecs_core/sources/System/system_load_library.c
 * Path: /home/osvegn/Documents/Repositories/ecs_core/sources/System
 * Created Date: Saturday, April 29th 2023, 5:52:03 pm
 * Author: osvegn
 *
 * Copyright (c) 2023 Your Company
 */

#include "resources.h"
#include "systems.h"
#include "world.h"
#include "world_logger.h"
#include "world_resource.h"
#include "world_system.h"
#include <dlfcn.h>
#include <stdio.h>

int system_load_library_constructor(system_t *system)
{
    system->type = S_LOAD_LIBRARY;
    system->run = &system_load_library;
    system->active = true;
    return 0;
}

int system_load_library(void *ptr)
{
    world_t *world = ptr;
    resource_t *resource = world_get_resource_by_type(world, R_LIBRARY_NAME);
    void *handle = 0;
    int (*entry_point)(void) = 0;

    handle = dlopen(resource->data, RTLD_LAZY);
    if (!handle) {
        log_error("%s", dlerror());
        return -1;
    }
    entry_point = dlsym(handle, "entry_point");
    if (!entry_point) {
        log_error("%s", dlerror());
        return -1;
    }
    entry_point();
    dlclose(handle);
    for (unsigned int i = 0; i < world->system_list.size(&world->system_list);
         i++) {
        if ((system_t *) { world->system_list.at(&world->system_list, i) }
            -> type == S_LOAD_LIBRARY) {
            world->system_list.erase(&world->system_list, i);
            break;
        }
    }
    return 0;
}