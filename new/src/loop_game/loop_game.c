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

int	loop_game(void)
{
	game_t *game = initialisation_game();

	if (game == NULL)
		return (84);
	game->map = search_map(game->list_map, game->index);
	game->map_graph = generate_map_graph(game->map);
	while (sfRenderWindow_isOpen(game->win->window) && game->map_graph != NULL) {
		event(game);
		sfRenderWindow_clear(game->win->window, sfBlack);
		display(game);
		sfRenderWindow_display(game->win->window);
	}
	destroy_map_graph(game->map_graph);
	free(game->win);
	free(game);
	return (0);
}
