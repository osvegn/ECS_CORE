/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/Component/jumpable.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/Component
 * Created Date: Wednesday, March 15th 2023, 2:24:05 pm
 * Author: Thomas
 * 
 * Copyright (c) 2023 Your Company
 */

#include "components.h"

int jumpable_constructor(component_t *component)
{
    component->type = JUMPABLE;
    component->data = 0;
    return 0;
}