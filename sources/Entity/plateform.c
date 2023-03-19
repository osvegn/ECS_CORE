/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/Entity/plateform.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/Entity
 * Created Date: Wednesday, March 15th 2023, 2:36:08 pm
 * Author: Thomas
 * 
 * Copyright (c) 2023 Your Company
 */

#include "world_entity.h"
#include "components.h"
#include "raylib.h"

int plateform_constructor(entity_t *entity)
{
    component_t component;
    int width = GetScreenWidth();
    int height = GetScreenHeight();

    entity_constructor(entity);
    component_size_constructor(&component, (vector2i_t){width / 2, 10});
    entity_add_component(entity, &component);
    component_position_constructor(&component, (vector2i_t){width / 4, height - 100});
    entity_add_component(entity, &component);
    component_displayable_constructor(&component);
    entity_add_component(entity, &component);
    component_collidable_constructor(&component);
    entity_add_component(entity, &component);
    return 0;
}
