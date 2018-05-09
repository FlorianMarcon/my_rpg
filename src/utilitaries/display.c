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

void	display(game_t *game, inv_t *tmp, pause_t *pause)
{
	sfRenderWindow_clear(game->win->window, sfBlack);
	display_sprite(game->win->window, game->background, NULL);
	display_map(game, game->win, game->draw_line);
	display_stat_bar(game);
	if (tmp != NULL)
		display_inventory(game->win->window, tmp->sprite);
	display_quete(game);
	if (pause != NULL)
		display_pause(game, pause);
	sfRenderWindow_display(game->win->window);
}
