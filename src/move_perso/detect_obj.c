/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** detect obj
*/

#include "game.h"

int	colision_x(game_t *game, int x)
{
	if (x == 0) {

		if (game->map->map[game->perso->x + 1][game->perso->y] < 20)
			return (0);
		/*else if (game->map->map[game->perso->x + 1][game->perso->y] >= 100) {
			run_quete(game, game->map->map[game->perso->x + 1][game->perso->y]);
			printf("**\n");
		}*/
	}
	if (x == 1 && game->perso->x > 0) {
		if (game->map->map[game->perso->x - 1][game->perso->y] < 20)
			return (0);
		/*else if (game->map->map[game->perso->x - 1][game->perso->y] >= 100) {
			run_quete(game, game->map->map[game->perso->x - 1][game->perso->y]);
			printf("*\n");
		}*/
	}
	return (-1);
}

int	colision_y(game_t *game, int y)
{
	if (y == 10) {
		if (game->map->map[game->perso->x][game->perso->y + 1] < 20)
			return (0);
	/*else if (game->map->map[game->perso->x][game->perso->y + 1] >= 100) {
			run_quete(game, game->map->map[game->perso->x][game->perso->y + 1]);
		}*/
	}
	if (y == 11 && game->perso->y > 0) {
		if (game->map->map[game->perso->x][game->perso->y - 1] < 20)
			return (0);
		/*else if (game->map->map[game->perso->x][game->perso->y - 1] >= 100) {
			run_quete(game, game->map->map[game->perso->x][game->perso->y - 1]);
		}*/
	}
	return (-1);
}

int	detect_col(game_t *game, int sens)
{
	if (sens < 10)
		return (colision_x(game, sens));
	else
		return (colision_y(game, sens));
	return (0);
}
