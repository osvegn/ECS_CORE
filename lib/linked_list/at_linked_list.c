/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** at_linked_list
*/

#include "linked_list.h"

void *at_linked_list(linked_list_t *list, unsigned int index)
{
    linked_list_t *tmp = list;
    unsigned int i = 0;

    if (!tmp)
        return NULL;
    while (tmp->next && i < index) {
        tmp = tmp->next;
        i++;
    }
    if (!tmp->next && i < index)
        return NULL;
    return tmp->data;
}
