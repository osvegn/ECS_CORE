/*
 * Filename: sources/Component/size.c
 * Path: sources/Component
 * Created Date: Thursday, March 9th 2023, 3:10:24 pm
 * Author: Thomas
 *
 * Copyright (c) 2023 Your Company
 */

#include "components.h"
#include "json.h"
#include "world_logger.h"
#include <stdlib.h>
#include <string.h>

/// @brief Check if component is size type.
/// @param component Component to check.
/// @return Return 1 if component is C_SIZE, 0 otherwise.
static int component_is_size(const component_t *component)
{
    if (component->type == C_SIZE)
        return 1;
    log_error("Component is not size.");
    return 0;
}

int component_size_constructor(component_t *component, void *data)
{
    int rvalue = 0;

    component->type = C_SIZE;
    component->data = malloc(sizeof(ecs_vector2i_t));
    if (!component->data) {
        log_fatal("Could not allocate memory for size component.");
        return -1;
    }
    if (!data) {
        data = &(ecs_vector2i_t){0, 0};
    }
    rvalue = component_size_set(component, data);
    log_info("Size component created.");
    return rvalue;
}

int component_size_set(component_t *component, void *data)
{
    if (!component_is_size(component) || !component->data || !data)
        return -1;
    memcpy(component->data, data, sizeof(ecs_vector2i_t));
    return 0;
}

void *component_size_get(const component_t *component)
{
    if (!component_is_size(component))
        return 0;
    return component->data;
}
