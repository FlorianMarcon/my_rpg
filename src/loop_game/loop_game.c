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

int	loop_game(void)
{
	game_t *game = initialisation_game();

	if (game == NULL)
		return (84);
	while (sfRenderWindow_isOpen(game->win->window)) {
		while (sfRenderWindow_pollEvent(game->win->window, &game->win->event))
		{
			if (game->win->event.type == sfEvtClosed)
			sfRenderWindow_close(game->win->window);
		}
		sfRenderWindow_clear(game->win->window, sfBlack);
		display(game);
		sfRenderWindow_display(game->win->window);
	}
	free(game->win);

	return (0);
}
