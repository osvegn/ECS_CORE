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

int window_constructor(resource_t *resource, void *data)
{
    window_t *window = data;

    return window_copy_constructor(resource, window);
}

int window_constructor_with_params(resource_t *resource, unsigned int width, unsigned int height, char *title, unsigned int fps)
{
    window_t window = {width, height, title, fps};

    return window_copy_constructor(resource, &window);
}

int window_copy_constructor(resource_t *resource, window_t *w)
{
    window_t *window = malloc(sizeof(window_t));

    if (!window)
        return -1;
    resource->type = WINDOW;
    window->width = w->width;
    window->height = w->height;
    strcpy(window->title, w->title);
    window->fps = w->fps;
    resource->data = (void *)window;
    InitWindow(window->width, window->height, window->title);
    SetTargetFPS(window->fps);
    return 0;
}

void window_destructor(resource_t *resource)
{
    CloseWindow();
    free(resource->data);
}