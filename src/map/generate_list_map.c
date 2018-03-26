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

linked_list_t	*generate_list_map(char *path)
{
	DIR *dir = opendir(path);
	struct dirent *file;
	linked_list_t *list = NULL;
	map_t *map;

	if (dir == NULL)
		return (NULL);
	while ((file = readdir(dir)) != NULL) {
		map = generate_map(my_strcat(path, file->d_name));
		if (map == NULL) {
		} else if (list == NULL) {
			list = create_list(map);
		} else {
			create_node(list, map);

		}
	}
	closedir(dir);
	return (list);
}
