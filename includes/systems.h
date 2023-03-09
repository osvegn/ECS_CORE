/*
 * Filename: /workspaces/our_rpg/includes/systems.h
 * Path: /workspaces/our_rpg/includes
 * Created Date: Saturday, January 21st 2023, 1:28:30 am
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#ifndef SYSTEMS_H_
#define SYSTEMS_H_

#include "system.h"

typedef enum system_type_e {
    S_UNDEFINED,
    WORLD_INITIALIZER,
    MOVEMENT,
    DISPLAY,
    S_MAX_VALUE
} system_type_t;

int movement(void *world);
int movement_constructor(system_t *system);

int world_initializer(void *ptr);
int world_initializer_constructor(system_t *system);

int display(void *world);
int display_constructor(system_t *system);
#endif /* !SYSTEMS_H_ */