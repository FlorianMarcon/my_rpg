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
		if (strcmp(ptr->type, name) == 0) 
				return (ptr);
			tmp = tmp->next;
		}
	return (NULL);
}

int	*init_pos_inventory(void)
{
	int i = 0;
	int x = 0;
	int y = 0;
	int value_x = 714;
	int value_y = 289;
	int *arr = malloc(sizeof(int) * 57);

	while (y != 7) {
		x = 0;
		value_x = 714;
		while (x != 8) {
			if (i % 2 == 0) {
				arr[i] = value_x;
				value_x += 80;
			} else
				arr[i] = value_y;
			i++;
			x++;
		}
		value_y += 79;
		y++;
	}
	return (arr);
}

int	calc_place(player_inv_t *ptr)
{
	int i = 0;
	
	while (ptr != NULL) {
		i++;
		ptr = ptr->next;
	}
	return (i);
}

player_inv_t	*create_node_player(obj_inv_t *tmp, int i, int *arr)
{
	player_inv_t *elem = malloc(sizeof(player_inv_t));
	obj_inv_t *str = tmp;

	elem->sprite = sfSprite_create();
	sfSprite_setTexture(elem->sprite, str->texture, sfTrue);
	elem->att = str->att;
	elem->att_mag = str->att_mag;
	elem->pos.x = arr[i];
	elem->pos.y = arr[i + 1];
	elem->next = NULL;
	sfSprite_setPosition(elem->sprite, elem->pos);
	return (elem);
}

player_inv_t	*create_obj_in_inv(linked_list_t *tmp, char *name, player_inv_t *list)
{
	int place = calc_place(list);
	int *pos_in_inv = init_pos_inventory();
	obj_inv_t *obj = NULL;
	player_inv_t *new = NULL;
	
	obj = find_my_obj(tmp, name);
	if (tmp == NULL)
		return (list);
	new = create_node_player(obj, place, pos_in_inv);
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
