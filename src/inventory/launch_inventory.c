/*
** EPITECH PROJECT, 2018
** launch
** File description:
** inventory
*/

#include "game.h"

inv_t	*inventory(game_t *game, inv_t *tmp)
{
	if(sfKeyboard_isKeyPressed(sfKeyI)) {
		tmp->pos.x = 0;
		tmp->pos.y = 0;
		game->can_move = false;
	}
	if(sfKeyboard_isKeyPressed(sfKeyQ)) {
		tmp->pos.x = 8000;
		tmp->pos.y = 8000;
		game->can_move = true;
	}
	sfSprite_setPosition(tmp->sprite, tmp->pos);
	return (tmp);
}
