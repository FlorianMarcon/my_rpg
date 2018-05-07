/*
** EPITECH PROJECT, 2018
** menu
** File description:
** menu
*/

#include <stdio.h>
#include "game.h"
#include "map.h"
#include "header.h"
#include "inventory.h"

int	loop_menu(void)
{
	game_t *game = initialisation_game();
	pause_t *pause = init_pause();
	inv_t *tmp = init_inventory();
	set_t *set = init_set();
	menu_t *men = init_menu();
	lock_t *ptr = malloc(sizeof(lock_t));
	sfVector2i pos_mouse;

	if (game == NULL)
		return (84);
	game->map = search_map(game->list_map, game->index);
	game->map_graph = generate_map_graph(game->map, game);
	game->perso->position.x = game->map->iso[0][0].x - 27;
	game->perso->position.y = game->map->iso[0][0].y - 32;
	set_text_menu(men, set);
	while (sfRenderWindow_isOpen(game->win->window)) {
		while (sfRenderWindow_pollEvent(game->win->window, &game->win->event))
			if (game->win->event.type == sfEvtClosed)
				sfRenderWindow_close(game->win->window);
		pos_mouse = sfMouse_getPositionRenderWindow(game->win->window);
		sfRenderWindow_clear(game->win->window, sfBlack);
		//sfRenderWindow_display(game->win->window);
		create_menu(set, ptr, men, game->win->window, pos_mouse, game, tmp, pause);
	}
	destroy_map_graph(game->map_graph);
	free(game->win);
	free(game);
	return (0);
}
