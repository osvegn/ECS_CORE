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
#include "vector2i.h"

typedef enum component_type_e {
    C_UNDEFINED,
    POSITION,
    VELOCITY,
    DISPLAYABLE,
    C_MAX_VALUE
} component_type_t;

int position_constructor(component_t *component, vector2i_t pos);
void position_destructor(component_t *component);
void position_set(component_t *component, const vector2i_t pos);
vector2i_t *position_get(const component_t *component);

int velocity_constructor(component_t *component, vector2i_t vel);
void velocity_destructor(component_t *component);
void velocity_set(component_t *component, const vector2i_t vel);
vector2i_t *velocity_get(const component_t *component);

int displayable_constructor(component_t *component);

#endif /* !COMPONENTS_H_ */
