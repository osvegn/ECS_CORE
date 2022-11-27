/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** entity
*/

#ifndef ENTITY_H_
#define ENTITY_H_

#include "linked_list.h"

typedef struct entity_s {
    unsigned int id;
    char name[256];
    linked_list_t *components;
} entity_t;

#endif /* !ENTITY_H_ */
