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
	unsigned int y = 550;

	game->textbox = sfSprite_create();
	sfSprite_setTexture(game->textbox, sfTexture_createFromFile("./matter/textbox.png", NULL), sfTrue);
	game->display_textbox = false;
	for (unsigned int i = 0; i != 8; i++) {
		game->text[i] = sfText_create();
		sfText_setFont(game->text[i], sfFont_createFromFile("./font/attack_of_the_cucumbers.ttf"));
		sfText_setPosition(game->text[i], (sfVector2f){215, y});
		y += 35;
	}
	game->size_text = 0;
	game->list_quete = generate_list_quete(PATH_DIR_QUETE);
}

void	initialisation_list_necessary(game_t *game)
{
	game->list_map = generate_list_map(PATH_DIR_MAP);
	game->list_obj = generate_list_object(PATH_DIR_OBJ);
	game->list_inventory = generate_list_inventory(PATH_DIR_INV);
	game->list_inv_player = NULL;
}

pause_t	*init_pause(void)
{
	pause_t *pause = malloc(sizeof(pause_t));

	pause->pause = sfSprite_create();
	pause->texture_pause = sfTexture_createFromFile("./matter/pause.png", NULL);
	sfSprite_setTexture(pause->pause, pause->texture_pause, sfTrue);
	pause->pos_pause = (sfVector2f){1200, 1200};
	sfSprite_setPosition(pause->pause, pause->pos_pause);
	return (pause);
}

void	init_inv(game_t *game)
{
	game->back_inv = init_inventory();
	game->font_inv = sfFont_createFromFile("./font/fibre-font.otf");
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
	game->draw_line = false;
	game->background = generate_sprite_from_file(BACKGROUND);
	game->perso = create_my_perso();
	game->stat = init_stat(game->perso->stat);
	game->can_move = true;
	game->pause = init_pause();
	init_inv(game);
	return (game);
}
