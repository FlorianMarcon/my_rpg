/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** detect obj
*/

#include "game.h"

int	colision_x(perso_t *perso, map_t *map, int x)
{
	if (x == 0 && perso->x < 13) {
		if (map->map[perso->x + 1][perso->y] < 20 || map->map[perso->x + 1][perso->y] >= 100)
			return (0);
	}
	if (x == 1 && perso->x > 0) {
		if (map->map[perso->x - 1][perso->y] < 20 || map->map[perso->x - 1][perso->y] >= 100)
			return (0);
	}
	return (-1);
}

int	colision_y(perso_t *perso, map_t *map, int y)
{
	if (y == 10 && perso->y < 13) {
		if (map->map[perso->x][perso->y + 1] < 20)
			return (0);
	}
	if (y == 11 && perso->y > 0) {
		if (map->map[perso->x][perso->y - 1] < 20)
			return (0);
	}
	return (-1);
}

int	detect_col(perso_t *perso, map_t *map, int x)
{
	if (x < 10)
		return (colision_x(perso, map, x));
	else
		return (colision_y(perso, map, x));
	return (0);
}
