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
    component_size_constructor(&component, (void *){&(ecs_vector2i_t){50, 50}});
    entity_add_component(entity, &component);
    component_position_constructor(&component, (void *){&(ecs_vector2i_t){200, -60}});
    entity_add_component(entity, &component);
    component_displayable_constructor(&component, 0);
    entity_add_component(entity, &component);
    component_controllable_constructor(&component, 0);
    entity_add_component(entity, &component);
    component_velocity_constructor(&component, (void *){&(ecs_vector2i_t){0, 0}});
    entity_add_component(entity, &component);
    component_gravitable_constructor(&component, 0);
    entity_add_component(entity, &component);
    component_jumpable_constructor(&component, 0);
    entity_add_component(entity, &component);
    component_collidable_constructor(&component, 0);
    entity_add_component(entity, &component);
    return 0;
}