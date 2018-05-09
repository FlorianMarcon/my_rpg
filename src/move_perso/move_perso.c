/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** move perso
*/

#include "game.h"

void	move_rect(perso_t *perso, int i, float second, sfClock *my_clock)
{
	int width = 32;
	int height = 48;

	perso->rect.top = i * height;

	if (second > 0.1) {
		sfClock_restart(my_clock);
		perso->rect.left += width;
		if (perso->rect.left >= 128)
			perso->rect.left = 0;
	}
	sfSprite_setTextureRect(perso->sprite, perso->rect);
}

void	move_y(perso_t *perso, my_clock_t *my_clock)
{
	if (perso->mouvement.y == 1) {
		move_rect(perso, 3, my_clock->second, my_clock->my_clock);
		perso->position.y -= 0.72;
		perso->position.x -= 1.82;
	}
	if (perso->mouvement.y == -1) {
		move_rect(perso, 0, my_clock->second, my_clock->my_clock);
		perso->position.y += 0.72;
		perso->position.x += 1.82;
	}
}

void	move_perso(perso_t *perso, my_clock_t *my_clock)
{

	move_y(perso, my_clock);
	if (perso->mouvement.x == -1) {
		move_rect(perso, 1, my_clock->second, my_clock->my_clock);
		perso->position.x -= 1.3;
		perso->position.y += 0.9;
	}
	if (perso->mouvement.x == 1) {
		move_rect(perso, 2, my_clock->second, my_clock->my_clock);
		perso->position.x += 1.3;
		perso->position.y -= 0.9;
	}
	sfSprite_setPosition(perso->sprite, perso->position);
}
