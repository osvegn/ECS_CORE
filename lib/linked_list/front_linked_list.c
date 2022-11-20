/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** front_linked_list
*/

#include "linked_list.h"

void *front_linked_list(linked_list_t *list)
{
    if (!list)
        return NULL;
    return list->data;
}
