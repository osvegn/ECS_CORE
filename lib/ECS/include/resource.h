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

#endif /* !RESOURCE_H_ */
