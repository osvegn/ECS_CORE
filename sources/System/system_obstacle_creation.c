/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/System/createObstacle.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/System
 * Created Date: Friday, March 17th 2023, 9:14:38 am
 * Author: Thomas
 * 
 * Copyright (c) 2023 Your Company
 */

#include "world.h"
#include "world_entity.h"
#include "systems.h"
#include "raylib.h"
#include "vector2i.h"
#include "components.h"
#include "resources.h"

int system_obstacle_creation_constructor(system_t *system)
{
    system->run = system_obstacle_creation_run;
    system->type = S_OBSTACLE_CREATION;
    system->active = true;
    return 0;
}

static int system_remove_obstacle(world_t *world, resource_t *resource)
{
    entity_t *entity = 0;
    vector_t entities = {0};
    vector2i_t *pos = 0;
    vector2i_t *size = 0;

    world_join_entities(world, &entities, 1, C_OBSTACLE);
    for (unsigned int i = 0; i < entities.size(&entities); i++) {
        entity = *(entity_t **)entities.at(&entities, i);
        pos = entity_get_component(entity, C_POSITION)->data;
        size = entity_get_component(entity, C_SIZE)->data;
        if (pos->x <= GetMouseX() + (Camera2D *){resource->data}->target.x - (Camera2D *){resource->data}->offset.x && pos->x + size->x >= GetMouseX() + (Camera2D *){resource->data}->target.x - (Camera2D *){resource->data}->offset.x &&
            pos->y <= GetMouseY() + (Camera2D *){resource->data}->target.y - (Camera2D *){resource->data}->offset.y && pos->y + size->y >= GetMouseY()  + (Camera2D *){resource->data}->target.y - (Camera2D *){resource->data}->offset.y) {
            world_remove_entity_by_id(world, entity->id);
            return 0;
        }
    }
    return 0;
}

int system_obstacle_creation_run(void *ptr)
{
    entity_t entity = {0};
    component_t *component = 0;
    vector2i_t pos = {0};
    resource_t *resource = world_get_resource_by_type(ptr, R_CAMERA);

    if (resource == 0)
        return -1;
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        pos.x = GetMouseX() + (Camera2D *){resource->data}->target.x - (Camera2D *){resource->data}->offset.x;
        pos.y = GetMouseY() + (Camera2D *){resource->data}->target.y - (Camera2D *){resource->data}->offset.y;
        pos.x = pos.x - (pos.x % 50);
        pos.y = pos.y - (pos.y % 50);
        obstacle_constructor(&entity, pos);
        world_add_entity(ptr, &entity);
    }
    if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
        system_remove_obstacle(ptr, resource);
    }
    return 0;
}
