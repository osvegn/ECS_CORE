/**
* Filename: position.h
* Path: include/components
* Created Date: Thursday, November 30th 2023, 6:23 pm
* Author: osvegn
*
* Copyright (c) 2023 our_rpg
*/

#ifndef POSITION_H
#define POSITION_H

#include "component.h"

/// @brief Create a position component from a json string.
/// @note The json string must be formatted as follow:
/// {
///     "x": 0,
///     "y": 0
/// }
/// @param component Component to initialize. It must be a valid component.
/// @param data Data to initialize the component. It must be a valid json string.
/// @return Return 0 if success, -1 otherwise.
int component_position_constructor(component_t *component, void *data);
int component_position_constructor_from_json(component_t *component, void *data);

/// @brief Set position component from json string.
/// @note The json string must be formatted as follow:
/// {
///     "x": 0,
///     "y": 0
/// }
/// @param component Component to set. It must be a valid component.
/// @param data Data to set the component with. It must be a valid json string.
/// @return Return 0 if success, -1 otherwise.
int component_position_set(component_t *component, void *data);

/// @brief Get the data of a position component.
/// @param component Component to get the data from. It must be a valid
/// position component.
/// @return Return the data of the component if success, 0 otherwise.
void *component_position_get(const component_t *component);

#endif // POSITION_H
