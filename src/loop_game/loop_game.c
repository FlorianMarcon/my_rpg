/*
** EPITECH PROJECT, 2017
** loop_game
** File description:
** loop_game
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "game.h"
#include "map.h"
#include "header.h"

int	loop_game(void)
{
	inv_t *tmp = init_inventory();;
	game_t *game = initialisation_game();
	set_t *set = init_set();
	lock_t *ptr = malloc(sizeof(lock_t));
	menu_t *men = init_menu();
	int i = 0;
	sfVector2i pos1;

	if (game == NULL)
		return (84);
	game->map = search_map(game->list_map, game->index);
	game->map_graph = generate_map_graph(game->map, game);
	game->perso->position.x = game->map->iso[0][0].x - 27;
	game->perso->position.y = game->map->iso[0][0].y - 32;
	ptr->lock = 0;
	set_text_menu(men, set);
	while (sfRenderWindow_isOpen(game->win->window) &&
					game->map_graph != NULL) {
		pos1 = sfMouse_getPositionRenderWindow(game->win->window);
		sfRenderWindow_clear(game->win->window, sfBlack);
		if (i == 0)
			i = create_menu(set, ptr, men, game->win->window, pos1, i);
		event(game);
		if (i != 0) {
			tmp = inventory(tmp);
			display(game, tmp);
		}
	}
	destroy_map_graph(game->map_graph);
	free(game->win);
	free(game);
	return (0);
}
