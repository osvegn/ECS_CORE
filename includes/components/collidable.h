/**
 * Filename: collidable.h
 * Path: include/components
 * Created Date: Thursday, November 30th 2023, 6:23 pm
 * Author: osvegn
 *
 * Copyright (c) 2023 our_rpg
 */

#ifndef COLLIDABLE_H
#define COLLIDABLE_H

#include "component.h"

/// @brief Construct a new component collidable object.
/// @param component The component to construct. Must be
/// a valid pointer to a component_t structure.
/// @param data The data to initialize the component with.
/// @return int 0.
int component_collidable_constructor(component_t *component, void *data);

#endif // COLLIDABLE_H
