/*
 * Filename: world_initializer.c
 * Path: our_rpg\sources\System
 * Created Date: Sunday, January 22nd 2023, 1:13:50 am
 * Author: osvegn
 * 
 * Copyright (c) 2023 Your Company
 */

#include "world.h"
#include "systems.h"

int world_initializer_constructor(system_t *system)
{
    system->type = WORLD_INITIALIZER;
    system->run = &world_initializer;
    system->active = true;
    return 0;
}

static void entity_initializer(world_t *world)
{

}

static void system_initializer(world_t *world)
{
    system_t system;
    vector_t *systems = &world->system_list;
    int (*constructors[])(system_t *) = {
        0
    };

    for (unsigned int i = 0; constructors[i]; i++) {
        constructors[i](&system);
        systems->emplace_back(systems, &system);
    }
    for (unsigned int i = 0; i < systems->size(systems); i++) {
        if (((system_t *)systems->at(systems, i))->type == WORLD_INITIALIZER) {
            systems->erase(systems, i);
            break;
        }
    }
}

static void resource_initializer(world_t *world)
{

}

int world_initializer(void *ptr)
{
    world_t *world = ptr;

    entity_initializer(world);
    system_initializer(world);
    resource_initializer(world);
    return 0;
}