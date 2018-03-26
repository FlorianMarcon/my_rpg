/*
** EPITECH PROJECT, 2017
** display_map
** File description:
** display_map
*/

#include "map.h"
#include "graphique.h"

void	display_map(map_t *map, window_t *win)
{
	int i = 0;

	while (map->arr_bottom[i] != NULL) {
		sfRenderWindow_drawVertexArray(win->window, map->arr_bottom[i], map->state_bottom);
		i++;
	}
	i = 0;
	while (i != (map->width - 1) * (map->height - 1) && map->arr_vertex[i] != NULL) {
		if (map->state_floor->texture != NULL) {
			sfRenderWindow_drawVertexArray(win->window, map->arr_vertex[i], map->state_floor);
		}
		i++;
	}
}
