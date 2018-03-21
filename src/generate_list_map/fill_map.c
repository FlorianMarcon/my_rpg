/*
** EPITECH PROJECT, 2017
** fill_map
** File description:
** fill_map
*/

#include "my.h"
#include "game.h"
#include "map.h"
#include "get_next_line.h"

int	fill_map(map_t *map, int fd)
{
	char *str;
	char **tab;

	if ((map->map = malloc(sizeof(*(map->map)) * (map->height))) == NULL)
		return (1);
	for (int y = 0; y != map->height; y++) {
		str = get_next_line(fd);
		map->map[y] = malloc(sizeof(*(map->map[y])) * (map->width));
		if (map->map[y] == NULL || str == NULL) {
			free(map->map);
			return (1);
		}
		tab = parsing_str(str, ' ');
		for (int x = 0; x != map->width; x++)
			map->map[y][x] = my_getnbr(tab[x]);
		free(tab);
	}
	return (0);
}
