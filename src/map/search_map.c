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
		my_printf("aa\n");
		if (map != NULL) {
			my_printf("nb = %i\n", map->number);
			if (map->number == number)
				return (map);
		}
		list = list->next;
	}
	return (NULL);
}
