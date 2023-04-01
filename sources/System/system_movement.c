/*
 * Filename: /workspaces/our_rpg/sources/System/movement.c
 * Path: /workspaces/our_rpg/sources/System
 * Created Date: Sunday, January 15th 2023, 3:59:05 pm
 * Author: osvegn
 *
 * Copyright (c) 2023 our_rpg
 */

#include "world.h"
#include "world_entity.h"
#include "components.h"
#include "systems.h"

int system_movement_constructor(system_t *system)
{
    system->type = S_MOVEMENT;
    system->run = &system_movement;
    system->active = true;
    return 0;
}

static int check_collision(ecs_vector2i_t **components, entity_t *entity, vector_t collidable)
{
    for (unsigned int j = 0; j < collidable.size(&collidable); j++) {
        if (entity->id == (*(entity_t **)collidable.at(&collidable, j))->id)
            continue;
        entity_t *collider = *(entity_t **)collidable.at(&collidable, j);
        ecs_vector2i_t *collider_pos = entity_get_component(collider, C_POSITION)->data;
        ecs_vector2i_t *collider_size = entity_get_component(collider, C_SIZE)->data;
        ecs_vector2i_t *entity_size;
        if (entity_contains_component_by_type(entity, C_SIZE)) {
            entity_size = entity_get_component(entity, C_SIZE)->data;
        } else {
            entity_size = 0;
        }
        if (components[0]->y + components[1]->y + entity_size->y > collider_pos->y &&
            components[0]->y + components[1]->y < collider_pos->y + collider_size->y &&
            components[0]->x + entity_size->x > collider_pos->x &&
            components[0]->x < collider_pos->x + collider_size->x) {
            components[1]->y = 0;
        }
        if (components[0]->x + components[1]->x + entity_size->x > collider_pos->x &&
            components[0]->x + components[1]->x < collider_pos->x + collider_size->x &&
            components[0]->y + entity_size->y > collider_pos->y &&
            components[0]->y < collider_pos->y + collider_size->y) {
            components[1]->x = 0;
        }
    }
}

int system_movement(void *world)
{
    vector_t entities = {0};
    vector_t collidable = {0};
    entity_t *entity;
    ecs_vector2i_t *components[2];
    int rvalue = world_join_entities(world, &entities, 2, C_VELOCITY, C_POSITION);

    if (rvalue <= 0)
        return rvalue;
    rvalue = world_join_entities(world, &collidable, 3, C_COLLIDABLE, C_POSITION, C_SIZE);
    if (rvalue <= 0)
        return rvalue;
    for (unsigned int i = 0; i < entities.size(&entities); i++) {
        entity = *(entity_t **)entities.at(&entities, i);
        components[0] = entity_get_component(entity, C_POSITION)->data;
        components[1] = entity_get_component(entity, C_VELOCITY)->data;
        if (entity_contains_component_by_type(entity, C_COLLIDABLE)) {
            check_collision(components, entity, collidable);
        }
        components[0]->x += components[1]->x;
        components[0]->y += components[1]->y;
    }
    entities.destructor(&entities);
    collidable.destructor(&collidable);
    return 0;
}