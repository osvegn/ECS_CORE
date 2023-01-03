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
    cr_assert_eq(add_entity(&world, entity), 0);
    cr_assert_eq(world.entity_list.size(&world.entity_list), 1);
}

Test(world_add_entity, world_add_entity_failure)
{
    world_t world;
    entity_t entity;

    entity.id = 0;
    vector_constructor(&world.entity_list, sizeof(int), 0);
    cr_assert_eq(add_entity(&world, entity), 0);
    cr_assert_eq(add_entity(&world, entity), -1);
    cr_assert_eq(world.entity_list.size(&world.entity_list), 1);
}

Test(world_add_entity, world_add_entity_success_with_two_elements)
{
    world_t world;
    entity_t entity;

    entity.id = 0;
    vector_constructor(&world.entity_list, sizeof(int), 0);
    cr_assert_eq(add_entity(&world, entity), 0);
    entity.id = 1;
    cr_assert_eq(add_entity(&world, entity), 0);
    cr_assert_eq(world.entity_list.size(&world.entity_list), 2);
}

Test(world_add_entity, world_remove_entity)
{
    world_t world;
    entity_t entity;

    entity.id = 0;
    vector_constructor(&world.entity_list, sizeof(int), 0);
    cr_assert_eq(add_entity(&world, entity), 0);
    entity.id = 1;
    cr_assert_eq(add_entity(&world, entity), 0);
    cr_assert_eq(remove_entity(&world, entity), 0);
    cr_assert_eq(world.entity_list.size(&world.entity_list), 1);
}

Test(world_add_entity, world_remove_entity_failure)
{
    world_t world;
    entity_t entity;

    entity.id = 0;
    vector_constructor(&world.entity_list, sizeof(int), 0);
    cr_assert_eq(add_entity(&world, entity), 0);
    entity.id = 1;
    cr_assert_eq(add_entity(&world, entity), 0);
    cr_assert_eq(remove_entity(&world, entity), 0);
    cr_assert_eq(remove_entity(&world, entity), -1);
    cr_assert_eq(world.entity_list.size(&world.entity_list), 1);
}

Test(world_contains_entity, world_contains_entity_success)
{
    world_t world;
    entity_t entity;

    entity.id = 0;
    world_constructor(&world);
    add_entity(&world, entity);
    cr_assert_eq(contains_entity(&world, entity), true);
}

Test(world_contains_entity, world_contains_entity_failure)
{
    world_t world;
    entity_t entity;

    entity.id = 0;
    world_constructor(&world);
    cr_assert_eq(contains_entity(&world, entity), false);
}

Test(world_join_entities, world_join_entities_1)
{
    world_t world;
    entity_t entity;
    vector_t vector;

    world_constructor(&world);
    entity_constructor(&entity);
    add_component(&entity, (component_t){1, 0});
    add_entity(&world, entity);
    cr_assert_eq(join_entities(&world, &vector, 1, 1), 1);
}

Test(world_join_entities, world_join_entities_2)
{
    world_t world;
    vector_t vector;

    world_constructor(&world);
    cr_assert_eq(join_entities(&world, &vector, 0), -1);
}

Test(world_join_entities, world_join_entities_3)
{
    world_t world;
    vector_t vector;
    entity_t entity;
    int expected_value = 2;

    world_constructor(&world);
    entity_constructor(&entity);
    add_component(&entity, (component_t){1, 0});
    add_entity(&world, entity);
    entity_constructor(&entity);
    add_component(&entity, (component_t){1, 0});
    add_entity(&world, entity);
    cr_assert_eq(join_entities(&world, &vector, 1, 1), expected_value);
}
