/*
** EPITECH PROJECT, 2017
** display_sprite
** File description:
** display_sprite
*/

#include <SFML/Graphics.h>
#include "game.h"

void	display_inventory(sfRenderWindow *win, sfSprite *spr)
{
	if (spr == NULL || win == NULL)
		return;
	sfRenderWindow_drawSprite(win, spr, NULL);
}

void	display_pause(game_t *game)
{
	pause_t *pause = game->pause;

	if (pause->pause == NULL || game->win->window == NULL)
		return;
	sfRenderWindow_drawSprite(game->win->window, pause->pause, NULL);
	sfRenderWindow_display(game->win->window);
}

void	display_sprite(sfRenderWindow *win, sfSprite *spr, sfRenderStates *sta)
{
	if (spr == NULL || win == NULL)
		return;
	sfRenderWindow_drawSprite(win, spr, sta);
}
