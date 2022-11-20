/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** push_back_linked_list
*/

#include "linked_list.h"

int push_back_linked_list(linked_list_t *list, void *data)
{
    linked_list_t *tmp = list;
    linked_list_t *node = malloc(sizeof(linked_list_t));

    if (!node)
        return -1;
    while (tmp && tmp->next) {
        tmp = tmp->next;
    }
    node->data = data;
    node->next = NULL;
    node->previous = tmp;
    tmp->next = node;
    return 0;
}
