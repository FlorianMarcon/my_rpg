/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** header move_perso
*/


#ifndef HEADER_
#define HEADER_

//#include "game.h"
#include "map.h"

typedef struct my_clock_s
{
	sfClock	*my_clock;
	sfTime	my_time;
	float	second;
	struct my_clock_s *next;
} my_clock_t;

typedef struct stat_s
{
	int att_m;
	int att_p;
	int defence;
	int xp;
	int xp_max;
	int vie;
	int vie_c;
	int lvl;
	bool change;
} stat_t;

typedef struct perso_s
{
	char const	*name;
	sfTexture	*texture;
	sfSprite	*sprite;
	sfVector2f	mouvement;
	sfVector2f	position;
	sfIntRect	rect;
	int		x;
	int		y;
	stat_t		stat;
} perso_t;

typedef	struct param_s
{
	window_t *win;
	perso_t *perso;
	map_t *map;
	linked_list_t *list;
} param_t;

void	display_perso(perso_t *perso, window_t *win);

perso_t	*create_my_perso(void);

perso_t	*create_bg(void);

void	move_perso(perso_t *perso, my_clock_t *my_clock);

void	move_rect(perso_t *perso, int i, float second, sfClock *my_clock);

my_clock_t	*update_time(my_clock_t *my_clock);

my_clock_t	*init_clock(void);

#endif
