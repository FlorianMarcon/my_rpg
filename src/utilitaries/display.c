/*
** EPITECH PROJECT, 2017
** display
** File description:
** display
*/

#include <unistd.h>
#include "map.h"
#include "game.h"
#include "graphique.h"

void	display(game_t *game)
{
	sfRenderWindow_clear(game->win->window, sfBlack);
	display_sprite(game->win->window, game->background, NULL);
	display_map(game, game->win, game->draw_line);
	if (game->display_textbox == true) {
		sfRenderWindow_drawSprite(game->win->window, game->textbox, NULL);
		sfRenderWindow_drawText(game->win->window, game->text, NULL);
		game->display_textbox = false;
	}
	sfRenderWindow_display(game->win->window);
}
