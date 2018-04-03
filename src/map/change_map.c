/*
** EPITECH PROJECT, 2017
** change_map
** File description:
** change_map
*/

#include <stdbool.h>
#include "game.h"

void	change_map(game_t *game)
{
//	map_t *map = game->map;

//	(void)game;
	game->index++;
	game->map = search_map(game->list_map, game->index);
	my_printf("change\n");
	game->change_map = false;
}
