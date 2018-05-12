/*
** EPITECH PROJECT, 2017
** my_RPG
** File description:
** attack
*/

#include "game.h"

void	lance_baton(game_t *game)
{
	int dommage = game->perso->stat.att_p -
		(game->perso->stat.att_p * game->fight->ennemy->defence / 100);
//	sfVector2f pos = {700, 600};

	if (game->fight->ennemy->vie - dommage < 0)
		dommage += game->fight->ennemy->vie - dommage;
	game->fight->ennemy->vie -= dommage;
	if (game->fight->ennemy->vie < 0)
		game->fight->ennemy->vie = 0;
	load_stat(game, game->fight->txt);
	display_fight(game, NULL);
	annimation_dommage(game, dommage, game->fight->ennemy->position, 0);
}

void	wingardium(game_t *game)
{
	int dommage = game->perso->stat.att_m -
		(game->perso->stat.att_m * game->fight->ennemy->defence / 100);

	if (game->fight->ennemy->vie - dommage < 0)
		dommage += game->fight->ennemy->vie - dommage;
	game->fight->ennemy->vie -= dommage;
	if (game->fight->ennemy->vie < 0)
		game->fight->ennemy->vie = 0;
	load_stat(game, game->fight->txt);
	display_fight(game, NULL);
	annimation_dommage(game, dommage, game->fight->ennemy->position, 0);
}
