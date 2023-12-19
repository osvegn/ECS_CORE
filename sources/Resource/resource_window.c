/*
 * Filename: window_resource.c
 * Path: sources/Resource 
 * Created Date: Sunday, February 12th 2023, 5:27:54 pm
 * Author: Thomas
 *
 * Copyright (c) 2023 our_rpg
 */

#include "json.h"
#include "resources.h"
#include "utils/ecs_window.h"
#include "world_logger.h"
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
    resource->data = malloc(sizeof(ecs_window_t));
    if (!resource->data) {
        log_fatal("Could not allocate memory for window resource.");
        return -1;
    }
    resource->destructor = &resource_window_destructor;
    if (!data) {
        data = &(ecs_window_t){.fps=60, .height=640, .width=840, .name="Default title"};
    }
    rvalue = resource_window_set(resource, data);
    log_info("Window resource created.");
    return rvalue;
}

int resource_window_constructor_from_json(resource_t *resource, void *data)
{
    ecs_window_t win = {0};
    json_object *obj = json_tokener_parse(data);

    win.width = json_object_get_int(json_object_object_get(obj, "width"));
    win.height = json_object_get_int(json_object_object_get(obj, "height"));
    win.fps = json_object_get_int(json_object_object_get(obj, "fps"));
    win.name = malloc(sizeof(char) * 256);
    if (!win.name) {
        log_fatal("Could not allocate memory for window title.");
        return -1;
    }
    strncpy(win.name, json_object_get_string(json_object_object_get(obj, "title")), 255);
    return resource_window_constructor(resource, &win);
}

int resource_window_set(resource_t *resource, void *data)
{
    ecs_window_t *win = 0;

    if (!resource_is_window(resource) || !resource->data || !data)
        return -1;
    memcpy(resource->data, data, sizeof(resource_t));
    win = resource->data;
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
    if (resource->data)
        free(resource->data);
    log_info("Window resource destroyed.");
    return 0;
}
