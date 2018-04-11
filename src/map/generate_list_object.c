/*
** EPITECH PROJECT, 2017
** generate_list_object
** File description:
** generate_list_object
*/

#include <sys/types.h>
#include <dirent.h>
#include "my.h"
#include "map.h"

linked_list_t	*generate_list_object(char *path)
{
	DIR *dir = opendir(path);
	struct dirent *file;
	linked_list_t *list = NULL;
	object_t *obj;

	if (dir == NULL)
		return (NULL);
	while ((file = readdir(dir)) != NULL) {
		obj = generate_object(my_strcat(path, file->d_name));
		if (obj == NULL) {
		} else if (list == NULL) {
			list = create_list(obj);
		} else {
			create_node(list, obj);
		}
	}
	closedir(dir);
	return (list);
}
