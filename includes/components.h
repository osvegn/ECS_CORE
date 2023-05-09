/*
 * Filename: /workspaces/our_rpg/includes/components.h
 * Path: /workspaces/our_rpg/includes
 * Created Date: Sunday, January 15th 2023, 3:59:05 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#ifndef COMPONENTS_H_
#define COMPONENTS_H_

#include "component.h"
#include "ecs_vector.h"
#include "ecs_color.h"

/// @brief Component types
typedef enum component_type_e {
    C_UNDEFINED,
    C_POSITION,
    C_VELOCITY,
    C_SIZE,
    C_COLOR,
    C_DISPLAYABLE,
    C_CONTROLLABLE,
    C_COLLIDABLE,
    C_MAX
} component_type_t;

int component_position_constructor(component_t *component, void *data);
int component_position_set(component_t *component, void *data);
void *component_position_get(const component_t *component);

int component_velocity_constructor(component_t *component, void *data);
int component_velocity_set(component_t *component, void *data);
void *component_velocity_get(const component_t *component);

int component_size_constructor(component_t *component, void *data);
int component_size_set(component_t *component, void *data);
void *component_size_get(const component_t *component);

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

int component_displayable_constructor(component_t *component, void *data);

int component_controllable_constructor(component_t *component, void *data);

/// @brief Construct a new component collidable object.
/// @param component The component to construct. Must be
/// a valid pointer to a component_t structure.
/// @param data The data to initialize the component with.
/// @return int 0.
int component_collidable_constructor(component_t *component, void *data);

#endif /* !COMPONENTS_H_ */
