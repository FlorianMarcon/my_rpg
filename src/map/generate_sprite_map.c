/*
** EPITECH PROJECT, 2017
** generate_sprite_map
** File description:
** generate_sprite_map
*/

#include <SFML/Graphics.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "map.h"
#include "my_printf.h"

void	generate_sprite_map(map_t *map)
{
	sfVector2f **iso = create_two_d_map(map);
	int a = 0;
	int o = 0;

	map->arr_vertex = malloc(sizeof(*map->arr_vertex) * ((map->width - 1) * (map->height - 1) + 1));
	map->arr_bottom = malloc(sizeof(*map->arr_bottom) * (map->width * map->height) * 2);
	if (map->arr_vertex == NULL || map->arr_bottom == NULL) {
		map->arr_bottom = NULL;
		map->arr_vertex = NULL;
		return;
	}
	for (int j = 0; j < map->height - 1; j++) {
		for (int i = 0; i < map->width - 1; i++) {
			map->arr_vertex[a++] = create_quad(iso[j][i], iso[j][i + 1], iso[j + 1][i + 1], iso[j + 1][i]);
			if (i == map->width - 2)
				map->arr_bottom[o++] = create_quad_bottom_map(iso[j][i + 1], iso[j + 1][i + 1]);
			if (j == map->height - 2)
				map->arr_bottom[o++] = create_quad_bottom_map(iso[j + 1][i], iso[j + 1][i + 1]);

		}
	}
	map->arr_bottom[o] = NULL;
	map->map_iso = iso;
}

void	generate_sprite_line_map(map_t *map)
{
	sfVector2f **iso = map->map_iso;
	sfVertexArray **arr_line;
	int a = 0;

	if (iso == NULL || (arr_line = malloc(sizeof(*arr_line) * ((map->width) * (map->height) * 3))) == NULL)
		return;
	for (int j = 0; j < map->height - 7; j++) {
		for (int i = 0; i < map->width - 7; i++) {
			my_printf("%i  %i\n", j, i);
			map->arr_line[a++] = create_line(iso[j][i], iso[j][i + 1], sfBlack);
			map->arr_line[a++] = create_line(iso[j][i], iso[j + 1][i], sfBlack);
		}
	}
	my_printf("END\n");
	map->arr_line[a] = NULL;
}
