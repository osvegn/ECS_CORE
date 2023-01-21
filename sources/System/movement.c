/*
 * Filename: /workspaces/our_rpg/sources/System/movement.c
 * Path: /workspaces/our_rpg/sources/System
 * Created Date: Sunday, January 15th 2023, 3:59:05 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#include "system.h"
#include "world.h"
#include "components.h"
#include "vector2i.h"
#include "systems.h"

int create_movement_system(system_t *system)
{
    system->type = MOVEMENT;
    system->run = &movement;
    system->active = true;
    return 0;
}

int movement(void *world)
{
    vector_t entities = {0};
    entity_t *entity;
    vector2i_t *components[2];
    int rvalue = world_join_entities(world, &entities, 2, VELOCITY, POSITION);


    if (rvalue <= 0)
        return rvalue;
    for (unsigned int i = 0; i < entities.size(&entities); i++) {
        entity = *(entity_t **)entities.at(&entities, i);
        components[0] = entity_get_component(entity, POSITION)->data;
        components[1] = entity_get_component(entity, VELOCITY)->data;
        components[0]->x += components[1]->x;
        components[0]->y += components[1]->y;
    }
    return 0;
}