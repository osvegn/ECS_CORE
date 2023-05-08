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
    rvalue = component_size_set(component, data);
    log_info("Size component created.");
    return rvalue;
}

int component_size_set(component_t *component, void *data)
{
    ecs_vector2i_t size = {0};
    json_object *json = json_tokener_parse((char *)data);

    if (!component_is_size(component) || !json)
        return -1;
    size.x = json_object_get_int(json_object_object_get(json, "x"));
    size.y = json_object_get_int(json_object_object_get(json, "y"));
    json_object_put(json);
    memcpy(component->data, &size, sizeof(ecs_vector2i_t));
    return 0;
}

void *component_size_get(const component_t *component)
{
    if (!component_is_size(component))
        return 0;
    return component->data;
}
