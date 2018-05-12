/*
** EPITECH PROJECT, 2017
** my_RPG
** File description:
** annimation
*/

#include "game.h"

sfText	*set_txt_dommage(int dommage, sfVector2f pos)
{
	sfText *text = sfText_create();
	sfFont *font = sfFont_createFromFile("./font/attack_of_the_cucumbers.ttf");
	char *buffer = "-";
	sfColor color = {155, 255, 155, 150};

	pos.x += 30;
	buffer = my_strcat(buffer, get_nb_in_char(dommage));
	sfText_setFont(text, font);
	sfText_setCharacterSize(text, 50);
	sfText_setColor(text, color);
	sfText_setPosition(text, pos);
	sfText_setString(text, buffer);
	return (text);
}

void	move_txt(sfVector2f *pos, int *x, sfColor *color, sfText *text)
{
	sfVector2f ppos = *pos;
	int xx = *x;
	sfColor col = *color;

	ppos.y -= 2;
	xx -= 5;
	col = (sfColor){155, 255, 0, xx};
	sfText_setColor(text, col);
	sfText_setPosition(text, ppos);
	*pos = ppos;
	*x = xx;
	*color = col;
}

void	move_sprite(int ref, game_t *game)
{
	static int sens = 1;

	if (ref == 0) {
		game->fight->ennemy->position.x += (5 * sens);
		sens *= -1;
		sfSprite_setPosition(game->fight->ennemy->sprite,
						game->fight->ennemy->position);
	} else {
		game->fight->item->next->next->position.x += (5 * sens);
		sens *= -1;
		sfSprite_setPosition(game->fight->item->next->next->sprite,
			game->fight->item->next->next->position);
	}
}

void	annimation_dommage(game_t *game, int dommage, sfVector2f pos, int ref)
{
	sfText *text = set_txt_dommage(dommage, pos);
	//sfVector2f pos = {700, 300};
	sfColor color = {155, 255, 0, 155};
	int x = 155;

	pos.x += 30;
	while (x > 20) {
		while (sfRenderWindow_pollEvent(game->win->window,
							&game->win->event)) {
			if (game->win->event.type == sfEvtClosed) {
				sfRenderWindow_close(game->win->window);
				return;
			}
		}
		move_sprite(ref, game);
		display_fight(game, text);
		move_txt(&pos, &x, &color, text);
		wait_sec(0.1);
	}
}
