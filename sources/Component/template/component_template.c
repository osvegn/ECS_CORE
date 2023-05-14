/*
 * Filename: /home/osvegn/Documents/Repositories/ecs_core/sources/Component/template/component_template.c
 * Path: /home/osvegn/Documents/Repositories/ecs_core/sources/Component/template
 * Created Date: Sunday, May 7th 2023, 1:44:19 am
 * Author: osvegn
 * 
 * Copyright (c) 2023 Your Company
 */

#include "components.h"
#include "json.h"
#include <stdlib.h>
#include <string.h>

/// @brief Constructor for the component.
/// @param component The component to be constructed.
/// @param data The data to be used to construct the component. It must be
/// a string containing a json object with a specific format.
/// @return 0 if the component was successfully constructed, -1 otherwise.
int component_template_constructor(component_t *component, void *data)
{
    component->data = malloc(sizeof(ecs_vector2i_t));
    if (!component->data)
        return -1;
    component->type = C_POSITION;
    component_template_set(component, data);
    return 0;
}

int component_template_set(component_t *component, void *data)
{
    json_object *json = json_tokener_parse((char *)data);
    ecs_vector2i_t exemple = {0, 0};

    if (!json || component->type != C_POSITION)
        return -1;
    /// Get the data from the json object and store it in the component.
    /// The data of the component must be allocated with malloc.
    /// The example below is for a component containing two integers.
    exemple.x = json_object_get_int(json_object_object_get(json, "x"));
    exemple.y = json_object_get_int(json_object_object_get(json, "y"));
    memcpy(component->data, &exemple, sizeof(ecs_vector2i_t));
}

void *component_template_get(const component_t *component)
{
    if (component->type != C_POSITION)
        return 0;
    return component->data;
}
