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
#include "utils/ecs_vector.h"
#include "utils/ecs_color.h"

#include "components/position.h"
#include "components/velocity.h"
#include "components/size.h"
#include "components/color.h"
#include "components/displayable.h"
#include "components/controllable.h"
#include "components/collidable.h"
#include "components/speed.h"
#include "components/clickable.h"

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
    C_SPEED,
    C_CLICKABLE,
    C_MAX
} component_type_t;

typedef struct component_def_s {
    char *name;
    int (*constructor)(component_t *, void *);
} component_def_t;

static const component_def_t components_def[] = {
    {"C_POSITION", &component_position_constructor_from_json},
    {"C_VELOCITY", &component_velocity_constructor_from_json},
    {"C_CONTROLLABLE", &component_controllable_constructor},
    {"C_SIZE", &component_size_constructor_from_json},
    {"C_DISPLAYABLE", &component_displayable_constructor},
    {"C_COLLIDABLE", &component_collidable_constructor},
    {"C_COLOR", &component_color_constructor_from_json},
    {"C_SPEED", &component_speed_constructor_from_json},
    {"C_CLICKABLE", &component_clickable_constructor},
    {0, 0}
};

#endif // COMPONENTS_H_
