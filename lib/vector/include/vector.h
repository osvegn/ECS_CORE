/*
** EPITECH PROJECT, 2022
** our_rpg
** File description:
** vector
*/

#ifndef VECTOR_H_
#define VECTOR_H_

/// @brief The vector structure is used to store multiple data from the same
/// type allong the memory.
/// It stores some informations such as the size of an element, the number of
/// element, the total number of element, the available number of element, and
/// a pointer to the beginning of the memory.
typedef struct vector_s {

    /// @brief The size of an element.
    unsigned int element_size;

    /// @brief The number of element.
    unsigned int size;

    /// @brief The capacity of element in the vector.
    unsigned int capacity;

    /// @brief The pointer to the memory.
    void *pointer;
} vector_t;

#endif /* !VECTOR_H_ */
