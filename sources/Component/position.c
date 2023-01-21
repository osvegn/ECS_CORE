/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** vector
*/

#include "component.h"
#include "components.h"
#include <stdlib.h>

int create_position(component_t *component, vector2i_t pos)
{
    vector2i_t *position = malloc(sizeof(vector2i_t));

    if (!position)
        return -1;
    component->type = POSITION;
    position->x = pos.x;
    position->y = pos.y;
    component->data = (void *)position;
    return 0;
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
