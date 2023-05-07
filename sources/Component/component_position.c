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

static int component_is_position(const component_t *component)
{
    if (component->type == C_POSITION)
        return 1;
    log_error("Component is not position.");
    return 0;
}
int component_position_constructor(component_t *component, void *data)
{
    component->type = C_POSITION;
    component->data = malloc(sizeof(ecs_vector2i_t));
    if (!component->data) {
        log_fatal("Could not allocate memory for position component.");
        return -1;
    }
    return component_position_set(component, data);
}

int component_position_set(component_t *component, void *data)
{
    ecs_vector2i_t position = {0};
    json_object *json = json_tokener_parse((char *)data);

    if (!component_is_position(component) || !json)
        return -1;
    position.x = json_object_get_int(json_object_object_get(json, "x"));
    position.y = json_object_get_int(json_object_object_get(json, "y"));
    json_object_put(json);
    memcpy(component->data, &position, sizeof(ecs_vector2i_t));
    return 0;
}

void *component_position_get(const component_t *component)
{
    if (!component_is_position(component))
        return 0;
    return component->data;
}
