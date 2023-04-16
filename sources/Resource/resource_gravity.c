/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/Resource/gravity.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/Resource
 * Created Date: Monday, March 13th 2023, 5:08:12 pm
 * Author: Thomas
 * 
 * Copyright (c) 2023 Your Company
 */

#include "resources.h"
#include <stdlib.h>

int resource_gravity_constructor(resource_t *resource, void *data)
{
    resource->type = R_GRAVITY;
    resource->data = (void *)atoi((char *)data);
    resource->destructor = &resource_gravity_destructor;
    return 0;
}

void *resource_gravity_get(const resource_t *resource)
{
    if (resource->type != R_GRAVITY)
        return 0;
    return resource->data;
}

void resource_gravity_set(resource_t *resource, void *data)
{
    if (resource->type != R_GRAVITY)
        return;
    resource->data = data;
}

int resource_gravity_destructor(resource_t *resource)
{
    return 0;
}
