/*
** EPITECH PROJECT, 2017
** generate_object
** File description:
** generate_object
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "graphique.h"
#include "map.h"

int	fill_setting_object(int fd, object_t *obj)
{
	char *str = get_next_line(fd);
	char **tab;

	if (str == NULL || (tab = parsing_str(str, ' ' | '\t')) == NULL)
		return (1);
	free(str);
	if (len_tab(tab) != 4) {
		free(tab);
		return (1);
	}
	obj->rect.left = 0;
	obj->rect.top = 0;
	obj->rect.width = my_getnbr(tab[0]);
	obj->rect.height = my_getnbr(tab[1]);
	obj->max_rect = my_getnbr(tab[2]);
	obj->time = sfSeconds(atof(tab[3]));
	free(tab);
	if ((str = get_next_line(fd)) == NULL || my_str_isnum(str) == 0)
		return (1);
	obj->number = my_getnbr(str);
	free(str);
	return (0);
}
object_t	*generate_object(char *file)
{
	int fd = open(file, O_RDONLY);
	object_t *obj;
	int res;

	if (fd == -1)
		return (NULL);
	if ((obj = malloc(sizeof(*obj))) == NULL) {
		close(fd);
		return (NULL);
	}
	obj->name = get_next_line(fd);
	res = fill_setting_object(fd, obj);
	obj->path = get_next_line(fd);
	obj->texture = sfTexture_createFromFile(obj->path, NULL);
	if (res || obj->name == NULL || obj->texture == NULL) {
		free(obj);
		return (NULL);
	}
	obj->size = sfTexture_getSize(obj->texture);
	obj->shader = get_next_line(fd);
	close(fd);
	return (obj);
}
