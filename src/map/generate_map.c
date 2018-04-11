/*
** EPITECH PROJECT, 2017
** generate_map
** File description:
** generate_map
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "game.h"
#include "map.h"
#include "my_printf.h"

sprite_t	*generate_sprite_from_object(object_t *obj, sfVector2f pos)
{
	sprite_t *sprite = malloc(sizeof(*sprite));

	sprite->texture = sfTexture_copy(obj->texture);
	sprite->sprite = sfSprite_create();
	sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
	sprite->rect = malloc(sizeof(*sprite->rect));
	sprite->rect->width = obj->rect->width;
	sprite->rect->height = obj->rect->height;
	sprite->rect->left = obj->rect->left;
	sprite->rect->top = obj->rect->top;
	sprite->max_rect = obj->max_rect;
	sprite->size = sfTexture_getSize(sprite->texture);
	pos.y = pos.y - sprite->size.y + SCALING_Y;
	pos.x = pos.x - (SCALING_X / 2);
	sfSprite_setPosition(sprite->sprite, pos);
	return (sprite);
}

object_t	*search_object(linked_list_t *list, int nb)
{
	object_t *obj;

	while (list != NULL) {
		obj = (object_t *)list->data;
		if (obj != NULL && obj->number == nb)
			return (obj);
		list = list->next;
	}
	return (NULL);
}
void	generate_sprite_map_object(linked_list_t *text, map_t *map)
{
	linked_list_t *list = NULL;
	object_t *obj;
	sprite_t *sprite = NULL;

	for (int x = 0; x != map->width; x++) {
		for (int y = 0; y != map->height; y++) {
			if ((obj = search_object(text, map->map[y][x])) != NULL)
				sprite = generate_sprite_from_object(obj, (map->map_iso[y][x]));
			if (list == NULL && sprite != NULL)
				list = create_list(sprite);
			if (list != NULL && sprite != NULL)
				create_node(list, sprite);
			sprite = NULL;
		}
	}
	map->list_object = list;
}

int	fill_all(map_t *map, int fd)
{
	if (fill_setting(map, fd)) {
		return (1);
	}
	if (fill_matter(map, fd)) {
		return (1);
	} else if (fill_map(map, fd)) {
		//free(map->state);
		return (1);
	} else
		return (0);
}

map_t	*generate_map(linked_list_t *text, char *path)
{
	(void)text;
	map_t *map;
	int fd = open(path, O_RDONLY);

	if (fd == -1)
		return (NULL);
	if ((map = malloc(sizeof(*map))) == NULL) {
		close(fd);
		return (NULL);
	} else if (fill_all(map, fd)) {
		free(map);
		close(fd);
		return (NULL);
	} else {
		close(fd);
		generate_sprite_map(map);
		generate_sprite_map_object(text, map);
//		generate_sprite_line_map(map);
		return (map);
	}
}
