/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** insert_linked_list
*/

#include "linked_list.h"

/**
 * It takes a linked list node, and a data pointer, and inserts a new node after
 * the given node, with the given data
 * 
 * @param tmp the node we're currently on
 * @param data the data to add to the list
 * 
 * @return -1 if malloc failed, 0 otherwise.
 */
static int update_links(linked_list_t *tmp, void *data)
{
    linked_list_t *node = malloc(sizeof(linked_list_t));

    if (!node)
        return -1;
    node->next = tmp->next;
    node->previous = tmp;
    node->data = data;
    tmp->next = node;
    tmp = node->next;
    tmp->previous = node;
    return 0;
}

int insert_linked_list(linked_list_t *list, unsigned int index, void *data)
{
    linked_list_t *tmp = list;
    unsigned int i = 0;

    while (tmp->next && i < index) {
        tmp = tmp->next;
        i++;
    }
    if (i < index)
        return -1;
    if (update_links(tmp, data) < 0)
        return -1;
    return 0;
}
