/*
** EPITECH PROJECT, 2017
** create_two_d_map
** File description:
** create_two_d_map
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "map.h"

sfVector2f	**create_two_d_map(map_t *map)
{
	int i = 0;
	int j = 0;
	sfVector2f **map_iso;

	map_iso = malloc(sizeof(sfVector2f*) * map->height);
	while (j < map->height) {
		i = 0;
		map_iso[j] = malloc(sizeof(sfVector2f) * map->width);
		while (i < map->width) {
			map_iso[j][i] = project_iso_point(i, j, map);
			i++;
		}
		j++;
	}
	return (map_iso);
}
