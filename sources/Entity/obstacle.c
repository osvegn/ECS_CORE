/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/Entity/obstacle.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/Entity
 * Created Date: Friday, March 17th 2023, 9:12:35 am
 * Author: Thomas
 * 
 * Copyright (c) 2023 Your Company
 */

#include "world_entity.h"
#include "components.h"

int obstacle_constructor(entity_t *entity, ecs_vector2i_t pos)
{
    component_t component;

    entity_constructor(entity);
    component_size_constructor(&component, (ecs_vector2i_t){50, 50});
    entity_add_component(entity, &component);
    component_position_constructor(&component, pos);
    entity_add_component(entity, &component);
    component_displayable_constructor(&component);
    entity_add_component(entity, &component);
    component_collidable_constructor(&component);
    entity_add_component(entity, &component);
    component_obstacle_constructor(&component);
    entity_add_component(entity, &component);
    return 0;
}
