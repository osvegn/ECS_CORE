/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/includes/resources.h
 * Path: /home/thomas/Documents/Perso/our_rpg/includes
 * Created Date: Sunday, February 12th 2023, 5:32:35 pm
 * Author: Thomas
 * 
 * Copyright (c) 2023 Your Company
 */

#ifndef RESOURCES_H_
#define RESOURCES_H_

#include "resource.h"
#include "window.h"

typedef enum resource_type_e {
    R_UNDEFINED,
    R_WINDOW,
    R_GRAVITY,
    R_MAX_VALUE
} resource_type_t;

/// @brief This function is used to create a window resource
/// @param resource The resource to create
/// @param data The data to use to create the resource
/// @return 0 if the resource was created, -1 otherwise
/// @details **Example**
/// @code
///    int main(void)
///    {
///        resource_t window;
///        window_t w = {1920, 1080, "Our RPG", 60};
///
///        if (resource_window_constructor(&window, &w) == -1)
///            return 84;
///        while (!WindowShouldClose()) {
///            BeginDrawing();
///            ClearBackground(RAYWHITE);
///            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
///            EndDrawing();
///        }
///        resource_window_destructor(&window);
///        return 0;
///    }
/// @endcode
int resource_window_constructor(resource_t *resource, void *data);

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
///        if (resource_window_constructor_with_params(&window, 800, 450, "Our RPG", 60) == -1)
///            return 84;
///        while (!WindowShouldClose()) {
///            BeginDrawing();
///            ClearBackground(RAYWHITE);
///            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
///            EndDrawing();
///        }
///        resource_window_destructor(&window);
///        return 0;
///    }
/// @endcode
int resource_window_constructor_with_params(resource_t *resource, unsigned int width, unsigned int height, char *title, unsigned int fps);

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
///        if (resource_window_copy_constructor(&window, &w) == -1)
///            return 84;
///        while (!WindowShouldClose()) {
///            BeginDrawing();
///            ClearBackground(RAYWHITE);
///            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
///            EndDrawing();
///        }
///        resource_window_destructor(&window);
///        return 0;
///    }
/// @endcode
int resource_window_copy_constructor(resource_t *resource, window_t *w);

/// @brief This function is used to close the window and free the memory allocated for the resource
/// @param resource The resource to free
/// @details **Example**
/// @code
///    int main(void)
///    {
///        resource_t window;
///
///        if (resource_window_constructor(&window) == -1)
///            return 84;
///        resource_window_destructor(&window);
///        return 0;
///    }
/// @endcode
void resource_window_destructor(resource_t *resource);

int resource_gravity_constructor(resource_t *resource, void *data);
void *resource_gravity_get(const resource_t *resource);
void resource_gravity_set(resource_t *resource, void *data);

#endif /* !RESOURCES_H_*/