/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/System/display.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/System
 * Created Date: Sunday, February 12th 2023, 6:18:12 pm
 * Author: Thomas
 *
 * Copyright (c) 2023 Your Company
 */

#include "world.h"
#include "systems.h"
#include "components.h"
#include "raylib.h"

int display_constructor(system_t *system)
{
    system->type = DISPLAY;
    system->run = &display;
    system->active = true;
    return 0;
}

int display(void *ptr)
{
    vector_t entities = {0};
    entity_t *entity = 0;
    int rvalue = world_join_entities(ptr, &entities, 1, DISPLAYABLE, POSITION, SIZE);
    vector2i_t position = {0};
    vector2i_t size = {0};

    if (rvalue <= 0)
        return rvalue;
    BeginDrawing();
    ClearBackground(RAYWHITE);
    for (unsigned int i = 0; i < entities.size(&entities); i++) {
        entity = *(entity_t **)entities.at(&entities, i);
        position = *(vector2i_t *){entity_get_component(entity, POSITION)->data};
        size = *(vector2i_t *){entity_get_component(entity, SIZE)->data};
        DrawRectangle(position.x, position.y, size.x, size.y, RED);
    }
    EndDrawing();
    return 0;
}