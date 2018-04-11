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
//	sfVector2f **map_iso;

//	sfRenderStates *state_floor;
//	sfRenderStates *state_teleport;
//	sfRenderStates *state_bottom;
//	sfVertexArray **arr_vertex;
//	sfVertexArray **arr_bottom;
//	sfVertexArray **arr_line;

	int width;
	int height;
	int number;

	char *path_sprite_floor;
	char *path_sprite_teleport;
	char *path_sprite_bottom;

//	int x_center;
//	int y_center;

//	linked_list_t *list_object;
}map_t;

typedef struct object_s {
	char *name;

	sfTexture *texture;
	sfIntRect *rect;
	int max_rect;

	int number;
}object_t;

// generate_map

map_t	*generate_map(char *path);

int	fill_setting(int fd, map_t *map);

int	fill_map(int fd, map_t *map);

int	fill_path_sprite(int fd, map_t *map);

linked_list_t	*generate_list_map(char *path);

#endif
