/*
** EPITECH PROJECT, 2017
** move_object
** File description:
** move_object
*/

#include "game.h"

void	move_rect_object(sprite_t *spr)
{
	int diff = spr->obj->time.microseconds -
				sfClock_getElapsedTime(spr->clock).microseconds;
	if (diff > 0)
		return;
	sfClock_restart(spr->clock);
	sfSprite_setTextureRect(spr->sprite, spr->rect);
	spr->rect.left += spr->obj->rect.width;
	spr->nb_rect++;
	if (spr->nb_rect >= spr->obj->max_rect) {
		spr->nb_rect = 0;
		spr->rect.left = 0;
	}
}
void	move_object(game_t *game)
{
	linked_list_t *list = game->map_graph->list_obj;
	sprite_t *spr = NULL;

	while (list != NULL) {
		spr = list->data;
		if (spr != NULL && spr->obj->max_rect > 0) {
			move_rect_object(spr);
		}
		list = list->next;
	}
}
