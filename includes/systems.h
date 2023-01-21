/*
** EPITECH PROJECT, 2023
** our_rpg [Codespaces]
** File description:
** systems
*/

#ifndef SYSTEMS_H_
#define SYSTEMS_H_

#include "system.h"

typedef enum system_type_e {
    UNDEFINED,
    MOVEMENT,
    MAX_VALUE
} system_type_t;

int movement(void *world);
int create_movement_system(system_t *system);

#endif /* !SYSTEMS_H_ */
