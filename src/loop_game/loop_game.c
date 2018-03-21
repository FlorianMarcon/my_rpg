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

map_t	*generate_map(char *path);

void	display_map(map_t *map, window_t *win)
{
	int i = 0;

	while (map->arr_bottom[i] != NULL) {
		sfRenderWindow_drawVertexArray(win->window, map->arr_bottom[i], map->state_bottom);
		i++;
	}
	i = 0;
	while (i != (map->width - 1) * (map->height - 1) && map->arr_vertex[i] != NULL) {
		if (map->state->texture != NULL) {
			sfRenderWindow_drawVertexArray(win->window, map->arr_vertex[i], map->state);
		}
		i++;
	}
}
int	loop_game(char *path)
{
	window_t *win = generate_window(1280, 800, 32);
	map_t *map = generate_map(path);

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
