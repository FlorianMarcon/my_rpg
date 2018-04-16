/*
** EPITECH PROJECT, 2017
** initialisation_game
** File description:
** initialisation_game
*/

#include "graphique.h"
#include "game.h"
#include "map.h"
#include <stdbool.h>

game_t	*initialisation_game(void)
{
	game_t *game = malloc(sizeof(*game));

	if (game == NULL)
		return (NULL);
	game->win = generate_window(1280, 800, 32);
	game->list_obj = generate_list_object(PATH_DIR_OBJ);
	game->list_map = generate_list_map(PATH_DIR_MAP);
	if (game->win == NULL) {
		free(game);
		return (NULL);
	}
	game->index = 1;
//	game->map = search_map(game->list_map, game->index);
	game->draw_line = false;
	game->background = generate_sprite_from_file(BACKGROUND);
	return (game);
}
