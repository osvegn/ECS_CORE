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

int resource_camera_constructor(resource_t *resource, void *data)
{
    Camera2D *camera = malloc(sizeof(Camera2D));

    if (!camera)
        return -1;
    camera->offset = (Vector2){0, 0};
    // camera->offset = (Vector2){GetScreenWidth()/2, GetScreenHeight()/2};
    camera->target = (Vector2){0, 0};
    camera->rotation = 0;
    camera->zoom = 1;
    resource->type = R_CAMERA;
    resource->data = camera;
    resource->destructor = &resource_camera_destructor;
    return 0;
}

int resource_camera_destructor(resource_t *resource)
{
    if (resource->data)
        free(resource->data);
    return 0;
}

int resource_camera_update_offset(resource_t *resource, void *data)
{
    Camera2D *camera = (Camera2D *)resource->data;
    Vector2 *offset = (Vector2 *)data;

    camera->offset = *offset;
    return 0;
}

int resource_camera_update_position(resource_t *resource, void *data)
{
    Camera2D *camera = (Camera2D *)resource->data;
    Vector2 *target = (Vector2 *)data;

    camera->target = *target;
    return 0;
}