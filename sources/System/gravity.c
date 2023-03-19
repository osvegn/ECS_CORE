/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/System/gravity.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/System
 * Created Date: Monday, March 13th 2023, 4:55:22 pm
 * Author: Thomas
 * 
 * Copyright (c) 2023 Your Company
 */

#include "world.h"
#include "world_entity.h"
#include "world_resource.h"
#include "systems.h"
#include "components.h"
#include "resources.h"

int gravity_constructor(system_t *system)
{
    system->type = GRAVITY_SYSTEM;
    system->run = &gravity;
    system->active = true;
    return 0;
}

int gravity(void *ptr)
{
    vector_t entities = {0};
    entity_t *entity = 0;
    int rvalue = world_join_entities(ptr, &entities, 2, C_GRAVITABLE, C_VELOCITY);
    resource_t *resource = world_get_resource_by_type(ptr, R_GRAVITY);
    vector2i_t *velocity = 0;

    if (rvalue <= 0)
        return rvalue;
    if (resource == 0)
        return -1;
    for (unsigned int i = 0; i < entities.size(&entities); i++) {
        entity = *(entity_t **)entities.at(&entities, i);
        velocity = (vector2i_t *)entity_get_component(entity, C_VELOCITY)->data;
        velocity->y += (int)resource->data;
    }
    return 0;
}
