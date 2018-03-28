/*
** EPITECH PROJECT, 2017
** search_map
** File description:
** search_map
*/

#include "map.h"

map_t	*search_map(linked_list_t *list, int number)
{
	map_t *map = NULL;

	while (list != NULL) {
		map = (map_t *)list->data;
		if (map != NULL) {
			if (map->number == number)
				return (map);
		}
		list = list->next;
	}
	return (NULL);
}
