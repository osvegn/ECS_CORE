/*
 * Filename: system_movement.c
 * Path: sources/System
 * Created Date: Sunday, September 17th 2023, 7:25:32 am
 * Author: osvegn
 * 
 * Copyright (c) 2023 Your Company
 */

#include "systems.h"
#include "vector.h"
#include "world_entity.h"
#include "components.h"

int system_movement_constructor(system_t *system)
{
    system->type = S_MOVEMENT;
    system->run = &system_movement;
    system->active = true;
    return 0;
}

static int system_movement(void *world)
{
    vector_t entities = {0};
    int rvalue = world_join_entities(world, &entities, 2, C_POSITION, C_VELOCITY);
    ecs_vector2i_t position = {0};
    entity_t *e = 0;
    component_t *c_position = 0;
    component_t *c_velocity = 0;

    if (rvalue <= 0)
        return 0;
    for (unsigned int i = 0; i < entities.size(&entities); i++) {
        e = *(entity_t **)entities.at(&entities, i);
        c_position = entity_get_component(e, C_POSITION);
        c_velocity = entity_get_component(e, C_VELOCITY);
        position.x = (ecs_vector2i_t *){c_position->data}->x + (ecs_vector2i_t *){c_velocity->data}->x;
        position.y = (ecs_vector2i_t *){c_position->data}->y + (ecs_vector2i_t *){c_velocity->data}->y;
        component_position_set(c_position, &position);
    }
    return 0;
}
