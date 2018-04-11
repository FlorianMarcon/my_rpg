/*
** EPITECH PROJECT, 2017
** game.h
** File description:
** game.h
*/

#ifndef GAME_
#define GAME_

#define PATH_DIR_MAP "./map/"
#define PATH_DIR_OBJ "./object/"
#define BACKGROUND "./matter/background.jpg"

#include <stdbool.h>
#include "map.h"
#include "graphique.h"
#include "my.h"

typedef struct game_s {

	// map
	linked_list_t *list_map;
	bool change_map;

	map_t *map;
	int index;

	// window
	window_t *win;
	sfSprite *background;

	//object

	linked_list_t *list_texture;
	// joueur
//	sfvector2i pos;

}game_t;

game_t	*initialisation_game(void);

int	loop_game(void);

void	display(game_t *game);

void	event(game_t *game);

void	change_map(game_t *game);

#endif
