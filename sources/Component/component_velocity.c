/*
 * Filename: /workspaces/our_rpg/sources/Component/velocity.c
 * Path: /workspaces/our_rpg/sources/Component
 * Created Date: Sunday, January 15th 2023, 3:59:05 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#include "components.h"
#include <stdlib.h>

int component_velocity_constructor(component_t *component, ecs_vector2i_t vel)
{
    ecs_vector2i_t *velocity = malloc(sizeof(ecs_vector2i_t));

    if (!velocity)
        return -1;
    component->type = C_VELOCITY;
    velocity->x = vel.x;
    velocity->y = vel.y;
    component->data = (void *)velocity;
    return 0;
}

void component_velocity_set(component_t *component, const ecs_vector2i_t vel)
{
    ecs_vector2i_t *velocity = component->data;

    if (!component->type != C_VELOCITY)
        return;
    velocity->x = vel.x;
    velocity->y = vel.y;
}

ecs_vector2i_t *component_velocity_get(const component_t *component)
{
    if (component->type != C_VELOCITY)
        return 0;
    return (ecs_vector2i_t *)component->data;
}
