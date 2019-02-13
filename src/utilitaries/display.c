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

void	display_inv(game_t *game, player_inv_t *list)
{
	sfVector2f pos = {714, 289};
	unsigned int i = 0;

	while (list != NULL) {
		sfText_setString(list->number, get_nb_in_char(list->quantity));
		sfText_setFont(list->number, game->font_inv);
		sfText_setPosition(list->number, pos);
		sfSprite_setPosition(list->sprite, pos);
		sfRenderWindow_drawSprite(game->win->window, list->sprite,\
		NULL);
		sfRenderWindow_drawText(game->win->window, list->number, NULL);
		pos.x += 80;
		i++;
		if (i == 4) {
			i = 0;
			pos.x = 714;
			pos.y += 80;
		}
		list = list->next;
	}
}

void	display(game_t *game, inv_t *tmp)
{
	sfRenderWindow_clear(game->win->window, sfBlack);
	display_sprite(game->win->window, game->map_graph->background, NULL);
	display_map(game, game->win, game->draw_line);
	display_stat_bar(game);
	if (tmp != NULL)
		display_inventory(game->win->window, tmp->sprite);
	if (game->can_disp == true)
		display_inv(game, game->list_inv_player);
	display_quete(game);
	sfRenderWindow_display(game->win->window);
}
