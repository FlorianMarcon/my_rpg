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
		game->perso->stat.vie += 10;
		game->perso->stat.vie_c = game->perso->stat.vie;
		game->perso->stat.defence += 5;
		game->perso->stat.att_m += 5;
		game->perso->stat.att_p += 5;
	}
}
