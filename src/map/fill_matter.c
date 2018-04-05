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

sfRenderStates	*fill_one_matter(char *str)
{
	sfRenderStates *states;

	if (str == NULL)
		return (NULL);
	if ((states = malloc(sizeof(*states))) == NULL) {
		free(str);
		return (NULL);
	}
	states->blendMode = sfBlendNone;
	states->transform = sfTransform_Identity;
	states->shader //= sfShader_createFromFile();
	states->texture; = sfTexture_createFromFile(str, NULL);
	if (states->texture == NULL) {
		free(states);
		states = NULL;
	}
	return (states);
}
int	fill_matter(map_t *map, int fd)
{
	char *str = get_next_line(fd);

	my_printf("%s\n", str);
	if (str == NULL)
		return (1);
	map->state_floor = fill_one_matter(str);
	free(str);
	if (map->state_floor == NULL)
		return (1);
	str = get_next_line(fd);
	map->state_bottom = fill_one_matter(str);
	if (map->state_bottom == NULL) {
		free(map->state_floor);
		map->state_floor = NULL;
		return (1);
	}
	free(str);
	return (0);
}
