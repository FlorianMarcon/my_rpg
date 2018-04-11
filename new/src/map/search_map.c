/*
** EPITECH PROJECT, 2017
** search_map
** File description:
** search_map
*/

#include "map.h"

map_t	*search_map(linked_list_t *list_map, int index)
{
	map_t *map;

	while (list_map != NULL) {
		map = (map_t *)list_map->data;
		if (map != NULL && map->number == index)
			return (map);
		list_map = list_map->next;
	}
	return (NULL);
}
