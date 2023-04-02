/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/System/system_camera.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/System
 * Created Date: Sunday, March 19th 2023, 7:01:46 pm
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
#include "raymath.h"

int system_camera_constructor(system_t *system)
{
    system->type = S_CAMERA;
    system->run = &system_camera;
    system->active = true;
    return 0;
}

void update_camera(resource_t *resource, ecs_vector2i_t *position)
{
    Vector2 p = {0};
    static float min_speed = 30;
    static float min_effect_length = 10;
    static float fraction_speed = 1;

    p.x = GetScreenWidth() / 2;
    p.y = GetScreenHeight() / 2;
    resource_camera_update_offset(resource, &p);
    p.x = position->x;
    p.y = position->y;
    Vector2 diff = Vector2Subtract(p, (Camera2D *){resource->data}->target);
    float length = Vector2Length(diff);
    if (length > min_effect_length) {
        float speed = fmaxf(fraction_speed * length, min_speed);
        p = Vector2Add((Camera2D *){resource->data}->target, Vector2Scale(diff, speed * GetFrameTime() / sqrt(length)));
        resource_camera_update_position(resource, &p);
    }
}

int system_camera(void *ptr)
{
    vector_t entities = {0};
    entity_t *entity = 0;
    int rvalue = world_join_entities(ptr, &entities, 2, C_CONTROLLABLE, C_POSITION);
    resource_t *resource = world_get_resource_by_type(ptr, R_CAMERA);
    ecs_vector2i_t *position = 0;

    if (rvalue <= 0)
        return rvalue;
    if (resource == 0)
        return -1;
    for (unsigned int i = 0; i < entities.size(&entities); i++) {
        entity = *(entity_t **)entities.at(&entities, i);
        position = (ecs_vector2i_t *)entity_get_component(entity, C_POSITION)->data;
        update_camera(resource, position);
    }
    entities.destructor(&entities);
    return 0;
}