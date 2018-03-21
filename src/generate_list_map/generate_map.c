/*
** EPITECH PROJECT, 2017
** generate_map
** File description:
** generate_map
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "map.h"
#include "my_printf.h"

sfVector2f	**create_two_d_map(map_t *map);
sfVertexArray *create_quad(sfVector2f point1, sfVector2f point2, sfVector2f point3, sfVector2f point4);
sfVertexArray *create_quad_bottom_map(sfVector2f point1, sfVector2f point2);

int	fill_all(map_t *map, int fd)
{
	if (fill_setting(map, fd)) {
		return (1);
	}
	if (fill_matter(map, fd)) {
		return (1);
	} else if (fill_map(map, fd)) {
		free(map->state);
		return (1);
	} else
		return (0);
}
void	generate_array_vertex_array(map_t *map)
{
	sfVector2f **iso = create_two_d_map(map);
	int a = 0;
	int o = 0;

	map->arr_vertex = malloc(sizeof(*map->arr_vertex) * ((map->width - 1) * (map->height - 1) + 1));
//	map->arr_bottom = malloc(sizeof(*map->arr_vertex) * ((map->width - 1) * (map->height - 1) + 1) * 4);
map->arr_bottom = malloc(sizeof(*map->arr_vertex) * (map->width * map->height) * 2);
	for (int j = 0; j < map->height - 1; j++) {
		for (int i = 0; i < map->width - 1; i++) {
			map->arr_vertex[a++] = create_quad(iso[j][i], iso[j][i + 1], iso[j + 1][i + 1], iso[j + 1][i]);
			if (i == map->width - 2)
				map->arr_bottom[o++] = create_quad_bottom_map(iso[j][i + 1], iso[j + 1][i + 1]);
			if (j == map->height - 2)
				map->arr_bottom[o++] = create_quad_bottom_map(iso[j + 1][i], iso[j + 1][i + 1]);
//			map->arr_bottom[o++] = create_quad_bottom_map(iso[j][i], iso[j][i + 1]);
//			map->arr_bottom[o++] = create_quad_bottom_map(iso[j][i], iso[j + 1][i]);

		}
	}
	map->arr_bottom[o] = NULL;
}
map_t	*generate_map(char *path)
{
	map_t *map;
	int fd = open(path, O_RDONLY);

	if (fd == -1) {
		my_printf("Bad file");
		return (NULL);
	}
	if ((map = malloc(sizeof(*map))) == NULL) {
		close(fd);
		return (NULL);
	} else if (fill_all(map, fd)) {
		free(map);
		close(fd);
		return (NULL);
	} else {
		close(fd);
		generate_array_vertex_array(map);
		return (map);
	}
}
