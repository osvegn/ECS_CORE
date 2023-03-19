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

int component_position_constructor(component_t *component, vector2i_t pos)
{
    vector2i_t *position = malloc(sizeof(vector2i_t));

    if (!position)
        return -1;
    component->type = C_POSITION;
    position->x = pos.x;
    position->y = pos.y;
    component->data = (void *)position;
    return 0;
}

void component_position_set(component_t *component, const vector2i_t pos)
{
    vector2i_t *position = component->data;

    if (!component->type == C_POSITION)
        return;
    position->x = pos.x;
    position->y = pos.y;
}

vector2i_t *component_position_get(const component_t *component)
{
    if (component->type != C_POSITION)
        return 0;
    return (vector2i_t *)component->data;
}
