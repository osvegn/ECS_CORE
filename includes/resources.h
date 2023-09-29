/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/includes/resources.h
 * Path: /home/thomas/Documents/Perso/our_rpg/includes
 * Created Date: Sunday, February 12th 2023, 5:32:35 pm
 * Author: Thomas
 * 
 * Copyright (c) 2023 our_rpg
 */

#ifndef RESOURCES_H_
#define RESOURCES_H_

#include "resource.h"
#include "window.h"


typedef enum resource_type_e {
    R_UNDEFINED,
    R_WINDOW,
    R_CAMERA,
    R_SCENE_FILENAME,
    R_GAME_CLOCK,
    R_MAX_VALUE
} resource_type_t;

/// @brief Window constructor. It opens a new window.
/// @note The json format must be formatted like:
/// {
///     "width": int,
///     "height": int,
///     "title": string,
///     "fps": int 
/// }
/// @param resource The resource to be construct.
/// @param data The data to set to the window. It must be a json formatted string.
/// @return 0, or -1 if something fail.
int resource_window_constructor(resource_t *resource, void *data);
int resource_window_constructor_from_json(resource_t *resource, void *data);

/// @brief Window destructor.
/// @param resource The resource to be destroy. It closes the window.
/// @return 0.
int resource_window_destructor(resource_t *resource);

/// @brief Set new data for a window resource. It opens a new window.
/// @note The json format must be formatted like:
/// {
///     "width": int,
///     "height": int,
///     "title": string,
///     "fps": int 
/// }
/// @param resource The resource to be updated.
/// @param data The data to set to the window. It must be a json formatted string.
/// @return 0, or -1 if something fail.
int resource_window_set(resource_t *resource, void *data);

/// @brief Get a pointer to the window resource data.
/// @param resource The resource to get the data from.
/// @return A pointer to the data, or 0 if it's not a valid resource.
void *resource_window_get(const resource_t *resource);


/// @brief Scene filename resource constructor.
/// @note The json format must be formatted like:
/// {
///     "filename": string
/// }
/// @param resource The resource to be construct.
/// @param data The data to be set to the resource. It must be a json formatted string.
/// @return 0, or -1 if something fail.
int resource_scene_filename_constructor(resource_t *resource, void *data);
int resource_scene_filename_constructor_from_json(resource_t *resource, void *data);

/// @brief Scene filename resource destructor.
/// @param resource The resource to be destroy.
/// @return 0.
int resource_scene_filename_destructor(resource_t *resource);

/// @brief Set scene filename resource data.
/// @note The json format must be formatted like:
/// {
///     "filename": string
/// }
/// @param resource The resource to be updated.
/// @param data The data to set.
/// @return 0, or -1 if something failed.
int resource_scene_filename_set(resource_t *resource, void *data);

/// @brief Get a pointer to the data of the resource.
/// @param resource The resource to get the data from.
/// @return A pointer to the data, or 0 if it's not a valid resource.
void *resource_scene_filename_get(const resource_t *resource);

int resource_game_clock_constructor(resource_t *resource, void *data);
int resource_game_clock_constructor_from_json(resource_t *resource, void *data);
int resource_game_clock_destructor(resource_t *resource);
int resource_game_clock_set(resource_t *resource, void *data);
void *resource_game_clock_get(const resource_t *resource);

int resource_camera_constructor(resource_t *resource, void *data);
int resource_camera_constructor_from_json(resource_t *resource, void *data);
int resource_camera_destructor(resource_t *resource);
int resource_camera_set(resource_t *resource, void *data);
void *resource_game_clock_get(const resource_t *resource);

#endif /* !RESOURCES_H_*/