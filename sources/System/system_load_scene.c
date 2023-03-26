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
#include "systems.h"
#include "resources.h"
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
    update_entities(world, json);
    json_object_put(json);
    return 0;
}
