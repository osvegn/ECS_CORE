/*
** EPITECH PROJECT, 2022
** our_rpg [Codespaces]
** File description:
** world_resource
*/

#include "world.h"

/// @brief It finds the index of a resource in a resource list
/// @param resource_list The list of resources that we're going to be adding to.
/// @param resource The resource to find.
/// @return The index of the resource in the resource list, or list size if not found.
static unsigned int find_resource(vector_t *resource_list, resource_t *resource)
{
    for (unsigned int i = 0; i < resource_list->size(resource_list); i++) {
        if (resource->type == (*(resource_t *)(resource_list->at(resource_list, i))).type) {
            return i;
        }
    }
    return resource_list->size(resource_list);
}

/// @brief It finds the index of a resource type in a resource list.
/// @param resource_list The list of resources on which find the corresponding type.
/// @param type The type of resource to find.
/// @return The index of the resource type in the resource list, or list size if not found.
static unsigned int find_resource_by_type(vector_t *resource_list, unsigned int type)
{
    for (unsigned int i = 0; i < resource_list->size(resource_list); i++) {
        if (type == (*(resource_t *)(resource_list->at(resource_list, i))).type) {
            return i;
        }
    }
    return resource_list->size(resource_list);
}

int add_resource(world_t *world, resource_t resource)
{
    unsigned int index = find_resource(&world->resource_list, &resource);

    if (index < world->resource_list.size(&world->resource_list)) {
        return -1;
    }
    world->resource_list.emplace_back(&world->resource_list, &resource);
    return 0;
}

int remove_resource(world_t *world, resource_t resource)
{
    unsigned int index = find_resource(&world->resource_list, &resource);

    if (index < world->resource_list.size(&world->resource_list)) {
        world->resource_list.erase(&world->resource_list, index);
        return 0;
    }
    return -1;
}

int remove_resource_by_type(world_t *world, unsigned int type)
{
    unsigned int index = find_resource_by_type(&world->resource_list, type);

    if (index < world->resource_list.size(&world->resource_list)) {
        world->resource_list.erase(&world->resource_list, index);
        return 0;
    }
    return -1;
}

bool contains_resource(world_t *world, resource_t resource)
{
    unsigned int index = find_resource(&world->resource_list, &resource);

    if (index < world->resource_list.size(&world->resource_list)) {
        return true;
    }
    return false;
}

bool contains_resource_by_type(world_t *world, unsigned int type)
{
    unsigned int index = find_resource_by_type(&world->resource_list, type);

    if (index < world->resource_list.size(&world->resource_list)) {
        return true;
    }
    return false;
}

resource_t *get_resource(world_t *world, resource_t resource)
{
    unsigned int index = find_resource(&world->resource_list, &resource);

    if (index < world->resource_list.size(&world->resource_list)) {
        return world->resource_list.at(&world->resource_list, index);
    }
    return 0;
}

resource_t *get_resource_by_type(world_t *world, unsigned int type)
{
    unsigned int index = find_resource_by_type(&world->resource_list, type);

    if (index < world->resource_list.size(&world->resource_list)) {
        return world->resource_list.at(&world->resource_list, index);
    }
    return 0;
}
