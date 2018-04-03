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
#include "game.h"
#include "map.h"
#include "my_printf.h"

int	fill_all(map_t *map, int fd)
{
	if (fill_setting(map, fd)) {
		return (1);
	}
	if (fill_matter(map, fd)) {
		return (1);
	} else if (fill_map(map, fd)) {
		//free(map->state);
		return (1);
	} else
		return (0);
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
		generate_sprite_map(map);
		return (map);
	}
}
