/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/Component/clickable.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/Component
 * Created Date: Friday, March 10th 2023, 10:47:44 pm
 * Author: Thomas
 * 
 * Copyright (c) 2023 Your Company
 */

#include "components.h"

int clickable_constructor(component_t *component)
{
    component->type = CLICKABLE;
    component->data = 0;
    return 0;
}
