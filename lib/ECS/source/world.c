/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** world
*/

#include "world.h"

int run_systems(world_t *world)
{
    vector_t *ptr = &world->system_list;
    system_t *system = NULL;
    unsigned int size = ptr->size(ptr);

    for (unsigned int i = 0; i < size; i++) {
        system = ptr->at(ptr, i);
        if (system)
            system->run((void *)world);
    }
    return 0;
}
