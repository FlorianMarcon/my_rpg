/*
** EPITECH PROJECT, 2017
** gene_list_inventory
** File description:
** gene_list_inventory
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>
#include "inventory.h"
#include "game.h"

obj_inv_t	*generate_object_inv(char *path)
{
	int fd = open(path, O_RDONLY);
	obj_inv_t *obj;
	char *str;

	if (fd == -1)
		return (NULL);
	if ((obj = malloc(sizeof(*obj))) == NULL)
		return (NULL);
	obj->type = get_next_line(fd);
	obj->att = 0;
	obj->att_mag = 0;
	if ((str = get_next_line(fd)) != NULL) {
		obj->att = atoi(str);
		free(str);
	}
	if ((str = get_next_line(fd)) != NULL) {;
		obj->att_mag = atoi(str);
		free(str);
	}
	if ((str = get_next_line(fd)) != NULL) {;
		obj->texture = sfTexture_createFromFile(str, NULL);
		free(str);
	}
	return (obj);
}
linked_list_t	*generate_list_inventory(char *path)
{
	DIR *dir = opendir(path);
	struct dirent *file;
	linked_list_t *list = NULL;
	object_t *obj;
	char *way;

	if (dir == NULL)
		return (NULL);
	while ((file = readdir(dir)) != NULL) {
		way = my_strcat(path, file->d_name);
		if (is_extension(way, "inv"))
			obj = generate_object(way);
		else
			obj = NULL;
		if (obj != NULL) {
			if (list == NULL) {
				list = create_list(obj);
			} else
				create_node(list, obj);
		}
		free(way);
	}
	closedir(dir);
	return (list);
}
