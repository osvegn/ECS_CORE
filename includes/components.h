/*
 * Filename: /workspaces/our_rpg/includes/components.h
 * Path: /workspaces/our_rpg/includes
 * Created Date: Sunday, January 15th 2023, 3:59:05 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#ifndef COMPONENTS_H_
#define COMPONENTS_H_

#include "component.h"
#include "vector2i.h"
#include "raylib.h"

/// @brief Component types
typedef enum component_type_e {
    C_UNDEFINED,
    C_POSITION,
    C_VELOCITY,
    C_DISPLAYABLE,
    C_SIZE,
    C_CLICKABLE,
    C_CLICKED,
    C_ACTION,
    C_CONTROLLABLE,
    C_WEIGHT,
    C_GRAVITABLE,
    C_JUMPABLE,
    C_COLLIDABLE,
    C_COLOR,
    C_OBSTACLE,
    C_MAX_VALUE
} component_type_t;

/// @brief This function is used to construct a position component
/// @param component The component to construct
/// @param pos The position to set
/// @return 0
/// @details **Example:**
/// @code
/// int main(void) {
///     component_t component;
///     vector2i_t pos = {0, 0};
///
///     component_position_constructor(&component, pos);
///     component_destructor(&component);
///     return 0;
/// }
/// @endcode
int component_position_constructor(component_t *component, vector2i_t pos);

/// @brief This function is used to set the position of a position component
/// @param component The component to set
/// @param pos The position to set
/// @details **Example:**
/// @code
/// int main(void) {
///     component_t component;
///     vector2i_t pos = {0, 0};
///
///     component_position_constructor(&component, pos);
///     pos.x = 1;
///     pos.y = 1;
///     component_position_set(&component, pos);
///     component_destructor(&component);
///     return 0;
/// }
/// @endcode
void component_position_set(component_t *component, const vector2i_t pos);

/// @brief This function is used to get the position of a position component
/// @param component The component to get
/// @return The position of the component
/// @details **Example:**
/// @code
/// int main(void) {
///     component_t component;
///     vector2i_t pos = {0, 0};
///
///     component_position_constructor(&component, pos);
///     pos = component_position_get(&component);
///     component_destructor(&component);
///     return 0;
/// }
/// @endcode
vector2i_t *component_position_get(const component_t *component);

int component_velocity_constructor(component_t *component, vector2i_t vel);
void component_velocity_set(component_t *component, const vector2i_t vel);
vector2i_t *component_velocity_get(const component_t *component);

/// @brief This function is used to construct a displayable component
/// @param component The component to construct
/// @return 0
/// @details **Example:**
/// @code
/// int main(void) {
///     component_t component;
///
///     component_displayable_constructor(&component);
///     component_destructor(&component);
///     return 0;
/// }
/// @endcode
int component_displayable_constructor(component_t *component);

/// @brief This function is used to initialize a clickable component
/// @param component The component to initialize
/// @return 0
/// @details **Example:**
/// @code
/// int main(void) {
///     component_t component;
///
///     clickable_constructor(&component);
///     component_destructor(&component);
///     return 0;
/// }
/// @endcode
int component_clickable_constructor(component_t *component);

/// @brief This function is used to initialize the clicked component.
/// @param component The component to initialize
/// @return 0
/// @details **Example:**
/// @code
/// int main(void) {
///     component_t component;
///
///     component_clicked_constructor(&component);
///     component_destructor(&component);
///     return 0;
/// }
/// @endcode
int component_clicked_constructor(component_t *component);

/// @brief The action component constructor
/// @param component The component to construct
/// @param data The data to store in the component
/// @return 0
/// @details **Example:**
/// @code
/// int main(void) {
///     component_t component;
///     void *data = NULL;
///
///     component_action_constructor(&component, data);
///     component_destructor(&component);
///     return 0;
/// }
/// @endcode
int component_action_constructor(component_t *component, void *data);

/// @brief Get the data stored in the component
/// @param component The component to get the data from
/// @return The data stored in the component
/// @details **Example:**
/// @code
/// int main(void) {
///     component_t component;
///     void *data = NULL;
///
///     component_action_constructor(&component, data);
///     void *data = component_action_get(&component);
///     component_destructor(&component);
///     return 0;
/// }
/// @endcode
void *component_action_get(const component_t *component);

/// @brief Set the data stored in the component
/// @param component The component to set the data in
/// @param data The data to store in the component
/// @details **Example:**
/// @code
/// int main(void) {
///     component_t component;
///     int data = 42;
///
///     component_action_constructor(&component, NULL);
///     component_action_set(&component, &data);
///     component_destructor(&component);
///     return 0;
/// }
/// @endcode
void component_action_set(component_t *component, void *data);

/// @brief This function is used to construct a controllable component
/// @param component The component to construct
/// @return 0
/// @details **Example:**
/// @code
/// int main(void) {
///     component_t component;
///
///     component_controllable_constructor(&component);
///     component_destructor(&component);
///     return 0;
/// }
/// @endcode
int component_controllable_constructor(component_t *component);

/// @brief This function is used to create a size component
/// @param component The component to create
/// @param s The size of the component
/// @return 0 if the component was created, -1 otherwise
/// @details **Example:**
/// @code
/// int main(void) {
///     component_t component;
///     vector2i_t size = {10, 10};
///
///     component_size_constructor(&component, size);
///     component_destroy(&component);
///     return 0;
/// }
/// @endcode
int component_size_constructor(component_t *component, vector2i_t s);

void component_size_set(component_t *component, const vector2i_t s);

void *component_size_get(const component_t *component, vector2i_t *s);


int component_gravitable_constructor(component_t *component);

int weight_constructor(component_t *component, void *data);
void *weight_get(const component_t *component);
void weight_set(component_t *component, void *data);

int component_color_constructor(component_t *component, Color color);
Color *component_get_color(component_t *component, Color *color);
int component_set_color(component_t *component, Color color);

int component_clickable_constructor(component_t *component);
int component_collidable_constructor(component_t *component);
int component_jumpable_constructor(component_t *component);
int component_obstacle_constructor(component_t *component);

#endif /* !COMPONENTS_H_ */
