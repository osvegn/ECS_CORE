/*
** EPITECH PROJECT, 2022
** our_rpg [Codespaces]
** File description:
** world_entity
*/

#include "world.h"

/// @brief It returns the index of the entity in the entity list if it exists, or the size of the entity list
/// if it doesn't
/// @param entity_list The list of entities to search through.
/// @param entity The entity to find.
/// @return The index of the entity in the entity list.
static unsigned int find_entity(vector_t *entity_list, entity_t *entity)
{
    for (unsigned int i = 0; i < entity_list->size(entity_list); i++) {
        if (entity->id == (*(entity_t *)(entity_list->at(entity_list, i))).id)
            return i;
    }
    return entity_list->size(entity_list);
}

int add_entity(world_t *world, entity_t entity)
{
    unsigned int index = find_entity(&world->entity_list, &entity);

    if (index < world->entity_list.size(&world->entity_list)) {
        return -1;
    }
    world->entity_list.emplace_back(&world->entity_list, &entity);
    return 0;
}

int remove_entity(world_t *world, entity_t entity)
{
    unsigned int index = find_entity(&world->entity_list, &entity);

    if (index < world->entity_list.size(&world->entity_list)) {
        world->entity_list.erase(&world->entity_list, index);
        return 0;
    }
    return -1;
}

bool contains_entity(world_t *world, entity_t entity)
{
    unsigned int index = find_entity(&world->entity_list, &entity);

    if (index < world->entity_list.size(&world->entity_list))
        return true;
    return false;
}
