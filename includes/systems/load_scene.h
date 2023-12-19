/**
* Filename: load_scene.h
* Path: include/systems
* Created Date: Thuesday, December 19th 2023, 11:37am
* Author: osvegn
*
* Copyright (c) 2023 our_rpg
*/

#ifndef LOAD_SCENE_H_
#define LOAD_SCENE_H_

#include "system.h"

int system_load_scene_constructor(system_t *system);
int system_load_scene_run(void *ptr);

#endif // LOAD_SCENE_H_
