/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** system
*/

#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <stdbool.h>

/// @brief It's the structure of a system. A system is used to update a type
/// of component or resource. It contains a type, a boolean and a
/// function pointer.
/// Systems are called by the world to be run.
typedef struct system_s {

    /// @brief The type of the system. It is used to know if a system already
    /// exists.
    unsigned int type;

    /// @brief The boolean is used to know if the system if active or not.
    bool active;

    /// @brief The run function pointer is used to know which function must be
    /// called to run this system.
    /// @param world The world on which the system is running.
    /// @return 0, or -1 if an error occurs.
    int (*run)(void *world);
} system_t;

#endif /* !SYSTEM_H_ */
