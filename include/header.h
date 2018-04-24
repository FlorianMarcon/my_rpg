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

typedef struct set {
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f pos;
	sfSprite *sprite1;
	sfTexture *texture1;
	sfVector2f pos1;
} set_t;

typedef struct lock {
	int lock;
	int lock1;
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
	sfSprite *sprite8;
	sfTexture *texture;
	sfTexture *texture1;
	sfTexture *texture2;
	sfTexture *texture3;
	sfTexture *texture4;
	sfTexture *texture5;
	sfTexture *texture6;
	sfTexture *texture7;
	sfTexture *texture8;
	sfVector2f pos_but;
	sfVector2f pos_but1;
	sfVector2f pos_but2;
	sfVector2f pos_but3;
	sfVector2f pos_but4;
	sfVector2f pos_but5;
	sfVector2f pos_but8;
	sfVector2f pos_bck;
	sfVector2f pos_sts;
	void(*callback)(struct menu *ptr);
} menu_t;

menu_t	*init_menu(void);

set_t	*init_set(void);

void	set_pos_men(menu_t *men, set_t *set);

void	draw_menu(menu_t *men, sfRenderWindow *window, lock_t *lock, set_t *set);

int	anim_menu(menu_t *men, sfRenderWindow *window, sfVector2i pos1, lock_t *lock, set_t *set, int i);

void	set_text_menu(menu_t *men, set_t *set);

void	anim_check(menu_t *men, sfVector2i pos1);

void	anim_but1(menu_t *menu, sfRenderWindow *window, sfVector2i pos1);

void	anim_back(set_t *set, sfRenderWindow *win, sfVector2i pos1, lock_t *lock);

int	create_menu(set_t *set, lock_t *ptr, menu_t *men, sfRenderWindow *window, sfVector2i pos1, int i);

#endif
