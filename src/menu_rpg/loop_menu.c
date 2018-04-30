/*
** EPITECH PROJECT, 2018
** menu
** File description:
** menu
*/

#include "game.h"
#include "map.h"
#include "header.h"
#include "inventory.h"

void	loop_menu(sfRenderWindow *window)
{
	inv_t *tmp = init_inventory();
	set_t *set = init_set();
	menu_t *men = init_menu();
	int i = 0;
	sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(window);

	set_text_menu(men, set);
	while (sfRenderWindow_isOpen(window)) {
		create_menu(set, men, window, pos_mouse, i);
		if (i 
}
