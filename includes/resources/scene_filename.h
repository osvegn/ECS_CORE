/*
* Filename: scene_filename.h
* Path: includes/resources
* Created Date: Monday, December 18th 2023, 5:47 pm
* Author: osvegn
*
* Copyright (c) 2023 our_rpg
 */

#ifndef R_SCENE_FILENAME_H_
#define R_SCENE_FILENAME_H_

#include "resource.h"

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

#endif // R_SCENE_FILENAME_H_
