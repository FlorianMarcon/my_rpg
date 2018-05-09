/*
** EPITECH PROJECT, 2017
** my_RPG
** File description:
** lvl_up
*/

#include "game.h"

void	lvl_up(game_t *game)
{
	if (game->perso->stat.xp >= game->perso->stat.xp_max) {
		game->perso->stat.lvl += 1;
		game->perso->stat.xp_max *= 2;
	}
}
