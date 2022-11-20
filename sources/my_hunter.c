/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** my_hunter
*/

#include "world.h"

int my_hunter(void)
{
    world_t *world = create_world();
    system_t *system = malloc(sizeof(system_t));
    resource_t *resource = malloc(sizeof(resource_t));

    if (!system || !resource)
        return -1;
    (*system) = construct_system(DISPLAY_WINDOW);
    add_system(world, system);
    resource = create_render_window((sfVideoMode){1920, 1080, 32}, "title", sfDefaultStyle, NULL);
    add_resource(world, resource);
    while (true) {
        run_systems(world);
    }
    return 0;
}
