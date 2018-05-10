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
#include "inventory.h"

int	loop_game(game_t *game)
{
	game->list_inv_player = create_obj_in_inv(game->list_inventory, "whool", game->list_inv_player);
//	game->list_inv_player = create_obj_in_inv(game->list_inventory, "whool", game->list_inv_player);
//	game->list_inv_player = create_obj_in_inv(game->list_inventory, "whool", game->list_inv_player);
	replace_perso(game, 0, 0);
	while (game->map_graph != NULL && sfRenderWindow_isOpen(game->win->window)) {
		display(game, game->back_inv);
		if (event(game))
			return (0);
	}
	return (0);
}
