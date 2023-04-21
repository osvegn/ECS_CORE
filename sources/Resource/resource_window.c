/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/Resource/window_resource.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/Resource
 * Created Date: Sunday, February 12th 2023, 5:27:54 pm
 * Author: Thomas
 *
 * Copyright (c) 2023 Your Company
 */

#include "resources.h"
#include "raylib.h"
#include <stdlib.h>
#include <string.h>
#include "json.h"
#include <stdio.h>

int resource_window_constructor(resource_t *resource, void *data)
{
    json_object *json = json_tokener_parse((char *)data);

    if (!json) {
        printf("Error: json_tokener_parse failed in resource_window_constructor\n");
        return -1;
    }
    window_t window = {json_object_get_int(json_object_object_get(json, "width")),
                       json_object_get_int(json_object_object_get(json, "height")),
                       "rpg",
                       json_object_get_int(json_object_object_get(json, "fps"))};

    printf("windows: %d %d %s %d\n", window.width, window.height, window.title, window.fps);
    json_object_put(json);
    return resource_window_copy_constructor(resource, &window);
}

int resource_window_constructor_with_params(resource_t *resource, unsigned int width, unsigned int height, char title[256], unsigned int fps)
{
    window_t window = {width, height, title, fps};

    return resource_window_copy_constructor(resource, &window);
}

int resource_window_copy_constructor(resource_t *resource, window_t *w)
{
    window_t *window = malloc(sizeof(window_t));

    if (!window)
        return -1;
    resource->type = R_WINDOW;
    window->width = w->width;
    window->height = w->height;
    strcpy(window->title, w->title);
    window->fps = w->fps;
    resource->data = (void *)window;
    resource->destructor = &resource_window_destructor;
    InitWindow(window->width, window->height, window->title);
    SetTargetFPS(window->fps);
    return 0;
}

int resource_window_destructor(resource_t *resource)
{
    CloseWindow();
    free(resource->data);
    return 0;
}
