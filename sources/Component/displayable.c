/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/Component/displayable.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/Component
 * Created Date: Sunday, February 12th 2023, 6:21:46 pm
 * Author: Thomas
 * 
 * Copyright (c) 2023 Your Company
 */

#include "components.h"

int displayable_constructor(component_t *component, const char *path)
{
    component->type = DISPLAYABLE;
    component->data = 0;
    return 0;
}
