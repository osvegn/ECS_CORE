/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/Resource/resource_scene_filename.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/Resource
 * Created Date: Tuesday, March 21st 2023, 9:45:13 am
 * Author: Thomas
 * 
 * Copyright (c) 2023 Your Company
 */

#include "resources.h"
#include <stdlib.h>
#include <string.h>
#include "json.h"
#include "world_logger.h"

/// @brief Check if the resource is a R_SCENE_FILENAME or not.
/// @param resource The resource to be checked.
/// @return 1 if the resource is a R_SCENE_FILENAME, or 0 otherwise.
/// @note This is a static function. 
static int resource_is_scene_filename(const resource_t *resource)
{
    if (resource->type == R_SCENE_FILENAME)
        return 1;
    log_error("Resource is not scene filename.");
    return 0;
}

int resource_scene_filename_constructor(resource_t *resource, void *data)
{
    int rvalue = 0;

    resource->type = R_SCENE_FILENAME;
    resource->data = 0;
    resource->destructor = &resource_scene_filename_destructor;
    rvalue = resource_scene_filename_set(resource, data);
    log_info("Scene filename resource created.");
    return rvalue;
}

int resource_scene_filename_constructor_from_json(resource_t *resource, void *data)
{
    void *new_data = 0;

    return resource_scene_filename_constructor(resource, new_data);
}

int resource_scene_filename_destructor(resource_t *resource)
{
    if (resource->data)
        free(resource->data);
    log_info("Scene filename resource destroyed.");
    return 0;
}

int resource_scene_filename_set(resource_t *resource, void *data)
{
    if (!resource_is_scene_filename(resource) || !data)
        return -1;
    if (resource->data) {
        if (!strcmp((char *)resource->data, (char *)data)) {
            free(resource->data);
            resource->data = strdup((char *)data);
        }
    } else {
        resource->data = strdup((char *)data);
    }
}

void *resource_scene_filename_get(const resource_t *resource)
{
    if (!resource_is_scene_filename(resource))
        return 0;
    return resource->data;
}
