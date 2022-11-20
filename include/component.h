/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** component
*/

#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <stddef.h>
#include <SFML/Graphics.h>

typedef enum component_type_e {
    COMPONENT_UNDEFINED,
    POSITION,
    MAX_COMPONENT_VALUE
} component_type_t;

typedef struct component_s {
    component_type_t type;
    void *data;
} component_t;

#endif /* !COMPONENT_H_ */
