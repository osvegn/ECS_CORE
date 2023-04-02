/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/Component/size.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/Component
 * Created Date: Thursday, March 9th 2023, 3:10:24 pm
 * Author: Thomas
 * 
 * Copyright (c) 2023 Your Company
 */

#include "components.h"
#include <stdlib.h>

int component_size_constructor(component_t *component, ecs_vector2i_t s)
{
    ecs_vector2i_t *size = malloc(sizeof(ecs_vector2i_t));

    if (!size)
        return -1;
    component->type = C_SIZE;
    size->x = s.x;
    size->y = s.y;
    component->data = (void *)size;
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
void component_size_set(component_t *component, const ecs_vector2i_t s)
{
    ecs_vector2i_t *size = component->data;

    if (component->type != C_SIZE)
        return;
    size->x = s.x;
    size->y = s.y;
}

void *component_size_get(const component_t *component, ecs_vector2i_t *s)
{
    if (component->type != C_SIZE)
        return 0;
    return (ecs_vector2i_t *)component->data;
}
