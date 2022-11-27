/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** world
*/

#ifndef WORLD_H_
#define WORLD_H_

#include "linked_list.h"
#include "system.h"
#include "resource.h"
#include "entity.h"

/// @brief It's the structure of a world. A world contains a list of systems,
/// a list of resources, and a list of entities.
/// @warning This ECS architecture should have only one world. You must write
/// a program as much as possible coplient to this information.
typedef struct world_s {

    /// @brief The list of systems to be run by the world.
    linked_list_t *system_list;

    /// @brief The list of resources contains in the world.
    linked_list_t *resource_list;

    /// @brief The list of entities contains in the world.
    linked_list_t *entity_list;
} world_t;

/// @brief It runs all systems which exists in the world.
/// @param world The world which contains all systems to be run.
/// It also contains all resources and entities that exists.
/// @return 0, or -1 if an error occurs.
int run_systems(world_t *world);

bool contain_system_by_type(world_t *world, unsigned int type);

bool contain_system(world_t *world, system_t *system);

int add_system(world_t *world, system_t *system);

resource_t *get_resource_by_type(world_t *world, unsigned int type);

world_t *create_world(void);

int add_resource(world_t *world, resource_t *resource);

#endif /* !WORLD_H_ */
