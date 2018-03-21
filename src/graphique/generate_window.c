/*
** EPITECH PROJECT, 2017
** generate_window
** File description:
** generate_window
*/

#include "graphique.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

window_t	*generate_window(int width, int height, int bits_per_pixels)
{
	window_t *win = malloc(sizeof(*win));

	if (win == NULL)
		return (NULL);
	win->mode.width = width;
	win->mode.height = height;
	win->mode.bitsPerPixel = bits_per_pixels;
	win->window = sfRenderWindow_create(win->mode, "SFML window", sfResize | sfClose, NULL);
	if (!win->window) {
		free(win);
		return (NULL);
	}
	return (win);
}
