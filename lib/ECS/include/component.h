/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** component
*/

#ifndef COMPONENT_H_
#define COMPONENT_H_

/// @brief It's the structure of a component. A component is a part of an
/// entity use to describe what is the entity and what it is able to do.
/// Only systems can update component data.
/// Components are only stores in entities.
/// A component contains a type and some data.
typedef struct component_s {

    /// @brief The type of the component. It is used to know if this component
    /// type already exists in a list. It is also used to know how to cast
    /// data.
    unsigned int type;

    /// @brief The data of the component. It stores all informations needed
    /// by the component. Use the type of a component to know how to cast data
    /// to use it properly.
    void *data;
} component_t;

#endif /* !COMPONENT_H_ */
