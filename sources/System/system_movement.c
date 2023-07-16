/*
 * Filename: /home/osvegn/Documents/Repositories/ecs_core/sources/System/system_movement.c
 * Path: /home/osvegn/Documents/Repositories/ecs_core/sources/System
 * Created Date: Sunday, May 14th 2023, 4:30:11 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 Your Company
 */

#include "world.h"
#include "systems.h"
#include "components.h"
#include <stdlib.h>
#include <stdio.h>

#include "world_logger.h"

int system_movement_constructor(system_t *system)
{
    system->type = S_MOVEMENT;
    system->run = &system_movement;
    system->active = true;
    log_info("Movement system created.");
    return 0;
}

int system_movement(void *ptr)
{
    vector_t entities = {0};
    entity_t *entity = 0;
    int rvalue = world_join_entities(ptr, &entities, 2, C_POSITION, C_VELOCITY);
    component_t *c_position = 0;
    component_t *c_velocity = 0;
    ecs_vector2i_t velocity = {0};
    ecs_vector2i_t position = {0};
    char *buffer = 0;

    if (rvalue < 0)
        return rvalue;
    for (unsigned int i = 0; i < entities.size(&entities); i++) {
        entity = *(entity_t **)entities.at(&entities, i);
        c_position = entity_get_component(entity, C_POSITION);
        c_velocity = entity_get_component(entity, C_VELOCITY);
        velocity = *(ecs_vector2i_t *)c_velocity->data;
        position = *(ecs_vector2i_t *)c_position->data;
        position.x += velocity.x;
        position.y += velocity.y;
        sprintf(&buffer, "{\"x\":%i, \"y\":%i}", position.x, position.y);
        component_position_set(c_position, &buffer);
    }
    entities.destructor(&entities);
    return 0;
}
