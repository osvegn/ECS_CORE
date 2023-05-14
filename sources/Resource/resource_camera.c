/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/Resource/resource_camera.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/Resource
 * Created Date: Sunday, March 19th 2023, 6:58:24 pm
 * Author: Thomas
 * 
 * Copyright (c) 2023 Your Company
 */

#include "resources.h"
#include "raylib.h"
#include "json.h"
#include "world_logger.h"
#include <stdlib.h>

static int resource_is_camera(const resource_t *resource)
{
    if (resource->type != R_CAMERA)
        return 1;
    return 0;
}

int resource_camera_constructor(resource_t *resource, void *data)
{
    int rvalue = 0;

    resource->type = R_CAMERA;
    resource->data = malloc(sizeof(Camera2D));
    resource->destructor = &resource_camera_destructor;
    rvalue = resource_camera_set(resource, data);
    log_info("Camera resource created.");
    return rvalue;
}

int resource_camera_destructor(resource_t *resource)
{
    if (resource->data)
        free(resource->data);
    log_info("Camera resource destroyed.");
    return 0;
}

int resource_camera_set(resource_t *resource, void *data)
{
    Camera2D *camera = 0;
    json_object *json = json_tokener_parse((char *)data);

    if (!resource_is_camera(resource) || !json)
        return -1;
    // configure camera def
    return 0;
}

void *resource_camera_get(const resource_t *resource)
{
    if (!resource_is_camera(resource))
        return 0;
    return resource->data;
}
