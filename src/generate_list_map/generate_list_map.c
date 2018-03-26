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
	char *name;

	if (dir == NULL)
		return (NULL);
	while ((file = readdir(dir)) != NULL) {
		name = my_strcat(path, file->d_name);
		if (list == NULL) {
			list = create_list(generate_map(my_strcat(path, file->d_name)));
		} else {
			create_node(list, file->d_name);

		}
		free(name);
	}
	return (list);
}
