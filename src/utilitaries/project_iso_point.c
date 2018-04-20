/*
** EPITECH PROJECT, 2017
** project_iso_point
** File description:
** project_iso_point
*/

#include <SFML/Graphics.h>
#include <math.h>
#include <stdlib.h>
#include "map.h"

sfVector2f	project_iso_point(int x, int y, map_t *map)
{
	sfVector2f point;
	double rota = ROTATION * M_PI / 180;
	double incli = INCLINAISON * M_PI / 180;

	point.x = (map->x_center + cos(rota) * (x - map->x_center));
	point.x -= sin(rota) * (y - map->y_center);
	point.y = (map->y_center + sin(rota) * (x - map->x_center));
	point.y += cos(rota) * (y - map->y_center);
	point.y = map->y_center  + cos(incli) * (point.y - map->y_center);
	point.x += TRANSLA_X;
	point.y += TRANSLA_Y;
	point.x = point.x * (SCALING_X);
	point.y = point.y * (SCALING_Y);
	return (point);
}
