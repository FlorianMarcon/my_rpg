/*
** EPITECH PROJECT, 2017
** my_RPG
** File description:
** stat_bar
*/

#include "game.h"

int	coef_xp(stat_t stat)
{
	int i = stat.xp / stat.xp_max;

	return (i * 6);
}

void	display_items(game_t *game)
{
	item_t *tmp = game->stat->item;

	while (tmp != NULL) {
		sfRenderWindow_drawSprite(game->win->window,
						tmp->sprite, NULL);
		tmp = tmp->next;
	}
}

void	display_text(window_t *win, stat_txt_t *txt)
{
	stat_txt_t *tmp = txt;

	while (tmp != NULL) {
		if (tmp->txt != NULL && win->window != NULL)
			sfRenderWindow_drawText(win->window, tmp->txt, NULL);
		tmp = tmp->next;
	}
}

void	load_stat_from_perso(stat_txt_t *txt, stat_t perso_stat)
{
	perso_stat.change = false;
	sfText_setString(txt->txt, get_nb_in_char(perso_stat.vie));
	txt = txt->next;
	sfText_setString(txt->txt, get_nb_in_char(perso_stat.att_m));
	txt = txt->next;
	sfText_setString(txt->txt, get_nb_in_char(perso_stat.att_p));
	txt = txt->next;
	sfText_setString(txt->txt, get_nb_in_char(perso_stat.defence));
	txt = txt->next;
	sfText_setString(txt->txt, get_nb_in_char(perso_stat.xp));
	txt = txt->next;
	sfText_setString(txt->txt, get_nb_in_char(perso_stat.xp_max));
	txt = txt->next;
	sfText_setString(txt->txt, get_nb_in_char(perso_stat.lvl));
	txt = txt->next;
	sfText_setString(txt->txt, get_nb_in_char(perso_stat.vie_c));
}

void	display_stat_bar(game_t *game)
{
	if (game->perso->stat.change == true)
		load_stat_from_perso(game->stat->txt, game->perso->stat);
	display_items(game);
	display_text(game->win, game->stat->txt);
}
