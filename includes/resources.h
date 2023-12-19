/*
 * Filename: resources.h
 * Path: includes
 * Created Date: Sunday, February 12th 2023, 5:32:35 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#ifndef RESOURCES_H_
#define RESOURCES_H_

#include "resource.h"

#include "resources/game_clock.h"
#include "resources/window.h"
#include "resources/scene_filename.h"

typedef enum resource_type_e {
    R_UNDEFINED,
    R_WINDOW,
    R_SCENE_FILENAME,
    R_GAME_CLOCK,
    R_MAX_VALUE
} resource_type_t;

typedef struct resource_def_s {
    char *name;
    int (*constructor)(resource_t *, void *);
} resource_def_t;

static const resource_def_t resource_def[] = {
    {"R_WINDOW", &resource_window_constructor_from_json},
    {"R_SCENE_FILENAME", &resource_scene_filename_constructor_from_json},
    {"R_GAME_CLOCK", &resource_game_clock_constructor},
    {0, 0}
};

#endif // RESOURCES_H_
