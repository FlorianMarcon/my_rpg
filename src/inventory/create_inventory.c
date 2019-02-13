/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "inventory.h"

inv_t	*init_inventory(void)
{
	inv_t *elem = malloc(sizeof(inv_t));

	elem->sprite = sfSprite_create();
	elem->texture = sfTexture_createFromFile(
			"src/inventory/png_inventory/inventory.png", NULL);
	sfSprite_setTexture(elem->sprite, elem->texture, sfTrue);
	elem->pos = (sfVector2f){10000, 1000000};
	sfSprite_setPosition(elem->sprite, elem->pos);
	return (elem);
}
