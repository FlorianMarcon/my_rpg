/*
** EPITECH PROJECT, 2017
** loop_game
** File description:
** loop_game
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "graphique.h"
#include "map.h"
#include "my_printf.h"
#include "my.h"

int	loop_game(char *path)
{
	window_t *win = generate_window(1280, 800, 32);
	linked_list_t *list = generate_list_map(path);
	map_t *map = (map_t *)list->data;

	if (win == NULL || map == NULL)
		return (84);
	while (sfRenderWindow_isOpen(win->window)) {
		while (sfRenderWindow_pollEvent(win->window, &win->event))
		{
			if (win->event.type == sfEvtClosed)
			sfRenderWindow_close(win->window);
		}
		sfRenderWindow_clear(win->window, sfBlack);
		display_map(map, win);
		sfRenderWindow_display(win->window);
	}
	free(win);

	return (0);
}
