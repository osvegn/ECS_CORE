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

int component_velocity_constructor(component_t *component, vector2i_t vel)
{
    vector2i_t *velocity = malloc(sizeof(vector2i_t));

    if (!velocity)
        return -1;
    component->type = C_VELOCITY;
    velocity->x = vel.x;
    velocity->y = vel.y;
    component->data = (void *)velocity;
    return 0;
}

void component_velocity_set(component_t *component, const vector2i_t vel)
{
    vector2i_t *velocity = component->data;

    if (!component->type != C_VELOCITY)
        return;
    velocity->x = vel.x;
    velocity->y = vel.y;
}

vector2i_t *component_velocity_get(const component_t *component)
{
    if (component->type != C_VELOCITY)
        return 0;
    return (vector2i_t *)component->data;
}
