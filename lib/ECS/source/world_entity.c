/*
** EPITECH PROJECT, 2022
** our_rpg [Codespaces]
** File description:
** world_entity
*/

#include "world.h"
#include "component.h"
#include <stdarg.h>

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

entity_t *get_entity_by_id(world_t *world, unsigned int id)
{
    entity_t entity;
    unsigned int index = 0;

    entity.id = id;
    index = find_entity(&world->entity_list, &entity);
    return world->entity_list.at(&world->entity_list, index);
}

int join_entities(world_t *world, vector_t *entities, unsigned int type, ...)
{
    va_list argptr;
    unsigned int component;
    bool first_element = true;

    vector_constructor(entities, sizeof(void *), 0);
    va_start(argptr, type);
    component = va_arg(argptr, unsigned int);
    while (component != 0) {
        if (first_element) {
            for (unsigned int i = 0; i < world->entity_list.size(&world->entity_list); i++) {
                if (contains_component(world->entity_list.at(&world->entity_list, i), (component_t){component, 0})) {
                    entities->emplace_back(entities, world->entity_list.at(&world->entity_list, i)); // to be tested
                }
            }
            first_element = false;
        } else {
            for (unsigned int i = 0; i < entities->size(entities); i++) {
                if (!contains_component(entities->at(entities, i), (component_t){component, 0})) {
                    entities->erase(entities, i);
                    i--;
                }
            }
            entities->shrink_to_fit(entities);
        }
        component = va_arg(argptr, unsigned int);
    }
    va_end(argptr);
    if (first_element)
        return -1;
    return entities->size(entities);
}
