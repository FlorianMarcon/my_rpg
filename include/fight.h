/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** fight.h
*/

#include <SFML/Graphics.h>
#include "stat.h"

#ifndef __FIGHT__
#define __FIGHT__

typedef	struct	my_sclock_s
{
	sfClock *my_clok;
	sfTime my_time;
	float second;
} my_sclock_t;

typedef struct linked_txt_s
{
	sfText *text;
	struct linked_txt_s *next;
} linked_txt_t;

typedef struct ennemy_s
{
	int vie_m;
	int vie;
	int att_m;
	int att_p;
	int defence;
	int xp_g;
	char *name;
	sfTexture	*texture;
	sfSprite	*sprite;
	sfSprite	*sprite2;
	sfVector2f	position;
	sfIntRect	rect;
} ennemy_t;

typedef struct fight_s
{
	item_t *item;
	int fight_mode;
	linked_txt_t *txt;
//	sfVector2f m_pos;
	ennemy_t *ennemy;
} fight_t;

fight_t	*init_fight(void);

#endif /*__FIGHT__*/
