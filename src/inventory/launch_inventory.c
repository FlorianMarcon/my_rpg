/*
** EPITECH PROJECT, 2018
** launch
** File description:
** inventory
*/

#include "game.h"

void	inventory(game_t *game)
{
	inv_t *inv = game->back_inv;

	if (sfKeyboard_isKeyPressed(sfKeyI)) {
		inv->pos.x = 0;
		inv->pos.y = 0;
		game->can_move = false;
		game->can_disp = true;
		sfSprite_setPosition(inv->sprite, inv->pos);
	}
	if (sfKeyboard_isKeyPressed(sfKeyQ)) {
		inv->pos.x = 8000;
		inv->pos.y = 8000;
		game->can_move = true;
		game->can_disp = false;
		sfSprite_setPosition(inv->sprite, inv->pos);
	}
}
