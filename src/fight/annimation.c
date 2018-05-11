/*
** EPITECH PROJECT, 2017
** my_RPG
** File description:
** annimation
*/

#include "game.h"

sfText	*set_txt_dommage(int dommage)
{
	sfText *text = sfText_create();
	sfVector2f pos = {700, 300};
	sfFont *font = sfFont_createFromFile("./font/\
	attack_of_the_cucumbers.ttf");
	char *buffer = "-";
	sfColor color = {155, 255, 155, 150};

	buffer = my_strcat(buffer, get_nb_in_char(dommage));
	sfText_setFont(text, font);
	sfText_setCharacterSize(text, 50);
	sfText_setColor(text, color);
	sfText_setPosition(text, pos);
	sfText_setString(text, buffer);
	return (text);
}

void	annimation_dommage(game_t *game, int dommage, sfVector2f pos)
{
	sfText *text = set_txt_dommage(dommage);
	//sfVector2f pos = {700, 300};
	sfColor color = {155, 255, 0, 155};
	int x = 155;

	while (x > 20) {
		while (sfRenderWindow_pollEvent(game->win->window,\
		&game->win->event)) {
			if (game->win->event.type == sfEvtClosed) {
				sfRenderWindow_close(game->win->window);
				return;
			}
		}
		display_fight(game, text);
		pos.y -= 5;
		x -= 5;
		color = (sfColor){155, 255, 0, x};
		sfText_setColor(text, color);
		sfText_setPosition(text, pos);
	//	wait_sec(0.2);
	}
}