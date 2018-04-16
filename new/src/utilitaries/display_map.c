/*
** EPITECH PROJECT, 2017
** display_map
** File description:
** display_map
*/

#include "map.h"
#include "graphique.h"
#include <stdbool.h>

void	display_floor(map_graph_t *map, window_t *win)
{
	int x = 0;
	int y = 0;

	(void)x;
	(void)y;
	for (int i = 0; map->arr_floor[i] != NULL; i++) {
		if (map->map->map[y][x] < 20 && map->map->map[y][x] > 0)
			sfRenderWindow_drawVertexArray(win->window, map->arr_floor[i], map->state_telep);
		else
			sfRenderWindow_drawVertexArray(win->window, map->arr_floor[i], map->state_floor);
		x++;
		if (x >= map->map->width) {
			y++;
			x = 0;
		}
	}
}
void	display_map(map_graph_t *map, window_t *win, bool line)
{
	linked_list_t *list = map->list_obj;
	sprite_t *spr;

	display_floor(map, win);
//	for (int i = 0; map->arr_floor[i] != NULL; i++)
//		sfRenderWindow_drawVertexArray(win->window, map->arr_floor[i], map->state_floor);
	for (int i = 0; map->arr_bottom[i] != NULL; i++)
		sfRenderWindow_drawVertexArray(win->window, map->arr_bottom[i], map->state_bottom);
	for (int i = 0; line == true && map->arr_line[i] != NULL; i++)
		sfRenderWindow_drawVertexArray(win->window, map->arr_line[i], NULL);
	while (list != NULL) {
		spr = (sprite_t *)list->data;
		if (spr != NULL || spr->sprite != NULL)
			sfRenderWindow_drawSprite(win->window, spr->sprite, NULL);
		list = list->next;
	}
}
