/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** vector
*/

#include "component.h"
#include <stdlib.h>

component_t *create_position(sfVector2f pos)
{
    component_t *component = malloc(sizeof(component_t));
    sfVector2f *position = malloc(sizeof(sfVector2f));

    if (!component || !position)
        return NULL;
    component->type = POSITION;
    component->data = NULL;
    position->x = pos.x;
    position->y = pos.y;
    component->data = (void *)position;
    return component;
}

void set_position(component_t *component, const sfVector2f pos)
{
    sfVector2f *position = component->data;

    position->x = pos.x;
    position->y = pos.y;
}

sfVector2f *get_position(const component_t *component)
{
    return (sfVector2f *)component->data;
}
