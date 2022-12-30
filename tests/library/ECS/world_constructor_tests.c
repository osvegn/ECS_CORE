/*
** EPITECH PROJECT, 2022
** our_rpg [Codespaces]
** File description:
** world_constructor_tests
*/

#include <criterion/criterion.h>
#include "world.h"

Test(world_constructor, world_constructor)
{
    world_t world;

    cr_assert_eq(world_constructor(&world), 0);
    world_destructor(&world);
}
