/*
** EPITECH PROJECT, 2017
** map.h
** File description:
** map.h
*/

#ifndef MAP_
#define MAP_

#include <SFML/Graphics.h>
#include "my.h"

#define SCALING_X 45
#define SCALING_Y 45
#define ROTATION 36
#define INCLINAISON 60
#define TRANSLA_X 5
#define TRANSLA_Y -1

typedef struct map {
	int **map;
	sfVector2f **map_iso;

	sfRenderStates *state;
	sfRenderStates *state_floor;
	sfRenderStates *state_bottom;
	sfVertexArray **arr_vertex;
	sfVertexArray **arr_bottom;
	sfVertexArray **arr_line;

	int width;
	int height;
	int number;
	int x_center;
	int y_center;
}map_t;

int	fill_setting(map_t *map, int fd);

int	fill_map(map_t *map, int fd);

int	fill_matter(map_t *map, int fd);

sfRenderStates	*fill_one_matter(char *str);

void	generate_sprite_map(map_t *map);

map_t	*generate_map(char *path);

sfVector2f	project_iso_point(int x, int y, map_t *map);

sfVector2f	**create_two_d_map(map_t *map);

sfVertexArray *create_quad(sfVector2f point1, sfVector2f point2,\
					sfVector2f point3, sfVector2f point4);

sfVertexArray *create_quad_bottom_map(sfVector2f point1, sfVector2f point2);

void	generate_sprite_map(map_t *map);

map_t	*generate_map(char *path);

linked_list_t	*generate_list_map(char *path);

#endif
