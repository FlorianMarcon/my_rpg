/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "game.h"
#include "header.h"

void	draw_menu(menu_t *men, sfRenderWindow *window, lock_t *lock, set_t *set)
{
	if (lock->lock == 0 || lock->lock == 2) {
		sfRenderWindow_drawSprite(window, men->sprite6, NULL);
		sfRenderWindow_drawSprite(window, men->sprite7, NULL);
		sfRenderWindow_drawSprite(window, men->sprite1, NULL);
		sfRenderWindow_drawSprite(window, men->sprite3, NULL);
		sfRenderWindow_drawSprite(window, men->sprite5, NULL);
	}
	if (lock->lock == 1) {
		sfRenderWindow_drawSprite(window, set->sprite, NULL);
		sfRenderWindow_drawSprite(window, men->sprite8, NULL);
	}
}

void	anim_but1(menu_t *men, sfRenderWindow *window, sfVector2i pos1)
{
	if (((pos1.x >= men->pos_but2.x) && (pos1.x <= men->pos_but2.x + 550))
	    && ((pos1.y >= men->pos_but2.y) && (pos1.y <= men->pos_but2.y + 200)))
		sfRenderWindow_drawSprite(window, men->sprite2, NULL);
	if (sfMouse_isButtonPressed(sfMouseLeft) && pos1.y > 728 && pos1.y < 799) {
		sfRenderWindow_close(window);
	}
}

void	anim_but2(menu_t *men, sfRenderWindow *window, sfVector2i pos1, lock_t *lock)
{
	if (((pos1.x >= men->pos_but5.x) && (pos1.x <= men->pos_but5.x + 550))
	    && ((pos1.y >= men->pos_but5.y) && (pos1.y <= men->pos_but5.y + 200))) {
			sfRenderWindow_drawSprite(window, men->sprite4, NULL);
			if (sfMouse_isButtonPressed(sfMouseLeft))
				lock->lock = 1;
	}
}

int	anim_but3(menu_t *men, sfRenderWindow *window, sfVector2i pos1, game_t *game)
{
	if (((pos1.x >= men->pos_but1.x) && (pos1.x <= men->pos_but1.x + 550))
	    && ((pos1.y >= men->pos_but1.y) && (pos1.y <= men->pos_but1.y + 200))) {
		sfRenderWindow_drawSprite(window, men->sprite, NULL);
		if (sfMouse_isButtonPressed(sfMouseLeft)) {
			loop_game(game);
		}
	}
	return (0);
}

int	anim_menu(menu_t *men, sfRenderWindow *window, sfVector2i pos1, lock_t *lock, set_t *set, game_t *game)
{
	if (lock->lock == 0 || lock->lock == 2) {
		anim_but1(men, window, pos1);
		anim_but2(men, window, pos1, lock);
		anim_but3(men, window, pos1, game);
	}
	if (lock->lock == 1) {
		anim_check(men, pos1);
		anim_back(set, window, pos1, lock);
	}
	return (0);
}
