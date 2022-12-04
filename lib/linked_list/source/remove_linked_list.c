/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** remove_linked_list
*/

#include "linked_list.h"

int remove_linked_list(linked_list_t *list, unsigned int index)
{
    linked_list_t *tmp = list;
    linked_list_t *next = NULL;
    linked_list_t *prev = NULL;
    unsigned int i = 0;

    while (tmp && tmp->next && i < index) {
        tmp = tmp->next;
        i++;
    }
    if (i < index)
        return -1;
    prev = tmp->previous;
    next = tmp->next;
    prev->next = next;
    next->previous = prev;
    if (tmp->data)
        free(tmp->data);
    if (tmp)
        free(tmp);
    return 0;
}
