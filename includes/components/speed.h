/**
* Filename: speed.h
* Path: include/components
* Created Date: Thursday, November 30th 2023, 6:23 pm
* Author: osvegn
*
* Copyright (c) 2023 our_rpg
*/

#ifndef SPEED_H
#define SPEED_H

#include "component.h"

int component_speed_constructor(component_t *component, void *data);
int component_speed_constructor_from_json(component_t *component, void *data);
int component_speed_set(component_t *component, void *data);
void *component_speed_get(const component_t *component);

#endif // SPEED_H
