/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** fighters
*/

#include "fight.h"
#include "graphique.h"
#include "game.h"

void	(scene_t *scene)
{
	scene->enemy.enemy_name = "Gargoyle";
	scene->enemy.enemy_life = 100;
	scene->enemy.enemy_attack = 10;
	scene->enemy.enemy_defence = 10;
	scene->enemy.enemy_def_magic = 10;
	scene->enemy.experience_gain = 10;
}

void	init_player(scene_t *scene, game_t *game)
{
	init_enemy(scene);

}