/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/Entity/rectangle.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/Entity
 * Created Date: Thursday, March 9th 2023, 3:12:59 pm
 * Author: Thomas
 * 
 * Copyright (c) 2023 Your Company
 */

#include "world_entity.h"
#include "components.h"

int player_constructor(entity_t *entity)
{
    component_t component;

    entity_constructor(entity);
    size_constructor(&component, (vector2i_t){50, 50});
    entity_add_component(entity, &component);
    position_constructor(&component, (vector2i_t){500, 200});
    entity_add_component(entity, &component);
    displayable_constructor(&component);
    entity_add_component(entity, &component);
    controllable_constructor(&component);
    entity_add_component(entity, &component);
    velocity_constructor(&component, (vector2i_t){0, 0});
    entity_add_component(entity, &component);
    gravitable_constructor(&component);
    entity_add_component(entity, &component);
    jumpable_constructor(&component);
    entity_add_component(entity, &component);
    collidable_constructor(&component);
    entity_add_component(entity, &component);
    return 0;
}