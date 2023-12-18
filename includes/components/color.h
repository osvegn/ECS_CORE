/**
* Filename: color.h
* Path: include/components
* Created Date: Thursday, November 30th 2023, 6:23 pm
* Author: osvegn
*
* Copyright (c) 2023 our_rpg
*/

#ifndef COLOR_H
#define COLOR_H

#include "component.h"

/// @brief Create a color component from a json string.
/// @note The json string must be formatted as follow:
/// {
///     "r": 0-255,
///     "g": 0-255,
///     "b": 0-255,
///     "a": 0-255
/// }
/// @param component Component to initialize. Must be a valid component_t.
/// @param data Data to initialize the component. Must be a valid json string.
/// @return Return 0 if success, -1 otherwise.
int component_color_constructor(component_t *component, void *data);
int component_color_constructor_from_json(component_t *component, void *data);

/// @brief Set color component from json string.
/// @note The json string must be formatted as follow:
/// {
///     "r": 0-255,
///     "g": 0-255,
///     "b": 0-255,
///     "a": 0-255
/// }
/// @param component Component to set. Must be a valid component_t.
/// @param data Data to set. Must be a valid json string.
/// @return Return 0 on success, -1 otherwise.
int component_set_color(component_t *component, void *data);

/// @brief Get a pointer to the color component data.
/// @param component Component to get data from. Must be a valid component_t.
/// @return Return a pointer to the color component data. 0 if component is not
/// a color component.
void *component_get_color(const component_t *component);

#endif // COLOR_H
