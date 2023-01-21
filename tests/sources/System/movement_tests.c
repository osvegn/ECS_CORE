/*
** EPITECH PROJECT, 2023
** our_rpg [Codespaces]
** File description:
** movement_tests
*/

#include <criterion/criterion.h>
#include "systems.h"
#include "world.h"
#include "components.h"

void create_world(world_t *world)
{
    entity_t entity;
    component_t component;
    system_t system;

    world_constructor(&world);
    entity_constructor(&entity);
    create_position(&component, (vector2i_t){10, 10});
    add_component(&entity, component);
    create_velocity(&component, (vector2i_t){5, 2});
    add_component(&entity, component);
    add_entity(world, entity);
    create_movement_system(&system);
}

Test(run_movement_system, test01)
{
    world_t world;
    vector_t entities;
    entity_t *entity;
    vector2i_t *position;

    create_world(&world);
    run_systems(&world);
    join_entities(&world, &entities, 2, VELOCITY, POSITION);
    entity = entities.at(&entities, 0);
    position = get_component(entity, POSITION)->data;
    cr_assert_eq(position->x, 15);
    cr_assert_eq(position->y, 12);
}
