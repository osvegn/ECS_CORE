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

static int resource_is_scene_filename(const resource_t *resource)
{
    if (resource->type != R_SCENE_FILENAME)
        return 1;
    log_error("Resource is not scene filename.");
    return 0;
}

int resource_scene_filename_constructor(resource_t *resource, void *data)
{
    resource->type = R_SCENE_FILENAME;
    resource->data = 0;
    resource->destructor = &resource_scene_filename_destructor;
    return resource_scene_filename_set(resource, data);
}

int resource_scene_filename_destructor(resource_t *resource)
{
    if (resource->data)
        free(resource->data);
    return 0;
}

int resource_scene_filename_set(const resource_t *resource, void *data)
{
    char *filename = 0;
    json_object *json = json_tokener_parse((char *)data);

    if (!resource_is_scene_filename(resource) || !json)
        return -1;
    filename = strdup(json_object_get_string(json_object_object_get(json, "filename")));
    json_object_put(json);
    if (!filename)
        return -1;
    memcpy(resource->data, &filename, sizeof(char) * (strlen(filename) + 1));
    return 0;
}

void *resource_scene_filename_get(resource_t *resource)
{
    if (!resource_is_scene_filename(resource))
        return 0;
    return resource->data;
}
