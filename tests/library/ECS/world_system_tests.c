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
    add_system(&world, system);
    cr_assert_eq(add_system(&world, system), -1);
    cr_assert_eq(world.system_list.size(&world.system_list), 1);
}

Test(world_add_system, world_add_system_success_with_two_elements)
{
    world_t world;
    system_t system;

    system.type = 0;
    vector_constructor(&world.system_list, sizeof(int), 0);
    add_system(&world, system);
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
    add_system(&world, system);
    system.type = 1;
    add_system(&world, system);
    cr_assert_eq(remove_system(&world, system), 0);
    cr_assert_eq(world.system_list.size(&world.system_list), 1);
}

Test(world_remove_system, world_remove_system_failure)
{
    world_t world;
    system_t system;

    system.type = 0;
    vector_constructor(&world.system_list, sizeof(int), 0);
    add_system(&world, system);
    system.type = 1;
    add_system(&world, system);
    remove_system(&world, system);
    cr_assert_eq(remove_system(&world, system), -1);
    cr_assert_eq(world.system_list.size(&world.system_list), 1);
}

Test(world_remove_system, world_remove_system_by_type)
{
    world_t world;
    system_t system;

    system.type = 0;
    vector_constructor(&world.system_list, sizeof(int), 0);
    add_system(&world, system);
    system.type = 1;
    add_system(&world, system);
    cr_assert_eq(remove_system_by_type(&world, 0), 0);
    cr_assert_eq(world.system_list.size(&world.system_list), 1);
}

Test(world_remove_system, world_remove_system_by_type_failure)
{
    world_t world;
    system_t system;

    system.type = 0;
    vector_constructor(&world.system_list, sizeof(int), 0);
    add_system(&world, system);
    system.type = 1;
    add_system(&world, system);
    remove_system_by_type(&world, 0);
    cr_assert_eq(remove_system_by_type(&world, 0), -1);
    cr_assert_eq(world.system_list.size(&world.system_list), 1);
}

Test(world_contains_system, world_contains_system_success)
{
    world_t world;
    system_t system;

    system.type = 0;
    world_constructor(&world);
    add_system(&world, system);
    cr_assert_eq(contains_system(&world, system), true);
}

Test(world_contains_system, world_contains_system_failure)
{
    world_t world;
    system_t system;

    system.type = 0;
    world_constructor(&world);
    cr_assert_eq(contains_system(&world, system), false);
}

Test(world_contains_system, world_contains_system_by_type_success)
{
    world_t world;
    system_t system;

    system.type = 0;
    world_constructor(&world);
    add_system(&world, system);
    cr_assert_eq(contains_system_by_type(&world, 0), true);
}

Test(world_contains_system, world_contains_system_by_type_failure)
{
    world_t world;
    system_t system;

    system.type = 0;
    world_constructor(&world);
    add_system(&world, system);
    cr_assert_eq(contains_system_by_type(&world, 1), true);
}

Test(wolrd_get_system, world_get_system_success)
{
    world_t world;
    system_t system;

    system.type = 0;
    world_constructor(&world);
    add_system(&world, system);
    cr_assert_neq(get_system(&world, (system_t){0, 0, 0}), 0);
}

Test(wolrd_get_system, world_get_system_failure)
{
    world_t world;
    system_t system;

    system.type = 0;
    world_constructor(&world);
    add_system(&world, system);
    cr_assert_eq(get_system(&world, (system_t){1, 0, 0}), 0);
}

Test(wolrd_get_system, world_get_system_by_type_success)
{
    world_t world;
    system_t system;

    system.type = 0;
    world_constructor(&world);
    add_system(&world, system);
    cr_assert_neq(get_system_by_type(&world, 0), 0);
}

Test(wolrd_get_system, world_get_system_by_type_failure)
{
    world_t world;
    system_t system;

    system.type = 0;
    world_constructor(&world);
    add_system(&world, system);
    cr_assert_eq(get_system_by_type(&world, 1), 0);
}
