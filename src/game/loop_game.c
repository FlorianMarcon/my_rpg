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

int	loop_game(game_t *game, inv_t *tmp, pause_t *pause)
{
	replace_perso(game, 0, 0);
	while (game->map_graph != NULL) {
		tmp = inventory(game, tmp);
		display(game, tmp);
		if (event(game, pause))
			return (0);
	}
	return (0);
}
