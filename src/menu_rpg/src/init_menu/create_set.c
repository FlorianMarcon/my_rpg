/*
** EPITECH PROJECT, 2018
** create_set.c
** File description:
** setting
*/

#include "header.h"

set_t	*init_set()
{
	set_t *elem = malloc(sizeof(set_t));

	elem->sprite = sfSprite_create();
	elem->texture = sfTexture_createFromFile("src/png_menu/setting.png", NULL);
	elem->pos = (sfVector2f){0, 0};

	return (elem);
}
