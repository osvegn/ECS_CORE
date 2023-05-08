/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/includes/resources.h
 * Path: /home/thomas/Documents/Perso/our_rpg/includes
 * Created Date: Sunday, February 12th 2023, 5:32:35 pm
 * Author: Thomas
 * 
 * Copyright (c) 2023 Your Company
 */

#ifndef RESOURCES_H_
#define RESOURCES_H_

#include "resource.h"
#include "window.h"


typedef enum resource_type_e {
    R_UNDEFINED,
    R_WINDOW,
    R_CAMERA,
    R_SCENE_FILENAME,
    R_MAX_VALUE
} resource_type_t;

int resource_window_constructor(resource_t *resource, void *data);
int resource_window_destructor(resource_t *resource);
int resource_window_set(resource_t *resource, void *data);
void *resource_window_get(const resource_t *resource);

int resource_camera_constructor(resource_t *resource, void *data);
int resource_camera_destructor(resource_t *resource);
int resource_camera_set( resource_t *resource, void *data);
void *resource_camera_get(const resource_t *resource);

int resource_scene_filename_constructor(resource_t *resource, void *data);
int resource_scene_filename_destructor(resource_t *resource);
int resource_scene_filename_set(resource_t *resource, void *data);
void *resource_scene_filename_get(const resource_t *resource);

#endif /* !RESOURCES_H_*/