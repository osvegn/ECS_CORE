/*
 * Filename: sources/Component/collidable.c
 * Path: sources/Component
 * Created Date: Wednesday, March 15th 2023, 2:41:37 pm
 * Author: Thomas
 *
 * Copyright (c) 2023 Your Company
 */

#include "components.h"

int component_collidable_constructor(component_t *component, void *data)
{
    component->type = C_COLLIDABLE;
    component->data = 0;
    return 0;
}
