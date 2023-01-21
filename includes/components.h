/*
** EPITECH PROJECT, 2023
** our_rpg [Codespaces]
** File description:
** components
*/

#ifndef COMPONENTS_H_
#define COMPONENTS_H_

#include "vector2i.h"

typedef enum component_type_e {
    C_UNDEFINED,
    POSITION,
    VELOCITY,
    C_MAX_VALUE
} component_type_t;

int create_position(component_t *component, vector2i_t pos);
void set_position(component_t *component, const vector2i_t pos);
vector2i_t *get_position(const component_t *component);

int create_velocity(component_t *component, vector2i_t vel);
void set_velocity(component_t *component, const vector2i_t vel);
vector2i_t *get_velocity(const component_t *component);

#endif /* !COMPONENTS_H_ */
