/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/Component/gravitable.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/Component
 * Created Date: Monday, March 13th 2023, 4:56:52 pm
 * Author: Thomas
 * 
 * Copyright (c) 2023 Your Company
 */

#include "components.h"

int component_gravitable_constructor(component_t *component)
{
    component->type = C_GRAVITABLE;
    component->data = 0;
    return 0;
}
