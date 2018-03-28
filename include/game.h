/*
** EPITECH PROJECT, 2017
** game.h
** File description:
** game.h
*/

#ifndef GAME_
#define GAME_

#include "map.h"
#include "graphique.h"
#include "my.h"

#define PATH "./map/"
#define BACKGROUND "./matter/background.jpg"

typedef struct game_s {
	linked_list_t *list_map;
	map_t *map;
	window_t *win;
	sfSprite *background;
}game_t;

game_t	*initialisation_game(void);

int	loop_game(void);

void	display(game_t *game);

#endif
