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

    /// @brief This is the destructor of a vector. It frees the pointer.
    /// @param this The vector to be free.
    void (*destructor)(struct vector_s *this);
} vector_t;

/// @brief This is the constructor of the vector structure.
/// It set all default value and member function pointer.
/// @param this The vector to be construct.
/// @param element_size The size of an element of the vector.
/// Use sizeof() to know the size of your type.
/// @param element_number The number of element you want to allow in vector
/// memory at the beginning. It can be increase during the runtime.
/// @return 0, or -1 if an error occurs.
int vector_constructor(vector_t *this, unsigned int element_size, unsigned int element_number);

#endif /* !VECTOR_H_ */
