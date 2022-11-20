/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** render_window
*/

#include "resource.h"
#include <stdlib.h>

resource_t *create_render_window(const sfVideoMode mode, const char *title, sfWindowStyle style, sfContextSettings *settings)
{
    resource_t *resource = malloc(sizeof(resource_t));
    sfRenderWindow *window = sfRenderWindow_create(mode, title, style, settings);

    if (!resource || !window)
        return NULL;
    resource->type = RENDER_WINDOW;
    resource->data = NULL;
    resource->data = (void *)window;
    return resource;
}

sfRenderWindow *get_window(resource_t *resource)
{
    if (resource->type != RENDER_WINDOW)
        return NULL;
    return (sfRenderWindow *)resource->data;
}
