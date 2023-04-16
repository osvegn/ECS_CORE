/*
 * Filename: sources/Component/color.c
 * Path: sources/Component
 * Created Date: Friday, March 17th 2023, 9:27:54 am
 * Author: Thomas
 *
 * Copyright (c) 2023 Your Company
 */

#include "components.h"
#include "ecs_color.h"
#include <json-c/json.h>
#include <stdlib.h>
#include <string.h>

int component_color_constructor(component_t *component, void *data)
{
    json_object *json = json_tokener_parse((char *)data);

    if (!json) {
        return -1;
    }
    ecs_color_t color = {
        json_object_get_int(json_object_object_get(json, "r")),
        json_object_get_int(json_object_object_get(json, "g")),
        json_object_get_int(json_object_object_get(json, "b")),
        json_object_get_int(json_object_object_get(json, "a"))};
    json_object_put(json);
    component->type = C_COLOR;
    component->data = malloc(sizeof(ecs_color_t));
    if (!component->data)
        return 84;
    memcpy(component->data, &color, sizeof(ecs_color_t));
    return 0;
}

ecs_color_t *component_get_color(component_t *component)
{
    if (component->type != C_COLOR)
        return 0;
    return (ecs_color_t *)component->data;
}

int component_set_color(component_t *component, void *data)
{
    if (component->type != C_COLOR)
        return 84;
    memcpy(component->data, data, sizeof(ecs_color_t));
    return 0;
}