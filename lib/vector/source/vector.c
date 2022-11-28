/*
** EPITECH PROJECT, 2022
** our_rpg
** File description:
** vector
*/

#include "vector.h"
#include <stdlib.h>

static void destructor(vector_t *this)
{
    if (this->pointer)
        free(this->pointer);
}

int vector_constructor(vector_t *this, unsigned int element_size, unsigned int element_number)
{
    this->element_size = element_size;
    this->pointer = malloc(this->element_size * element_number);
    if (!this->pointer)
        return - 1;
    this->available_size = element_number;
    this->size = 0;
    this->total_size = element_number;
    this->destructor = &destructor;
    return 0;
}
