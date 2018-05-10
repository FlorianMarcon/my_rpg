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
	replace_perso(game, 0, 0);
	while (game->map_graph != NULL && sfRenderWindow_isOpen(game->win->window)) {
		display(game, game->back_inv);
		if (event(game))
			return (0);
	}
	return (0);
}
