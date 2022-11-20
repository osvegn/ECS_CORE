/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** resource
*/

#ifndef RESOURCE_H_
#define RESOURCE_H_

#include <stddef.h>
#include <SFML/Graphics.h>

typedef enum resource_type_e {
    RESOURCE_UNDEFINED,
    RENDER_WINDOW,
    MAX_RESOURCE_VALUE
} resource_type_t;

typedef struct resource_s {
    resource_type_t type;
    void *data;
} resource_t;

sfRenderWindow *get_window(resource_t *resource);
resource_t *create_render_window(const sfVideoMode mode, const char *title, sfWindowStyle style, sfContextSettings *settings);

#endif /* !RESOURCE_H_ */
