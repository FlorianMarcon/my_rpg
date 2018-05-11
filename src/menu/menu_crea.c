/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "header.h"

int	create_menu(set_t *set, lock_t *ptr, menu_t *men, sfRenderWindow *window, sfVector2i pos1, game_t *game)
{
	men->pos_sts.x -= 0.1;
	set_pos_men(men, set);
	sfRenderWindow_clear(window, sfWhite);
	draw_menu(men, window, ptr, set);
	anim_menu(men, window, pos1, ptr, set, game);
	sfRenderWindow_display(window);
	return (0);
}
