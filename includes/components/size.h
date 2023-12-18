/**
* Filename: size.h
* Path: include/components
* Created Date: Thursday, November 30th 2023, 6:23 pm
* Author: osvegn
*
* Copyright (c) 2023 our_rpg
*/

#ifndef SIZE_H
#define SIZE_H

#include "component.h"

/// @brief Constructor for size component from json data.
/// @note The json string must be formatted as follow:
/// {
///     "width": 0,
///     "height": 0
/// }
/// @param component Component to construct. It must be a valid component.
/// @param data Json data to construct component from.
/// @return Return 0 if component was successfully constructed, -1 otherwise.
int component_size_constructor(component_t *component, void *data);
int component_size_constructor_from_json(component_t *component, void *data);

/// @brief Set size component from json data.
/// @note The json string must be formatted as follow:
/// {
///     "width": 0,
///     "height": 0
/// }
/// @param component Component to set. It must be a valid component.
/// @param data Json data to set component from.
/// @return Return 0 if component was successfully set, -1 otherwise.
int component_size_set(component_t *component, void *data);

/// @brief Get size component data.
/// @param component Component to get data from.
/// @return Return a pointer to the data if component is a size component, 0
/// otherwise.
void *component_size_get(const component_t *component);

#endif // SIZE_H
