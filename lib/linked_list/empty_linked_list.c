/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** empty_linked_list
*/

#include "linked_list.h"

bool empty_linked_list(linked_list_t *list)
{
    if (size_linked_list(list))
        return false;
    return true;
}
