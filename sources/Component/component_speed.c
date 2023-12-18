/*
 * Filename: component_speed.c
 * Path: sources/Component
 * Created Date: Sunday, September 17th 2023, 7:35:03 am
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#include "json.h"
#include "components.h"
#include "world_logger.h"
#include <stdlib.h>
#include <string.h>

static int component_is_speed(const component_t *component)
{
    if (component->type == C_SPEED)
        return 1;
    log_error("Component is not speed.");
    return 0;
}

int component_speed_constructor(component_t *component, void *data)
{
    int rvalue = 0;

    component->type = C_SPEED;
    component->data = malloc(sizeof(int));
    if (!component->data) {
        log_fatal("Could not allocate memory for speed component.");
        return -1;
    }
    if (!data) {
        data = &(int){5};
    }
    rvalue = component_speed_set(component, data);
    log_info("Speed component created.");
    return rvalue;
}

int component_speed_constructor_from_json(component_t *component, void *data)
{
    json_object *obj = json_tokener_parse(data);
    int speed = 0;

    speed = json_object_get_int(obj);
    return component_speed_constructor(component, &speed);
}

int component_speed_set(component_t *component, void *data)
{
    if (!component_is_speed(component) || !component->data || !data)
        return -1;
    memcpy(component->data, data, sizeof(int));
    return 0;
}

void *component_speed_get(const component_t *component)
{
    if (!component_is_speed(component))
        return 0;
    return component->data;
}
