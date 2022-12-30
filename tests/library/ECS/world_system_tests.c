/*
** EPITECH PROJECT, 2022
** our_rpg [Codespaces]
** File description:
** world_system_tests
*/

#include <criterion/criterion.h>
#include "world.h"

Test(world_add_system, world_add_system)
{
    world_t world;
    system_t system;

    system.type = 0;
    vector_constructor(&world.system_list, sizeof(int), 0);
    cr_assert_eq(add_system(&world, system), 0);
    cr_assert_eq(world.system_list.size(&world.system_list), 1);
}

Test(world_add_system, world_add_system_failure)
{
    world_t world;
    system_t system;

    system.type = 0;
    vector_constructor(&world.system_list, sizeof(int), 0);
    cr_assert_eq(add_system(&world, system), 0);
    cr_assert_eq(add_system(&world, system), -1);
    cr_assert_eq(world.system_list.size(&world.system_list), 1);
}

Test(world_add_system, world_add_system_success_with_two_elements)
{
    world_t world;
    system_t system;

    system.type = 0;
    vector_constructor(&world.system_list, sizeof(int), 0);
    cr_assert_eq(add_system(&world, system), 0);
    system.type = 1;
    cr_assert_eq(add_system(&world, system), 0);
    cr_assert_eq(world.system_list.size(&world.system_list), 2);
}

Test(world_remove_system, world_remove_system)
{
    world_t world;
    system_t system;

    system.type = 0;
    vector_constructor(&world.system_list, sizeof(int), 0);
    cr_assert_eq(add_system(&world, system), 0);
    system.type = 1;
    cr_assert_eq(add_system(&world, system), 0);
    cr_assert_eq(remove_system(&world, system), 0);
    cr_assert_eq(world.system_list.size(&world.system_list), 1);
}

Test(world_remove_system, world_remove_system_failure)
{
    world_t world;
    system_t system;

    system.type = 0;
    vector_constructor(&world.system_list, sizeof(int), 0);
    cr_assert_eq(add_system(&world, system), 0);
    system.type = 1;
    cr_assert_eq(add_system(&world, system), 0);
    cr_assert_eq(remove_system(&world, system), 0);
    cr_assert_eq(remove_system(&world, system), -1);
    cr_assert_eq(world.system_list.size(&world.system_list), 1);
}