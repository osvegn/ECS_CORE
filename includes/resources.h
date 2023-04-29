/*
 * Filename: /home/osvegn/Documents/Repositories/ecs_core/includes/resources.h
 * Path: /home/osvegn/Documents/Repositories/ecs_core/includes
 * Created Date: Saturday, April 29th 2023, 7:08:18 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 Your Company
 */

#ifndef RESOURCES_H_
#define RESOURCES_H_

#include "resource.h"

typedef enum resource_type_e {
    R_UNDEFINED,
    R_LIBRARY_NAME,
    R_MAX_VALUE
} resource_type_t;

int resource_library_name_constructor(resource_t *resource, void *data);
int resource_library_name_destructor(resource_t *resource);

#endif