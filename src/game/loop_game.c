/*
** EPITECH PROJECT, 2017
** loop_game
** File description:
** loop_game
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "game.h"
#include "map.h"
#include "header.h"

void	teub(player_inv_t *list)
{
	unsigned int i = 0;

	while (list != NULL)
	{
		i++;
		list = list->next;
	}
	fprintf(stderr, "size = %u\n", i);
}
int	loop_game(game_t *game, inv_t *tmp, pause_t *pause)
{
	game->list_inv_player = create_obj_in_inv(game->list_inventory, "whool", game->list_inv_player);
	game->list_inv_player = create_obj_in_inv(game->list_inventory, "ring", game->list_inv_player);
	game->list_inv_player = create_obj_in_inv(game->list_inventory, "sword", game->list_inv_player);
	game->list_inv_player = create_obj_in_inv(game->list_inventory, "sword", game->list_inv_player);
	game->list_inv_player = create_obj_in_inv(game->list_inventory, "potion", game->list_inv_player);
	replace_perso(game, 0, 0);
	while (game->map_graph != NULL && sfRenderWindow_isOpen(game->win->window)) {
		tmp = inventory(game, tmp);
		display(game, tmp);
		if (event(game, pause))
			return (0);
	}
	return (0);
}
