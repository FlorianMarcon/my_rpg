/*
** EPITECH PROJECT, 2017
** map.h
** File description:
** map.h
*/

#ifndef MAP_
#define MAP_

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "my.h"
#include "graphique.h"

#define SCALING_X 45
#define SCALING_Y 45
#define ROTATION 36
#define INCLINAISON 60
#define TRANSLA_X 5
#define TRANSLA_Y -1

typedef struct map_s {
	int **map;
	sfVector2f **iso;

	int width;
	int height;
	int number;

	char *path_sprite_floor;
	char *path_sprite_teleport;
	char *path_sprite_bottom;
	char *path_sprite_back;

	int x_center;
	int y_center;
}map_t;

typedef struct map_graph_s {
	map_t *map;
	sfVector2f **iso;

	sfVertexArray **arr_floor;
	sfRenderStates *state_floor;
	sfRenderStates *state_telep;
	sfVertexArray **arr_bottom;
	sfRenderStates *state_bottom;
	sfVertexArray **arr_line;

	sfSprite *background;

	linked_list_t *list_obj;
}map_graph_t;

typedef struct object_s {
	char *name;

	sfTexture *texture;
	char *path;
	char *shader;
	sfIntRect rect;
	sfVector2u size;
	int max_rect;
	sfTime time;

	int number;
}object_t;

typedef struct sprite_s {
	unsigned int x;
	unsigned int y;

	sfSprite *sprite;
	sfRenderStates *states;

	sfIntRect rect;
	int nb_rect;
	object_t *obj;

	bool displaying;
	sfClock *time_no_disp;

	sfClock *clock;
}sprite_t;
// generate_map

map_t	*generate_map(char *path);

int	fill_setting(int fd, map_t *map);

int	fill_map(int fd, map_t *map);

int	fill_path_sprite(int fd, map_t *map);

linked_list_t	*generate_list_map(char *path);

// generate object

object_t	*search_object(linked_list_t *list_obj, int index);

linked_list_t	*generate_list_object(char *path);

object_t	*generate_object(char *file);

linked_list_t	*generate_list_sprite(map_t *map, linked_list_t *list_texture);

// other

void	destroy_map_graph(map_graph_t *map);

map_t	*search_map(linked_list_t *list_map, int index);

void	no_display_object(linked_list_t *list, unsigned int x, unsigned int y);

#endif
