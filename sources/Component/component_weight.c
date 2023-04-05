/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/Component/weight.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/Component
 * Created Date: Monday, March 13th 2023, 4:51:45 pm
 * Author: Thomas
 *
 * Copyright (c) 2023 Your Company
 */

#include "components.h"

int component_weight_constructor(component_t *component, void *data)
{
    component->type = C_WEIGHT;
    component->data = 0;
    return 0;
}

void *component_weight_get(const component_t *component)
{
    if (component->type != C_WEIGHT)
        return 0;
    return component->data;
}

void component_weight_set(component_t *component, void *data)
{
    if (component->type != C_WEIGHT)
        return;
    component->data = data;
}
