/**
* Filename: velocity.h
* Path: include/components
* Created Date: Thursday, November 30th 2023, 6:23 pm
* Author: osvegn
*
* Copyright (c) 2023 our_rpg
*/

#ifndef VELOCITY_H
#define VELOCITY_H

#include "component.h"

/// @brief Constructor for velocity component from json data.
/// @note The json string must be formatted as follow:
/// {
///     "x": 0,
///     "y": 0
/// }
/// @param component Component to construct. It must be a valid component.
/// @param data Json data to construct component from.
/// @return Return 0 if component was successfully constructed, -1 otherwise.
int component_velocity_constructor(component_t *component, void *data);
int component_velocity_constructor_from_json(component_t *component, void *data);

/// @brief Set velocity component from json data.
/// @note The json string must be formatted as follow:
/// {
///     "x": 0,
///     "y": 0
/// }
/// @param component Component to set. It must be a valid component.
/// @param data Json data to set component from.
/// @return Return 0 if component was successfully set, -1 otherwise.
int component_velocity_set(component_t *component, void *data);

/// @brief Get the data of a velocity component.
/// @param component Component to get the data from.
/// @return Return the data of the component if success, 0 otherwise.
void *component_velocity_get(const component_t *component);

#endif // VELOCITY_H
