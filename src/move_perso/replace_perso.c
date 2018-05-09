/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** replace perso
*/

#include "game.h"

void	replace_perso(game_t *game, int x, int y)
{
	game->perso->position.x = game->map->iso[x][y].x - 10;
	game->perso->position.y = game->map->iso[x][y].y - 27;
	sfSprite_setPosition(game->perso->sprite, game->perso->position);
}
