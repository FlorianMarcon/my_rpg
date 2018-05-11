/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** free move
*/

#include "game.h"
/*
void	move_rect(perso_t *perso, int i, float second, sfClock *my_clock)
{
	int width = 64;
	int height = 56;

	perso->rect.top = i * height;

	if (second > 0.2) {
		sfClock_restart(my_clock);
		perso->rect.left += width;
		if (perso->rect.left > 254)
			perso->rect.left = 0;
	}
	sfSprite_setTextureRect(perso->sprite, perso->rect);
}*/

void	free_move_perso(perso_t *perso, float second, sfClock *my_clock)//map_t *map)
{
	//printf("x = %f, y = %f\n", map->map_iso[perso->y][perso->x + 1].x - map->map_iso[perso->y][perso->x].x, map->map_iso[perso->y][perso->x + 1].y -  map->map_iso[perso->y][perso->x].y);
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
		/*while (perso->position.x != map->map_iso[perso->y][perso->x + 1].x && perso->position.y != map->map_iso[perso->y][perso->x + 1].y)
			move_perso(perso, second, my_clock, map);*/
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
