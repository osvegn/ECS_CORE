/*
 * Filename:
 * /home/thomas/Documents/Perso/our_rpg/sources/Resource/window_resource.c Path:
 * /home/thomas/Documents/Perso/our_rpg/sources/Resource Created Date: Sunday,
 * February 12th 2023, 5:27:54 pm Author: Thomas
 *
 * Copyright (c) 2023 Your Company
 */

#include "json.h"
#include "raylib.h"
#include "resources.h"
#include "world_logger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// @brief Check if the resource is a R_WINDOW or not.
/// @param resource The resource to be checked.
/// @return 1 if the resource is a R_WINDOW, 0 otherwise.
/// @note This function is static.
static int resource_is_window(const resource_t *resource)
{
    if (resource->type == R_WINDOW)
        return 1;
    log_error("Resource is not window.");
    return 0;
}

int resource_window_constructor(resource_t *resource, void *data)
{
    int rvalue = 0;

    resource->type = R_WINDOW;
    resource->data = malloc(sizeof(window_t));
    if (!resource->data) {
        log_fatal("Could not allocate memory for window resource.");
        return -1;
    }
    resource->destructor = &resource_window_destructor;
    if (!data) {
        data = &(window_t){.fps=60, .height=640, .width=840, .title="Default title"};
    }
    rvalue = resource_window_set(resource, data);
    log_info("Window resource created.");
    return rvalue;
}

int resource_window_set(resource_t *resource, void *data)
{
    window_t *win = 0;

    if (!resource_is_window(resource) || !resource->data || !data)
        return -1;
    memcpy(resource->data, data, sizeof(resource_t));
    win = resource->data;
    InitWindow(win->width, win->height, win->title);
    SetTargetFPS(win->fps);
    return 0;
}

void *resource_window_get(const resource_t *resource)
{
    if (!resource_is_window(resource))
        return 0;
    return resource->data;
}

int resource_window_destructor(resource_t *resource)
{
    CloseWindow();
    if (resource->data)
        free(resource->data);
    log_info("Window resource destroyed.");
    return 0;
}
