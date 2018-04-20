/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** create_perso
*/

#include "game.h"

perso_t	*create_my_perso(void)
{
	perso_t *perso = malloc(sizeof(perso_t) * 1);

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
	return (perso);
}

perso_t	*create_bg(void)
{
	perso_t *perso = malloc(sizeof(perso_t) * 1);

	perso->texture = sfTexture_createFromFile("./src/capture_map.png", NULL);
	perso->sprite = sfSprite_create();
	perso->position.x = 0;
	perso->position.y = 0;
	sfSprite_setTexture(perso->sprite, perso->texture, sfTrue);
	sfSprite_setPosition(perso->sprite, perso->position);
	return (perso);
}
