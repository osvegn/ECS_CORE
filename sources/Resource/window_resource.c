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

int window_constructor(resource_t *resource)
{
    window_t *window = malloc(sizeof(window_t));

    if (!window)
        return -1;
    resource->type = WINDOW;
    window->width = 800;
    window->height = 450;
    strcpy(window->title, "Our RPG");
    window->fps = 60;
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