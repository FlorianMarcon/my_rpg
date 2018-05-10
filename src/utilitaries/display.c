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

void	display_inv(game_t *tmp, player_inv_t *ply)
{
	while (ply != NULL) {
		sfRenderWindow_drawSprite(tmp->win->window, ply->sprite, NULL);
//		sfRenderWindow_display(tmp->win->window);
		ply = ply->next;
	}
}

void	display(game_t *game, inv_t *tmp, player_inv_t *ply)
{
	sfRenderWindow_clear(game->win->window, sfBlack);
	display_sprite(game->win->window, game->background, NULL);
	display_map(game, game->win, game->draw_line);
	display_stat_bar(game);
	if (tmp != NULL)
		display_inventory(game->win->window, tmp->sprite);
	if (game->can_disp == true)
		display_inv(game, ply);
	display_quete(game);
	sfRenderWindow_display(game->win->window);
}
