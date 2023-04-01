/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/System/display.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/System
 * Created Date: Sunday, February 12th 2023, 6:18:12 pm
 * Author: Thomas
 *
 * Copyright (c) 2023 Your Company
 */

#include "world.h"
#include "world_entity.h"
#include "world_resource.h"
#include "systems.h"
#include "components.h"
#include "resources.h"
#include "raylib.h"

int system_display_constructor(system_t *system)
{
    system->type = S_DISPLAY;
    system->run = &system_display;
    system->active = true;
    return 0;
}

int system_display(void *ptr)
{
    vector_t entities = {0};
    entity_t *entity = 0;
    int rvalue = world_join_entities(ptr, &entities, 3, C_DISPLAYABLE, C_POSITION, C_SIZE);
    ecs_vector2i_t position = {0};
    ecs_vector2i_t size = {0};
    Camera2D *camera = world_get_resource_by_type(ptr, R_CAMERA)->data;

    if (rvalue <= 0)
        return rvalue;
    BeginDrawing();
    BeginMode2D(*camera);
    ClearBackground(RAYWHITE);
    for (unsigned int i = 0; i < entities.size(&entities); i++) {
        entity = *(entity_t **)entities.at(&entities, i);
        position = *(ecs_vector2i_t *){entity_get_component(entity, C_POSITION)->data};
        size = *(ecs_vector2i_t *){entity_get_component(entity, C_SIZE)->data};
        DrawRectangle(position.x, position.y, size.x, size.y, RED);
    }
    EndMode2D();
    EndDrawing();
    entities.destructor(&entities);
    return 0;
}