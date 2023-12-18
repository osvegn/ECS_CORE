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

#endif /* !COMPONENTS_H_ */
