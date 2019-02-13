/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "header.h"


void	anim_check(menu_t *men, sfVector2i pos1)
{
	if ((pos1.x >= 658) && (pos1.x <= 739)) {
		if (sfMouse_isButtonPressed(sfMouseLeft))
			men->pos_but8.x = 193;
	}
	if ((pos1.x <= 523) && (pos1.x >= 441)) {
		if (sfMouse_isButtonPressed(sfMouseLeft))
			men->pos_but8.x = -25;
	}
}

void	anim_back(set_t *men, sfRenderWindow *window,
					sfVector2i pos1, lock_t *lock)
{
	if ((pos1.x >= 537) && (pos1.x <= 645)
				&& (pos1.y >= 816) && (pos1.y <= 940)) {
		sfRenderWindow_drawSprite(window, men->sprite1, NULL);
		if (sfMouse_isButtonPressed(sfMouseLeft))
			lock->lock = 0;
	}
}
