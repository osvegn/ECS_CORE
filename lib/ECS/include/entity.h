/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** entity
*/

#ifndef ENTITY_H_
#define ENTITY_H_

#include "vector.h"
#include "component.h"

/// @brief It's the structure of an entity. An entity contains an id,
/// a name and a list of components.
/// Only systems can update an entity.
/// Entities are only store in the world.
typedef struct entity_s {

    /// @brief The id is used to differentiate two entities with the same name
    /// and the same component list.
    unsigned int id;

    /// @brief It stores a list of components.
    /// It describes what is the entity.
    vector_t components;
} entity_t;

bool contains_component(entity_t *entity, component_t component);
int entity_constructor(entity_t *entity);
int remove_component(entity_t *entity, component_t component);
int add_component(entity_t *entity, component_t component);

#endif /* !ENTITY_H_ */
