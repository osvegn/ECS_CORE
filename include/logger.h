/*
** EPITECH PROJECT, 2022
** my_my_hunter
** File description:
** logger
*/

#ifndef LOGGER_H_
#define LOGGER_H_

#include <stddef.h>

typedef enum logger_type_e {
    UNDEFINED,
    INFO,
    MINOR,
    MAJOR,
    CRITICAL,
    MAX_LOGGER_VALUE
} logger_type_t;

typedef struct logger_s {
    logger_type_t type;
    char *file_name;
    char *function_name;
    char *info;
} logger_t;

static logger_t static_log = {UNDEFINED, NULL, NULL, NULL};

inline void set_log(logger_t new_log)
{
    static_log = new_log;
}

inline logger_t get_log(void)
{
    return static_log;
}

void display_logs(void);

#endif /* !LOGGER_H_ */
