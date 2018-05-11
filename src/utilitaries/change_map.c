/*
** EPITECH PROJECT, 2017
** change_map
** File description:
** change_map
*/

#include "map.h"
#include "game.h"

int	change_map(game_t *game)
{
	map_t *map;
	int here = game->map->map[game->perso->x][game->perso->y];

	if (here > 20 || here <= 0)
		return (0);
	if ((map = search_map(game->list_map, here)) == NULL)
		return (1);
	destroy_map_graph(game->map_graph);
	game->map = map;
	game->map_graph = generate_map_graph(game->map, game);
	return (0);
}
