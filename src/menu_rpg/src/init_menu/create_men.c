/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "header.h"

menu_t	*suite_init_menu(menu_t *elem)
{
	elem->pos_sts = (sfVector2f){0, 0};
	elem->pos_but1 = (sfVector2f){320, 325};
	elem->pos_but2 = (sfVector2f){320, 715};
	elem->pos_but3 = (sfVector2f){320, 715};
	elem->pos_but4 = (sfVector2f){320, 520};
	elem->pos_but5 = (sfVector2f){320, 520};
	elem->pos_bck = (sfVector2f){0, 0};
	elem->pos_but = (sfVector2f){320, 325};

	return (elem);
}

menu_t	*init_menu(void)
{
	menu_t *elem = malloc(sizeof(menu_t));

	elem->sprite = sfSprite_create();
	elem->sprite1 = sfSprite_create();
	elem->sprite2 = sfSprite_create();
	elem->sprite3 = sfSprite_create();
	elem->sprite4 = sfSprite_create();
	elem->sprite5 = sfSprite_create();
	elem->sprite6 = sfSprite_create();
	elem->sprite7 = sfSprite_create();
	elem->texture = sfTexture_createFromFile("src/play_on.png", NULL); 
	elem->texture1 = sfTexture_createFromFile("src/play_off.png", NULL);
	elem->texture2 = sfTexture_createFromFile("src/quit_on.png", NULL);
	elem->texture3 = sfTexture_createFromFile("src/quit_off.png", NULL);
	elem->texture4 = sfTexture_createFromFile("src/setting_on.png", NULL);
	elem->texture5 = sfTexture_createFromFile("src/setting_off.png", NULL);
	elem->texture6 = sfTexture_createFromFile("src/bckl.png", NULL);
	elem->texture7 = sfTexture_createFromFile("src/stars.png", NULL);
	elem = suite_init_menu(elem);
	
	return (elem);
}

void	set_text_menu(menu_t *men)
{
	sfSprite_setTexture(men->sprite, men->texture, sfTrue);
	sfSprite_setTexture(men->sprite1, men->texture1, sfTrue);
	sfSprite_setTexture(men->sprite2, men->texture2, sfTrue);
	sfSprite_setTexture(men->sprite3, men->texture3, sfTrue);
	sfSprite_setTexture(men->sprite4, men->texture4, sfTrue);
	sfSprite_setTexture(men->sprite5, men->texture5, sfTrue);
	sfSprite_setTexture(men->sprite6, men->texture6, sfTrue);
	sfSprite_setTexture(men->sprite7, men->texture7, sfTrue);
}

void	set_pos_men(menu_t *men)
{
	sfSprite_setPosition(men->sprite, men->pos_but);
	sfSprite_setPosition(men->sprite1, men->pos_but1);
	sfSprite_setPosition(men->sprite2, men->pos_but2);
	sfSprite_setPosition(men->sprite3, men->pos_but3);
	sfSprite_setPosition(men->sprite4, men->pos_but4);
	sfSprite_setPosition(men->sprite5, men->pos_but5);
	sfSprite_setPosition(men->sprite6, men->pos_bck);
	sfSprite_setPosition(men->sprite7, men->pos_sts);
}
