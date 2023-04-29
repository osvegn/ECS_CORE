/*
 * Filename: /home/osvegn/Documents/Repositories/ecs_core/sources/Resource/resource_library_name.c
 * Path: /home/osvegn/Documents/Repositories/ecs_core/sources/Resource
 * Created Date: Saturday, April 29th 2023, 7:02:19 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 Your Company
 */

#include "resources.h"

int resource_library_name_constructor(resource_t *resource, void *data)
{
    resource->type = R_LIBRARY_NAME;
    resource->destructor = &resource_library_name_destructor;
    resource->data = strdup((char *)data);
    return 0;
}

int resource_library_name_destructor(resource_t *resource)
{
    if (resource->data)
        free(resource->data);
    return 0;
}
