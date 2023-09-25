/*
 * Filename: system_move_controllable.c
 * Path: sources/System
 * Created Date: Saturday, September 16th 2023, 4:09:34 am
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#include "systems.h"
#include "raylib.h"
#include "vector.h"
#include "world.h"
#include "world_entity.h"
#include "components.h"

int system_move_controllable_constructor(system_t *system)
{
    system->type = S_MOVE_CONTROLLABLE;
    system->run = &system_move_controllable;
    system->active = true;
    return 0;
}

static int system_move_controllable(void *world)
{
    vector_t entities = {0};
    int rvalue = world_join_entities(world, &entities, 3, C_CONTROLLABLE, C_VELOCITY, C_SPEED);
    ecs_vector2i_t movement = {0};
    ecs_vector2i_t offset = {0};
    entity_t *e = 0;
    component_t *c_speed = 0;
    component_t *c_velocity = 0;

    if (rvalue <= 0)
        return 0;
    if (IsKeyDown(KEY_A))
        offset.x = -1;
    if (IsKeyDown(KEY_D))
        offset.x = 1;
    if (IsKeyDown(KEY_W))
        offset.y = -1;
    if (IsKeyDown(KEY_S))
        offset.y = 1;
    for (unsigned int i = 0; i < entities.size(&entities); i++) {
        e = *(entity_t **)entities.at(&entities, i);
        c_speed = entity_get_component(e, C_SPEED);
        c_velocity = entity_get_component(e, C_VELOCITY);
        movement.x = offset.x * *(int *){c_speed->data};
        movement.y = offset.y * *(int *){c_speed->data};
        component_velocity_set(c_velocity, &movement);
    }
    return 0;
}
