/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** world
*/

#include "world.h"

int run_systems(world_t *world)
{
    system_t *system = NULL;
    linked_list_t *tmp = world->system_list;

    while (tmp->next) {
        system = tmp->data;
        if (system)
            system->run((void *)world);
        tmp = tmp->next;
    }
    return 0;
}

int add_system(world_t *world, system_t *system)
{
    return push_back_linked_list(world->system_list, system);
}


// TO BE FIX
int remove_system(world_t *world, system_t *system)
{
    (void *)system;
    return remove_linked_list(world->system_list, 0);
}

bool contain_system(world_t *world, system_t *system)
{
    linked_list_t *tmp = world->system_list;
    system_t *s = NULL;

    while (tmp->next) {
        s = tmp->data;
        if (s->type == system->type)
            return true;
        tmp = tmp->next;
    }
    return false;
}

bool contain_system_by_type(world_t *world, unsigned int type)
{
    linked_list_t *tmp = world->system_list;
    system_t *s = NULL;

    while (tmp->next) {
        s = tmp->data;
        if (s->type == type)
            return true;
        tmp = tmp->next;
    }
    return false;
}

int add_resource(world_t *world, resource_t *resource)
{
    return push_back_linked_list(world->resource_list, resource);
}

resource_t *get_resource_by_type(world_t *world, unsigned int type)
{
    linked_list_t *list = world->resource_list;
    resource_t *r = NULL;

    while (list && list->next) {
        r = list->data;
        if (r && r->type == type)
            return (r);
        list = list->next;
    }
    return NULL;
}

world_t *create_world(void)
{
    world_t *world = malloc(sizeof(world_t));

    if (!world)
        return NULL;
    world->resource_list = create_linked_list();
    world->system_list = create_linked_list();
    return world;
}