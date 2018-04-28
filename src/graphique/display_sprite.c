/*
** EPITECH PROJECT, 2017
** display_sprite
** File description:
** display_sprite
*/

#include <SFML/Graphics.h>

void	display_inventory(sfRenderWindow *win, sfSprite *spr)
{
	if (spr == NULL || win == NULL)
		return;
	sfRenderWindow_drawSprite(win, spr, NULL);
}

void	display_sprite(sfRenderWindow *win, sfSprite *spr, sfRenderStates *sta)
{
	if (spr == NULL || win == NULL)
		return;
	sfRenderWindow_drawSprite(win, spr, sta);
}
