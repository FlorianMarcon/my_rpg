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
	int i = 0;
	int is_pause = 0;

	replace_perso(game, 0, 0);
	while (i == 0 && game->map_graph != NULL) {
		if (sfKeyboard_isKeyPressed(sfKeyM)) {
			pause->pos_pause.x = 0;
			pause->pos_pause.y = 0;
			sfSprite_setPosition(pause->pause, pause->pos_pause);
			is_pause = 1;
		}
		tmp = inventory(tmp);
		display(game, tmp, pause);
		event(game);
		if (is_pause == 1) {
			if (sfKeyboard_isKeyPressed(sfKeyP)) {
				pause->pos_pause.x = 1220;
				pause->pos_pause.y = 120000;
				sfSprite_setPosition(pause->pause, pause->pos_pause);
				is_pause = 0;
			}
			if (sfKeyboard_isKeyPressed(sfKeyE)) {
				pause->pos_pause.x = 1220;
				pause->pos_pause.y = 120000;
				sfSprite_setPosition(pause->pause, pause->pos_pause);
				i = 1;
			}
		}
	}
	return (0);
}
