/*
 * Filename: sources/Component/velocity.c
 * Path: sources/Component
 * Created Date: Sunday, January 15th 2023, 3:59:05 pm
 * Author: osvegn
 *
 * Copyright (c) 2023 our_rpg
 */

#include "components.h"
#include "json.h"
#include "world_logger.h"
#include <stdlib.h>
#include <string.h>

/// @brief Check if a component is a velocity component.
/// @param component Component to check. It must be a valid component.
/// @return Return 1 if the component is a velocity component, 0 otherwise.
static int component_is_velocity(const component_t *component)
{
    if (component->type == C_VELOCITY)
        return 1;
    log_error("Component is not velocity.");
    return 0;
}

int component_velocity_constructor(component_t *component, void *data)
{
    int rvalue = 0;

    component->type = C_VELOCITY;
    component->data = malloc(sizeof(ecs_vector2i_t));
    if (!component->data) {
        log_fatal("Could not allocate memory for velocity component.");
        return -1;
    }
    if (!data) {
        data = &(ecs_vector2i_t){0, 0};
    }
    rvalue = component_velocity_set(component, data);
    log_info("Velocity component created.");
    return rvalue;
}

int component_velocity_set(component_t *component, void *data)
{
    if (!component_is_velocity(component) || !component->data || !data)
        return -1;
    memcpy(component->data, data, sizeof(ecs_vector2i_t));
    return 0;
}

void *component_velocity_get(const component_t *component)
{
    if (component->type != C_VELOCITY)
        return 0;
    return component->data;
}
