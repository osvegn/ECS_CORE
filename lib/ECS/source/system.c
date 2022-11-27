/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** system
*/

#include "system.h"

system_t construct_system(int (*system)(void *), unsigned int type)
{
    return systems[type];
}