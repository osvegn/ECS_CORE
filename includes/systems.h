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

#include "systems/load_scene.h"
#include "systems/window_manager.h"
#include "systems/movement.h"
#include "systems/reset_game_clock.h"
#include "systems/world_initializer.h"

typedef enum system_type_e {
    S_UNDEFINED,
    S_WORLD_INITIALIZER,
    S_WINDOW_MANAGER,
    S_LOAD_SCENE,
    S_MOVEMENT,
    S_RESET_GAME_CLOCK,
    S_MAX_VALUE
} system_type_t;

typedef struct system_def_s {
    char *name;
    int (*constructor)(system_t *);
} system_def_t;

static const system_def_t system_def[] = {
    {"S_LOAD_SCENE", &system_load_scene_constructor},
    {"S_WINDOW_MANAGER", &system_windows_manager_constructor},
    {"S_MOVEMENT", &system_movement_constructor},
    {"S_RESET_GAME_CLOCK", &system_reset_game_clock_constructor},
    {0, 0},
};

#endif /* !SYSTEMS_H_ */
