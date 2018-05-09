/*
** EPITECH PROJECT, 2017
** loop_game
** File description:
** loop_game
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "game.h"
#include "map.h"
#include "header.h"

int	loop_game(game_t *game, inv_t *tmp, pause_t *pause)
{
//	player_inv_t *ptr = malloc(sizeof(player_inv_t));
	int i = 0;
//	int y = 0;
	int is_pause = 0;
//	sfVector2i test;

//	ptr->next = NULL;

	linked_list_t *relou = game->list_inventory;
	obj_inv_t *pausedemescouilles;
	
	while (relou != NULL) {
		pausedemescouilles = (obj_inv_t *)relou->data;
		if (pausedemescouilles != NULL)
			fprintf(stderr, "%s\n", pausedemescouilles->type);
		relou = relou->next;
	}





	replace_perso(game, 0, 0);
	while (i == 0 && game->map_graph != NULL) {
/*		test = sfMouse_getPositionRenderWindow(game->win->window);
		printf("X == %i\n", test.x);
		printf("Y == %i\n", test.y);*/
		if (sfKeyboard_isKeyPressed(sfKeyM)) {
			pause->pos_pause.x = 0;
			pause->pos_pause.y = 0;
			sfSprite_setPosition(pause->pause, pause->pos_pause);
			is_pause = 1;
		}
		tmp = inventory(tmp);
/*		if (y == 0) {
			ptr = create_obj_in_inv(game->list_inventory, "sword", ptr);
			y++;
			}*/
		display(game, tmp, pause, NULL);
		event(game);
		if (is_pause == 1) {
			if (sfKeyboard_isKeyPressed(sfKeyP)) {
				pause->pos_pause.x = 1220;
				pause->pos_pause.y = 120000;
				sfSprite_setPosition(pause->pause, pause->pos_pause);
				is_pause = 0;
			}
			if (sfKeyboard_isKeyPressed(sfKeyE)) {
				pause->pos_pause.x = 1220;
				pause->pos_pause.y = 120000;
				sfSprite_setPosition(pause->pause, pause->pos_pause);
				i = 1;
			}
		}
	}
	return (0);
}
