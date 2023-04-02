/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/Component/controllable.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/Component
 * Created Date: Friday, March 10th 2023, 11:07:40 pm
 * Author: Thomas
 * 
 * Copyright (c) 2023 Your Company
 */

#include "components.h"

int component_controllable_constructor(component_t *component, void *data)
{
    component->type = C_CONTROLLABLE;
    component->data = data;
    return 0;
}
