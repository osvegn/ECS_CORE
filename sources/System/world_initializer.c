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
#include "resources.h"

int world_initializer_constructor(system_t *system)
{
    system->type = WORLD_INITIALIZER;
    system->run = &world_initializer;
    system->active = true;
    return 0;
}

static void entity_initializer(world_t *world)
{
    entity_t entity;
    vector_t *entities = &world->entity_list;

    rectangle_constructor(&entity);
    entities->emplace_back(entities, &entity);
}

static void system_initializer(world_t *world)
{
    system_t system;
    vector_t *systems = &world->system_list;
    int (*constructors[])(system_t *) = {
        &display_constructor,
        &windows_manager_constructor,
        &movement_constructor,
        &move_controllable_constructor,
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
    resource_t resource;
    vector_t *resources = &world->resource_list;
    int (*constructors[])(resource_t *) = {
        &window_constructor,
        0
    };

    for (unsigned int i = 0; constructors[i]; i++) {
        constructors[i](&resource);
        resources->emplace_back(resources, &resource);
    }
}

int world_initializer(void *ptr)
{
    world_t *world = ptr;

    entity_initializer(world);
    system_initializer(world);
    resource_initializer(world);
    return 0;
}