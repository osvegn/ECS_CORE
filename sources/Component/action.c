/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/Component/action.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/Component
 * Created Date: Friday, March 10th 2023, 10:51:44 pm
 * Author: Thomas
 * 
 * Copyright (c) 2023 Your Company
 */

#include "components.h"

int action_constructor(component_t *component, void *data)
{
    component->type = ACTION;
    component->data = data;
    return 0;
}

void *action_get(const component_t *component)
{
    return component->data;
}

void action_set(component_t *component, void *data)
{
    component->data = data;
}
