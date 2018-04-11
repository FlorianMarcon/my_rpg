/*
** EPITECH PROJECT, 2017
** display_map
** File description:
** display_map
*/

#include "map.h"
#include "graphique.h"
#include <stdbool.h>

void	display_map(map_graph_t *map, window_t *win, bool line)
{
	for (int i = 0; map->arr_floor[i] != NULL; i++)
		sfRenderWindow_drawVertexArray(win->window, map->arr_floor[i], map->state_floor);
	for (int i = 0; map->arr_bottom[i] != NULL; i++)
		sfRenderWindow_drawVertexArray(win->window, map->arr_bottom[i], map->state_bottom);
	for (int i = 0; line == true && map->arr_line[i] != NULL; i++)
		sfRenderWindow_drawVertexArray(win->window, map->arr_line[i], NULL);
}
