/*
 * Filename: /home/osvegn/Documents/Repositories/ecs_core/tests/unit/Component/component_velocity.c
 * Path: /home/osvegn/Documents/Repositories/ecs_core/tests/unit/Component
 * Created Date: Tuesday, August 29th 2023, 5:12:16 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#include <criterion/criterion.h>
#include "components.h"

Test(component_velocity_constructor, component_velocity_constructor)
{
    component_t component;
    int rvalue = 0;
    ecs_vector2i_t *p;

    rvalue = component_velocity_constructor(&component, &(ecs_vector2i_t){.x=10, .y=550});
    cr_assert_eq(rvalue, 0);
    p = component_velocity_get(&component);
    cr_assert_eq(p->x, 10);
    cr_assert_eq(p->y, 550);
}

Test(component_velocity_constructor, component_velocity_constructor_null_data)
{
    component_t component;
    int rvalue = 0;
    ecs_vector2i_t *p;

    rvalue = component_velocity_constructor(&component, NULL);
    cr_assert_eq(rvalue, 0);
    p = component_velocity_get(&component);
    cr_assert_eq(p->x, 0);
    cr_assert_eq(p->y, 0);
}

Test(component_velocity_set, component_velocity_set)
{
    component_t component;
    int rvalue = 0;
    ecs_vector2i_t *p;

    component_velocity_constructor(&component, NULL);
    rvalue = component_velocity_set(&component, &(ecs_vector2i_t){.x=50, .y=220});
    cr_assert_eq(rvalue, 0);
}
