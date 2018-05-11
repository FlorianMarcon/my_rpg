/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** free move
*/

#include "game.h"

void	free_move_perso(perso_t *perso, float second, sfClock *my_clock)//map_t *map)
{
	if (perso->mouvement.y == 1) {
		move_rect(perso, 3, second, my_clock);
		perso->position.y -= 1;
		perso->position.x -= 2.8;
	}
	if (perso->mouvement.y == -1) {
		move_rect(perso, 0, second, my_clock);
		perso->position.y += 1;
		perso->position.x += 2.8;
	}
	if (perso->mouvement.x == -1) {
		move_rect(perso, 1, second, my_clock);
		perso->position.x -= 2.175;
		perso->position.y += 1.5;
	}
	if (perso->mouvement.x == 1) {
		move_rect(perso, 2, second, my_clock);
		perso->position.x += 2.175;
		perso->position.y -= 1.5;
	}
	sfSprite_setPosition(perso->sprite, perso->position);
}

perso_t	*affect_free_move_perso(perso_t *perso, float second, sfClock *my_clock)
{
	if (sfKeyboard_isKeyPressed(sfKeyUp)) {
		perso->mouvement.y = 1;
		perso->mouvement.x = 0;
		move_perso(perso, second, my_clock, map);
	} if (sfKeyboard_isKeyPressed(sfLeft)) {
		perso->mouvement.x = 0;
		perso->mouvement.y = -1;
		move_perso(perso, second, my_clock, map);
	} if (sfKeyboard_isKeyPressed(sfKeyDown)) {
		perso->mouvement.y = 0;
		perso->mouvement.x = -1;
		move_perso(perso, second, my_clock, map);
	} if (sfKeyboard_isKeyPressed(sfKeyRight)) {
		perso->mouvement.y = 0;
		perso->mouvement.x = 1;
		move_perso(perso, second, my_clock, map);
	}
	return (perso);
}
