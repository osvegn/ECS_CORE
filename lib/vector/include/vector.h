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

    /// @brief The number of element in used.
    unsigned int size;

    /// @brief The number of element in memory.
    unsigned int total_size;

    /// @brief The number of element available in memory not used by the
    /// vector.
    unsigned int available_size;

    /// @brief The pointer to the memory.
    void *pointer;

    void (*destructor)(struct vector_s *this);
    int (*emplace)(struct vector_s *this, void *data, unsigned int index);
} vector_t;

int vector_constructor(vector_t *this, unsigned int element_size, unsigned int element_number);

#endif /* !VECTOR_H_ */
