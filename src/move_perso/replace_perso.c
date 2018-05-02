/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** replace perso
*/

#include "game.h"

void	replace_perso(game_t *game, int x, int y)
{
	game->perso->position.x = game->map->iso[x][y].x - 27;
	game->perso->position.y = game->map->iso[x][y].y - 32;
	sfSprite_setPosition(game->perso->sprite, game->perso->position);
}
