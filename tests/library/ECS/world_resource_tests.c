/*
** EPITECH PROJECT, 2022
** our_rpg [Codespaces]
** File description:
** world_resource_tests
*/

#include <criterion/criterion.h>
#include "world.h"

Test(world_add_resource, world_add_resource)
{
    world_t world;
    resource_t resource;

    resource.id = 0;
    vector_constructor(&world.resource_list, sizeof(int), 0);
    cr_assert_eq(add_resource(&world, resource), 0);
    cr_assert_eq(world.resource_list.size(&world.entity_list), 1);
}

Test(world_add_resource, world_add_resource_failure)
{
    world_t world;
    resource_t resource;

    resource.id = 0;
    vector_constructor(&world.resource_list, sizeof(int), 0);
    cr_assert_eq(add_resource(&world, resource), 0);
    cr_assert_eq(add_resource(&world, resource), -1);
    cr_assert_eq(world.resource_list.size(&world.entity_list), 1);
}

Test(world_add_resource, world_add_resource_success_with_two_elements)
{
    world_t world;
    resource_t resource;

    resource.id = 0;
    vector_constructor(&world.resource_list, sizeof(int), 0);
    cr_assert_eq(add_resource(&world, resource), 0);
    resource.id = 1;
    cr_assert_eq(add_resource(&world, resource), 0);
    cr_assert_eq(world.resource_list.size(&world.entity_list), 2);
}

Test(world_remove_resource, world_remove_resource)
{
    world_t world;
    resource_t resource;

    resource.id = 0;
    vector_constructor(&world.resource_list, sizeof(int), 0);
    cr_assert_eq(add_resource(&world, resource), 0);
    resource.id = 1;
    cr_assert_eq(add_resource(&world, resource), 0);
    cr_assert_eq(remove_resource(&world, resource), 0);
    cr_assert_eq(world.resource_list.size(&world.entity_list), 1);
}

Test(world_remove_resource, world_remove_resource_failure)
{
    world_t world;
    resource_t resource;

    resource.id = 0;
    vector_constructor(&world.resource_list, sizeof(int), 0);
    cr_assert_eq(add_resource(&world, resource), 0);
    resource.id = 1;
    cr_assert_eq(add_resource(&world, resource), 0);
    cr_assert_eq(remove_resource(&world, resource), 0);
    cr_assert_eq(remove_resource(&world, resource), -1);
    cr_assert_eq(world.resource_list.size(&world.entity_list), 1);
}