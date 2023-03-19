/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/Component/color.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/Component
 * Created Date: Friday, March 17th 2023, 9:27:54 am
 * Author: Thomas
 * 
 * Copyright (c) 2023 Your Company
 */

#include "components.h"
#include "raylib.h"

int color_constructor(component_t *component, Color color)
{
    component->type = COLOR;
    component->data = malloc(sizeof(Color));
    if (!component->data)
        return 84;
    *(Color *)component->data = color;
    return 0;
}

Color *get_color(component_t *component, Color *color)
{
    if (component->type != COLOR)
        return 0;
    return (Color *)component->data;
}

int set_color(component_t *component, Color color)
{
    if (component->type != COLOR)
        return 84;
    *(Color *)component->data = color;
    return 0;
}