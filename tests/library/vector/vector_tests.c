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

Test(vector_at, vector_at_valid)
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

Test(vector_at, vector_at_too_high_index)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    int data = 10;
    void *ptr;

    cr_assert_eq(rvalue, 0);
    vector.emplace_back(&vector, &data);
    ptr = vector.at(&vector, 10);
    cr_assert_eq(ptr, 0);
    vector.destructor(&vector);
}

Test(vector_at, vector_at_invalid_pointer)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    void *ptr;

    cr_assert_eq(rvalue, 0);
    free(vector.pointer);
    vector.pointer = NULL;
    vector._size = 1;
    ptr = vector.at(&vector, 0);
    cr_assert_eq(ptr, 0);
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

Test(vector_back, vector_back_invalid_pointer)
{
    vector_t vector;
    int rvalue = vector_constructor(&vector, sizeof(int), 0);
    void *ptr;

    cr_assert_eq(rvalue, 0);
    free(vector.pointer);
    vector.pointer = NULL;
    ptr = vector.back(&vector);
    cr_assert_eq(ptr, 0);
}
