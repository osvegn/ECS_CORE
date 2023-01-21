/*
** EPITECH PROJECT, 2023
** our_rpg [Codespaces]
** File description:
** velocity
*/

#include "component.h"
#include "components.h"
#include "vector2i.h"
#include <stdlib.h>

int create_velocity(component_t *component, vector2i_t vel)
{
    vector2i_t *velocity = malloc(sizeof(vector2i_t));

    if (!velocity)
        return -1;
    component->type = VELOCITY;
    velocity->x = vel.x;
    velocity->y = vel.y;
    component->data = (void *)velocity;
    return 0;
}

void set_velocity(component_t *component, const vector2i_t vel)
{
    vector2i_t *velocity = component->data;

    velocity->x = vel.x;
    velocity->y = vel.y;
}

vector2i_t *get_velocity(const component_t *component)
{
    return (vector2i_t *)component->data;
}
