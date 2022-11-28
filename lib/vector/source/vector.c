/*
** EPITECH PROJECT, 2022
** our_rpg
** File description:
** vector
*/

#include "vector.h"
#include <stdlib.h>
#include <string.h>

static int emplace(vector_t *this, void *data, unsigned int index)
{
    void *ptr = NULL;

    if (index > this->total_size)
        return -1;
    if (!this->available_size) {
        this->pointer = realloc(this->pointer, (this->total_size + 1) * this->element_size);
        if (!this->pointer)
            return -1;
        this->total_size++;
        this->available_size++;
    }
    ptr = this->pointer + index * this->element_size;
    for (unsigned int i = this->size; i > index; i--) {
        memcpy(this->pointer + i * this->element_size, this->pointer + (i - 1) * this->element_size, this->element_size);
    }
    memcpy(ptr, data, this->element_size);
    this->available_size--;
    this->size++;
    return 0;
}

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
    this->emplace = &emplace;
    return 0;
}
