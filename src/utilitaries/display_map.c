/*
** EPITECH PROJECT, 2017
** display_map
** File description:
** display_map
*/

#include <stdbool.h>
#include "game.h"
#include "map.h"
#include "graphique.h"

void	display_floor(map_graph_t *map, window_t *win)
{
	int x = 0;
	int y = 0;

	for (int i = 0; map->arr_floor[i] != NULL; i++) {
		if (map->map->map[y][x] < 20 && map->map->map[y][x] > 0)
			sfRenderWindow_drawVertexArray(win->window, map->arr_floor[i], map->state_telep);
		else
			sfRenderWindow_drawVertexArray(win->window, map->arr_floor[i], map->state_floor);
		x++;
		if (x >= map->map->width - 1) {
			y++;
			x = 0;
		}
	}
}

void	display_map(game_t *game, window_t *win, bool line)
{
	map_graph_t *map = game->map_graph;
	linked_list_t *list = map->list_obj;
	sprite_t *spr;
	bool player = false;

	display_floor(map, win);
	for (int i = 0; map->arr_bottom[i] != NULL; i++)
		sfRenderWindow_drawVertexArray(win->window, map->arr_bottom[i], map->state_bottom);
	for (int i = 0; line == true && map->arr_line[i] != NULL; i++)
		sfRenderWindow_drawVertexArray(win->window, map->arr_line[i], NULL);
	while (list != NULL) {
		spr = (sprite_t *)list->data;
		if (player == false && spr->y >= game->perso->x + 1) {
			display_perso(game->perso, game->win);
			player = true;
		}
		if (spr != NULL || spr->sprite != NULL)
			sfRenderWindow_drawSprite(win->window, spr->sprite, spr->states);
		list = list->next;
	}
	if (player == false)
		display_perso(game->perso, game->win);
}
