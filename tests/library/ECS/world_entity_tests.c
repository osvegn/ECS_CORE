/*
** EPITECH PROJECT, 2022
** our_rpg [Codespaces]
** File description:
** world_entity_tests
*/

#include <criterion/criterion.h>
#include "world.h"

Test(test, test)
{
    cr_assert_eq(1, 1);
}

Test(world_add_entity, world_add_entity)
{
    world_t world;
    entity_t entity;

    entity.id = 0;
    vector_constructor(&world.entity_list, sizeof(int), 0);
    add_entity(&world, entity);
    cr_assert_eq(world.entity_list.size(&world.entity_list), 1);
}
