/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** system
*/

#ifndef SYSTEM_H_
#define SYSTEM_H_

typedef struct system_s {
    unsigned int type;
    int (*run)(void *);
} system_t;

system_t construct_system(unsigned int type);

#endif /* !SYSTEM_H_ */
