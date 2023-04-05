/*
 * Filename: /workspaces/our_rpg/sources/Component/velocity.c
 * Path: /workspaces/our_rpg/sources/Component
 * Created Date: Sunday, January 15th 2023, 3:59:05 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#include "components.h"
#include <stdlib.h>
#include <json-c/json.h>

int component_velocity_constructor(component_t *component, void *data)
{
    json_object *json = json_tokener_parse((char *)data);

    if (!json) {
        return -1;
    }
    ecs_vector2i_t velocity = {
        json_object_get_int(json_object_object_get(json, "x")),
        json_object_get_int(json_object_object_get(json, "y"))
    };

    component->data = malloc(sizeof(ecs_vector2i_t));
    if (!component->data)
        return -1;
    component->type = C_VELOCITY;
    memcpy(component->data, &velocity, sizeof(ecs_vector2i_t));
    return 0;
}

void component_velocity_set(component_t *component, void *data)
{
    if (!component->type != C_VELOCITY)
        return;
    memcpy(component->data, data, sizeof(ecs_vector2i_t));
}

void *component_velocity_get(const component_t *component)
{
    if (component->type != C_VELOCITY)
        return 0;
    return component->data;
}
