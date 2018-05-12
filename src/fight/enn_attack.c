/*
** EPITECH PROJECT, 2017
** my_RPG
** File description:
** enn_attack
*/

#include "game.h"
#include "time.h"

void	enn_att1(game_t *game)
{
	int dommage = game->fight->ennemy->att_p -
	(game->fight->ennemy->att_p * game->perso->stat.defence / 100);
	sfVector2f pos = {150, 300};

	if (game->perso->stat.vie_c - dommage < 0)
		dommage += game->perso->stat.vie_c - dommage;
	game->perso->stat.vie_c -= dommage;
	if (game->perso->stat.vie_c < 0)
		game->perso->stat.vie_c = 0;
	load_stat(game, game->fight->txt);
	display_fight(game, NULL);
	annimation_dommage(game, dommage, pos, 1);
}

void	enn_att2(game_t *game)
{
	int dommage = game->fight->ennemy->att_m -
	(game->fight->ennemy->att_m * game->perso->stat.defence / 100);
	sfVector2f pos = {150, 300};

	if (game->perso->stat.vie_c - dommage < 0)
		dommage += game->perso->stat.vie_c - dommage;
	game->perso->stat.vie_c -= dommage;
	if (game->perso->stat.vie_c < 0)
		game->perso->stat.vie_c = 0;
	load_stat(game, game->fight->txt);
	display_fight(game, NULL);
	annimation_dommage(game, dommage, pos, 1);
}

void	ennemy_tour(game_t *game)
{
	if (rand()%10 % 2 == 0)
		enn_att1(game);
	else
		enn_att2(game);
	//wait_sec(2);
}
