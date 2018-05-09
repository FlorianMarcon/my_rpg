/*
** EPITECH PROJECT, 2018
** inv
** File description:
** player
*/

#include "inventory.h"


linked_list_t	*find_my_obj(linked_list_t *tmp, char *name)
{
	obj_inv_t *ptr = tmp->data;
	
	if (tmp != NULL) {
		while (strcmp(ptr->type, name) != 0)
			tmp = tmp->next;
	}
	return (tmp);
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

	while (ptr->next != NULL) {
		i++;
		ptr = ptr->next;
	}
	return (i);
}

player_inv_t	*create_node_player(player_inv_t *ptr, linked_list_t *tmp, int i, int *arr)
{
	player_inv_t *elem = malloc(sizeof(player_inv_t));
	obj_inv_t *str = tmp->data;

	while (ptr->next != NULL)
		ptr = ptr->next;
	elem->sprite = sfSprite_create();
	sfSprite_setTexture(elem->sprite, str->texture, sfTrue);
	elem->att = str->att;
	elem->att_mag = str->att_mag;
	elem->pos.x = arr[i];
	elem->pos.y = arr[i + 1];
	ptr->next = elem;
	elem->next = NULL;
	sfSprite_setPosition(elem->sprite, elem->pos);
	return (ptr);
}

player_inv_t	*create_obj_in_inv(linked_list_t *tmp, char *name, player_inv_t *ptr)
{
	int place = calc_place(ptr);
	int *pos_in_inv = init_pos_inventory();
	
	tmp = find_my_obj(tmp, name);
	ptr = create_node_player(ptr, tmp, place, pos_in_inv);
	return (ptr);
}
