/*
** EPITECH PROJECT, 2017
** generate_map
** File description:
** generate_map
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "game.h"
#include "my.h"
#include "map.h"

int	fill_setting(int fd, map_t *map)
{
	char *str = get_next_line(fd);
	char **tab;
	int res = 1;

	if (str == NULL) {
	} else if ((tab = parsing_str(str, ' ' | '\t')) == NULL) {
		free(str);
	} else {
		if (len_tab(tab) == 3) {
			res = 0;
			map->width = my_getnbr(tab[0]);
			map->x_center = map->width / 2;
			map->height = my_getnbr(tab[1]);
			map->y_center = map->height / 2;
			map->number = my_getnbr(tab[2]);
		}
		free(str);
		free(tab);
	}
	return (res);
}
int	fill_path_sprite(int fd, map_t *map)
{
	char *str;

	if ((str = get_next_line(fd)) == NULL)
		return (1);
	map->path_sprite_floor = str;
	if ((str = get_next_line(fd)) == NULL) {
		free(map->path_sprite_floor);
		return (1);
	}
	map->path_sprite_teleport = str;
	if ((str = get_next_line(fd)) == NULL) {
		free(map->path_sprite_floor);
		free(map->path_sprite_teleport);
		return (1);
	}
	map->path_sprite_bottom = str;
	if ((str = get_next_line(fd)) == NULL) {
		free(map->path_sprite_floor);
		free(map->path_sprite_teleport);
		return (1);
	}
	map->path_sprite_back = str;
	return (0);
}

int     fill_map(int fd, map_t *map)
{
	char *str;
	char **tab;
	int **arr_map = malloc(sizeof(*(map->map)) * (map->height));

	if (arr_map == NULL)
		return (1);
	for (int y = 0; y != map->height; y++) {
		str = get_next_line(fd);
		if (str == NULL || (arr_map[y] = malloc(sizeof(*(arr_map[y])) * (map->width))) == NULL) {
			free(arr_map);
			return (1);
		} else {
			tab = parsing_str(str, ' ');
			for (int x = 0; x != map->width && tab[x] != NULL; x++)
				arr_map[y][x] = my_getnbr(tab[x]);
			free(tab);
		}
	}
	map->map = arr_map;
	return (0);
}

map_t	*generate_map(char *path)
{
	int fd = open(path, O_RDONLY);
	map_t *map;
	int res = 0;

	if (fd == -1)
		return (NULL);
	else if ((map = malloc(sizeof(*map))) == NULL) {
		close(fd);
	} else {
		res += fill_setting(fd, map);
		res += fill_path_sprite(fd, map);
		res += fill_map(fd, map);
		if (res != 0) {
			free(map);
			map = NULL;
		} else
			map->iso = create_two_d_map(map);
	}
	return (map);
}
