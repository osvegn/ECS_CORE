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
    cr_assert_eq(0, 0);
}

Test(vector_emplace_back, vector_emplace_back)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    vector.emplace_back(&vector, &data);
    vector.destructor(&vector);
    cr_assert_eq(0, 0);
}

Test(vector_emplace, vector_emplace)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    vector.emplace(&vector, &data, 0);
    vector.destructor(&vector);
    cr_assert_eq(0, 0);
}

Test(vector_clear, vector_clear)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    vector.emplace_back(&vector, &data);
    vector.emplace_back(&vector, &data);
    vector.emplace_back(&vector, &data);
    vector.emplace_back(&vector, &data);
    rvalue = vector.size(&vector);
    cr_assert_eq(rvalue, 4);
    vector.clear(&vector);
    rvalue = vector.size(&vector);
    cr_assert_eq(rvalue, 0);
    vector.destructor(&vector);
}

Test(vector_at, vector_at)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    vector.emplace_back(&vector, &data);
    rvalue = *(int *)vector.at(&vector, 0);
    cr_assert_eq(rvalue, 10);
    vector.destructor(&vector);
}

Test(vector_front, vector_front)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    vector.emplace_back(&vector, &data);
    data = 5;
    vector.emplace_back(&vector, &data);
    rvalue = *(int *)vector.front(&vector);
    cr_assert_eq(rvalue, 10);
    vector.destructor(&vector);
}

Test(vector_back, vector_back)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    int data = 10;

    cr_assert_eq(rvalue, 0);
    vector.emplace_back(&vector, &data);
    data = 5;
    vector.emplace_back(&vector, &data);
    rvalue = *(int *)vector.back(&vector);
    cr_assert_eq(rvalue, 5);
    vector.destructor(&vector);
}
