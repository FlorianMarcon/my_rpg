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

sfSprite	*generate_sprite_from_file(char *path);

void	display_sprite(sfRenderWindow *win, sfSprite *spr, sfRenderStates *sta);

sfRenderStates 	*generate_state(char *str, char *shader);

#endif
