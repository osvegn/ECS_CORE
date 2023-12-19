/*
* Filename: window.h
* Path: includes/resources
* Created Date: Monday, December 18th 2023, 5:43 pm
* Author: osvegn
*
* Copyright (c) 2023 our_rpg
*/

#ifndef R_WINDOW_H_
#define R_WINDOW_H_

#include "resource.h"

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

#endif // R_WINDOW_H_
