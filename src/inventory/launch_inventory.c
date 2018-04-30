/*
** EPITECH PROJECT, 2018
** launch
** File description:
** inventory
*/

#include "inventory.h"

inv_t	*inventory(inv_t *tmp)
{
	
	if(sfKeyboard_isKeyPressed(sfKeyI)) {
		tmp->pos.x = 0;
		tmp->pos.y = 0;
	}
	if(sfKeyboard_isKeyPressed(sfKeyQ)) {
		tmp->pos.x = 8000;
		tmp->pos.y = 8000;
	}
	sfSprite_setPosition(tmp->sprite, tmp->pos);
	return (tmp);
}
