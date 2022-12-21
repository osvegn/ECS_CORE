/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** world
*/

#include "world.h"
#include <stddef.h>

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

int add_system(world_t *world, system_t system)
{
    for (unsigned int i = 0; i < world->system_list.size(&world->system_list); i++) {
        if (system.type == (*(system_t *)(world->system_list.at(&world->system_list, i))).type) {
            return -1;
        }
    }
    world->system_list.emplace_back(&world->system_list, &system);
    return 0;
}

int remove_system(world_t *world, system_t system)
{
    for (unsigned int i = 0; i < world->system_list.size(&world->system_list); i++) {
        if (system.type == (*(system_t *)(world->system_list.at(&world->system_list, i))).type) {
            world->system_list.erase(&world->system_list, i);
            return 0;
        }
    }
    return -1;
}

int add_resource(world_t *world, resource_t resource)
{
    for (unsigned int i = 0; i < world->resource_list.size(&world->resource_list); i++) {
        if (resource.type == (*(resource_t *)(world->resource_list.at(&world->resource_list, i))).type) {
            return -1;
        }
    }
    world->resource_list.emplace_back(&world->resource_list, &resource);
    return 0;
}

int remove_resource(world_t *world, resource_t resource)
{
    for (unsigned int i = 0; i < world->resource_list.size(&world->resource_list); i++) {
        if (resource.type == (*(resource_t *)(world->resource_list.at(&world->resource_list, i))).type) {
            world->resource_list.erase(&world->resource_list, i);
            return 0;
        }
    }
    return -1;
}

int add_entity(world_t *world, entity_t entity)
{
    for (unsigned int i = 0; i < world->entity_list.size(&world->entity_list); i++) {
        if (entity.id == (*(entity_t *)(world->entity_list.at(&world->entity_list, i))).id) {
            return -1;
        }
    }
    world->entity_list.emplace_back(&world->entity_list, &entity);
    return 0;
}

int remove_entity(world_t *world, entity_t entity)
{
    for (unsigned int i = 0; i < world->entity_list.size(&world->entity_list); i++) {
        if (entity.id == (*(entity_t *)(world->entity_list.at(&world->entity_list, i))).id) {
            world->entity_list.erase(&world->entity_list, i);
            return 0;
        }
    }
    return -1;
}
