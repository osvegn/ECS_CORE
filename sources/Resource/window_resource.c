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

/// @brief This function is used to create a window resource
/// @param resource The resource to create
/// @return 0 if the resource was created, -1 otherwise
/// @details **Example**
/// @code
///    int main(void)
///    {
///        resource_t window;
///
///        if (window_constructor(&window) == -1)
///            return 84;
///        while (!WindowShouldClose()) {
///            BeginDrawing();
///            ClearBackground(RAYWHITE);
///            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
///            EndDrawing();
///        }
///        window_destructor(&window);
///        return 0;
///    }
/// @endcode
int window_constructor(resource_t *resource)
{
    window_t window = {800, 450, "Our RPG", 60};

    return window_copy_constructor(resource, &window);
}

/// @brief This function is used to create a window resource
/// @param resource The resource to create
/// @param width The width of the window
/// @param height The height of the window
/// @param title The title of the window
/// @param fps The fps of the window
/// @return 0 if the resource was created, -1 otherwise
/// @details **Example**
/// @code
///    int main(void)
///    {
///        resource_t window;
///
///        if (window_constructor_with_params(&window, 800, 450, "Our RPG", 60) == -1)
///            return 84;
///        while (!WindowShouldClose()) {
///            BeginDrawing();
///            ClearBackground(RAYWHITE);
///            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
///            EndDrawing();
///        }
///        window_destructor(&window);
///        return 0;
///    }
/// @endcode
int window_constructor_with_params(resource_t *resource, unsigned int width, unsigned int height, char *title, unsigned int fps)
{
    window_t window = {width, height, title, fps};

    return window_copy_constructor(resource, &window);
}

/// @brief This function is used to create a window resource
/// @param resource The resource to create
/// @param w The window to copy
/// @return 0 if the resource was created, -1 otherwise
/// @details **Example**
/// @code
///    int main(void)
///    {
///        resource_t window;
///        window_t w = {800, 450, "Our RPG", 60};
///
///        if (window_copy_constructor(&window, &w) == -1)
///            return 84;
///        while (!WindowShouldClose()) {
///            BeginDrawing();
///            ClearBackground(RAYWHITE);
///            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
///            EndDrawing();
///        }
///        window_destructor(&window);
///        return 0;
///    }
/// @endcode
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

/// @brief This function is used to close the window and free the memory allocated for the resource
/// @param resource The resource to free
/// @details **Example**
/// @code
///    int main(void)
///    {
///        resource_t window;
///
///        if (window_constructor(&window) == -1)
///            return 84;
///        window_destructor(&window);
///        return 0;
///    }
/// @endcode
void window_destructor(resource_t *resource)
{
    CloseWindow();
    free(resource->data);
}