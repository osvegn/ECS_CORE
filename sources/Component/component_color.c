/*
 * Filename: sources/Component/color.c
 * Path: sources/Component
 * Created Date: Friday, March 17th 2023, 9:27:54 am
 * Author: Thomas
 *
 * Copyright (c) 2023 Your Company
 */

#include <stdlib.h>
#include <string.h>
#include "components.h"
#include "json.h"
#include "world_logger.h"

/// @brief Check if component is color type.
/// @param component Component to check. Must be a valid component_t.
/// @return Return 1 if component is C_COLOR, 0 otherwise.
/// @note This function is static.
static int component_is_color(const component_t *component)
{
    if (component->type == C_COLOR)
        return 1;
    log_error("Component is not color.");
    return 0;
}

int component_color_constructor(component_t *component, void *data)
{
    int rvalue = 0;

    component->type = C_COLOR;
    component->data = malloc(sizeof(ecs_color_t));
    if (!component->data) {
        log_fatal("Could not allocate memory for color component.");
        return -1;
    }
    rvalue = component_set_color(component, data);
    log_info("Color component created.");
    return rvalue;
}

int component_set_color(component_t *component, void *data)
{
    ecs_color_t color = {0};
    json_object *json = json_tokener_parse((char *)data);

    if (!component_is_color(component) || !json)
        return -1;
    color.r = json_object_get_int(json_object_object_get(json, "r"));
    color.g = json_object_get_int(json_object_object_get(json, "g"));
    color.b = json_object_get_int(json_object_object_get(json, "b"));
    color.a = json_object_get_int(json_object_object_get(json, "a"));
    json_object_put(json);
    memcpy(component->data, data, sizeof(ecs_color_t));
    return 0;
}

void *component_get_color(const component_t *component)
{
    if (component->type != C_COLOR)
        return 0;
    return (ecs_color_t *)component->data;
}
