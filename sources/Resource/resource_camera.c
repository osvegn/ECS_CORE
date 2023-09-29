/*
 * Filename: resource_camera.c
 * Path: sources/Resource
 * Created Date: Thursday, September 28th 2023, 2:38:28 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#include "resources.h"
#include <raylib.h>
#include <stdlib.h>

static int resource_is_camera(resource_t *resource)
{
    return (resource->type == R_CAMERA);
}


int resource_camera_constructor(resource_t *resource, void *data)
{
    int rvalue = 0;

    resource->type = R_CAMERA;
    resource->destructor = resource_camera_destructor;
    resource->data = malloc(sizeof(Camera2D));
    if (!resource->data) {
        return -1;
    }
    if (!data) {
        data = &(Camera2D){.offset=(Vector2){GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f}, .rotation=0.0f, .target=(Vector2){0, 0}, .zoom=1.0f};
    }
    rvalue = resource_camera_set(resource, data);
    return rvalue;
}

int resource_camera_constructor_from_json(resource_t *resource, void *data)
{
    return resource_camera_constructor(resource, 0);
}

int resource_camera_destructor(resource_t *resource)
{
    if (resource->data)
        free(resource->data);
    return 0;
}

int resource_camera_set(resource_t *resource, void *data)
{
    if (!resource_is_camera(resource) || !data)
        return -1;
    memcpy(resource->data, data, sizeof(Camera2D));
    return 0;
}
