/*
** EPITECH PROJECT, 2018
** inv
** File description:
** player
*/

#include "inventory.h"

obj_inv_t	*find_my_obj(linked_list_t *tmp, char *name)
{
	obj_inv_t *ptr = NULL;

	while (tmp != NULL) {
		ptr = (obj_inv_t *)tmp->data;
		fprintf(stderr, "%s    %s\n", name, ptr->type);
		if (strcmp(ptr->type, name) == 0)
				return (ptr);
			tmp = tmp->next;
		}
	return (NULL);
}

player_inv_t	*create_node_player(obj_inv_t *obj)
{
	player_inv_t *elem = malloc(sizeof(player_inv_t));

	elem->sprite = sfSprite_create();
	if (elem->sprite == NULL) {
		free(elem);
		return (NULL);
	}
	sfSprite_setTexture(elem->sprite, obj->texture, sfTrue);
	elem->att = obj->att;
	elem->att_mag = obj->att_mag;
	elem->next = NULL;
	return (elem);
}

player_inv_t	*create_obj_in_inv(linked_list_t *tmp, char *name, player_inv_t *list)
{
	obj_inv_t *obj = NULL;
	player_inv_t *new = NULL;

	obj = find_my_obj(tmp, name);
	if (obj == NULL)
		return (list);
	new = create_node_player(obj);
	if (new == NULL) {
		return (list);
	}
	if (list == NULL)
		list = new;
	else {
		while (list->next != NULL)
			list = list->next;
		list->next = new;
	}
	return (list);
}
