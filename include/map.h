/*
** EPITECH PROJECT, 2017
** map.h
** File description:
** map.h
*/

#ifndef MAP_
#define MAP_

#include <SFML/Graphics.h>

#define SCALING_X 45
#define SCALING_Y 45
#define ROTATION 36
#define INCLINAISON 60 //56
#define TRANSLA_X 5
#define TRANSLA_Y -1

typedef struct map {
	int **map;
	sfRenderStates *state;
	sfRenderStates *state_bottom;
	sfVertexArray **arr_vertex;
	sfVertexArray **arr_bottom;

	int width;
	int height;
	int number;
	int x_center;
	int y_center;
}map_t;

int	fill_setting(map_t *map, int fd);

int	fill_map(map_t *map, int fd);

int	fill_matter(map_t *map, int fd);

#endif
