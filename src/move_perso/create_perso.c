/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** create_perso
*/

#include "game.h"

void	init_perso_param(perso_t *perso)
{
	perso->texture = sfTexture_createFromFile("./src/dinosaure.png", NULL);
	perso->sprite = sfSprite_create();
	perso->rect.top = 0;
	perso->rect.left = 0;
	perso->rect.width = 64;
	perso->rect.height = 56;
	perso->position.x = 0;
	perso->position.y = 0;
	perso->mouvement.x = 0;
	perso->mouvement.y = 0;
	perso->x = 0;
	perso->y = 0;
	sfSprite_setTexture(perso->sprite, perso->texture, sfTrue);
	sfSprite_setPosition(perso->sprite, perso->position);
	sfSprite_setTextureRect(perso->sprite, perso->rect);
}

void	init_perso_stat(perso_t *perso)
{
	perso->stat.vie = 100;
	perso->stat.vie_c = 100;
	perso->stat.att_m = 10;
	perso->stat.att_p = 10;
	perso->stat.defence = 10;
	perso->stat.xp = 0;
	perso->stat.xp_max = 100;
	perso->stat.lvl = 0;
	perso->stat.change = true;
}

perso_t	*create_my_perso(void)
{
	perso_t *perso = malloc(sizeof(perso_t) * 1);

	init_perso_param(perso);
	init_perso_stat(perso);
	return (perso);
}
