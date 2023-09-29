/*
 * Filename: system_handle_click.c
 * Path: sources/System
 * Created Date: Friday, September 29th 2023, 12:56:22 am
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#include "systems.h"
#include "vector.h"
#include "world_entity.h"
#include "world_resource.h"
#include "resources.h"
#include "components.h"
#include <raylib.h>

int system_handle_click_constructor(system_t *system)
{
    system->type = S_HANDLE_CLICK;
    system->run = &system_handle_click;
    system->active = true;
    return 0;
}

int system_handle_click(void *world)
{
    vector_t entities = {0};
    int rvalue = world_join_entities(world, &entities, 1, C_CLICKABLE);
    resource_t *r = world_get_resource_by_type(world, R_CAMERA);
    entity_t *e = 0;
    component_t *c = 0;
    Vector2 mouse_position = GetMousePosition();
    Vector2 old_mouse_position = {0};
    if (r) {
        Vector2 camera_position = (Camera2D *){r->data}->target;

        mouse_position.x += camera_position.x;
        mouse_position.y += camera_position.y;
        camera_position = (Camera2D *){r->data}->offset;
        mouse_position.x -= camera_position.x;
        mouse_position.y -= camera_position.y;
    }
    old_mouse_position = mouse_position;
    
    if (!IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        return (0);
    }
    for (unsigned int i = 0; i < entities.size(&entities); i++) {
        mouse_position = old_mouse_position;
        e = *(entity_t **)entities.at(&entities, i);
        if (entity_contains_component_by_type(e, C_POSITION) && entity_contains_component_by_type(e, C_SIZE)) {
            c = entity_get_component(e, C_POSITION);
            mouse_position.x -= (ecs_vector2f_t *){c->data}->x;
            mouse_position.y -= (ecs_vector2f_t *){c->data}->y;
            if (mouse_position.x < 0 || mouse_position.y < 0)
                continue;
            c = entity_get_component(e, C_SIZE);
            if (mouse_position.x > (ecs_vector2i_t *){c->data}->x || mouse_position.y > (ecs_vector2i_t *){c->data}->y)
                continue;
            printf("Click!\n");

        } else {
            printf("Click! (without position or size)\n");
        }
    }
    return 0;
}
