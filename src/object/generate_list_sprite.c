/*
** EPITECH PROJECT, 2017
** generate_list_sprite
** File description:
** generate_list_sprite
*/

#include <sys/types.h>
#include <dirent.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "map.h"
#include "game.h"

void	set_sprite_from_object(object_t *obj, sprite_t *spr)
{
	spr->obj = obj;
	spr->sprite = sfSprite_create();
	spr->rect = obj->rect;
	spr->nb_rect = 0;
	spr->clock = NULL;
	spr->time_no_disp = NULL;
	spr->displaying = true;
}
sprite_t	*generate_sprite_from_object(object_t *obj, sfVector2f *pos)
{
	sprite_t *spr = malloc(sizeof(*spr));

	if (spr == NULL)
		return (NULL);
	set_sprite_from_object(obj, spr);
	if (obj->max_rect > 0) {
		pos->x -= (obj->rect.width * 0.25);
		pos->y -= (obj->size.y * 0.75);
	} else {
		pos->x -= (obj->size.x * 0.25);
		pos->y -= (obj->size.y * 0.75);
	}
	sfSprite_setPosition(spr->sprite, *pos);
	sfSprite_setTexture(spr->sprite, obj->texture, sfTrue);
	if (obj->max_rect > 0) {
		sfSprite_setTextureRect(spr->sprite, spr->rect);
		spr->clock = sfClock_create();
	}
	spr->states = generate_state(obj->path, obj->shader);
	return (spr);
}

sprite_t	*add_object_graph_list(map_t *map, linked_list_t *tex,\
		sfVector2i *a)
{
	object_t *obj;
	sprite_t *spr = NULL;
	int index;
	sfVector2f pos = {map->iso[a->y][a->x].x, map->iso[a->y][a->x].y};

	index = map->map[a->y][a->x];
	if (index < 20)
		return (NULL);
	else if (index >= 100)
		index = 100;
	obj = search_object(tex, index);
	if (obj == NULL || (spr = generate_sprite_from_object(obj, &pos))\
	== NULL)
		return (NULL);
	else {
		spr->x = a->x;
		spr->y = a->y;
		return (spr);
	}
	return (NULL);
}

linked_list_t	*generate_list_sprite(map_t *map, linked_list_t *list_texture)
{
	linked_list_t *new = NULL;
	sprite_t *spr;
	sfVector2i pos;

	for (int y = 0; y != map->height; y++) {
		for (int x = 0; x != map->width; x++) {
			pos.x = x;
			pos.y = y;
			spr = add_object_graph_list(map, list_texture, &pos);
			if (spr != NULL && new == NULL)
				new = create_list(spr);
			if (spr != NULL && new != NULL)
				create_node(new, spr);
		}
	}
	return (new);
}
