/*
** EPITECH PROJECT, 2017
** generate_object
** File description:
** generate_object
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "map.h"
#include "my.h"

void	fill_rect(object_t *obj, int fd)
{
	char *str = get_next_line(fd);
	char **tab;
	sfIntRect *rect = malloc(sizeof(*rect));

	if (rect == NULL || str == NULL)
		return;
	tab = parsing_str(str, ' ' | '\t');
	rect->left = 0;
	rect->top = 0;
	rect->width = my_getnbr(tab[0]);
	rect->height = my_getnbr(tab[1]);
	obj->max_rect = my_getnbr(tab[2]);
	free(tab);
	obj->rect = rect;
}

sfTexture	*generate_texture_from_fd(int fd, sfIntRect *rect)
{
	char *path = get_next_line(fd);
	sfTexture *texture;

	if (path == NULL)
		return (NULL);
	my_printf("path = %s\n", path);
	texture = sfTexture_createFromFile(path, rect);
	free(path);
	return (texture);
}

object_t	*generate_object(char *path)
{
	object_t *obj = malloc(sizeof(*obj));
	char *str;
	int fd = open(path, O_RDONLY);

	if (fd == -1 || obj == NULL)
		return (NULL);
	if ((obj->name = get_next_line(fd)) == NULL) {
		free(obj);
		return (NULL);
	}
	fill_rect(obj, fd);
	obj->texture = generate_texture_from_fd(fd, obj->rect);
	str = get_next_line(fd);
	obj->number = my_getnbr(str);
	free(str);
	close(fd);
	return (obj);
}
