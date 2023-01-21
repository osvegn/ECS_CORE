/*
 * Filename: /workspaces/our_rpg/lib/ECS/source/entity_component.c
 * Path: /workspaces/our_rpg/lib/ECS/source
 * Created Date: Sunday, January 15th 2023, 3:59:16 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#include "entity.h"

static unsigned int find_component(entity_t *entity, component_t *component)
{
    for (unsigned int i = 0; i < entity->components.size(&entity->components); i++) {
        if (component->type == ((component_t *)entity->components.at(&entity->components, i))->type) {
            return i;
        }
    }
    return entity->components.size(&entity->components);
}

bool entity_contains_component(entity_t *entity, component_t component)
{
    unsigned int index = find_component(entity, &component);

    if (index < entity->components.size(&entity->components)) {
        return true;
    }
    return false;
}

int entity_add_component(entity_t *entity, component_t component)
{
    unsigned int index = find_component(entity, &component);

    if (index < entity->components.size(&entity->components)) {
        return -1;
    }
    entity->components.emplace_back(&entity->components, &component);
    return 0;
}

int entity_remove_component(entity_t *entity, component_t component)
{
    unsigned int index = find_component(entity, &component);

    if (index < entity->components.size(&entity->components)) {
        entity->components.erase(&entity->components, index);
        return 0;
    }
    return -1;
}

component_t *entity_get_component(entity_t *entity, unsigned int type)
{
    if (entity->components.size(&entity->components) <= 0)
        return 0;
    for (unsigned int index = 0; index < entity->components.size(&entity->components); index++) {
        if (((component_t *)entity->components.at(&entity->components, index))->type == type)
            return entity->components.at(&entity->components, index);
    }
    return 0;
}

int entity_constructor(entity_t *entity)
{
    static int id = 0;

    entity->id = id;
    id++;
    return vector_constructor(&entity->components, sizeof(component_t), 0);
}
