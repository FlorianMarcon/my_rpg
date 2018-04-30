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

int	loop_game(game_t *game, inv_t *tmp)
{
	int i = 0;
	
	while (i == 0 && game->map_graph != NULL) {
		tmp = inventory(tmp);
		display(game, tmp);
		event(game);
	}
	return (0);
}
