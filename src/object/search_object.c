/*
** EPITECH PROJECT, 2017
** search_map
** File description:
** search_map
*/

#include "map.h"

object_t	*search_object(linked_list_t *list_obj, int index)
{
	object_t *obj;

	while (list_obj != NULL) {
		obj = (object_t *)list_obj->data;
		if (obj != NULL && obj->number == index)
			return (obj);
		list_obj = list_obj->next;
	}
	return (NULL);
}
