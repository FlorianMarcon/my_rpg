/*
** EPITECH PROJECT, 2017
** graphique.h
** File description:
** graphique.h
*/

#ifndef GRAPH_
#define GRAPH_

#include <SFML/Graphics.h>

typedef struct window {
	sfVideoMode mode;
	sfRenderWindow *window;
	sfEvent event;
}window_t;

window_t	*generate_window(int width, int height, int bits_per_pixels);

#endif
