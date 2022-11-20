/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** display_window
*/

#include "world.h"

int display_window(void *data)
{
    world_t *world = (world_t *)data;
    resource_t *resource = NULL;
    sfRenderWindow *window = NULL;

    resource = get_resource_by_type(world, RENDER_WINDOW);
    window = get_window(resource);
    if (sfRenderWindow_isOpen(window))
        sfRenderWindow_display(window);
    return 0;
}
