/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "header.h"

void	draw_menu(menu_t *men, sfRenderWindow *window, lock_t *lock)
{
	sfRenderWindow_drawSprite(window, men->sprite6, NULL);
	if (lock->lock == 0) {
		sfRenderWindow_drawSprite(window, men->sprite7, NULL);
		sfRenderWindow_drawSprite(window, men->sprite1, NULL);
		sfRenderWindow_drawSprite(window, men->sprite3, NULL);
		sfRenderWindow_drawSprite(window, men->sprite5, NULL);
	}
}

void	anim_menu(menu_t *men, sfRenderWindow *window, sfVector2i pos1, lock_t *lock)
{
	if (lock->lock == 0) {
		if (((pos1.x >= men->pos_but2.x) && (pos1.x <= men->pos_but2.x + 550))
		    && ((pos1.y >= men->pos_but2.y) && (pos1.y <= men->pos_but2.y + 200))) {
			if (sfMouse_isButtonPressed(sfMouseLeft))
				sfRenderWindow_close(window);
			sfRenderWindow_drawSprite(window, men->sprite2, NULL);
		}
		if (((pos1.x >= men->pos_but5.x) && (pos1.x <= men->pos_but5.x + 550))
		    && ((pos1.y >= men->pos_but5.y) && (pos1.y <= men->pos_but5.y + 200))) {
			sfRenderWindow_drawSprite(window, men->sprite4, NULL);
			if (sfMouse_isButtonPressed(sfMouseLeft))
				lock->lock = 1;
		}
		if (((pos1.x >= men->pos_but1.x) && (pos1.x <= men->pos_but1.x + 550))
		    && ((pos1.y >= men->pos_but1.y) && (pos1.y <= men->pos_but1.y + 200))) {
			sfRenderWindow_drawSprite(window, men->sprite, NULL);
		}
		
	}
}

