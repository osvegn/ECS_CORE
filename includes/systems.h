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
    S_MOVEMENT,
    S_DISPLAY,
    S_WINDOW_MANAGER,
    S_MOVE_INPUT,
    S_MOVE_CONTROLLABLE,
    S_GRAVITY_SYSTEM,
    S_JUMP_SYSTEM,
    S_COLLISION_SYSTEM,
    S_OBSTACLE_CREATION,
    S_MAX_VALUE
} system_type_t;

int system_movement(void *world);
int system_movement_constructor(system_t *system);

int system_world_initializer(void *ptr);
int system_world_initializer_constructor(system_t *system);

int system_display(void *world);
int system_display_constructor(system_t *system);

int system_windows_manager(void *ptr);
int system_windows_manager_constructor(system_t *system);

int system_move_controllable_run(void *world);
int system_move_controllable_constructor(system_t *system);

int system_gravity_constructor(system_t *system);
int system_gravity(void *ptr);

int system_jump_constructor(system_t *system);
int system_jump(void *ptr);

int system_obstacle_creation_constructor(system_t *system);
int system_obstacle_creation_run(void *ptr);

#endif /* !SYSTEMS_H_ */
