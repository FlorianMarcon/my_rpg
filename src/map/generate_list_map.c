/*
** EPITECH PROJECT, 2017
** generate_list_map
** File description:
** generate_list_map
*/

#include <sys/types.h>
#include <dirent.h>
#include "my.h"
#include "map.h"
#include "game.h"

linked_list_t	*generate_list_map(char *path)
{
	DIR *dir = opendir(path);
	struct dirent *file;
	linked_list_t *list = NULL;
	map_t *map;
	char *way;

	if (dir == NULL)
		return (NULL);
	while ((file = readdir(dir)) != NULL) {
		way = my_strcat(path, file->d_name);
		if (is_extension(way, "map"))
			map = generate_map(way);
		else
			map = NULL;
		if (map != NULL) {
			if (list == NULL) {
				list = create_list(map);
			} else
				create_node(list, map);
		}
		free(way);
	}
	closedir(dir);
	return (list);
}
