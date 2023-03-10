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
    WINDOW,
    R_MAX_VALUE
} resource_type_t;

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
int window_constructor(resource_t *resource);

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
int window_constructor_with_params(resource_t *resource, unsigned int width, unsigned int height, char *title, unsigned int fps);

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
int window_copy_constructor(resource_t *resource, window_t *w);

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
void window_destructor(resource_t *resource);


#endif /* !RESOURCES_H_*/