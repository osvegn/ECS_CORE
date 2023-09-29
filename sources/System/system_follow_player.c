/*
 * Filename: system_follow_player.c
 * Path: sources/System
 * Created Date: Thursday, September 28th 2023, 3:01:43 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#include "systems.h"
#include "components.h"
#include "vector.h"
#include "world_resource.h"
#include "resources.h"
#include <raylib.h>

int system_follow_player_constructor(system_t *system)
{
    system->type = S_FOLLOW_PLAYER;
    system->run = &system_follow_player;
    system->active = true;
    return 0;
}

int system_follow_player(void *world)
{
    vector_t entities = {0};
    int rvalue = world_join_entities(world, &entities, 1, C_CONTROLLABLE);
    resource_t *camera = world_get_resource_by_type(world, R_CAMERA);
    Camera2D *cam = camera->data;
    entity_t *e = *(entity_t **)entities.at(&entities, 0);
    ecs_vector2f_t *pos = entity_get_component(e, C_POSITION)->data;
    ecs_vector2i_t *size = entity_get_component(e, C_SIZE)->data;

    cam->target.x = pos->x + size->x / 2;
    cam->target.y = pos->y + size->y / 2;
    resource_camera_set(camera, cam);
    return 0;
}
