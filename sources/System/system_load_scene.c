/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/sources/System/system_load_scene
 * Path: /home/thomas/Documents/Perso/our_rpg/sources/System
 * Created Date: Tuesday, March 21st 2023, 9:40:17 am
 * Author: Thomas
 *
 * Copyright (c) 2023 Your Company
 */

#include "world.h"
#include "world_system.h"
#include "world_resource.h"
#include "world_entity.h"
#include "systems.h"
#include "resources.h"
#include "components.h"
#include <json-c/json.h>

int system_load_scene_constructor(system_t *system)
{
    system->run = system_load_scene_run;
    system->type = S_LOAD_SCENE;
    system->active = true;
    return 0;
}

static int update_systems(world_t *world, json_object *systems)
{
    char *systems_types[] = {
        "S_LOAD_SCENE",
        "S_DISPLAY",
        "S_WINDOWS_MANAGER",
        "S_MOVEMENT",
        "S_MOVE_CONTROLLABLE",
        "S_GRAVITY",
        "S_JUMP",
        "S_OBSTACLE_CREATION",
        "S_CAMERA",
        "S_RELOAD_CONFIG",
        0
    };
    int (*constructors[])(system_t *) = {
        &system_load_scene_constructor,
        &system_display_constructor,
        &system_windows_manager_constructor,
        &system_movement_constructor,
        &system_move_controllable_constructor,
        &system_gravity_constructor,
        &system_jump_constructor,
        &system_obstacle_creation_constructor,
        &system_camera_constructor,
        &system_reload_config_constructor,
        0
    };
    system_t system = {0};
    json_object *tmp = 0;

    while (world->system_list.size(&world->system_list) > 0) {
        printf("remove system type: %i\n", (system_t *){world->system_list.back(&world->system_list)}->type);
        world->system_list.pop_back(&world->system_list);
    }
    printf("systems: %s\n", json_object_to_json_string(systems));
    for (int i = 0; i < json_object_array_length(systems); i++) {
        tmp = json_object_array_get_idx(systems, i);
        for (int j = 0; systems_types[j]; j++) {
            if (strcmp(json_object_get_string(tmp), systems_types[j]) == 0) {
                constructors[j](&system);
                world_add_system(world, &system);
                printf("Add system: %s\n", systems_types[j]);
                break;
            }
            if (!systems_types[j + 1])
                printf("System not found: %s\n", json_object_get_string(tmp));
        }
        printf("\tsystems %i: %s\n", i, json_object_to_json_string(tmp));
    }
    return 0;
}

static int update_resources(world_t *world, json_object *resources)
{
    char *resources_types[] = {
        "R_WINDOW",
        "R_GRAVITY",
        "R_CAMERA",
        "R_SCENE_FILENAME",
        0
    };
    int (*constructors[])(resource_t *, void *) = {
        &resource_window_constructor,
        &resource_gravity_constructor,
        &resource_camera_constructor,
        &resource_scene_filename_constructor,
        0
    };
    resource_t resource = {0};
    json_object *tmp = 0;
    void *data = 0;

    while (world->resource_list.size(&world->resource_list) > 0) {
        printf("remove resource type: %i\n", (resource_t *){world->resource_list.back(&world->resource_list)}->type);
        (resource_t *){world->resource_list.back(&world->resource_list)}->destructor(world->resource_list.back(&world->resource_list));
        world->resource_list.pop_back(&world->resource_list);
    }
    for (int i = 0; i < json_object_array_length(resources); i++) {
        tmp = json_object_array_get_idx(resources, i);
        for (int j = 0; resources_types[j]; j++) {
            if (strcmp(json_object_get_string(json_object_object_get(tmp, "type")), resources_types[j]) == 0) {
                char *wooow = json_object_to_json_string(json_object_object_get(tmp, "data"));
                printf("wooow: %s\n", wooow);
                constructors[j](&resource, json_object_to_json_string(json_object_object_get(tmp, "data")));
                world_add_resource(world, &resource);
                printf("Add resource: %s\n", resources_types[j]);
                break;
            }
            if (!resources_types[j + 1])
                printf("Resource not found: %s\n", json_object_get_string(tmp));
        }
        printf("\tresources %i: %s\n", i, json_object_to_json_string(tmp));
    }
    return 0;
}

static int update_entities(world_t *world, json_object *entities)
{
    const char *components_types[] = {
        "C_POSITION",
        "C_VELOCITY",
        "C_CONTROLLABLE",
        "C_SIZE",
        "C_DISPLAYABLE",
        "C_GRAVITABLE",
        "C_JUMPABLE",
        "C_COLLIDABLE",
        0
    };
    int (*constructors[])(component_t *, void *) = {
        &component_position_constructor,
        &component_velocity_constructor,
        &component_controllable_constructor,
        &component_size_constructor,
        &component_displayable_constructor,
        &component_gravitable_constructor,
        &component_jumpable_constructor,
        &component_collidable_constructor,
        0
    };
    entity_t entity = {0};
    component_t component = {0};
    json_object *tmp = 0;
    void *data = 0;

    while (world->entity_list.size(&world->entity_list) > 0) {
        printf("remove entity id: %i\n", (entity_t *){world->entity_list.back(&world->entity_list)}->id);
        entity_t *ptr = world->entity_list.back(&world->entity_list);
        while (ptr->components.size(&ptr->components) > 0) {
            component_destructor(ptr->components.back(&ptr->components));
            ptr->components.pop_back(&ptr->components);
        }
        world->entity_list.pop_back(&world->entity_list);
    }
    for (unsigned int i = 0; i < json_object_array_length(entities); i++) {
        printf("add entity\n");
        tmp = json_object_object_get(json_object_array_get_idx(entities, i), "components");
        entity_constructor(&entity);
        for (unsigned int j = 0; j < json_object_array_length(tmp); j++) {
            printf("add component\n");
            for (unsigned int k = 0; components_types[k]; k++) {
                if (strcmp(json_object_get_string(json_object_object_get(json_object_array_get_idx(tmp, j), "type")), components_types[k]) == 0) {
                    constructors[k](&component, json_object_to_json_string(json_object_object_get(json_object_array_get_idx(tmp, j), "data")));
                    entity_add_component(&entity, &component);
                    break;
                }
                if (!components_types[k + 1])
                    printf("Component not found\n");
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
    printf("scene_filename: %s\n", scene_filename->data);
    json = json_object_from_file(scene_filename->data);
    if (json == 0)
        return -2;
    printf("Loading scene: %s\n", scene_filename->data);
    printf("Scene loaded: %s\n", json_object_to_json_string(json));
    update_resources(world, json_object_object_get(json_object_object_get(json, "world"), "resources"));
    update_systems(world, json_object_object_get(json_object_object_get(json, "world"), "systems"));
    update_entities(world, json_object_object_get(json_object_object_get(json, "world"), "entities"));
    json_object_put(json);
    return 0;
}
