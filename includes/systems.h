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
    S_WORLD_INITIALIZER,
    S_LOAD_LIBRARY,
    S_MAX_VALUE
} system_type_t;

int system_world_initializer(void *ptr);
int system_world_initializer_constructor(system_t *system);

int system_load_library(void *ptr);
int system_load_library_constructor(system_t *system);

#endif /* !SYSTEMS_H_ */
