/*
 * Filename: sources/Component/action.c
 * Path: sources/Component
 * Created Date: Friday, March 10th 2023, 10:51:44 pm
 * Author: Thomas
 *
 * Copyright (c) 2023 Your Company
 */

#include "components.h"

int component_action_constructor(component_t *component, void *data)
{
    component->type = C_ACTION;
    component->data = 0;
    return 0;
}

void *component_action_get(const component_t *component)
{
    if (component->type != C_ACTION)
        return 0;
    return component->data;
}

void component_action_set(component_t *component, void *data)
{
    if (component->type != C_ACTION)
        return;
    component->data = data;
}
