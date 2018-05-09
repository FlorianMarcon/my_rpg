/*
** EPITECH PROJECT, 2017
** my_RPG
** File description:
** window
*/

#include "game.h"
#include "graphique.h"

param_t	*gp()
{
	static param_t *var;
	static int ps = 0;

	if (ps == 0) {
		ps = 1;
		var->win = generate_window(1200, 800, 32);
		var->perso = create_my_perso();
		var->list = generate_list_map("./map/");
		var->map = (map_t *)var->list->next->data;
	}
	return (var);
}

void	affect_move_perso(game_t *game)
{
	if (game->can_move == false)
		return;
	if (sfKeyboard_isKeyPressed(sfKeyUp))
		dep_up(game);
	if (sfKeyboard_isKeyPressed(sfKeyDown))
		dep_down(game);
	if (sfKeyboard_isKeyPressed(sfKeyLeft))
		dep_left(game);
	if (sfKeyboard_isKeyPressed(sfKeyRight))
		dep_right(game);
}
