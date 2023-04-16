/*
 * Filename: sources/Component/clickable.c
 * Path: sources/Component
 * Created Date: Friday, March 10th 2023, 10:47:44 pm
 * Author: Thomas
 *
 * Copyright (c) 2023 Your Company
 */

#include "components.h"

int component_clickable_constructor(component_t *component, void *data)
{
    component->type = C_CLICKABLE;
    component->data = 0;
    return 0;
}
