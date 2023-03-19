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

int movement_constructor(system_t *system)
{
    system->type = MOVEMENT;
    system->run = &movement;
    system->active = true;
    return 0;
}

static int check_collision(vector2i_t **components, entity_t *entity, vector_t collidable)
{
    for (unsigned int j = 0; j < collidable.size(&collidable); j++) {
        if (entity->id == (*(entity_t **)collidable.at(&collidable, j))->id)
            continue;
        entity_t *collider = *(entity_t **)collidable.at(&collidable, j);
        vector2i_t *collider_pos = entity_get_component(collider, POSITION)->data;
        vector2i_t *collider_size = entity_get_component(collider, SIZE)->data;
        vector2i_t *entity_size;
        if (entity_contains_component_by_type(entity, SIZE)) {
            entity_size = entity_get_component(entity, SIZE)->data;
        } else {
            entity_size = (vector2i_t *){1, 1};
        }
        if (components[0]->y + components[1]->y + entity_size->y > collider_pos->y &&
            components[0]->y + components[1]->y < collider_pos->y + collider_size->y &&
            components[0]->x + entity_size->x > collider_pos->x &&
            components[0]->x < collider_pos->x + collider_size->x
        ) {
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

int movement(void *world)
{
    vector_t entities = {0};
    vector_t collidable = {0};
    entity_t *entity;
    vector2i_t *components[2];
    int rvalue = world_join_entities(world, &entities, 2, VELOCITY, POSITION);

    if (rvalue <= 0)
        return rvalue;
    rvalue = world_join_entities(world, &collidable, 3, COLLIDABLE, POSITION, SIZE);
    if (rvalue <= 0)
        return rvalue;
    for (unsigned int i = 0; i < entities.size(&entities); i++) {
        entity = *(entity_t **)entities.at(&entities, i);
        components[0] = entity_get_component(entity, POSITION)->data;
        components[1] = entity_get_component(entity, VELOCITY)->data;
        if (entity_contains_component_by_type(entity, COLLIDABLE)) {
            check_collision(components, entity, collidable);
        }
        components[0]->x += components[1]->x;
        components[0]->y += components[1]->y;
    }
    return 0;
}