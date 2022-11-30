/*
** EPITECH PROJECT, 2022
** our_rpg
** File description:
** vector
*/

#include "vector.h"
#include <stdlib.h>
#include <string.h>

/// @brief The emplace function adds an element at the given index.
/// It increases the capacity of the vector if needed.
/// @param this The vector on which adds an element.
/// @param data The data to be added.
/// @param index The index where the data must be added.
/// @return 0, or -1 if an error occurs.
static int emplace(vector_t *this, void *data, unsigned int index)
{
    void *ptr = NULL;

    if (index > this->capacity)
        return -1;
    if (this->size == this->capacity) {
        this->pointer = realloc(this->pointer, (this->capacity + 1) * this->element_size);
        if (!this->pointer)
            return -1;
        this->capacity++;
    }
    ptr = this->pointer + index * this->element_size;
    for (unsigned int i = this->size; i > index; i--) {
        memcpy(this->pointer + i * this->element_size, this->pointer + (i - 1) * this->element_size, this->element_size);
    }
    memcpy(ptr, data, this->element_size);
    this->size++;
    return 0;
}

/// @brief The emplace_back function adds an element at the end.
/// It increases the capacity of the vector if needed.
/// @param this The vector on which adds an element.
/// @param data The data to be added.
/// @return 0, or -1 if an error occurs.
static int emplace_back(vector_t *this, void *data)
{
    if (this->size == this->capacity) {
        this->pointer = realloc(this->pointer, (this->capacity + 1) * this->element_size);
        if (!this->pointer)
            return -1;
        this->capacity++;
    }
    memcpy(this->pointer + this->size * this->element_size, data, this->element_size);
    this->size++;
    return 0;
}

/// @brief This is the destructor of a vector. It frees the pointer.
/// @param this The vector to be free.
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
    this->size = 0;
    this->capacity = element_number;
    this->destructor = &destructor;
    this->emplace = &emplace;
    this->emplace_back = &emplace_back;
    return 0;
}
