/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/Component/clicked.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/Component
 * Created Date: Friday, March 10th 2023, 10:50:06 pm
 * Author: Thomas
 * 
 * Copyright (c) 2023 Your Company
 */

#include "components.h"

int clicked_constructor(component_t *component)
{
    component->type = CLICKED;
    component->data = 0;
    return 0;
}