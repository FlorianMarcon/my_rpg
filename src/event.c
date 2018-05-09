/*
** EPITECH PROJECT, 2017
** event
** File description:
** event
*/

#include "game.h"
#include <SFML/Graphics.h>
#include <stdbool.h>

void	move_rect_object(sprite_t *spr)
{
	int diff = spr->obj->time.microseconds - sfClock_getElapsedTime(spr->clock).microseconds;

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
bool	event(game_t *game, pause_t *stpause)
{
	while (sfRenderWindow_pollEvent(game->win->window, &game->win->event)) {
		if (game->win->event.type == sfEvtClosed)
			sfRenderWindow_close(game->win->window);
		if (sfKeyboard_isKeyPressed(sfKeyL))
			game->draw_line = true;
		if (sfKeyboard_isKeyPressed(sfKeyO))
			game->draw_line = false;
		if (sfKeyboard_isKeyPressed(sfKeyM))
			if (loop_pause(game, stpause))
				return (true);
		affect_move_perso(game);
	}
	run_quete(game, game->map->map[game->perso->y][game->perso->x]);
	change_map(game);
	move_object(game);
	return (false);
}
