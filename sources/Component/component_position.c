/*
 * Filename: sources/Component/position.c
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

/// @brief Check if a component is a position component.
/// @param component Component to check.
/// @return Return 1 if the component is a position component, 0 otherwise.
/// @note This function is static.
static int component_is_position(const component_t *component)
{
    if (component->type == C_POSITION)
        return 1;
    log_error("Component is not position.");
    return 0;
}

int component_position_constructor(component_t *component, void *data)
{
    int rvalue = 0;

    component->type = C_POSITION;
    component->data = malloc(sizeof(ecs_vector2i_t));
    if (!component->data) {
        log_fatal("Could not allocate memory for position component.");
        return -1;
    }
    if (!data) {
        data = &(ecs_vector2i_t){0, 0};
    }
    rvalue = component_position_set(component, data);
    log_info("Position component created.");
    return rvalue;
}

int component_position_constructor_from_json(component_t *component, void *data)
{
    json_object *obj = json_tokener_parse(data);
    ecs_vector2i_t v = {0};

    v.x = json_object_get_int(json_object_object_get(obj, "x"));
    v.y = json_object_get_int(json_object_object_get(obj, "y"));
    return component_position_constructor(component, &v);
}

int component_position_set(component_t *component, void *data)
{
    if (!component_is_position(component) || !component->data || !data)
        return -1;
    memcpy(component->data, data, sizeof(ecs_vector2i_t));
    return 0;
}

void *component_position_get(const component_t *component)
{
    if (!component_is_position(component))
        return 0;
    return component->data;
}
