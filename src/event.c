/*
** EPITECH PROJECT, 2017
** event
** File description:
** event
*/

#include "game.h"
#include <SFML/Graphics.h>
#include <stdbool.h>

void	event(game_t *game)
{
	while (sfRenderWindow_pollEvent(game->win->window, &game->win->event)) {
		if (game->win->event.type == sfEvtClosed)
			sfRenderWindow_close(game->win->window);
		if (sfKeyboard_isKeyPressed(sfKeyL))
			game->draw_line = true;
		if (sfKeyboard_isKeyPressed(sfKeyO))
			game->draw_line = false;
		affect_move_perso(game);
	}
	change_map(game);
//	if (game->change_map == true) {
//		change_map(game);
//	}
}
