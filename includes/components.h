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

int component_color_constructor(component_t *component, void *data);
int component_set_color(const component_t *component, void *data);
void *component_get_color(component_t *component);

int component_displayable_constructor(component_t *component, void *data);

int component_controllable_constructor(component_t *component, void *data);

int component_collidable_constructor(component_t *component, void *data);

#endif /* !COMPONENTS_H_ */
