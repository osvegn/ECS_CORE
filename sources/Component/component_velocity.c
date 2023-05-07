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
#include <stdlib.h>
#include <string.h>
#include "world_logger.h"

/// @brief Check if the component is a velocity component.
/// @param component The component to check.
/// @return 1 if the component is a velocity component, 0 otherwise.
static int component_is_velocity(const component_t *component)
{
    if (component->type == C_VELOCITY)
        return 1;
    log_error("Component is not velocity.");
    return 0;
}

/// @brief This function is used to construct a velocity component.
/// @param component The component to construct.
/// @param data The velocity to set. Use the format {"x": 0, "y": 0}.
/// @return 0 if the component was successfully constructed, -1 otherwise.
int component_velocity_constructor(component_t *component, void *data)
{
    component->type = C_VELOCITY;
    component->data = malloc(sizeof(ecs_vector2i_t));
    if (!component->data) {
        log_fatal("Could not allocate memory for velocity component.");
        return -1;
    }
    return component_velocity_set(component, data);
}

/// @brief This function is used to set the velocity of a velocity component.
/// @param component The component to set.
/// @param data The velocity to set. Use the format {"x": 0, "y": 0}.
/// @return 0 if the component was successfully set, -1 otherwise.
int component_velocity_set(component_t *component, void *data)
{
    ecs_vector2i_t velocity = {0};
    json_object *json = json_tokener_parse((char *)data);

    if (!component_is_velocity(component) || !json)
        return -1;
    velocity.x = json_object_get_int(json_object_object_get(json, "x"));
    velocity.y = json_object_get_int(json_object_object_get(json, "y"));
    json_object_put(json);
    memcpy(component->data, &velocity, sizeof(ecs_vector2i_t));
    return 0;
}

/// @brief This function is used to get the velocity of a velocity component.
/// @param component The component to get.
/// @return A pointer to the velocity of the component.
void *component_velocity_get(const component_t *component)
{
    if (component->type != C_VELOCITY)
        return 0;
    return component->data;
}
