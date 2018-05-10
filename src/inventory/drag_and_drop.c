/*
** EPITECH PROJECT, 2018
** drag
** File description:
** drop
*/

#include "game.h"

void	drag_and_drop(game_t *game)
{
	sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(game->win->window);

	if (game->list_inv_player != NULL) {
		if (sfMouse_isButtonPressed(sfMouseLeft) && game->can_disp == true) {
			game->list_inv_player->pos.x = pos_mouse.x;
			game->list_inv_player->pos.y = pos_mouse.y;
			printf("X = %f\n", game->list_inv_player->pos.x);
			printf("Y = %f\n", game->list_inv_player->pos.y);
			sfSprite_setPosition(game->list_inv_player->sprite, game->list_inv_player->pos); 
		}
	}
}
