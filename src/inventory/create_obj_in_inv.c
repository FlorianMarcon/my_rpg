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
		if (my_strcmp(ptr->name, name) == 0)
				return (ptr);
			tmp = tmp->next;
		}
	return (NULL);
}

player_inv_t	*create_node_player(obj_inv_t *obj)
{
	player_inv_t *elem = malloc(sizeof(player_inv_t));

	elem->sprite = sfSprite_create();
	elem->name = obj->name;
	if (elem->sprite == NULL) {
		free(elem);
		return (NULL);
	}
	sfSprite_setTexture(elem->sprite, obj->texture, sfTrue);
	elem->att = obj->att;
	elem->att_mag = obj->att_mag;
	elem->next = NULL;
	elem->number = sfText_create();
	elem->quantity = 1;
	return (elem);
}

player_inv_t	*add_obj_in_inv(obj_inv_t *obj, player_inv_t *li)
{
	player_inv_t *new = NULL;
	player_inv_t *re = li;

	new = create_node_player(obj);
	if (new == NULL) {
		return (li);
	}
	if (li == NULL) {
		li = new;
	} else {
		while (re->next != NULL) {
			re = re->next;
		}
		re->next = new;
	}
	return (li);
}
player_inv_t	*create_obj_in_inv(linked_list_t *tmp, char *name,
							player_inv_t *list)
{
	obj_inv_t *obj = NULL;
	player_inv_t *new = NULL;

	obj = find_my_obj(tmp, name);
	if (obj == NULL)
		return (list);
	if ((new = search_obj_inv_player(name, list)) != NULL) {
		new->quantity++;
		return (list);
	}
	list = add_obj_in_inv(obj, list);
	return (list);
}
