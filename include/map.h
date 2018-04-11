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
#include "graphique.h"

#define SCALING_X 45
#define SCALING_Y 45
#define ROTATION 36
#define INCLINAISON 60
#define TRANSLA_X 5
#define TRANSLA_Y -1

typedef struct sprite_s {
	sfTexture *texture;
	sfSprite *sprite;
	sfIntRect *rect;
	sfVector2u size;
	int max_rect;
}sprite_t;

typedef struct map {
	int **map;
	sfVector2f **map_iso;

	sfRenderStates *state_floor;
	sfRenderStates *state_teleport;
	sfRenderStates *state_bottom;
	sfVertexArray **arr_vertex;
	sfVertexArray **arr_bottom;
	sfVertexArray **arr_line;

	int width;
	int height;
	int number;
	int x_center;
	int y_center;

	linked_list_t *list_object;
}map_t;

typedef struct object_s {
	char *name;

	sfTexture *texture;
	sfIntRect *rect;
	int max_rect;

	int number;
}object_t;

// generate_map
int	fill_setting(map_t *map, int fd);

int	fill_map(map_t *map, int fd);

int	fill_matter(map_t *map, int fd);

sfRenderStates	*fill_one_matter(char *str);

void	generate_sprite_map(map_t *map);

sfVector2f	project_iso_point(int x, int y, map_t *map);

sfVector2f	**create_two_d_map(map_t *map);

sfVertexArray *create_quad(sfVector2f point1, sfVector2f point2,\
					sfVector2f point3, sfVector2f point4);

sfVertexArray *create_quad_bottom_map(sfVector2f point1, sfVector2f point2);

void	generate_sprite_map(map_t *map);

map_t	*generate_map(linked_list_t *text, char *path);

linked_list_t	*generate_list_map(linked_list_t *texture, char *path);

void	generate_sprite_line_map(map_t *map);

// generate_object

object_t	*generate_object(char *path);

linked_list_t	*generate_list_object(char *path);

// other

void	display_map(map_t *map, window_t *win);

map_t	*search_map(linked_list_t *list, int number);

sfVertexArray	*create_line(sfVector2f point1, sfVector2f point2, sfColor color);

#endif
