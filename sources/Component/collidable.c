/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/Component/collidable.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/Component
 * Created Date: Wednesday, March 15th 2023, 2:41:37 pm
 * Author: Thomas
 * 
 * Copyright (c) 2023 Your Company
 */

#include "components.h"

int collidable_constructor(component_t *component)
{
    component->type = COLLIDABLE;
    component->data = 0;
    return 0;
}
