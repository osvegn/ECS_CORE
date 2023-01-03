/*
** EPITECH PROJECT, 2023
** our_rpg [Codespaces]
** File description:
** entity_component
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

bool contains_component(entity_t *entity, component_t component)
{
    unsigned int index = find_component(entity, &component);

    if (index < entity->components.size(&entity->components)) {
        return true;
    }
    return false;
}

int add_component(entity_t *entity, component_t component)
{
    unsigned int index = find_component(entity, &component);

    if (index < entity->components.size(&entity->components)) {
        return -1;
    }
    entity->components.emplace_back(&entity->components, &component);
    return 0;
}

int remove_component(entity_t *entity, component_t component)
{
    unsigned int index = find_component(entity, &component);

    if (index < entity->components.size(&entity->components)) {
        entity->components.erase(&entity->components, index);
        return 0;
    }
    return -1;
}

int entity_constructor(entity_t *entity)
{
    static id = 0;

    entity->id = id;
    id++;
    return vector_constructor(&entity->components, sizeof(component_t), 0);
}
