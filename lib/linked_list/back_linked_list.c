/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** back_linked_list
*/

#include "linked_list.h"

void *back_linked_list(linked_list_t *list)
{
    linked_list_t *tmp = list;

    if (!tmp)
        return NULL;
    while (tmp->next) {
        tmp = tmp->next;
    }
    return tmp->data;
}
