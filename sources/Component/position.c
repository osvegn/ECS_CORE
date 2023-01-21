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

int position_constructor(component_t *component, vector2i_t pos)
{
    vector2i_t *position = malloc(sizeof(vector2i_t));

    if (!position)
        return -1;
    component->type = POSITION;
    position->x = pos.x;
    position->y = pos.y;
    component->data = (void *)position;
    return 0;
}

void position_destructor(component_t *component)
{
    free(component->data);
}

void position_set(component_t *component, const vector2i_t pos)
{
    vector2i_t *position = component->data;

    position->x = pos.x;
    position->y = pos.y;
}

vector2i_t *position_get(const component_t *component)
{
    return (vector2i_t *)component->data;
}
