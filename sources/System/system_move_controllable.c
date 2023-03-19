/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/System/move_controllable.c
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/System
 * Created Date: Friday, March 10th 2023, 11:08:33 pm
 * Author: Thomas
 * 
 * Copyright (c) 2023 Your Company
 */


#include "systems.h"
#include "world_entity.h"
#include "components.h"
#include "raylib.h"

int system_move_controllable_constructor(system_t *system)
{
    system->type = S_MOVE_CONTROLLABLE;
    system->run = &system_move_controllable_run;
    system->active = true;
    return 0;
}

int system_move_controllable_run(void *world)
{
    vector_t entities = {0};
    entity_t *entity = 0;
    component_t *component = 0;
    int rvalue = world_join_entities(world, &entities, 2, C_CONTROLLABLE, C_VELOCITY);

    if (rvalue <= 0)
        return rvalue;
    for (unsigned int i = 0; i < entities.size(&entities); i++) {
        entity = *(entity_t **)entities.at(&entities, i);
        component = entity_get_component(entity, C_VELOCITY);
        ((vector2i_t *)component->data)->x = 0;
        if (IsKeyDown(KEY_Q)) {
            ((vector2i_t *)component->data)->x = -5;
        }
        if (IsKeyDown(KEY_D)) {
            ((vector2i_t *)component->data)->x = 5;
        }
    }
    return 0;
}