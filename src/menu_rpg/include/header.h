/*
** EPITECH PROJECT, 2017
** header
** File description:
** header
*/

#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef HEADER_MY_
#define HEADER_MY_

typedef struct lock {
	int lock;
} lock_t;

typedef struct menu {
	sfSprite *sprite;
	sfSprite *sprite1;
	sfSprite *sprite2;
	sfSprite *sprite3;
	sfSprite *sprite4;
	sfSprite *sprite5;
	sfSprite *sprite6;
	sfSprite *sprite7;
	sfTexture *texture;
	sfTexture *texture1;
	sfTexture *texture2;
	sfTexture *texture3;
	sfTexture *texture4;
	sfTexture *texture5;
	sfTexture *texture6;
	sfTexture *texture7;
	sfVector2f pos_but;
	sfVector2f pos_but1;
	sfVector2f pos_but2;
	sfVector2f pos_but3;
	sfVector2f pos_but4;
	sfVector2f pos_but5;
	sfVector2f pos_bck;
	sfVector2f pos_sts;
	void(*callback)(struct menu *ptr);
} menu_t;

menu_t	*init_menu(void);

void	set_pos_men(menu_t *men);

void	draw_menu(menu_t *men, sfRenderWindow *window, lock_t *lock);

void	anim_menu(menu_t *men, sfRenderWindow *window, sfVector2i pos1, lock_t *lock);

#endif
