/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** linked_list
*/

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdbool.h>
#include <stdlib.h>


/// @brief Creating a new type called linked_list_t.
typedef struct linked_list_s {

    /// @brief A pointer to the data of the node.
    void *data;

    /// @brief A pointer to the next node in the linked list.
    void *next;

    /// @brief A pointer to the previous node in the linked list.
    void *previous;
} linked_list_t;


/// @brief It creates a new linked list
/// @return A pointer to a linked_list_t struct.
linked_list_t *create_linked_list(void);


/// @brief It frees all the memory allocated for the linked list
/// @param list The linked list to destroy.
void destroy_linked_list(linked_list_t *);


/// @brief Return the data at the given index in the linked list.
/// @param list The linked list to get the data from.
/// @param index the index of the element to return
/// @return The data of the node at the given index.
void *at_linked_list(linked_list_t *, unsigned int);


/// @brief Return the data at the front of the list.
/// @param list A pointer to the linked list.
/// @return The data of the first node in the linked list.
void *front_linked_list(linked_list_t *);


/// @brief If the list is not empty, return the last element of the list.
/// @param list the linked list
/// @return The data of the last element of the linked list.
void *back_linked_list(linked_list_t *);


/// @brief If the size of the list is not zero, return false, otherwise return true.
/// @param list The linked list to check.
/// @return A boolean value.
bool empty_linked_list(linked_list_t *);


/// @brief It returns the number of elements in a linked list
/// @param list the linked list to get the size of
/// @return The size of the linked list.
unsigned int size_linked_list(linked_list_t *);


/// @brief It inserts a node at a given index
/// @param list the linked list
/// @param index the index of the node to insert the new node before
/// @param data the data to insert
/// @return -1 if an error occurs, 0 otherwise.
int insert_linked_list(linked_list_t *, unsigned int, void *);


/// @brief Create a new node, find the last node in the list, set the new node's previous
/// pointer to the last node, set the last node's next pointer to the new node, and
/// return 0.
/// @param list The list to add the node to.
/// @param data The data to be added to the linked list.
/// @return -1 if an error occurs, 0 otherwise.
int push_back_linked_list(linked_list_t *, void *);


/// @brief It removes the node at the given index from the list
/// @param list The linked list to remove the node from.
/// @param index the index of the element to remove
/// @return 0 if the element was removed, -1 if the index was out of bounds.
int remove_linked_list(linked_list_t *, unsigned int);

#endif /* !LINKED_LIST_H
