/*
** EPITECH PROJECT, 2018
** inv
** File description:
** player
*/

#include "inventory_header.h"

linked_list_t	*find_my_obj(linked_list_t *tmp, char *name)
{
}

player_inv_t	*create_player_obj(linked_list_t *tmp, char *name, inv_t *inv, 	player_inv_t *ptr)
{
	static int place =  calc_place(player);

	tmp = find_my_obj(tmp);
	ptr = create_node(ptr, tmp);
	
}
