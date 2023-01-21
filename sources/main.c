/*
 * Filename: /workspaces/our_rpg/sources/main.c
 * Path: /workspaces/our_rpg/sources
 * Created Date: Saturday, January 21st 2023, 2:35:06 am
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
