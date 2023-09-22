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
    S_DISPLAY,
    S_WINDOW_MANAGER,
    S_LOAD_SCENE,
    S_RELOAD_CONFIG,
    S_MOVE_CONTROLLABLE,
    S_MOVEMENT,
    S_MAX_VALUE
} system_type_t;

int system_world_initializer(void *ptr);
int system_world_initializer_constructor(system_t *system);

int system_display(void *world);
int system_display_constructor(system_t *system);

int system_windows_manager(void *ptr);
int system_windows_manager_constructor(system_t *system);

int system_load_scene_constructor(system_t *system);
int system_load_scene_run(void *ptr);

int system_reload_config_constructor(system_t *system);
int system_reload_config_run(void *ptr);

int system_move_controllable_constructor(system_t *system);
static int system_move_controllable(void *world);

static int system_movement(void *world);
int system_movement_constructor(system_t *system);

#endif /* !SYSTEMS_H_ */
