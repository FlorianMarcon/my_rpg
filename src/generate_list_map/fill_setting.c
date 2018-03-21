/*
** EPITECH PROJECT, 2017
** fill_setting
** File description:
** fill_setting
*/

#include "my.h"
#include "get_next_line.h"
#include "game.h"
#include "map.h"

int	fill_setting(map_t *map, int fd)
{
	char *str = get_next_line(fd);
	char **tab;

	if (str == NULL)
		return (1);
	if ((tab = parsing_str(str, ' ')) == NULL || len_tab(tab) != 3) {
		free(str);
		return (1);
	}
	map->width = my_getnbr(tab[0]);
	map->height = my_getnbr(tab[1]);
	map->number = my_getnbr(tab[2]);
	map->x_center = map->width / 2;
	map->y_center = map->height / 2;
	free(str);
	return (0);
}
