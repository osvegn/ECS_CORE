/*
** EPITECH PROJECT, 2022
** our_rpg
** File description:
** vector_tests
*/

#include <criterion/criterion.h>
#include "vector.h"

Test(a, a)
{
    cr_assert_eq(1, 1);
}

Test(construct_vector, construct_vector)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);

    cr_assert_eq(rvalue, 0);
    vector.destructor(&vector);
}

Test(vector_emplace_back, vector_emplace_back)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    vector.emplace_back(&vector, &data);
    vector.constructor(&vector);
    cr_assert_eq(0, 0);
}