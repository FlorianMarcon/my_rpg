/*
** EPITECH PROJECT, 2017
** event
** File description:
** event
*/

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "game.h"

bool	event(game_t *game, pause_t *stpause)
{
	while (sfRenderWindow_pollEvent(game->win->window, &game->win->event)) {
		if (game->win->event.type == sfEvtClosed)
			sfRenderWindow_close(game->win->window);
		if (sfKeyboard_isKeyPressed(sfKeyL))
			game->draw_line = true;
		if (sfKeyboard_isKeyPressed(sfKeyO))
			game->draw_line = false;
		if (sfKeyboard_isKeyPressed(sfKeyM))
			if (loop_pause(game, stpause))
				return (true);
		if (sfKeyboard_isKeyPressed(sfKeyF))
			launch_fight(game);
		affect_move_perso(game);
	}
	if (game->map->map[game->perso->x][game->perso->y - 1] >= 100)
		run_quete(game, game->map->map[game->perso->x][game->perso->y - 1]);
	change_map(game);
	move_object(game);
	lvl_up(game);
	return (false);
}
