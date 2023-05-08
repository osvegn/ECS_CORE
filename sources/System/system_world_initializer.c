/*
 * Filename: world_initializer.c
 * Path: our_rpg\sources\System
 * Created Date: Sunday, January 22nd 2023, 1:13:50 am
 * Author: osvegn
 *
 * Copyright (c) 2023 Your Company
 */

#include "resources.h"
#include "systems.h"
#include "world.h"

int system_world_initializer_constructor(system_t *system)
{
    system->type = S_WORLD_INITIALIZER;
    system->run = &system_world_initializer;
    system->active = true;
    return 0;
}

static void system_initializer(world_t *world)
{
    system_t system;
    vector_t *systems = &world->system_list;
    int (*constructors[])(system_t *) = {&system_load_scene_constructor, 0};

    for (unsigned int i = 0; constructors[i]; i++) {
        constructors[i](&system);
        systems->emplace_back(systems, &system);
    }
    for (unsigned int i = 0; i < systems->size(systems); i++) {
        if (((system_t *)systems->at(systems, i))->type ==
            S_WORLD_INITIALIZER) {
            systems->erase(systems, i);
            break;
        }
    }
}

static void resource_initializer(world_t *world)
{
    resource_t resource;
    vector_t *resources = &world->resource_list;

    void *data[] = {"{\"filename\":\"config/basic_scene.json\"}", 0};
    int (*constructors[])(resource_t *,
                          void *) = {&resource_scene_filename_constructor, 0};
    for (unsigned int i = 0; constructors[i]; i++) {
        constructors[i](&resource, data[i]);
        resources->emplace_back(resources, &resource);
    }
}

int system_world_initializer(void *ptr)
{
    world_t *world = ptr;

    resource_initializer(world);
    system_initializer(world);
    return 0;
}
