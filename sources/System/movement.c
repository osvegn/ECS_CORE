/*
** EPITECH PROJECT, 2023
** our_rpg [Codespaces]
** File description:
** movement
*/

#include "system.h"
#include "world.h"
#include "components.h"
#include "vector2i.h"

int movement(void *world)
{
    vector_t entities = {0};
    entity_t *entity;
    vector2i_t *components[2];
    int rvalue = join_entities(world, &entities, 2, VELOCITY, POSITION);


    if (rvalue <= 0)
        return rvalue;
    for (unsigned int i = 0; i < entities.size(&entities); i++) {
        entity = entities.at(&entities, i);
        components[0] = get_component(entity, POSITION)->data;
        components[1] = get_component(entity, VELOCITY)->data;
        components[0]->x += components[1]->x;
        components[0]->y += components[1]->y;
    }
    return 0;
}