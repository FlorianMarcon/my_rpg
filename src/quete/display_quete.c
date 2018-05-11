/*
** EPITECH PROJECT, 2017
** display_quete
** File description:
** display_quete
*/

#include "game.h"

void	display_quete(game_t *game)
{
	if (game->display_textbox == true) {
		sfRenderWindow_drawSprite(game->win->window,
							game->textbox, NULL);
		for (unsigned int i = 0; i != game->size_text; i++) {
			sfRenderWindow_drawText(game->win->window,
							game->text[i], NULL);
		}
		game->display_textbox = false;
	}
}
