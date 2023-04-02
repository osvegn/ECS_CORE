/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/Component/displayable.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/Component
 * Created Date: Sunday, February 12th 2023, 6:21:46 pm
 * Author: Thomas
 * 
 * Copyright (c) 2023 Your Company
 */

#include "components.h"

int component_displayable_constructor(component_t *component, void *data)
{
    component->type = C_DISPLAYABLE;
    component->data = data;
    return 0;
}
