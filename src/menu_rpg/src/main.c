/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "header.h"

int	main(void)
{
	lock_t *ptr = malloc(sizeof(lock_t));
	menu_t *men = init_menu();
	sfVideoMode mode = {1200, 1000, 32};
	sfRenderWindow *window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
	sfEvent event;
	sfVector2i pos1;

	ptr->lock = 0;
	set_text_menu(men);
	while (sfRenderWindow_isOpen(window)) {
		pos1 = sfMouse_getPositionRenderWindow(window);
		while(sfRenderWindow_pollEvent(window, &event)){
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(window);
		}
		men->pos_sts.x -= 0.1;
		set_pos_men(men);
		sfRenderWindow_clear(window, sfWhite);
		draw_menu(men, window, ptr);
		anim_menu(men, window, pos1, ptr);
		sfRenderWindow_display(window);
	}
	sfSprite_destroy(men->sprite);
	sfSprite_destroy(men->sprite1);
	sfSprite_destroy(men->sprite2);
	sfSprite_destroy(men->sprite3);
	sfSprite_destroy(men->sprite4);
	sfSprite_destroy(men->sprite5);
	sfRenderWindow_destroy(window);
	return (0);
}
