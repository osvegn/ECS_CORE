/*
 * Filename: /workspaces/our_rpg/tests/sources/System/movement_tests.c
 * Path: /workspaces/our_rpg/tests/sources/System
 * Created Date: Saturday, January 21st 2023, 2:31:21 am
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#include <criterion/criterion.h>
#include "systems.h"
#include "world.h"
#include "world_entity.h"
#include "world_system.h"
#include "components.h"

void create_world(world_t *world)
{
    entity_t entity;
    component_t component;
    system_t system;

    world_constructor(world);
    entity_constructor(&entity);
    position_constructor(&component, (vector2i_t){10, 10});
    entity_add_component(&entity, component);
    velocity_constructor(&component, (vector2i_t){5, 2});
    entity_add_component(&entity, component);
    world_add_entity(world, &entity);
    movement_constructor(&system);
    world_add_system(world, &system);
}

Test(run_movement_system, test01)
{
    world_t world;
    vector_t entities;
    entity_t *entity;
    vector2i_t *position;

    create_world(&world);
    world_run_systems(&world);
    world_join_entities(&world, &entities, 2, VELOCITY, POSITION);
    entity = *(entity_t **)entities.at(&entities, 0);
    position = entity_get_component(entity, POSITION)->data;
    cr_assert_eq(position->x, 15);
    cr_assert_eq(position->y, 12);
}
