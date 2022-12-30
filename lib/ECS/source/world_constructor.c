/*
** EPITECH PROJECT, 2022
** our_rpg [Codespaces]
** File description:
** world_constructor
*/

#include "world.h"

int world_constructor(world_t *world)
{
    int rvalue = 0;

    rvalue = vector_constructor(&world->resource_list, sizeof(resource_t), 0);
    if (rvalue < 0)
        return -1;    
    rvalue = vector_constructor(&world->entity_list, sizeof(entity_t), 0);
    if (rvalue < 0)
        return -1;
    rvalue = vector_constructor(&world->system_list, sizeof(system_t), 0);
    if (rvalue < 0)
        return -1;
    return 0;
}

void world_destructor(world_t *world)
{
    world->entity_list.destructor(&world->entity_list);
    world->resource_list.destructor(&world->resource_list);
    world->system_list.destructor(&world->system_list);
}
