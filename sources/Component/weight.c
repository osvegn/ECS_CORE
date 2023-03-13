/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/Component/weight.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/Component
 * Created Date: Monday, March 13th 2023, 4:51:45 pm
 * Author: Thomas
 *
 * Copyright (c) 2023 Your Company
 */

#include "components.h"

int weight_constructor(component_t *component, void *data)
{
    component->type = WEIGHT;
    component->data = data;
    return 0;
}

void *weight_get(const component_t *component)
{
    return component->data;
}

void weight_set(component_t *component, void *data)
{
    component->data = data;
}
