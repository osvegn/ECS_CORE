/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/System/system_load_scene
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/System
 * Created Date: Tuesday, March 21st 2023, 9:40:17 am
 * Author: Thomas
 *
 * Copyright (c) 2023 our_rpg
 */

#include "world.h"
#include "world_system.h"
#include "world_resource.h"
#include "world_entity.h"
#include "world_loader_constructors.h"
#include "json.h"

int system_load_scene_constructor(system_t *system)
{
    system->run = system_load_scene_run;
    system->type = S_LOAD_SCENE;
    system->active = true;
    return 0;
}

static int update_systems(world_t *world, json_object *systems)
{
    system_t system = {0};
    json_object *tmp = 0;

    while (world->system_list.size(&world->system_list) > 0) {
        world->system_list.pop_back(&world->system_list);
    }
    for (int i = 0; i < json_object_array_length(systems); i++) {
        tmp = json_object_array_get_idx(systems, i);
        for (int j = 0; systems_types[j]; j++) {
            if (strcmp(json_object_get_string(tmp), systems_types[j]) == 0) {
                systems_constructors[j](&system);
                world_add_system(world, &system);
                break;
            }
        }
    }
    return 0;
}

static int update_resources(world_t *world, json_object *resources)
{
    resource_t resource = {0};
    json_object *tmp = 0;
    void *data = 0;

    while (world->resource_list.size(&world->resource_list) > 0) {
        (resource_t *){world->resource_list.back(&world->resource_list)}->destructor(world->resource_list.back(&world->resource_list));
        world->resource_list.pop_back(&world->resource_list);
    }
    for (int i = 0; i < json_object_array_length(resources); i++) {
        tmp = json_object_array_get_idx(resources, i);
        for (int j = 0; resources_types[j]; j++) {
            if (strcmp(json_object_get_string(json_object_object_get(tmp, "type")), resources_types[j]) == 0) {
                char *wooow = json_object_to_json_string(json_object_object_get(tmp, "data"));
                resources_constructors[j](&resource, json_object_to_json_string(json_object_object_get(tmp, "data")));
                world_add_resource(world, &resource);
                break;
            }
        }
    }
    return 0;
}

static int update_entities(world_t *world, json_object *entities)
{
    entity_t entity = {0};
    component_t component = {0};
    json_object *tmp = 0;
    void *data = 0;

    while (world->entity_list.size(&world->entity_list) > 0) {
        entity_t *ptr = world->entity_list.back(&world->entity_list);
        while (ptr->components.size(&ptr->components) > 0) {
            component_destructor(ptr->components.back(&ptr->components));
            ptr->components.pop_back(&ptr->components);
        }
        world->entity_list.pop_back(&world->entity_list);
    }
    for (unsigned int i = 0; i < json_object_array_length(entities); i++) {
        tmp = json_object_object_get(json_object_array_get_idx(entities, i), "components");
        entity_constructor(&entity);
        for (unsigned int j = 0; j < json_object_array_length(tmp); j++) {
            for (unsigned int k = 0; components_types[k]; k++) {
                if (strcmp(json_object_get_string(json_object_object_get(json_object_array_get_idx(tmp, j), "type")), components_types[k]) == 0) {
                    components_constructors[k](&component, json_object_to_json_string(json_object_object_get(json_object_array_get_idx(tmp, j), "data")));
                    entity_add_component(&entity, &component);
                    break;
                }
            }
        }
        world_add_entity(world, &entity);
    }
    return 0;
}

int system_load_scene_run(void *ptr)
{
    world_t *world = ptr;
    resource_t *scene_filename = world_get_resource_by_type(world, R_SCENE_FILENAME);
    json_object *json = 0;

    if (scene_filename == 0)
        return -1;
    json = json_object_from_file(scene_filename->data);
    if (json == 0)
        return -2;
    update_resources(world, json_object_object_get(json_object_object_get(json, "world"), "resources"));
    update_systems(world, json_object_object_get(json_object_object_get(json, "world"), "systems"));
    update_entities(world, json_object_object_get(json_object_object_get(json, "world"), "entities"));
    json_object_put(json);
    return 0;
}
