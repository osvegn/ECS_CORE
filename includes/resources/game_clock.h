/*
* Filename: game_clock.h
* Path: includes/resources
* Created Date: Monday, December 18th 2023, 5:43 pm
* Author: osvegn
*
* Copyright (c) 2023 our_rpg
*/

#ifndef R_GAME_CLOCK_H_
#define R_GAME_CLOCK_H_

#include "resource.h"

int resource_game_clock_constructor(resource_t *resource, void *data);
int resource_game_clock_constructor_from_json(resource_t *resource, void *data);
int resource_game_clock_destructor(resource_t *resource);
int resource_game_clock_set(resource_t *resource, void *data);
void *resource_game_clock_get(const resource_t *resource);

#endif /* !R_GAME_CLOCK_H_ */
