/*
 * Filename: sources/Component/gravitable.c
 * Path: sources/Component
 * Created Date: Monday, March 13th 2023, 4:56:52 pm
 * Author: Thomas
 *
 * Copyright (c) 2023 Your Company
 */

#include "components.h"

int component_gravitable_constructor(component_t *component, void *data)
{
    component->type = C_GRAVITABLE;
    component->data = 0;
    return 0;
}
