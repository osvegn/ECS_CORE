/*
 * Filename: /workspaces/our_rpg/sources/Component/position.c
 * Path: /workspaces/our_rpg/sources/Component
 * Created Date: Sunday, January 15th 2023, 3:59:05 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#include "components.h"
#include <stdlib.h>

int component_position_constructor(component_t *component, void *data)
{
    component->data = malloc(sizeof(ecs_vector2i_t));
    if (!component->data)
        return -1;
    component->type = C_POSITION;
    memcpy(component->data, data, sizeof(ecs_vector2i_t));
    return 0;
}

void component_position_set(component_t *component, void *data)
{
    ecs_vector2i_t *position = component->data;

    if (!component->type == C_POSITION)
        return;
    memcpy(component->data, data, sizeof(ecs_vector2i_t));
}

void *component_position_get(const component_t *component)
{
    if (component->type != C_POSITION)
        return 0;
    return component->data;
}
