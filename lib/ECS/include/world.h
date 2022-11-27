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

typedef struct world_s {
    linked_list_t *system_list;
    linked_list_t *resource_list;
    linked_list_t *entity_list;
} world_t;

bool contain_system_by_type(world_t *world, unsigned int type);

bool contain_system(world_t *world, system_t *system);

int add_system(world_t *world, system_t *system);

void run_systems(world_t *world);

resource_t *get_resource_by_type(world_t *world, unsigned int type);

world_t *create_world(void);

int add_resource(world_t *world, resource_t *resource);

#endif /* !WORLD_H_ */
