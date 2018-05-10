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
#define PATH_DIR_QUETE "./quete/"
#define PATH_DIR_INV "./inventory/"
#define BACKGROUND "./matter/background.jpg"

#include <stdbool.h>
#include "move_perso.h"
#include "graphique.h"
#include "my.h"
#include "map.h"
#include "inventory.h"
#include "quete.h"
#include "stat.h"

typedef struct pause_s {
	sfSprite *pause;
	sfTexture *texture_pause;
	sfVector2f pos_pause;
} pause_t;

typedef struct game_s {

	// map
	linked_list_t *list_map;
	map_t *map;
	map_graph_t *map_graph;
	bool draw_line;

	//map_t *map;
	int index;

	// window
	window_t *win;
	sfSprite *background;

	//object
	linked_list_t *list_obj;

	//quete
	linked_list_t *list_quete;
	sfSprite *textbox;
	sfText *text[8];
	unsigned int size_text;
	bool display_textbox;

	//joueur
	perso_t *perso;
	bool can_move;

	//stat_bar
	chstat_t *stat;

	//inventory
	linked_list_t *list_inventory;
	bool can_disp;
	player_inv_t *list_inv_player;
	inv_t *back_inv;

	//pause
	pause_t *pause;

} game_t;

game_t	*initialisation_game(void);

int	loop_game(game_t *game);

void	display(game_t *game, inv_t *tmp);

bool	event(game_t *game);

bool      loop_pause(game_t *game);

//utilitaries

int	is_extension(char *str, char *ext);

sfVector2f	**create_two_d_map(map_t *map);

sfVector2f	project_iso_point(int x, int y, map_t *map);

sfVertexArray *create_quad(sfVector2f point1, sfVector2f point2,\
					sfVector2f point3, sfVector2f point4);

sfVertexArray *create_quad_bottom_map(sfVector2f point1, sfVector2f point2);

sfVertexArray   *create_line(sfVector2f point1, sfVector2f point2, sfColor color);

int	change_map(game_t *game);

map_graph_t	*generate_map_graph(map_t *map, game_t *game);

//perso
void	dep_right(game_t *game);

void	dep_left(game_t *game);

void	dep_up(game_t *game);

void	dep_down(game_t *game);

void	affect_move_perso(game_t *game);

void	replace_rect(game_t *game, int i);

//autre

void	display_map(game_t *game, window_t *win, bool line);

int	loop_menu(void);

// quete

void	run_quete(game_t *game, int id);

quete_t	*search_quete(game_t *game, int id);

void	display_quete(game_t *game);

void	display_pause(game_t *game);

void	replace_perso(game_t *game, int x, int y);

bool	status_quete(quete_t *quete, game_t *game);

//lvl_up

void	lvl_up(game_t *game);

//colision

int	detect_col(game_t *game, int sens);

//pause

pause_t	*init_pause(void);

//stat

void	display_stat_bar(game_t *game);

// inventory

void	inventory(game_t *game);

void	drag_and_drop(game_t *game);
//object

void	move_object(game_t *game);

void	launch_fight(game_t *game);

#endif
