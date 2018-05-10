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

int	loop_game(game_t *game, inv_t *tmp, pause_t *pause, player_inv_t *ply)
{
	ply = create_obj_in_inv(game->list_inventory, "sword", ply);
//	printf("%s\n", ply->type);
	fprintf(stderr, "anthony le bg\n");
	ply = create_obj_in_inv(game->list_inventory, "potion", ply);
	fprintf(stderr, "hello\n");
	replace_perso(game, 0, 0);
	while (game->map_graph != NULL && sfRenderWindow_isOpen(game->win->window)) {
		tmp = inventory(game, tmp);
		display(game, tmp, ply);
		if (event(game, pause))
			return (0);
	}
	return (0);
}
