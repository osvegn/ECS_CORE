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
    WINDOW,
    R_MAX_VALUE
} resource_type_t;

int window_constructor(resource_t *resource);


#endif /* !RESOURCES_H_*/