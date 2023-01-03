/*
** EPITECH PROJECT, 2023
** our_rpg [Codespaces]
** File description:
** entity_component_tests
*/

#include <criterion/criterion.h>
#include "entity.h"
#include "component.h"

Test(entity_component, test_entity_constructor)
{
    entity_t entity;

    cr_assert_eq(entity_constructor(&entity), 0);
}


Test(entity_component, test_entity_add_component)
{
    entity_t entity;

    entity_constructor(&entity);
    cr_assert_eq(add_component(&entity, (component_t){0, 0}), 0);
}
