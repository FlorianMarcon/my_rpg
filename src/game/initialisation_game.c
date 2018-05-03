/*
** EPITECH PROJECT, 2017
** initialisation_game
** File description:
** initialisation_game
*/

#include <stdbool.h>
#include "graphique.h"
#include "game.h"
#include "map.h"
#include "quete.h"

void	initialisation_quete(game_t *game)
{
	game->textbox = sfSprite_create();
	sfSprite_setTexture(game->textbox, sfTexture_createFromFile("./matter/textbox.png", NULL), sfTrue);
	game->display_textbox = false;
	game->text = sfText_create();
	sfText_setFont(game->text, sfFont_createFromFile("./font/attack_of_the_cucumbers.ttf"));
	sfText_setPosition(game->text, (sfVector2f){215, 550});
	game->list_quete = generate_list_quete(PATH_DIR_QUETE);
}

void	initialisation_list_necessary(game_t *game)
{
	game->list_map = generate_list_map(PATH_DIR_MAP);
	game->list_obj = generate_list_object(PATH_DIR_OBJ);
	game->list_inventory = generate_list_inventory(PATH_DIR_INV);
}

game_t	*initialisation_game(void)
{
	game_t *game = malloc(sizeof(*game));

	if (game == NULL)
		return (NULL);
	game->win = generate_window(1200, 1000, 32);
	if (game->win == NULL) {
		free(game);
		return (NULL);
	}
	initialisation_list_necessary(game);
	initialisation_quete(game);
	game->index = 1;
//	game->map = search_map(game->list_map, game->index);
	game->draw_line = false;
	game->background = generate_sprite_from_file(BACKGROUND);
	game->perso = create_my_perso();
	return (game);
}
