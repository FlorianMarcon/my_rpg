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
	display_map(game->map_graph, game->win, game->draw_line);
	display_perso(game->perso, game->win);
	sfRenderWindow_display(game->win->window);
}
