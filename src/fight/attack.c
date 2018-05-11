/*
** EPITECH PROJECT, 2017
** my_RPG
** File description:
** attack
*/

#include "game.h"
#include "time.h"

void	lance_baton(game_t *game)
{
	game->fight->ennemy->vie -= game->perso->stat.att_p -
		(game->perso->stat.att_p * game->fight->ennemy->defence / 100);
	if (game->fight->ennemy->vie < 0)
		game->fight->ennemy->vie = 0;
	//annimation_p(game);
}

void	wingardium(game_t *game)
{
	game->fight->ennemy->vie -= game->perso->stat.att_m -
		(game->perso->stat.att_m * game->fight->ennemy->defence / 100);
	if (game->fight->ennemy->vie < 0)
		game->fight->ennemy->vie = 0;
	//annimation_m(game);
}

void	enn_att1(game_t *game)
{
	game->perso->stat.vie_c -= game->fight->ennemy->att_p -
	(game->fight->ennemy->att_p * game->perso->stat.defence / 100);
	if (game->perso->stat.vie_c < 0)
		game->perso->stat.vie_c = 0;
	//annimation_enn_1(game);
}

void	enn_att2(game_t *game)
{
	game->perso->stat.vie_c -= game->fight->ennemy->att_m -
	(game->fight->ennemy->att_m * game->perso->stat.defence / 100);
	if (game->perso->stat.vie_c < 0)
		game->perso->stat.vie_c = 0;
	//annimation_enn_2(game);
}

void	ennemy_tour(game_t *game)
{
	if (rand()%10 % 2 == 0)
		enn_att1(game);
	else
		enn_att2(game);
	//wait_sec(2);
}
