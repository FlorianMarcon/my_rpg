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

linked_list_t	*generate_list_map_create(char *way, linked_list_t *list)
{
	map_t *map = generate_map(way);

	if (map == NULL)
		return (list);
	if (list == NULL) {
		list = create_list(map);
	} else
		create_node(list, map);
	return (list);
}
linked_list_t	*generate_list_map(char *path)
{
	DIR *dir = opendir(path);
	struct dirent *file;
	linked_list_t *list = NULL;
	char *way;

	if (dir == NULL)
		return (NULL);
	while ((file = readdir(dir)) != NULL) {
		way = my_strcat(path, file->d_name);
		if (is_extension(way, "map"))
			list = generate_list_map_create(way, list);
		free(way);
	}
	closedir(dir);
	return (list);
}
