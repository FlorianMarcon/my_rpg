/*
** EPITECH PROJECT, 2017
** my_RPG
** File description:
** display fight
*/

#include "game.h"


void	display_fight_item(game_t *game)
{
	item_t *tmp = game->fight->item;

	while (tmp != NULL) {
		sfRenderWindow_drawSprite(game->win->window, tmp->sprite, NULL);
		tmp = tmp->next;
	}
}

void	display_fight_txt(game_t *game)
{
	linked_txt_t *tmp = game->fight->txt;

	while (tmp != NULL) {
		sfRenderWindow_drawText(game->win->window, tmp->text, NULL);
		tmp = tmp->next;
	}
}

void	display_fight(game_t *game, sfText *txt)
{
	sfRenderWindow_clear(game->win->window, sfBlack);
	display_fight_item(game);
	display_fight_txt(game);
	sfRenderWindow_drawSprite(game->win->window,
					game->fight->ennemy->sprite, NULL);
	if (txt != NULL)
		sfRenderWindow_drawText(game->win->window, txt, NULL);
	sfRenderWindow_display(game->win->window);
}
