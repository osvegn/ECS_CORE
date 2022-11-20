/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** size_linked_list
*/

#include "linked_list.h"

unsigned int size_linked_list(linked_list_t *list)
{
    linked_list_t *tmp = list;
    unsigned int size = 0;

    while (tmp) {
        tmp = tmp->next;
        size++;
    }
    return size;
}
