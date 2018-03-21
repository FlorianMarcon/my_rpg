/*
** EPITECH PROJECT, 2017
** fill_matter
** File description:
** fill_matter
*/

#include "my.h"
#include "game.h"
#include "map.h"
#include "get_next_line.h"
#include <stdlib.h>

int	fill_matter(map_t *map, int fd)
{
	char *str = get_next_line(fd);
	char *str_two = get_next_line(fd);

	if (str == NULL || str_two == NULL)
		return (1);
	map->state = malloc(sizeof(*(map->state)));
	map->state_bottom = malloc(sizeof(*(map->state_bottom)));
	if (map->state == NULL/* || map->state_bottom == NULL*/) {
		free(str);
		return (1);
	}
	map->state->blendMode = sfBlendNone;
	map->state_bottom->blendMode = sfBlendNone;
	map->state->transform = sfTransform_Identity;
	map->state_bottom->transform = sfTransform_Identity;
	map->state->shader = NULL;
	map->state_bottom->shader = NULL;
	map->state->texture = sfTexture_createFromFile(str, NULL);
	map->state_bottom->texture = sfTexture_createFromFile(str_two, NULL);
	if (map->state->texture == NULL) {
		free(str);
		free(map->state);
		return (1);
	}
	return (0);
}
