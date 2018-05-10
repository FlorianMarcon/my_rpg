/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** display
*/

#include "game.h"

void	display_perso(perso_t *perso, window_t *win)
{
	sfRenderWindow_drawSprite(win->window, perso->sprite, NULL);
}
