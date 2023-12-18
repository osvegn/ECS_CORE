/**
* Filename: controllable.h
* Path: include/components
* Created Date: Thursday, November 30th 2023, 6:23 pm
* Author: osvegn
*
* Copyright (c) 2023 our_rpg
*/

#ifndef CONTROLLABLE_H
#define CONTROLLABLE_H

#include "component.h"

/// @brief Create a controllable component. It allows the entity to be
/// controllable by the player.
/// @param component The component to initialize. It must be a valid
/// component_t.
/// @param data The data to initialize the component. It must be empty.
/// @return Return 0
int component_controllable_constructor(component_t *component, void *data);

#endif // CONTROLLABLE_H
