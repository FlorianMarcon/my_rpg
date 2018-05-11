/*
** EPITECH PROJECT, 2017
** manage_object_no_displaying
** File description:
** manage_object_no_displaying
*/

#include "game.h"

void	manage_object_no_displaying(sprite_t *spr)
{
	sfTime tim;

	if (spr->time_no_disp == NULL)
		spr->time_no_disp = sfClock_create();
	tim = sfClock_getElapsedTime(spr->time_no_disp);
	if (tim.microseconds > 15000000) {
		spr->displaying = true;
		sfClock_destroy(spr->time_no_disp);
		spr->time_no_disp = NULL;
	}
}
