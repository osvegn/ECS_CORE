/*
 * Filename: /home/osvegn/Documents/Repositories/ecs_core/tests/unit/Component/component_color.c
 * Path: /home/osvegn/Documents/Repositories/ecs_core/tests/unit/Component
 * Created Date: Tuesday, August 29th 2023, 4:53:57 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 Your Company
 */

#include <criterion/criterion.h>
#include "components.h"

Test(component_color_constructor, component_color_constructor)
{
    component_t component;
    int rvalue = 0;
    ecs_color_t *c;

    rvalue = component_color_constructor(&component, &(ecs_color_t){.a=10, .b=50, .g=120, .r=242});
    cr_assert_eq(rvalue, 0);
    c = component_get_color(&component);
    cr_assert_eq(c->a, 10);
    cr_assert_eq(c->b, 50);
    cr_assert_eq(c->g, 120);
    cr_assert_eq(c->r, 242);
}

Test(component_color_constructor, component_color_constructor_null_data)
{
    component_t component;
    int rvalue = 0;
    ecs_color_t *c;

    rvalue = component_color_constructor(&component, NULL);
    cr_assert_eq(rvalue, 0);
    c = component_get_color(&component);
    cr_assert_eq(c->a, 0);
    cr_assert_eq(c->b, 0);
    cr_assert_eq(c->g, 0);
    cr_assert_eq(c->r, 0);
}

Test(component_color_set, component_color_set)
{
    component_t component;
    int rvalue = 0;
    ecs_color_t *c;

    component_color_constructor(&component, NULL);
    component_set_color(&component, &(ecs_color_t){.a=10, .b=20, .g=52, .r=0});
    c = component_get_color(&component);
    cr_assert_eq(c->a, 10);
    cr_assert_eq(c->b, 20);
    cr_assert_eq(c->g, 52);
    cr_assert_eq(c->r, 0);
}