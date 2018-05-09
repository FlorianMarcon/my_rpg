/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** header move_perso
*/

#ifndef INVENTORY_
#define INVENTORY_

#include "map.h"

typedef struct obj_inv {
	char *type;
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f pos;
	int att;
	int att_mag;
} obj_inv_t;

typedef struct inv {
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f pos;
	struct inv *next;
} inv_t;

inv_t	*init_inventory(void);

void	display_inventory(sfRenderWindow *win, sfSprite *sprite);

linked_list_t	*generate_list_inventory(char *path);

#endif
