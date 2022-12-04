/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** create_linked_list
*/

#include "linked_list.h"

linked_list_t *create_linked_list(void)
{
    linked_list_t *list = malloc(sizeof(linked_list_t));

    if (!list)
        return NULL;
    list->data = NULL;
    list->previous = NULL;
    list->next = NULL;
    return list;
}
