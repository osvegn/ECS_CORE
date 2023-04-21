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
#include <stdlib.h>
#include <string.h>

int component_size_constructor(component_t *component, void *data)
{
    json_object *json = json_tokener_parse((char *)data);

    if (!json) {
        return -1;
    }
    ecs_vector2i_t size = {
        json_object_get_int(json_object_object_get(json, "width")),
        json_object_get_int(json_object_object_get(json, "height"))};
    json_object_put(json);
    component->data = malloc(sizeof(ecs_vector2i_t));
    if (!component->data)
        return -1;
    component->type = C_SIZE;
    memcpy(component->data, &size, sizeof(ecs_vector2i_t));
    return 0;
}

/// @brief This function set the size of the component
/// @param component The component to set the size
/// @param s The new size of the component
/// @details **Example:**
/// @code
/// int main(void) {
///     component_t component;
///     ecs_vector2i_t size = {10, 10};
///
///     size_constructor(&component, size);
///     size_set(&component, (ecs_vector2i_t){20, 20});
///     component_destroy(&component);
///     return 0;
/// }
/// @endcode
void component_size_set(component_t *component, void *data)
{
    if (component->type != C_SIZE)
        return;
    memcpy(component->data, data, sizeof(ecs_vector2i_t));
}

void *component_size_get(const component_t *component)
{
    if (component->type != C_SIZE)
        return 0;
    return component->data;
}
