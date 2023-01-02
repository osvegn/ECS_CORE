/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** vector
*/

#include "component.h"
#include "components.h"
#include "vector2i.h"
#include <stdlib.h>

component_t *create_position(vector2i_t pos)
{
    component_t *component = malloc(sizeof(component_t));
    vector2i_t *position = malloc(sizeof(vector2i_t));

    if (!component || !position)
        return NULL;
    component->type = POSITION;
    position->x = pos.x;
    position->y = pos.y;
    component->data = (void *)position;
    return component;
}

void set_position(component_t *component, const vector2i_t pos)
{
    vector2i_t *position = component->data;

    position->x = pos.x;
    position->y = pos.y;
}

vector2i_t *get_position(const component_t *component)
{
    return (vector2i_t *)component->data;
}
