/*
** EPITECH PROJECT, 2022
** our_rpg
** File description:
** vector
*/

#include "vector.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int clear(vector_t *this)
{
    this->size = 0;
    this->available_size = this->total_size;
    return 0;
}

static int erase(vector_t *this, unsigned int index)
{
    if (index > this->size)
        return -1;
    memcpy(this->pointer + index * this->element_size, this->pointer + (index + 1) * this->element_size, (this->size - (index + 1)) * this->element_size);
    this->size--;
    this->available_size++;
    return 0;
}

/// @brief The print_at function prints an element at the given index
/// using print_fct function pointer.
/// The format dependant on how print_fct function pointer print the data.
/// @param this The vector on which print an element.
/// @param index The position of the element to print.
/// @param print_fct The function pointer used to know how to print an
/// element.
/// @return It returns the value of print_fct, or -1 if an error occurs.
static int print_at(vector_t *this, unsigned int index, int (*print_fct)(void *data))
{
    if (index > this->size)
        return -1;
    return print_fct(this->pointer + index * this->element_size);
}

/// @brief The print function prints all elements of the vector.
/// The format dependant on how print_fct function pointer print the data.
/// @param this The vector on which print all elements.
/// @param print_fct The function pointer used to know how to print an
/// element.
/// @return 0, or -1 if print_fct return -1.
static int print(vector_t *this, int (*print_fct)(void *data))
{
    printf("[");
    fflush(stdout);
    for (unsigned int i = 0; i < this->size; i++) {
        if (print_fct(this->pointer + i * this->element_size) < 0)
            return -1;
        if (i + 1 < this->size) {
            printf(", ");
            fflush(stdout);
        }
    }
    printf("]\n");
    fflush(stdout);
    return 0;
}

/// @brief The emplace function adds an element at the given index.
/// It increases the capacity of the vector if needed.
/// @param this The vector on which adds an element.
/// @param data The data to be added.
/// @param index The index where the data must be added.
/// @return 0, or -1 if an error occurs.
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

/// @brief The emplace_back function adds an element at the end.
/// It increases the capacity of the vector if needed.
/// @param this The vector on which adds an element.
/// @param data The data to be added.
/// @return 0, or -1 if an error occurs.
static int emplace_back(vector_t *this, void *data)
{
    if (!this->available_size) {
        this->pointer = realloc(this->pointer, (this->total_size + 1) * this->element_size);
        if (!this->pointer)
            return -1;
        this->total_size++;
        this->available_size++;
    }
    memcpy(this->pointer + this->size * this->element_size, data, this->element_size);
    this->available_size--;
    this->size++;
    return 0;
}

/// @brief This is the destructor of a vector. It free the pointer.
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
    this->available_size = element_number;
    this->size = 0;
    this->total_size = element_number;
    this->destructor = &destructor;
    this->emplace = &emplace;
    this->emplace_back = &emplace_back;
    this->print_at = &print_at;
    this->print = &print;
    this->clear = &clear;
    this->erase = &erase;
    return 0;
}
