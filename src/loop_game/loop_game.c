/*
** EPITECH PROJECT, 2017
** loop_game
** File description:
** loop_game
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "graphique.h"

int	loop_game(void)
{
	window_t *win = generate_window(800, 600, 32);

	if (win == NULL)
		return (84);
	while (sfRenderWindow_isOpen(win->window)) {
		while (sfRenderWindow_pollEvent(win->window, &win->event))
		{
			if (win->event.type == sfEvtClosed)
			sfRenderWindow_close(win->window);
		}
		sfRenderWindow_clear(win->window, sfBlack);
		sfRenderWindow_display(win->window);
	}
	free(win);

	return (0);
}
