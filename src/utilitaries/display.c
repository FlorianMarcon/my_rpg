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

void	display_player_inv(game_t *tmp, player_inv_t *ptr)
{
	if (ptr != NULL) {
		while (ptr != NULL) {
			sfRenderWindow_drawSprite(tmp->win->window, ptr->sprite, NULL);
			sfRenderWindow_display(tmp->win->window);
			ptr = ptr->next;
		}
	}
}

void	display(game_t *game, inv_t *tmp, pause_t *pause, player_inv_t *ptr)
{
	sfRenderWindow_clear(game->win->window, sfBlack);
	display_sprite(game->win->window, game->background, NULL);
	display_map(game, game->win, game->draw_line);
	if (tmp != NULL)
		display_inventory(game->win->window, tmp->sprite);
	display_player_inv(game, ptr);
	display_quete(game);
	if (pause != NULL)
		display_pause(game, pause);
	sfRenderWindow_display(game->win->window);
}
