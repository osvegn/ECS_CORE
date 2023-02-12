/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/includes/window.h
 * Path: /home/thomas/Documents/Perso/our_rpg/includes
 * Created Date: Sunday, February 12th 2023, 5:30:29 pm
 * Author: Thomas
 *
 * Copyright (c) 2023 Your Company
 */

#ifndef WINDOW_H_
#define WINDOW_H_

typedef struct window_s {
    unsigned int width;
    unsigned int height;
    char title[256];
    unsigned int fps;
} window_t;

#endif /* !WINDOW_H_ */