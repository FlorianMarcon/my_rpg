/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** fight.h
*/

#include <SFML/Graphics.h>

#ifndef __FIGHT__
#define __FIGHT__

typedef struct enemy_s {
	char *enemy_name;
	int enemy_life;
	int enemy_attack;
	int enemy_defence;
	int enemy_def_magic;
	int experience_gain;
} enemy_t;

typedef struct scene_s {
	sfFont *font;

	sfText *attack;
	sfText *survol_attack;
	sfText *char_name;
	sfText *life;
	sfText *dead;
	sfText *you_won;
	sfText *magic;
	sfText *survol_magic;

	sfVector2f pos_attack;
	sfVector2f pos_name;
	sfVector2f pos_dead;
	sfVector2f origi_dead;
	sfVector2f pos_you_won;
	sfVector2f pos_life;
	sfVector2f origi_barre;
	sfVector2f pos_barre;
	sfVector2f pos_magic;

	sfFloatRect real_pos_attack;
	sfFloatRect real_pos_magic;

	sfTexture *battleground;
	sfTexture *textu_barre;

	sfSprite *sprite_battleground;
	sfSprite *sprite_barre;

	char *life_tab;

	enemy_t enemy;
} scene_t;

#endif /*__FIGHT__*/