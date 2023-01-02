/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** world
*/

#ifndef WORLD_H_
#define WORLD_H_

#include "vector.h"
#include "system.h"
#include "resource.h"
#include "entity.h"

/// @brief It's the structure of a world. A world contains a list of systems,
/// a list of resources, and a list of entities.
/// @warning This ECS architecture should have only one world. You must write
/// a program as much as possible coplient to this information.
typedef struct world_s {

    /// @brief The list of systems to be run by the world.
    vector_t system_list;

    /// @brief The list of resources contains in the world.
    vector_t resource_list;

    /// @brief The list of entities contains in the world.
    vector_t entity_list;
} world_t;

/// @brief It runs all systems which exists in the world.
/// @param world The world which contains all systems to be run.
/// It also contains all resources and entities that exists.
/// @return 0, or -1 if an error occurs.
int run_systems(world_t *world);

/// @brief It adds a system to the world
/// @param world The world to add the system to.
/// @param system The system to add to the world.
/// @return 0, or -1 if the system already exists.
int add_system(world_t *world, system_t system);

/// @brief It removes a system from the world
/// @param world The world to remove the system from.
/// @param system The system to remove.
/// @return 0, or -1 if the system isn't found.
int remove_system(world_t *world, system_t system);

/// @brief It adds a resource to the world's resource list
/// @param world The world object
/// @param resource The resource to add to the world.
/// @return 0, or -1 if the resource already exists.
int add_resource(world_t *world, resource_t resource);

/// @brief It removes a resource from the world's resource list
/// @param world The world that the resource is in.
/// @param resource The resource to be removed.
/// @return 0, or -1 if the resoure isn't found.
int remove_resource(world_t *world, resource_t resource);

/// @brief It adds an entity to the world
/// @param world The world to add the entity to.
/// @param entity The entity to add to the world.
/// @return 0, or -1 if the entity already exists.
int add_entity(world_t *world, entity_t entity);

/// @brief It removes an entity from the world
/// @param world The world that the entity is in.
/// @param entity The entity to remove from the world.
/// @return 0, or -1 if the entity isn't found.
int remove_entity(world_t *world, entity_t entity);

/// @brief It creates a new world by creating a new resource list, entity list, and system
/// list
/// @param world a pointer to the world_t struct
/// @return 0, or -1 on failure
int world_constructor(world_t *world);

/// @brief It calls the destructor of each of the three lists in the world
/// @param world The world to be destructed.
void world_destructor(world_t *world);

/// @brief It returns true if the entity is in the world, false otherwise
/// @param world The world that the entity is in.
/// @param entity The entity to check for.
/// @return A boolean value.
bool contains_entity(world_t *world, entity_t entity);

/// @brief It returns true if the resource is in the world's resource list
/// @param world The world that contains the resource.
/// @param resource The resource to check for.
/// @return A boolean value.
bool contains_resource(world_t *world, resource_t resource);

/// @brief It returns true if the world contains the system, false otherwise
/// @param world The world to add the system to.
/// @param system The system to check for.
/// @return A boolean value.
bool contains_system(world_t *world, system_t system);

#endif /* !WORLD_H_ */
