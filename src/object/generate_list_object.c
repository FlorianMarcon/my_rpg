/*
** EPITECH PROJECT, 2017
** generate_list_object
** File description:
** generate_list_object
*/

#include <sys/types.h>
#include <dirent.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "map.h"
#include "game.h"

linked_list_t	*generate_list_object_create(char *way, linked_list_t *list)
{
	object_t *obj = generate_object(way);

	if (obj != NULL) {
		if (list == NULL) {
			list = create_list(obj);
		} else
			create_node(list, obj);
	}
	return (list);
}
linked_list_t	*generate_list_object(char *path)
{
	DIR *dir = opendir(path);
	struct dirent *file;
	linked_list_t *list = NULL;
	char *way;

	if (dir == NULL)
		return (NULL);
	while ((file = readdir(dir)) != NULL) {
		way = my_strcat(path, file->d_name);
		if (is_extension(way, "object"))
			list = generate_list_object_create(way, list);
		free(way);
	}
	closedir(dir);
	return (list);
}
