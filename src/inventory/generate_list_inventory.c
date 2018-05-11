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

void	set_attack_object_inv(obj_inv_t *obj, int fd)
{
	char *str = NULL;

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
}

obj_inv_t	*generate_object_inv(char *path)
{
	int fd = open(path, O_RDONLY);
	obj_inv_t *obj;
	char *str;

	if (fd == -1)
		return (NULL);
	if ((obj = malloc(sizeof(*obj))) == NULL)
		return (NULL);
	obj->name = get_next_line(fd);
	obj->type = get_next_line(fd);
	set_attack_object_inv(obj, fd);
	if ((str = get_next_line(fd)) != NULL) {;
		obj->texture = sfTexture_createFromFile(str, NULL);
		free(str);
	}
	return (obj);
}

linked_list_t	*generate_list_inv_create(char *way, linked_list_t *li)
{
	obj_inv_t *obj;

	obj = generate_object_inv(way);
	if (obj == NULL)
		return (li);
	if (li == NULL) {
		li = create_list(obj);
	} else
		create_node(li, obj);
	return (li);

}
linked_list_t	*generate_list_inventory(char *path)
{
	DIR *dir = opendir(path);
	struct dirent *file;
	linked_list_t *list = NULL;
	char *way;

	if (dir == NULL)
		return (NULL);
	while ((file = readdir(dir)) != NULL) {
		way = my_strcat(path, file->d_name);
		if (is_extension(way, "inv")) {
			list = generate_list_inv_create(way, list);
		}
		free(way);
	}
	closedir(dir);
	return (list);
}
