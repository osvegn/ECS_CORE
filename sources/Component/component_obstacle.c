/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/Component/obstacle.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/Component
 * Created Date: Friday, March 17th 2023, 9:43:47 am
 * Author: Thomas
 * 
 * Copyright (c) 2023 Your Company
 */

#include "components.h"

int component_obstacle_constructor(component_t *component, void *data)
{
    component->type = C_OBSTACLE;
    component->data = 0;
    return 0;
}
