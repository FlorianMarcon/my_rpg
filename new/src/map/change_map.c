/*
** EPITECH PROJECT, 2017
** change_map
** File description:
** change_map
*/

#include "map.h"
#include "game.h"

int	change_map(game_t *game, int index)
{
	map_t *map = search_map(game->list_map, index);

	if (map == NULL)
		return (1);
	destroy_map_graph(game->map_graph);
	game->map = map;
	game->map_graph = generate_map_graph(game->map);
	return (0);
}
