/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** system
*/

#ifndef SYSTEM_H_
#define SYSTEM_H_

typedef enum system_type_e {
    SYSTEM_UNDEFINED,
    DISPLAY_WINDOW,
    MAX_SYSTEM_VALUE
} system_type_t;

typedef struct system_s {
    system_type_t type;
    int (*run)(void *);
} system_t;

system_t construct_system(system_type_t type);

#endif /* !SYSTEM_H_ */
