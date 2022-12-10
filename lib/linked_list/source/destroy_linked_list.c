/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** destroy_linked_list
*/

#include "linked_list.h"

void destroy_linked_list(linked_list_t *list)
{
    if (!list)
        return;
    while (list->next) {
        if (list->previous)
            free(list->previous);
        if (list->data)
            free(list->data);
        list = list->next;
    }
    if (list->previous)
        free(list->previous);
    if (list->data)
        free(list->data);
    if (list)
        free(list);
}
