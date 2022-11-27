/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** system
*/

#include "system.h"

static const system_t systems[] =
{
    {
        .type = SYSTEM_UNDEFINED,
        .run = NULL
    },
    {
        .type = DISPLAY_WINDOW,
        .run = &display_window
    },
    {
        .type = MAX_SYSTEM_VALUE,
        .run = NULL
    }
};

system_t construct_system(unsigned int type)
{
    return systems[type];
}