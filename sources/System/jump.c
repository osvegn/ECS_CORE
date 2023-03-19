/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/System/jump.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/System
 * Created Date: Wednesday, March 15th 2023, 1:58:10 pm
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

int jump_constructor(system_t *system)
{
    system->type = JUMP_SYSTEM;
    system->run = &jump;
    system->active = true;
    return 0;
}

int jump(void *ptr)
{
    vector_t entities = {0};
    entity_t *entity = 0;
    int rvalue = world_join_entities(ptr, &entities, 2, JUMPABLE, VELOCITY);
    vector2i_t *velocity = 0;

    if (rvalue <= 0)
        return rvalue;
    for (unsigned int i = 0; i < entities.size(&entities); i++) {
        if (IsKeyPressed(KEY_SPACE)) {
            entity = *(entity_t **)entities.at(&entities, i);
            velocity = (vector2i_t *)entity_get_component(entity, VELOCITY)->data;
            velocity->y = -20;
        }
    }
    return 0;
}