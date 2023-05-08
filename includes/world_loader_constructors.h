/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/System/world_loader_constructors.h
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/System
 * Created Date: Wednesday, April 5th 2023, 12:21:01 pm
 * Author: Thomas
 * 
 * Copyright (c) 2023 Your Company
 */

#include "systems.h"
#include "resources.h"
#include "components.h"

const char *systems_types[] = {
        "S_LOAD_SCENE",
        "S_DISPLAY",
        "S_WINDOW_MANAGER",
        "S_RELOAD_CONFIG",
        // "S_MOVEMENT",
        // "S_MOVE_CONTROLLABLE",
        // "S_GRAVITY",
        // "S_JUMP",
        // "S_OBSTACLE_CREATION",
        // "S_CAMERA",
        0
};

const int (*systems_constructors[])(system_t *) = {
        &system_load_scene_constructor,
        &system_display_constructor,
        &system_windows_manager_constructor,
        &system_reload_config_constructor,
        // &system_movement_constructor,
        // &system_move_controllable_constructor,
        // &system_gravity_constructor,
        // &system_jump_constructor,
        // &system_obstacle_creation_constructor,
        // &system_camera_constructor,
        0
};

const char *resources_types[] = {
        "R_WINDOW",
        "R_CAMERA",
        "R_SCENE_FILENAME",
        0
};

const int (*resources_constructors[])(resource_t *, void *) = {
        &resource_window_constructor,
        &resource_camera_constructor,
        &resource_scene_filename_constructor,
        0
};

const char *components_types[] = {
        "C_POSITION",
        "C_VELOCITY",
        "C_CONTROLLABLE",
        "C_SIZE",
        "C_DISPLAYABLE",
        "C_COLLIDABLE",
        "C_COLOR",
        0
};

const int (*components_constructors[])(component_t *, void *) = {
        &component_position_constructor,
        &component_velocity_constructor,
        &component_controllable_constructor,
        &component_size_constructor,
        &component_displayable_constructor,
        &component_collidable_constructor,
        &component_color_constructor,
        0
};