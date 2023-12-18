/**
* Filename: displayable.h
* Path: include/components
* Created Date: Thursday, November 30th 2023, 6:23 pm
* Author: osvegn
*
* Copyright (c) 2023 our_rpg
*/

#ifndef DISPLAYABLE_H
#define DISPLAYABLE_H

#include "component.h"

/// @brief Create a displayable component. It is used to display an entity.
/// @param component The component to initialize. It must be a valid
/// component_t.
/// @param data The data to initialize the component. It must be empty.
/// @return Return 0.
int component_displayable_constructor(component_t *component, void *data);

#endif // DISPLAYABLE_H
