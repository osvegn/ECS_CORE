/*
 * Filename: component_clickable.c
 * Path: sources/Component
 * Created Date: Friday, September 29th 2023, 12:52:35 am
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#include "components.h"

int component_clickable_constructor(component_t *component, void *data)
{
    component->type = C_CLICKABLE;
    component->data = 0;
    return 0;
}
