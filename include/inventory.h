/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** header move_perso
*/

#include "map.h"

#ifndef INVENTORY_
#define INVENTORY_

//#include "game.h"

typedef struct obj_inv {
	char *type;
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f pos;
	int att;
	int att_mag;
	struct obj_inv *next;
} obj_inv_t;

typedef struct inv {
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f pos;
	struct inv *next;
} inv_t;

inv_t	*init_inventory(void);

inv_t	*inventory(inv_t *tmp);

void	display_inventory(sfRenderWindow *win, sfSprite *sprite);

#endif
